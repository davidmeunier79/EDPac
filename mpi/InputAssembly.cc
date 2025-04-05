// InputAssembly.cc

// Local Includes
#include "InputAssembly.h"

/****************************************************************************************************************************************/
/************************************************** Methodes de la classe InputAssembly *************************************************/
/****************************************************************************************************************************************/
int InputAssembly::INPUT_RATIO=1; 

int InputAssembly::nbInputAssemblies = NB_ASSEMBLIES;

InputAssembly::InputAssembly()
{
	cerr << "Warning, InputAssembly() should be accessed by InputAssembly(int newNbNeurons, int newTag, int newSourceMPIId)" << endl;
	assemblyNature=INPUT;
	index = nbInputAssemblies;
	nbInputAssemblies++;
	
//#ifdef _TEST
	cout << "InputAssembly" << index << endl;
//#endif
}

InputAssembly::InputAssembly(int newNbNeurons, int newTag, int newSourceMPIId): InputBuffer(newNbNeurons,newTag,newSourceMPIId)
{
	index = nbInputAssemblies;
	nbInputAssemblies++;
//#ifdef _TEST
	cout << "InputAssembly: index " << index << endl;
//#endif
	assemblyNature = INPUT;
	initAssembly(newNbNeurons);
}

InputAssembly::~InputAssembly()
{
	nbInputAssemblies--;
#ifdef _TEST
	cout << "~InputAssembly" << endl;
#endif
}

void InputAssembly::initNeuronIndexs()
{
	int relativeIndex = index - NB_ASSEMBLIES;
	
	int firstNeuronIndex = NB_HIDDEN_NEURONS;
	
	if (0 <= relativeIndex && relativeIndex < NB_VISIO_INPUTS)
	{
		firstNeuronIndex += relativeIndex*VISIO_BUFFER_SIZE;
	}
	else 
	{
		firstNeuronIndex += NB_VISIO_NEURONS;
		relativeIndex -= NB_VISIO_INPUTS;
		
		if (0 <= relativeIndex && relativeIndex < NB_AUDIO_INPUTS)
		{
			firstNeuronIndex += relativeIndex*AUDIO_BUFFER_SIZE;
		}
		else
		{
			firstNeuronIndex += NB_AUDIO_NEURONS;
			relativeIndex -= NB_AUDIO_INPUTS;
			
			if (0 <= relativeIndex && relativeIndex < NB_CONDITIONNING_INPUTS)
			{
				firstNeuronIndex += relativeIndex*CONDITIONNING_BUFFER_SIZE;
			}
			else
			{
				cerr << "Warning, assembly " << index << " is an input assembly" << endl;
				return;
			}
		}
	}
	
	std::vector<Neuron*>::iterator it=neurons.begin();
	std::vector<Neuron*>::iterator end=neurons.end();

	int count = 0;
	
	while (it!=end)
	{
		((Neuron*) *it)->setIndex(firstNeuronIndex+count);
		it++;
		count++;
	}
	
}

#ifdef _BLOCKING_MODE
void InputAssembly::integrateInput(int time, int timeRef)
{
	#ifdef _TEST
	cout << "size:" << size << ", nbNeurons: " << neurons.size() << endl;
	#endif

	if (0.0 <= ((double) (timeRef-time)/((double) INTER_WAVE_PERIOD)) && ((double) (timeRef-time)/((double) INTER_WAVE_PERIOD)) <1.0)
	{
		if (getActive())
		{
			if (size==neurons.size())
			{
				std::vector<Neuron*>::iterator it=neurons.begin();
				std::vector<Neuron*>::iterator end=neurons.end();

				int compt=0;

				while (it!=end && compt<size)
				{
	#ifdef _MPI_TEST
					cout << message[compt] << " ";
	#endif
					if (0.0<=message[compt] && message[compt]<=1.0)
					{
						if ((((double) (timeRef-time)/((double) INTER_WAVE_PERIOD)) < (double) message[compt]) && ((double) message[compt] <= (((double) (timeRef-time+1))/((double) INTER_WAVE_PERIOD))) )
						{

	#ifdef _TEST
							cout << "Emission at time " << time << ", with message[" << compt << "]=" << message[compt];
							cout << " and " <<  ((double) (timeRef-time)/((double) INTER_WAVE_PERIOD)) << endl;
	#endif
							((EDNeuron*) *it)->emitSpike(time);
	#ifdef _ASSEMBLY_STAT_MODE
							if (stater)
							{
								((InputAssemblyStater*) stater)->traceSpikeEmission(((EDNeuron*) *it)->getIndex(),time);
							}
	#endif
						}
						else
						{
	#ifdef _TEST
							cerr << "Warning, unable to integrate message " << message[compt];
							cerr << " with " << ((double) (timeRef-time))/((double) INTER_WAVE_PERIOD);
							cerr << " && " << ((double) (timeRef-time+1))/((double) INTER_WAVE_PERIOD) << endl;
	#endif
						}
					}
					else
					{
						cerr << "Warning, unable to integrate message " << message[compt] << endl;
						break;
					}

					compt++;
					it++;
				}
	#ifdef _MPI_TEST
				cout << endl;
	#endif
			}
			else
			{
				cerr << "*** EDNetwork *** assembly " << index;
				cerr << " receiving incompatible message (taille=" << size << ", nbNeurons=" << neurons.size() << endl;
			}
		}
		else
		{
			cerr << "Warning, unable to integrate input (buffer is not active)" << endl;
		}
	}
	else
	{
	#ifdef _TEST
		cout << "No input integration at time " << time << " diff = " << (double) (timeRef-time)/((double) INTER_WAVE_PERIOD) << endl;
	#endif
	}
	
	//if (time==timeRef-1)
	if (time==timeRef)
	{
	#ifdef _MPI_TEST
		cout << "*** EDNetwork *** assembly " << index << " reiniting active at time " << time << endl;
	#endif 
		active=0;
	}
}
#else
void InputAssembly::integrateInput(int time, int timeRef)
{
	#ifdef _TEST
	cout << "size:" << size << ", nbNeurons: " << neurons.size() << endl;
	#endif

	if (size==neurons.size())
	{
		std::vector<Neuron*>::iterator it=neurons.begin();
		std::vector<Neuron*>::iterator end=neurons.end();

		int compt=0;

		while (it!=end && compt<size)
		{
	#ifdef _MPI_TEST
			cout << message[compt] << " ";
	#endif

			if (0.0<=message[compt] && message[compt]<=1.0)
			{
	#ifdef _STOCHASTIC_INPUT_MODE
				double random=randomProb();
				if (random<=message[compt]*1.0/INTER_WAVE_PERIOD)
				//if (random<=message[compt]*0.5/INTER_WAVE_PERIOD)
				{
		#ifdef _TEST
					cout << "Emission at time " << time << ", with message[" << compt << "]=" << message[compt] << endl;
		#endif
					((EDNeuron*) *it)->emitSpike(time);
		#ifdef _ASSEMBLY_STAT_MODE
					if (stater)
					{
						((InputAssemblyStater*) stater)->traceSpikeEmission(((EDNeuron*) *it)->getIndex(),time);
					}
		#endif
				}
	#else
		#ifdef _TEMPORAL_CODING_INPUT_MODE
				if ((((double) (timeRef-time)/((double) INTER_WAVE_PERIOD)) < (double) message[compt]) && ((double) message[compt] <= (((double) (timeRef-time+1))/((double) INTER_WAVE_PERIOD))) )
				{
						//cout << ((double) (timeRef-time-1)/INTER_WAVE_PERIOD) << " < " << message[compt] << " < " <<  ((double) (timeRef-time)/INTER_WAVE_PERIOD) << endl;

			#ifdef _TEST
					cout << "Emission at time " << time << ", with message[" << compt << "]=" << message[compt];
					cout << " and " <<  ((double) (timeRef-time)/((double) INTER_WAVE_PERIOD)) << endl;
			#endif
					((EDNeuron*) *it)->emitSpike(time);

			#ifdef _ASSEMBLY_STAT_MODE
					if (stater)
					{
						((InputAssemblyStater*) stater)->traceSpikeEmission(((EDNeuron*) *it)->getIndex(),time);
					}
			#endif
				}
				else
				{
			#ifdef _TEST
					cout << "Unable to integrate message " << message[compt];
					cout << " with " << ((double) (timeRef-time))/((double) INTER_WAVE_PERIOD);
					cout << " && " << ((double) (timeRef-time+1))/((double) INTER_WAVE_PERIOD) << endl;
			#endif
				}
		#else
					cerr << "Warning, neither _STOCHASTIC_INPUT_MODE nor _TEMPORAL_CODING_INPUT_MODE is defined for InputAssembly::integrateInput" << endl;
		#endif
	#endif
			}

			compt++;
			it++;
		}

	#ifdef _MPI_TEST
			cout << endl;
	#endif
	}
	else
	{
		cerr << "*** EDNetwork *** assembly " << index;
		cerr << " receiving incompatible message (taille=" << size << ", nbNeurons=" << neurons.size() << endl;
	}

	active=0;
}
#endif

#ifdef _ALL_TO_ALL_PROJECTION_MODE
void InputAssembly::buildTotalPostExcitProjection(Assembly* postAssembly)
{
	#ifdef _CONSOLE_TRACE_MODE
	cout << "Building Excit Projection between assembly " << index << " and assembly " << _pPostAssembly->getIndex() << endl;
	#endif

	std::vector<Neuron*>::iterator itPre=neurons.begin();
	std::vector<Neuron*>::iterator endPre=neurons.end();

	while (itPre!=endPre)
	{
		std::vector<Neuron*>::iterator itPost=(*postAssembly).getBegin();
		std::vector<Neuron*>::iterator endPost=(*postAssembly).getEnd();

		while (itPost!=endPost)
		{
			double random=randomProb();
			if (random<=((double) 1.0-0.1*(INPUT_RATIO-1)))
			{
				((EDNeuron*) *itPre)->buildPostExcitLink(*itPost);
			}
			itPost++;
		}

		itPre++;
	}


	EDExcitProjection* newExcitProjection = new EDExcitProjection((Assembly*) this,(Assembly*) postAssembly);
	((Assembly*) postAssembly)->addInputLink((Projection*) newExcitProjection);
	addOutputLink((Projection*) newExcitProjection);
}

void InputAssembly::buildTotalPostInhibProjection(Assembly* postAssembly)
{
	#ifdef _CONSOLE_TRACE_MODE
	cout << "Building Excit Projection between assembly " << index << " and assembly " << _pPostAssembly->getIndex() << endl;
	#endif

	std::vector<Neuron*>::iterator itPre=neurons.begin();
	std::vector<Neuron*>::iterator endPre=neurons.end();

	while (itPre!=endPre)
	{
		std::vector<Neuron*>::iterator itPost=(*postAssembly).getBegin();
		std::vector<Neuron*>::iterator endPost=(*postAssembly).getEnd();

		while (itPost!=endPost)
		{
			double random=randomProb();
			if (random<=((double) 1.0-0.1*(INPUT_RATIO-1)))
			//if (random<=((double) 1.0/((double) INPUT_RATIO)))
			{
				((EDNeuron*) *itPre)->buildPostInhibLink(*itPost);
			}
			itPost++;
		}

		itPre++;
	}

	EDInhibProjection* newInhibProjection = new EDInhibProjection((Assembly*) this,(Assembly*) postAssembly);
	((Assembly*) postAssembly)->addInputLink((Projection*) newInhibProjection);
	addOutputLink((Projection*) newInhibProjection);
}
#endif

#ifdef _FIXED_RATIO_PROJECTION_MODE
void InputAssembly::buildPostExcitProjection(Assembly* postAssembly)
{
	#ifdef _CONSOLE_TRACE_MODE
	cout << "Building Excit Projection between assembly " << index << " and assembly " << postAssembly->getIndex() << endl;
	#endif

	std::vector<Neuron*>::iterator itPre=neurons.begin();
	std::vector<Neuron*>::iterator endPre=neurons.end();

	while (itPre!=endPre)
	{
		std::vector<Neuron*>::iterator itPost=(*postAssembly).getBegin();
		std::vector<Neuron*>::iterator endPost=(*postAssembly).getEnd();

		while (itPost!=endPost)
		{
			double random=randomProb();
			if (random<=((double) NB_NEURONS_EACH_ASSEMBLY*INPUT_RATIO)/neurons.size())
			{
				((EDNeuron*) *itPre)->buildPostExcitLink(*itPost);
			}
			itPost++;
			/*
			((EDNeuron*)*itPre)->buildPostExcitLink(*itPost);
			itPost++;
			*/
		}

		itPre++;
	}

	EDExcitProjection* newExcitProjection = new EDExcitProjection((Assembly*) this,(Assembly*) postAssembly);
	addOutputLink((Projection*) newExcitProjection);
	((Assembly*) postAssembly)->addInputLink((Projection*) newExcitProjection);
}

void InputAssembly::buildPostInhibProjection(Assembly* postAssembly)
{
	#ifdef _CONSOLE_TRACE_MODE
	cout << "Building Inhib Projection between assembly " << index << " and assembly " << postAssembly->getIndex() << endl;
	#endif

	std::vector<Neuron*>::iterator itPre=neurons.begin();
	std::vector<Neuron*>::iterator endPre=neurons.end();

	while (itPre!=endPre)
	{
		std::vector<Neuron*>::iterator itPost=(*postAssembly).getBegin();
		std::vector<Neuron*>::iterator endPost=(*postAssembly).getEnd();

		while (itPost!=endPost)
		{
			#ifdef _INHIBITION_RESET_COMPUTING_MODE
			double random=randomProb();
			if (random <= 0.2)
			{
				((EDNeuron*) *itPre)->buildPostInhibLink(*itPost);
			}
			#else
			double random=randomProb();
			if (random<=((double) NB_NEURONS_EACH_ASSEMBLY*INPUT_RATIO)/neurons.size())
			{
				((EDNeuron*) *itPre)->buildPostInhibLink(*itPost);
			}
			itPost++;
			#endif

			//((EDNeuron*) *itPre)->buildPostInhibLink(*itPost);
			//itPost++;
		}

		itPre++;
	}

	EDInhibProjection* newInhibProjection = new EDInhibProjection((Assembly*) this,(Assembly*) postAssembly);
	addOutputLink((Projection*) newInhibProjection);
	((Assembly*) postAssembly)->addInputLink((Projection*) newInhibProjection);
}
#endif

void InputAssembly::initAssemblyFiles()
{
#ifdef _ASSEMBLY_STAT_MODE	
	stater = new InputAssemblyStater((IndexedObject*) this);	
#endif
/*
	std::vector<Neuron*>::iterator it=neurons.begin();
	std::vector<Neuron*>::iterator end=neurons.end();

	while (it!=end)
	{
//#ifdef _TEST
		cout << "initing neuron " << ((EDNeuron*) *it)->getIndex() << " files" << endl;
//#endif
		((EDNeuron*) *it)->initNeuronFiles((NeuronStater*) stater);
		it++;
	}
*/
}

void InputAssembly::endAssemblyFiles()
{
/*
	std::vector<Neuron*>::iterator it=neurons.begin();
	std::vector<Neuron*>::iterator end=neurons.end();

	while (it!=end)
	{
//#ifdef _TEST
		cout << "initing neuron " << ((EDNeuron*) *it)->getIndex() << " files" << endl;
//#endif
		((EDNeuron*) *it)->endNeuronFiles();
		it++;
	}
*/
#ifdef _ASSEMBLY_STAT_MODE
	delete((InputAssemblyStater*) stater);
#endif
}

#ifdef _ASSEMBLY_STAT_MODE
void InputAssembly::traceAssemblyFiles(int time)
{
	if (stater)
	{
		//((InhibSynapseStater*) stater)->trace(time);
		//((ExcitSynapseStater*) stater)->trace(time);
		//((InputAssemblyStater*) stater)->trace(time);
		((NeuronStater*) stater)->trace(time);
	}
}
	
	#ifdef _NO_LINK_INPUT_STAT_MODE
void InputAssembly::freeAssemblyFiles()
{
	std::vector<Projection*>::iterator it = postProjections.begin();
	std::vector<Projection*>::iterator end = postProjections.end();
	
	while (it!=end)
	{
		#ifdef _NO_EXCIT_LINK_INPUT_STAT_MODE
		if (((Projection*) *it)->getProjectionNature() == (projNature) EXCIT)
		{	
	//#ifdef _STAT_TEST
			cout << "Ending assembly " << ((EDAssembly*) ((Projection*) *it)->getPostAssembly())->getIndex() << " files because excit proj with inputs" << endl;
	//#endif
			((EDAssembly*) ((Projection*) *it)->getPostAssembly())->endAssemblyFiles();
		}
		#else
//#ifdef _STAT_TEST
		cout << "Ending assembly " << ((EDAssembly*) ((Projection*) *it)->getPostAssembly())->getIndex() << " files" << endl;
//#endif
		((EDAssembly*) ((Projection*) *it)->getPostAssembly())->endAssemblyFiles();
		#endif
		it++;
	}
}
	#endif
	
	#ifdef _LINK_INPUT_STAT_MODE
void InputAssembly::freeAssemblyFiles(NeuronStater* ns)
{
	std::vector<Projection*>::iterator it = postProjections.begin();
	std::vector<Projection*>::iterator end = postProjections.end();
	
	while (it!=end)
	{
		#ifdef _EXCIT_LINK_INPUT_STAT_MODE
		if (((EDAssembly*) ((Projection*) *it)->getPostAssembly())->getIndex()<NB_ASSEMBLIES && ((Projection*) *it)->getProjectionNature() == (projNature) EXCIT)
		{
			//#ifdef _STAT_TEST
			cout << "Initing excit assembly " << ((EDAssembly*) ((Projection*) *it)->getPostAssembly())->getIndex() << " files" << endl;
			//#endif
			
			((EDAssembly*) ((Projection*) *it)->getPostAssembly())->initAssemblyFiles((NeuronStater*) ns);
		}
		else
		{
			//#ifdef _STAT_TEST
			cout << "Ending assembly " << ((EDAssembly*) ((Projection*) *it)->getPostAssembly())->getIndex() << " files" << endl;
			//#endif
			
			((EDAssembly*) ((Projection*) *it)->getPostAssembly())->endAssemblyFiles();
		}
		#else
			#ifdef _INHIB_LINK_INPUT_STAT_MODE
		if (((EDAssembly*) ((Projection*) *it)->getPostAssembly())->getIndex()<NB_ASSEMBLIES && ((Projection*) *it)->getProjectionNature() == (projNature) INHIB)
		{
			//#ifdef _STAT_TEST
			cout << "Initing inhib assembly " << ((EDAssembly*) ((Projection*) *it)->getPostAssembly())->getIndex() << " files" << endl;
			//#endif
			
			((EDAssembly*) ((Projection*) *it)->getPostAssembly())->initAssemblyFiles((NeuronStater*) ns);
		}
		else
		{
			//#ifdef _STAT_TEST
			cout << "Ending assembly " << ((EDAssembly*) ((Projection*) *it)->getPostAssembly())->getIndex() << " files" << endl;
			//#endif
			
			((EDAssembly*) ((Projection*) *it)->getPostAssembly())->endAssemblyFiles();
		}
			#else
		if (((EDAssembly*) ((Projection*) *it)->getPostAssembly())->getIndex()<NB_ASSEMBLIES)
		{
				#ifdef _STAT_TEST
			cout << "Ending assembly " << ((EDAssembly*) ((Projection*) *it)->getPostAssembly())->getIndex() << " files" << endl;
				#endif
			
			((EDAssembly*) ((Projection*) *it)->getPostAssembly())->initAssemblyFiles((NeuronStater*) ns);
		}
			#endif
		#endif
		it++;
	}
}
	#endif
#endif

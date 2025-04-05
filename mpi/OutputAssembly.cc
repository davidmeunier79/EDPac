// OutputAssembly.cc

// Local Includes
#include "OutputAssembly.h"

/****************************************************************************************************************************************/
/************************************************** Methodes de la classe OutputAssembly ************************************************/
/****************************************************************************************************************************************/

int OutputAssembly::nbOutputAssemblies = NB_ASSEMBLIES+NB_INPUT_ASSEMBLIES;

OutputAssembly::OutputAssembly()
{
	cerr << "Warning, OutputAssembly() should be accessed by OutputAssembly(int newNbNeurons, int newTag, int newSourceMPIId)" << endl;
	assemblyNature=OUTPUT;
	
	index=nbOutputAssemblies;
	nbOutputAssemblies++;
}

OutputAssembly::OutputAssembly(int newNbNeurons, int newTag, int newTargetMPIId): OutputBuffer(newNbNeurons,newTag,newTargetMPIId)
{
	index=nbOutputAssemblies;
	nbOutputAssemblies++;
	
	assemblyNature=OUTPUT;
	initAssembly(newNbNeurons);
	
	// Construction du buffer de sortie
//#ifdef _TEST
	cout << "OutputAssembly: index " << index << endl;
//#endif
}

OutputAssembly::~OutputAssembly()
{
	nbOutputAssemblies--;
#ifdef _TEST
	cout << "~OutputAssembly" << endl;
#endif
}

void OutputAssembly::initNeuronIndexs()
{
	int relativeIndex = index - (NB_ASSEMBLIES + NB_INPUT_ASSEMBLIES);
	
	int firstNeuronIndex = NB_HIDDEN_NEURONS + NB_VISIO_NEURONS + NB_AUDIO_NEURONS + NB_CONDITIONNING_NEURONS;
	
	if (0 <= relativeIndex && relativeIndex < NB_OUTPUT_ASSEMBLIES)
	{
		firstNeuronIndex += relativeIndex*MOTOR_PATTERN_BUFFER_SIZE;
	}
	else 
	{
		cerr << "Warning, assembly " << index << " is an output assembly" << endl;
		return;
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
void OutputAssembly::initOutputIntegration()
{
	std::vector<Neuron*>::iterator it=neurons.begin();
	std::vector<Neuron*>::iterator end=neurons.end();

	int compt=0;
	
	if (!getActive())
	{
		if (neurons.size() == size)
		{
			while (it!=end)
			{
				message[compt]=0.0;
			
				compt++;
				it++;
			}
		
			active=1;
		}
		else
		{
			cerr << "Warning, incompatible size between buffer size (" << size << ") and assembly size (" << neurons.size() << ")" << endl;
		}
	}
	else
	{
		cerr << "Warning, active is already at 1, no initOutputIntegration" << endl; 
	}
}

void OutputAssembly::integrateOutput(int time)
{
	std::vector<Neuron*>::iterator it=neurons.begin();
	std::vector<Neuron*>::iterator end=neurons.end();

	int compt=0;

	if (getActive())
	{
		while (it!=end)
		{
			int lastTimeOfFiring=((EDNeuron*) *it)->getLastTimeOfFiring();
	#ifdef _TEST
			cout << "lastTimeOfFiring = " << lastTimeOfFiring << ", time = " << time << endl;
	#endif
			if (time-1<=lastTimeOfFiring && lastTimeOfFiring<=time)
			{
				message[compt]+=1.0;

	#ifdef _ASSEMBLY_STAT_MODE
				if (stater)
				{
					((OutputAssemblyStater*) stater)->traceSpikeEmission(((EDNeuron*) *it)->getIndex(),lastTimeOfFiring);
				}
	#endif
	
	#ifdef _TEST
				cout << compt << " " << message[compt] << endl;
	#endif
			}
			else
			{
	#ifdef _TEST
				cout << compt << " No value added" << endl;
	#endif
			}

			compt++;
			it++;
		}
	}
	else
	{
		cerr << "Warning, output assembly buffer is not active, unable to integrate output" << endl;
	}
}
#endif

#ifndef _BLOCKING_MODE
void OutputAssembly::integrateOutput(int time)
{
	std::vector<Neuron*>::iterator it=neurons.begin();
	std::vector<Neuron*>::iterator end=neurons.end();

	int compt=0;

	while (it!=end)
	{
		int lastTimeOfFiring=((EDNeuron*) *it)->getLastTimeOfFiring();
	#ifdef _TEST
		cout << "lastTimeOfFiring = " << lastTimeOfFiring << ", time = " << time << endl;
	#endif
		if (time-1<=lastTimeOfFiring && lastTimeOfFiring<=time)
		{
			active=1;
			message[compt]=1.0;

	#ifdef _ASSEMBLY_STAT_MODE
			if (stater)
			{
				((OutputAssemblyStater*) stater)->traceSpikeEmission(((EDNeuron*) *it)->getIndex(),lastTimeOfFiring);
			}
	#endif

	#ifdef _TEST
			cout << compt << " " << message[compt] << endl;
	#endif
		}
		else
		{
			message[compt]=0.0;
	#ifdef _TEST
			cout << compt << " No value added" << endl;
	#endif
		}

		compt++;
		it++;
	}
}
#endif

void OutputAssembly::initAssemblyFiles()
{
#ifdef _ASSEMBLY_STAT_MODE
	stater = new OutputAssemblyStater((IndexedObject*) this);
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

void OutputAssembly::endAssemblyFiles()
{
#ifdef _ASSEMBLY_STAT_MODE
	delete((OutputAssemblyStater*) stater);
#endif
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
}

#ifdef _ASSEMBLY_STAT_MODE
void OutputAssembly::traceAssemblyFiles(int time)
{
	if (stater)
	{
		//((InhibSynapseStater*) stater)->trace(time);
		//((ExcitSynapseStater*) stater)->trace(time);
		//((NeuronStater*) stater)->trace(time);

		((NeuronStater*) stater)->trace(time);
	}
}
#endif

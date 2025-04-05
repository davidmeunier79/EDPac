// EDAssembly.cc

// Local Includes
#include "EDAssembly.h"

/****************************************************************************************************************************************/
/******************************************************* Methodes de la classe EDAssembly ***********************************************/
/****************************************************************************************************************************************/
#ifdef _INHIB_RATIO_TEST_MODE
double EDAssembly::INHIB_RATIO=1.0;
#endif
#ifdef _EXCIT_RATIO_TEST_MODE
double EDAssembly::EXCIT_RATIO=1.0;
#endif

int EDAssembly::nbEDAssemblies=0;

EDAssembly::EDAssembly()
{
	assemblyNature=NO_NATURE;
}

EDAssembly::EDAssembly(int nbNeurons)
{
	assemblyNature=NO_NATURE;
	index = nbEDAssemblies;
	nbEDAssemblies++;
	
	initAssembly(nbNeurons);

#ifdef _TEST	
	cout << "EDAssembly: " << index << endl;
#endif
}

EDAssembly::EDAssembly(int nbNeurons, int newAssemblyNature)
{
	assemblyNature=newAssemblyNature;
	initAssembly(nbNeurons);
}

EDAssembly::~EDAssembly()
{
#ifdef _TEST
	cout << "~EDAssembly " << index << endl;
#endif

	if (assemblyNature == NO_NATURE)
	{
		nbEDAssemblies--;

#ifdef _TEST		
		cout << "nbEDAssemblies: " << nbEDAssemblies << endl;
#endif
	}
	
	std::vector<Neuron*>::iterator it=neurons.begin();
	std::vector<Neuron*>::iterator end=neurons.end();

	while (it!=end)
	{
		delete ((EDNeuron*) *it);
		it++;
	}
}


EDAssembly& EDAssembly::operator=(const EDAssembly& n)
{
	return *this;
}

void EDAssembly::initAssembly(int nbNeurons)
{
	for (int i=0;i<nbNeurons;i++)
	{
		Neuron* newNeuron=new EDNeuron();
		addNeuron(newNeuron);
	}
	
	initNeuronIndexs();
}

void EDAssembly::initNeuronIndexs()
{
	std::vector<Neuron*>::iterator it=neurons.begin();
	std::vector<Neuron*>::iterator end=neurons.end();

	int count = 0;
	
	while (it!=end)
	{
		((Neuron*) *it)->setIndex(index*NB_NEURONS_EACH_ASSEMBLY+count);
		it++;
		count++;
	}
}

void EDAssembly::reInitAssembly()
{
#ifdef _TEST
	cout << "*** EDNetwork *** Re-initing Assembly " << index << endl;
#endif
	std::vector<Neuron*>::iterator it=neurons.begin();
	std::vector<Neuron*>::iterator end=neurons.end();

	while (it!=end)
	{
		((EDNeuron*) *it)->reInitNeuron();
		it++;
	}

#ifdef _ASSEMBLY_STAT_MODE
	stater = 0;
#endif

#ifdef _NETWORK_TRACE_MODE
	tracer = 0;

	#ifdef _NETWORK_GRAPH_MODE
	grapher = 0;
	#endif
#endif

}

void EDAssembly::reInitEDAssembly()
{
#ifdef _TEST
	cout << "*** EDNetwork *** Re-Initing EDAssembly " << index << endl;
#endif
	std::vector<Neuron*>::iterator it=neurons.begin();
	std::vector<Neuron*>::iterator end=neurons.end();

	while (it!=end)
	{
		((EDNeuron*) *it)->reInitEDNeuron();
		it++;
	}

#ifdef _ASSEMBLY_STAT_MODE
	stater = 0;
#endif

#ifdef _NETWORK_TRACE_MODE
	tracer = 0;

	#ifdef _NETWORK_GRAPH_MODE
	grapher = 0;
	#endif
#endif
}

int EDAssembly::getNbExcitPreProjections()
{
	std::vector<Link*>::iterator itInput=inputLinks.begin();
	std::vector<Link*>::iterator endInput=inputLinks.end();

	int nbExcitPreProjections=0;
	
	while (itInput!=endInput)
	{
		if (((Projection*) *itInput)->getProjectionNature() == (projNature) EXCIT)
		{
			nbExcitPreProjections++;
		}
		
		itInput++;
	}
	
	return nbExcitPreProjections;
}

int EDAssembly::getNbInhibPreProjections()
{
	std::vector<Link*>::iterator itInput=inputLinks.begin();
	std::vector<Link*>::iterator endInput=inputLinks.end();

	int nbInhibPreProjections=0;
	
	while (itInput!=endInput)
	{
		if (((Projection*) *itInput)->getProjectionNature() == (projNature) INHIB)
		{
			nbInhibPreProjections++;
		}
		
		itInput++;
	}
	
	return nbInhibPreProjections;
}

#ifndef _TOPOLOGY_PROJECTION_MODE
void EDAssembly::buildSelfInhibition()
{
	std::vector<Neuron*>::iterator itPre=neurons.begin();
	std::vector<Neuron*>::iterator endPre=neurons.end();

	while (itPre!=endPre)
	{
		std::vector<Neuron*>::iterator itPost=neurons.begin();
		std::vector<Neuron*>::iterator endPost=neurons.end();

		while (itPost!=endPost)
		{
   			((EDNeuron*) *itPre)->buildPostInhibLink((EDNeuron*) *itPost);
			itPost++;
		}
		itPre++;
	}

	buildPostInhibProjection((Assembly*) this);
}
	
	#ifdef _ALL_TO_ALL_PROJECTION_MODE
void EDAssembly::buildTotalPostExcitProjection(Assembly* postAssembly)
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
		#ifdef _EXCIT_RATIO_TEST_MODE
			if (random<=((double) 1.0-0.1*(EXCIT_RATIO-1)))
			//if (random<=(1.0/((double) EXCIT_RATIO)))
			{
				((EDNeuron*) *itPre)->buildPostExcitLink(*itPost);
			}
		#else
			((EDNeuron*)*itPre)->buildPostExcitLink(*itPost);
		#endif
			itPost++;
			/*
			itPost++;
			*/
		}

		itPre++;
	}

	buildPostExcitProjection(postAssembly);
}

void EDAssembly::buildTotalPostInhibProjection(Assembly* postAssembly)
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
		#ifdef _INHIB_RATIO_TEST_MODE
			if (random<=((double) 1.0-0.1*(INHIB_RATIO-1)))
			//if (random<=(1.0/((double) INHIB_RATIO)))
			{
				((EDNeuron*) *itPre)->buildPostInhibLink(*itPost);
			}
		#else
			((EDNeuron*)*itPre)->buildPostInhibLink(*itPost);
		#endif
			itPost++;
		}

		itPre++;
	}

	buildPostInhibProjection(postAssembly);

}
	#endif

	#ifdef _FIXED_RATIO_PROJECTION_MODE
void EDAssembly::buildFixedPostExcitProjection(Assembly* postAssembly)
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
			if (random<=((double) NB_NEURONS_EACH_ASSEMBLY)/neurons.size())
			{
				((EDNeuron*) *itPre)->buildPostExcitLink(*itPost);
			}
			itPost++;
			/*
			double random=randomProb();
			if (random<=((double) 2*NB_MEAN_PSPS_TO_SPIKE)/NB_NEURONS_EACH_ASSEMBLY)
			{
				((EDNeuron*) *itPre)->buildPostExcitLink(*itPost);
			}
			itPost++;
			*/
			/*
			((EDNeuron*)*itPre)->buildPostExcitLink(*itPost);
			itPost++;
			*/
		}

		itPre++;
	}

	buildPostExcitProjection(postAssembly);
}

void EDAssembly::buildFixedPostInhibProjection(Assembly* postAssembly)
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
			if (random<=((double) NB_NEURONS_EACH_ASSEMBLY)/neurons.size())
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

	buildPostInhibProjection(postAssembly);
}
	#endif

void EDAssembly::destroyProjections()
{
	destroyLinks();
	
	std::vector<Neuron*>::iterator it=neurons.begin();
	std::vector<Neuron*>::iterator end=neurons.end();

	while (it!=end)
	{
	#ifdef _TEST
		cout << "Links of neuron " << ((EDNeuron*) *it)->getIndex() << " are destroyed" << endl;
	#endif
		((EDNeuron*) *it)->destroyLinks();
		((EDNeuron*) *it)->initNeuron();
		it++;
	}
	#ifdef _TEST
	cout << "Projections of assembly " << index << " are destroyed" << endl;
	#endif

	#ifdef _ASSEMBLY_STAT_MODE
	stater = 0;
	#endif

	#ifdef _NETWORK_TRACE_MODE
	tracer = 0;

		#ifdef _NETWORK_GRAPH_MODE
	grapher = 0;
		#endif
	#endif
	
}
#endif	

void EDAssembly::buildPostExcitProjection(Assembly* postAssembly)
{
	EDExcitProjection* newExcitProjection = new EDExcitProjection((Assembly*) this,(Assembly*) postAssembly);
	addOutputLink((Projection*) newExcitProjection);
	((Assembly*) postAssembly)->addInputLink((Projection*) newExcitProjection);
}	

void EDAssembly::buildPostInhibProjection(Assembly* postAssembly)
{
	EDInhibProjection* newInhibProjection = new EDInhibProjection((Assembly*) this,(Assembly*) postAssembly);
	addOutputLink((Projection*) newInhibProjection);
	((Assembly*) postAssembly)->addInputLink((Projection*) newInhibProjection);
}

/****************************************************************************************************************************************/
/******************************************************* Methodes de traces *************************************************************/
/****************************************************************************************************************************************/
#ifdef _ASSEMBLY_STAT_MODE
 	#ifdef _GLOBAL_STAT_MODE

void EDAssembly::initAssemblyFiles(NeuronStater* as)
{
		#ifdef _NO_SELF_EXCIT_STAT_MODE
	std::vector<Projection*>::iterator it = postProjections.begin();
	std::vector<Projection*>::iterator end = postProjections.end();
	
	bool selfExcitProjection=0;
	
	while (it!=end)
	{
		if (((EDAssembly*) ((Projection*) *it)->getPostAssembly())->getIndex()==getIndex() && ((Projection*) *it)->getProjectionNature()==(projNature) EXCIT)
		{
			selfExcitProjection=1;
		}
		it++;
	}
	
	if (selfExcitProjection==1)
	{
		//#ifdef _STAT_TEST
		cout << "Self excit projection for assembly " << getIndex() << endl;
		//#endif
		endAssemblyFiles();
	}
	else
	{
		stater = (NeuronStater*) as;
	
		std::vector<Neuron*>::iterator it=neurons.begin();
		std::vector<Neuron*>::iterator end=neurons.end();
	
		while (it!=end)
		{
				#ifdef _STAT_TEST
			cout << "Initing neuron " << ((EDNeuron*) *it)->getIndex() << " files" << endl;
				#endif
			((EDNeuron*) *it)->initNeuronFiles((NeuronStater*) stater);
			it++;
		}
	}
		#else
	stater = (NeuronStater*) as;

	std::vector<Neuron*>::iterator it=neurons.begin();
	std::vector<Neuron*>::iterator end=neurons.end();

	while (it!=end)
	{
			#ifdef _STAT_TEST
		cout << "Initing neuron " << ((EDNeuron*) *it)->getIndex() << " files" << endl;
			#endif
		((EDNeuron*) *it)->initNeuronFiles((NeuronStater*) stater);
		it++;
	}
		#endif
}
	#else

void EDAssembly::initAssemblyFiles()
{
		#ifdef _SINGLE_ASSEMBLY_STAT_MODE
	if (index==SINGLE_ASSEMBLY_INDEX)
	{
		cout << "Assembly " << index << " opening neuron stater" << endl;
		stater = new NeuronStater((IndexedObject*) this);
	}
	else
	{
		stater = 0;
	}
		#else
			#ifdef _ALL_ASSEMBLY_STAT_MODE
				#ifdef _STAT_TEST
	cout << "Initing assembly files " << index << endl;
				#endif
	stater = new NeuronStater((IndexedObject*) this);
			#endif
		#endif

	std::vector<Neuron*>::iterator it=neurons.begin();
	std::vector<Neuron*>::iterator end=neurons.end();

	if (stater)
	{
		while (it!=end)
		{
		#ifdef _STAT_TEST
			cout << "Initing neuron " << ((EDNeuron*) *it)->getIndex() << " files" << endl;
		#endif
			((EDNeuron*) *it)->initNeuronFiles((NeuronStater*) stater);
			it++;
		}
	}
}
	#endif

	#ifdef _PSP_LFP_STAT_MODE
void EDAssembly::initPSPotential()
{
	std::vector<Neuron*>::iterator it=neurons.begin();
	std::vector<Neuron*>::iterator end=neurons.end();

	while (it!=end)
	{
		((EDNeuron*) *it)->initPSPotential();
		it++;
	}
}
	#endif
	
void EDAssembly::endAssemblyFiles()
{
	std::vector<Neuron*>::iterator it=neurons.begin();
	std::vector<Neuron*>::iterator end=neurons.end();

	while (it!=end)
	{
	#ifdef _STAT_TEST
		cout << "Ending neuron " << ((EDNeuron*) *it)->getIndex() << " files" << endl;
	#endif
		((EDNeuron*) *it)->endNeuronFiles();
		it++;
	}

	#ifdef _GLOBAL_STAT_MODE
	stater = 0;
	#else
		#ifdef _SINGLE_ASSEMBLY_STAT_MODE
	if (index==SINGLE_ASSEMBLY_INDEX)
	{
		cout << "Deleting assembly stater" << endl;
		delete((NeuronStater*) stater);
	}
	else
	{
		stater = 0;
	}
		#else
			#ifdef _ALL_ASSEMBLY_STAT_MODE
	delete((NeuronStater*) stater);
			#endif
		#endif
	#endif
}

void EDAssembly::traceAssemblyFiles(int time)
{
	if (stater)
	{
	#ifdef _GLOBAL_STAT_MODE
		((NeuronStater*) stater)->trace(time);	
	#else
		std::vector<Neuron*>::iterator it=neurons.begin();
		std::vector<Neuron*>::iterator end=neurons.end();
		
		while (it != end)
		{
		#ifdef _PSP_LFP_STAT_MODE
			((NeuronStater*) stater)->statPSPLFP((EDNeuron*) *it);
		#else
			((NeuronStater*) stater)->statLFP((EDNeuron*) *it);
			
		#endif
			
			it++;
		}
		
		((NeuronStater*) stater)->trace(time);
		
		((NeuronStater*) stater)->initCounters();
	#endif
	}
}
#endif

#ifdef _NETWORK_GRAPH_MODE
void EDAssembly::initAssemblyGrapher()
{
	//#ifdef _ASSEMBLY_GRAPH_MODE
	#ifdef _SINGLE_ASSEMBLY_TRACE_MODE
	if (index == SINGLE_ASSEMBLY_INDEX)
	{
		grapher = new AssemblyGrapher();

		std::vector<Neuron*>::iterator it=neurons.begin();
		std::vector<Neuron*>::iterator end=neurons.end();

		while (it!=end)
		{
			((EDNeuron*) *it)->initNeuronGrapher((NeuronGrapher*) grapher);
			it++;
		}
	}
	else
	{
		grapher = 0;

		std::vector<Neuron*>::iterator it=neurons.begin();
		std::vector<Neuron*>::iterator end=neurons.end();

		while (it!=end)
		{
			((EDNeuron*) *it)->initNeuronGrapher();
			it++;
		}
	}
	#else
		#ifdef _NEURON_GRAPH_MODE
	grapher = 0;

	std::vector<Neuron*>::iterator it=neurons.begin();
	std::vector<Neuron*>::iterator end=neurons.end();

	while (it!=end)
	{
		((EDNeuron*) *it)->initNeuronGrapher();
		it++;
	}
		#endif
	#endif
}

void EDAssembly::initAssemblyGrapher(AssemblyGrapher* ag)
{
	grapher = (AssemblyGrapher*) ag;

	#ifdef _NEURON_GRAPH_MODE
	std::vector<Neuron*>::iterator it=neurons.begin();
	std::vector<Neuron*>::iterator end=neurons.end();

	while (it!=end)
	{
		((EDNeuron*) *it)->initNeuronGrapher((NeuronGrapher*) ag);
		it++;
	}
	#endif
}

void EDAssembly::freeAssemblyGrapher()
{
	#ifdef _NEURON_GRAPH_MODE
	std::vector<Neuron*>::iterator it=neurons.begin();
	std::vector<Neuron*>::iterator end=neurons.end();

	while (it!=end)
	{
		((EDNeuron*) *it)->freeNeuronGrapher();
		it++;
	}
	#endif
	
	#ifdef _SINGLE_ASSEMBLY_TRACE_MODE
	delete((AssemblyGrapher*) grapher);
	#endif
}
#endif

#ifdef _NETWORK_TRACE_MODE
void EDAssembly::initAssemblyTracer()
{

	#ifdef _SINGLE_ASSEMBLY_TRACE_MODE
	if (index == SINGLE_ASSEMBLY_INDEX)
	{
		tracer = new AssemblyTracer();

		std::vector<Neuron*>::iterator it=neurons.begin();
		std::vector<Neuron*>::iterator end=neurons.end();

		while (it!=end)
		{
			((EDNeuron*) *it)->initNeuronTracer((NeuronTracer*) tracer);
			it++;
		}
	}
	else
	{
		tracer = 0;

		std::vector<Neuron*>::iterator it=neurons.begin();
		std::vector<Neuron*>::iterator end=neurons.end();

		while (it!=end)
		{
			((EDNeuron*) *it)->initNeuronTracer();
			it++;
		}
	}
	#else
	tracer = 0;

	std::vector<Neuron*>::iterator it=neurons.begin();
	std::vector<Neuron*>::iterator end=neurons.end();

	while (it!=end)
	{
		((EDNeuron*) *it)->initNeuronTracer();
		it++;
	}
	#endif
}
void EDAssembly::initAssemblyTracer(AssemblyTracer* at)
{
	tracer = (AssemblyTracer*) at;

	std::vector<Neuron*>::iterator it=neurons.begin();
	std::vector<Neuron*>::iterator end=neurons.end();

	while (it!=end)
	{
		((EDNeuron*) *it)->initNeuronTracer((NeuronTracer*) at);
		it++;
	}

}
	//#endif

void EDAssembly::freeAssemblyTracer()
{
	std::vector<Neuron*>::iterator it=neurons.begin();
	std::vector<Neuron*>::iterator end=neurons.end();

	while (it!=end)
	{
		((EDNeuron*) *it)->freeNeuronTracer();
		it++;
	}

	#ifdef _SINGLE_ASSEMBLY_TRACE_MODE
	if (index == SINGLE_ASSEMBLY_INDEX)
	{
		delete((AssemblyTracer*) tracer);
	}
	#endif

	tracer = 0;
}
#endif
/****************************************************************************************************************************************/
/******************************************************* Methodes d'affichage ***********************************************************/
/****************************************************************************************************************************************/

std::ostream& operator<<(std::ostream& f, EDAssembly& s)
{
}


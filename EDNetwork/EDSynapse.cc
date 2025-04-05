// EDSynapse.cc

// Local Includes
#include "EDSynapse.h"

/****************************************************************************************************************************************/
/******************************************************* Methodes de la classe EDSynapse ************************************************/
/****************************************************************************************************************************************/

//EventManager EDSynapse::theEventManager(DELAY * 4+1);
EventManager EDSynapse::theEventManager((int) EVENT_MANAGER_SIZE);

EDSynapse::EDSynapse()
{
}

EDSynapse::EDSynapse(Neuron* _pNewPreNeuron, Neuron* _pNewPostNeuron):
DynamicSynapse(_pNewPreNeuron,_pNewPostNeuron)
{

}

void EDSynapse::reInitSynapse()
{
#ifdef _TEST
	cout << "Re-Initing Synapse " << index << endl;
#endif

#ifdef _ONLINE_LEARNING_MODE
	lastTimeOfPreSpike=-1;
	lastTimeOfPostSpike=-1;
#endif
	initSynapse();

#ifdef _ASSEMBLY_STAT_MODE
	stater = 0;
#endif

#ifdef _SYNAPSE_TRACE_MODE
	tracer = 0;

	#ifdef _SYNAPSE_GRAPH_MODE
	grapher = 0;
	#endif
#endif
}

void EDSynapse::reInitEDSynapse()
{

#ifdef _ASSEMBLY_STAT_MODE
	stater = 0;
#endif

#ifdef _SYNAPSE_TRACE_MODE
	tracer = 0;

	#ifdef _SYNAPSE_GRAPH_MODE
	grapher = 0;
	#endif
#endif
#ifdef _ONLINE_LEARNING_MODE
	lastTimeOfPreSpike=-1;
	lastTimeOfPostSpike=-1;
#endif
}

EDSynapse::~EDSynapse()
{
#ifdef _TEST
	cout << "~EDSynapse" << endl;
#endif
}

void EDSynapse::initSynapse()
{
	cerr << "Warning, Accessing virtual method" << endl;
}

#ifdef _TOPOLOGICAL_DELAY_MODE
int EDSynapse::returnTopologicalDelay()
{
	if (preNode->getIndex() < NB_HIDDEN_NEURONS && postNode->getIndex() < NB_HIDDEN_NEURONS)
	{
		int preAssemblyIndex = preNode->getIndex()/NB_NEURONS_EACH_ASSEMBLY;
		int postAssemblyIndex = postNode->getIndex()/NB_NEURONS_EACH_ASSEMBLY;
	
		int xPreAssembly = preAssemblyIndex%SQRT_NB_ASSEMBLIES;
		int yPreAssembly = preAssemblyIndex/SQRT_NB_ASSEMBLIES;
	
		int xPostAssembly = postAssemblyIndex%SQRT_NB_ASSEMBLIES;
		int yPostAssembly = postAssemblyIndex/SQRT_NB_ASSEMBLIES;
	
		int topologicalDelay = (int) sqrt((double) ((xPreAssembly-xPostAssembly)*(xPreAssembly-xPostAssembly)+(yPreAssembly-yPostAssembly)*(yPreAssembly-yPostAssembly)))*DELAY_STEP;
		#ifdef _TEST
		cout << "For neuron " << preNode->getIndex() << "(Assembly " << preAssemblyIndex << ") and neuron " << postNode->getIndex() << "(Assembly " << postAssemblyIndex << "),";
		cout << " delay = " << topologicalDelay << endl;
		#endif
		return topologicalDelay;
	}
	else
	{
		//return ((int) (SQRT_NB_ASSEMBLIES*1.414*DELAY_STEP));
		return 0;
	}
}
#endif

#ifdef _ONLINE_LEARNING_MODE
void EDSynapse::computeBPSpikeImpact(int timeOfBPSpike)
{
	updateLastTimeOfPostSpike(timeOfBPSpike);

	if (preNode)
	{
		if (preNode->getIndex() <=NB_ASSEMBLIES*NB_NEURONS_EACH_ASSEMBLY)
		{
			#ifdef _SYNAPSE_TRACE_MODE
			if (tracer)
			{
				#ifdef _TEST
				cout << "EDSynapse tracing post weight" << endl;
				#endif
				((SynapseTracer*) tracer)->tracePostWeight(this);
			}
			#endif
	
			#ifdef _ASSEMBLY_STAT_MODE
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
			statPostTemporalVariation(lastTimeOfPostSpike-lastTimeOfPreSpike);
				#endif
			#endif
		}
		#ifdef _TEST
		else
		{
			cout << "No stat for PSP from neuron" << preNode->getIndex() << endl;
		}
		#endif
	}
}
#endif

void EDSynapse::computeSpikeImpact(int timeOfSpike)
{
	theEventManager.addNewEvent(timeOfSpike+delay,this);

#ifdef _ONLINE_LEARNING_MODE
	#ifndef _DELAYED_STDP_MODE
	updateLastTimeOfPreSpike(timeOfSpike);

	if (preNode)
	{
		if (preNode->getIndex() <=NB_ASSEMBLIES*NB_NEURONS_EACH_ASSEMBLY)
		{
		#ifdef _SYNAPSE_TRACE_MODE
			if (tracer)
			{
			#ifdef _TEST
				cout << "EDSynapse tracing pre weight" << endl;
			#endif
				((SynapseTracer*) tracer)->tracePreWeight(this);
			}
		#endif
	
		#ifdef _ASSEMBLY_STAT_MODE
			#ifdef _GLOBAL_SYNAPSE_STAT_MODE
			statPreTemporalVariation(lastTimeOfPostSpike-lastTimeOfPreSpike);
			#endif
		#endif
		}
		#ifdef _TEST
		else
		{
			cout << "No stat for PSP from neuron" << preNode->getIndex() << endl;
		}
		#endif
	}
	#endif
#endif

}

void EDSynapse::computePSPEmission(int timeOfEmission)
{

#ifdef _ONLINE_LEARNING_MODE
	#ifdef _DELAYED_STDP_MODE
	
		#ifdef _TEST
	cerr << "computePSPEmission at time " << timeOfEmission;
	cerr << " for synapse " << (Synapse&) *this << endl;
		#endif
		
	updateLastTimeOfPreSpike(timeOfEmission);

		#ifdef _TEST
	cerr << "after update time of pre spike" << timeOfEmission;
	cerr << " for synapse " << (Synapse&) *this << endl;
		#endif
		
	if (preNode)
	{
		if (preNode->getIndex() <=NB_ASSEMBLIES*NB_NEURONS_EACH_ASSEMBLY)
		{
		#ifdef _SYNAPSE_TRACE_MODE
			if (tracer)
			{
			#ifdef _TEST
				cout << "EDSynapse tracing pre weight" << endl;
			#endif
				((SynapseTracer*) tracer)->tracePreWeight(this);
			}
		#endif
	
		#ifdef _ASSEMBLY_STAT_MODE
			#ifdef _GLOBAL_SYNAPSE_STAT_MODE
			statPreTemporalVariation(lastTimeOfPostSpike-lastTimeOfPreSpike);
			#endif
		#endif
		}
		#ifdef _TEST
		else
		{
			cerr << "No stat for PSP from neuron" << preNode->getIndex() << endl;
		}
		#endif
	}
	else
	{
		cerr << "Warning, preNode is undefined" << endl;
	}

	#endif
#endif
	if (postNode)
	{
#ifdef _TEST
		cerr << "Before computePSPImpact of postNode" << endl;
#endif		
		((Neuron*) postNode)->computePSPImpact(timeOfEmission,weight);
#ifdef _TEST
		cerr << "After computePSPImpact of postNode" << endl;
#endif
	}
	else
	{
		cerr << "Warning, postNode undefined" << endl;
	}
}

#ifdef _ASSEMBLY_STAT_MODE
	#ifdef _GLOBAL_SYNAPSE_STAT_MODE
void EDSynapse::statPreTemporalVariation(int temporalDeviation)
{
	cerr << "Warning, Accessing EDSynapse::statPreTemporalVariation virtual method" << endl;
}

void EDSynapse::statPostTemporalVariation(int temporalDeviation)
{
	cerr << "Warning, Accessing EDSynapse::statPostTemporalVariation virtual method" << endl;
}

void EDSynapse::initSynapseFiles(SynapseStater* ss)
{
	cerr << "Warning, accessing virtual EDSynapse::initSynapseFiles method" << endl;
}

void EDSynapse::endSynapseFiles()
{
	stater = 0;
}
	#endif
#endif

#ifdef _SYNAPSE_GRAPH_MODE
void EDSynapse::initSynapseGrapher()
{
	#ifdef _SINGLE_SYNAPSE_TRACE_MODE
	if (index == SINGLE_SYNAPSE_INDEX)
	{
		if (!grapher)
		{
			cout << "Initing grapher for synapse " << index << endl;
			grapher = new SynapseGrapher(this);
		}
		else
		{
			cout << "Grapher for Synapse " << getIndex() << " inited" <<endl;
		}
	}
	else
	{
		grapher = 0;
	}
	#else
	grapher = 0;
	#endif
}

void EDSynapse::initSynapseGrapher(SynapseGrapher* s)
{
	grapher = (SynapseGrapher*) s;
}

void EDSynapse::freeSynapseGrapher()
{
	#ifdef _SINGLE_SYNAPSE_TRACE_MODE
	if (index == SINGLE_SYNAPSE_INDEX)
	{
		cout << "Deleting SynapseGrapher index " << index << endl;
		delete((SynapseGrapher*) grapher);
	}
	#endif

	grapher = 0;
}

void EDSynapse::graph()
{
	if (grapher)
	{
		cout << "Graphing Synapse " << getIndex() << endl;
		((SynapseGrapher*) grapher)->graph((EDSynapse*) this);
	}
}
#endif

#ifdef _SYNAPSE_TRACE_MODE
void EDSynapse::initSynapseTracer()
{
 	#ifdef _SINGLE_SYNAPSE_TRACE_MODE
	if(index==SINGLE_SYNAPSE_INDEX)
	{
		if (!tracer)
		{
			cout << "Initing Tracer for Synapse " << getIndex() << endl;
			tracer = new SynapseTracer((IndexedObject*) this);
		}
		else
		{
			cout << "Tracer for Synapse " << getIndex() << " inited" <<endl;
		}
	}
	else
	{
		tracer = 0;
	}
	#else
	tracer = 0;
	#endif
}

void EDSynapse::initSynapseTracer(SynapseTracer* st)
{
	tracer = (SynapseTracer*) st;
}

void EDSynapse::freeSynapseTracer()
{
	#ifdef _SINGLE_SYNAPSE_TRACE_MODE
	if(index==SINGLE_SYNAPSE_INDEX)
	{
		delete((SynapseTracer*) tracer);
	}
	#endif

	tracer = 0;
}
#endif


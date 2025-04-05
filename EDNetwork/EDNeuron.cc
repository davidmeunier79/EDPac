// EDNeuron.cc

// Local Includes
#include "EDNeuron.h"

/****************************************************************************************************************************************/
/******************************************************* Methodes de la classe EDNeuron *************************************************/
/****************************************************************************************************************************************/

EDNeuron::EDNeuron()
{

#ifdef _ASSEMBLY_STAT_MODE
	#ifdef _PSP_LFP_STAT_MODE
	PSPotentialAccu =  new Accumulater();
	#endif
#endif
}

EDNeuron::~EDNeuron()
{
#ifdef _TEST
	cout << "~EDNeuron" << endl;
#endif

#ifdef _ASSEMBLY_STAT_MODE
	#ifdef _PSP_LFP_STAT_MODE
	delete(PSPotentialAccu);
	#endif
#endif

	std::vector<Link*>::iterator itOutput=outputLinks.begin();
	std::vector<Link*>::iterator endOutput=outputLinks.end();

	while (itOutput!=endOutput)
	{
		delete(*itOutput);

		itOutput++;
	}
}

void EDNeuron::buildPostExcitLink(Neuron* _pPostNeuron)
{
	// Construction de la synapse
	Synapse* newSynapse=new EDExcitSynapse(this,_pPostNeuron);

	#ifdef _TEST
	cout << "Building Excit Link between " << index << " and " << ((EDNeuron*) _pPostNeuron)->getIndex() << endl;
	#endif

	// Ajout des réferences à la synapse dans les neurones pré- et post-synaptiques
	_pPostNeuron->addInputLink(newSynapse);
	addOutputLink(newSynapse);
}

void EDNeuron::buildPostInhibLink(Neuron* _pPostNeuron)
{
	// Construction de la synapse
	Synapse* newSynapse=new EDInhibSynapse(this,_pPostNeuron);
	
	#ifdef _TEST
	cout << "Building Inhib Link between " << index << " and " << ((EDNeuron*) _pPostNeuron)->getIndex() << endl;
	#endif
	
	// Ajout des réferences à la synapse dans les neurones pré- et post-synaptiques
	_pPostNeuron->addInputLink(newSynapse);
	addOutputLink(newSynapse);
}

void EDNeuron::reInitNeuron()
{
#ifdef _TEST
	cout << "Re-Initing Neuron " << index << endl;
#endif
	// Destruction + desallocation des pointeurs sur synapses de sortie
	std::vector<Link*>::iterator itOutput=outputLinks.begin();
	std::vector<Link*>::iterator endOutput=outputLinks.end();
#ifdef _TEST
	cout << "Reiniting output synapses parameters" << endl;
#endif
	while (itOutput!=endOutput)
	{
		((EDSynapse*) *itOutput)->reInitSynapse();
		itOutput++;
	}

#ifdef _TEST
	cout << "Reiniting neuron parameters" << endl;
#endif
	initNeuron();

#ifdef _ASSEMBLY_STAT_MODE
	stater = 0;
#endif

#ifdef _NEURON_TRACE_MODE
	tracer = 0;

	#ifdef _NEURON_GRAPH_MODE
	grapher = 0;
	#endif
#endif
}


void EDNeuron::reInitEDNeuron()
{
#ifdef _TEST
	cout << "Re-Initing Neuron " << index << endl;
#endif
	// Destruction + desallocation des pointeurs sur synapses de sortie
	std::vector<Link*>::iterator itOutput=outputLinks.begin();
	std::vector<Link*>::iterator endOutput=outputLinks.end();
#ifdef _TEST
	cout << "Reiniting output synapses parameters" << endl;
#endif
	while (itOutput!=endOutput)
	{
		((EDSynapse*) *itOutput)->reInitEDSynapse();
		itOutput++;
	}

#ifdef _TEST
	cout << "Reiniting neuron parameters" << endl;
#endif
	initNeuron();

#ifdef _ASSEMBLY_STAT_MODE
	stater = 0;
#endif

#ifdef _NEURON_TRACE_MODE
	tracer = 0;

	#ifdef _NEURON_GRAPH_MODE
	grapher = 0;
	#endif
#endif
}

void EDNeuron::computePSPImpact(int timeOfImpact, double weightOfImpact)
{
	
#ifdef _TEST
	cerr << "Treating psp impact at timeOfImpact " << timeOfImpact << " for neuron " << index << endl;
#endif
	if (timeOfImpact<lastTimeOfPSPImpact)
	{
		cerr << "Accessing last modified neuron " << index << " with diff " << lastTimeOfPSPImpact-timeOfImpact << endl;
	}
	else if (timeOfImpact==lastTimeOfFiring)
	{
#ifdef _TEST
		cout << "Treating PSP at same time of last spike for neuron " << index << endl;
#endif
	}
#ifdef _INHIBITION_RESET_COMPUTING_MODE
	else if (weightOfImpact<0.0)
	{
		membranePotential=updateMembranePotential(timeOfImpact);
		
		membranePotential=(membranePotential-HYPER_POLARISATION_POTENTIAL)*(1.0+weightOfImpact)+HYPER_POLARISATION_POTENTIAL;
		lastTimeOfPSPImpact=timeOfImpact;

	#ifdef _NEURON_TRACE_MODE
		if (tracer)
		{
		#ifdef _TEST
			cout << "EDNeuron tracing PSP impact" << endl;
		#endif
			((NeuronTracer*) tracer)->tracePSPImpact(this);
		}
	#endif
	#ifdef _ASSEMBLY_STAT_MODE
		#ifdef _GLOBAL_STAT_MODE
		if(stater)
		{
			#ifdef _TEST
			cout << "EDNeuron stating inhibLFP" << endl;
			#endif
			((NeuronStater*) stater)->statInhibLFP(weightOfImpact);
		}
		#else
			#ifdef _PSP_LFP_STAT_MODE
		PSPotentialAccu->accumulate(fabs(weightOfImpact));
			#endif
	
		#endif
	#endif

	}
#else
	else if (weightOfImpact < 0.0)
	{
		
	#ifdef _TEST
		cerr << "Treating inhibitory psp impact at timeOfImpact " << timeOfImpact << " for neuron " << index << endl;
	#endif
		computeSpikeEmission(timeOfImpact,weightOfImpact);

		if (membranePotential <= HYPER_POLARISATION_POTENTIAL)
		{
			membranePotential=HYPER_POLARISATION_POTENTIAL;
		}
			
	#ifdef _TEST
		cerr << "after membranePotential" << endl;
	#endif	
	
	#ifdef _NEURON_TRACE_MODE
		if (tracer)
		{
		#ifdef _TEST
			cout << "EDNeuron tracing PSP impact" << endl;
		#endif
			((NeuronTracer*) tracer)->tracePSPImpact(this);
		}
	#endif
	
	#ifdef _ASSEMBLY_STAT_MODE
		#ifdef _GLOBAL_STAT_MODE
		if(stater)
		{
			#ifdef _TEST
			cout << "EDNeuron stating inhibLFP" << endl;
			#endif
			((NeuronStater*) stater)->statInhibLFP(weightOfImpact);
		}

		#else
		
			#ifdef _PSP_LFP_STAT_MODE
		PSPotentialAccu->accumulate(fabs(weightOfImpact));
			#endif
	
		#endif
	#endif

	}
#endif
	else
	{

#ifdef _ASSEMBLY_STAT_MODE
	#ifdef _GLOBAL_STAT_MODE
		if(stater)
		{
		#ifdef _TEST
			cout << "EDNeuron stating LFP" << endl;
		#endif
			((NeuronStater*) stater)->statExcitLFP(weightOfImpact);
		}
	#else
		#ifdef _PSP_LFP_STAT_MODE
		PSPotentialAccu->accumulate(weightOfImpact);
		#endif
	#endif
#endif

	#ifdef _TEST
		cerr << "Treating excitatory psp impact at timeOfImpact " << timeOfImpact << " for neuron " << index << endl;
	#endif	
		bool emission=computeSpikeEmission(timeOfImpact,weightOfImpact);
	
	#ifdef _TEST
		cerr << "after computeSpikeEmission: " << emission << endl;
	#endif

#ifdef _NEURON_TRACE_MODE
		if (tracer)
		{
	#ifdef _TEST
			cout << "EDNeuron tracing PSP impact" << endl;
	#endif
			((NeuronTracer*) tracer)->tracePSPImpact(this);
		}
#endif
		if (emission==1)
		{
		
#ifdef _CONSOLE_TRACE_MODE
	cerr << "resetNeuron" << endl;
#endif
			resetNeuron();

#ifdef _CONSOLE_TRACE_MODE
	cerr << "after resetNeuron" << endl;
#endif

#ifdef _ASSEMBLY_STAT_MODE
	#ifdef _GLOBAL_STAT_MODE
			if (stater && lastTimeOfFiring!=-1)
			{
		#ifdef _TEST
				cout << "EDNeuron stating ISI " << timeOfImpact-lastTimeOfFiring << " " << endl;
		#endif
				((NeuronStater*) stater)->statFrequency(abs(timeOfImpact-lastTimeOfFiring));
			}
	#endif
#endif

#ifdef _CONSOLE_TRACE_MODE
	cerr << "emitSpike" << endl;
#endif
			emitSpike(timeOfImpact);

#ifdef _CONSOLE_TRACE_MODE
	cerr << "emitBPSpike" << endl;
#endif
#ifdef _ONLINE_LEARNING_MODE
			emitBPSpike(timeOfImpact);
#endif

#ifdef _CONSOLE_TRACE_MODE
	cerr << "after emitBPSpike" << endl;
#endif
		}
		else
		{
		}
	}
}
#ifdef _ONLINE_LEARNING_MODE
void EDNeuron::emitBPSpike(int timeOfBPSpike)
{
	std::vector<Link*>::iterator itInput=inputLinks.begin();
	std::vector<Link*>::iterator endInput=inputLinks.end();

	while (itInput!=endInput)
	{
		((EDSynapse*) *itInput)->computeBPSpikeImpact(timeOfBPSpike);
		itInput++;
	}
}
#endif

void EDNeuron::emitSpike(int timeOfSpike)
{

#ifdef _CONSOLE_TRACE_MODE
	cerr << "Spike Emission for neuron " << index << " at time " << timeOfSpike << endl;
#endif

	lastTimeOfFiring=timeOfSpike;

#ifdef _NEURON_TRACE_MODE
	if (tracer)
	{
	#ifdef _TEST
		cout << "EDNeuron tracing spike emission" << endl;
	#endif
		((NeuronTracer*) tracer)->traceSpikeEmission(this);
	}
#endif

#ifdef _ASSEMBLY_STAT_MODE
	if(stater)
	{
	#ifdef _TEST
		cout << "EDNeuron stating evoked spike" << endl;
	#endif
		((NeuronStater*) stater)->statSpikeEmission(this);
	}
#endif

#ifdef _CONSOLE_TRACE_MODE
	cerr << "Spike Emission display for neuron " << index << " at time " << timeOfSpike << endl;
#endif

#ifdef _GRAPHICAL_DISPLAY_MODE
	display();
#endif

#ifdef _CONSOLE_TRACE_MODE
	cerr << "Spike Emission after display for neuron " << index << " at time " << timeOfSpike << endl;
#endif

	std::vector<Link*>::iterator itOutput=outputLinks.begin();
	std::vector<Link*>::iterator endOutput=outputLinks.end();

	while (itOutput!=endOutput)
	{
		
#ifdef _CONSOLE_TRACE_MODE
		cerr << "Spike Impact on synapse" << (Synapse&) *(*itOutput) << " at time " << timeOfSpike << endl;
#endif
		((EDSynapse*) *itOutput)->computeSpikeImpact(timeOfSpike);
		itOutput++;
	}
	
#ifdef _CONSOLE_TRACE_MODE
	cerr << "After Spike Emission for neuron " << index << " at time " << timeOfSpike << endl;
#endif
}

/****************************************************************************************************************************************/
/******************************************************* Methodes de traces *************************************************************/
/****************************************************************************************************************************************/
#ifdef _ASSEMBLY_STAT_MODE
	
	#ifdef _PSP_LFP_STAT_MODE
void EDNeuron::initPSPotential()
{
	PSPotentialAccu->initAccu();
}
	#endif
	
void EDNeuron::initNeuronFiles(NeuronStater* nt)
{
	stater = nt;

	#ifdef _GLOBAL_STAT_MODE
		#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	std::vector<Link*>::iterator itOutput=outputLinks.begin();
	std::vector<Link*>::iterator endOutput=outputLinks.end();

	while (itOutput!=endOutput)
	{
		((EDSynapse*) *itOutput)->initSynapseFiles((SynapseStater*) nt);
		itOutput++;
	}
		#endif
	#endif
}

void EDNeuron::endNeuronFiles()
{
	stater = 0;

	#ifdef _GLOBAL_STAT_MODE
		#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	std::vector<Link*>::iterator itOutput=outputLinks.begin();
	std::vector<Link*>::iterator endOutput=outputLinks.end();

	while (itOutput!=endOutput)
	{
	
		#ifdef _STAT_TEST
		cout << "Ending synapse " << ((EDSynapse*) *itOutput)->getIndex() << " files" << endl;
		#endif
		
		((EDSynapse*) *itOutput)->endSynapseFiles();
		itOutput++;
	}
		#endif
	#endif
}
#endif

#ifdef _NEURON_GRAPH_MODE
void EDNeuron::initNeuronGrapher(NeuronGrapher* ng)
{
	grapher = (NeuronGrapher*) ng;

	#ifdef _SYNAPSE_GRAPH_MODE
	std::vector<Link*>::iterator itOut=outputLinks.begin();
	std::vector<Link*>::iterator endOut=outputLinks.end();

	while (itOut!=endOut)
	{

		((EDSynapse*) *itOut)->initSynapseGrapher((SynapseGrapher*) grapher);
		itOut++;
	}

	std::vector<Link*>::iterator itIn=inputLinks.begin();
	std::vector<Link*>::iterator endIn=inputLinks.end();

	while (itIn!=endIn)
	{
		((EDSynapse*) *itIn)->initSynapseGrapher((SynapseGrapher*) grapher);
		itIn++;
	}
	#endif
}
	//#else
void EDNeuron::initNeuronGrapher()
{
	#ifdef _SINGLE_NEURON_TRACE_MODE
	if (index==SINGLE_NEURON_INDEX)
	{
		grapher = new NeuronGrapher();

		#ifdef _SYNAPSE_GRAPH_MODE
		std::vector<Link*>::iterator itOut=outputLinks.begin();
		std::vector<Link*>::iterator endOut=outputLinks.end();

		while (itOut!=endOut)
		{
			((EDSynapse*) *itOut)->initSynapseGrapher((SynapseGrapher*) grapher);
			itOut++;
		}

		std::vector<Link*>::iterator itIn=inputLinks.begin();
		std::vector<Link*>::iterator endIn=inputLinks.end();

		while (itIn!=endIn)
		{
			((EDSynapse*) *itIn)->initSynapseGrapher((SynapseGrapher*) grapher);
			itIn++;
		}
		#endif
	}
	else
	{
		grapher = 0;
	}
	#else
		#ifdef _SINGLE_SYNAPSE_TRACE_MODE
	std::vector<Link*>::iterator itIn=inputLinks.begin();
	std::vector<Link*>::iterator endIn=inputLinks.end();

	while (itIn!=endIn)
	{
		if (((EDSynapse*) *itIn)->getIndex() == SINGLE_SYNAPSE_INDEX)
		{
			cout << "Initing neuron grapher for post neuron of synapse " << SINGLE_SYNAPSE_INDEX << endl;
			grapher = new NeuronGrapher((EDNeuron*) this);
			((EDSynapse*) *itIn)->initSynapseGrapher();
		}
		itIn++;
	}

	std::vector<Link*>::iterator itOut=outputLinks.begin();
	std::vector<Link*>::iterator endOut=outputLinks.end();

	while (itOut!=endOut)
	{

		if (((EDSynapse*) *itOut)->getIndex() == SINGLE_SYNAPSE_INDEX)
		{
			
			cout << "Initing grapher tracer for pre neuron of synapse " << SINGLE_SYNAPSE_INDEX << endl;
			grapher = new NeuronGrapher((EDNeuron*) this);
			//((EDSynapse*) *itOut)->initSynapseTracer();
		}
		itOut++;
	}
	
	if (grapher)
	{
		std::vector<Link*>::iterator itIn2=inputLinks.begin();
		std::vector<Link*>::iterator endIn2=inputLinks.end();
	
		while (itIn2!=endIn2)
		{
			if (((EDSynapse*) *itIn2)->getIndex() != SINGLE_SYNAPSE_INDEX)
			{
				((EDSynapse*) *itIn2)->initSynapseGrapher((SynapseGrapher*) grapher);
			}
			itIn2++;
		}
			
		std::vector<Link*>::iterator itOut2=outputLinks.begin();
		std::vector<Link*>::iterator endOut2=outputLinks.end();
	
		while (itOut2!=endOut2)
		{
	
			if (((EDSynapse*) *itOut2)->getIndex() != SINGLE_SYNAPSE_INDEX)
			{
				((EDSynapse*) *itOut2)->initSynapseGrapher((SynapseGrapher*) grapher);
			}
			itOut2++;
		}		
	}
		#else
		/*
			#ifdef _SYNAPSE_GRAPH_MODE
	std::vector<Link*>::iterator itOut=outputLinks.begin();
	std::vector<Link*>::iterator endOut=outputLinks.end();

	while (itOut!=endOut)
	{
		((EDSynapse*) *itOut)->initSynapseGrapher();
		itOut++;
	}
			#endif
		*/
		#endif
	#endif
}
//	#endif

void EDNeuron::freeNeuronGrapher()
{
	#ifdef _SYNAPSE_GRAPH_MODE
	std::vector<Link*>::iterator itOut=outputLinks.begin();
	std::vector<Link*>::iterator endOut=outputLinks.end();

	while (itOut!=endOut)
	{

		((EDSynapse*) *itOut)->freeSynapseGrapher();
		itOut++;
	}

	#endif

	#ifdef _SINGLE_NEURON_TRACE_MODE

	std::vector<Link*>::iterator itIn=inputLinks.begin();
	std::vector<Link*>::iterator endIn=inputLinks.end();

	while (itIn!=endIn)
	{

		((EDSynapse*) *itIn)->freeSynapseGrapher();
		itIn++;
	}

	#endif

	if (grapher)
	{
		cout << "Deleting NeuronGrapher " << index << endl;
		delete((NeuronGrapher*) grapher);
	}
	
	grapher = 0;
	//#endif
}

void EDNeuron::graph()
{
	if (grapher)
	{
		cout << "EDNeuron Graphing neuron " << index << endl;
		((NeuronGrapher*) grapher)->graph(this);
	}

		#ifdef _SYNAPSE_GRAPH_MODE
	std::vector<Link*>::iterator itOut=outputLinks.begin();
	std::vector<Link*>::iterator endOut=outputLinks.end();

	while (itOut!=endOut)
	{
		//cout << "Graphing Synapse " << ((EDSynapse*) *itOut)->getIndex() << endl;
		((EDSynapse*) *itOut)->graph();
		itOut++;
	}
			#ifdef _SINGLE_NEURON_TRACE_MODE
	std::vector<Link*>::iterator itIn=inputLinks.begin();
	std::vector<Link*>::iterator endIn=inputLinks.end();

	while (itIn!=endIn)
	{
		//cout << "Graphing Synapse " << ((EDSynapse*) *itOut)->getIndex() << endl;
		((EDSynapse*) *itIn)->graph();
		itIn++;
	}
			#endif
		#endif

}
#endif

#ifdef _NEURON_TRACE_MODE
void EDNeuron::initNeuronTracer()
{
	#ifdef _SINGLE_NEURON_TRACE_MODE
	if (index==SINGLE_NEURON_INDEX)
	{
		tracer = new NeuronTracer((IndexedObject*) this);

		#ifdef _SYNAPSE_TRACE_MODE
		std::vector<Link*>::iterator itIn=inputLinks.begin();
		std::vector<Link*>::iterator endIn=inputLinks.end();

		while (itIn!=endIn)
		{
			((EDSynapse*) *itIn)->initSynapseTracer((SynapseTracer*) tracer);
			itIn++;
		}

		std::vector<Link*>::iterator itOut=outputLinks.begin();
		std::vector<Link*>::iterator endOut=outputLinks.end();

		while (itOut!=endOut)
		{
			((EDSynapse*) *itOut)->initSynapseTracer((SynapseTracer*) tracer);
			itOut++;
		}
		#endif
	}
	else
	{

		tracer = 0;

		#ifdef _SYNAPSE_TRACE_MODE
		std::vector<Link*>::iterator itIn=inputLinks.begin();
		std::vector<Link*>::iterator endIn=inputLinks.end();

		std::vector<Link*>::iterator itOut=outputLinks.begin();
		std::vector<Link*>::iterator endOut=outputLinks.end();

		while (itIn!=endIn)
		{
			((EDSynapse*) *itIn)->initSynapseTracer();
			itIn++;
		}

		while (itOut!=endOut)
		{
			((EDSynapse*) *itOut)->initSynapseTracer();
			itOut++;
		}
		#endif
	}
	#else
		#ifdef _SINGLE_SYNAPSE_TRACE_MODE
			#ifdef _SYNAPSE_TRACE_MODE
	std::vector<Link*>::iterator itIn=inputLinks.begin();
	std::vector<Link*>::iterator endIn=inputLinks.end();

	while (itIn!=endIn)
	{
		if (((EDSynapse*) *itIn)->getIndex() == SINGLE_SYNAPSE_INDEX)
		{
			cout << "Initing neuron tracer for post neuron of synapse " << SINGLE_SYNAPSE_INDEX << endl;
			tracer = new NeuronTracer((IndexedObject*) this);
			((EDSynapse*) *itIn)->initSynapseTracer();
		}
		itIn++;
	}

	std::vector<Link*>::iterator itOut=outputLinks.begin();
	std::vector<Link*>::iterator endOut=outputLinks.end();

	while (itOut!=endOut)
	{

		if (((EDSynapse*) *itOut)->getIndex() == SINGLE_SYNAPSE_INDEX)
		{
			
			cout << "Initing neuron tracer for pre neuron of synapse " << SINGLE_SYNAPSE_INDEX << endl;
			tracer = new NeuronTracer((IndexedObject*) this);
			//((EDSynapse*) *itOut)->initSynapseTracer();
		}
		itOut++;
	}
	
	if (tracer)
	{
		std::vector<Link*>::iterator itIn2=inputLinks.begin();
		std::vector<Link*>::iterator endIn2=inputLinks.end();
	
		while (itIn2!=endIn2)
		{
			if (((EDSynapse*) *itIn2)->getIndex() != SINGLE_SYNAPSE_INDEX)
			{
				((EDSynapse*) *itIn2)->initSynapseTracer((SynapseTracer*) tracer);
			}
			itIn2++;
		}
			
		std::vector<Link*>::iterator itOut2=outputLinks.begin();
		std::vector<Link*>::iterator endOut2=outputLinks.end();
	
		while (itOut2!=endOut2)
		{
	
			if (((EDSynapse*) *itOut2)->getIndex() != SINGLE_SYNAPSE_INDEX)
			{
				((EDSynapse*) *itOut2)->initSynapseTracer((SynapseTracer*) tracer);
			}
			itOut2++;
		}		
	}
			#endif
		#else
			/*
			#ifdef _SYNAPSE_TRACE_MODE
	std::vector<Link*>::iterator itIn=inputLinks.begin();
	std::vector<Link*>::iterator endIn=inputLinks.end();

	std::vector<Link*>::iterator itOut=outputLinks.begin();
	std::vector<Link*>::iterator endOut=outputLinks.end();

	while (itIn!=endIn)
	{
		((EDSynapse*) *itIn)->initSynapseTracer();
		itIn++;
	}

	while (itOut!=endOut)
	{
		((EDSynapse*) *itOut)->initSynapseTracer();
		itOut++;
	}
			#endif
			*/
		#endif
	#endif
}
	//#else
void EDNeuron::initNeuronTracer(NeuronTracer* nt)
{
	tracer = (NeuronTracer*) nt;

	#ifdef _SYNAPSE_TRACE_MODE
	std::vector<Link*>::iterator itIn=inputLinks.begin();
	std::vector<Link*>::iterator endIn=inputLinks.end();

	std::vector<Link*>::iterator itOut=outputLinks.begin();
	std::vector<Link*>::iterator endOut=outputLinks.end();

	while (itIn!=endIn)
	{
		((EDSynapse*) *itIn)->initSynapseTracer((SynapseTracer*) tracer);
		itIn++;
	}

	while (itOut!=endOut)
	{
		((EDSynapse*) *itOut)->initSynapseTracer((SynapseTracer*) tracer);
		itOut++;
	}
	#endif
}
	//#endif

void EDNeuron::freeNeuronTracer()
{
	#ifdef _SYNAPSE_TRACE_MODE
	std::vector<Link*>::iterator itIn=inputLinks.begin();
	std::vector<Link*>::iterator endIn=inputLinks.end();

	std::vector<Link*>::iterator itOut=outputLinks.begin();
	std::vector<Link*>::iterator endOut=outputLinks.end();

	while (itIn!=endIn)
	{
		((EDSynapse*) *itIn)->freeSynapseTracer();
		itIn++;
	}

	while (itOut!=endOut)
	{
		((EDSynapse*) *itOut)->freeSynapseTracer();
		//((SynapseTracer*) tracer)->initSynapseTracer((DynamicSynapse*) *itOut);
		itOut++;
	}
	#endif
/*
	#ifdef _SINGLE_NEURON_TRACE_MODE
	if (index==SINGLE_NEURON_INDEX)
	{
		delete((NeuronTracer*) tracer);
	}
	#else
		#ifdef _SINGLE_SYNAPSE_TRACE_MODE
			#ifdef _SYNAPSE_TRACE_MODE
	std::vector<Link*>::iterator itIn=inputLinks.begin();
	std::vector<Link*>::iterator endIn=inputLinks.end();

	while (itIn!=endIn)
	{
		if (((EDSynapse*) *itIn)->getIndex() == SINGLE_SYNAPSE_INDEX)
		{
			cout << "Initing neuron tracer for post neuron of synapse " << SINGLE_SYNAPSE_INDEX << endl;
			tracer = new NeuronTracer((IndexedObject*) this);
			//((EDSynapse*) *itIn)->initSynapseTracer();
		}
		itIn++;
	}

	std::vector<Link*>::iterator itOut=outputLinks.begin();
	std::vector<Link*>::iterator endOut=outputLinks.end();

	while (itOut!=endOut)
	{

		if (((EDSynapse*) *itOut)->getIndex() == SINGLE_SYNAPSE_INDEX)
		{
			
			cout << "Initing neuron tracer for pre neuron of synapse " << SINGLE_SYNAPSE_INDEX << endl;
			tracer = new NeuronTracer((IndexedObject*) this);
			//((EDSynapse*) *itOut)->initSynapseTracer();
		}
		itOut++;
	}
			#endif
		#else
		#endif
	#endif
*/
	if (tracer)
	{
		cout << "Deleting NeuronTracer " << index << endl;
		delete((NeuronTracer*) tracer);
	}
	tracer = 0;
}
#endif
/****************************************************************************************************************************************/
/******************************************************* Methodes d'affichage ***********************************************************/
/****************************************************************************************************************************************/

std::ostream& operator<<(std::ostream& f, EDNeuron& s)
{
}


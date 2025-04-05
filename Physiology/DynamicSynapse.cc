// DynamicSynapse.cc

// Local Includes
#include "DynamicSynapse.h"

/****************************************************************************************************************************************/
/*********************************************** Methodes de la classe DynamicSynapse ***************************************************/
/****************************************************************************************************************************************/

DynamicSynapse::DynamicSynapse()
{
#ifdef _ONLINE_LEARNING_MODE
	lastTimeOfPreSpike=-1;
	lastTimeOfPostSpike=-1;
#endif

	deltaWeight=0.0;

	realDeltaWeight = 0.0;

#ifdef _TEST
	cout << "SynapseTracer: " << tracer << endl;
#endif
}

DynamicSynapse::DynamicSynapse(Neuron* _pNewPreNeuron, Neuron* _pNewPostNeuron): 
Synapse(_pNewPreNeuron,_pNewPostNeuron)
{
#ifdef _ONLINE_LEARNING_MODE
	lastTimeOfPreSpike=-1;
	lastTimeOfPostSpike=-1;
#endif

	deltaWeight=0.0;

	realDeltaWeight = 0.0;

#ifdef _TEST
	cout << "SynapseTracer: " << tracer << endl;
#endif
}

DynamicSynapse::~DynamicSynapse()
{
#ifdef _TEST
	cout << "~DynamicSynapse" << endl;
#endif
}

double DynamicSynapse::getWeight()
{
	return weight;
}

int DynamicSynapse::getDelay()
{
	return delay;
}

#ifdef _ONLINE_LEARNING_MODE
void DynamicSynapse::updateLastTimeOfPreSpike(int newTimeOfPreSpike)
{
	lastTimeOfPreSpike=newTimeOfPreSpike;

	computeNewWeight();
}
void DynamicSynapse::updateLastTimeOfPostSpike(int newTimeOfPostSpike)
{
	lastTimeOfPostSpike=newTimeOfPostSpike;

	computeNewWeight();
}

void DynamicSynapse::computeNewWeight()
{
	cerr << "Warning, Accessing DynamicSynapse::computeNewWeight virtual method" << endl;
}

void DynamicSynapse::initSynapse()
{
	cerr << "Warning, Accessing DynamicSynapse::initSynapse virtual method" << endl;
}

#endif

/****************************************************************************************************************************************/
/**************************************************** Methodes d'affichage console ******************************************************/
/****************************************************************************************************************************************/

std::ostream& operator<<(std::ostream& f, DynamicSynapse& s)
{
	return f << " Weight: " << s.weight << " Delay: " << s.delay << "\n";
}



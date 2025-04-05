// Synapse.cc

// Local Includes
#include "Synapse.h"

/****************************************************************************************************************************************/
/***************************************************** Methodes de la classe Synapse ****************************************************/
/****************************************************************************************************************************************/

int Synapse::nbSynapses=0;

Synapse::Synapse()
{
	//index=nbSynapses;
	nbSynapses++;
	
#ifdef _TEST
	cout << "SynapseGrapher: " << evoGrapher << endl;
#endif
}


Synapse::~Synapse()
{
#ifdef _TEST
	cout << "~Synapse" << endl;
#endif
	nbSynapses--;
}

Synapse::Synapse(Neuron* newPreNeuron, Neuron* newPostNeuron): Link(newPreNeuron,newPostNeuron)
{
	index=nbSynapses;
	nbSynapses++;
}

void Synapse::computePSPEmission(int)
{

}

/****************************************************************************************************************************************/
/******************************************************* Methodes d'affichage ***********************************************************/
/****************************************************************************************************************************************/

std::ostream& operator<<(std::ostream& f, Synapse& s)
{
	f << "Synapse n° : " << s.index << endl;
	f << (Link&) s;
	return f;
}


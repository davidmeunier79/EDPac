// Neuron.cc

// Local Includes
#include "Neuron.h"

/****************************************************************************************************************************************/
/***************************************************** Methodes de la classe Neuron *****************************************************/
/****************************************************************************************************************************************/

int Neuron::nbNeurons=0;

Neuron::Neuron()
{
	//index=nbNeurons;
	nbNeurons++;
	
#ifdef _TEST
	cout << "NeuronGrapher: " << evoGrapher << endl;
#endif
}

Neuron::~Neuron()
{
	nbNeurons--;
#ifdef _TEST
	cout << "~Neuron" << endl;
#endif
}

void Neuron::computePSPImpact(int timeOfImpact, double weightOfImpact)
{
	cout << "Warning: accessing virtual method" << endl;
}

#ifdef _GRAPHICAL_DISPLAY_MODE
void Neuron::initNeuronDisplayer(NeuronDisplayer* nd)
{
	displayer = (NeuronDisplayer*) nd;
}

void Neuron::display()
{
	((NeuronDisplayer*) displayer)->display(this);;
}

void Neuron::freeNeuronDisplayer()
{
	displayer = 0;
}
#endif
/****************************************************************************************************************************************/
/******************************************************* Methodes d'affichage ***********************************************************/
/****************************************************************************************************************************************/

std::ostream& operator<<(std::ostream& f, Neuron& n)
{
	f << "Neuron: " << n.index << endl;
	f << (Node&) n;

	return f;
}


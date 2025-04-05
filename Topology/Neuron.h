// Neuron.h

#ifndef _NEURON_H
#define _NEURON_H

// STL Includes
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

// Local Includes
#include "../Define.h"
#include "../DefineEDNetwork.h"

#include "../DirectedGraph/Node.h"

#include "../Interfaces/Displayable.h"

class Neuron;
#include "../Windows/NeuronDisplayer.h"
#include "Synapse.h"


/******************************************************************************************************************************************/
/************************************************************ Classe Neuron ***************************************************************/
/******************************************************************************************************************************************/

class Neuron : public Node, public Displayable
{
public:

	Neuron();
	~Neuron();

	static int nbNeurons;

	virtual void computePSPImpact(int timeOfImpact, double weightOfImpact);

#ifdef _GRAPHICAL_DISPLAY_MODE
	friend class AssemblyDisplayer;
	void initNeuronDisplayer(NeuronDisplayer* nd);
	void display();
	void freeNeuronDisplayer();
#endif
	friend std::ostream& operator<<(std::ostream&, Neuron&);
};

#endif

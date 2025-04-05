// Synapse.h

#ifndef _SYNAPSE_H
#define _SYNAPSE_H

//#include <stdio.h>

// STL Includes
#include <iostream>
//#include <fstream>

// Local Includes
#include "../Define.h"
#include "../DefineEDNetwork.h"

#include "../DirectedGraph/Link.h"

class Synapse;
#include "Neuron.h"

using namespace std;

/******************************************************************************************************************************************/
/*********************************************************** Classe Synapse ***************************************************************/
/******************************************************************************************************************************************/

class Synapse : public Link
{
public:
	Synapse();
	virtual ~Synapse();

	Synapse(Neuron* newPreNeuron, Neuron* newPostNeuron);

	static int nbSynapses;

	virtual void computePSPEmission(int);

	friend std::ostream& operator<<(std::ostream&, Synapse&);

};

#endif

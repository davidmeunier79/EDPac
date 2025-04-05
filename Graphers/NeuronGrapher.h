// NeuronGrapher.h

#ifndef _NEURON_GRAPHER_H
#define _NEURON_GRAPHER_H

// STL Includes
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Local Includes
#include "../Define.h"
#include "../DefineEDNetwork.h"

#include "../DefineTracer.h"
#include "../DefineGrapher.h"

#include "../Handlers/Grapher.h"
#include "SynapseGrapher.h"

class NeuronGrapher;
#include "../EDNetwork/EDNeuron.h"

/******************************************************************************************************************************************/
/******************************************************* Classe NeuronGrapher *************************************************************/
/******************************************************************************************************************************************/

class NeuronGrapher : public SynapseGrapher
{
#ifdef _NEURON_TRACE_MODE
	void graphNeuronFiles(EDNeuron* n);
#endif

#ifdef _SYNAPSE_TRACE_MODE
	void graphSynapseFiles(EDNeuron* n);
#endif

public:
	NeuronGrapher();
	NeuronGrapher(IndexedObject* io);
	
	virtual ~NeuronGrapher();

#ifdef _NETWORK_GRAPH_MODE
	void graph(EDNeuron* n);
#endif
};

#endif

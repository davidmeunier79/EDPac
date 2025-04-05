// NetworkGrapher.h

#ifndef _NETWORK_GRAPHER_H
#define _NETWORK_GRAPHER_H

// STL Includes
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class NetworkGrapher;
#include "../EDNetwork/EDNetwork.h"

// Local Includes
#include "../Define.h"
#include "../DefineEDNetwork.h"

#include "../DefineTracer.h"
#include "../DefineGrapher.h"
#include "../Handlers/Grapher.h"

#include "AssemblyGrapher.h"

/******************************************************************************************************************************************/
/********************************************************** Classe NetworkGrapher ***************************************************************/
/******************************************************************************************************************************************/

class NetworkGrapher : public AssemblyGrapher
{

#ifdef _NETWORK_GRAPH_MODE
	#ifdef _NEURON_TRACE_MODE
	void graphNeuronFiles(EDNetwork* t);
	#endif
	#ifdef _SYNAPSE_TRACE_MODE
	void graphSynapseFiles(EDNetwork* t);
	#endif
#endif
	//static TopologyGrapher* theTopologyGrapher;
public:
	NetworkGrapher();
	virtual ~NetworkGrapher();

#ifdef _NETWORK_GRAPH_MODE
	void graph(EDNetwork* t);
#endif
};

#endif

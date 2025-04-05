// AssemblyGrapher.h

#ifndef _ASSEMBLY_GRAPHER_H
#define _ASSEMBLY_GRAPHER_H

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
#include "NeuronGrapher.h"

class AssemblyGrapher;
#include "../EDNetwork/EDAssembly.h"

/******************************************************************************************************************************************/
/****************************************************** Classe AssemblyGrapher ************************************************************/
/******************************************************************************************************************************************/

class AssemblyGrapher : public NeuronGrapher
{
#ifdef _NEURON_TRACE_MODE
	//GnuplotFile* neuronGnuplotFile;
	void graphNeuronFiles(EDAssembly* t);
#endif

#ifdef _SYNAPSE_TRACE_MODE
	//GnuplotFile* synapseGnuplotFile;
	void graphSynapseFiles(EDAssembly* t);
#endif

	//static AssemblyGrapher* theAssemblyGrapher;
public:
	AssemblyGrapher();
	virtual ~AssemblyGrapher();
	
#ifdef _NETWORK_GRAPH_MODE
	void graph(EDAssembly* a);
#endif
};

#endif

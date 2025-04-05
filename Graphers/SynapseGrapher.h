// SynapseGrapher.h

#ifndef _SYNAPSE_GRAPHER_H
#define _SYNAPSE_GRAPHER_H

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

class SynapseGrapher;
#include "../EDNetwork/EDSynapse.h"

/******************************************************************************************************************************************/
/********************************************************** Classe SynapseGrapher ***************************************************************/
/******************************************************************************************************************************************/

class SynapseGrapher : public Grapher
{
#ifdef _NEURON_TRACE_MODE
	void graphNeuronFiles(EDSynapse* s);
#endif

#ifdef _SYNAPSE_TRACE_MODE
	void graphSynapseFiles(EDSynapse* s);
#endif
protected:
 	GnuplotFile* neuronGnuplotFile;
	GnuplotFile* synapseGnuplotFile;

public:
	SynapseGrapher();
	SynapseGrapher(IndexedObject* io);
	
	virtual ~SynapseGrapher();

	void openGrapher();
	void runGrapher();
	void closeGrapher();

#ifdef _SYNAPSE_GRAPH_MODE
	void graph(EDSynapse* s);
#endif
};

#endif

// NeuronTracer.h

#ifndef _NEURON_TRACER_H
#define _NEURON_TRACER_H

// Local Includes
#include "../Define.h"
#include "../DefineEDNetwork.h"
#include "../DefineTracer.h"

#include "../Handlers/Tracer.h"

#include "../Tracers/SynapseTracer.h"

class NeuronTracer;
#include "../EDNetwork/EDNeuron.h"

// STL Includes
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

/******************************************************************************************************************************************/
/******************************************************** Classe NeuronTracer *************************************************************/
/******************************************************************************************************************************************/

class NeuronTracer: public SynapseTracer
{
	DataFile* membraneFile;
	DataFile* thresholdFile;

protected:

	void openTracer();
	void runTracer();
	void closeTracer();
	//static NeuronTracer* theNeuronTracer;
public:
	NeuronTracer();
	NeuronTracer(IndexedObject* io);
	
	virtual ~NeuronTracer();

#ifdef _NEURON_TRACE_MODE
	void tracePSPImpact(EDNeuron* n);
	void traceSpikeEmission(EDNeuron* n);
#endif
};

#endif

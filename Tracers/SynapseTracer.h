// SynapseTracer.h

#ifndef _SYNAPSE_TRACER_H
#define _SYNAPSE_TRACER_H

// Local Includes
#include "../Define.h"
#include "../DefineEDNetwork.h"
#include "../DefineTracer.h"

#include "../Handlers/Tracer.h"

class SynapseTracer;
#include "../EDNetwork/EDSynapse.h"

// STL Includes
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

/******************************************************************************************************************************************/
/******************************************************* Classe SynapseTracer *************************************************************/
/******************************************************************************************************************************************/

class SynapseTracer: public Tracer
{
#ifdef _WEIGHT_TRACE_MODE
	DataFile* weightFile;
#endif
protected:

	void openTracer();
	void runTracer();
	void closeTracer();
	//static SynapseTracer* theSynapseTracer;
public:
	SynapseTracer();
	SynapseTracer(IndexedObject* io);

	virtual ~SynapseTracer();

#ifdef _SYNAPSE_TRACE_MODE
	void initSynapseTracer(EDSynapse* s);
	void freeSynapseTracer(EDSynapse* s);

	void tracePreWeight(EDSynapse* s);
	void tracePostWeight(EDSynapse* s);
#endif
};

#endif

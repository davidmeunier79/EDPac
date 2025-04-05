// AssemblyTracer.h

#ifndef _ASSEMBLY_TRACER_H
#define _ASSEMBLY_TRACER_H

// Local Includes
#include "../Define.h"
#include "../DefineEDNetwork.h"
#include "../DefineTracer.h"

#include "../Handlers/Tracer.h"

#include "../Tracers/NeuronTracer.h"

class AssemblyTracer;
#include "../EDNetwork/EDAssembly.h"

// STL Includes
#include <string>
#include <fstream>
using namespace std;

/******************************************************************************************************************************************/
/******************************************************** Classe AssemblyTracer *************************************************************/
/******************************************************************************************************************************************/

class AssemblyTracer: public NeuronTracer
{
protected:

	void openTracer();
	void runTracer();
	void closeTracer();

public:
	AssemblyTracer();
	virtual ~AssemblyTracer();

#ifdef _NETWORK_TRACE_MODE
	void trace();
#endif

};

#endif

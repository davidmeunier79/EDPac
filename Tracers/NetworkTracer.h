// NetworkTracer.h

#ifndef _NETWORK_TRACER_H
#define _NETWORK_TRACER_H

// Local Includes
//#include "../MPI/MpiGlobals.h"
/*
//#include <mpi++.h>
// Special lam 7.0
#include <mpi.h>
using namespace MPI;
*/
class NetworkTracer;
#include "../EDNetwork/EDNetwork.h"

#include "../Define.h"
#include "../DefineEDNetwork.h"
#include "../DefineTracer.h"

#include "../Handlers/Tracer.h"

#include "../Tracers/AssemblyTracer.h"

// STL Includes
#include <string>
#include <fstream>
using namespace std;

/******************************************************************************************************************************************/
/******************************************************** Classe NetworkTracer *************************************************************/
/******************************************************************************************************************************************/

class NetworkTracer: public AssemblyTracer
{
protected:

	void openTracer();
	void runTracer();
	void closeTracer();
public:
	NetworkTracer();
	virtual ~NetworkTracer();

#ifdef _NETWORK_TRACE_MODE
	void trace();
#endif


};

#endif

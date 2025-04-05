// ZooTracer.h

#ifndef _ZOO_TRACER_H
#define _ZOO_TRACER_H

// Local Includes
#include "../Define.h"
#include "../DefineTracer.h"

#include "../Handlers/Tracer.h"

#include "IndividualTracer.h"

class ZooTracer;
#include "../Zoo/Zoo.h"

// STL Includes
#include <string>
#include <fstream>
using namespace std;

/******************************************************************************************************************************************/
/******************************************************* Classe ZooTracer *************************************************************/
/******************************************************************************************************************************************/

class ZooTracer: public Tracer
{
#ifdef _RUN_MODE
	DataFile* fitnessFile;
#endif
#ifdef _TEST_MODE
	DataFile* goodBehaviourFile;
	DataFile* badBehaviourFile;

	GnuplotFile* gnuplotBehaviourFile;

#endif

public:

	ZooTracer();
	~ZooTracer();

	void openTracer();
	void closeTracer();

#ifdef _POPULATION_TRACE_MODE
	void trace(Individual* p);
	void trace(Zoo* pop);
#endif
};

#endif

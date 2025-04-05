// IndividualTracer.h

#ifndef _INDIVIDUAL_TRACER_H
#define _INDIVIDUAL_TRACER_H

// Local Includes
#include "../Define.h"
#include "../DefineTracer.h"

#include "../Handlers/Tracer.h"

class IndividualTracer;
#include "../GeneticAlgorithm/Individual.h"

// STL Includes
#include <string>
#include <fstream>
using namespace std;

/******************************************************************************************************************************************/
/******************************************************* Classe IndividualTracer *************************************************************/
/******************************************************************************************************************************************/

class IndividualTracer: public Tracer
{
#ifdef _RUN_MODE
	DataFile* lifeLevelFile;
	DataFile* positionFile;
#endif

public:

	void openTracer();
	void closeTracer();

	IndividualTracer();
	~IndividualTracer();


#ifdef _INDIVIDUAL_TRACE_MODE
	void trace(Individual* pac);
#endif
};
#endif

// IndividualGrapher.h

#ifndef _INDIVIDUAL_GRAPHER_H
#define _INDIVIDUAL_GRAPHER_H

// Local Includes
#include "../Define.h"
#include "../DefineTracer.h"
#include "../DefineGrapher.h"

#include "../Handlers/Grapher.h"

class IndividualGrapher;
#include "../GeneticAlgorithm/Individual.h"

// STL Includes
#include <string>
#include <fstream>
using namespace std;

/******************************************************************************************************************************************/
/******************************************************* Classe IndividualGrapher *************************************************************/
/******************************************************************************************************************************************/

class IndividualGrapher: public Grapher
{
#ifdef _RUN_MODE
	GnuplotFile* lifeGnuplotFile;
#endif
	void openGrapher();
	void runGrapher();
	void closeGrapher();

public:

	IndividualGrapher();
	~IndividualGrapher();

#ifdef _INDIVIDUAL_GRAPH_MODE
	void graph();
#endif
};
#endif

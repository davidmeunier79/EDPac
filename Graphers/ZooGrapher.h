// ZooGrapher.h

#ifndef _ZOO_GRAPHER_H
#define _ZOO_GRAPHER_H

// STL Includes
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Local Includes
#include "../Define.h"
#include "../DefineTracer.h"
#include "../DefineGrapher.h"

#include "../Handlers/Grapher.h"

#include "IndividualGrapher.h"

class ZooGrapher;
#include "../Zoo/Zoo.h"

/******************************************************************************************************************************************/
/**************************************************** Classe ZooGrapher ************************************************************/
/******************************************************************************************************************************************/

class ZooGrapher: public Grapher
{
#ifdef _RUN_MODE
	GnuplotFile* populationGnuplotFile;
#endif

#ifdef _TEST_MODE
	GnuplotFile* gnuplotBehaviourFile;
#endif

	void openGrapher();
	void runGrapher();
	void closeGrapher();

public:
	ZooGrapher();
	~ZooGrapher();

#ifdef _POPULATION_GRAPH_MODE
	void graph(Zoo* p);
#endif
};

#endif

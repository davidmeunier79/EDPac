// ZooStater.h

#ifndef _ZOO_STATER_H
#define _ZOO_STATER_H

// STL Includes
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Local Includes
#include "../Define.h"
#include "../DefineZoo.h"

#include "../DefineTester.h"
#include "../DefineStater.h"

#include "../Handlers/Stater.h"

#include "../Handlers/Accumulater.h"

#include "../Files/DistributionGnuplotFile.h"
#include "../Files/AccuDataFile.h"

#include "../GeneticAlgorithm/Individual.h"

class ZooStater;
#include "../Zoo/Zoo.h"

/******************************************************************************************************************************************/
/****************************************************** Classe ZooStater *************************************************************/
/******************************************************************************************************************************************/

class ZooStater : public Stater
{
#ifdef _RUN_MODE
	DataFile* meanFitnessFile;
	DataFile* bestFitnessFile;

	DataFile* nbStepsFile;

	DataFile* nbPacgumsFile;
	DataFile* nbPreysFile;
	DataFile* nbMvtAvantsFile;

	Accumulater* meanFitness;

	Accumulater* meanSteps;

	Accumulater* meanPacgums;
	Accumulater* meanPreys;

	Accumulater* meanMvtAvants;
#endif

#ifdef _TEST_MODE

	#ifdef _RUN_MODE
	Accumulater* scoreBeforeRun;
	Accumulater* scoreAfterRun;

	AccuDataFile* scoreBeforeRunFile;
	AccuDataFile* scoreAfterRunFile;
	#endif

	Accumulater* meanGoodBehaviour;
	Accumulater* meanBadBehaviour;

	//DataFile* goodBehaviourFile;
	//DataFile* badBehaviourFile;

	AccuDataFile* meanGoodBehaviourFile;
	AccuDataFile* meanBadBehaviourFile;
#endif

	DistributionGnuplotFile* fitnessGnuplotFile;

	void openTracer();
	void closeTracer();

	void openGrapher();
	void runGrapher();
	void closeGrapher();


public:

	ZooStater();
	~ZooStater();

	void flushAccumulater();
	void initAccumulaters();


#ifdef _TEST_MODE
	#ifdef _RUN_MODE
	void statScoreBeforeRun(Individual* pac);
	void statScoreAfterRun(Individual* pac);
	#endif

	void trace(Individual* pac);
#endif

#ifdef _POPULATION_STAT_MODE
	void trace(Zoo* pop);
	virtual void graph();
	void stat(Zoo* pop);
#endif
};

#endif

// EvoNetwork.h

#ifndef _EVO_NETWORK_H
#define _EVO_NETWORK_H

//#include <stdio.h>

// Local Includes
#include "../Define.h"
#include "../DefinePhysiology.h"
#include "../DefineZoo.h"

#include "../DefineEDNetwork.h"
#include "../DefineGA.h"
#include "../DefineMPI.h"


#include "../DefineWindow.h"

#include "../DefineStater.h"
#include "../DefineTracer.h"

#include "../Interfaces/EvoIndexable.h"
#include "../Interfaces/EvalIndexable.h"
#include "../Interfaces/TestIndexable.h"
#include "../Interfaces/Testable.h"

#include "../EDNetwork/EDNetwork.h"

class EvoNetwork;
#include "../Testers/ActivityTester.h"
#include "../Testers/InputTester.h"

/*
class EvoNetwork;
friend class NetworkTester;
*/
/******************************************************************************************************************************************/
/****************************************************** Classe EvoNetwork *****************************************************************/
/******************************************************************************************************************************************/

class EvoNetwork: public EDNetwork, public EvoIndexable, public EvalIndexable, public Testable
{
#ifdef _PARAMETRIC_TEST_MODE
	int paramIndex;
#endif

	void integrateSynchro();
	void integrateVoidSynchro();
	void integrateSkipSynchro();
/*
	void initNetworkStater();
	void endNetworkStater();
*/
	void reInitTopology();
	void reInitEDNetwork();

public:
	EvoNetwork();
	~EvoNetwork();

	void integrateBirthFlash();
	
	void statEvo();
	
#ifdef _RUN_MODE
	void run();
	void runNetwork();
#endif

#ifdef _NETWORK_STAT_MODE
	void initEvoNetworkFiles();
	void endEvoNetworkFiles();
#endif

#ifdef _TEST_MODE
	void test();
	void testNetwork();
#endif

//#ifdef _TEST_BEST_POPULATION_MODE
	void testBest();
	void testBestIndividual();
	
	#ifdef _MULTI_TEST_MODE
	void meanDataFiles();
	#endif
//#endif
};

#endif

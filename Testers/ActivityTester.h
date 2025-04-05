// ActivityTester.h

#ifndef _ACTIVITY_TESTER_H
#define _ACTIVITY_TESTER_H

// C includes
// Spécial itoa
#include <stdio.h>
#include <stdlib.h>

// STL Includes
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Local Includes
#include "../Define.h"
#include "../DefineGA.h"
#include "../DefineZoo.h"
#include "../DefineEDNetwork.h"

#include "../DefineTester.h"
#include "../DefineStater.h"
#include "../DefineTracer.h"
#include "../DefineGrapher.h"

#include "../Staters/ActivityStater.h"

#include "../Handlers/Tester.h"

class ActivityTester;
#include "../GeneticAlgorithm/EvoNetwork.h"

//extern int currentParamIndex;

/******************************************************************************************************************************************/
/*************************************************** Classe ActivityTester ************************************************************/
/******************************************************************************************************************************************/

class ActivityTester : public Tester, public ActivityStater
{
	GnuplotFile* activityTestGnuplotFile;
	

#ifdef _GLOBAL_STAT_MODE
	#ifdef _MULTI_TEST_MODE
		#ifdef _PARAMETRIC_TEST_MODE
	
	DataFile* timeFrequencyTestFile;
	DataFile* highTimeFrequencyTestFile;
			#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	DataFile* excitTempDevRepartitionTestFile;
	DataFile* inhibTempDevRepartitionTestFile;
			#endif
			
	DataFile* ISIRepartitionTestFile;
	DataFile* SpikeRepartitionTestFile;
	DataFile* AssemblySpikeRepartitionTestFile;
	
			#ifdef _PHASE_TEST_MODE
			
	DataFile* diffTimeFrequencyTestFile;
	DataFile* diffHighTimeFrequencyTestFile;
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	DataFile* diffExcitTempDevRepartitionTestFile;
	DataFile* diffInhibTempDevRepartitionTestFile;
				#endif
				
	DataFile* diffISIRepartitionTestFile;
	DataFile* diffSpikeRepartitionTestFile;
	DataFile* diffAssemblySpikeRepartitionTestFile;
	
				#ifdef _TRANSITION_STAT_MODE
	Accumulater timeFrequencyTest[NB_HIGH_FREQUENCY_BINS][2*(1+2*NB_TESTED_ANIMALS+1)][NB_PARAMETRIC_TESTS];
	Accumulater highTimeFrequencyTest[NB_HIGH_FREQUENCY_BINS][2*(1+2*NB_TESTED_ANIMALS+1)][NB_PARAMETRIC_TESTS];
	
					#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	Accumulater excitPreTempDevRepartitionTest[100][2*(1+2*NB_TESTED_ANIMALS+1)][NB_PARAMETRIC_TESTS];
	Accumulater excitPostTempDevRepartitionTest[100][2*(1+2*NB_TESTED_ANIMALS+1)][NB_PARAMETRIC_TESTS];
	
	Accumulater inhibPreTempDevRepartitionTest[100][2*(1+2*NB_TESTED_ANIMALS+1)][NB_PARAMETRIC_TESTS];
	Accumulater inhibPostTempDevRepartitionTest[100][2*(1+2*NB_TESTED_ANIMALS+1)][NB_PARAMETRIC_TESTS];
					#endif
					
	Accumulater ISIRepartitionTest[100][2*(1+2*NB_TESTED_ANIMALS+1)][NB_PARAMETRIC_TESTS];
	Accumulater SpikeRepartitionTest[NB_HIDDEN_NEURONS][2*(1+2*NB_TESTED_ANIMALS+1)][NB_PARAMETRIC_TESTS];
	Accumulater AssemblySpikeRepartitionTest[NB_ASSEMBLIES][2*(1+2*NB_TESTED_ANIMALS+1)][NB_PARAMETRIC_TESTS];
	
				#else
	Accumulater timeFrequencyTest[NB_HIGH_FREQUENCY_BINS][1+2*NB_TESTED_ANIMALS+1][NB_PARAMETRIC_TESTS];
	Accumulater highTimeFrequencyTest[NB_HIGH_FREQUENCY_BINS][1+2*NB_TESTED_ANIMALS+1][NB_PARAMETRIC_TESTS];
					#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	Accumulater excitPreTempDevRepartitionTest[100][1+2*NB_TESTED_ANIMALS+1][NB_PARAMETRIC_TESTS];
	Accumulater excitPostTempDevRepartitionTest[100][1+2*NB_TESTED_ANIMALS+1][NB_PARAMETRIC_TESTS];
	
	Accumulater inhibPreTempDevRepartitionTest[100][1+2*NB_TESTED_ANIMALS+1][NB_PARAMETRIC_TESTS];
	Accumulater inhibPostTempDevRepartitionTest[100][1+2*NB_TESTED_ANIMALS+1][NB_PARAMETRIC_TESTS];
					#endif
					
	Accumulater ISIRepartitionTest[100][1+2*NB_TESTED_ANIMALS+1][NB_PARAMETRIC_TESTS];
	Accumulater SpikeRepartitionTest[NB_HIDDEN_NEURONS][1+2*NB_TESTED_ANIMALS+1][NB_PARAMETRIC_TESTS];
	Accumulater AssemblySpikeRepartitionTest[NB_ASSEMBLIES][1+2*NB_TESTED_ANIMALS+1][NB_PARAMETRIC_TESTS];
	
	
				#endif
		
			#else
	Accumulater timeFrequencyTest[NB_HIGH_FREQUENCY_BINS][NB_PARAMETRIC_TESTS];
	Accumulater highTimeFrequencyTest[NB_HIGH_FREQUENCY_BINS][NB_PARAMETRIC_TESTS];
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	Accumulater excitPreTempDevRepartitionTest[100][NB_PARAMETRIC_TESTS];
	Accumulater excitPostTempDevRepartitionTest[100][NB_PARAMETRIC_TESTS];
	
	Accumulater inhibPreTempDevRepartitionTest[100][NB_PARAMETRIC_TESTS];
	Accumulater inhibPostTempDevRepartitionTest[100][NB_PARAMETRIC_TESTS];
				#endif
				
	Accumulater ISIRepartitionTest[100][NB_PARAMETRIC_TESTS];
			#endif
		#else	
			#ifdef _PHASE_TEST_MODE
	
	DataFile* timeFrequencyTestFile;
	DataFile* highTimeFrequencyTestFile;
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	DataFile* excitTempDevRepartitionTestFile;
	DataFile* inhibTempDevRepartitionTestFile;
				#endif
				
	DataFile* ISIRepartitionTestFile;
	DataFile* SpikeRepartitionTestFile;
	DataFile* AssemblySpikeRepartitionTestFile;
	
	DataFile* diffTimeFrequencyTestFile;
	DataFile* diffHighTimeFrequencyTestFile;
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	DataFile* diffExcitTempDevRepartitionTestFile;
	DataFile* diffInhibTempDevRepartitionTestFile;
				#endif
				
	DataFile* diffISIRepartitionTestFile;
	DataFile* diffSpikeRepartitionTestFile;
	DataFile* diffAssemblySpikeRepartitionTestFile;
	
				#ifdef _TRANSITION_STAT_MODE
	Accumulater timeFrequencyTest[NB_HIGH_FREQUENCY_BINS][2*(1+2*NB_TESTED_ANIMALS+1)];
	Accumulater highTimeFrequencyTest[NB_HIGH_FREQUENCY_BINS][2*(1+2*NB_TESTED_ANIMALS+1)];
					#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	Accumulater excitPreTempDevRepartitionTest[100][2*(1+2*NB_TESTED_ANIMALS+1)];
	Accumulater excitPostTempDevRepartitionTest[100][2*(1+2*NB_TESTED_ANIMALS+1)];

	Accumulater inhibPreTempDevRepartitionTest[100][2*(1+2*NB_TESTED_ANIMALS+1)];
	Accumulater inhibPostTempDevRepartitionTest[100][2*(1+2*NB_TESTED_ANIMALS+1)];
					#endif
					
	Accumulater ISIRepartitionTest[100][2*(1+2*NB_TESTED_ANIMALS+1)];
	Accumulater SpikeRepartitionTest[NB_HIDDEN_NEURONS][2*(1+2*NB_TESTED_ANIMALS+1)];
	Accumulater AssemblySpikeRepartitionTest[NB_ASSEMBLIES][2*(1+2*NB_TESTED_ANIMALS+1)];
				#else
	Accumulater timeFrequencyTest[NB_HIGH_FREQUENCY_BINS][1+2*NB_TESTED_ANIMALS+1];
	Accumulater highTimeFrequencyTest[NB_HIGH_FREQUENCY_BINS][1+2*NB_TESTED_ANIMALS+1];
					#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	Accumulater excitPreTempDevRepartitionTest[100][1+2*NB_TESTED_ANIMALS+1];
	Accumulater excitPostTempDevRepartitionTest[100][1+2*NB_TESTED_ANIMALS+1];

	Accumulater inhibPreTempDevRepartitionTest[100][1+2*NB_TESTED_ANIMALS+1];
	Accumulater inhibPostTempDevRepartitionTest[100][1+2*NB_TESTED_ANIMALS+1];
					#endif
	Accumulater ISIRepartitionTest[100][1+2*NB_TESTED_ANIMALS+1];
	Accumulater SpikeRepartitionTest[NB_HIDDEN_NEURONS][1+2*NB_TESTED_ANIMALS+1];
	Accumulater AssemblySpikeRepartitionTest[NB_ASSEMBLIES][1+2*NB_TESTED_ANIMALS+1];
				#endif
			#endif
		#endif
	
	void openTracer();
	void closeTracer();

	void openGrapher();
	void runGrapher();
	void closeGrapher();
	
	void traceMeanIndexedFiles(string dataFileName);
	void traceTemporalMeanIndexedFiles(string dataFileName);
	void traceTemporalMeanNegativeIndexedFiles(string dataFileName);
	void traceMeanFiles(string dataFileName);
	#endif
#endif
public:

	ActivityTester();
	ActivityTester(IndexedObject* io);

	virtual ~ActivityTester();

	

#ifdef _GLOBAL_STAT_MODE
	#ifdef _MULTI_TEST_MODE
	void initAccumulaters();
	
	void trace();
	virtual void graph();
	
		#ifdef _PARAMETRIC_TEST_MODE
	void stat(int paramIndex);
		#else	
			#ifdef _PHASE_TEST_MODE
	void stat();
			#endif
		#endif
	#endif
#endif
};

#endif

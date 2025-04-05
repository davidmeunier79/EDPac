// ActivityTester.h

#ifndef _INPUT_TESTER_H
#define _INPUT_TESTER_H

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

#include "../Staters/InputStater.h"

#include "../Handlers/Tester.h"

class InputTester;
#include "../GeneticAlgorithm/EvoNetwork.h"

//extern int currentParamIndex;

/******************************************************************************************************************************************/
/*************************************************** Classe InputTester ************************************************************/
/******************************************************************************************************************************************/

class InputTester : public Tester, public InputStater
{
	GnuplotFile* activityInputTestGnuplotFile;

#ifdef _GLOBAL_STAT_MODE
	#ifdef _MULTI_TEST_MODE
		#ifdef _PARAMETRIC_TEST_MODE
	
	DataFile* timeFrequencyInputTestFile;
	DataFile* highTimeFrequencyInputTestFile;
	
			#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	DataFile* excitTempDevRepartitionInputTestFile;
	DataFile* inhibTempDevRepartitionInputTestFile;
			#endif
			
	DataFile* ISIRepartitionInputTestFile;
	
			#ifdef _PHASE_TEST_MODE
			
	DataFile* diffTimeFrequencyInputTestFile;
	DataFile* diffHighTimeFrequencyInputTestFile;
	
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	DataFile* diffExcitTempDevRepartitionInputTestFile;
	DataFile* diffInhibTempDevRepartitionInputTestFile;
				#endif
				
	DataFile* diffISIRepartitionInputTestFile;
	
	Accumulater timeFrequencyInputTest[NB_HIGH_FREQUENCY_BINS][1+2*NB_TESTED_ANIMALS+1][NB_PARAMETRIC_TESTS];
	Accumulater highTimeFrequencyInputTest[NB_HIGH_FREQUENCY_BINS][1+2*NB_TESTED_ANIMALS+1][NB_PARAMETRIC_TESTS];

				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	Accumulater excitPreTempDevRepartitionInputTest[100][1+2*NB_TESTED_ANIMALS+1][NB_PARAMETRIC_TESTS];
	Accumulater excitPostTempDevRepartitionInputTest[100][1+2*NB_TESTED_ANIMALS+1][NB_PARAMETRIC_TESTS];
	
	Accumulater inhibPreTempDevRepartitionInputTest[100][1+2*NB_TESTED_ANIMALS+1][NB_PARAMETRIC_TESTS];
	Accumulater inhibPostTempDevRepartitionInputTest[100][1+2*NB_TESTED_ANIMALS+1][NB_PARAMETRIC_TESTS];
				#endif
				
	Accumulater ISIRepartitionInputTest[100][1+2*NB_TESTED_ANIMALS+1][NB_PARAMETRIC_TESTS];
	
			#else
	Accumulater timeFrequencyInputTest[NB_HIGH_FREQUENCY_BINS][NB_PARAMETRIC_TESTS];
	Accumulater highTimeFrequencyInputTest[NB_HIGH_FREQUENCY_BINS][NB_PARAMETRIC_TESTS];

				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	Accumulater excitPreTempDevRepartitionInputTest[100][NB_PARAMETRIC_TESTS];
	Accumulater excitPostTempDevRepartitionInputTest[100][NB_PARAMETRIC_TESTS];
	
	Accumulater inhibPreTempDevRepartitionInputTest[100][NB_PARAMETRIC_TESTS];
	Accumulater inhibPostTempDevRepartitionInputTest[100][NB_PARAMETRIC_TESTS];
				#endif
				
	Accumulater ISIRepartitionInputTest[100][NB_PARAMETRIC_TESTS];
			#endif
		#else	
			#ifdef _PHASE_TEST_MODE
	
	DataFile* timeFrequencyInputTestFile;
	DataFile* highTimeFrequencyInputTestFile;
	
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	DataFile* excitTempDevRepartitionInputTestFile;
	DataFile* inhibTempDevRepartitionInputTestFile;
				#endif
				
	DataFile* ISIRepartitionInputTestFile;
	DataFile* SpikeRepartitionInputTestFile;
	DataFile* AssemblySpikeRepartitionInputTestFile;
	
	DataFile* diffTimeFrequencyInputTestFile;
	DataFile* diffHighTimeFrequencyInputTestFile;
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	DataFile* diffExcitTempDevRepartitionInputTestFile;
	DataFile* diffInhibTempDevRepartitionInputTestFile;
				#endif
				
	DataFile* diffISIRepartitionInputTestFile;
	DataFile* diffSpikeRepartitionInputTestFile;
	DataFile* diffAssemblySpikeRepartitionInputTestFile;
	
				#ifdef _TRANSITION_STAT_MODE
	Accumulater timeFrequencyInputTest[NB_HIGH_FREQUENCY_BINS][2*(1+2*NB_TESTED_ANIMALS+1)];
	Accumulater highTimeFrequencyInputTest[NB_HIGH_FREQUENCY_BINS][2*(1+2*NB_TESTED_ANIMALS+1)];
	
					#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	Accumulater excitPreTempDevRepartitionInputTest[100][2*(1+2*NB_TESTED_ANIMALS+1)];
	Accumulater excitPostTempDevRepartitionInputTest[100][2*(1+2*NB_TESTED_ANIMALS+1)];

	Accumulater inhibPreTempDevRepartitionInputTest[100][2*(1+2*NB_TESTED_ANIMALS+1)];
	Accumulater inhibPostTempDevRepartitionInputTest[100][2*(1+2*NB_TESTED_ANIMALS+1)];
					#endif
					
	Accumulater ISIRepartitionInputTest[100][2*(1+2*NB_TESTED_ANIMALS+1)];
	Accumulater SpikeRepartitionInputTest[NB_HIDDEN_NEURONS][2*(1+2*NB_TESTED_ANIMALS+1)];
	Accumulater AssemblySpikeRepartitionInputTest[NB_ASSEMBLIES][2*(1+2*NB_TESTED_ANIMALS+1)];
				#else
	Accumulater timeFrequencyInputTest[NB_HIGH_FREQUENCY_BINS][1+2*NB_TESTED_ANIMALS+1];
	Accumulater highTimeFrequencyInputTest[NB_HIGH_FREQUENCY_BINS][1+2*NB_TESTED_ANIMALS+1];
	
					#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	Accumulater excitPreTempDevRepartitionInputTest[100][1+2*NB_TESTED_ANIMALS+1];
	Accumulater excitPostTempDevRepartitionInputTest[100][1+2*NB_TESTED_ANIMALS+1];

	Accumulater inhibPreTempDevRepartitionInputTest[100][1+2*NB_TESTED_ANIMALS+1];
	Accumulater inhibPostTempDevRepartitionInputTest[100][1+2*NB_TESTED_ANIMALS+1];
					#endif
					
	Accumulater ISIRepartitionInputTest[100][1+2*NB_TESTED_ANIMALS+1];
	Accumulater SpikeRepartitionInputTest[NB_HIDDEN_NEURONS][1+2*NB_TESTED_ANIMALS+1];
	Accumulater AssemblySpikeRepartitionInputTest[NB_ASSEMBLIES][1+2*NB_TESTED_ANIMALS+1];
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

	InputTester();
	InputTester(IndexedObject* io);

	virtual ~InputTester();

	

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

// ExcitSynapseStater.h

#ifndef _EXCIT_SYNAPSE_STATER_H
#define _EXCIT_SYNAPSE_STATER_H

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
#include "../DefinePhysiology.h"

//#include "../DefineGA.h"
//#include "../DefineZoo.h"
#include "../DefineStater.h"

#include "../Handlers/Stater.h"

#include "../Handlers/Accumulater.h"

#include "SynapseStater.h"

class ExcitSynapseStater;
#include "../EDNetwork/EDExcitSynapse.h"

/******************************************************************************************************************************************/
/*************************************************** Classe ExcitSynapseStater ************************************************************/
/******************************************************************************************************************************************/

class ExcitSynapseStater : public Stater
{

protected:
#ifdef _ASSEMBLY_STAT_MODE

	#ifdef _GLOBAL_SYNAPSE_STAT_MODE
		#ifndef _MULTI_TEST_MODE
		// Potentiation
		
			#ifndef _PHASE_TEST_MODE
	// Fichers traces
	DataFile* excitPotMeanPSPWeightsFile;
	DataFile* excitPotMeanWeightVariationFile;
	DataFile* excitPotRealWeightVariationFile;
			#endif
	
	// Accus
	Accumulater* excitPotPSPWeights;
	Accumulater* excitPotWeightVariation;
	Accumulater* excitPotRealWeightVariation;

		// Depression
		
			#ifndef _PHASE_TEST_MODE
	// Fichers traces
	DataFile* excitDepMeanPSPWeightsFile;
	DataFile* excitDepMeanWeightVariationFile;
	DataFile* excitDepRealWeightVariationFile;
			#endif
	// Accus
	Accumulater* excitDepPSPWeights;
	Accumulater* excitDepWeightVariation;
	Accumulater* excitDepRealWeightVariation;

		// Déviations temporelles
	
	Accumulater* excitPreTemporalDeviation;
	Accumulater* excitPostTemporalDeviation;
	
			#ifndef _PHASE_TEST_MODE
	DataFile* excitPreTemporalDeviationFile;
	DataFile* excitPostTemporalDeviationFile;
	
	DataFile* preDelayRepartitionFile;
	DataFile* postDelayRepartitionFile;
			#endif

		// Repartition des délais
	Counter preDelayRepartition[DELAY];
	Counter postDelayRepartition[DELAY];
	

		#endif
	
		#ifndef _MULTI_TEST_MODE
			#ifndef _PHASE_TEST_MODE
	DataFile* excitTempDevRepartitionFile;
//#ifdef _SINGLE_ASSEMBLY_STAT_MODE
	// fichier graphs
	GnuplotFile* excitGnuplotSynapseFile;
//#endif
	void openTracer();
	void closeTracer();

	void openGrapher();
	void runGrapher();
	void closeGrapher();
			#endif	
		#endif
			
	Counter excitPreTempDevRepartition[100];
	Counter excitPostTempDevRepartition[100];
	#endif
#endif

public:
 
	ExcitSynapseStater();
	ExcitSynapseStater(IndexedObject* io);

	~ExcitSynapseStater();
	
#ifdef _ASSEMBLY_STAT_MODE
	#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	void flushCounters();
	void initCounters();

	int getExcitPreTempDevRepartition(int i);
	int getExcitPostTempDevRepartition(int i);

	bool isVoidExcitPreTempDevRepartition(int index);
	bool isVoidExcitPostTempDevRepartition(int index);

	void freeVoidExcitPreTempDevRepartition(int index);
	void freeVoidExcitPostTempDevRepartition(int index);
	
	void statPreTemporalVariation(int tempVariation);
	void statPostTemporalVariation(int tempVariation);

	//#ifndef _MULTI_TEST_MODE
	//	#ifndef _PHASE_TEST_MODE
	void trace(int timeOfTrace);
	void traceVoid();
	//	#endif
	//#endif
	
	void graph();
	
	void statPotentiation(EDExcitSynapse* eds);
	void statDepression(EDExcitSynapse* eds);
	#endif
#endif
};

#endif

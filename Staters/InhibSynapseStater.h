// InhibSynapseStater.h

#ifndef _INHIB_SYNAPSE_STATER_H
#define _INHIB_SYNAPSE_STATER_H

// C includes
// Sp?cial itoa
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

class InhibSynapseStater;
#include "../EDNetwork/EDInhibSynapse.h"

/******************************************************************************************************************************************/
/*************************************************** Classe InhibSynapseStater ************************************************************/
/******************************************************************************************************************************************/

class InhibSynapseStater : public Stater
{
protected:
#ifdef _ASSEMBLY_STAT_MODE
	#ifdef _GLOBAL_SYNAPSE_STAT_MODE
		#ifndef _MULTI_TEST_MODE
		// Potentiation
			#ifndef _PHASE_TEST_MODE
	// Fichers traces
	DataFile* inhibPotMeanPSPWeightsFile;
	DataFile* inhibPotMeanWeightVariationFile;
	DataFile* inhibPotRealWeightVariationFile;
			#endif
	
	// Accus
	Accumulater* inhibPotPSPWeights;
	Accumulater* inhibPotWeightVariation;
	Accumulater* inhibPotRealWeightVariation;

		// Depression
			#ifndef _PHASE_TEST_MODE
	// Fichers traces
	DataFile* inhibDepMeanPSPWeightsFile;
	DataFile* inhibDepMeanWeightVariationFile;
	DataFile* inhibDepRealWeightVariationFile;
			#endif
	
	// Accus
	Accumulater* inhibDepPSPWeights;
	Accumulater* inhibDepWeightVariation;
	Accumulater* inhibDepRealWeightVariation;

		// D?viations temporelles
	Accumulater* inhibPreTemporalDeviation;
	Accumulater* inhibPostTemporalDeviation;
	
			#ifndef _PHASE_TEST_MODE
	DataFile* inhibPreTemporalDeviationFile;
	DataFile* inhibPostTemporalDeviationFile;
			#endif
		

		#endif
	
		#ifndef _MULTI_TEST_MODE
	
			#ifndef _PHASE_TEST_MODE
	DataFile* inhibTempDevRepartitionFile;
//#ifdef _SINGLE_ASSEMBLY_STAT_MODE
	// fichier graphs
	GnuplotFile* inhibGnuplotSynapseFile;
//#endif
	void openTracer();
	void closeTracer();

	void openGrapher();
	void runGrapher();
	void closeGrapher();
			#endif
		#endif
	Counter inhibPreTempDevRepartition[100];
	Counter inhibPostTempDevRepartition[100];
	#endif
#endif

public:

	InhibSynapseStater();
	InhibSynapseStater(IndexedObject* io);

	~InhibSynapseStater();


#ifdef _ASSEMBLY_STAT_MODE
	#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	void flushCounters();
	void initCounters();

	//#ifndef _MULTI_TEST_MODE
	//	#ifndef _PHASE_TEST_MODE
	void trace(int timeOfTrace);
	void traceVoid();
	//	#endif
	//#endif
	
	void graph();
	
	int getInhibPreTempDevRepartition(int i);
	int getInhibPostTempDevRepartition(int i);

	bool isVoidInhibPreTempDevRepartition(int index);
	bool isVoidInhibPostTempDevRepartition(int index);

	void freeVoidInhibPreTempDevRepartition(int index);
	void freeVoidInhibPostTempDevRepartition(int index);
	
	void statPreTemporalVariation(int tempVariation);
	void statPostTemporalVariation(int tempVariation);

	void statPotentiation(EDInhibSynapse* eds);
	void statDepression(EDInhibSynapse* eds);
	#endif
#endif
};

#endif

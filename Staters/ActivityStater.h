// ActivityStater.h

#ifndef _ACTIVITY_STATER_H
#define _ACTIVITY_STATER_H

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

#include "../DefineStater.h"
#include "../DefineTracer.h"

class ActivityStater;
#include "../EDNetwork/EDNetwork.h"

#include "../Staters/NeuronStater.h"


/******************************************************************************************************************************************/
/*************************************************** Classe ActivityStater ************************************************************/
/******************************************************************************************************************************************/

class ActivityStater : public NeuronStater
{

#ifdef _GLOBAL_STAT_MODE
	#ifdef _MULTI_TEST_MODE
		#ifndef _PARAMETRIC_TEST_MODE
			#ifndef _PHASE_TEST_MODE
	GnuplotFile* activityGnuplotFile;
			#endif
		#endif
	
protected:	
	Accumulater meanTimeFrequency[NB_FREQUENCY_BINS];
	Accumulater meanHighTimeFrequency[NB_HIGH_FREQUENCY_BINS];
	
	Accumulater meanISIRepartition[100];
	Accumulater meanSpikeRepartition[NB_HIDDEN_NEURONS];
	
		#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	Accumulater meanExcitPreTempDevRepartition[100];
	Accumulater meanExcitPostTempDevRepartition[100];
	
	Accumulater meanInhibPreTempDevRepartition[100];
	Accumulater meanInhibPostTempDevRepartition[100];
		#endif
		
	
		#ifndef _PARAMETRIC_TEST_MODE
			#ifndef _PHASE_TEST_MODE
	DataFile* meanTimeFrequencyFile;
	DataFile* meanHighTimeFrequencyFile;
	
	DataFile* meanISIRepartitionFile;
	DataFile* meanSpikeRepartitionFile;
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	DataFile* meanExcitTempDevRepartitionFile;
	DataFile* meanInhibTempDevRepartitionFile;
				#endif
				
	
	void openTracer();
	void closeTracer();

	void openGrapher();
	void runGrapher();
	void closeGrapher();
			#endif
		#endif
	#endif
#endif

public:

	ActivityStater();
	ActivityStater(IndexedObject* io);

	virtual ~ActivityStater();
	
#ifdef _GLOBAL_STAT_MODE
	#ifdef _MULTI_TEST_MODE
	void initAccumulaters();
	
		#ifndef _PARAMETRIC_TEST_MODE
			#ifndef _PHASE_TEST_MODE
	virtual void graph();
	void trace();
	
			#endif
		#endif
	void stat();
	#endif
#endif
	
};

#endif

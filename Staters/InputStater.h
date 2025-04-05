// InputStater.h

#ifndef _INPUT_STATER_H
#define _INPUT_STATER_H

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

class InputStater;
#include "../EDNetwork/EDNetwork.h"

#include "../Staters/NeuronStater.h"


/******************************************************************************************************************************************/
/*************************************************** Classe ActivityStater ************************************************************/
/******************************************************************************************************************************************/
class InputStater : public NeuronStater
{

#ifdef _GLOBAL_STAT_MODE
	#ifdef _MULTI_TEST_MODE
		#ifndef _PARAMETRIC_TEST_MODE
			#ifndef _PHASE_TEST_MODE
	GnuplotFile* activityGnuplotFile;
			#endif
		#endif
	
protected:	
	Accumulater meanInputTimeFrequency[NB_FREQUENCY_BINS];
	Accumulater meanInputHighTimeFrequency[NB_HIGH_FREQUENCY_BINS];
	
	Accumulater meanInputExcitPreTempDevRepartition[100];
	Accumulater meanInputExcitPostTempDevRepartition[100];
	
	Accumulater meanInputInhibPreTempDevRepartition[100];
	Accumulater meanInputInhibPostTempDevRepartition[100];
	
	Accumulater meanInputISIRepartition[100];
	Accumulater meanInputSpikeRepartition[NB_HIDDEN_NEURONS];
	
		#ifndef _PARAMETRIC_TEST_MODE
			#ifndef _PHASE_TEST_MODE
	DataFile* meanInputTimeFrequencyFile;
	DataFile* meanInputHighTimeFrequencyFile;
	
	DataFile* meanInputExcitTempDevRepartitionFile;
	DataFile* meanInputInhibTempDevRepartitionFile;
	
	DataFile* meanInputISIRepartitionFile;
	DataFile* meanInputSpikeRepartitionFile;
	
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

	InputStater();
	InputStater(IndexedObject* io);

	virtual ~InputStater();

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

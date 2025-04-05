// NeuronStater.h

#ifndef _NEURON_STATER_H
#define _NEURON_STATER_H

// C includes
// Sp�ial itoa
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

#include "../Handlers/Stater.h"

#include "../Handlers/Accumulater.h"

#include "SynapseStater.h"

#include "ExcitSynapseStater.h"
#include "InhibSynapseStater.h"

class NeuronStater;
#include "../EDNetwork/EDNeuron.h"

/******************************************************************************************************************************************/
/*************************************************** Classe NeuronStater ************************************************************/
/******************************************************************************************************************************************/

class NeuronStater : public SynapseStater
{
protected:

#ifdef _ASSEMBLY_STAT_MODE
	
	#ifdef _GLOBAL_STAT_MODE
	
		#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	ExcitSynapseStater* excitSS;
	InhibSynapseStater* inhibSS;
		#endif
		
		#ifndef _MULTI_TEST_MODE
			#ifndef _PHASE_TEST_MODE
	DataFile* excitLFPFile;
	DataFile* inhibLFPFile;

	DataFile* LFPFile;
	DataFile* STAFile;

	DataFile* evokedSpikesFile;
			#endif
	
	Accumulater* excitLFPAccumulater;
	Accumulater* inhibLFPAccumulater;

	Counter* evokedSpikesCounter;

			#ifndef _PHASE_TEST_MODE
	DataFile* spikeFile;
	DataFile* meanISIFile;
			#endif
		
	Accumulater* meanISIAccumulater;
	
			#ifndef _PHASE_TEST_MODE
	GnuplotFile* neuronGnuplotFile;

	void openTracer();
	void closeTracer();

	void openGrapher();
	void runGrapher();
	void closeGrapher();
	
	DataFile* timeFrequencyFile;
	DataFile* highTimeFrequencyFile;
	DataFile* ISIFile;
	//DataFile* spikeCountFile;
			#endif
		#endif
		
	Counter ISICounters[100];
	//Counter spikeCounters[NB_HIDDEN_NEURONS];
	
	Counter frequenciesCounters[NB_FREQUENCY_BINS];
	Counter highFrequenciesCounters[NB_HIGH_FREQUENCY_BINS];
	
	#else
	GnuplotFile* neuronGnuplotFile;

		#ifdef _PSP_LFP_STAT_MODE
	Accumulater* PSPLFPAccumulater;
	DataFile* PSPLFPFile;
		#else
	
	Accumulater* ThresholdLFPAccumulater;
	Accumulater* LFPAccumulater;
	
	DataFile* LFPFile;
	DataFile* ThresholdLFPFile;
		
		#endif
		
	DataFile* spikeFile;
	
	void openTracer();
	void closeTracer();

	void openGrapher();
	void runGrapher();
	void closeGrapher();
	
	#endif
	
#endif
public:

	NeuronStater();
	NeuronStater(IndexedObject* io);

	virtual ~NeuronStater();
	
#ifdef _ASSEMBLY_STAT_MODE

	#ifdef _GLOBAL_STAT_MODE	
		#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	virtual InhibSynapseStater* getInhibSynapseStater();
	virtual ExcitSynapseStater* getExcitSynapseStater();
		#endif
		
	void statExcitLFP(double weightOfImpact);
	void statInhibLFP(double weightOfImpact);

	void statSpikeEmission(EDNeuron* n);
	void statEvokedSpike();
	
	void statFrequency(int interSpikeInterval);
	
	void flushCounters();
	#else
	
	void statSpikeEmission(EDNeuron* n);
	
		#ifdef _PSP_LFP_STAT_MODE
	void statPSPLFP(EDNeuron* n);
		#else
		
	void statLFP(EDNeuron* n);
	
		#endif
	#endif
	
	void initCounters();
	void trace(int timeOfTrace);
	void traceVoid();
	
	virtual void graph();
	
#endif
};


#endif

// NeuronStater.cc

// Local Includes
#include "NeuronStater.h"

/****************************************************************************************************************************************/
/************************************************* Methodes de la classe NeuronStater ************************************************/
/****************************************************************************************************************************************/

NeuronStater::NeuronStater()
{
#ifdef _ASSEMBLY_STAT_MODE

	#ifdef _GLOBAL_STAT_MODE
	
		#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	excitSS = new ExcitSynapseStater();
	inhibSS = new InhibSynapseStater();
		#endif
		
		#ifndef _MULTI_TEST_MODE
			#ifndef _PHASE_TEST_MODE
	excitLFPFile = new DataFile();
	inhibLFPFile = new DataFile();

	LFPFile = new DataFile();
	STAFile = new DataFile();

	evokedSpikesFile = new DataFile();
			#endif

	excitLFPAccumulater = new Accumulater();
	inhibLFPAccumulater = new Accumulater();

	evokedSpikesCounter = new Counter();

			#ifndef _PHASE_TEST_MODE
	timeFrequencyFile = new DataFile();
	highTimeFrequencyFile = new DataFile();

	spikeFile = new DataFile();
	
	meanISIFile = new DataFile();
	ISIFile = new DataFile();
			#endif

	meanISIAccumulater = new Accumulater();
	
			#ifndef _PHASE_TEST_MODE
	timeFrequencyFile = new DataFile();
	highTimeFrequencyFile = new DataFile();
	ISIFile = new DataFile();
	//spikeCountFile = new DataFile();
	
	neuronGnuplotFile = new GnuplotFile();
	
	openStater();
			#endif
		#endif
	#else
	spikeFile = new DataFile();
	
		#ifdef _PSP_LFP_STAT_MODE
	PSPLFPAccumulater = new Accumulater();
	PSPLFPFile = new DataFile();
		#else
	
	ThresholdLFPAccumulater = new Accumulater();
	ThresholdLFPFile = new DataFile();
	
	LFPAccumulater = new Accumulater();
	LFPFile = new DataFile();
		
		#endif
		
	neuronGnuplotFile = new GnuplotFile();
	
	openStater();
	#endif	
#endif
}

NeuronStater::NeuronStater(IndexedObject* io): SynapseStater(io)
{
#ifdef _ASSEMBLY_STAT_MODE
	#ifdef _GLOBAL_STAT_MODE
	
		#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	excitSS = new ExcitSynapseStater(io);
	inhibSS = new InhibSynapseStater(io);
		#endif
		
		#ifndef _MULTI_TEST_MODE
			#ifndef _PHASE_TEST_MODE
	excitLFPFile = new DataFile();
	inhibLFPFile = new DataFile();

	LFPFile = new DataFile();
	STAFile = new DataFile();

	evokedSpikesFile = new DataFile();
			#endif

	excitLFPAccumulater = new Accumulater();
	inhibLFPAccumulater = new Accumulater();

	evokedSpikesCounter = new Counter();

			#ifndef _PHASE_TEST_MODE
	timeFrequencyFile = new DataFile();
	highTimeFrequencyFile = new DataFile();

	spikeFile = new DataFile();
	
	meanISIFile = new DataFile();
	ISIFile = new DataFile();
			#endif

	meanISIAccumulater = new Accumulater();
		
		#endif
	
		#ifndef _MULTI_TEST_MODE
			#ifndef _PHASE_TEST_MODE
	timeFrequencyFile = new DataFile();
	highTimeFrequencyFile = new DataFile();
	ISIFile = new DataFile();
	//spikeCountFile = new DataFile();
	
	neuronGnuplotFile = new GnuplotFile();
	
	openStater();
			#endif
	
		#endif	
	#else
	spikeFile = new DataFile();
	
		#ifdef _PSP_LFP_STAT_MODE
	PSPLFPAccumulater = new Accumulater();
	PSPLFPFile = new DataFile();
		#else
		
	ThresholdLFPAccumulater = new Accumulater();
	ThresholdLFPFile = new DataFile();
	
	LFPAccumulater = new Accumulater();
	LFPFile = new DataFile();
	
		#endif
		
	neuronGnuplotFile = new GnuplotFile();
	
	openStater();
	#endif	
#endif
}

NeuronStater::~NeuronStater()
{
#ifdef _ASSEMBLY_STAT_MODE
	cerr << "In ~NeuronStater" << endl;
	
	#ifdef _GLOBAL_STAT_MODE	
		#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	delete((ExcitSynapseStater*) excitSS);
	delete((InhibSynapseStater*) inhibSS);
		#endif
		
		#ifndef _MULTI_TEST_MODE	
			#ifndef _PHASE_TEST_MODE
	closeStater();	
	
	delete(neuronGnuplotFile);
	
	delete(timeFrequencyFile);
	delete(highTimeFrequencyFile);
	delete(ISIFile);
	//delete(spikeCountFile);
	
	cerr << "After Freeing NeuronStater" << endl;		
			#endif
			
			#ifndef _PHASE_TEST_MODE
	delete(excitLFPFile);
	delete(inhibLFPFile);

	delete(LFPFile);
	delete(STAFile);

	delete(evokedSpikesFile);
			#endif
	
	delete(excitLFPAccumulater);
	delete(inhibLFPAccumulater);

	delete(evokedSpikesCounter);

			#ifndef _PHASE_TEST_MODE
	delete(spikeFile);
	delete(meanISIFile);
			#endif
		
	delete(meanISIAccumulater);
		#endif
	#else
	closeStater();	
	
	delete(neuronGnuplotFile);
	
		#ifdef _PSP_LFP_STAT_MODE
	delete(PSPLFPAccumulater);
	delete(PSPLFPFile);
		#else
		
	delete(LFPAccumulater);
	delete(LFPFile);
	
	delete(ThresholdLFPAccumulater);
	delete(ThresholdLFPFile);
	
		#endif
		
	delete(spikeFile);
	
	#endif
#endif
}

#ifdef _ASSEMBLY_STAT_MODE
	#ifndef _MULTI_TEST_MODE	
void NeuronStater::openTracer()
{	
		#ifdef _GLOBAL_STAT_MODE
			#ifndef _PHASE_TEST_MODE
	if (excitLFPFile)
	{
		ostringstream oss;
		oss << "excitLFPStats" << (Handler*) this;
		excitLFPFile->openDataFile(oss.str());
	}

	if (inhibLFPFile)
	{
		ostringstream oss;
		oss << "inhibLFPStats" << (Handler*) this;
		inhibLFPFile->openDataFile(oss.str());
	}
			
	if (LFPFile)
	{
		ostringstream oss;
		oss << "LFPStats" << (Handler*) this;
		LFPFile->openDataFile(oss.str());
	}


	if (STAFile)
	{
		ostringstream oss;
		oss << "STAStats" << (Handler*) this;
		STAFile ->openDataFile(oss.str());
	}

	if (evokedSpikesFile)
	{
		ostringstream oss;
		oss << "evokedSpikesStats" << (Handler*) this;
		evokedSpikesFile->openDataFile(oss.str());
	}
	
	if (spikeFile)
	{
		ostringstream oss;
		oss << SPIKE_FILENAME << (Handler*) this;
		spikeFile->openDataFile(oss.str());
	}

	if (meanISIFile)
	{
		ostringstream oss;
		oss << "meanISIStats" << (Handler*) this;
		meanISIFile->openDataFile(oss.str());
	}
				//#endif
	if (timeFrequencyFile)
	{
		ostringstream oss;
		oss << "timeFrequencyStats" << (Handler*) this;
		timeFrequencyFile->openDataFile(oss.str());
	}

	if (highTimeFrequencyFile)
	{
		ostringstream oss;
		oss << "highTimeFrequencyStats" << (Handler*) this;
		highTimeFrequencyFile->openDataFile(oss.str());
	}
	
	if (ISIFile)
	{
		ostringstream oss;
		oss << "ISIStats" << (Handler*) this;
		ISIFile->openDataFile(oss.str());
	}
		
	/*
	if (spikeCountFile)
	{
		ostringstream oss;
		oss << "spikeCountStats" << (Handler*) this;
		spikeCountFile->openDataFile(oss.str());
	}
	*/
			#endif
		#else
	
	if (spikeFile)
	{
		ostringstream oss;
		oss << SPIKE_FILENAME << (string) getStringIndex() << (Handler*) this;
		spikeFile->openDataFile(oss.str());
	}
			#ifdef _PSP_LFP_STAT_MODE
	if (PSPLFPFile)
	{
		ostringstream oss;
		oss << "PSPLFPStats" << (string) getStringIndex() << (Handler*) this;
		PSPLFPFile->openDataFile(oss.str());
	}
			#else
	if (LFPFile)
	{
		ostringstream oss;
		oss << "LFPStats" << (string) getStringIndex() << (Handler*) this;
		LFPFile->openDataFile(oss.str());
	}

	if (ThresholdLFPFile)
	{
		ostringstream oss;
		oss << "ThresholdLFPStats" << (string) getStringIndex() << (Handler*) this;
		ThresholdLFPFile->openDataFile(oss.str());
	}

			#endif
		#endif
}

void NeuronStater::closeTracer()
{
		#ifdef _GLOBAL_STAT_MODE
			#ifndef _PHASE_TEST_MODE
	if (excitLFPFile->isOpen())
	{
				#ifdef _PHASE_STAT_MODE
		excitLFPFile->phase3DFile();
		excitLFPFile->phase2DFile();
				#endif
				
		excitLFPFile->closeFile();
	}

	if (inhibLFPFile->isOpen())
	{
				#ifdef _PHASE_STAT_MODE
		inhibLFPFile->phase3DFile();
		inhibLFPFile->phase2DFile();
				#endif
				
		inhibLFPFile->closeFile();
	}

	if (LFPFile->isOpen())
	{
				#ifdef _PHASE_STAT_MODE
		LFPFile->phase3DFile();
		LFPFile->phase2DFile();
				#endif
				
		LFPFile->closeFile();
	}

	if (STAFile->isOpen())
	{
				#ifdef _PHASE_STAT_MODE
		STAFile->phase3DFile();
		STAFile->phase2DFile();
				#endif
				
		STAFile->closeFile();
	}

	if (evokedSpikesFile->isOpen())
	{
				#ifdef _PHASE_STAT_MODE
		evokedSpikesFile->phase3DFile();
		evokedSpikesFile->phase2DFile();
				#endif
				
		evokedSpikesFile->closeFile();
	}
	
	if (spikeFile->isOpen())
	{
		spikeFile->closeFile();
	}

	if (meanISIFile->isOpen())
	{
				#ifdef _PHASE_STAT_MODE
		meanISIFile->phase3DFile();
		meanISIFile->phase2DFile();
				#endif
				
		meanISIFile->closeFile();
	}
	
	if (timeFrequencyFile->isOpen())
	{
		timeFrequencyFile->closeFile();
		timeFrequencyFile->formatFile();
	}
	if (highTimeFrequencyFile->isOpen())
	{
		highTimeFrequencyFile->closeFile();
		highTimeFrequencyFile->formatFile();
	}

	if (ISIFile->isOpen())
	{
		ISIFile->closeFile();
		ISIFile->formatFile();
	}
	/*
	if (spikeCountFile->isOpen())
	{
		spikeCountFile->closeFile();
		spikeCountFile->formatFile();
	}
	*/
			#endif
		#else
	
	if (spikeFile->isOpen())
	{
		spikeFile->closeFile();
	}
	
			#ifdef _PSP_LFP_STAT_MODE
	if (PSPLFPFile->isOpen())
	{
		PSPLFPFile->closeFile();
	}
			#else
	
	if (LFPFile->isOpen())
	{
		LFPFile->closeFile();
	}

	if (ThresholdLFPFile->isOpen())
	{
		ThresholdLFPFile->closeFile();
	}
		
			#endif
		#endif
}

void NeuronStater::openGrapher()
{
		
		#ifdef _GLOBAL_STAT_MODE
			#ifndef _PHASE_TEST_MODE
	if (neuronGnuplotFile)
	{
		neuronGnuplotFile->openGnuplotFile("NeuronStat");
	}
	else
	{
		cerr << "Warning, neuronGnuplotFile is not inited" << endl;
	}
			#endif
		#else
	if (neuronGnuplotFile)
	{
		ostringstream oss;
		oss << "NeuronStat" << (Handler*) this;
		neuronGnuplotFile->openGnuplotFile(oss.str());
	}
	else
	{
		cerr << "Warning, neuronGnuplotFile is not inited" << endl;
	}		
		#endif
}

void NeuronStater::runGrapher()
{
	if (neuronGnuplotFile)
	{
		neuronGnuplotFile->systemFile();
	}
	else
	{
		cerr << "Warning, neuronGnuplotFile is not inited" << endl;
	}
}

void NeuronStater::closeGrapher()
{
	if (neuronGnuplotFile->isOpen())
	{
		neuronGnuplotFile->closeFile();
	}
	else
	{
		cerr << "Warning, neuronGnuplotFile is not open" << endl;
	}
}
	#endif
#endif
/****************************************************************************************************************************************/
/******************************************************* Methodes de stats **************************************************************/
/****************************************************************************************************************************************/
#ifdef _ASSEMBLY_STAT_MODE
	#ifdef _GLOBAL_STAT_MODE
		#ifdef _GLOBAL_SYNAPSE_STAT_MODE
ExcitSynapseStater* NeuronStater::getExcitSynapseStater()
{
	return ((ExcitSynapseStater*) excitSS);
}

InhibSynapseStater* NeuronStater::getInhibSynapseStater()
{
	return ((InhibSynapseStater*) inhibSS);
}
		#endif
		
void NeuronStater::statExcitLFP(double weightOfImpact)
{
		#ifndef _MULTI_TEST_MODE
	if (excitLFPAccumulater)
	{
		if(0.0<=weightOfImpact)
		{
			excitLFPAccumulater->accumulate(fabs(weightOfImpact));
		}
		else
		{
			cerr << "Warning, stating negative weight in excitLFPAccumulater" << endl;
		}
	}
	else
	{
		cerr << "Warning, excitLFPAccumulater should be inited" << endl;
	}
		#endif
}

void NeuronStater::statInhibLFP(double weightOfImpact)
{
		#ifndef _MULTI_TEST_MODE
	if (inhibLFPAccumulater)
	{
		if (weightOfImpact<=0.0)
		{
			inhibLFPAccumulater->accumulate(fabs(weightOfImpact));
		}
		else
		{
			cerr << "Warning, stating positive weight in inhibLFPAccumulater" << endl;
		}
	}
	else
	{
		cerr << "Warning, inhibLFPAccumulater should be inited" << endl;
	}
		#endif
}

void NeuronStater::statSpikeEmission(EDNeuron* n)
{
		#ifndef _MULTI_TEST_MODE
			#ifndef _PHASE_TEST_MODE
	if (spikeFile->isOpen())
	{
		spikeFile->addDotData(n->index, n->lastTimeOfFiring);
	}
			#endif
		#endif
	/*
	if (n->index < NB_HIDDEN_NEURONS)
	{
		spikeCounters[n->index].count();
	}
	*/
	statEvokedSpike();
}

void NeuronStater::statEvokedSpike()
{
		#ifndef _MULTI_TEST_MODE
	if (evokedSpikesCounter)
	{
		evokedSpikesCounter->count();
	}
	else
	{
		cerr << "Warning, evokedSpikesCounter should be inited" << endl;
	}
		#endif
}
void NeuronStater::statFrequency(int interSpikeInterval)
{
	if (0<=interSpikeInterval)
	{
		if (interSpikeInterval<99)
		{
			ISICounters[interSpikeInterval].count();
			//cout << "ISIvalue: " << interSpikeInterval << endl;
		}
		else
		{
			ISICounters[99].count();
		}
		
		#ifndef _MULTI_TEST_MODE	
		if (meanISIAccumulater)
		{
			meanISIAccumulater->accumulate(fabs((double) interSpikeInterval));
		}
		#endif
		int frequency = (int) ONE_SECOND/interSpikeInterval;

		#ifdef _LOW_PASS_STAT_MODE
		if (frequency/HIGH_FREQUENCY_BIN_LENGTH < (NB_HIGH_FREQUENCY_BINS-1))
		{
			for (int i=0;i< (int) frequency/HIGH_FREQUENCY_BIN_LENGTH;i++)
			{
				highFrequenciesCounters[(int) frequency/HIGH_FREQUENCY_BIN_LENGTH].count();
			}
		}
		else
		{
			for (int i=0;i< (int) frequency/HIGH_FREQUENCY_BIN_LENGTH;i++)
			{
				highFrequenciesCounters[NB_HIGH_FREQUENCY_BINS-1].count();
			}
		}
		
		#else

		if (frequency/HIGH_FREQUENCY_BIN_LENGTH < (NB_HIGH_FREQUENCY_BINS-1))
		{
			highFrequenciesCounters[(int) frequency/HIGH_FREQUENCY_BIN_LENGTH].count();
		}
		else
		{
			highFrequenciesCounters[NB_HIGH_FREQUENCY_BINS-1].count();
		}
		#endif

		if (frequency/5 < (NB_FREQUENCY_BINS-1))
		{
			frequenciesCounters[(int) frequency/5].count();
		}
		else
		{
			frequenciesCounters[NB_FREQUENCY_BINS-1].count();
		}

/*
		if (frequency/5 < NB_FREQUENCY_BINS)
		{
			frequenciesCounters[(int) frequency/5].count();
		}
*/
	}
	else cerr << "Warning, interSpikeInterval should be positive (" << interSpikeInterval << ")" << endl;
}

void NeuronStater::flushCounters()
{
		#ifndef _MULTI_TEST_MODE
	cout << "excitLFPAccumulater: " << (Accumulater*) excitLFPAccumulater << endl;
	cout << "inhibLFPAccumulater: " << (Accumulater*) inhibLFPAccumulater << endl;
			#ifdef _SINGLE_ASSEMBLY_STAT_MODE
	cout << "evokedSpikesCounter: " << (Counter*) evokedSpikesCounter << endl;
			#endif
		#endif
}

	#else

void NeuronStater::statSpikeEmission(EDNeuron* n)
{
	if (spikeFile->isOpen())
	{
		spikeFile->addDotData(n->index, n->lastTimeOfFiring);
	}
}

		#ifdef _PSP_LFP_STAT_MODE
void NeuronStater::statPSPLFP(EDNeuron* n)
{
	if (PSPLFPAccumulater)
	{
		PSPLFPAccumulater->accumulate(fabs(n->PSPotentialAccu->getAccu()));
	}
	else
	{
		cerr << "Warning, PSPLFPAccumulater should be inited" << endl;
	} 
}
		#else

void NeuronStater::statLFP(EDNeuron* n)
{
	if (LFPAccumulater)
	{
		LFPAccumulater->accumulate(n->membranePotential - HYPER_POLARISATION_POTENTIAL);
	}
	else
	{
		cerr << "Warning, LFPAccumulater should be inited" << endl;
	}
	
	if (ThresholdLFPAccumulater)
	{
		if (0.0 <= (n->thresholdPotential - n->membranePotential))
		{ 	
			ThresholdLFPAccumulater->accumulate(n->thresholdPotential - n->membranePotential);
		}
		else
		{
			ThresholdLFPAccumulater->accumulate(0.0);
		}
	}
	else
	{
		cerr << "Warning, ThresholdLFPAccumulater should be inited" << endl;
	}
}		
		#endif
		
	#endif

void  NeuronStater::initCounters()
{
	#ifdef _GLOBAL_STAT_MODE
	#else
	
		#ifdef _PSP_LFP_STAT_MODE
	if (PSPLFPAccumulater)
	{
		PSPLFPAccumulater->initAccu();
	}
	else
	{
		cerr << "Warning, PSPLFPAccumulater should be inited" << endl;
	} 

		#else
	if (ThresholdLFPAccumulater)
	{
		ThresholdLFPAccumulater->initAccu();
	}
	else
	{
		cerr << "Warning, countExcitProjections should be inited" << endl;
	}
	
	if (LFPAccumulater)
	{
		LFPAccumulater->initAccu();
	}
	else
	{
		cerr << "Warning, countExcitProjections should be inited" << endl;
	}
		#endif
	#endif
}

void NeuronStater::trace(int timeOfTrace)
{
/*
#ifdef _TEST_STAT
	cout << "*** NeuronStater *** Tracing Neuron stats at time " << timeOfTrace << endl;
#endif
*/
	#ifdef _GLOBAL_STAT_MODE
		#ifndef _MULTI_TEST_MODE
			#ifndef _PHASE_TEST_MODE
	if(LFPFile->isOpen())
	{
		if (excitLFPAccumulater && inhibLFPAccumulater)
		{
			LFPFile->addLineData(timeOfTrace,excitLFPAccumulater->getAccu() - inhibLFPAccumulater->getAccu());
		}
		else
		{
			cerr << "Warning, excitLFPAccumulater and inhibLFPAccumulater should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, LFPFile should be inited" << endl;
	}

	if(STAFile ->isOpen())
	{
		if (excitLFPAccumulater && evokedSpikesCounter)
		{
			if (evokedSpikesCounter->getCounter() != 0)
			{
				STAFile->addLineData(timeOfTrace,excitLFPAccumulater->getAccu()/evokedSpikesCounter->getCounter());
			}
			else
			{
				cerr << "Warning, evokedSpikesCounter is void, no STA" << endl;
			}
		}
		else
		{
			cerr << "Warning, excitLFPAccumulater and evokedSpikesCounter should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, STAFile should be inited" << endl;
	}

	if(excitLFPFile->isOpen())
	{
		if (excitLFPAccumulater)
		{
			excitLFPFile->addLineData(timeOfTrace,excitLFPAccumulater->getAccu());
			excitLFPAccumulater->initAccu();
		}
		else
		{
			cerr << "Warning, excitLFPAccumulater should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, excitLFPFile should be inited" << endl;
	}

	if(inhibLFPFile->isOpen())
	{
		if (inhibLFPAccumulater)
		{
			//inhibLFPFile->addLineData(timeOfTrace,inhibLFPAccumulater->getAccu());
			inhibLFPFile->addLineData(timeOfTrace,-inhibLFPAccumulater->getAccu());
			inhibLFPAccumulater->initAccu();
		}
		else
		{
			cerr << "Warning, inhibLFPAccumulater should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, inhibLFPFile should be inited" << endl;
	}

	if(evokedSpikesFile->isOpen())
	{
		if (evokedSpikesCounter)
		{
			evokedSpikesFile->addLineData(timeOfTrace,evokedSpikesCounter->getCounter());
			evokedSpikesCounter->initCounter();
		}
		else
		{
			cerr << "Warning, evokedSpikesCounter should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, evokedSpikesFile should be inited" << endl;
	}
	
	if (meanISIFile->isOpen())
	{
		if (meanISIAccumulater)
		{
			meanISIFile->addLineData(timeOfTrace,meanISIAccumulater->getMean());
			meanISIAccumulater->initAccu();
		}
	}
	
	if (highTimeFrequencyFile->isOpen())
	{
		if (highFrequenciesCounters)
		{
			for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
			{
				highTimeFrequencyFile->addIndexedLineData(i*HIGH_FREQUENCY_BIN_LENGTH,timeOfTrace,((double) highFrequenciesCounters[i].getCounter()));
				highFrequenciesCounters[i].initCounter();
			}
			//highTimeFrequencyFile->addDataSeparator();
		}
	}
	else
	{
		cerr << "Warning, highTimeFrequencyFile should be inited" << endl;
	}

	if (timeFrequencyFile->isOpen())
	{
		if (frequenciesCounters)
		{
			for (int i=0;i<NB_FREQUENCY_BINS;i++)
			{
				timeFrequencyFile->addIndexedLineData(i*5,timeOfTrace,(double) frequenciesCounters[i].getCounter());
				frequenciesCounters[i].initCounter();
			}
		//timeFrequencyFile->addDataSeparator();
		}
	}
	else
	{
		cerr << "Warning, timeFrequencyFile should be inited" << endl;
	}

	if (ISIFile->isOpen())
	{
		if (ISICounters)
		{
			for (int i=0;i<100;i++)
			{
				ISIFile->addIndexedLineData(i,timeOfTrace,(double) ISICounters[i].getCounter());
				ISICounters[i].initCounter();
			}
		}
	}
	/*
	if (spikeCountFile->isOpen())
	{
		if (spikeCounters)
		{
			for (int i=0;i<NB_HIDDEN_NEURONS;i++)
			{
				spikeCountFile->addIndexedLineData(i,timeOfTrace,(double) spikeCounters[i].getCounter());
				spikeCounters[i].initCounter();
			}
		}
	}
	*/
			#endif
		#endif
	
		#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	((ExcitSynapseStater*) excitSS)->trace(timeOfTrace);
	((InhibSynapseStater*) inhibSS)->trace(timeOfTrace);
		#endif
	#else
	
		#ifdef _PSP_LFP_STAT_MODE
	
	if(PSPLFPFile->isOpen())
	{
		if (PSPLFPAccumulater)
		{
			PSPLFPFile->addLineData(timeOfTrace,PSPLFPAccumulater->getMean());
		}
		else
		{
			cerr << "Warning, PSPLFPAccumulater should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, ThresholdLFPFile should be inited" << endl;
	}
		#else
	if(LFPFile->isOpen())
	{
		if (LFPAccumulater)
		{
			LFPFile->addLineData(timeOfTrace,LFPAccumulater->getMean()-HYPER_POLARISATION_POTENTIAL);
		}
		else
		{
			cerr << "Warning, excitLFPAccumulater and inhibLFPAccumulater should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, LFPFile should be inited" << endl;
	}
	
	if(ThresholdLFPFile->isOpen())
	{
		if (ThresholdLFPAccumulater)
		{
			ThresholdLFPFile->addLineData(timeOfTrace,-ThresholdLFPAccumulater->getMean());
		}
		else
		{
			cerr << "Warning, ThresholdLFPAccumulater should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, ThresholdLFPFile should be inited" << endl;
	}
		#endif
	#endif
}

void NeuronStater::traceVoid()
{
	#ifdef _GLOBAL_STAT_MODE
		#ifndef _MULTI_TEST_MODE
	if (excitLFPAccumulater)
	{
		excitLFPAccumulater->setVoid();
	}
	else
	{
		cerr << "Warning, excitLFPAccumulater should be inited" << endl;
	}

	if (inhibLFPAccumulater)
	{
		inhibLFPAccumulater->setVoid();
	}
	else
	{
		cerr << "Warning, inhibLFPAccumulater should be inited" << endl;
	}

	

	if (evokedSpikesCounter)
	{
		evokedSpikesCounter->setVoid();
	}
	else
	{
		cerr << "Warning, evokedSpikesCounter should be inited" << endl;
	}
	
	if (meanISIAccumulater)
	{
		meanISIAccumulater->setVoid();
	}
		#endif
	
	//#ifndef _PARAMETRIC_TEST_MODE
	if (highFrequenciesCounters)
	{
		for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
		{
			highFrequenciesCounters[i].setVoid();
		}
		//highTimeFrequencyFile->addDataSeparator();
	}

	if (frequenciesCounters)
	{
		for (int i=0;i<NB_FREQUENCY_BINS;i++)
		{
			frequenciesCounters[i].setVoid();
		}
	//timeFrequencyFile->addDataSeparator();
	}

	if (ISICounters)
	{
		for (int i=0;i<100;i++)
		{
			ISICounters[i].setVoid();
		}
	}
	/*
	if (spikeCounters)
	{
		for (int i=0;i<NB_HIDDEN_NEURONS;i++)
		{
			spikeCounters[i].setVoid();
		}
	}
	*/
		#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	((ExcitSynapseStater*) excitSS)->traceVoid();
	((InhibSynapseStater*) inhibSS)->traceVoid();
		#endif
	#else
	

		#ifdef _PSP_LFP_STAT_MODE
	
	if (PSPLFPAccumulater)
	{
		PSPLFPAccumulater->setVoid();
	}
	else
	{
		cerr << "Warning, PSPLFPAccumulater should be inited" << endl;
	}
	
		#else
	
	if (LFPAccumulater)
	{
		LFPAccumulater->setVoid();
	}
	else
	{
		cerr << "Warning, LFPAccumulater should be inited" << endl;
	}

	if (ThresholdLFPAccumulater)
	{
		ThresholdLFPAccumulater->setVoid();
	}
	else
	{
		cerr << "Warning, ThresholdLFPAccumulater should be inited" << endl;
	}	
		#endif
	#endif
}

void NeuronStater::graph()
{
	#ifdef _GLOBAL_STAT_MODE
		#ifndef _MULTI_TEST_MODE
			#ifndef _PHASE_TEST_MODE
	if (neuronGnuplotFile->isOpen())
	{
		//#ifdef _TEST_STAT
		cout << "In graph global assemblies neuron assembly" << getIndex() << endl;
		//#endif

		ostringstream oss;
		oss << (Handler*) this;

		// Difference de LFP
		neuronGnuplotFile->setOutput("LFPStats"+oss.str());
		neuronGnuplotFile->setTitle("LFPStats"+oss.str());
		neuronGnuplotFile->plotLine((string)"LFPStats" +oss.str());

				#ifdef _PHASE_STAT_MODE
		neuronGnuplotFile->setTitle((string)"Phase_2D_LFPStats"+oss.str());
		neuronGnuplotFile->setOutput((string)"Phase_2D_LFPStats"+oss.str());
		neuronGnuplotFile->plotLine((string)"Phase_2D_LFPStats" +oss.str());

		neuronGnuplotFile->setTitle((string)"Phase3D_LFPStats");
		neuronGnuplotFile->setOutput((string)"Phase3D_LFPStats_"+oss.str());
		neuronGnuplotFile->plot3DLine((string)"Phase_3D_LFPStats" +oss.str());
				#endif
				
		// Spike Triggered Average
		neuronGnuplotFile->setOutput("STAStats"+oss.str());
		neuronGnuplotFile->setTitle("STAStats"+oss.str());
		neuronGnuplotFile->plotLine((string)"STAStats"+oss.str());

				#ifdef _PHASE_STAT_MODE
		neuronGnuplotFile->setTitle((string)"Phase_2D_STAStats"+oss.str());
		neuronGnuplotFile->setOutput((string)"Phase_2D_STAStats"+oss.str());
		neuronGnuplotFile->plotLine((string)"Phase_2D_STAStats"+oss.str() );

		neuronGnuplotFile->setTitle((string)"Phase3D_STAStats"+oss.str());
		neuronGnuplotFile->setOutput((string)"Phase3D_STAStats_"+oss.str());
		neuronGnuplotFile->plot3DLine((string)"Phase_3D_STAStats"+oss.str());
				#endif
				
		// excit/inhib LFP
		neuronGnuplotFile->setOutput("IELFPStats"+oss.str());
		neuronGnuplotFile->setTitle("IELFPStats"+oss.str());
		neuronGnuplotFile->plotFirstSingleLine("excitLFPStats"+oss.str());
		neuronGnuplotFile->plotSecondSingleLine("inhibLFPStats"+oss.str());

		neuronGnuplotFile->setOutput("excitLFPStats"+oss.str());
		neuronGnuplotFile->setTitle("excitLFPStats"+oss.str());
		neuronGnuplotFile->plotLine("excitLFPStats"+oss.str());

				#ifdef _PHASE_STAT_MODE
		neuronGnuplotFile->setTitle((string)"Phase3D_excitLFPStats"+oss.str());
		neuronGnuplotFile->setOutput((string)"Phase3D_excitLFPStats_"+oss.str());
		neuronGnuplotFile->plot3DLine((string)"Phase_3D_excitLFPStats"+oss.str() );

		neuronGnuplotFile->setTitle((string)"Phase_2D_excitLFPStats"+oss.str());
		neuronGnuplotFile->setOutput((string)"Phase_2D_excitLFPStats"+oss.str());
		neuronGnuplotFile->plotLine((string)"Phase_2D_excitLFPStats"+oss.str() );
				#endif
				
		neuronGnuplotFile->setOutput("inhibLFPStats"+oss.str());
		neuronGnuplotFile->setTitle("inhibLFPStats"+oss.str());
		neuronGnuplotFile->plotLine("inhibLFPStats"+oss.str());

				#ifdef _PHASE_STAT_MODE
		neuronGnuplotFile->setTitle((string)"Phase3D_inhibLFPStats"+oss.str());
		neuronGnuplotFile->setOutput((string)"Phase3D_inhibLFPStats_"+oss.str());
		neuronGnuplotFile->plot3DLine((string)"Phase_3D_inhibLFPStats" +oss.str());

		neuronGnuplotFile->setTitle((string)"Phase_2D_inhibLFPStats"+oss.str());
		neuronGnuplotFile->setOutput((string)"Phase_2D_inhibLFPStats"+oss.str());
		neuronGnuplotFile->plotLine((string)"Phase_2D_inhibLFPStats" +oss.str());
				#endif
				
		neuronGnuplotFile->setOutput("evokedSpikesStats"+oss.str());
		neuronGnuplotFile->setTitle("evokedSpikesStats"+oss.str());
		neuronGnuplotFile->plotLine("evokedSpikesStats"+oss.str());

				#ifdef _PHASE_STAT_MODE
		neuronGnuplotFile->setTitle((string)"Phase3D_evokedSpikesStats"+oss.str());
		neuronGnuplotFile->setOutput((string)"Phase3D_evokedSpikesStats"+oss.str());
		neuronGnuplotFile->plot3DLine((string)"Phase_3D_evokedSpikesStats"+oss.str() );

		neuronGnuplotFile->setTitle((string)"Phase_2D_evokedSpikesStats"+oss.str());
		neuronGnuplotFile->setOutput((string)"Phase_2D_evokedSpikesStats"+oss.str());
		neuronGnuplotFile->plotLine((string)"Phase_2D_evokedSpikesStats" +oss.str());
				#endif
				
		// ISI
		neuronGnuplotFile->setOutput("ISIStats"+oss.str());
		neuronGnuplotFile->setTitle("ISI Stats"+oss.str());
		neuronGnuplotFile->plot3DIndexedLines("ISIStats"+oss.str());

		neuronGnuplotFile->setOutput("meanISIStats"+oss.str());
		neuronGnuplotFile->setTitle("meanISIStats"+oss.str());
		neuronGnuplotFile->plotLine("meanISIStats"+oss.str() );

				#ifdef _PHASE_STAT_MODE
		neuronGnuplotFile->setTitle((string)"Phase3D_meanISIStats"+oss.str());
		neuronGnuplotFile->setOutput((string)"Phase3D_meanISIStats"+oss.str());
		neuronGnuplotFile->plot3DLine((string)"Phase_3D_meanISIStats"+oss.str() );

		neuronGnuplotFile->setTitle((string)"Phase_2D_meanISIStats"+oss.str());
		neuronGnuplotFile->setOutput((string)"Phase_2D_meanISIStats"+oss.str());
		neuronGnuplotFile->plotLine((string)"Phase_2D_meanISIStats" +oss.str());
				#endif
				
		// Diagramme temps frequence
		neuronGnuplotFile->setOutput("Time-Frequency"+oss.str());
		neuronGnuplotFile->setTitle("Time-Frequency"+oss.str());
		neuronGnuplotFile->plot3DIndexedLines("timeFrequencyStats"+oss.str());

		neuronGnuplotFile->setOutput("High-Time-Frequency"+oss.str());
		neuronGnuplotFile->setTitle("High-Time-Frequency"+oss.str());
		neuronGnuplotFile->plot3DIndexedLines("highTimeFrequencyStats"+oss.str());

		// Digramme global de spikes
		neuronGnuplotFile->setOutput(SPIKE_FILENAME+oss.str());
		neuronGnuplotFile->setTitle(SPIKE_FILENAME+oss.str());
		neuronGnuplotFile->plotDots(SPIKE_FILENAME+oss.str());
	}
	else
	{
		cerr << "Warning, neuronGnuplotFile should be open" << endl;
	}
			#endif
		#endif
	#else
	if (neuronGnuplotFile->isOpen())
	{
		//#ifdef _TEST_STAT
		cout << "In graph global assemblies neuron assembly" << getIndex() << endl;
		//#endif

		ostringstream oss;
		oss << (string) getStringIndex() << (Handler*) this;

		// Digramme global de spikes
		neuronGnuplotFile->setOutput(SPIKE_FILENAME+oss.str());
		neuronGnuplotFile->setTitle(SPIKE_FILENAME+oss.str());
		neuronGnuplotFile->plotDots(SPIKE_FILENAME+oss.str());
		
		#ifdef _PSP_LFP_STAT_MODE
	
		// PSPLFP
		neuronGnuplotFile->setOutput("PSPLFPStats"+oss.str());
		neuronGnuplotFile->setTitle("PSPLFPStats"+oss.str());
		neuronGnuplotFile->plotLine((string)"PSPLFPStats" +oss.str());

	
		#else
		
		// Difference de LFP
		neuronGnuplotFile->setOutput("LFPStats"+oss.str());
		neuronGnuplotFile->setTitle("LFPStats"+oss.str());
		neuronGnuplotFile->plotLine((string)"LFPStats" +oss.str());

		
		// Difference de ThresholdLFP
		neuronGnuplotFile->setOutput("ThresholdLFPStats"+oss.str());
		neuronGnuplotFile->setTitle("ThresholdLFPStats"+oss.str());
		neuronGnuplotFile->plotLine((string)"ThresholdLFPStats" +oss.str());

		#endif
	}
	else
	{
		cerr << "Warning, neuronGnuplotFile should be open" << endl;
	}
	#endif
}
#endif




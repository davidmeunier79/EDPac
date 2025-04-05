// ActivityStater.cc

// Local Includes
#include "ActivityStater.h"

/****************************************************************************************************************************************/
/************************************************* Methodes de la classe ActivityStater ************************************************/
/****************************************************************************************************************************************/

ActivityStater::ActivityStater()
{

#ifdef _GLOBAL_STAT_MODE
	#ifdef _MULTI_TEST_MODE
	initAccumulaters();
	
		#ifndef _PARAMETRIC_TEST_MODE
			#ifndef _PHASE_TEST_MODE
	activityGnuplotFile = new GnuplotFile();
	
	meanTimeFrequencyFile = new DataFile();
	meanHighTimeFrequencyFile = new DataFile();
	
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	meanExcitTempDevRepartitionFile = new DataFile();
	meanInhibTempDevRepartitionFile = new DataFile();
				#endif
				
	meanISIRepartitionFile = new DataFile();
	meanSpikeRepartitionFile = new DataFile();
	
	openStater();
			#endif
		#endif
	#endif
#endif
}

ActivityStater::ActivityStater(IndexedObject* io): NeuronStater(io)
{

#ifdef _GLOBAL_STAT_MODE
	#ifdef _MULTI_TEST_MODE
	initAccumulaters();
	
		#ifndef _PARAMETRIC_TEST_MODE
			#ifndef _PHASE_TEST_MODE
	activityGnuplotFile = new GnuplotFile();
	
	meanTimeFrequencyFile = new DataFile();
	meanHighTimeFrequencyFile = new DataFile();
				
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	meanExcitTempDevRepartitionFile = new DataFile();
	meanInhibTempDevRepartitionFile = new DataFile();
				#endif
				
	meanISIRepartitionFile = new DataFile();
	meanSpikeRepartitionFile = new DataFile();
	
	openStater();
			#endif
		#endif
	#endif
#endif
}

ActivityStater::~ActivityStater()
{

#ifdef _GLOBAL_STAT_MODE
	#ifdef _MULTI_TEST_MODE
		#ifndef _PARAMETRIC_TEST_MODE
			#ifndef _PHASE_TEST_MODE
	cerr << "In ~ActivityStater" << endl;		
	closeStater();

	delete(meanTimeFrequencyFile);
	delete(meanHighTimeFrequencyFile);
				
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	delete(meanExcitTempDevRepartitionFile);
	delete(meanInhibTempDevRepartitionFile);
				#endif
				
	delete(meanISIRepartitionFile);
	delete(meanSpikeRepartitionFile);
	
	delete(activityGnuplotFile);
	
	cerr << "After Freeing ActivityStater" << endl;
			#endif
		#endif
	#endif
#endif
}

#ifdef _GLOBAL_STAT_MODE
	#ifdef _MULTI_TEST_MODE
		#ifndef _PARAMETRIC_TEST_MODE
			#ifndef _PHASE_TEST_MODE
void ActivityStater::openTracer()
{
	if (meanTimeFrequencyFile)
	{
		ostringstream oss;
		oss << "meanTimeFrequencyStats";
		meanTimeFrequencyFile->openDataFile(oss.str());
	}

	if (meanHighTimeFrequencyFile)
	{
		ostringstream oss;
		oss << "meanHighTimeFrequencyStats";
		meanHighTimeFrequencyFile->openDataFile(oss.str());
	}
				
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	if (meanExcitTempDevRepartitionFile)
	{
		ostringstream oss;
		oss << "meanExcitTempDevRepartitionStats";
		meanExcitTempDevRepartitionFile->openDataFile(oss.str());
	}
	
	if (meanInhibTempDevRepartitionFile)
	{
		ostringstream oss;
		oss << "meanInhibTempDevRepartitionStats";
		meanInhibTempDevRepartitionFile->openDataFile(oss.str());
	}
				#endif
				
	if (meanISIRepartitionFile)
	{
		ostringstream oss;
		oss << "meanISIRepartitionStats";
		meanISIRepartitionFile->openDataFile(oss.str());
	}
	
	if (meanSpikeRepartitionFile)
	{
		ostringstream oss;
		oss << "meanSpikeRepartitionStats";
		meanSpikeRepartitionFile->openDataFile(oss.str());
	}
}

void ActivityStater::closeTracer()
{
	if (meanTimeFrequencyFile->isOpen())
	{
		meanTimeFrequencyFile->closeFile();
	}
	
	if (meanHighTimeFrequencyFile->isOpen())
	{
		meanHighTimeFrequencyFile->closeFile();
	}

			
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	if (meanExcitTempDevRepartitionFile->isOpen())
	{
		meanExcitTempDevRepartitionFile->closeFile();
	}
	
	if (meanInhibTempDevRepartitionFile->isOpen())
	{
		meanInhibTempDevRepartitionFile->closeFile();
	}
				#endif
				
	if (meanISIRepartitionFile->isOpen())
	{
		meanISIRepartitionFile->closeFile();
	}
	
	if (meanSpikeRepartitionFile->isOpen())
	{
		meanSpikeRepartitionFile->closeFile();
			#ifdef _SORT_ASSEMBLY_STAT_MODE
		meanSpikeRepartitionFile->formatValuesFile();
			#endif
	}
}

void ActivityStater::openGrapher()
{
	if (activityGnuplotFile)
	{
		activityGnuplotFile->openGnuplotFile("ActivityStat");
	}
	else
	{
		cerr << "Warning, activityGnuplotFile is not inited" << endl;
	}
}

void ActivityStater::runGrapher()
{
	if (activityGnuplotFile)
	{
		activityGnuplotFile->systemFile();
	}
	else
	{
		cerr << "Warning, neuronGnuplotFile is not inited" << endl;
	}
}

void ActivityStater::closeGrapher()
{
	if (activityGnuplotFile->isOpen())
	{
		activityGnuplotFile->closeFile();
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

void ActivityStater::initAccumulaters()
{
	if (meanTimeFrequency)
	{
		for (int i=0;i<NB_FREQUENCY_BINS;i++)
		{
			meanTimeFrequency[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, meanTimeFrequency should be inited" << endl;
	}

	if (meanHighTimeFrequency)
	{
		for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
		{
			meanHighTimeFrequency[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, meanHighTimeFrequencies should be inited" << endl;
	}
	
	
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	if (meanExcitPreTempDevRepartition)
	{
		for (int i=0;i<100;i++)
		{
			meanExcitPreTempDevRepartition[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, meanExcitPreTempDevRepartition should be inited" << endl;
	}
	
	if (meanExcitPostTempDevRepartition)
	{
		for (int i=0;i<100;i++)
		{
			meanExcitPostTempDevRepartition[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, meanExcitPostTempDevRepartition should be inited" << endl;
	}
	
	if (meanInhibPreTempDevRepartition)
	{
		for (int i=0;i<100;i++)
		{
			meanInhibPreTempDevRepartition[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, meanInhibPreTempDevRepartition should be inited" << endl;
	}
	
	if (meanInhibPostTempDevRepartition)
	{
		for (int i=0;i<100;i++)
		{
			meanInhibPostTempDevRepartition[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, meanInhibPostTempDevRepartition should be inited" << endl;
	}
	
				#endif
				
	if (meanISIRepartition)
	{
		for (int i=0;i<100;i++)
		{
			meanISIRepartition[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, meanISIRepartition should be inited" << endl;
	}
	
	
	if (meanSpikeRepartition)
	{
		for (int i=0;i<NB_HIDDEN_NEURONS;i++)
		{
			meanSpikeRepartition[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, meanISIRepartition should be inited" << endl;
	}
}

		#ifndef _PARAMETRIC_TEST_MODE
			#ifndef _PHASE_TEST_MODE
void ActivityStater::trace()
{
	if (meanTimeFrequencyFile->isOpen())
	{
		if (meanTimeFrequency)
		{
			for (int i=0;i<NB_FREQUENCY_BINS;i++)
			{
				meanTimeFrequencyFile->addLineData(i*5,(double) meanTimeFrequency[i].getMean());

			}
		}
		
		meanTimeFrequencyFile->addDataSeparator();
	}
	else
	{
		cerr << "Warning, timeFrequencyFile should be inited" << endl;
	}

	if (meanHighTimeFrequencyFile->isOpen())
	{
		if (meanHighTimeFrequency)
		{
			for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
			{
				meanHighTimeFrequencyFile->addLineData(i*HIGH_FREQUENCY_BIN_LENGTH,(double) meanHighTimeFrequency[i].getMean());
				//highTimeFrequencyFile->addIndexedLineData(timeOfTrace,i*10,(double) highFrequenciesCounters[i].getCounter());
			}
		}
		
		meanHighTimeFrequencyFile->addDataSeparator();
	}
	else
	{
		cerr << "Warning, highTimeFrequencyFile should be inited" << endl;
	}
	
		
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	if (meanExcitTempDevRepartitionFile->isOpen())
	{
		if (meanExcitPreTempDevRepartition)
		{
			for (int i=0;i<100;i++)
			{
				meanExcitTempDevRepartitionFile->addLineData(99-i,(double) meanExcitPreTempDevRepartition[99-i].getMean());
			}
		}
		else
		{
			cerr << "Warning, meanExcitPreTempDevRepartition should be inited" << endl;
		}
		
		if (meanExcitPostTempDevRepartition)
		{
			for (int i=0;i<100;i++)
			{
				meanExcitTempDevRepartitionFile->addLineData(i,(double) meanExcitPostTempDevRepartition[i].getMean());
			}
		}
		else
		{
			cerr << "Warning, meanExcitPostTempDevRepartition should be inited" << endl;
		}
	}
	
	if (meanInhibTempDevRepartitionFile->isOpen())
	{
		if (meanInhibPreTempDevRepartition)
		{
			for (int i=0;i<100;i++)
			{
				meanInhibTempDevRepartitionFile->addLineData(99-i,(double) meanInhibPreTempDevRepartition[99-i].getMean());
			}
		}
		else
		{
			cerr << "Warning, meanInhibPreTempDevRepartition should be inited" << endl;
		}
		
		if (meanInhibPostTempDevRepartition)
		{
			for (int i=0;i<100;i++)
			{
				meanInhibTempDevRepartitionFile->addLineData(i,(double) meanInhibPostTempDevRepartition[i].getMean());
			}
		}
		else
		{
			cerr << "Warning, meanInhibPostTempDevRepartition should be inited" << endl;
		}
	}
	
				#endif
				
	if (meanISIRepartitionFile->isOpen())
	{
		if (meanISIRepartition)
		{
			for (int i=0;i<100;i++)
			{
				meanISIRepartitionFile->addLineData(i,(double) meanISIRepartition[i].getMean());
				//highTimeFrequencyFile->addIndexedLineData(timeOfTrace,i*10,(double) highFrequenciesCounters[i].getCounter());
			}
		}
		
		meanISIRepartitionFile->addDataSeparator();
	}
	else
	{
		cerr << "Warning, meanISIRepartitionFile should be inited" << endl;
	}	
	
	if (meanSpikeRepartitionFile->isOpen())
	{
		if (meanSpikeRepartition)
		{
			for (int i=0;i<NB_HIDDEN_NEURONS;i++)
			{
				//meanSpikeRepartitionFile->addLineData(i,(double) meanSpikeRepartition[i].getMean());
				meanSpikeRepartitionFile->addLineData(i,(double) meanSpikeRepartition[i].getAccu());
			}
		}
		
		meanSpikeRepartitionFile->addDataSeparator();
	}
	else
	{
		cerr << "Warning, meanSpikeRepartitionFile should be inited" << endl;
	}
}

void ActivityStater::graph()
{
	if (activityGnuplotFile->isOpen())
	{
		//#ifdef _TEST_STAT
		cout << "In graph global assemblies activity" << getIndex() << endl;
		//#endif
		
		activityGnuplotFile->setOutput("meanTimeFrequencyStats");
		activityGnuplotFile->setTitle("meanTimeFrequencyStats");
		activityGnuplotFile->plotLine("meanTimeFrequencyStats");
		
		activityGnuplotFile->setOutput("meanHighTimeFrequencyStats");
		activityGnuplotFile->setTitle("meanHighTimeFrequencyStats");
		activityGnuplotFile->plotLine("meanHighTimeFrequencyStats");
		
		
			#ifdef _GLOBAL_SYNAPSE_STAT_MODE
		activityGnuplotFile->setOutput("meanExcitTempDevRepartitionStats");
		activityGnuplotFile->setTitle("meanExcitTempDevRepartitionStats");
		activityGnuplotFile->plotLine("meanExcitTempDevRepartitionStats");	
		
		activityGnuplotFile->setOutput("meanInhibTempDevRepartitionStats");
		activityGnuplotFile->setTitle("meanInhibTempDevRepartitionStats");
		activityGnuplotFile->plotLine("meanInhibTempDevRepartitionStats");	
		
		activityGnuplotFile->setOutput("meanISIRepartitionStats");
		activityGnuplotFile->setTitle("meanISIRepartitionStats");
		activityGnuplotFile->plotLine("meanISIRepartitionStats");	
		
		activityGnuplotFile->setOutput("meanSpikeRepartitionStats");
		activityGnuplotFile->setTitle("meanSpikeRepartitionStats");
		activityGnuplotFile->plotLine("meanSpikeRepartitionStats");
			#endif
				
			#ifdef _SORT_ASSEMBLY_STAT_MODE
		activityGnuplotFile->setOutput("meanSortedSpikeRepartitionStats");
		activityGnuplotFile->setTitle("meanSpikeRepartitionStats");
		activityGnuplotFile->plotSorted2Line("meanSpikeRepartitionStats");
			#endif	
	}
	else
	{
		cerr << "Warning, activityGnuplotFile should be open" << endl;
	}
}
			#endif
		#endif

void ActivityStater::stat()
{
	if (meanTimeFrequency)
	{
		for (int i=0;i<NB_FREQUENCY_BINS;i++)
		{
			if (!frequenciesCounters[i].isVoid())
			{
				meanTimeFrequency[i].accumulate((double) frequenciesCounters[i].getCounter());
				////cout << "frequenciesCounters " << i << " " << frequenciesCounters[i].getCounter() << endl;
				frequenciesCounters[i].initCounter();
			}
			else
			{
				//cout << "meanTimeFrequency " << i << " is void" << endl;
				meanTimeFrequency[i].setVoid();
				frequenciesCounters[i].freeVoid();
			}
		}
	}
	else
	{
		cerr << "Warning, meanTimeFrequency should be inited" << endl;
	}

	
	if (meanHighTimeFrequency)
	{
		for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
		{
			if (!highFrequenciesCounters[i].isVoid())
			{
				meanHighTimeFrequency[i].accumulate((double) highFrequenciesCounters[i].getCounter());
				////cout << "highFrequenciesCounters " << i << " " << highFrequenciesCounters[i].getCounter() << endl;
				highFrequenciesCounters[i].initCounter();
			}
			else
			{
				//cout << "meanHighTimeFrequency " << i << " is void" << endl;
				meanHighTimeFrequency[i].setVoid();
				highFrequenciesCounters[i].freeVoid();
			}
		}
	}
	else
	{
		cerr << "Warning, meanHighTimeFrequency should be inited" << endl;
	}
	
		#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	if (meanExcitPreTempDevRepartition)
	{
		for (int i=0;i<100;i++)
		{
			if (!excitSS->isVoidExcitPreTempDevRepartition(i))
			{
				meanExcitPreTempDevRepartition[i].accumulate((double) excitSS->getExcitPreTempDevRepartition(i));
			}
			else
			{
				//cout << "meanExcitPreTempDevRepartition " << i << " is void" << endl;
				meanExcitPreTempDevRepartition[i].setVoid();
				excitSS->freeVoidExcitPreTempDevRepartition(i);
			}
			////cout << "ExcitPreTempDevRepartition " << i << " " << excitSS->getExcitPreTempDevRepartition(i) << endl;
		}
	}
	else
	{
		cerr << "Warning, meanExcitPreTempDevRepartition should be inited" << endl;
	}
	
	if (meanExcitPostTempDevRepartition)
	{
		for (int i=0;i<100;i++)
		{
			if (!excitSS->isVoidExcitPostTempDevRepartition(i))
			{
				meanExcitPostTempDevRepartition[i].accumulate((double) excitSS->getExcitPostTempDevRepartition(i));
			}
			else
			{
				//cout << "meanExcitPostTempDevRepartition " << i << " is void" << endl;
				meanExcitPostTempDevRepartition[i].setVoid();
				excitSS->freeVoidExcitPostTempDevRepartition(i);
			}
		}
	}
	else
	{
		cerr << "Warning, meanExcitPostTempDevRepartition should be inited" << endl;
	}
	
	excitSS->initCounters();
	
	if (meanInhibPreTempDevRepartition)
	{
		for (int i=0;i<100;i++)
		{
			if (!inhibSS->isVoidInhibPreTempDevRepartition(i))
			{
				meanInhibPreTempDevRepartition[i].accumulate((double) inhibSS->getInhibPreTempDevRepartition(i));
			}
			else
			{
				//cout << "meanInhibPreTempDevRepartition " << i << " is void" << endl;
				meanInhibPreTempDevRepartition[i].setVoid();
				inhibSS->freeVoidInhibPreTempDevRepartition(i);
			}
			////cout << "InhibPreTempDevRepartition " << i << " " << inhibSS->getInhibPreTempDevRepartition(i) << endl;
		}
	}
	else
	{
		cerr << "Warning, meanInhibPreTempDevRepartition should be inited" << endl;
	}
	
	if (meanInhibPostTempDevRepartition)
	{
		for (int i=0;i<100;i++)
		{
			if (!inhibSS->isVoidInhibPostTempDevRepartition(i))
			{
				meanInhibPostTempDevRepartition[i].accumulate((double) inhibSS->getInhibPostTempDevRepartition(i));
			}
			else
			{
				//cout << "meanInhibPostTempDevRepartition " << i << " is void" << endl;
				meanInhibPostTempDevRepartition[i].setVoid();
				inhibSS->freeVoidInhibPostTempDevRepartition(i);
			}
		}
	}
	else
	{
		cerr << "Warning, meanInhibPostTempDevRepartition should be inited" << endl;
	}
	
	inhibSS->initCounters();
		#endif
	
	// ISI
	if (meanISIRepartition)
	{
		for (int i=0;i<100;i++)
		{
			if (!ISICounters[i].isVoid())
			{
				meanISIRepartition[i].accumulate((double) ISICounters[i].getCounter());
				////cout << "meanISIRepartition " << i << " " << meanISIRepartition[i].getCounter() << endl;
				ISICounters[i].initCounter();
			}
			else
			{
				//cout << "meanISIRepartition " << i << " is void" << endl;
				meanISIRepartition[i].setVoid();
				ISICounters[i].freeVoid();
			}
		}
	}
	else
	{
		cerr << "Warning, meanISIRepartition should be inited" << endl;
	}
	
	// Spike counters
	if (meanSpikeRepartition)
	{
		for (int i=0;i<NB_HIDDEN_NEURONS;i++)
		{
			if (!spikeCounters[i].isVoid())
			{
				meanSpikeRepartition[i].accumulate((double) spikeCounters[i].getCounter());
				////cout << "meanISIRepartition " << i << " " << meanISIRepartition[i].getCounter() << endl;
				spikeCounters[i].initCounter();
			}
			else
			{
				//cout << "meanSpikeRepartition " << i << " is void" << endl;
				meanSpikeRepartition[i].setVoid();
				spikeCounters[i].freeVoid();
			}
		}
	}
	else
	{
		cerr << "Warning, meanISIRepartition should be inited" << endl;
	}
}
	#endif
#endif


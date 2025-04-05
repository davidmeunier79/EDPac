// ActivityStater.cc

// Local Includes
#include "InputStater.h"

/****************************************************************************************************************************************/
/************************************************* Methodes de la classe InputStater ************************************************/
/****************************************************************************************************************************************/

InputStater::InputStater()
{

#ifdef _GLOBAL_STAT_MODE
	#ifdef _MULTI_TEST_MODE
	initAccumulaters();
		
		#ifndef _PARAMETRIC_TEST_MODE
			#ifndef _PHASE_TEST_MODE
	activityGnuplotFile = new GnuplotFile();
	
	meanInputTimeFrequencyFile = new DataFile();
	meanInputHighTimeFrequencyFile = new DataFile();
	
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	meanInputExcitTempDevRepartitionFile = new DataFile();
	meanInputInhibTempDevRepartitionFile = new DataFile();
				#endif
				
	meanInputISIRepartitionFile = new DataFile();
	meanInputSpikeRepartitionFile = new DataFile();
	
	openStater();
			#endif
		#endif
	#endif
#endif
}

InputStater::InputStater(IndexedObject* io): NeuronStater(io)
{

#ifdef _GLOBAL_STAT_MODE
	#ifdef _MULTI_TEST_MODE
	initAccumulaters();
	
		#ifndef _PARAMETRIC_TEST_MODE
			#ifndef _PHASE_TEST_MODE
	activityGnuplotFile = new GnuplotFile();
	
	meanInputTimeFrequencyFile = new DataFile();
	meanInputHighTimeFrequencyFile = new DataFile();
	
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	meanInputExcitTempDevRepartitionFile = new DataFile();
	meanInputInhibTempDevRepartitionFile = new DataFile();
				#endif
				
	meanInputISIRepartitionFile = new DataFile();
	meanInputSpikeRepartitionFile = new DataFile();
	
	openStater();
			#endif
		#endif
	#endif
#endif
}

InputStater::~InputStater()
{


#ifdef _GLOBAL_STAT_MODE
	#ifdef _MULTI_TEST_MODE
		#ifndef _PARAMETRIC_TEST_MODE
			#ifndef _PHASE_TEST_MODE
	cerr << "In ~InputStater" << endl;		
	closeStater();

	delete(meanInputTimeFrequencyFile);
	delete(meanInputHighTimeFrequencyFile);
	
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	delete(meanInputExcitTempDevRepartitionFile);
	delete(meanInputInhibTempDevRepartitionFile);
				#endif
				
	delete(meanInputISIRepartitionFile);
	delete(meanInputSpikeRepartitionFile);
	
	delete(activityGnuplotFile);
	
	cerr << "After Freeing InputStater" << endl;
			#endif
		#endif
	#endif
#endif
}

#ifdef _GLOBAL_STAT_MODE
	#ifdef _MULTI_TEST_MODE
		#ifndef _PARAMETRIC_TEST_MODE
			#ifndef _PHASE_TEST_MODE
void InputStater::openTracer()
{
	if (meanInputTimeFrequencyFile)
	{
		ostringstream oss;
		oss << "meanInputTimeFrequencyStats";
		meanInputTimeFrequencyFile->openDataFile(oss.str());
	}

	if (meanInputHighTimeFrequencyFile)
	{
		ostringstream oss;
		oss << "meanInputHighTimeFrequencyStats";
		meanInputHighTimeFrequencyFile->openDataFile(oss.str());
	}
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	if (meanInputExcitTempDevRepartitionFile)
	{
		ostringstream oss;
		oss << "meanInputExcitTempDevRepartitionStats";
		meanInputExcitTempDevRepartitionFile->openDataFile(oss.str());
	}
	
	if (meanInputInhibTempDevRepartitionFile)
	{
		ostringstream oss;
		oss << "meanInputInhibTempDevRepartitionStats";
		meanInputInhibTempDevRepartitionFile->openDataFile(oss.str());
	}
				#endif
				
	if (meanInputISIRepartitionFile)
	{
		ostringstream oss;
		oss << "meanInputISIRepartitionStats";
		meanInputISIRepartitionFile->openDataFile(oss.str());
	}
	
	if (meanInputSpikeRepartitionFile)
	{
		ostringstream oss;
		oss << "meanInputSpikeRepartitionStats";
		meanInputSpikeRepartitionFile->openDataFile(oss.str());
	}
}

void InputStater::closeTracer()
{
	if (meanInputTimeFrequencyFile->isOpen())
	{
		meanInputTimeFrequencyFile->closeFile();
	}
	
	if (meanInputHighTimeFrequencyFile->isOpen())
	{
		meanInputHighTimeFrequencyFile->closeFile();
	}
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	if (meanInputExcitTempDevRepartitionFile->isOpen())
	{
		meanInputExcitTempDevRepartitionFile->closeFile();
	}
	
	if (meanInputInhibTempDevRepartitionFile->isOpen())
	{
		meanInputInhibTempDevRepartitionFile->closeFile();
	}
				#endif
				
	if (meanInputISIRepartitionFile->isOpen())
	{
		meanInputISIRepartitionFile->closeFile();
	}
	
	if (meanInputSpikeRepartitionFile->isOpen())
	{
		meanInputSpikeRepartitionFile->closeFile();
				#ifdef _SORT_ASSEMBLY_STAT_MODE
		meanInputSpikeRepartitionFile->formatValuesFile();
				#endif
	}
}

void InputStater::openGrapher()
{
	if (activityGnuplotFile)
	{
		activityGnuplotFile->openGnuplotFile("InputStat");
	}
	else
	{
		cerr << "Warning, activityGnuplotFile is not inited" << endl;
	}
}

void InputStater::runGrapher()
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

void InputStater::closeGrapher()
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

void InputStater::initAccumulaters()
{
	if (meanInputTimeFrequency)
	{
		for (int i=0;i<NB_FREQUENCY_BINS;i++)
		{
			meanInputTimeFrequency[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, meanInputTimeFrequency should be inited" << endl;
	}

	if (meanInputHighTimeFrequency)
	{
		for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
		{
			meanInputHighTimeFrequency[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, meanInputHighTimeFrequencies should be inited" << endl;
	}
		
		#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	if (meanInputExcitPreTempDevRepartition)
	{
		for (int i=0;i<100;i++)
		{
			meanInputExcitPreTempDevRepartition[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, meanInputExcitPreTempDevRepartition should be inited" << endl;
	}
	
	if (meanInputExcitPostTempDevRepartition)
	{
		for (int i=0;i<100;i++)
		{
			meanInputExcitPostTempDevRepartition[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, meanInputExcitPostTempDevRepartition should be inited" << endl;
	}
	
	if (meanInputInhibPreTempDevRepartition)
	{
		for (int i=0;i<100;i++)
		{
			meanInputInhibPreTempDevRepartition[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, meanInputInhibPreTempDevRepartition should be inited" << endl;
	}
	
	if (meanInputInhibPostTempDevRepartition)
	{
		for (int i=0;i<100;i++)
		{
			meanInputInhibPostTempDevRepartition[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, meanInputInhibPostTempDevRepartition should be inited" << endl;
	}
			#endif
			
	if (meanInputISIRepartition)
	{
		for (int i=0;i<100;i++)
		{
			meanInputISIRepartition[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, meanInputISIRepartition should be inited" << endl;
	}
	
	
	if (meanInputSpikeRepartition)
	{
		for (int i=0;i<NB_HIDDEN_NEURONS;i++)
		{
			meanInputSpikeRepartition[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, meanInputISIRepartition should be inited" << endl;
	}
}

		#ifndef _PARAMETRIC_TEST_MODE
			#ifndef _PHASE_TEST_MODE
void InputStater::trace()
{
	if (meanInputTimeFrequencyFile->isOpen())
	{
		if (meanInputTimeFrequency)
		{
			for (int i=0;i<NB_FREQUENCY_BINS;i++)
			{
				meanInputTimeFrequencyFile->addLineData(i*5,(double) meanInputTimeFrequency[i].getMean());

			}
		}
		
		meanInputTimeFrequencyFile->addDataSeparator();
	}
	else
	{
		cerr << "Warning, timeFrequencyFile should be inited" << endl;
	}

	if (meanInputHighTimeFrequencyFile->isOpen())
	{
		if (meanInputHighTimeFrequency)
		{
			for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
			{
				meanInputHighTimeFrequencyFile->addLineData(i*HIGH_FREQUENCY_BIN_LENGTH,(double) meanInputHighTimeFrequency[i].getMean());
				//highTimeFrequencyFile->addIndexedLineData(timeOfTrace,i*10,(double) highFrequenciesCounters[i].getCounter());
			}
		}
		
		meanInputHighTimeFrequencyFile->addDataSeparator();
	}
	else
	{
		cerr << "Warning, highTimeFrequencyFile should be inited" << endl;
	}
	
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	if (meanInputExcitTempDevRepartitionFile->isOpen())
	{
		if (meanInputExcitPreTempDevRepartition)
		{
			for (int i=0;i<100;i++)
			{
				meanInputExcitTempDevRepartitionFile->addLineData(99-i,(double) meanInputExcitPreTempDevRepartition[99-i].getMean());
			}
		}
		else
		{
			cerr << "Warning, meanInputExcitPreTempDevRepartition should be inited" << endl;
		}
		
		if (meanInputExcitPostTempDevRepartition)
		{
			for (int i=0;i<100;i++)
			{
				meanInputExcitTempDevRepartitionFile->addLineData(i,(double) meanInputExcitPostTempDevRepartition[i].getMean());
			}
		}
		else
		{
			cerr << "Warning, meanInputExcitPostTempDevRepartition should be inited" << endl;
		}
	}
	
	if (meanInputInhibTempDevRepartitionFile->isOpen())
	{
		if (meanInputInhibPreTempDevRepartition)
		{
			for (int i=0;i<100;i++)
			{
				meanInputInhibTempDevRepartitionFile->addLineData(99-i,(double) meanInputInhibPreTempDevRepartition[99-i].getMean());
			}
		}
		else
		{
			cerr << "Warning, meanInputInhibPreTempDevRepartition should be inited" << endl;
		}
		
		if (meanInputInhibPostTempDevRepartition)
		{
			for (int i=0;i<100;i++)
			{
				meanInputInhibTempDevRepartitionFile->addLineData(i,(double) meanInputInhibPostTempDevRepartition[i].getMean());
			}
		}
		else
		{
			cerr << "Warning, meanInputInhibPostTempDevRepartition should be inited" << endl;
		}
	}
				#endif
				
	if (meanInputISIRepartitionFile->isOpen())
	{
		if (meanInputISIRepartition)
		{
			for (int i=0;i<100;i++)
			{
				meanInputISIRepartitionFile->addLineData(i,(double) meanInputISIRepartition[i].getMean());
				//highTimeFrequencyFile->addIndexedLineData(timeOfTrace,i*10,(double) highFrequenciesCounters[i].getCounter());
			}
		}
		
		meanInputISIRepartitionFile->addDataSeparator();
	}
	else
	{
		cerr << "Warning, meanInputISIRepartitionFile should be inited" << endl;
	}	
	
	if (meanInputSpikeRepartitionFile->isOpen())
	{
		if (meanInputSpikeRepartition)
		{
			for (int i=0;i<NB_HIDDEN_NEURONS;i++)
			{
				//meanInputSpikeRepartitionFile->addLineData(i,(double) meanInputSpikeRepartition[i].getMean());
				meanInputSpikeRepartitionFile->addLineData(i,(double) meanInputSpikeRepartition[i].getAccu());
			}
		}
		
		meanInputSpikeRepartitionFile->addDataSeparator();
	}
	else
	{
		cerr << "Warning, meanInputSpikeRepartitionFile should be inited" << endl;
	}
}

void InputStater::graph()
{
	if (activityGnuplotFile->isOpen())
	{
		//#ifdef _TEST_STAT
		cout << "In graph global assemblies activity" << getIndex() << endl;
		//#endif
		
		ostringstream oss;
		oss << (Handler*) this;
		
		#ifdef _PHASE_TEST_MODE
		activityGnuplotFile->setOutput("meanInputTimeFrequencyStats");
		activityGnuplotFile->setTitle("meanInputTimeFrequencyStats");
		activityGnuplotFile->plotTitleIndexedLines("meanInputTimeFrequencyStats",0,getEvalIndex());
		
		activityGnuplotFile->setOutput("meanInputHighTimeFrequencyStats");
		activityGnuplotFile->setTitle("meanInputHighTimeFrequencyStats");
		activityGnuplotFile->plotTitleIndexedLines("meanInputHighTimeFrequencyStats",0,getEvalIndex());
		
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
		activityGnuplotFile->setOutput("meanInputExcitTempDevRepartitionStats");
		activityGnuplotFile->setTitle("meanInputExcitTempDevRepartitionStats");
		activityGnuplotFile->plotIndexedLines("meanInputExcitTempDevRepartitionStats",0,getEvalIndex());	
		
		activityGnuplotFile->setOutput("meanInputInhibTempDevRepartitionStats");
		activityGnuplotFile->setTitle("meanInputInhibTempDevRepartitionStats");
		activityGnuplotFile->plotIndexedLines("meanInputInhibTempDevRepartitionStats",0,getEvalIndex());	
				#endif
				
		activityGnuplotFile->setOutput("meanInputISIRepartitionStats");
		activityGnuplotFile->setTitle("meanInputISIRepartitionStats");
		activityGnuplotFile->plotIndexedLines("meanInputISIRepartitionStats",0,getEvalIndex());	
		#else
		
		activityGnuplotFile->setOutput("meanInputTimeFrequencyStats");
		activityGnuplotFile->setTitle("meanInputTimeFrequencyStats");
		activityGnuplotFile->plotLine("meanInputTimeFrequencyStats");
		
		activityGnuplotFile->setOutput("meanInputHighTimeFrequencyStats");
		activityGnuplotFile->setTitle("meanInputHighTimeFrequencyStats");
		activityGnuplotFile->plotLine("meanInputHighTimeFrequencyStats");
		
			#ifdef _GLOBAL_SYNAPSE_STAT_MODE
		activityGnuplotFile->setOutput("meanInputExcitTempDevRepartitionStats");
		activityGnuplotFile->setTitle("meanInputExcitTempDevRepartitionStats");
		activityGnuplotFile->plotLine("meanInputExcitTempDevRepartitionStats");	
		
		activityGnuplotFile->setOutput("meanInputInhibTempDevRepartitionStats");
		activityGnuplotFile->setTitle("meanInputInhibTempDevRepartitionStats");
		activityGnuplotFile->plotLine("meanInputInhibTempDevRepartitionStats");	
			#endif
			
		activityGnuplotFile->setOutput("meanInputISIRepartitionStats");
		activityGnuplotFile->setTitle("meanInputISIRepartitionStats");
		activityGnuplotFile->plotLine("meanInputISIRepartitionStats");	
		
		activityGnuplotFile->setOutput("meanInputSpikeRepartitionStats");
		activityGnuplotFile->setTitle("meanInputSpikeRepartitionStats");
		activityGnuplotFile->plotLine("meanInputSpikeRepartitionStats");
		
			#ifdef _SORT_ASSEMBLY_STAT_MODE
		activityGnuplotFile->setOutput("meanInputSortedSpikeRepartitionStats");
		activityGnuplotFile->setTitle("meanInputSpikeRepartitionStats");
		activityGnuplotFile->plotSorted2Line("meanInputSpikeRepartitionStats");
			#endif	
		#endif
	}
	else
	{
		cerr << "Warning, activityGnuplotFile should be open" << endl;
	}
}
	
			#endif	
		#endif

void InputStater::stat()
{
	if (meanInputTimeFrequency)
	{
		for (int i=0;i<NB_FREQUENCY_BINS;i++)
		{
			if (!frequenciesCounters[i].isVoid())
			{
				meanInputTimeFrequency[i].accumulate((double) frequenciesCounters[i].getCounter());
				////cout << "frequenciesCounters " << i << " " << frequenciesCounters[i].getCounter() << endl;
				frequenciesCounters[i].initCounter();
			}
			else
			{
				//cout << "meanInputTimeFrequency " << i << " is void" << endl;
				meanInputTimeFrequency[i].setVoid();
				frequenciesCounters[i].freeVoid();
			}
		}
	}
	else
	{
		cerr << "Warning, meanInputTimeFrequency should be inited" << endl;
	}

	
	if (meanInputHighTimeFrequency)
	{
		for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
		{
			if (!highFrequenciesCounters[i].isVoid())
			{
				meanInputHighTimeFrequency[i].accumulate((double) highFrequenciesCounters[i].getCounter());
				////cout << "highFrequenciesCounters " << i << " " << highFrequenciesCounters[i].getCounter() << endl;
				highFrequenciesCounters[i].initCounter();
			}
			else
			{
				//cout << "meanInputHighTimeFrequency " << i << " is void" << endl;
				meanInputHighTimeFrequency[i].setVoid();
				highFrequenciesCounters[i].freeVoid();
			}
		}
	}
	else
	{
		cerr << "Warning, meanInputHighTimeFrequency should be inited" << endl;
	}
	
		#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	if (meanInputExcitPreTempDevRepartition)
	{
		for (int i=0;i<100;i++)
		{
			if (!excitSS->isVoidExcitPreTempDevRepartition(i))
			{
				meanInputExcitPreTempDevRepartition[i].accumulate((double) excitSS->getExcitPreTempDevRepartition(i));
			}
			else
			{
				//cout << "meanInputExcitPreTempDevRepartition " << i << " is void" << endl;
				meanInputExcitPreTempDevRepartition[i].setVoid();
				excitSS->freeVoidExcitPreTempDevRepartition(i);
			}
			////cout << "ExcitPreTempDevRepartition " << i << " " << excitSS->getExcitPreTempDevRepartition(i) << endl;
		}
	}
	else
	{
		cerr << "Warning, meanInputExcitPreTempDevRepartition should be inited" << endl;
	}
	
	if (meanInputExcitPostTempDevRepartition)
	{
		for (int i=0;i<100;i++)
		{
			if (!excitSS->isVoidExcitPostTempDevRepartition(i))
			{
				meanInputExcitPostTempDevRepartition[i].accumulate((double) excitSS->getExcitPostTempDevRepartition(i));
			}
			else
			{
				//cout << "meanInputExcitPostTempDevRepartition " << i << " is void" << endl;
				meanInputExcitPostTempDevRepartition[i].setVoid();
				excitSS->freeVoidExcitPostTempDevRepartition(i);
			}
		}
	}
	else
	{
		cerr << "Warning, meanInputExcitPostTempDevRepartition should be inited" << endl;
	}
	
	excitSS->initCounters();
	
	if (meanInputInhibPreTempDevRepartition)
	{
		for (int i=0;i<100;i++)
		{
			if (!inhibSS->isVoidInhibPreTempDevRepartition(i))
			{
				meanInputInhibPreTempDevRepartition[i].accumulate((double) inhibSS->getInhibPreTempDevRepartition(i));
			}
			else
			{
				//cout << "meanInputInhibPreTempDevRepartition " << i << " is void" << endl;
				meanInputInhibPreTempDevRepartition[i].setVoid();
				inhibSS->freeVoidInhibPreTempDevRepartition(i);
			}
			////cout << "InhibPreTempDevRepartition " << i << " " << inhibSS->getInhibPreTempDevRepartition(i) << endl;
		}
	}
	else
	{
		cerr << "Warning, meanInputInhibPreTempDevRepartition should be inited" << endl;
	}
	
	if (meanInputInhibPostTempDevRepartition)
	{
		for (int i=0;i<100;i++)
		{
			if (!inhibSS->isVoidInhibPostTempDevRepartition(i))
			{
				meanInputInhibPostTempDevRepartition[i].accumulate((double) inhibSS->getInhibPostTempDevRepartition(i));
			}
			else
			{
				//cout << "meanInputInhibPostTempDevRepartition " << i << " is void" << endl;
				meanInputInhibPostTempDevRepartition[i].setVoid();
				inhibSS->freeVoidInhibPostTempDevRepartition(i);
			}
		}
	}
	else
	{
		cerr << "Warning, meanInputInhibPostTempDevRepartition should be inited" << endl;
	}
	
	inhibSS->initCounters();
		#endif
		
	// ISI
	if (meanInputISIRepartition)
	{
		for (int i=0;i<100;i++)
		{
			if (!ISICounters[i].isVoid())
			{
				meanInputISIRepartition[i].accumulate((double) ISICounters[i].getCounter());
				////cout << "meanInputISIRepartition " << i << " " << meanInputISIRepartition[i].getCounter() << endl;
				ISICounters[i].initCounter();
			}
			else
			{
				//cout << "meanInputISIRepartition " << i << " is void" << endl;
				meanInputISIRepartition[i].setVoid();
				ISICounters[i].freeVoid();
			}
		}
	}
	else
	{
		cerr << "Warning, meanInputISIRepartition should be inited" << endl;
	}
	
	// Spike counters
	if (meanInputSpikeRepartition)
	{
		for (int i=0;i<NB_HIDDEN_NEURONS;i++)
		{
			if (!spikeCounters[i].isVoid())
			{
				meanInputSpikeRepartition[i].accumulate((double) spikeCounters[i].getCounter());
				////cout << "meanInputISIRepartition " << i << " " << meanInputISIRepartition[i].getCounter() << endl;
				spikeCounters[i].initCounter();
			}
			else
			{
				//cout << "meanInputSpikeRepartition " << i << " is void" << endl;
				meanInputSpikeRepartition[i].setVoid();
				spikeCounters[i].freeVoid();
			}
		}
	}
	else
	{
		cerr << "Warning, meanInputISIRepartition should be inited" << endl;
	}
	
}
	#endif
#endif

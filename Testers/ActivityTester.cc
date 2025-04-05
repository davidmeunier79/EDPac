// ActivityTester.cc

// Local Includes
#include "ActivityTester.h"

/****************************************************************************************************************************************/
/************************************************* Methodes de la classe ActivityTester ************************************************/
/****************************************************************************************************************************************/

ActivityTester::ActivityTester()
{

#ifdef _GLOBAL_STAT_MODE
	#ifdef _MULTI_TEST_MODE	
	initAccumulaters();
	
	activityTestGnuplotFile = new GnuplotFile();
	
		#ifdef _PARAMETRIC_TEST_MODE
	timeFrequencyTestFile = new DataFile();
	highTimeFrequencyTestFile = new DataFile();
	
			#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	excitTempDevRepartitionTestFile = new DataFile();
	inhibTempDevRepartitionTestFile = new DataFile();
			#endif
			
	ISIRepartitionTestFile = new DataFile();
	SpikeRepartitionTestFile = new DataFile();
	AssemblySpikeRepartitionTestFile = new DataFile();
	
			#ifdef _PHASE_TEST_MODE
	diffTimeFrequencyTestFile = new DataFile();
	diffHighTimeFrequencyTestFile = new DataFile();
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	diffExcitTempDevRepartitionTestFile = new DataFile();
	diffInhibTempDevRepartitionTestFile = new DataFile();
				#endif
	diffISIRepartitionTestFile = new DataFile();
	diffSpikeRepartitionTestFile = new DataFile();
	diffAssemblySpikeRepartitionTestFile = new DataFile();
	
			#endif
		#else
			#ifdef _PHASE_TEST_MODE	
	timeFrequencyTestFile = new DataFile();
	highTimeFrequencyTestFile = new DataFile();
	
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	excitTempDevRepartitionTestFile = new DataFile();
	inhibTempDevRepartitionTestFile = new DataFile();
				#endif
				
	ISIRepartitionTestFile = new DataFile();
	SpikeRepartitionTestFile = new DataFile();
	AssemblySpikeRepartitionTestFile = new DataFile();
	
	diffTimeFrequencyTestFile = new DataFile();
	diffHighTimeFrequencyTestFile = new DataFile();
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	diffExcitTempDevRepartitionTestFile = new DataFile();
	diffInhibTempDevRepartitionTestFile = new DataFile();
				#endif
				
	diffISIRepartitionTestFile = new DataFile();
	diffSpikeRepartitionTestFile = new DataFile();
	diffAssemblySpikeRepartitionTestFile = new DataFile();
			#endif
		#endif
	#endif
#endif	
	openStater();
}

ActivityTester::ActivityTester(IndexedObject* io): ActivityStater(io)
{

#ifdef _GLOBAL_STAT_MODE
	#ifdef _MULTI_TEST_MODE	
	initAccumulaters();
	
	activityTestGnuplotFile = new GnuplotFile();
	
		#ifdef _PARAMETRIC_TEST_MODE
	timeFrequencyTestFile = new DataFile();
	highTimeFrequencyTestFile = new DataFile();
			#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	excitTempDevRepartitionTestFile = new DataFile();
	inhibTempDevRepartitionTestFile = new DataFile();
			#endif
			
	ISIRepartitionTestFile = new DataFile();
	SpikeRepartitionTestFile = new DataFile();
	AssemblySpikeRepartitionTestFile = new DataFile();
	
			#ifdef _PHASE_TEST_MODE
	diffTimeFrequencyTestFile = new DataFile();
	diffHighTimeFrequencyTestFile = new DataFile();
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	diffExcitTempDevRepartitionTestFile = new DataFile();
	diffInhibTempDevRepartitionTestFile = new DataFile();
				#endif
				
	diffISIRepartitionTestFile = new DataFile();
	diffSpikeRepartitionTestFile = new DataFile();
	diffAssemblySpikeRepartitionTestFile = new DataFile();
	
			#endif
		#else
			#ifdef _PHASE_TEST_MODE
	timeFrequencyTestFile = new DataFile();
	highTimeFrequencyTestFile = new DataFile();
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	excitTempDevRepartitionTestFile = new DataFile();
	inhibTempDevRepartitionTestFile = new DataFile();
				#endif
	ISIRepartitionTestFile = new DataFile();
	SpikeRepartitionTestFile = new DataFile();
	AssemblySpikeRepartitionTestFile = new DataFile();
	
	diffTimeFrequencyTestFile = new DataFile();
	diffHighTimeFrequencyTestFile = new DataFile();
	
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	diffExcitTempDevRepartitionTestFile = new DataFile();
	diffInhibTempDevRepartitionTestFile = new DataFile();
				#endif
				
	diffISIRepartitionTestFile = new DataFile();
	diffSpikeRepartitionTestFile = new DataFile();
	diffAssemblySpikeRepartitionTestFile = new DataFile();
			#endif
		#endif
	#endif
#endif
	
	openStater();
}

ActivityTester::~ActivityTester()
{
	closeStater();
	

#ifdef _GLOBAL_STAT_MODE
	#ifdef _MULTI_TEST_MODE	
		#ifdef _PARAMETRIC_TEST_MODE
	delete(timeFrequencyTestFile);
	delete(highTimeFrequencyTestFile);
	
			#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	delete(excitTempDevRepartitionTestFile);
	delete(inhibTempDevRepartitionTestFile);
			#endif
			
	delete(ISIRepartitionTestFile);
	delete(SpikeRepartitionTestFile);
	delete(AssemblySpikeRepartitionTestFile);
	
			#ifdef _PHASE_TEST_MODE

	delete(diffTimeFrequencyTestFile);
	delete(diffHighTimeFrequencyTestFile);
	
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	delete(diffExcitTempDevRepartitionTestFile);
	delete(diffInhibTempDevRepartitionTestFile);
				#endif
				
	delete(diffISIRepartitionTestFile);
	delete(diffSpikeRepartitionTestFile);
	delete(diffAssemblySpikeRepartitionTestFile);
			#endif
		#else
			#ifdef _PHASE_TEST_MODE
	
	delete(timeFrequencyTestFile);
	delete(highTimeFrequencyTestFile);
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	delete(excitTempDevRepartitionTestFile);
	delete(inhibTempDevRepartitionTestFile);
				#endif
	delete(ISIRepartitionTestFile);
	delete(SpikeRepartitionTestFile);
	delete(AssemblySpikeRepartitionTestFile);
	
	delete(diffTimeFrequencyTestFile);
	delete(diffHighTimeFrequencyTestFile);
	
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	delete(diffExcitTempDevRepartitionTestFile);
	delete(diffInhibTempDevRepartitionTestFile);
				#endif
				
	delete(diffISIRepartitionTestFile);
	delete(diffSpikeRepartitionTestFile);
	delete(diffAssemblySpikeRepartitionTestFile);
			#endif
		#endif
	delete(activityTestGnuplotFile);
	#endif
#endif	
}


#ifdef _GLOBAL_STAT_MODE
	#ifdef _MULTI_TEST_MODE
void ActivityTester::openTracer()
{
		#ifdef _PARAMETRIC_TEST_MODE
	if (timeFrequencyTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_timeFrequencyTestStats";
		timeFrequencyTestFile->openDataFile(oss.str());
	}

	if (highTimeFrequencyTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_highTimeFrequencyTestStats";
		highTimeFrequencyTestFile->openDataFile(oss.str());
	}
	
			#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	if (excitTempDevRepartitionTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_excitTempDevRepartitionTestStats";
		excitTempDevRepartitionTestFile->openDataFile(oss.str());
	}
	
	if (inhibTempDevRepartitionTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_inhibTempDevRepartitionTestStats";
		inhibTempDevRepartitionTestFile->openDataFile(oss.str());
	}
			#endif
			
	if (ISIRepartitionTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_ISIRepartitionTestStats";
		ISIRepartitionTestFile->openDataFile(oss.str());
	}
	
	if (SpikeRepartitionTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_SpikeRepartitionTestStats";
		SpikeRepartitionTestFile->openDataFile(oss.str());
	}
	
	if (AssemblySpikeRepartitionTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_AssemblySpikeRepartitionTestStats";
		AssemblySpikeRepartitionTestFile->openDataFile(oss.str());
	}
			#ifdef _PHASE_TEST_MODE

	if (diffTimeFrequencyTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_diffTimeFrequencyTestStats";
		diffTimeFrequencyTestFile->openDataFile(oss.str());
	}
	
	
	if (diffHighTimeFrequencyTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_diffHighTimeFrequencyTestStats";
		diffHighTimeFrequencyTestFile->openDataFile(oss.str());
	}

				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	if (diffExcitTempDevRepartitionTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_diffExcitTempDevRepartitionTestStats";
		diffExcitTempDevRepartitionTestFile->openDataFile(oss.str());
	}	
	
	
	if (diffInhibTempDevRepartitionTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_diffInhibTempDevRepartitionTestStats";
		diffInhibTempDevRepartitionTestFile->openDataFile(oss.str());
	}	
				#endif
				
	if (diffISIRepartitionTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_diffISIRepartitionTestStats";
		diffISIRepartitionTestFile->openDataFile(oss.str());
	}	
	
	if (diffSpikeRepartitionTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_diffSpikeRepartitionTestStats";
		diffSpikeRepartitionTestFile->openDataFile(oss.str());
	}	
	
	if (diffAssemblySpikeRepartitionTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_diffAssemblySpikeRepartitionTestStats";
		diffAssemblySpikeRepartitionTestFile->openDataFile(oss.str());
	}	
			#endif
		#else
			#ifdef _PHASE_TEST_MODE
	if (timeFrequencyTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_timeFrequencyTestStats";
		timeFrequencyTestFile->openDataFile(oss.str());
	}

	if (highTimeFrequencyTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_highTimeFrequencyTestStats";
		highTimeFrequencyTestFile->openDataFile(oss.str());
	}
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	if (excitTempDevRepartitionTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_excitTempDevRepartitionTestStats";
		excitTempDevRepartitionTestFile->openDataFile(oss.str());
	}
	
	if (inhibTempDevRepartitionTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_inhibTempDevRepartitionTestStats";
		inhibTempDevRepartitionTestFile->openDataFile(oss.str());
	}
				#endif
				
	if (ISIRepartitionTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_ISIRepartitionTestStats";
		ISIRepartitionTestFile->openDataFile(oss.str());
	}
	
	if (SpikeRepartitionTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_SpikeRepartitionTestStats";
		SpikeRepartitionTestFile->openDataFile(oss.str());
	}
	
	if (AssemblySpikeRepartitionTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_AssemblySpikeRepartitionTestStats";
		AssemblySpikeRepartitionTestFile->openDataFile(oss.str());
	}
	
	if (diffTimeFrequencyTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_diffTimeFrequencyTestStats";
		diffTimeFrequencyTestFile->openDataFile(oss.str());
	}
	
	
	if (diffHighTimeFrequencyTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_diffHighTimeFrequencyTestStats";
		diffHighTimeFrequencyTestFile->openDataFile(oss.str());
	}

				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	if (diffExcitTempDevRepartitionTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_diffExcitTempDevRepartitionTestStats";
		diffExcitTempDevRepartitionTestFile->openDataFile(oss.str());
	}	
	
	
	if (diffInhibTempDevRepartitionTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_diffInhibTempDevRepartitionTestStats";
		diffInhibTempDevRepartitionTestFile->openDataFile(oss.str());
	}	
				#endif
				
	if (diffISIRepartitionTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_diffISIRepartitionTestStats";
		diffISIRepartitionTestFile->openDataFile(oss.str());
	}	
	
	if (diffSpikeRepartitionTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_diffSpikeRepartitionTestStats";
		diffSpikeRepartitionTestFile->openDataFile(oss.str());
	}	
	
	if (diffAssemblySpikeRepartitionTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_diffAssemblySpikeRepartitionTestStats";
		diffAssemblySpikeRepartitionTestFile->openDataFile(oss.str());
	}	
	
			#endif
		#endif	
}

void ActivityTester::closeTracer()
{
		#ifdef _PARAMETRIC_TEST_MODE
	if (timeFrequencyTestFile->isOpen())
	{
		timeFrequencyTestFile->closeFile();
		//timeFrequencyTestFile->formatFile();
	}
		
	if (highTimeFrequencyTestFile->isOpen())
	{
		highTimeFrequencyTestFile->closeFile();
		//highTimeFrequencyTestFile->formatFile();
	}
			#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	if (excitTempDevRepartitionTestFile->isOpen())
	{
		excitTempDevRepartitionTestFile->closeFile();
		//excitTempDevRepartitionTestFile->formatFile();
	}
	
	if (inhibTempDevRepartitionTestFile->isOpen())
	{
		inhibTempDevRepartitionTestFile->closeFile();
		//inhibTempDevRepartitionTestFile->formatFile();
	}
			#endif
	
	if (ISIRepartitionTestFile->isOpen())
	{
		ISIRepartitionTestFile->closeFile();
		//ISIRepartitionTestFile->formatFile();
	}
	
	if (SpikeRepartitionTestFile->isOpen())
	{
		SpikeRepartitionTestFile->closeFile();
			#ifdef _SORT_ASSEMBLY_STAT_MODE
		SpikeRepartitionTestFile->formatIndexedValuesFile();
			#endif
	}
	
	if (AssemblySpikeRepartitionTestFile->isOpen())
	{
		AssemblySpikeRepartitionTestFile->closeFile();
			#ifdef _SORT_ASSEMBLY_STAT_MODE
		AssemblySpikeRepartitionTestFile->formatIndexedValuesFile();
			#endif
	}

			#ifdef _PHASE_TEST_MODE

	if (diffTimeFrequencyTestFile->isOpen())
	{
		diffTimeFrequencyTestFile->closeFile();
		//timeFrequencyTestFile->formatFile();
	}
	
	if (diffHighTimeFrequencyTestFile->isOpen())
	{
		diffHighTimeFrequencyTestFile->closeFile();
		//diffHighTimeFrequencyTestFile->formatFile();
	}
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	if (diffExcitTempDevRepartitionTestFile->isOpen())
	{
		diffExcitTempDevRepartitionTestFile->closeFile();
		//diffExcitTempDevRepartitionTestFile->formatFile();
	}
	
	if (diffInhibTempDevRepartitionTestFile->isOpen())
	{
		diffInhibTempDevRepartitionTestFile->closeFile();
		//diffInhibTempDevRepartitionTestFile->formatFile();
	}
				#endif
				
	if (diffISIRepartitionTestFile->isOpen())
	{
		diffISIRepartitionTestFile->closeFile();
		//diffExcitTempDevRepartitionTestFile->formatFile();
	}
	
	if (diffSpikeRepartitionTestFile->isOpen())
	{
		diffSpikeRepartitionTestFile->closeFile();
				#ifdef _SORT_ASSEMBLY_STAT_MODE
		diffSpikeRepartitionTestFile->formatIndexedValuesFile();
				#endif
	}
	
	if (diffAssemblySpikeRepartitionTestFile->isOpen())
	{
		diffAssemblySpikeRepartitionTestFile->closeFile();
				#ifdef _SORT_ASSEMBLY_STAT_MODE
		diffAssemblySpikeRepartitionTestFile->formatIndexedValuesFile();
				#endif
	}	
			#endif
		#else
			#ifdef _PHASE_TEST_MODE
	if (timeFrequencyTestFile->isOpen())
	{
		timeFrequencyTestFile->closeFile();
		//timeFrequencyTestFile->formatFile();
	}
		
	if (highTimeFrequencyTestFile->isOpen())
	{
		highTimeFrequencyTestFile->closeFile();
		//highTimeFrequencyTestFile->formatFile();
	}
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	if (excitTempDevRepartitionTestFile->isOpen())
	{
		excitTempDevRepartitionTestFile->closeFile();
		//excitTempDevRepartitionTestFile->formatFile();
	}
	
	if (inhibTempDevRepartitionTestFile->isOpen())
	{
		inhibTempDevRepartitionTestFile->closeFile();
		//inhibTempDevRepartitionTestFile->formatFile();
	}
				#endif
				
	if (ISIRepartitionTestFile->isOpen())
	{
		ISIRepartitionTestFile->closeFile();
		//ISIRepartitionTestFile->formatFile();
	}
	
	if (SpikeRepartitionTestFile->isOpen())
	{
		SpikeRepartitionTestFile->closeFile();
				#ifdef _SORT_ASSEMBLY_STAT_MODE
		SpikeRepartitionTestFile->formatIndexedValuesFile();
				#endif
	}
	
	if (AssemblySpikeRepartitionTestFile->isOpen())
	{
		AssemblySpikeRepartitionTestFile->closeFile();
				#ifdef _SORT_ASSEMBLY_STAT_MODE
		AssemblySpikeRepartitionTestFile->formatIndexedValuesFile();
				#endif
	}
	
	if (diffTimeFrequencyTestFile->isOpen())
	{
		diffTimeFrequencyTestFile->closeFile();
		//timeFrequencyTestFile->formatFile();
	}
	
	if (diffHighTimeFrequencyTestFile->isOpen())
	{
		diffHighTimeFrequencyTestFile->closeFile();
		//diffHighTimeFrequencyTestFile->formatFile();
	}
	
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	if (diffExcitTempDevRepartitionTestFile->isOpen())
	{
		diffExcitTempDevRepartitionTestFile->closeFile();
		//diffExcitTempDevRepartitionTestFile->formatFile();
	}
	
	if (diffInhibTempDevRepartitionTestFile->isOpen())
	{
		diffInhibTempDevRepartitionTestFile->closeFile();
		//diffInhibTempDevRepartitionTestFile->formatFile();
	}
				#endif
				
	if (diffISIRepartitionTestFile->isOpen())
	{
		diffISIRepartitionTestFile->closeFile();
		//diffExcitTempDevRepartitionTestFile->formatFile();
	}
	
	if (diffSpikeRepartitionTestFile->isOpen())
	{
		diffSpikeRepartitionTestFile->closeFile();
				#ifdef _SORT_ASSEMBLY_STAT_MODE
		diffSpikeRepartitionTestFile->formatIndexedValuesFile();
				#endif
	}
	
	if (diffAssemblySpikeRepartitionTestFile->isOpen())
	{
		diffAssemblySpikeRepartitionTestFile->closeFile();
				#ifdef _SORT_ASSEMBLY_STAT_MODE
		diffAssemblySpikeRepartitionTestFile->formatIndexedValuesFile();
				#endif
	}
	
			#else
	traceTemporalMeanIndexedFiles("highTimeFrequencyStats");
	traceTemporalMeanIndexedFiles("timeFrequencyStats");
	traceTemporalMeanIndexedFiles("ISIStats");
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	traceTemporalMeanNegativeIndexedFiles("excitTempDevRepartitionStats");
	traceTemporalMeanNegativeIndexedFiles("inhibTempDevRepartitionStats");
				#endif
	traceTemporalMeanIndexedFiles("spikeCountStats");
			#endif
		#endif
}

void ActivityTester::openGrapher()
{
	if (activityTestGnuplotFile)
	{
		activityTestGnuplotFile->openGnuplotFile("ActivityTestStat");
	}
	else
	{
		cerr << "Warning, activityTestGnuplotFile is not inited" << endl;
	}
}

void ActivityTester::runGrapher()
{
	if (activityTestGnuplotFile)
	{
		activityTestGnuplotFile->systemFile();
	}
	else
	{
		cerr << "Warning, neuronGnuplotFile is not inited" << endl;
	}
}

void ActivityTester::closeGrapher()
{
	if (activityTestGnuplotFile->isOpen())
	{
		activityTestGnuplotFile->closeFile();
	}
	else
	{
		cerr << "Warning, neuronGnuplotFile is not open" << endl;
	}
}

void ActivityTester::traceMeanFiles(string dataFileName)
{
	DataFile* awkLFPFile = new DataFile();
	
	ostringstream awkScriptFile;
	awkScriptFile << "Mean_" << dataFileName << "_AWKscript";
	
	if (awkLFPFile)
	{
		awkLFPFile->openDataFile(awkScriptFile.str());
	}
	else
	{
		cerr << "Warning, awkLFPFile is not inited" << endl;
		return;
	}
	
	initTestIndex();
	incrementTestIndex();
	
	string lastTestFileName;
	
	awkLFPFile->addStringLine("BEGIN{}");
	awkLFPFile->addStringLine("{line=$0;rng=$1;mean=$2;");

	while (getTestIndex() < NB_MULTI_TESTS+1)
	{
		ostringstream testFileName;
		testFileName << dataFileName << (Handler*) this << ".dat";
		
		if (getTestIndex()==NB_MULTI_TESTS)
		{
			lastTestFileName = testFileName.str();
		}
		else
		{
			ostringstream stringLine;
			//stringLine << "getline < \"" << testFileName.str() << "\";if (rng==$1){mean+=$2};";
			stringLine << "getline < \"" << testFileName.str() << "\";if (rng==$1){if ($2!=-1.0 && mean!=-1.0) {mean+=$2} else mean=-1.0};";
			awkLFPFile->addStringLine(stringLine.str());
		}
		
		incrementTestIndex();
	}
	
	awkLFPFile->addStringLine("if (length(line) == 0) {printf(\"\\n\");next;} else {printf(\"%d %lf\\n\",rng,mean)}");
	awkLFPFile->addStringLine("}");	
	
	ostringstream meanFileName;
	meanFileName << "Mean_" << dataFileName << ".dat";

	ostringstream meanCommand;
	meanCommand << "awk -f " << awkScriptFile.str() << ".dat " << lastTestFileName << " > " << meanFileName.str();
	
	system(((string)meanCommand.str()).c_str());
	
	if (awkLFPFile->isOpen())
	{
		awkLFPFile->closeFile();
	}
	else
	{
		cerr << "Warning, awkLFPFile is not open" << endl;
	}
	
	delete(awkLFPFile);
}

void ActivityTester::traceMeanIndexedFiles(string dataFileName)
{

	DataFile* awkHighFrequencyFile = new DataFile();
	
	ostringstream awkScriptFile;
	awkScriptFile << "Mean_" << dataFileName << "_AWKscript";
	
	if (awkHighFrequencyFile)
	{
		awkHighFrequencyFile->openDataFile(awkScriptFile.str());
	}
	else
	{
		cerr << "Warning, awkHighFrequencyFile is not inited" << endl;
		
		return;
	}
	
	initTestIndex();
	incrementTestIndex();
	
	awkHighFrequencyFile->addStringLine("BEGIN{}");
	awkHighFrequencyFile->addStringLine("{line=$0;rng=$1;time=$2;mean=$3;");
	
	//string firstTestFileName;
	string lastTestFileName;
	
	while (getTestIndex() < NB_MULTI_TESTS+1)
	{
		ostringstream testFileName;
		testFileName << "Indexed_Sorted_" << dataFileName << (Handler*) this << ".dat";
				
		if (getTestIndex()==NB_MULTI_TESTS)
		{
			lastTestFileName = testFileName.str();
		}
		else
		{
			ostringstream stringLine;
			//stringLine << "getline < \"" << testFileName.str() << "\";if (rng==$1 && time==$2){mean+=$3}";
			stringLine << "getline < \"" << testFileName.str() << "\";if (rng==$1 && time==$2){if ($3!=-1.0 && mean!=-1.0) {mean+=$3} else mean=-1.0};";
			awkHighFrequencyFile->addStringLine(stringLine.str());
		}
		
		incrementTestIndex();
	}
	
	awkHighFrequencyFile->addStringLine("if (length(line) == 0) {printf(\"\\n\");next;} else {printf(\"%d %d %lf\\n\",rng,time,mean)}");
	//awkHighFrequencyFile->addStringLine("time++");
	awkHighFrequencyFile->addStringLine("}");
	
	ostringstream meanFileName;
	meanFileName << "Indexed_Sorted_Mean_" << dataFileName << ".dat";

	ostringstream meanCommand;
	meanCommand << "awk -f " << awkScriptFile.str() << ".dat " << lastTestFileName << " > " << meanFileName.str();
	
	system(((string)meanCommand.str()).c_str());
	
	if (awkHighFrequencyFile->isOpen())
	{
		awkHighFrequencyFile->closeFile();
	}
	else
	{
		cerr << "Warning, awkHighFrequencyFile is not open" << endl;
	}
	
	delete(awkHighFrequencyFile);
}

void ActivityTester::traceTemporalMeanIndexedFiles(string dataFileName)
{
	traceMeanIndexedFiles(dataFileName);
	
	DataFile* awkHighFrequencyFile = new DataFile();
	
	ostringstream awkScriptFile;
	awkScriptFile << "Temporal_Mean_" << dataFileName << "_AWKscript";
	
	if (awkHighFrequencyFile)
	{
		awkHighFrequencyFile->openDataFile(awkScriptFile.str());
	}
	else
	{
		cerr << "Warning, awkHighFrequencyFile is not inited" << endl;
		
		return;
	}
	
	awkHighFrequencyFile->addStringLine("BEGIN{}");
	awkHighFrequencyFile->addStringLine("{");
	awkHighFrequencyFile->addStringLine("tempMean[$1]+=$3;");
	awkHighFrequencyFile->addStringLine("}");
	awkHighFrequencyFile->addStringLine("END{f=0; while ( i in tempMean ) {printf(\"%d %lf\\n\",f,tempMean[f]);f++;} printf(\"\\n\\n\")}");
	//awkHighFrequencyFile->addStringLine("END{for ( i in tempMean ) {printf(\"%d %lf\\n\",i,tempMean[i]);} printf(\"\\n\\n\")}");
	//awkHighFrequencyFile->addStringLine("END{( i in tempMean ) {printf(\"%d %lf\\n\",i,tempMean[i]);} printf(\"\\n\\n\")}");

	ostringstream meanFileName;
	meanFileName << "Indexed_Sorted_Mean_" << dataFileName << ".dat";

	ostringstream tempMeanFileName;
	tempMeanFileName << "Temporal_Mean_" << dataFileName << ".dat";
	
	ostringstream meanCommand;
	meanCommand << "awk -f " << awkScriptFile.str() << ".dat " << meanFileName.str() << " > " << tempMeanFileName.str();
	
	system(((string)meanCommand.str()).c_str());
	
	if (awkHighFrequencyFile->isOpen())
	{
		awkHighFrequencyFile->closeFile();
	}
	else
	{
		cerr << "Warning, awkHighFrequencyFile is not open" << endl;
	}
	
	delete(awkHighFrequencyFile);
}

void ActivityTester::traceTemporalMeanNegativeIndexedFiles(string dataFileName)
{
	traceMeanIndexedFiles(dataFileName);
	
	DataFile* awkHighFrequencyFile = new DataFile();
	
	ostringstream awkScriptFile;
	awkScriptFile << "Temporal_Mean_" << dataFileName << "_AWKscript";
	
	if (awkHighFrequencyFile)
	{
		awkHighFrequencyFile->openDataFile(awkScriptFile.str());
	}
	else
	{
		cerr << "Warning, awkHighFrequencyFile is not inited" << endl;
		
		return;
	}
	
	awkHighFrequencyFile->addStringLine("BEGIN{}");
	awkHighFrequencyFile->addStringLine("{");
	awkHighFrequencyFile->addStringLine("if ($1>0) {tempMean[$1+100]+=$3} else {tempMean[100+$1]+=$3};");
	awkHighFrequencyFile->addStringLine("}");
	awkHighFrequencyFile->addStringLine("END{f=0; for ( i in tempMean ) {printf(\"%d %lf\\n\",f,tempMean[f]);f++;} printf(\"\\n\\n\")}");

	ostringstream meanFileName;
	meanFileName << "Indexed_Sorted_Mean_" << dataFileName << ".dat";

	ostringstream tempMeanFileName;
	tempMeanFileName << "Temporal_Mean_" << dataFileName << ".dat";
	
	ostringstream meanCommand;
	meanCommand << "awk -f " << awkScriptFile.str() << ".dat " << meanFileName.str() << " > " << tempMeanFileName.str();
	
	system(((string)meanCommand.str()).c_str());
	
	if (awkHighFrequencyFile->isOpen())
	{
		awkHighFrequencyFile->closeFile();
	}
	else
	{
		cerr << "Warning, awkHighFrequencyFile is not open" << endl;
	}
	
	delete(awkHighFrequencyFile);
}
/****************************************************************************************************************************************/
/******************************************************* Methodes de stats **************************************************************/
/****************************************************************************************************************************************/

void ActivityTester::trace()
{
		#ifdef _PARAMETRIC_TEST_MODE
			#ifdef _PHASE_TEST_MODE
				#ifdef _CONDITIONAL_TEST_MODE
	if (timeFrequencyTestFile->isOpen() && diffTimeFrequencyTestFile->isOpen())
	{
		if (timeFrequencyTest)
		{
			for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
			{
				for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
				{
					for (int i=0;i<NB_FREQUENCY_BINS;i++)
					{
						if (!timeFrequencyTest[i][j][k].isVoid())
						{
							timeFrequencyTestFile->addIndexedLineData(k*(1+2*NB_TESTED_ANIMALS+1)+j,i*5,(double) timeFrequencyTest[i][j][k].getMean());
						}
						else
						{
							//cout << "timeFrequencyTest  is void" << endl;
							timeFrequencyTestFile->addIndexedLineData(k*(1+2*NB_TESTED_ANIMALS+1)+j,i*5,-1.0);
						}
					}
				
					timeFrequencyTestFile->addDataSeparator();
				}
			}
			
			for (int i=0;i<NB_FREQUENCY_BINS;i++)
			{
				if (!timeFrequencyTest[i][0][0].isVoid() && !timeFrequencyTest[i][0][1].isVoid())
				{
					diffTimeFrequencyTestFile->addIndexedLineData(0,i*5,(double) timeFrequencyTest[i][0][0].getMean()-timeFrequencyTest[i][0][1].getMean());
				}
				else
				{
					//cout << "timeFrequencyTest  is void" << endl;
					diffTimeFrequencyTestFile->addIndexedLineData(0,i*5,-1.0);
				}
			}
			
			diffTimeFrequencyTestFile->addDataSeparator();
		
			for (int i=0;i<NB_FREQUENCY_BINS;i++)
			{
				if (!timeFrequencyTest[i][1][0].isVoid() && !timeFrequencyTest[i][1][1].isVoid())
				{
					diffTimeFrequencyTestFile->addIndexedLineData(1,i*5,(double) timeFrequencyTest[i][1][0].getMean()-timeFrequencyTest[i][1][1].getMean());
				}
				else
				{
					//cout << "diffTimeFrequencyTestFile  is void" << endl;
					diffTimeFrequencyTestFile->addIndexedLineData(1,i*5,-1.0);
				}
			}
				
			diffTimeFrequencyTestFile->addDataSeparator();
			
			for (int i=0;i<NB_FREQUENCY_BINS;i++)
			{
				if (!timeFrequencyTest[i][2][0].isVoid() && !timeFrequencyTest[i][2][1].isVoid())
				{
					diffTimeFrequencyTestFile->addIndexedLineData(2,i*5,(double) timeFrequencyTest[i][2][0].getMean()-timeFrequencyTest[i][2][1].getMean());
				}
				else
				{
					//cout << "diffTimeFrequencyTestFile  is void" << endl;
					diffTimeFrequencyTestFile->addIndexedLineData(2,i*5,-1.0);
				}
			}
				
			diffTimeFrequencyTestFile->addDataSeparator();
			
			for (int i=0;i<NB_FREQUENCY_BINS;i++)
			{
				if (!timeFrequencyTest[i][3][0].isVoid() && !timeFrequencyTest[i][3][1].isVoid())
				{
					diffTimeFrequencyTestFile->addIndexedLineData(3,i*5,(double) timeFrequencyTest[i][3][0].getMean()-timeFrequencyTest[i][3][1].getMean());
				}
				else
				{
					//cout << "diffTimeFrequencyTestFile  is void" << endl;
					diffTimeFrequencyTestFile->addIndexedLineData(3,i*5,-1.0);
				}
			}
				
			diffTimeFrequencyTestFile->addDataSeparator();
		
		}
	}
	else
	{
		cerr << "Warning, timeFrequencyTestFile && diffTimeFrequencyTestFile should be inited" << endl;
	}
				#else
					#ifdef _TRANSITION_STAT_MODE
	if (timeFrequencyTestFile->isOpen())
	{
		if (timeFrequencyTest)
		{
			for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
				{
					for (int i=0;i<NB_FREQUENCY_BINS;i++)
					{
						if (!timeFrequencyTest[i][j][k].isVoid())
						{
							if (j%2==0)
							{
								timeFrequencyTestFile->addIndexedLineData(j,i*5,(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*timeFrequencyTest[i][j][k].getAccu());
							}
							else
							{
								timeFrequencyTestFile->addIndexedLineData(j,i*5,(double) EDNetwork::TRANSITION_TIME_LENGTH*timeFrequencyTest[i][j][k].getAccu());
							}
						}
						else
						{
							//cout << "timeFrequencyTestFile  is void" << endl;
							timeFrequencyTestFile->addIndexedLineData(j,i*5,-1.0);
						}
					}
	
					timeFrequencyTestFile->addDataSeparator();
				}
			}
		}
	}
	else
	{
		cerr << "Warning, timeFrequencyTestFile should be inited" << endl;
	}
		
	if (diffTimeFrequencyTestFile->isOpen())
	{
		if (diffTimeFrequencyTestFile)
		{
			for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
			{
				for (int i=0;i<NB_FREQUENCY_BINS;i++)
				{
					if (!timeFrequencyTest[i][0][k].isVoid() && !timeFrequencyTest[i][1][k].isVoid())
					{
						diffTimeFrequencyTestFile->addIndexedLineData(0,i*5,(double) ((NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*timeFrequencyTest[i][0][k].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*timeFrequencyTest[i][1][k].getAccu()));
					}
					else
					{
						//cout << "diffTimeFrequencyTestFile  is void" << endl;
						diffTimeFrequencyTestFile->addIndexedLineData(0,i*5,-1.0);
					}
				}

				diffTimeFrequencyTestFile->addDataSeparator();
				
				for (int i=0;i<NB_FREQUENCY_BINS;i++)
				{
					if (!timeFrequencyTest[i][2][k].isVoid() && !timeFrequencyTest[i][3][k].isVoid())
					{
						diffTimeFrequencyTestFile->addIndexedLineData(1,i*5,(double) ((NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*timeFrequencyTest[i][2][k].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*timeFrequencyTest[i][3][k].getAccu()));
					}
					else
					{
						//cout << "diffTimeFrequencyTestFile  is void" << endl;
						diffTimeFrequencyTestFile->addIndexedLineData(0,i*5,-1.0);
					}
				}

				diffTimeFrequencyTestFile->addDataSeparator();
				
				for (int i=0;i<NB_FREQUENCY_BINS;i++)
				{
					if (!timeFrequencyTest[i][4][k].isVoid() && !timeFrequencyTest[i][5][k].isVoid())
					{
						diffTimeFrequencyTestFile->addIndexedLineData(2,i*5,(double) ((NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*timeFrequencyTest[i][4][k].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*timeFrequencyTest[i][5][k].getAccu()));
					}
					else
					{
						//cout << "diffTimeFrequencyTestFile  is void" << endl;
						diffTimeFrequencyTestFile->addIndexedLineData(2,i*5,-1.0);
					}
				}

				diffTimeFrequencyTestFile->addDataSeparator();
				
				for (int i=0;i<NB_FREQUENCY_BINS;i++)
				{
					if (!timeFrequencyTest[i][6][k].isVoid() && !timeFrequencyTest[i][7][k].isVoid())
					{
						diffTimeFrequencyTestFile->addIndexedLineData(3,i*5,(double) ((NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*timeFrequencyTest[i][6][k].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*timeFrequencyTest[i][7][k].getAccu()));
					}
					else
					{
						//cout << "diffTimeFrequencyTestFile  is void" << endl;
						diffTimeFrequencyTestFile->addIndexedLineData(3,i*5,-1.0);
					}
				}

				diffTimeFrequencyTestFile->addDataSeparator();
				
			}
		}
	}
	else
	{
		cerr << "Warning, diffTimeFrequencyTestFile should be inited" << endl;
	}
					#else
	if (timeFrequencyTestFile->isOpen())
	{
		if (timeFrequencyTest)
		{
			for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
			{
				for (int i=0;i<NB_FREQUENCY_BINS;i++)
				{
					if (!timeFrequencyTest[i][1][k].isVoid())
					{
						timeFrequencyTestFile->addIndexedLineData(k,i*5,(double) timeFrequencyTest[i][1][k].getMean());
					}
					else
					{
						//cout << "timeFrequencyTestFile  is void" << endl;
						timeFrequencyTestFile->addIndexedLineData(k,i*5,-1.0);
					}
				}

				timeFrequencyTestFile->addDataSeparator();
			}
		}
	}
	else
	{
		cerr << "Warning, timeFrequencyTestFile should be inited" << endl;
	}
		
	if (diffTimeFrequencyTestFile->isOpen())
	{
		if (diffTimeFrequencyTestFile)
		{
			for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
			{
				for (int i=0;i<NB_FREQUENCY_BINS;i++)
				{
					if (!timeFrequencyTest[i][0][k].isVoid())
					{
						diffTimeFrequencyTestFile->addIndexedLineData(k,i*5,(double) (timeFrequencyTest[i][1][k].getMean()-timeFrequencyTest[i][0][k].getMean()));
					}
					else
					{
						//cout << "diffTimeFrequencyTestFile  is void" << endl;
						diffTimeFrequencyTestFile->addIndexedLineData(k,i*5,-1.0);
					}
				}

				diffTimeFrequencyTestFile->addDataSeparator();
			}
		}
	}
	else
	{
		cerr << "Warning, diffTimeFrequencyTestFile should be inited" << endl;
	}
					#endif
				#endif
			#else
	if (timeFrequencyTestFile->isOpen())
	{
		if (timeFrequencyTest)
		{
			for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
			{
				for (int i=0;i<NB_FREQUENCY_BINS;i++)
				{
					if (!timeFrequencyTest[i][k].isVoid())
					{
						timeFrequencyTestFile->addIndexedLineData(k,i*5,(double) timeFrequencyTest[i][k].getMean());
					}
					else
					{
						//cout << "timeFrequencyTestFile  is void" << endl;
						timeFrequencyTestFile->addIndexedLineData(k,i*5,-1.0);
					}
				}

				timeFrequencyTestFile->addDataSeparator();
			}
		}
	}
	else
	{
		cerr << "Warning, timeFrequencyTestFile should be inited" << endl;
	}
			#endif

		#else	
			#ifdef _PHASE_TEST_MODE
	if (timeFrequencyTestFile->isOpen() && diffTimeFrequencyTestFile->isOpen())
	{
		if (timeFrequencyTest)
		{
				#ifdef _TRANSITION_STAT_MODE
			for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<NB_FREQUENCY_BINS;i++)
				{
					if (!timeFrequencyTest[i][j].isVoid())
					{
						if (j%2==0)
						{
							timeFrequencyTestFile->addIndexedLineData(j,i*5,(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*timeFrequencyTest[i][j].getAccu());
						}
						else
						{
							timeFrequencyTestFile->addIndexedLineData(j,i*5,(double) EDNetwork::TRANSITION_TIME_LENGTH*timeFrequencyTest[i][j].getAccu());
						}
						//timeFrequencyTestFile->addIndexedLineData(j,i*5,(double) timeFrequencyTest[i][j].getAccu());
					}
					else
					{
						//cout << "timeFrequencyTestFile  is void" << endl;
						timeFrequencyTestFile->addIndexedLineData(j,i*5,-1.0);
					}
				}
				
				timeFrequencyTestFile->addDataSeparator();
			}
			
			for (int i=0;i<NB_FREQUENCY_BINS;i++)
			{
				if (!timeFrequencyTest[i][0].isVoid() && !timeFrequencyTest[i][1].isVoid())
				{
					diffTimeFrequencyTestFile->addIndexedLineData(0,i*5,(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*timeFrequencyTest[i][0].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*timeFrequencyTest[i][1].getAccu());
				}
				else
				{
					//cout << "diffTimeFrequencyTestFile  is void" << endl;
					diffTimeFrequencyTestFile->addIndexedLineData(0,i*5,-1.0);
				}
			}
				
			diffTimeFrequencyTestFile->addDataSeparator();
			
			for (int i=0;i<NB_FREQUENCY_BINS;i++)
			{
				if (!timeFrequencyTest[i][2].isVoid() && !timeFrequencyTest[i][3].isVoid())
				{
					diffTimeFrequencyTestFile->addIndexedLineData(1,i*5,(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*timeFrequencyTest[i][2].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*timeFrequencyTest[i][3].getAccu());
				}
				else
				{
					//cout << "diffTimeFrequencyTestFile  is void" << endl;
					diffTimeFrequencyTestFile->addIndexedLineData(1,i*5,-1.0);
				}
			}
				
			diffTimeFrequencyTestFile->addDataSeparator();
			
			for (int i=0;i<NB_FREQUENCY_BINS;i++)
			{
				if (!timeFrequencyTest[i][4].isVoid() && !timeFrequencyTest[i][5].isVoid())
				{
					diffTimeFrequencyTestFile->addIndexedLineData(2,i*5,(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*timeFrequencyTest[i][4].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*timeFrequencyTest[i][5].getAccu());
				}
				else
				{
					//cout << "diffTimeFrequencyTestFile  is void" << endl;
					diffTimeFrequencyTestFile->addIndexedLineData(2,i*5,-1.0);
				}
			}
				
			diffTimeFrequencyTestFile->addDataSeparator();
			
			for (int i=0;i<NB_FREQUENCY_BINS;i++)
			{
				if (!timeFrequencyTest[i][6].isVoid() && !timeFrequencyTest[i][7].isVoid())
				{
					diffTimeFrequencyTestFile->addIndexedLineData(3,i*5,(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*timeFrequencyTest[i][6].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*timeFrequencyTest[i][7].getAccu());
				}
				else
				{
					//cout << "diffTimeFrequencyTestFile  is void" << endl;
					diffTimeFrequencyTestFile->addIndexedLineData(3,i*5,-1.0);
				}
			}
				
			diffTimeFrequencyTestFile->addDataSeparator();
			
				#else
					#ifdef _REPETITIVE_TEST_MODE
			for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<NB_FREQUENCY_BINS;i++)
				{
					if (!timeFrequencyTest[i][j].isVoid())
					{
						timeFrequencyTestFile->addIndexedLineData(j,i*5,(double) timeFrequencyTest[i][j].getMean());
					}
					else
					{
						//cout << "timeFrequencyTestFile  is void" << endl;
						timeFrequencyTestFile->addIndexedLineData(j,i*5,-1.0);
					}
				}
				
				timeFrequencyTestFile->addDataSeparator();
			}
			
			for (int i=0;i<NB_FREQUENCY_BINS;i++)
			{
				if (!timeFrequencyTest[i][2].isVoid() && !timeFrequencyTest[i][0].isVoid())
				{
					diffTimeFrequencyTestFile->addIndexedLineData(0,i*5,(double) timeFrequencyTest[i][2].getMean()-timeFrequencyTest[i][0].getMean());
				}
				else
				{
					//cout << "diffTimeFrequencyTestFile  is void" << endl;
					diffTimeFrequencyTestFile->addIndexedLineData(0,i*5,-1.0);
				}
			}
				
			diffTimeFrequencyTestFile->addDataSeparator();
			
			for (int i=0;i<NB_FREQUENCY_BINS;i++)
			{
				if (!timeFrequencyTest[i][3].isVoid() && !timeFrequencyTest[i][1].isVoid())
				{
					diffTimeFrequencyTestFile->addIndexedLineData(1,i*5,(double) timeFrequencyTest[i][3].getMean()-timeFrequencyTest[i][1].getMean());
				}
				else
				{
					//cout << "diffTimeFrequencyTestFile  is void" << endl;
					diffTimeFrequencyTestFile->addIndexedLineData(1,i*5,-1.0);
				}
			}
				
			diffTimeFrequencyTestFile->addDataSeparator();

					#else
			for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<NB_FREQUENCY_BINS;i++)
				{
					if (!timeFrequencyTest[i][j].isVoid())
					{
						timeFrequencyTestFile->addIndexedLineData(j,i*5,(double) timeFrequencyTest[i][j].getMean());
					}
					else
					{
						//cout << "timeFrequencyTestFile  is void" << endl;
						timeFrequencyTestFile->addIndexedLineData(j,i*5,-1.0);
					}
				}
				
				timeFrequencyTestFile->addDataSeparator();
			}
			
			for (int i=0;i<NB_FREQUENCY_BINS;i++)
			{
				if (!timeFrequencyTest[i][0].isVoid() && !timeFrequencyTest[i][1].isVoid())
				{
					diffTimeFrequencyTestFile->addIndexedLineData(0,i*5,(double) timeFrequencyTest[i][1].getMean()-timeFrequencyTest[i][0].getMean());
				}
				else
				{
					//cout << "diffTimeFrequencyTestFile  is void" << endl;
					diffTimeFrequencyTestFile->addIndexedLineData(0,i*5,-1.0);
				}
			}
				
			diffTimeFrequencyTestFile->addDataSeparator();
			
			for (int i=0;i<NB_FREQUENCY_BINS;i++)
			{
				if (!timeFrequencyTest[i][0].isVoid() && !timeFrequencyTest[i][2].isVoid())
				{
					diffTimeFrequencyTestFile->addIndexedLineData(1,i*5,(double) timeFrequencyTest[i][2].getMean()-timeFrequencyTest[i][0].getMean());
				}
				else
				{
					//cout << "diffTimeFrequencyTestFile  is void" << endl;
					diffTimeFrequencyTestFile->addIndexedLineData(1,i*5,-1.0);
				}
			}
				
			diffTimeFrequencyTestFile->addDataSeparator();
			
			for (int i=0;i<NB_FREQUENCY_BINS;i++)
			{
				if (!timeFrequencyTest[i][0].isVoid() && !timeFrequencyTest[i][3].isVoid())
				{
					diffTimeFrequencyTestFile->addIndexedLineData(2,i*5,(double) timeFrequencyTest[i][3].getMean()-timeFrequencyTest[i][0].getMean());
				}
				else
				{
					//cout << "diffTimeFrequencyTestFile  is void" << endl;
					diffTimeFrequencyTestFile->addIndexedLineData(2,i*5,-1.0);
				}
			}
				
			diffTimeFrequencyTestFile->addDataSeparator();
					#endif
				#endif
		}
	}
	else
	{
		cerr << "Warning, timeFrequencyTestFile && diffTimeFrequencyTestFile should be inited" << endl;
	}
			#endif
		#endif
	
		#ifdef _PARAMETRIC_TEST_MODE
			#ifdef _PHASE_TEST_MODE
				#ifdef _CONDITIONAL_TEST_MODE
	if (highTimeFrequencyTestFile->isOpen() && diffHighTimeFrequencyTestFile->isOpen())
	{
		if (highTimeFrequencyTest)
		{
			for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
			{
				for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
				{
					for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
					{
						if (!highTimeFrequencyTest[i][j][k].isVoid())
						{
							highTimeFrequencyTestFile->addIndexedLineData(k*(1+2*NB_TESTED_ANIMALS+1)+j,i*5,(double) highTimeFrequencyTest[i][j][k].getMean());
						}
						else
						{
							//cout << "highTimeFrequencyTestFile  is void" << endl;
							highTimeFrequencyTestFile->addIndexedLineData(k*(1+2*NB_TESTED_ANIMALS+1)+j,i*5,-1.0);
						}
					}
				
					highTimeFrequencyTestFile->addDataSeparator();
				}
			}
			
			for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
			{
				if (!highTimeFrequencyTest[i][0][0].isVoid() && !highTimeFrequencyTest[i][0][1].isVoid())
				{
					diffHighTimeFrequencyTestFile->addIndexedLineData(0,i*5,(double) highTimeFrequencyTest[i][0][0].getMean()-highTimeFrequencyTest[i][0][1].getMean());
				}
				else
				{
					//cout << "diffHighTimeFrequencyTestFile  is void" << endl;
					diffHighTimeFrequencyTestFile->addIndexedLineData(0,i*5,-1.0);
				}
			}
			
			diffHighTimeFrequencyTestFile->addDataSeparator();
			
			
			for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
			{
				if (!highTimeFrequencyTest[i][1][0].isVoid() && !highTimeFrequencyTest[i][1][1].isVoid())
				{
					diffHighTimeFrequencyTestFile->addIndexedLineData(1,i*5,(double) highTimeFrequencyTest[i][1][0].getMean()-highTimeFrequencyTest[i][1][1].getMean());
				}
				else
				{
					//cout << "diffHighTimeFrequencyTestFile  is void" << endl;
					diffHighTimeFrequencyTestFile->addIndexedLineData(1,i*5,-1.0);
				}
			}
			
			diffHighTimeFrequencyTestFile->addDataSeparator();
			
			
			for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
			{
				if (!highTimeFrequencyTest[i][2][0].isVoid() && !highTimeFrequencyTest[i][2][1].isVoid())
				{
					diffHighTimeFrequencyTestFile->addIndexedLineData(2,i*5,(double) highTimeFrequencyTest[i][2][0].getMean()-highTimeFrequencyTest[i][2][1].getMean());
				}
				else
				{
					//cout << "diffHighTimeFrequencyTestFile  is void" << endl;
					diffHighTimeFrequencyTestFile->addIndexedLineData(2,i*5,-1.0);
				}
			}
			
			diffHighTimeFrequencyTestFile->addDataSeparator();
			
			for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
			{
				if (!highTimeFrequencyTest[i][3][0].isVoid() && !highTimeFrequencyTest[i][3][1].isVoid())
				{
					diffHighTimeFrequencyTestFile->addIndexedLineData(3,i*5,(double) highTimeFrequencyTest[i][3][0].getMean()-highTimeFrequencyTest[i][3][1].getMean());
				}
				else
				{
					//cout << "diffHighTimeFrequencyTestFile  is void" << endl;
					diffHighTimeFrequencyTestFile->addIndexedLineData(3,i*5,-1.0);
				}
			}
			
			diffHighTimeFrequencyTestFile->addDataSeparator();

		}
	}
	else
	{
		cerr << "Warning, highTimeFrequencyTestFile && diffHighTimeFrequencyTestFile should be inited" << endl;
	}
			#else
				#ifdef _TRANSITION_STAT_MODE
	if (highTimeFrequencyTestFile->isOpen())
	{
		if (highTimeFrequencyTest)
		{
			for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
				{
					for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
					{
						if (!highTimeFrequencyTest[i][j][k].isVoid())
						{
							if (j%2==0)
							{
								highTimeFrequencyTestFile->addIndexedLineData(j,i*5,(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*highTimeFrequencyTest[i][j][k].getAccu());
							}
							else
							{
								highTimeFrequencyTestFile->addIndexedLineData(j,i*5,(double) EDNetwork::TRANSITION_TIME_LENGTH*highTimeFrequencyTest[i][j][k].getAccu());
							}
						}
						else
						{
							//cout << "highTimeFrequencyTestFile  is void" << endl;
							highTimeFrequencyTestFile->addIndexedLineData(j,i*5,-1.0);
						}
					}
	
					highTimeFrequencyTestFile->addDataSeparator();
				}
			}
		}
	}
	else
	{
		cerr << "Warning, highTimeFrequencyTestFile should be inited" << endl;
	}
		
	if (diffHighTimeFrequencyTestFile->isOpen())
	{
		if (diffTimeFrequencyTestFile)
		{
			for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
			{
				for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
				{
					if (!highTimeFrequencyTest[i][0][k].isVoid() && !highTimeFrequencyTest[i][1][k].isVoid())
					{
						diffHighTimeFrequencyTestFile->addIndexedLineData(0,i*5,(double) ((NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*highTimeFrequencyTest[i][0][k].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*highTimeFrequencyTest[i][1][k].getAccu()));
					}
					else
					{
						//cout << "diffTimeFrequencyTestFile  is void" << endl;
						diffHighTimeFrequencyTestFile->addIndexedLineData(0,i*5,-1.0);
					}
				}

				diffHighTimeFrequencyTestFile->addDataSeparator();
				
				for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
				{
					if (!highTimeFrequencyTest[i][2][k].isVoid() && !highTimeFrequencyTest[i][3][k].isVoid())
					{
						diffHighTimeFrequencyTestFile->addIndexedLineData(1,i*5,(double) ((NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*highTimeFrequencyTest[i][2][k].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*highTimeFrequencyTest[i][3][k].getAccu()));
					}
					else
					{
						//cout << "diffTimeFrequencyTestFile  is void" << endl;
						diffHighTimeFrequencyTestFile->addIndexedLineData(0,i*5,-1.0);
					}
				}

				diffHighTimeFrequencyTestFile->addDataSeparator();
				
				for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
				{
					if (!highTimeFrequencyTest[i][4][k].isVoid() && !highTimeFrequencyTest[i][5][k].isVoid())
					{
						diffHighTimeFrequencyTestFile->addIndexedLineData(2,i*5,(double) ((NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*highTimeFrequencyTest[i][4][k].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*highTimeFrequencyTest[i][5][k].getAccu()));
					}
					else
					{
						//cout << "diffTimeFrequencyTestFile  is void" << endl;
						diffHighTimeFrequencyTestFile->addIndexedLineData(2,i*5,-1.0);
					}
				}

				diffHighTimeFrequencyTestFile->addDataSeparator();
				
				for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
				{
					if (!highTimeFrequencyTest[i][6][k].isVoid() && !highTimeFrequencyTest[i][7][k].isVoid())
					{
						diffHighTimeFrequencyTestFile->addIndexedLineData(3,i*5,(double) ((NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*highTimeFrequencyTest[i][6][k].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*highTimeFrequencyTest[i][7][k].getAccu()));
					}
					else
					{
						//cout << "diffTimeFrequencyTestFile  is void" << endl;
						diffHighTimeFrequencyTestFile->addIndexedLineData(3,i*5,-1.0);
					}
				}

				diffHighTimeFrequencyTestFile->addDataSeparator();
				
			}
		}
	}
	else
	{
		cerr << "Warning, diffTimeFrequencyTestFile should be inited" << endl;
	}
					#else
	if (highTimeFrequencyTestFile->isOpen())
	{
		if (highTimeFrequencyTest)
		{
			for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
			{
				for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
				{
					if (!highTimeFrequencyTest[i][1][k].isVoid())
					{
						highTimeFrequencyTestFile->addIndexedLineData(k,i*HIGH_FREQUENCY_BIN_LENGTH,(double) highTimeFrequencyTest[i][1][k].getMean());
					}
					else
					{
						//cout << "highTimeFrequencyTestFile  is void" << endl;
						highTimeFrequencyTestFile->addIndexedLineData(k,i*HIGH_FREQUENCY_BIN_LENGTH,-1.0);
					}
				}

				highTimeFrequencyTestFile->addDataSeparator();
			}
		}
	}
	else
	{
		cerr << "Warning, highTimeFrequencyTestFile should be inited" << endl;
	}

	
	if (diffHighTimeFrequencyTestFile->isOpen())
	{	
		if (diffHighTimeFrequencyTestFile)
		{
			for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
			{
				for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
				{
					if (!highTimeFrequencyTest[i][0][k].isVoid())
					{
						diffHighTimeFrequencyTestFile->addIndexedLineData(k,i*HIGH_FREQUENCY_BIN_LENGTH,(double) (highTimeFrequencyTest[i][1][k].getMean()-highTimeFrequencyTest[i][0][k].getMean()));
					}
					else
					{
						//cout << "diffHighTimeFrequencyTestFile  is void" << endl;
						diffHighTimeFrequencyTestFile->addIndexedLineData(k,i*HIGH_FREQUENCY_BIN_LENGTH,-1.0);
					}
				}

				diffHighTimeFrequencyTestFile->addDataSeparator();
			}
		}
	}
	else
	{
		cerr << "Warning, diffHighTimeFrequencyTestFile should be inited" << endl;
	}
					#endif
				#endif
			#else
	if (highTimeFrequencyTestFile->isOpen())
	{
		if (highTimeFrequencyTest)
		{
			for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
			{
				for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
				{
					if (!highTimeFrequencyTest[i][k].isVoid())
					{
						highTimeFrequencyTestFile->addIndexedLineData(k,i*HIGH_FREQUENCY_BIN_LENGTH,(double) highTimeFrequencyTest[i][k].getMean());
					}
					else
					{
						//cout << "highTimeFrequencyTestFile  is void" << endl;
						highTimeFrequencyTestFile->addIndexedLineData(k,i*HIGH_FREQUENCY_BIN_LENGTH,-1.0);
					}
					
				}

				highTimeFrequencyTestFile->addDataSeparator();
			}
		}
	}
	else
	{
		cerr << "Warning, highTimeFrequencyTestFile should be inited" << endl;
	}
			#endif
		#else	
			#ifdef _PHASE_TEST_MODE	
	if (highTimeFrequencyTestFile->isOpen() && diffHighTimeFrequencyTestFile->isOpen())
	{
		if (highTimeFrequencyTest)
		{	
				#ifdef _TRANSITION_STAT_MODE
			for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
				{
					if (!highTimeFrequencyTest[i][j].isVoid())
					{
						if (j%2==0)
						{
							highTimeFrequencyTestFile->addIndexedLineData(j,i*HIGH_FREQUENCY_BIN_LENGTH,(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*highTimeFrequencyTest[i][j].getAccu());
						}
						else
						{
							highTimeFrequencyTestFile->addIndexedLineData(j,i*HIGH_FREQUENCY_BIN_LENGTH,(double) EDNetwork::TRANSITION_TIME_LENGTH*highTimeFrequencyTest[i][j].getAccu());
						}
						//highTimeFrequencyTestFile->addIndexedLineData(j,i*HIGH_FREQUENCY_BIN_LENGTH,(double) highTimeFrequencyTest[i][j].getAccu());
					}
					else
					{
						//cout << "highTimeFrequencyTestFile  is void" << endl;
						highTimeFrequencyTestFile->addIndexedLineData(j,i*HIGH_FREQUENCY_BIN_LENGTH,-1.0);
					}
				}
				
				highTimeFrequencyTestFile->addDataSeparator();
			}
			
			
			for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
			{
				if (!highTimeFrequencyTest[i][0].isVoid() && !highTimeFrequencyTest[i][1].isVoid())
				{
					diffHighTimeFrequencyTestFile->addIndexedLineData(0,i*HIGH_FREQUENCY_BIN_LENGTH,(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*highTimeFrequencyTest[i][0].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*highTimeFrequencyTest[i][1].getAccu());
				}
				else
				{
					//cout << "diffHighTimeFrequencyTestFile  is void" << endl;
					diffHighTimeFrequencyTestFile->addIndexedLineData(0,i*HIGH_FREQUENCY_BIN_LENGTH,-1.0);
				}
			}
				
			diffHighTimeFrequencyTestFile->addDataSeparator();
			
			for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
			{
				if (!highTimeFrequencyTest[i][2].isVoid() && !highTimeFrequencyTest[i][3].isVoid())
				{
					diffHighTimeFrequencyTestFile->addIndexedLineData(1,i*HIGH_FREQUENCY_BIN_LENGTH,(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*highTimeFrequencyTest[i][2].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*highTimeFrequencyTest[i][3].getAccu());
				}
				else
				{
					//cout << "diffHighTimeFrequencyTestFile  is void" << endl;
					diffHighTimeFrequencyTestFile->addIndexedLineData(1,i*HIGH_FREQUENCY_BIN_LENGTH,-1.0);
				}
			}
				
			diffHighTimeFrequencyTestFile->addDataSeparator();
			
			for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
			{
				if (!highTimeFrequencyTest[i][4].isVoid() && !highTimeFrequencyTest[i][5].isVoid())
				{
					diffHighTimeFrequencyTestFile->addIndexedLineData(2,i*HIGH_FREQUENCY_BIN_LENGTH,(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*highTimeFrequencyTest[i][4].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*highTimeFrequencyTest[i][5].getAccu());
				}
				else
				{
					//cout << "diffHighTimeFrequencyTestFile  is void" << endl;
					diffHighTimeFrequencyTestFile->addIndexedLineData(2,i*HIGH_FREQUENCY_BIN_LENGTH,-1.0);
				}
			}
				
			diffHighTimeFrequencyTestFile->addDataSeparator();
			
			for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
			{
				if (!highTimeFrequencyTest[i][6].isVoid() && !highTimeFrequencyTest[i][7].isVoid())
				{
					diffHighTimeFrequencyTestFile->addIndexedLineData(3,i*HIGH_FREQUENCY_BIN_LENGTH,(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*highTimeFrequencyTest[i][6].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*highTimeFrequencyTest[i][7].getAccu());
				}
				else
				{
					//cout << "diffHighTimeFrequencyTestFile  is void" << endl;
					diffHighTimeFrequencyTestFile->addIndexedLineData(3,i*HIGH_FREQUENCY_BIN_LENGTH,-1.0);
				}
			}
				
			diffHighTimeFrequencyTestFile->addDataSeparator();
			
				#else
					#ifdef _REPETITIVE_TEST_MODE
			for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
				{
					if (!highTimeFrequencyTest[i][j].isVoid())
					{
						highTimeFrequencyTestFile->addIndexedLineData(j,i*HIGH_FREQUENCY_BIN_LENGTH,(double) highTimeFrequencyTest[i][j].getMean());
					}
					else
					{
						//cout << "highTimeFrequencyTestFile  is void" << endl;
						highTimeFrequencyTestFile->addIndexedLineData(j,i*HIGH_FREQUENCY_BIN_LENGTH,-1.0);
					}
				}
				
				highTimeFrequencyTestFile->addDataSeparator();
			}
			
			
			for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
			{
				if (!highTimeFrequencyTest[i][2].isVoid() && !highTimeFrequencyTest[i][0].isVoid())
				{
					diffHighTimeFrequencyTestFile->addIndexedLineData(0,i*HIGH_FREQUENCY_BIN_LENGTH,(double) highTimeFrequencyTest[i][2].getMean()-highTimeFrequencyTest[i][0].getMean());
				}
				else
				{
					//cout << "diffHighTimeFrequencyTestFile  is void" << endl;
					diffHighTimeFrequencyTestFile->addIndexedLineData(0,i*HIGH_FREQUENCY_BIN_LENGTH,-1.0);
				}
			}
				
			diffHighTimeFrequencyTestFile->addDataSeparator();
			
			for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
			{
				if (!highTimeFrequencyTest[i][3].isVoid() && !highTimeFrequencyTest[i][1].isVoid())
				{
					diffHighTimeFrequencyTestFile->addIndexedLineData(1,i*HIGH_FREQUENCY_BIN_LENGTH,(double) highTimeFrequencyTest[i][3].getMean()-highTimeFrequencyTest[i][1].getMean());
				}
				else
				{
					//cout << "diffHighTimeFrequencyTestFile  is void" << endl;
					diffHighTimeFrequencyTestFile->addIndexedLineData(1,i*HIGH_FREQUENCY_BIN_LENGTH,-1.0);
				}
			}
				
			diffHighTimeFrequencyTestFile->addDataSeparator();

					#else
			for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
				{
					if (!highTimeFrequencyTest[i][j].isVoid())
					{
						highTimeFrequencyTestFile->addIndexedLineData(j,i*HIGH_FREQUENCY_BIN_LENGTH,(double) highTimeFrequencyTest[i][j].getMean());
					}
					else
					{
						//cout << "highTimeFrequencyTestFile  is void" << endl;
						highTimeFrequencyTestFile->addIndexedLineData(j,i*HIGH_FREQUENCY_BIN_LENGTH,-1.0);
					}
				}
				
				highTimeFrequencyTestFile->addDataSeparator();
			}
			
			
			for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
			{
				if (!highTimeFrequencyTest[i][0].isVoid() && !highTimeFrequencyTest[i][1].isVoid())
				{
					diffHighTimeFrequencyTestFile->addIndexedLineData(0,i*HIGH_FREQUENCY_BIN_LENGTH,(double) highTimeFrequencyTest[i][1].getMean()-highTimeFrequencyTest[i][0].getMean());
				}
				else
				{
					//cout << "diffHighTimeFrequencyTestFile  is void" << endl;
					diffHighTimeFrequencyTestFile->addIndexedLineData(0,i*HIGH_FREQUENCY_BIN_LENGTH,-1.0);
				}
			}
				
			diffHighTimeFrequencyTestFile->addDataSeparator();
			
			for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
			{
				if (!highTimeFrequencyTest[i][0].isVoid() && !highTimeFrequencyTest[i][2].isVoid())
				{
					diffHighTimeFrequencyTestFile->addIndexedLineData(1,i*HIGH_FREQUENCY_BIN_LENGTH,(double) highTimeFrequencyTest[i][2].getMean()-highTimeFrequencyTest[i][0].getMean());
				}
				else
				{
					//cout << "diffHighTimeFrequencyTestFile  is void" << endl;
					diffHighTimeFrequencyTestFile->addIndexedLineData(1,i*HIGH_FREQUENCY_BIN_LENGTH,-1.0);
				}
			}
				
			diffHighTimeFrequencyTestFile->addDataSeparator();
			
			for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
			{
				if (!highTimeFrequencyTest[i][0].isVoid() && !highTimeFrequencyTest[i][3].isVoid())
				{
					diffHighTimeFrequencyTestFile->addIndexedLineData(2,i*HIGH_FREQUENCY_BIN_LENGTH,(double) highTimeFrequencyTest[i][3].getMean()-highTimeFrequencyTest[i][0].getMean());
				}
				else
				{
					//cout << "diffHighTimeFrequencyTestFile  is void" << endl;
					diffHighTimeFrequencyTestFile->addIndexedLineData(2,i*HIGH_FREQUENCY_BIN_LENGTH,-1.0);
				}
			}
				
			diffHighTimeFrequencyTestFile->addDataSeparator();
					#endif
				#endif
		}
	}
	else
	{
		cerr << "Warning, highTimeFrequencyTestFile should be inited" << endl;
	}
			#endif
		#endif
	
		#ifdef _GLOBAL_SYNAPSE_STAT_MODE
			#ifdef _PARAMETRIC_TEST_MODE
				#ifdef _PHASE_TEST_MODE
					#ifdef _CONDITIONAL_TEST_MODE
	if (excitTempDevRepartitionTestFile->isOpen() && diffExcitTempDevRepartitionTestFile->isOpen())
	{
		for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
		{
			for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				if (excitPreTempDevRepartitionTest)
				{
					for (int i=0;i<100;i++)
					{
						if (!excitPreTempDevRepartitionTest[99-i][j][k].isVoid())
						{
							excitTempDevRepartitionTestFile->addIndexedLineData(k*(1+2*NB_TESTED_ANIMALS+1)+j,-(99-i),(double) excitPreTempDevRepartitionTest[99-i][j][k].getMean());
						}
						else
						{
							//cout << "excitTempDevRepartitionTestFile is void" << endl;
							excitTempDevRepartitionTestFile->addIndexedLineData(k*(1+2*NB_TESTED_ANIMALS+1)+j,-(99-i),-1.0);
						}
					}
				}
					
				if (excitPostTempDevRepartitionTest)
				{
					for (int i=0;i<100;i++)
					{
						if (!excitPostTempDevRepartitionTest[99-i][j][k].isVoid())
						{
							excitTempDevRepartitionTestFile->addIndexedLineData(k*(1+2*NB_TESTED_ANIMALS+1)+j,i,(double) excitPostTempDevRepartitionTest[i][j][k].getMean());
						}
						else
						{
							//cout << "excitTempDevRepartitionTestFile is void" << endl;
							excitTempDevRepartitionTestFile->addIndexedLineData(k*(1+2*NB_TESTED_ANIMALS+1)+j,i,-1.0);
						}
					}
				}
				
				excitTempDevRepartitionTestFile->addDataSeparator();
			}
		}	
		
		for (int i=0;i<100;i++)
		{
			if (!excitPreTempDevRepartitionTest[99-i][0][0].isVoid() && !excitPreTempDevRepartitionTest[99-i][0][1].isVoid())
			{
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(0,-(99-i),(double) excitPreTempDevRepartitionTest[99-i][0][0].getMean()-excitPreTempDevRepartitionTest[99-i][0][1].getMean());
			}
			else
			{
				//cout << "diffExcitTempDevRepartitionTestFile is void" << endl;
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(0,-(99-i),-1.0);
			}
						
		}
		
		for (int i=0;i<100;i++)
		{
			if (!excitPostTempDevRepartitionTest[i][0][0].isVoid() && !excitPostTempDevRepartitionTest[i][0][1].isVoid())
			{
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(0,i,(double) excitPostTempDevRepartitionTest[i][0][0].getMean()-excitPostTempDevRepartitionTest[i][0][1].getMean());
			}
			else
			{
				//cout << "diffExcitTempDevRepartitionTestFile is void" << endl;
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(0,i,-1.0);
			}
		}
			
		diffExcitTempDevRepartitionTestFile->addDataSeparator();
		
		for (int i=0;i<100;i++)
		{
			if (!excitPreTempDevRepartitionTest[99-i][1][0].isVoid() && !excitPreTempDevRepartitionTest[99-i][1][1].isVoid())
			{
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(1,-(99-i),(double) excitPreTempDevRepartitionTest[99-i][1][0].getMean()-excitPreTempDevRepartitionTest[99-i][1][1].getMean());
			}
			else
			{
				//cout << "diffExcitTempDevRepartitionTestFile is void" << endl;
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(1,-(99-i),-1.0);
			}
						
		}
		
		for (int i=0;i<100;i++)
		{
			if (!excitPostTempDevRepartitionTest[i][1][0].isVoid() && !excitPostTempDevRepartitionTest[i][1][1].isVoid())
			{
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(1,i,(double) excitPostTempDevRepartitionTest[i][1][0].getMean()-excitPostTempDevRepartitionTest[i][1][1].getMean());
			}
			else
			{
				//cout << "diffExcitTempDevRepartitionTestFile is void" << endl;
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(1,i,-1.0);
			}
		}
	
			
		diffExcitTempDevRepartitionTestFile->addDataSeparator();
		
		for (int i=0;i<100;i++)
		{
			if (!excitPreTempDevRepartitionTest[99-i][2][0].isVoid() && !excitPreTempDevRepartitionTest[99-i][2][1].isVoid())
			{
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(2,-(99-i),(double) excitPreTempDevRepartitionTest[99-i][2][0].getMean()-excitPreTempDevRepartitionTest[99-i][2][1].getMean());
			}
			else
			{
				//cout << "diffExcitTempDevRepartitionTestFile is void" << endl;
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(2,-(99-i),-1.0);
			}
						
		}
		
		for (int i=0;i<100;i++)
		{
			if (!excitPostTempDevRepartitionTest[i][2][0].isVoid() && !excitPostTempDevRepartitionTest[i][2][1].isVoid())
			{
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(2,i,(double) excitPostTempDevRepartitionTest[i][2][0].getMean()-excitPostTempDevRepartitionTest[i][2][1].getMean());
			}
			else
			{
				//cout << "diffExcitTempDevRepartitionTestFile is void" << endl;
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(2,i,-1.0);
			}
		}
		
		diffExcitTempDevRepartitionTestFile->addDataSeparator();
		
		for (int i=0;i<100;i++)
		{
			if (!excitPreTempDevRepartitionTest[99-i][3][0].isVoid() && !excitPreTempDevRepartitionTest[99-i][3][1].isVoid())
			{
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(3,-(99-i),(double) excitPreTempDevRepartitionTest[99-i][3][0].getMean()-excitPreTempDevRepartitionTest[99-i][3][1].getMean());
			}
			else
			{
				//cout << "diffExcitTempDevRepartitionTestFile is void" << endl;
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(3,-(99-i),-1.0);
			}
						
		}
		
		for (int i=0;i<100;i++)
		{
			if (!excitPostTempDevRepartitionTest[i][3][0].isVoid() && !excitPostTempDevRepartitionTest[i][3][1].isVoid())
			{
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(3,i,(double) excitPostTempDevRepartitionTest[i][3][0].getMean()-excitPostTempDevRepartitionTest[i][3][1].getMean());
			}
			else
			{
				//cout << "diffExcitTempDevRepartitionTestFile is void" << endl;
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(3,i,-1.0);
			}
		}
			
		diffExcitTempDevRepartitionTestFile->addDataSeparator();

	}
	else
	{
		cerr << "Warning, excitTempDevRepartitionTestFile && diffExcitTempDevRepartitionTestFile should be inited" << endl;
	}
	
	if (inhibTempDevRepartitionTestFile->isOpen() && diffInhibTempDevRepartitionTestFile->isOpen())
	{
		for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
		{
			for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				if (inhibPreTempDevRepartitionTest)
				{
					for (int i=0;i<100;i++)
					{
						if (!inhibPreTempDevRepartitionTest[99-i][j][k].isVoid())
						{
							inhibTempDevRepartitionTestFile->addIndexedLineData(k*(1+2*NB_TESTED_ANIMALS+1)+j,-(99-i),(double) inhibPreTempDevRepartitionTest[99-i][j][k].getMean());
						}
						else
						{
							//cout << "inhibTempDevRepartitionTestFile is void" << endl;
							inhibTempDevRepartitionTestFile->addIndexedLineData(k*(1+2*NB_TESTED_ANIMALS+1)+j,-(99-i),-1.0);
						}
					}
				}
					
				if (inhibPostTempDevRepartitionTest)
				{
					for (int i=0;i<100;i++)
					{
						if (!inhibPostTempDevRepartitionTest[99-i][j][k].isVoid())
						{
							inhibTempDevRepartitionTestFile->addIndexedLineData(k*(1+2*NB_TESTED_ANIMALS+1)+j,i,(double) inhibPostTempDevRepartitionTest[i][j][k].getMean());
						}
						else
						{
							//cout << "inhibTempDevRepartitionTestFile is void" << endl;
							inhibTempDevRepartitionTestFile->addIndexedLineData(k*(1+2*NB_TESTED_ANIMALS+1)+j,i,-1.0);
						}
					}
				}
				
				
				inhibTempDevRepartitionTestFile->addDataSeparator();
			}
		}	
		
		for (int i=0;i<100;i++)
		{
			if (!inhibPreTempDevRepartitionTest[99-i][0][0].isVoid() && !inhibPreTempDevRepartitionTest[99-i][0][1].isVoid())
			{
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(0,-(99-i),(double) inhibPreTempDevRepartitionTest[99-i][0][0].getMean()-inhibPreTempDevRepartitionTest[99-i][0][1].getMean());
			}
			else
			{
				//cout << "diffInhibTempDevRepartitionTestFile is void" << endl;
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(0,-(99-i),-1.0);
			}
						
		}
		
		for (int i=0;i<100;i++)
		{
			if (!inhibPostTempDevRepartitionTest[i][0][0].isVoid() && !inhibPostTempDevRepartitionTest[i][0][1].isVoid())
			{
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(0,i,(double) inhibPostTempDevRepartitionTest[i][0][0].getMean()-inhibPostTempDevRepartitionTest[i][0][1].getMean());
			}
			else
			{
				//cout << "diffInhibTempDevRepartitionTestFile is void" << endl;
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(0,i,-1.0);
			}
		}
			
		diffInhibTempDevRepartitionTestFile->addDataSeparator();
		
		for (int i=0;i<100;i++)
		{
			if (!inhibPreTempDevRepartitionTest[99-i][1][0].isVoid() && !inhibPreTempDevRepartitionTest[99-i][1][1].isVoid())
			{
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(1,-(99-i),(double) inhibPreTempDevRepartitionTest[99-i][1][0].getMean()-inhibPreTempDevRepartitionTest[99-i][1][1].getMean());
			}
			else
			{
				//cout << "diffInhibTempDevRepartitionTestFile is void" << endl;
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(1,-(99-i),-1.0);
			}
						
		}
		
		for (int i=0;i<100;i++)
		{
			if (!inhibPostTempDevRepartitionTest[i][1][0].isVoid() && !inhibPostTempDevRepartitionTest[i][1][1].isVoid())
			{
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(1,i,(double) inhibPostTempDevRepartitionTest[i][1][0].getMean()-inhibPostTempDevRepartitionTest[i][1][1].getMean());
			}
			else
			{
				//cout << "diffInhibTempDevRepartitionTestFile is void" << endl;
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(1,i,-1.0);
			}
		}
	
			
		diffInhibTempDevRepartitionTestFile->addDataSeparator();
		
		for (int i=0;i<100;i++)
		{
			if (!inhibPreTempDevRepartitionTest[99-i][2][0].isVoid() && !inhibPreTempDevRepartitionTest[99-i][2][1].isVoid())
			{
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(2,-(99-i),(double) inhibPreTempDevRepartitionTest[99-i][2][0].getMean()-inhibPreTempDevRepartitionTest[99-i][2][1].getMean());
			}
			else
			{
				//cout << "diffInhibTempDevRepartitionTestFile is void" << endl;
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(2,-(99-i),-1.0);
			}
						
		}
		
		for (int i=0;i<100;i++)
		{
			if (!inhibPostTempDevRepartitionTest[i][2][0].isVoid() && !inhibPostTempDevRepartitionTest[i][2][1].isVoid())
			{
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(2,i,(double) inhibPostTempDevRepartitionTest[i][2][0].getMean()-inhibPostTempDevRepartitionTest[i][2][1].getMean());
			}
			else
			{
				//cout << "diffInhibTempDevRepartitionTestFile is void" << endl;
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(2,i,-1.0);
			}
		}
		
		diffInhibTempDevRepartitionTestFile->addDataSeparator();
		
		for (int i=0;i<100;i++)
		{
			if (!inhibPreTempDevRepartitionTest[99-i][3][0].isVoid() && !inhibPreTempDevRepartitionTest[99-i][3][1].isVoid())
			{
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(3,-(99-i),(double) inhibPreTempDevRepartitionTest[99-i][3][0].getMean()-inhibPreTempDevRepartitionTest[99-i][3][1].getMean());
			}
			else
			{
				//cout << "diffInhibTempDevRepartitionTestFile is void" << endl;
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(3,-(99-i),-1.0);
			}
						
		}
		
		for (int i=0;i<100;i++)
		{
			if (!inhibPostTempDevRepartitionTest[i][3][0].isVoid() && !inhibPostTempDevRepartitionTest[i][3][1].isVoid())
			{
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(3,i,(double) inhibPostTempDevRepartitionTest[i][3][0].getMean()-inhibPostTempDevRepartitionTest[i][3][1].getMean());
			}
			else
			{
				//cout << "diffInhibTempDevRepartitionTestFile is void" << endl;
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(3,i,-1.0);
			}
		}
			
		diffInhibTempDevRepartitionTestFile->addDataSeparator();
	}
	else
	{
		cerr << "Warning, inhibTempDevRepartitionTestFile && diffInhibTempDevRepartitionTestFile should be inited" << endl;
	}
					#else
						#ifdef _TRANSITION_STAT_MODE
	if (excitTempDevRepartitionTestFile->isOpen() && diffExcitTempDevRepartitionTestFile->isOpen())
	{
		for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
			{
				if (excitPreTempDevRepartitionTest)
				{
					for (int i=0;i<100;i++)
					{
						if (!excitPreTempDevRepartitionTest[99-i][j][k].isVoid())
						{
							if (j%2==0)
							{
								excitTempDevRepartitionTestFile->addIndexedLineData(j,-99+i,(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*excitPreTempDevRepartitionTest[99-i][j][k].getAccu());
							}
							else
							{
								excitTempDevRepartitionTestFile->addIndexedLineData(j,-99+i,(double) EDNetwork::TRANSITION_TIME_LENGTH*excitPreTempDevRepartitionTest[99-i][j][k].getAccu());
							}
							//excitTempDevRepartitionTestFile->addIndexedLineData(j,-(99-i),(double) (excitPreTempDevRepartitionTest[99-i][j][k].getAccu()));
						}
						else
						{
							//cout << "excitTempDevRepartitionTestFile is void" << endl;
							excitTempDevRepartitionTestFile->addIndexedLineData(j,-(99-i),-1.0);
						}
						
					}
				}
	
				if (excitPostTempDevRepartitionTest)
				{
					for (int i=0;i<100;i++)
					{
						if (!excitPostTempDevRepartitionTest[i][j][k].isVoid())
						{
							if (j%2==0)
							{
								excitTempDevRepartitionTestFile->addIndexedLineData(j,i,(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*excitPostTempDevRepartitionTest[i][j][k].getAccu());
							}
							else
							{
								excitTempDevRepartitionTestFile->addIndexedLineData(j,i,(double) EDNetwork::TRANSITION_TIME_LENGTH*excitPostTempDevRepartitionTest[i][j][k].getAccu());
							}
							//excitTempDevRepartitionTestFile->addIndexedLineData(j,i,(double) (excitPostTempDevRepartitionTest[i][j][k].getAccu()));
						}
						else
						{
							//cout << "excitTempDevRepartitionTestFile is void" << endl;
							excitTempDevRepartitionTestFile->addIndexedLineData(j,i,-1.0);
						}
					}
				}
	
				excitTempDevRepartitionTestFile->addDataSeparator();
			}			
		}
			
		
		for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
		{
			
			for (int i=0;i<100;i++)
			{
				if (!excitPreTempDevRepartitionTest[99-i][1][k].isVoid() && !excitPreTempDevRepartitionTest[99-i][0][k].isVoid())
				{
					diffExcitTempDevRepartitionTestFile->addIndexedLineData(0,-(99-i),(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*excitPreTempDevRepartitionTest[99-i][0][k].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*excitPreTempDevRepartitionTest[99-i][1][k].getAccu());
				}
				else
				{	
					//cout << "diffExcitTempDevRepartitionTestFile is void" << endl;
					diffExcitTempDevRepartitionTestFile->addIndexedLineData(0,-(99-i),-1.0);
				}
			}
			
			for (int i=0;i<100;i++)
			{
				if (!excitPostTempDevRepartitionTest[i][1][k].isVoid() && !excitPostTempDevRepartitionTest[i][0][k].isVoid())
				{
					diffExcitTempDevRepartitionTestFile->addIndexedLineData(0,i,(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*excitPostTempDevRepartitionTest[i][0][k].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*excitPostTempDevRepartitionTest[i][1][k].getAccu());
				}
				else
				{
					//cout << "diffExcitTempDevRepartitionTestFile is void" << endl;
					diffExcitTempDevRepartitionTestFile->addIndexedLineData(0,i,-1.0);
				}
			}
				
			diffExcitTempDevRepartitionTestFile->addDataSeparator();
			
			for (int i=0;i<100;i++)
			{
				if (!excitPreTempDevRepartitionTest[99-i][3][k].isVoid() && !excitPreTempDevRepartitionTest[99-i][2][k].isVoid())
				{
					diffExcitTempDevRepartitionTestFile->addIndexedLineData(1,-(99-i),(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*excitPreTempDevRepartitionTest[99-i][2][k].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*excitPreTempDevRepartitionTest[99-i][3][k].getAccu());
				}
				else
				{	
					//cout << "diffExcitTempDevRepartitionTestFile is void" << endl;
					diffExcitTempDevRepartitionTestFile->addIndexedLineData(1,-(99-i),-1.0);
				}
	
			}
				
			for (int i=0;i<100;i++)
			{
				if (!excitPostTempDevRepartitionTest[i][3][k].isVoid() && !excitPostTempDevRepartitionTest[i][2][k].isVoid())
				{
					diffExcitTempDevRepartitionTestFile->addIndexedLineData(1,i,(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*excitPostTempDevRepartitionTest[i][2][k].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*excitPostTempDevRepartitionTest[i][3][k].getAccu());
				}
				else
				{	
					//cout << "diffExcitTempDevRepartitionTestFile is void" << endl;
					diffExcitTempDevRepartitionTestFile->addIndexedLineData(1,i,-1.0);
				}
			}
				
			diffExcitTempDevRepartitionTestFile->addDataSeparator();
			
			for (int i=0;i<100;i++)
			{
				if (!excitPreTempDevRepartitionTest[99-i][5][k].isVoid() && !excitPreTempDevRepartitionTest[99-i][4][k].isVoid())
				{
					diffExcitTempDevRepartitionTestFile->addIndexedLineData(2,-(99-i),(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*excitPreTempDevRepartitionTest[99-i][4][k].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*excitPreTempDevRepartitionTest[99-i][5][k].getAccu());
				}
				else
				{	
					//cout << "diffExcitTempDevRepartitionTestFile is void" << endl;
					diffExcitTempDevRepartitionTestFile->addIndexedLineData(2,-(99-i),-1.0);
				}
			}
				
			for (int i=0;i<100;i++)
			{
				if (!excitPostTempDevRepartitionTest[i][5][k].isVoid() && !excitPostTempDevRepartitionTest[i][4][k].isVoid())
				{
					diffExcitTempDevRepartitionTestFile->addIndexedLineData(2,i,(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*excitPostTempDevRepartitionTest[i][4][k].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*excitPostTempDevRepartitionTest[i][5][k].getAccu());
				}
				else
				{	
					//cout << "diffExcitTempDevRepartitionTestFile is void" << endl;
					diffExcitTempDevRepartitionTestFile->addIndexedLineData(2,i,-1.0);
				}
			}
			
			diffExcitTempDevRepartitionTestFile->addDataSeparator();
			
			for (int i=0;i<100;i++)
			{
				if (!excitPreTempDevRepartitionTest[99-i][7][k].isVoid() && !excitPreTempDevRepartitionTest[99-i][6][k].isVoid())
				{
					diffExcitTempDevRepartitionTestFile->addIndexedLineData(3,-(99-i),(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*excitPreTempDevRepartitionTest[99-i][6][k].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*excitPreTempDevRepartitionTest[99-i][7][k].getAccu());
				}
				else
				{	
					//cout << "diffExcitTempDevRepartitionTestFile is void" << endl;
					diffExcitTempDevRepartitionTestFile->addIndexedLineData(3,-(99-i),-1.0);
				}
			}
				
			for (int i=0;i<100;i++)
			{
				if (!excitPostTempDevRepartitionTest[i][7][k].isVoid() && !excitPostTempDevRepartitionTest[i][6][k].isVoid())
				{
					diffExcitTempDevRepartitionTestFile->addIndexedLineData(3,i,(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*excitPostTempDevRepartitionTest[i][6][k].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*excitPostTempDevRepartitionTest[i][7][k].getAccu());
				}
				else
				{	
					//cout << "diffExcitTempDevRepartitionTestFile is void" << endl;
					diffExcitTempDevRepartitionTestFile->addIndexedLineData(3,i,-1.0);
				}
			}
			
			diffExcitTempDevRepartitionTestFile->addDataSeparator();
		}
	}
	
	if (inhibTempDevRepartitionTestFile->isOpen() && diffInhibTempDevRepartitionTestFile->isOpen())
	{
		for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
			{
				if (inhibPreTempDevRepartitionTest)
				{
					for (int i=0;i<100;i++)
					{
						if (!inhibPreTempDevRepartitionTest[99-i][j][k].isVoid())
						{
							if (j%2==0)
							{
								inhibTempDevRepartitionTestFile->addIndexedLineData(j,-99+i,(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*inhibPreTempDevRepartitionTest[99-i][j][k].getAccu());
							}
							else
							{
								inhibTempDevRepartitionTestFile->addIndexedLineData(j,-99+i,(double) EDNetwork::TRANSITION_TIME_LENGTH*inhibPreTempDevRepartitionTest[99-i][j][k].getAccu());
							}
							//inhibTempDevRepartitionTestFile->addIndexedLineData(j,-(99-i),(double) (inhibPreTempDevRepartitionTest[99-i][j][k].getAccu()));
						}
						else
						{
							//cout << "inhibTempDevRepartitionTestFile is void" << endl;
							inhibTempDevRepartitionTestFile->addIndexedLineData(j,-(99-i),-1.0);
						}
						
					}
				}
	
				if (inhibPostTempDevRepartitionTest)
				{
					for (int i=0;i<100;i++)
					{
						if (!inhibPostTempDevRepartitionTest[i][j][k].isVoid())
						{
							if (j%2==0)
							{
								inhibTempDevRepartitionTestFile->addIndexedLineData(j,i,(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*inhibPostTempDevRepartitionTest[i][j][k].getAccu());
							}
							else
							{
								inhibTempDevRepartitionTestFile->addIndexedLineData(j,i,(double) EDNetwork::TRANSITION_TIME_LENGTH*inhibPostTempDevRepartitionTest[i][j][k].getAccu());
							}
							//inhibTempDevRepartitionTestFile->addIndexedLineData(j,i,(double) (inhibPostTempDevRepartitionTest[i][j][k].getAccu()));
						}
						else
						{
							//cout << "inhibTempDevRepartitionTestFile is void" << endl;
							inhibTempDevRepartitionTestFile->addIndexedLineData(j,i,-1.0);
						}
					}
				}
	
				inhibTempDevRepartitionTestFile->addDataSeparator();
			}
		}
		
		for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
		{
			for (int i=0;i<100;i++)
			{
				if (!inhibPreTempDevRepartitionTest[99-i][1][k].isVoid() && !inhibPreTempDevRepartitionTest[99-i][0][k].isVoid())
				{
					diffInhibTempDevRepartitionTestFile->addIndexedLineData(0,-(99-i),(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*inhibPreTempDevRepartitionTest[99-i][0][k].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*inhibPreTempDevRepartitionTest[99-i][1][k].getAccu());
				}
				else
				{	
					
					//cout << "diffInhibTempDevRepartitionTestFile is void" << endl;
					diffInhibTempDevRepartitionTestFile->addIndexedLineData(0,-(99-i),-1.0);
				}
			}
			
			for (int i=0;i<100;i++)
			{
				if (!inhibPostTempDevRepartitionTest[i][1][k].isVoid() && !inhibPostTempDevRepartitionTest[i][0][k].isVoid())
				{
					diffInhibTempDevRepartitionTestFile->addIndexedLineData(0,i,(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*inhibPostTempDevRepartitionTest[i][0][k].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*inhibPostTempDevRepartitionTest[i][1][k].getAccu());
				}
				else
				{	
					//cout << "diffInhibTempDevRepartitionTestFile is void" << endl;
					diffInhibTempDevRepartitionTestFile->addIndexedLineData(0,i,-1.0);
				}
			}
				
			diffInhibTempDevRepartitionTestFile->addDataSeparator();
			
			for (int i=0;i<100;i++)
			{
				if (!inhibPreTempDevRepartitionTest[99-i][3][k].isVoid() && !inhibPreTempDevRepartitionTest[99-i][2][k].isVoid())
				{
					diffInhibTempDevRepartitionTestFile->addIndexedLineData(1,-(99-i),(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*inhibPreTempDevRepartitionTest[99-i][2][k].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*inhibPreTempDevRepartitionTest[99-i][3][k].getAccu());
				}
				else
				{	
					//cout << "diffInhibTempDevRepartitionTestFile is void" << endl;
					diffInhibTempDevRepartitionTestFile->addIndexedLineData(1,-(99-i),-1.0);
				}
	
			}
				
			for (int i=0;i<100;i++)
			{
				if (!inhibPostTempDevRepartitionTest[i][3][k].isVoid() && !inhibPostTempDevRepartitionTest[i][2][k].isVoid())
				{
					diffInhibTempDevRepartitionTestFile->addIndexedLineData(1,i,(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*inhibPostTempDevRepartitionTest[i][2][k].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*inhibPostTempDevRepartitionTest[i][3][k].getAccu());
				}
				else
				{	
					//cout << "diffInhibTempDevRepartitionTestFile is void" << endl;
					diffInhibTempDevRepartitionTestFile->addIndexedLineData(1,i,-1.0);
				}
			}
				
			diffInhibTempDevRepartitionTestFile->addDataSeparator();
			
			for (int i=0;i<100;i++)
			{
				if (!inhibPreTempDevRepartitionTest[99-i][5][k].isVoid() && !inhibPreTempDevRepartitionTest[99-i][4][k].isVoid())
				{
					diffInhibTempDevRepartitionTestFile->addIndexedLineData(2,-(99-i),(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*inhibPreTempDevRepartitionTest[99-i][4][k].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*inhibPreTempDevRepartitionTest[99-i][5][k].getAccu());
				}
				else
				{	
					//cout << "diffInhibTempDevRepartitionTestFile is void" << endl;
					diffInhibTempDevRepartitionTestFile->addIndexedLineData(2,-(99-i),-1.0);
				}
			}
				
			for (int i=0;i<100;i++)
			{
				if (!inhibPostTempDevRepartitionTest[i][5][k].isVoid() && !inhibPostTempDevRepartitionTest[i][4][k].isVoid())
				{
					diffInhibTempDevRepartitionTestFile->addIndexedLineData(2,i,(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*inhibPostTempDevRepartitionTest[i][4][k].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*inhibPostTempDevRepartitionTest[i][5][k].getAccu());
				}
				else
				{	
					//cout << "diffInhibTempDevRepartitionTestFile is void" << endl;
					diffInhibTempDevRepartitionTestFile->addIndexedLineData(2,i,-1.0);
				}
			}
			
			diffInhibTempDevRepartitionTestFile->addDataSeparator();
				
			for (int i=0;i<100;i++)
			{
				if (!inhibPreTempDevRepartitionTest[99-i][7][k].isVoid() && !inhibPreTempDevRepartitionTest[99-i][6][k].isVoid())
				{
					diffInhibTempDevRepartitionTestFile->addIndexedLineData(3,-(99-i),(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*inhibPreTempDevRepartitionTest[99-i][6][k].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*inhibPreTempDevRepartitionTest[99-i][7][k].getAccu());
				}
				else
				{	
					//cout << "diffInhibTempDevRepartitionTestFile is void" << endl;
					diffInhibTempDevRepartitionTestFile->addIndexedLineData(3,-(99-i),-1.0);
				}
			}
				
			for (int i=0;i<100;i++)
			{
				if (!inhibPostTempDevRepartitionTest[i][7][k].isVoid() && !inhibPostTempDevRepartitionTest[i][6][k].isVoid())
				{
					diffInhibTempDevRepartitionTestFile->addIndexedLineData(3,i,(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*inhibPostTempDevRepartitionTest[i][6][k].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*inhibPostTempDevRepartitionTest[i][7][k].getAccu());
				}
				else
				{	
					//cout << "diffInhibTempDevRepartitionTestFile is void" << endl;
					diffInhibTempDevRepartitionTestFile->addIndexedLineData(3,i,-1.0);
				}
			}
			
			diffInhibTempDevRepartitionTestFile->addDataSeparator();
		}
	}
						#else
		
	if (diffExcitTempDevRepartitionTestFile->isOpen())
	{
		for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
		{
			if (excitPreTempDevRepartitionTest)
			{
				for (int i=0;i<100;i++)
				{
					if (!excitPreTempDevRepartitionTest[99-i][1][k].isVoid() && !excitPreTempDevRepartitionTest[99-i][0][k].isVoid())
					{
						diffExcitTempDevRepartitionTestFile->addIndexedLineData(k,-(99-i),(double) (excitPreTempDevRepartitionTest[99-i][1][k].getMean() - excitPreTempDevRepartitionTest[99-i][0][k].getMean()));
					}
					else
					{
						//cout << "diffExcitTempDevRepartitionTestFile is void" << endl;
						diffExcitTempDevRepartitionTestFile->addIndexedLineData(k,-(99-i),-1.0);
					}
				}
			}

			if (excitPostTempDevRepartitionTest)
			{
				for (int i=0;i<100;i++)
				{
					if (!excitPostTempDevRepartitionTest[i][1][k].isVoid() && !excitPostTempDevRepartitionTest[i][0][k].isVoid())
					{
						diffExcitTempDevRepartitionTestFile->addIndexedLineData(k,i,(double) (excitPostTempDevRepartitionTest[i][1][k].getMean() - excitPostTempDevRepartitionTest[i][0][k].getMean()));
					}
					else
					{
						//cout << "diffExcitTempDevRepartitionTestFile is void" << endl;
						diffExcitTempDevRepartitionTestFile->addIndexedLineData(k,i,-1.0);
					}
				}
			}

			diffExcitTempDevRepartitionTestFile->addDataSeparator();
		}
	}
	else
	{
		cerr << "Warning, diffExcitTempDevRepartitionTestFile should be inited" << endl;
	}
	
	if (diffInhibTempDevRepartitionTestFile->isOpen())
	{
		for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
		{
			if (inhibPreTempDevRepartitionTest)
			{
				for (int i=0;i<100;i++)
				{
					if (!inhibPreTempDevRepartitionTest[99-i][1][k].isVoid() && !inhibPreTempDevRepartitionTest[99-i][0][k].isVoid())
					{
						diffInhibTempDevRepartitionTestFile->addIndexedLineData(k,-(99-i),(double) (inhibPreTempDevRepartitionTest[99-i][1][k].getMean() - inhibPreTempDevRepartitionTest[99-i][0][k].getMean()));
					}
					else
					{
						//cout << "diffInhibTempDevRepartitionTestFile is void" << endl;
						diffInhibTempDevRepartitionTestFile->addIndexedLineData(k,-(99-i),-1.0);
					}
					
				}
			}

			if (inhibPostTempDevRepartitionTest)
			{
				for (int i=0;i<100;i++)
				{
					if (!inhibPostTempDevRepartitionTest[i][1][k].isVoid() && !inhibPostTempDevRepartitionTest[i][0][k].isVoid())
					{
						diffInhibTempDevRepartitionTestFile->addIndexedLineData(k,i,(double) (inhibPostTempDevRepartitionTest[i][1][k].getMean() - inhibPostTempDevRepartitionTest[i][0][k].getMean()));
					}
					else
					{
						//cout << "diffInhibTempDevRepartitionTestFile is void" << endl;
						diffInhibTempDevRepartitionTestFile->addIndexedLineData(k,i,-1.0);
					}
				}
			}

			diffInhibTempDevRepartitionTestFile->addDataSeparator();
		}
	}
	else
	{
		cerr << "Warning, diffInhibTempDevRepartitionTestFile should be inited" << endl;
	}
	
	if (excitTempDevRepartitionTestFile->isOpen())
	{
		for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
		{
			if (excitPreTempDevRepartitionTest)
			{
				for (int i=0;i<100;i++)
				{
					if (!excitPreTempDevRepartitionTest[99-i][1][k].isVoid())
					{
						excitTempDevRepartitionTestFile->addIndexedLineData(k,-(99-i),(double) (excitPreTempDevRepartitionTest[99-i][1][k].getMean()));
					}
					else
					{
						
						//cout << "excitTempDevRepartitionTestFile is void" << endl;
						excitTempDevRepartitionTestFile->addIndexedLineData(k,-(99-i),-1.0);
					}
				}
			}

			if (excitPostTempDevRepartitionTest)
			{
				for (int i=0;i<100;i++)
				{
					if (!excitPostTempDevRepartitionTest[i][1][k].isVoid())
					{
						excitTempDevRepartitionTestFile->addIndexedLineData(k,i,(double) (excitPostTempDevRepartitionTest[i][1][k].getMean()));
					}
					else
					{
						//cout << "excitTempDevRepartitionTestFile is void" << endl;
						excitTempDevRepartitionTestFile->addIndexedLineData(k,i,-1.0);
					}
				}
			}
 
			excitTempDevRepartitionTestFile->addDataSeparator();
		}
	}
	else
	{
		cerr << "Warning, excitTempDevRepartitionTestFile should be inited" << endl;
	}
	
	if (inhibTempDevRepartitionTestFile->isOpen())
	{
		for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
		{
			if (inhibPreTempDevRepartitionTest)
			{
				for (int i=0;i<100;i++)
				{
					if (!inhibPreTempDevRepartitionTest[99-i][1][k].isVoid())
					{
						inhibTempDevRepartitionTestFile->addIndexedLineData(k,-(99-i),(double) (inhibPreTempDevRepartitionTest[99-i][1][k].getMean()));
					}
					else
					{
						//cout << "inhibTempDevRepartitionTestFile is void" << endl;
						inhibTempDevRepartitionTestFile->addIndexedLineData(k,-(99-i),-1.0);
					}
					
				}
			}

			if (inhibPostTempDevRepartitionTest)
			{
				for (int i=0;i<100;i++)
				{
					if (!inhibPostTempDevRepartitionTest[i][1][k].isVoid())
					{
						inhibTempDevRepartitionTestFile->addIndexedLineData(k,i,(double) (inhibPostTempDevRepartitionTest[i][1][k].getMean()));
					}
					else
					{
						//cout << "inhibTempDevRepartitionTestFile is void" << endl;
						inhibTempDevRepartitionTestFile->addIndexedLineData(k,i,-1.0);
					}
				}
			}

			inhibTempDevRepartitionTestFile->addDataSeparator();
		}
	}
	else
	{
		cerr << "Warning, inhibTempDevRepartitionTestFile should be inited" << endl;
	}
						#endif
					#endif
				#else
	if (excitTempDevRepartitionTestFile->isOpen())
	{
		for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
		{
			if (excitPreTempDevRepartitionTest)
			{
				for (int i=0;i<100;i++)
				{
					if (!excitPreTempDevRepartitionTest[99-i][k].isVoid())
					{
						excitTempDevRepartitionTestFile->addIndexedLineData(k,-(99-i),(double) (excitPreTempDevRepartitionTest[99-i][k].getMean()));
					}
					else
					{
						//cout << "excitTempDevRepartitionTestFile is void" << endl;
						excitTempDevRepartitionTestFile->addIndexedLineData(k,-(99-i),-1.0);
					}
				}
			}

			if (excitPostTempDevRepartitionTest)
			{
				for (int i=0;i<100;i++)
				{
					if (!excitPostTempDevRepartitionTest[i][k].isVoid())
					{
						excitTempDevRepartitionTestFile->addIndexedLineData(k,i,(double) (excitPostTempDevRepartitionTest[i][k].getMean()));
					}
					else
					{
						//cout << "excitTempDevRepartitionTestFile is void" << endl;
						excitTempDevRepartitionTestFile->addIndexedLineData(k,i,-1.0);
					}
				}
			}
			
			excitTempDevRepartitionTestFile->addDataSeparator();
		}
	}
	else
	{
		cerr << "Warning, excitTempDevRepartitionTestFile should be inited" << endl;
	}
	
	if (inhibTempDevRepartitionTestFile->isOpen())
	{
		for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
		{
			if (inhibPreTempDevRepartitionTest)
			{
				for (int i=0;i<100;i++)
				{
					if (!inhibPreTempDevRepartitionTest[99-i][k].isVoid())
					{
						inhibTempDevRepartitionTestFile->addIndexedLineData(k,-(99-i),(double) (inhibPreTempDevRepartitionTest[99-i][k].getMean()));
					}
					else
					{
						//cout << "inhibTempDevRepartitionTestFile is void" << endl;
						inhibTempDevRepartitionTestFile->addIndexedLineData(k,-(99-i),-1.0);
					}
					
				}
			}

			if (inhibPostTempDevRepartitionTest)
			{
				for (int i=0;i<100;i++)
				{
					if (!inhibPostTempDevRepartitionTest[i][k].isVoid())
					{
						inhibTempDevRepartitionTestFile->addIndexedLineData(k,i,(double) (inhibPostTempDevRepartitionTest[i][k].getMean()));
					}
					else
					{
						//cout << "inhibTempDevRepartitionTestFile is void" << endl;
						inhibTempDevRepartitionTestFile->addIndexedLineData(k,i,-1.0);
					}
				}
			}

			inhibTempDevRepartitionTestFile->addDataSeparator();
		}
	}
	else
	{
		cerr << "Warning, inhibTempDevRepartitionTestFile should be inited" << endl;
	}	
				#endif
			#else	
				#ifdef _PHASE_TEST_MODE
	if (excitTempDevRepartitionTestFile->isOpen() && diffExcitTempDevRepartitionTestFile->isOpen())
	{
					#ifdef _TRANSITION_STAT_MODE
		for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			if (excitPreTempDevRepartitionTest)
			{
				for (int i=0;i<100;i++)
				{
					if (!excitPreTempDevRepartitionTest[99-i][j].isVoid())
					{
						if (j%2==0)
						{
							excitTempDevRepartitionTestFile->addIndexedLineData(j,-99+i,(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*excitPreTempDevRepartitionTest[99-i][j].getAccu());
						}
						else
						{
							excitTempDevRepartitionTestFile->addIndexedLineData(j,-99+i,(double) EDNetwork::TRANSITION_TIME_LENGTH*excitPreTempDevRepartitionTest[99-i][j].getAccu());
						}
						//excitTempDevRepartitionTestFile->addIndexedLineData(j,-(99-i),(double) (excitPreTempDevRepartitionTest[99-i][j].getAccu()));
					}
					else
					{
						//cout << "excitTempDevRepartitionTestFile is void" << endl;
						excitTempDevRepartitionTestFile->addIndexedLineData(j,-(99-i),-1.0);
					}
					
				}
			}

			if (excitPostTempDevRepartitionTest)
			{
				for (int i=0;i<100;i++)
				{
					if (!excitPostTempDevRepartitionTest[i][j].isVoid())
					{
						if (j%2==0)
						{
							excitTempDevRepartitionTestFile->addIndexedLineData(j,i,(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*excitPostTempDevRepartitionTest[i][j].getAccu());
						}
						else
						{
							excitTempDevRepartitionTestFile->addIndexedLineData(j,i,(double) EDNetwork::TRANSITION_TIME_LENGTH*excitPostTempDevRepartitionTest[i][j].getAccu());
						}
						//excitTempDevRepartitionTestFile->addIndexedLineData(j,i,(double) (excitPostTempDevRepartitionTest[i][j].getAccu()));
					}
					else
					{
						//cout << "excitTempDevRepartitionTestFile is void" << endl;
						excitTempDevRepartitionTestFile->addIndexedLineData(j,i,-1.0);
					}
				}
			}

			excitTempDevRepartitionTestFile->addDataSeparator();
		}
			
		for (int i=0;i<100;i++)
		{
			if (!excitPreTempDevRepartitionTest[99-i][1].isVoid() && !excitPreTempDevRepartitionTest[99-i][0].isVoid())
			{
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(0,-(99-i),(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*excitPreTempDevRepartitionTest[99-i][0].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*excitPreTempDevRepartitionTest[99-i][1].getAccu());
			}
			else
			{	
				//cout << "diffExcitTempDevRepartitionTestFile is void" << endl;
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(0,-(99-i),-1.0);
			}
		}
		
		for (int i=0;i<100;i++)
		{
			if (!excitPostTempDevRepartitionTest[i][1].isVoid() && !excitPostTempDevRepartitionTest[i][0].isVoid())
			{
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(0,i,(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*excitPostTempDevRepartitionTest[i][0].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*excitPostTempDevRepartitionTest[i][1].getAccu());
			}
			else
			{
				//cout << "diffExcitTempDevRepartitionTestFile is void" << endl;
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(0,i,-1.0);
			}
		}
			
		diffExcitTempDevRepartitionTestFile->addDataSeparator();
		
		for (int i=0;i<100;i++)
		{
			if (!excitPreTempDevRepartitionTest[99-i][3].isVoid() && !excitPreTempDevRepartitionTest[99-i][2].isVoid())
			{
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(1,-(99-i),(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*excitPreTempDevRepartitionTest[99-i][2].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*excitPreTempDevRepartitionTest[99-i][3].getAccu());
			}
			else
			{	
				//cout << "diffExcitTempDevRepartitionTestFile is void" << endl;
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(1,-(99-i),-1.0);
			}

		}
			
		for (int i=0;i<100;i++)
		{
			if (!excitPostTempDevRepartitionTest[i][3].isVoid() && !excitPostTempDevRepartitionTest[i][2].isVoid())
			{
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(1,i,(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*excitPostTempDevRepartitionTest[i][2].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*excitPostTempDevRepartitionTest[i][3].getAccu());
			}
			else
			{	
				//cout << "diffExcitTempDevRepartitionTestFile is void" << endl;
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(1,i,-1.0);
			}
		}
			
		diffExcitTempDevRepartitionTestFile->addDataSeparator();
		
		for (int i=0;i<100;i++)
		{
			if (!excitPreTempDevRepartitionTest[99-i][5].isVoid() && !excitPreTempDevRepartitionTest[99-i][4].isVoid())
			{
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(2,-(99-i),(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*excitPreTempDevRepartitionTest[99-i][4].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*excitPreTempDevRepartitionTest[99-i][5].getAccu());
			}
			else
			{	
				//cout << "diffExcitTempDevRepartitionTestFile is void" << endl;
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(2,-(99-i),-1.0);
			}
		}
			
		for (int i=0;i<100;i++)
		{
			if (!excitPostTempDevRepartitionTest[i][5].isVoid() && !excitPostTempDevRepartitionTest[i][4].isVoid())
			{
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(2,i,(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*excitPostTempDevRepartitionTest[i][4].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*excitPostTempDevRepartitionTest[i][5].getAccu());
			}
			else
			{	
				//cout << "diffExcitTempDevRepartitionTestFile is void" << endl;
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(2,i,-1.0);
			}
		}
		
		diffExcitTempDevRepartitionTestFile->addDataSeparator();
		
		for (int i=0;i<100;i++)
		{
			if (!excitPreTempDevRepartitionTest[99-i][7].isVoid() && !excitPreTempDevRepartitionTest[99-i][6].isVoid())
			{
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(3,-(99-i),(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*excitPreTempDevRepartitionTest[99-i][6].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*excitPreTempDevRepartitionTest[99-i][7].getAccu());
			}
			else
			{	
				//cout << "diffExcitTempDevRepartitionTestFile is void" << endl;
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(3,-(99-i),-1.0);
			}
		}
			
		for (int i=0;i<100;i++)
		{
			if (!excitPostTempDevRepartitionTest[i][7].isVoid() && !excitPostTempDevRepartitionTest[i][6].isVoid())
			{
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(3,i,(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*excitPostTempDevRepartitionTest[i][6].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*excitPostTempDevRepartitionTest[i][7].getAccu());
			}
			else
			{	
				//cout << "diffExcitTempDevRepartitionTestFile is void" << endl;
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(3,i,-1.0);
			}
		}
		
		diffExcitTempDevRepartitionTestFile->addDataSeparator();
		
				#else
					#ifdef _REPETITIVE_TEST_MODE
		
		for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			if (excitPreTempDevRepartitionTest)
			{
				for (int i=0;i<100;i++)
				{
					if (!excitPreTempDevRepartitionTest[99-i][j].isVoid())
					{
						excitTempDevRepartitionTestFile->addIndexedLineData(j,-(99-i),(double) (excitPreTempDevRepartitionTest[99-i][j].getMean()));
					}
					else
					{
						//cout << "excitTempDevRepartitionTestFile is void" << endl;
						excitTempDevRepartitionTestFile->addIndexedLineData(j,-(99-i),-1.0);
					}
				}
			}

			if (excitPostTempDevRepartitionTest)
			{
				for (int i=0;i<100;i++)
				{
					if (!excitPostTempDevRepartitionTest[i][j].isVoid())
					{
						excitTempDevRepartitionTestFile->addIndexedLineData(j,i,(double) (excitPostTempDevRepartitionTest[i][j].getMean()));
					}
					else
					{
						//cout << "excitTempDevRepartitionTestFile is void" << endl;
						excitTempDevRepartitionTestFile->addIndexedLineData(j,i,-1.0);
					}
				}
			}
			
			excitTempDevRepartitionTestFile->addDataSeparator();
			
			
		}
			
		for (int i=0;i<100;i++)
		{
			if (!excitPreTempDevRepartitionTest[99-i][2].isVoid() && !excitPreTempDevRepartitionTest[99-i][0].isVoid())
			{
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(0,-(99-i),(double) excitPreTempDevRepartitionTest[99-i][2].getMean()-excitPreTempDevRepartitionTest[99-i][0].getMean());
			}
			else
			{	
				//cout << "diffExcitTempDevRepartitionTestFile is void" << endl;
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(0,-(99-i),-1.0);
			}
		}
		
		for (int i=0;i<100;i++)
		{
			if (!excitPostTempDevRepartitionTest[i][2].isVoid() && !excitPostTempDevRepartitionTest[i][0].isVoid())
			{
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(0,i,(double) excitPostTempDevRepartitionTest[i][2].getMean()-excitPostTempDevRepartitionTest[i][0].getMean());
			}
			else
			{
				//cout << "diffExcitTempDevRepartitionTestFile is void" << endl;
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(0,i,-1.0);
			}
		}
			
		diffExcitTempDevRepartitionTestFile->addDataSeparator();
		
		for (int i=0;i<100;i++)
		{
			if (!excitPreTempDevRepartitionTest[99-i][3].isVoid() && !excitPreTempDevRepartitionTest[99-i][1].isVoid())
			{
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(1,-(99-i),(double) excitPreTempDevRepartitionTest[99-i][3].getMean()-excitPreTempDevRepartitionTest[99-i][1].getMean());
			}
			else
			{	
				//cout << "diffExcitTempDevRepartitionTestFile is void" << endl;
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(1,-(99-i),-1.0);
			}

		}
			
		for (int i=0;i<100;i++)
		{
			if (!excitPostTempDevRepartitionTest[i][3].isVoid() && !excitPostTempDevRepartitionTest[i][1].isVoid())
			{
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(1,i,(double) excitPostTempDevRepartitionTest[i][3].getMean()-excitPostTempDevRepartitionTest[i][1].getMean());
			}
			else
			{	
				//cout << "diffExcitTempDevRepartitionTestFile is void" << endl;
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(1,i,-1.0);
			}
		}
			
		diffExcitTempDevRepartitionTestFile->addDataSeparator();
		
					#else
		for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			if (excitPreTempDevRepartitionTest)
			{
				for (int i=0;i<100;i++)
				{
					if (!excitPreTempDevRepartitionTest[99-i][j].isVoid())
					{
						excitTempDevRepartitionTestFile->addIndexedLineData(j,-(99-i),(double) (excitPreTempDevRepartitionTest[99-i][j].getMean()));
					}
					else
					{
						//cout << "excitTempDevRepartitionTestFile is void" << endl;
						excitTempDevRepartitionTestFile->addIndexedLineData(j,-(99-i),-1.0);
					}
				}
			}

			if (excitPostTempDevRepartitionTest)
			{
				for (int i=0;i<100;i++)
				{
					if (!excitPostTempDevRepartitionTest[i][j].isVoid())
					{
						excitTempDevRepartitionTestFile->addIndexedLineData(j,i,(double) (excitPostTempDevRepartitionTest[i][j].getMean()));
					}
					else
					{
						//cout << "excitTempDevRepartitionTestFile is void" << endl;
						excitTempDevRepartitionTestFile->addIndexedLineData(j,i,-1.0);
					}
				}
			}
			
			excitTempDevRepartitionTestFile->addDataSeparator();
			
			
		}
			
		for (int i=0;i<100;i++)
		{
			if (!excitPreTempDevRepartitionTest[99-i][1].isVoid() && !excitPreTempDevRepartitionTest[99-i][0].isVoid())
			{
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(0,-(99-i),(double) excitPreTempDevRepartitionTest[99-i][1].getMean()-excitPreTempDevRepartitionTest[99-i][0].getMean());
			}
			else
			{	
				//cout << "diffExcitTempDevRepartitionTestFile is void" << endl;
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(0,-(99-i),-1.0);
			}
		}
		
		for (int i=0;i<100;i++)
		{
			if (!excitPostTempDevRepartitionTest[i][1].isVoid() && !excitPostTempDevRepartitionTest[i][0].isVoid())
			{
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(0,i,(double) excitPostTempDevRepartitionTest[i][1].getMean()-excitPostTempDevRepartitionTest[i][0].getMean());
			}
			else
			{
				//cout << "diffExcitTempDevRepartitionTestFile is void" << endl;
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(0,i,-1.0);
			}
		}
			
		diffExcitTempDevRepartitionTestFile->addDataSeparator();
		
		for (int i=0;i<100;i++)
		{
			if (!excitPreTempDevRepartitionTest[99-i][2].isVoid() && !excitPreTempDevRepartitionTest[99-i][0].isVoid())
			{
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(1,-(99-i),(double) excitPreTempDevRepartitionTest[99-i][2].getMean()-excitPreTempDevRepartitionTest[99-i][0].getMean());
			}
			else
			{	
				//cout << "diffExcitTempDevRepartitionTestFile is void" << endl;
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(1,-(99-i),-1.0);
			}

		}
			
		for (int i=0;i<100;i++)
		{
			if (!excitPostTempDevRepartitionTest[i][2].isVoid() && !excitPostTempDevRepartitionTest[i][0].isVoid())
			{
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(1,i,(double) excitPostTempDevRepartitionTest[i][2].getMean()-excitPostTempDevRepartitionTest[i][0].getMean());
			}
			else
			{	
				//cout << "diffExcitTempDevRepartitionTestFile is void" << endl;
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(1,i,-1.0);
			}
		}
			
		diffExcitTempDevRepartitionTestFile->addDataSeparator();
		
		for (int i=0;i<100;i++)
		{
			if (!excitPreTempDevRepartitionTest[99-i][3].isVoid() && !excitPreTempDevRepartitionTest[99-i][0].isVoid())
			{
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(2,-(99-i),(double) excitPreTempDevRepartitionTest[99-i][3].getMean()-excitPreTempDevRepartitionTest[99-i][0].getMean());
			}
			else
			{	
				//cout << "diffExcitTempDevRepartitionTestFile is void" << endl;
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(2,-(99-i),-1.0);
			}
		}
			
		for (int i=0;i<100;i++)
		{
			if (!excitPostTempDevRepartitionTest[i][3].isVoid() && !excitPostTempDevRepartitionTest[i][0].isVoid())
			{
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(2,i,(double) excitPostTempDevRepartitionTest[i][3].getMean()-excitPostTempDevRepartitionTest[i][0].getMean());
			}
			else
			{	
				//cout << "diffExcitTempDevRepartitionTestFile is void" << endl;
				diffExcitTempDevRepartitionTestFile->addIndexedLineData(2,i,-1.0);
			}
		}
		
		diffExcitTempDevRepartitionTestFile->addDataSeparator();
						#endif
					#endif
	}
	else
	{
		cerr << "Warning, excitTempDevRepartitionTestFile && diffExcitTempDevRepartitionTestFile should be inited" << endl;
	}
	
	if (inhibTempDevRepartitionTestFile->isOpen() && diffInhibTempDevRepartitionTestFile->isOpen())
	{
					#ifdef _TRANSITION_STAT_MODE
		for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			if (inhibPreTempDevRepartitionTest)
			{
				for (int i=0;i<100;i++)
				{
					if (!inhibPreTempDevRepartitionTest[99-i][j].isVoid())
					{
						if (j%2==0)
						{
							inhibTempDevRepartitionTestFile->addIndexedLineData(j,-99+i,(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*inhibPreTempDevRepartitionTest[99-i][j].getAccu());
						}
						else
						{
							inhibTempDevRepartitionTestFile->addIndexedLineData(j,-99+i,(double) EDNetwork::TRANSITION_TIME_LENGTH*inhibPreTempDevRepartitionTest[99-i][j].getAccu());
						}
						//inhibTempDevRepartitionTestFile->addIndexedLineData(j,-(99-i),(double) (inhibPreTempDevRepartitionTest[99-i][j].getAccu()));
					}
					else
					{
						//cout << "inhibTempDevRepartitionTestFile is void" << endl;
						inhibTempDevRepartitionTestFile->addIndexedLineData(j,-(99-i),-1.0);
					}
					
				}
			}

			if (inhibPostTempDevRepartitionTest)
			{
				for (int i=0;i<100;i++)
				{
					if (!inhibPostTempDevRepartitionTest[i][j].isVoid())
					{
						if (j%2==0)
						{
							inhibTempDevRepartitionTestFile->addIndexedLineData(j,i,(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*inhibPostTempDevRepartitionTest[i][j].getAccu());
						}
						else
						{
							inhibTempDevRepartitionTestFile->addIndexedLineData(j,i,(double) EDNetwork::TRANSITION_TIME_LENGTH*inhibPostTempDevRepartitionTest[i][j].getAccu());
						}
						//inhibTempDevRepartitionTestFile->addIndexedLineData(j,i,(double) (inhibPostTempDevRepartitionTest[i][j].getAccu()));
					}
					else
					{
						//cout << "inhibTempDevRepartitionTestFile is void" << endl;
						inhibTempDevRepartitionTestFile->addIndexedLineData(j,i,-1.0);
					}
				}
			}

			inhibTempDevRepartitionTestFile->addDataSeparator();
	
		}
			
		for (int i=0;i<100;i++)
		{
			if (!inhibPreTempDevRepartitionTest[99-i][1].isVoid() && !inhibPreTempDevRepartitionTest[99-i][0].isVoid())
			{
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(0,-(99-i),(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*inhibPreTempDevRepartitionTest[99-i][0].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*inhibPreTempDevRepartitionTest[99-i][1].getAccu());
			}
			else
			{	
				
				//cout << "diffInhibTempDevRepartitionTestFile is void" << endl;
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(0,-(99-i),-1.0);
			}
		}
		
		for (int i=0;i<100;i++)
		{
			if (!inhibPostTempDevRepartitionTest[i][1].isVoid() && !inhibPostTempDevRepartitionTest[i][0].isVoid())
			{
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(0,i,(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*inhibPostTempDevRepartitionTest[i][0].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*inhibPostTempDevRepartitionTest[i][1].getAccu());
			}
			else
			{	
				//cout << "diffInhibTempDevRepartitionTestFile is void" << endl;
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(0,i,-1.0);
			}
		}
			
		diffInhibTempDevRepartitionTestFile->addDataSeparator();
		
		for (int i=0;i<100;i++)
		{
			if (!inhibPreTempDevRepartitionTest[99-i][3].isVoid() && !inhibPreTempDevRepartitionTest[99-i][2].isVoid())
			{
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(1,-(99-i),(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*inhibPreTempDevRepartitionTest[99-i][2].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*inhibPreTempDevRepartitionTest[99-i][3].getAccu());
			}
			else
			{	
				//cout << "diffInhibTempDevRepartitionTestFile is void" << endl;
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(1,-(99-i),-1.0);
			}

		}
			
		for (int i=0;i<100;i++)
		{
			if (!inhibPostTempDevRepartitionTest[i][3].isVoid() && !inhibPostTempDevRepartitionTest[i][2].isVoid())
			{
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(1,i,(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*inhibPostTempDevRepartitionTest[i][2].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*inhibPostTempDevRepartitionTest[i][3].getAccu());
			}
			else
			{	
				//cout << "diffInhibTempDevRepartitionTestFile is void" << endl;
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(1,i,-1.0);
			}
		}
			
		diffInhibTempDevRepartitionTestFile->addDataSeparator();
		
		for (int i=0;i<100;i++)
		{
			if (!inhibPreTempDevRepartitionTest[99-i][5].isVoid() && !inhibPreTempDevRepartitionTest[99-i][4].isVoid())
			{
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(2,-(99-i),(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*inhibPreTempDevRepartitionTest[99-i][4].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*inhibPreTempDevRepartitionTest[99-i][5].getAccu());
			}
			else
			{	
				//cout << "diffInhibTempDevRepartitionTestFile is void" << endl;
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(2,-(99-i),-1.0);
			}
		}
			
		for (int i=0;i<100;i++)
		{
			if (!inhibPostTempDevRepartitionTest[i][5].isVoid() && !inhibPostTempDevRepartitionTest[i][4].isVoid())
			{
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(2,i,(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*inhibPostTempDevRepartitionTest[i][4].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*inhibPostTempDevRepartitionTest[i][5].getAccu());
			}
			else
			{	
				//cout << "diffInhibTempDevRepartitionTestFile is void" << endl;
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(2,i,-1.0);
			}
		}
		
		diffInhibTempDevRepartitionTestFile->addDataSeparator();
			
		for (int i=0;i<100;i++)
		{
			if (!inhibPreTempDevRepartitionTest[99-i][7].isVoid() && !inhibPreTempDevRepartitionTest[99-i][6].isVoid())
			{
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(3,-(99-i),(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*inhibPreTempDevRepartitionTest[99-i][6].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*inhibPreTempDevRepartitionTest[99-i][7].getAccu());
			}
			else
			{	
				//cout << "diffInhibTempDevRepartitionTestFile is void" << endl;
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(3,-(99-i),-1.0);
			}
		}
			
		for (int i=0;i<100;i++)
		{
			if (!inhibPostTempDevRepartitionTest[i][7].isVoid() && !inhibPostTempDevRepartitionTest[i][6].isVoid())
			{
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(3,i,(double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)*inhibPostTempDevRepartitionTest[i][6].getAccu()-EDNetwork::TRANSITION_TIME_LENGTH*inhibPostTempDevRepartitionTest[i][7].getAccu());
			}
			else
			{	
				//cout << "diffInhibTempDevRepartitionTestFile is void" << endl;
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(3,i,-1.0);
			}
		}
		
		diffInhibTempDevRepartitionTestFile->addDataSeparator();
		
				#else
					#ifdef _REPETITIVE_TEST_MODE
		for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			if (inhibPreTempDevRepartitionTest)
			{
				for (int i=0;i<100;i++)
				{
					if (!inhibPreTempDevRepartitionTest[99-i][j].isVoid())
					{
						inhibTempDevRepartitionTestFile->addIndexedLineData(j,-(99-i),(double) (inhibPreTempDevRepartitionTest[99-i][j].getMean()));
					}
					else
					{
						//cout << "inhibTempDevRepartitionTestFile is void" << endl;
						inhibTempDevRepartitionTestFile->addIndexedLineData(j,-(99-i),-1.0);
					}
					
				}
			}

			if (inhibPostTempDevRepartitionTest)
			{
				for (int i=0;i<100;i++)
				{
					if (!inhibPostTempDevRepartitionTest[i][j].isVoid())
					{
						inhibTempDevRepartitionTestFile->addIndexedLineData(j,i,(double) (inhibPostTempDevRepartitionTest[i][j].getMean()));
					}
					else
					{
						//cout << "inhibTempDevRepartitionTestFile is void" << endl;
						inhibTempDevRepartitionTestFile->addIndexedLineData(j,i,-1.0);
					}
				}
			}

			inhibTempDevRepartitionTestFile->addDataSeparator();
	
		}
			
		for (int i=0;i<100;i++)
		{
			if (!inhibPreTempDevRepartitionTest[99-i][2].isVoid() && !inhibPreTempDevRepartitionTest[99-i][0].isVoid())
			{
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(0,-(99-i),(double) inhibPreTempDevRepartitionTest[99-i][2].getMean()-inhibPreTempDevRepartitionTest[99-i][0].getMean());
			}
			else
			{	
				
				//cout << "diffInhibTempDevRepartitionTestFile is void" << endl;
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(0,-(99-i),-1.0);
			}
		}
		
		for (int i=0;i<100;i++)
		{
			if (!inhibPostTempDevRepartitionTest[i][2].isVoid() && !inhibPostTempDevRepartitionTest[i][0].isVoid())
			{
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(0,i,(double) inhibPostTempDevRepartitionTest[i][2].getMean()-inhibPostTempDevRepartitionTest[i][0].getMean());
			}
			else
			{	
				//cout << "diffInhibTempDevRepartitionTestFile is void" << endl;
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(0,i,-1.0);
			}
		}
			
		diffInhibTempDevRepartitionTestFile->addDataSeparator();
		
		for (int i=0;i<100;i++)
		{
			if (!inhibPreTempDevRepartitionTest[99-i][3].isVoid() && !inhibPreTempDevRepartitionTest[99-i][1].isVoid())
			{
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(1,-(99-i),(double) inhibPreTempDevRepartitionTest[99-i][3].getMean()-inhibPreTempDevRepartitionTest[99-i][1].getMean());
			}
			else
			{	
				//cout << "diffInhibTempDevRepartitionTestFile is void" << endl;
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(1,-(99-i),-1.0);
			}

		}
			
		for (int i=0;i<100;i++)
		{
			if (!inhibPostTempDevRepartitionTest[i][3].isVoid() && !inhibPostTempDevRepartitionTest[i][3].isVoid())
			{
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(1,i,(double) inhibPostTempDevRepartitionTest[i][1].getMean()-inhibPostTempDevRepartitionTest[i][1].getMean());
			}
			else
			{	
				//cout << "diffInhibTempDevRepartitionTestFile is void" << endl;
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(1,i,-1.0);
			}
		}
			
		diffInhibTempDevRepartitionTestFile->addDataSeparator();
		
					#else
		for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			if (inhibPreTempDevRepartitionTest)
			{
				for (int i=0;i<100;i++)
				{
					if (!inhibPreTempDevRepartitionTest[99-i][j].isVoid())
					{
						inhibTempDevRepartitionTestFile->addIndexedLineData(j,-(99-i),(double) (inhibPreTempDevRepartitionTest[99-i][j].getMean()));
					}
					else
					{
						//cout << "inhibTempDevRepartitionTestFile is void" << endl;
						inhibTempDevRepartitionTestFile->addIndexedLineData(j,-(99-i),-1.0);
					}
					
				}
			}

			if (inhibPostTempDevRepartitionTest)
			{
				for (int i=0;i<100;i++)
				{
					if (!inhibPostTempDevRepartitionTest[i][j].isVoid())
					{
						inhibTempDevRepartitionTestFile->addIndexedLineData(j,i,(double) (inhibPostTempDevRepartitionTest[i][j].getMean()));
					}
					else
					{
						//cout << "inhibTempDevRepartitionTestFile is void" << endl;
						inhibTempDevRepartitionTestFile->addIndexedLineData(j,i,-1.0);
					}
				}
			}

			inhibTempDevRepartitionTestFile->addDataSeparator();
	
		}
			
		for (int i=0;i<100;i++)
		{
			if (!inhibPreTempDevRepartitionTest[99-i][1].isVoid() && !inhibPreTempDevRepartitionTest[99-i][0].isVoid())
			{
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(0,-(99-i),(double) inhibPreTempDevRepartitionTest[99-i][1].getMean()-inhibPreTempDevRepartitionTest[99-i][0].getMean());
			}
			else
			{	
				
				//cout << "diffInhibTempDevRepartitionTestFile is void" << endl;
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(0,-(99-i),-1.0);
			}
		}
		
		for (int i=0;i<100;i++)
		{
			if (!inhibPostTempDevRepartitionTest[i][1].isVoid() && !inhibPostTempDevRepartitionTest[i][0].isVoid())
			{
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(0,i,(double) inhibPostTempDevRepartitionTest[i][1].getMean()-inhibPostTempDevRepartitionTest[i][0].getMean());
			}
			else
			{	
				//cout << "diffInhibTempDevRepartitionTestFile is void" << endl;
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(0,i,-1.0);
			}
		}
			
		diffInhibTempDevRepartitionTestFile->addDataSeparator();
		
		for (int i=0;i<100;i++)
		{
			if (!inhibPreTempDevRepartitionTest[99-i][2].isVoid() && !inhibPreTempDevRepartitionTest[99-i][0].isVoid())
			{
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(1,-(99-i),(double) inhibPreTempDevRepartitionTest[99-i][2].getMean()-inhibPreTempDevRepartitionTest[99-i][0].getMean());
			}
			else
			{	
				//cout << "diffInhibTempDevRepartitionTestFile is void" << endl;
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(1,-(99-i),-1.0);
			}

		}
			
		for (int i=0;i<100;i++)
		{
			if (!inhibPostTempDevRepartitionTest[i][2].isVoid() && !inhibPostTempDevRepartitionTest[i][0].isVoid())
			{
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(1,i,(double) inhibPostTempDevRepartitionTest[i][2].getMean()-inhibPostTempDevRepartitionTest[i][0].getMean());
			}
			else
			{	
				//cout << "diffInhibTempDevRepartitionTestFile is void" << endl;
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(1,i,-1.0);
			}
		}
			
		diffInhibTempDevRepartitionTestFile->addDataSeparator();
		
		for (int i=0;i<100;i++)
		{
			if (!inhibPreTempDevRepartitionTest[99-i][3].isVoid() && !inhibPreTempDevRepartitionTest[99-i][0].isVoid())
			{
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(2,-(99-i),(double) inhibPreTempDevRepartitionTest[99-i][3].getMean()-inhibPreTempDevRepartitionTest[99-i][0].getMean());
			}
			else
			{	
				//cout << "diffInhibTempDevRepartitionTestFile is void" << endl;
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(2,-(99-i),-1.0);
			}
		}
			
		for (int i=0;i<100;i++)
		{
			if (!inhibPostTempDevRepartitionTest[i][3].isVoid() && !inhibPostTempDevRepartitionTest[i][0].isVoid())
			{
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(2,i,(double) inhibPostTempDevRepartitionTest[i][3].getMean()-inhibPostTempDevRepartitionTest[i][0].getMean());
			}
			else
			{	
				//cout << "diffInhibTempDevRepartitionTestFile is void" << endl;
				diffInhibTempDevRepartitionTestFile->addIndexedLineData(2,i,-1.0);
			}
		}
		
		diffInhibTempDevRepartitionTestFile->addDataSeparator();
						#endif
					#endif
	}
	else
	{
		cerr << "Warning, inhibTempDevRepartitionTestFile && diffInhibTempDevRepartitionTestFile should be inited" << endl;
	}
				#endif
			#endif	
		#endif

		#ifdef _PARAMETRIC_TEST_MODE
			#ifdef _PHASE_TEST_MODE
				#ifdef _CONDITIONAL_TEST_MODE
	if (ISIRepartitionTestFile->isOpen() && diffISIRepartitionTestFile->isOpen())
	{
		if (ISIRepartitionTest)
		{
			for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
			{
				for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
				{
					for (int i=0;i<100;i++)
					{
						if (!ISIRepartitionTest[i][j][k].isVoid())
						{
							ISIRepartitionTestFile->addIndexedLineData(j,i,(double) ISIRepartitionTest[i][j][k].getMean());
						}
						else
						{
							cout << "ISIRepartitionTestFile is void" << endl;
							ISIRepartitionTestFile->addIndexedLineData(j,i,-1.0);
						}
					}
					
					ISIRepartitionTestFile->addDataSeparator();
				}
			}
				
			for (int i=0;i<100;i++)
			{
				if (!ISIRepartitionTest[i][0][0].isVoid() && !ISIRepartitionTest[i][0][1].isVoid())
				{
					diffISIRepartitionTestFile->addIndexedLineData(0,i,(double) ISIRepartitionTest[i][0][0].getMean()-ISIRepartitionTest[i][0][1].getMean());
				}
				else
				{
					cout << "diffISIRepartitionTestFile is void" << endl;
					diffISIRepartitionTestFile->addIndexedLineData(0,i,-1.0);
				}
			}
				
			diffISIRepartitionTestFile->addDataSeparator();
			
			for (int i=0;i<100;i++)
			{
				if (!ISIRepartitionTest[i][1][0].isVoid() && !ISIRepartitionTest[i][1][1].isVoid())
				{
					diffISIRepartitionTestFile->addIndexedLineData(1,i,(double) ISIRepartitionTest[i][1][0].getMean()-ISIRepartitionTest[i][1][1].getMean());
				}
				else
				{
					cout << "diffISIRepartitionTestFile is void" << endl;
					diffISIRepartitionTestFile->addIndexedLineData(1,i,-1.0);
				}
			}
				
			diffISIRepartitionTestFile->addDataSeparator();
				
			for (int i=0;i<100;i++)
			{
				if (!ISIRepartitionTest[i][2][0].isVoid() && !ISIRepartitionTest[i][2][1].isVoid())
				{
					diffISIRepartitionTestFile->addIndexedLineData(2,i,(double) ISIRepartitionTest[i][2][0].getMean()-ISIRepartitionTest[i][2][1].getMean());
				}
				else
				{
					cout << "diffISIRepartitionTestFile is void" << endl;
					diffISIRepartitionTestFile->addIndexedLineData(2,i,-1.0);
				}
			}
				
			diffISIRepartitionTestFile->addDataSeparator();
					
			for (int i=0;i<100;i++)
			{
				if (!ISIRepartitionTest[i][3][0].isVoid() && !ISIRepartitionTest[i][3][1].isVoid())
				{
					diffISIRepartitionTestFile->addIndexedLineData(3,i,(double) ISIRepartitionTest[i][3][0].getMean()-ISIRepartitionTest[i][3][1].getMean());
				}
				else
				{
					cout << "diffISIRepartitionTestFile is void" << endl;
					diffISIRepartitionTestFile->addIndexedLineData(3,i,-1.0);
				}
			}
				
			diffISIRepartitionTestFile->addDataSeparator();

		}
	}
	else
	{
		cerr << "Warning, ISIRepartitionTestFile && diffISIRepartitionTestFile should be inited" << endl;
	}
				#else
					#ifdef _TRANSITION_STAT_MODE
	if (ISIRepartitionTestFile->isOpen() && diffISIRepartitionTestFile->isOpen())
	{
		if (ISIRepartitionTest)
		{
			for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
				{
					for (int i=0;i<100;i++)
					{
						if (!ISIRepartitionTest[i][j][k].isVoid())
						{
							if (j%2==0)
							{
								ISIRepartitionTestFile->addIndexedLineData(j,i,(double) ISIRepartitionTest[i][j][k].getAccu()/((double) TRANSITION_TIME_STEP*(k+1)));
							}
							else
							{
								ISIRepartitionTestFile->addIndexedLineData(j,i,(double) ISIRepartitionTest[i][j][k].getAccu()/((double) NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP*(k+1)));
							}
						}
						else
						{
							cout << "ISIRepartitionTestFile is void" << endl;
							ISIRepartitionTestFile->addIndexedLineData(j,i,-1.0);
						}
					}
					
					ISIRepartitionTestFile->addDataSeparator();
				}
			}
			
			for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
			{
				for (int i=0;i<100;i++)
				{
					if (!ISIRepartitionTest[i][1][k].isVoid() && !ISIRepartitionTest[i][0][k].isVoid())
					{
						diffISIRepartitionTestFile->addIndexedLineData(0,i,(double) ISIRepartitionTest[i][0][k].getAccu()/((double) TRANSITION_TIME_STEP*(k+1))-ISIRepartitionTest[i][1][k].getAccu()/((double) NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP*(k+1)));
					}
					else
					{
						cout << "diffISIRepartitionTestFile is void" << endl;
						diffISIRepartitionTestFile->addIndexedLineData(0,i,-1.0);
					}
				}
					
				diffISIRepartitionTestFile->addDataSeparator();
				
				for (int i=0;i<100;i++)
				{
					if (!ISIRepartitionTest[i][3][k].isVoid() && !ISIRepartitionTest[i][2][k].isVoid())
					{
						diffISIRepartitionTestFile->addIndexedLineData(1,i,(double) ISIRepartitionTest[i][2][k].getAccu()/((double) TRANSITION_TIME_STEP*(k+1))-ISIRepartitionTest[i][3][k].getAccu()/((double) NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP*(k+1)));
					}
					else
					{
						cout << "diffISIRepartitionTestFile is void" << endl;
						diffISIRepartitionTestFile->addIndexedLineData(1,i,-1.0);
					}
				}
					
				diffISIRepartitionTestFile->addDataSeparator();
				
				for (int i=0;i<100;i++)
				{
					if (!ISIRepartitionTest[i][5][k].isVoid() && !ISIRepartitionTest[i][4][k].isVoid())
					{
						diffISIRepartitionTestFile->addIndexedLineData(2,i,(double) ISIRepartitionTest[i][4][k].getAccu()/((double) TRANSITION_TIME_STEP*(k+1))-ISIRepartitionTest[i][5][k].getAccu()/((double) NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP*(k+1)));
					}
					else
					{
						cout << "diffISIRepartitionTestFile is void" << endl;
						diffISIRepartitionTestFile->addIndexedLineData(2,i,-1.0);
					}
				}
					
				diffISIRepartitionTestFile->addDataSeparator();	
				
				for (int i=0;i<100;i++)
				{
					if (!ISIRepartitionTest[i][7][k].isVoid() && !ISIRepartitionTest[i][6][k].isVoid())
					{
						diffISIRepartitionTestFile->addIndexedLineData(3,i,(double) ISIRepartitionTest[i][6][k].getAccu()/((double) TRANSITION_TIME_STEP*(k+1))-ISIRepartitionTest[i][7][k].getAccu()/((double) NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP*(k+1)));
					}
					else
					{
						cout << "diffISIRepartitionTestFile is void" << endl;
						diffISIRepartitionTestFile->addIndexedLineData(3,i,-1.0);
					}
				}
					
				diffISIRepartitionTestFile->addDataSeparator();	
			}
		}
	}
					#else
	if (diffISIRepartitionTestFile->isOpen())
	{
		if (ISIRepartitionTest)
		{
			for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
			{
				for (int i=0;i<100;i++)
				{
					if (!ISIRepartitionTest[i][0][k].isVoid() && !ISIRepartitionTest[i][1][k].isVoid())
					{
						diffISIRepartitionTestFile->addIndexedLineData(k,i,(double) (ISIRepartitionTest[i][1][k].getMean()-ISIRepartitionTest[i][0][k].getMean()));
					}
					else
					{
						cout << "diffISIRepartitionTestFile is void" << endl;
						diffISIRepartitionTestFile->addIndexedLineData(k,i,-1.0);
					}
				}

				diffISIRepartitionTestFile->addDataSeparator();
			}
		}
	}
	else
	{
		cerr << "Warning, diffISIRepartitionTestFile should be inited" << endl;
	}
	
	if (ISIRepartitionTestFile->isOpen())
	{
		if (ISIRepartitionTest)
		{
			for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
			{
				for (int i=0;i<100;i++)
				{
					if (!ISIRepartitionTest[i][1][k].isVoid())
					{
						ISIRepartitionTestFile->addIndexedLineData(k,i,(double) ISIRepartitionTest[i][1][k].getMean());
					}
					else
					{
						cout << "ISIRepartitionTestFile is void" << endl;
						ISIRepartitionTestFile->addIndexedLineData(k,i,-1.0);
					}
				}

				ISIRepartitionTestFile->addDataSeparator();
			}
		}
	}
	else
	{
		cerr << "Warning, ISIRepartitionTestFile should be inited" << endl;
	}
					#endif
				#endif
			#else
	if (ISIRepartitionTestFile->isOpen())
	{
		if (ISIRepartitionTest)
		{
			for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
			{
				for (int i=0;i<100;i++)
				{
					if (!ISIRepartitionTest[i][k].isVoid())
					{
						ISIRepartitionTestFile->addIndexedLineData(k,i,(double) ISIRepartitionTest[i][k].getMean());
					}
					else
					{
						cout << "ISIRepartitionTestFile is void" << endl;
						ISIRepartitionTestFile->addIndexedLineData(k,i,-1.0);
					}
				}

				ISIRepartitionTestFile->addDataSeparator();
			}
		}
	}
	else
	{
		cerr << "Warning, ISIRepartitionTestFile should be inited" << endl;
	}
			#endif
		#else
			#ifdef _PHASE_TEST_MODE
	if (ISIRepartitionTestFile->isOpen() && diffISIRepartitionTestFile->isOpen())
	{
		if (ISIRepartitionTest)
		{
				#ifdef _TRANSITION_STAT_MODE
			for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<100;i++)
				{
					if (!ISIRepartitionTest[i][j].isVoid())
					{
						if (j%2==0)
						{
							ISIRepartitionTestFile->addIndexedLineData(j,i,(double) ISIRepartitionTest[i][j].getAccu()/((double) TRANSITION_TIME_STEP));
						}
						else
						{
							ISIRepartitionTestFile->addIndexedLineData(j,i,ISIRepartitionTest[i][j].getAccu()/((double) NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP));
						}
					}
					else
					{
						cout << "ISIRepartitionTestFile is void" << endl;
						ISIRepartitionTestFile->addIndexedLineData(j,i,-1.0);
					}
				}
				
				ISIRepartitionTestFile->addDataSeparator();
			}
			
			for (int i=0;i<100;i++)
			{
				if (!ISIRepartitionTest[i][1].isVoid() && !ISIRepartitionTest[i][0].isVoid())
				{
					diffISIRepartitionTestFile->addIndexedLineData(0,i,(double) ISIRepartitionTest[i][0].getAccu()/((double) TRANSITION_TIME_STEP)-ISIRepartitionTest[i][1].getAccu()/((double) NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP));
				}
				else
				{
					cout << "diffISIRepartitionTestFile is void" << endl;
					diffISIRepartitionTestFile->addIndexedLineData(0,i,-1.0);
				}
			}
				
			diffISIRepartitionTestFile->addDataSeparator();
			
			for (int i=0;i<100;i++)
			{
				if (!ISIRepartitionTest[i][3].isVoid() && !ISIRepartitionTest[i][2].isVoid())
				{
					diffISIRepartitionTestFile->addIndexedLineData(1,i,(double) ISIRepartitionTest[i][2].getAccu()/((double) TRANSITION_TIME_STEP)-ISIRepartitionTest[i][3].getAccu()/((double) NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP));
				}
				else
				{
					cout << "diffISIRepartitionTestFile is void" << endl;
					diffISIRepartitionTestFile->addIndexedLineData(1,i,-1.0);
				}
			}
				
			diffISIRepartitionTestFile->addDataSeparator();
			
			for (int i=0;i<100;i++)
			{
				if (!ISIRepartitionTest[i][5].isVoid() && !ISIRepartitionTest[i][4].isVoid())
				{
					diffISIRepartitionTestFile->addIndexedLineData(2,i,(double) ISIRepartitionTest[i][4].getAccu()/((double) TRANSITION_TIME_STEP)-ISIRepartitionTest[i][5].getAccu()/((double) NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP));
				}
				else
				{
					cout << "diffISIRepartitionTestFile is void" << endl;
					diffISIRepartitionTestFile->addIndexedLineData(2,i,-1.0);
				}
			}
				
			diffISIRepartitionTestFile->addDataSeparator();	
			
			for (int i=0;i<100;i++)
			{
				if (!ISIRepartitionTest[i][7].isVoid() && !ISIRepartitionTest[i][6].isVoid())
				{
					diffISIRepartitionTestFile->addIndexedLineData(3,i,(double) ISIRepartitionTest[i][6].getAccu()/((double) TRANSITION_TIME_STEP)-ISIRepartitionTest[i][7].getAccu()/((double) NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP));
				}
				else
				{
					cout << "diffISIRepartitionTestFile is void" << endl;
					diffISIRepartitionTestFile->addIndexedLineData(3,i,-1.0);
				}
			}
				
			diffISIRepartitionTestFile->addDataSeparator();	
			
				#else
					#ifdef _REPETITIVE_TEST_MODE
			for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<100;i++)
				{
					if (!ISIRepartitionTest[i][j].isVoid())
					{
						ISIRepartitionTestFile->addIndexedLineData(j,i,(double) ISIRepartitionTest[i][j].getMean());
					}
					else
					{
						cout << "ISIRepartitionTestFile is void" << endl;
						ISIRepartitionTestFile->addIndexedLineData(j,i,-1.0);
					}
				}
				
				ISIRepartitionTestFile->addDataSeparator();
			}
			
			for (int i=0;i<100;i++)
			{
				if (!ISIRepartitionTest[i][2].isVoid() && !ISIRepartitionTest[i][0].isVoid())
				{
					diffISIRepartitionTestFile->addIndexedLineData(0,i,(double) ISIRepartitionTest[i][2].getMean()-ISIRepartitionTest[i][0].getMean());
				}
				else
				{
					cout << "diffISIRepartitionTestFile is void" << endl;
					diffISIRepartitionTestFile->addIndexedLineData(0,i,-1.0);
				}
			}
				
			diffISIRepartitionTestFile->addDataSeparator();
			
			for (int i=0;i<100;i++)
			{
				if (!ISIRepartitionTest[i][3].isVoid() && !ISIRepartitionTest[i][1].isVoid())
				{
					diffISIRepartitionTestFile->addIndexedLineData(1,i,(double) ISIRepartitionTest[i][3].getMean()-ISIRepartitionTest[i][1].getMean());
				}
				else
				{
					cout << "diffISIRepartitionTestFile is void" << endl;
					diffISIRepartitionTestFile->addIndexedLineData(1,i,-1.0);
				}
			}
				
			diffISIRepartitionTestFile->addDataSeparator();
			
					#else
			for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<100;i++)
				{
					if (!ISIRepartitionTest[i][j].isVoid())
					{
						ISIRepartitionTestFile->addIndexedLineData(j,i,(double) ISIRepartitionTest[i][j].getMean());
					}
					else
					{
						cout << "ISIRepartitionTestFile is void" << endl;
						ISIRepartitionTestFile->addIndexedLineData(j,i,-1.0);
					}
				}
				
				ISIRepartitionTestFile->addDataSeparator();
			}
			
			for (int i=0;i<100;i++)
			{
				if (!ISIRepartitionTest[i][1].isVoid() && !ISIRepartitionTest[i][0].isVoid())
				{
					diffISIRepartitionTestFile->addIndexedLineData(0,i,(double) ISIRepartitionTest[i][1].getMean()-ISIRepartitionTest[i][0].getMean());
				}
				else
				{
					cout << "diffISIRepartitionTestFile is void" << endl;
					diffISIRepartitionTestFile->addIndexedLineData(0,i,-1.0);
				}
			}
				
			diffISIRepartitionTestFile->addDataSeparator();
			
			for (int i=0;i<100;i++)
			{
				if (!ISIRepartitionTest[i][2].isVoid() && !ISIRepartitionTest[i][0].isVoid())
				{
					diffISIRepartitionTestFile->addIndexedLineData(1,i,(double) ISIRepartitionTest[i][2].getMean()-ISIRepartitionTest[i][0].getMean());
				}
				else
				{
					cout << "diffISIRepartitionTestFile is void" << endl;
					diffISIRepartitionTestFile->addIndexedLineData(1,i,-1.0);
				}
			}
				
			diffISIRepartitionTestFile->addDataSeparator();
			
			for (int i=0;i<100;i++)
			{
				if (!ISIRepartitionTest[i][3].isVoid() && !ISIRepartitionTest[i][0].isVoid())
				{
					diffISIRepartitionTestFile->addIndexedLineData(2,i,(double) ISIRepartitionTest[i][3].getMean()-ISIRepartitionTest[i][0].getMean());
				}
				else
				{
					cout << "diffISIRepartitionTestFile is void" << endl;
					diffISIRepartitionTestFile->addIndexedLineData(2,i,-1.0);
				}
			}
				
			diffISIRepartitionTestFile->addDataSeparator();	
					#endif
				#endif
		}
	}
	else
	{
		cerr << "Warning, ISIRepartitionTestFile && diffISIRepartitionTestFile should be inited" << endl;
	}
			#endif	
		#endif

		#ifdef _PARAMETRIC_TEST_MODE
			#ifdef _PHASE_TEST_MODE
	if (SpikeRepartitionTestFile->isOpen() && diffSpikeRepartitionTestFile->isOpen())
	{
		if (SpikeRepartitionTest)
		{
				#ifdef _TRANSITION_STAT_MODE
			for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
				{
					for (int i=0;i<NB_HIDDEN_NEURONS;i++)
					{
						if (!SpikeRepartitionTest[i][j][k].isVoid())
						{
							//SpikeRepartitionTestFile->addIndexedLineData(j,i,(double) SpikeRepartitionTest[i][j][k].getAccu());
							if (j%2==0)
							{
								SpikeRepartitionTestFile->addIndexedLineData(j,i,(double) SpikeRepartitionTest[i][j][k].getAccu()/((double) TRANSITION_TIME_STEP*(k+1)));
							}
							else
							{
								SpikeRepartitionTestFile->addIndexedLineData(j,i,(double) SpikeRepartitionTest[i][j][k].getAccu()/((double) NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP*(k+1)));
							}
						}
						else
						{
							//cout << "SpikeRepartitionTestFile is void" << endl;
							SpikeRepartitionTestFile->addIndexedLineData(j,i,-1.0);
						}
					}
					#ifndef _SORT_ASSEMBLY_STAT_MODE
					SpikeRepartitionTestFile->addDataSeparator();
					#endif
				}
			}
			
			for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
			{
				for (int i=0;i<NB_HIDDEN_NEURONS;i++)
				{
					if (!SpikeRepartitionTest[i][0][k].isVoid() && !SpikeRepartitionTest[i][1][k].isVoid())
					{
						//diffSpikeRepartitionTestFile->addIndexedLineData(0,i,(double) SpikeRepartitionTest[i][1][k].getAccu()-SpikeRepartitionTest[i][0][k].getAccu());
						diffSpikeRepartitionTestFile->addIndexedLineData(0,i,(double) SpikeRepartitionTest[i][0][k].getAccu()/((double) TRANSITION_TIME_STEP*(k+1))-SpikeRepartitionTest[i][1][k].getAccu()/((double) NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP*(k+1)));
					}
					else
					{	
						//cout << "diffSpikeRepartitionTestFile is void" << endl;
						diffSpikeRepartitionTestFile->addIndexedLineData(0,i,-1.0);
					}
				}
				
					#ifndef _SORT_ASSEMBLY_STAT_MODE	
				diffSpikeRepartitionTestFile->addDataSeparator();
					#endif
				
				for (int i=0;i<NB_HIDDEN_NEURONS;i++)
				{
					if (!SpikeRepartitionTest[i][3][k].isVoid() && !SpikeRepartitionTest[i][2][k].isVoid())
					{
						//diffSpikeRepartitionTestFile->addIndexedLineData(1,i,(double) SpikeRepartitionTest[i][2][k].getAccu()-SpikeRepartitionTest[i][0][k].getAccu());
						diffSpikeRepartitionTestFile->addIndexedLineData(1,i,(double) SpikeRepartitionTest[i][2][k].getAccu()/((double) TRANSITION_TIME_STEP*(k+1))-SpikeRepartitionTest[i][3][k].getAccu()/((double) NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP*(k+1)));
					}
					else
					{
						//cout << "diffSpikeRepartitionTestFile is void" << endl;
						diffSpikeRepartitionTestFile->addIndexedLineData(1,i,-1.0);
					}
				}
				
					#ifndef _SORT_ASSEMBLY_STAT_MODE	
				diffSpikeRepartitionTestFile->addDataSeparator();
					#endif
				
				for (int i=0;i<NB_HIDDEN_NEURONS;i++)
				{
					if (!SpikeRepartitionTest[i][5][k].isVoid() && !SpikeRepartitionTest[i][4][k].isVoid())
					{
						//diffSpikeRepartitionTestFile->addIndexedLineData(2,i,(double) SpikeRepartitionTest[i][3][k].getAccu()-SpikeRepartitionTest[i][0][k].getAccu());
						diffSpikeRepartitionTestFile->addIndexedLineData(2,i,(double) SpikeRepartitionTest[i][4][k].getAccu()/((double) TRANSITION_TIME_STEP*(k+1))-SpikeRepartitionTest[i][5][k].getAccu()/((double) NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP*(k+1)));
					}
					else
					{
						//cout << "diffSpikeRepartitionTestFile is void" << endl;
						diffSpikeRepartitionTestFile->addIndexedLineData(2,i,-1.0);
					}
				}
					#ifndef _SORT_ASSEMBLY_STAT_MODE		
				diffSpikeRepartitionTestFile->addDataSeparator();
					#endif	
				
				for (int i=0;i<NB_HIDDEN_NEURONS;i++)
				{
					if (!SpikeRepartitionTest[i][7][k].isVoid() && !SpikeRepartitionTest[i][6][k].isVoid())
					{
						//diffSpikeRepartitionTestFile->addIndexedLineData(2,i,(double) SpikeRepartitionTest[i][3][k].getAccu()-SpikeRepartitionTest[i][0][k].getAccu());
						diffSpikeRepartitionTestFile->addIndexedLineData(3,i,(double) SpikeRepartitionTest[i][6][k].getAccu()/((double) TRANSITION_TIME_STEP*(k+1))-SpikeRepartitionTest[i][7][k].getAccu()/((double) NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP*(k+1)));
					}
					else
					{
						//cout << "diffSpikeRepartitionTestFile is void" << endl;
						diffSpikeRepartitionTestFile->addIndexedLineData(3,i,-1.0);
					}
				}
					#ifndef _SORT_ASSEMBLY_STAT_MODE		
				diffSpikeRepartitionTestFile->addDataSeparator();
					#endif	
			}

				#else
			 
			for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
				{
					for (int i=0;i<NB_HIDDEN_NEURONS;i++)
					{
						if (!SpikeRepartitionTest[i][j][k].isVoid())
						{
							//SpikeRepartitionTestFile->addIndexedLineData(j,i,(double) SpikeRepartitionTest[i][j][k].getMean());
							SpikeRepartitionTestFile->addIndexedLineData(j,i,(double) SpikeRepartitionTest[i][j][k].getAccu());
						}
						else
						{
							//cout << "SpikeRepartitionTestFile is void" << endl;
							SpikeRepartitionTestFile->addIndexedLineData(j,i,-1.0);
						}
					}
					#ifndef _SORT_ASSEMBLY_STAT_MODE
					SpikeRepartitionTestFile->addDataSeparator();
					#endif
				}
			}
			
			for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
			{
				for (int i=0;i<NB_HIDDEN_NEURONS;i++)
				{
					if (!SpikeRepartitionTest[i][0][k].isVoid() && !SpikeRepartitionTest[i][1][k].isVoid())
					{
						//diffSpikeRepartitionTestFile->addIndexedLineData(0,i,(double) SpikeRepartitionTest[i][1][k].getMean()-SpikeRepartitionTest[i][0][k].getMean());
						diffSpikeRepartitionTestFile->addIndexedLineData(0,i,(double) SpikeRepartitionTest[i][1][k].getAccu()-SpikeRepartitionTest[i][0][k].getAccu());
					}
					else
					{	
						//cout << "diffSpikeRepartitionTestFile is void" << endl;
						diffSpikeRepartitionTestFile->addIndexedLineData(0,i,-1.0);
					}
				}
				
					#ifndef _SORT_ASSEMBLY_STAT_MODE	
				diffSpikeRepartitionTestFile->addDataSeparator();
					#endif
				
				for (int i=0;i<NB_HIDDEN_NEURONS;i++)
				{
					if (!SpikeRepartitionTest[i][0][k].isVoid() && !SpikeRepartitionTest[i][2][k].isVoid())
					{
						//diffSpikeRepartitionTestFile->addIndexedLineData(1,i,(double) SpikeRepartitionTest[i][2][k].getMean()-SpikeRepartitionTest[i][0][k].getMean());
						diffSpikeRepartitionTestFile->addIndexedLineData(1,i,(double) SpikeRepartitionTest[i][2][k].getAccu()-SpikeRepartitionTest[i][0][k].getAccu());
					}
					else
					{
						//cout << "diffSpikeRepartitionTestFile is void" << endl;
						diffSpikeRepartitionTestFile->addIndexedLineData(1,i,-1.0);
					}
				}
				
					#ifndef _SORT_ASSEMBLY_STAT_MODE	
				diffSpikeRepartitionTestFile->addDataSeparator();
					#endif
				
				for (int i=0;i<NB_HIDDEN_NEURONS;i++)
				{
					if (!SpikeRepartitionTest[i][0][k].isVoid() && !SpikeRepartitionTest[i][3][k].isVoid())
					{
						//diffSpikeRepartitionTestFile->addIndexedLineData(2,i,(double) SpikeRepartitionTest[i][3][k].getMean()-SpikeRepartitionTest[i][0][k].getMean());
						diffSpikeRepartitionTestFile->addIndexedLineData(2,i,(double) SpikeRepartitionTest[i][3][k].getAccu()-SpikeRepartitionTest[i][0][k].getAccu());
					}
					else
					{
						//cout << "diffSpikeRepartitionTestFile is void" << endl;
						diffSpikeRepartitionTestFile->addIndexedLineData(2,i,-1.0);
					}
				}
					#ifndef _SORT_ASSEMBLY_STAT_MODE		
				diffSpikeRepartitionTestFile->addDataSeparator();
					#endif	
			}
				#endif
		}
	}
	else
	{
		cerr << "Warning, SpikeRepartitionTestFile && diffSpikeRepartitionTestFile should be inited" << endl;
	}

	if (AssemblySpikeRepartitionTestFile->isOpen() && diffAssemblySpikeRepartitionTestFile->isOpen())
	{
		if (AssemblySpikeRepartitionTest)
		{
				#ifdef _TRANSITION_STAT_MODE
			for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
				{
					for (int i=0;i<NB_ASSEMBLIES;i++)
					{
						if (!AssemblySpikeRepartitionTest[i][j][k].isVoid())
						{
							
							if (j%2==0)
							{
								AssemblySpikeRepartitionTestFile->addIndexedLineData(j,i,(double) AssemblySpikeRepartitionTest[i][j][k].getAccu()/((double) TRANSITION_TIME_STEP*(k+1)));
							}
							else
							{
								AssemblySpikeRepartitionTestFile->addIndexedLineData(j,i,(double) AssemblySpikeRepartitionTest[i][j][k].getAccu()/((double) NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP*(k+1)));
							}
						}
						else
						{
							//cout << "AssemblySpikeRepartitionTestFile is void" << endl;
							AssemblySpikeRepartitionTestFile->addIndexedLineData(j,i,-1.0);
						}
					}
					#ifndef _SORT_ASSEMBLY_STAT_MODE	
					AssemblySpikeRepartitionTestFile->addDataSeparator();
					#endif
				}
			}
			
			for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
			{
				for (int i=0;i<NB_ASSEMBLIES;i++)
				{
					if (!AssemblySpikeRepartitionTest[i][1][k].isVoid() && !AssemblySpikeRepartitionTest[i][0][k].isVoid())
					{
						diffAssemblySpikeRepartitionTestFile->addIndexedLineData(0,i,(double) AssemblySpikeRepartitionTest[i][0][k].getAccu()/((double) TRANSITION_TIME_STEP*(k+1))-AssemblySpikeRepartitionTest[i][1][k].getAccu()/((double) NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP*(k+1)));
					}
					else
					{
						diffAssemblySpikeRepartitionTestFile->addIndexedLineData(0,i,-1.0);
					}
				}
					
					#ifndef _SORT_ASSEMBLY_STAT_MODE	
				diffAssemblySpikeRepartitionTestFile->addDataSeparator();
					#endif
				
				for (int i=0;i<NB_ASSEMBLIES;i++)
				{
					if (!AssemblySpikeRepartitionTest[i][3][k].isVoid() && !AssemblySpikeRepartitionTest[i][2][k].isVoid())
					{
						diffAssemblySpikeRepartitionTestFile->addIndexedLineData(1,i,(double) AssemblySpikeRepartitionTest[i][2][k].getAccu()/((double) TRANSITION_TIME_STEP*(k+1))-AssemblySpikeRepartitionTest[i][3][k].getAccu()/((double) NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP*(k+1)));
					}
					else
					{
						diffAssemblySpikeRepartitionTestFile->addIndexedLineData(1,i,-1.0);
					}
				}
					
					#ifndef _SORT_ASSEMBLY_STAT_MODE	
				diffAssemblySpikeRepartitionTestFile->addDataSeparator();
					#endif
				
				for (int i=0;i<NB_ASSEMBLIES;i++)
				{
					if (!AssemblySpikeRepartitionTest[i][5][k].isVoid() && !AssemblySpikeRepartitionTest[i][4][k].isVoid())
					{
						diffAssemblySpikeRepartitionTestFile->addIndexedLineData(2,i,(double) AssemblySpikeRepartitionTest[i][4][k].getAccu()/((double) TRANSITION_TIME_STEP*(k+1))-AssemblySpikeRepartitionTest[i][5][k].getAccu()/((double) NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP*(k+1)));
					}
					else
					{
						//cout << "diffAssemblySpikeRepartitionTestFile is void" << endl;
						diffAssemblySpikeRepartitionTestFile->addIndexedLineData(2,i,-1.0);
					}
				}
					
					#ifndef _SORT_ASSEMBLY_STAT_MODE	
				diffAssemblySpikeRepartitionTestFile->addDataSeparator();
					#endif	
				
				for (int i=0;i<NB_ASSEMBLIES;i++)
				{
					if (!AssemblySpikeRepartitionTest[i][7][k].isVoid() && !AssemblySpikeRepartitionTest[i][6][k].isVoid())
					{
						diffAssemblySpikeRepartitionTestFile->addIndexedLineData(3,i,(double) AssemblySpikeRepartitionTest[i][6][k].getAccu()/((double) TRANSITION_TIME_STEP*(k+1))-AssemblySpikeRepartitionTest[i][7][k].getAccu()/((double) NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP*(k+1)));
					}
					else
					{
						//cout << "diffAssemblySpikeRepartitionTestFile is void" << endl;
						diffAssemblySpikeRepartitionTestFile->addIndexedLineData(3,i,-1.0);
					}
				}
					
					#ifndef _SORT_ASSEMBLY_STAT_MODE	
				diffAssemblySpikeRepartitionTestFile->addDataSeparator();
					#endif	
			}
				#else
			for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
				{
					for (int i=0;i<NB_ASSEMBLIES;i++)
					{
						if (!AssemblySpikeRepartitionTest[i][j][k].isVoid())
						{
							//AssemblySpikeRepartitionTestFile->addIndexedLineData(j,i,(double) AssemblySpikeRepartitionTest[i][j][k].getMean());
							AssemblySpikeRepartitionTestFile->addIndexedLineData(j,i,(double) AssemblySpikeRepartitionTest[i][j][k].getAccu());
						}
						else
						{
							//cout << "AssemblySpikeRepartitionTestFile is void" << endl;
							AssemblySpikeRepartitionTestFile->addIndexedLineData(j,i,-1.0);
						}
					}
					#ifndef _SORT_ASSEMBLY_STAT_MODE	
					AssemblySpikeRepartitionTestFile->addDataSeparator();
					#endif
				}
			}
			
			for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
			{
				for (int i=0;i<NB_ASSEMBLIES;i++)
				{
					if (!AssemblySpikeRepartitionTest[i][0][k].isVoid() && !AssemblySpikeRepartitionTest[i][1][k].isVoid())
					{
						//diffAssemblySpikeRepartitionTestFile->addIndexedLineData(0,i,(double) AssemblySpikeRepartitionTest[i][1][k].getMean()-AssemblySpikeRepartitionTest[i][0][k].getMean());
						diffAssemblySpikeRepartitionTestFile->addIndexedLineData(0,i,(double) AssemblySpikeRepartitionTest[i][1][k].getAccu()-AssemblySpikeRepartitionTest[i][0][k].getAccu());
					}
					else
					{	
						//cout << "diffAssemblySpikeRepartitionTestFile is void" << endl;
						diffAssemblySpikeRepartitionTestFile->addIndexedLineData(0,i,-1.0);
					}
				}
					
					#ifndef _SORT_ASSEMBLY_STAT_MODE	
				diffAssemblySpikeRepartitionTestFile->addDataSeparator();
					#endif
				
				for (int i=0;i<NB_ASSEMBLIES;i++)
				{
					if (!AssemblySpikeRepartitionTest[i][0][k].isVoid() && !AssemblySpikeRepartitionTest[i][2][k].isVoid())
					{
						//diffAssemblySpikeRepartitionTestFile->addIndexedLineData(1,i,(double) AssemblySpikeRepartitionTest[i][2][k].getMean()-AssemblySpikeRepartitionTest[i][0][k].getMean());
						diffAssemblySpikeRepartitionTestFile->addIndexedLineData(1,i,(double) AssemblySpikeRepartitionTest[i][2][k].getAccu()-AssemblySpikeRepartitionTest[i][0][k].getAccu());
					}
					else
					{
						//cout << "diffAssemblySpikeRepartitionTestFile is void" << endl;
						diffAssemblySpikeRepartitionTestFile->addIndexedLineData(1,i,-1.0);
					}
				}
					
					#ifndef _SORT_ASSEMBLY_STAT_MODE	
				diffAssemblySpikeRepartitionTestFile->addDataSeparator();
					#endif
				
				for (int i=0;i<NB_ASSEMBLIES;i++)
				{
					if (!AssemblySpikeRepartitionTest[i][0][k].isVoid() && !AssemblySpikeRepartitionTest[i][3][k].isVoid())
					{
						//diffAssemblySpikeRepartitionTestFile->addIndexedLineData(2,i,(double) AssemblySpikeRepartitionTest[i][3][k].getMean()-AssemblySpikeRepartitionTest[i][0][k].getMean());
						diffAssemblySpikeRepartitionTestFile->addIndexedLineData(2,i,(double) AssemblySpikeRepartitionTest[i][3][k].getAccu()-AssemblySpikeRepartitionTest[i][0][k].getAccu());
					}
					else
					{
						//cout << "diffAssemblySpikeRepartitionTestFile is void" << endl;
						diffAssemblySpikeRepartitionTestFile->addIndexedLineData(2,i,-1.0);
					}
				}
					
					#ifndef _SORT_ASSEMBLY_STAT_MODE	
				diffAssemblySpikeRepartitionTestFile->addDataSeparator();
					#endif	
			}
				#endif
		}
	}
	else
	{
		cerr << "Warning, AssemblySpikeRepartitionTestFile && diffAssemblySpikeRepartitionTestFile should be inited" << endl;
	}
			#endif
		#else
			#ifdef _PHASE_TEST_MODE
	if (SpikeRepartitionTestFile->isOpen() && diffSpikeRepartitionTestFile->isOpen())
	{
		if (SpikeRepartitionTest)
		{
				#ifdef _TRANSITION_STAT_MODE
				
					#ifndef _SORT_ASSEMBLY_STAT_MODE
			for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<NB_HIDDEN_NEURONS;i++)
				{
					if (!SpikeRepartitionTest[i][j].isVoid())
					{
						//SpikeRepartitionTestFile->addIndexedLineData(j,i,(double) SpikeRepartitionTest[i][j].getAccu());
						if (j%2==0)
						{
							SpikeRepartitionTestFile->addIndexedLineData(j,i,(double) SpikeRepartitionTest[i][j].getAccu()/((double) TRANSITION_TIME_STEP));
						}
						else
						{
							SpikeRepartitionTestFile->addIndexedLineData(j,i,(double) SpikeRepartitionTest[i][j].getAccu()/((double) (NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP)));
						}
					}
					else
					{
						//cout << "SpikeRepartitionTestFile is void" << endl;
						SpikeRepartitionTestFile->addIndexedLineData(j,i,-1.0);
					}
				}
				SpikeRepartitionTestFile->addDataSeparator();
			}	
			
					#else
			
			for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<NB_HIDDEN_NEURONS;i++)
				{
					if (!SpikeRepartitionTest[i][j].isVoid())
					{
						//SpikeRepartitionTestFile->addIndexedLineData(j,i,(double) SpikeRepartitionTest[i][j].getAccu());
						if (j%2==0)
						{
							SpikeRepartitionTestFile->addIndexedLineData(j,i,(double) (NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP)*SpikeRepartitionTest[i][j].getAccu());
						}
						else
						{
							SpikeRepartitionTestFile->addIndexedLineData(j,i,(double) TRANSITION_TIME_STEP*SpikeRepartitionTest[i][j].getAccu());
						}
					}
					else
					{
						//cout << "SpikeRepartitionTestFile is void" << endl;
						SpikeRepartitionTestFile->addIndexedLineData(j,i,-1.0);
					}
				}
				SpikeRepartitionTestFile->addDataSeparator();
			}
					#endif
			
					#ifndef _SORT_ASSEMBLY_STAT_MODE
			for (int i=0;i<NB_HIDDEN_NEURONS;i++)
			{
				if (!SpikeRepartitionTest[i][0].isVoid() && !SpikeRepartitionTest[i][1].isVoid())
				{
					diffSpikeRepartitionTestFile->addIndexedLineData(0,i,(double) SpikeRepartitionTest[i][0].getAccu()/((double) TRANSITION_TIME_STEP)-SpikeRepartitionTest[i][1].getAccu()/((double) (NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP)));
				}
				else
				{	
					//cout << "diffSpikeRepartitionTestFile is void" << endl;
					diffSpikeRepartitionTestFile->addIndexedLineData(0,i,-1.0);
				}
			}
				
			diffSpikeRepartitionTestFile->addDataSeparator();
			
			for (int i=0;i<NB_HIDDEN_NEURONS;i++)
			{
				if (!SpikeRepartitionTest[i][3].isVoid() && !SpikeRepartitionTest[i][2].isVoid())
				{
					diffSpikeRepartitionTestFile->addIndexedLineData(1,i,(double) SpikeRepartitionTest[i][2].getAccu()/((double) TRANSITION_TIME_STEP)-SpikeRepartitionTest[i][3].getAccu()/((double) (NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP)));
				}
				else
				{
					//cout << "diffSpikeRepartitionTestFile is void" << endl;
					diffSpikeRepartitionTestFile->addIndexedLineData(1,i,-1.0);
				}
			}
				
			diffSpikeRepartitionTestFile->addDataSeparator();
			
			for (int i=0;i<NB_HIDDEN_NEURONS;i++)
			{
				if (!SpikeRepartitionTest[i][5].isVoid() && !SpikeRepartitionTest[i][4].isVoid())
				{
					diffSpikeRepartitionTestFile->addIndexedLineData(2,i,(double) SpikeRepartitionTest[i][4].getAccu()/((double) TRANSITION_TIME_STEP)-SpikeRepartitionTest[i][5].getAccu()/((double) (NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP)));
				}
				else
				{
					//cout << "diffSpikeRepartitionTestFile is void" << endl;
					diffSpikeRepartitionTestFile->addIndexedLineData(2,i,-1.0);
				}
			}		
			
			diffSpikeRepartitionTestFile->addDataSeparator();
			
			for (int i=0;i<NB_HIDDEN_NEURONS;i++)
			{
				if (!SpikeRepartitionTest[i][7].isVoid() && !SpikeRepartitionTest[i][6].isVoid())
				{
					diffSpikeRepartitionTestFile->addIndexedLineData(3,i,(double) SpikeRepartitionTest[i][6].getAccu()/((double) TRANSITION_TIME_STEP)-SpikeRepartitionTest[i][7].getAccu()/((double) (NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP)));
				}
				else
				{
					//cout << "diffSpikeRepartitionTestFile is void" << endl;
					diffSpikeRepartitionTestFile->addIndexedLineData(3,i,-1.0);
				}
			}		
			
			diffSpikeRepartitionTestFile->addDataSeparator();
					#else
			
			for (int i=0;i<NB_HIDDEN_NEURONS;i++)
			{
				if (!SpikeRepartitionTest[i][0].isVoid() && !SpikeRepartitionTest[i][1].isVoid())
				{
					diffSpikeRepartitionTestFile->addIndexedLineData(0,i,(double) (NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP)*SpikeRepartitionTest[i][0].getAccu()-TRANSITION_TIME_STEP*SpikeRepartitionTest[i][1].getAccu());
				}
				else
				{	
					//cout << "diffSpikeRepartitionTestFile is void" << endl;
					diffSpikeRepartitionTestFile->addIndexedLineData(0,i,-1.0);
				}
			}
				
			for (int i=0;i<NB_HIDDEN_NEURONS;i++)
			{
				if (!SpikeRepartitionTest[i][3].isVoid() && !SpikeRepartitionTest[i][2].isVoid())
				{
					diffSpikeRepartitionTestFile->addIndexedLineData(1,i,(double) (NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP)*SpikeRepartitionTest[i][2].getAccu()-TRANSITION_TIME_STEP*SpikeRepartitionTest[i][3].getAccu());
				}
				else
				{
					//cout << "diffSpikeRepartitionTestFile is void" << endl;
					diffSpikeRepartitionTestFile->addIndexedLineData(1,i,-1.0);
				}
			}
				
			for (int i=0;i<NB_HIDDEN_NEURONS;i++)
			{
				if (!SpikeRepartitionTest[i][5].isVoid() && !SpikeRepartitionTest[i][4].isVoid())
				{
					diffSpikeRepartitionTestFile->addIndexedLineData(2,i,(double) (NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP)*SpikeRepartitionTest[i][4].getAccu()-TRANSITION_TIME_STEP*SpikeRepartitionTest[i][5].getAccu());
				}
				else
				{
					//cout << "diffSpikeRepartitionTestFile is void" << endl;
					diffSpikeRepartitionTestFile->addIndexedLineData(2,i,-1.0);
				}
			}		
			for (int i=0;i<NB_HIDDEN_NEURONS;i++)
			{
				if (!SpikeRepartitionTest[i][7].isVoid() && !SpikeRepartitionTest[i][6].isVoid())
				{
					diffSpikeRepartitionTestFile->addIndexedLineData(3,i,(double) (NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP)*SpikeRepartitionTest[i][6].getAccu()-TRANSITION_TIME_STEP*SpikeRepartitionTest[i][7].getAccu());
				}
				else
				{
					//cout << "diffSpikeRepartitionTestFile is void" << endl;
					diffSpikeRepartitionTestFile->addIndexedLineData(3,i,-1.0);
				}
			}			
					#endif	
			
				#else
					#ifdef _REPETITIVE_TEST_MODE
			for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<NB_HIDDEN_NEURONS;i++)
				{
					if (!SpikeRepartitionTest[i][j].isVoid())
					{
						//SpikeRepartitionTestFile->addIndexedLineData(j,i,(double) SpikeRepartitionTest[i][j].getMean());
						SpikeRepartitionTestFile->addIndexedLineData(j,i,(double) SpikeRepartitionTest[i][j].getAccu());
					}
					else
					{
						//cout << "SpikeRepartitionTestFile is void" << endl;
						SpikeRepartitionTestFile->addIndexedLineData(j,i,-1.0);
					}
				}
						#ifndef _SORT_ASSEMBLY_STAT_MODE
				SpikeRepartitionTestFile->addDataSeparator();
						#endif
			}
			
			for (int i=0;i<NB_HIDDEN_NEURONS;i++)
			{
				if (!SpikeRepartitionTest[i][0].isVoid() && !SpikeRepartitionTest[i][2].isVoid())
				{
					//diffSpikeRepartitionTestFile->addIndexedLineData(0,i,(double) SpikeRepartitionTest[i][1].getMean()-SpikeRepartitionTest[i][0].getMean());
					diffSpikeRepartitionTestFile->addIndexedLineData(0,i,(double) SpikeRepartitionTest[i][2].getAccu()-SpikeRepartitionTest[i][0].getAccu());
				}
				else
				{	
					//cout << "diffSpikeRepartitionTestFile is void" << endl;
					diffSpikeRepartitionTestFile->addIndexedLineData(0,i,-1.0);
				}
			}
			
						#ifndef _SORT_ASSEMBLY_STAT_MODE	
			diffSpikeRepartitionTestFile->addDataSeparator();
						#endif
			
			for (int i=0;i<NB_HIDDEN_NEURONS;i++)
			{
				if (!SpikeRepartitionTest[i][1].isVoid() && !SpikeRepartitionTest[i][3].isVoid())
				{
					//diffSpikeRepartitionTestFile->addIndexedLineData(1,i,(double) SpikeRepartitionTest[i][2].getMean()-SpikeRepartitionTest[i][0].getMean());
					diffSpikeRepartitionTestFile->addIndexedLineData(1,i,(double) SpikeRepartitionTest[i][3].getAccu()-SpikeRepartitionTest[i][1].getAccu());
				}
				else
				{
					//cout << "diffSpikeRepartitionTestFile is void" << endl;
					diffSpikeRepartitionTestFile->addIndexedLineData(1,i,-1.0);
				}
			}
			
						#ifndef _SORT_ASSEMBLY_STAT_MODE	
			diffSpikeRepartitionTestFile->addDataSeparator();
						#endif
					#else
			for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<NB_HIDDEN_NEURONS;i++)
				{
					if (!SpikeRepartitionTest[i][j].isVoid())
					{
						//SpikeRepartitionTestFile->addIndexedLineData(j,i,(double) SpikeRepartitionTest[i][j].getMean());
						SpikeRepartitionTestFile->addIndexedLineData(j,i,(double) SpikeRepartitionTest[i][j].getAccu());
					}
					else
					{
						//cout << "SpikeRepartitionTestFile is void" << endl;
						SpikeRepartitionTestFile->addIndexedLineData(j,i,-1.0);
					}
				}
						#ifndef _SORT_ASSEMBLY_STAT_MODE
				SpikeRepartitionTestFile->addDataSeparator();
						#endif
			}
			
			for (int i=0;i<NB_HIDDEN_NEURONS;i++)
			{
				if (!SpikeRepartitionTest[i][0].isVoid() && !SpikeRepartitionTest[i][1].isVoid())
				{
					//diffSpikeRepartitionTestFile->addIndexedLineData(0,i,(double) SpikeRepartitionTest[i][1].getMean()-SpikeRepartitionTest[i][0].getMean());
					diffSpikeRepartitionTestFile->addIndexedLineData(0,i,(double) SpikeRepartitionTest[i][1].getAccu()-SpikeRepartitionTest[i][0].getAccu());
				}
				else
				{	
					//cout << "diffSpikeRepartitionTestFile is void" << endl;
					diffSpikeRepartitionTestFile->addIndexedLineData(0,i,-1.0);
				}
			}
			
						#ifndef _SORT_ASSEMBLY_STAT_MODE	
			diffSpikeRepartitionTestFile->addDataSeparator();
						#endif
			
			for (int i=0;i<NB_HIDDEN_NEURONS;i++)
			{
				if (!SpikeRepartitionTest[i][0].isVoid() && !SpikeRepartitionTest[i][2].isVoid())
				{
					//diffSpikeRepartitionTestFile->addIndexedLineData(1,i,(double) SpikeRepartitionTest[i][2].getMean()-SpikeRepartitionTest[i][0].getMean());
					diffSpikeRepartitionTestFile->addIndexedLineData(1,i,(double) SpikeRepartitionTest[i][2].getAccu()-SpikeRepartitionTest[i][0].getAccu());
				}
				else
				{
					//cout << "diffSpikeRepartitionTestFile is void" << endl;
					diffSpikeRepartitionTestFile->addIndexedLineData(1,i,-1.0);
				}
			}
			
						#ifndef _SORT_ASSEMBLY_STAT_MODE	
			diffSpikeRepartitionTestFile->addDataSeparator();
						#endif
			
			for (int i=0;i<NB_HIDDEN_NEURONS;i++)
			{
				if (!SpikeRepartitionTest[i][0].isVoid() && !SpikeRepartitionTest[i][3].isVoid())
				{
					//diffSpikeRepartitionTestFile->addIndexedLineData(2,i,(double) SpikeRepartitionTest[i][3].getMean()-SpikeRepartitionTest[i][0].getMean());
					diffSpikeRepartitionTestFile->addIndexedLineData(2,i,(double) SpikeRepartitionTest[i][3].getAccu()-SpikeRepartitionTest[i][0].getAccu());
				}
				else
				{
					//cout << "diffSpikeRepartitionTestFile is void" << endl;
					diffSpikeRepartitionTestFile->addIndexedLineData(2,i,-1.0);
				}
			}
						#ifndef _SORT_ASSEMBLY_STAT_MODE		
			diffSpikeRepartitionTestFile->addDataSeparator();
						#endif	
					#endif
				#endif
		}
	}
	else
	{
		cerr << "Warning, SpikeRepartitionTestFile && diffSpikeRepartitionTestFile should be inited" << endl;
	}
	
	if (AssemblySpikeRepartitionTestFile->isOpen() && diffAssemblySpikeRepartitionTestFile->isOpen())
	{
		if (AssemblySpikeRepartitionTest)
		{
				#ifdef _TRANSITION_STAT_MODE
				
					#ifndef _SORT_ASSEMBLY_STAT_MODE
			for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<NB_ASSEMBLIES;i++)
				{
					if (!AssemblySpikeRepartitionTest[i][j].isVoid())
					{
						
						if (j%2==0)
						{
							AssemblySpikeRepartitionTestFile->addIndexedLineData(j,i,(double) AssemblySpikeRepartitionTest[i][j].getAccu()/((double) TRANSITION_TIME_STEP));
						}
						else
						{
							AssemblySpikeRepartitionTestFile->addIndexedLineData(j,i,(double) AssemblySpikeRepartitionTest[i][j].getAccu()/((double) (NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP)));
						}
					}
					else
					{
						//cout << "AssemblySpikeRepartitionTestFile is void" << endl;
						AssemblySpikeRepartitionTestFile->addIndexedLineData(j,i,-1.0);
					}
				}	
				AssemblySpikeRepartitionTestFile->addDataSeparator();
			}
					#else
			for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<NB_ASSEMBLIES;i++)
				{
					if (!AssemblySpikeRepartitionTest[i][j].isVoid())
					{
						
						if (j%2==0)
						{
							AssemblySpikeRepartitionTestFile->addIndexedLineData(j,i,(double) (NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP)*AssemblySpikeRepartitionTest[i][j].getAccu());
						}
						else
						{
							AssemblySpikeRepartitionTestFile->addIndexedLineData(j,i,(double) TRANSITION_TIME_STEP*AssemblySpikeRepartitionTest[i][j].getAccu());
						}
					}
					else
					{
						//cout << "AssemblySpikeRepartitionTestFile is void" << endl;
						AssemblySpikeRepartitionTestFile->addIndexedLineData(j,i,-1.0);
					}
				}	
			}
					#endif
			
			//diffAssemblySpikeRepartitionTestFile->addIndexedLineData(0,i,(double) AssemblySpikeRepartitionTest[i][1].getAccu()-AssemblySpikeRepartitionTest[i][0].getAccu());
			//diffAssemblySpikeRepartitionTestFile->addIndexedLineData(1,i,(double) AssemblySpikeRepartitionTest[i][2].getAccu()-AssemblySpikeRepartitionTest[i][0].getAccu());
			//diffAssemblySpikeRepartitionTestFile->addIndexedLineData(2,i,(double) AssemblySpikeRepartitionTest[i][3].getAccu()-AssemblySpikeRepartitionTest[i][0].getAccu());
					
				
					#ifndef _SORT_ASSEMBLY_STAT_MODE
			for (int i=0;i<NB_ASSEMBLIES;i++)
			{
				if (!AssemblySpikeRepartitionTest[i][1].isVoid() && !AssemblySpikeRepartitionTest[i][0].isVoid())
				{
					diffAssemblySpikeRepartitionTestFile->addIndexedLineData(0,i,(double) AssemblySpikeRepartitionTest[i][0].getAccu()/((double) TRANSITION_TIME_STEP)-AssemblySpikeRepartitionTest[i][1].getAccu()/((double) (NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP)));
				}
				else
				{	
					//cout << "diffAssemblySpikeRepartitionTestFile is void" << endl;
					diffAssemblySpikeRepartitionTestFile->addIndexedLineData(0,i,-1.0);
				}
			}
					
			diffAssemblySpikeRepartitionTestFile->addDataSeparator();
			
			for (int i=0;i<NB_ASSEMBLIES;i++)
			{
				if (!AssemblySpikeRepartitionTest[i][3].isVoid() && !AssemblySpikeRepartitionTest[i][2].isVoid())
				{
					diffAssemblySpikeRepartitionTestFile->addIndexedLineData(1,i,(double) AssemblySpikeRepartitionTest[i][2].getAccu()/((double) TRANSITION_TIME_STEP)-AssemblySpikeRepartitionTest[i][3].getAccu()/((double) (NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP)));
				}
				else
				{
					//cout << "diffAssemblySpikeRepartitionTestFile is void" << endl;
					diffAssemblySpikeRepartitionTestFile->addIndexedLineData(1,i,-1.0);
				}
			}
				
			diffAssemblySpikeRepartitionTestFile->addDataSeparator();
			
			for (int i=0;i<NB_ASSEMBLIES;i++)
			{
				if (!AssemblySpikeRepartitionTest[i][5].isVoid() && !AssemblySpikeRepartitionTest[i][4].isVoid())
				{
					diffAssemblySpikeRepartitionTestFile->addIndexedLineData(2,i,(double) AssemblySpikeRepartitionTest[i][4].getAccu()/((double) TRANSITION_TIME_STEP)-AssemblySpikeRepartitionTest[i][5].getAccu()/((double) (NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP)));
				}
				else
				{
					//cout << "diffAssemblySpikeRepartitionTestFile is void" << endl;
					diffAssemblySpikeRepartitionTestFile->addIndexedLineData(2,i,-1.0);
				}
			}
				
			diffAssemblySpikeRepartitionTestFile->addDataSeparator();
			
			for (int i=0;i<NB_ASSEMBLIES;i++)
			{
				if (!AssemblySpikeRepartitionTest[i][7].isVoid() && !AssemblySpikeRepartitionTest[i][6].isVoid())
				{
					diffAssemblySpikeRepartitionTestFile->addIndexedLineData(3,i,(double) AssemblySpikeRepartitionTest[i][6].getAccu()/((double) TRANSITION_TIME_STEP)-AssemblySpikeRepartitionTest[i][7].getAccu()/((double) (NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP)));
				}
				else
				{
					//cout << "diffAssemblySpikeRepartitionTestFile is void" << endl;
					diffAssemblySpikeRepartitionTestFile->addIndexedLineData(3,i,-1.0);
				}
			}
				
			diffAssemblySpikeRepartitionTestFile->addDataSeparator();
					#else
			for (int i=0;i<NB_ASSEMBLIES;i++)
			{
				if (!AssemblySpikeRepartitionTest[i][1].isVoid() && !AssemblySpikeRepartitionTest[i][0].isVoid())
				{
					diffAssemblySpikeRepartitionTestFile->addIndexedLineData(0,i,(double) (NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP)*AssemblySpikeRepartitionTest[i][0].getAccu()-TRANSITION_TIME_STEP*AssemblySpikeRepartitionTest[i][1].getAccu());
				}
				else
				{	
					//cout << "diffAssemblySpikeRepartitionTestFile is void" << endl;
					diffAssemblySpikeRepartitionTestFile->addIndexedLineData(0,i,-1.0);
				}
			}
					
			for (int i=0;i<NB_ASSEMBLIES;i++)
			{
				if (!AssemblySpikeRepartitionTest[i][3].isVoid() && !AssemblySpikeRepartitionTest[i][2].isVoid())
				{
					diffAssemblySpikeRepartitionTestFile->addIndexedLineData(1,i,(double) (NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP)*AssemblySpikeRepartitionTest[i][2].getAccu()-TRANSITION_TIME_STEP*AssemblySpikeRepartitionTest[i][3].getAccu());
				}
				else
				{
					//cout << "diffAssemblySpikeRepartitionTestFile is void" << endl;
					diffAssemblySpikeRepartitionTestFile->addIndexedLineData(1,i,-1.0);
				}
			}
				
			for (int i=0;i<NB_ASSEMBLIES;i++)
			{
				if (!AssemblySpikeRepartitionTest[i][5].isVoid() && !AssemblySpikeRepartitionTest[i][4].isVoid())
				{
					diffAssemblySpikeRepartitionTestFile->addIndexedLineData(2,i,(double) (NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP)*AssemblySpikeRepartitionTest[i][4].getAccu()-TRANSITION_TIME_STEP*AssemblySpikeRepartitionTest[i][5].getAccu());
				}
				else
				{
					//cout << "diffAssemblySpikeRepartitionTestFile is void" << endl;
					diffAssemblySpikeRepartitionTestFile->addIndexedLineData(2,i,-1.0);
				}
			}
			
			for (int i=0;i<NB_ASSEMBLIES;i++)
			{
				if (!AssemblySpikeRepartitionTest[i][7].isVoid() && !AssemblySpikeRepartitionTest[i][6].isVoid())
				{
					diffAssemblySpikeRepartitionTestFile->addIndexedLineData(3,i,(double) (NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP)*AssemblySpikeRepartitionTest[i][6].getAccu()-TRANSITION_TIME_STEP*AssemblySpikeRepartitionTest[i][7].getAccu());
				}
				else
				{
					//cout << "diffAssemblySpikeRepartitionTestFile is void" << endl;
					diffAssemblySpikeRepartitionTestFile->addIndexedLineData(3,i,-1.0);
				}
			}	
					#endif	
				#else
					#ifdef _REPETITIVE_TEST_MODE
			for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<NB_ASSEMBLIES;i++)
				{
					if (!AssemblySpikeRepartitionTest[i][j].isVoid())
					{
						//AssemblySpikeRepartitionTestFile->addIndexedLineData(j,i,(double) AssemblySpikeRepartitionTest[i][j].getMean());
						AssemblySpikeRepartitionTestFile->addIndexedLineData(j,i,(double) AssemblySpikeRepartitionTest[i][j].getAccu());
					}
					else
					{
						//cout << "AssemblySpikeRepartitionTestFile is void" << endl;
						AssemblySpikeRepartitionTestFile->addIndexedLineData(j,i,-1.0);
					}
				}
						#ifndef _SORT_ASSEMBLY_STAT_MODE	
				AssemblySpikeRepartitionTestFile->addDataSeparator();
						#endif
			}
			
			for (int i=0;i<NB_ASSEMBLIES;i++)
			{
				if (!AssemblySpikeRepartitionTest[i][0].isVoid() && !AssemblySpikeRepartitionTest[i][2].isVoid())
				{
					//diffAssemblySpikeRepartitionTestFile->addIndexedLineData(0,i,(double) AssemblySpikeRepartitionTest[i][1].getMean()-AssemblySpikeRepartitionTest[i][0].getMean());
					diffAssemblySpikeRepartitionTestFile->addIndexedLineData(0,i,(double) AssemblySpikeRepartitionTest[i][2].getAccu()-AssemblySpikeRepartitionTest[i][0].getAccu());
				}
				else
				{	
					//cout << "diffAssemblySpikeRepartitionTestFile is void" << endl;
					diffAssemblySpikeRepartitionTestFile->addIndexedLineData(0,i,-1.0);
				}
			}
				
						#ifndef _SORT_ASSEMBLY_STAT_MODE	
			diffAssemblySpikeRepartitionTestFile->addDataSeparator();
						#endif
				
			for (int i=0;i<NB_ASSEMBLIES;i++)
			{
				if (!AssemblySpikeRepartitionTest[i][1].isVoid() && !AssemblySpikeRepartitionTest[i][3].isVoid())
				{
					//diffAssemblySpikeRepartitionTestFile->addIndexedLineData(1,i,(double) AssemblySpikeRepartitionTest[i][2].getMean()-AssemblySpikeRepartitionTest[i][0].getMean());
					diffAssemblySpikeRepartitionTestFile->addIndexedLineData(1,i,(double) AssemblySpikeRepartitionTest[i][3].getAccu()-AssemblySpikeRepartitionTest[i][1].getAccu());
				}
				else
				{
					//cout << "diffAssemblySpikeRepartitionTestFile is void" << endl;
					diffAssemblySpikeRepartitionTestFile->addIndexedLineData(1,i,-1.0);
				}
			}
				
						#ifndef _SORT_ASSEMBLY_STAT_MODE	
			diffAssemblySpikeRepartitionTestFile->addDataSeparator();
						#endif

					#else
			for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<NB_ASSEMBLIES;i++)
				{
					if (!AssemblySpikeRepartitionTest[i][j].isVoid())
					{
						//AssemblySpikeRepartitionTestFile->addIndexedLineData(j,i,(double) AssemblySpikeRepartitionTest[i][j].getMean());
						AssemblySpikeRepartitionTestFile->addIndexedLineData(j,i,(double) AssemblySpikeRepartitionTest[i][j].getAccu());
					}
					else
					{
						//cout << "AssemblySpikeRepartitionTestFile is void" << endl;
						AssemblySpikeRepartitionTestFile->addIndexedLineData(j,i,-1.0);
					}
				}
						#ifndef _SORT_ASSEMBLY_STAT_MODE	
				AssemblySpikeRepartitionTestFile->addDataSeparator();
						#endif
			}
			
			for (int i=0;i<NB_ASSEMBLIES;i++)
			{
				if (!AssemblySpikeRepartitionTest[i][0].isVoid() && !AssemblySpikeRepartitionTest[i][1].isVoid())
				{
					//diffAssemblySpikeRepartitionTestFile->addIndexedLineData(0,i,(double) AssemblySpikeRepartitionTest[i][1].getMean()-AssemblySpikeRepartitionTest[i][0].getMean());
					diffAssemblySpikeRepartitionTestFile->addIndexedLineData(0,i,(double) AssemblySpikeRepartitionTest[i][1].getAccu()-AssemblySpikeRepartitionTest[i][0].getAccu());
				}
				else
				{	
					//cout << "diffAssemblySpikeRepartitionTestFile is void" << endl;
					diffAssemblySpikeRepartitionTestFile->addIndexedLineData(0,i,-1.0);
				}
			}
				
						#ifndef _SORT_ASSEMBLY_STAT_MODE	
			diffAssemblySpikeRepartitionTestFile->addDataSeparator();
						#endif
			
			for (int i=0;i<NB_ASSEMBLIES;i++)
			{
				if (!AssemblySpikeRepartitionTest[i][0].isVoid() && !AssemblySpikeRepartitionTest[i][2].isVoid())
				{
					//diffAssemblySpikeRepartitionTestFile->addIndexedLineData(1,i,(double) AssemblySpikeRepartitionTest[i][2].getMean()-AssemblySpikeRepartitionTest[i][0].getMean());
					diffAssemblySpikeRepartitionTestFile->addIndexedLineData(1,i,(double) AssemblySpikeRepartitionTest[i][2].getAccu()-AssemblySpikeRepartitionTest[i][0].getAccu());
				}
				else
				{
					//cout << "diffAssemblySpikeRepartitionTestFile is void" << endl;
					diffAssemblySpikeRepartitionTestFile->addIndexedLineData(1,i,-1.0);
				}
			}
				
						#ifndef _SORT_ASSEMBLY_STAT_MODE	
			diffAssemblySpikeRepartitionTestFile->addDataSeparator();
						#endif
			
			for (int i=0;i<NB_ASSEMBLIES;i++)
			{
				if (!AssemblySpikeRepartitionTest[i][0].isVoid() && !AssemblySpikeRepartitionTest[i][3].isVoid())
				{
					//diffAssemblySpikeRepartitionTestFile->addIndexedLineData(2,i,(double) AssemblySpikeRepartitionTest[i][3].getMean()-AssemblySpikeRepartitionTest[i][0].getMean());
					diffAssemblySpikeRepartitionTestFile->addIndexedLineData(2,i,(double) AssemblySpikeRepartitionTest[i][3].getAccu()-AssemblySpikeRepartitionTest[i][0].getAccu());
				}
				else
				{
					//cout << "diffAssemblySpikeRepartitionTestFile is void" << endl;
					diffAssemblySpikeRepartitionTestFile->addIndexedLineData(2,i,-1.0);
				}
			}
				
						#ifndef _SORT_ASSEMBLY_STAT_MODE	
			diffAssemblySpikeRepartitionTestFile->addDataSeparator();
						#endif	
					#endif
				#endif
		}
	}
	else
	{
		cerr << "Warning, AssemblySpikeRepartitionTestFile && diffAssemblySpikeRepartitionTestFile should be inited" << endl;
	}
			#endif	
		#endif
}

void ActivityTester::initAccumulaters()
{
		#ifdef _PARAMETRIC_TEST_MODE
			#ifdef _PHASE_TEST_MODE
	if (timeFrequencyTest)
	{
		for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
		{
				#ifdef _TRANSITION_STAT_MODE
			for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<NB_FREQUENCY_BINS;i++)
				{
					timeFrequencyTest[i][j][k].initAccu();
				}
			}
				#else
			for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<NB_FREQUENCY_BINS;i++)
				{
					timeFrequencyTest[i][j][k].initAccu();
				}
			}
				#endif
		}
	}
	else
	{
		cerr << "Warning, timeFrequencyTest should be inited" << endl;
	}

	if (highTimeFrequencyTest)
	{
		for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
		{
				#ifdef _TRANSITION_STAT_MODE
			for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
				{
					highTimeFrequencyTest[i][j][k].initAccu();
				}
			}
				#else
			for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
				{
					highTimeFrequencyTest[i][j][k].initAccu();
				}
			}
				#endif
		}
	}
	else
	{
		cerr << "Warning, highTimeFrequencyTest should be inited" << endl;
	}
	
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	if (excitPreTempDevRepartitionTest)
	{
		for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
		{
					#ifdef _TRANSITION_STAT_MODE
			for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<100;i++)
				{
					excitPreTempDevRepartitionTest[i][j][k].initAccu();
				}
			}
					#else
			for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<100;i++)
				{
					excitPreTempDevRepartitionTest[i][j][k].initAccu();
				}
			}
					#endif
			
		}
	}
	else
	{
		cerr << "Warning, highTimeFrequencyTest should be inited" << endl;
	}
	
	if (excitPostTempDevRepartitionTest)
	{
		for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
		{
					#ifdef _TRANSITION_STAT_MODE
			for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<100;i++)
				{
					excitPostTempDevRepartitionTest[i][j][k].initAccu();
				}
			}
					#else
			for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<100;i++)
				{
					excitPostTempDevRepartitionTest[i][j][k].initAccu();
				}
			}
					#endif
			
		}
	}
	else
	{
		cerr << "Warning, highTimeFrequencyTest should be inited" << endl;
	}
	
	if (inhibPreTempDevRepartitionTest)
	{
		for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
		{
					#ifdef _TRANSITION_STAT_MODE
			for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<100;i++)
				{
					inhibPreTempDevRepartitionTest[i][j][k].initAccu();
				}
			}
					#else
			for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<100;i++)
				{
					inhibPreTempDevRepartitionTest[i][j][k].initAccu();
				}
			}
					#endif
			
		}
	}
	else
	{
		cerr << "Warning, inhibPreTempDevRepartitionTest should be inited" << endl;
	}
	
	if (inhibPostTempDevRepartitionTest)
	{
		for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
		{
					#ifdef _TRANSITION_STAT_MODE
			for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<100;i++)
				{
					inhibPostTempDevRepartitionTest[i][j][k].initAccu();
				}
			}
					#else
			for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<100;i++)
				{
					inhibPostTempDevRepartitionTest[i][j][k].initAccu();
				}
			}
					#endif
			
		}
	}
	else
	{
		cerr << "Warning, inhibPostTempDevRepartitionTest should be inited" << endl;
	}
				#endif
				
	if (ISIRepartitionTest)
	{
		for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
		{
				#ifdef _TRANSITION_STAT_MODE
			for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<100;i++)
				{
					ISIRepartitionTest[i][j][k].initAccu();
				}
			}
				#else
			for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<100;i++)
				{
					ISIRepartitionTest[i][j][k].initAccu();
				}
			}
				#endif
			
		}
	}
	else
	{
		cerr << "Warning, ISIRepartitionTest should be inited" << endl;
	}
	
	if (SpikeRepartitionTest)
	{
		for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
		{
				#ifdef _TRANSITION_STAT_MODE
			for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<NB_HIDDEN_NEURONS;i++)
				{
					SpikeRepartitionTest[i][j][k].initAccu();
				}
			}
				#else
			for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<NB_HIDDEN_NEURONS;i++)
				{
					SpikeRepartitionTest[i][j][k].initAccu();
				}
			}
				#endif
			
		}
	}
	else
	{
		cerr << "Warning, SpikeRepartitionTest should be inited" << endl;
	}
	
	
	if (AssemblySpikeRepartitionTest)
	{
		for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
		{
				#ifdef _TRANSITION_STAT_MODE
			for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<NB_ASSEMBLIES;i++)
				{
					AssemblySpikeRepartitionTest[i][j][k].initAccu();
				}
			}
				#else
			for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<NB_ASSEMBLIES;i++)
				{
					AssemblySpikeRepartitionTest[i][j][k].initAccu();
				}
			}
				#endif
			
		}
	}
	else
	{
		cerr << "Warning, AssemblySpikeRepartitionTest should be inited" << endl;
	}
	
			#else
	if (timeFrequencyTest)
	{
		for (int j=0;j<NB_PARAMETRIC_TESTS;j++)
		{
			for (int i=0;i<NB_FREQUENCY_BINS;i++)
			{
				timeFrequencyTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, timeFrequencyTest should be inited" << endl;
	}

	if (highTimeFrequencyTest)
	{
		for (int j=0;j<NB_PARAMETRIC_TESTS;j++)
		{
			for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
			{
				highTimeFrequencyTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, highTimeFrequencyTest should be inited" << endl;
	}
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	if (excitPreTempDevRepartitionTest)
	{
		for (int j=0;j<NB_PARAMETRIC_TESTS;j++)
		{
			for (int i=0;i<100;i++)
			{
				excitPreTempDevRepartitionTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, excitPreTempDevRepartitionTest should be inited" << endl;
	}
	
	if (excitPostTempDevRepartitionTest)
	{
		for (int j=0;j<NB_PARAMETRIC_TESTS;j++)
		{
			for (int i=0;i<100;i++)
			{
				excitPostTempDevRepartitionTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, excitPostTempDevRepartitionTest should be inited" << endl;
	}
	
	if (inhibPreTempDevRepartitionTest)
	{
		for (int j=0;j<NB_PARAMETRIC_TESTS;j++)
		{
			for (int i=0;i<100;i++)
			{
				inhibPreTempDevRepartitionTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, inhibPreTempDevRepartitionTest should be inited" << endl;
	}
	
	if (inhibPostTempDevRepartitionTest)
	{
		for (int j=0;j<NB_PARAMETRIC_TESTS;j++)
		{
			for (int i=0;i<100;i++)
			{
				inhibPostTempDevRepartitionTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, inhibPostTempDevRepartitionTest should be inited" << endl;
	}
				#endif
				
	if (ISIRepartitionTest)
	{
		for (int j=0;j<NB_PARAMETRIC_TESTS;j++)
		{
			for (int i=0;i<100;i++)
			{
				ISIRepartitionTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, inhibPostTempDevRepartitionTest should be inited" << endl;
	}
		
	if (SpikeRepartitionTest)
	{
		for (int j=0;j<NB_PARAMETRIC_TESTS;j++)
		{
			for (int i=0;i<NB_HIDDEN_NEURONS;i++)
			{
				SpikeRepartitionTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, SpikeRepartitionTest should be inited" << endl;
	}
	
	
	if (AssemblySpikeRepartitionTest)
	{
		for (int j=0;j<NB_PARAMETRIC_TESTS;j++)
		{
			for (int i=0;i<NB_ASSEMBLIES;i++)
			{
				AssemblySpikeRepartitionTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, AssemblySpikeRepartitionTest should be inited" << endl;
	}
			#endif
		#else
			#ifdef _PHASE_TEST_MODE
				#ifdef _TRANSITION_STAT_MODE
	if (timeFrequencyTest)
	{
		for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			for (int i=0;i<NB_FREQUENCY_BINS;i++)
			{
				timeFrequencyTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, timeFrequencyTest should be inited" << endl;
	}

	if (highTimeFrequencyTest)
	{
		for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
			{
				highTimeFrequencyTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, highTimeFrequencyTest should be inited" << endl;
	}
					#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	if (excitPreTempDevRepartitionTest)
	{
		for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			for (int i=0;i<100;i++)
			{
				excitPreTempDevRepartitionTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, highTimeFrequencyTest should be inited" << endl;
	}
	
	if (excitPostTempDevRepartitionTest)
	{
		for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			for (int i=0;i<100;i++)
			{
				excitPostTempDevRepartitionTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, highTimeFrequencyTest should be inited" << endl;
	}
	
	if (inhibPreTempDevRepartitionTest)
	{
		for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			for (int i=0;i<100;i++)
			{
				inhibPreTempDevRepartitionTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, inhibPreTempDevRepartitionTest should be inited" << endl;
	}
	
	if (inhibPostTempDevRepartitionTest)
	{
		for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			for (int i=0;i<100;i++)
			{
				inhibPostTempDevRepartitionTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, inhibPostTempDevRepartitionTest should be inited" << endl;
	}
					#endif
					
	if (ISIRepartitionTest)
	{
		for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			for (int i=0;i<100;i++)
			{
				ISIRepartitionTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, ISIRepartitionTest should be inited" << endl;
	}
	
	
	if (SpikeRepartitionTest)
	{
		for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			for (int i=0;i<NB_HIDDEN_NEURONS;i++)
			{
				SpikeRepartitionTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, SpikeRepartitionTest should be inited" << endl;
	}
	
	
	if (AssemblySpikeRepartitionTest)
	{
		for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			for (int i=0;i<NB_ASSEMBLIES;i++)
			{
				AssemblySpikeRepartitionTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, AssemblySpikeRepartitionTest should be inited" << endl;
	}
				#else
	if (timeFrequencyTest)
	{
		for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			for (int i=0;i<NB_FREQUENCY_BINS;i++)
			{
				timeFrequencyTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, timeFrequencyTest should be inited" << endl;
	}

	if (highTimeFrequencyTest)
	{
		for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
			{
				highTimeFrequencyTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, highTimeFrequencyTest should be inited" << endl;
	}
					#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	if (excitPreTempDevRepartitionTest)
	{
		for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			for (int i=0;i<100;i++)
			{
				excitPreTempDevRepartitionTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, highTimeFrequencyTest should be inited" << endl;
	}
	
	if (excitPostTempDevRepartitionTest)
	{
		for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			for (int i=0;i<100;i++)
			{
				excitPostTempDevRepartitionTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, highTimeFrequencyTest should be inited" << endl;
	}
	
	if (inhibPreTempDevRepartitionTest)
	{
		for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			for (int i=0;i<100;i++)
			{
				inhibPreTempDevRepartitionTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, inhibPreTempDevRepartitionTest should be inited" << endl;
	}
	
	if (inhibPostTempDevRepartitionTest)
	{
		for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			for (int i=0;i<100;i++)
			{
				inhibPostTempDevRepartitionTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, inhibPostTempDevRepartitionTest should be inited" << endl;
	}
					#endif
					
	if (ISIRepartitionTest)
	{
		for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			for (int i=0;i<100;i++)
			{
				ISIRepartitionTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, ISIRepartitionTest should be inited" << endl;
	}
	
	
	if (SpikeRepartitionTest)
	{
		for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			for (int i=0;i<NB_HIDDEN_NEURONS;i++)
			{
				SpikeRepartitionTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, SpikeRepartitionTest should be inited" << endl;
	}
	
	
	if (AssemblySpikeRepartitionTest)
	{
		for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			for (int i=0;i<NB_ASSEMBLIES;i++)
			{
				AssemblySpikeRepartitionTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, AssemblySpikeRepartitionTest should be inited" << endl;
	}
				#endif
			#endif
		#endif
}

		#ifdef _PARAMETRIC_TEST_MODE
void ActivityTester::stat(int paramIndex)
{
			#ifdef _PHASE_TEST_MODE
	if (timeFrequencyTest)
	{
		for (int i=0;i<NB_FREQUENCY_BINS;i++)
		{
			if (!meanTimeFrequency[i].isVoid())
			{
				timeFrequencyTest[i][getEvalIndex()][paramIndex].accumulate((double) meanTimeFrequency[i].getMean());
				meanTimeFrequency[i].initAccu();
			}
			else
			{
				timeFrequencyTest[i][getEvalIndex()][paramIndex].setVoid();
				meanTimeFrequency[i].freeVoid();
			}
		}
	}
	else
	{
		cerr << "Warning, timeFrequencyTest should be inited" << endl;
	}

	if (highTimeFrequencyTest)
	{
		for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
		{
			if (!meanHighTimeFrequency[i].isVoid())
			{
				highTimeFrequencyTest[i][getEvalIndex()][paramIndex].accumulate((double) meanHighTimeFrequency[i].getMean());
				meanHighTimeFrequency[i].initAccu();
			}
			else
			{
				highTimeFrequencyTest[i][getEvalIndex()][paramIndex].setVoid();
				meanHighTimeFrequency[i].freeVoid();
			}
		}
	}
	else
	{
		cerr << "Warning, highTimeFrequencyTest should be inited" << endl;
	}
	
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	if (excitPreTempDevRepartitionTest)
	{
		for (int i=0;i<100;i++)
		{
			if (!meanExcitPreTempDevRepartition[i].isVoid())
			{
				excitPreTempDevRepartitionTest[i][getEvalIndex()][paramIndex].accumulate((double) meanExcitPreTempDevRepartition[i].getMean());
				meanExcitPreTempDevRepartition[i].initAccu();
			}
			else
			{
				excitPreTempDevRepartitionTest[i][getEvalIndex()][paramIndex].setVoid();
				meanExcitPreTempDevRepartition[i].freeVoid();
			}
		}
	}

	if (excitPostTempDevRepartitionTest)
	{
		for (int i=0;i<100;i++)
		{
			if (!meanExcitPostTempDevRepartition[i].isVoid())
			{
				excitPostTempDevRepartitionTest[i][getEvalIndex()][paramIndex].accumulate((double) meanExcitPostTempDevRepartition[i].getMean());
				meanExcitPostTempDevRepartition[i].initAccu();
			}
			else
			{
				excitPostTempDevRepartitionTest[i][getEvalIndex()][paramIndex].setVoid();
				meanExcitPostTempDevRepartition[i].freeVoid();
			}
		}
	}
	
	if (inhibPreTempDevRepartitionTest)
	{
		for (int i=0;i<100;i++)
		{
			if (!meanInhibPreTempDevRepartition[i].isVoid())
			{
				inhibPreTempDevRepartitionTest[i][getEvalIndex()][paramIndex].accumulate((double) meanInhibPreTempDevRepartition[i].getMean());
				meanInhibPreTempDevRepartition[i].initAccu();
			}
			else
			{
				inhibPreTempDevRepartitionTest[i][getEvalIndex()][paramIndex].setVoid();
				meanInhibPreTempDevRepartition[i].freeVoid();
			}
		}
	}

	if (inhibPostTempDevRepartitionTest)
	{
		for (int i=0;i<100;i++)
		{
			if (!meanInhibPostTempDevRepartition[i].isVoid())
			{
				inhibPostTempDevRepartitionTest[i][getEvalIndex()][paramIndex].accumulate((double) meanInhibPostTempDevRepartition[i].getMean());
				meanInhibPostTempDevRepartition[i].initAccu();
			}
			else
			{
				inhibPostTempDevRepartitionTest[i][getEvalIndex()][paramIndex].setVoid();
				meanInhibPostTempDevRepartition[i].freeVoid();
			}
		}
	}
				#endif
				
	if (ISIRepartitionTest)
	{
		for (int i=0;i<100;i++)
		{
			if (!meanISIRepartition[i].isVoid())
			{
				ISIRepartitionTest[i][getEvalIndex()][paramIndex].accumulate((double) meanISIRepartition[i].getMean());
				meanISIRepartition[i].initAccu();
			}
			else
			{
				ISIRepartitionTest[i][getEvalIndex()][paramIndex].setVoid();
				meanISIRepartition[i].freeVoid();
			}
		}
	}
	else
	{
		cerr << "Warning, ISIRepartitionTest should be inited" << endl;
	}
	
	if (AssemblySpikeRepartitionTest)
	{
		for (int i=0;i<NB_ASSEMBLIES;i++)
		{
			for (int j=0;j<NB_NEURONS_EACH_ASSEMBLY;j++)
			{
				if (!meanSpikeRepartition[i*NB_NEURONS_EACH_ASSEMBLY+j].isVoid())
				{
					AssemblySpikeRepartitionTest[i][getEvalIndex()][paramIndex].accumulate((double) meanSpikeRepartition[i*NB_NEURONS_EACH_ASSEMBLY+j].getMean());
				}
				else
				{
					AssemblySpikeRepartitionTest[i][getEvalIndex()][paramIndex].setVoid();
					meanSpikeRepartition[i*NB_NEURONS_EACH_ASSEMBLY+j].freeVoid();
				}
			}
		}
	}
	else
	{
		cerr << "Warning, AssemblySpikeRepartitionTest should be inited" << endl;
	}
	
	if (SpikeRepartitionTest)
	{
		for (int i=0;i<NB_HIDDEN_NEURONS;i++)
		{
			if (!meanSpikeRepartition[i].isVoid())
			{
				SpikeRepartitionTest[i][getEvalIndex()][paramIndex].accumulate((double) meanSpikeRepartition[i].getMean());
				meanSpikeRepartition[i].initAccu();
			}
			else
			{
				SpikeRepartitionTest[i][getEvalIndex()][paramIndex].setVoid();
				meanSpikeRepartition[i].freeVoid();
			}
		}
	}
	else
	{
		cerr << "Warning, SpikeRepartitionTest should be inited" << endl;
	}
	
			#else
	if (timeFrequencyTest)
	{
		for (int i=0;i<NB_FREQUENCY_BINS;i++)
		{
			if (!meanTimeFrequency[i].isVoid())
			{
				timeFrequencyTest[i][paramIndex].accumulate((double) meanTimeFrequency[i].getMean());
				meanTimeFrequency[i].initAccu();
			}
			else
			{
				timeFrequencyTest[i][paramIndex].setVoid();
				meanTimeFrequency[i].freeVoid();
			}
		}
	}
	else
	{
		cerr << "Warning, timeFrequencyTest should be inited" << endl;
	}

	if (highTimeFrequencyTest)
	{
		for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
		{
			if (!meanHighTimeFrequency[i].isVoid())
			{
				highTimeFrequencyTest[i][paramIndex].accumulate((double) meanHighTimeFrequency[i].getMean());
				meanHighTimeFrequency[i].initAccu();
			}
			else
			{
				highTimeFrequencyTest[i][paramIndex].setVoid();
				meanHighTimeFrequency[i].freeVoid();
			}
		}
	}
	else
	{
		cerr << "Warning, highTimeFrequencyTest should be inited" << endl;
	}
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	if (excitPreTempDevRepartitionTest)
	{
		for (int i=0;i<100;i++)
		{
			if (!meanExcitPreTempDevRepartition[i].isVoid())
			{
				excitPreTempDevRepartitionTest[i][paramIndex].accumulate((double) meanExcitPreTempDevRepartition[i].getMean());
				meanExcitPreTempDevRepartition[i].initAccu();
			}
			else
			{
				excitPreTempDevRepartitionTest[i][paramIndex].setVoid();
				meanExcitPreTempDevRepartition[i].freeVoid();
			}
		}
	}

	if (excitPostTempDevRepartitionTest)
	{
		for (int i=0;i<100;i++)
		{
			if (!meanExcitPostTempDevRepartition[i].isVoid())
			{
				excitPostTempDevRepartitionTest[i][paramIndex].accumulate((double) meanExcitPostTempDevRepartition[i].getMean());
				meanExcitPostTempDevRepartition[i].initAccu();
			}
			else
			{
				excitPostTempDevRepartitionTest[i][paramIndex].setVoid();
				meanExcitPostTempDevRepartition[i].freeVoid();
			}
		}
	}
	
	if (inhibPreTempDevRepartitionTest)
	{
		for (int i=0;i<100;i++)
		{
			if (!meanInhibPreTempDevRepartition[i].isVoid())
			{
				inhibPreTempDevRepartitionTest[i][paramIndex].accumulate((double) meanInhibPreTempDevRepartition[i].getMean());
				meanInhibPreTempDevRepartition[i].initAccu();
			}
			else
			{
				inhibPreTempDevRepartitionTest[i][paramIndex].setVoid();
				meanInhibPreTempDevRepartition[i].freeVoid();
			}
		}
	}

	if (inhibPostTempDevRepartitionTest)
	{
		for (int i=0;i<100;i++)
		{
			if (!meanInhibPostTempDevRepartition[i].isVoid())
			{
				inhibPostTempDevRepartitionTest[i][paramIndex].accumulate((double) meanInhibPostTempDevRepartition[i].getMean());
				meanInhibPostTempDevRepartition[i].initAccu();
			}
			else
			{
				inhibPostTempDevRepartitionTest[i][paramIndex].setVoid();
				meanInhibPostTempDevRepartition[i].freeVoid();
			}
		}
	}
				#endif
				
	if (ISIRepartitionTest)
	{
		for (int i=0;i<100;i++)
		{
			if (!meanISIRepartition[i].isVoid())
			{
				ISIRepartitionTest[i][paramIndex].accumulate((double) meanISIRepartition[i].getMean());
				meanISIRepartition[i].initAccu();
			}
			else
			{
				ISIRepartitionTest[i][paramIndex].setVoid();
				meanISIRepartition[i].freeVoid();
			}
		}
	}
	else
	{
		cerr << "Warning, ISIRepartitionTest should be inited" << endl;
	}
	
			#endif
}
		#else
			#ifdef _PHASE_TEST_MODE
void ActivityTester::stat()
{
	if (timeFrequencyTest)
	{
		for (int i=0;i<NB_FREQUENCY_BINS;i++)
		{
			if (!meanTimeFrequency[i].isVoid())
			{
				timeFrequencyTest[i][getEvalIndex()].accumulate((double) meanTimeFrequency[i].getMean());
				meanTimeFrequency[i].initAccu();
			}
			else
			{
				timeFrequencyTest[i][getEvalIndex()].setVoid();
				meanTimeFrequency[i].freeVoid();
			}
		}
	}
	else
	{
		cerr << "Warning, timeFrequencyTest should be inited" << endl;
	}

	if (highTimeFrequencyTest)
	{
		for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
		{
			if (!meanHighTimeFrequency[i].isVoid())
			{
				highTimeFrequencyTest[i][getEvalIndex()].accumulate((double) meanHighTimeFrequency[i].getMean());
				meanHighTimeFrequency[i].initAccu();
			}
			else
			{
				highTimeFrequencyTest[i][getEvalIndex()].setVoid();
				meanHighTimeFrequency[i].freeVoid();
			}
		}
	}
	else
	{
		cerr << "Warning, highTimeFrequencyTest should be inited" << endl;
	}
	
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	if (excitPreTempDevRepartitionTest)
	{
		for (int i=0;i<100;i++)
		{
			if (!meanExcitPreTempDevRepartition[i].isVoid())
			{
				excitPreTempDevRepartitionTest[i][getEvalIndex()].accumulate((double) meanExcitPreTempDevRepartition[i].getMean());
				meanExcitPreTempDevRepartition[i].initAccu();
			}
			else
			{
				excitPreTempDevRepartitionTest[i][getEvalIndex()].setVoid();
				meanExcitPreTempDevRepartition[i].freeVoid();
			}
		}
	}

	if (excitPostTempDevRepartitionTest)
	{
		for (int i=0;i<100;i++)
		{
			if (!meanExcitPostTempDevRepartition[i].isVoid())
			{
				excitPostTempDevRepartitionTest[i][getEvalIndex()].accumulate((double) meanExcitPostTempDevRepartition[i].getMean());
				meanExcitPostTempDevRepartition[i].initAccu();
			}
			else
			{
				excitPostTempDevRepartitionTest[i][getEvalIndex()].setVoid();
				meanExcitPostTempDevRepartition[i].freeVoid();
			}
		}
	}
	
	if (inhibPreTempDevRepartitionTest)
	{
		for (int i=0;i<100;i++)
		{
			if (!meanInhibPreTempDevRepartition[i].isVoid())
			{
				inhibPreTempDevRepartitionTest[i][getEvalIndex()].accumulate((double) meanInhibPreTempDevRepartition[i].getMean());
				meanInhibPreTempDevRepartition[i].initAccu();
			}
			else
			{
				inhibPreTempDevRepartitionTest[i][getEvalIndex()].setVoid();
				meanInhibPreTempDevRepartition[i].freeVoid();
			}
		}
	}

	if (inhibPostTempDevRepartitionTest)
	{
		for (int i=0;i<100;i++)
		{
			if (!meanInhibPostTempDevRepartition[i].isVoid())
			{
				inhibPostTempDevRepartitionTest[i][getEvalIndex()].accumulate((double) meanInhibPostTempDevRepartition[i].getMean());
				meanInhibPostTempDevRepartition[i].initAccu();
			}
			else
			{
				inhibPostTempDevRepartitionTest[i][getEvalIndex()].setVoid();
				meanInhibPostTempDevRepartition[i].freeVoid();
			}
		}
	}
				#endif
				
	if (ISIRepartitionTest)
	{
		for (int i=0;i<100;i++)
		{
			if (!meanISIRepartition[i].isVoid())
			{
				ISIRepartitionTest[i][getEvalIndex()].accumulate((double) meanISIRepartition[i].getMean());
				meanISIRepartition[i].initAccu();
			}
			else
			{
				ISIRepartitionTest[i][getEvalIndex()].setVoid();
				meanISIRepartition[i].freeVoid();
			}
		}
	}
	else
	{
		cerr << "Warning, ISIRepartitionTest should be inited" << endl;
	}
	
	if (AssemblySpikeRepartitionTest)
	{
		for (int i=0;i<NB_ASSEMBLIES;i++)
		{
			for (int j=0;j<NB_NEURONS_EACH_ASSEMBLY;j++)
			{
				if (!meanSpikeRepartition[i*NB_NEURONS_EACH_ASSEMBLY+j].isVoid())
				{
					AssemblySpikeRepartitionTest[i][getEvalIndex()].accumulate((double) meanSpikeRepartition[i*NB_NEURONS_EACH_ASSEMBLY+j].getMean());
				}
				else
				{
					AssemblySpikeRepartitionTest[i][getEvalIndex()].setVoid();
					meanSpikeRepartition[i*NB_NEURONS_EACH_ASSEMBLY+j].freeVoid();
				}
			}
		}
	}
	else
	{
		cerr << "Warning, AssemblySpikeRepartitionTest should be inited" << endl;
	}
	
	if (SpikeRepartitionTest)
	{
		for (int i=0;i<NB_HIDDEN_NEURONS;i++)
		{
			if (!meanSpikeRepartition[i].isVoid())
			{
				SpikeRepartitionTest[i][getEvalIndex()].accumulate((double) meanSpikeRepartition[i].getMean());
				meanSpikeRepartition[i].initAccu();
			}
			else
			{
				SpikeRepartitionTest[i][getEvalIndex()].setVoid();
				meanSpikeRepartition[i].freeVoid();
			}
		}
	}
	else
	{
		cerr << "Warning, SpikeRepartitionTest should be inited" << endl;
	}
}
			#endif
		#endif

void ActivityTester::graph()
{
	if (activityTestGnuplotFile->isOpen())
	{
		//#ifdef _TEST_STAT
		cout << "In ActivityTester graph" << endl;
		//#endif
	
		#ifdef _PARAMETRIC_TEST_MODE
			#ifdef _CONDITIONAL_TEST_MODE
		activityTestGnuplotFile->setOutput("timeFrequencyTest0");
		activityTestGnuplotFile->setTitle("time FrequencyTest0");
		activityTestGnuplotFile->plotTitleIndexedLines("timeFrequencyTestStats",0,2*(NB_TESTED_ANIMALS+1));
		
		activityTestGnuplotFile->setOutput("highTimeFrequencyTest0");
		activityTestGnuplotFile->setTitle("high TimeFrequency Test0");
		activityTestGnuplotFile->plotTitleIndexedLines("highTimeFrequencyTestStats",0,2*(NB_TESTED_ANIMALS+1));
		
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
		activityTestGnuplotFile->setOutput("excitTempDevRepartitionTestStats0");
		activityTestGnuplotFile->setTitle("Excit tempDev Repartition Test Stats0");
		activityTestGnuplotFile->plotTitleIndexedLines("excitTempDevRepartitionTestStats",0,2*(NB_TESTED_ANIMALS+1));	
		
		activityTestGnuplotFile->setOutput("inhibTempDevRepartitionTestStats0");
		activityTestGnuplotFile->setTitle("Inhib tempDev Repartition Test Stats0");
		activityTestGnuplotFile->plotTitleIndexedLines("inhibTempDevRepartitionTestStats",0,2*(NB_TESTED_ANIMALS+1));	
				#endif
				
		activityTestGnuplotFile->setOutput("ISIRepartitionTestStats0");
		activityTestGnuplotFile->setTitle("ISI Repartition Test Stats0");
		activityTestGnuplotFile->plotTitleIndexedLines("ISIRepartitionTestStats",0,2*(NB_TESTED_ANIMALS+1));
		
		activityTestGnuplotFile->setOutput("timeFrequencyTest1");
		activityTestGnuplotFile->setTitle("time FrequencyTest1");
		activityTestGnuplotFile->plotTitleIndexedLines("timeFrequencyTestStats",2*(NB_TESTED_ANIMALS+1),NB_PARAMETRIC_TESTS*2*(NB_TESTED_ANIMALS+1));
		
		activityTestGnuplotFile->setOutput("highTimeFrequencyTest1");
		activityTestGnuplotFile->setTitle("high TimeFrequency Test1");
		activityTestGnuplotFile->plotTitleIndexedLines("highTimeFrequencyTestStats",2*(NB_TESTED_ANIMALS+1),NB_PARAMETRIC_TESTS*2*(NB_TESTED_ANIMALS+1));
		
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
		activityTestGnuplotFile->setOutput("excitTempDevRepartitionTestStats1");
		activityTestGnuplotFile->setTitle("Excit tempDev Repartition Test Stats1");
		activityTestGnuplotFile->plotTitleIndexedLines("excitTempDevRepartitionTestStats",2*(NB_TESTED_ANIMALS+1),NB_PARAMETRIC_TESTS*2*(NB_TESTED_ANIMALS+1));	
		
		activityTestGnuplotFile->setOutput("inhibTempDevRepartitionTestStats1");
		activityTestGnuplotFile->setTitle("Inhib tempDev Repartition Test Stats1");
		activityTestGnuplotFile->plotTitleIndexedLines("inhibTempDevRepartitionTestStats",2*(NB_TESTED_ANIMALS+1),NB_PARAMETRIC_TESTS*2*(NB_TESTED_ANIMALS+1));	
				#endif
				
		activityTestGnuplotFile->setOutput("ISIRepartitionTestStats1");
		activityTestGnuplotFile->setTitle("ISI Repartition Test Stats1");
		activityTestGnuplotFile->plotTitleIndexedLines("ISIRepartitionTestStats",2*(NB_TESTED_ANIMALS+1),NB_PARAMETRIC_TESTS*2*(NB_TESTED_ANIMALS+1));
		
				#ifdef _PHASE_TEST_MODE
		activityTestGnuplotFile->setOutput("diffTimeFrequencyTest");
		activityTestGnuplotFile->setTitle("diff TimeFrequency Test");
		activityTestGnuplotFile->plotTitleIndexedLines("diffTimeFrequencyTestStats",0,2*(NB_TESTED_ANIMALS+1));
		
		activityTestGnuplotFile->setOutput("diffHighTimeFrequencyTest");
		activityTestGnuplotFile->setTitle("diff High TimeFrequency Test");
		activityTestGnuplotFile->plotTitleIndexedLines("diffHighTimeFrequencyTestStats",0,2*(NB_TESTED_ANIMALS+1));
		
					#ifdef _GLOBAL_SYNAPSE_STAT_MODE
		activityTestGnuplotFile->setOutput("diffExcitTempDevRepartitionTestStats");
		activityTestGnuplotFile->setTitle("diff Excit TempDev Repartition Test Stats");
		activityTestGnuplotFile->plotTitleIndexedLines("diffExcitTempDevRepartitionTestStats",0,2*(NB_TESTED_ANIMALS+1));
		
		activityTestGnuplotFile->setOutput("diffInhibTempDevRepartitionTestStats");
		activityTestGnuplotFile->setTitle("diff Inhib TempDev Repartition Test Stats");
		activityTestGnuplotFile->plotTitleIndexedLines("diffInhibTempDevRepartitionTestStats",0,2*(NB_TESTED_ANIMALS+1));	
					#endif
					
		activityTestGnuplotFile->setOutput("diffISIRepartitionTestStats");
		activityTestGnuplotFile->setTitle("diff ISI Repartition Test Stats");
		activityTestGnuplotFile->plotTitleIndexedLines("diffISIRepartitionTestStats",0,2*(NB_TESTED_ANIMALS+1));
				#endif
			#else
				#ifdef _TRANSITION_STAT_MODE
		for (int i=0;i<2*(1+2*NB_TESTED_ANIMALS+1);i++)
		{
			ostringstream oss;
			oss << i;
			activityTestGnuplotFile->setOutput("timeFrequencyTest"+oss.str());
			activityTestGnuplotFile->setTitle("time FrequencyTest "+oss.str());
			activityTestGnuplotFile->plotTitleIndexedLines("timeFrequencyTestStats",i*NB_PARAMETRIC_TESTS,(i+1)*NB_PARAMETRIC_TESTS);
			
			activityTestGnuplotFile->setOutput("highTimeFrequencyTest"+oss.str());
			activityTestGnuplotFile->setTitle("high TimeFrequency Test "+oss.str());
			activityTestGnuplotFile->plotTitleIndexedLines("highTimeFrequencyTestStats",i*NB_PARAMETRIC_TESTS,(i+1)*NB_PARAMETRIC_TESTS);
					
					#ifdef _GLOBAL_SYNAPSE_STAT_MODE
			activityTestGnuplotFile->setOutput("excitTempDevRepartitionTestStats"+oss.str());
			activityTestGnuplotFile->setTitle("Excit tempDev Repartition Test Stats "+oss.str());
			activityTestGnuplotFile->plotTitleIndexedLines("excitTempDevRepartitionTestStats",i*NB_PARAMETRIC_TESTS,(i+1)*NB_PARAMETRIC_TESTS);	
			
			activityTestGnuplotFile->setOutput("inhibTempDevRepartitionTestStats"+oss.str());
			activityTestGnuplotFile->setTitle("Inhib tempDev Repartition Test Stats "+oss.str());
			activityTestGnuplotFile->plotTitleIndexedLines("inhibTempDevRepartitionTestStats",i*NB_PARAMETRIC_TESTS,(i+1)*NB_PARAMETRIC_TESTS);	
					#endif
					
			activityTestGnuplotFile->setOutput("ISIRepartitionTestStats"+oss.str());
			activityTestGnuplotFile->setTitle("ISI Repartition Test Stats "+oss.str());
			activityTestGnuplotFile->plotTitleIndexedLines("ISIRepartitionTestStats",i*NB_PARAMETRIC_TESTS,(i+1)*NB_PARAMETRIC_TESTS);
			
			activityTestGnuplotFile->setOutput("SpikeRepartitionTestStats"+oss.str());
			activityTestGnuplotFile->setTitle("Spike Repartition Test Stats"+oss.str());
			activityTestGnuplotFile->plotTitleIndexedLines("SpikeRepartitionTestStats",i*NB_PARAMETRIC_TESTS,(i+1)*NB_PARAMETRIC_TESTS);
			//activityTestGnuplotFile->plotTitleIndexedLines("SpikeRepartitionTestStats",0,4*(NB_TESTED_ANIMALS+1));
		
			activityTestGnuplotFile->setOutput("AssemblySpikeRepartitionTestStats"+oss.str());
			activityTestGnuplotFile->setTitle("AssemblySpike Repartition Test Stats"+oss.str());
			activityTestGnuplotFile->plotTitleIndexedLines("AssemblySpikeRepartitionTestStats",i*NB_PARAMETRIC_TESTS,(i+1)*NB_PARAMETRIC_TESTS);
			
			//activityTestGnuplotFile->plotTitleIndexedLines("AssemblySpikeRepartitionTestStats",0,4*(NB_TESTED_ANIMALS+1));
			
		}
		
		for (int i=0;i<(1+2*NB_TESTED_ANIMALS+1);i++)
		{
			ostringstream oss;
			oss << i;
			
			activityTestGnuplotFile->setOutput("diffTimeFrequencyTest"+oss.str());
			activityTestGnuplotFile->setTitle("diff TimeFrequency Test "+oss.str());
			activityTestGnuplotFile->plotTitleEveryIndexedLines("diffTimeFrequencyTestStats",i,(1+2*NB_TESTED_ANIMALS+1),NB_PARAMETRIC_TESTS);
			
			activityTestGnuplotFile->setOutput("diffHighTimeFrequencyTest"+oss.str());
			activityTestGnuplotFile->setTitle("diff High TimeFrequency Test "+oss.str());
			activityTestGnuplotFile->plotTitleEveryIndexedLines("diffHighTimeFrequencyTestStats",i,(1+2*NB_TESTED_ANIMALS+1),NB_PARAMETRIC_TESTS);
			
					#ifdef _GLOBAL_SYNAPSE_STAT_MODE
			activityTestGnuplotFile->setOutput("diffExcitTempDevRepartitionTestStats"+oss.str());
			activityTestGnuplotFile->setTitle("diff Excit TempDev Repartition Test Stats "+oss.str());
			activityTestGnuplotFile->plotTitleEveryIndexedLines("diffExcitTempDevRepartitionTestStats",i,(1+2*NB_TESTED_ANIMALS+1),NB_PARAMETRIC_TESTS);
			
			activityTestGnuplotFile->setOutput("diffInhibTempDevRepartitionTestStats"+oss.str());
			activityTestGnuplotFile->setTitle("diff Inhib TempDev Repartition Test Stats "+oss.str());
			activityTestGnuplotFile->plotTitleEveryIndexedLines("diffInhibTempDevRepartitionTestStats",i,(1+2*NB_TESTED_ANIMALS+1),NB_PARAMETRIC_TESTS);
					#endif
					
			activityTestGnuplotFile->setOutput("diffISIRepartitionTestStats"+oss.str());
			activityTestGnuplotFile->setTitle("diff ISI Repartition Test Stats "+oss.str());
			activityTestGnuplotFile->plotTitleEveryIndexedLines("diffISIRepartitionTestStats",i,(1+2*NB_TESTED_ANIMALS+1),NB_PARAMETRIC_TESTS);
				
			activityTestGnuplotFile->setOutput("diffSpikeRepartitionTestStats"+oss.str());
			activityTestGnuplotFile->setTitle("diff Spike Repartition Test Stats"+oss.str());
			activityTestGnuplotFile->plotTitleEveryIndexedLines("diffSpikeRepartitionTestStats",i,(1+2*NB_TESTED_ANIMALS+1),NB_PARAMETRIC_TESTS);
			//activityTestGnuplotFile->plotTitleIndexedLines("diffSpikeRepartitionTestStats",0,2+(NB_TESTED_ANIMALS+1));
			
			activityTestGnuplotFile->setOutput("diffAssemblySpikeRepartitionTestStats"+oss.str());
			activityTestGnuplotFile->setTitle("diff AssemblySpike Repartition Test Stats"+oss.str());
			activityTestGnuplotFile->plotTitleEveryIndexedLines("diffAssemblySpikeRepartitionTestStats",i,(1+2*NB_TESTED_ANIMALS+1),NB_PARAMETRIC_TESTS);
			//activityTestGnuplotFile->plotTitleIndexedLines("diffAssemblySpikeRepartitionTestStats",0,2+(NB_TESTED_ANIMALS+1));
			
		}
				#else
		activityTestGnuplotFile->setOutput("timeFrequencyTest");
		activityTestGnuplotFile->setTitle("time FrequencyTest");
		activityTestGnuplotFile->plotTitleIndexedLines("timeFrequencyTestStats",0,NB_PARAMETRIC_TESTS);
		
		activityTestGnuplotFile->setOutput("highTimeFrequencyTest");
		activityTestGnuplotFile->setTitle("high TimeFrequency Test");
		activityTestGnuplotFile->plotTitleIndexedLines("highTimeFrequencyTestStats",0,NB_PARAMETRIC_TESTS);
		
					#ifdef _GLOBAL_SYNAPSE_STAT_MODE
		activityTestGnuplotFile->setOutput("excitTempDevRepartitionTestStats");
		activityTestGnuplotFile->setTitle("Excit tempDev Repartition Test Stats");
		activityTestGnuplotFile->plotTitleIndexedLines("excitTempDevRepartitionTestStats",0,NB_PARAMETRIC_TESTS);	
		
		activityTestGnuplotFile->setOutput("inhibTempDevRepartitionTestStats");
		activityTestGnuplotFile->setTitle("Inhib tempDev Repartition Test Stats");
		activityTestGnuplotFile->plotTitleIndexedLines("inhibTempDevRepartitionTestStats",0,NB_PARAMETRIC_TESTS);	
					#endif
		activityTestGnuplotFile->setOutput("ISIRepartitionTestStats");
		activityTestGnuplotFile->setTitle("ISI Repartition Test Stats");
		activityTestGnuplotFile->plotTitleIndexedLines("ISIRepartitionTestStats",0,NB_PARAMETRIC_TESTS);
		
		activityTestGnuplotFile->setOutput("SpikeRepartitionTestStats");
		activityTestGnuplotFile->setTitle("Spike Repartition Test Stats");
		activityTestGnuplotFile->plotTitleIndexedLines("SpikeRepartitionTestStats",0,NB_PARAMETRIC_TESTS);
	
		activityTestGnuplotFile->setOutput("AssemblySpikeRepartitionTestStats");
		activityTestGnuplotFile->setTitle("AssemblySpike Repartition Test Stats");
		activityTestGnuplotFile->plotTitleIndexedLines("AssemblySpikeRepartitionTestStats",0,NB_PARAMETRIC_TESTS);
		
					#ifdef _PHASE_TEST_MODE
		activityTestGnuplotFile->setOutput("diffTimeFrequencyTest");
		activityTestGnuplotFile->setTitle("diff TimeFrequency Test");
		activityTestGnuplotFile->plotTitleIndexedLines("diffTimeFrequencyTestStats",0,NB_PARAMETRIC_TESTS);
		
		activityTestGnuplotFile->setOutput("diffHighTimeFrequencyTest");
		activityTestGnuplotFile->setTitle("diff High TimeFrequency Test");
		activityTestGnuplotFile->plotTitleIndexedLines("diffHighTimeFrequencyTestStats",0,NB_PARAMETRIC_TESTS);
		
						#ifdef _GLOBAL_SYNAPSE_STAT_MODE
		activityTestGnuplotFile->setOutput("diffExcitTempDevRepartitionTestStats");
		activityTestGnuplotFile->setTitle("diff Excit TempDev Repartition Test Stats");
		activityTestGnuplotFile->plotTitleIndexedLines("diffExcitTempDevRepartitionTestStats",0,NB_PARAMETRIC_TESTS);
		
		activityTestGnuplotFile->setOutput("diffInhibTempDevRepartitionTestStats");
		activityTestGnuplotFile->setTitle("diff Inhib TempDev Repartition Test Stats");
		activityTestGnuplotFile->plotTitleIndexedLines("diffInhibTempDevRepartitionTestStats",0,NB_PARAMETRIC_TESTS);	
						#endif
						
		activityTestGnuplotFile->setOutput("diffISIRepartitionTestStats");
		activityTestGnuplotFile->setTitle("diff ISI Repartition Test Stats");
		activityTestGnuplotFile->plotTitleIndexedLines("diffISIRepartitionTestStats",0,NB_PARAMETRIC_TESTS);
		
		activityTestGnuplotFile->setOutput("diffSpikeRepartitionTestStats");
		activityTestGnuplotFile->setTitle("diff Spike Repartition Test Stats");
		activityTestGnuplotFile->plotTitleIndexedLines("diffSpikeRepartitionTestStats",0,NB_PARAMETRIC_TESTS);
		
		activityTestGnuplotFile->setOutput("diffAssemblySpikeRepartitionTestStats");
		activityTestGnuplotFile->setTitle("diff AssemblySpike Repartition Test Stats");
		activityTestGnuplotFile->plotTitleIndexedLines("diffAssemblySpikeRepartitionTestStats",0,NB_PARAMETRIC_TESTS);
					#endif
				#endif
			#endif
		#else
			#ifdef _PHASE_TEST_MODE
				#ifdef _TRANSITION_STAT_MODE
		activityTestGnuplotFile->setOutput("timeFrequencyTest");
		activityTestGnuplotFile->setTitle("timeFrequency Test");
		activityTestGnuplotFile->plotTitleIndexedLines("timeFrequencyTestStats",0,4*(NB_TESTED_ANIMALS+1));
		
		activityTestGnuplotFile->setOutput("diffTimeFrequencyTest");
		activityTestGnuplotFile->setTitle("diff TimeFrequency Test");
		activityTestGnuplotFile->plotTitleIndexedLines("diffTimeFrequencyTestStats",0,2+(NB_TESTED_ANIMALS+1));
		
		activityTestGnuplotFile->setOutput("highTimeFrequencyTest");
		activityTestGnuplotFile->setTitle("high TimeFrequency Test");
		activityTestGnuplotFile->plotTitleIndexedLines("highTimeFrequencyTestStats",0,4*(NB_TESTED_ANIMALS+1));
		
		activityTestGnuplotFile->setOutput("diffHighTimeFrequencyTest");
		activityTestGnuplotFile->setTitle("diff High TimeFrequency Test");
		activityTestGnuplotFile->plotTitleIndexedLines("diffHighTimeFrequencyTestStats",0,2+(NB_TESTED_ANIMALS+1));
					#ifdef _GLOBAL_SYNAPSE_STAT_MODE
		activityTestGnuplotFile->setOutput("inhibTempDevRepartitionTestStats");
		activityTestGnuplotFile->setTitle("Inhib tempDev Repartition Test Stats");
		activityTestGnuplotFile->plotTitleIndexedLines("inhibTempDevRepartitionTestStats",0,4*(NB_TESTED_ANIMALS+1));	
		
		activityTestGnuplotFile->setOutput("excitTempDevRepartitionTestStats");
		activityTestGnuplotFile->setTitle("Excit tempDev Repartition Test Stats");
		activityTestGnuplotFile->plotTitleIndexedLines("excitTempDevRepartitionTestStats",0,4*(NB_TESTED_ANIMALS+1));	
		
		activityTestGnuplotFile->setOutput("diffExcitTempDevRepartitionTestStats");
		activityTestGnuplotFile->setTitle("diff Excit TempDev Repartition Test Stats");
		activityTestGnuplotFile->plotTitleIndexedLines("diffExcitTempDevRepartitionTestStats",0,2+(NB_TESTED_ANIMALS+1));
		
		activityTestGnuplotFile->setOutput("diffInhibTempDevRepartitionTestStats");
		activityTestGnuplotFile->setTitle("diff Inhib TempDev Repartition Test Stats");
		activityTestGnuplotFile->plotTitleIndexedLines("diffInhibTempDevRepartitionTestStats",0,2+(NB_TESTED_ANIMALS+1));	
					#endif
					
		activityTestGnuplotFile->setOutput("ISIRepartitionTestStats");
		activityTestGnuplotFile->setTitle("ISI Repartition Test Stats");
		activityTestGnuplotFile->plotTitleIndexedLines("ISIRepartitionTestStats",0,4*(NB_TESTED_ANIMALS+1));
		
		activityTestGnuplotFile->setOutput("diffISIRepartitionTestStats");
		activityTestGnuplotFile->setTitle("diff ISI Repartition Test Stats");
		activityTestGnuplotFile->plotTitleIndexedLines("diffISIRepartitionTestStats",0,2+(NB_TESTED_ANIMALS+1));
		
					#ifdef _SORT_ASSEMBLY_STAT_MODE
		activityTestGnuplotFile->setOutput("SortedSpikeRepartitionTestStats");
		activityTestGnuplotFile->setTitle("Sorted Spike Repartition Test Stats");
		activityTestGnuplotFile->plotTitleSorted3IndexedLines("SpikeRepartitionTestStats",0,4*(NB_TESTED_ANIMALS+1));
		
		activityTestGnuplotFile->setOutput("diffSortedSpikeRepartitionTestStats");
		activityTestGnuplotFile->setTitle("diff Sorted Spike Repartition Test Stats");
		activityTestGnuplotFile->plotTitleSorted3IndexedLines("diffSpikeRepartitionTestStats",0,2+(NB_TESTED_ANIMALS+1));
		
		activityTestGnuplotFile->setOutput("SortedAssemblySpikeRepartitionTestStats");
		activityTestGnuplotFile->setTitle("Sorted AssemblySpike Repartition Test Stats");
		activityTestGnuplotFile->plotTitleSorted3IndexedLines("AssemblySpikeRepartitionTestStats",0,4*(NB_TESTED_ANIMALS+1));
		
		activityTestGnuplotFile->setOutput("diffSortedAssemblySpikeRepartitionTestStats");
		activityTestGnuplotFile->setTitle("diff Sorted AssemblySpike Repartition Test Stats");
		activityTestGnuplotFile->plotTitleSorted3IndexedLines("diffAssemblySpikeRepartitionTestStats",0,2+(NB_TESTED_ANIMALS+1));
		
					#else
		activityTestGnuplotFile->setOutput("SpikeRepartitionTestStats");
		activityTestGnuplotFile->setTitle("Spike Repartition Test Stats");
		activityTestGnuplotFile->plotTitleIndexedLines("SpikeRepartitionTestStats",0,4*(NB_TESTED_ANIMALS+1));
	
		activityTestGnuplotFile->setOutput("diffSpikeRepartitionTestStats");
		activityTestGnuplotFile->setTitle("diff Spike Repartition Test Stats");
		activityTestGnuplotFile->plotTitleIndexedLines("diffSpikeRepartitionTestStats",0,2+(NB_TESTED_ANIMALS+1));
		
		activityTestGnuplotFile->setOutput("AssemblySpikeRepartitionTestStats");
		activityTestGnuplotFile->setTitle("AssemblySpike Repartition Test Stats");
		activityTestGnuplotFile->plotTitleIndexedLines("AssemblySpikeRepartitionTestStats",0,4*(NB_TESTED_ANIMALS+1));
		
		activityTestGnuplotFile->setOutput("diffAssemblySpikeRepartitionTestStats");
		activityTestGnuplotFile->setTitle("diff AssemblySpike Repartition Test Stats");
		activityTestGnuplotFile->plotTitleIndexedLines("diffAssemblySpikeRepartitionTestStats",0,2+(NB_TESTED_ANIMALS+1));
					#endif
				#else
					#ifdef _REPETITIVE_TEST_MODE
		activityTestGnuplotFile->setOutput("diffTimeFrequencyTest");
		activityTestGnuplotFile->setTitle("diff TimeFrequency Test");
		activityTestGnuplotFile->plotTitleIndexedLines("diffTimeFrequencyTestStats",0,2);
		
		activityTestGnuplotFile->setOutput("diffHighTimeFrequencyTest");
		activityTestGnuplotFile->setTitle("diff High TimeFrequency Test");
		activityTestGnuplotFile->plotTitleIndexedLines("diffHighTimeFrequencyTestStats",0,2);
						
						#ifdef _GLOBAL_SYNAPSE_STAT_MODE
		activityTestGnuplotFile->setOutput("diffExcitTempDevRepartitionTestStats");
		activityTestGnuplotFile->setTitle("diff Excit TempDev Repartition Test Stats");
		activityTestGnuplotFile->plotTitleIndexedLines("diffExcitTempDevRepartitionTestStats",0,2);
		
		activityTestGnuplotFile->setOutput("diffInhibTempDevRepartitionTestStats");
		activityTestGnuplotFile->setTitle("diff Inhib TempDev Repartition Test Stats");
		activityTestGnuplotFile->plotTitleIndexedLines("diffInhibTempDevRepartitionTestStats",0,2);	
						#endif
						
		activityTestGnuplotFile->setOutput("diffISIRepartitionTestStats");
		activityTestGnuplotFile->setTitle("diff ISI Repartition Test Stats");
		activityTestGnuplotFile->plotTitleIndexedLines("diffISIRepartitionTestStats",0,2);
		
						#ifdef _SORT_ASSEMBLY_STAT_MODE
		activityTestGnuplotFile->setOutput("diffSortedSpikeRepartitionTestStats");
		activityTestGnuplotFile->setTitle("diff Sorted Spike Repartition Test Stats");
		activityTestGnuplotFile->plotTitleSorted3IndexedLines("diffSpikeRepartitionTestStats",0,2);
		
		activityTestGnuplotFile->setOutput("diffSortedAssemblySpikeRepartitionTestStats");
		activityTestGnuplotFile->setTitle("diff Sorted AssemblySpike Repartition Test Stats");
		activityTestGnuplotFile->plotTitleSorted3IndexedLines("diffAssemblySpikeRepartitionTestStats",0,2);
		
						#else
		activityTestGnuplotFile->setOutput("diffSpikeRepartitionTestStats");
		activityTestGnuplotFile->setTitle("diff Spike Repartition Test Stats");
		activityTestGnuplotFile->plotTitleIndexedLines("diffSpikeRepartitionTestStats",0,2);
		
		activityTestGnuplotFile->setOutput("diffAssemblySpikeRepartitionTestStats");
		activityTestGnuplotFile->setTitle("diff AssemblySpike Repartition Test Stats");
		activityTestGnuplotFile->plotTitleIndexedLines("diffAssemblySpikeRepartitionTestStats",0,2);
						#endif
		
					#else
		activityTestGnuplotFile->setOutput("timeFrequencyTest");
		activityTestGnuplotFile->setTitle("timeFrequency Test");
		activityTestGnuplotFile->plotTitleIndexedLines("timeFrequencyTestStats",0,2*(NB_TESTED_ANIMALS+1));
		
		activityTestGnuplotFile->setOutput("diffTimeFrequencyTest");
		activityTestGnuplotFile->setTitle("diff TimeFrequency Test");
		activityTestGnuplotFile->plotTitleIndexedLines("diffTimeFrequencyTestStats",0,1+(NB_TESTED_ANIMALS+1));
		
		activityTestGnuplotFile->setOutput("highTimeFrequencyTest");
		activityTestGnuplotFile->setTitle("high TimeFrequency Test");
		activityTestGnuplotFile->plotTitleIndexedLines("highTimeFrequencyTestStats",0,2*(NB_TESTED_ANIMALS+1));
		
		activityTestGnuplotFile->setOutput("diffHighTimeFrequencyTest");
		activityTestGnuplotFile->setTitle("diff High TimeFrequency Test");
		activityTestGnuplotFile->plotTitleIndexedLines("diffHighTimeFrequencyTestStats",0,1+(NB_TESTED_ANIMALS+1));
						
						#ifdef _GLOBAL_SYNAPSE_STAT_MODE
		activityTestGnuplotFile->setOutput("inhibTempDevRepartitionTestStats");
		activityTestGnuplotFile->setTitle("Inhib tempDev Repartition Test Stats");
		activityTestGnuplotFile->plotTitleIndexedLines("inhibTempDevRepartitionTestStats",0,2*(NB_TESTED_ANIMALS+1));	
		
		activityTestGnuplotFile->setOutput("excitTempDevRepartitionTestStats");
		activityTestGnuplotFile->setTitle("Excit tempDev Repartition Test Stats");
		activityTestGnuplotFile->plotTitleIndexedLines("excitTempDevRepartitionTestStats",0,2*(NB_TESTED_ANIMALS+1));	
		
		activityTestGnuplotFile->setOutput("diffExcitTempDevRepartitionTestStats");
		activityTestGnuplotFile->setTitle("diff Excit TempDev Repartition Test Stats");
		activityTestGnuplotFile->plotTitleIndexedLines("diffExcitTempDevRepartitionTestStats",0,1+(NB_TESTED_ANIMALS+1));
		
		activityTestGnuplotFile->setOutput("diffInhibTempDevRepartitionTestStats");
		activityTestGnuplotFile->setTitle("diff Inhib TempDev Repartition Test Stats");
		activityTestGnuplotFile->plotTitleIndexedLines("diffInhibTempDevRepartitionTestStats",0,1+(NB_TESTED_ANIMALS+1));	
						#endif
						
		activityTestGnuplotFile->setOutput("ISIRepartitionTestStats");
		activityTestGnuplotFile->setTitle("ISI Repartition Test Stats");
		activityTestGnuplotFile->plotTitleIndexedLines("ISIRepartitionTestStats",0,2*(NB_TESTED_ANIMALS+1));
		
		activityTestGnuplotFile->setOutput("diffISIRepartitionTestStats");
		activityTestGnuplotFile->setTitle("diff ISI Repartition Test Stats");
		activityTestGnuplotFile->plotTitleIndexedLines("diffISIRepartitionTestStats",0,1+(NB_TESTED_ANIMALS+1));
		
						#ifdef _SORT_ASSEMBLY_STAT_MODE
		activityTestGnuplotFile->setOutput("SortedSpikeRepartitionTestStats");
		activityTestGnuplotFile->setTitle("Sorted Spike Repartition Test Stats");
		activityTestGnuplotFile->plotTitleSorted3IndexedLines("SpikeRepartitionTestStats",0,2*(NB_TESTED_ANIMALS+1));
		
		activityTestGnuplotFile->setOutput("diffSortedSpikeRepartitionTestStats");
		activityTestGnuplotFile->setTitle("diff Sorted Spike Repartition Test Stats");
		activityTestGnuplotFile->plotTitleSorted3IndexedLines("diffSpikeRepartitionTestStats",0,1+(NB_TESTED_ANIMALS+1));
		
		activityTestGnuplotFile->setOutput("SortedAssemblySpikeRepartitionTestStats");
		activityTestGnuplotFile->setTitle("Sorted AssemblySpike Repartition Test Stats");
		activityTestGnuplotFile->plotTitleSorted3IndexedLines("AssemblySpikeRepartitionTestStats",0,2*(NB_TESTED_ANIMALS+1));
		
		activityTestGnuplotFile->setOutput("diffSortedAssemblySpikeRepartitionTestStats");
		activityTestGnuplotFile->setTitle("diff Sorted AssemblySpike Repartition Test Stats");
		activityTestGnuplotFile->plotTitleSorted3IndexedLines("diffAssemblySpikeRepartitionTestStats",0,1+(NB_TESTED_ANIMALS+1));
		
						#else
		activityTestGnuplotFile->setOutput("SpikeRepartitionTestStats");
		activityTestGnuplotFile->setTitle("Spike Repartition Test Stats");
		activityTestGnuplotFile->plotTitleIndexedLines("SpikeRepartitionTestStats",0,2*(NB_TESTED_ANIMALS+1));
	
		activityTestGnuplotFile->setOutput("diffSpikeRepartitionTestStats");
		activityTestGnuplotFile->setTitle("diff Spike Repartition Test Stats");
		activityTestGnuplotFile->plotTitleIndexedLines("diffSpikeRepartitionTestStats",0,1+(NB_TESTED_ANIMALS+1));
		
		activityTestGnuplotFile->setOutput("AssemblySpikeRepartitionTestStats");
		activityTestGnuplotFile->setTitle("AssemblySpike Repartition Test Stats");
		activityTestGnuplotFile->plotTitleIndexedLines("AssemblySpikeRepartitionTestStats",0,2*(NB_TESTED_ANIMALS+1));
		
		activityTestGnuplotFile->setOutput("diffAssemblySpikeRepartitionTestStats");
		activityTestGnuplotFile->setTitle("diff AssemblySpike Repartition Test Stats");
		activityTestGnuplotFile->plotTitleIndexedLines("diffAssemblySpikeRepartitionTestStats",0,1+(NB_TESTED_ANIMALS+1));
						#endif
					#endif
				#endif
			#else
		
		activityTestGnuplotFile->setOutput("MeanHigh-Time-Frequency");
		activityTestGnuplotFile->setTitle("Mean High-Time-Frequency");
		activityTestGnuplotFile->plot3DIndexedLines("Mean_highTimeFrequencyStats");

		activityTestGnuplotFile->setOutput("Temporal_MeanHigh-Time-Frequency");
		activityTestGnuplotFile->setTitle("Temporal Mean High Time-Frequency");
		activityTestGnuplotFile->plotLine("Temporal_Mean_highTimeFrequencyStats");
		
		activityTestGnuplotFile->setOutput("MeanTime-Frequency");
		activityTestGnuplotFile->setTitle("Mean Time-Frequency");
		activityTestGnuplotFile->plot3DIndexedLines("Mean_timeFrequencyStats");
		
		activityTestGnuplotFile->setOutput("Temporal_MeanTime-Frequency");
		activityTestGnuplotFile->setTitle("Temporal Mean Time-Frequency");
		activityTestGnuplotFile->plotLine("Temporal_Mean_timeFrequencyStats");
		
		activityTestGnuplotFile->setOutput("Mean_ISI");
		activityTestGnuplotFile->setTitle("Mean ISI");
		activityTestGnuplotFile->plot3DIndexedLines("Mean_ISIStats");
		
		activityTestGnuplotFile->setOutput("Temporal_Mean_ISI");
		activityTestGnuplotFile->setTitle("Temporal Mean ISI");
		activityTestGnuplotFile->plotLine("Temporal_Mean_ISIStats");
		
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
		activityTestGnuplotFile->setOutput("Mean_ExcitTempDev");
		activityTestGnuplotFile->setTitle("Mean Excit Temp Dev");
		activityTestGnuplotFile->plot3DIndexedLines("Mean_excitTempDevRepartitionStats");
		
		activityTestGnuplotFile->setOutput("Temporal_Mean_ExcitTempDev");
		activityTestGnuplotFile->setTitle("Temporal Mean Excit Temp Dev");
		activityTestGnuplotFile->plotLine("Temporal_Mean_excitTempDevRepartitionStats");
		
		activityTestGnuplotFile->setOutput("Mean_InhibTempDev");
		activityTestGnuplotFile->setTitle("Mean Inhib Temp Dev");
		activityTestGnuplotFile->plot3DIndexedLines("Mean_inhibTempDevRepartitionStats");
		
		activityTestGnuplotFile->setOutput("Temporal_Mean_InhibTempDev");
		activityTestGnuplotFile->setTitle("Temporal Mean Inhib Temp Dev");
		activityTestGnuplotFile->plotLine("Temporal_Mean_inhibTempDevRepartitionStats");
				#endif
				
		activityTestGnuplotFile->setOutput("Mean_SpikeCount");
		activityTestGnuplotFile->setTitle("Mean Spike Count");
		activityTestGnuplotFile->plot3DIndexedLines("Mean_spikeCountStats");
		
		activityTestGnuplotFile->setOutput("Temporal_Mean_SpikeCount");
		activityTestGnuplotFile->setTitle("Temporal Mean Spike Count");
		activityTestGnuplotFile->plotLine("Temporal_Mean_spikeCountStats");
			#endif
		#endif	
	}
	else
	{
		cerr << "Warning, activityTestGnuplotFile should be open" << endl;
	}
}
	#endif
#endif


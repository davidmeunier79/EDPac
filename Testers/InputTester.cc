// ActivityTester.cc

// Local Includes
#include "InputTester.h"

/****************************************************************************************************************************************/
/************************************************* Methodes de la classe InputTester ************************************************/
/****************************************************************************************************************************************/

InputTester::InputTester()
{

#ifdef _GLOBAL_STAT_MODE
	#ifdef _MULTI_TEST_MODE	
	initAccumulaters();
	
	activityInputTestGnuplotFile = new GnuplotFile();
	
		#ifdef _PARAMETRIC_TEST_MODE
	timeFrequencyInputTestFile = new DataFile();
	highTimeFrequencyInputTestFile = new DataFile();
			#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	excitTempDevRepartitionInputTestFile = new DataFile();
	inhibTempDevRepartitionInputTestFile = new DataFile();
			#endif
			
	ISIRepartitionInputTestFile = new DataFile();
	
			#ifdef _PHASE_TEST_MODE
	diffTimeFrequencyInputTestFile = new DataFile();
	diffHighTimeFrequencyInputTestFile = new DataFile();
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	diffExcitTempDevRepartitionInputTestFile = new DataFile();
	diffInhibTempDevRepartitionInputTestFile = new DataFile();
				#endif
	diffISIRepartitionInputTestFile = new DataFile();
			#endif
		#else
			#ifdef _PHASE_TEST_MODE	
	timeFrequencyInputTestFile = new DataFile();
	highTimeFrequencyInputTestFile = new DataFile();
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	excitTempDevRepartitionInputTestFile = new DataFile();
	inhibTempDevRepartitionInputTestFile = new DataFile();
				#endif
				
	ISIRepartitionInputTestFile = new DataFile();
	SpikeRepartitionInputTestFile = new DataFile();
	AssemblySpikeRepartitionInputTestFile = new DataFile();
	
	diffTimeFrequencyInputTestFile = new DataFile();
	diffHighTimeFrequencyInputTestFile = new DataFile();
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	diffExcitTempDevRepartitionInputTestFile = new DataFile();
	diffInhibTempDevRepartitionInputTestFile = new DataFile();
				#endif
				
	diffISIRepartitionInputTestFile = new DataFile();
	diffSpikeRepartitionInputTestFile = new DataFile();
	diffAssemblySpikeRepartitionInputTestFile = new DataFile();
			#endif
		#endif
	#endif	
#endif
	openStater();
}

InputTester::InputTester(IndexedObject* io): InputStater(io)
{

#ifdef _GLOBAL_STAT_MODE
	#ifdef _MULTI_TEST_MODE	
	initAccumulaters();
	
	activityInputTestGnuplotFile = new GnuplotFile();
	
		#ifdef _PARAMETRIC_TEST_MODE
	timeFrequencyInputTestFile = new DataFile();
	highTimeFrequencyInputTestFile = new DataFile();
			#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	excitTempDevRepartitionInputTestFile = new DataFile();
	inhibTempDevRepartitionInputTestFile = new DataFile();
			#endif
	ISIRepartitionInputTestFile = new DataFile();
	
			#ifdef _PHASE_TEST_MODE
	diffTimeFrequencyInputTestFile = new DataFile();
	diffHighTimeFrequencyInputTestFile = new DataFile();
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	diffExcitTempDevRepartitionInputTestFile = new DataFile();
	diffInhibTempDevRepartitionInputTestFile = new DataFile();
				#endif
	diffISIRepartitionInputTestFile = new DataFile();
			#endif
		#else
			#ifdef _PHASE_TEST_MODE
	timeFrequencyInputTestFile = new DataFile();
	highTimeFrequencyInputTestFile = new DataFile();
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	excitTempDevRepartitionInputTestFile = new DataFile();
	inhibTempDevRepartitionInputTestFile = new DataFile();
				#endif
	ISIRepartitionInputTestFile = new DataFile();
	SpikeRepartitionInputTestFile = new DataFile();
	AssemblySpikeRepartitionInputTestFile = new DataFile();
	
	diffTimeFrequencyInputTestFile = new DataFile();
	diffHighTimeFrequencyInputTestFile = new DataFile();
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	diffExcitTempDevRepartitionInputTestFile = new DataFile();
	diffInhibTempDevRepartitionInputTestFile = new DataFile();
				#endif
	diffISIRepartitionInputTestFile = new DataFile();
	diffSpikeRepartitionInputTestFile = new DataFile();
	diffAssemblySpikeRepartitionInputTestFile = new DataFile();
			#endif
		#endif
	#endif
#endif
	
	openStater();
}

InputTester::~InputTester()
{
	closeStater();
	

#ifdef _GLOBAL_STAT_MODE
	#ifdef _MULTI_TEST_MODE	
		#ifdef _PARAMETRIC_TEST_MODE
	delete(timeFrequencyInputTestFile);
	delete(highTimeFrequencyInputTestFile);
			#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	delete(excitTempDevRepartitionInputTestFile);
	delete(inhibTempDevRepartitionInputTestFile);
			#endif
			
	delete(ISIRepartitionInputTestFile);
			#ifdef _PHASE_TEST_MODE

	delete(diffTimeFrequencyInputTestFile);
	delete(diffHighTimeFrequencyInputTestFile);
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	delete(diffExcitTempDevRepartitionInputTestFile);
	delete(diffInhibTempDevRepartitionInputTestFile);
				#endif
				
	delete(diffISIRepartitionInputTestFile);
			#endif
		#else
			#ifdef _PHASE_TEST_MODE
	
	delete(timeFrequencyInputTestFile);
	delete(highTimeFrequencyInputTestFile);
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	delete(excitTempDevRepartitionInputTestFile);
	delete(inhibTempDevRepartitionInputTestFile);
				#endif
	delete(ISIRepartitionInputTestFile);
	delete(SpikeRepartitionInputTestFile);
	delete(AssemblySpikeRepartitionInputTestFile);
	
	delete(diffTimeFrequencyInputTestFile);
	delete(diffHighTimeFrequencyInputTestFile);
	
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	delete(diffExcitTempDevRepartitionInputTestFile);
	delete(diffInhibTempDevRepartitionInputTestFile);
				#endif
				
	delete(diffISIRepartitionInputTestFile);
	delete(diffSpikeRepartitionInputTestFile);
	delete(diffAssemblySpikeRepartitionInputTestFile);
			#endif
		#endif
	delete(activityInputTestGnuplotFile);
	#endif
#endif	
}


#ifdef _GLOBAL_STAT_MODE
	#ifdef _MULTI_TEST_MODE
void InputTester::openTracer()
{
		#ifdef _PARAMETRIC_TEST_MODE
	if (timeFrequencyInputTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_timeFrequencyInputTestStats";
		timeFrequencyInputTestFile->openDataFile(oss.str());
	}

	if (highTimeFrequencyInputTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_highTimeFrequencyInputTestStats";
		highTimeFrequencyInputTestFile->openDataFile(oss.str());
	}
	
			#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	if (excitTempDevRepartitionInputTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_excitTempDevRepartitionInputTestStats";
		excitTempDevRepartitionInputTestFile->openDataFile(oss.str());
	}
	
	if (inhibTempDevRepartitionInputTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_inhibTempDevRepartitionInputTestStats";
		inhibTempDevRepartitionInputTestFile->openDataFile(oss.str());
	}
			#endif
			
	if (ISIRepartitionInputTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_ISIRepartitionInputTestStats";
		ISIRepartitionInputTestFile->openDataFile(oss.str());
	}
			#ifdef _PHASE_TEST_MODE

	if (diffTimeFrequencyInputTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_diffTimeFrequencyInputTestStats";
		diffTimeFrequencyInputTestFile->openDataFile(oss.str());
	}
	
	
	if (diffHighTimeFrequencyInputTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_diffHighTimeFrequencyInputTestStats";
		diffHighTimeFrequencyInputTestFile->openDataFile(oss.str());
	}

				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	if (diffExcitTempDevRepartitionInputTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_diffExcitTempDevRepartitionInputTestStats";
		diffExcitTempDevRepartitionInputTestFile->openDataFile(oss.str());
	}	
	
	
	if (diffInhibTempDevRepartitionInputTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_diffInhibTempDevRepartitionInputTestStats";
		diffInhibTempDevRepartitionInputTestFile->openDataFile(oss.str());
	}	
				#endif
				
	if (diffISIRepartitionInputTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_diffISIRepartitionInputTestStats";
		diffISIRepartitionInputTestFile->openDataFile(oss.str());
	}	
			#endif
		#else
			#ifdef _PHASE_TEST_MODE
	if (timeFrequencyInputTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_timeFrequencyInputTestStats";
		timeFrequencyInputTestFile->openDataFile(oss.str());
	}

	if (highTimeFrequencyInputTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_highTimeFrequencyInputTestStats";
		highTimeFrequencyInputTestFile->openDataFile(oss.str());
	}
	
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	if (excitTempDevRepartitionInputTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_excitTempDevRepartitionInputTestStats";
		excitTempDevRepartitionInputTestFile->openDataFile(oss.str());
	}
	
	if (inhibTempDevRepartitionInputTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_inhibTempDevRepartitionInputTestStats";
		inhibTempDevRepartitionInputTestFile->openDataFile(oss.str());
	}
				#endif
	
	if (ISIRepartitionInputTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_ISIRepartitionInputTestStats";
		ISIRepartitionInputTestFile->openDataFile(oss.str());
	}
	
	if (SpikeRepartitionInputTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_SpikeRepartitionInputTestStats";
		SpikeRepartitionInputTestFile->openDataFile(oss.str());
	}
	
	if (AssemblySpikeRepartitionInputTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_AssemblySpikeRepartitionInputTestStats";
		AssemblySpikeRepartitionInputTestFile->openDataFile(oss.str());
	}
	
	if (diffTimeFrequencyInputTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_diffTimeFrequencyInputTestStats";
		diffTimeFrequencyInputTestFile->openDataFile(oss.str());
	}
	
	
	if (diffHighTimeFrequencyInputTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_diffHighTimeFrequencyInputTestStats";
		diffHighTimeFrequencyInputTestFile->openDataFile(oss.str());
	}

				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	if (diffExcitTempDevRepartitionInputTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_diffExcitTempDevRepartitionInputTestStats";
		diffExcitTempDevRepartitionInputTestFile->openDataFile(oss.str());
	}	
	
	
	if (diffInhibTempDevRepartitionInputTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_diffInhibTempDevRepartitionInputTestStats";
		diffInhibTempDevRepartitionInputTestFile->openDataFile(oss.str());
	}	
				#endif
				
	if (diffISIRepartitionInputTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_diffISIRepartitionInputTestStats";
		diffISIRepartitionInputTestFile->openDataFile(oss.str());
	}	
	
	if (diffSpikeRepartitionInputTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_diffSpikeRepartitionInputTestStats";
		diffSpikeRepartitionInputTestFile->openDataFile(oss.str());
	}	
	
	if (diffAssemblySpikeRepartitionInputTestFile)
	{
		ostringstream oss;
		oss << "Indexed_Sorted_diffAssemblySpikeRepartitionInputTestStats";
		diffAssemblySpikeRepartitionInputTestFile->openDataFile(oss.str());
	}	
	
			#endif
		#endif	
}

void InputTester::closeTracer()
{
		#ifdef _PARAMETRIC_TEST_MODE
	if (timeFrequencyInputTestFile->isOpen())
	{
		timeFrequencyInputTestFile->closeFile();
		//timeFrequencyInputTestFile->formatFile();
	}
		
	if (highTimeFrequencyInputTestFile->isOpen())
	{
		highTimeFrequencyInputTestFile->closeFile();
		//highTimeFrequencyInputTestFile->formatFile();
	}
			#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	if (excitTempDevRepartitionInputTestFile->isOpen())
	{
		excitTempDevRepartitionInputTestFile->closeFile();
		//excitTempDevRepartitionInputTestFile->formatFile();
	}
	
	if (inhibTempDevRepartitionInputTestFile->isOpen())
	{
		inhibTempDevRepartitionInputTestFile->closeFile();
		//inhibTempDevRepartitionInputTestFile->formatFile();
	}
			#endif
			
	if (ISIRepartitionInputTestFile->isOpen())
	{
		ISIRepartitionInputTestFile->closeFile();
		//ISIRepartitionInputTestFile->formatFile();
	}
			#ifdef _PHASE_TEST_MODE

	if (diffTimeFrequencyInputTestFile->isOpen())
	{
		diffTimeFrequencyInputTestFile->closeFile();
		//timeFrequencyInputTestFile->formatFile();
	}
	
	if (diffHighTimeFrequencyInputTestFile->isOpen())
	{
		diffHighTimeFrequencyInputTestFile->closeFile();
		//diffHighTimeFrequencyInputTestFile->formatFile();
	}
	
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	if (diffExcitTempDevRepartitionInputTestFile->isOpen())
	{
		diffExcitTempDevRepartitionInputTestFile->closeFile();
		//diffExcitTempDevRepartitionInputTestFile->formatFile();
	}
	
	if (diffInhibTempDevRepartitionInputTestFile->isOpen())
	{
		diffInhibTempDevRepartitionInputTestFile->closeFile();
		//diffInhibTempDevRepartitionInputTestFile->formatFile();
	}
				#endif
				
	if (diffISIRepartitionInputTestFile->isOpen())
	{
		diffISIRepartitionInputTestFile->closeFile();
		//diffExcitTempDevRepartitionInputTestFile->formatFile();
	}
			#endif
		#else
			#ifdef _PHASE_TEST_MODE
	if (timeFrequencyInputTestFile->isOpen())
	{
		timeFrequencyInputTestFile->closeFile();
		//timeFrequencyInputTestFile->formatFile();
	}
		
	if (highTimeFrequencyInputTestFile->isOpen())
	{
		highTimeFrequencyInputTestFile->closeFile();
		//highTimeFrequencyInputTestFile->formatFile();
	}
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	if (excitTempDevRepartitionInputTestFile->isOpen())
	{
		excitTempDevRepartitionInputTestFile->closeFile();
		//excitTempDevRepartitionInputTestFile->formatFile();
	}
	
	if (inhibTempDevRepartitionInputTestFile->isOpen())
	{
		inhibTempDevRepartitionInputTestFile->closeFile();
		//inhibTempDevRepartitionInputTestFile->formatFile();
	}
				#endif
				
	if (ISIRepartitionInputTestFile->isOpen())
	{
		ISIRepartitionInputTestFile->closeFile();
		//ISIRepartitionInputTestFile->formatFile();
	}
	
	if (SpikeRepartitionInputTestFile->isOpen())
	{
		SpikeRepartitionInputTestFile->closeFile();
				#ifdef _SORT_ASSEMBLY_STAT_MODE
		SpikeRepartitionInputTestFile->formatIndexedValuesFile();
				#endif
	}
	
	if (AssemblySpikeRepartitionInputTestFile->isOpen())
	{
		AssemblySpikeRepartitionInputTestFile->closeFile();
				#ifdef _SORT_ASSEMBLY_STAT_MODE
		AssemblySpikeRepartitionInputTestFile->formatIndexedValuesFile();
				#endif
	}
	
	if (diffTimeFrequencyInputTestFile->isOpen())
	{
		diffTimeFrequencyInputTestFile->closeFile();
		//timeFrequencyInputTestFile->formatFile();
	}
	
	if (diffHighTimeFrequencyInputTestFile->isOpen())
	{
		diffHighTimeFrequencyInputTestFile->closeFile();
		//diffHighTimeFrequencyInputTestFile->formatFile();
	}
	
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	if (diffExcitTempDevRepartitionInputTestFile->isOpen())
	{
		diffExcitTempDevRepartitionInputTestFile->closeFile();
		//diffExcitTempDevRepartitionInputTestFile->formatFile();
	}
	
	if (diffInhibTempDevRepartitionInputTestFile->isOpen())
	{
		diffInhibTempDevRepartitionInputTestFile->closeFile();
		//diffInhibTempDevRepartitionInputTestFile->formatFile();
	}
				#endif
				
	if (diffISIRepartitionInputTestFile->isOpen())
	{
		diffISIRepartitionInputTestFile->closeFile();
		//diffExcitTempDevRepartitionInputTestFile->formatFile();
	}
	
	if (diffSpikeRepartitionInputTestFile->isOpen())
	{
		diffSpikeRepartitionInputTestFile->closeFile();
				#ifdef _SORT_ASSEMBLY_STAT_MODE
		diffSpikeRepartitionInputTestFile->formatIndexedValuesFile();
				#endif
	}
	
	if (diffAssemblySpikeRepartitionInputTestFile->isOpen())
	{
		diffAssemblySpikeRepartitionInputTestFile->closeFile();
				#ifdef _SORT_ASSEMBLY_STAT_MODE
		diffAssemblySpikeRepartitionInputTestFile->formatIndexedValuesFile();
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
	/*
	traceMeanIndexedFiles("preDelayRepartitionStats");
	traceMeanIndexedFiles("postDelayRepartitionStats");
	
	traceMeanIndexedFiles("tempDevRepartitionStats");
	
	traceMeanFiles("LFPStats");
	traceMeanFiles("STAStats");
	*/
}

void InputTester::openGrapher()
{
	if (activityInputTestGnuplotFile)
	{
		activityInputTestGnuplotFile->openGnuplotFile("ActivityInputTestStat");
	}
	else
	{
		cerr << "Warning, activityInputTestGnuplotFile is not inited" << endl;
	}
}

void InputTester::runGrapher()
{
	if (activityInputTestGnuplotFile)
	{
		activityInputTestGnuplotFile->systemFile();
	}
	else
	{
		cerr << "Warning, neuronGnuplotFile is not inited" << endl;
	}
}

void InputTester::closeGrapher()
{
	if (activityInputTestGnuplotFile->isOpen())
	{
		activityInputTestGnuplotFile->closeFile();
	}
	else
	{
		cerr << "Warning, neuronGnuplotFile is not open" << endl;
	}
}

void InputTester::traceMeanFiles(string dataFileName)
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

void InputTester::traceMeanIndexedFiles(string dataFileName)
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

void InputTester::traceTemporalMeanIndexedFiles(string dataFileName)
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

void InputTester::traceTemporalMeanNegativeIndexedFiles(string dataFileName)
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

void InputTester::trace()
{
		#ifdef _PARAMETRIC_TEST_MODE
			#ifdef _PHASE_TEST_MODE
				#ifdef _CONDITIONAL_TEST_MODE
	if (timeFrequencyInputTestFile->isOpen() && diffTimeFrequencyInputTestFile->isOpen())
	{
		if (timeFrequencyInputTest)
		{
			for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
			{
				for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
				{
					for (int i=0;i<NB_FREQUENCY_BINS;i++)
					{
						if (!timeFrequencyInputTest[i][j][k].isVoid())
						{
							timeFrequencyInputTestFile->addIndexedLineData(k*(1+2*NB_TESTED_ANIMALS+1)+j,i*5,(double) timeFrequencyInputTest[i][j][k].getMean());
						}
						else
						{
							//cout << "timeFrequencyInputTest  is void" << endl;
							timeFrequencyInputTestFile->addIndexedLineData(k*(1+2*NB_TESTED_ANIMALS+1)+j,i*5,-1.0);
						}
					}
				
					timeFrequencyInputTestFile->addDataSeparator();
				}
			}
			
			for (int i=0;i<NB_FREQUENCY_BINS;i++)
			{
				if (!timeFrequencyInputTest[i][0][0].isVoid() && !timeFrequencyInputTest[i][0][1].isVoid())
				{
					diffTimeFrequencyInputTestFile->addIndexedLineData(0,i*5,(double) timeFrequencyInputTest[i][0][0].getMean()-timeFrequencyInputTest[i][0][1].getMean());
				}
				else
				{
					//cout << "timeFrequencyInputTest  is void" << endl;
					diffTimeFrequencyInputTestFile->addIndexedLineData(0,i*5,-1.0);
				}
			}
			
			diffTimeFrequencyInputTestFile->addDataSeparator();
		
			for (int i=0;i<NB_FREQUENCY_BINS;i++)
			{
				if (!timeFrequencyInputTest[i][1][0].isVoid() && !timeFrequencyInputTest[i][1][1].isVoid())
				{
					diffTimeFrequencyInputTestFile->addIndexedLineData(1,i*5,(double) timeFrequencyInputTest[i][1][0].getMean()-timeFrequencyInputTest[i][1][1].getMean());
				}
				else
				{
					//cout << "diffTimeFrequencyInputTestFile  is void" << endl;
					diffTimeFrequencyInputTestFile->addIndexedLineData(1,i*5,-1.0);
				}
			}
				
			diffTimeFrequencyInputTestFile->addDataSeparator();
			
			for (int i=0;i<NB_FREQUENCY_BINS;i++)
			{
				if (!timeFrequencyInputTest[i][2][0].isVoid() && !timeFrequencyInputTest[i][2][1].isVoid())
				{
					diffTimeFrequencyInputTestFile->addIndexedLineData(2,i*5,(double) timeFrequencyInputTest[i][2][0].getMean()-timeFrequencyInputTest[i][2][1].getMean());
				}
				else
				{
					//cout << "diffTimeFrequencyInputTestFile  is void" << endl;
					diffTimeFrequencyInputTestFile->addIndexedLineData(2,i*5,-1.0);
				}
			}
				
			diffTimeFrequencyInputTestFile->addDataSeparator();
			
			for (int i=0;i<NB_FREQUENCY_BINS;i++)
			{
				if (!timeFrequencyInputTest[i][3][0].isVoid() && !timeFrequencyInputTest[i][3][1].isVoid())
				{
					diffTimeFrequencyInputTestFile->addIndexedLineData(3,i*5,(double) timeFrequencyInputTest[i][3][0].getMean()-timeFrequencyInputTest[i][3][1].getMean());
				}
				else
				{
					//cout << "diffTimeFrequencyInputTestFile  is void" << endl;
					diffTimeFrequencyInputTestFile->addIndexedLineData(3,i*5,-1.0);
				}
			}
				
			diffTimeFrequencyInputTestFile->addDataSeparator();
		
		}
	}
	else
	{
		cerr << "Warning, timeFrequencyInputTestFile && diffTimeFrequencyInputTestFile should be inited" << endl;
	}
				#else
	if (timeFrequencyInputTestFile->isOpen())
	{
		if (timeFrequencyInputTest)
		{
			for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
			{
				for (int i=0;i<NB_FREQUENCY_BINS;i++)
				{
					if (!timeFrequencyInputTest[i][1][k].isVoid())
					{
						timeFrequencyInputTestFile->addIndexedLineData(k,i*5,(double) timeFrequencyInputTest[i][1][k].getMean());
					}
					else
					{
						//cout << "timeFrequencyInputTestFile  is void" << endl;
						timeFrequencyInputTestFile->addIndexedLineData(k,i*5,-1.0);
					}
				}

				timeFrequencyInputTestFile->addDataSeparator();
			}
		}
	}
	else
	{
		cerr << "Warning, timeFrequencyInputTestFile should be inited" << endl;
	}
		
	if (diffTimeFrequencyInputTestFile->isOpen())
	{
		if (diffTimeFrequencyInputTestFile)
		{
			for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
			{
				for (int i=0;i<NB_FREQUENCY_BINS;i++)
				{
					if (!timeFrequencyInputTest[i][0][k].isVoid())
					{
						diffTimeFrequencyInputTestFile->addIndexedLineData(k,i*5,(double) (timeFrequencyInputTest[i][1][k].getMean()-timeFrequencyInputTest[i][0][k].getMean()));
					}
					else
					{
						//cout << "diffTimeFrequencyInputTestFile  is void" << endl;
						diffTimeFrequencyInputTestFile->addIndexedLineData(k,i*5,-1.0);
					}
				}

				diffTimeFrequencyInputTestFile->addDataSeparator();
			}
		}
	}
	else
	{
		cerr << "Warning, diffTimeFrequencyInputTestFile should be inited" << endl;
	}
				#endif
			#else
	if (timeFrequencyInputTestFile->isOpen())
	{
		if (timeFrequencyInputTest)
		{
			for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
			{
				for (int i=0;i<NB_FREQUENCY_BINS;i++)
				{
					if (!timeFrequencyInputTest[i][k].isVoid())
					{
						timeFrequencyInputTestFile->addIndexedLineData(k,i*5,(double) timeFrequencyInputTest[i][k].getMean());
					}
					else
					{
						//cout << "timeFrequencyInputTestFile  is void" << endl;
						timeFrequencyInputTestFile->addIndexedLineData(k,i*5,-1.0);
					}
				}

				timeFrequencyInputTestFile->addDataSeparator();
			}
		}
	}
	else
	{
		cerr << "Warning, timeFrequencyInputTestFile should be inited" << endl;
	}
			#endif

		#else	
			#ifdef _PHASE_TEST_MODE
	if (timeFrequencyInputTestFile->isOpen() && diffTimeFrequencyInputTestFile->isOpen())
	{
		if (timeFrequencyInputTest)
		{
				#ifdef _TRANSITION_STAT_MODE
			for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<NB_FREQUENCY_BINS;i++)
				{
					if (!timeFrequencyInputTest[i][j].isVoid())
					{
						if (j%2==0)
						{
							timeFrequencyInputTestFile->addIndexedLineData(j,i*5,(double) timeFrequencyInputTest[i][j].getAccu()/((double) EDNetwork::TRANSITION_TIME_LENGTH));
						}
						else
						{
							timeFrequencyInputTestFile->addIndexedLineData(j,i*5,(double) timeFrequencyInputTest[i][j].getAccu()/((double) (NB_MAX_TEST_STEPS-EDNetwork::EDNetwork::TRANSITION_TIME_LENGTH)));
						}
						//timeFrequencyInputTestFile->addIndexedLineData(j,i*5,(double) timeFrequencyInputTest[i][j].getMean());
					}
					else
					{
						//cout << "timeFrequencyInputTestFile  is void" << endl;
						timeFrequencyInputTestFile->addIndexedLineData(j,i*5,-1.0);
					}
				}
				
				timeFrequencyInputTestFile->addDataSeparator();
			}
			
			for (int i=0;i<NB_FREQUENCY_BINS;i++)
			{
				if (!timeFrequencyInputTest[i][0].isVoid() && !timeFrequencyInputTest[i][1].isVoid())
				{
					diffTimeFrequencyInputTestFile->addIndexedLineData(0,i*5,(double) timeFrequencyInputTest[i][0].getAccu()/((double) EDNetwork::TRANSITION_TIME_LENGTH)-timeFrequencyInputTest[i][1].getAccu()/((double) (NB_MAX_TEST_STEPS-EDNetwork::EDNetwork::TRANSITION_TIME_LENGTH)));
				}
				else
				{
					//cout << "diffTimeFrequencyInputTestFile  is void" << endl;
					diffTimeFrequencyInputTestFile->addIndexedLineData(0,i*5,-1.0);
				}
			}
				
			diffTimeFrequencyInputTestFile->addDataSeparator();
			
			for (int i=0;i<NB_FREQUENCY_BINS;i++)
			{
				if (!timeFrequencyInputTest[i][2].isVoid() && !timeFrequencyInputTest[i][3].isVoid())
				{	
					diffTimeFrequencyInputTestFile->addIndexedLineData(1,i*5,(double) timeFrequencyInputTest[i][2].getAccu()/((double) EDNetwork::TRANSITION_TIME_LENGTH)-timeFrequencyInputTest[i][3].getAccu()/((double) (NB_MAX_TEST_STEPS-EDNetwork::EDNetwork::TRANSITION_TIME_LENGTH)));

				}
				else
				{
					//cout << "diffTimeFrequencyInputTestFile  is void" << endl;
					diffTimeFrequencyInputTestFile->addIndexedLineData(1,i*5,-1.0);
				}
			}
				
			diffTimeFrequencyInputTestFile->addDataSeparator();
			
			for (int i=0;i<NB_FREQUENCY_BINS;i++)
			{
				if (!timeFrequencyInputTest[i][4].isVoid() && !timeFrequencyInputTest[i][5].isVoid())
				{
					diffTimeFrequencyInputTestFile->addIndexedLineData(2,i*5,(double) timeFrequencyInputTest[i][4].getAccu()/((double) EDNetwork::TRANSITION_TIME_LENGTH)-timeFrequencyInputTest[i][5].getAccu()/((double) (NB_MAX_TEST_STEPS-EDNetwork::EDNetwork::TRANSITION_TIME_LENGTH)));
				}
				else
				{
					//cout << "diffTimeFrequencyInputTestFile  is void" << endl;
					diffTimeFrequencyInputTestFile->addIndexedLineData(2,i*5,-1.0);
				}
			}
				
			diffTimeFrequencyInputTestFile->addDataSeparator();
			
			for (int i=0;i<NB_FREQUENCY_BINS;i++)
			{
				if (!timeFrequencyInputTest[i][6].isVoid() && !timeFrequencyInputTest[i][7].isVoid())
				{
					diffTimeFrequencyInputTestFile->addIndexedLineData(3,i*5,(double) timeFrequencyInputTest[i][6].getAccu()/((double) EDNetwork::TRANSITION_TIME_LENGTH)-timeFrequencyInputTest[i][7].getAccu()/((double) (NB_MAX_TEST_STEPS-EDNetwork::EDNetwork::TRANSITION_TIME_LENGTH)));
				}
				else
				{
					//cout << "diffTimeFrequencyInputTestFile  is void" << endl;
					diffTimeFrequencyInputTestFile->addIndexedLineData(3,i*5,-1.0);
				}
			}
				
			diffTimeFrequencyInputTestFile->addDataSeparator();
			
				#else
			for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<NB_FREQUENCY_BINS;i++)
				{
					if (!timeFrequencyInputTest[i][j].isVoid())
					{
						timeFrequencyInputTestFile->addIndexedLineData(j,i*5,(double) timeFrequencyInputTest[i][j].getMean());
					}
					else
					{
						//cout << "timeFrequencyInputTestFile  is void" << endl;
						timeFrequencyInputTestFile->addIndexedLineData(j,i*5,-1.0);
					}
				}
				
				timeFrequencyInputTestFile->addDataSeparator();
			}
			
			for (int i=0;i<NB_FREQUENCY_BINS;i++)
			{
				if (!timeFrequencyInputTest[i][0].isVoid() && !timeFrequencyInputTest[i][1].isVoid())
				{
					diffTimeFrequencyInputTestFile->addIndexedLineData(0,i*5,(double) timeFrequencyInputTest[i][1].getMean()-timeFrequencyInputTest[i][0].getMean());
				}
				else
				{
					//cout << "diffTimeFrequencyInputTestFile  is void" << endl;
					diffTimeFrequencyInputTestFile->addIndexedLineData(0,i*5,-1.0);
				}
			}
				
			diffTimeFrequencyInputTestFile->addDataSeparator();
			
			for (int i=0;i<NB_FREQUENCY_BINS;i++)
			{
				if (!timeFrequencyInputTest[i][0].isVoid() && !timeFrequencyInputTest[i][2].isVoid())
				{
					diffTimeFrequencyInputTestFile->addIndexedLineData(1,i*5,(double) timeFrequencyInputTest[i][2].getMean()-timeFrequencyInputTest[i][0].getMean());
				}
				else
				{
					//cout << "diffTimeFrequencyInputTestFile  is void" << endl;
					diffTimeFrequencyInputTestFile->addIndexedLineData(1,i*5,-1.0);
				}
			}
				
			diffTimeFrequencyInputTestFile->addDataSeparator();
			
			for (int i=0;i<NB_FREQUENCY_BINS;i++)
			{
				if (!timeFrequencyInputTest[i][0].isVoid() && !timeFrequencyInputTest[i][3].isVoid())
				{
					diffTimeFrequencyInputTestFile->addIndexedLineData(2,i*5,(double) timeFrequencyInputTest[i][3].getMean()-timeFrequencyInputTest[i][0].getMean());
				}
				else
				{
					//cout << "diffTimeFrequencyInputTestFile  is void" << endl;
					diffTimeFrequencyInputTestFile->addIndexedLineData(2,i*5,-1.0);
				}
			}
				
			diffTimeFrequencyInputTestFile->addDataSeparator();
				#endif
		}
	}
	else
	{
		cerr << "Warning, timeFrequencyInputTestFile && diffTimeFrequencyInputTestFile should be inited" << endl;
	}
			#endif
		#endif
	
		#ifdef _PARAMETRIC_TEST_MODE
			#ifdef _PHASE_TEST_MODE
				#ifdef _CONDITIONAL_TEST_MODE
	if (highTimeFrequencyInputTestFile->isOpen() && diffHighTimeFrequencyInputTestFile->isOpen())
	{
		if (highTimeFrequencyInputTest)
		{
			for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
			{
				for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
				{
					for (int i=0;i<NB_FREQUENCY_BINS;i++)
					{
						if (!highTimeFrequencyInputTest[i][j][k].isVoid())
						{
							highTimeFrequencyInputTestFile->addIndexedLineData(k*(1+2*NB_TESTED_ANIMALS+1)+j,i*5,(double) highTimeFrequencyInputTest[i][j][k].getMean());
						}
						else
						{
							//cout << "highTimeFrequencyInputTestFile  is void" << endl;
							highTimeFrequencyInputTestFile->addIndexedLineData(k*(1+2*NB_TESTED_ANIMALS+1)+j,i*5,-1.0);
						}
					}
				
					highTimeFrequencyInputTestFile->addDataSeparator();
				}
			}
			
			for (int i=0;i<NB_FREQUENCY_BINS;i++)
			{
				if (!highTimeFrequencyInputTest[i][0][0].isVoid() && !highTimeFrequencyInputTest[i][0][1].isVoid())
				{
					diffHighTimeFrequencyInputTestFile->addIndexedLineData(0,i*5,(double) highTimeFrequencyInputTest[i][0][0].getMean()-highTimeFrequencyInputTest[i][0][1].getMean());
				}
				else
				{
					//cout << "diffHighTimeFrequencyInputTestFile  is void" << endl;
					diffHighTimeFrequencyInputTestFile->addIndexedLineData(0,i*5,-1.0);
				}
			}
			
			diffHighTimeFrequencyInputTestFile->addDataSeparator();
			
			
			for (int i=0;i<NB_FREQUENCY_BINS;i++)
			{
				if (!highTimeFrequencyInputTest[i][1][0].isVoid() && !highTimeFrequencyInputTest[i][1][1].isVoid())
				{
					diffHighTimeFrequencyInputTestFile->addIndexedLineData(1,i*5,(double) highTimeFrequencyInputTest[i][1][0].getMean()-highTimeFrequencyInputTest[i][1][1].getMean());
				}
				else
				{
					//cout << "diffHighTimeFrequencyInputTestFile  is void" << endl;
					diffHighTimeFrequencyInputTestFile->addIndexedLineData(1,i*5,-1.0);
				}
			}
			
			diffHighTimeFrequencyInputTestFile->addDataSeparator();
			
			
			for (int i=0;i<NB_FREQUENCY_BINS;i++)
			{
				if (!highTimeFrequencyInputTest[i][2][0].isVoid() && !highTimeFrequencyInputTest[i][2][1].isVoid())
				{
					diffHighTimeFrequencyInputTestFile->addIndexedLineData(2,i*5,(double) highTimeFrequencyInputTest[i][2][0].getMean()-highTimeFrequencyInputTest[i][2][1].getMean());
				}
				else
				{
					//cout << "diffHighTimeFrequencyInputTestFile  is void" << endl;
					diffHighTimeFrequencyInputTestFile->addIndexedLineData(2,i*5,-1.0);
				}
			}
			
			diffHighTimeFrequencyInputTestFile->addDataSeparator();
			
			for (int i=0;i<NB_FREQUENCY_BINS;i++)
			{
				if (!highTimeFrequencyInputTest[i][3][0].isVoid() && !highTimeFrequencyInputTest[i][3][1].isVoid())
				{
					diffHighTimeFrequencyInputTestFile->addIndexedLineData(3,i*5,(double) highTimeFrequencyInputTest[i][3][0].getMean()-highTimeFrequencyInputTest[i][3][1].getMean());
				}
				else
				{
					//cout << "diffHighTimeFrequencyInputTestFile  is void" << endl;
					diffHighTimeFrequencyInputTestFile->addIndexedLineData(3,i*5,-1.0);
				}
			}
			
			diffHighTimeFrequencyInputTestFile->addDataSeparator();

		}
	}
	else
	{
		cerr << "Warning, highTimeFrequencyInputTestFile && diffHighTimeFrequencyInputTestFile should be inited" << endl;
	}
				#else
	if (highTimeFrequencyInputTestFile->isOpen())
	{
		if (highTimeFrequencyInputTest)
		{
			for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
			{
				for (int i=0;i<NB_FREQUENCY_BINS;i++)
				{
					if (!highTimeFrequencyInputTest[i][1][k].isVoid())
					{
						highTimeFrequencyInputTestFile->addIndexedLineData(k,i*HIGH_FREQUENCY_BIN_LENGTH,(double) highTimeFrequencyInputTest[i][1][k].getMean());
					}
					else
					{
						//cout << "highTimeFrequencyInputTestFile  is void" << endl;
						highTimeFrequencyInputTestFile->addIndexedLineData(k,i*HIGH_FREQUENCY_BIN_LENGTH,-1.0);
					}
				}

				highTimeFrequencyInputTestFile->addDataSeparator();
			}
		}
	}
	else
	{
		cerr << "Warning, highTimeFrequencyInputTestFile should be inited" << endl;
	}

	
	if (diffHighTimeFrequencyInputTestFile->isOpen())
	{	
		if (diffHighTimeFrequencyInputTestFile)
		{
			for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
			{
				for (int i=0;i<NB_FREQUENCY_BINS;i++)
				{
					if (!highTimeFrequencyInputTest[i][0][k].isVoid())
					{
						diffHighTimeFrequencyInputTestFile->addIndexedLineData(k,i*HIGH_FREQUENCY_BIN_LENGTH,(double) (highTimeFrequencyInputTest[i][1][k].getMean()-highTimeFrequencyInputTest[i][0][k].getMean()));
					}
					else
					{
						//cout << "diffHighTimeFrequencyInputTestFile  is void" << endl;
						diffHighTimeFrequencyInputTestFile->addIndexedLineData(k,i*HIGH_FREQUENCY_BIN_LENGTH,-1.0);
					}
				}

				diffHighTimeFrequencyInputTestFile->addDataSeparator();
			}
		}
	}
	else
	{
		cerr << "Warning, diffHighTimeFrequencyInputTestFile should be inited" << endl;
	}
	
				#endif
			#else
	if (highTimeFrequencyInputTestFile->isOpen())
	{
		if (highTimeFrequencyInputTest)
		{
			for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
			{
				for (int i=0;i<NB_FREQUENCY_BINS;i++)
				{
					if (!highTimeFrequencyInputTest[i][k].isVoid())
					{
						highTimeFrequencyInputTestFile->addIndexedLineData(k,i*HIGH_FREQUENCY_BIN_LENGTH,(double) highTimeFrequencyInputTest[i][k].getMean());
					}
					else
					{
						//cout << "highTimeFrequencyInputTestFile  is void" << endl;
						highTimeFrequencyInputTestFile->addIndexedLineData(k,i*HIGH_FREQUENCY_BIN_LENGTH,-1.0);
					}
					
				}

				highTimeFrequencyInputTestFile->addDataSeparator();
			}
		}
	}
	else
	{
		cerr << "Warning, highTimeFrequencyInputTestFile should be inited" << endl;
	}
			#endif
		#else	
			#ifdef _PHASE_TEST_MODE	
	if (highTimeFrequencyInputTestFile->isOpen() && diffHighTimeFrequencyInputTestFile->isOpen())
	{
		if (highTimeFrequencyInputTest)
		{	
				#ifdef _TRANSITION_STAT_MODE
			for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
				{
					if (!highTimeFrequencyInputTest[i][j].isVoid())
					{
						if (j%2==0)
						{
							highTimeFrequencyInputTestFile->addIndexedLineData(j,i*HIGH_FREQUENCY_BIN_LENGTH,(double) highTimeFrequencyInputTest[i][j].getAccu()/((double) EDNetwork::TRANSITION_TIME_LENGTH));
						}
						else
						{
							highTimeFrequencyInputTestFile->addIndexedLineData(j,i*HIGH_FREQUENCY_BIN_LENGTH,(double) highTimeFrequencyInputTest[i][j].getAccu()/((double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)));
						}
						//highTimeFrequencyInputTestFile->addIndexedLineData(j,i*HIGH_FREQUENCY_BIN_LENGTH,(double) highTimeFrequencyInputTest[i][j].getAccu());
					}
					else
					{
						//cout << "highTimeFrequencyInputTestFile  is void" << endl;
						highTimeFrequencyInputTestFile->addIndexedLineData(j,i*HIGH_FREQUENCY_BIN_LENGTH,-1.0);
					}
				}
				
				highTimeFrequencyInputTestFile->addDataSeparator();
			}
			
			
			for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
			{
				if (!highTimeFrequencyInputTest[i][0].isVoid() && !highTimeFrequencyInputTest[i][1].isVoid())
				{
					diffHighTimeFrequencyInputTestFile->addIndexedLineData(0,i*HIGH_FREQUENCY_BIN_LENGTH,(double) highTimeFrequencyInputTest[i][0].getAccu()/((double) EDNetwork::TRANSITION_TIME_LENGTH)-highTimeFrequencyInputTest[i][1].getAccu()/((double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)));
				}
				else
				{
					//cout << "diffHighTimeFrequencyInputTestFile  is void" << endl;
					diffHighTimeFrequencyInputTestFile->addIndexedLineData(0,i*HIGH_FREQUENCY_BIN_LENGTH,-1.0);
				}
			}
				
			diffHighTimeFrequencyInputTestFile->addDataSeparator();
			
			for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
			{
				if (!highTimeFrequencyInputTest[i][2].isVoid() && !highTimeFrequencyInputTest[i][3].isVoid())
				{
					diffHighTimeFrequencyInputTestFile->addIndexedLineData(0,i*HIGH_FREQUENCY_BIN_LENGTH,(double) highTimeFrequencyInputTest[i][2].getAccu()/((double) EDNetwork::TRANSITION_TIME_LENGTH)-highTimeFrequencyInputTest[i][3].getAccu()/((double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)));
					
				}
				else
				{
					//cout << "diffHighTimeFrequencyInputTestFile  is void" << endl;
					diffHighTimeFrequencyInputTestFile->addIndexedLineData(1,i*HIGH_FREQUENCY_BIN_LENGTH,-1.0);
				}
			}
				
			diffHighTimeFrequencyInputTestFile->addDataSeparator();
			
			for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
			{
				if (!highTimeFrequencyInputTest[i][4].isVoid() && !highTimeFrequencyInputTest[i][5].isVoid())
				{
					diffHighTimeFrequencyInputTestFile->addIndexedLineData(2,i*HIGH_FREQUENCY_BIN_LENGTH,(double) highTimeFrequencyInputTest[i][4].getAccu()/((double) EDNetwork::TRANSITION_TIME_LENGTH)-highTimeFrequencyInputTest[i][5].getAccu()/((double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)));
				}
				else
				{
					//cout << "diffHighTimeFrequencyInputTestFile  is void" << endl;
					diffHighTimeFrequencyInputTestFile->addIndexedLineData(2,i*HIGH_FREQUENCY_BIN_LENGTH,-1.0);
				}
			}
				
			diffHighTimeFrequencyInputTestFile->addDataSeparator();
			
			for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
			{
				if (!highTimeFrequencyInputTest[i][6].isVoid() && !highTimeFrequencyInputTest[i][7].isVoid())
				{
					diffHighTimeFrequencyInputTestFile->addIndexedLineData(3,i*HIGH_FREQUENCY_BIN_LENGTH,(double) highTimeFrequencyInputTest[i][6].getAccu()/((double) EDNetwork::TRANSITION_TIME_LENGTH)-highTimeFrequencyInputTest[i][7].getAccu()/((double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)));
				}
				else
				{
					//cout << "diffHighTimeFrequencyInputTestFile  is void" << endl;
					diffHighTimeFrequencyInputTestFile->addIndexedLineData(3,i*HIGH_FREQUENCY_BIN_LENGTH,-1.0);
				}
			}
				
			diffHighTimeFrequencyInputTestFile->addDataSeparator();
			
				#else
			
			for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
				{
					if (!highTimeFrequencyInputTest[i][j].isVoid())
					{
						highTimeFrequencyInputTestFile->addIndexedLineData(j,i*HIGH_FREQUENCY_BIN_LENGTH,(double) highTimeFrequencyInputTest[i][j].getMean());
					}
					else
					{
						//cout << "highTimeFrequencyInputTestFile  is void" << endl;
						highTimeFrequencyInputTestFile->addIndexedLineData(j,i*HIGH_FREQUENCY_BIN_LENGTH,-1.0);
					}
				}
				
				highTimeFrequencyInputTestFile->addDataSeparator();
			}
			
			
			for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
			{
				if (!highTimeFrequencyInputTest[i][0].isVoid() && !highTimeFrequencyInputTest[i][1].isVoid())
				{
					diffHighTimeFrequencyInputTestFile->addIndexedLineData(0,i*HIGH_FREQUENCY_BIN_LENGTH,(double) highTimeFrequencyInputTest[i][1].getMean()-highTimeFrequencyInputTest[i][0].getMean());
				}
				else
				{
					//cout << "diffHighTimeFrequencyInputTestFile  is void" << endl;
					diffHighTimeFrequencyInputTestFile->addIndexedLineData(0,i*HIGH_FREQUENCY_BIN_LENGTH,-1.0);
				}
			}
				
			diffHighTimeFrequencyInputTestFile->addDataSeparator();
			
			for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
			{
				if (!highTimeFrequencyInputTest[i][0].isVoid() && !highTimeFrequencyInputTest[i][2].isVoid())
				{
					diffHighTimeFrequencyInputTestFile->addIndexedLineData(1,i*HIGH_FREQUENCY_BIN_LENGTH,(double) highTimeFrequencyInputTest[i][2].getMean()-highTimeFrequencyInputTest[i][0].getMean());
				}
				else
				{
					//cout << "diffHighTimeFrequencyInputTestFile  is void" << endl;
					diffHighTimeFrequencyInputTestFile->addIndexedLineData(1,i*HIGH_FREQUENCY_BIN_LENGTH,-1.0);
				}
			}
				
			diffHighTimeFrequencyInputTestFile->addDataSeparator();
			
			for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
			{
				if (!highTimeFrequencyInputTest[i][0].isVoid() && !highTimeFrequencyInputTest[i][3].isVoid())
				{
					diffHighTimeFrequencyInputTestFile->addIndexedLineData(2,i*HIGH_FREQUENCY_BIN_LENGTH,(double) highTimeFrequencyInputTest[i][3].getMean()-highTimeFrequencyInputTest[i][0].getMean());
				}
				else
				{
					//cout << "diffHighTimeFrequencyInputTestFile  is void" << endl;
					diffHighTimeFrequencyInputTestFile->addIndexedLineData(2,i*HIGH_FREQUENCY_BIN_LENGTH,-1.0);
				}
			}
				
			diffHighTimeFrequencyInputTestFile->addDataSeparator();
				#endif
		}
	}
	else
	{
		cerr << "Warning, highTimeFrequencyInputTestFile should be inited" << endl;
	}
		#endif
	#endif
	
		#ifdef _GLOBAL_SYNAPSE_STAT_MODE
			#ifdef _PARAMETRIC_TEST_MODE
				#ifdef _PHASE_TEST_MODE
					#ifdef _CONDITIONAL_TEST_MODE
	if (excitTempDevRepartitionInputTestFile->isOpen() && diffExcitTempDevRepartitionInputTestFile->isOpen())
	{
		for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
		{
			for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				if (excitPreTempDevRepartitionInputTest)
				{
					for (int i=0;i<100;i++)
					{
						if (!excitPreTempDevRepartitionInputTest[99-i][j][k].isVoid())
						{
							excitTempDevRepartitionInputTestFile->addIndexedLineData(k*(1+2*NB_TESTED_ANIMALS+1)+j,-(99-i),(double) excitPreTempDevRepartitionInputTest[99-i][j][k].getMean());
						}
						else
						{
							//cout << "excitTempDevRepartitionInputTestFile is void" << endl;
							excitTempDevRepartitionInputTestFile->addIndexedLineData(k*(1+2*NB_TESTED_ANIMALS+1)+j,-(99-i),-1.0);
						}
					}
				}
					
				if (excitPostTempDevRepartitionInputTest)
				{
					for (int i=0;i<100;i++)
					{
						if (!excitPostTempDevRepartitionInputTest[99-i][j][k].isVoid())
						{
							excitTempDevRepartitionInputTestFile->addIndexedLineData(k*(1+2*NB_TESTED_ANIMALS+1)+j,i,(double) excitPostTempDevRepartitionInputTest[i][j][k].getMean());
						}
						else
						{
							//cout << "excitTempDevRepartitionInputTestFile is void" << endl;
							excitTempDevRepartitionInputTestFile->addIndexedLineData(k*(1+2*NB_TESTED_ANIMALS+1)+j,i,-1.0);
						}
					}
				}
				
				excitTempDevRepartitionInputTestFile->addDataSeparator();
			}
		}	
		
		for (int i=0;i<100;i++)
		{
			if (!excitPreTempDevRepartitionInputTest[99-i][0][0].isVoid() && !excitPreTempDevRepartitionInputTest[99-i][0][1].isVoid())
			{
				diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(0,-(99-i),(double) excitPreTempDevRepartitionInputTest[99-i][0][0].getMean()-excitPreTempDevRepartitionInputTest[99-i][0][1].getMean());
			}
			else
			{
				//cout << "diffExcitTempDevRepartitionInputTestFile is void" << endl;
				diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(0,-(99-i),-1.0);
			}
						
		}
		
		for (int i=0;i<100;i++)
		{
			if (!excitPostTempDevRepartitionInputTest[i][0][0].isVoid() && !excitPostTempDevRepartitionInputTest[i][0][1].isVoid())
			{
				diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(0,i,(double) excitPostTempDevRepartitionInputTest[i][0][0].getMean()-excitPostTempDevRepartitionInputTest[i][0][1].getMean());
			}
			else
			{
				//cout << "diffExcitTempDevRepartitionInputTestFile is void" << endl;
				diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(0,i,-1.0);
			}
		}
			
		diffExcitTempDevRepartitionInputTestFile->addDataSeparator();
		
		for (int i=0;i<100;i++)
		{
			if (!excitPreTempDevRepartitionInputTest[99-i][1][0].isVoid() && !excitPreTempDevRepartitionInputTest[99-i][1][1].isVoid())
			{
				diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(1,-(99-i),(double) excitPreTempDevRepartitionInputTest[99-i][1][0].getMean()-excitPreTempDevRepartitionInputTest[99-i][1][1].getMean());
			}
			else
			{
				//cout << "diffExcitTempDevRepartitionInputTestFile is void" << endl;
				diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(1,-(99-i),-1.0);
			}
						
		}
		
		for (int i=0;i<100;i++)
		{
			if (!excitPostTempDevRepartitionInputTest[i][1][0].isVoid() && !excitPostTempDevRepartitionInputTest[i][1][1].isVoid())
			{
				diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(1,i,(double) excitPostTempDevRepartitionInputTest[i][1][0].getMean()-excitPostTempDevRepartitionInputTest[i][1][1].getMean());
			}
			else
			{
				//cout << "diffExcitTempDevRepartitionInputTestFile is void" << endl;
				diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(1,i,-1.0);
			}
		}
	
			
		diffExcitTempDevRepartitionInputTestFile->addDataSeparator();
		
		for (int i=0;i<100;i++)
		{
			if (!excitPreTempDevRepartitionInputTest[99-i][2][0].isVoid() && !excitPreTempDevRepartitionInputTest[99-i][2][1].isVoid())
			{
				diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(2,-(99-i),(double) excitPreTempDevRepartitionInputTest[99-i][2][0].getMean()-excitPreTempDevRepartitionInputTest[99-i][2][1].getMean());
			}
			else
			{
				//cout << "diffExcitTempDevRepartitionInputTestFile is void" << endl;
				diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(2,-(99-i),-1.0);
			}
						
		}
		
		for (int i=0;i<100;i++)
		{
			if (!excitPostTempDevRepartitionInputTest[i][2][0].isVoid() && !excitPostTempDevRepartitionInputTest[i][2][1].isVoid())
			{
				diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(2,i,(double) excitPostTempDevRepartitionInputTest[i][2][0].getMean()-excitPostTempDevRepartitionInputTest[i][2][1].getMean());
			}
			else
			{
				//cout << "diffExcitTempDevRepartitionInputTestFile is void" << endl;
				diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(2,i,-1.0);
			}
		}
		
		diffExcitTempDevRepartitionInputTestFile->addDataSeparator();
		
		for (int i=0;i<100;i++)
		{
			if (!excitPreTempDevRepartitionInputTest[99-i][3][0].isVoid() && !excitPreTempDevRepartitionInputTest[99-i][3][1].isVoid())
			{
				diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(3,-(99-i),(double) excitPreTempDevRepartitionInputTest[99-i][3][0].getMean()-excitPreTempDevRepartitionInputTest[99-i][3][1].getMean());
			}
			else
			{
				//cout << "diffExcitTempDevRepartitionInputTestFile is void" << endl;
				diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(3,-(99-i),-1.0);
			}
						
		}
		
		for (int i=0;i<100;i++)
		{
			if (!excitPostTempDevRepartitionInputTest[i][3][0].isVoid() && !excitPostTempDevRepartitionInputTest[i][3][1].isVoid())
			{
				diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(3,i,(double) excitPostTempDevRepartitionInputTest[i][3][0].getMean()-excitPostTempDevRepartitionInputTest[i][3][1].getMean());
			}
			else
			{
				//cout << "diffExcitTempDevRepartitionInputTestFile is void" << endl;
				diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(3,i,-1.0);
			}
		}
			
		diffExcitTempDevRepartitionInputTestFile->addDataSeparator();

	}
	else
	{
		cerr << "Warning, excitTempDevRepartitionInputTestFile && diffExcitTempDevRepartitionInputTestFile should be inited" << endl;
	}
	
	if (inhibTempDevRepartitionInputTestFile->isOpen() && diffInhibTempDevRepartitionInputTestFile->isOpen())
	{
		for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
		{
			for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				if (inhibPreTempDevRepartitionInputTest)
				{
					for (int i=0;i<100;i++)
					{
						if (!inhibPreTempDevRepartitionInputTest[99-i][j][k].isVoid())
						{
							inhibTempDevRepartitionInputTestFile->addIndexedLineData(k*(1+2*NB_TESTED_ANIMALS+1)+j,-(99-i),(double) inhibPreTempDevRepartitionInputTest[99-i][j][k].getMean());
						}
						else
						{
							//cout << "inhibTempDevRepartitionInputTestFile is void" << endl;
							inhibTempDevRepartitionInputTestFile->addIndexedLineData(k*(1+2*NB_TESTED_ANIMALS+1)+j,-(99-i),-1.0);
						}
					}
				}
					
				if (inhibPostTempDevRepartitionInputTest)
				{
					for (int i=0;i<100;i++)
					{
						if (!inhibPostTempDevRepartitionInputTest[99-i][j][k].isVoid())
						{
							inhibTempDevRepartitionInputTestFile->addIndexedLineData(k*(1+2*NB_TESTED_ANIMALS+1)+j,i,(double) inhibPostTempDevRepartitionInputTest[i][j][k].getMean());
						}
						else
						{
							//cout << "inhibTempDevRepartitionInputTestFile is void" << endl;
							inhibTempDevRepartitionInputTestFile->addIndexedLineData(k*(1+2*NB_TESTED_ANIMALS+1)+j,i,-1.0);
						}
					}
				}
				
				
				inhibTempDevRepartitionInputTestFile->addDataSeparator();
			}
		}	
		
		for (int i=0;i<100;i++)
		{
			if (!inhibPreTempDevRepartitionInputTest[99-i][0][0].isVoid() && !inhibPreTempDevRepartitionInputTest[99-i][0][1].isVoid())
			{
				diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(0,-(99-i),(double) inhibPreTempDevRepartitionInputTest[99-i][0][0].getMean()-inhibPreTempDevRepartitionInputTest[99-i][0][1].getMean());
			}
			else
			{
				//cout << "diffInhibTempDevRepartitionInputTestFile is void" << endl;
				diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(0,-(99-i),-1.0);
			}
						
		}
		
		for (int i=0;i<100;i++)
		{
			if (!inhibPostTempDevRepartitionInputTest[i][0][0].isVoid() && !inhibPostTempDevRepartitionInputTest[i][0][1].isVoid())
			{
				diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(0,i,(double) inhibPostTempDevRepartitionInputTest[i][0][0].getMean()-inhibPostTempDevRepartitionInputTest[i][0][1].getMean());
			}
			else
			{
				//cout << "diffInhibTempDevRepartitionInputTestFile is void" << endl;
				diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(0,i,-1.0);
			}
		}
			
		diffInhibTempDevRepartitionInputTestFile->addDataSeparator();
		
		for (int i=0;i<100;i++)
		{
			if (!inhibPreTempDevRepartitionInputTest[99-i][1][0].isVoid() && !inhibPreTempDevRepartitionInputTest[99-i][1][1].isVoid())
			{
				diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(1,-(99-i),(double) inhibPreTempDevRepartitionInputTest[99-i][1][0].getMean()-inhibPreTempDevRepartitionInputTest[99-i][1][1].getMean());
			}
			else
			{
				//cout << "diffInhibTempDevRepartitionInputTestFile is void" << endl;
				diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(1,-(99-i),-1.0);
			}
						
		}
		
		for (int i=0;i<100;i++)
		{
			if (!inhibPostTempDevRepartitionInputTest[i][1][0].isVoid() && !inhibPostTempDevRepartitionInputTest[i][1][1].isVoid())
			{
				diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(1,i,(double) inhibPostTempDevRepartitionInputTest[i][1][0].getMean()-inhibPostTempDevRepartitionInputTest[i][1][1].getMean());
			}
			else
			{
				//cout << "diffInhibTempDevRepartitionInputTestFile is void" << endl;
				diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(1,i,-1.0);
			}
		}
	
			
		diffInhibTempDevRepartitionInputTestFile->addDataSeparator();
		
		for (int i=0;i<100;i++)
		{
			if (!inhibPreTempDevRepartitionInputTest[99-i][2][0].isVoid() && !inhibPreTempDevRepartitionInputTest[99-i][2][1].isVoid())
			{
				diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(2,-(99-i),(double) inhibPreTempDevRepartitionInputTest[99-i][2][0].getMean()-inhibPreTempDevRepartitionInputTest[99-i][2][1].getMean());
			}
			else
			{
				//cout << "diffInhibTempDevRepartitionInputTestFile is void" << endl;
				diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(2,-(99-i),-1.0);
			}
						
		}
		
		for (int i=0;i<100;i++)
		{
			if (!inhibPostTempDevRepartitionInputTest[i][2][0].isVoid() && !inhibPostTempDevRepartitionInputTest[i][2][1].isVoid())
			{
				diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(2,i,(double) inhibPostTempDevRepartitionInputTest[i][2][0].getMean()-inhibPostTempDevRepartitionInputTest[i][2][1].getMean());
			}
			else
			{
				//cout << "diffInhibTempDevRepartitionInputTestFile is void" << endl;
				diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(2,i,-1.0);
			}
		}
		
		diffInhibTempDevRepartitionInputTestFile->addDataSeparator();
		
		for (int i=0;i<100;i++)
		{
			if (!inhibPreTempDevRepartitionInputTest[99-i][3][0].isVoid() && !inhibPreTempDevRepartitionInputTest[99-i][3][1].isVoid())
			{
				diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(3,-(99-i),(double) inhibPreTempDevRepartitionInputTest[99-i][3][0].getMean()-inhibPreTempDevRepartitionInputTest[99-i][3][1].getMean());
			}
			else
			{
				//cout << "diffInhibTempDevRepartitionInputTestFile is void" << endl;
				diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(3,-(99-i),-1.0);
			}
						
		}
		
		for (int i=0;i<100;i++)
		{
			if (!inhibPostTempDevRepartitionInputTest[i][3][0].isVoid() && !inhibPostTempDevRepartitionInputTest[i][3][1].isVoid())
			{
				diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(3,i,(double) inhibPostTempDevRepartitionInputTest[i][3][0].getMean()-inhibPostTempDevRepartitionInputTest[i][3][1].getMean());
			}
			else
			{
				//cout << "diffInhibTempDevRepartitionInputTestFile is void" << endl;
				diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(3,i,-1.0);
			}
		}
			
		diffInhibTempDevRepartitionInputTestFile->addDataSeparator();
	}
	else
	{
		cerr << "Warning, inhibTempDevRepartitionInputTestFile && diffInhibTempDevRepartitionInputTestFile should be inited" << endl;
	}
					#else
	if (diffExcitTempDevRepartitionInputTestFile->isOpen())
	{
		for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
		{
			if (excitPreTempDevRepartitionInputTest)
			{
				for (int i=0;i<100;i++)
				{
					if (!excitPreTempDevRepartitionInputTest[99-i][1][k].isVoid() && !excitPreTempDevRepartitionInputTest[99-i][0][k].isVoid())
					{
						diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(k,-(99-i),(double) (excitPreTempDevRepartitionInputTest[99-i][1][k].getMean() - excitPreTempDevRepartitionInputTest[99-i][0][k].getMean()));
					}
					else
					{
						//cout << "diffExcitTempDevRepartitionInputTestFile is void" << endl;
						diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(k,-(99-i),-1.0);
					}
				}
			}

			if (excitPostTempDevRepartitionInputTest)
			{
				for (int i=0;i<100;i++)
				{
					if (!excitPostTempDevRepartitionInputTest[i][1][k].isVoid() && !excitPostTempDevRepartitionInputTest[i][0][k].isVoid())
					{
						diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(k,i,(double) (excitPostTempDevRepartitionInputTest[i][1][k].getMean() - excitPostTempDevRepartitionInputTest[i][0][k].getMean()));
					}
					else
					{
						//cout << "diffExcitTempDevRepartitionInputTestFile is void" << endl;
						diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(k,i,-1.0);
					}
				}
			}

			diffExcitTempDevRepartitionInputTestFile->addDataSeparator();
		}
	}
	else
	{
		cerr << "Warning, diffExcitTempDevRepartitionInputTestFile should be inited" << endl;
	}
	
	if (diffInhibTempDevRepartitionInputTestFile->isOpen())
	{
		for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
		{
			if (inhibPreTempDevRepartitionInputTest)
			{
				for (int i=0;i<100;i++)
				{
					if (!inhibPreTempDevRepartitionInputTest[99-i][1][k].isVoid() && !inhibPreTempDevRepartitionInputTest[99-i][0][k].isVoid())
					{
						diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(k,-(99-i),(double) (inhibPreTempDevRepartitionInputTest[99-i][1][k].getMean() - inhibPreTempDevRepartitionInputTest[99-i][0][k].getMean()));
					}
					else
					{
						//cout << "diffInhibTempDevRepartitionInputTestFile is void" << endl;
						diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(k,-(99-i),-1.0);
					}
					
				}
			}

			if (inhibPostTempDevRepartitionInputTest)
			{
				for (int i=0;i<100;i++)
				{
					if (!inhibPostTempDevRepartitionInputTest[i][1][k].isVoid() && !inhibPostTempDevRepartitionInputTest[i][0][k].isVoid())
					{
						diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(k,i,(double) (inhibPostTempDevRepartitionInputTest[i][1][k].getMean() - inhibPostTempDevRepartitionInputTest[i][0][k].getMean()));
					}
					else
					{
						//cout << "diffInhibTempDevRepartitionInputTestFile is void" << endl;
						diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(k,i,-1.0);
					}
				}
			}

			diffInhibTempDevRepartitionInputTestFile->addDataSeparator();
		}
	}
	else
	{
		cerr << "Warning, diffInhibTempDevRepartitionInputTestFile should be inited" << endl;
	}
	
	if (excitTempDevRepartitionInputTestFile->isOpen())
	{
		for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
		{
			if (excitPreTempDevRepartitionInputTest)
			{
				for (int i=0;i<100;i++)
				{
					if (!excitPreTempDevRepartitionInputTest[99-i][1][k].isVoid())
					{
						excitTempDevRepartitionInputTestFile->addIndexedLineData(k,-(99-i),(double) (excitPreTempDevRepartitionInputTest[99-i][1][k].getMean()));
					}
					else
					{
						
						//cout << "excitTempDevRepartitionInputTestFile is void" << endl;
						excitTempDevRepartitionInputTestFile->addIndexedLineData(k,-(99-i),-1.0);
					}
				}
			}

			if (excitPostTempDevRepartitionInputTest)
			{
				for (int i=0;i<100;i++)
				{
					if (!excitPostTempDevRepartitionInputTest[i][1][k].isVoid())
					{
						excitTempDevRepartitionInputTestFile->addIndexedLineData(k,i,(double) (excitPostTempDevRepartitionInputTest[i][1][k].getMean()));
					}
					else
					{
						//cout << "excitTempDevRepartitionInputTestFile is void" << endl;
						excitTempDevRepartitionInputTestFile->addIndexedLineData(k,i,-1.0);
					}
				}
			}
 
			excitTempDevRepartitionInputTestFile->addDataSeparator();
		}
	}
	else
	{
		cerr << "Warning, excitTempDevRepartitionInputTestFile should be inited" << endl;
	}
	
	if (inhibTempDevRepartitionInputTestFile->isOpen())
	{
		for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
		{
			if (inhibPreTempDevRepartitionInputTest)
			{
				for (int i=0;i<100;i++)
				{
					if (!inhibPreTempDevRepartitionInputTest[99-i][1][k].isVoid())
					{
						inhibTempDevRepartitionInputTestFile->addIndexedLineData(k,-(99-i),(double) (inhibPreTempDevRepartitionInputTest[99-i][1][k].getMean()));
					}
					else
					{
						//cout << "inhibTempDevRepartitionInputTestFile is void" << endl;
						inhibTempDevRepartitionInputTestFile->addIndexedLineData(k,-(99-i),-1.0);
					}
					
				}
			}

			if (inhibPostTempDevRepartitionInputTest)
			{
				for (int i=0;i<100;i++)
				{
					if (!inhibPostTempDevRepartitionInputTest[i][1][k].isVoid())
					{
						inhibTempDevRepartitionInputTestFile->addIndexedLineData(k,i,(double) (inhibPostTempDevRepartitionInputTest[i][1][k].getMean()));
					}
					else
					{
						//cout << "inhibTempDevRepartitionInputTestFile is void" << endl;
						inhibTempDevRepartitionInputTestFile->addIndexedLineData(k,i,-1.0);
					}
				}
			}

			inhibTempDevRepartitionInputTestFile->addDataSeparator();
		}
	}
	else
	{
		cerr << "Warning, inhibTempDevRepartitionInputTestFile should be inited" << endl;
	}
					#endif
				#else
	if (excitTempDevRepartitionInputTestFile->isOpen())
	{
		for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
		{
			if (excitPreTempDevRepartitionInputTest)
			{
				for (int i=0;i<100;i++)
				{
					if (!excitPreTempDevRepartitionInputTest[99-i][k].isVoid())
					{
						excitTempDevRepartitionInputTestFile->addIndexedLineData(k,-(99-i),(double) (excitPreTempDevRepartitionInputTest[99-i][k].getMean()));
					}
					else
					{
						//cout << "excitTempDevRepartitionInputTestFile is void" << endl;
						excitTempDevRepartitionInputTestFile->addIndexedLineData(k,-(99-i),-1.0);
					}
				}
			}

			if (excitPostTempDevRepartitionInputTest)
			{
				for (int i=0;i<100;i++)
				{
					if (!excitPostTempDevRepartitionInputTest[i][k].isVoid())
					{
						excitTempDevRepartitionInputTestFile->addIndexedLineData(k,i,(double) (excitPostTempDevRepartitionInputTest[i][k].getMean()));
					}
					else
					{
						//cout << "excitTempDevRepartitionInputTestFile is void" << endl;
						excitTempDevRepartitionInputTestFile->addIndexedLineData(k,i,-1.0);
					}
				}
			}
			
			excitTempDevRepartitionInputTestFile->addDataSeparator();
		}
	}
	else
	{
		cerr << "Warning, excitTempDevRepartitionInputTestFile should be inited" << endl;
	}
	
	if (inhibTempDevRepartitionInputTestFile->isOpen())
	{
		for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
		{
			if (inhibPreTempDevRepartitionInputTest)
			{
				for (int i=0;i<100;i++)
				{
					if (!inhibPreTempDevRepartitionInputTest[99-i][k].isVoid())
					{
						inhibTempDevRepartitionInputTestFile->addIndexedLineData(k,-(99-i),(double) (inhibPreTempDevRepartitionInputTest[99-i][k].getMean()));
					}
					else
					{
						//cout << "inhibTempDevRepartitionInputTestFile is void" << endl;
						inhibTempDevRepartitionInputTestFile->addIndexedLineData(k,-(99-i),-1.0);
					}
					
				}
			}

			if (inhibPostTempDevRepartitionInputTest)
			{
				for (int i=0;i<100;i++)
				{
					if (!inhibPostTempDevRepartitionInputTest[i][k].isVoid())
					{
						inhibTempDevRepartitionInputTestFile->addIndexedLineData(k,i,(double) (inhibPostTempDevRepartitionInputTest[i][k].getMean()));
					}
					else
					{
						//cout << "inhibTempDevRepartitionInputTestFile is void" << endl;
						inhibTempDevRepartitionInputTestFile->addIndexedLineData(k,i,-1.0);
					}
				}
			}

			inhibTempDevRepartitionInputTestFile->addDataSeparator();
		}
	}
	else
	{
		cerr << "Warning, inhibTempDevRepartitionInputTestFile should be inited" << endl;
	}
				#endif
			#else	
				#ifdef _PHASE_TEST_MODE
	if (excitTempDevRepartitionInputTestFile->isOpen() && diffExcitTempDevRepartitionInputTestFile->isOpen())
	{
					#ifdef _TRANSITION_STAT_MODE
		for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			if (excitPreTempDevRepartitionInputTest)
			{
				for (int i=0;i<100;i++)
				{
					if (!excitPreTempDevRepartitionInputTest[99-i][j].isVoid())
					{
						if (j%2==0)
						{
							excitTempDevRepartitionInputTestFile->addIndexedLineData(j,-99+i,(double) excitPreTempDevRepartitionInputTest[99-i][j].getAccu()/((double) EDNetwork::TRANSITION_TIME_LENGTH));
						}
						else
						{
							excitTempDevRepartitionInputTestFile->addIndexedLineData(j,-99+i,(double) excitPreTempDevRepartitionInputTest[99-i][j].getAccu()/((double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)));
						}
						//excitTempDevRepartitionInputTestFile->addIndexedLineData(j,-(99-i),(double) (excitPreTempDevRepartitionInputTest[99-i][j].getAccu()));
					}
					else
					{
						//cout << "excitTempDevRepartitionInputTestFile is void" << endl;
						excitTempDevRepartitionInputTestFile->addIndexedLineData(j,-(99-i),-1.0);
					}
					
				}
			}

			if (excitPostTempDevRepartitionInputTest)
			{
				for (int i=0;i<100;i++)
				{
					if (!excitPostTempDevRepartitionInputTest[i][j].isVoid())
					{
						if (j%2==0)
						{
							excitTempDevRepartitionInputTestFile->addIndexedLineData(j,i,(double) excitPostTempDevRepartitionInputTest[i][j].getAccu()/((double) EDNetwork::TRANSITION_TIME_LENGTH));
						}
						else
						{
							excitTempDevRepartitionInputTestFile->addIndexedLineData(j,i,(double) excitPostTempDevRepartitionInputTest[i][j].getAccu()/((double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)));
						}
						//excitTempDevRepartitionInputTestFile->addIndexedLineData(j,i,(double) (excitPostTempDevRepartitionInputTest[i][j].getAccu()));
					}
					else
					{
						//cout << "excitTempDevRepartitionInputTestFile is void" << endl;
						excitTempDevRepartitionInputTestFile->addIndexedLineData(j,i,-1.0);
					}
				}
			}

			excitTempDevRepartitionInputTestFile->addDataSeparator();
			
		}
			
		for (int i=0;i<100;i++)
		{
			if (!excitPreTempDevRepartitionInputTest[99-i][1].isVoid() && !excitPreTempDevRepartitionInputTest[99-i][0].isVoid())
			{
				diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(0,-(99-i),(double) excitPreTempDevRepartitionInputTest[99-i][0].getAccu()/((double) EDNetwork::TRANSITION_TIME_LENGTH)-excitPreTempDevRepartitionInputTest[99-i][1].getAccu()/((double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)));
			}
			else
			{	
				//cout << "diffExcitTempDevRepartitionInputTestFile is void" << endl;
				diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(0,-(99-i),-1.0);
			}
		}
		
		for (int i=0;i<100;i++)
		{
			if (!excitPostTempDevRepartitionInputTest[i][1].isVoid() && !excitPostTempDevRepartitionInputTest[i][0].isVoid())
			{
				diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(0,i,(double) excitPostTempDevRepartitionInputTest[i][0].getAccu()/((double) EDNetwork::TRANSITION_TIME_LENGTH)-excitPostTempDevRepartitionInputTest[i][1].getAccu()/((double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)));
			}
			else
			{
				//cout << "diffExcitTempDevRepartitionInputTestFile is void" << endl;
				diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(0,i,-1.0);
			}
		}
			
		diffExcitTempDevRepartitionInputTestFile->addDataSeparator();
		
		for (int i=0;i<100;i++)
		{
			if (!excitPreTempDevRepartitionInputTest[99-i][3].isVoid() && !excitPreTempDevRepartitionInputTest[99-i][2].isVoid())
			{
				diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(1,-(99-i),(double) excitPreTempDevRepartitionInputTest[99-i][2].getAccu()/((double) EDNetwork::TRANSITION_TIME_LENGTH)-excitPreTempDevRepartitionInputTest[99-i][3].getAccu()/((double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)));
			}
			else
			{	
				//cout << "diffExcitTempDevRepartitionInputTestFile is void" << endl;
				diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(1,-(99-i),-1.0);
			}
		}
		
		for (int i=0;i<100;i++)
		{
			if (!excitPostTempDevRepartitionInputTest[i][3].isVoid() && !excitPostTempDevRepartitionInputTest[i][2].isVoid())
			{
				diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(1,i,(double) excitPostTempDevRepartitionInputTest[i][2].getAccu()/((double) EDNetwork::TRANSITION_TIME_LENGTH)-excitPostTempDevRepartitionInputTest[i][3].getAccu()/((double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)));
			}
			else
			{
				//cout << "diffExcitTempDevRepartitionInputTestFile is void" << endl;
				diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(1,i,-1.0);
			}
		}
	
		diffExcitTempDevRepartitionInputTestFile->addDataSeparator();
		
		for (int i=0;i<100;i++)
		{
			if (!excitPreTempDevRepartitionInputTest[99-i][5].isVoid() && !excitPreTempDevRepartitionInputTest[99-i][4].isVoid())
			{
				diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(2,-(99-i),(double) excitPreTempDevRepartitionInputTest[99-i][4].getAccu()/((double) EDNetwork::TRANSITION_TIME_LENGTH)-excitPreTempDevRepartitionInputTest[99-i][5].getAccu()/((double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)));
			}
			else
			{	
				//cout << "diffExcitTempDevRepartitionInputTestFile is void" << endl;
				diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(2,-(99-i),-1.0);
			}
		}
		
		for (int i=0;i<100;i++)
		{
			if (!excitPostTempDevRepartitionInputTest[i][5].isVoid() && !excitPostTempDevRepartitionInputTest[i][4].isVoid())
			{
				diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(2,i,(double) excitPostTempDevRepartitionInputTest[i][4].getAccu()/((double) EDNetwork::TRANSITION_TIME_LENGTH)-excitPostTempDevRepartitionInputTest[i][5].getAccu()/((double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)));
			}
			else
			{
				//cout << "diffExcitTempDevRepartitionInputTestFile is void" << endl;
				diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(2,i,-1.0);
			}
		}
		
		diffExcitTempDevRepartitionInputTestFile->addDataSeparator();
		
		for (int i=0;i<100;i++)
		{
			if (!excitPreTempDevRepartitionInputTest[99-i][7].isVoid() && !excitPreTempDevRepartitionInputTest[99-i][6].isVoid())
			{
				diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(3,-(99-i),(double) excitPreTempDevRepartitionInputTest[99-i][6].getAccu()/((double) EDNetwork::TRANSITION_TIME_LENGTH)-excitPreTempDevRepartitionInputTest[99-i][7].getAccu()/((double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)));
			}
			else
			{	
				//cout << "diffExcitTempDevRepartitionInputTestFile is void" << endl;
				diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(3,-(99-i),-1.0);
			}
		}
		
		for (int i=0;i<100;i++)
		{
			if (!excitPostTempDevRepartitionInputTest[i][7].isVoid() && !excitPostTempDevRepartitionInputTest[i][6].isVoid())
			{
				diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(3,i,(double) excitPostTempDevRepartitionInputTest[i][6].getAccu()/((double) EDNetwork::TRANSITION_TIME_LENGTH)-excitPostTempDevRepartitionInputTest[i][7].getAccu()/((double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)));
			}
			else
			{
				//cout << "diffExcitTempDevRepartitionInputTestFile is void" << endl;
				diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(3,i,-1.0);
			}
		}
		
		diffExcitTempDevRepartitionInputTestFile->addDataSeparator();
		
				#else
		for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			if (excitPreTempDevRepartitionInputTest)
			{
				for (int i=0;i<100;i++)
				{
					if (!excitPreTempDevRepartitionInputTest[99-i][j].isVoid())
					{
						excitTempDevRepartitionInputTestFile->addIndexedLineData(j,-(99-i),(double) (excitPreTempDevRepartitionInputTest[99-i][j].getMean()));
					}
					else
					{
						//cout << "excitTempDevRepartitionInputTestFile is void" << endl;
						excitTempDevRepartitionInputTestFile->addIndexedLineData(j,-(99-i),-1.0);
					}
				}
			}

			if (excitPostTempDevRepartitionInputTest)
			{
				for (int i=0;i<100;i++)
				{
					if (!excitPostTempDevRepartitionInputTest[i][j].isVoid())
					{
						excitTempDevRepartitionInputTestFile->addIndexedLineData(j,i,(double) (excitPostTempDevRepartitionInputTest[i][j].getMean()));
					}
					else
					{
						//cout << "excitTempDevRepartitionInputTestFile is void" << endl;
						excitTempDevRepartitionInputTestFile->addIndexedLineData(j,i,-1.0);
					}
				}
			}
			
			excitTempDevRepartitionInputTestFile->addDataSeparator();
			
			
		}
			
		for (int i=0;i<100;i++)
		{
			if (!excitPreTempDevRepartitionInputTest[99-i][1].isVoid() && !excitPreTempDevRepartitionInputTest[99-i][0].isVoid())
			{
				diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(0,-(99-i),(double) excitPreTempDevRepartitionInputTest[99-i][1].getMean()-excitPreTempDevRepartitionInputTest[99-i][0].getMean());
			}
			else
			{	
				//cout << "diffExcitTempDevRepartitionInputTestFile is void" << endl;
				diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(0,-(99-i),-1.0);
			}
		}
		
		for (int i=0;i<100;i++)
		{
			if (!excitPostTempDevRepartitionInputTest[i][1].isVoid() && !excitPostTempDevRepartitionInputTest[i][0].isVoid())
			{
				diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(0,i,(double) excitPostTempDevRepartitionInputTest[i][1].getMean()-excitPostTempDevRepartitionInputTest[i][0].getMean());
			}
			else
			{
				//cout << "diffExcitTempDevRepartitionInputTestFile is void" << endl;
				diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(0,i,-1.0);
			}
		}
			
		diffExcitTempDevRepartitionInputTestFile->addDataSeparator();
		
		for (int i=0;i<100;i++)
		{
			if (!excitPreTempDevRepartitionInputTest[99-i][2].isVoid() && !excitPreTempDevRepartitionInputTest[99-i][0].isVoid())
			{
				diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(1,-(99-i),(double) excitPreTempDevRepartitionInputTest[99-i][2].getMean()-excitPreTempDevRepartitionInputTest[99-i][0].getMean());
			}
			else
			{	
				//cout << "diffExcitTempDevRepartitionInputTestFile is void" << endl;
				diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(1,-(99-i),-1.0);
			}

		}
			
		for (int i=0;i<100;i++)
		{
			if (!excitPostTempDevRepartitionInputTest[i][2].isVoid() && !excitPostTempDevRepartitionInputTest[i][0].isVoid())
			{
				diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(1,i,(double) excitPostTempDevRepartitionInputTest[i][2].getMean()-excitPostTempDevRepartitionInputTest[i][0].getMean());
			}
			else
			{	
				//cout << "diffExcitTempDevRepartitionInputTestFile is void" << endl;
				diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(1,i,-1.0);
			}
		}
			
		diffExcitTempDevRepartitionInputTestFile->addDataSeparator();
		
		for (int i=0;i<100;i++)
		{
			if (!excitPreTempDevRepartitionInputTest[99-i][3].isVoid() && !excitPreTempDevRepartitionInputTest[99-i][0].isVoid())
			{
				diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(2,-(99-i),(double) excitPreTempDevRepartitionInputTest[99-i][3].getMean()-excitPreTempDevRepartitionInputTest[99-i][0].getMean());
			}
			else
			{	
				//cout << "diffExcitTempDevRepartitionInputTestFile is void" << endl;
				diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(2,-(99-i),-1.0);
			}
		}
			
		for (int i=0;i<100;i++)
		{
			if (!excitPostTempDevRepartitionInputTest[i][3].isVoid() && !excitPostTempDevRepartitionInputTest[i][0].isVoid())
			{
				diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(2,i,(double) excitPostTempDevRepartitionInputTest[i][3].getMean()-excitPostTempDevRepartitionInputTest[i][0].getMean());
			}
			else
			{	
				//cout << "diffExcitTempDevRepartitionInputTestFile is void" << endl;
				diffExcitTempDevRepartitionInputTestFile->addIndexedLineData(2,i,-1.0);
			}
		}
		
		diffExcitTempDevRepartitionInputTestFile->addDataSeparator();
					#endif
	}
	else
	{
		cerr << "Warning, excitTempDevRepartitionInputTestFile && diffExcitTempDevRepartitionInputTestFile should be inited" << endl;
	}
	
	if (inhibTempDevRepartitionInputTestFile->isOpen() && diffInhibTempDevRepartitionInputTestFile->isOpen())
	{
					#ifdef _TRANSITION_STAT_MODE
		for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			if (inhibPreTempDevRepartitionInputTest)
			{
				for (int i=0;i<100;i++)
				{
					if (!inhibPreTempDevRepartitionInputTest[99-i][j].isVoid())
					{
						if (j%2==0)
						{
							inhibTempDevRepartitionInputTestFile->addIndexedLineData(j,-99+i,(double) inhibPreTempDevRepartitionInputTest[99-i][j].getAccu()/((double) EDNetwork::TRANSITION_TIME_LENGTH));
						}
						else
						{
							inhibTempDevRepartitionInputTestFile->addIndexedLineData(j,-99+i,(double) inhibPreTempDevRepartitionInputTest[99-i][j].getAccu()/((double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)));
						}
						//inhibTempDevRepartitionInputTestFile->addIndexedLineData(j,-(99-i),(double) (inhibPreTempDevRepartitionInputTest[99-i][j].getAccu()));
					}
					else
					{
						//cout << "inhibTempDevRepartitionInputTestFile is void" << endl;
						inhibTempDevRepartitionInputTestFile->addIndexedLineData(j,-(99-i),-1.0);
					}
					
				}
			}

			if (inhibPostTempDevRepartitionInputTest)
			{
				for (int i=0;i<100;i++)
				{
					if (!inhibPostTempDevRepartitionInputTest[i][j].isVoid())
					{
						if (j%2==0)
						{
							inhibTempDevRepartitionInputTestFile->addIndexedLineData(j,i,(double) inhibPostTempDevRepartitionInputTest[i][j].getAccu()/((double) EDNetwork::TRANSITION_TIME_LENGTH));
						}
						else
						{
							inhibTempDevRepartitionInputTestFile->addIndexedLineData(j,i,(double) inhibPostTempDevRepartitionInputTest[i][j].getAccu()/((double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)));
						}
						//inhibTempDevRepartitionInputTestFile->addIndexedLineData(j,i,(double) (inhibPostTempDevRepartitionInputTest[i][j].getAccu()));
					}
					else
					{
						//cout << "inhibTempDevRepartitionInputTestFile is void" << endl;
						inhibTempDevRepartitionInputTestFile->addIndexedLineData(j,i,-1.0);
					}
				}
			}

			inhibTempDevRepartitionInputTestFile->addDataSeparator();
	
		}
			
		for (int i=0;i<100;i++)
		{
			if (!inhibPreTempDevRepartitionInputTest[99-i][1].isVoid() && !inhibPreTempDevRepartitionInputTest[99-i][0].isVoid())
			{
				diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(0,-(99-i),(double) inhibPreTempDevRepartitionInputTest[99-i][0].getAccu()/((double) EDNetwork::TRANSITION_TIME_LENGTH)-inhibPreTempDevRepartitionInputTest[99-i][1].getAccu()/((double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)));
			}
			else
			{	
				
				//cout << "diffInhibTempDevRepartitionInputTestFile is void" << endl;
				diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(0,-(99-i),-1.0);
			}
		}
		
		for (int i=0;i<100;i++)
		{
			if (!inhibPostTempDevRepartitionInputTest[i][1].isVoid() && !inhibPostTempDevRepartitionInputTest[i][0].isVoid())
			{
				diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(0,i,(double) inhibPostTempDevRepartitionInputTest[i][0].getAccu()/((double) EDNetwork::TRANSITION_TIME_LENGTH)-inhibPostTempDevRepartitionInputTest[i][1].getAccu()/((double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)));
			}
			else
			{	
				//cout << "diffInhibTempDevRepartitionInputTestFile is void" << endl;
				diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(0,i,-1.0);
			}
		}
			
		diffInhibTempDevRepartitionInputTestFile->addDataSeparator();
		
		for (int i=0;i<100;i++)
		{
			if (!inhibPreTempDevRepartitionInputTest[99-i][3].isVoid() && !inhibPreTempDevRepartitionInputTest[99-i][2].isVoid())
			{
				diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(1,-(99-i),(double) inhibPreTempDevRepartitionInputTest[99-i][2].getAccu()/((double) EDNetwork::TRANSITION_TIME_LENGTH)-inhibPreTempDevRepartitionInputTest[99-i][3].getAccu()/((double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)));
			}
			else
			{	
				
				//cout << "diffInhibTempDevRepartitionInputTestFile is void" << endl;
				diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(1,-(99-i),-1.0);
			}
		}
		
		for (int i=0;i<100;i++)
		{
			if (!inhibPostTempDevRepartitionInputTest[i][3].isVoid() && !inhibPostTempDevRepartitionInputTest[i][2].isVoid())
			{
				diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(1,i,(double) inhibPostTempDevRepartitionInputTest[i][2].getAccu()/((double) EDNetwork::TRANSITION_TIME_LENGTH)-inhibPostTempDevRepartitionInputTest[i][3].getAccu()/((double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)));
			}
			else
			{	
				//cout << "diffInhibTempDevRepartitionInputTestFile is void" << endl;
				diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(1,i,-1.0);
			}
		}
		
		diffInhibTempDevRepartitionInputTestFile->addDataSeparator();
		
		for (int i=0;i<100;i++)
		{
			if (!inhibPreTempDevRepartitionInputTest[99-i][5].isVoid() && !inhibPreTempDevRepartitionInputTest[99-i][4].isVoid())
			{
				diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(2,-(99-i),(double) inhibPreTempDevRepartitionInputTest[99-i][4].getAccu()/((double) EDNetwork::TRANSITION_TIME_LENGTH)-inhibPreTempDevRepartitionInputTest[99-i][5].getAccu()/((double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)));
			}
			else
			{	
				
				//cout << "diffInhibTempDevRepartitionInputTestFile is void" << endl;
				diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(2,-(99-i),-1.0);
			}
		}
		
		for (int i=0;i<100;i++)
		{
			if (!inhibPostTempDevRepartitionInputTest[i][5].isVoid() && !inhibPostTempDevRepartitionInputTest[i][5].isVoid())
			{
				diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(2,i,(double) inhibPostTempDevRepartitionInputTest[i][4].getAccu()/((double) EDNetwork::TRANSITION_TIME_LENGTH)-inhibPostTempDevRepartitionInputTest[i][5].getAccu()/((double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)));
			}
			else
			{	
				//cout << "diffInhibTempDevRepartitionInputTestFile is void" << endl;
				diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(2,i,-1.0);
			}
		}
	
		diffInhibTempDevRepartitionInputTestFile->addDataSeparator();
			
		for (int i=0;i<100;i++)
		{
			if (!inhibPreTempDevRepartitionInputTest[99-i][7].isVoid() && !inhibPreTempDevRepartitionInputTest[99-i][6].isVoid())
			{
				diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(3,-(99-i),(double) inhibPreTempDevRepartitionInputTest[99-i][6].getAccu()/((double) EDNetwork::TRANSITION_TIME_LENGTH)-inhibPreTempDevRepartitionInputTest[99-i][7].getAccu()/((double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)));
			}
			else
			{	
				
				//cout << "diffInhibTempDevRepartitionInputTestFile is void" << endl;
				diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(3,-(99-i),-1.0);
			}
		}
		
		for (int i=0;i<100;i++)
		{
			if (!inhibPostTempDevRepartitionInputTest[i][7].isVoid() && !inhibPostTempDevRepartitionInputTest[i][6].isVoid())
			{
				diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(3,i,(double) inhibPostTempDevRepartitionInputTest[i][6].getAccu()/((double) EDNetwork::TRANSITION_TIME_LENGTH)-inhibPostTempDevRepartitionInputTest[i][7].getAccu()/((double) (NB_MAX_TEST_STEPS-EDNetwork::TRANSITION_TIME_LENGTH)));
			}
			else
			{	
				//cout << "diffInhibTempDevRepartitionInputTestFile is void" << endl;
				diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(3,i,-1.0);
			}
		}
		
		diffInhibTempDevRepartitionInputTestFile->addDataSeparator();
		
					#else
		for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			if (inhibPreTempDevRepartitionInputTest)
			{
				for (int i=0;i<100;i++)
				{
					if (!inhibPreTempDevRepartitionInputTest[99-i][j].isVoid())
					{
						inhibTempDevRepartitionInputTestFile->addIndexedLineData(j,-(99-i),(double) (inhibPreTempDevRepartitionInputTest[99-i][j].getMean()));
					}
					else
					{
						//cout << "inhibTempDevRepartitionInputTestFile is void" << endl;
						inhibTempDevRepartitionInputTestFile->addIndexedLineData(j,-(99-i),-1.0);
					}
					
				}
			}

			if (inhibPostTempDevRepartitionInputTest)
			{
				for (int i=0;i<100;i++)
				{
					if (!inhibPostTempDevRepartitionInputTest[i][j].isVoid())
					{
						inhibTempDevRepartitionInputTestFile->addIndexedLineData(j,i,(double) (inhibPostTempDevRepartitionInputTest[i][j].getMean()));
					}
					else
					{
						//cout << "inhibTempDevRepartitionInputTestFile is void" << endl;
						inhibTempDevRepartitionInputTestFile->addIndexedLineData(j,i,-1.0);
					}
				}
			}

			inhibTempDevRepartitionInputTestFile->addDataSeparator();
	
		}
			
		for (int i=0;i<100;i++)
		{
			if (!inhibPreTempDevRepartitionInputTest[99-i][1].isVoid() && !inhibPreTempDevRepartitionInputTest[99-i][0].isVoid())
			{
				diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(0,-(99-i),(double) inhibPreTempDevRepartitionInputTest[99-i][1].getMean()-inhibPreTempDevRepartitionInputTest[99-i][0].getMean());
			}
			else
			{	
				
				//cout << "diffInhibTempDevRepartitionInputTestFile is void" << endl;
				diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(0,-(99-i),-1.0);
			}
		}
		
		for (int i=0;i<100;i++)
		{
			if (!inhibPostTempDevRepartitionInputTest[i][1].isVoid() && !inhibPostTempDevRepartitionInputTest[i][0].isVoid())
			{
				diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(0,i,(double) inhibPostTempDevRepartitionInputTest[i][1].getMean()-inhibPostTempDevRepartitionInputTest[i][0].getMean());
			}
			else
			{	
				//cout << "diffInhibTempDevRepartitionInputTestFile is void" << endl;
				diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(0,i,-1.0);
			}
		}
			
		diffInhibTempDevRepartitionInputTestFile->addDataSeparator();
		
		for (int i=0;i<100;i++)
		{
			if (!inhibPreTempDevRepartitionInputTest[99-i][2].isVoid() && !inhibPreTempDevRepartitionInputTest[99-i][0].isVoid())
			{
				diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(1,-(99-i),(double) inhibPreTempDevRepartitionInputTest[99-i][2].getMean()-inhibPreTempDevRepartitionInputTest[99-i][0].getMean());
			}
			else
			{	
				//cout << "diffInhibTempDevRepartitionInputTestFile is void" << endl;
				diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(1,-(99-i),-1.0);
			}

		}
			
		for (int i=0;i<100;i++)
		{
			if (!inhibPostTempDevRepartitionInputTest[i][2].isVoid() && !inhibPostTempDevRepartitionInputTest[i][0].isVoid())
			{
				diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(1,i,(double) inhibPostTempDevRepartitionInputTest[i][2].getMean()-inhibPostTempDevRepartitionInputTest[i][0].getMean());
			}
			else
			{	
				//cout << "diffInhibTempDevRepartitionInputTestFile is void" << endl;
				diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(1,i,-1.0);
			}
		}
			
		diffInhibTempDevRepartitionInputTestFile->addDataSeparator();
		
		for (int i=0;i<100;i++)
		{
			if (!inhibPreTempDevRepartitionInputTest[99-i][3].isVoid() && !inhibPreTempDevRepartitionInputTest[99-i][0].isVoid())
			{
				diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(2,-(99-i),(double) inhibPreTempDevRepartitionInputTest[99-i][3].getMean()-inhibPreTempDevRepartitionInputTest[99-i][0].getMean());
			}
			else
			{	
				//cout << "diffInhibTempDevRepartitionInputTestFile is void" << endl;
				diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(2,-(99-i),-1.0);
			}
		}
			
		for (int i=0;i<100;i++)
		{
			if (!inhibPostTempDevRepartitionInputTest[i][3].isVoid() && !inhibPostTempDevRepartitionInputTest[i][0].isVoid())
			{
				diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(2,i,(double) inhibPostTempDevRepartitionInputTest[i][3].getMean()-inhibPostTempDevRepartitionInputTest[i][0].getMean());
			}
			else
			{	
				//cout << "diffInhibTempDevRepartitionInputTestFile is void" << endl;
				diffInhibTempDevRepartitionInputTestFile->addIndexedLineData(2,i,-1.0);
			}
		}
		
		diffInhibTempDevRepartitionInputTestFile->addDataSeparator();
					#endif
	}
	else
	{
		cerr << "Warning, inhibTempDevRepartitionInputTestFile && diffInhibTempDevRepartitionInputTestFile should be inited" << endl;
	}
				#endif
			#endif	
		#endif
	
		#ifdef _PARAMETRIC_TEST_MODE
			#ifdef _PHASE_TEST_MODE
				#ifdef _CONDITIONAL_TEST_MODE
	if (ISIRepartitionInputTestFile->isOpen() && diffISIRepartitionInputTestFile->isOpen())
	{
		if (ISIRepartitionInputTest)
		{
			for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
			{
				for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
				{
					for (int i=0;i<100;i++)
					{
						if (!ISIRepartitionInputTest[i][j][k].isVoid())
						{
							ISIRepartitionInputTestFile->addIndexedLineData(j,i,(double) ISIRepartitionInputTest[i][j][k].getMean());
						}
						else
						{
							//cout << "ISIRepartitionInputTestFile is void" << endl;
							ISIRepartitionInputTestFile->addIndexedLineData(j,i,-1.0);
						}
					}
					
					ISIRepartitionInputTestFile->addDataSeparator();
				}
			}
				
			for (int i=0;i<100;i++)
			{
				if (!ISIRepartitionInputTest[i][0][0].isVoid() && !ISIRepartitionInputTest[i][0][1].isVoid())
				{
					diffISIRepartitionInputTestFile->addIndexedLineData(0,i,(double) ISIRepartitionInputTest[i][0][0].getMean()-ISIRepartitionInputTest[i][0][1].getMean());
				}
				else
				{
					//cout << "diffISIRepartitionInputTestFile is void" << endl;
					diffISIRepartitionInputTestFile->addIndexedLineData(0,i,-1.0);
				}
			}
				
			diffISIRepartitionInputTestFile->addDataSeparator();
			
			for (int i=0;i<100;i++)
			{
				if (!ISIRepartitionInputTest[i][1][0].isVoid() && !ISIRepartitionInputTest[i][1][1].isVoid())
				{
					diffISIRepartitionInputTestFile->addIndexedLineData(1,i,(double) ISIRepartitionInputTest[i][1][0].getMean()-ISIRepartitionInputTest[i][1][1].getMean());
				}
				else
				{
					//cout << "diffISIRepartitionInputTestFile is void" << endl;
					diffISIRepartitionInputTestFile->addIndexedLineData(1,i,-1.0);
				}
			}
				
			diffISIRepartitionInputTestFile->addDataSeparator();
				
			for (int i=0;i<100;i++)
			{
				if (!ISIRepartitionInputTest[i][2][0].isVoid() && !ISIRepartitionInputTest[i][2][1].isVoid())
				{
					diffISIRepartitionInputTestFile->addIndexedLineData(2,i,(double) ISIRepartitionInputTest[i][2][0].getMean()-ISIRepartitionInputTest[i][2][1].getMean());
				}
				else
				{
					//cout << "diffISIRepartitionInputTestFile is void" << endl;
					diffISIRepartitionInputTestFile->addIndexedLineData(2,i,-1.0);
				}
			}
				
			diffISIRepartitionInputTestFile->addDataSeparator();
					
			for (int i=0;i<100;i++)
			{
				if (!ISIRepartitionInputTest[i][3][0].isVoid() && !ISIRepartitionInputTest[i][3][1].isVoid())
				{
					diffISIRepartitionInputTestFile->addIndexedLineData(3,i,(double) ISIRepartitionInputTest[i][3][0].getMean()-ISIRepartitionInputTest[i][3][1].getMean());
				}
				else
				{
					//cout << "diffISIRepartitionInputTestFile is void" << endl;
					diffISIRepartitionInputTestFile->addIndexedLineData(3,i,-1.0);
				}
			}
				
			diffISIRepartitionInputTestFile->addDataSeparator();

		}
	}
	else
	{
		cerr << "Warning, ISIRepartitionInputTestFile && diffISIRepartitionInputTestFile should be inited" << endl;
	}
				#else
	if (diffISIRepartitionInputTestFile->isOpen())
	{
		if (ISIRepartitionInputTest)
		{
			for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
			{
				for (int i=0;i<100;i++)
				{
					if (!ISIRepartitionInputTest[i][0][k].isVoid() && !ISIRepartitionInputTest[i][1][k].isVoid())
					{
						diffISIRepartitionInputTestFile->addIndexedLineData(k,i,(double) (ISIRepartitionInputTest[i][1][k].getMean()-ISIRepartitionInputTest[i][0][k].getMean()));
					}
					else
					{
						//cout << "diffISIRepartitionInputTestFile is void" << endl;
						diffISIRepartitionInputTestFile->addIndexedLineData(k,i,-1.0);
					}
				}

				diffISIRepartitionInputTestFile->addDataSeparator();
			}
		}
	}
	else
	{
		cerr << "Warning, diffISIRepartitionInputTestFile should be inited" << endl;
	}
	
	if (ISIRepartitionInputTestFile->isOpen())
	{
		if (ISIRepartitionInputTest)
		{
			for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
			{
				for (int i=0;i<100;i++)
				{
					if (!ISIRepartitionInputTest[i][1][k].isVoid())
					{
						ISIRepartitionInputTestFile->addIndexedLineData(k,i,(double) ISIRepartitionInputTest[i][1][k].getMean());
					}
					else
					{
						//cout << "ISIRepartitionInputTestFile is void" << endl;
						ISIRepartitionInputTestFile->addIndexedLineData(k,i,-1.0);
					}
				}

				ISIRepartitionInputTestFile->addDataSeparator();
			}
		}
	}
	else
	{
		cerr << "Warning, ISIRepartitionInputTestFile should be inited" << endl;
	}
				#endif
			#else
	if (ISIRepartitionInputTestFile->isOpen())
	{
		if (ISIRepartitionInputTest)
		{
			for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
			{
				for (int i=0;i<100;i++)
				{
					if (!ISIRepartitionInputTest[i][k].isVoid())
					{
						ISIRepartitionInputTestFile->addIndexedLineData(k,i,(double) ISIRepartitionInputTest[i][k].getMean());
					}
					else
					{
						//cout << "ISIRepartitionInputTestFile is void" << endl;
						ISIRepartitionInputTestFile->addIndexedLineData(k,i,-1.0);
					}
				}

				ISIRepartitionInputTestFile->addDataSeparator();
			}
		}
	}
	else
	{
		cerr << "Warning, ISIRepartitionInputTestFile should be inited" << endl;
	}
			#endif
		#else
			#ifdef _PHASE_TEST_MODE
	if (ISIRepartitionInputTestFile->isOpen() && diffISIRepartitionInputTestFile->isOpen())
	{
		if (ISIRepartitionInputTest)
		{
				#ifdef _TRANSITION_STAT_MODE
			for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<100;i++)
				{
					if (!ISIRepartitionInputTest[i][j].isVoid())
					{
						if (j%2==0)
						{
							ISIRepartitionInputTestFile->addIndexedLineData(j,i,(double) ISIRepartitionInputTest[i][j].getAccu()/((double) TRANSITION_TIME_STEP));
						}
						else
						{
							ISIRepartitionInputTestFile->addIndexedLineData(j,i,(double) ISIRepartitionInputTest[i][j].getAccu()/((double) NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP));
						}
					}
					else
					{
						//cout << "ISIRepartitionInputTestFile is void" << endl;
						ISIRepartitionInputTestFile->addIndexedLineData(j,i,-1.0);
					}
				}
				
				ISIRepartitionInputTestFile->addDataSeparator();
			}
			
			for (int i=0;i<100;i++)
			{
				if (!ISIRepartitionInputTest[i][1].isVoid() && !ISIRepartitionInputTest[i][0].isVoid())
				{
					diffISIRepartitionInputTestFile->addIndexedLineData(0,i,(double) ISIRepartitionInputTest[i][0].getAccu()/((double) TRANSITION_TIME_STEP)-ISIRepartitionInputTest[i][1].getAccu()/((double) NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP));
				}
				else
				{
					cout << "diffISIRepartitionTestFile is void" << endl;
					diffISIRepartitionInputTestFile->addIndexedLineData(0,i,-1.0);
				}
			}
				
			diffISIRepartitionInputTestFile->addDataSeparator();
			
			for (int i=0;i<100;i++)
			{
				
				if (!ISIRepartitionInputTest[i][3].isVoid() && !ISIRepartitionInputTest[i][2].isVoid())
				{
					diffISIRepartitionInputTestFile->addIndexedLineData(1,i,(double) ISIRepartitionInputTest[i][2].getAccu()/((double) TRANSITION_TIME_STEP)-ISIRepartitionInputTest[i][3].getAccu()/((double) NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP));
				}
				else
				{
					cout << "diffISIRepartitionTestFile is void" << endl;
					diffISIRepartitionInputTestFile->addIndexedLineData(1,i,-1.0);
				}
			}
				
			diffISIRepartitionInputTestFile->addDataSeparator();
			
			for (int i=0;i<100;i++)
			{
				if (!ISIRepartitionInputTest[i][5].isVoid() && !ISIRepartitionInputTest[i][4].isVoid())
				{
					diffISIRepartitionInputTestFile->addIndexedLineData(2,i,(double) ISIRepartitionInputTest[i][4].getAccu()/((double) TRANSITION_TIME_STEP)-ISIRepartitionInputTest[i][5].getAccu()/((double) NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP));
				}
				else
				{
					cout << "diffISIRepartitionTestFile is void" << endl;
					diffISIRepartitionInputTestFile->addIndexedLineData(2,i,-1.0);
				}
			}
				
			diffISIRepartitionInputTestFile->addDataSeparator();	
			
			for (int i=0;i<100;i++)
			{
				if (!ISIRepartitionInputTest[i][7].isVoid() && !ISIRepartitionInputTest[i][6].isVoid())
				{
					diffISIRepartitionInputTestFile->addIndexedLineData(3,i,(double) ISIRepartitionInputTest[i][6].getAccu()/((double) TRANSITION_TIME_STEP)-ISIRepartitionInputTest[i][7].getAccu()/((double) NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP));
				}
				else
				{
					cout << "diffISIRepartitionTestFile is void" << endl;
					diffISIRepartitionInputTestFile->addIndexedLineData(3,i,-1.0);
				}
			}
				
			diffISIRepartitionInputTestFile->addDataSeparator();	
			
				#else
			
			for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<100;i++)
				{
					if (!ISIRepartitionInputTest[i][j].isVoid())
					{
						ISIRepartitionInputTestFile->addIndexedLineData(j,i,(double) ISIRepartitionInputTest[i][j].getMean());
					}
					else
					{
						//cout << "ISIRepartitionInputTestFile is void" << endl;
						ISIRepartitionInputTestFile->addIndexedLineData(j,i,-1.0);
					}
				}
				
				ISIRepartitionInputTestFile->addDataSeparator();
			}
			
			for (int i=0;i<100;i++)
			{
				if (!ISIRepartitionInputTest[i][1].isVoid() && !ISIRepartitionInputTest[i][0].isVoid())
				{
					diffISIRepartitionInputTestFile->addIndexedLineData(0,i,(double) ISIRepartitionInputTest[i][1].getMean()-ISIRepartitionInputTest[i][0].getMean());
				}
				else
				{
					//cout << "diffISIRepartitionInputTestFile is void" << endl;
					diffISIRepartitionInputTestFile->addIndexedLineData(0,i,-1.0);
				}
			}
				
			diffISIRepartitionInputTestFile->addDataSeparator();
			
			for (int i=0;i<100;i++)
			{
				if (!ISIRepartitionInputTest[i][2].isVoid() && !ISIRepartitionInputTest[i][0].isVoid())
				{
					diffISIRepartitionInputTestFile->addIndexedLineData(1,i,(double) ISIRepartitionInputTest[i][2].getMean()-ISIRepartitionInputTest[i][0].getMean());
				}
				else
				{
					//cout << "diffISIRepartitionInputTestFile is void" << endl;
					diffISIRepartitionInputTestFile->addIndexedLineData(1,i,-1.0);
				}
			}
				
			diffISIRepartitionInputTestFile->addDataSeparator();
			
			for (int i=0;i<100;i++)
			{
				if (!ISIRepartitionInputTest[i][3].isVoid() && !ISIRepartitionInputTest[i][0].isVoid())
				{
					diffISIRepartitionInputTestFile->addIndexedLineData(2,i,(double) ISIRepartitionInputTest[i][3].getMean()-ISIRepartitionInputTest[i][0].getMean());
				}
				else
				{
					//cout << "diffISIRepartitionInputTestFile is void" << endl;
					diffISIRepartitionInputTestFile->addIndexedLineData(2,i,-1.0);
				}
			}
				
			diffISIRepartitionInputTestFile->addDataSeparator();	
				#endif
		}
	}
	else
	{
		cerr << "Warning, ISIRepartitionInputTestFile && diffISIRepartitionInputTestFile should be inited" << endl;
	}
			#endif	
		#endif

		#ifndef _PARAMETRIC_TEST_MODE
			#ifdef _PHASE_TEST_MODE
	if (SpikeRepartitionInputTestFile->isOpen() && diffSpikeRepartitionInputTestFile->isOpen())
	{
		if (SpikeRepartitionInputTest)
		{
				#ifdef _TRANSITION_STAT_MODE
					#ifndef _SORT_ASSEMBLY_STAT_MODE
			for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<NB_HIDDEN_NEURONS;i++)
				{
					if (!SpikeRepartitionInputTest[i][j].isVoid())
					{
						//SpikeRepartitionInputTestFile->addIndexedLineData(j,i,(double) SpikeRepartitionInputTest[i][j].getAccu());
						if (j%2==0)
						{
							SpikeRepartitionInputTestFile->addIndexedLineData(j,i,(double) SpikeRepartitionInputTest[i][j].getAccu()/((double) TRANSITION_TIME_STEP));
						}
						else
						{
							SpikeRepartitionInputTestFile->addIndexedLineData(j,i,(double) SpikeRepartitionInputTest[i][j].getAccu()/((double) (NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP)));
						}
					}
					else
					{
						//cout << "SpikeRepartitionInputTestFile is void" << endl;
						SpikeRepartitionInputTestFile->addIndexedLineData(j,i,-1.0);
					}
				}
				SpikeRepartitionInputTestFile->addDataSeparator();
			}
					#else
			for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<NB_HIDDEN_NEURONS;i++)
				{
					if (!SpikeRepartitionInputTest[i][j].isVoid())
					{
						//SpikeRepartitionInputTestFile->addIndexedLineData(j,i,(double) SpikeRepartitionInputTest[i][j].getAccu());
						if (j%2==0)
						{
							SpikeRepartitionInputTestFile->addIndexedLineData(j,i,(double) (NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP)*SpikeRepartitionInputTest[i][j].getAccu());
						}
						else
						{
							SpikeRepartitionInputTestFile->addIndexedLineData(j,i,(double) TRANSITION_TIME_STEP*SpikeRepartitionInputTest[i][j].getAccu());
						}
					}
					else
					{
						//cout << "SpikeRepartitionInputTestFile is void" << endl;
						SpikeRepartitionInputTestFile->addIndexedLineData(j,i,-1.0);
					}
				}
			}
					#endif
			
					#ifndef _SORT_ASSEMBLY_STAT_MODE
			for (int i=0;i<NB_HIDDEN_NEURONS;i++)
			{
				if (!SpikeRepartitionInputTest[i][0].isVoid() && !SpikeRepartitionInputTest[i][1].isVoid())
				{
					//diffSpikeRepartitionInputTestFile->addIndexedLineData(0,i,(double) SpikeRepartitionInputTest[i][1].getAccu()-SpikeRepartitionInputTest[i][0].getAccu());
					diffSpikeRepartitionInputTestFile->addIndexedLineData(0,i,(double) SpikeRepartitionInputTest[i][0].getAccu()/((double) TRANSITION_TIME_STEP)-SpikeRepartitionInputTest[i][1].getAccu()/((double) (NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP)));
				}
				else
				{	
					//cout << "diffSpikeRepartitionInputTestFile is void" << endl;
					diffSpikeRepartitionInputTestFile->addIndexedLineData(0,i,-1.0);
				}
			}
				
			diffSpikeRepartitionInputTestFile->addDataSeparator();
			
			for (int i=0;i<NB_HIDDEN_NEURONS;i++)
			{
				if (!SpikeRepartitionInputTest[i][3].isVoid() && !SpikeRepartitionInputTest[i][2].isVoid())
				{
					//diffSpikeRepartitionInputTestFile->addIndexedLineData(1,i,(double) SpikeRepartitionInputTest[i][2].getAccu()-SpikeRepartitionInputTest[i][0].getAccu());
					diffSpikeRepartitionInputTestFile->addIndexedLineData(1,i,(double) SpikeRepartitionInputTest[i][2].getAccu()/((double) TRANSITION_TIME_STEP)-SpikeRepartitionInputTest[i][3].getAccu()/((double) (NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP)));
				}
				else
				{
					//cout << "diffSpikeRepartitionInputTestFile is void" << endl;
					diffSpikeRepartitionInputTestFile->addIndexedLineData(1,i,-1.0);
				}
			}
				
			diffSpikeRepartitionInputTestFile->addDataSeparator();
			
			for (int i=0;i<NB_HIDDEN_NEURONS;i++)
			{
				if (!SpikeRepartitionInputTest[i][5].isVoid() && !SpikeRepartitionInputTest[i][4].isVoid())
				{
					//diffSpikeRepartitionInputTestFile->addIndexedLineData(2,i,(double) SpikeRepartitionInputTest[i][3].getAccu()-SpikeRepartitionInputTest[i][0].getAccu());
					diffSpikeRepartitionInputTestFile->addIndexedLineData(2,i,(double) SpikeRepartitionInputTest[i][4].getAccu()/((double) TRANSITION_TIME_STEP)-SpikeRepartitionInputTest[i][5].getAccu()/((double) (NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP)));
				}
				else
				{
					//cout << "diffSpikeRepartitionInputTestFile is void" << endl;
					diffSpikeRepartitionInputTestFile->addIndexedLineData(2,i,-1.0);
				}
			}		
			
			diffSpikeRepartitionInputTestFile->addDataSeparator();
			
			for (int i=0;i<NB_HIDDEN_NEURONS;i++)
			{
				if (!SpikeRepartitionInputTest[i][7].isVoid() && !SpikeRepartitionInputTest[i][6].isVoid())
				{
					//diffSpikeRepartitionInputTestFile->addIndexedLineData(2,i,(double) SpikeRepartitionInputTest[i][3].getAccu()-SpikeRepartitionInputTest[i][0].getAccu());
					diffSpikeRepartitionInputTestFile->addIndexedLineData(3,i,(double) SpikeRepartitionInputTest[i][6].getAccu()/((double) TRANSITION_TIME_STEP)-SpikeRepartitionInputTest[i][7].getAccu()/((double) (NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP)));
				}
				else
				{
					//cout << "diffSpikeRepartitionInputTestFile is void" << endl;
					diffSpikeRepartitionInputTestFile->addIndexedLineData(3,i,-1.0);
				}
			}		
			
			diffSpikeRepartitionInputTestFile->addDataSeparator();
			
					#else
			for (int i=0;i<NB_HIDDEN_NEURONS;i++)
			{
				if (!SpikeRepartitionInputTest[i][0].isVoid() && !SpikeRepartitionInputTest[i][1].isVoid())
				{
					//diffSpikeRepartitionInputTestFile->addIndexedLineData(0,i,(double) SpikeRepartitionInputTest[i][1].getAccu()-SpikeRepartitionInputTest[i][0].getAccu());
					diffSpikeRepartitionInputTestFile->addIndexedLineData(0,i,(double) (NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP)*SpikeRepartitionInputTest[i][0].getAccu()-TRANSITION_TIME_STEP*SpikeRepartitionInputTest[i][1].getAccu());
				}
				else
				{	
					//cout << "diffSpikeRepartitionInputTestFile is void" << endl;
					diffSpikeRepartitionInputTestFile->addIndexedLineData(0,i,-1.0);
				}
			}
				
			for (int i=0;i<NB_HIDDEN_NEURONS;i++)
			{
				if (!SpikeRepartitionInputTest[i][3].isVoid() && !SpikeRepartitionInputTest[i][2].isVoid())
				{
					//diffSpikeRepartitionInputTestFile->addIndexedLineData(1,i,(double) SpikeRepartitionInputTest[i][2].getAccu()-SpikeRepartitionInputTest[i][0].getAccu());
					diffSpikeRepartitionInputTestFile->addIndexedLineData(1,i,(double) (NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP)*SpikeRepartitionInputTest[i][2].getAccu()-TRANSITION_TIME_STEP*SpikeRepartitionInputTest[i][3].getAccu());
				}
				else
				{
					//cout << "diffSpikeRepartitionInputTestFile is void" << endl;
					diffSpikeRepartitionInputTestFile->addIndexedLineData(1,i,-1.0);
				}
			}
				
			for (int i=0;i<NB_HIDDEN_NEURONS;i++)
			{
				if (!SpikeRepartitionInputTest[i][5].isVoid() && !SpikeRepartitionInputTest[i][4].isVoid())
				{
					//diffSpikeRepartitionInputTestFile->addIndexedLineData(2,i,(double) SpikeRepartitionInputTest[i][3].getAccu()-SpikeRepartitionInputTest[i][0].getAccu());
					diffSpikeRepartitionInputTestFile->addIndexedLineData(2,i,(double) (NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP)*SpikeRepartitionInputTest[i][4].getAccu()-TRANSITION_TIME_STEP*SpikeRepartitionInputTest[i][5].getAccu());
				}
				else
				{
					//cout << "diffSpikeRepartitionInputTestFile is void" << endl;
					diffSpikeRepartitionInputTestFile->addIndexedLineData(2,i,-1.0);
				}
			}		
			
			for (int i=0;i<NB_HIDDEN_NEURONS;i++)
			{
				if (!SpikeRepartitionInputTest[i][7].isVoid() && !SpikeRepartitionInputTest[i][6].isVoid())
				{
					//diffSpikeRepartitionInputTestFile->addIndexedLineData(2,i,(double) SpikeRepartitionInputTest[i][3].getAccu()-SpikeRepartitionInputTest[i][0].getAccu());
					diffSpikeRepartitionInputTestFile->addIndexedLineData(3,i,(double) (NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP)*SpikeRepartitionInputTest[i][6].getAccu()-TRANSITION_TIME_STEP*SpikeRepartitionInputTest[i][7].getAccu());
				}
				else
				{
					//cout << "diffSpikeRepartitionInputTestFile is void" << endl;
					diffSpikeRepartitionInputTestFile->addIndexedLineData(3,i,-1.0);
				}
			}		
					#endif
				
				#else
			
			for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<NB_HIDDEN_NEURONS;i++)
				{
					if (!SpikeRepartitionInputTest[i][j].isVoid())
					{
						//SpikeRepartitionInputTestFile->addIndexedLineData(j,i,(double) SpikeRepartitionInputTest[i][j].getMean());
						SpikeRepartitionInputTestFile->addIndexedLineData(j,i,(double) SpikeRepartitionInputTest[i][j].getAccu());
					}
					else
					{
						//cout << "SpikeRepartitionInputTestFile is void" << endl;
						SpikeRepartitionInputTestFile->addIndexedLineData(j,i,-1.0);
					}
				}
					#ifndef _SORT_ASSEMBLY_STAT_MODE
				SpikeRepartitionInputTestFile->addDataSeparator();
					#endif
			}
			
			for (int i=0;i<NB_HIDDEN_NEURONS;i++)
			{
				if (!SpikeRepartitionInputTest[i][0].isVoid() && !SpikeRepartitionInputTest[i][1].isVoid())
				{
					//diffSpikeRepartitionInputTestFile->addIndexedLineData(0,i,(double) SpikeRepartitionInputTest[i][1].getMean()-SpikeRepartitionInputTest[i][0].getMean());
					diffSpikeRepartitionInputTestFile->addIndexedLineData(0,i,(double) SpikeRepartitionInputTest[i][1].getAccu()-SpikeRepartitionInputTest[i][0].getAccu());
				}
				else
				{	
					//cout << "diffSpikeRepartitionInputTestFile is void" << endl;
					diffSpikeRepartitionInputTestFile->addIndexedLineData(0,i,-1.0);
				}
			}
			
					#ifndef _SORT_ASSEMBLY_STAT_MODE	
			diffSpikeRepartitionInputTestFile->addDataSeparator();
					#endif
			
			for (int i=0;i<NB_HIDDEN_NEURONS;i++)
			{
				if (!SpikeRepartitionInputTest[i][0].isVoid() && !SpikeRepartitionInputTest[i][2].isVoid())
				{
					//diffSpikeRepartitionInputTestFile->addIndexedLineData(1,i,(double) SpikeRepartitionInputTest[i][2].getMean()-SpikeRepartitionInputTest[i][0].getMean());
					diffSpikeRepartitionInputTestFile->addIndexedLineData(1,i,(double) SpikeRepartitionInputTest[i][2].getAccu()-SpikeRepartitionInputTest[i][0].getAccu());
				}
				else
				{
					//cout << "diffSpikeRepartitionInputTestFile is void" << endl;
					diffSpikeRepartitionInputTestFile->addIndexedLineData(1,i,-1.0);
				}
			}
			
					#ifndef _SORT_ASSEMBLY_STAT_MODE	
			diffSpikeRepartitionInputTestFile->addDataSeparator();
					#endif
			
			for (int i=0;i<NB_HIDDEN_NEURONS;i++)
			{
				if (!SpikeRepartitionInputTest[i][0].isVoid() && !SpikeRepartitionInputTest[i][3].isVoid())
				{
					//diffSpikeRepartitionInputTestFile->addIndexedLineData(2,i,(double) SpikeRepartitionInputTest[i][3].getMean()-SpikeRepartitionInputTest[i][0].getMean());
					diffSpikeRepartitionInputTestFile->addIndexedLineData(2,i,(double) SpikeRepartitionInputTest[i][3].getAccu()-SpikeRepartitionInputTest[i][0].getAccu());
				}
				else
				{
					//cout << "diffSpikeRepartitionInputTestFile is void" << endl;
					diffSpikeRepartitionInputTestFile->addIndexedLineData(2,i,-1.0);
				}
			}
					#ifndef _SORT_ASSEMBLY_STAT_MODE		
			diffSpikeRepartitionInputTestFile->addDataSeparator();
					#endif	
				#endif
		}
	}
	else
	{
		cerr << "Warning, SpikeRepartitionInputTestFile && diffSpikeRepartitionInputTestFile should be inited" << endl;
	}
	
	if (AssemblySpikeRepartitionInputTestFile->isOpen() && diffAssemblySpikeRepartitionInputTestFile->isOpen())
	{
		if (AssemblySpikeRepartitionInputTest)
		{
				#ifdef _TRANSITION_STAT_MODE
					#ifndef _SORT_ASSEMBLY_STAT_MODE
			for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<NB_ASSEMBLIES;i++)
				{
					if (!AssemblySpikeRepartitionInputTest[i][j].isVoid())
					{
						
						//AssemblySpikeRepartitionInputTestFile->addIndexedLineData(j,i,(double) AssemblySpikeRepartitionInputTest[i][j].getAccu());
						if (j%2==0)
						{
							AssemblySpikeRepartitionInputTestFile->addIndexedLineData(j,i,(double) AssemblySpikeRepartitionInputTest[i][j].getAccu()/((double) TRANSITION_TIME_STEP));
						}
						else
						{
							AssemblySpikeRepartitionInputTestFile->addIndexedLineData(j,i,(double) AssemblySpikeRepartitionInputTest[i][j].getAccu()/((double) (NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP)));
						}
						//AssemblySpikeRepartitionInputTestFile->addIndexedLineData(j,i,(double) AssemblySpikeRepartitionInputTest[i][j].getAccu());
					}
					else
					{
						//cout << "AssemblySpikeRepartitionInputTestFile is void" << endl;
						AssemblySpikeRepartitionInputTestFile->addIndexedLineData(j,i,-1.0);
					}
				}	
				AssemblySpikeRepartitionInputTestFile->addDataSeparator();
			}
					#else
			for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<NB_ASSEMBLIES;i++)
				{
					if (!AssemblySpikeRepartitionInputTest[i][j].isVoid())
					{
						
						//AssemblySpikeRepartitionInputTestFile->addIndexedLineData(j,i,(double) AssemblySpikeRepartitionInputTest[i][j].getAccu());
						if (j%2==0)
						{
							AssemblySpikeRepartitionInputTestFile->addIndexedLineData(j,i,(double) (NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP)*AssemblySpikeRepartitionInputTest[i][j].getAccu());
						}
						else
						{
							AssemblySpikeRepartitionInputTestFile->addIndexedLineData(j,i,(double)
							TRANSITION_TIME_STEP*AssemblySpikeRepartitionInputTest[i][j].getAccu());
						}
						//AssemblySpikeRepartitionInputTestFile->addIndexedLineData(j,i,(double) AssemblySpikeRepartitionInputTest[i][j].getAccu());
					}
					else
					{
						//cout << "AssemblySpikeRepartitionInputTestFile is void" << endl;
						AssemblySpikeRepartitionInputTestFile->addIndexedLineData(j,i,-1.0);
					}
				}	
			}
					#endif
				
					#ifndef _SORT_ASSEMBLY_STAT_MODE			
			for (int i=0;i<NB_ASSEMBLIES;i++)
			{
				if (!AssemblySpikeRepartitionInputTest[i][1].isVoid() && !AssemblySpikeRepartitionInputTest[i][0].isVoid())
				{
					diffAssemblySpikeRepartitionInputTestFile->addIndexedLineData(0,i,(double) AssemblySpikeRepartitionInputTest[i][0].getAccu()/((double) TRANSITION_TIME_STEP)-AssemblySpikeRepartitionInputTest[i][1].getAccu()/((double) (NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP)));
				}
				else
				{	
					//cout << "diffAssemblySpikeRepartitionInputTestFile is void" << endl;
					diffAssemblySpikeRepartitionInputTestFile->addIndexedLineData(0,i,-1.0);
				}
			}
			
			diffAssemblySpikeRepartitionInputTestFile->addDataSeparator();
			
			for (int i=0;i<NB_ASSEMBLIES;i++)
			{
				if (!AssemblySpikeRepartitionInputTest[i][3].isVoid() && !AssemblySpikeRepartitionInputTest[i][2].isVoid())
				{
					diffAssemblySpikeRepartitionInputTestFile->addIndexedLineData(1,i,(double) AssemblySpikeRepartitionInputTest[i][2].getAccu()/((double) TRANSITION_TIME_STEP)-AssemblySpikeRepartitionInputTest[i][3].getAccu()/((double) (NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP)));
				}
				else
				{
					//cout << "diffAssemblySpikeRepartitionInputTestFile is void" << endl;
					diffAssemblySpikeRepartitionInputTestFile->addIndexedLineData(1,i,-1.0);
				}
			}
			
			diffAssemblySpikeRepartitionInputTestFile->addDataSeparator();
			
			for (int i=0;i<NB_ASSEMBLIES;i++)
			{
				if (!AssemblySpikeRepartitionInputTest[i][5].isVoid() && !AssemblySpikeRepartitionInputTest[i][4].isVoid())
				{
					diffAssemblySpikeRepartitionInputTestFile->addIndexedLineData(2,i,(double) AssemblySpikeRepartitionInputTest[i][4].getAccu()/((double) TRANSITION_TIME_STEP)-AssemblySpikeRepartitionInputTest[i][5].getAccu()/((double) (NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP)));
				}
				else
				{
					//cout << "diffAssemblySpikeRepartitionInputTestFile is void" << endl;
					diffAssemblySpikeRepartitionInputTestFile->addIndexedLineData(2,i,-1.0);
				}
			}
			
			diffAssemblySpikeRepartitionInputTestFile->addDataSeparator();
			
			for (int i=0;i<NB_ASSEMBLIES;i++)
			{
				if (!AssemblySpikeRepartitionInputTest[i][7].isVoid() && !AssemblySpikeRepartitionInputTest[i][6].isVoid())
				{
					diffAssemblySpikeRepartitionInputTestFile->addIndexedLineData(3,i,(double) AssemblySpikeRepartitionInputTest[i][6].getAccu()/((double) TRANSITION_TIME_STEP)-AssemblySpikeRepartitionInputTest[i][7].getAccu()/((double) (NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP)));
				}
				else
				{
					//cout << "diffAssemblySpikeRepartitionInputTestFile is void" << endl;
					diffAssemblySpikeRepartitionInputTestFile->addIndexedLineData(3,i,-1.0);
				}
			}		
			
			diffAssemblySpikeRepartitionInputTestFile->addDataSeparator();
			
					#else
			for (int i=0;i<NB_ASSEMBLIES;i++)
			{
				if (!AssemblySpikeRepartitionInputTest[i][1].isVoid() && !AssemblySpikeRepartitionInputTest[i][0].isVoid())
				{
					diffAssemblySpikeRepartitionInputTestFile->addIndexedLineData(0,i,(double) (NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP)*AssemblySpikeRepartitionInputTest[i][0].getAccu()-TRANSITION_TIME_STEP*AssemblySpikeRepartitionInputTest[i][1].getAccu());
				}
				else
				{	
					//cout << "diffAssemblySpikeRepartitionInputTestFile is void" << endl;
					diffAssemblySpikeRepartitionInputTestFile->addIndexedLineData(0,i,-1.0);
				}
			}
			
			for (int i=0;i<NB_ASSEMBLIES;i++)
			{
				if (!AssemblySpikeRepartitionInputTest[i][3].isVoid() && !AssemblySpikeRepartitionInputTest[i][2].isVoid())
				{
					diffAssemblySpikeRepartitionInputTestFile->addIndexedLineData(1,i,(double) (NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP)*AssemblySpikeRepartitionInputTest[i][2].getAccu()-TRANSITION_TIME_STEP*AssemblySpikeRepartitionInputTest[i][3].getAccu());
				}
				else
				{
					//cout << "diffAssemblySpikeRepartitionInputTestFile is void" << endl;
					diffAssemblySpikeRepartitionInputTestFile->addIndexedLineData(1,i,-1.0);
				}
			}
			
			for (int i=0;i<NB_ASSEMBLIES;i++)
			{
				if (!AssemblySpikeRepartitionInputTest[i][5].isVoid() && !AssemblySpikeRepartitionInputTest[i][4].isVoid())
				{
					diffAssemblySpikeRepartitionInputTestFile->addIndexedLineData(2,i,(double) (NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP)*AssemblySpikeRepartitionInputTest[i][4].getAccu()-TRANSITION_TIME_STEP*AssemblySpikeRepartitionInputTest[i][5].getAccu());
				}
				else
				{
					//cout << "diffAssemblySpikeRepartitionInputTestFile is void" << endl;
					diffAssemblySpikeRepartitionInputTestFile->addIndexedLineData(2,i,-1.0);
				}
			}
			
			for (int i=0;i<NB_ASSEMBLIES;i++)
			{
				if (!AssemblySpikeRepartitionInputTest[i][7].isVoid() && !AssemblySpikeRepartitionInputTest[i][6].isVoid())
				{
					diffAssemblySpikeRepartitionInputTestFile->addIndexedLineData(3,i,(double) (NB_MAX_TEST_STEPS-TRANSITION_TIME_STEP)*AssemblySpikeRepartitionInputTest[i][6].getAccu()-TRANSITION_TIME_STEP*AssemblySpikeRepartitionInputTest[i][7].getAccu());
				}
				else
				{
					//cout << "diffAssemblySpikeRepartitionInputTestFile is void" << endl;
					diffAssemblySpikeRepartitionInputTestFile->addIndexedLineData(3,i,-1.0);
				}
			}
			
					#endif	
				#else
			for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<NB_ASSEMBLIES;i++)
				{
					if (!AssemblySpikeRepartitionInputTest[i][j].isVoid())
					{
						//AssemblySpikeRepartitionInputTestFile->addIndexedLineData(j,i,(double) AssemblySpikeRepartitionInputTest[i][j].getMean());
						AssemblySpikeRepartitionInputTestFile->addIndexedLineData(j,i,(double) AssemblySpikeRepartitionInputTest[i][j].getAccu());
					}
					else
					{
						//cout << "AssemblySpikeRepartitionInputTestFile is void" << endl;
						AssemblySpikeRepartitionInputTestFile->addIndexedLineData(j,i,-1.0);
					}
				}
					#ifndef _SORT_ASSEMBLY_STAT_MODE	
				AssemblySpikeRepartitionInputTestFile->addDataSeparator();
					#endif
			}
			
			for (int i=0;i<NB_ASSEMBLIES;i++)
			{
				if (!AssemblySpikeRepartitionInputTest[i][0].isVoid() && !AssemblySpikeRepartitionInputTest[i][1].isVoid())
				{
					//diffAssemblySpikeRepartitionInputTestFile->addIndexedLineData(0,i,(double) AssemblySpikeRepartitionInputTest[i][1].getMean()-AssemblySpikeRepartitionInputTest[i][0].getMean());
					diffAssemblySpikeRepartitionInputTestFile->addIndexedLineData(0,i,(double) AssemblySpikeRepartitionInputTest[i][1].getAccu()-AssemblySpikeRepartitionInputTest[i][0].getAccu());
				}
				else
				{	
					//cout << "diffAssemblySpikeRepartitionInputTestFile is void" << endl;
					diffAssemblySpikeRepartitionInputTestFile->addIndexedLineData(0,i,-1.0);
				}
			}
				
					#ifndef _SORT_ASSEMBLY_STAT_MODE	
			diffAssemblySpikeRepartitionInputTestFile->addDataSeparator();
					#endif
			
			for (int i=0;i<NB_ASSEMBLIES;i++)
			{
				if (!AssemblySpikeRepartitionInputTest[i][0].isVoid() && !AssemblySpikeRepartitionInputTest[i][2].isVoid())
				{
					//diffAssemblySpikeRepartitionInputTestFile->addIndexedLineData(1,i,(double) AssemblySpikeRepartitionInputTest[i][2].getMean()-AssemblySpikeRepartitionInputTest[i][0].getMean());
					diffAssemblySpikeRepartitionInputTestFile->addIndexedLineData(1,i,(double) AssemblySpikeRepartitionInputTest[i][2].getAccu()-AssemblySpikeRepartitionInputTest[i][0].getAccu());
				}
				else
				{
					//cout << "diffAssemblySpikeRepartitionInputTestFile is void" << endl;
					diffAssemblySpikeRepartitionInputTestFile->addIndexedLineData(1,i,-1.0);
				}
			}
				
					#ifndef _SORT_ASSEMBLY_STAT_MODE	
			diffAssemblySpikeRepartitionInputTestFile->addDataSeparator();
					#endif
			
			for (int i=0;i<NB_ASSEMBLIES;i++)
			{
				if (!AssemblySpikeRepartitionInputTest[i][0].isVoid() && !AssemblySpikeRepartitionInputTest[i][3].isVoid())
				{
					//diffAssemblySpikeRepartitionInputTestFile->addIndexedLineData(2,i,(double) AssemblySpikeRepartitionInputTest[i][3].getMean()-AssemblySpikeRepartitionInputTest[i][0].getMean());
					diffAssemblySpikeRepartitionInputTestFile->addIndexedLineData(2,i,(double) AssemblySpikeRepartitionInputTest[i][3].getAccu()-AssemblySpikeRepartitionInputTest[i][0].getAccu());
				}
				else
				{
					//cout << "diffAssemblySpikeRepartitionInputTestFile is void" << endl;
					diffAssemblySpikeRepartitionInputTestFile->addIndexedLineData(2,i,-1.0);
				}
			}
				
					#ifndef _SORT_ASSEMBLY_STAT_MODE	
			diffAssemblySpikeRepartitionInputTestFile->addDataSeparator();
					#endif	
				#endif
		}
	}
	else
	{
		cerr << "Warning, AssemblySpikeRepartitionInputTestFile && diffAssemblySpikeRepartitionInputTestFile should be inited" << endl;
	}
			#endif	
		#endif
}

void InputTester::initAccumulaters()
{
		#ifdef _PARAMETRIC_TEST_MODE
			#ifdef _PHASE_TEST_MODE
	if (timeFrequencyInputTest)
	{
		for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
		{
			for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<NB_FREQUENCY_BINS;i++)
				{
					timeFrequencyInputTest[i][j][k].initAccu();
				}
			}
		}
	}
	else
	{
		cerr << "Warning, timeFrequencyInputTest should be inited" << endl;
	}

	if (highTimeFrequencyInputTest)
	{
		for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
		{
			for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
				{
					highTimeFrequencyInputTest[i][j][k].initAccu();
				}
			}
		}
	}
	else
	{
		cerr << "Warning, highTimeFrequencyInputTest should be inited" << endl;
	}
	
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	if (excitPreTempDevRepartitionInputTest)
	{
		for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
		{
			for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<100;i++)
				{
					excitPreTempDevRepartitionInputTest[i][j][k].initAccu();
				}
			}
		}
	}
	else
	{
		cerr << "Warning, highTimeFrequencyInputTest should be inited" << endl;
	}
	
	if (excitPostTempDevRepartitionInputTest)
	{
		for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
		{
			for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<100;i++)
				{
					excitPostTempDevRepartitionInputTest[i][j][k].initAccu();
				}
			}
		}
	}
	else
	{
		cerr << "Warning, highTimeFrequencyInputTest should be inited" << endl;
	}
	
	if (inhibPreTempDevRepartitionInputTest)
	{
		for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
		{
			for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<100;i++)
				{
					inhibPreTempDevRepartitionInputTest[i][j][k].initAccu();
				}
			}
		}
	}
	else
	{
		cerr << "Warning, inhibPreTempDevRepartitionInputTest should be inited" << endl;
	}
	
	if (inhibPostTempDevRepartitionInputTest)
	{
		for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
		{
			for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<100;i++)
				{
					inhibPostTempDevRepartitionInputTest[i][j][k].initAccu();
				}
			}
		}
	}
	else
	{
		cerr << "Warning, inhibPostTempDevRepartitionInputTest should be inited" << endl;
	}
				#endif
				
	if (ISIRepartitionInputTest)
	{
		for (int k=0;k<NB_PARAMETRIC_TESTS;k++)
		{
			for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
			{
				for (int i=0;i<100;i++)
				{
					ISIRepartitionInputTest[i][j][k].initAccu();
				}
			}
		}
	}
	else
	{
		cerr << "Warning, ISIRepartitionInputTest should be inited" << endl;
	}
			#else
	if (timeFrequencyInputTest)
	{
		for (int j=0;j<NB_PARAMETRIC_TESTS;j++)
		{
			for (int i=0;i<NB_FREQUENCY_BINS;i++)
			{
				timeFrequencyInputTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, timeFrequencyInputTest should be inited" << endl;
	}

	if (highTimeFrequencyInputTest)
	{
		for (int j=0;j<NB_PARAMETRIC_TESTS;j++)
		{
			for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
			{
				highTimeFrequencyInputTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, highTimeFrequencyInputTest should be inited" << endl;
	}
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	if (excitPreTempDevRepartitionInputTest)
	{
		for (int j=0;j<NB_PARAMETRIC_TESTS;j++)
		{
			for (int i=0;i<100;i++)
			{
				excitPreTempDevRepartitionInputTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, excitPreTempDevRepartitionInputTest should be inited" << endl;
	}
	
	if (excitPostTempDevRepartitionInputTest)
	{
		for (int j=0;j<NB_PARAMETRIC_TESTS;j++)
		{
			for (int i=0;i<100;i++)
			{
				excitPostTempDevRepartitionInputTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, excitPostTempDevRepartitionInputTest should be inited" << endl;
	}
	
	if (inhibPreTempDevRepartitionInputTest)
	{
		for (int j=0;j<NB_PARAMETRIC_TESTS;j++)
		{
			for (int i=0;i<100;i++)
			{
				inhibPreTempDevRepartitionInputTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, inhibPreTempDevRepartitionInputTest should be inited" << endl;
	}
	
	if (inhibPostTempDevRepartitionInputTest)
	{
		for (int j=0;j<NB_PARAMETRIC_TESTS;j++)
		{
			for (int i=0;i<100;i++)
			{
				inhibPostTempDevRepartitionInputTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, inhibPostTempDevRepartitionInputTest should be inited" << endl;
	}
				#endif
				
	if (ISIRepartitionInputTest)
	{
		for (int j=0;j<NB_PARAMETRIC_TESTS;j++)
		{
			for (int i=0;i<100;i++)
			{
				ISIRepartitionInputTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, inhibPostTempDevRepartitionInputTest should be inited" << endl;
	}
			#endif
		#else
			#ifdef _PHASE_TEST_MODE
				#ifdef _TRANSITION_STAT_MODE
	if (timeFrequencyInputTest)
	{
		for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			for (int i=0;i<NB_FREQUENCY_BINS;i++)
			{
				timeFrequencyInputTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, timeFrequencyInputTest should be inited" << endl;
	}

	if (highTimeFrequencyInputTest)
	{
		for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
			{
				highTimeFrequencyInputTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, highTimeFrequencyInputTest should be inited" << endl;
	}
	
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	if (excitPreTempDevRepartitionInputTest)
	{
		for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			for (int i=0;i<100;i++)
			{
				excitPreTempDevRepartitionInputTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, highTimeFrequencyInputTest should be inited" << endl;
	}
	
	if (excitPostTempDevRepartitionInputTest)
	{
		for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			for (int i=0;i<100;i++)
			{
				excitPostTempDevRepartitionInputTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, highTimeFrequencyInputTest should be inited" << endl;
	}
	
	if (inhibPreTempDevRepartitionInputTest)
	{
		for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			for (int i=0;i<100;i++)
			{
				inhibPreTempDevRepartitionInputTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, inhibPreTempDevRepartitionInputTest should be inited" << endl;
	}
	
	if (inhibPostTempDevRepartitionInputTest)
	{
		for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			for (int i=0;i<100;i++)
			{
				inhibPostTempDevRepartitionInputTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, inhibPostTempDevRepartitionInputTest should be inited" << endl;
	}
				#endif
				
	if (ISIRepartitionInputTest)
	{
		for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			for (int i=0;i<100;i++)
			{
				ISIRepartitionInputTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, ISIRepartitionInputTest should be inited" << endl;
	}
	
	
	if (SpikeRepartitionInputTest)
	{
		for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			for (int i=0;i<NB_HIDDEN_NEURONS;i++)
			{
				SpikeRepartitionInputTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, SpikeRepartitionInputTest should be inited" << endl;
	}
	
	
	if (AssemblySpikeRepartitionInputTest)
	{
		for (int j=0;j<2*(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			for (int i=0;i<NB_ASSEMBLIES;i++)
			{
				AssemblySpikeRepartitionInputTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, AssemblySpikeRepartitionInputTest should be inited" << endl;
	}
			#else
	if (timeFrequencyInputTest)
	{
		for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			for (int i=0;i<NB_FREQUENCY_BINS;i++)
			{
				timeFrequencyInputTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, timeFrequencyInputTest should be inited" << endl;
	}

	if (highTimeFrequencyInputTest)
	{
		for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
			{
				highTimeFrequencyInputTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, highTimeFrequencyInputTest should be inited" << endl;
	}
	
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	if (excitPreTempDevRepartitionInputTest)
	{
		for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			for (int i=0;i<100;i++)
			{
				excitPreTempDevRepartitionInputTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, highTimeFrequencyInputTest should be inited" << endl;
	}
	
	if (excitPostTempDevRepartitionInputTest)
	{
		for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			for (int i=0;i<100;i++)
			{
				excitPostTempDevRepartitionInputTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, highTimeFrequencyInputTest should be inited" << endl;
	}
	
	if (inhibPreTempDevRepartitionInputTest)
	{
		for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			for (int i=0;i<100;i++)
			{
				inhibPreTempDevRepartitionInputTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, inhibPreTempDevRepartitionInputTest should be inited" << endl;
	}
	
	if (inhibPostTempDevRepartitionInputTest)
	{
		for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			for (int i=0;i<100;i++)
			{
				inhibPostTempDevRepartitionInputTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, inhibPostTempDevRepartitionInputTest should be inited" << endl;
	}
				#endif
				
	if (ISIRepartitionInputTest)
	{
		for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			for (int i=0;i<100;i++)
			{
				ISIRepartitionInputTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, ISIRepartitionInputTest should be inited" << endl;
	}
	
	
	if (SpikeRepartitionInputTest)
	{
		for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			for (int i=0;i<NB_HIDDEN_NEURONS;i++)
			{
				SpikeRepartitionInputTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, SpikeRepartitionInputTest should be inited" << endl;
	}
	
	
	if (AssemblySpikeRepartitionInputTest)
	{
		for (int j=0;j<(1+2*NB_TESTED_ANIMALS+1);j++)
		{
			for (int i=0;i<NB_ASSEMBLIES;i++)
			{
				AssemblySpikeRepartitionInputTest[i][j].initAccu();
			}
		}
	}
	else
	{
		cerr << "Warning, AssemblySpikeRepartitionInputTest should be inited" << endl;
	}
				#endif
			#endif
		#endif
}

		#ifdef _PARAMETRIC_TEST_MODE
void InputTester::stat(int paramIndex)
{
			#ifdef _PHASE_TEST_MODE
	if (timeFrequencyInputTest)
	{
		for (int i=0;i<NB_FREQUENCY_BINS;i++)
		{
			if (!meanInputTimeFrequency[i].isVoid())
			{
				timeFrequencyInputTest[i][getEvalIndex()][paramIndex].accumulate((double) meanInputTimeFrequency[i].getMean());
				meanInputTimeFrequency[i].initAccu();
			}
			else
			{
				timeFrequencyInputTest[i][getEvalIndex()][paramIndex].setVoid();
				meanInputTimeFrequency[i].freeVoid();
			}
		}
	}
	else
	{
		cerr << "Warning, timeFrequencyInputTest should be inited" << endl;
	}

	if (highTimeFrequencyInputTest)
	{
		for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
		{
			if (!meanInputHighTimeFrequency[i].isVoid())
			{
				highTimeFrequencyInputTest[i][getEvalIndex()][paramIndex].accumulate((double) meanInputHighTimeFrequency[i].getMean());
				meanInputHighTimeFrequency[i].initAccu();
			}
			else
			{
				highTimeFrequencyInputTest[i][getEvalIndex()][paramIndex].setVoid();
				meanInputHighTimeFrequency[i].freeVoid();
			}
		}
	}
	else
	{
		cerr << "Warning, highTimeFrequencyInputTest should be inited" << endl;
	}

				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	if (excitPreTempDevRepartitionInputTest)
	{
		for (int i=0;i<100;i++)
		{
			if (!meanInputExcitPreTempDevRepartition[i].isVoid())
			{
				excitPreTempDevRepartitionInputTest[i][getEvalIndex()][paramIndex].accumulate((double) meanInputExcitPreTempDevRepartition[i].getMean());
				meanInputExcitPreTempDevRepartition[i].initAccu();
			}
			else
			{
				excitPreTempDevRepartitionInputTest[i][getEvalIndex()][paramIndex].setVoid();
				meanInputExcitPreTempDevRepartition[i].freeVoid();
			}
		}
	}

	if (excitPostTempDevRepartitionInputTest)
	{
		for (int i=0;i<100;i++)
		{
			if (!meanInputExcitPostTempDevRepartition[i].isVoid())
			{
				excitPostTempDevRepartitionInputTest[i][getEvalIndex()][paramIndex].accumulate((double) meanInputExcitPostTempDevRepartition[i].getMean());
				meanInputExcitPostTempDevRepartition[i].initAccu();
			}
			else
			{
				excitPostTempDevRepartitionInputTest[i][getEvalIndex()][paramIndex].setVoid();
				meanInputExcitPostTempDevRepartition[i].freeVoid();
			}
		}
	}
	
	if (inhibPreTempDevRepartitionInputTest)
	{
		for (int i=0;i<100;i++)
		{
			if (!meanInputInhibPreTempDevRepartition[i].isVoid())
			{
				inhibPreTempDevRepartitionInputTest[i][getEvalIndex()][paramIndex].accumulate((double) meanInputInhibPreTempDevRepartition[i].getMean());
				meanInputInhibPreTempDevRepartition[i].initAccu();
			}
			else
			{
				inhibPreTempDevRepartitionInputTest[i][getEvalIndex()][paramIndex].setVoid();
				meanInputInhibPreTempDevRepartition[i].freeVoid();
			}
		}
	}

	if (inhibPostTempDevRepartitionInputTest)
	{
		for (int i=0;i<100;i++)
		{
			if (!meanInputInhibPostTempDevRepartition[i].isVoid())
			{
				inhibPostTempDevRepartitionInputTest[i][getEvalIndex()][paramIndex].accumulate((double) meanInputInhibPostTempDevRepartition[i].getMean());
				meanInputInhibPostTempDevRepartition[i].initAccu();
			}
			else
			{
				inhibPostTempDevRepartitionInputTest[i][getEvalIndex()][paramIndex].setVoid();
				meanInputInhibPostTempDevRepartition[i].freeVoid();
			}
		}
	}
				#endif
				
	if (ISIRepartitionInputTest)
	{
		for (int i=0;i<100;i++)
		{
			if (!meanInputISIRepartition[i].isVoid())
			{
				ISIRepartitionInputTest[i][getEvalIndex()][paramIndex].accumulate((double) meanInputISIRepartition[i].getMean());
				meanInputISIRepartition[i].initAccu();
			}
			else
			{
				ISIRepartitionInputTest[i][getEvalIndex()][paramIndex].setVoid();
				meanInputISIRepartition[i].freeVoid();
			}
		}
	}
	else
	{
		cerr << "Warning, ISIRepartitionInputTest should be inited" << endl;
	}
	
			#else
	if (timeFrequencyInputTest)
	{
		for (int i=0;i<NB_FREQUENCY_BINS;i++)
		{
			if (!meanInputTimeFrequency[i].isVoid())
			{
				timeFrequencyInputTest[i][paramIndex].accumulate((double) meanInputTimeFrequency[i].getMean());
				meanInputTimeFrequency[i].initAccu();
			}
			else
			{
				timeFrequencyInputTest[i][paramIndex].setVoid();
				meanInputTimeFrequency[i].freeVoid();
			}
		}
	}
	else
	{
		cerr << "Warning, timeFrequencyInputTest should be inited" << endl;
	}

	if (highTimeFrequencyInputTest)
	{
		for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
		{
			if (!meanInputHighTimeFrequency[i].isVoid())
			{
				highTimeFrequencyInputTest[i][paramIndex].accumulate((double) meanInputHighTimeFrequency[i].getMean());
				meanInputHighTimeFrequency[i].initAccu();
			}
			else
			{
				highTimeFrequencyInputTest[i][paramIndex].setVoid();
				meanInputHighTimeFrequency[i].freeVoid();
			}
		}
	}
	else
	{
		cerr << "Warning, highTimeFrequencyInputTest should be inited" << endl;
	}
	
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	if (excitPreTempDevRepartitionInputTest)
	{
		for (int i=0;i<100;i++)
		{
			if (!meanInputExcitPreTempDevRepartition[i].isVoid())
			{
				excitPreTempDevRepartitionInputTest[i][paramIndex].accumulate((double) meanInputExcitPreTempDevRepartition[i].getMean());
				meanInputExcitPreTempDevRepartition[i].initAccu();
			}
			else
			{
				excitPreTempDevRepartitionInputTest[i][paramIndex].setVoid();
				meanInputExcitPreTempDevRepartition[i].freeVoid();
			}
		}
	}

	if (excitPostTempDevRepartitionInputTest)
	{
		for (int i=0;i<100;i++)
		{
			if (!meanInputExcitPostTempDevRepartition[i].isVoid())
			{
				excitPostTempDevRepartitionInputTest[i][paramIndex].accumulate((double) meanInputExcitPostTempDevRepartition[i].getMean());
				meanInputExcitPostTempDevRepartition[i].initAccu();
			}
			else
			{
				excitPostTempDevRepartitionInputTest[i][paramIndex].setVoid();
				meanInputExcitPostTempDevRepartition[i].freeVoid();
			}
		}
	}
	
	if (inhibPreTempDevRepartitionInputTest)
	{
		for (int i=0;i<100;i++)
		{
			if (!meanInputInhibPreTempDevRepartition[i].isVoid())
			{
				inhibPreTempDevRepartitionInputTest[i][paramIndex].accumulate((double) meanInputInhibPreTempDevRepartition[i].getMean());
				meanInputInhibPreTempDevRepartition[i].initAccu();
			}
			else
			{
				inhibPreTempDevRepartitionInputTest[i][paramIndex].setVoid();
				meanInputInhibPreTempDevRepartition[i].freeVoid();
			}
		}
	}

	if (inhibPostTempDevRepartitionInputTest)
	{
		for (int i=0;i<100;i++)
		{
			if (!meanInputInhibPostTempDevRepartition[i].isVoid())
			{
				inhibPostTempDevRepartitionInputTest[i][paramIndex].accumulate((double) meanInputInhibPostTempDevRepartition[i].getMean());
				meanInputInhibPostTempDevRepartition[i].initAccu();
			}
			else
			{
				inhibPostTempDevRepartitionInputTest[i][paramIndex].setVoid();
				meanInputInhibPostTempDevRepartition[i].freeVoid();
			}
		}
	}
				#endif
				
	if (ISIRepartitionInputTest)
	{
		for (int i=0;i<100;i++)
		{
			if (!meanInputISIRepartition[i].isVoid())
			{
				ISIRepartitionInputTest[i][paramIndex].accumulate((double) meanInputISIRepartition[i].getMean());
				meanInputISIRepartition[i].initAccu();
			}
			else
			{
				ISIRepartitionInputTest[i][paramIndex].setVoid();
				meanInputISIRepartition[i].freeVoid();
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
void InputTester::stat()
{
	if (timeFrequencyInputTest)
	{
		for (int i=0;i<NB_FREQUENCY_BINS;i++)
		{
			if (!meanInputTimeFrequency[i].isVoid())
			{
				timeFrequencyInputTest[i][getEvalIndex()].accumulate((double) meanInputTimeFrequency[i].getMean());
				meanInputTimeFrequency[i].initAccu();
			}
			else
			{
				timeFrequencyInputTest[i][getEvalIndex()].setVoid();
				meanInputTimeFrequency[i].freeVoid();
			}
		}
	}
	else
	{
		cerr << "Warning, timeFrequencyInputTest should be inited" << endl;
	}

	if (highTimeFrequencyInputTest)
	{
		for (int i=0;i<NB_HIGH_FREQUENCY_BINS;i++)
		{
			if (!meanInputHighTimeFrequency[i].isVoid())
			{
				highTimeFrequencyInputTest[i][getEvalIndex()].accumulate((double) meanInputHighTimeFrequency[i].getMean());
				meanInputHighTimeFrequency[i].initAccu();
			}
			else
			{
				highTimeFrequencyInputTest[i][getEvalIndex()].setVoid();
				meanInputHighTimeFrequency[i].freeVoid();
			}
		}
	}
	else
	{
		cerr << "Warning, highTimeFrequencyInputTest should be inited" << endl;
	}
	
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	if (excitPreTempDevRepartitionInputTest)
	{
		for (int i=0;i<100;i++)
		{
			if (!meanInputExcitPreTempDevRepartition[i].isVoid())
			{
				excitPreTempDevRepartitionInputTest[i][getEvalIndex()].accumulate((double) meanInputExcitPreTempDevRepartition[i].getMean());
				meanInputExcitPreTempDevRepartition[i].initAccu();
			}
			else
			{
				excitPreTempDevRepartitionInputTest[i][getEvalIndex()].setVoid();
				meanInputExcitPreTempDevRepartition[i].freeVoid();
			}
		}
	}

	if (excitPostTempDevRepartitionInputTest)
	{
		for (int i=0;i<100;i++)
		{
			if (!meanInputExcitPostTempDevRepartition[i].isVoid())
			{
				excitPostTempDevRepartitionInputTest[i][getEvalIndex()].accumulate((double) meanInputExcitPostTempDevRepartition[i].getMean());
				meanInputExcitPostTempDevRepartition[i].initAccu();
			}
			else
			{
				excitPostTempDevRepartitionInputTest[i][getEvalIndex()].setVoid();
				meanInputExcitPostTempDevRepartition[i].freeVoid();
			}
		}
	}
	
	if (inhibPreTempDevRepartitionInputTest)
	{
		for (int i=0;i<100;i++)
		{
			if (!meanInputInhibPreTempDevRepartition[i].isVoid())
			{
				inhibPreTempDevRepartitionInputTest[i][getEvalIndex()].accumulate((double) meanInputInhibPreTempDevRepartition[i].getMean());
				meanInputInhibPreTempDevRepartition[i].initAccu();
			}
			else
			{
				inhibPreTempDevRepartitionInputTest[i][getEvalIndex()].setVoid();
				meanInputInhibPreTempDevRepartition[i].freeVoid();
			}
		}
	}

	if (inhibPostTempDevRepartitionInputTest)
	{
		for (int i=0;i<100;i++)
		{
			if (!meanInputInhibPostTempDevRepartition[i].isVoid())
			{
				inhibPostTempDevRepartitionInputTest[i][getEvalIndex()].accumulate((double) meanInputInhibPostTempDevRepartition[i].getMean());
				meanInputInhibPostTempDevRepartition[i].initAccu();
			}
			else
			{
				inhibPostTempDevRepartitionInputTest[i][getEvalIndex()].setVoid();
				meanInputInhibPostTempDevRepartition[i].freeVoid();
			}
		}
	}
				#endif
				
	if (ISIRepartitionInputTest)
	{
		for (int i=0;i<100;i++)
		{
			if (!meanInputISIRepartition[i].isVoid())
			{
				ISIRepartitionInputTest[i][getEvalIndex()].accumulate((double) meanInputISIRepartition[i].getMean());
				meanInputISIRepartition[i].initAccu();
			}
			else
			{
				ISIRepartitionInputTest[i][getEvalIndex()].setVoid();
				meanInputISIRepartition[i].freeVoid();
			}
		}
	}
	else
	{
		cerr << "Warning, ISIRepartitionInputTest should be inited" << endl;
	}
	
	if (AssemblySpikeRepartitionInputTest)
	{
		for (int i=0;i<NB_ASSEMBLIES;i++)
		{
			for (int j=0;j<NB_NEURONS_EACH_ASSEMBLY;j++)
			{
				if (!meanInputSpikeRepartition[i*NB_NEURONS_EACH_ASSEMBLY+j].isVoid())
				{
					AssemblySpikeRepartitionInputTest[i][getEvalIndex()].accumulate((double) meanInputSpikeRepartition[i*NB_NEURONS_EACH_ASSEMBLY+j].getMean());
				}
				else
				{
					AssemblySpikeRepartitionInputTest[i][getEvalIndex()].setVoid();
					meanInputSpikeRepartition[i*NB_NEURONS_EACH_ASSEMBLY+j].freeVoid();
				}
			}
		}
	}
	else
	{
		cerr << "Warning, AssemblySpikeRepartitionInputTest should be inited" << endl;
	}
	
	if (SpikeRepartitionInputTest)
	{
		for (int i=0;i<NB_HIDDEN_NEURONS;i++)
		{
			if (!meanInputSpikeRepartition[i].isVoid())
			{
				SpikeRepartitionInputTest[i][getEvalIndex()].accumulate((double) meanInputSpikeRepartition[i].getMean());
				meanInputSpikeRepartition[i].initAccu();
			}
			else
			{
				SpikeRepartitionInputTest[i][getEvalIndex()].setVoid();
				meanInputSpikeRepartition[i].freeVoid();
			}
		}
	}
	else
	{
		cerr << "Warning, SpikeRepartitionInputTest should be inited" << endl;
	}
}
			#endif
		#endif

void InputTester::graph()
{
	if (activityInputTestGnuplotFile->isOpen())
	{
		//#ifdef _TEST_STAT
		cout << "In InputInputTester graph" << endl;
		//#endif
	
		#ifdef _PARAMETRIC_TEST_MODE
			#ifdef _CONDITIONAL_TEST_MODE
		activityInputTestGnuplotFile->setOutput("timeFrequencyInputTest0");
		activityInputTestGnuplotFile->setTitle("time FrequencyInputTest0");
		activityInputTestGnuplotFile->plotTitleIndexedLines("timeFrequencyInputTestStats",0,2*(NB_TESTED_ANIMALS+1));
		
		activityInputTestGnuplotFile->setOutput("highTimeFrequencyInputTest0");
		activityInputTestGnuplotFile->setTitle("high TimeFrequency InputTest0");
		activityInputTestGnuplotFile->plotTitleIndexedLines("highTimeFrequencyInputTestStats",0,2*(NB_TESTED_ANIMALS+1));
		
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
		activityInputTestGnuplotFile->setOutput("excitTempDevRepartitionInputTestStats0");
		activityInputTestGnuplotFile->setTitle("Excit tempDev Repartition InputTest Stats0");
		activityInputTestGnuplotFile->plotTitleIndexedLines("excitTempDevRepartitionInputTestStats",0,2*(NB_TESTED_ANIMALS+1));	
		
		activityInputTestGnuplotFile->setOutput("inhibTempDevRepartitionInputTestStats0");
		activityInputTestGnuplotFile->setTitle("Inhib tempDev Repartition InputTest Stats0");
		activityInputTestGnuplotFile->plotTitleIndexedLines("inhibTempDevRepartitionInputTestStats",0,2*(NB_TESTED_ANIMALS+1));	
				#endif
				
		activityInputTestGnuplotFile->setOutput("ISIRepartitionInputTestStats0");
		activityInputTestGnuplotFile->setTitle("ISI Repartition InputTest Stats0");
		activityInputTestGnuplotFile->plotTitleIndexedLines("ISIRepartitionInputTestStats",0,2*(NB_TESTED_ANIMALS+1));
		
		activityInputTestGnuplotFile->setOutput("timeFrequencyInputTest1");
		activityInputTestGnuplotFile->setTitle("time FrequencyInputTest1");
		activityInputTestGnuplotFile->plotTitleIndexedLines("timeFrequencyInputTestStats",2*(NB_TESTED_ANIMALS+1),NB_PARAMETRIC_TESTS*2*(NB_TESTED_ANIMALS+1));
		
		activityInputTestGnuplotFile->setOutput("highTimeFrequencyInputTest1");
		activityInputTestGnuplotFile->setTitle("high TimeFrequency InputTest1");
		activityInputTestGnuplotFile->plotTitleIndexedLines("highTimeFrequencyInputTestStats",2*(NB_TESTED_ANIMALS+1),NB_PARAMETRIC_TESTS*2*(NB_TESTED_ANIMALS+1));
		
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
		activityInputTestGnuplotFile->setOutput("excitTempDevRepartitionInputTestStats1");
		activityInputTestGnuplotFile->setTitle("Excit tempDev Repartition InputTest Stats1");
		activityInputTestGnuplotFile->plotTitleIndexedLines("excitTempDevRepartitionInputTestStats",2*(NB_TESTED_ANIMALS+1),NB_PARAMETRIC_TESTS*2*(NB_TESTED_ANIMALS+1));	
		
		activityInputTestGnuplotFile->setOutput("inhibTempDevRepartitionInputTestStats1");
		activityInputTestGnuplotFile->setTitle("Inhib tempDev Repartition InputTest Stats1");
		activityInputTestGnuplotFile->plotTitleIndexedLines("inhibTempDevRepartitionInputTestStats",2*(NB_TESTED_ANIMALS+1),NB_PARAMETRIC_TESTS*2*(NB_TESTED_ANIMALS+1));	
				#endif
				
		activityInputTestGnuplotFile->setOutput("ISIRepartitionInputTestStats1");
		activityInputTestGnuplotFile->setTitle("ISI Repartition InputTest Stats1");
		activityInputTestGnuplotFile->plotTitleIndexedLines("ISIRepartitionInputTestStats",2*(NB_TESTED_ANIMALS+1),NB_PARAMETRIC_TESTS*2*(NB_TESTED_ANIMALS+1));
		
				#ifdef _PHASE_TEST_MODE
		activityInputTestGnuplotFile->setOutput("diffTimeFrequencyInputTest");
		activityInputTestGnuplotFile->setTitle("diff TimeFrequency InputTest");
		activityInputTestGnuplotFile->plotTitleIndexedLines("diffTimeFrequencyInputTestStats",0,2*(NB_TESTED_ANIMALS+1));
		
		activityInputTestGnuplotFile->setOutput("diffHighTimeFrequencyInputTest");
		activityInputTestGnuplotFile->setTitle("diff High TimeFrequency InputTest");
		activityInputTestGnuplotFile->plotTitleIndexedLines("diffHighTimeFrequencyInputTestStats",0,2*(NB_TESTED_ANIMALS+1));
					#ifdef _GLOBAL_SYNAPSE_STAT_MODE
		activityInputTestGnuplotFile->setOutput("diffExcitTempDevRepartitionInputTestStats");
		activityInputTestGnuplotFile->setTitle("diff Excit TempDev Repartition InputTest Stats");
		activityInputTestGnuplotFile->plotTitleIndexedLines("diffExcitTempDevRepartitionInputTestStats",0,2*(NB_TESTED_ANIMALS+1));
		
		activityInputTestGnuplotFile->setOutput("diffInhibTempDevRepartitionInputTestStats");
		activityInputTestGnuplotFile->setTitle("diff Inhib TempDev Repartition InputTest Stats");
		activityInputTestGnuplotFile->plotTitleIndexedLines("diffInhibTempDevRepartitionInputTestStats",0,2*(NB_TESTED_ANIMALS+1));	
					#endif
					
		activityInputTestGnuplotFile->setOutput("diffISIRepartitionInputTestStats");
		activityInputTestGnuplotFile->setTitle("diff ISI Repartition InputTest Stats");
		activityInputTestGnuplotFile->plotTitleIndexedLines("diffISIRepartitionInputTestStats",0,2*(NB_TESTED_ANIMALS+1));
				#endif
			#else
		activityInputTestGnuplotFile->setOutput("timeFrequencyInputTest");
		activityInputTestGnuplotFile->setTitle("time FrequencyInputTest");
		activityInputTestGnuplotFile->plotTitleIndexedLines("timeFrequencyInputTestStats",0,NB_PARAMETRIC_TESTS);
		
		activityInputTestGnuplotFile->setOutput("highTimeFrequencyInputTest");
		activityInputTestGnuplotFile->setTitle("high TimeFrequency InputTest");
		activityInputTestGnuplotFile->plotTitleIndexedLines("highTimeFrequencyInputTestStats",0,NB_PARAMETRIC_TESTS);
					#ifdef _GLOBAL_SYNAPSE_STAT_MODE
		activityInputTestGnuplotFile->setOutput("excitTempDevRepartitionInputTestStats");
		activityInputTestGnuplotFile->setTitle("Excit tempDev Repartition InputTest Stats");
		activityInputTestGnuplotFile->plotTitleIndexedLines("excitTempDevRepartitionInputTestStats",0,NB_PARAMETRIC_TESTS);	
		
		activityInputTestGnuplotFile->setOutput("inhibTempDevRepartitionInputTestStats");
		activityInputTestGnuplotFile->setTitle("Inhib tempDev Repartition InputTest Stats");
		activityInputTestGnuplotFile->plotTitleIndexedLines("inhibTempDevRepartitionInputTestStats",0,NB_PARAMETRIC_TESTS);	
					#endif
					
		activityInputTestGnuplotFile->setOutput("ISIRepartitionInputTestStats");
		activityInputTestGnuplotFile->setTitle("ISI Repartition InputTest Stats");
		activityInputTestGnuplotFile->plotTitleIndexedLines("ISIRepartitionInputTestStats",0,NB_PARAMETRIC_TESTS);
		
				#ifdef _PHASE_TEST_MODE
		activityInputTestGnuplotFile->setOutput("diffTimeFrequencyInputTest");
		activityInputTestGnuplotFile->setTitle("diff TimeFrequency InputTest");
		activityInputTestGnuplotFile->plotTitleIndexedLines("diffTimeFrequencyInputTestStats",0,NB_PARAMETRIC_TESTS);
		
		activityInputTestGnuplotFile->setOutput("diffHighTimeFrequencyInputTest");
		activityInputTestGnuplotFile->setTitle("diff High TimeFrequency InputTest");
		activityInputTestGnuplotFile->plotTitleIndexedLines("diffHighTimeFrequencyInputTestStats",0,NB_PARAMETRIC_TESTS);
					#ifdef _GLOBAL_SYNAPSE_STAT_MODE
		activityInputTestGnuplotFile->setOutput("diffExcitTempDevRepartitionInputTestStats");
		activityInputTestGnuplotFile->setTitle("diff Excit TempDev Repartition InputTest Stats");
		activityInputTestGnuplotFile->plotTitleIndexedLines("diffExcitTempDevRepartitionInputTestStats",0,NB_PARAMETRIC_TESTS);
		
		activityInputTestGnuplotFile->setOutput("diffInhibTempDevRepartitionInputTestStats");
		activityInputTestGnuplotFile->setTitle("diff Inhib TempDev Repartition InputTest Stats");
		activityInputTestGnuplotFile->plotTitleIndexedLines("diffInhibTempDevRepartitionInputTestStats",0,NB_PARAMETRIC_TESTS);	
					#endif
					
		activityInputTestGnuplotFile->setOutput("diffISIRepartitionInputTestStats");
		activityInputTestGnuplotFile->setTitle("diff ISI Repartition InputTest Stats");
		activityInputTestGnuplotFile->plotTitleIndexedLines("diffISIRepartitionInputTestStats",0,NB_PARAMETRIC_TESTS);
				#endif
			#endif
		#else
			#ifdef _PHASE_TEST_MODE
				#ifdef _TRANSITION_STAT_MODE
		activityInputTestGnuplotFile->setOutput("timeFrequencyInputTest");
		activityInputTestGnuplotFile->setTitle("timeFrequency InputTest");
		activityInputTestGnuplotFile->plotTitleIndexedLines("timeFrequencyInputTestStats",0,4*(NB_TESTED_ANIMALS+1));
		
		activityInputTestGnuplotFile->setOutput("diffTimeFrequencyInputTest");
		activityInputTestGnuplotFile->setTitle("diff TimeFrequency InputTest");
		activityInputTestGnuplotFile->plotTitleIndexedLines("diffTimeFrequencyInputTestStats",0,2+(NB_TESTED_ANIMALS+1));
		
		activityInputTestGnuplotFile->setOutput("highTimeFrequencyInputTest");
		activityInputTestGnuplotFile->setTitle("high TimeFrequency InputTest");
		activityInputTestGnuplotFile->plotTitleIndexedLines("highTimeFrequencyInputTestStats",0,4*(NB_TESTED_ANIMALS+1));
		
		activityInputTestGnuplotFile->setOutput("diffHighTimeFrequencyInputTest");
		activityInputTestGnuplotFile->setTitle("diff High TimeFrequency InputTest");
		activityInputTestGnuplotFile->plotTitleIndexedLines("diffHighTimeFrequencyInputTestStats",0,2+(NB_TESTED_ANIMALS+1));
					#ifdef _GLOBAL_SYNAPSE_STAT_MODE
		activityInputTestGnuplotFile->setOutput("inhibTempDevRepartitionInputTestStats");
		activityInputTestGnuplotFile->setTitle("Inhib tempDev Repartition InputTest Stats");
		activityInputTestGnuplotFile->plotTitleIndexedLines("inhibTempDevRepartitionInputTestStats",0,4*(NB_TESTED_ANIMALS+1));	
		
		activityInputTestGnuplotFile->setOutput("excitTempDevRepartitionInputTestStats");
		activityInputTestGnuplotFile->setTitle("Excit tempDev Repartition InputTest Stats");
		activityInputTestGnuplotFile->plotTitleIndexedLines("excitTempDevRepartitionInputTestStats",0,4*(NB_TESTED_ANIMALS+1));	
		
		activityInputTestGnuplotFile->setOutput("diffExcitTempDevRepartitionInputTestStats");
		activityInputTestGnuplotFile->setTitle("diff Excit TempDev Repartition InputTest Stats");
		activityInputTestGnuplotFile->plotTitleIndexedLines("diffExcitTempDevRepartitionInputTestStats",0,2+(NB_TESTED_ANIMALS+1));
		
		activityInputTestGnuplotFile->setOutput("diffInhibTempDevRepartitionInputTestStats");
		activityInputTestGnuplotFile->setTitle("diff Inhib TempDev Repartition InputTest Stats");
		activityInputTestGnuplotFile->plotTitleIndexedLines("diffInhibTempDevRepartitionInputTestStats",0,2+(NB_TESTED_ANIMALS+1));	
					#endif
					
		activityInputTestGnuplotFile->setOutput("ISIRepartitionInputTestStats");
		activityInputTestGnuplotFile->setTitle("ISI Repartition InputTest Stats");
		activityInputTestGnuplotFile->plotTitleIndexedLines("ISIRepartitionInputTestStats",0,4*(NB_TESTED_ANIMALS+1));
		
		activityInputTestGnuplotFile->setOutput("diffISIRepartitionInputTestStats");
		activityInputTestGnuplotFile->setTitle("diff ISI Repartition InputTest Stats");
		activityInputTestGnuplotFile->plotTitleIndexedLines("diffISIRepartitionInputTestStats",0,2+(NB_TESTED_ANIMALS+1));
		
					#ifdef _SORT_ASSEMBLY_STAT_MODE
		activityInputTestGnuplotFile->setOutput("SortedSpikeRepartitionInputTestStats");
		activityInputTestGnuplotFile->setTitle("Sorted Spike Repartition InputTest Stats");
		activityInputTestGnuplotFile->plotTitleSorted3IndexedLines("SpikeRepartitionInputTestStats",0,4*(NB_TESTED_ANIMALS+1));
		
		activityInputTestGnuplotFile->setOutput("diffSortedSpikeRepartitionInputTestStats");
		activityInputTestGnuplotFile->setTitle("diff Sorted Spike Repartition InputTest Stats");
		activityInputTestGnuplotFile->plotTitleSorted3IndexedLines("diffSpikeRepartitionInputTestStats",0,2+(NB_TESTED_ANIMALS+1));
		
		activityInputTestGnuplotFile->setOutput("SortedAssemblySpikeRepartitionInputTestStats");
		activityInputTestGnuplotFile->setTitle("Sorted AssemblySpike Repartition InputTest Stats");
		activityInputTestGnuplotFile->plotTitleSorted3IndexedLines("AssemblySpikeRepartitionInputTestStats",0,4*(NB_TESTED_ANIMALS+1));
		
		activityInputTestGnuplotFile->setOutput("diffSortedAssemblySpikeRepartitionInputTestStats");
		activityInputTestGnuplotFile->setTitle("diff Sorted AssemblySpike Repartition InputTest Stats");
		activityInputTestGnuplotFile->plotTitleSorted3IndexedLines("diffAssemblySpikeRepartitionInputTestStats",0,2+(NB_TESTED_ANIMALS+1));
		
					#else
		activityInputTestGnuplotFile->setOutput("SpikeRepartitionInputTestStats");
		activityInputTestGnuplotFile->setTitle("Spike Repartition InputTest Stats");
		activityInputTestGnuplotFile->plotTitleIndexedLines("SpikeRepartitionInputTestStats",0,4*(NB_TESTED_ANIMALS+1));
	
		activityInputTestGnuplotFile->setOutput("diffSpikeRepartitionInputTestStats");
		activityInputTestGnuplotFile->setTitle("diff Spike Repartition InputTest Stats");
		activityInputTestGnuplotFile->plotTitleIndexedLines("diffSpikeRepartitionInputTestStats",0,2+(NB_TESTED_ANIMALS+1));
		
		activityInputTestGnuplotFile->setOutput("AssemblySpikeRepartitionInputTestStats");
		activityInputTestGnuplotFile->setTitle("AssemblySpike Repartition InputTest Stats");
		activityInputTestGnuplotFile->plotTitleIndexedLines("AssemblySpikeRepartitionInputTestStats",0,4*(NB_TESTED_ANIMALS+1));
		
		activityInputTestGnuplotFile->setOutput("diffAssemblySpikeRepartitionInputTestStats");
		activityInputTestGnuplotFile->setTitle("diff AssemblySpike Repartition InputTest Stats");
		activityInputTestGnuplotFile->plotTitleIndexedLines("diffAssemblySpikeRepartitionInputTestStats",0,2+(NB_TESTED_ANIMALS+1));
					#endif
				#else
		activityInputTestGnuplotFile->setOutput("timeFrequencyInputTest");
		activityInputTestGnuplotFile->setTitle("timeFrequency InputTest");
		activityInputTestGnuplotFile->plotTitleIndexedLines("timeFrequencyInputTestStats",0,2*(NB_TESTED_ANIMALS+1));
		
		activityInputTestGnuplotFile->setOutput("diffTimeFrequencyInputTest");
		activityInputTestGnuplotFile->setTitle("diff TimeFrequency InputTest");
		activityInputTestGnuplotFile->plotTitleIndexedLines("diffTimeFrequencyInputTestStats",0,1+(NB_TESTED_ANIMALS+1));
		
		activityInputTestGnuplotFile->setOutput("highTimeFrequencyInputTest");
		activityInputTestGnuplotFile->setTitle("high TimeFrequency InputTest");
		activityInputTestGnuplotFile->plotTitleIndexedLines("highTimeFrequencyInputTestStats",0,2*(NB_TESTED_ANIMALS+1));
		
		activityInputTestGnuplotFile->setOutput("diffHighTimeFrequencyInputTest");
		activityInputTestGnuplotFile->setTitle("diff High TimeFrequency InputTest");
		activityInputTestGnuplotFile->plotTitleIndexedLines("diffHighTimeFrequencyInputTestStats",0,1+(NB_TESTED_ANIMALS+1));
					#ifdef _GLOBAL_SYNAPSE_STAT_MODE
		activityInputTestGnuplotFile->setOutput("inhibTempDevRepartitionInputTestStats");
		activityInputTestGnuplotFile->setTitle("Inhib tempDev Repartition InputTest Stats");
		activityInputTestGnuplotFile->plotTitleIndexedLines("inhibTempDevRepartitionInputTestStats",0,2*(NB_TESTED_ANIMALS+1));	
		
		activityInputTestGnuplotFile->setOutput("excitTempDevRepartitionInputTestStats");
		activityInputTestGnuplotFile->setTitle("Excit tempDev Repartition InputTest Stats");
		activityInputTestGnuplotFile->plotTitleIndexedLines("excitTempDevRepartitionInputTestStats",0,2*(NB_TESTED_ANIMALS+1));	
		
		activityInputTestGnuplotFile->setOutput("diffExcitTempDevRepartitionInputTestStats");
		activityInputTestGnuplotFile->setTitle("diff Excit TempDev Repartition InputTest Stats");
		activityInputTestGnuplotFile->plotTitleIndexedLines("diffExcitTempDevRepartitionInputTestStats",0,1+(NB_TESTED_ANIMALS+1));
		
		activityInputTestGnuplotFile->setOutput("diffInhibTempDevRepartitionInputTestStats");
		activityInputTestGnuplotFile->setTitle("diff Inhib TempDev Repartition InputTest Stats");
		activityInputTestGnuplotFile->plotTitleIndexedLines("diffInhibTempDevRepartitionInputTestStats",0,1+(NB_TESTED_ANIMALS+1));	
					#endif
					
		activityInputTestGnuplotFile->setOutput("ISIRepartitionInputTestStats");
		activityInputTestGnuplotFile->setTitle("ISI Repartition InputTest Stats");
		activityInputTestGnuplotFile->plotTitleIndexedLines("ISIRepartitionInputTestStats",0,2*(NB_TESTED_ANIMALS+1));
		
		activityInputTestGnuplotFile->setOutput("diffISIRepartitionInputTestStats");
		activityInputTestGnuplotFile->setTitle("diff ISI Repartition InputTest Stats");
		activityInputTestGnuplotFile->plotTitleIndexedLines("diffISIRepartitionInputTestStats",0,1+(NB_TESTED_ANIMALS+1));
		
					#ifdef _SORT_ASSEMBLY_STAT_MODE
		activityInputTestGnuplotFile->setOutput("SortedSpikeRepartitionInputTestStats");
		activityInputTestGnuplotFile->setTitle("Sorted Spike Repartition InputTest Stats");
		activityInputTestGnuplotFile->plotTitleSorted3IndexedLines("SpikeRepartitionInputTestStats",0,2*(NB_TESTED_ANIMALS+1));
		
		activityInputTestGnuplotFile->setOutput("diffSortedSpikeRepartitionInputTestStats");
		activityInputTestGnuplotFile->setTitle("diff Sorted Spike Repartition InputTest Stats");
		activityInputTestGnuplotFile->plotTitleSorted3IndexedLines("diffSpikeRepartitionInputTestStats",0,1+(NB_TESTED_ANIMALS+1));
		
		activityInputTestGnuplotFile->setOutput("SortedAssemblySpikeRepartitionInputTestStats");
		activityInputTestGnuplotFile->setTitle("Sorted AssemblySpike Repartition InputTest Stats");
		activityInputTestGnuplotFile->plotTitleSorted3IndexedLines("AssemblySpikeRepartitionInputTestStats",0,2*(NB_TESTED_ANIMALS+1));
		
		activityInputTestGnuplotFile->setOutput("diffSortedAssemblySpikeRepartitionInputTestStats");
		activityInputTestGnuplotFile->setTitle("diff Sorted AssemblySpike Repartition InputTest Stats");
		activityInputTestGnuplotFile->plotTitleSorted3IndexedLines("diffAssemblySpikeRepartitionInputTestStats",0,1+(NB_TESTED_ANIMALS+1));
		
					#else
		activityInputTestGnuplotFile->setOutput("SpikeRepartitionInputTestStats");
		activityInputTestGnuplotFile->setTitle("Spike Repartition InputTest Stats");
		activityInputTestGnuplotFile->plotTitleIndexedLines("SpikeRepartitionInputTestStats",0,2*(NB_TESTED_ANIMALS+1));
	
		activityInputTestGnuplotFile->setOutput("diffSpikeRepartitionInputTestStats");
		activityInputTestGnuplotFile->setTitle("diff Spike Repartition InputTest Stats");
		activityInputTestGnuplotFile->plotTitleIndexedLines("diffSpikeRepartitionInputTestStats",0,1+(NB_TESTED_ANIMALS+1));
		
		activityInputTestGnuplotFile->setOutput("AssemblySpikeRepartitionInputTestStats");
		activityInputTestGnuplotFile->setTitle("AssemblySpike Repartition InputTest Stats");
		activityInputTestGnuplotFile->plotTitleIndexedLines("AssemblySpikeRepartitionInputTestStats",0,2*(NB_TESTED_ANIMALS+1));
		
		activityInputTestGnuplotFile->setOutput("diffAssemblySpikeRepartitionInputTestStats");
		activityInputTestGnuplotFile->setTitle("diff AssemblySpike Repartition InputTest Stats");
		activityInputTestGnuplotFile->plotTitleIndexedLines("diffAssemblySpikeRepartitionInputTestStats",0,1+(NB_TESTED_ANIMALS+1));
					#endif
				#endif
			#else
		
		activityInputTestGnuplotFile->setOutput("MeanHigh-Time-Frequency");
		activityInputTestGnuplotFile->setTitle("Mean High-Time-Frequency");
		activityInputTestGnuplotFile->plot3DIndexedLines("Mean_highTimeFrequencyStats");

		activityInputTestGnuplotFile->setOutput("Temporal_MeanHigh-Time-Frequency");
		activityInputTestGnuplotFile->setTitle("Temporal Mean High Time-Frequency");
		activityInputTestGnuplotFile->plotLine("Temporal_Mean_highTimeFrequencyStats");
		
		activityInputTestGnuplotFile->setOutput("MeanTime-Frequency");
		activityInputTestGnuplotFile->setTitle("Mean Time-Frequency");
		activityInputTestGnuplotFile->plot3DIndexedLines("Mean_timeFrequencyStats");
		
		activityInputTestGnuplotFile->setOutput("Temporal_MeanTime-Frequency");
		activityInputTestGnuplotFile->setTitle("Temporal Mean Time-Frequency");
		activityInputTestGnuplotFile->plotLine("Temporal_Mean_timeFrequencyStats");
		
		activityInputTestGnuplotFile->setOutput("Mean_ISI");
		activityInputTestGnuplotFile->setTitle("Mean ISI");
		activityInputTestGnuplotFile->plot3DIndexedLines("Mean_ISIStats");
		
		activityInputTestGnuplotFile->setOutput("Temporal_Mean_ISI");
		activityInputTestGnuplotFile->setTitle("Temporal Mean ISI");
		activityInputTestGnuplotFile->plotLine("Temporal_Mean_ISIStats");
		
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
		activityInputTestGnuplotFile->setOutput("Mean_ExcitTempDev");
		activityInputTestGnuplotFile->setTitle("Mean Excit Temp Dev");
		activityInputTestGnuplotFile->plot3DIndexedLines("Mean_excitTempDevRepartitionStats");
		
		activityInputTestGnuplotFile->setOutput("Temporal_Mean_ExcitTempDev");
		activityInputTestGnuplotFile->setTitle("Temporal Mean Excit Temp Dev");
		activityInputTestGnuplotFile->plotLine("Temporal_Mean_excitTempDevRepartitionStats");
		
		activityInputTestGnuplotFile->setOutput("Mean_InhibTempDev");
		activityInputTestGnuplotFile->setTitle("Mean Inhib Temp Dev");
		activityInputTestGnuplotFile->plot3DIndexedLines("Mean_inhibTempDevRepartitionStats");
		
		activityInputTestGnuplotFile->setOutput("Temporal_Mean_InhibTempDev");
		activityInputTestGnuplotFile->setTitle("Temporal Mean Inhib Temp Dev");
		activityInputTestGnuplotFile->plotLine("Temporal_Mean_inhibTempDevRepartitionStats");
				#endif
				
		activityInputTestGnuplotFile->setOutput("Mean_SpikeCount");
		activityInputTestGnuplotFile->setTitle("Mean Spike Count");
		activityInputTestGnuplotFile->plot3DIndexedLines("Mean_spikeCountStats");
		
		activityInputTestGnuplotFile->setOutput("Temporal_Mean_SpikeCount");
		activityInputTestGnuplotFile->setTitle("Temporal Mean Spike Count");
		activityInputTestGnuplotFile->plotLine("Temporal_Mean_spikeCountStats");
			#endif
		#endif	
	}
	else
	{
		cerr << "Warning, activityInputTestGnuplotFile should be open" << endl;
	}
}
	#endif
#endif


// InhibSynapseStater.cc

// Local Includes
#include "InhibSynapseStater.h"

/****************************************************************************************************************************************/
/************************************************* Methodes de la classe InhibSynapseStater ************************************************/
/****************************************************************************************************************************************/

InhibSynapseStater::InhibSynapseStater()
{

#ifdef _ASSEMBLY_STAT_MODE
	#ifdef _GLOBAL_SYNAPSE_STAT_MODE
		#ifndef _MULTI_TEST_MODE
		// Potentiation
	// Accus
	inhibPotPSPWeights = new Accumulater();
	inhibPotWeightVariation = new Accumulater();
	inhibPotRealWeightVariation = new Accumulater();
			#ifndef _PHASE_TEST_MODE
	// Fichiers traces
	inhibPotMeanPSPWeightsFile = new DataFile();
	inhibPotMeanWeightVariationFile = new DataFile();
	inhibPotRealWeightVariationFile = new DataFile();
			#endif
		// Depression
	// Accus
	inhibDepPSPWeights = new Accumulater();
	inhibDepWeightVariation = new Accumulater();
	inhibDepRealWeightVariation = new Accumulater();
	
			#ifndef _PHASE_TEST_MODE
	// Fichiers traces
	inhibDepMeanPSPWeightsFile = new DataFile();
	inhibDepMeanWeightVariationFile = new DataFile();
	inhibDepRealWeightVariationFile = new DataFile();
			#endif
		// Variation temporelle

	inhibPreTemporalDeviation = new Accumulater();
	inhibPostTemporalDeviation = new Accumulater();
		
			#ifndef _PHASE_TEST_MODE
	inhibPreTemporalDeviationFile = new DataFile();
	inhibPostTemporalDeviationFile = new DataFile();
	
			#endif
		#endif
	
		#ifndef _MULTI_TEST_MODE	
			#ifndef _PHASE_TEST_MODE
	inhibTempDevRepartitionFile = new DataFile();
//#ifdef _SINGLE_ASSEMBLY_STAT_MODE
	// Fichiers graphs
	inhibGnuplotSynapseFile = new GnuplotFile();
//#endif
	openStater();
			#endif
		#endif
	#endif
#endif
}

InhibSynapseStater::InhibSynapseStater(IndexedObject* io): Stater(io)
{

#ifdef _ASSEMBLY_STAT_MODE
	#ifdef _GLOBAL_SYNAPSE_STAT_MODE
		#ifndef _MULTI_TEST_MODE
		// Potentiation
	// Accus
	inhibPotPSPWeights = new Accumulater();
	inhibPotWeightVariation = new Accumulater();
	inhibPotRealWeightVariation = new Accumulater();
	
			#ifndef _PHASE_TEST_MODE
	// Fichiers traces
	inhibPotMeanPSPWeightsFile = new DataFile();
	inhibPotMeanWeightVariationFile = new DataFile();
	inhibPotRealWeightVariationFile = new DataFile();
			#endif
		// Depression
	// Accus
	inhibDepPSPWeights = new Accumulater();
	inhibDepWeightVariation = new Accumulater();
	inhibDepRealWeightVariation = new Accumulater();
	
			#ifndef _PHASE_TEST_MODE
	// Fichiers traces
	inhibDepMeanPSPWeightsFile = new DataFile();
	inhibDepMeanWeightVariationFile = new DataFile();
	inhibDepRealWeightVariationFile = new DataFile();
			#endif
		// Variation temporelle

	inhibPreTemporalDeviation = new Accumulater();
	inhibPostTemporalDeviation = new Accumulater();
	
			#ifndef _PHASE_TEST_MODE
	inhibPreTemporalDeviationFile = new DataFile();
	inhibPostTemporalDeviationFile = new DataFile();

			#endif
		#endif
	
		#ifndef _MULTI_TEST_MODE	
			#ifndef _PHASE_TEST_MODE
	inhibTempDevRepartitionFile = new DataFile();
	
	// Fichiers graphs
	inhibGnuplotSynapseFile = new GnuplotFile();
//#endif

	openStater();
			#endif
		#endif
	#endif
	
#endif
}

InhibSynapseStater::~InhibSynapseStater()
{
	cerr << "In ~InhibSynapseStater" << endl;
	
#ifdef _ASSEMBLY_STAT_MODE
	#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	
		#ifndef _MULTI_TEST_MODE
			#ifndef _PHASE_TEST_MODE
	closeStater();		
	
	
	delete(inhibTempDevRepartitionFile);
	
//#ifdef _SINGLE_ASSEMBLY_STAT_MODE
	// fichier graphs
	delete(inhibGnuplotSynapseFile);
//#endif	
			#endif	
		#endif
	
		#ifndef _MULTI_TEST_MODE
		// Potentiation
	// Accus
	delete(inhibPotPSPWeights);
	delete(inhibPotWeightVariation);
	delete(inhibPotRealWeightVariation);
	
			#ifndef _PHASE_TEST_MODE
	// Fichiers traces
	delete(inhibPotMeanPSPWeightsFile);
	delete(inhibPotMeanWeightVariationFile);
	delete(inhibPotRealWeightVariationFile);
			#endif

		// Depression
	// Accus
	delete(inhibDepPSPWeights);
	delete(inhibDepWeightVariation);
	delete(inhibDepRealWeightVariation);

			#ifndef _PHASE_TEST_MODE
	// Fichiers traces
	delete(inhibDepMeanPSPWeightsFile);
	delete(inhibDepMeanWeightVariationFile);
	delete(inhibDepRealWeightVariationFile);
			#endif

		// Variation temporelles

	delete(inhibPreTemporalDeviation);
	delete(inhibPostTemporalDeviation);
	
			#ifndef _PHASE_TEST_MODE
	delete(inhibPreTemporalDeviationFile);
	delete(inhibPostTemporalDeviationFile);

			#endif
		#endif
	#endif
#endif
	cerr << "After Freeing InhibSynapseStater" << endl;	
}

#ifdef _ASSEMBLY_STAT_MODE
	#ifdef _GLOBAL_SYNAPSE_STAT_MODE
		#ifndef _MULTI_TEST_MODE
			#ifndef _PHASE_TEST_MODE
void InhibSynapseStater::openGrapher()
{
				#ifdef _GLOBAL_STAT_MODE
	if (inhibGnuplotSynapseFile)
	{
	
		inhibGnuplotSynapseFile->openGnuplotFile("InhibSynapseStat");
	}
	else
	{
		cerr << "Warning, inhibGnuplotSynapseFile is not inited" << endl;
	}
				#endif
}

void InhibSynapseStater::runGrapher()
{
	if (inhibGnuplotSynapseFile)
	{
		inhibGnuplotSynapseFile->systemFile();
	}
	else
	{
		cerr << "Warning, inhibGnuplotSynapseFile is not inited" << endl;
	}
}

void InhibSynapseStater::closeGrapher()
{
	if (inhibGnuplotSynapseFile->isOpen())
	{
		inhibGnuplotSynapseFile->closeFile();
	}
	else
	{
		cerr << "Warning, inhibGnuplotSynapseFile is not inited" << endl;
	}
}

void InhibSynapseStater::openTracer()
{
				#ifdef _GLOBAL_STAT_MODE
					#ifndef _MULTI_TEST_MODE
	// Potentiation
	if (inhibPotMeanPSPWeightsFile)
	{
		ostringstream oss;
		oss << "inhibPotMeanPSPWeightsStats" << (Handler*) this;
		inhibPotMeanPSPWeightsFile->openDataFile(oss.str());
	}

	if (inhibPotMeanWeightVariationFile)
	{
		ostringstream oss;
		oss << "inhibPotMeanWeightVariationStats" << (Handler*) this;
		inhibPotMeanWeightVariationFile->openDataFile(oss.str());
	}

	if (inhibPotRealWeightVariationFile)
	{
		ostringstream oss;
		oss << "inhibPotRealWeightVariationStats" << (Handler*) this;
		inhibPotRealWeightVariationFile->openDataFile(oss.str());
	}

		// Depression
	if (inhibDepMeanPSPWeightsFile)
	{
		ostringstream oss;
		oss << "inhibDepMeanPSPWeightsStats" << (Handler*) this;
		inhibDepMeanPSPWeightsFile->openDataFile(oss.str());
	}

	if (inhibDepMeanWeightVariationFile)
	{
		ostringstream oss;
		oss << "inhibDepMeanWeightVariationStats" << (Handler*) this;
		inhibDepMeanWeightVariationFile->openDataFile(oss.str());
	}

	if (inhibDepRealWeightVariationFile)
	{
		ostringstream oss;
		oss << "inhibDepRealWeightVariationStats" << (Handler*) this;
		inhibDepRealWeightVariationFile->openDataFile(oss.str());
	}

		// Variation temporelles
	if (inhibPreTemporalDeviationFile)
	{
		ostringstream oss;
		oss << "inhibPreTemporalDeviationStats" << (Handler*) this;
		inhibPreTemporalDeviationFile->openDataFile(oss.str());
	}

	if (inhibPostTemporalDeviationFile)
	{
		ostringstream oss;
		oss << "inhibPostTemporalDeviationStats" << (Handler*) this;
		inhibPostTemporalDeviationFile->openDataFile(oss.str());
	}
					#endif
	if (inhibTempDevRepartitionFile)
	{
		ostringstream oss;
		oss << "inhibTempDevRepartitionStats" << (Handler*) this;
		inhibTempDevRepartitionFile->openDataFile(oss.str());
	}
				#endif
}

void InhibSynapseStater::closeTracer()
{
				#ifdef _GLOBAL_STAT_MODE
					#ifndef _MULTI_TEST_MODE
	// Potentiation
	if (inhibPotMeanPSPWeightsFile)
	{
		inhibPotMeanPSPWeightsFile->closeFile();
	}

	if (inhibPotMeanWeightVariationFile)
	{
		inhibPotMeanWeightVariationFile->closeFile();
	}

	if (inhibPotRealWeightVariationFile)
	{
		inhibPotRealWeightVariationFile->closeFile();
	}

	// Depression

	if (inhibDepMeanPSPWeightsFile)
	{
		inhibDepMeanPSPWeightsFile->closeFile();
	}

	if (inhibDepMeanWeightVariationFile)
	{
		inhibDepMeanWeightVariationFile->closeFile();
	}

	if (inhibDepRealWeightVariationFile)
	{
		inhibDepRealWeightVariationFile->closeFile();
	}

	// Variation temporelle
	if (inhibPreTemporalDeviationFile)
	{
		inhibPreTemporalDeviationFile->closeFile();
	}

	if (inhibPostTemporalDeviationFile)
	{
		inhibPostTemporalDeviationFile->closeFile();
	}
					#endif
	if (inhibTempDevRepartitionFile)
	{
		inhibTempDevRepartitionFile->closeFile();
		inhibTempDevRepartitionFile->formatFile();
	}
				#endif
}
			#endif
		#endif

/****************************************************************************************************************************************/
/******************************************************* Methodes de stats **************************************************************/
/****************************************************************************************************************************************/

int InhibSynapseStater::getInhibPreTempDevRepartition(int index)
{
	if (0<=index && index<100)
	{
		return inhibPreTempDevRepartition[index].getCounter();
	}
}

int InhibSynapseStater::getInhibPostTempDevRepartition(int index)
{
	if (0<=index && index<100)
	{
		return inhibPostTempDevRepartition[index].getCounter();
	}
}

bool InhibSynapseStater::isVoidInhibPreTempDevRepartition(int index)
{
	if (0<=index && index<100)
	{
		return inhibPreTempDevRepartition[index].isVoid();
	}
}

bool InhibSynapseStater::isVoidInhibPostTempDevRepartition(int index)
{
	if (0<=index && index<100)
	{
		return inhibPostTempDevRepartition[index].isVoid();
	}
}

void InhibSynapseStater::freeVoidInhibPreTempDevRepartition(int index)
{
	if (0<=index && index<100)
	{
		inhibPreTempDevRepartition[index].freeVoid();
	}
}

void InhibSynapseStater::freeVoidInhibPostTempDevRepartition(int index)
{
	if (0<=index && index<100)
	{
		inhibPostTempDevRepartition[index].freeVoid();
	}
}

void InhibSynapseStater::statPreTemporalVariation(int tempVariation)
{
		#ifndef _MULTI_TEST_MODE
	if (inhibPreTemporalDeviation)
	{
		inhibPreTemporalDeviation->accumulate(fabs((double) tempVariation));
	}
		#endif
	
	if (tempVariation<=0)
	{
		if (abs(tempVariation) < 99)
		{
			inhibPreTempDevRepartition[(int) abs(tempVariation)].count();
		}
		else
		{
			inhibPreTempDevRepartition[99].count();
		}
	}
	else
	{
		cerr << "Warning, inhibPreTemporalDeviation should be negative for pre update" << endl;
	}
}

void InhibSynapseStater::statPostTemporalVariation(int tempVariation)
{
		#ifndef _MULTI_TEST_MODE
	if (inhibPostTemporalDeviation)
	{
		inhibPostTemporalDeviation->accumulate(fabs((double) tempVariation));
	}
		#endif
	
	if (0<=tempVariation)
	{
		if (tempVariation < 100)
		{
			inhibPostTempDevRepartition[(int) tempVariation].count();
		}
		else
		{
			inhibPostTempDevRepartition[99].count();
		}
	}
	else
	{
		cerr << "Warning, inhibPostTemporalDeviation should be positive for post update" << endl;
	}
}
void InhibSynapseStater::statPotentiation(EDInhibSynapse* eds)
{
		#ifndef _MULTI_TEST_MODE
	if (inhibPotPSPWeights)
	{
		inhibPotPSPWeights->accumulate(fabs(eds->weight));
	}

	if (inhibPotWeightVariation)
	{
		inhibPotWeightVariation->accumulate(fabs(eds->deltaWeight));
	}

	if (inhibPotRealWeightVariation)
	{
		inhibPotRealWeightVariation->accumulate(fabs(eds->realDeltaWeight));
	}
		#endif
}

void InhibSynapseStater::statDepression(EDInhibSynapse* eds)
{
		#ifndef _MULTI_TEST_MODE
	if (inhibDepPSPWeights)
	{
		inhibDepPSPWeights->accumulate(fabs(eds->weight));
	}

	if (inhibDepWeightVariation)
	{
		inhibDepWeightVariation->accumulate(fabs(eds->deltaWeight));
	}

	if (inhibDepRealWeightVariation)
	{
		inhibDepRealWeightVariation->accumulate(fabs(eds->realDeltaWeight));
	}
		#endif
}
	
	
void InhibSynapseStater::trace(int timeOfTrace)
{
		#ifndef _MULTI_TEST_MODE
			#ifndef _PHASE_TEST_MODE
	// Potentiation
	if(inhibPotMeanPSPWeightsFile->isOpen())
	{
		if (inhibPotPSPWeights)
		{
			inhibPotMeanPSPWeightsFile->addLineData(timeOfTrace,inhibPotPSPWeights->getMean());
			inhibPotPSPWeights->initAccu();

		}
		else
		{
			cerr << "Warning, inhibPotPSPWeights should be inited" << endl;
		}

	}

	if(inhibPotMeanWeightVariationFile->isOpen())
	{
		if (inhibPotWeightVariation)
		{
			inhibPotMeanWeightVariationFile->addLineData(timeOfTrace,inhibPotWeightVariation->getMean());
			inhibPotWeightVariation->initAccu();
		}
		else
		{
			cerr << "Warning, inhibPotWeightVariation should be inited" << endl;
		}
	}

	if(inhibPotRealWeightVariationFile->isOpen())
	{
		if (inhibPotRealWeightVariation)
		{
			inhibPotRealWeightVariationFile->addLineData(timeOfTrace,inhibPotRealWeightVariation->getMean());
			inhibPotRealWeightVariation->initAccu();
		}
		else
		{
			cerr << "Warning, inhibPotTemporalDeviation should be inited" << endl;
		}
	}

	// Depression
	if(inhibDepMeanPSPWeightsFile->isOpen())
	{
		if (inhibDepPSPWeights)
		{
			inhibDepMeanPSPWeightsFile->addLineData(timeOfTrace,inhibDepPSPWeights->getMean());
			inhibDepPSPWeights->initAccu();

		}
		else
		{
			cerr << "Warning, inhibDepPSPWeights should be inited" << endl;
		}

	}

	if(inhibDepMeanWeightVariationFile->isOpen())
	{
		if (inhibDepWeightVariation)
		{
			inhibDepMeanWeightVariationFile->addLineData(timeOfTrace,inhibDepWeightVariation->getMean());
			inhibDepWeightVariation->initAccu();
		}
		else
		{
			cerr << "Warning, inhibDepWeightVariation should be inited" << endl;
		}
	}

	if(inhibDepRealWeightVariationFile->isOpen())
	{
		if (inhibDepRealWeightVariation)
		{
			inhibDepRealWeightVariationFile->addLineData(timeOfTrace,inhibDepRealWeightVariation->getMean());
			inhibDepRealWeightVariation->initAccu();
		}
		else
		{
			cerr << "Warning, inhibDepTemporalDeviation should be inited" << endl;
		}
	}

	// Variations temporelles
	if(inhibPreTemporalDeviationFile->isOpen())
	{
		if (inhibPreTemporalDeviation)
		{
			inhibPreTemporalDeviationFile->addLineData(timeOfTrace,inhibPreTemporalDeviation->getMean());
			inhibPreTemporalDeviation->initAccu();
		}
		else
		{
			cerr << "Warning, inhibPreTemporalDeviation should be inited" << endl;
		}
	}


	if(inhibPostTemporalDeviationFile->isOpen())
	{
		if (inhibPostTemporalDeviation)
		{
			inhibPostTemporalDeviationFile->addLineData(timeOfTrace,inhibPostTemporalDeviation->getMean());
			inhibPostTemporalDeviation->initAccu();
		}
		else
		{
			cerr << "Warning, inhibPostTemporalDeviation should be inited" << endl;
		}
	}
		
			#endif

		#endif
	
		#ifndef _MULTI_TEST_MODE
			#ifndef _PHASE_TEST_MODE		
	if(inhibTempDevRepartitionFile->isOpen())
	{
		for (int i=0;i<100;i++)
		{
			inhibTempDevRepartitionFile->addIndexedLineData(-i,timeOfTrace,inhibPreTempDevRepartition[i].getCounter());
			inhibPreTempDevRepartition[i].initCounter();
		}
		
		for (int i=0;i<100;i++)
		{
			inhibTempDevRepartitionFile->addIndexedLineData(i,timeOfTrace,inhibPostTempDevRepartition[i].getCounter());
			inhibPostTempDevRepartition[i].initCounter();
		}
	}
	else
	{
		cerr << "Warning, inhibPreTemporalDeviation should be inited" << endl;
	}
			#endif
		#endif
	
}

void InhibSynapseStater::traceVoid()
{	
		#ifndef _MULTI_TEST_MODE
	if (inhibPotPSPWeights)
	{
		inhibPotPSPWeights->setVoid();

	}
	else
	{
		cerr << "Warning, inhibPotPSPWeights should be inited" << endl;
	}

	if (inhibPotWeightVariation)
	{
		inhibPotWeightVariation->setVoid();
	}
	else
	{
		cerr << "Warning, inhibPotWeightVariation should be inited" << endl;
	}

	if (inhibPotRealWeightVariation)
	{
		inhibPotRealWeightVariation->setVoid();
	}
	else
	{
		cerr << "Warning, inhibPotTemporalDeviation should be inited" << endl;
	}
	
	if (inhibDepPSPWeights)
	{
		inhibDepPSPWeights->setVoid();

	}
	else
	{
		cerr << "Warning, inhibDepPSPWeights should be inited" << endl;
	}

	if (inhibDepWeightVariation)
	{
		inhibDepWeightVariation->setVoid();
	}
	else
	{
		cerr << "Warning, inhibDepWeightVariation should be inited" << endl;
	}
	if (inhibDepRealWeightVariation)
	{
		inhibDepRealWeightVariation->setVoid();
	}
	else
	{
		cerr << "Warning, inhibDepTemporalDeviation should be inited" << endl;
	}
	if (inhibPreTemporalDeviation)
	{
		inhibPreTemporalDeviation->setVoid();
	}
	else
	{
		cerr << "Warning, inhibPreTemporalDeviation should be inited" << endl;
	}
	if (inhibPostTemporalDeviation)
	{
		inhibPostTemporalDeviation->setVoid();
	}
	else
	{
		cerr << "Warning, inhibPostTemporalDeviation should be inited" << endl;
	}	
		#endif
	
	for (int i=0;i<100;i++)
	{
		inhibPreTempDevRepartition[i].setVoid();
	}
		
	for (int i=0;i<100;i++)
	{
		inhibPostTempDevRepartition[i].setVoid();
	}
}
		
void InhibSynapseStater::graph()
{

		#ifdef _GLOBAL_STAT_MODE
			#ifndef _MULTI_TEST_MODE
				#ifndef _PHASE_TEST_MODE
			
	//#ifdef _TEST_STAT
	cout << "*** AssemblyStater *** Graphing Inhib Synapses stats for all assemblies "<< endl;
	//#endif

	ostringstream oss;
	oss << (Handler*) this;

	if (inhibGnuplotSynapseFile->isOpen())
	{
		ostringstream oss;
		oss << (Handler*) this;

		// Variation de poids
		inhibGnuplotSynapseFile->setOutput("inhibMeanPSPWeightsStats"+oss.str());
		inhibGnuplotSynapseFile->setTitle("inhibMeanPSPWeightsStats"+oss.str());
		inhibGnuplotSynapseFile->plotFirstSingleLine("inhibPotMeanPSPWeightsStats"+oss.str());
		inhibGnuplotSynapseFile->plotSecondSingleLine("inhibDepMeanPSPWeightsStats"+oss.str());

		inhibGnuplotSynapseFile->setOutput("inhibRealWeightVariationStats"+oss.str());
		inhibGnuplotSynapseFile->setTitle("inhibRealWeightVariationStats"+oss.str());
		inhibGnuplotSynapseFile->plotFirstSingleLine("inhibPotRealWeightVariationStats"+oss.str());
		inhibGnuplotSynapseFile->plotSecondSingleLine("inhibDepRealWeightVariationStats"+oss.str());

		inhibGnuplotSynapseFile->setOutput("inhibMeanWeightVariationStats"+oss.str());
		inhibGnuplotSynapseFile->setTitle("inhibMeanWeightVariationStats"+oss.str());
		inhibGnuplotSynapseFile->plotFirstSingleLine("inhibPotMeanWeightVariationStats"+oss.str());
		inhibGnuplotSynapseFile->plotSecondSingleLine("inhibDepMeanWeightVariationStats"+oss.str());

		// Variations temporelles
		inhibGnuplotSynapseFile->setOutput("inhibTemporalDeviationStats"+oss.str());
		inhibGnuplotSynapseFile->setTitle("inhibTemporalDeviationStats"+oss.str());
		inhibGnuplotSynapseFile->plotFirstSingleLine("inhibPreTemporalDeviationStats"+oss.str());
		inhibGnuplotSynapseFile->plotSecondSingleLine("inhibPostTemporalDeviationStats"+oss.str());
		

		inhibGnuplotSynapseFile->setOutput("InhibTempDeviationRepartition"+oss.str());
		inhibGnuplotSynapseFile->setTitle("Inhib TempDeviation Repartition"+oss.str());
		inhibGnuplotSynapseFile->plot3DIndexedLines("inhibTempDevRepartitionStats"+oss.str());

	}
	else
	{
		cerr << "Warning, inhibGnuplotSynapseFile should be open" << endl;
	}
				#endif
			#endif
		#else
	/*
		#ifdef _ALL_ASSEMBLY_STAT_MODE
			#ifdef _SINGLE_PLOT_GRAPH_MODE
	ostringstream oss;
	oss << (Handler*) this;

	if (inhibGnuplotSynapseFile->isOpen())
	{
		cout << "In graph assemblies inhib synapse single plot assembly" << getIndex() << endl;

		ostringstream oss;
		oss << "_Generation" << getEvoIndex();
		oss << "_Pacman" << getTopoIndex();
		oss << "_Run" << getEvalIndex();
		oss << "_Test" << getTestIndex();
		oss << "_Assembly" << getIndex();

		// Variation de poids
		inhibGnuplotSynapseFile->setOutput("inhibMeanPSPWeightsStats"+oss.str());
		inhibGnuplotSynapseFile->setTitle("inhibMeanPSPWeightsStats"+oss.str());
		inhibGnuplotSynapseFile->plotFirstSingleLine("inhibPotMeanPSPWeightsStats"+ (string) getStringIndex());
		inhibGnuplotSynapseFile->plotSecondSingleLine("inhibDepMeanPSPWeightsStats"+ (string) getStringIndex());

		inhibGnuplotSynapseFile->setOutput("inhibRealWeightVariationStats"+oss.str());
		inhibGnuplotSynapseFile->setTitle("inhibRealWeightVariationStats"+oss.str());
		inhibGnuplotSynapseFile->plotFirstSingleLine("inhibPotRealWeightVariationStats"+ (string) getStringIndex());
		inhibGnuplotSynapseFile->plotSecondSingleLine("inhibDepRealWeightVariationStats"+ (string) getStringIndex());

		inhibGnuplotSynapseFile->setOutput("inhibMeanWeightVariationStats"+oss.str());
		inhibGnuplotSynapseFile->setTitle("inhibMeanWeightVariationStats"+oss.str());
		inhibGnuplotSynapseFile->plotFirstSingleLine("inhibPotMeanWeightVariationStats"+(string) getStringIndex());
		inhibGnuplotSynapseFile->plotSecondSingleLine("inhibDepMeanWeightVariationStats"+(string) getStringIndex());

		// Variations temporelles
		inhibGnuplotSynapseFile->setOutput("inhibTemporalDeviationStats"+oss.str());
		inhibGnuplotSynapseFile->setTitle("inhibTemporalDeviationStats"+oss.str());
		inhibGnuplotSynapseFile->plotFirstSingleLine("inhibPreTemporalDeviationStats"+(string) getStringIndex());
		inhibGnuplotSynapseFile->plotSecondSingleLine("inhibPostTemporalDeviationStats"+ (string) getStringIndex());

	}
			#endif
		#else
			#ifdef _SINGLE_ASSEMBLY_STAT_MODE
//#ifdef _TEST_STAT
	cout << "*** InhibSynapseStater *** Graphing InhibSynapseStater stats for assembly " << getStringIndex() << endl;
//#endif

	ostringstream oss;
	oss << (Handler*) this;
	oss << "_Assembly" << (string) getStringIndex();

	// Potentiation
	if (inhibGnuplotSynapseFile->isOpen())
	{
		inhibGnuplotSynapseFile->setOutput("inhibMeanPSPWeightsStats"+oss.str());
		inhibGnuplotSynapseFile->setTitle("inhibMeanPSPWeightsStats"+oss.str());
		inhibGnuplotSynapseFile->plotFirstSingleLine("inhibPotMeanPSPWeightsStats"+(string) getStringIndex());
		inhibGnuplotSynapseFile->plotSecondSingleLine("inhibDepMeanPSPWeightsStats"+(string) getStringIndex());

		inhibGnuplotSynapseFile->setOutput("inhibRealWeightVariationStats"+oss.str());
		inhibGnuplotSynapseFile->setTitle("inhibRealWeightVariationStats"+oss.str());
		inhibGnuplotSynapseFile->plotFirstSingleLine("inhibPotRealWeightVariationStats"+(string) getStringIndex());
		inhibGnuplotSynapseFile->plotSecondSingleLine("inhibDepRealWeightVariationStats"+(string) getStringIndex());

		inhibGnuplotSynapseFile->setOutput("inhibMeanWeightVariationStats"+oss.str());
		inhibGnuplotSynapseFile->setTitle("inhibMeanWeightVariationStats"+oss.str());
		inhibGnuplotSynapseFile->plotFirstSingleLine("inhibPotMeanWeightVariationStats"+(string) getStringIndex());
		inhibGnuplotSynapseFile->plotSecondSingleLine("inhibDepMeanWeightVariationStats"+(string) getStringIndex());

		// Variations temporelles
		inhibGnuplotSynapseFile->setOutput("inhibTemporalDeviationStats"+oss.str());
		inhibGnuplotSynapseFile->setTitle("inhibTemporalDeviationStats"+oss.str());
		inhibGnuplotSynapseFile->plotFirstSingleLine("inhibPreTemporalDeviationStats"+(string) getStringIndex());
		inhibGnuplotSynapseFile->plotSecondSingleLine("inhibPostTemporalDeviationStats"+(string) getStringIndex());
	}
	else
	{
		cerr << "Warning, inhibGnuplotSynapseFile should be open" << endl;
	}
			#endif
		#endif
	*/
		#endif
}
	
void InhibSynapseStater::initCounters()
{	
		#ifndef _MULTI_TEST_MODE
	if (inhibPotPSPWeights)
	{
		inhibPotPSPWeights->initAccu();

	}
	else
	{
		cerr << "Warning, inhibPotPSPWeights should be inited" << endl;
	}

	if (inhibPotWeightVariation)
	{
		inhibPotWeightVariation->initAccu();
	}
	else
	{
		cerr << "Warning, inhibPotWeightVariation should be inited" << endl;
	}

	if (inhibPotRealWeightVariation)
	{
		inhibPotRealWeightVariation->initAccu();
	}
	else
	{
		cerr << "Warning, inhibPotTemporalDeviation should be inited" << endl;
	}
	
	if (inhibDepPSPWeights)
	{
		inhibDepPSPWeights->initAccu();

	}
	else
	{
		cerr << "Warning, inhibDepPSPWeights should be inited" << endl;
	}

	if (inhibDepWeightVariation)
	{
		inhibDepWeightVariation->initAccu();
	}
	else
	{
		cerr << "Warning, inhibDepWeightVariation should be inited" << endl;
	}
	if (inhibDepRealWeightVariation)
	{
		inhibDepRealWeightVariation->initAccu();
	}
	else
	{
		cerr << "Warning, inhibDepTemporalDeviation should be inited" << endl;
	}
	if (inhibPreTemporalDeviation)
	{
		inhibPreTemporalDeviation->initAccu();
	}
	else
	{
		cerr << "Warning, inhibPreTemporalDeviation should be inited" << endl;
	}
	if (inhibPostTemporalDeviation)
	{
		inhibPostTemporalDeviation->initAccu();
	}
	else
	{
		cerr << "Warning, inhibPostTemporalDeviation should be inited" << endl;
	}
	
		#endif
	
	for (int i=0;i<100;i++)
	{
		inhibPreTempDevRepartition[i].initCounter();
	}
		
	for (int i=0;i<100;i++)
	{
		inhibPostTempDevRepartition[i].initCounter();
	}
}

void InhibSynapseStater::flushCounters()
{
		#ifndef _MULTI_TEST_MODE
	cout << "inhibPotPSPWeights: " << (Accumulater*) inhibPotPSPWeights << endl;
	cout << "inhibPotWeightVariation: " << (Accumulater*) inhibPotWeightVariation << endl;
	cout << "inhibPotRealWeightVariation: " << (Accumulater*) inhibPotRealWeightVariation << endl;

	cout << "inhibDepPSPWeights: " << (Accumulater*) inhibDepPSPWeights << endl;
	cout << "inhibDepWeightVariation: " << (Accumulater*) inhibDepWeightVariation << endl;
	cout << "inhibDepRealWeightVariation: " << (Accumulater*) inhibDepRealWeightVariation << endl;

	cout << "inhibPreTemporalDeviation: " << (Accumulater*) inhibPreTemporalDeviation << endl;
	cout << "inhibPostTemporalDeviation: " << (Accumulater*) inhibPostTemporalDeviation << endl;
		#endif
}
	#endif
#endif




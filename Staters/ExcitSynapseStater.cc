// ExcitSynapseStater.cc

// Local Includes
#include "ExcitSynapseStater.h"

/****************************************************************************************************************************************/
/************************************************* Methodes de la classe ExcitSynapseStater ************************************************/
/****************************************************************************************************************************************/

ExcitSynapseStater::ExcitSynapseStater()
{
#ifdef _ASSEMBLY_STAT_MODE
	#ifdef _GLOBAL_SYNAPSE_STAT_MODE
		#ifndef _MULTI_TEST_MODE
		// Potentiation
	// Accus
	excitPotPSPWeights = new Accumulater();
	excitPotWeightVariation = new Accumulater();
	excitPotRealWeightVariation = new Accumulater();
	
			#ifndef _PHASE_TEST_MODE
	// Fichiers traces
	excitPotMeanPSPWeightsFile = new DataFile();
	excitPotMeanWeightVariationFile = new DataFile();
	excitPotRealWeightVariationFile = new DataFile();
			#endif

		// Depression
	// Accus
	excitDepPSPWeights = new Accumulater();
	excitDepWeightVariation = new Accumulater();
	excitDepRealWeightVariation = new Accumulater();
	
			#ifndef _PHASE_TEST_MODE
	// Fichiers traces
	excitDepMeanPSPWeightsFile = new DataFile();
	excitDepMeanWeightVariationFile = new DataFile();
	excitDepRealWeightVariationFile = new DataFile();
			#endif

		// Variation temporelle

			#ifndef _PHASE_TEST_MODE
	excitPreTemporalDeviationFile = new DataFile();
	excitPostTemporalDeviationFile = new DataFile();
		// Delay
	
	preDelayRepartitionFile = new DataFile();
	postDelayRepartitionFile = new DataFile();
			#endif
		
	excitPreTemporalDeviation = new Accumulater();
	excitPostTemporalDeviation = new Accumulater();
		#endif
	
		#ifndef _MULTI_TEST_MODE
			#ifndef _PHASE_TEST_MODE
	excitTempDevRepartitionFile = new DataFile();
	
//#ifdef _SINGLE_ASSEMBLY_STAT_MODE
	// Fichiers graphs
	excitGnuplotSynapseFile = new GnuplotFile();
//#endif

	openStater();
			#endif
		#endif
	#endif
#endif
}

ExcitSynapseStater::ExcitSynapseStater(IndexedObject* io): Stater(io)
{
#ifdef _ASSEMBLY_STAT_MODE
	#ifdef _GLOBAL_SYNAPSE_STAT_MODE
		#ifndef _MULTI_TEST_MODE
		// Potentiation
	// Accus
	excitPotPSPWeights = new Accumulater();
	excitPotWeightVariation = new Accumulater();
	excitPotRealWeightVariation = new Accumulater();
	
			#ifndef _PHASE_TEST_MODE
	// Fichiers traces
	excitPotMeanPSPWeightsFile = new DataFile();
	excitPotMeanWeightVariationFile = new DataFile();
	excitPotRealWeightVariationFile = new DataFile();
			#endif

		// Depression
	// Accus
	excitDepPSPWeights = new Accumulater();
	excitDepWeightVariation = new Accumulater();
	excitDepRealWeightVariation = new Accumulater();
	
			#ifndef _PHASE_TEST_MODE
	// Fichiers traces
	excitDepMeanPSPWeightsFile = new DataFile();
	excitDepMeanWeightVariationFile = new DataFile();
	excitDepRealWeightVariationFile = new DataFile();
			#endif

		// Variation temporelle

			#ifndef _PHASE_TEST_MODE
	excitPreTemporalDeviationFile = new DataFile();
	excitPostTemporalDeviationFile = new DataFile();
		// Delay
	
	preDelayRepartitionFile = new DataFile();
	postDelayRepartitionFile = new DataFile();
			#endif
		
	excitPreTemporalDeviation = new Accumulater();
	excitPostTemporalDeviation = new Accumulater();
		#endif
	
		#ifndef _MULTI_TEST_MODE
			#ifndef _PHASE_TEST_MODE
	excitTempDevRepartitionFile = new DataFile();
	
//#ifdef _SINGLE_ASSEMBLY_STAT_MODE
	// Fichiers graphs
	excitGnuplotSynapseFile = new GnuplotFile();
//#endif

	openStater();
			#endif
		#endif
	#endif
#endif
}

ExcitSynapseStater::~ExcitSynapseStater()
{
	cerr << "In ~ExcitSynapseStater" << endl;
#ifdef _ASSEMBLY_STAT_MODE
	#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	
		#ifndef _MULTI_TEST_MODE
			#ifndef _PHASE_TEST_MODE		
	closeStater();
	
	delete(excitTempDevRepartitionFile);
	
	// fichier graphs
	delete(excitGnuplotSynapseFile);		
			#endif
		#endif
	
		#ifndef _MULTI_TEST_MODE
	
		// Potentiation
	// Accus
	delete(excitPotPSPWeights);
	delete(excitPotWeightVariation);
	delete(excitPotRealWeightVariation);

			#ifndef _PHASE_TEST_MODE
	// Fichiers traces
	delete(excitPotMeanPSPWeightsFile);
	delete(excitPotMeanWeightVariationFile);
	delete(excitPotRealWeightVariationFile);
			#endif

		// Depression
	// Accus
	delete(excitDepPSPWeights);
	delete(excitDepWeightVariation);
	delete(excitDepRealWeightVariation);
	
			#ifndef _PHASE_TEST_MODE
	// Fichiers traces
	delete(excitDepMeanPSPWeightsFile);
	delete(excitDepMeanWeightVariationFile);
	delete(excitDepRealWeightVariationFile);
			#endif

		// Variation temporelles

	delete(excitPreTemporalDeviation);
	delete(excitPostTemporalDeviation);
	
			#ifndef _PHASE_TEST_MODE
	delete(excitPreTemporalDeviationFile);
	delete(excitPostTemporalDeviationFile);

		// Delai
	delete(preDelayRepartitionFile);
	delete(postDelayRepartitionFile);

			#endif
		#endif
	#endif
#endif
	cerr << "After Freeing ExcitSynapseStater" << endl;
}

#ifdef _ASSEMBLY_STAT_MODE
	#ifdef _GLOBAL_SYNAPSE_STAT_MODE
		#ifndef _MULTI_TEST_MODE
			#ifndef _PHASE_TEST_MODE
void ExcitSynapseStater::openGrapher()
{
				#ifdef _GLOBAL_STAT_MODE
	if (excitGnuplotSynapseFile)
	{
		excitGnuplotSynapseFile->openGnuplotFile("ExcitSynapseStat");
	}
	else
	{
		cerr << "Warning, excitGnuplotSynapseFile is not inited" << endl;
	}
				#endif
}

void ExcitSynapseStater::runGrapher()
{
	if (excitGnuplotSynapseFile)
	{
		excitGnuplotSynapseFile->systemFile();
	}
	else
	{
		cerr << "Warning, excitGnuplotSynapseFile is not inited" << endl;
	}
}

void ExcitSynapseStater::closeGrapher()
{
	if (excitGnuplotSynapseFile->isOpen())
	{
		excitGnuplotSynapseFile->closeFile();
	}
	else
	{
		cerr << "Warning, excitGnuplotSynapseFile is not inited" << endl;
	}
}

void ExcitSynapseStater::openTracer()
{
		// Potentiation
				#ifdef _GLOBAL_STAT_MODE
					#ifndef _MULTI_TEST_MODE
	if (excitPotMeanPSPWeightsFile)
	{
		ostringstream oss;
		oss << "excitPotMeanPSPWeightsStats" << (Handler*) this;
		excitPotMeanPSPWeightsFile->openDataFile(oss.str());
	}

	if (excitPotMeanWeightVariationFile)
	{
		ostringstream oss;
		oss << "excitPotMeanWeightVariationStats" << (Handler*) this;
		excitPotMeanWeightVariationFile->openDataFile(oss.str());
	}

	if (excitPotRealWeightVariationFile)
	{
		ostringstream oss;
		oss << "excitPotRealWeightVariationStats" << (Handler*) this;
		excitPotRealWeightVariationFile->openDataFile(oss.str());
	}

		// Depression
	if (excitDepMeanPSPWeightsFile)
	{
		ostringstream oss;
		oss << "excitDepMeanPSPWeightsStats" << (Handler*) this;
		excitDepMeanPSPWeightsFile->openDataFile(oss.str());
	}

	if (excitDepMeanWeightVariationFile)
	{
		ostringstream oss;
		oss << "excitDepMeanWeightVariationStats" << (Handler*) this;
		excitDepMeanWeightVariationFile->openDataFile(oss.str());
	}

	if (excitDepRealWeightVariationFile)
	{
		ostringstream oss;
		oss << "excitDepRealWeightVariationStats" << (Handler*) this;
		excitDepRealWeightVariationFile->openDataFile(oss.str());
	}

		// Variation temporelles
	if (excitPreTemporalDeviationFile)
	{
		ostringstream oss;
		oss << "excitPreTemporalDeviationStats" << (Handler*) this;
		excitPreTemporalDeviationFile->openDataFile(oss.str());
	}

	if (excitPostTemporalDeviationFile)
	{
		ostringstream oss;
		oss << "excitPostTemporalDeviationStats" << (Handler*) this;
		excitPostTemporalDeviationFile->openDataFile(oss.str());
	}
	
	if (preDelayRepartitionFile)
	{
		ostringstream oss;
		oss << "preDelayRepartitionStats" << (Handler*) this;
		preDelayRepartitionFile->openDataFile(oss.str());
	}
	
	if (postDelayRepartitionFile)
	{
		ostringstream oss;
		oss << "postDelayRepartitionStats" << (Handler*) this;
		postDelayRepartitionFile->openDataFile(oss.str());
	}
					#endif
				
	if (excitTempDevRepartitionFile)
	{
		ostringstream oss;
		oss << "excitTempDevRepartitionStats" << (Handler*) this;
		excitTempDevRepartitionFile->openDataFile(oss.str());
	}
				#endif
}

void ExcitSynapseStater::closeTracer()
{
				#ifdef _GLOBAL_STAT_MODE
					#ifndef _MULTI_TEST_MODE
	// Potentiation
	if (excitPotMeanPSPWeightsFile)
	{
		excitPotMeanPSPWeightsFile->closeFile();
	}

	if (excitPotMeanWeightVariationFile)
	{
		excitPotMeanWeightVariationFile->closeFile();
	}

	if (excitPotRealWeightVariationFile)
	{
		excitPotRealWeightVariationFile->closeFile();
	}

	// Depression
	if (excitDepMeanPSPWeightsFile)
	{
		excitDepMeanPSPWeightsFile->closeFile();
	}

	if (excitDepMeanWeightVariationFile)
	{
		excitDepMeanWeightVariationFile->closeFile();
	}

	if (excitDepRealWeightVariationFile)
	{
		excitDepRealWeightVariationFile->closeFile();
	}

	// Variation temporelle
	if (excitPreTemporalDeviationFile)
	{
		excitPreTemporalDeviationFile->closeFile();
	}

	if (excitPostTemporalDeviationFile)
	{
		excitPostTemporalDeviationFile->closeFile();
	}
	
	if (preDelayRepartitionFile)
	{
		preDelayRepartitionFile->closeFile();
		preDelayRepartitionFile->formatFile();
	}
	
	
	if (postDelayRepartitionFile)
	{
		postDelayRepartitionFile->closeFile();
		postDelayRepartitionFile->formatFile();
	}
					#endif
				#endif
	if (excitTempDevRepartitionFile)
	{
		excitTempDevRepartitionFile->closeFile();
		excitTempDevRepartitionFile->formatFile();
	}
}
			#endif
		#endif

/****************************************************************************************************************************************/
/******************************************************* Methodes de stats **************************************************************/
/****************************************************************************************************************************************/

int ExcitSynapseStater::getExcitPreTempDevRepartition(int index)
{
	if (0<=index && index<100)
	{
		return excitPreTempDevRepartition[index].getCounter();
	}
}

int ExcitSynapseStater::getExcitPostTempDevRepartition(int index)
{
	if (0<=index && index<100)
	{
		return excitPostTempDevRepartition[index].getCounter();
	}
}

bool ExcitSynapseStater::isVoidExcitPreTempDevRepartition(int index)
{
	if (0<=index && index<100)
	{
		return excitPreTempDevRepartition[index].isVoid();
	}
}

bool ExcitSynapseStater::isVoidExcitPostTempDevRepartition(int index)
{
	if (0<=index && index<100)
	{
		return excitPostTempDevRepartition[index].isVoid();
	}
}

void ExcitSynapseStater::freeVoidExcitPreTempDevRepartition(int index)
{
	if (0<=index && index<100)
	{
		excitPreTempDevRepartition[index].freeVoid();
	}
}

void ExcitSynapseStater::freeVoidExcitPostTempDevRepartition(int index)
{
	if (0<=index && index<100)
	{
		excitPostTempDevRepartition[index].freeVoid();
	}
}

void ExcitSynapseStater::initCounters()
{	
		#ifndef _MULTI_TEST_MODE
	if (excitPotPSPWeights)
	{
		excitPotPSPWeights->initAccu();

	}
	else
	{
		cerr << "Warning, excitPotPSPWeights should be inited" << endl;
	}

	if (excitPotWeightVariation)
	{
		excitPotWeightVariation->initAccu();
	}
	else
	{
		cerr << "Warning, excitPotWeightVariation should be inited" << endl;
	}

	if (excitPotRealWeightVariation)
	{
		excitPotRealWeightVariation->initAccu();
	}
	else
	{
		cerr << "Warning, excitPotTemporalDeviation should be inited" << endl;
	}
	
	if (excitDepPSPWeights)
	{
		excitDepPSPWeights->initAccu();

	}
	else
	{
		cerr << "Warning, excitDepPSPWeights should be inited" << endl;
	}

	if (excitDepWeightVariation)
	{
		excitDepWeightVariation->initAccu();
	}
	else
	{
		cerr << "Warning, excitDepWeightVariation should be inited" << endl;
	}
	if (excitDepRealWeightVariation)
	{
		excitDepRealWeightVariation->initAccu();
	}
	else
	{
		cerr << "Warning, excitDepTemporalDeviation should be inited" << endl;
	}
	if (excitPreTemporalDeviation)
	{
		excitPreTemporalDeviation->initAccu();
	}
	else
	{
		cerr << "Warning, excitPreTemporalDeviation should be inited" << endl;
	}
	if (excitPostTemporalDeviation)
	{
		excitPostTemporalDeviation->initAccu();
	}
	else
	{
		cerr << "Warning, excitPostTemporalDeviation should be inited" << endl;
	}
	
	for (int i=0;i<DELAY;i++)
	{
		preDelayRepartition[i].initCounter();
	}
	
	for (int i=0;i<DELAY;i++)
	{
		postDelayRepartition[i].initCounter();
	}	
		#endif

	for (int i=0;i<100;i++)
	{
		excitPreTempDevRepartition[i].initCounter();
	}
		
	for (int i=0;i<100;i++)
	{
		excitPostTempDevRepartition[i].initCounter();
	}
}

void ExcitSynapseStater::flushCounters()
{
		#ifndef _MULTI_TEST_MODE
	cout << "excitPotPSPWeights: " << (Accumulater*) excitPotPSPWeights << endl;
	cout << "excitPotWeightVariation: " << (Accumulater*) excitPotWeightVariation << endl;
	cout << "excitPotRealWeightVariation: " << (Accumulater*) excitPotRealWeightVariation << endl;

	cout << "excitDepPSPWeights: " << (Accumulater*) excitDepPSPWeights << endl;
	cout << "excitDepWeightVariation: " << (Accumulater*) excitDepWeightVariation << endl;
	cout << "excitDepRealWeightVariation: " << (Accumulater*) excitDepRealWeightVariation << endl;

	cout << "excitPreTemporalDeviation: " << (Accumulater*) excitPreTemporalDeviation << endl;
	cout << "excitPostTemporalDeviation: " << (Accumulater*) excitPostTemporalDeviation << endl;
		#endif
}

void ExcitSynapseStater::statPreTemporalVariation(int tempVariation)
{
		#ifndef _MULTI_TEST_MODE
	if (excitPreTemporalDeviation)
	{
		excitPreTemporalDeviation->accumulate(fabs((double) tempVariation));
	}
		#endif
	
	if (tempVariation<=0)
	{
		if (abs(tempVariation) < 99)
		{
			excitPreTempDevRepartition[(int) abs(tempVariation)].count();
		}
		else
		{
			excitPreTempDevRepartition[99].count();
		}
	}
	else
	{
		cerr << "Warning, excitPreTemporalDeviation should be negative for pre update" << endl;
	}
}

void ExcitSynapseStater::statPostTemporalVariation(int tempVariation)
{
		#ifndef _MULTI_TEST_MODE
	if (excitPostTemporalDeviation)
	{
		excitPostTemporalDeviation->accumulate(fabs((double) tempVariation));
	}
		#endif
	
	if (0<=tempVariation)
	{
		if (tempVariation < 99)
		{
			excitPostTempDevRepartition[(int) tempVariation].count();
		}
		else
		{
			excitPostTempDevRepartition[99].count();
		}
	}
	else
	{
		cerr << "Warning, excitPostTemporalDeviation should be positive for post update" << endl;
	}
}
void ExcitSynapseStater::statPotentiation(EDExcitSynapse* eds)
{
		#ifndef _MULTI_TEST_MODE
	if (excitPotPSPWeights)
	{
		excitPotPSPWeights->accumulate(fabs(eds->weight));
	}

	if (excitPotWeightVariation)
	{
		excitPotWeightVariation->accumulate(fabs(eds->deltaWeight));
	}

	if (excitPotRealWeightVariation)
	{
		excitPotRealWeightVariation->accumulate(fabs(eds->realDeltaWeight));
	}
	
	if (0<eds->delay && eds->delay<=DELAY)
	{
		postDelayRepartition[eds->delay-1].count();
	}
		#endif
}

void ExcitSynapseStater::statDepression(EDExcitSynapse* eds)
{
		#ifndef _MULTI_TEST_MODE
	if (excitDepPSPWeights)
	{
		excitDepPSPWeights->accumulate(fabs(eds->weight));
	}

	if (excitDepWeightVariation)
	{
		excitDepWeightVariation->accumulate(fabs(eds->deltaWeight));
	}

	if (excitDepRealWeightVariation)
	{
		excitDepRealWeightVariation->accumulate(fabs(eds->realDeltaWeight));
	}
	
	if (0<eds->delay && eds->delay<=DELAY)
	{
		preDelayRepartition[eds->delay-1].count();
	}
		#endif
}
	
	
void ExcitSynapseStater::trace(int timeOfTrace)
{
		#ifndef _PHASE_TEST_MODE
			#ifndef _MULTI_TEST_MODE
	// Potentiation
	if(excitPotMeanPSPWeightsFile->isOpen())
	{
		if (excitPotPSPWeights)
		{
			excitPotMeanPSPWeightsFile->addLineData(timeOfTrace,excitPotPSPWeights->getMean());
			excitPotPSPWeights->initAccu();

		}
		else
		{
			cerr << "Warning, excitPotPSPWeights should be inited" << endl;
		}
	}

	if(excitPotMeanWeightVariationFile->isOpen())
	{
		if (excitPotWeightVariation)
		{
			excitPotMeanWeightVariationFile->addLineData(timeOfTrace,excitPotWeightVariation->getMean());
			excitPotWeightVariation->initAccu();
		}
		else
		{
			cerr << "Warning, excitPotWeightVariation should be inited" << endl;
		}
	}

	if(excitPotRealWeightVariationFile->isOpen())
	{
		if (excitPotRealWeightVariation)
		{
			excitPotRealWeightVariationFile->addLineData(timeOfTrace,excitPotRealWeightVariation->getMean());
			excitPotRealWeightVariation->initAccu();
		}
		else
		{
			cerr << "Warning, excitPotTemporalDeviation should be inited" << endl;
		}
	}

	// Depression
	if(excitDepMeanPSPWeightsFile->isOpen())
	{
		if (excitDepPSPWeights)
		{
			excitDepMeanPSPWeightsFile->addLineData(timeOfTrace,excitDepPSPWeights->getMean());
			excitDepPSPWeights->initAccu();

		}
		else
		{
			cerr << "Warning, excitDepPSPWeights should be inited" << endl;
		}
	}

	if(excitDepMeanWeightVariationFile->isOpen())
	{
		if (excitDepWeightVariation)
		{
			excitDepMeanWeightVariationFile->addLineData(timeOfTrace,excitDepWeightVariation->getMean());
			excitDepWeightVariation->initAccu();
		}
		else
		{
			cerr << "Warning, excitDepWeightVariation should be inited" << endl;
		}
	}

	if(excitDepRealWeightVariationFile->isOpen())
	{
		if (excitDepRealWeightVariation)
		{
			excitDepRealWeightVariationFile->addLineData(timeOfTrace,excitDepRealWeightVariation->getMean());
			excitDepRealWeightVariation->initAccu();
		}
		else
		{
			cerr << "Warning, excitDepTemporalDeviation should be inited" << endl;
		}
	}
	
	// Delay
	if(preDelayRepartitionFile->isOpen())
	{
		for (int i=0;i<DELAY;i++)
		{
			preDelayRepartitionFile->addIndexedLineData(i+1,timeOfTrace,preDelayRepartition[i].getCounter());
			preDelayRepartition[i].initCounter();
		}
	}
	else
	{
		cerr << "Warning, excitPreTemporalDeviation should be inited" << endl;
	}
	
	
	if(postDelayRepartitionFile->isOpen())
	{
		for (int i=0;i<DELAY;i++)
		{
			postDelayRepartitionFile->addIndexedLineData(i+1,timeOfTrace,postDelayRepartition[i].getCounter());
			postDelayRepartition[i].initCounter();
		}
	}
	else
	{
		cerr << "Warning, excitPreTemporalDeviation should be inited" << endl;
	}
	// Variations temporelles
	if(excitPreTemporalDeviationFile->isOpen())
	{
		if (excitPreTemporalDeviation)
		{
			excitPreTemporalDeviationFile->addLineData(timeOfTrace,excitPreTemporalDeviation->getMean());
			excitPreTemporalDeviation->initAccu();
		}
		else
		{
			cerr << "Warning, excitPreTemporalDeviation should be inited" << endl;
		}
	}

	if(excitPostTemporalDeviationFile->isOpen())
	{
		if (excitPostTemporalDeviation)
		{
			excitPostTemporalDeviationFile->addLineData(timeOfTrace,excitPostTemporalDeviation->getMean());
			excitPostTemporalDeviation->initAccu();
		}
		else
		{
			cerr << "Warning, excitPostTemporalDeviation should be inited" << endl;
		}
	}
	
			#endif
			#ifndef _MULTI_TEST_MODE
	if(excitTempDevRepartitionFile->isOpen())
	{
		for (int i=0;i<100;i++)
		{
			excitTempDevRepartitionFile->addIndexedLineData(-i,timeOfTrace,excitPreTempDevRepartition[i].getCounter());
			excitPreTempDevRepartition[i].initCounter();
		}
		
		for (int i=0;i<100;i++)
		{
			excitTempDevRepartitionFile->addIndexedLineData(i,timeOfTrace,excitPostTempDevRepartition[i].getCounter());
			excitPostTempDevRepartition[i].initCounter();
		}
	}
	else
	{
		cerr << "Warning, excitPreTemporalDeviation should be inited" << endl;
	}
			#endif
		#endif
}

void ExcitSynapseStater::traceVoid()
{	
		#ifndef _MULTI_TEST_MODE
	if (excitPotPSPWeights)
	{
		excitPotPSPWeights->setVoid();

	}
	else
	{
		cerr << "Warning, excitPotPSPWeights should be inited" << endl;
	}

	if (excitPotWeightVariation)
	{
		excitPotWeightVariation->setVoid();
	}
	else
	{
		cerr << "Warning, excitPotWeightVariation should be inited" << endl;
	}

	if (excitPotRealWeightVariation)
	{
		excitPotRealWeightVariation->setVoid();
	}
	else
	{
		cerr << "Warning, excitPotTemporalDeviation should be inited" << endl;
	}
	
	if (excitDepPSPWeights)
	{
		excitDepPSPWeights->setVoid();

	}
	else
	{
		cerr << "Warning, excitDepPSPWeights should be inited" << endl;
	}

	if (excitDepWeightVariation)
	{
		excitDepWeightVariation->setVoid();
	}
	else
	{
		cerr << "Warning, excitDepWeightVariation should be inited" << endl;
	}
	if (excitDepRealWeightVariation)
	{
		excitDepRealWeightVariation->setVoid();
	}
	else
	{
		cerr << "Warning, excitDepTemporalDeviation should be inited" << endl;
	}
	if (excitPreTemporalDeviation)
	{
		excitPreTemporalDeviation->setVoid();
	}
	else
	{
		cerr << "Warning, excitPreTemporalDeviation should be inited" << endl;
	}
	if (excitPostTemporalDeviation)
	{
		excitPostTemporalDeviation->setVoid();
	}
	else
	{
		cerr << "Warning, excitPostTemporalDeviation should be inited" << endl;
	}
	
	for (int i=0;i<DELAY;i++)
	{
		preDelayRepartition[i].setVoid();
	}
	
	for (int i=0;i<DELAY;i++)
	{
		postDelayRepartition[i].setVoid();
	}	
		#endif
	
	for (int i=0;i<100;i++)
	{
		excitPreTempDevRepartition[i].setVoid();
	}
		
	for (int i=0;i<100;i++)
	{
		excitPostTempDevRepartition[i].setVoid();
	}
}

void ExcitSynapseStater::graph()
{
		#ifdef _GLOBAL_STAT_MODE
			#ifndef _MULTI_TEST_MODE
				#ifndef _PHASE_TEST_MODE
	//#ifdef _TEST_STAT
	cout << "*** AssemblyStater *** Graphing Excit Synpases stats for all assemblies "<< endl;
	//#endif

	if (excitGnuplotSynapseFile->isOpen())
	{
		cout << "In graph assemblies multiplot" << endl;

		ostringstream oss;
		oss << (Handler*) this;

		// Variation de poids
		excitGnuplotSynapseFile->setOutput("excitMeanPSPWeightsStats"+oss.str());
		excitGnuplotSynapseFile->setTitle("excitMeanPSPWeightsStats"+oss.str());
		excitGnuplotSynapseFile->plotFirstSingleLine("excitPotMeanPSPWeightsStats"+oss.str());
		excitGnuplotSynapseFile->plotSecondSingleLine("excitDepMeanPSPWeightsStats"+oss.str());

		excitGnuplotSynapseFile->setOutput("excitMeanWeightVariationStats"+oss.str());
		excitGnuplotSynapseFile->setTitle("excitMeanWeightVariationStats"+oss.str());
		excitGnuplotSynapseFile->plotFirstSingleLine("excitPotMeanWeightVariationStats"+oss.str());
		excitGnuplotSynapseFile->plotSecondSingleLine("excitDepMeanWeightVariationStats"+oss.str());

		excitGnuplotSynapseFile->setOutput("excitRealWeightVariationStats"+oss.str());
		excitGnuplotSynapseFile->setTitle("excitRealWeightVariationStats"+oss.str());
		excitGnuplotSynapseFile->plotFirstSingleLine("excitPotRealWeightVariationStats"+oss.str());
		excitGnuplotSynapseFile->plotSecondSingleLine("excitDepRealWeightVariationStats"+oss.str());

		// Variations temporelles
		excitGnuplotSynapseFile->setOutput("excitTemporalDeviationStats"+oss.str());
		excitGnuplotSynapseFile->setTitle("excitTemporalDeviationStats"+oss.str());
		excitGnuplotSynapseFile->plotFirstSingleLine("excitPreTemporalDeviationStats"+oss.str());
		excitGnuplotSynapseFile->plotSecondSingleLine("excitPostTemporalDeviationStats"+oss.str());
		
		excitGnuplotSynapseFile->setOutput("ExcitTempDeviationRepartition"+oss.str());
		excitGnuplotSynapseFile->setTitle("Excit TempDeviation Repartition"+oss.str());
		excitGnuplotSynapseFile->plot3DIndexedLines("excitTempDevRepartitionStats"+oss.str());
		
		// Delais
		excitGnuplotSynapseFile->setOutput("PreDelayRepartitionStats"+oss.str());
		excitGnuplotSynapseFile->setTitle("Pre Delay Repartition"+oss.str());
		excitGnuplotSynapseFile->plot3DIndexedLines("preDelayRepartitionStats"+oss.str());
		
		excitGnuplotSynapseFile->setOutput("PostDelayRepartitionStats"+oss.str());
		excitGnuplotSynapseFile->setTitle("Post Delay Repartition"+oss.str());
		excitGnuplotSynapseFile->plot3DIndexedLines("postDelayRepartitionStats"+oss.str());
	}
	else
	{
		cerr << "Warning, excitGnuplotSynapseFile should be open" << endl;
	}
				#endif
			#endif
		#endif
}
	#endif
#endif

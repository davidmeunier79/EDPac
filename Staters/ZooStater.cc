// ZooStater.cc

// Local Includes
#include "ZooStater.h"

/****************************************************************************************************************************************/
/************************************************* Methodes de la classe ZooStater ************************************************/
/****************************************************************************************************************************************/

ZooStater::ZooStater()
{
	fitnessGnuplotFile = new DistributionGnuplotFile();

#ifdef _RUN_MODE
	meanFitness = new Accumulater();

	meanSteps = new Accumulater();

	meanMvtAvants = new Accumulater();
	meanPacgums = new Accumulater();
	meanPreys = new Accumulater();

	// Fichiers traces
	meanFitnessFile = new DataFile();
	bestFitnessFile = new DataFile();

	nbStepsFile = new DataFile();
	nbPreysFile = new DataFile();

	nbPacgumsFile = new DataFile();
	nbMvtAvantsFile = new DataFile();
#endif

#ifdef _TEST_MODE
	meanGoodBehaviour = new Accumulater();
	meanBadBehaviour = new Accumulater();

	#ifdef _RUN_MODE
	scoreBeforeRun = new Accumulater();
	scoreAfterRun = new Accumulater();
	#endif

	// Fichiers traces
/*
	goodBehaviourFile = new DataFile();
	badBehaviourFile = new DataFile();
*/
	meanGoodBehaviourFile = new AccuDataFile();
	meanBadBehaviourFile = new AccuDataFile();

	#ifdef _RUN_MODE
	scoreBeforeRunFile = new AccuDataFile();
	scoreAfterRunFile = new AccuDataFile();
	#endif
#endif
}

ZooStater::~ZooStater()
{


#ifdef _TEST_MODE
	delete(meanGoodBehaviour);
	delete(meanBadBehaviour);

	#ifdef _RUN_MODE
	delete(scoreBeforeRun);
	delete(scoreAfterRun);
	#endif

	// Fichiers traces
	//delete(goodBehaviourFile);
	//delete(badBehaviourFile);

	delete(meanGoodBehaviourFile);
	delete(meanBadBehaviourFile);

	#ifdef _RUN_MODE
	delete(scoreBeforeRunFile);
	delete(scoreAfterRunFile);
	#endif
#endif
#ifdef _RUN_MODE
	delete(meanFitness);

	delete(meanSteps);
	delete(meanPreys);

	delete(meanMvtAvants);
	delete(meanPacgums);

	// Fichiers traces
	delete(meanFitnessFile);
	delete(bestFitnessFile);

	delete(nbStepsFile);
	delete(nbPreysFile);
#endif
	delete(fitnessGnuplotFile);

}

void ZooStater::openGrapher()
{

	if (fitnessGnuplotFile)
	{
		fitnessGnuplotFile->openGnuplotFile("ZooStat");
	}
	else
	{
		cerr << "Warning, fitnessGnuplotFile is not inited" << endl;
	}
}

void ZooStater::runGrapher()
{
	if (fitnessGnuplotFile)
	{
		fitnessGnuplotFile->systemFile();
	}
	else
	{
		cerr << "Warning, fitnessGnuplotFile is not inited" << endl;
	}
}

void ZooStater::closeGrapher()
{
	if (fitnessGnuplotFile->isOpen())
	{
		fitnessGnuplotFile->closeFile();
	}
	else
	{
		cerr << "Warning, fitnessGnuplotFile is not inited" << endl;
	}
}

void ZooStater::openTracer()
{
#ifdef _RUN_MODE
	if (meanFitnessFile)
	{
		meanFitnessFile->openDataFile("MeanFitness");
	}
	else
	{
		cerr << "Warning, meanFitnessFile should be inited" << endl;
	}

	if (bestFitnessFile)
	{
		bestFitnessFile->openDataFile("BestFitness");
	}
	else
	{
		cerr << "Warning, bestFitnessFile should be inited" << endl;
	}

	if (nbStepsFile)
	{
		nbStepsFile->openDataFile("NbSteps");
	}
	else
	{
		cerr << "Warning, nbStepsFile should be inited" << endl;
	}

	if (nbPacgumsFile)
	{
		nbPacgumsFile->openDataFile("NbPacgums");
	}
	else
	{
		cerr << "Warning, nbPacgumsFile should be inited" << endl;
	}

	if (nbMvtAvantsFile)
	{
		nbMvtAvantsFile->openDataFile("NbMvtAvants");
	}
	else
	{
		cerr << "Warning, nbMvtAvantsFile should be inited" << endl;
	}

	if (nbPreysFile)
	{
		nbPreysFile->openDataFile("NbPreys");
	}
	else
	{
		cerr << "Warning, nbPreysFile should be inited" << endl;
	}
#endif

#ifdef _TEST_MODE
	if (meanGoodBehaviourFile)
	{
		meanGoodBehaviourFile->openAccuDataFile("MeanGoodBehaviour");
	}
	else
	{
		cerr << "Warning, meanGoodBehaviourFile should be inited" << endl;
	}

	if (meanBadBehaviourFile)
	{
		meanBadBehaviourFile->openAccuDataFile("MeanBadBehaviour");
	}
	else
	{
		cerr << "Warning, meanBadBehaviourFile should be inited" << endl;
	}
/*
	if (goodBehaviourFile)
	{
		if (!goodBehaviourFile->isOpen())
		{
			goodBehaviourFile->openDataFile("Indexed_Sorted_GoodBehaviourStat");
		}
		else
		{
			cerr << "Warning, goodBehaviourFile is already open" << endl;
		}
	}
	else
	{
		cerr << "Warning, goodBehaviourFile should be inited" << endl;
	}

	if (badBehaviourFile)
	{
		if (!badBehaviourFile->isOpen())
		{
			badBehaviourFile->openDataFile("Indexed_Sorted_BadBehaviourStat");
		}
		else
		{
			cerr << "Warning, badBehaviourFile is already open" << endl;
		}

	}
	else
	{
		cerr << "Warning, badBehaviourFile should be inited" << endl;
	}
*/
	#ifdef _RUN_MODE
	if (scoreBeforeRunFile)
	{
		if (!scoreBeforeRunFile->isOpen())
		{
			scoreBeforeRunFile->openAccuDataFile("ScoreBeforeRun");
		}
		else
		{
			cerr << "Warning, scoreBeforeRunFile is already open" << endl;
		}
	}
	else
	{
		cerr << "Warning, scoreBeforeRunFile is not inited" << endl;
	}

	if (scoreAfterRunFile)
	{
		if (!scoreAfterRunFile->isOpen())
		{
			scoreAfterRunFile->openAccuDataFile("ScoreAfterRun");
		}
		else
		{
			cerr << "Warning, scoreBeforeRunFile is already open" << endl;
		}
	}
	else
	{
		cerr << "Warning, scoreAfterRunFile is not inited" << endl;
	}
	#endif
#endif
}

void ZooStater::closeTracer()
{
#ifdef _RUN_MODE
	if (meanFitnessFile)
	{
		meanFitnessFile->closeFile();
	}
	else
	{
		cerr << "Warning, meanFitnessFile should be inited" << endl;
	}

	if (bestFitnessFile)
	{
		bestFitnessFile->closeFile();
	}
	else
	{
		cerr << "Warning, bestFitnessFile should be inited" << endl;
	}

	if (nbStepsFile)
	{
		nbStepsFile->closeFile();
	}
	else
	{
		cerr << "Warning, nbStepsFile should be inited" << endl;
	}

	if (nbPacgumsFile)
	{
		nbPacgumsFile->closeFile();
	}
	else
	{
		cerr << "Warning, nbPacgumsFile should be inited" << endl;
	}

	if (nbMvtAvantsFile)
	{
		nbMvtAvantsFile->closeFile();
	}
	else
	{
		cerr << "Warning, nbMvtAvantsFile should be inited" << endl;
	}

	if (nbPreysFile)
	{
		nbPreysFile->closeFile();
	}
	else
	{
		cerr << "Warning, nbPreysFile should be inited" << endl;
	}
#endif

#ifdef _TEST_MODE
/*
	if (goodBehaviourFile)
	{
		goodBehaviourFile->closeFile();
	}
	else
	{
		cerr << "Warning, goodBehaviourFile should be inited" << endl;
	}

	if (badBehaviourFile)
	{
		badBehaviourFile->closeFile();
	}
	else
	{
		cerr << "Warning, badBehaviourFile should be inited" << endl;
	}
*/
	if (meanGoodBehaviourFile)
	{
		meanGoodBehaviourFile->closeAccuDataFile();
	}
	else
	{
		cerr << "Warning, meanGoodBehaviourFile should be inited" << endl;
	}

	if (meanBadBehaviourFile)
	{
		meanBadBehaviourFile->closeAccuDataFile();
	}
	else
	{
		cerr << "Warning, meanBadBehaviourFile should be inited" << endl;
	}

	#ifdef _RUN_MODE
	if (scoreBeforeRunFile)
	{
		if (scoreBeforeRunFile->isOpen())
		{
			scoreBeforeRunFile->closeAccuDataFile();
		}
		else
		{
			cerr << "Warning, scoreBeforeRunFile is not open" << endl;
		}
	}
	else
	{
		cerr << "Warning, scoreBeforeRunFile is not inited" << endl;
	}

	if (scoreAfterRunFile)
	{
		if (scoreAfterRunFile->isOpen())
		{
			scoreAfterRunFile->closeAccuDataFile();
		}
		else
		{
			cerr << "Warning, scoreAfterRunFile is not open" << endl;
		}
	}
	else
	{
		cerr << "Warning, scoreAfterRunFile is not inited" << endl;
	}
	#endif
#endif
}

void ZooStater::initAccumulaters()
{
#ifdef _RUN_MODE
	if (meanFitness)
	{
		meanFitness->initAccu();
	}
	else
	{
		cerr << "Warning, meanFitness should be inited" << endl;
	}

	if (meanSteps)
	{
		meanSteps->initAccu();
	}
	else
	{
		cerr << "Warning, meanNbSteps should be inited" << endl;
	}

	if (meanPacgums)
	{
		meanPacgums->initAccu();
	}
	else
	{
		cerr << "Warning, meanPacgums should be inited" << endl;
	}

	if (meanPreys)
	{
		meanPreys->initAccu();
	}
	else
	{
		cerr << "Warning, meanPreys should be inited" << endl;
	}

	if (meanMvtAvants)
	{
		meanMvtAvants->initAccu();
	}
	else
	{
		cerr << "Warning, meanMvtAvants should be inited" << endl;
	}
#endif
#ifdef _TEST_MODE
	if (meanGoodBehaviour)
	{
		meanGoodBehaviour->initAccu();
	}
	else
	{
		cerr << "Warning, meanGoodBehaviour should be inited" << endl;
	}

	if (meanBadBehaviour)
	{
		meanBadBehaviour->initAccu();
	}
	else
	{
		cerr << "Warning, meanBadBehaviour should be inited" << endl;
	}

	#ifdef _RUN_MODE
	if (scoreBeforeRun)
	{
		scoreBeforeRun->initAccu();
	}
	else
	{
		cerr << "Warning, scoreBeforeRun should be inited" << endl;
	}

	if (scoreAfterRun)
	{
		scoreAfterRun->initAccu();
	}
	else
	{
		cerr << "Warning, scoreAfterRun should be inited" << endl;
	}
	#endif
#endif
}

void ZooStater::flushAccumulater()
{
#ifdef _RUN_MODE
	cout << "meanFitness: " << (Accumulater*) meanFitness << endl;
	cout << "meanNbSteps: " << (Accumulater*) meanSteps << endl;
	cout << "meanMvtAvants: " << (Accumulater*) meanMvtAvants << endl;
	cout << "meanPacgums: " << (Accumulater*) meanPacgums << endl;
	cout << "meanPreys: " << (Accumulater*) meanPreys << endl;
#endif

#ifdef _TEST_MODE
	cout << "meanGoodBehaviour: " << (Accumulater*) meanGoodBehaviour << endl;
	cout << "meanBadBehaviour: " << (Accumulater*) meanBadBehaviour << endl;

	#ifdef _RUN_MODE
	cout << "scoreBeforeRun: " << (Accumulater*) scoreBeforeRun << endl;
	cout << "scoreAfterRun: " << (Accumulater*) scoreAfterRun << endl;
	#endif
#endif
}


#ifdef _TEST_MODE
	#ifdef _RUN_MODE
void ZooStater::statScoreBeforeRun(Individual* pac)
{
/*
	if (meanGoodBehaviour)
	{
		meanGoodBehaviour->accumulate(((Individual*) pac)->getGoodBehaviour());
	}
	else
	{
		cerr << "Warning, meanGoodBehaviour should be inited" << endl;
	}
	if (meanBadBehaviour)
	{
		meanBadBehaviour->accumulate(((Individual*) pac)->getBadBehaviour());
	}
	else
	{
		cerr << "Warning, meanBadBehaviour should be inited" << endl;
	}


		#ifdef _ANOVA_STAT_MODE
	if (meanGoodBehaviourFile)
	{
		meanGoodBehaviourFile->addValueData(getEvoIndex(),getTopoIndex(),(double) ((Individual*) pac)->getGoodBehaviour());
	}

	if (meanBadBehaviourFile)
	{
		meanBadBehaviourFile->addValueData(getEvoIndex(),getTopoIndex(),(double) ((Individual*) pac)->getBadBehaviour());
	}
		#endif
*/
	if (scoreBeforeRun)
	{
		#ifdef _ORDERED_TEST_MODE
		scoreBeforeRun->accumulate((double) ((Individual*) pac)->getIndividualScore() + 4*NB_MAX_SCREENS);
		#else
		scoreBeforeRun->accumulate((double) ((Individual*) pac)->getIndividualScore() + NB_TESTED_ANIMALS);
		#endif
	}
	else
	{
		cerr << "Warning, scoreBeforeRun should be inited" << endl;
	}

		#ifdef _ANOVA_STAT_MODE
			#ifdef _ORDERED_TEST_MODE
	if (scoreBeforeRunFile)
	{
		scoreBeforeRunFile->addValueData(getEvoIndex(),getTopoIndex(),(double) ((Individual*) pac)->getIndividualScore() + 4*NB_MAX_SCREENS);
	}
			#else
	if (scoreBeforeRunFile)
	{
		scoreBeforeRunFile->addValueData(getEvoIndex(),getTopoIndex(),(double) ((Individual*) pac)->getIndividualScore() + NB_TESTED_ANIMALS);
	}
			#endif
		#endif

	trace(pac);
}

void ZooStater::statScoreAfterRun(Individual* pac)
{
	if (scoreAfterRun)
	{
		#ifdef _ORDERED_TEST_MODE
		scoreAfterRun->accumulate((double) ((Individual*) pac)->getIndividualScore() + 4*NB_MAX_SCREENS);
		#else
		scoreAfterRun->accumulate((double) ((Individual*) pac)->getIndividualScore() + NB_TESTED_ANIMALS);
		#endif

	}
	else
	{
		cerr << "Warning, scoreAfterRun should be inited" << endl;
	}

		#ifdef _ANOVA_STAT_MODE
			#ifdef _ORDERED_TEST_MODE
	if (scoreAfterRunFile)
	{
		scoreAfterRunFile->addValueData(getEvoIndex(),getTopoIndex(),(double) ((Individual*) pac)->getIndividualScore() + 4*NB_MAX_SCREENS);
	}
			#else
	if (scoreAfterRunFile)
	{
		scoreAfterRunFile->addValueData(getEvoIndex(),getTopoIndex(),(double) ((Individual*) pac)->getIndividualScore() + NB_TESTED_ANIMALS);
	}
			#endif
		#endif
	trace(pac);
}
	#endif

void ZooStater::trace(Individual* p)
{
	cout << "Tracing stats for individual " << getTopoIndex() << endl;

	if (meanGoodBehaviour)
	{
		meanGoodBehaviour->accumulate(((Individual*) p)->getGoodBehaviour());
	}
	else
	{
		cerr << "Warning, meanGoodBehaviour should be inited" << endl;
	}

	if (meanBadBehaviour)
	{
		meanBadBehaviour->accumulate(((Individual*) p)->getBadBehaviour());
	}
	else
	{
		cerr << "Warning, meanBadBehaviour should be inited" << endl;
	}

		#ifdef _ANOVA_STAT_MODE
	if (meanGoodBehaviourFile)
	{
		meanGoodBehaviourFile->addValueData(getEvoIndex(),getTopoIndex(),(double) ((Individual*) p)->getGoodBehaviour());
	}

	if (meanBadBehaviourFile)
	{
		meanBadBehaviourFile->addValueData(getEvoIndex(),getTopoIndex(),(double) ((Individual*) p)->getBadBehaviour());
	}
		#endif

}

#endif


/****************************************************************************************************************************************/
/******************************************************* Methodes de stats **************************************************************/
/****************************************************************************************************************************************/
#ifdef _POPULATION_STAT_MODE
void ZooStater::stat(Zoo* pop)
{
	#ifdef _RUN_MODE
	vector<Chromosome*>::iterator it = pop->tabChromosomes.begin();
	vector<Chromosome*>::iterator end = pop->tabChromosomes.end();

	while(it!=end)
	{
		meanFitness->accumulate(((Individual*) *it)->getFitness());

		meanSteps->accumulate(((Individual*) *it)->getNbSteps());
		meanPacgums->accumulate(((Individual*) *it)->getNbPacgums());
		meanPreys->accumulate(((Individual*) *it)->getNbPreys());
		meanMvtAvants->accumulate(((Individual*) *it)->getNbMvtAvants());

		it++;
	}
	#endif
}

void ZooStater::trace(Zoo* pop)
{
	#ifdef _RUN_MODE
	if(meanFitnessFile->isOpen())
	{
		if (meanFitness)
		{
		#ifdef _TEST_STAT
			cout << "ZooStater adding data line to meanFitnessFile" << endl;
		#endif
			meanFitnessFile->addLineData(pop->getEvoIndex(),meanFitness->getMean());

		}
		else
		{
			cerr << "Warning, meanFitness should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, meanFitnessFile should be inited" << endl;
	}

	if(bestFitnessFile->isOpen())
	{
		if (meanFitness)
		{
		#ifdef _TEST_STAT
			cout << "ZooStater adding data line to bestFitnessFile" << endl;
		#endif
			bestFitnessFile->addLineData(pop->getEvoIndex(),meanFitness->getBest());

		}
		else
		{
			cerr << "Warning, meanFitness should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, bestFitnessFile should be inited" << endl;
	}

	if (nbStepsFile->isOpen())
	{
		if (meanSteps)
		{
		#ifdef _TEST_STAT
			cout << "PacmanStater adding data line to nbStepsFile" << endl;
		#endif
			nbStepsFile->addLineData(pop->getEvoIndex(),meanSteps->getMean());
		}
	}
	else
	{
		cerr << "Warning, nbStepsFile should be inited" << endl;
	}

	if (nbPacgumsFile->isOpen())
	{
		if (meanPacgums)
		{
		#ifdef _TEST_STAT
			cout << "PacmanStater adding data line to nbPacgumsFile" << endl;
		#endif
			nbPacgumsFile->addLineData(pop->getEvoIndex(),meanPacgums->getMean());
		}
	}
	else
	{
		cerr << "Warning, nbPacgumsFile should be inited" << endl;
	}

	if (nbPreysFile->isOpen())
	{
		if (meanPreys)
		{
		#ifdef _TEST_STAT
			cout << "PacmanStater adding data line to nbPreysFile" << endl;
		#endif
			nbPreysFile->addLineData(pop->getEvoIndex(),meanPreys->getMean());
		}
	}
	else
	{
		cerr << "Warning, nbPreysFile should be inited" << endl;
	}

	if (nbMvtAvantsFile->isOpen())
	{
		if (meanMvtAvants)
		{
		#ifdef _TEST_STAT
			cout << "PacmanStater adding data line to nbMvtAvantsFile" << endl;
		#endif
			nbMvtAvantsFile->addLineData(pop->getEvoIndex(),meanMvtAvants->getMean());
		}
	}
	else
	{
		cerr << "Warning, nbMvtAvantsFile should be inited" << endl;
	}
	#endif

	#ifdef _TEST_MODE
	if(meanGoodBehaviourFile->isOpen())
	{
		if (meanGoodBehaviour)
		{
		#ifdef _TEST_STAT
			cout << "ZooStater adding data line to goodBehaviourFile" << endl;
		#endif
			meanGoodBehaviourFile->addAccuLineData(pop->getEvoIndex(),*meanGoodBehaviour);

		}
		else
		{
			cerr << "Warning, meanGoodBehaviour should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, goodBehaviourFile should be inited" << endl;
	}

	if(meanBadBehaviourFile->isOpen())
	{
		if (meanBadBehaviour)
		{
		#ifdef _TEST_STAT
			cout << "PacmanStater adding data line to badBehaviourFile" << endl;
		#endif
			meanBadBehaviourFile->addAccuLineData(pop->getEvoIndex(),*meanBadBehaviour);
		}
		else
		{
			cerr << "Warning, meanBadBehaviour should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, badBehaviourFile should be inited" << endl;
	}

		#ifdef _RUN_MODE
	if(scoreBeforeRunFile->isOpen())
	{
		if (scoreBeforeRun)
		{
			#ifdef _TEST_STAT
			cout << "PacmanTester adding score before run to scoreFile" << endl;
			#endif
			scoreBeforeRunFile->addAccuLineData(pop->getEvoIndex(),*scoreBeforeRun);

		}
		else
		{
			cerr << "Warning, scoreBeforeRun should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, scoreBeforeRunFile should be inited" << endl;
	}

	if(scoreAfterRunFile->isOpen())
	{
		if (scoreAfterRun)
		{
			#ifdef _TEST_STAT
			cout << "PacmanTester adding score after run to scoreFile" << endl;
			#endif
			scoreAfterRunFile->addAccuLineData(pop->getEvoIndex(),*scoreAfterRun);

		}
		else
		{
			cerr << "Warning, scoreAfterRun should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, scoreAfterRunFile should be inited" << endl;
	}
		#endif
/*
	// Ajout de séparateurs
	if(goodBehaviourFile)
	{
			#ifdef _TEST_STAT
		cout << "IndividualStater adding data separator to goodBehaviourFile" << endl;
			#endif
		goodBehaviourFile->addDataSeparator();
	}
	else
	{
		cerr << "Warning, goodBehaviourFile should be inited" << endl;
	}

	if(badBehaviourFile)
	{
#ifdef _TEST_STAT
		cout << "IndividualStater adding data separator to badBehaviourFile" << endl;
#endif
		badBehaviourFile->addDataSeparator();
	}
	else
	{
		cerr << "Warning, badBehaviourFile should be inited" << endl;
	}
	*/
	#endif

	initAccumulaters();
	flushAccumulater();
}

void ZooStater::graph()
{
	cout << "Graphing population stats" << endl;
	#ifdef _RUN_MODE
	stringstream inss;
	inss << "MeanFitnessStat";

	fitnessGnuplotFile->setOutput(inss.str());
	fitnessGnuplotFile->setTitle(inss.str());
	fitnessGnuplotFile->plotLine("MeanFitness");

	stringstream inss2;
	inss2 << "BestFitnessStat";

	fitnessGnuplotFile->setOutput(inss2.str());
	fitnessGnuplotFile->setTitle(inss2.str());
	fitnessGnuplotFile->plotLine("BestFitness");


	stringstream inss3;
	inss3 << "NbStepsStat";

	fitnessGnuplotFile->setOutput(inss3.str());
	fitnessGnuplotFile->setTitle(inss3.str());
	fitnessGnuplotFile->plotLine("NbSteps");

	stringstream inss4;
	inss4 << "NbPacgumsStat";

	fitnessGnuplotFile->setOutput(inss4.str());
	fitnessGnuplotFile->setTitle(inss4.str());
	fitnessGnuplotFile->plotLine("NbPacgums");

	stringstream inss5;
	inss5 << "NbPacgumsStat";

	fitnessGnuplotFile->setOutput(inss5.str());
	fitnessGnuplotFile->setTitle(inss5.str());
	fitnessGnuplotFile->plotLine("NbPacgums");

	stringstream inss6;
	inss6 << "NPreysStat";

	fitnessGnuplotFile->setOutput(inss6.str());
	fitnessGnuplotFile->setTitle(inss6.str());
	fitnessGnuplotFile->plotLine("NbPreys");
	#endif

	#ifdef _TEST_MODE
		#ifdef _RUN_MODE
			#ifdef _TEST_STAT
	cout << "Graphing pacman test scores" << endl;
			#endif
	stringstream inss9;
	inss9 << "TestScore";


	fitnessGnuplotFile->plotMean("TestScore","ScoreBeforeRun","ScoreAfterRun",getEvoIndex());
		#endif

		#ifdef _TEST_STAT
	cout << "Graphing pacman stats" << endl;
		#endif

	fitnessGnuplotFile->plotMean("MeanGoodBehaviour",getEvoIndex());
	fitnessGnuplotFile->plotMean("MeanBadBehaviour",getEvoIndex());
/*

	stringstream inss7;
	inss7 << "MeanGoodBehaviourStat";

	fitnessGnuplotFile->setOutput(inss7.str());
	fitnessGnuplotFile->setTitle(inss7.str());
	fitnessGnuplotFile->plotLine("MeanGoodBehaviour");

	stringstream inss8;
	inss8 << "MeanBadBehaviourStat";

	fitnessGnuplotFile->setOutput(inss8.str());
	fitnessGnuplotFile->setTitle(inss8.str());
	fitnessGnuplotFile->plotLine("MeanBadBehaviour");

	stringstream inss10;
	inss10 << "3D_" << "GoodBehaviourStat";

	fitnessGnuplotFile->setOutput(inss10.str());
	fitnessGnuplotFile->setTitle(inss10.str());
	fitnessGnuplotFile->plot3DIndexedLines("GoodBehaviourStat");

	stringstream inss11;
	inss11 << "3D_" << "BadBehaviourStat";

	fitnessGnuplotFile->setOutput(inss11.str());
	fitnessGnuplotFile->setTitle(inss11.str());
	fitnessGnuplotFile->plot3DIndexedLines("BadBehaviourStat");
*/
		#ifdef _TEST_STAT
	cout << "End of Graph pacman stats" << endl;
		#endif
	#endif
}
#endif


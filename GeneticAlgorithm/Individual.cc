// Individual.cc

#include "Individual.h"

/****************************************************************************************************************************************/
/*************************************************** Methodes de la classe EvoNetwork ***************************************************/
/****************************************************************************************************************************************/

// Construit un chromosome vide, avec un tableau de genes vides et un fitness à -1
Individual::Individual()
{
#ifdef _RUN_MODE
	initEvalFitness();
#endif

#ifdef _TEST_MODE
	countGoodBehaviour = new Counter();
	countBadBehaviour = new Counter();
#endif
}

Individual::Individual(Individual& chr): Chromosome((Chromosome&) chr)
{
#ifdef _RUN_MODE
	initEvalFitness();
#endif
#ifdef _TEST_MODE
	countGoodBehaviour = new Counter();
	countBadBehaviour = new Counter();
#endif
}

// Construit un chromosome vide, avec un tableau de genes vides et un fitness à -1
Individual::~Individual()
{
//#ifdef _GA_TEST
	cout << "~Individual " << getTopoIndex() << endl;
//#endif
#ifdef _TEST_MODE
	delete(countGoodBehaviour);
	delete(countBadBehaviour);
#endif
}

#ifdef _TEST_MODE
void Individual::statGoodBehaviour()
{
//#ifdef _TEST_STAT
	cout << "Individual stating Good Behaviour" << endl;
//#endif
	countGoodBehaviour->count();
}

void Individual::statBadBehaviour()
{
//#ifdef _TEST_STAT
	cout << "Individual stating Bad Behaviour" << endl;
//#endif
	countBadBehaviour->count();
}

int Individual::getIndividualScore()
{
	if (countGoodBehaviour && countBadBehaviour)
	{
		return (countGoodBehaviour->getCounter() - countBadBehaviour->getCounter());
	}
}

int Individual::getGoodBehaviour()
{
	if (countGoodBehaviour)
	{
		return (countGoodBehaviour->getCounter());
	}
}

int Individual::getBadBehaviour()
{
	if (countBadBehaviour)
	{
		return (countBadBehaviour->getCounter());
	}
}

void Individual::initIndividualScore()
{
	if (countGoodBehaviour)
	{
		countGoodBehaviour->initCounter();
	}
	else
	{
		cerr << "Warning, countGoodBehaviour should be inited" << endl;
	}

	if (countBadBehaviour)
	{
		countBadBehaviour->initCounter();
	}
	else
	{
		cerr << "Warning, countBadBehaviour should be inited" << endl;
	}
}
#endif

void Individual::getPosition(int& posX,int& posY)
{
	cerr << "Warning, accessing virtual Individual::getPosition method" << endl;
}

void Individual::initNbSteps()
{
	nbSteps=0;
}

#ifdef _RUN_MODE
void Individual::setFitness()
{
	#ifdef _CONDITIONNING_MODE

		#ifdef _BLOCKING_MODE
	fitness->accumulate(lifeLevel*INTER_WAVE_PERIOD);
		#else
	fitness->accumulate(lifeLevel);
		#endif
		
		#ifdef _ZOO_TEST
	cout << "fitness:" << fitness << " (lifeLevel = " << lifeLevel << ")" << endl;
		#endif

	if (tracer)
	{
		((IndividualTracer*) tracer)->trace(this);
	}
	#else

	fitness->accumulate(NB_POINTS_EACH_PACGUM*pacgomesMangees+NB_POINTS_EACH_PREY*gentilsManges);
	#endif
}

void Individual::initEvalFitness()
{
	evalFitness=new Accumulater();
}

void Individual::setEvalFitness()
{
	if (fitness)
	{
		if (evalFitness)
		{
			evalFitness->accumulate(fitness->getAccu());
	//#ifdef _ZOO_TEST
			cout << "Setting fitness " << fitness->getAccu() << " for evaluation " << getEvalIndex() << endl;
	//#endif
		}
		else
		{
			cerr << "Warning, evalFitness should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, fitness should be inited" << endl;
	}
}

double Individual::getFitness()
{
#ifdef _LOWEST_FITNESS_MODE
	return evalFitness->getLowest();
#endif
#ifdef _MEAN_FITNESS_MODE
	return evalFitness->getMean();
#endif
}

int Individual::getNbSteps()
{
	return nbSteps;
}

int Individual::getNbMvtsTous()
{
	return nbMvtsTous;
}

int Individual::getNbMvtAvants()
{
	return nbMvtAvants;
}

int Individual::getNbPacgums()
{
	return nbPacgums;
}

int Individual::getNbPreys()
{
	return nbPreys;
}

void Individual::initIndividualFiles()
{
	#ifdef _INDIVIDUAL_TRACE_MODE
		#ifdef _TRACE_TEST
	cerr << "IndividualTracer openTracer" << endl;
		#endif
	tracer = new IndividualTracer();
	#endif
}

void Individual::endIndividualFiles()
{
	#ifdef _INDIVIDUAL_TRACE_MODE
		#ifdef _TRACE_TEST
	cout << "IndividualTracer closeTracer" << endl;
		#endif

	delete((IndividualTracer*) tracer);
	
		#ifdef _INDIVIDUAL_GRAPH_MODE
			#ifdef _GRAPH_TEST
	cout << "IndividualGrapher graph" << endl;
			#endif
		
		
	grapher = new IndividualGrapher();
	((IndividualGrapher*) grapher)->graph();
	delete((IndividualGrapher*) grapher);
		#endif
	#endif
}
#endif

Chromosome* Individual::clone()
{
#ifdef _ZOO_TEST
	cout << "Cloning Individual " << getTopoIndex() << endl;
#endif
	return new Individual(*this);
}

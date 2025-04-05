// ZooTracer.cc

// Local Includes
#include "ZooTracer.h"

/****************************************************************************************************************************************/
/*********************************************** Methodes de la classe ZooTracer *************************************************/
/****************************************************************************************************************************************/

ZooTracer::ZooTracer()
{
#ifdef _TRACE_TEST
	cout << "ZooTracer" << endl;
#endif

#ifdef _RUN_MODE
	fitnessFile = new DataFile();
#endif
#ifdef _TEST_MODE
	goodBehaviourFile = new DataFile();
	badBehaviourFile = new DataFile();
#endif
	openTracer();
}

ZooTracer::~ZooTracer()
{
#ifdef _TRACE_TEST
	cout << "~ZooTracer" << endl;
#endif
	closeTracer();

#ifdef _TEST_MODE
	delete(goodBehaviourFile);
	delete(badBehaviourFile);
#endif
#ifdef _RUN_MODE
	delete(fitnessFile);
#endif
}

void ZooTracer::openTracer()
{
#ifdef _RUN_MODE
	if (fitnessFile)
	{
		fitnessFile->openDataFile((string)"Indexed_Sorted_"+(string)FITNESS_FILENAME);
	}
#endif
#ifdef _TEST_MODE
	if (goodBehaviourFile)
	{
		goodBehaviourFile->openDataFile("Indexed_Sorted_GoodBehaviourStat");
	}
	else
	{
		cerr << "Warning, goodBehaviourFile is not inited" << endl;
	}

	if (badBehaviourFile)
	{
		badBehaviourFile->openDataFile("Indexed_Sorted_BadBehaviourStat");
	}
	else
	{
		cerr << "Warning, badBehaviourFile is not inited" << endl;
	}
#endif
}

void ZooTracer::closeTracer()
{
#ifdef _RUN_MODE
	if (fitnessFile)
	{
		fitnessFile->closeFile();
	}
#endif
#ifdef _TEST_MODE
	if (goodBehaviourFile)
	{
		goodBehaviourFile->closeFile();
	}
	else
	{
		cerr << "Warning, goodBehaviourFile is not inited" << endl;
	}

	if (badBehaviourFile)
	{
		badBehaviourFile->closeFile();
	}
	else
	{
		cerr << "Warning, badBehaviourFile is not inited" << endl;
	}
#endif
}

/****************************************************************************************************************************************/
/************************************************** Methodes de traces ******************************************************************/
/****************************************************************************************************************************************/
#ifdef _POPULATION_TRACE_MODE
void ZooTracer::trace(Individual* p)
{
	#ifdef _TEST_MODE
	if(goodBehaviourFile->isOpen())
	{
	#ifdef _TEST_STAT
		cout << "ZooTracer adding data line to goodBehaviourFile" << endl;
	#endif
		goodBehaviourFile->addIndexedLineData(p->getEvoIndex(),p->getTopoIndex(),((Individual*) p)->getGoodBehaviour());
	}
	else
	{
		cerr << "Warning, goodBehaviourFile should be inited" << endl;
	}

	if(badBehaviourFile->isOpen())
	{
	#ifdef _TEST_STAT
		cout << "ZooTracer adding data line to badBehaviourFile" << endl;
	#endif
badBehaviourFile->addIndexedLineData(p->getEvoIndex(),p->getTopoIndex(),((Individual*) p)->getBadBehaviour());
	}
	else
	{
		cerr << "Warning, badBehaviourFile should be inited" << endl;
	}
	#endif
}

void ZooTracer::trace(Zoo* z)
{
	std::vector<Chromosome*>::iterator itChr=z->tabChromosomes.begin();
	std::vector<Chromosome*>::iterator endChr=z->tabChromosomes.end();

	z->initTopoIndex();

	while (itChr!=endChr)
	{
	#ifdef _RUN_MODE
		if (fitnessFile->isOpen())
		{
			fitnessFile->addIndexedLineData(z->getEvoIndex(),z->getTopoIndex(),((Individual*) *itChr)->getFitness());
		}
	#endif
		z->incrementTopoIndex();
		itChr++;
	}
	#ifdef _RUN_MODE
	fitnessFile->addDataSeparator();
	#endif
	#ifdef _TEST_MODE
	goodBehaviourFile->addDataSeparator();
	badBehaviourFile->addDataSeparator();
	#endif
}

#endif

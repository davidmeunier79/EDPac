// ZooGrapher.cc

// Local Includes
#include "ZooGrapher.h"

/****************************************************************************************************************************************/
/********************************************** Methodes de la classe ZooGrapher *************************************************/
/****************************************************************************************************************************************/

ZooGrapher::ZooGrapher()
{
#ifdef _RUN_MODE
	populationGnuplotFile = new GnuplotFile();
#endif

#ifdef _TEST_MODE
	gnuplotBehaviourFile = new GnuplotFile();
#endif
	openGrapher();
}

ZooGrapher::~ZooGrapher()
{
	runGrapher();
	closeGrapher();

#ifdef _TEST_MODE
	delete(gnuplotBehaviourFile);
#endif
#ifdef _RUN_MODE
	delete(populationGnuplotFile);
#endif
}

void ZooGrapher::openGrapher()
{
#ifdef _POPULATION_GRAPH_MODE
	#ifdef _RUN_MODE
	if(populationGnuplotFile)
	{
		#ifdef _TRACE_TEST
		cout << "Opening ZooFitness File" << endl;
		#endif
		populationGnuplotFile->openGnuplotFile(FITNESS_GRAPH_NAME);
	}
	#endif

	#ifdef _TEST_MODE
	if (gnuplotBehaviourFile)
	{
		gnuplotBehaviourFile->openGnuplotFile(BEHAVIOUR_FILENAME);
	}
	else
	{
		cerr << "Warning, gnuplotBehaviourFile is not inited" << endl;
	}
	#endif
#endif
}

void ZooGrapher::runGrapher()
{
#ifdef _RUN_MODE
	if(populationGnuplotFile)
	{
		populationGnuplotFile->systemFile();
	}
#endif
#ifdef _TEST_MODE
	if (gnuplotBehaviourFile)
	{
		gnuplotBehaviourFile->systemFile();
	}
	else
	{
		cerr << "Warning, gnuplotBehaviourFile is not inited" << endl;
	}
#endif
}

void ZooGrapher::closeGrapher()
{
#ifdef _TEST_MODE
	if (gnuplotBehaviourFile)
	{
		gnuplotBehaviourFile->closeFile();
	}
	else
	{
		cerr << "Warning, gnuplotBehaviourFile is not inited" << endl;
	}
#endif
#ifdef _RUN_MODE
	if(populationGnuplotFile)
	{
		populationGnuplotFile->closeFile();
	}
#endif
}

/****************************************************************************************************************************************/
/******************************************************* Methodes de graphiques *********************************************************/
/****************************************************************************************************************************************/
#ifdef _POPULATION_GRAPH_MODE
void ZooGrapher::graph(Zoo* p)
{
	#ifdef _RUN_MODE
	//#ifdef _TRACE_TEST
	cout << "Graphing population " << p->getEvoIndex() << endl;
	//#endif
	if (populationGnuplotFile->isOpen())
	{
		#ifdef _POPULATION_TRACE_MODE
		stringstream inss2;
		inss2 << "3D_" << FITNESS_FILENAME;

		populationGnuplotFile->setOutput(inss2.str());
		populationGnuplotFile->setTitle(inss2.str());
		populationGnuplotFile->plot3DIndexedLines(FITNESS_FILENAME);
		#endif
	}
	else
	{
		cerr << "Warning, populationGnuplotFile should be open" << endl;
	}

	#endif

	#ifdef _TEST_MODE
		#ifdef _TEST_STAT
	cout << "Graphing pacman stats" << endl;
		#endif
	if (gnuplotBehaviourFile->isOpen())
	{
		stringstream inss;
		inss << "3D_" << "GoodBehaviourStat";

		gnuplotBehaviourFile->setOutput(inss.str());
		gnuplotBehaviourFile->setTitle(inss.str());
		gnuplotBehaviourFile->plot3DIndexedLines("GoodBehaviourStat");

		stringstream inss2;
		inss2 << "3D_" << "BadBehaviourStat";

		gnuplotBehaviourFile->setOutput(inss2.str());
		gnuplotBehaviourFile->setTitle(inss2.str());
		gnuplotBehaviourFile->plot3DIndexedLines("BadBehaviourStat");

			#ifdef _TEST_STAT
		cout << "End of Graph pacman stats" << endl;
			#endif
	}
	else
	{
		cerr << "Warning, populationGnuplotFile should be open" << endl;
	}

	#endif
}
#endif

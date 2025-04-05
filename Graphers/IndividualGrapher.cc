// IndividualGrapher.cc

// Local Includes
#include "IndividualGrapher.h"

/****************************************************************************************************************************************/
/*********************************************** Methodes de la classe IndividualGrapher *************************************************/
/****************************************************************************************************************************************/

IndividualGrapher::IndividualGrapher()
{
#ifdef _TRACE_TEST
	cout << "IndividualGrapher" << endl;
#endif

#ifdef _RUN_MODE
	lifeGnuplotFile = new GnuplotFile();
#endif
}

IndividualGrapher::~IndividualGrapher()
{
#ifdef _TRACE_TEST
	cout << "~IndividualGrapher" << endl;
#endif
#ifdef _RUN_MODE
	delete(lifeGnuplotFile);
#endif
}

void IndividualGrapher::openGrapher()
{
#ifdef _RUN_MODE
	#ifdef _INDIVIDUAL_GRAPH_MODE
	if (lifeGnuplotFile)
	{
		lifeGnuplotFile->openGnuplotFile(INDIVIDUAL_GRAPH_NAME);
	}
	else
	{
		cerr << "Warning, lifeGnuplotFile should be inited" << endl;
	}
	#endif
#endif
}

void IndividualGrapher::runGrapher()
{
#ifdef _RUN_MODE
	if (lifeGnuplotFile->isOpen())
	{
		lifeGnuplotFile->systemFile();
	}
	else
	{
		cerr << "Warning, lifeGnuplotFile should be opened" << endl;
	}
#endif
}

void IndividualGrapher::closeGrapher()
{
#ifdef _RUN_MODE
	if (lifeGnuplotFile->isOpen())
	{
		lifeGnuplotFile->closeFile();
	}
	else
	{
		cerr << "Warning, lifeGnuplotFile should be opened" << endl;
	}
#endif
}

/****************************************************************************************************************************************/
/************************************************** Methodes de traces ******************************************************************/
/****************************************************************************************************************************************/

#ifdef INDIVIDUAL_GRAPH_NAME
void IndividualGrapher::graph()
{
//#ifdef _TEST_TRACE
	cout << "Graphing individual " << getTopoIndex() << endl;
//#endif
	openGrapher();

	#ifdef _RUN_MODE
	if (lifeGnuplotFile->isOpen())
	{
		#ifdef _INDIVIDUAL_TRACE_MODE
		stringstream oss;
		oss << "LifeTraces";
		oss << "_Generation" << getEvoIndex();
		oss << "_Individual" << getTopoIndex();
		oss << "_Run" << getEvalIndex();

			#ifdef _TEST_MODE
		oss << "_Test" << getTestIndex();
			#endif

		lifeGnuplotFile->setOutput(oss.str());
		lifeGnuplotFile->setTitle(oss.str());
		lifeGnuplotFile->plotLine((string)LIFE_LEVEL_FILENAME);

		stringstream oss2;
		oss2 << "Positions";
		oss2 << "_Generation" << getEvoIndex();
		oss2 << "_Individual" << getTopoIndex();
		oss2 << "_Run" << getEvalIndex();

			#ifdef _TEST_MODE
		oss2 << "_Test" << getTestIndex();
			#endif

		lifeGnuplotFile->setOutput(oss2.str());
		lifeGnuplotFile->setTitle(oss2.str());
		lifeGnuplotFile->plotSingleIndexedLine((string)POSITION_FILENAME);
		#endif
	}
	else
	{
		cerr << "Warning, lifeGnuplotFile should be open" << endl;
	}

	runGrapher();
	#endif

	closeGrapher();
}
#endif

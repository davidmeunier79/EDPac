// IndividualTracer.cc

// Local Includes
#include "IndividualTracer.h"

/****************************************************************************************************************************************/
/*********************************************** Methodes de la classe IndividualTracer *************************************************/
/****************************************************************************************************************************************/

//IndividualTracer* IndividualTracer::theIndividualTracer=0;

IndividualTracer::IndividualTracer()
{
#ifdef _TRACE_TEST
	cout << "IndividualTracer" << endl;
#endif
#ifdef _RUN_MODE
	lifeLevelFile = new DataFile();
	positionFile = new DataFile();
#endif
	openTracer();
}

IndividualTracer::~IndividualTracer()
{
#ifdef _TRACE_TEST
	cout << "~IndividualTracer" << endl;
#endif
	closeTracer();

#ifdef _RUN_MODE
	delete(lifeLevelFile);
	delete(positionFile);
#endif
}

void IndividualTracer::openTracer()
{
#ifdef _RUN_MODE

	#ifdef _INDIVIDUAL_TRACE_MODE
	if (lifeLevelFile)
	{
		lifeLevelFile->openDataFile(LIFE_LEVEL_FILENAME);
	}
	else
	{
		cerr << "Warning, liveLevelFile should be inited" << endl;
	}

	if (positionFile)
	{
		positionFile->openDataFile(POSITION_FILENAME);
	}
	else
	{
		cerr << "Warning, positionFile should be inited" << endl;
	}
	#endif
#endif
}

void IndividualTracer::closeTracer()
{
#ifdef _RUN_MODE
	if (lifeLevelFile->isOpen())
	{
		lifeLevelFile->closeFile();
	}
	else
	{
		cerr << "Warning, liveLevelFile should be open" << endl;
	}


	if (positionFile->isOpen())
	{
		positionFile->closeFile();
	}
	else
	{
		cerr << "Warning, positionFile should be open" << endl;
	}
#endif
}

/****************************************************************************************************************************************/
/************************************************** Methodes de traces ******************************************************************/
/****************************************************************************************************************************************/
#ifdef _INDIVIDUAL_TRACE_MODE
void IndividualTracer::trace(Individual* p)
{

	#ifdef _TRACE_TEST
	cout << "IndividualTracer tracing life fitness" << endl;
	#endif

	#ifdef _RUN_MODE
	if (lifeLevelFile->isOpen())
	{
		lifeLevelFile->addLineData(((Individual*) p)->nbSteps,((Individual*) p)->lifeLevel);
	}
	else
	{
		cerr << "Warning, lifeLevelFile should be open" << endl;
	}

	if (positionFile->isOpen())
	{
		int posX,posY;
		p->getPosition(posX,posY);

		positionFile->addIndexedLineData(((Individual*) p)->nbSteps,posY,-posX);
	}
	else
	{
		cerr << "Warning, positionFile should be open" << endl;
	}
	#endif
}
#endif

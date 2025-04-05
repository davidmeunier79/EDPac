// ZooSaver.cc

// Local Includes
#include "ZooSaver.h"

/****************************************************************************************************************************************/
/*********************************************** Methodes de la classe ZooSaver **************************************************/
/****************************************************************************************************************************************/

//ZooSaver* ZooSaver::theZooSaver=0;

ZooSaver::ZooSaver()
{
	chromoFile = new IOFile();
}

ZooSaver::~ZooSaver()
{
	delete(chromoFile);
}

void ZooSaver::save(Zoo* zoo)
{
	if (chromoFile)
	{
		ostringstream oss;
		oss << CHROMO_SAVER_FILENAME << zoo->getEvoIndex();

		cout << "*** ZooSaver *** opening IO File " << oss.str() << endl;
		chromoFile->openOutputFile(oss.str());

		cout << "*** ZooSaver *** saving population " << zoo->getEvoIndex() << endl;
		ostringstream oss2;
		oss2 << zoo;
		chromoFile->add((ostringstream*) &oss2);

		chromoFile->closeFile();
	}
}

/****************************************************************************************************************************************/
/********************************************* Methodes statiques de la classe ZooSaver *************************************************/
/****************************************************************************************************************************************/
/*
ZooSaver* ZooSaver::initZooSaver()
{
	if (!theZooSaver)
	{
		cout << "*** ZooSaver *** initialisation" << endl;
		theZooSaver = new ZooSaver();
	}
	return theZooSaver;
}

void ZooSaver::closeSaver()
{
	if (theZooSaver)
	{
		delete(theZooSaver);
	}
	theZooSaver=0;
}
*/

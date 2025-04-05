// ZooLoader.cc

// Local Includes
#include "ZooLoader.h"

/****************************************************************************************************************************************/
/*********************************************** Methodes de la classe ZooLoader **************************************************/
/****************************************************************************************************************************************/

//ZooLoader* ZooLoader::theZooLoader=0;

ZooLoader::ZooLoader()
{
	chromoFile = new IOFile();
}

ZooLoader::~ZooLoader()
{
	delete(chromoFile);
}

//#ifdef _TEST_MODE
bool ZooLoader::load(Zoo* zoo, int index)
{
	if (chromoFile)
	{

		ostringstream oss;
		oss << CHROMO_SAVER_FILENAME << index;

		cerr << "*** ZooLoader *** extracting istream from IOFile " << oss.str() << endl;
		chromoFile->openInputFile(oss.str());

		istream& i((istream&) chromoFile->getFile());

		cerr << "*** ZooLoader *** loading zoo" << endl;

		if (i >> zoo)
		{
			cerr << "*** ZooLoader *** Loaded " << zoo->tabChromosomes.size() << " chromosomes for population " << index << endl;
			chromoFile->closeFile();
			return 1;
		}
		else
		{
			cerr << "Warning, unable to read population " << index << endl;
		}

		chromoFile->closeFile();

		return 0;
	}
}

//#endif
/****************************************************************************************************************************************/
/******************************************** Methodes statiques de la classe ZooLoader *************************************************/
/****************************************************************************************************************************************/
/*
ZooLoader* ZooLoader::initZooLoader()
{
	if (!theZooLoader)
	{
		cout << "*** ZooLoader *** initialisation" << endl;
		theZooLoader = new ZooLoader();
	}
	return theZooLoader;
}

void ZooLoader::closeLoader()
{
	if (theZooLoader)
	{
		delete(theZooLoader);
	}
	theZooLoader=0;
}
*/

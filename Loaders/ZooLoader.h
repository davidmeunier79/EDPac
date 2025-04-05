// ZooLoader.h

#ifndef _ZOO_LOADER_H
#define _ZOO_LOADER_H

// Local Includes
#include "../Define.h"
#include "../DefineGA.h"

#include "../DefineSaver.h"

#include "../Handlers/Loader.h"

#include "../Files/IOFile.h"

class ZooLoader;
#include "../Zoo/Zoo.h"

// STL Includes
#include <string>
#include <fstream>
using namespace std;

/******************************************************************************************************************************************/
/***************************************************** Classe ZooLoader *************************************************************/
/******************************************************************************************************************************************/

class ZooLoader: public Loader
{
	IOFile* chromoFile;

	//static ZooLoader* theZooLoader;

	void closeIOFile();

public:

	ZooLoader();
	~ZooLoader();


	//#ifdef _TEST_MODE
	bool load(Zoo* zoo, int evoIndex);
	//void loadBestChromosomes(Zoo* zoo);
	//#endif

	//static ZooLoader* initZooLoader();
	//static void closeLoader();
};

#endif

// ZooSaver.h

#ifndef _ZOO_SAVER_H
#define _ZOO_SAVER_H

// Local Includes
#include "../Define.h"
#include "../DefineGA.h"
#include "../DefineSaver.h"

#include "../Handlers/Saver.h"

#include "../Files/IOFile.h"

class ZooSaver;
#include "../Zoo/Zoo.h"

// STL Includes
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

/******************************************************************************************************************************************/
/***************************************************** Classe ZooSaver *************************************************************/
/******************************************************************************************************************************************/

class ZooSaver: public Saver
{
	IOFile* chromoFile;
/*
	static ZooSaver* theZooSaver;
*/
public:

	ZooSaver();
	~ZooSaver();

	void save(Zoo* pop);

	//static ZooSaver* initZooSaver();
	//static void closeSaver();
};

#endif

// IndexedObject.h

#ifndef _INDEXED_OBJECT_H
#define _INDEXED_OBJECT_H

// STL Includes
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

// Local Includes
#include "Object.h"


//class IndexedObject;
//#include "../Handlers/Stater.h"

/******************************************************************************************************************************************/
/******************************************************* Classe IndexedObject *************************************************************/
/******************************************************************************************************************************************/

class IndexedObject: public Object
{
protected:

	int index;

public:
	IndexedObject();
	~IndexedObject();

	void incrementIndex();

	void setIndex(int newIndex);
	int getIndex();
	
	bool sameIndex(int targetIndex);
	bool isSameIndex(IndexedObject* io);
	
	bool operator==(IndexedObject* io);
	bool operator!=(IndexedObject* io);
	
	string getStringIndex();
};

#endif

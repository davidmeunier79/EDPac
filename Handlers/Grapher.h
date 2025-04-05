// Grapher.h

#ifndef _GRAPHER_H
#define _GRAPHER_H

// Local Includes
#include "Handler.h"

#include "../Objets/Object.h"

#include "../Files/GnuplotFile.h"

// STL Includes
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/******************************************************************************************************************************************/
/********************************************************** Classe Grapher ***************************************************************/
/******************************************************************************************************************************************/

class Grapher : public Handler
{
protected:
	//virtual void openGrapher();
	//virtual void runGrapher();
	//virtual void closeGrapher();

public:
	Grapher();
	Grapher(IndexedObject* io);
	
	virtual ~Grapher();

	virtual void graph(Object* obj);

	virtual void initGrapher(Object* obj);
	virtual void freeGrapher(Object* obj);
};

#endif

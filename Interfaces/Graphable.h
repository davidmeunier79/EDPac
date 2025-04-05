// Graphable.h

#ifndef _GRAPHABLE_H
#define _GRAPHABLE_H

//#include <stdio.h>

// STL Includes
#include <iostream>
using namespace std;

// Local Includes
#include "../Objets/Object.h"

#include "../Handlers/Grapher.h"


/******************************************************************************************************************************************/
/************************************************************* Classe Graphable ***********************************************************/
/******************************************************************************************************************************************/

class Graphable
{
protected:

	Grapher* grapher;
public:

	Graphable();
	~Graphable();
	
	virtual void initGrapher();
	virtual void graph(Object* obj);
};

#endif

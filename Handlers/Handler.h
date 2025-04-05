// Grapher.h

#ifndef _HANDLER_H
#define _HANDLER_H

// Local Includes
//#include "../Define.h"

#include "../Objets/Object.h"
#include "../Interfaces/EvoIndexable.h"
#include "../Interfaces/EvalIndexable.h"
#include "../Interfaces/TestIndexable.h"
#include "../Interfaces/TopoIndexable.h"

#include "../Objets/IndexedObject.h"

// STL Includes
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/******************************************************************************************************************************************/
/********************************************************** Classe Grapher ***************************************************************/
/******************************************************************************************************************************************/

class Handler : public IndexedObject, public EvoIndexable, public EvalIndexable, public TestIndexable, public TopoIndexable
{
public:
	Handler();
	Handler(IndexedObject* io);

	virtual ~Handler();

	virtual void handle(Object* obj);

	friend ostream& operator<<(ostream& o, Handler* h);
};

#endif

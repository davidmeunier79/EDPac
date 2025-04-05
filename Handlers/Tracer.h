// Tracer.h

#ifndef _TRACER_H
#define _TRACER_H

// Local Includes
#include "../Objets/Object.h"

#include "../Files/DataFile.h"

//#include "../Objets/IndexedObject.h"

#include "Handler.h"

// STL Includes
#include <string>
#include <fstream>
using namespace std;

/******************************************************************************************************************************************/
/********************************************************** Classe Tracer ***************************************************************/
/******************************************************************************************************************************************/

class Tracer : public Handler
//class Tracer
{
public:
	Tracer();
	Tracer(IndexedObject* io);

	virtual ~Tracer();

	virtual void trace(Object* obj);

	virtual void initTracer(Object* obj);
	virtual void freeTracer(Object* obj);
};

#endif

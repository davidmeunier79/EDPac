// TracableObject.h

#ifndef _TRACABLE_H
#define _TRACABLE_H

// Local Includes
#include "../Objets/Object.h"

#include "../Handlers/Tracer.h"

// STL Includes
#include <string>
#include <fstream>
using namespace std;

/******************************************************************************************************************************************/
/****************************************************** Classe TracableObject *************************************************************/
/******************************************************************************************************************************************/

class Tracable
{
protected:

	Tracer* tracer;
public:

	Tracable();
	~Tracable();
	
	virtual void initTracer();
	virtual void trace(Object* obj);
};

#endif

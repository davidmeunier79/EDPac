// Stater.h

#ifndef _STATER_H
#define _STATER_H

// Local Includes
#include "../DefineStater.h"

#include "../Objets/Object.h"
#include "../Handlers/Handler.h"

class Stater;
#include "../Objets/IndexedObject.h"

// STL Includes
#include <string>
#include <fstream>
using namespace std;

/******************************************************************************************************************************************/
/********************************************************** Classe Stater ***************************************************************/
/******************************************************************************************************************************************/

class Stater : public Handler
{
	virtual void openTracer();
	virtual void closeTracer();

	virtual void openGrapher();
	virtual void runGrapher();
	virtual void closeGrapher();

protected:

	friend class IndexedObject;
public:
	Stater();
	Stater(IndexedObject* io);
	virtual ~Stater();

	virtual void stat(Object* obj);
	virtual void graph();

	virtual void openStater();
	virtual void closeStater();
};

#endif

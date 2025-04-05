// Statable.h

#ifndef _STATABLE_H
#define _STATABLE_H

// Local Includes
#include "../Objets/Object.h"

#include "../Handlers/Stater.h"

// STL Includes
#include <string>
#include <fstream>
using namespace std;

/******************************************************************************************************************************************/
/******************************************************** Classe Statable *****************************************************************/
/******************************************************************************************************************************************/

class Statable
{
protected:

	Stater* stater;
public:
	Statable();
	~Statable();
	
	virtual void initStater();
	virtual void freeStater();
	
	virtual void stat(Object* obj);
};

#endif

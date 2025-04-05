// Loadable.h

#ifndef _LOADABLE_H
#define _LOADABLE_H

// Local Includes
#include "../Objets/Object.h"

class Loadable;
#include "../Handlers/Loader.h"

// STL Includes
#include <string>
#include <fstream>
using namespace std;

/******************************************************************************************************************************************/
/********************************************************* Classe Loadable  ****************************************************************/
/******************************************************************************************************************************************/

class Loadable
{
protected:

	Loader* loader;
public:

	Loadable();
	~Loadable();
	
	virtual void initLoader();
	virtual void load(Object* obj);
};

#endif

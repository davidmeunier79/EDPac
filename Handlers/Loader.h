// Loader.h

#ifndef _LOADER_H
#define _LOADER_H

// Local Includes
#include "../Objets/Object.h"

class Loader;
#include "../Interfaces/Loadable.h"

// STL Includes
#include <string>
#include <sstream>
using namespace std;

/******************************************************************************************************************************************/
/********************************************************** Classe Loader ******************************************************************/
/******************************************************************************************************************************************/

class Loader : public Object
{
public:
	Loader();
	virtual ~Loader();
	
	virtual void load(Object*);
};

#endif

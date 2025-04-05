// Savable.h

#ifndef _SAVABLE_H
#define _SAVABLE_H

// Local Includes
#include "../Objets/Object.h"

class Savable;
#include "../Handlers/Saver.h"

// STL Includes
#include <string>
#include <fstream>
using namespace std;

/******************************************************************************************************************************************/
/********************************************************* Classe Savable  ****************************************************************/
/******************************************************************************************************************************************/

class Savable
{
protected:

	Saver* saver;
public:
	Savable();
	~Savable();
	
	virtual void initSaver();
	virtual void save(Object* obj);
};

#endif

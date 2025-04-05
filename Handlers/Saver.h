// Saver.h

#ifndef _SAVER_H
#define _SAVER_H

// Local Includes
#include "../Objets/Object.h"

class Saver;
#include "../Interfaces/Savable.h"

// STL Includes
#include <string>
#include <sstream>
using namespace std;

/******************************************************************************************************************************************/
/********************************************************** Classe Saver ******************************************************************/
/******************************************************************************************************************************************/

class Saver : public Object
{
public:
	Saver();
	virtual ~Saver();
};

#endif

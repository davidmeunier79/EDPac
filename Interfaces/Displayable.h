// Displayable.h

#ifndef _DISPLAYABLE_H
#define _DISPLAYABLE_H

// STL Includes
#include <iostream>
using namespace std;

// Local Includes
#include "../Objets/Object.h"

class Displayable;
#include "../Handlers/Displayer.h"


/******************************************************************************************************************************************/
/*********************************************************** Classe Displayable *********************************************************/
/******************************************************************************************************************************************/

class Displayable
{
protected:
	Displayer* displayer;

public:
	Displayable();
	~Displayable();
	
	void display();

};

#endif

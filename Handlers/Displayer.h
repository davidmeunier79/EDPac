// Displayer.h

#ifndef _DISPLAYER_H
#define _DISPLAYER_H

// STL Includes
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Local Includes
#include "Handler.h"
#include "../Fenetre/Fenetre.h"

class Displayer;
#include "../Interfaces/Displayable.h"

/******************************************************************************************************************************************/
/********************************************************* Classe Displayer ***************************************************************/
/******************************************************************************************************************************************/

class Displayer : public Handler
{
public:
	Displayer();
	virtual ~Displayer();

	virtual void display(Displayable* disp);
	
	virtual void flushDisplay();
	virtual void cleanDisplay();
	
};

#endif

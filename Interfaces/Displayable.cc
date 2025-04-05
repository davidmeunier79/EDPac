// Displayable.cc

// Local Includes
#include "Displayable.h"

/****************************************************************************************************************************************/
/*************************************************** Methodes de la classe Displayable **************************************************/
/****************************************************************************************************************************************/

Displayable::Displayable()
{
	displayer=0;
}

Displayable::~Displayable()
{
	displayer=0;
}

void Displayable::display()
{
	if (displayer)
	{
		displayer->display(this);
	}
}

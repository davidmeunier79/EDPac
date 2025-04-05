// Displayer.cc

// Local Includes
#include "Displayer.h"

/****************************************************************************************************************************************/
/**************************************************** Methodes de la classe Displayer ***************************************************/
/****************************************************************************************************************************************/

Displayer::Displayer()
{
}

Displayer::~Displayer()
{
}

void Displayer::display(Displayable* disp)
{
	cerr << "Warning, accessing virtual Displayer::display method" << endl;	
}

void Displayer::flushDisplay()
{
	cerr << "Warning, accessing virtual Displayer::flushDisplay method" << endl;	
}

void Displayer::cleanDisplay()
{
	cerr << "Warning, accessing virtual Displayer::cleanDisplay method" << endl;	
}

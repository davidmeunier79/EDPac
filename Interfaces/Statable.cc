// Statable.cc

// Local Includes
#include "Statable.h"

/****************************************************************************************************************************************/
/**************************************************** Methodes de la classe Statable ****************************************************/
/****************************************************************************************************************************************/
Statable::Statable()
{
	stater=0;
}

Statable::~Statable()
{
	stater=0;
}

void Statable::initStater()
{
	cerr << "Warning, accessing Statable::initStater virtual method" << endl;
}

void Statable::freeStater()
{
	cerr << "Warning, accessing Statable::freeStater virtual method" << endl;
}

void Statable::stat(Object* obj)
{
	cerr << "Warning, accessing Statable::stat virtual method" << endl;
}


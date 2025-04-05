// Loadable.cc

// Local Includes
#include "Loadable.h"

/****************************************************************************************************************************************/
/************************************************* Methodes de la classe Loadable ********************************************************/
/****************************************************************************************************************************************/
Loadable::Loadable()
{
	loader=0;
}

Loadable::~Loadable()
{
	loader=0;
}

void Loadable::initLoader()
{
	cerr << "Warning, accessing Loadable::initLoader virtual method" << endl;
}

void Loadable::load(Object* obj)
{
	cerr << "Warning, accessing Loadable::save virtual method" << endl;
}


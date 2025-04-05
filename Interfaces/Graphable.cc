// Graphable.cc

// Local Includes
#include "Graphable.h"

/****************************************************************************************************************************************/
/**************************************************** Methodes de la classe Graphable ***************************************************/
/****************************************************************************************************************************************/

Graphable::Graphable()
{
	grapher=0;
}

Graphable::~Graphable()
{
	grapher=0;
}

void Graphable::graph(Object* obj)
{
	cerr << "Warning, accessing GraphableObject::graph virtual method" << endl;
}

void Graphable::initGrapher()
{
	cerr << "Warning, accessing GraphableObject::initGrapher virtual method" << endl;
}

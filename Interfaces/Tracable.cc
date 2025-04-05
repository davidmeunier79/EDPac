// Tracable.cc

// Local Includes
#include "Tracable.h"

/****************************************************************************************************************************************/
/************************************************* Methodes de la classe Tracable *************************************************/
/****************************************************************************************************************************************/
Tracable::Tracable()
{
	tracer = 0;
}

Tracable::~Tracable()
{
	tracer = 0;
}

void Tracable::initTracer()
{
	cerr << "Warning, accessing Tracable::initTracer virtual method" << endl;
}

void Tracable::trace(Object* obj)
{
	cerr << "Warning, accessing Tracable::trace virtual method" << endl;
}


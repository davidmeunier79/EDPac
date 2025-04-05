// Tracer.cc

// Local Includes
#include "Tracer.h"

/****************************************************************************************************************************************/
/***************************************************** Methodes de la classe Tracer *****************************************************/
/****************************************************************************************************************************************/

Tracer::Tracer()
{
}

Tracer::~Tracer()
{
}

Tracer::Tracer(IndexedObject* io)
{
	setIndex(io->getIndex());
#ifdef _TEST_STAT
	cout << "index: " << index;
#endif
}

void Tracer::trace(Object* obj)
{
	cerr << "Warning, accessing Tracer::trace virtual method" << endl;
}

void Tracer::initTracer(Object* obj)
{
	cerr << "Warning, accessing Tracer::initTracer virtual method" << endl;
}

void Tracer::freeTracer(Object* obj)
{
	cerr << "Warning, accessing Tracer::freeTracer virtual method" << endl;
}

// Savable.cc

// Local Includes
#include "Savable.h"

/****************************************************************************************************************************************/
/************************************************* Methodes de la classe Savable ********************************************************/
/****************************************************************************************************************************************/
Savable::Savable()
{
	saver=0;
}

Savable::~Savable()
{
	saver=0;
}

void Savable::initSaver()
{
	cerr << "Warning, accessing Tracable::initTracer virtual method" << endl;
}

void Savable::save(Object* obj)
{
	cerr << "Warning, accessing Savable::save virtual method" << endl;
}


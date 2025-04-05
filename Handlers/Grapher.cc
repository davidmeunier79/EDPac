// Grapher.cc

// Local Includes
#include "Grapher.h"

/****************************************************************************************************************************************/
/**************************************************** Methodes de la classe Grapher *****************************************************/
/****************************************************************************************************************************************/

Grapher::Grapher()
{
}

Grapher::Grapher(IndexedObject* io)
{
	setIndex(io->getIndex());
#ifdef _TEST_STAT
	cout << "index: " << index;
#endif
}

Grapher::~Grapher()
{
}

/*
void Grapher::openGrapher()
{
	cerr << "Warning, accessing Grapher::openGrapher virtual method" << endl;
}

void Grapher::runGrapher()
{
	cerr << "Warning, accessing Grapher::runGrapher virtual method" << endl;
}

void Grapher::closeGrapher()
{
	cerr << "Warning, accessing Grapher::closeGrapher virtual method" << endl;
}
*/
void Grapher::graph(Object* obj)
{
	cerr << "Warning, accessing Grapher::graph virtual method" << endl;
}

void Grapher::initGrapher(Object* obj)
{
	cerr << "Warning, accessing Grapher::initGrapher virtual method" << endl;
}

void Grapher::freeGrapher(Object* obj)
{
	cerr << "Warning, accessing Grapher::freeGrapher virtual method" << endl;
}


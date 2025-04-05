// Stater.cc

// Local Includes
#include "Stater.h"

/****************************************************************************************************************************************/
/***************************************************** Methodes de la classe Stater *****************************************************/
/****************************************************************************************************************************************/

Stater::Stater()
{
}

Stater::Stater(IndexedObject* io): Handler(io)
{
}

Stater::~Stater()
{
}


void Stater::openStater()
{
	openTracer();

}

void Stater::closeStater()
{
	closeTracer();
	openGrapher();

	graph();

	closeGrapher();
	runGrapher();
}

void Stater::stat(Object* obj)
{
	cerr << "Warning, accessing Stater::stat virtual method" << endl;
}

void Stater::openTracer()
{
	cerr << "Warning, accessing Stater::openTracer virtual method" << endl;
}

void Stater::closeTracer()
{
	cerr << "Warning, accessing Stater::closeTracer virtual method" << endl;
}
		
void Stater::openGrapher()
{
	cerr << "Warning, accessing Stater::openGrapher virtual method" << endl;
}

void Stater::runGrapher()
{
	cerr << "Warning, accessing Stater::runGrapher virtual method" << endl;
}

void Stater::closeGrapher()
{
	cerr << "Warning, accessing Stater::closeGrapher virtual method" << endl;
}

void Stater::graph()
{
	cerr << "Warning, accessing Stater::graph virtual method" << endl;
}

// Handler.cc

// Local Includes
#include "Handler.h"

/****************************************************************************************************************************************/
/**************************************************** Methodes de la classe Handler *****************************************************/
/****************************************************************************************************************************************/

Handler::Handler()
{
}

Handler::Handler(IndexedObject* io)
{
	setIndex(io->getIndex());
}
Handler::~Handler()
{
}

void Handler::handle(Object* obj)
{
	cerr << "Warning, accessing Handler::graph virtual method" << endl;
}

ostream& operator<<(ostream& o, Handler* h)
{
	o << "_Generation" << h->getEvoIndex();
	o << "_Pacman" << h->getTopoIndex();
	o << "_Run" << h->getEvalIndex();
	o << "_Test" << h->getTestIndex();
	
	return o;
}

// Projection.cc

// Local Includes
#include "Projection.h"

/****************************************************************************************************************************************/
/***************************************************** Methodes de la classe Projection ****************************************************/
/****************************************************************************************************************************************/

int Projection::nbProjections=0;

Projection::Projection():projectionNature(NO_NATURE)
{
	index=nbProjections;
	nbProjections++;

}

Projection::Projection(Assembly* newPreAssembly, Assembly* newPostAssembly):Link((Node*) newPreAssembly,(Node*) newPostAssembly)
{
	index = nbProjections;
	nbProjections++;

}

Projection::~Projection()
{
	nbProjections--;
	
#ifdef _TEST
	cout << "~Projection " << nbProjections<< endl;
#endif
}

int Projection::getProjectionNature()
{
	return projectionNature;
}

/****************************************************************************************************************************************/
/******************************************************* Methodes d'affichage ***********************************************************/
/****************************************************************************************************************************************/

std::ostream& operator<<(std::ostream& f, Projection& p)
{
	f << p.projectionNature << " " << (Link&) p;
	return f;
}


// EDInhibProjection.cc

// Local Includes
#include "EDInhibProjection.h"

/****************************************************************************************************************************************/
/*************************************************** Methodes de la classe EDInhibProjection ***********************************************/
/****************************************************************************************************************************************/

EDInhibProjection::EDInhibProjection()
{
	projectionNature = (projNature) INHIB;
}

EDInhibProjection::EDInhibProjection(Assembly* newPreAssembly, Assembly* newPostAssembly):
Projection((Assembly*) newPreAssembly,(Assembly*) newPostAssembly)
{
	projectionNature = (projNature) INHIB;
}

EDInhibProjection::~EDInhibProjection()
{
#ifdef _TEST
	cout << "~EDInhibProjection" << endl;
#endif
}

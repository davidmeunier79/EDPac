// EDExcitProjection.cc

// Local Includes
#include "EDExcitProjection.h"

/****************************************************************************************************************************************/
/*************************************************** Methodes de la classe EDExcitProjection ***********************************************/
/****************************************************************************************************************************************/

EDExcitProjection::EDExcitProjection()
{
	projectionNature = (projNature) EXCIT;
}

EDExcitProjection::EDExcitProjection(Assembly* newPreAssembly, Assembly* newPostAssembly):
Projection((Assembly*) newPreAssembly,(Assembly*) newPostAssembly)
{
	projectionNature = (projNature) EXCIT;
}

EDExcitProjection::~EDExcitProjection()
{
#ifdef _TEST
	cout << "~EDExcitProjection" << endl;
#endif
}

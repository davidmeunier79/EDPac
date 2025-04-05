// EDExcitProjection.h

#ifndef _ED_EXCIT_PROJECTION_H
#define _ED_EXCIT_PROJECTION_H

//#include "stdio.h"

// Local Includes
#include "../Define.h"
#include "../DefineEDNetwork.h"

#include "../Topology/Projection.h"
#include "../Topology/Assembly.h"

/******************************************************************************************************************************************/
/******************************************************** Classe EDExcitProjection ***********************************************************/
/******************************************************************************************************************************************/

class EDExcitProjection: public Projection
{
public:
	EDExcitProjection();
	EDExcitProjection(Assembly* newPreAssembly, Assembly* newPostAssembly);
	
	virtual ~EDExcitProjection();

};

#endif



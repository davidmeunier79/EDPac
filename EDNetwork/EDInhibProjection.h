// EDInhibProjection.h

#ifndef _ED_INHIB_PROJECTION_H
#define _ED_INHIB_PROJECTION_H

//#include "stdio.h"

// Local Includes
#include "../Define.h"
#include "../DefineEDNetwork.h"

#include "../Topology/Projection.h"
#include "../Topology/Assembly.h"

/******************************************************************************************************************************************/
/******************************************************** Classe EDInhibProjection ***********************************************************/
/******************************************************************************************************************************************/

class EDInhibProjection: public Projection
{
public:
	EDInhibProjection();
	EDInhibProjection(Assembly* preAssembly, Assembly* postAssembly);

	virtual ~EDInhibProjection();
};

#endif


// Projection.h

#ifndef _PROJECTION_H
#define _PROJECTION_H

//#include <stdio.h>

// STL Includes
#include <iostream>
//#include <fstream>

// Local Includes
#include "../Define.h"
#include "../DefineEDNetwork.h"

#include "../DirectedGraph/Link.h"

class Projection;
#include "Assembly.h"

using namespace std;

/******************************************************************************************************************************************/
/*********************************************************** Classe Projection ***************************************************************/
/******************************************************************************************************************************************/

class Projection : public Link
{
protected:

	// Nature de la projection (NO_NATURE,EXCIT,INHIB)
	int projectionNature;

public:
	Projection();
	Projection(Assembly* preAssembly,Assembly* postAssembly);
	
	virtual ~Projection();
	static int nbProjections;

	int getProjectionNature();

	friend std::ostream& operator<<(std::ostream&, Projection&);

};

#endif

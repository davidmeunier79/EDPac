// TopologyDisplayer.h

#ifndef _TOPOLOGY_DISPLAYER_H
#define _TOPOLOGY_DISPLAYER_H

//#include <stdio.h>

// STL Includes
#include <iostream>
using namespace std;

// Local Includes
#include "../Define.h"
#include "../DefineZoo.h"
#include "../DefineEDNetwork.h"
#include "../DefineGA.h"

#include "../DefineStater.h"


#include "../DefineWindow.h"
 
#include "../Handlers/Displayer.h"

#include "AssemblyDisplayer.h"

class TopologyDisplayer;
#include "../Topology/Topology.h"

/******************************************************************************************************************************************/
/********************************************************* Classe TopologyDisplayer *******************************************************/
/******************************************************************************************************************************************/

class TopologyDisplayer: public AssemblyDisplayer
{
public:

	TopologyDisplayer();
	~TopologyDisplayer();

	void flushDisplay();
	void cleanDisplay();
	
#ifdef _GRAPHICAL_DISPLAY_MODE
	void traceProjection(int preAssemblyIndex,int postAssemblyIndex, int projectionCode, const string & couleur);
	void traceProjection(Projection* curProj);
	void display(Topology* t);
	
	void saveTopologyDisplayer(int time);
#endif
};

#endif


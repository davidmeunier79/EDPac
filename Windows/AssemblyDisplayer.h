// AssemblyDisplayer.h

#ifndef _ASSEMBLY_DISPLAYER_H
#define _ASSEMBLY_DISPLAYER_H

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
#include "../Fenetre/Fenetre.h"

#include "NeuronDisplayer.h"

class AssemblyDisplayer;
#include "../Topology/Assembly.h"

/******************************************************************************************************************************************/
/********************************************************* Classe TopologyDisplayer *******************************************************/
/******************************************************************************************************************************************/

class AssemblyDisplayer: public NeuronDisplayer
{
public:

	AssemblyDisplayer();
	~AssemblyDisplayer();

#ifdef _GRAPHICAL_DISPLAY_MODE
	void display(Assembly* a);
#endif

};

#endif


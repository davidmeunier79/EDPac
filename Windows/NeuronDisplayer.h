// TopologyDisplayer.h

#ifndef _NEURON_DISPLAYER_H
#define _NEURON_DISPLAYER_H

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

class NeuronDisplayer;
#include "../Topology/Neuron.h"

/******************************************************************************************************************************************/
/********************************************************* Classe TopologyDisplayer *******************************************************/
/******************************************************************************************************************************************/

class NeuronDisplayer: public Displayer
{
protected:
	Fenetre* topoWindow;

public:

	NeuronDisplayer();
	~NeuronDisplayer();

#ifdef _GRAPHICAL_DISPLAY_MODE
	void display(Neuron* n);
#endif
};

#endif


// InputAssemblyStater.h

#ifndef _INPUT_ASSEMBLY_STATER_H
#define _INPUT_ASSEMBLY_STATER_H

// C includes
// Spécial itoa
#include <stdio.h>
#include <stdlib.h>

// STL Includes
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class InputAssemblyStater;
#include "../MPI/InputAssembly.h"

// Local Includes
#include "../Define.h"
#include "../DefineTracer.h"
#include "../DefineStater.h"

#include "../Handlers/Stater.h"

#include "NeuronStater.h"

/******************************************************************************************************************************************/
/*************************************************** Classe InputAssemblyStater ************************************************************/
/******************************************************************************************************************************************/

class InputAssemblyStater : public Stater
{	
	DataFile* inputSpikeFile;

	GnuplotFile* neuronInputGnuplotFile;

	virtual void openTracer();
	virtual void closeTracer();

	virtual void openGrapher();

	virtual void runGrapher();
	virtual void closeGrapher();

public:

	InputAssemblyStater();
	InputAssemblyStater(IndexedObject* io);

	virtual ~InputAssemblyStater();

#ifdef _ASSEMBLY_STAT_MODE
	void traceSpikeEmission(int neuronIndex, int timeOfFiring);
	virtual void graph();

	friend class InputAssembly;
#endif
};

#endif

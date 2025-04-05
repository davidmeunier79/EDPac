// OutputAssemblyStater.h

#ifndef _OUTPUT_ASSEMBLY_STATER_H
#define _OUTPUT_ASSEMBLY_STATER_H

// C includes
// Spécial itoa
#include <stdio.h>
#include <stdlib.h>

// STL Includes
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class OutputAssemblyStater;
#include "../MPI/OutputAssembly.h"

// Local Includes
#include "../Define.h"
#include "../DefineTracer.h"

#include "../Handlers/Stater.h"

#include "NeuronStater.h"

/******************************************************************************************************************************************/
/*************************************************** Classe OutputAssemblyStater ************************************************************/
/******************************************************************************************************************************************/

class OutputAssemblyStater : public Stater
{
	DataFile* outputSpikeFile;

	GnuplotFile* neuronOutputGnuplotFile;

	virtual void openTracer();
	virtual void closeTracer();

	virtual void openGrapher();

	virtual void runGrapher();
	virtual void closeGrapher();

public:

	OutputAssemblyStater();
	OutputAssemblyStater(IndexedObject* io);
	
	virtual ~OutputAssemblyStater();

 #ifdef _ASSEMBLY_STAT_MODE

	virtual void graph();
	void traceSpikeEmission(int neuronIndex, int timeOfFiring);
	friend class OutputAssembly;

#endif
};

#endif

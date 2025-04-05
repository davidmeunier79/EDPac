// InhibSynapseStater.h

#ifndef _SYNAPSE_STATER_H
#define _SYNAPSE_STATER_H

// C includes
// Spécial itoa
#include <stdio.h>
#include <stdlib.h>

// STL Includes
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Local Includes
#include "../Define.h"
#include "../DefineGA.h"
#include "../DefineZoo.h"

#include "../DefineStater.h"

#include "../Handlers/Stater.h"

#include "../Handlers/Accumulater.h"

class SynapseStater;
#include "../EDNetwork/EDSynapse.h"

/******************************************************************************************************************************************/
/****************************************************** Classe SynapseStater *************************************************************/
/******************************************************************************************************************************************/

class SynapseStater : public Stater
{
public:

	SynapseStater();
	SynapseStater(IndexedObject* io);
	
	virtual ~SynapseStater();
	
#ifdef _ASSEMBLY_STAT_MODE
	#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	virtual void statPreTemporalVariation(int tempVariation);
	virtual void statPostTemporalVariation(int tempVariation);

	virtual void flushCounters();
	
	virtual void stat(EDSynapse* eds);

	virtual Stater* getInhibSynapseStater();
	virtual Stater* getExcitSynapseStater();
	
	//virtual SynapseStater* getInhibSynapseStater();
	//virtual SynapseStater* getExcitSynapseStater();
	
	virtual void trace(int timeOfTrace);
	virtual void graph();
	#endif
#endif
};

#endif

// SynchroModule.h

#ifndef _SYNCHRO_MODULE_H
#define _SYNCHRO_MODULE_H

//#include <stdio.h>
#include <iostream>

// Local Includes
#include "../Define.h"
#include "../DefineEDNetwork.h"
#include "../DefineMPI.h"

#include "MPIModule.h"

/******************************************************************************************************************************************/
/*************************************************** Classe SynchroModule *****************************************************************/
/******************************************************************************************************************************************/

class SynchroModule : public MPIModule
{
protected:

	InputBuffer* synchroBuffer;
public:

	SynchroModule();
	SynchroModule(int newNbInputBuffers, int newNbOutputBuffers);
	~SynchroModule();

	void initSynchroBuffer();
	bool testSynchro();
	bool testBreak();
	virtual bool isReady();

	virtual void integrateSynchro();
	virtual void integrateVoidSynchro();
	virtual void integrateSkipSynchro();
	
};

#endif

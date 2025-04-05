// RootModule.h

#ifndef _ROOT_MODULE_H
#define _ROOT_MODULE_H

// Local Includes
#include "../Define.h"
#include "../DefineEDNetwork.h"
#include "../DefineMPI.h"

#include "MPIModule.h"

/******************************************************************************************************************************************/
/***************************************************** Classe RootModule *****************************************************************/
/******************************************************************************************************************************************/

class RootModule : public MPIModule
{
protected:
	// Buffer de synchronisation, sur COMM_WORLD
	//int nbSynchroBuffers;
	//OutputBuffer** synchroBuffers;
	OutputBuffer* synchroBuffer;

public:
	RootModule();
	RootModule(RootModule& rm);
	RootModule(int newNbInputBuffers, int newNbOutputBuffers);

	~RootModule();

	bool testSynchro();
	virtual bool isReady();
	//bool synchronize();

	void sendSynchro();
	void sendVoidSynchro();
	void sendSkipSynchro();
	
	void sendBreak();

	virtual void initSynchroBuffers();
};

#endif

// RootModule.cc

// Local Includes
#include "RootModule.h"

/****************************************************************************************************************************************/
/**************************************************** Methodes de la classe RootModule **************************************************/
/****************************************************************************************************************************************/

RootModule::RootModule()
{
}

RootModule::RootModule(int newNbInputBuffers, int newNbOutputBuffers): MPIModule(newNbInputBuffers, newNbOutputBuffers)
{
}

RootModule::RootModule(RootModule& rm): MPIModule((MPIModule&) rm)
{
#ifdef _MPI_TEST
	cout << "Accessing copy constructor RootModule" << endl;
#endif	
}

RootModule::~RootModule()
{
#ifdef _MPI_TEST
	cerr << "In ~RootModule" << endl;
#endif
	delete(synchroBuffer);
}

bool RootModule::testSynchro()
{

#ifdef _MPI_TEST
	cout << "*** Root Module " << MPI_GLOBALS.getMyId() << " *** synchronizing with COMM_WORLD synchro modules " << endl;
#endif
	MPI_GLOBALS.synchronize();

	return 1;
}

bool RootModule::isReady()
{
	return (synchroBuffer->getFlag() && !synchroBuffer->isActive());
}

void RootModule::sendSynchro()
{
	synchroBuffer->send();
}

void RootModule::sendVoidSynchro()
{
	cout << "Sending VOID synchroBuffer " << endl;
	synchroBuffer->sendVoid();
}

void RootModule::sendSkipSynchro()
{
	cout << "Sending SKIP synchroBuffer " << endl;
	synchroBuffer->sendSkip();
}

void RootModule::sendBreak()
{
	cout << "*** Module " << MPI_GLOBALS.getMyId() << " *** sending BREAK input to synchro module" << endl;
	synchroBuffer->sendBreak();

//#ifdef _MPI_TEST
	cout << "*** Root Module " << MPI_GLOBALS.getMyId() << " *** synchronizing with COMM_WORLD synchro modules " << endl;
//#endif
	testSynchro();

//#ifdef _MPI_TEST
	cout << "*** Root Module " << MPI_GLOBALS.getMyId() << " *** synchronizing with COMM_WORLD synchro modules " << endl;
//#endif
	testSynchro();
}

void RootModule::initSynchroBuffers()
{
	cerr << "Warninig, accessing virtual RootModule::initSynchroBuffers method" << endl;
}

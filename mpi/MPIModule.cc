// MPIModule.cc

// Local Includes
#include "MPIModule.h"

/****************************************************************************************************************************************/
/***************************************************** Methodes de la classe MPIModule **************************************************/
/****************************************************************************************************************************************/

MPIModule::MPIModule()
{
	nbInputBuffers=0;
	nbOutputBuffers=0;

	inputBuffers=0;
	outputBuffers=0;
}

MPIModule::MPIModule(MPIModule& MPIm)
{
#ifdef _MPI_TEST
	cout << "Accessing copy constructor MPIModule" << endl;
#endif	
	nbInputBuffers=MPIm.nbInputBuffers;
	nbOutputBuffers=MPIm.nbOutputBuffers;

	inputBuffers=(InputBuffer**) malloc(sizeof(InputBuffer*)*nbInputBuffers);
	outputBuffers=(OutputBuffer**) malloc(sizeof(OutputBuffer*)*nbOutputBuffers);
}

MPIModule::MPIModule(int newNbInputBuffers, int newNbOutputBuffers)
{
#ifdef _MPI_TEST
	cout << "Accessing constructor MPIModule(int,int)" << endl;
#endif	
	nbInputBuffers=newNbInputBuffers;
	nbOutputBuffers=newNbOutputBuffers;

	inputBuffers=(InputBuffer**) malloc(sizeof(InputBuffer*)*nbInputBuffers);
	outputBuffers=(OutputBuffer**) malloc(sizeof(OutputBuffer*)*nbOutputBuffers);
}

MPIModule::~MPIModule()
{
	free(inputBuffers);
	free(outputBuffers);
}

void MPIModule::initMPIModule()
{
#ifdef _MPI_TEST
	cout << "*** MPIModule " << MPI_GLOBALS.getMyId() << " *** synchronizing with COMM_WORLD synchro modules " << endl;
#endif
	MPI_GLOBALS.synchronize();

	for (int i=0;i<nbInputBuffers;i++)
	{
#ifdef _MPI_TEST
		cout << "*** Module " << MPI_GLOBALS.getMyId() << " *** inputBuffers[" << i << "], tag = " << inputBuffers[i]->getTag();
		cout << ", sourceMPIId = " << inputBuffers[i]->getSourceMPIId() << endl;
#endif
		inputBuffers[i]->initReceiveInput();
	}

	for (int i=0;i<nbOutputBuffers;i++)
	{
#ifdef _MPI_TEST
		cout << "*** Module " << MPI_GLOBALS.getMyId() << " *** inputBuffers[" << i << "], tag = " << outputBuffers[i]->getTag();
		cout << ", targetMPIId = " << outputBuffers[i]->getTargetMPIId() << endl;
#endif
		outputBuffers[i]->initSendOutput();
	}
}

void MPIModule::freeMPIModule()
{
/*
//#ifdef _MPI_TEST
	cout << "*** Module " << MPI_GLOBALS.getMyId() << " *** waiting all inputs" << endl;
//#endif
	waitAllInputs();
*/	
	for (int i=0;i<nbInputBuffers;i++)
	{
#ifdef _MPI_TEST
		cout << "*** Module " << MPI_GLOBALS.getMyId() << " *** inputBuffers[" << i << "], tag = " << inputBuffers[i]->getTag();
		cout << ", sourceMPIId = " << inputBuffers[i]->getSourceMPIId() << " ";
#endif
		inputBuffers[i]->freeRequest();
		//inputBuffers[i]->freeActive();
	}
/*
//#ifdef _MPI_TEST
	cout << "*** Module " << MPI_GLOBALS.getMyId() << " *** waiting all outputs" << endl;
//#endif
	waitAllOutputs();
*/	
	for (int i=0;i<nbOutputBuffers;i++)
	{
#ifdef _MPI_TEST
		cout << "*** Module " << MPI_GLOBALS.getMyId() << " *** outputBuffers[" << i << "], tag = " << outputBuffers[i]->getTag();
		cout << ", targetMPIId = " << outputBuffers[i]->getTargetMPIId() << " ";
#endif
		outputBuffers[i]->freeRequest();
		//inputBuffers[i]->freeActive();
	}
}

// Reception des inputs
bool MPIModule::testAnyInputs()
{
	bool any=GenericBuffer::testAny((GenericBuffer**)inputBuffers,nbInputBuffers);
	return any;
}
/*
bool MPIModule::testAllInputs()
{
	bool any=GenericBuffer::testAll((GenericBuffer**)inputBuffers,nbInputBuffers);
	return any;
}
*/
void MPIModule::testAllInputs()
{
	for (int i=0;i<nbInputBuffers;i++)
	{
		if (inputBuffers[i]->getFlag())
		{
			inputBuffers[i]->receiveInput();
		}
	}
	/*
	bool any=GenericBuffer::testAll((GenericBuffer**)inputBuffers,nbInputBuffers);
	return any;
	*/
}

int MPIModule::testSomeInputs(int* recus)
{
	int retour=GenericBuffer::testSome((GenericBuffer**)inputBuffers,nbInputBuffers,recus);
	return retour;
}

int MPIModule::waitSomeInputs(int* recus)
{
	int retour=GenericBuffer::waitSome((GenericBuffer**)inputBuffers,nbInputBuffers,recus);
	return retour;
}

bool MPIModule::waitAllInputs()
{
	int retour=GenericBuffer::waitAll((GenericBuffer**)inputBuffers,nbInputBuffers);
	return retour;
}

// Envoi des outputs
void MPIModule::testAllOutputs()
{
	for (int i=0;i<nbOutputBuffers;i++)
	{
		if (outputBuffers[i]->testActiveRequete())
		{
			if(outputBuffers[i]->getFlag())
			{
				outputBuffers[i]->setFlag(1);
				//outputBuffers[i]->freeBuffer();
#ifdef _MPI_TEST
				cout << "*** Module " << MPI_GLOBALS.getMyId() << " *** Output buffer " << i << " is active and free" << endl;
#endif
			}
			else
			{
#ifdef _MPI_TEST
				cout << "*** Module " << MPI_GLOBALS.getMyId() << " *** Output buffer " << i << " is active but not free" << endl;
#endif
			}
		}
		else
		{
			outputBuffers[i]->setFlag(1);
			//outputBuffers[i]->freeBuffer();
#ifdef _MPI_TEST
			cout << "*** Module " << MPI_GLOBALS.getMyId() << " *** Output buffer " << i << " is free" << endl;
#endif
		}
	}
}

int MPIModule::testSomeOutputs(int* sended)
{
	int retour=GenericBuffer::testSome((GenericBuffer**)outputBuffers,nbOutputBuffers,sended);
	return retour;
}

int MPIModule::waitSomeOutputs(int* sended)
{
	int retour=GenericBuffer::waitSome((GenericBuffer**)outputBuffers,nbOutputBuffers,sended);
	return retour;
}

bool MPIModule::waitAllOutputs()
{
	int retour=GenericBuffer::waitAll((GenericBuffer**)outputBuffers,nbOutputBuffers);
	return retour;
}
/*
bool MPIModule::testAllOutputs()
{
	int retour=GenericBuffer::testAll((GenericBuffer**)outputBuffers,nbOutputBuffers);
	return retour;
}
*/
/*
void MPIModule::initSynchroBuffer(int newSize, int newSourceMPIId, int newTargetMPIId)
{
#ifdef _MPI_TEST
	cout << "*** Module " << MPI_GLOBALS.getMyId() << " *** Initing synchro buffer" << endl;
#endif
	synchro = (SynchroBuffer*) new SynchroBuffer(newSize,newSourceMPIId,newTargetMPIId);
}

bool MPIModule::synchronize()
{
	MPI_GLOBALS.synchronize();
	return 1;
}

bool MPIModule::testSynchro()
{
	MPI_GLOBALS.synchronize();
	return (!synchro->getFlag());
}

void MPIModule::receiveSynchro()
{
#ifdef _MPI_TEST
	cout << "*** Module " << MPI_GLOBALS.getMyId() << " *** receiving synchro message from source process" << endl;
#endif
	synchro->receiveInput();
}

void MPIModule::sendSynchro()
{
#ifdef _MPI_TEST
	cout << "*** Module " << MPI_GLOBALS.getMyId() << " *** sending synchro message to target process" << endl;
#endif
	synchro->sendOutput();
}

void MPIModule::sendVoidSynchro()
{
#ifdef _MPI_TEST
	cout << "*** Module " << MPI_GLOBALS.getMyId() << " *** sending VOID synchro message to target process" << endl;
#endif
	synchro->sendVoidOutput();
}
*/

bool MPIModule::isReady()
{
	cout << "Warning: accessing virtual method MPIModule::isReady" << endl;
}

void MPIModule::initInputBuffers()
{
	cout << "Warning: accessing virtual method MPIModule::initInputBuffers" << endl;
}

void MPIModule::initOutputBuffers()
{
	cout << "Warning: accessing virtual method MPIModule::initOutputBuffers" << endl;
}

void MPIModule::receiveInputs()
{
	cout << "Warning: accessing virtual method MPIModule::receiveInputs" << endl;
}

void MPIModule::sendOutputs()
{
	cout << "Warning: accessing virtual method MPIModule::sendOutputs" << endl;
}

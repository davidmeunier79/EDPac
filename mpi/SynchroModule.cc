// SynchroModule.cc

// Local Includes
#include "SynchroModule.h"

/****************************************************************************************************************************************/
/*************************************************** Methodes de la classe SynchroModule ************************************************/
/****************************************************************************************************************************************/

SynchroModule::SynchroModule()
{
}

SynchroModule::SynchroModule(int newNbInputBuffers, int newNbOutputBuffers):MPIModule(newNbInputBuffers,newNbOutputBuffers)
{
}

SynchroModule::~SynchroModule()
{
}

bool SynchroModule::testSynchro()
{

#ifdef _MPI_TEST
	cout << "*** Synchro Module " << MPI_GLOBALS.getMyId() << " *** synchronizing with COMM_WORLD root module " << endl;
#endif
	MPI_GLOBALS.synchronize();

	return isReady();
}

bool SynchroModule::testBreak()
{
#ifdef _MPI_TEST
	cout << "*** Module " << MPI_GLOBALS.getMyId() << " *** in testBreak()" << endl;
#endif
	if (synchroBuffer->isActive())
	{
		if (synchroBuffer->getFlag())
		{
			switch(synchroBuffer->getCount())
			{
				case 1:
				{

#ifdef _MPI_TEST
					cout << "*** Module " << MPI_GLOBALS.getMyId() << " *** integrating input of size " << synchroBuffer->getCount() << endl;
#endif
					switch((MPI_Message) (*synchroBuffer)[0])
					{
						case BREAK:
						{

#ifdef _MPI_TEST
							cout << "*** Module " << MPI_GLOBALS.getMyId() << " *** integrating BREAK input" << endl;
#endif
							return 1;
							break;
						}
						case VOID:
						{

#ifdef _MPI_TEST
							cout << "*** Module " << MPI_GLOBALS.getMyId() << " *** integrating VOID input" << endl;
#endif
							integrateVoidSynchro();
							synchroBuffer->freeActive();
							return 0;
							break;
						}
						case SKIP:
						{

#ifdef _MPI_TEST
							cout << "*** Module " << MPI_GLOBALS.getMyId() << " *** integrating SKIP input" << endl;
#endif
							integrateSkipSynchro();
							synchroBuffer->freeActive();
							return 0;
							break;
						}
						default :
						{

							cerr << "Warning, wrong MPI message " << (*synchroBuffer)[0] << endl;
							break;
						}
					}
					break;
				}
				default :
				{
#ifdef _MPI_TEST
					cout << "*** Module " << MPI_GLOBALS.getMyId() << " *** integrating input of size " << synchroBuffer->getCount() << endl;
#endif
					integrateSynchro();
					synchroBuffer->freeActive();
					return 0;
					break;
				}
			}
		}
		else
		{
			cerr << "Warning, synchroBuffer is not ready" << endl;
		}
	}
	else
	{
		cerr << "Warning, synchroBuffer is not active" << endl;
	}

	return 0;
}

bool SynchroModule::isReady()
{
	if (!synchroBuffer->getActive())
	{
		synchroBuffer->receive();
	}
	else
	{
		if (synchroBuffer->getFlag())
		{
			return 1;
		}
	}

	return 0;
}
	
void SynchroModule::initSynchroBuffer()
{
	cerr << "Warning, accessing virtual SynchroModule::initSynchroBuffer method" << endl;
}

void SynchroModule::integrateSynchro()
{
	cerr << "Warning, accessing virtual SynchroModule::integrateSynchro method" << endl;
}

void SynchroModule::integrateVoidSynchro()
{
	cerr << "Warning, accessing virtual SynchroModule::integrateVoidSynchro method" << endl;
}

void SynchroModule::integrateSkipSynchro()
{
	cerr << "Warning, accessing virtual SynchroModule::integrateSkipSynchro method" << endl;
}




// run.cc

#include <sys/types.h>
#include <unistd.h>

// Local Includes
#include "MPI/MpiGlobals.h"

#include "Define.h"
#include "DefineMPI.h"
#include "DefineEDNetwork.h"

#include "Zoo/TestLab.h"

#include "GeneticAlgorithm/EvoNetwork.h"

int main(int argc, char ** argv)
{
#ifdef _CLEAR_DATA_DIRECTORY_MODE
	cout << "Deleting data directory" << endl;
	FileObject::deleteDataFiles();
#endif

	// Calcul on-line en fonction des perceptions issues du zoo
	MPI_GLOBALS.initialise(argc,argv);
 
  	if(MPI_GLOBALS.getMyId()==GRAPHICAL_ENVIRONNEMENT_MPI_ID)
    	{
		cout<<"processus n° "<<MPI_GLOBALS.getMyId() <<" de pid :"<<getpid()<<" gere le zoo"<<endl;
		TestLab newLab;
		#ifdef _RUN_MODE
		newLab.runEvo();
		#endif
  	}
  	else
    	{
      		switch(MPI_GLOBALS.getMyId())
		{
			case EVO_NETWORK_MPI_ID :
	  		{
				cout<< "processus n° " << MPI_GLOBALS.getMyId() << " de pid :" << getpid() << " gere un EvoNetwork " << endl;
				EvoNetwork newEvoNN;
				newEvoNN.run();
				break;
			}
			/*
			case MOTOR_MODULE_MPI_ID :
	  		{
	    			cout << "processus n° " << MPI_GLOBALS.getMyId() << " de pid :" << getpid() << " gere un moteur" << endl;
	    			Moteur moteur;
	    			moteur.mainMoteur();
	    			break;
	  		}
			*/
		}
    	}
	
	//cout << "processus n° " << MPI_GLOBALS.getMyId() << " de pid :" << getpid() << " synchronizing" << endl;
	//MPI_GLOBALS.synchronize();
	
  	MPI_GLOBALS.finalise();
  
 	return 0;
}

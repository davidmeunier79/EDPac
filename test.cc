// test.cc

#include <sys/types.h>
#include <unistd.h>

// Local Includes
#include "MPI/MpiGlobals.h"

#include "Define.h"
#include "DefineMPI.h"
#include "DefineEDNetwork.h"

#include "Zoo/TestLab.h"
//#include "Zoo/Zoo.h"

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
		newLab.testEvo();
  	}
  	else
    	{
      		switch(MPI_GLOBALS.getMyId())
		{
			case EVO_NETWORK_MPI_ID :
	  		{
				cout<< "processus n° " << MPI_GLOBALS.getMyId() << " de pid :" << getpid() << " gere un EvoNetwork " << endl;
				EvoNetwork newEvoNN;
				//newEvoNN.run();
				newEvoNN.test();
				break;
			}
		}
    	}
  	MPI_GLOBALS.finalise();
  
 	return 0;
}

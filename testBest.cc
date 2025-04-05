// test.cc

#include <sys/types.h>
#include <unistd.h>

// Local Includes
#include "MPI/MpiGlobals.h"

#include "Define.h"
#include "DefineMPI.h"
#include "DefineEDNetwork.h"

#include "Zoo/TestLab.h"
//#include "Zoo/Moteur.h"
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
		TestLab newZoo;
		#ifdef _TEST_BEST_POPULATION_MODE
		newZoo.testBestChromos();
		#else
			#ifdef _TEST_RANDOM_POPULATION_MODE
		newZoo.testRandomChromos();
			#else
		cerr << " Warning, _TEST_BEST_POPULATION_MODE or _TEST_RANDOM_POPLATION_MODE should be defined for testBest" << endl;
			#endif
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

				#if (defined(_TEST_BEST_POPULATION_MODE) || defined(_TEST_RANDOM_POPULATION_MODE))
					#ifdef _TEST_MODE
						//#ifdef _PHASE_TEST_MODE
				newEvoNN.testBest();
						//#else
				//newEvoNN.test();
						//#endif
					#else
						#ifdef _RUN_MODE
							#ifdef _PHASE_TEST_MODE
				newEvoNN.testBest();
							#else
				newEvoNN.run();
							#endif
						#else
				newEvoNN.testBest();
						#endif
					#endif
				#endif

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
  	MPI_GLOBALS.finalise();
  
 	return 0;
}

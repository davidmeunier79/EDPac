// MpiGlobals.h

#ifndef _MPI_GLOBALS_H
#define _MPI_GLOBALS_H

// NEW
//#include <mpi++.h>
// Special lam 7.0
#include <mpi.h>
#include <iostream>
#include <string>
using namespace std;
using namespace MPI;


#include "../Define.h"
#include "../DefineMPI.h"

#define MPI_GLOBALS (MpiGlobals::getInstance())

// MpiGlobals est un singleon qui contient les variables globales necessaires a MPI
// utiliser  MPI_GLOBALS ou MpiGlobals::getInstance() pour acceder au singleton
class MpiGlobals
{
private :
	// pointeur sur le singleton
	static MpiGlobals *leSingleton;
	// constructeur et destructeur prives pour maitriser le nombre d'instances
	MpiGlobals();
	~MpiGlobals();
	// variables globales necessaires a MPI
	double startWTime, endWTime;
	int nameLen, numProcs, myId;
	char processorName[MPI_MAX_PROCESSOR_NAME];
	char name[50];
	int len;


public :

	void synchronize();
	void abort();

	// fonction permetant d'acceder au singleton
	static MpiGlobals & getInstance();

	// fonctions permettant d'initialiser e de finaliser le protocole MPI
	bool initialise(int &argc,char ** &argv);
	bool finalise();

	// accesseurs en lecture aux variables
	double getStartWTime();
	double getEndWTime();
	int getNameLen();
	int getNumProc();
	int getMyId();
	string getProcessorName();
};

#endif


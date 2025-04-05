// GenericBuffer.h

#ifndef _GENERIC_BUFFER_H
#define _GENERIC_BUFFER_H

//#include <mpi++.h>
// Special lam 7.0
#include <mpi.h>
#include <iostream>
using namespace std;
using namespace MPI;

// Local Includes
#include "../Define.h"
#include "../DefineMPI.h"

#include "MpiGlobals.h"

// cette classe factorise les attributs des buffers
class GenericBuffer
{
protected :
	bool active;
	int flag;
	
	int tag;
	
	MPI::Status status;
	//MPI::Request request;
	MPI::Prequest request;
public :

	GenericBuffer(int tag=DEFAULT_TAG);

	virtual bool isActive();
	void setActive();
	bool getActive();
	void freeActive();

	void initRequest();
	void freeRequest();

	// Gestion du flag
	bool getFlag();
	void setFlag(bool flag);
	void wait();

	// Lancement de la Prequest
	void startRequest();

	void setTag(int tag=DEFAULT_TAG);
	int getTag();

	bool testActiveRequete();

	// attend qu'une des requetes soit verifiee, renvoie l'indice de celle-ci
	static int waitAny(GenericBuffer ** listBuffers,int sizeList);
	static int waitSome(GenericBuffer ** listBuffers,int sizeList, int* recus);
	static bool waitAll(GenericBuffer ** listBuffers,int sizeList);
	static bool testAll(GenericBuffer ** listBuffers,int sizeList);

	static bool testAny(GenericBuffer ** listBuffers,int sizeList);
	static int testSome(GenericBuffer ** listBuffers,int sizeList, int* recus);

};

#endif


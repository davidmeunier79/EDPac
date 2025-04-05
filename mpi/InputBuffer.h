// InputBuffer.h

#ifndef _INPUT_BUFFER_H
#define _INPUT_BUFFER_H

//#include <stdio.h>
#include <mpi.h>
#include <iostream>
using namespace MPI;

// Local Includes
#include "../MPI/Buffer.h"

#include "../Define.h"

/******************************************************************************************************************************************/
/***************************************************** Classe InputBuffer *****************************************************************/
/******************************************************************************************************************************************/

class InputBuffer : public MPIBuffer
{
	int sourceMPIId;
	
public:
	InputBuffer();
	InputBuffer(InputBuffer& iBuf);
	InputBuffer(int size, int tag, int sourceMPIId);
	
	virtual ~InputBuffer();
	
	void setSourceMPIId(int newSourceMPIId);
	int getSourceMPIId();

	void initReceiveInput();
	bool testInput();
	
	bool isActive();
	
	void receiveInput();
	void receive();
	//void receiveBInput();

	//InputBuffer& operator=(const InputBuffer&);
};

#endif

// OutputBuffer.h

#ifndef _OUTPUT_BUFFER_H
#define _OUTPUT_BUFFER_H

//#include <stdio.h>
#include <vector>
using namespace std;

// Local Includes
#include "../MPI/Buffer.h"

#include "../Define.h"

/******************************************************************************************************************************************/
/***************************************************** Classe OutputBuffer *****************************************************************/
/******************************************************************************************************************************************/

class OutputBuffer : public MPIBuffer
{
	int targetMPIId;


public:
	OutputBuffer();
	OutputBuffer(OutputBuffer& iBuf);
	OutputBuffer(int newSize, int newTag, int newtargetMPIId);

	virtual ~OutputBuffer();

	bool isActive();

	void setTargetMPIId(int newTargetMPIId);
	int getTargetMPIId();

	void initSendOutput();
	void sendOutput();
	
	void send();
	void sendVoid();

	void integrateOutput(vector<double>&);

	void sendBreak();
	void sendSkip();

	//OutputBuffer& operator=(const OutputBuffer&);
};

#endif

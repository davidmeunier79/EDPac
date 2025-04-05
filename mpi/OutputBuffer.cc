// OutputBuffer.cc

// Local Includes
#include "OutputBuffer.h"

/****************************************************************************************************************************************/
/**************************************************** Methodes de la classe OutputBuffer *************************************************/
/****************************************************************************************************************************************/

OutputBuffer::OutputBuffer()
{
}

OutputBuffer::OutputBuffer(int newSize, int newTag, int newtargetMPIId): MPIBuffer(newSize,newTag), targetMPIId(newtargetMPIId)
{
}

OutputBuffer::OutputBuffer(OutputBuffer& oBuf): MPIBuffer(oBuf.size,oBuf.tag),targetMPIId(oBuf.targetMPIId)
{
	cout << "OutputBuffer message: " << message << endl;
#ifdef _MPI_TEST
	cout << "Initing active bool" << endl;
#endif
	active=0;
}

OutputBuffer::~OutputBuffer()
{
}

void OutputBuffer::setTargetMPIId(int newTargetMPIId)
{
	targetMPIId=newTargetMPIId;
}

int OutputBuffer::getTargetMPIId()
{
	return targetMPIId;
}

void OutputBuffer::initSendOutput()
{
	initSend(targetMPIId);
}

bool OutputBuffer::isActive()
{
	return active;
}

void OutputBuffer::sendOutput()
{
	if (active && getFlag())
	{
		startRequest();
		active=0;
	}
	else
	{
		wait();
#ifdef _MPI_TEST
		cout << "Output Buffer " << getTag() << " " << MPI_GLOBALS.getMyId() << " waiting for send output" << endl;
#endif
	}
}

void OutputBuffer::send()
{
	sendMessage(targetMPIId);
}

void OutputBuffer::sendVoid()
{
	sendVoidMessage(targetMPIId);
}

void OutputBuffer::integrateOutput(vector<double>& objet)
{
	if (!active && getFlag())
	{
		if (objet.size()==size)
		{
			setMessage(objet);
			active=1;
		}
		else
		{
			cerr << "Warning, incompatible size of object:" << objet.size() << ", should be " << size << endl;
		}
	}
	else
	{
		cerr << "Warning, output buffer " << getTag() << " " << MPI_GLOBALS.getMyId() << " is not ready to integrate " << endl;
	}
}
	
void OutputBuffer::sendBreak()
{
	sendBreakMessage(targetMPIId);
}

void OutputBuffer::sendSkip()
{
	sendSkipMessage(targetMPIId);
}
/*
OutputBuffer& OutputBuffer::operator=(const OutputBuffer& out)
{
	tag=out.tag;
	size=out.size;
	targetMPIId=out.targetMPIId;

	return *this;
}
*/

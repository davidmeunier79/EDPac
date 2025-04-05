// InputBuffer.cc

// Local Includes
#include "InputBuffer.h"

/****************************************************************************************************************************************/
/**************************************************** Methodes de la classe InputBuffer *************************************************/
/****************************************************************************************************************************************/

InputBuffer::InputBuffer()
{
}

InputBuffer::InputBuffer(int newSize, int newEtiquette, int newSourceMPIId): MPIBuffer(newSize,newEtiquette),sourceMPIId(newSourceMPIId)
{
#ifdef _MPI_TEST
	cout << "Initing active bool" << endl;
#endif
	active=0;
}

InputBuffer::InputBuffer(InputBuffer& iBuf): MPIBuffer(iBuf.size,iBuf.tag),sourceMPIId(iBuf.sourceMPIId)
{
	cout << "InputBuffer message: " << message << endl;
#ifdef _MPI_TEST
	cout << "Initing active bool" << endl;
#endif
	active=0;
}

InputBuffer::~InputBuffer()
{
}

void InputBuffer::setSourceMPIId(int newSourceMPIId)
{
	sourceMPIId=newSourceMPIId;
}

int InputBuffer::getSourceMPIId()
{
	return sourceMPIId;
}

bool InputBuffer::isActive()
{
	if (!active)
	{
		active=testInput();
	}
	return active;
}

bool InputBuffer::testInput()
{
	if(MPI::COMM_WORLD.Iprobe(sourceMPIId,tag,status))
	{
		if(status.Get_tag()==tag && status.Get_source()==sourceMPIId)
		{
#ifdef _MPI_TEST
			cout << "Buffer receiving compatible input" << endl;
#endif
			return 1;
		}
		else
		{
			cerr << "Warning, tag = " << status.Get_tag() << ", should be " << tag;
			cerr << " && source MPI ID = " << status.Get_source() << ", should be " << sourceMPIId;
		}
	}
	else
	{
#ifdef _MPI_TEST
		cout << "No probe that turn for buffer" << endl;
#endif
	}

	return 0;
}

void InputBuffer::receive()
{
	if (isActive())
	{
		receiveMessage(sourceMPIId);
	}
}

void InputBuffer::receiveInput()
{
	if (isActive())
	{
		startRequest();
/*
#ifdef _MPI_TEST
		cout << "Input Buffer " << getTag() << " " << MPI_GLOBALS.getMyId() << " waiting for receive inputs" << endl;
#endif
		wait();
*/
		active=1;
		//cout << "true" << endl;
	}
	else
	{
		//cout << "false" << endl;
	}
}

void InputBuffer::initReceiveInput()
{
	initReceive(sourceMPIId);
}
/*
InputBuffer& InputBuffer::operator=(const InputBuffer& in)
{
	tag=in.tag;
	size=in.size;
	sourceMPIId=in.sourceMPIId;

	return *this;
}
*/

// GenericBuffer.cc

#include "GenericBuffer.h"

/*********************************************************************************************/
/*                                                                                           */
/*                   Definitions des methodes de BufferGenerique                             */
/*                                                                                           */
/*********************************************************************************************/

GenericBuffer::GenericBuffer(int newTag) : tag(newTag),flag(1), active(0)
{}

void GenericBuffer::freeActive()
{
	active=0;
}

void GenericBuffer::setActive()
{
	active=1;
}

bool GenericBuffer::getActive()
{
	return active;
}

bool GenericBuffer::isActive()
{
	cerr << "Warning, accessing virtual GenericBuffer::isActive method" << endl;
}


void GenericBuffer::initRequest()
{
	if (request)
	{
#ifdef _MPI_TEST
		cout << "Initing request: " << request << " ";
#endif
		(MPI::Prequest) request = (MPI::Prequest) MPI_REQUEST_NULL;
#ifdef _MPI_TEST
		cout << "After init, request: " << request << endl;
#endif
	}

	active =0;
}

void GenericBuffer::freeRequest()
{
	if (getFlag())
	{
#ifdef _MPI_TEST
		cout << "Freeing request:" << request << endl;
#endif
		request.Free();
#ifdef _MPI_TEST
		cout << "Request after free:" << request << endl;
#endif
	}
	else
	{
#ifdef _MPI_TEST
		cout << "Cancelling request:" << request << endl;
#endif
		request.Cancel();

#ifdef _MPI_TEST
		cout << "Waiting for request to be cancelled " << endl;
#endif
		wait();

	}
}

bool GenericBuffer::getFlag()
{
	if(!flag)
    	{
		flag=request.Test(status);
  	}
	return flag;
}

void GenericBuffer::setFlag(bool newFlag)
{
	flag=newFlag;
}

void GenericBuffer::wait()
{
	if(!flag)
	{
		request.Wait(status);
		flag=1;
	}
}

void GenericBuffer::startRequest()
{
	((MPI::Prequest) request).Start();
	flag=0;
}

void GenericBuffer::setTag(int newTag)
{
	tag=newTag;
}

int GenericBuffer::getTag()
{
  	return tag;
}

bool GenericBuffer::testActiveRequete()
{
	if (request)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int GenericBuffer::waitAny(GenericBuffer ** listBuffers,int sizeList)
{
	MPI::Request* tabRequetes=new MPI::Request[sizeList];
	for(int i=0;i<sizeList;i++)
	{
	tabRequetes[i]=listBuffers[i]->request;
	}
	int retour=MPI::Request::Waitany(sizeList,tabRequetes);
	delete [] tabRequetes;
	return retour;
}

int GenericBuffer::waitSome(GenericBuffer ** listBuffers,int sizeList,int* indexRecu)
{
	MPI::Request* tabRequetes=new MPI::Request[sizeList];
	for(int i=0;i<sizeList;i++)
	{
	tabRequetes[i]=listBuffers[i]->request;
	}
	int retour;

	if((retour=MPI::Request::Waitsome(sizeList,tabRequetes,indexRecu))!=MPI_UNDEFINED)
	{
		if (retour!=0)
		{
			delete [] tabRequetes;
			return retour;
		}
		else
		{
			delete [] tabRequetes;
			cerr << "No request has finished" << endl;
			return 0;
		}
	}
	else
	{
		delete [] tabRequetes;
		cerr << "Warning, no valid request in tabRequetes" << endl;
		return 0;
	}
}

bool GenericBuffer::waitAll(GenericBuffer ** listBuffers,int sizeList)
{
	MPI::Request* tabRequetes=new MPI::Request[sizeList];

	for(int i=0;i<sizeList;i++)
	{
		tabRequetes[i]=listBuffers[i]->request;
	}

	MPI::Request::Waitall(sizeList,tabRequetes);
#ifdef _MPI_TEST
	cout << "All valid requests in tabRequetes complete" << endl;
#endif
	delete [] tabRequetes;
	return 1;
}


bool GenericBuffer::testAll(GenericBuffer ** listBuffers,int sizeList)
{
	MPI::Request* tabRequetes=new MPI::Request[sizeList];

	for(int i=0;i<sizeList;i++)
	{
		tabRequetes[i]=listBuffers[i]->request;
	}

	bool retour;
	retour = MPI::Request::Testall(sizeList,tabRequetes);

	if (retour)
	{
#ifdef _MPI_TEST
		cout << "All valid requests in tabRequetes complete" << endl;
#endif
	}
	else
	{
#ifdef _MPI_TEST
		cout << "Not All valid requests in tabRequetes complete" << endl;
#endif
	}
	delete [] tabRequetes;
	return retour;
}

bool GenericBuffer::testAny(GenericBuffer ** listBuffers,int sizeList)
{
	int recu;
	MPI::Request* tabRequetes=new MPI::Request[sizeList];
	for(int i=0;i<sizeList;i++)
	{
		tabRequetes[i]=listBuffers[i]->request;
	}

	bool retour=MPI::Request::Testany(sizeList,tabRequetes,recu);

	delete [] tabRequetes;
	return retour;
}

int GenericBuffer::testSome(GenericBuffer ** listBuffers,int sizeList,int* indexRecu)
{
	MPI::Request* tabRequetes=new MPI::Request[sizeList];
	for(int i=0;i<sizeList;i++)
	{
	tabRequetes[i]=listBuffers[i]->request;
	}
	int retour;

	if((retour=MPI::Request::Testsome(sizeList,tabRequetes,indexRecu))!=MPI_UNDEFINED)
	{
		if (retour!=0)
		{
			if (retour!=0)
			{
				delete [] tabRequetes;
				return retour;
			}
			else
			{
				delete [] tabRequetes;
				return 0;
			}
		}
		else
		{
			delete [] tabRequetes;
	#ifdef _MPI_TEST
			cout << "No valid request in tabRequetes" << endl;
	#endif
			return 0;
		}
	}
}


// MpiGlobals.cc

#include "MpiGlobals.h"

/*********************************************************************************************/
/*                                                                                           */
/*                   Definitions des methodes de MpiGlobals                                  */
/*                                                                                           */
/*********************************************************************************************/

MpiGlobals *MpiGlobals::leSingleton=0;

MpiGlobals::MpiGlobals()
{
}

MpiGlobals::~MpiGlobals()
{
  if(leSingleton)
    delete leSingleton;
}

MpiGlobals & MpiGlobals::getInstance()
{
  if(!leSingleton)
    leSingleton=new MpiGlobals();
  return *leSingleton;
}

bool MpiGlobals::initialise(int &argc,char ** &argv)
{
  MPI::Init(argc,argv);
  startWTime = MPI::Wtime();
  myId=MPI::COMM_WORLD.Get_rank();
  numProcs=MPI::COMM_WORLD.Get_size();
  MPI::Get_processor_name(name,len);
  return 1;
}

bool MpiGlobals::finalise()
{
  endWTime = MPI::Wtime();
  MPI::Finalize();
  return 1;
}

void MpiGlobals::synchronize()
{
	MPI::COMM_WORLD.Barrier();
}

void MpiGlobals::abort()
{
	MPI::COMM_WORLD.Abort(0);
}

double MpiGlobals::getStartWTime()
{
  return startWTime;
}

double  MpiGlobals::getEndWTime()
{
  return endWTime;
}

int  MpiGlobals::getNameLen()
{
  return nameLen;
}

int  MpiGlobals::getNumProc()
{
  return numProcs;
}

int  MpiGlobals::getMyId()
{
  return myId;
}

string  MpiGlobals::getProcessorName()
{
  return processorName;
}

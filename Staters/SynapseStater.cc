// SynapseStater.cc

// Local Includes
#include "SynapseStater.h"

/****************************************************************************************************************************************/
/************************************************* Methodes de la classe SynapseStater ************************************************/
/****************************************************************************************************************************************/

//SynapseStater* SynapseStater::theSynapseStater=0;

SynapseStater::SynapseStater()
{
}

SynapseStater::SynapseStater(IndexedObject* io):Stater(io)
{
}

SynapseStater::~SynapseStater()
{
}

/****************************************************************************************************************************************/
/******************************************************* Methodes de stats **************************************************************/
/****************************************************************************************************************************************/

#ifdef _ASSEMBLY_STAT_MODE
	#ifdef _GLOBAL_SYNAPSE_STAT_MODE
void SynapseStater::statPreTemporalVariation(int tempVariation)
{
	cerr << "Warning, accessing virtual SynapseStater::statPreTemporalVariation method " << endl;
}

void SynapseStater::statPostTemporalVariation(int tempVariation)
{
	cerr << "Warning, accessing virtual SynapseStater::statPostTemporalVariation method " << endl;
}

void SynapseStater::stat(EDSynapse* eds)
{	
	cerr << "Warning, accessing virtual SynapseStater::stat method " << endl;
}

void SynapseStater::trace(int timeOfTrace)
{	
	cerr << "Warning, accessing virtual SynapseStater::trace method " << endl;
}

void SynapseStater::graph()
{
	cerr << "Warning, accessing virtual SynapseStater::graph method " << endl;
}

void SynapseStater::flushCounters()
{
	cerr << "Warning, accessing virtual SynapseStater::flushCounters method " << endl;
}

Stater* SynapseStater::getInhibSynapseStater()
{
	cerr << "Warning, accessing virtual SynapseStater::getInhibSynapseStater method " << endl;
}

Stater* SynapseStater::getExcitSynapseStater()
{
	cerr << "Warning, accessing virtual SynapseStater::getExcitSynapseStater method " << endl;
}
	#endif
#endif


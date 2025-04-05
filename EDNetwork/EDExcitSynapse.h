// EDExcitSynapse.h

#ifndef _ED_EXCIT_SYNAPSE_H
#define _ED_EXCIT_SYNAPSE_H

//#include "stdio.h"

// Local Includes
#include "../Define.h"
#include "../DefinePhysiology.h"
#include "../DefineEDNetwork.h"

#include "../DefineStater.h"
#include "../DefineTracer.h"
#include "../DefineGrapher.h"

#include "EDSynapse.h"

class EDExcitSynapse;
#include "../Staters/ExcitSynapseStater.h"
  
/******************************************************************************************************************************************/
/******************************************************** Classe EDExcitSynapse ***********************************************************/
/******************************************************************************************************************************************/

class EDExcitSynapse: public EDSynapse
{
public:
	EDExcitSynapse();
	EDExcitSynapse(Neuron* _pNewPreNeuron, Neuron* _pNewPostNeuron);
	
	~EDExcitSynapse();

	void initSynapse();
#ifdef _ONLINE_LEARNING_MODE
	void computeNewWeight();
#endif

#ifdef _ASSEMBLY_STAT_MODE
	#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	friend class ExcitSynapseStater;

	void statPotentiation();
	void statDepression();
	
	virtual void initSynapseFiles(SynapseStater* ss);

	void statPreTemporalVariation(int temporalDeviation);
	void statPostTemporalVariation(int temporalDeviation);
	
	#endif
#endif
};

#endif



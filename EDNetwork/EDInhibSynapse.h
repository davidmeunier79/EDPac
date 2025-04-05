// EDInhibSynapse.h

#ifndef _ED_INHIB_SYNAPSE_H
#define _ED_INHIB_SYNAPSE_H

//#include "stdio.h"

// Local Includes
#include "../Define.h"
#include "../DefinePhysiology.h"
#include "../DefineEDNetwork.h"

#include "../DefineStater.h"
#include "../DefineTracer.h"
#include "../DefineGrapher.h"


#include "EDSynapse.h"

class EDInhibSynapse;
#include "../Staters/InhibSynapseStater.h"
/******************************************************************************************************************************************/
/******************************************************** Classe EDInhibSynapse ***********************************************************/
/******************************************************************************************************************************************/

class EDInhibSynapse: public EDSynapse
{
public:
	EDInhibSynapse();
	EDInhibSynapse(Neuron* _pNewPreNeuron, Neuron* _pNewPostNeuron);
	
	~EDInhibSynapse();
	
	void initSynapse();
#ifdef _ONLINE_LEARNING_MODE
	void computeNewWeight();
#endif

#ifdef _ASSEMBLY_STAT_MODE
	#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	friend class InhibSynapseStater;
	void initSynapseFiles(SynapseStater* ss);
	
	void statPotentiation();
	void statDepression();

	void statPreTemporalVariation(int temporalDeviation);
	void statPostTemporalVariation(int temporalDeviation);
	#endif
#endif
};

#endif


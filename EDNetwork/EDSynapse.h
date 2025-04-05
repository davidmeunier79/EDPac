// EDSynapse.h

#ifndef _ED_SYNAPSE_H
#define _ED_SYNAPSE_H

//#include "stdio.h"

// Local Includes
#include "../Define.h"
#include "../DefineZoo.h"
#include "../DefinePhysiology.h"
#include "../DefineEDNetwork.h"

#include "../DefineStater.h"
#include "../DefineTracer.h"
#include "../DefineGrapher.h"

#include "../Interfaces/Statable.h"
#include "../Interfaces/Tracable.h"
#include "../Interfaces/Graphable.h"

#include "../Physiology/DynamicSynapse.h"

class EDSynapse;
#include "../EventManager/EventManager.h"

//class EDSynapse;
#include "../Staters/SynapseStater.h"
#include "../Tracers/SynapseTracer.h"
#include "../Graphers/SynapseGrapher.h"

/******************************************************************************************************************************************/
/*********************************************************** Classe EDSynapse *************************************************************/
/******************************************************************************************************************************************/

class EDSynapse: public DynamicSynapse, public Statable, public Tracable, public Graphable
{
public:
	EDSynapse();

	virtual ~EDSynapse();
	virtual void initSynapse();

	void reInitSynapse();
	void reInitEDSynapse();

	EDSynapse(Neuron* _pNewPreNeuron, Neuron* _pNewPostNeuron);

	static EventManager theEventManager;

#ifdef _TOPOLOGICAL_DELAY_MODE
	int returnTopologicalDelay();
#endif

#ifdef _ONLINE_LEARNING_MODE
	void computeBPSpikeImpact(int timeOfBPSpike);
#endif

	void computeSpikeImpact(int timeOfSpike);
	void computePSPEmission(int timeOfEmission);

#ifdef _ASSEMBLY_STAT_MODE
	#ifdef _GLOBAL_SYNAPSE_STAT_MODE
	friend class SynapseStater;

	virtual void statPreTemporalVariation(int temporalDeviation);
	virtual void statPostTemporalVariation(int temporalDeviation);

	virtual void initSynapseFiles(SynapseStater* ss);
	void endSynapseFiles();
	#endif
#endif

	// Graphs
#ifdef _SYNAPSE_GRAPH_MODE
	friend class SynapseGrapher;

	void initSynapseGrapher(SynapseGrapher* s);
	void initSynapseGrapher();
	void freeSynapseGrapher();

	void graph();
#endif

#ifdef _SYNAPSE_TRACE_MODE
	friend class SynapseTracer;
	//#ifdef _SINGLE_SYNAPSPE_TRACE_MODE
	void initSynapseTracer();
	//#else
	void initSynapseTracer(SynapseTracer* st);
	//#endif
	void freeSynapseTracer();
#endif
};

#endif

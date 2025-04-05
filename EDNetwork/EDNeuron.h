// EDNeuron.h

#ifndef _ED_NEURON_H
#define _ED_NEURON_H

// STL includes
//#include <stdio.h>
#include <iostream>
using namespace std;

// Local Includes
#include "../Define.h"
#include "../DefineZoo.h"
#include "../DefinePhysiology.h"
#include "../DefineEDNetwork.h"

#include "../DefineStater.h"
#include "../DefineTracer.h"
#include "../DefineGrapher.h"

#include "EDExcitSynapse.h"
#include "EDInhibSynapse.h"

#include "../Interfaces/Statable.h"
#include "../Interfaces/Tracable.h"
#include "../Interfaces/Graphable.h"

#include "../Physiology/SpikingNeuron.h"

#include "../Handlers/Accumulater.h"

class EDNeuron;
#include "../Staters/NeuronStater.h"
#include "../Tracers/NeuronTracer.h"
#include "../Graphers/NeuronGrapher.h"

/******************************************************************************************************************************************/
/******************************************************** Classe EDNeuron *****************************************************************/
/******************************************************************************************************************************************/

class EDNeuron : public SpikingNeuron, public Statable, public Graphable, public Tracable
{
#ifdef _ASSEMBLY_STAT_MODE
	#ifdef _PSP_LFP_STAT_MODE
	Accumulater* PSPotentialAccu;
	#endif
#endif
public:
	EDNeuron();
	~EDNeuron();

	void buildPostExcitLink(Neuron* _pPostNeuron);
	void buildPostInhibLink(Neuron* _pPostNeuron);

	void reInitNeuron();
	void reInitEDNeuron();
	
	//void destroyLinks();

	void computePSPImpact(int timeOfImpact, double weightOfImpact);
	void emitSpike(int timeOfSpike);
	
#ifdef _ONLINE_LEARNING_MODE
	void emitBPSpike(int timeOfSpike);
#endif

#ifdef _ASSEMBLY_STAT_MODE
	friend class NeuronStater;
	
	#ifdef _PSP_LFP_STAT_MODE
	void initPSPotential();
	#endif
	
	void initNeuronFiles(NeuronStater* nt);
	void endNeuronFiles();
#endif

	// Methodes de traces
#ifdef _NEURON_TRACE_MODE
	friend class NeuronTracer;
	void initNeuronTracer(NeuronTracer* nt);
	void initNeuronTracer();
	void freeNeuronTracer();
#endif

	// Méthodes de graphs
#ifdef _NEURON_GRAPH_MODE
	friend class NeuronGrapher;
	void initNeuronGrapher(NeuronGrapher* ng);
	void initNeuronGrapher();
	void freeNeuronGrapher();

	void graph();
#endif

	friend std::ostream& operator<<(std::ostream&, EDNeuron&);

};

#endif

// DynamicSynapse.h

#ifndef _DYNAMIC_SYNAPSE_H
#define _DYNAMIC_SYNAPSE_H

//#include <stdio.h>
// STL Includes
#include <iostream>
#include <fstream>
using namespace std;

// Local Includes
#include "../Define.h"
#include "../DefinePhysiology.h"
#include "../DefineEDNetwork.h"

#include "../MathTools/RandomMathTools.h"
#include "../MathTools/SynapseMathTools.h"

#include "../Topology/Synapse.h"

/******************************************************************************************************************************************/
/******************************************************** Classe DynamicSynapse ***********************************************************/
/******************************************************************************************************************************************/

class DynamicSynapse : public Synapse, public SynapseMathTools
{
protected:

#ifdef _ONLINE_LEARNING_MODE

	// Temps d'émission des neurones pre et post-synaptique
	int lastTimeOfPreSpike;
	int lastTimeOfPostSpike;
#endif

	// Poids de la synapse
	double weight;
	double deltaWeight;
	double realDeltaWeight;

	// Delai de propagation entre le neurone pre- et le neurone postsynaptique
	int delay;

public:

	DynamicSynapse();
	DynamicSynapse(Neuron* _pNewPreNeuron, Neuron* new_pNewPostNeuron);
	
	~DynamicSynapse();

	double getWeight();
	int getDelay();

#ifdef _WEIGHT_NORMALIZE_MODE
	void updateWeight(double sumWeight);
#endif

#ifdef _ONLINE_LEARNING_MODE
	void updateLastTimeOfPreSpike(int newTimeOfPreSpike);
	void updateLastTimeOfPostSpike(int newTimeOfPostSpike);

	virtual void computeNewWeight();
	virtual void initSynapse();
#endif

	friend std::ostream& operator<<(std::ostream&, DynamicSynapse&);

};

#endif

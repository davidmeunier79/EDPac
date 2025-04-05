// SpikingNeuron.h

#ifndef _SPIKING_NEURON_H
#define _SPIKING_NEURON_H

// STL Includes
#include <vector>
using namespace std;

// Local Includes
#include "../Define.h"
#include "../DefinePhysiology.h"
#include "../DefineEDNetwork.h"

#include "../MathTools/NeuronMathTools.h"
#include "../Topology/Neuron.h"

#include "DynamicSynapse.h"

/******************************************************************************************************************************************/
/******************************************************** Classe SpikingNeuron ************************************************************/
/******************************************************************************************************************************************/

class SpikingNeuron : public Neuron, public NeuronMathTools
{
protected:

	int lastTimeOfPSPImpact;
	int lastTimeOfFiring;

	double membranePotential;
	double thresholdPotential;

public:

	SpikingNeuron();
	~SpikingNeuron();

	void initNeuron();
	
	void resetNeuron();

	double updateThresholdPotential(int currentTimeOfImpact);
	double updateMembranePotential(int currentTimeOfImpact);

	bool computeSpikeEmission(int timeOfImpact, double weightOfImpact);
	
	int getLastTimeOfFiring();


	friend std::ostream& operator<<(std::ostream&, SpikingNeuron&);
};

#endif

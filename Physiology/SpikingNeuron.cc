// SpikingNeuron.cc

// Local Includes
#include "SpikingNeuron.h"

/****************************************************************************************************************************************/
/***************************************************** Methodes de la classe SpikingNeuron **********************************************/
/****************************************************************************************************************************************/

SpikingNeuron::SpikingNeuron()
{
	initNeuron();

#ifdef _TEST
	cout << "NeuronTracer: " << tracer << endl;
#endif
}

SpikingNeuron::~SpikingNeuron()
{
#ifdef _TEST
	cout << "~SpikingNeuron" << endl;
#endif
}

void SpikingNeuron::initNeuron()
{
	lastTimeOfFiring=-1;
	lastTimeOfPSPImpact=-1;

	thresholdPotential=THRESHOLD_REF;
	membranePotential=RESTING_POTENTIAL;
}

void SpikingNeuron::resetNeuron()
{
#ifdef _ADDITIVE_THRESHOLD_MODE
	thresholdPotential+=THRESHOLD_MAX;
#else
	thresholdPotential=THRESHOLD_MAX;
#endif
	membranePotential=RESTING_POTENTIAL;
	//membranePotential=HYPER_POLARISATION_POTENTIAL;
}

double SpikingNeuron::updateThresholdPotential(int currentTimeOfImpact)
{
	if (lastTimeOfFiring!=-1 && lastTimeOfPSPImpact!=-1)
	{
		if (currentTimeOfImpact!=lastTimeOfPSPImpact)
		{
			return (THRESHOLD_REF+(thresholdPotential-THRESHOLD_REF)*threshold(lastTimeOfPSPImpact-lastTimeOfFiring));
		}
		else
		{
			return (thresholdPotential);
		}

	}
	else
	{
		return THRESHOLD_REF;
	}
}
/*
void SpikingNeuron::resetNeuron()
{
	thresholdPotential=THRESHOLD_MAX;
	membranePotential=RESTING_POTENTIAL;
}

double SpikingNeuron::updateThresholdPotential()
{
	if (lastTimeOfFiring!=-1 && lastTimeOfPSPImpact!=-1)
	{
		return (threshold(lastTimeOfPSPImpact-lastTimeOfFiring));
	}
	else
	{
		return THRESHOLD_REF;
	}
}
*/
double SpikingNeuron::updateMembranePotential(int currentTimeOfImpact)
{
	#ifdef _DISCRETE_EXP_MODE
	if (lastTimeOfPSPImpact!=-1 && currentTimeOfImpact<=lastTimeOfPSPImpact+NB_DISCRETE_EXP_STEPS)
	{
		//cout << "Computing diff " << currentTimeOfImpact-lastTimeOfPSPImpact << endl;
		
		return((double) membranePotential*getDiscreteExp(currentTimeOfImpact-lastTimeOfPSPImpact));
	}
	else
	{
		return RESTING_POTENTIAL;
	}
	#else
	if (lastTimeOfPSPImpact!=-1 && currentTimeOfImpact<=lastTimeOfPSPImpact+PSP_TEMPORAL_IMPACT)
	{
		
		return(membranePotential*epsilon(currentTimeOfImpact-lastTimeOfPSPImpact));
	}
	else
	{
		return RESTING_POTENTIAL;
	}
	#endif
}

bool SpikingNeuron::computeSpikeEmission(int timeOfImpact, double weightOfImpact)
{
	membranePotential=updateMembranePotential(timeOfImpact);
	membranePotential+=MAX_PSP_POTENTIAL*weightOfImpact;

	thresholdPotential=updateThresholdPotential(timeOfImpact);
	
	lastTimeOfPSPImpact=timeOfImpact;

	// Comparaison pour émission
	if (thresholdPotential<=membranePotential)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int SpikingNeuron::getLastTimeOfFiring()
{
	return lastTimeOfFiring;
}

/****************************************************************************************************************************************/
/******************************************************* Methodes d'affichage ***********************************************************/
/****************************************************************************************************************************************/

std::ostream& operator<<(std::ostream& f, SpikingNeuron& s)
{

	f << "***Last Time Of Firing: " << s.lastTimeOfFiring << endl;
	f << "***Last Time Of PSP Impact: " << s.lastTimeOfPSPImpact << endl;
	f << "***Membrane Potential: " << s.membranePotential << endl;
}


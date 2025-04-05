// MathTools.cc

// Local Includes
#include "NeuronMathTools.h"

/****************************************************************************************************************************************/
/**************************************************************** Calcul du seuil *******************************************************/
/****************************************************************************************************************************************/

int NeuronMathTools::ABSOLUT_REFRACTORY_PERIOD = DELAY;
//int NeuronMathTools::ABSOLUT_REFRACTORY_PERIOD = DELAY+INHIBITORY_DELAY;
	
int NeuronMathTools::PSP_TEMPORAL_IMPACT = DELAY+INHIBITORY_DELAY;
	
double NeuronMathTools::MAX_PSP_POTENTIAL = 0.0020;

#ifdef _BURSTY_NEURON_MODE
int NeuronMathTools::RELATIVE_REFRACTORY_PERIOD = DELAY;
//int NeuronMathTools::RELATIVE_REFRACTORY_PERIOD = DELAY+INHIBITORY_DELAY;
#endif

#ifdef _BURSTY_NEURON_MODE
double NeuronMathTools::THRESHOLD_MAX = 2*THRESHOLD_REF;
#else
double NeuronMathTools::THRESHOLD_MAX = 1.0;
#endif
	
#ifdef _DISCRETE_EXP_MODE
void NeuronMathTools::initDiscreteExp()
{
	for (int i=0;i<NB_DISCRETE_EXP_STEPS;i++)
	{
		discreteExp[i]=(double) exp(((double) -i)/PSP_TEMPORAL_IMPACT);
	}
}

double NeuronMathTools::getDiscreteExp(int expIndex)
{
	if (expIndex < NB_DISCRETE_EXP_STEPS)
	{		
		return((double) discreteExp[expIndex]);
	}
	else
	{
		return 0.0;
	}
}
#endif

double NeuronMathTools::threshold(int relativeTime)
{
	double thresholdVal=0.0;
	
#ifdef _BURSTY_NEURON_MODE
	if (0<=relativeTime && relativeTime < ABSOLUT_REFRACTORY_PERIOD)
	{
		thresholdVal=1.0;
	}
	else if (ABSOLUT_REFRACTORY_PERIOD <= relativeTime && relativeTime < ABSOLUT_REFRACTORY_PERIOD+RELATIVE_REFRACTORY_PERIOD)
	{
		thresholdVal = ((double) ABSOLUT_REFRACTORY_PERIOD+RELATIVE_REFRACTORY_PERIOD-relativeTime)/RELATIVE_REFRACTORY_PERIOD;
	}
	else if (ABSOLUT_REFRACTORY_PERIOD+RELATIVE_REFRACTORY_PERIOD <= relativeTime)
	{
		thresholdVal= 0.0;
	}
	else
	{
		cout << "Error, relativeTime = " << relativeTime << " (Negative Value)" << endl;
		thresholdVal = 0.0;
	}
#else

	if (0 <= relativeTime && relativeTime < ABSOLUT_REFRACTORY_PERIOD)
	{
		thresholdVal=1.0;
	}
	else if (ABSOLUT_REFRACTORY_PERIOD <= relativeTime)
	{
		thresholdVal=0.0;
	}
	else cout << "Error, relativeTime = " << relativeTime << " (Negative Value)" << endl;
#endif
	return thresholdVal;
}


/****************************************************************************************************************************************/
/******************************************************** Calcul de la contribution du PSP **********************************************/
/****************************************************************************************************************************************/

double NeuronMathTools::epsilon(int relativeTime)
{
	double membranePotentialValue=0.0000;

	if (0<=relativeTime && relativeTime<=PSP_TEMPORAL_IMPACT)
	{
		membranePotentialValue+=1.0-((double)relativeTime)/((double)PSP_TEMPORAL_IMPACT);
	}
	return membranePotentialValue;
}


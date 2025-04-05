// MathTools.cc

// Local Includes
#include "SynapseMathTools.h"

/****************************************************************************************************************************************/
/*************************************************** Fenetre temporelle pour variation du poids *****************************************/
/****************************************************************************************************************************************/

#ifdef _EXCIT_ALPHA_UPDATE_MODE

	#ifdef _NO_EXCIT_STDP_MODE
double SynapseMathTools::EXCIT_ALPHA = 0.0;
	#else
		#ifdef _OLD_CONFIG_MODE
// Utilise pour les anciennes simulations
double SynapseMathTools::EXCIT_ALPHA = 0.1;
		#else
double SynapseMathTools::EXCIT_ALPHA = 0.5;
		#endif
	#endif
	
#endif

#ifdef _INHIB_ALPHA_UPDATE_MODE
	#ifdef _NO_INHIB_STDP_MODE
double SynapseMathTools::INHIB_ALPHA = 0.0;
	#else
		#ifdef _NO_INHIBITION_MODE
double SynapseMathTools::INHIB_ALPHA = 0.0;
		#else
double SynapseMathTools::INHIB_ALPHA = 0.1;
		#endif
	#endif
#endif

#ifdef _NO_INHIBITION_MODE
double SynapseMathTools::INHIB_WEIGHT=0.0;
#else
double SynapseMathTools::INHIB_WEIGHT=0.5;
#endif

double SynapseMathTools::INHIB_DEPRESSION_STRENGTH=0.25;
double SynapseMathTools::EXCIT_DEPRESSION_STRENGTH=0.5;

int SynapseMathTools::INHIB_STDP_TIME_LENGTH=DELAY+INHIBITORY_DELAY;

#ifdef _ONLINE_LEARNING_MODE
double SynapseMathTools::excitTemporalWindow(int temporalDifference)
{
	double deltaWeight=0.000;

	#ifdef _CONTINUOUS_HEBBIAN_WINDOW_MODE

	//if (-5*(DELAY+INHIBITORY_DELAY)<temporalDifference && temporalDifference<0)
	if (-5*(DELAY+INHIBITORY_DELAY)<temporalDifference && temporalDifference<=0)
	{
		deltaWeight=-1.0/((double) 5*(DELAY+INHIBITORY_DELAY))*((double)temporalDifference)-EXCIT_DEPRESSION_STRENGTH;
	}
	//else if(0<=temporalDifference && temporalDifference<DELAY)
	else if(0<temporalDifference && temporalDifference<DELAY)
	{
		deltaWeight=1.0*((double)temporalDifference)/((double) DELAY);
	}
	else if(DELAY<=temporalDifference && temporalDifference<(DELAY+INHIBITORY_DELAY))
	{
		deltaWeight=-1.0/((double) INHIBITORY_DELAY)*((double) (temporalDifference-(DELAY+INHIBITORY_DELAY)));
	}  
	/*
	// Modifcation pour 5
	if (-5*(DELAY+INHIBITORY_DELAY)<temporalDifference && temporalDifference<=0)
	{
		deltaWeight=-1.0/((double) 5*(DELAY+INHIBITORY_DELAY))*((double)temporalDifference)-EXCIT_DEPRESSION_STRENGTH;
	}
	//else if(0<=temporalDifference && temporalDifference<DELAY)
	else if(0<temporalDifference && temporalDifference<5)
	{
		deltaWeight=1.0*((double)temporalDifference)/((double) 5);
	}
	else if(5<=temporalDifference && temporalDifference<(DELAY))
	{
		deltaWeight=-1.0/((double) 5)*((double) (temporalDifference-DELAY));
	}  
	*/
	#else
		#ifdef _SHARP_HEBBIAN_WINDOW_MODE
	if (-(DELAY+INHIBITORY_DELAY)<temporalDifference && temporalDifference<0)
	//if (-(DELAY+INHIBITORY_DELAY)<temporalDifference && temporalDifference<=0)
	//if (-5*(DELAY+INHIBITORY_DELAY)<temporalDifference && temporalDifference<=0)
	//if (-5*(DELAY+INHIBITORY_DELAY)<temporalDifference && temporalDifference<0)
	//if (-2.5*(DELAY+INHIBITORY_DELAY)<temporalDifference && temporalDifference<0)
	//if (-2.5*(DELAY+INHIBITORY_DELAY)<temporalDifference && temporalDifference<=0)
	{
		//deltaWeight=-1.0/((double) 2.5*(DELAY+INHIBITORY_DELAY))*((double)temporalDifference)-1.0;
		//deltaWeight=-1.0/((double) 5*(DELAY+INHIBITORY_DELAY))*((double)temporalDifference)-0.5;
		deltaWeight=-1.0/((double) (DELAY+INHIBITORY_DELAY))*((double)temporalDifference)-1.0;
	}
	else if(0<=temporalDifference && temporalDifference<(DELAY+INHIBITORY_DELAY))
	//else if(0<temporalDifference && temporalDifference<(DELAY+INHIBITORY_DELAY))
	{
		deltaWeight=-1.0/((double) (DELAY+INHIBITORY_DELAY))*((double)temporalDifference)+1.0;
	}
		#endif
	#endif


	return deltaWeight;
}

double SynapseMathTools::inhibTemporalWindow(int temporalDifference)
{
	double deltaWeight=0.000;

	if (-INHIB_STDP_TIME_LENGTH<=temporalDifference && temporalDifference<=INHIB_STDP_TIME_LENGTH)
	//if (-DELAY<=temporalDifference && temporalDifference<=DELAY)
	{
		deltaWeight=1.0;
	}
	else
	{
		deltaWeight=-INHIB_DEPRESSION_STRENGTH;
	}

	return deltaWeight;
}
#endif





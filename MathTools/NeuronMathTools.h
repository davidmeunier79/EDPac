// MathTools.h

#ifndef _NEURON_MATHTOOLS_H
#define _NEURON_MATHTOOLS_H

//#include <stdio.h>
//#include <math.h>
#include <iostream>
using namespace std;

// Local Includes
#include "../Define.h"
#include "../DefineEDNetwork.h"
#include "../DefinePhysiology.h"

/******************************************************************************************************************************************/
/****************************************************** Fonctions temporelles du neurone **************************************************/
/******************************************************************************************************************************************/

class NeuronMathTools
{
	#ifdef _DISCRETE_EXP_MODE
	static double discreteExp[NB_DISCRETE_EXP_STEPS];
	
	void initDiscreteExp();
	double getDiscreteExp(int expIndex);
	#endif
	
protected:		
	static double threshold(int relativeTime);
	static double epsilon(int relativeTime);
	
public:	
	// Période réfractaire absolue
	static int ABSOLUT_REFRACTORY_PERIOD;
	
	// Impact temporel du PSP sur le neurone
	static int PSP_TEMPORAL_IMPACT;
	
	// Seuil maximal
	static double THRESHOLD_MAX;
	
	static double MAX_PSP_POTENTIAL;
	
#ifdef _BURSTY_NEURON_MODE
	// Période réfractaire relative
	static int RELATIVE_REFRACTORY_PERIOD;
#endif
	
};
#endif



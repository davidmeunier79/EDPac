// MathTools.h

#ifndef _SYNAPSE_MATHTOOLS_H
#define _SYNAPSE_MATHTOOLS_H

//#include <stdio.h>

// Local Includes
#include "../Define.h"
#include "../DefinePhysiology.h"
#include "../DefineEDNetwork.h"

/******************************************************************************************************************************************/
/****************************************************** Fenetre temporelle de STDP ********************************************************/
/******************************************************************************************************************************************/

class SynapseMathTools
{

protected:
		
#ifdef _ONLINE_LEARNING_MODE
	static double excitTemporalWindow(int temporalDifference);
	static double inhibTemporalWindow(int temporalDifference);
#endif

public:
	static int INHIB_STDP_TIME_LENGTH;
	
#ifdef _EXCIT_ALPHA_UPDATE_MODE
	static double EXCIT_ALPHA;
#endif

#ifdef _INHIB_ALPHA_UPDATE_MODE
	static double INHIB_ALPHA;
#endif
	// Inluence max de la depression pour la fenetre STDP inhib
	static double INHIB_DEPRESSION_STRENGTH;
	
	// Inluence max de la depression pour la fenetre STDP excit
	static double EXCIT_DEPRESSION_STRENGTH;

	// Poids inhib moyen
	static double INHIB_WEIGHT;
};

#endif


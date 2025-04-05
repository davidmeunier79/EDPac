// OngoingMeanLogDistribution.h

#ifndef _ONGOING_MEAN_LOG_DISTRIBUTION_H
#define _ONGOING_MEAN_LOG_DISTRIBUTION_H

// C includes
#include <math.h>

// STL Includes
//#include <string>
//#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

// Local Includes
#include "LogDistribution.h"
#include "MeanLogDistribution.h"

#include "OngoingMeanDistribution.h"


/******************************************************************************************************************************************/
/*********************************************** Classe OngoingMeanLogDistribution ********************************************************/
/******************************************************************************************************************************************/

class OngoingMeanLogDistribution : public OngoingMeanDistribution
{
public:

	OngoingMeanLogDistribution();
	OngoingMeanLogDistribution(int nbOngoingDistrib, int newMinLogRange, int newMaxLogRange, int newRangeEachDecade);

	virtual ~OngoingMeanLogDistribution();
	
	friend ostream& operator<<(ostream& o, OngoingMeanLogDistribution* co);
};

#endif

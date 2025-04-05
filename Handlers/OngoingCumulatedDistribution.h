// OngoingCumulatedDistribution.h

#ifndef _ONGOING_CUMULATED_DISTRIBUTION_H
#define _ONGOING_CUMULATED_DISTRIBUTION_H

// C includes
#include <math.h>

// STL Includes
//#include <string>
//#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

// Local Includes
#include "CumulatedDistribution.h"
#include "OngoingMeanDistribution.h"

/******************************************************************************************************************************************/
/******************************************** Classe OngoingCumulatedDistribution *****************************************************/
/******************************************************************************************************************************************/

class OngoingCumulatedDistribution: public OngoingMeanDistribution
{
	void buildTabCumulatedDistributions(int nbOngoingDistrib, int nbAccus);
	
	virtual void buildCumulatedDistribution(int nbAccus);
public:

	OngoingCumulatedDistribution();
	OngoingCumulatedDistribution(int nbOngoingDistrib, int nbAccus);

	virtual ~OngoingCumulatedDistribution();
	
	void initOngoingCumulatedDistribution();
	
	void ongoingCumulate(int ongoingIndex, MeanDistribution* curDistrib);
	virtual MeanDistribution* getCumulatedDistribution();
	
	friend ostream& operator<<(ostream& o, OngoingCumulatedDistribution* co);
};

#endif

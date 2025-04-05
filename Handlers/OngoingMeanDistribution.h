// OngoingMeanDistribution.h

#ifndef _ONGOING_MEAN_DISTRIBUTION_H
#define _ONGOING_MEAN_DISTRIBUTION_H

// C includes
#include <math.h>

// STL Includes
//#include <string>
//#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

// Local Includes
#include "OngoingDistribution.h"
#include "MeanDistribution.h"

/******************************************************************************************************************************************/
/************************************************** Classe OngoingMeanDistribution ***********************************************************/
/******************************************************************************************************************************************/

class OngoingMeanDistribution: public OngoingDistribution
{
protected:

	void buildTabMeanDistributions(int nbOngoingDistrib, int nbAccus);
	void initTabMeanDistributions();
	
public:
	OngoingMeanDistribution();
	OngoingMeanDistribution(int nbOngoingDistrib, int nbAccus);

	virtual ~OngoingMeanDistribution();

	void initOngoingMeanDistribution();

	void ongoingAccumulate(int ongoingIndex, Distribution* curDistrib);

	void ongoingAccumulateProba(int ongoingIndex, Distribution* curDistrib);
	void ongoingAccumulateCumulProba(int ongoingIndex, Distribution* curDistrib);

	MeanDistribution* getMeanDistribution(int ongoingIndex);	
	virtual MeanDistribution* getCumulatedDistribution();
	
	friend ostream& operator<<(ostream& o, OngoingMeanDistribution* co);
};

#endif

// OngoingDistribution.h

#ifndef _ONGOING_DISTRIBUTION_H
#define _ONGOING_DISTRIBUTION_H

// C includes
#include <math.h>

// STL Includes
//#include <string>
//#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

// Local Includes
#include "Distribution.h"
#include "MeanDistribution.h"

/******************************************************************************************************************************************/
/************************************************** Classe OngoingDistribution ***********************************************************/
/******************************************************************************************************************************************/

class OngoingDistribution
{
	
	void buildTabDistributions(int nbOngoingDistrib, int nbCounters);
	void initTabDistributions();
	
protected:
	MeanDistribution* cumulatedDistribution;
	
	vector<Distribution*> tabDistributions;
	
	void initCumulatedDistribution();
	virtual void buildCumulatedDistribution(int nbCounters);
	
public:
	friend class OngoingDistributionDataFile;
	
	OngoingDistribution();
	OngoingDistribution(int nbOngoingDistrib, int nbCounters);

	virtual ~OngoingDistribution();
	
	void initOngoingDistribution();
	
	void ongoingCount(int ongoingIndex, int index);

	Distribution* getDistribution(int ongoingIndex);
	virtual MeanDistribution* getCumulatedDistribution();
	
	friend ostream& operator<<(ostream& o, OngoingDistribution* co);
};

#endif

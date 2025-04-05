// MeanLogDistribution.h

#ifndef _MEAN_LOG_DISTRIBUTION_H
#define _MEAN_LOG_DISTRIBUTION_H

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
#include "MeanDistribution.h"

/******************************************************************************************************************************************/
/*************************************************** Classe MeanLogDistribution ***********************************************************/
/******************************************************************************************************************************************/

class MeanLogDistribution : public MeanDistribution
{
	int rangeEachDecade;
	int minLogRange;
	int maxLogRange;
	
public:
	
	MeanLogDistribution();
	MeanLogDistribution(int newMinLogRange, int newMaxLogRange, int newRangeEachDecade);

	virtual ~MeanLogDistribution();
	
	friend ostream& operator<<(ostream& o, MeanLogDistribution* co);
};

#endif

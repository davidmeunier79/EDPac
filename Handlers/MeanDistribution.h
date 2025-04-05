// MeanDistribution.h

#ifndef _MEAN_DISTRIBUTION_H
#define _MEAN_DISTRIBUTION_H

// C includes
#include <math.h>

// STL Includes
//#include <string>
//#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

// Local Includes
#include "Accumulater.h"
#include "Distribution.h"


/******************************************************************************************************************************************/
/***************************************************** Classe LogDistribution *************************************************************/
/******************************************************************************************************************************************/

class MeanDistribution: public Distribution
{
public:
	MeanDistribution();
	MeanDistribution(int nbAccus);
	
	virtual ~MeanDistribution();
	
	void initMeanDistribution();

	void accumulate(int index, double value);

	double getMean(int index);
	
	void accumulate(Distribution* curDistrib);
	void accumulate(MeanDistribution* curDistrib);

	void accumulateProba(Distribution* curDistrib);
	void accumulateCumulProba(Distribution* curDistrib);
	
	friend ostream& operator<<(ostream& o, MeanDistribution* co);
};

#endif

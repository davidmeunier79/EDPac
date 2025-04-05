// CumulatedDistribution.h

#ifndef _CUMULATED_DISTRIBUTION_H
#define _CUMULATED_DISTRIBUTION_H

// C includes
#include <math.h>

// STL Includes
//#include <string>
//#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

// Local Includes
#include "MeanDistribution.h"

/******************************************************************************************************************************************/
/************************************************* Classe CumulatedDistribution ***********************************************************/
/******************************************************************************************************************************************/

class CumulatedDistribution: public MeanDistribution
{
public:
	CumulatedDistribution();
	CumulatedDistribution(int nbAccus);
	
	virtual ~CumulatedDistribution();
	
	void cumulate(Distribution* curDistrib);
	void cumulate(MeanDistribution* curDistrib);
	
	friend ostream& operator<<(ostream& o, CumulatedDistribution* co);
};

#endif

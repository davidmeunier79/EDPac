// LogDistribution.h

#ifndef _LOG_DISTRIBUTION_H
#define _LOG_DISTRIBUTION_H

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

/******************************************************************************************************************************************/
/***************************************************** Classe LogDistribution *************************************************************/
/******************************************************************************************************************************************/

class LogDistribution : public Distribution
{
	int rangeEachDecade;
	int minLogRange;
	int maxLogRange;
public:
	
	LogDistribution();
	LogDistribution(int newMinLogRange, int newMaxLogRange, int newRangeEachDecade);

	virtual ~LogDistribution();

	void count(double value);
	
	double getMaxLogIndex();
	double getMeanLogIndex();
	
	double getLogIndex(int index);
	
	double getLogValue(int index);
	double getLogProbaValue(int index);
	double getLogCumulProbaValue(int index);
	
	friend ostream& operator<<(ostream& o, LogDistribution* co);
};

#endif

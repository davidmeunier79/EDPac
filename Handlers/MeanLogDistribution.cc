// MeanLogDistribution.cc

// Local Includes
#include "MeanLogDistribution.h"

/****************************************************************************************************************************************/
/******************************************************* Methodes de la classe MeanLogDistribution **********************************************/
/****************************************************************************************************************************************/

MeanLogDistribution::MeanLogDistribution()
{
}

MeanLogDistribution::MeanLogDistribution(int newMinLogRange, int newMaxLogRange, int newRangeEachDecade):MeanDistribution((newMaxLogRange-newMinLogRange+1)*newRangeEachDecade)
{
	if (newMinLogRange < newMaxLogRange)
	{
		maxLogRange = newMaxLogRange;
		minLogRange = newMinLogRange;
	}
	else
	{
		cerr << "Warning, newMaxLogRange should be higher than newMinLogRange" << endl;
	}

	if (0 <newRangeEachDecade)
	{
		rangeEachDecade = newRangeEachDecade;
	}
	else
	{
		cerr << "Warning, newRangeEachDecade should be stricly positive" << endl;
	}
}

MeanLogDistribution::~MeanLogDistribution()
{
}

ostream& operator<<(ostream& o, MeanLogDistribution* d)
{
	o << (MeanDistribution*) d << endl;
	
	return o;
}

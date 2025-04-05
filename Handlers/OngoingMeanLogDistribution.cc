// OngoingMeanLogDistribution.cc

// Local Includes
#include "OngoingMeanLogDistribution.h"

/****************************************************************************************************************************************/
/******************************************************* Methodes de la classe OngoingMeanLogDistribution **********************************************/
/****************************************************************************************************************************************/

OngoingMeanLogDistribution::OngoingMeanLogDistribution()
{
}

OngoingMeanLogDistribution::OngoingMeanLogDistribution(int nbOngoingDistrib, int newMinLogRange, int newMaxLogRange, int newRangeEachDecade)
{
	int count = 0;
	
	while (count < nbOngoingDistrib)
	{
		MeanLogDistribution* newLogDistrib = new MeanLogDistribution(newMinLogRange,newMaxLogRange,newRangeEachDecade);
		tabDistributions.push_back(newLogDistrib);
		count++;
	}
	
	//cumulatedDistribution = new LogDistribution(newMinLogRange,newMaxLogRange,newRangeEachDecade);
	cumulatedDistribution = new MeanLogDistribution(newMinLogRange,newMaxLogRange,newRangeEachDecade);
}

OngoingMeanLogDistribution::~OngoingMeanLogDistribution()
{
}

ostream& operator<<(ostream& o, OngoingMeanLogDistribution* d)
{
	o << (MeanDistribution*) d << endl;
	
	return o;
}

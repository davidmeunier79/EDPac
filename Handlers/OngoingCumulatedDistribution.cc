// OngoingCumulatedDistribution.cc

// Local Includes
#include "OngoingCumulatedDistribution.h"

/****************************************************************************************************************************************/
/******************************************************* Methodes de la classe OngoingCumulatedDistribution **********************************************/
/****************************************************************************************************************************************/

OngoingCumulatedDistribution::OngoingCumulatedDistribution()
{
}

OngoingCumulatedDistribution::OngoingCumulatedDistribution(int nbOngoingDistrib, int nbAccus)
{
	buildTabCumulatedDistributions(nbOngoingDistrib,nbAccus);
	buildCumulatedDistribution(nbAccus);
}

OngoingCumulatedDistribution::~OngoingCumulatedDistribution()
{
}

void OngoingCumulatedDistribution::buildCumulatedDistribution(int nbAccus)
{
	cumulatedDistribution = new CumulatedDistribution(nbAccus);
}
	
void OngoingCumulatedDistribution::initOngoingCumulatedDistribution()
{
	initTabMeanDistributions();
	initCumulatedDistribution();
}

void OngoingCumulatedDistribution::buildTabCumulatedDistributions(int nbOngoingDistrib, int nbAccus)
{
	int count = 0;

	while (count < nbOngoingDistrib)
	{
		CumulatedDistribution* newDistrib = new CumulatedDistribution(nbAccus);
		tabDistributions.push_back(newDistrib);
		count++;
	}
}

void OngoingCumulatedDistribution::ongoingCumulate(int ongoingIndex, MeanDistribution* curLogDistrib)
{
	if (0 <= ongoingIndex && ongoingIndex < tabDistributions.size())
	{
		((CumulatedDistribution*) tabDistributions[ongoingIndex])->cumulate((MeanDistribution*) curLogDistrib);
	}
	else
	{
		cerr << "Warning, ongoing index " << ongoingIndex << " out of range " << tabDistributions.size() << endl;
	}
}

MeanDistribution* OngoingCumulatedDistribution::getCumulatedDistribution()
{
	vector<Distribution*>::iterator it =tabDistributions.begin();
	vector<Distribution*>::iterator end =tabDistributions.end();
	
	while (it != end)
	{
		((CumulatedDistribution*) cumulatedDistribution)->cumulate((MeanDistribution*) *it);
		it++;
	}
	
	return ((MeanDistribution*) cumulatedDistribution);
}

ostream& operator<<(ostream& o, OngoingCumulatedDistribution* d)
{
	o << (OngoingMeanDistribution*) d << endl;
	
	return o;
}

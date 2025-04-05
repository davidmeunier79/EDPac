// OngoingMeanDistribution.cc

// Local Includes
#include "OngoingMeanDistribution.h"

/****************************************************************************************************************************************/
/******************************************************* Methodes de la classe OngoingMeanDistribution **********************************************/
/****************************************************************************************************************************************/

OngoingMeanDistribution::OngoingMeanDistribution()
{
}

OngoingMeanDistribution::OngoingMeanDistribution(int nbOngoingDistrib, int nbAccus)
{
	buildTabMeanDistributions(nbOngoingDistrib, nbAccus);	
	buildCumulatedDistribution(nbAccus);
}

OngoingMeanDistribution::~OngoingMeanDistribution()
{
}

void OngoingMeanDistribution::buildTabMeanDistributions(int nbOngoingDistrib, int nbAccus)
{
	int count = 0;

	while (count < nbOngoingDistrib)
	{
		MeanDistribution* newDistrib = new MeanDistribution(nbAccus);
		tabDistributions.push_back(newDistrib);
		count++;
	}

}

void OngoingMeanDistribution::initTabMeanDistributions()
{
	vector<Distribution*>::iterator it =tabDistributions.begin();
	vector<Distribution*>::iterator end =tabDistributions.end();
	
	while (it != end)
	{
		((MeanDistribution*) *it)->initMeanDistribution();
		it++;
	}
}
	
void OngoingMeanDistribution::initOngoingMeanDistribution()
{
	initTabMeanDistributions();
	initCumulatedDistribution();
}

void OngoingMeanDistribution::ongoingAccumulate(int ongoingIndex, Distribution* curLogDistrib)
{
	if (0 <= ongoingIndex && ongoingIndex < tabDistributions.size())
	{
		((MeanDistribution*) tabDistributions[ongoingIndex])->accumulate((Distribution*) curLogDistrib);
	}
	else
	{
		cerr << "Warning, ongoing index " << ongoingIndex << " out of range " << tabDistributions.size() << endl;
	}
}

void OngoingMeanDistribution::ongoingAccumulateProba(int ongoingIndex, Distribution* curLogDistrib)
{
	if (0 <= ongoingIndex && ongoingIndex < tabDistributions.size())
	{
		((MeanDistribution*) tabDistributions[ongoingIndex])->accumulateProba((Distribution*) curLogDistrib);
	}
	else
	{
		cerr << "Warning, ongoing index " << ongoingIndex << " out of range " << tabDistributions.size() << endl;
	}
}

void OngoingMeanDistribution::ongoingAccumulateCumulProba(int ongoingIndex, Distribution* curLogDistrib)
{
	if (0 <= ongoingIndex && ongoingIndex < tabDistributions.size())
	{
		((MeanDistribution*) tabDistributions[ongoingIndex])->accumulateCumulProba((Distribution*) curLogDistrib);
	}
	else
	{
		cerr << "Warning, ongoing index " << ongoingIndex << " out of range " << tabDistributions.size() << endl;
	}
}

MeanDistribution*  OngoingMeanDistribution::getMeanDistribution(int ongoingIndex)
{
	if (0 <= ongoingIndex && ongoingIndex < tabDistributions.size())
	{
		return ((MeanDistribution*) tabDistributions[ongoingIndex]);
	}
	else
	{
		cerr << "Warning, ongoing index " << ongoingIndex << " out of range " << tabDistributions.size() << endl;
	}
}

MeanDistribution* OngoingMeanDistribution::getCumulatedDistribution()
{
	vector<Distribution*>::iterator it =tabDistributions.begin();
	vector<Distribution*>::iterator end =tabDistributions.end();
	
	while (it != end)
	{
		((MeanDistribution*) cumulatedDistribution)->accumulate((MeanDistribution*) *it);
		it++;
	}
	
	return ((MeanDistribution*) cumulatedDistribution);
}

ostream& operator<<(ostream& o, OngoingMeanDistribution* d)
{
	o << (OngoingDistribution*) d << endl;
	
	return o;
}

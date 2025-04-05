// OngoingDistribution.cc

// Local Includes
#include "OngoingDistribution.h"

/****************************************************************************************************************************************/
/******************************************************* Methodes de la classe OngoingDistribution **********************************************/
/****************************************************************************************************************************************/

OngoingDistribution::OngoingDistribution()
{
}

OngoingDistribution::OngoingDistribution(int nbOngoingDistrib, int nbCounters)
{
	buildTabDistributions(nbOngoingDistrib, nbCounters);
	
	buildCumulatedDistribution(nbCounters);
}

OngoingDistribution::~OngoingDistribution()
{
	vector<Distribution*>::iterator it =tabDistributions.begin();
	vector<Distribution*>::iterator end =tabDistributions.end();
	
	while (it != end)
	{
		delete(*it);
		it++;
	}
	
	tabDistributions.erase(tabDistributions.begin(),tabDistributions.end());
	tabDistributions.clear();
	
	delete(cumulatedDistribution);
}

void OngoingDistribution::buildTabDistributions(int nbOngoingDistrib, int nbCounters)
{
	int count = 0;
	
	while (count < nbOngoingDistrib)
	{
		Distribution* newDistrib = new Distribution(nbCounters);
		tabDistributions.push_back(newDistrib);
		count++;
	}
	
}

void OngoingDistribution::initTabDistributions()
{
	vector<Distribution*>::iterator it =tabDistributions.begin();
	vector<Distribution*>::iterator end =tabDistributions.end();

	while (it != end)
	{
		((Distribution*) *it)->initDistribution();
		it++;
	}
}
	
void OngoingDistribution::buildCumulatedDistribution(int nbCounters)
{
	cumulatedDistribution = new MeanDistribution(nbCounters);
}
	
void OngoingDistribution::initCumulatedDistribution()
{
	cumulatedDistribution->initMeanDistribution();
}

void OngoingDistribution::initOngoingDistribution()
{
	initTabDistributions();
	
	initCumulatedDistribution();
}

void OngoingDistribution::ongoingCount(int ongoingIndex, int index)
{
	if (0 <= ongoingIndex && ongoingIndex < tabDistributions.size())
	{
		((Distribution*) tabDistributions[ongoingIndex])->count((int) index);
	}
	else
	{
		cerr << "Warning, ongoing index " << ongoingIndex << " out of range " << tabDistributions.size() << endl;
	}
}

Distribution* OngoingDistribution::getDistribution(int ongoingIndex)
{
	if (0 <= ongoingIndex && ongoingIndex < tabDistributions.size())
	{
		return ((Distribution*) tabDistributions[ongoingIndex]);
	}
	else
	{
		cerr << "Warning, ongoing index " << ongoingIndex << " out of range " << tabDistributions.size() << endl;
	}
}

MeanDistribution* OngoingDistribution::getCumulatedDistribution()
{
	vector<Distribution*>::iterator it =tabDistributions.begin();
	vector<Distribution*>::iterator end =tabDistributions.end();
	
	while (it != end)
	{
		((MeanDistribution*) cumulatedDistribution)->accumulate((Distribution*) *it);
		it++;
	}
	
	return ((MeanDistribution*) cumulatedDistribution);
}

ostream& operator<<(ostream& o, OngoingDistribution* d)
{
	vector<Distribution*>::iterator it =d->tabDistributions.begin();
	vector<Distribution*>::iterator end = d->tabDistributions.end();

	while (it != end)
	{

		o << (Distribution*) *it << endl;
		it++;
	}

	return o;
}

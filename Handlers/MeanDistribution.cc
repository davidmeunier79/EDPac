// MeanDistribution.cc

// Local Includes
#include "MeanDistribution.h"

/****************************************************************************************************************************************/
/******************************************************* Methodes de la classe MeanDistribution **********************************************/
/****************************************************************************************************************************************/

MeanDistribution::MeanDistribution()
{
}

MeanDistribution::MeanDistribution(int nbAccus)
{
	int countAccus = 0;
	
	while (countAccus < nbAccus+1)
	{
		Accumulater* curAccumulater = new Accumulater();
		tabCounters.push_back((Accumulater*) curAccumulater);
		countAccus++;
	}
}

MeanDistribution::~MeanDistribution()
{
	vector<Counter*>::iterator it = tabCounters.begin();
	vector<Counter*>::iterator end = tabCounters.end();
	
	while (it != end)
	{
		delete((Accumulater*) *it);
		it++;
	}
	
	tabCounters.erase(tabCounters.begin(),tabCounters.end());
	tabCounters.clear();
}

void MeanDistribution::initMeanDistribution()
{
	vector<Counter*>::iterator it = tabCounters.begin();
	vector<Counter*>::iterator end = tabCounters.end();
	
	while (it != end)
	{
		((Accumulater*) *it)->initAccu();
		it++;
	}
}

void MeanDistribution::accumulate(int index, double value)
{
	if (0<= index && index < tabCounters.size())
	{	
		
		((Accumulater*) tabCounters[index])->accumulate((double) value);
	}
	else
	{
		cerr << "Warning, incompatible index for count" << endl;
	}
}

double MeanDistribution::getMean(int index)
{
	if (0 <= index && index < tabCounters.size())
	{
		return ((double) ((Accumulater*) tabCounters[index])->getMean());
	}
	else
	{
		cerr << "Warning, index " << index << " out of range" << endl;
	}
}

void MeanDistribution::accumulate(Distribution* curDistrib)
{
	if (curDistrib->getNbCounters() == tabCounters.size())
	{	
		vector<Counter*>::iterator it = tabCounters.begin();
		vector<Counter*>::iterator end = tabCounters.end();
		
		int count=0;
		
		while (it != end)
		{
			((Accumulater*) *it)->accumulate((double) curDistrib->getCount(count));

			count++;
			it++;
		}
	}
	else
	{
		cerr << "Warning, incompatible size for curDistrib " << curDistrib->getNbCounters() << " " << tabCounters.size() << endl;
	}
}

void MeanDistribution::accumulate(MeanDistribution* curDistrib)
{
	if (curDistrib->getNbCounters() == tabCounters.size())
	{	
		vector<Counter*>::iterator it = tabCounters.begin();
		vector<Counter*>::iterator end = tabCounters.end();
		
		vector<Counter*>::iterator it2 = curDistrib->tabCounters.begin();
		vector<Counter*>::iterator end2 = curDistrib->tabCounters.end();

		while (it != end)
		{
			((Accumulater*) *it)->accumulate((double) ((Accumulater*) *it2)->getMean());

			it++;
			it2++;
		}
	}
	else
	{
		cerr << "Warning, incompatible size for curDistrib " << curDistrib->getNbCounters()  << " " << tabCounters.size() << endl;
	}
}

void MeanDistribution::accumulateProba(Distribution* curDistrib)
{
	if (curDistrib->getNbCounters() == tabCounters.size())
	{	
		vector<Counter*>::iterator it = tabCounters.begin();
		vector<Counter*>::iterator end = tabCounters.end();
		
		int count=0;
		
		while (it != end)
		{
			((Accumulater*) *it)->accumulate((double) curDistrib->getProba(count));
			count++;
			it++;
		}
	}
	else
	{
		cerr << "Warning, incompatible size for curDistrib " << curDistrib->getNbCounters()  << " " << tabCounters.size() << endl;
	}
}

void MeanDistribution::accumulateCumulProba(Distribution* curDistrib) 
{
	if (curDistrib->getNbCounters() == tabCounters.size())
	{	
		vector<Counter*>::iterator it = tabCounters.begin();
		vector<Counter*>::iterator end = tabCounters.end();
		
		int count=0;
		
		while (it != end)
		{
			((Accumulater*) *it)->accumulate((double) curDistrib->getCumulProba(count));
			count++;
			it++;
		}
	}
	else
	{
		cerr << "Warning, incompatible size for curDistrib " << curDistrib->getNbCounters()  << " " << tabCounters.size() << endl;
	}
}

ostream& operator<<(ostream& o, MeanDistribution* d)
{
	vector<Counter*>::iterator it = d->tabCounters.begin();
	vector<Counter*>::iterator end = d->tabCounters.end();
		
	while (it != end)
	{
		o << (Accumulater*) *it << ends;
	}
	
	o << endl;
	
	return o;
}

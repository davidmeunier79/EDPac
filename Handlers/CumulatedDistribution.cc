// CumulatedDistribution.cc

// Local Includes
#include "CumulatedDistribution.h"

/****************************************************************************************************************************************/
/******************************************************* Methodes de la classe CumulatedDistribution **********************************************/
/****************************************************************************************************************************************/

CumulatedDistribution::CumulatedDistribution()
{
}

CumulatedDistribution::CumulatedDistribution(int nbAccus): MeanDistribution(nbAccus)
{
}

CumulatedDistribution::~CumulatedDistribution()
{
}

void CumulatedDistribution::cumulate(Distribution* curDistrib)
{
	if (curDistrib->getNbCounters() == tabCounters.size())
	{	
		vector<Counter*>::iterator it = tabCounters.begin();
		vector<Counter*>::iterator end = tabCounters.end();
		
		int count=0;
		
		while (it != end)
		{
			if (curDistrib->getCount(count) != 0)
			{
				((Accumulater*) *it)->accumulate((double) curDistrib->getCount(count));
			}
			
			count++;
			it++;
		}
	}
	else
	{
		cerr << "Warning, incompatible size for curDistrib " << curDistrib->getNbCounters() << " " << tabCounters.size() << endl;
	}
}

void CumulatedDistribution::cumulate(MeanDistribution* curDistrib)
{
	if (curDistrib->getNbCounters() == tabCounters.size())
	{	
		vector<Counter*>::iterator it = tabCounters.begin();
		vector<Counter*>::iterator end = tabCounters.end();
		
		int count=0;
		
		while (it != end)
		{
			if (curDistrib->getCount(count) != 0)
			{
				((Accumulater*) *it)->accumulate((double) curDistrib->getMean(count));
			}

			count++;
			it++;
		}
	}
	else
	{
		cerr << "Warning, incompatible size for curDistrib " << curDistrib->getNbCounters()  << " " << tabCounters.size() << endl;
	}
}

ostream& operator<<(ostream& o, CumulatedDistribution* d)
{
	o << (MeanDistribution*) d <<  endl;
	
	return o;
}

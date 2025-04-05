// Distribution.cc

// Local Includes
#include "Distribution.h"

/****************************************************************************************************************************************/
/******************************************************* Methodes de la classe Distribution **********************************************/
/****************************************************************************************************************************************/

Distribution::Distribution()
{
	initCounter();
}

Distribution::Distribution(int nbCounters)
{
	int countCounters=0;
	while (countCounters < nbCounters+1)
	{
		Counter* curCounter = new Counter;
		tabCounters.push_back((Counter*) curCounter);
		countCounters++;
	}
	
	initCounter();
}

Distribution::~Distribution()
{
	vector<Counter*>::iterator it = tabCounters.begin();
	vector<Counter*>::iterator end = tabCounters.end();
	
	while (it != end)
	{
		delete((Counter*) *it);
		it++;
	}
	
	tabCounters.erase(tabCounters.begin(),tabCounters.end());
	tabCounters.clear();

}

void Distribution::initDistribution()
{
	vector<Counter*>::iterator it = tabCounters.begin();
	vector<Counter*>::iterator end = tabCounters.end();
	
	while (it != end)
	{
		((Counter*) *it)->initCounter();
		it++;
	}
	
	initCounter();
}

void Distribution::count(int index)
{
	if (0 <= index && index < tabCounters.size())
	{
		((Counter*) tabCounters[index])->count();
		counter++;
	}
	else
	{
		cerr << "Warning, index " << index << " out of range" << endl;
	}
}

void Distribution::count(int index, int value)
{
	if (0 <= index && index < tabCounters.size())
	{
		((Counter*) tabCounters[index])->countSeveral((int) value);
		countSeveral((int) value);
	}
	else
	{
		cerr << "Warning, index " << index << " out of range" << endl;
	}
}
void Distribution::countDistrib(Distribution* curDistrib)
{
	if (curDistrib->getNbCounters() == tabCounters.size())
	{	
		vector<Counter*>::iterator it = tabCounters.begin();
		vector<Counter*>::iterator end = tabCounters.end();
		
		int count=0;
		
		//cout << "Before: " << endl;
		//cout << (Distribution*) this << endl;
		
		while (it != end)
		{
			((Counter*) *it)->countSeveral((int) curDistrib->getCount(count));
			count++;
			it++;
		}
		
		countSeveral((int) curDistrib->getCounter());
		//cout << "After: " << endl;
		//cout << (Distribution*) this << endl;
	}
	else
	{
		cerr << "Warning, incompatible size for curDistrib " << curDistrib->getNbCounters() << " " << tabCounters.size() << endl;
	}
}

int Distribution::getCount(int index)
{
	if (0 <= index && index < tabCounters.size())
	{
		return ((int) ((Counter*) tabCounters[index])->getCounter());
	}
	else
	{
		cerr << "Warning, index " << index << " out of range" << endl;
	}
}

int Distribution::getCumulCount(int index)
{
	if (0 <= index && index < tabCounters.size())
	{
		vector<Counter*>::iterator it = tabCounters.begin();
		vector<Counter*>::iterator end = tabCounters.end();

		int cumulCount =0;
		int count = 0;

		while (it != end)
		{
			if (index <= count)
			{
				cumulCount += ((Counter*) *it)->getCounter();
			}
			it++;
			count++;
		}

		return (((int) cumulCount));

	}
	else
	{
		cerr << "Warning, index " << index << " out of range" << endl;
	}
}

int Distribution::getMaxIndex()
{
	vector<Counter*>::iterator it = tabCounters.begin();
	vector<Counter*>::iterator end = tabCounters.end();
		
	int maxIndex = 0;
	int index = 0;
	
	while (it != end)
	{
		if (0 < ((Counter*) *it)->getCounter())
		{
			maxIndex = index;
		}
		index++;
		it++;
	}
	
	return maxIndex;
}

double Distribution::getMeanIndex()
{
	vector<Counter*>::iterator it = tabCounters.begin();
	vector<Counter*>::iterator end = tabCounters.end();
		
	int meanValue = 0;
	int index = 0;
	
	while (it != end)
	{
		meanValue += index*((Counter*) *it)->getCounter();

		index++;
		it++;
	}
	
	return (((double) meanValue)/((double) getCounter()));
}

double Distribution::getProba(int index)
{
	if (0 <= index && index < tabCounters.size())
	{
		if (getCounter() != 0)
		{
			return (((double) tabCounters[index]->getCounter())/(double) getCounter());
		}
		else
		{
			return 0.0;
		}
	}
	else
	{
		cerr << "Warning, index " << index << " out of range" << endl;
	}
}

double Distribution::getCumulProba(int index)
{
	if (0 <= index && index < tabCounters.size())
	{
		if (getCounter() != 0)
		{
			vector<Counter*>::iterator it = tabCounters.begin();
			vector<Counter*>::iterator end = tabCounters.end();

			int cumulCount =0;
			int count = 0;

			while (it != end)
			{
				if (index <= count)
				{
					cumulCount += ((Counter*) *it)->getCounter();
				}
				it++;
				count++;
			}

			return (((double) cumulCount)/(double) getCounter());
		}
		else
		{
			return 0.0;
		}
	}
	else
	{
		cerr << "Warning, index " << index << " out of range" << endl;
	}
}

int Distribution::getNbCounters()
{
	return (tabCounters.size());
}

ostream& operator<<(ostream& o, Distribution* d)
{
	vector<Counter*>::iterator it = d->tabCounters.begin();
	vector<Counter*>::iterator end = d->tabCounters.end();
		
	int count = 0;
	while (it != end)
	{
		o << count << " " << (Counter*) *it << endl;
		count++;
		it++;
	}
	
	o << "Counter: " << d->getCounter() << endl;
	
	return o;
}

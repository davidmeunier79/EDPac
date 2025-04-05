// LogDistribution.cc

// Local Includes
#include "LogDistribution.h"

/****************************************************************************************************************************************/
/******************************************************* Methodes de la classe LogDistribution **********************************************/
/****************************************************************************************************************************************/

LogDistribution::LogDistribution()
{
}

LogDistribution::LogDistribution(int newMinLogRange, int newMaxLogRange, int newRangeEachDecade):Distribution((newMaxLogRange-newMinLogRange+1)*newRangeEachDecade)
{
	if (newMinLogRange < newMaxLogRange)
	{
		maxLogRange = newMaxLogRange;
		minLogRange = newMinLogRange;
	}
	else
	{
		cerr << "Warning, newMaxLogRange should be strictly higher than newMinLogRange" << endl;
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

LogDistribution::~LogDistribution()
{
}

void LogDistribution::count(double value)
{
	//cout << "value: " << value << endl;
	
	if (0 <= value)
	{
		if (((double) exp10(minLogRange)) <= value)
		{	
			//cout << "log: " << log10(value) << endl;

			int index = (int) ((double) ((double) ((double) log10(((double) value)) - (double) minLogRange))*((double) rangeEachDecade));
			
			//cout << "index: " << index << endl;
			
			Distribution::count((int) index);
			
		}
		else
		{
			//cerr << "Adding value to first index of distribution " << endl;
			Distribution::count((int) 0);
		}
	}
	else
	{
		cerr << "Warning, value is negative, can't take the log" << endl;
	}
}

double LogDistribution::getMaxLogIndex()
{
	return ((double) exp10(((double) getMaxIndex())/((double) rangeEachDecade) + ((double) minLogRange)));
}

double LogDistribution::getMeanLogIndex()
{
	vector<Counter*>::iterator it = tabCounters.begin();
	vector<Counter*>::iterator end = tabCounters.end();
		
	double meanIndex = 0.0;
	int index = 0;
	
	while (it != end)
	{
		meanIndex += getLogIndex(index)*((Counter*) *it)->getCounter();

		index++;
		it++;
	}
	
	return (((double) meanIndex)/((double) getCounter()));
}

double LogDistribution::getLogIndex(int index)
{
	return (((double) index)/((double) rangeEachDecade) + ((double) minLogRange));
}


double LogDistribution::getLogValue(int index)
{
	if (((double) exp10(-5.0)) < (double) getCount(index))
	{
		return ((double) log10((double) getCount(index)));
	} 
	else
	{
		return (-5.0);
	}
}

double LogDistribution::getLogProbaValue(int index)
{
	if (((double) exp10(-5.0)) < getProba(index))
	{
		//cout << "index" << index << " " << getProba(index) << endl;
		return ((double) log10(getProba(index)));
	} 
	else
	{
		return (-5.0);
	}
}

double LogDistribution::getLogCumulProbaValue(int index)
{
	if (((double) exp10(-5.0)) < getCumulProba(index))
	{
		//cout << "index" << index << " " << getCumulProba(index) << endl;
		return ((double) log10(getCumulProba(index)));
	} 
	else
	{
		return (-5.0);
	}
}

ostream& operator<<(ostream& o, LogDistribution* d)
{
	o << (Distribution*) d;
	return o;
}

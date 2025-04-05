// Accumulater.cc

// Local Includes
#include "Accumulater.h"

/****************************************************************************************************************************************/
/******************************************************* Methodes de la classe Accumulater **********************************************/
/****************************************************************************************************************************************/

Accumulater::Accumulater()
{
	initAccu();
}

Accumulater::~Accumulater()
{
}

void Accumulater::initAccu()
{
	initCounter();
	accu=0.0;
	accuSquare = 0.0;
	
	best=0.0;
	lowest=RAND_MAX;
}

void Accumulater::accumulate(double value)
{
	if (0.0 <= value)
	{
		if (best<value)
		{
			best=value;
		}
		
		if (accu == 0.0)
		{
			lowest = value;
		}
		else if (value<lowest)
		{
			lowest=value;
		}
		
		accu+=value;
		accuSquare+=value*value;
		
		counter++;
		
	}
	else
	{
		cerr << "Warning, accumulater only stores positive values, value = " << value << endl;
	}
}

double Accumulater::getAccu()
{
	if (!isVoid())
	{
		return accu;
	}
	else
	{
		return -1.0;
	}
}

double Accumulater::getMean()
{
	if (!isVoid())
	{
		if (counter)
		{
			return (accu/((double) counter));
		}
		else
		{
			return 0.0;
		}
	}
	else
	{
		return -1.0;
	}
}

double Accumulater::getLogMean()
{
	if (((double) exp10(-5.0)) < getMean())
	{
		return ((double) log10(getMean()));
	} 
	else
	{
		return (-5.0);
	}
}

double Accumulater::getMeanSquare()
{
	if (!isVoid())
	{
		if (counter)
		{
			return (accuSquare/((double) counter));
		}
		else
		{
			return 0.0;
		}
	}
	else
	{
		return -1.0;
	}
}

double Accumulater::getStd()
{
	if (!isVoid())
	{
		if (counter)
		{
			return ((double) sqrt(getMeanSquare() - getMean()*getMean()));
		}
		else
		{
			return 0.0;
		}
	}
	else
	{
		return -1.0;
	}
}

double Accumulater::getStdMax()
{
	if (!isVoid())
	{
		if (counter)
		{
			return ((double) getMean() + (double) getStd()/2.0);
		}
		else
		{
			return 0.0;
		}
	}
	else
	{
		return -1.0;
	}
}

double Accumulater::getStdMin()
{
	if (!isVoid())
	{
		if (counter)
		{
			return ((double) getMean() - (double) getStd()/2.0);
		}
		else
		{
			return 0.0;
		}
	}
	else
	{
		return -1.0;
	}
}

double Accumulater::getBest()
{
	return best;
}

double Accumulater::getLowest()
{
	if (counter)
	{
		return lowest;
	}
	else
	{
		return 0.0;
	}
}

ostream& operator<<(ostream& o, Accumulater* acc)
{
	//o << acc->accu << " (mean = " << acc->getMean() << " for " << acc->counter << " objects)";
	o << acc->accu;
	return o;
}


istream& operator>>(istream& i, Accumulater* acc)
{
	int readAccu;
	if (i >> readAccu)
	{
		acc->accu = readAccu;
		
		cout << "Loaded accu " << acc->accu << endl;
	}
	else
	{
		cerr << "Warning, unable to load accu value: " << readAccu << endl;
	}
	return i;
}

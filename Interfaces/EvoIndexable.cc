// EvoIndexableObject.cc

// Local Includes
#include "EvoIndexable.h"

/****************************************************************************************************************************************/
/*********************************************** Methodes de la classe EvoIndexableObject ************************************************/
/****************************************************************************************************************************************/

int EvoIndexable::evoIndex=0;

EvoIndexable::EvoIndexable()
{
}

EvoIndexable::~EvoIndexable()
{
}

void EvoIndexable::incrementEvoIndex()
{
	evoIndex++;
}

void EvoIndexable::decrementEvoIndex()
{
	evoIndex--;
}

void EvoIndexable::initEvoIndex()
{
	evoIndex=0;
}

int EvoIndexable::getEvoIndex()
{
	return evoIndex;
}

istream& operator>>(istream& i, EvoIndexable* evo)
{
	int readEvoIndex;
	if (i >> readEvoIndex)
	{
		if (readEvoIndex != evo->getEvoIndex())
		{ 
			cerr << "Warning, evoIndex (" << evo->getEvoIndex() << ") != readEvoIndex (" <<  readEvoIndex << ")" << endl;
		}
	}
	else
	{
		cerr << "Warning, wrong evo index " << readEvoIndex << " (" << evo->getEvoIndex() << ") " << endl;
	}
	
	return i;
}

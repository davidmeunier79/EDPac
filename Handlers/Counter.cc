// Counter.cc

// Local Includes
#include "Counter.h"

/****************************************************************************************************************************************/
/******************************************************* Methodes de la classe Counter **********************************************/
/****************************************************************************************************************************************/

Counter::Counter()
{
	//initCounter();
	freeVoid();

	counter=0;
}

Counter::~Counter()
{
}

void Counter::count()
{
	counter++;
}

void Counter::countSeveral(int value)
{
	if (0 <= value)
	{
		counter+=value;
	}
	else
	{
		cerr << "Warning, in countSeveral, value " << value << " is negative" << endl;
	}
}

void Counter::freeVoid()
{
	voidCounter=0;
}

int Counter::getCounter()
{
	if (!voidCounter)
	{
		return counter;
	}
	else
	{
		return -1;
	}
}

void Counter::initCounter()
{
	counter=0;
}

void Counter::setVoid()
{
	voidCounter=1;
}

bool Counter::isVoid()
{
	return voidCounter;
}

ostream& operator<<(ostream& o, Counter* co)
{
	o << co->counter << ends;
	return o;
}

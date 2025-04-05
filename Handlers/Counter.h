// Counter.h

#ifndef _COUNTER_H
#define _COUNTER_H

// STL Includes
//#include <string>
//#include <fstream>
#include <iostream>
using namespace std;

// Local Includes
#include "../Objets/Object.h"

/******************************************************************************************************************************************/
/******************************************************* Classe Counter *************************************************************/
/******************************************************************************************************************************************/

class Counter: public Object
{
	bool voidCounter;
protected:
	int counter;
public:
	Counter();
	virtual ~Counter();

	void count();
	void countSeveral(int value);
	
	int getCounter();

	void freeVoid();
	
	void initCounter();
	void setVoid();
	bool isVoid();
	
	friend ostream& operator<<(ostream& o, Counter* co);
};

#endif

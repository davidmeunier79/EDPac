// EvoIndexable.h

#ifndef _EVO_INDEXABLE_H
#define _EVO_INDEXABLE_H

//#include <stdio.h>

// STL Includes
#include <iostream>
using namespace std;

/******************************************************************************************************************************************/
/*********************************************************** Classe EvoIndexable **********************************************************/
/******************************************************************************************************************************************/

class EvoIndexable
{
	static int evoIndex;
public:

	EvoIndexable();
	~EvoIndexable();

	//friend class EvoObject;

	static void incrementEvoIndex();
	static void decrementEvoIndex();

	static void initEvoIndex();

	static int getEvoIndex();

	friend istream& operator>>(istream& i, EvoIndexable* evo);
};

#endif

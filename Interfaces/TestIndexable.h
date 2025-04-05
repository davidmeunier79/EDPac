// TestIndexable.h

#ifndef _TEST_INDEXABLE_H
#define _TEST_INDEXABLE_H

// STL Includes
#include <iostream>
using namespace std;

/******************************************************************************************************************************************/
/********************************************************** Classe EvalIndexable **********************************************************/
/******************************************************************************************************************************************/

class TestIndexable
{
	static int testIndex;
public:

	TestIndexable();
	~TestIndexable();

	static void incrementTestIndex();
	static void initTestIndex();

	static int getTestIndex();
};

#endif

// TestIndexable.cc

// Local Includes
#include "TestIndexable.h"

/****************************************************************************************************************************************/
/*********************************************** Methodes de la classe TestIndexable ****************************************************/
/****************************************************************************************************************************************/

int TestIndexable::testIndex=0;

TestIndexable::TestIndexable()
{
}

TestIndexable::~TestIndexable()
{
}

void TestIndexable::incrementTestIndex()
{
	testIndex++;
}

void TestIndexable::initTestIndex()
{
	testIndex=0;
}

int TestIndexable::getTestIndex()
{
	return testIndex;
}

// Testable.cc

// Local Includes
#include "Testable.h"

/****************************************************************************************************************************************/
/**************************************************** Methodes de la classe Testable ****************************************************/
/****************************************************************************************************************************************/
Testable::Testable()
{
	tester=0;
}

Testable::~Testable()
{
	tester=0;
}

void Testable::initTester()
{
	cerr << "Warning, accessing Testable::initTester virtual method" << endl;
}

void Testable::test(Object* obj)
{
	cerr << "Warning, accessing Testable::test virtual method" << endl;
}


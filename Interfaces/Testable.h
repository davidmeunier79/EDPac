// Testable.h

#ifndef _TESTABLE_H
#define _TESTABLE_H

// Local Includes
#include "../Objets/Object.h"

#include "../Interfaces/TestIndexable.h"
#include "../Handlers/Tester.h"

// STL Includes
#include <string>
#include <fstream>
using namespace std;

/******************************************************************************************************************************************/
/******************************************************** Classe Testable *****************************************************************/
/******************************************************************************************************************************************/

class Testable: public TestIndexable
{
protected:

	Tester* tester;
public:
	Testable();
	~Testable();
	
	virtual void initTester();
	virtual void test(Object* obj);
};

#endif

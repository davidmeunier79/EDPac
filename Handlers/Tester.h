// Tester.h

#ifndef _TESTER_H
#define _TESTER_H

// Local Includes
#include "../Objets/Object.h"

//#include "Handler.h"

// STL Includes
#include <string>
#include <fstream>
using namespace std;

/******************************************************************************************************************************************/
/********************************************************** Classe Tester ***************************************************************/
/******************************************************************************************************************************************/

class Tester //: public Handler
{
/*
	virtual void openStater();
	virtual void closeStater();
*/	
/*
	virtual void openTracer();
	virtual void closeTracer();

	virtual void openGrapher();
	virtual void runGrapher();
	virtual void closeGrapher();
*/
public:
	Tester();
	virtual ~Tester();

	virtual void test(Object* obj);

	//virtual void openTester();
	//virtual void closeTester();
};

#endif

// TestLab.h

#ifndef _TEST_LAB_H
#define _TEST_LAB_H

// STL includes
#include <iostream>

// Local Includes
#include "../Define.h"
#include "../DefineZoo.h"
#include "../DefineGA.h"
#include "../DefineTracer.h"
#include "../DefineGrapher.h"
#include "../DefineStater.h"

#include "../DefineTester.h"

#include "Pacman.h"
#include "Menagerie.h"

#include "Zoo.h"

/******************************************************************************************************************************************/
/**************************************************************** Classe Zoo **************************************************************/
/******************************************************************************************************************************************/

class TestLab: public Zoo
{
public :
	TestLab();
	~TestLab();
#ifdef _TEST_MODE
	virtual void initTestZoo(int level);

	//virtual void vivre(Pacman* pac);

	void getAnimalPosition(int& x,int &y);

	virtual void testAvancer(Pacman* pac);

	virtual bool testMort(Pacman* pac);
#endif
};
#endif

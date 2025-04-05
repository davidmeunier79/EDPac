// ZooDisplayer.h

#ifndef _ZOO_DISPLAYER_H
#define _ZOO_DISPLAYER_H

//#include <stdio.h>

// STL Includes
#include <iostream>
#include <list>
#include <iterator>
using namespace std;

// Local Includes
#include "../Define.h"
#include "../DefineZoo.h"
#include "../DefineWindow.h"

#include "../Zoo/Zoo.h"

#include "../Handlers/Displayer.h"

/******************************************************************************************************************************************/
/************************************************************ Classe ZooDisplayer *********************************************************/
/******************************************************************************************************************************************/

class ZooDisplayer: public Displayer
{
	Fenetre* zooWindow;
	
public:
	friend class Zoo;
	friend class Pacman;

	ZooDisplayer();
	~ZooDisplayer();

	void flushDisplay();
	void cleanDisplay();

	void initDisplayer(Zoo* zoo);

	void displayVoid(int posX, int posY);
	void displayDot(int posX, int posY);

	void display(string etiquette,int x, int y);

	void displayDirMvt(Pacman* pac);
	void displayDirVue(Pacman* pac);
	
	void saveZooDisplayer(int nbSteps);

};
#endif


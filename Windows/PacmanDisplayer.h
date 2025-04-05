// PacmanDisplayer.h

#ifndef _FENETRE_RESEAU_H
#define _FENETRE_RESEAU_H

// Local Includes
#include "../Define.h"
#include "../DefineZoo.h"
#include "../DefineWindow.h"
 
#include "../Zoo/Pacman.h"

#include "../Handlers/Displayer.h"

#include "../Zoo/Animal.h"

#include "../Zoo/Image.h"
#include "../Zoo/Son.h"


/******************************************************************************************************************************************/
/************************************************************ Classe PacmanDisplayer ********************************************************/
/******************************************************************************************************************************************/

// cette fenetre servira a afficher les differentes infos liees aux reseaux
class PacmanDisplayer : public Displayer
{
private :
	//static PacmanDisplayer* thePacmanDisplayer;

	Fenetre* pacmanWindow;

	friend class Pacman;

public :
	PacmanDisplayer();
	~PacmanDisplayer();

	void flushDisplay();
	void cleanDisplay();

	#ifdef _GRAPHICAL_DISPLAY_MODE
	void setObjetAVoir(const Image *,int,int,int);
	void setObjetAEntendre(const Son *,int,int,int);
	#endif

	//static PacmanDisplayer* initPacmanDisplayer();
	//static void endPacmanDisplayer();
};

#endif

// PacmanDisplayer.cc

#include "PacmanDisplayer.h"

/*********************************************************************************************/
/*                                                                                           */
/*                       Definitions des methodes de FentreReseau                            */
/*                                                                                           */
/*********************************************************************************************/

//PacmanDisplayer* PacmanDisplayer::thePacmanDisplayer=0;

PacmanDisplayer::PacmanDisplayer()
{
#ifdef _GRAPHICAL_DISPLAY_MODE
	pacmanWindow = new Fenetre();
	
	pacmanWindow->setDimensions(
	MARGIN+NB_VISIO_INPUTS*(VISIO_GRAPHICAL_SIZE*5+MARGIN)+MARGIN+NB_AUDIO_INPUTS*AUDIO_GRAPHICAL_SIZE*AUDIO_GRAPHICAL_SIZE/2+MARGIN,
	3*MARGIN+VISIO_GRAPHICAL_SIZE*5
	);
	char titre[50];
	sprintf(titre,"Pacman inputs");
	pacmanWindow->setTitre(titre);
	pacmanWindow->setIconeTitre(titre);
	pacmanWindow->setPosition(0,0);
#endif
}

PacmanDisplayer::~PacmanDisplayer()
{
	delete(pacmanWindow);
}

void PacmanDisplayer::flushDisplay()
{
	pacmanWindow->redessine();
}

void PacmanDisplayer::cleanDisplay()
{
	pacmanWindow->effacer();
}

#ifdef _GRAPHICAL_DISPLAY_MODE
void PacmanDisplayer::setObjetAVoir(const Image * objetAIdentifier,int i,int j, int colonne)
{
	if(objetAIdentifier)
	{
		// affiche l'image
		for(int x=0;x<VISIO_GRAPHICAL_SIZE;x++)
		{
			for(int y=0;y<VISIO_GRAPHICAL_SIZE;y++)
			{
				//cerr << "Displaying pixel" << x << " " << y << endl;

				pacmanWindow->colorierZone(MARGIN+(MARGIN+5*VISIO_GRAPHICAL_SIZE)*colonne+5*x,MARGIN+5*y, 5, 5, "blanc");
		
				if(objetAIdentifier->getValeur(x,y)==1)
				{
					pacmanWindow->colorierZone(MARGIN+(MARGIN+5*VISIO_GRAPHICAL_SIZE)*colonne+5*x,MARGIN+5*y, 5, 5, "gris");
				}
			}
		}
	
		// on affiche le texte
		char texte[50];
		pacmanWindow->colorierZone(MARGIN+(MARGIN+5*VISIO_GRAPHICAL_SIZE)*colonne,MARGIN+5*VISIO_GRAPHICAL_SIZE,MARGIN+5*VISIO_GRAPHICAL_SIZE,2*MARGIN, "blanc");
		sprintf(texte,"Vu en (%i,%i)",j,-i);
		pacmanWindow->afficheTexte(texte,MARGIN+colonne*(MARGIN+5*VISIO_GRAPHICAL_SIZE),2*MARGIN+5*VISIO_GRAPHICAL_SIZE,"noir");
	}
	else
	{
		for(int x=0;x<VISIO_GRAPHICAL_SIZE;x++)
		{
			for(int y=0;y<VISIO_GRAPHICAL_SIZE;y++)
			{
				pacmanWindow->colorierZone(20+(MARGIN+5*VISIO_GRAPHICAL_SIZE)*colonne+5*x, MARGIN+5*y, 5, 5, "blanc");
			}
		}
		// on n'affiche que le texte
		pacmanWindow->colorierZone(MARGIN+(MARGIN+5*VISIO_GRAPHICAL_SIZE)*colonne,MARGIN+5*VISIO_GRAPHICAL_SIZE,MARGIN+5*VISIO_GRAPHICAL_SIZE,2*MARGIN, "blanc");
		pacmanWindow->afficheTexte("Rien Vu",MARGIN+(MARGIN+5*VISIO_GRAPHICAL_SIZE)*colonne,2*MARGIN+5*VISIO_GRAPHICAL_SIZE,"noir");
	}
}

void PacmanDisplayer::setObjetAEntendre(const Son * objetAIdentifier,int i,int j, int index)
{
	if(objetAIdentifier)
	{
		// affiche le son
		for(int x=0;x<AUDIO_GRAPHICAL_SIZE*AUDIO_GRAPHICAL_SIZE;x++)
		{
			// Efface le trait précédent
			pacmanWindow->traceLigne(
			MARGIN+NB_VISIO_INPUTS*(5*VISIO_GRAPHICAL_SIZE+MARGIN)+MARGIN+index*AUDIO_GRAPHICAL_SIZE*AUDIO_GRAPHICAL_SIZE/2+x/2,
			5*VISIO_GRAPHICAL_SIZE+MARGIN,
			MARGIN+NB_VISIO_INPUTS*(5*VISIO_GRAPHICAL_SIZE+MARGIN)+MARGIN+index*AUDIO_GRAPHICAL_SIZE*AUDIO_GRAPHICAL_SIZE/2+x/2,
			MARGIN,
			"blanc");

			// Trace le nouveau trait
			pacmanWindow->traceLigne(
			MARGIN+NB_VISIO_INPUTS*(5*VISIO_GRAPHICAL_SIZE+MARGIN)+MARGIN+index*AUDIO_GRAPHICAL_SIZE*AUDIO_GRAPHICAL_SIZE/2+x/2,
			MARGIN+5*VISIO_GRAPHICAL_SIZE,
			MARGIN+NB_VISIO_INPUTS*(5*VISIO_GRAPHICAL_SIZE+MARGIN)+MARGIN+index*AUDIO_GRAPHICAL_SIZE*AUDIO_GRAPHICAL_SIZE/2+x/2,
			MARGIN+5*VISIO_GRAPHICAL_SIZE-static_cast<int>((*objetAIdentifier)[x]*VISIO_GRAPHICAL_SIZE*5),
			"gris");
		}

		// on affiche le texte
		char texte[50];
		sprintf(texte,"Entendu (%i,%i)",j,-i);

		pacmanWindow->colorierZone(
		MARGIN+NB_VISIO_INPUTS*(5*VISIO_GRAPHICAL_SIZE+MARGIN)+MARGIN+index*AUDIO_GRAPHICAL_SIZE/2,
		MARGIN+5*VISIO_GRAPHICAL_SIZE,
		AUDIO_GRAPHICAL_SIZE/2,
		2*MARGIN,
		"blanc");

		pacmanWindow->afficheTexte(
		texte,
		MARGIN+NB_VISIO_INPUTS*(5*VISIO_GRAPHICAL_SIZE+MARGIN)+MARGIN+index*AUDIO_GRAPHICAL_SIZE*AUDIO_GRAPHICAL_SIZE/2,
		MARGIN*2+5*VISIO_GRAPHICAL_SIZE,
		"noir");
	}
	else
	{
		// On efface la zone de son
		pacmanWindow->colorierZone(
		MARGIN+(MARGIN+5*VISIO_GRAPHICAL_SIZE)*NB_VISIO_INPUTS+MARGIN+index*AUDIO_GRAPHICAL_SIZE*AUDIO_GRAPHICAL_SIZE/2,
		MARGIN,
		AUDIO_GRAPHICAL_SIZE*AUDIO_GRAPHICAL_SIZE/2,
		5*VISIO_GRAPHICAL_SIZE,
		"blanc");

		// On efface la zone de texte
		pacmanWindow->colorierZone(
		MARGIN+(MARGIN+5*VISIO_GRAPHICAL_SIZE)*NB_VISIO_INPUTS+MARGIN+index*AUDIO_GRAPHICAL_SIZE*AUDIO_GRAPHICAL_SIZE/2,
		MARGIN+5*VISIO_GRAPHICAL_SIZE,
		AUDIO_GRAPHICAL_SIZE*AUDIO_GRAPHICAL_SIZE/2,
		2*MARGIN,
		"blanc");

		// on affiche le texte
		char texte[50];
		sprintf(texte,"Rien entendu");

		pacmanWindow->afficheTexte(
		texte,
		MARGIN+NB_VISIO_INPUTS*(5*VISIO_GRAPHICAL_SIZE+MARGIN)+MARGIN+index*AUDIO_GRAPHICAL_SIZE*AUDIO_GRAPHICAL_SIZE/2,
		MARGIN*2+5*VISIO_GRAPHICAL_SIZE,
		"noir");
	}
}
#endif

/****************************************************************************************************************************************/
/**************************************************** Methodes statiques de ZooDisplayer ************************************************/
/****************************************************************************************************************************************/
/*
PacmanDisplayer* PacmanDisplayer::initPacmanDisplayer()
{
	if (!thePacmanDisplayer)
	{
		thePacmanDisplayer = new PacmanDisplayer();
	}
	return thePacmanDisplayer;
}


void PacmanDisplayer::endPacmanDisplayer()
{
	if (thePacmanDisplayer)
	{
		delete(thePacmanDisplayer);
	}
	thePacmanDisplayer=0;
}
*/



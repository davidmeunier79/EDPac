// ZooDisplayer.cc

// Local Includes
#include "ZooDisplayer.h"

// macros presentent pour raisons historiques
#define AT(n) ((n)*20)
#define TA(n) ((n)/20)

/****************************************************************************************************************************************/
/**************************************************** Methodes de la classe ZooDisplayer ************************************************/
/****************************************************************************************************************************************/

ZooDisplayer::ZooDisplayer()
{
	zooWindow = new Fenetre();
}

ZooDisplayer::~ZooDisplayer()
{
}

void ZooDisplayer::flushDisplay()
{
	zooWindow->redessine();
}

void ZooDisplayer::cleanDisplay()
{
	zooWindow->effacer();
}



void ZooDisplayer::displayDirMvt(Pacman* pac)
{
	int x,y;;
	pac->getPosition(x,y);
	
	zooWindow->colorierZone(AT(y) , AT(x), 20, 20,"blanc");
	
	switch(pac->getDirMvt())
	{
		case HAUT:
		{
			zooWindow->placeImage("bmUserup", AT(y)+2 , AT(x)+2);
			break;
		}
		case BAS:
		{
			zooWindow->placeImage("bmUserdown", AT(y)+2 , AT(x)+2);
			break;
		}
		case DROITE:
		{
			zooWindow->placeImage("bmUserright", AT(y)+2 , AT(x)+2);
			break;
		}
		case GAUCHE:
		{
			zooWindow->placeImage("bmUserleft", AT(y)+2 , AT(x)+2);
			break;
		}
		default:
		{
			break;
		}
	}
}

void ZooDisplayer::displayDirVue(Pacman* pac)
	{
	int x,y;;
	pac->getPosition(x,y);
	
	string color="bleu";
	
	switch(pac->getDirVue())
	{
		case HAUT:
		{
			zooWindow->colorierZone(AT(y) , AT(x), 20, 2,color);
			break;
		}
		case BAS:
		{
			zooWindow->colorierZone(AT(y) , AT(x)+18, 20, 2,color);
			break;
		}
		case DROITE:
		{
			zooWindow->colorierZone(AT(y)+18 , AT(x), 2, 20,color);
			break;
		}
		case GAUCHE:
		{
			zooWindow->colorierZone(AT(y) , AT(x), 2, 20,color);
			break;
		}
		default:
		{
			break;
		}
	}
}

void ZooDisplayer::displayVoid(int posX, int posY)
{
	zooWindow->colorierZone(AT(posX) , AT(posY), 20, 20,"blanc");
}

void ZooDisplayer::displayDot(int posX, int posY)
{
	displayVoid(posX,posY);
	zooWindow->placeImage("bmDot", AT(posX), AT(posY));
}

void ZooDisplayer::display(string etiquette,int posX, int posY)
{
	// on effectue le mouvement graphiquement
	displayVoid(posX,posY);
	zooWindow->placeImage(etiquette, AT(posX), AT(posY));
}

void ZooDisplayer::initDisplayer(Zoo* zoo)
{
	zooWindow->effacer();
	
	// on charge les images utiles
	zooWindow->initImage("bmUsereat","formes/usereat", "orange");
	zooWindow->initImage("bmWall","formes/wall", "gris");
	zooWindow->initImage("bmDot","formes/dot", "noir");
	zooWindow->initImage("bmUserup","formes/userup","orange");
	zooWindow->initImage("bmUserdown","formes/userdown","orange");
	zooWindow->initImage("bmUserright","formes/userright","orange");
	zooWindow->initImage("bmUserleft","formes/userleft","orange");
	
	// on configure la fenetre
	if (AT(zoo->colonnes) <= 800 && AT(zoo->lignes) <= 480)
	{
		zooWindow->setDimensions(800,480);
	}
	
	//zooWindow->setDimensions(AT(zoo->colonnes)+40,AT(zoo->lignes));
	zooWindow->setTitre("pacman au zoo");
	zooWindow->setIconeTitre("pacman au zoo");
	zooWindow->setPosition(100,270);
	
	// on affiche le zoo
	for(int i=0;i<zoo->lignes;i++)
	{
		for(int j=0;j<zoo->colonnes;j++)
		{
			// si c'est un point, un mur ou un pacman on l'affiche
			if((*zoo)(i,j)=='.')
			{
				zooWindow->placeImage("bmDot", AT(j), AT(i));
			}
			if((*zoo)(i,j)=='X')
			{
				zooWindow->placeImage("bmWall", AT(j), AT(i));
			}
			if((*zoo)(i,j)=='0')
			{
				zooWindow->placeImage("bmUsereat", AT(j), AT(i));
			}
			
			// sinon, c'est un animal
			if((*zoo)(i,j)>='A' && (*zoo)(i,j)<'X')
			{
				string colpix;
				
				switch(zoo->menagerie[(*zoo)(i,j)-'A'].getPersonnalite())
				{
					case MECHANT:
					{
						colpix = "rouge";
						break;
					}
					case NEUTRE:
					{
						colpix = "gris";
						break;
					}
					case GENTIL:
					{
						colpix = "bleu";
						break;
					}
					default:
					{
						colpix = "noir";
						break;
					}
				}
				
				string nomAnimal=zoo->menagerie[(*zoo)(i,j)-'A'].getNomFR();
				zooWindow->initImage(nomAnimal,"./menagerie/"+nomAnimal+"/"+nomAnimal+".XBM",colpix);
				zooWindow->placeImage(nomAnimal, AT(j), AT(i));
			}
		}
	}
	zooWindow->redessine();
}


void ZooDisplayer::saveZooDisplayer(int nbSteps)
{
	ostringstream oss;
	oss << "Zoo" << getEvoIndex() << "_" << getTopoIndex() << "_" << nbSteps << ".xpm";

	((Fenetre*) zooWindow)->saveXpmImage(oss.str());
}

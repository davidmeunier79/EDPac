// TestLab.cc

#include "TestLab.h"


/*********************************************************************************************/
/*                                                                                           */
/*                             Definitions des methodes de TestLab 			     */
/*                                                                                           */
/*********************************************************************************************/

TestLab::TestLab()
{
}

TestLab::~TestLab()
{
}

// prepare le zoo selon les fichiers de configuration
#ifdef _TEST_MODE
void TestLab::initTestZoo(int level)
{
	char ligne[500];

	// lecture du niveau
	ifstream f2;

	sprintf(ligne,"screens/%s.%i",_SCREEN_FILENAME,level);

	f2.open(ligne,ifstream::in);
	if(!f2)
	{
		cerr<<"fichier "<<static_cast<string>(ligne)<<" n'a pas ete trouve"<<endl;
		return;
	}

	f2.ignore(500,':');
	f2>>lignes;
	f2.ignore(500,':');
	f2>>colonnes;
	f2.ignore(500,'\n');

	// Cr?ation du zoo
	zoo=new char*[lignes];
	
	for(int i=0;i<lignes;i++)
	{
		zoo[i]=new char[colonnes];
		for(int j=0;j<colonnes;j++)
			zoo[i][j]=f2.get();
		f2.ignore(500,'\n');
	}
}

bool TestLab::testMort(Pacman* pac)
{
#ifdef _ZOO_TEST
	cout << "Accessing TestLab::testMort" << endl;
#endif

	int x,y;
  	pac->getPosition(x,y);
#ifdef _ZOO_TEST
	cout << "position: " << x << " " << y << " (" << X_TARGET_ANIMAL << " " << Y_TARGET_ANIMAL << ")" << endl;
#endif
	// Si le pacman mange l'animal
	if((x == X_TARGET_ANIMAL) && (y == Y_TARGET_ANIMAL))
	{
		cout << "break" << endl;
		
		// si l'animal est un predateur
		if((zoo[x][y]>='A' && zoo[x][y]<'X') && (menagerie[zoo[x][y]-'A'].getPersonnalite()==MECHANT))
		{
			cout << "Eating predator" << endl;
		
			pac->statBadBehaviour();
		}
		
		return 1;
	}
	// Si le pacman sort du zoo
	else if ((x==0 || x==lignes-1) || (y==0 || y==colonnes-1))
	{
#ifdef _ZOO_TEST
		cout << "break" << endl;
#endif
		int x,y;

		getAnimalPosition(x,y);

		if (menagerie[zoo[x][y]-'A'].getPersonnalite()==GENTIL)
		{
			pac->statBadBehaviour();
		}
		else if (menagerie[zoo[x][y]-'A'].getPersonnalite()==MECHANT)
		{
			pac->statGoodBehaviour();
		}

		return 1;
	}
	else
	{
#ifdef _ZOO_TEST
		cout << "continue" << endl;
#endif
		return 0;
	}
}

void TestLab::testAvancer(Pacman* pac)
{
	// calcul de la nouvelle position
	int x,y;
	pac->getPosition(x,y);
	int newX=x,newY=y;

	switch(pac->getDirMvt())
	{
		case HAUT:
		newX--;
		break;
		case BAS:
		newX++;
		break;
		case GAUCHE:
		newY--;
		break;
		case DROITE:
		newY++;
		break;
	}
#ifdef _ZOO_TEST
	cout << "position " << newX << " " << newY << endl;
#endif

	// on met a jour les stats
	if ((0<=newX || newX<=lignes) && (0<=newY || newX<=colonnes))
	{

		// Cas d'un animal gentil
		if((zoo[newX][newY]>='A' && zoo[newX][newY]<'X') && (menagerie[zoo[newX][newY]-'A'].getPersonnalite()==GENTIL))
		{
			#ifdef _RUN_MODE
			pac->nbMvtsTous++;
			pac->nbMvtAvants++;
			pac->nbPreys++;
/*
					#ifdef _CONDITIONNING_MODE
			pac->lifeLevel+=NB_POINTS_EACH_PREY;
			pac->sendReward();
					#endif
*/
			#endif

			pac->statGoodBehaviour();

		}

		// Cas d'un Pacgum
		if(zoo[newX][newY]=='.')
		{
				#ifdef _RUN_MODE
			pac->nbMvtsTous++;
			pac->nbMvtAvants++;
			pac->nbPacgums++;
/*
					#ifdef _CONDITIONNING_MODE
			pac->lifeLevel+=NB_POINTS_EACH_PACGUM;
			pac->sendRandomReward();
					#endif
*/
				#endif

		}
		// Cas d'une case vide
		if(zoo[newX][newY]==' ')
		{
				#ifdef _RUN_MODE
			pac->nbMvtsTous++;
			pac->nbMvtAvants++;
				#endif
		}

		zoo[newX][newY]=zoo[x][y];
		zoo[x][y]=' ';

		#ifdef _GRAPHICAL_DISPLAY_MODE
		if (displayer)
		{
			((ZooDisplayer*) displayer)->displayVoid(y,x);
		}
		#endif
	}
	else
	{
		cout << "Pacamn out of testLab" << endl;
	}
}

void TestLab::getAnimalPosition(int & x,int & y)
{
	for(int i=0;i<lignes;i++)
	{
		for(int j=0;j<colonnes;j++)
		{
			if(('A'<=zoo[i][j] && zoo[i][j]<'X'))
			{
				x=i;
				y=j;
				return;
			}
		}
	}

	cerr<< "animal non trouve dans le zoo"<<endl;

	x=-1;
	y=-1;
	return;
}
#endif

// Zoo.cc

#include "Zoo.h"


/*********************************************************************************************/
/*                                                                                           */
/*                             Definitions des methodes de Zoo                               */
/*                                                                                           */
/*********************************************************************************************/

Zoo::Zoo()
{
#ifdef _ZOO_TEST
	cout << "PopulationTracer: " << tracer << endl;
#endif
#ifdef _ZOO_TEST
	cout << "PopulationGrapher: " << grapher << endl;
#endif

#ifdef _GRAPHICAL_DISPLAY_MODE
  displayer = new ZooDisplayer();
  
  	#ifdef _SAVE_ZOO_DISPLAY_MODE
	system("rm Zoo*.xpm");	
	system("rm Zoo*.jpeg");
	
	system("rm Zoo*.sh");
	system("rm Zoo*.par_mpg");
	#endif
#endif
}

Zoo::~Zoo()
{
#ifdef _GRAPHICAL_DISPLAY_MODE
	delete((ZooDisplayer*) displayer);
#endif
}

char Zoo::operator()(int x,int y)
{
	return zoo[x][y];
}

Menagerie & Zoo::getMenagerie()
{
	return menagerie;
}

void Zoo::getTaille(int &x,int &y)
{
	x=lignes;
	y=colonnes;
}


void Zoo::deleteZoo()
{
	for(int i=0;i<lignes;i++)
	{
		delete [] zoo[i];
	}
	delete [] zoo;
}

void Zoo::tourner(Pacman* pac)
{
#ifdef _RUN_MODE
	pac->nbMvtsTous++;
#endif
}

void Zoo::statEvo()
{
	initLoader();

	initRandom();

	initEvoIndex();

	while (getEvoIndex() < NB_GENERATIONS)
	{
		#if (defined(_TEST_BEST_POPULATION_MODE) || defined(_TEST_RANDOM_POPULATION_MODE))
			#ifdef _TEST_RANDOM_POPULATION_MODE
		if (getEvoIndex() == 0)
		{
			if (((ZooLoader*) loader)->load(this,getEvoIndex()))
			{
				cout << "Entering stat with " << tabChromosomes.size() << " chromosomes to test" << endl;
				
				vector<Chromosome*>::iterator it = tabChromosomes.begin();
				vector<Chromosome*>::iterator end = tabChromosomes.end();
			
				initTopoIndex();
			
				while (it!=end)
				{
#ifdef _MPI_TEST
					cout << "*** Pacman *** sending chromosome to *** EDNetwork ***" << endl;
#endif
					((Pacman*) *it)->setSynchroBuffers();
					((Pacman*) *it)->sendSynchro();

					cout << "*** Pacman *** Topo index " << getTopoIndex() << " (" << NB_INDIVIDUS << ")" << endl;

					while (!((Pacman*) *it)->isReady())
					{
#ifdef _MPI_TEST
						cout << "*** Pacman *** waiting send complete" << endl;
#endif
					}

					((Pacman*) *it)->testSynchro();
#ifdef _MPI_TEST
					cout << "*** Pacman *** out of testSynchro" << endl;
#endif

#ifdef _ASSEMBLY_STAT_MODE
#endif
					incrementTopoIndex();
/*
					if (NB_INDIVIDUS <= getTopoIndex())
					{
						cout << "Breaking, topo index " << getTopoIndex() << " higher than " << NB_INDIVIDUS << endl;
						break;
					}
*/
					it++;
				}
			}
			else
			{
				cerr << "No population " << getEvoIndex() << " was loaded" << endl;
			}
		}
		else
		{
#ifdef _ZOO_TEST
			cout << "Population " << getEvoIndex() << " not tested" << endl;
#endif
		}
			#endif	
			#ifdef _TEST_BEST_POPULATION_MODE
		if (getEvoIndex() == NB_GENERATIONS-1)
		{
			if (((ZooLoader*) loader)->load(this,getEvoIndex()))
			{
				cout << "Entering stat with " << tabChromosomes.size() << " chromosomes to test" << endl;
				
				vector<Chromosome*>::iterator it = tabChromosomes.begin();
				vector<Chromosome*>::iterator end = tabChromosomes.end();
			
				initTopoIndex();
			
				while (it!=end)
				{
#ifdef _MPI_TEST
					cout << "*** Pacman *** sending chromosome to *** EDNetwork ***" << endl;
#endif
					((Pacman*) *it)->setSynchroBuffers();
					((Pacman*) *it)->sendSynchro();

					cout << "*** Pacman *** Topo index " << getTopoIndex() << " (" << NB_INDIVIDUS << ")" << endl;

					while (!((Pacman*) *it)->isReady())
					{
#ifdef _MPI_TEST
						cout << "*** Pacman *** waiting send complete" << endl;
#endif
					}

					((Pacman*) *it)->testSynchro();
#ifdef _MPI_TEST
					cout << "*** Pacman *** out of testSynchro" << endl;
#endif
					incrementTopoIndex();
/*
					if (NB_INDIVIDUS <= getTopoIndex())
					{
						cout << "Breaking, topo index " << getTopoIndex() << " higher than " << NB_INDIVIDUS << endl;
						break;
					}
*/
					it++;
				}
			}
			else
			{
				cerr << "No population " << getEvoIndex() << " was loaded" << endl;
			}
		}
		else
		{
#ifdef _ZOO_TEST
			cout << "Population " << getEvoIndex() << " not tested" << endl;
#endif
		}
			#endif
		#else
		if (((ZooLoader*) loader)->load(this,getEvoIndex()))
		{
			cout << "Entering stat with " << tabChromosomes.size() << " chromosomes to test" << endl;
			
			vector<Chromosome*>::iterator it = tabChromosomes.begin();
			vector<Chromosome*>::iterator end = tabChromosomes.end();
		
			initTopoIndex();
		
			while (it!=end)
			{
#ifdef _MPI_TEST
				cout << "*** Pacman *** sending chromosome to *** EDNetwork ***" << endl;
#endif
				((Pacman*) *it)->setSynchroBuffers();
				((Pacman*) *it)->sendSynchro();

				cout << "*** Pacman *** Topo index " << getTopoIndex() << " (" << NB_INDIVIDUS << ")" << endl;

				while (!((Pacman*) *it)->isReady())
				{
#ifdef _MPI_TEST
					cout << "*** Pacman *** waiting send complete" << endl;
#endif
				}

				((Pacman*) *it)->testSynchro();
#ifdef _MPI_TEST
				cout << "*** Pacman *** out of testSynchro" << endl;
#endif
				incrementTopoIndex();
/*
				if (NB_INDIVIDUS <= getTopoIndex())
				{
					cout << "Breaking, topo index " << getTopoIndex() << " higher than " << NB_INDIVIDUS << endl;
					break;
				}
*/
				it++;
			}
		}
		else
		{
			cerr << "No population " << getEvoIndex() << " was loaded" << endl;
		}
		#endif
		incrementEvoIndex();
	}

	cerr << "Out of test loop " << endl;

	closeLoader();

	((Pacman*) tabChromosomes[0])->sendBreak();

	//cout << "*** Root Module " << MPI_GLOBALS.getMyId() << " *** after break synchronizing with synchro modules" << endl;
  	//((Pacman*) tabChromosomes[0])->testSynchro();
}

void Zoo::initPacmans()
{
	// creation des pacmans
	int comptChromo = 0;

	while (comptChromo<NB_INDIVIDUS)
	{
		Pacman* pac= new Pacman(this);
		//Pacman* pac= new Pacman(*this);
		//Chromosome* chr = new Chromosome();
		pac->initChromosome();
		tabChromosomes.push_back(pac);

		comptChromo++;
	}
}

#ifdef _RUN_MODE
// prepare le zoo selon les fichiers de configuration
void Zoo::initZoo(int level)
{
  char ligne[500];

  // lecture du niveau
  ifstream f2;

  sprintf(ligne,"screens/screen.%i",level);

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
  zoo=new char* [lignes];
  for(int i=0;i<lignes;i++)
  {
      zoo[i]=new char[colonnes];
      for(int j=0;j<colonnes;j++)
	zoo[i][j]=f2.get();
      f2.ignore(500,'\n');
  }
}

void Zoo::probasAnimaux(int i,int j,double probas[4],Pacman* pac)
{
  	probas[0]=probas[1]=probas[2]=probas[3]=0.00;

	//int probas[4];
	int hPac,lPac;
	pac->getPosition(hPac,lPac);

	// detremine ou est le pacman par rapport a l'animal
	Direction direction;
	int x=i-hPac,y=lPac-j;
	if(-y<=x && x<=y)
	{
		direction=DROITE;
	}
	else if(y<=x && x<=-y)
	{
		direction=GAUCHE;
	}
	else if(-x<y && y<x)
	{
		direction=HAUT;
	}
	else
	{
		direction=BAS;
	}

	// le mouvement se fait selon la personalite
	switch(menagerie[zoo[i][j]-'A'].getPersonnalite())
	{
		// si l'animal est mechant il se rapproche du pacman
		case MECHANT :
		{

			probas[direction]=0.85;
			probas[(direction+1)%4]=0.06;
			probas[(direction+3)%4]=0.06;
			probas[(direction+2)%4]=0.03;
			break;
		}
		// s'il est neutre il bouge aleatoirement
		case NEUTRE :
		{
			probas[direction]=0.25;
			probas[(direction+1)%4]=0.25;
			probas[(direction+3)%4]=0.25;
			probas[(direction+2)%4]=0.25;
			break;
		}
		// s'il est gentil il s'eloigne du pacman
		case GENTIL :
		{

			probas[direction]=0.03;
			probas[(direction+1)%4]=0.06;
			probas[(direction+3)%4]=0.06;
			probas[(direction+2)%4]=0.85;
			break;
		}
	}
}

void Zoo::vivre(Pacman* pac)
{
	// on parcoure tout le zoo
	for(int i=0;i<lignes;i++)
	{
		for(int j=0;j<colonnes;j++)
		{
			// si ce n'est pas un animal on ne fait rien
			if(!(zoo[i][j]>='A' && zoo[i][j]<'X'))
			{
				continue;
			}

			// Si animal hors de zoo
			if((i==0 || i==lignes-1) || (j==0 || j==colonnes-1))
			{
				continue;
			}

			double randomMove=randomProb();

	#ifdef _MOVING_ANIMAL_MODE
			// sinon, il a 90% de chances de ne pas bouger
			if(PROB_ANIMAL_MOUVEMENT<randomMove)
	#endif
	#ifdef _QUIET_ANIMAL_MODE
			//les animaux ne bougent pas
			if(0.0<randomMove)
	#endif
			{
				continue;
			}

			// pour connaitre les directions envisageables
			bool libre[4];
			libre[HAUT]=(zoo[i-1][j]==' ' || zoo[i-1][j]=='.');
			libre[BAS]=(zoo[i+1][j]==' ' || zoo[i+1][j]=='.');
			libre[GAUCHE]=(zoo[i][j-1]==' ' || zoo[i][j-1]=='.');
			libre[DROITE]=(zoo[i][j+1]==' ' || zoo[i][j+1]=='.');

			// si pas de direction envisageable, on ne fait rien
			if(!libre[HAUT] && !libre[BAS] && !libre[GAUCHE] && !libre[DROITE])
			{
				continue;
			}

			// tableau contenant les probas
			double probas[4];
			probasAnimaux(i,j,probas,pac);  // calcule les probas

			// on tire aleatoirement la direction
			Direction newDirection=STOP;

			double random = randomUniform();

			//cout << "random: " << random << endl;

			if(0.0<=random && random<probas[HAUT])
			{
				if (libre[HAUT])
				{
					newDirection=HAUT;
				}
			}
			else if(probas[HAUT]<=random && random<probas[HAUT]+probas[BAS])
			{
				if (libre[BAS])
				{
					newDirection=BAS;
				}
			}
			else if(probas[HAUT]+probas[BAS]<=random && random<probas[HAUT]+probas[BAS]+probas[DROITE])
			{
				if (libre[DROITE])
				{
					newDirection=DROITE;
				}
			}
			else if(probas[HAUT]+probas[BAS]+probas[DROITE]<=random && random<=1.00)
			{
				if (libre[GAUCHE])
				{
					newDirection=GAUCHE;
				}
			}
			else
			{
				cerr << "Warning, incompatible with probas values" << endl;
			}

			if (newDirection!=STOP)
			{
				// on obtient alors la nouvelle position de l'animal
				int hNew=i, lNew=j;
				switch(newDirection)
				{
					case HAUT:
					{
						hNew--;
						break;
					}
					case BAS:
					{
						hNew++;
						break;
					}
					case GAUCHE:
					{
						lNew--;
						break;
					}
					case DROITE:
					{
						lNew++;
						break;
					}
					default:
					{
						continue;
					}
				}


				// on effectue le mouvement dans le zoo
				char tmp=zoo[hNew][lNew];
				zoo[hNew][lNew]=zoo[i][j];
				zoo[i][j]=tmp;

	#ifdef _GRAPHICAL_DISPLAY_MODE
				// On modifie l'affichage
				((ZooDisplayer*) displayer)->display(menagerie[zoo[hNew][lNew]-'A'].getNomFR(),lNew,hNew);

				if(zoo[i][j]=='.')
				{
					((ZooDisplayer*) displayer)->displayDot(j,i);
				}
				else
				{
					((ZooDisplayer*) displayer)->displayVoid(j,i);
				}

				// on rafraichit
				((ZooDisplayer*) displayer)->flushDisplay();
	#endif

			}
		}
	}
}

void Zoo::avancer(Pacman* pac)
{
  // calcul de la nouvelle position
  int x,y;
  pac->getPosition(x,y);
  int newX=x,newY=y;

  switch(pac->dirMvt)
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

  // on met a jour les stats

  // Cas d'un animal gentil
  if((zoo[newX][newY]>='A' && zoo[newX][newY]<'X') && (menagerie[zoo[newX][newY]-'A'].getPersonnalite()==GENTIL))
    {
 	#ifdef _RUN_MODE
      pac->nbMvtsTous++;
      pac->nbMvtAvants++;
      pac->nbPreys++;

		#ifdef _CONDITIONNING_MODE
      pac->lifeLevel+=NB_POINTS_EACH_PREY;
      pac->sendReward();
		#endif
	#endif

    }
  // Cas d'un animal neutre
  if((zoo[newX][newY]>='A' && zoo[newX][newY]<'X') && (menagerie[zoo[newX][newY]-'A'].getPersonnalite()==NEUTRE))
    {
	#ifdef _RUN_MODE
      pac->nbMvtsTous++;
      pac->nbMvtAvants++;
        #endif
    }
  // Cas d'un Pacgum
  if(zoo[newX][newY]=='.')
    {
    	#ifdef _RUN_MODE
      pac->nbMvtsTous++;
      pac->nbMvtAvants++;
      pac->nbPacgums++;

		#ifdef _CONDITIONNING_MODE
      pac->lifeLevel+=NB_POINTS_EACH_PACGUM;
      pac->sendRandomReward();
		#endif
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

  // si on se cogne pas sur un mur et si l'animal n'est pas un predateur, on avance
   if(zoo[newX][newY]=='X' ||((zoo[newX][newY]>='A' && zoo[newX][newY]<'X') && (menagerie[zoo[newX][newY]-'A'].getPersonnalite()==MECHANT)))
   {
   }
   else
   {
	 zoo[newX][newY]=zoo[x][y];
	 zoo[x][y]=' ';

	#ifdef _GRAPHICAL_DISPLAY_MODE
  	 ((ZooDisplayer*) displayer)->displayVoid(y,x);
	#endif
   }
}

bool Zoo::mort(Pacman* pac)
{

	int x,y;
  	pac->getPosition(x,y);

	#ifdef _CONDITIONNING_MODE
	if(
	((zoo[x-1][y]>='A' && zoo[x-1][y]<'X') && (menagerie[zoo[x-1][y]-'A'].getPersonnalite()==MECHANT)) ||
	((zoo[x+1][y]>='A' && zoo[x+1][y]<'X') && (menagerie[zoo[x+1][y]-'A'].getPersonnalite()==MECHANT)) ||
	((zoo[x][y-1]>='A' && zoo[x][y-1]<'X') && (menagerie[zoo[x][y-1]-'A'].getPersonnalite()==MECHANT)) ||
	((zoo[x][y+1]>='A' && zoo[x][y+1]<'X') && (menagerie[zoo[x][y+1]-'A'].getPersonnalite()==MECHANT))
	)
	{
		#ifdef _RUN_MODE
		pac->lifeLevel-=NB_POINTS_EACH_PREDATOR;
      		#endif
		pac->sendPunish();
	}

		#ifdef _RUN_MODE
	if (pac->lifeLevel<=0)
	{
		return 1;
	}
	else
	{
		pac->setFitness();
		return 0;
	}
		#endif
	#else
  	// s'il y a un mechant adjacent au pacman
	if(
	((zoo[x-1][y]>='A' && zoo[x-1][y]<'X') && (menagerie[zoo[x-1][y]-'A'].getPersonnalite()==MECHANT)) ||
	((zoo[x+1][y]>='A' && zoo[x+1][y]<'X') && (menagerie[zoo[x+1][y]-'A'].getPersonnalite()==MECHANT)) ||
	((zoo[x][y-1]>='A' && zoo[x][y-1]<'X') && (menagerie[zoo[x][y-1]-'A'].getPersonnalite()==MECHANT)) ||
	((zoo[x][y+1]>='A' && zoo[x][y+1]<'X') && (menagerie[zoo[x][y+1]-'A'].getPersonnalite()==MECHANT))
	)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	#endif
}
#endif

void Zoo::initZooFiles()
{
#ifdef _POPULATION_STAT_MODE
	stater = new ZooStater();
	((ZooStater*) stater)->openStater();
#endif

#ifdef _POPULATION_TRACE_MODE
	tracer = new ZooTracer();
#endif
}

void Zoo::endZooFiles()
{

#ifdef _POPULATION_TRACE_MODE
	delete(tracer);
#endif
#ifdef _POPULATION_GRAPH_MODE
	cout << "Running zoo grapher" << endl;
	grapher = new ZooGrapher();

//	((ZooGrapher*) grapher)->initZooGrapher(this);
	((ZooGrapher*) grapher)->graph(this);
//	((ZooGrapher*) grapher)->freeZooGrapher(this);

	delete(grapher);

	cout << "after zoo grapher" << endl;
#endif
#ifdef _POPULATION_STAT_MODE


	cout << "Before closeStater" << endl;
	((ZooStater*) stater)->closeStater();

	delete(stater);
#endif
}

void Zoo::initSaver()
{
	saver= new ZooSaver();
}

void Zoo::closeSaver()
{
	delete((ZooSaver*) saver);
	saver = 0;
}

void Zoo::initLoader()
{
	loader= new ZooLoader();
}

void Zoo::closeLoader()
{
	delete((ZooLoader*) loader);
	loader = 0;
}

#ifdef _RUN_MODE
void Zoo::evaluatePopulation()
{
	vector<Chromosome*>::iterator it = tabChromosomes.begin();
	vector<Chromosome*>::iterator end = tabChromosomes.end();

	initTopoIndex();

	while (it!=end)
	{

		((Individual*) *it)->initEvalIndex();
		//((Individual*) *it)->initEvalFitness();

		while (((Individual*) *it)->getEvalIndex()<NB_EVALUATIONS)
		{
	#ifdef _ZOO_TEST
			cout << "Entering evaluation " << ((Pacman*) *it)->getEvalIndex() << " loop" << endl;
	#endif

			if (((Individual*) *it)->getEvalIndex()==0)
			{
	//#ifdef _MPI_TEST
				cout << "*** Pacman *** sending chromosome to *** EDNetwork ***" << endl;
	//#endif
				// Envoi du chromosome au premier tour
				((Pacman*) *it)->setSynchroBuffers();
				((Pacman*) *it)->sendSynchro();
			}
			else
			{
	//#ifdef _MPI_TEST
				cout << "*** Pacman *** sending SKIP chromosome to *** EDNetwork ***" << endl;
	//#endif
				// Envoi d'un message vide au second tour.
				((Pacman*) *it)->sendSkipSynchro();
			}

			// Envoi du birth flash

	//#ifdef _MPI_TEST
			cout << "*** Pacman *** initing MPIModule" << endl;
	//#endif
			((Pacman*) *it)->initMPIModule();

			initZoo(LEVEL);
			
	#ifdef _GRAPHICAL_DISPLAY_MODE
			((Pacman*) *it)->initPacmanDisplayer();
	#endif
	
	#ifdef _GRAPHICAL_DISPLAY_MODE
			cout << "initing zoo displayer for individual " << ((Pacman*) *it)->getTopoIndex() << endl;
			((ZooDisplayer*) displayer)->initDisplayer((Zoo*) this);
	#endif
	
			cerr << "*** Pacman *** sendind birth flash" << endl;

			((Pacman*) *it)->integrateBirthFlash();

	#ifdef _MPI_TEST
			cout << "*** Pacman *** sending VOID chromosome to *** EDNetwork ***" << endl;
	#endif

			((Pacman*) *it)->sendVoidSynchro();

			// Test n1

	#ifdef _TEST_MODE

			cerr << "*** Pacman *** testing Pacman " << ((Chromosome*) *it)->getTopoIndex() << " before run eval " << ((Pacman*) *it)->nbSteps  << endl;
			((Pacman*) *it)->test();
			((ZooStater*) stater)->statScoreBeforeRun((Pacman*) *it);
			((ZooTracer*) tracer)->trace((Pacman*) *it);
/*
		//#ifdef _MPI_TEST
			cerr << "*** Pacman *** sending VOID chromosome to *** EDNetwork ***" << endl;
			cerr << "*** Pacman *** sending VOID to *** Motor ***" << endl;
		//#endif
			// Envoi d'un message vide au second tour.
			((Pacman*) *it)->sendVoidSynchro();
*/
	#endif


			// Run

		/*
	//#ifdef _MPI_TEST
			cout << "*** Pacman *** initing MPIModule" << endl;
	//#endif
			((Pacman*) *it)->initMPIModule();
		*/
			((Pacman*) *it)->run();

			// Test n2
	#ifdef _TEST_MODE
/*
		//#ifdef _MPI_TEST
			cout << "*** Pacman *** sending VOID chromosome to *** EDNetwork ***" << endl;
			cout << "*** Pacman *** sending VOID to *** Motor ***" << endl;
		//#endif
			// Envoi d'un message vide au second tour.
			((Pacman*) *it)->sendVoidSynchro();

		//#ifdef _MPI_TEST
			cout << "*** Pacman *** initing MPIModule" << endl;
		//#endif
			((Pacman*) *it)->initMPIModule();
*/
			cout << "Testing Pacman " << ((Chromosome*) *it)->getTopoIndex() << " after run eval " << ((Pacman*) *it)->nbSteps << endl;
			((Pacman*) *it)->test();
			((ZooStater*) stater)->statScoreAfterRun((Pacman*) *it);
			((ZooTracer*) tracer)->trace((Pacman*) *it);
/*
			cout << "*** Pacman *** freeing MPIModule" << endl;

			((Pacman*) *it)->freeMPIModule();
*/
	#endif
/*
		//#ifdef _MPI_TEST
			cout << "*** Pacman *** waiting synchro" << endl;
		//#endif
			((Pacman*) *it)->waitSynchro();
*/
			
	#ifdef _MPI_TEST
			cout << "*** Pacman *** freeing MPIModule" << endl;
	#endif
			((Pacman*) *it)->freeMPIModule();
		
			//#ifdef _ZOO_TEST
			cout << "delete Zoo" << endl;
			//#endif
		
			deleteZoo();
			
	#ifdef _GRAPHICAL_DISPLAY_MODE
			((Pacman*) *it)->freePacmanDisplayer();
	#endif
		// Fin de l'evaluation

	//#ifndef _CONDITIONNING_MODE
			cout << "*** Pacman *** set Eval Fitness" << endl;
			((Individual*) *it)->setEvalFitness();
	//#else

	//#endif
			cout << "*** Pacman *** increment Eval Fitness" << endl;
			((Individual*) *it)->incrementEvalIndex();
		}
/*
	#ifdef _TEST_MODE
		((PacmanStater*) ((Pacman*) *it)->stater)->traceBehaviourCounters((Pacman*) *it);
	#endif
*/
		#ifdef _MEAN_FITNESS_MODE
		cout << "Mean fitness for individual " << ((Chromosome*) *it)->getTopoIndex() << " : " << ((Pacman*) *it)->getFitness() << endl;
		#endif
		#ifdef _LOWEST_FITNESS_MODE
		cout << "Lowest fitness for individual " << ((Chromosome*) *it)->getTopoIndex() << " : " << ((Pacman*) *it)->getFitness() << endl;
		#endif

		cout << "Individual " << ((Chromosome*) *it)->getTopoIndex() << " has fitness = " << ((Pacman*) *it)->getFitness() << endl;
		sumFitness << "Generation " << getEvoIndex() << ", Individual " << ((Chromosome*) *it)->getTopoIndex() << " has fitness = " << ((Pacman*) *it)->getFitness()  << endl;
		//((Chromosome*) *it)->setFitness(fitness);

		((Chromosome*) *it)->incrementTopoIndex();

		#ifdef _SINGLE_INDIVIDUAL_MODE
		if (1 <= getTopoIndex())
		{
			cerr << "Breaking, topoindex " << getTopoIndex() << " is higher than " << 1 << endl;
			break;
		}
		#else
		if (NB_INDIVIDUS <= getTopoIndex())
		{
			cerr << "Breaking, topoindex " << getTopoIndex() << " is higher than " << NB_INDIVIDUS << endl;
			break;
		}
		#endif
		it++;
	}
}
	
void Zoo::runEvo()
{
	initRandom();

	#if ((defined(_TEST_BEST_POPULATION_MODE) || defined(_TEST_RANDOM_POPULATION_MODE)))
	initLoader();
	#else
		#ifdef _CONTINUE_EVOLUTION_MODE
	initLoader();

	bool loadedLastPopulation = 0;
	
	initSaver();
	
		#else
	initSaver();

	system("rm *.txt");
	initPacmans();
		#endif
	#endif

	initZooFiles();

//#ifdef _ZOO_TEST
	cout << "Apres initPopulation" << endl;
	cout << (Zoo*) this;
//#endif
	cout << "*** Zoo *** opening Sum fitness file" << endl;
	openSumFitness();

	initEvoIndex();

	while(getEvoIndex()<NB_GENERATIONS)
	{
	#if (defined(_TEST_BEST_POPULATION_MODE) || defined(_TEST_RANDOM_POPULATION_MODE))
		#ifdef _TEST_RANDOM_POPULATION_MODE
		if (getEvoIndex() == 0)
		{
			cerr << "Population " << getEvoIndex() << " will be loaded" << endl;

			if (((ZooLoader*) loader)->load(this,getEvoIndex()))
			{
				cout << "Entering test with " << tabChromosomes.size() << " chromosomes to test" << endl;

			#ifdef _POPULATION_STAT_MODE
				((ZooStater*) stater)->initAccumulaters();
			#endif

				evaluatePopulation();

				sortPopulation();

			#ifdef _POPULATION_TRACE_MODE
				((ZooTracer*) tracer)->trace((Zoo*) this);
			#endif

			#ifdef _POPULATION_STAT_MODE
				((ZooStater*) stater)->stat((Zoo*) this);
				((ZooStater*) stater)->trace((Zoo*) this);
			#endif
			}
			else
			{
				cerr << "No population " << getEvoIndex() << " was loaded" << endl;
			}
		}
		else
		{
		//#ifdef _ZOO_TEST
			cout << "Population " << getEvoIndex() << " not tested" << endl;
		//#endif
		}

		#endif

		#ifdef _TEST_BEST_POPULATION_MODE
		if (getEvoIndex() == NB_GENERATIONS-1)
		{
			cerr << "Population " << getEvoIndex() << " will be loaded" << endl;

			if (((ZooLoader*) loader)->load(this,getEvoIndex()))
			{
				cout << "Entering test with " << tabChromosomes.size() << " chromosomes to test" << endl;

			#ifdef _POPULATION_STAT_MODE
				((ZooStater*) stater)->initAccumulaters();
			#endif

				evaluatePopulation();

				sortPopulation();

			#ifdef _POPULATION_TRACE_MODE
				((ZooTracer*) tracer)->trace((Zoo*) this);
			#endif

			#ifdef _POPULATION_STAT_MODE
				((ZooStater*) stater)->stat((Zoo*) this);
				((ZooStater*) stater)->trace((Zoo*) this);
			#endif
			}
			else
			{
				cerr << "No population " << getEvoIndex() << " was loaded" << endl;
			}
		}
		else
		{
			//#ifdef _ZOO_TEST
			cout << "Population " << getEvoIndex() << " not tested" << endl;
			//#endif
		}
		#endif

	#else

		#ifdef _CONTINUE_EVOLUTION_MODE
		if (loadedLastPopulation == 0)
		{
			// Load les populations
			if (getEvoIndex() == LAST_POPULATION_INDEX)
			{
				if (((ZooLoader*) loader)->load(this,getEvoIndex()))
				{

					cout << "Population " << getEvoIndex() << " exists, skipping" << endl;

					loadedLastPopulation = 1;
				}
				else
				{
					cerr << "Warning, should have been able to read population " << getEvoIndex() << endl;
				}
			}
			else
			{
				// Fin des loads
				cerr << "No population " << getEvoIndex() << " was loaded" << endl;
				loadedLastPopulation = 0;
			}

			// Premiere evaluation sans save
			if (loadedLastPopulation == 1)
			{
				// Evaluation et evoluation des populations
			#ifdef _POPULATION_STAT_MODE
				((ZooStater*) stater)->initAccumulaters();
			#endif
	
				evaluatePopulation();
	
				sortPopulation();
	
			#ifdef _POPULATION_TRACE_MODE
				((ZooTracer*) tracer)->trace((Zoo*) this);
			#endif
	
			#ifdef _POPULATION_STAT_MODE
				((ZooStater*) stater)->stat((Zoo*) this);
				((ZooStater*) stater)->trace((Zoo*) this);
			#endif
	
			//#ifdef _GA_TEST
				cout << "Apres evaluatePopulation " << getEvoIndex() << endl;
			//#endif
	
				selectPopulation();
	
			//#ifdef _GA_TEST
				cout << "Apres selectPopulation " << getEvoIndex() << endl;
			//#endif
	
				varyPopulation();
	
			//#ifdef _GA_TEST
				cout << "Apres varyPopulation " << getEvoIndex() << endl;
			//#endif
				clusterizeChromos();
	
			//#ifdef _GA_TEST
				cout << "Apres clusterizeChromos " << getEvoIndex() << endl;
			//#endif
			}
		}
		else if (loadedLastPopulation == 1)
		{
			// Evaluation et evoluation des populations
			#ifdef _POPULATION_STAT_MODE
		((ZooStater*) stater)->initAccumulaters();
			#endif

		evaluatePopulation();

		sortPopulation();

			#ifdef _POPULATION_TRACE_MODE
		((ZooTracer*) tracer)->trace((Zoo*) this);
			#endif

			#ifdef _POPULATION_STAT_MODE
		((ZooStater*) stater)->stat((Zoo*) this);
		((ZooStater*) stater)->trace((Zoo*) this);
			#endif

		((ZooSaver*) saver)->save(this);
			//#ifdef _GA_TEST
		cout << "Apres evaluatePopulation " << getEvoIndex() << endl;
			//#endif

		selectPopulation();

			//#ifdef _GA_TEST
		cout << "Apres selectPopulation " << getEvoIndex() << endl;
			//#endif

		varyPopulation();

			//#ifdef _GA_TEST
		cout << "Apres varyPopulation " << getEvoIndex() << endl;
			//#endif
		clusterizeChromos();

			//#ifdef _GA_TEST
		cout << "Apres clusterizeChromos " << getEvoIndex() << endl;
			//#endif
		}
		#else
		
			#ifdef _POPULATION_STAT_MODE
		((ZooStater*) stater)->initAccumulaters();
			#endif

		evaluatePopulation();

		sortPopulation();

			#ifdef _POPULATION_TRACE_MODE
		((ZooTracer*) tracer)->trace((Zoo*) this);
			#endif

			#ifdef _POPULATION_STAT_MODE
		((ZooStater*) stater)->stat((Zoo*) this);
		((ZooStater*) stater)->trace((Zoo*) this);
			#endif
		((ZooSaver*) saver)->save(this);
			//#ifdef _GA_TEST
		cout << "Apres evaluatePopulation " << getEvoIndex() << endl;
			//#endif

		selectPopulation();

			//#ifdef _GA_TEST
		cout << "Apres selectPopulation " << getEvoIndex() << endl;
			//#endif

		varyPopulation();

			//#ifdef _GA_TEST
		cout << "Apres varyPopulation " << getEvoIndex() << endl;
			//#endif
		clusterizeChromos();

			//#ifdef _GA_TEST
		cout << "Apres clusterizeChromos " << getEvoIndex() << endl;
			//#endif
		#endif
	#endif


		incrementEvoIndex();
	}

	((Pacman*) tabChromosomes[0])->sendBreak();

//#ifdef _TRACE_MODE
	endZooFiles();
//#endif
	closeSumFitness();

	//cout << "*** Root Module " << MPI_GLOBALS.getMyId() << " *** after break synchronizing with synchro modules" << endl;
//  	((Pacman*) tabChromosomes[0])->testSynchro();

}

	#ifdef _CLUSTER_EVO_MODE
void Zoo::clusterizeChromos()
{
		#ifdef _GA_TEST
	cout << "Avant cluster evo" << endl;
	cout << (Population*) this;
		#endif

	initTopoIndex();
	
	vector<Chromosome*>::iterator it = tabChromosomes.begin();
	vector<Chromosome*>::iterator end = tabChromosomes.end();

	while (it != end)
	{
		//vector<Chromosome*>::iterator it2 = tabChromosomes.begin();
		vector<Chromosome*>::iterator it2 = it;
		vector<Chromosome*>::iterator end2 = tabChromosomes.end();

		int countTopo = getTopoIndex();
		
		while (it2 != end2)
		{
			if ((Chromosome*) *it != (Chromosome*) *it2)
			{
				if ((Chromosome&) *(*it) == (Chromosome&) *(*it2))
				{
					cout << "Chromosome " << countTopo << " is reinited, idem as " << getTopoIndex() << endl;
					
					sumFitness << "Chromosome " << countTopo << " is reinited, idem as " << getTopoIndex() << endl;
					
					cout << "Avant erase tabChromosomes : " << tabChromosomes.size() << endl;
					
					((Pacman*) *it2)->reInitChromosome();
					
					cout << "Apre new tabChromosomes : " << tabChromosomes.size() << endl;
				}
			}
			countTopo++;
			it2++;
		}
		
		incrementTopoIndex();	
		it++;
	}
		#ifdef _GA_TEST
	cout << "Apres cluster evo" << endl;
	cout << (Population*) this;
		#endif
}
	#endif
#endif

#ifdef _TEST_MODE

// prepare le zoo selon les fichiers de configuration
void Zoo::initTestZoo(int level)
{
	cerr << "Warning, accessing virtual Zoo::initTestZoo method " <<endl;
}

bool Zoo::testMort(Pacman* pac)
{
	cerr << "Warning, accessing Zoo::testMort" << endl;
}

void Zoo::testAvancer(Pacman* pac)
{
	cerr << "Warning, accessing Zoo::testAvancer " << endl;
}

void Zoo::testPopulation()
{
	vector<Chromosome*>::iterator it = tabChromosomes.begin();
	vector<Chromosome*>::iterator end = tabChromosomes.end();

	initTopoIndex();

	while (it!=end)
	{

		//#ifdef _MPI_TEST
		cout << "*** Pacman *** sending chromosome to *** EDNetwork ***" << endl;
		//#endif
		((Pacman*) *it)->setSynchroBuffers();
		((Pacman*) *it)->sendSynchro();

		//#ifdef _MPI_TEST
		cout << "*** Pacman *** initing MPIModule" << endl;
		//#endif
		((Pacman*) *it)->initMPIModule();

	#ifdef _GRAPHICAL_DISPLAY_MODE
		((Pacman*) *it)->initPacmanDisplayer();
	#endif
		//#ifdef _MPI_TEST
		cout << "*** Pacman *** integrating BirthFlash" << endl;
		//#endif
		((Pacman*) *it)->integrateBirthFlash();
		((Pacman*) *it)->sendVoidSynchro();

/*
		//#ifdef _MPI_TEST
		cout << "*** Pacman *** freeing MPIModule" << endl;
		//#endif
		((Pacman*) *it)->freeMPIModule();
*/
/*
		//#ifdef _MPI_TEST
		cout << "*** Pacman *** initing MPIModule" << endl;
		//#endif
		((Pacman*) *it)->initMPIModule();
*/
	#ifdef _RUN_MODE
			// Debut de l'evaluation
	//#ifndef _CONDITIONNING_MODE
		cout << "*** Pacman *** initing Eval Fitness" << endl;
		((Pacman*) *it)->initEvalFitness();
		((Pacman*) *it)->initEvalIndex();
	//#else

		// test n°1
		cerr << "*** Pacman *** testing Pacman " << ((Chromosome*) *it)->getTopoIndex() << " before run eval " << ((Pacman*) *it)->nbSteps  << endl;
		((Pacman*) *it)->test();

		((ZooStater*) stater)->statScoreBeforeRun((Pacman*) *it);
		((ZooTracer*) tracer)->trace((Pacman*) *it);

		((Pacman*) *it)->incrementEvalIndex();


	
		cout << "*** Pacman *** sending void synchro" << endl;
		((Pacman*) *it)->sendVoidSynchro();

			// run
		initZoo(LEVEL);
			
	#ifdef _GRAPHICAL_DISPLAY_MODE
		cout << "initing zoo displayer for individual " << ((Pacman*) *it)->getTopoIndex() << endl;
		((ZooDisplayer*) displayer)->initDisplayer((Zoo*) this);
	#endif
	
		((Pacman*) *it)->run();
		
		//#ifdef _ZOO_TEST
		cout << "delete Zoo" << endl;
		//#endif
		
		deleteZoo();
	
		((Pacman*) *it)->incrementEvalIndex();

	//#ifndef _CONDITIONNING_MODE
		cout << "*** Pacman *** set Eval Fitness" << endl;
		((Pacman*) *it)->setEvalFitness();
	//#endif

		cout << "*** Pacman *** sending void synchro" << endl;
		((Pacman*) *it)->sendVoidSynchro();

			// Fin de l'evaluation

		// test n°2
		cout << "*** Pacman *** Testing Pacman " << ((Chromosome*) *it)->getTopoIndex();
		cout << " after " << ((Pacman*) *it)->nbSteps << " nb steps" << endl;

		((Pacman*) *it)->test();
		((ZooStater*) stater)->statScoreAfterRun((Pacman*) *it);
		((ZooTracer*) tracer)->trace((Pacman*) *it);

	#else
		cerr << "*** Pacman *** testing Pacman " << ((Chromosome*) *it)->getTopoIndex() << endl;
		((Pacman*) *it)->test();
		((ZooStater*) stater)->trace((Pacman*) *it);
		((ZooTracer*) tracer)->trace((Pacman*) *it);
	#endif

		// Si graph du réseau
		//((Pacman*) *it)->waitSynchro();

		//#ifdef _MPI_TEST
		cout << "*** Pacman *** freeing MPIModule" << endl;
		//#endif
		((Pacman*) *it)->freeMPIModule();

	#ifdef _GRAPHICAL_DISPLAY_MODE
		((Pacman*) *it)->freePacmanDisplayer();
	#endif
		//((Individual*) *it)->endIndividualFiles();

		incrementTopoIndex();

		if (NB_INDIVIDUS <= getTopoIndex())
		{
			cerr << "Breaking, topo index " << getTopoIndex() << " higher than " << NB_INDIVIDUS << endl;
			break;
		}
		it++;
	}
}

void Zoo::testEvo()
{
	initLoader();

	initRandom();

	initZooFiles();

	initEvoIndex();

	while (getEvoIndex() < NB_GENERATIONS)
	{
		if (getEvoIndex() == 0 || getEvoIndex() == NB_GENERATIONS-1)
		{
			if (((ZooLoader*) loader)->load(this,getEvoIndex()))
			{
				cout << "Entering test with " << tabChromosomes.size() << " chromosomes to test" << endl;

		#ifdef _POPULATION_STAT_MODE
				((ZooStater*) stater)->initAccumulaters();
		#endif
				testPopulation();

		#ifdef _POPULATION_TRACE_MODE
				((ZooTracer*) tracer)->trace(this);
		#endif

		#ifdef _POPULATION_STAT_MODE
				((ZooStater*) stater)->stat(this);
				((ZooStater*) stater)->trace(this);
		#endif
				//endPopulationFiles();
			}
			else
			{
				cerr << "No population " << getEvoIndex() << " was loaded" << endl;
			}
		}
		else
		{
		//#ifdef _ZOO_TEST
			cout << "Population " << getEvoIndex() << " not tested" << endl;
		//#endif
		}

		incrementEvoIndex();
	}


	endZooFiles();

	cerr << "Out of test loop " << endl;

	closeLoader();

	((Pacman*) tabChromosomes[0])->sendBreak();

	cout << "*** Root Module " << MPI_GLOBALS.getMyId() << " *** after break synchronizing with synchro modules" << endl;
  	((Pacman*) tabChromosomes[0])->sendBreak();
}
#endif

void Zoo::testBestPopulation()
{
	vector<Chromosome*>::iterator it = tabChromosomes.begin();
	vector<Chromosome*>::iterator end = tabChromosomes.end();

	initTopoIndex();

	while (it!=end)
	{

		// Debut de l'evaluation
	//#ifndef _CONDITIONNING_MODE
		cout << "*** Pacman *** initing Eval Fitness" << endl;
		//((Pacman*) *it)->initEvalFitness();
		((Pacman*) *it)->initEvalIndex();
	//#else
		//#ifdef _MPI_TEST
		cout << "*** Pacman *** sending chromosome to *** EDNetwork ***" << endl;
		//#endif
		((Pacman*) *it)->setSynchroBuffers();
		((Pacman*) *it)->sendSynchro();

		//#ifdef _MPI_TEST
		cout << "*** Pacman *** initing MPIModule" << endl;
		//#endif
		((Pacman*) *it)->initMPIModule();

	#ifdef _GRAPHICAL_DISPLAY_MODE
		((Pacman*) *it)->initPacmanDisplayer();
	#endif

	#ifdef _RUN_MODE

		// Run

		((Pacman*) *it)->run();

	#else
		#ifdef _TEST_MODE
		cerr << "*** Pacman *** testing Pacman " << ((Chromosome*) *it)->getTopoIndex() << endl;

			#ifdef _PARAMETRIC_TEST_MODE
		int count=0;
		while (count<NB_PARAMETRIC_TESTS)
		{
			((Pacman*) *it)->testAllZoo();

			count++;

			if (count< NB_PARAMETRIC_TESTS)
			{
				((Pacman*) *it)->sendSynchro();
			}

		}
			#else
		((Pacman*) *it)->testAllZoo();
			#endif
		#else
			#ifdef _PARAMETRIC_TEST_MODE
		int count=0;
		while (count<NB_PARAMETRIC_TESTS)
		{
			((Pacman*) *it)->testVoid();

			count++;

			if (count< NB_PARAMETRIC_TESTS)
			{
				((Pacman*) *it)->sendSynchro();
			}

		}
			#else
		((Pacman*) *it)->testVoid();
			#endif
		#endif

	#endif

		//#ifdef _MPI_TEST
		cout << "*** Pacman *** freeing MPIModule" << endl;
		//#endif
		((Pacman*) *it)->freeMPIModule();

	#ifdef _GRAPHICAL_DISPLAY_MODE
		((Pacman*) *it)->freePacmanDisplayer();
	#endif
		//((Individual*) *it)->endIndividualFiles();

		incrementTopoIndex();

		if (NB_INDIVIDUS <= getTopoIndex())
		{
			cerr << "Breaking, topo index " << getTopoIndex() << " higher than " << NB_INDIVIDUS << endl;
			break;
		}
		it++;
	}
}

#ifdef _TEST_BEST_POPULATION_MODE
void Zoo::testBestChromos()
{
	initLoader();

	initRandom();

	initEvoIndex();

	while (getEvoIndex() < NB_GENERATIONS)
	{
		if (getEvoIndex() == NB_GENERATIONS-1)
		{
			if (((ZooLoader*) loader)->load(this,getEvoIndex()))
			{
				cout << "Entering test with " << tabChromosomes.size() << " chromosomes to test" << endl;
	
				testBestPopulation();
			}
			else
			{
				cerr << "Warning, No best population " << NB_GENERATIONS-1 << " was loaded" << endl;
			}
		}
		else
		{
			cerr << "No population " << getEvoIndex() << " was loaded" << endl;
		}
		
		incrementEvoIndex();
	}

	cerr << "Out of test loop " << endl;

	closeLoader();

	((Pacman*) tabChromosomes[0])->sendBreak();

	cout << "*** Root Module " << MPI_GLOBALS.getMyId() << " *** after break synchronizing with synchro modules" << endl;
  	((Pacman*) tabChromosomes[0])->testSynchro();
	((Pacman*) tabChromosomes[0])->testSynchro();
}
#endif

#ifdef _TEST_RANDOM_POPULATION_MODE
void Zoo::testRandomChromos()
{
	initLoader();

	initRandom();

	initEvoIndex();

	if (((ZooLoader*) loader)->load(this,getEvoIndex()) && getEvoIndex() == 0)
	{
		cout << "Loaded chromosomes to test from Chromosome" << getEvoIndex() << ".txt" << endl;
		
		cout << "Entering test with " << tabChromosomes.size() << " chromosomes to test" << endl;

		testBestPopulation();
	}
	else
	{
		cout << "Entering test with " << tabChromosomes.size() << " chromosomes to test" << endl;
		initPacmans();
		
		testBestPopulation();
		
		cout << "Saving population" << endl;

		initSaver();
		
		((ZooSaver*) saver)->save(this);	
		
	}

	cerr << "Out of test loop " << endl;

	closeLoader();

	((Pacman*) tabChromosomes[0])->sendBreak();

	cout << "*** Root Module " << MPI_GLOBALS.getMyId() << " *** after break synchronizing with synchro modules" << endl;
  	((Pacman*) tabChromosomes[0])->testSynchro();
}
#endif

ostream& operator<<(ostream& o, Zoo* z)
{
	//o << z->getEvoIndex() << " ";

	//z->initTopoIndex();

	z->initTopoIndex();

	copy(z->tabChromosomes.begin(),z->tabChromosomes.end(),ostream_iterator<Chromosome*>(o,"\n"));

	return o;
}

istream& operator>>(istream& i, Zoo* z)
{
	cerr << "In Zoo >> for population " << z->getEvoIndex() << endl;

	//int readIndex;
	//if (i >> readIndex)
	//{
	//cout << "Zoo index: " << z->getEvoIndex() << endl;

	z->initTabChromosomes();
	//z->initTopoIndex();
	//}
	//else
	//{
	//	cerr << "Warning, read index: " << readIndex << "(" << z->getEvoIndex() << ")" << endl;
	//	return i;
	//}

	Pacman* pac;

	//while (i >> (pac = new Pacman(*z)) && pac->getIndex() < NB_INDIVIDUS/2 )
	//while (i >> (pac = new Pacman(*z)) && pac->getIndex() < NB_INDIVIDUS-1 )

	int topoIndex = 0;

	//while (i >> (pac = new Pacman(*z)))
	while (i >> (pac = new Pacman(z)))
	{
		#ifdef _SINGLE_INDIVIDUAL_MODE

			#ifdef _BEST_INDIVIDUAL_MODE
		
		if (topoIndex <= NB_INDIVIDUS-1)
		{
			cout << "Adding pacman " << topoIndex << " to tabChromosomes" << endl;
			z->tabChromosomes.push_back((Chromosome*) pac);
/*
			if (topoIndex == 2)
			{

				cout << "Adding pacman " << topoIndex << " to tabChromosomes" << endl;
				z->tabChromosomes.push_back((Chromosome*) pac);
			}
*/
		}
		else
		{
			cerr << "Warning, wrong chromosome index " << topoIndex << endl;
			break;
		}

		topoIndex++;

		if (1 <= topoIndex)
		{
			cerr << "Breaking, topo index " << topoIndex << " higher than " << 1 << endl;
			break;
		}
			#else
		
		if (topoIndex == SINGLE_INDIVIDUAL_INDEX)
		{
			cout << "Adding pacman " << topoIndex << " to tabChromosomes" << endl;
			z->tabChromosomes.push_back((Chromosome*) pac);
/*
			if (topoIndex == 2)
			{

				cout << "Adding pacman " << topoIndex << " to tabChromosomes" << endl;
				z->tabChromosomes.push_back((Chromosome*) pac);
			}
*/
			break;
		}

		topoIndex++;
		
		if (NB_INDIVIDUS <= topoIndex)
		{
			cerr << "Breaking, topo index " << topoIndex << " higher than " << NB_INDIVIDUS << endl;
			break;
		}
	
			#endif

		#else
	
		if (topoIndex <= NB_INDIVIDUS-1)
		{
			cout << "Adding pacman " << topoIndex << " to tabChromosomes" << endl;
			z->tabChromosomes.push_back((Chromosome*) pac);
/*
			if (topoIndex == 2)
			{

				cout << "Adding pacman " << topoIndex << " to tabChromosomes" << endl;
				z->tabChromosomes.push_back((Chromosome*) pac);
			}
*/
		}
		else
		{
			cerr << "Warning, wrong chromosome index " << topoIndex << endl;
			break;
		}

		topoIndex++;

			#ifdef _FIRST_BEST_INDIVIDUALS_MODE
		if (NB_FIRST_BEST_INDIVIDUALS <= topoIndex)
		{
			cerr << "Breaking, topo index " << topoIndex << " higher than " << NB_FIRST_BEST_INDIVIDUALS << endl;
			break;
		}	
			#else
		if (NB_INDIVIDUS <= topoIndex)
		{
			cerr << "Breaking, topo index " << topoIndex << " higher than " << NB_INDIVIDUS << endl;
			break;
		}	
			#endif
		#endif
	}

	cout << "Loaded " << z->tabChromosomes.size() << " chromosomes for population " << z->getEvoIndex() << endl;

	return i;
}

// Zoo.h

#ifndef _ZOO_H
#define _ZOO_H

// STL includes
#include <iostream>

// pour system (NEW)
#include <cstdlib>

// Local Includes
#include "../Define.h"
#include "../DefineZoo.h"
#include "../DefineGA.h"
#include "../DefineTracer.h"
#include "../DefineGrapher.h"
#include "../DefineStater.h"

#include "../DefineWindow.h"

#include "Pacman.h"
#include "Menagerie.h"

#include "../MathTools/RandomMathTools.h"

#include "../Objets/FileObject.h"

#include "../GeneticAlgorithm/Population.h"

#include "../Interfaces/Loadable.h"
#include "../Interfaces/Savable.h"
#include "../Interfaces/Displayable.h"
#include "../Interfaces/Statable.h"
#include "../Interfaces/Tracable.h"
#include "../Interfaces/Graphable.h"

class Zoo;
#include "../Tracers/ZooTracer.h"
#include "../Graphers/ZooGrapher.h"
#include "../Staters/ZooStater.h"
#include "../Loaders/ZooLoader.h"
#include "../Savers/ZooSaver.h"
#include "../Windows/ZooDisplayer.h"

/******************************************************************************************************************************************/
/**************************************************************** Classe Zoo **************************************************************/
/******************************************************************************************************************************************/

class Zoo : public Population, public Displayable, public Loadable, public Savable, public Statable, public Tracable, public Graphable
{
protected :

	Menagerie menagerie;

	// la grille du zoo contenant les animaux
	int lignes,colonnes;
	char ** zoo;

	// A mettre dans _RUN_MODE, ou non si test dans le zoo
	friend class ZooDisplayer;

	// Pacmans
	friend class Pacman;
	void initPacmans();

	// Detruit le Zoo
	void deleteZoo();

	// fait tourner le pacman courrant dans le zoo
	void tourner(Pacman* pac);

public :
	// constructeurs, destructeur
	Zoo();
	~Zoo();


	// acces aux attributs
	char operator()(int x,int y);
	Menagerie & getMenagerie();
	void getTaille(int &x,int &y);

	// Test une fois l'évolution effectuée de la structure topologique pour toutes les générations
	void statEvo();

#ifdef _RUN_MODE

	// la fonction d'initialisation
	void initZoo(int level);

	// test si le pacman courant est mort
	bool mort(Pacman* pac);

	// fait bouger les animaux
	void vivre(Pacman* pac);

	// donne les probas de bouger un animal selon les positions des pacmans
	void probasAnimaux(int i,int j,double probas[4],Pacman* pac);
	// fait avancer le pacman courrant dans le zoo
	void avancer(Pacman* pac);

	// methodes principales
	void evaluatePopulation();
	void runEvo();

	#ifdef _CLUSTER_EVO_MODE
	virtual void clusterizeChromos();
	#endif

#endif
	// Special test.cc
#ifdef _TEST_MODE

	virtual void initTestZoo(int level);

	virtual void testAvancer(Pacman* pac);
	virtual bool testMort(Pacman* pac);

	void testPopulation();
	void testEvo();

#endif

	void testBestPopulation();

#ifdef _TEST_BEST_POPULATION_MODE
	void testBestChromos();
#endif

#ifdef _TEST_RANDOM_POPULATION_MODE
	void testRandomChromos();
#endif

	friend class ZooSaver;
	void initSaver();
	void closeSaver();

	friend class ZooLoader;
	void initLoader();
	void closeLoader();


	void initZooFiles();
	void endZooFiles();

	//#ifdef _TRACE_MODE
	//void initPopulationFiles();
	//void endPopulationFiles();
	//#endif
#ifdef _POPULATION_STAT_MODE
	friend class ZooStater;
#endif
#ifdef _POPULATION_TRACE_MODE
	friend class ZooTracer;
#endif
#ifdef _POPULATION_GRAPH_MODE
	friend class ZooGrapher;
#endif
	friend ostream& operator<<(ostream& o, Zoo* z);
	friend istream& operator>>(istream& i, Zoo* z);
};

#endif

// Pacman.h

#ifndef _PACMAN_H
#define _PACMAN_H

#include <vector>
#include <iterator>
using namespace std;

// Local Includes
#include "../Define.h"
#include "../DefineZoo.h"

#include "../DefineEDNetwork.h"
#include "../DefineGA.h"
#include "../DefineMPI.h"

#include "../DefineWindow.h"

#include "../DefineTester.h"
#include "../DefineStater.h"

#include "../MPI/RootModule.h"

#include "Menagerie.h"
#include "Animal.h"
#include "Zoo.h"

#include "../EDNetwork/EDNetwork.h"

//#include "TestLab.h"

#include "../MathTools/RandomMathTools.h"

#include "../Interfaces/Displayable.h"

#include "../GeneticAlgorithm/Individual.h"

#include "../Interfaces/TestIndexable.h"

class Pacman;
#include "../Windows/PacmanDisplayer.h"


// Matrice définissant l'ordre de test des inputs auditifs
#if (AUDIO_RANGE_DEPTH==5)
static int distMatrix[5][5]=
{
{5,4,3,4,5},
{4,2,1,2,4},
{3,1,0,1,3},
{4,2,1,2,4},
{5,4,3,4,5}
};
#elif (AUDIO_RANGE_DEPTH==11)
static int distMatrix[11][11]=
{

{11,10,9,8,7,6,7,8,9,10,11},
{10,9,8,7,6,7,8,9,10},
{9,8,5,4,3,4,5,8,9},
{8,7,4,2,1,2,4,7,8},
{7,6,3,1,0,1,3,6,7},
{7,6,3,1,0,1,3,6,7},
{8,7,4,2,1,2,4,7,8},
{9,8,5,4,3,4,5,8,9},
{10,9,8,7,6,7,8,9,10},

};
#endif

/******************************************************************************************************************************************/
/************************************************************* Classe Pacman **************************************************************/
/******************************************************************************************************************************************/

// le pacman est le heros de notre simulation !
class Pacman : public RootModule, public Individual, public Displayable, public TestIndexable
{
  Direction dirMvt;
  Direction dirVue;

  int comptMoveBodyOnLeft;
  int comptMoveBodyOnRight;

  int comptMoveHeadOnLeft;
  int comptMoveHeadOnRight;
  
  void initSynchroBuffers();
  void setSynchroBuffers();

  void initInputBuffers();
  void initOutputBuffers();

#ifdef _GRAPHICAL_DISPLAY_MODE
  void initPacmanDisplayer();
  void freePacmanDisplayer();
#endif
  void waitSynchro();

  void integrateOutputs();
  void sendOutputs();

  void receiveInputs();
  void integrateInputs();
#ifdef _CONDITIONNING_MODE

	#ifdef _PREDATOR_CONTACT_PUNISHES_PACMAN_MODE
  void sendPunish();
	#endif

	#ifdef _PREY_CONTACT_REWARDS_PACMAN_MODE
  void sendReward();
	#endif

   void sendRandomReward();
#endif

  void integrateVisioOutputs();
  void integrateAudioOutputs();

  void integrateVisioOutputs(int columnIndex);
  void integrateAudioOutputs(int lateralityIndex);

  // methodes internes
  void receiveMotorPatterns();
  void initComptMove();


private:

  Menagerie &menagerie;

public :

  friend class Zoo;
  Zoo* zoo;

  Pacman(Zoo* zoo);
  Pacman(Pacman &pac);
  ~Pacman();

  virtual Chromosome* clone();
  //virtual void setFitness();

  // methode utile
  void getPosition(int &,int &);

  Direction getDirVue();
  Direction getDirMvt();


  void integrateBirthFlash();

  bool receiveVoidInputs();

#ifdef _RUN_MODE
  // en fonction de NB_MAX_STEPS
  void run();

  // input,output + mvt dans le zoo
  void runPacman();

  //mouvement dans le zoo
  void runOneStep();


  // ecrit les stats dans un fichier
	#ifdef _REAL_TIME_OF_COMPUTING_MODE
  void ecrireStats(double diffTime);
	#endif
	#ifndef _REAL_TIME_OF_COMPUTING_MODE
  void ecrireStats();
	#endif

  void initStats();
#endif

#ifdef _TEST_MODE

  friend class TestLab;

  void testPacman();
  void test();

  #ifdef _WAITING_PERIOD_TEST_MODE
  void waitPeriod();
  #endif
  
  void testOneStep();
  //bool testMotorInput(Animal& a, int posX, int posY);
  //void testMotorInput(Animal& a, int posX, int posY);
  
		#if (defined(_TEST_BEST_POPULATION_MODE) || defined (_TEST_RANDOM_POPULATION_MODE))
  void testAllZoo();
  		#endif
		
		#ifdef _NO_MOVE_TEST_MODE
  void integrateTestOutputs(const Animal& animalTest);
  void testBestPacman(int animalIndex);
		#endif
	//#endif
#else
	//#ifdef _TEST_BEST_POPULATION_MODE
  void testVoid();
	//#endif
#endif

  //friend class PacmanGrapher;

  friend ostream& operator<<(ostream& o, Pacman* p);
  friend istream& operator>>(istream& i, Pacman* p);

};

#endif

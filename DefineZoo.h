//defineZoo.h
#ifndef _DEFINE_ZOO_H
#define _DEFINE_ZOO_H

#include "Define.h"
#include "DefinePhysiology.h"
//#include "DefineWindow.h"

/****************************************************************************************************************************************/
/****************************************************** Parametres du Zoo ***************************************************************/
/****************************************************************************************************************************************/

enum Personnalite
{
	MECHANT = -1,
	NEUTRE,
	GENTIL
};

// attention, l'ordre des direction n'est pas qcq
// c'est dans le sens trigo (vous pouvez faire des permutations circulaires entres les 4 premier)
enum Direction
{
	HAUT = 0,
	DROITE,
	BAS,
	GAUCHE,
	STOP
};
/*
enum RelativeDirection
{
	RELATIVE_STOP=0,
	TURN_LEFT,
	TURN_RIGHT,
	GO_AHEAD
};
*/
	// Paramètres du zoo

// "Niveau" du zoo (correspond au fichier screen.? dans screens/)
#define LEVEL 0

	// Définition du moteur

#define MOTOR_GRAPHICAL_SIZE 10

// Activité maximale des neurones d'une couche rapportée au nombre total de neurones
#ifdef _BLOCKING_MODE
	//#define MIN_ACTIVITY_RATIO 5.0
	//#define MIN_ACTIVITY_RATIO 3.0
	//#define MIN_ACTIVITY_RATIO 2.0
	#define MIN_ACTIVITY_RATIO 1.0
	//#define MIN_ACTIVITY_RATIO 0.8
#else
	//#define MIN_ACTIVITY_RATIO 2.25
	//#define MIN_ACTIVITY_RATIO 2.0
	//#define MIN_ACTIVITY_RATIO 1.5
	#define MIN_ACTIVITY_RATIO 1.0
	//#define MIN_ACTIVITY_RATIO 0.5
#endif

// Activité différentielle entre deux assemblées outputs complémentaires
#ifdef _BLOCKING_MODE
	//#define MIN_DIFF_ACTIVITY_RATIO 3.0
	//#define MIN_DIFF_ACTIVITY_RATIO 2.5
	//#define MIN_DIFF_ACTIVITY_RATIO 2.0
	//#define MIN_DIFF_ACTIVITY_RATIO 1.5
	#define MIN_DIFF_ACTIVITY_RATIO 1.0
	//#define MIN_DIFF_ACTIVITY_RATIO 0.5
#else

	#ifdef _SELF_INHIBITION_MODE
		#define MIN_DIFF_ACTIVITY_RATIO (MIN_ACTIVITY_RATIO*0.05)
	#else
		#define MIN_DIFF_ACTIVITY_RATIO (MIN_ACTIVITY_RATIO*0.95)
		//#define MIN_DIFF_ACTIVITY_RATIO (MIN_ACTIVITY_RATIO*0.05)
	#endif
	//#define MIN_DIFF_ACTIVITY_RATIO (0.95)
	//#define MIN_DIFF_ACTIVITY_RATIO (0.7)
#endif

	// Calcul du fitness

// Mesure le temps réel d'éxection du programme
#define _REAL_TIME_OF_COMPUTING_MODE

// Intervale de temps entre 2 vagues successives
//#define INTER_WAVE_PERIOD (PSP_TEMPORAL_IMPACT)
#define INTER_WAVE_PERIOD (DELAY)

#ifdef _TEST_MODE

	#ifdef _NO_MOVE_TEST_MODE

		#ifdef _BLOCKING_MODE
			// Temps maximal de stimulation
			#define NB_MAX_TEST_STEPS (100)
			//#define NB_MAX_TEST_STEPS (10)
		#else
			// Temps maximal passé dans le mini-zoo
			#define NB_MAX_TEST_STEPS (100*INTER_WAVE_PERIOD*MIN_ACTIVITY_RATIO)
		#endif

		// Nombre de repetitions testees
		#ifdef _REPETITIVE_TEST_MODE
			//#define NB_TESTED_ANIMALS 3
			#define NB_TESTED_ANIMALS 10
		#else
			#define NB_TESTED_ANIMALS 1
		#endif
	#else
		#ifdef _BLOCKING_MODE
		
			// Temps maximal passé dans le mini-zoo
			//#define NB_MAX_TEST_STEPS (10*MIN_ACTIVITY_RATIO)
			#define NB_MAX_TEST_STEPS (20*MIN_ACTIVITY_RATIO)
			//#define NB_MAX_TEST_STEPS (50*MIN_ACTIVITY_RATIO)
		#else
			// Temps maximal passé dans le mini-zoo
			//#define NB_MAX_TEST_STEPS (10*INTER_WAVE_PERIOD*MIN_ACTIVITY_RATIO)
			#define NB_MAX_TEST_STEPS (20*INTER_WAVE_PERIOD*MIN_ACTIVITY_RATIO)
			//#define NB_MAX_TEST_STEPS (50*INTER_WAVE_PERIOD*MIN_ACTIVITY_RATIO)
		#endif

		
		#ifndef _ORDERED_TEST_MODE
			// Nombre d'animaux du zoo testes
			//#define NB_TESTED_ANIMALS 10
			//#define NB_TESTED_ANIMALS 20
			//#define NB_TESTED_ANIMALS 50
			#define NB_TESTED_ANIMALS 100
		#endif
	#endif
#else
	#ifdef _REPETITIVE_TEST_MODE
		// Temps maximal de simulation
		#define NB_MAX_TEST_STEPS 2200
	#else
		// Temps maximal de simulation
		#define NB_MAX_TEST_STEPS 400
	#endif
	
#endif

#ifdef _RUN_MODE
	// Temps maximal passé dans le zoo
	#ifdef _BLOCKING_MODE
		#define NB_MAX_STEPS (1000*MIN_ACTIVITY_RATIO)

	#else
		#define NB_MAX_STEPS (1000*INTER_WAVE_PERIOD*MIN_ACTIVITY_RATIO)
	#endif
#endif

// Chaque individu est évalué plusieurs fois. Son fitness correspond à la moyenne de chaque évaluation
#ifdef _LOWEST_FITNESS_MODE
	//#define NB_EVALUATIONS 4
	//#define NB_EVALUATIONS 2
	#define NB_EVALUATIONS 1
#endif

#ifdef _MEAN_FITNESS_MODE
	//#define NB_EVALUATIONS 4
	//#define NB_EVALUATIONS 2
	#define NB_EVALUATIONS 1
#endif
	// Pour les tests

	// Définition de la vision

#define VISIO_GRAPHICAL_SIZE 20
// Nombre de colonnes visuelles vues simultannement
/* Attention, doit impérativement etre impaire */
#define NB_VISIO_INPUTS 5

// Profondeur de chaque colonne
// Doit impérativement etre supérieur à (NB_VISIO_INPUTS-1)/2
#define VISIO_COLUMN_DEPTH 5

	// Définition de l'audition

// Nombre d'intervale frequentiel dans un son
#define AUDIO_GRAPHICAL_SIZE 16
//#define AUDIO_PICTURE_LENGTH 256

// Nombre de buffers dédiés à la modalité visuelle
#define NB_AUDIO_INPUTS 2

// Portée à laquelle l'audio peut aller
/* Attention, fixe pour l'instant à 5 ou 11*/
//#define AUDIO_RANGE_DEPTH 5
#define AUDIO_RANGE_DEPTH 11

// Frequence d'intégration des cris des animaux (1.0 au maximum)
#define ANIMAL_EMITS_SOUND_PROB 1.0

#ifdef _CONDITIONNING_MODE
	
	// Nombre de buffer pour traduction direct de la proximité d'un animal
	#define NB_CONDITIONNING_INPUTS 2
	
	// Définition du punish
	#define CONDITIONNING_GRAPHICAL_SIZE 20
	
	// Nombre de points perdus par la presence d'un prédateur
	#ifdef _BLOCKING_MODE
		#define NB_POINTS_EACH_PREDATOR (2*INTER_WAVE_PERIOD)
	#else
		#define NB_POINTS_EACH_PREDATOR 2
	#endif
	
	// Nombre de points par pacgum
	#ifdef _BLOCKING_MODE
		#define NB_POINTS_EACH_PACGUM 20
	#else
		#define NB_POINTS_EACH_PACGUM 20
	#endif
	
	// Niveau de vie initiale du pacman
	#define INITIAL_LIFE_LEVEL 200
	
	// Nombre de points par proie mangée
	#define NB_POINTS_EACH_PREY (10*NB_POINTS_EACH_PACGUM)

#else
	// Nombre de points par pacgum
	#define NB_POINTS_EACH_PACGUM 1

	// Nombre de points par proie mangée
	#define NB_POINTS_EACH_PREY 10

#endif


// Nombre de buffers dédiés aux mouvements moteur
#define NB_MOTOR_PATTERNS 4

	// Nombre d'inputs/outputs du pacman

// Parametres du pacman
#define PACMAN_NB_INPUTS (NB_MOTOR_PATTERNS)

#ifdef _CONDITIONNING_MODE

	// Nombre d'outputs du pacman
	#define PACMAN_NB_OUTPUTS (NB_VISIO_INPUTS+NB_AUDIO_INPUTS+NB_CONDITIONNING_INPUTS)
#endif
#ifndef _CONDITIONNING_MODE
	// Nombre d'outputs du pacman
	#define PACMAN_NB_OUTPUTS (NB_VISIO_INPUTS+NB_AUDIO_INPUTS)
#endif

	// Parametres internes au zoo

//marqueur d'activation des mouvement d'animaux
#define _MOVING_ANIMAL_MODE

#ifdef _MOVING_ANIMAL_MODE

        //probabilitée qu'un animal bouge ce tour ci
	#ifdef _BLOCKING_MODE
		//#define PROB_ANIMAL_MOUVEMENT 1.0/(2*MIN_ACTIVITY_RATIO)
		#define PROB_ANIMAL_MOUVEMENT 1.0/(5*MIN_ACTIVITY_RATIO)
		//#define PROB_ANIMAL_MOUVEMENT 1.0/(20*MIN_ACTIVITY_RATIO)
		//#define PROB_ANIMAL_MOUVEMENT 1.0/(50*MIN_ACTIVITY_RATIO)
	#else
		#define PROB_ANIMAL_MOUVEMENT 1.0/(5*MIN_ACTIVITY_RATIO*INTER_WAVE_PERIOD)
		//#define PROB_ANIMAL_MOUVEMENT 1.0/(2*MIN_ACTIVITY_RATIO*INTER_WAVE_PERIOD)
	#endif
#endif

#ifndef _MOVING_ANIMAL_MODE

        //les animaux ne bougent pas
        #define _QUIET_ANIMAL_MODE
#endif

#endif

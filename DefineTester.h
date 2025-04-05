// DefineSaver.h

#ifndef _DEFINE_SAVER_H
#define _DEFINE_SAVER_H

#include "Define.h"
#include "DefineStater.h"

/****************************************************************************************************************************************/
/****************************************************** Parametres des sauvegardes ******************************************************/
/****************************************************************************************************************************************/

#ifdef _TEST_MODE

	// Indice de l'assemblée recevant l'input visuel
	#define TEST_VISIO_INPUT_ASSEMBLY 2
			
	#ifdef _REPETITIVE_TEST_MODE
		//#define _REPETITIVE_PREDATOR_TEST_MODE
		
		#ifndef _REPETITIVE_PREDATOR_TEST_MODE
			#define _REPETITIVE_PREY_TEST_MODE
			
			#ifndef _REPETITIVE_PREY_TEST_MODE
				#define _ALTERNATED_REPETITIVE_TEST_MODE
			#endif
		#endif
		
		#ifdef _REPETITIVE_PREDATOR_TEST_MODE
			#define REPETITIVE_PREDATOR_INDEX 12
		#endif
		
		#ifdef _REPETITIVE_PREY_TEST_MODE
			#define REPETITIVE_PREY_INDEX 1
		#endif
		
		#ifdef _ALTERNATED_REPETITIVE_TEST_MODE
			#define REPETITIVE_PREDATOR_INDEX 11
			#define REPETITIVE_PREY_INDEX 0
		#endif
	#else
		// Mode de présentation aléatoire, mais autant de proies que de prédateurs
		//#define _RANDOM_TEST_MODE

		#ifndef _RANDOM_TEST_MODE
	
			//#ifdef _MULTI_TEST_MODE
			// Tous les animaux (proies et prédateurs sont présentés dans l'ordre
			#define _ORDERED_TEST_MODE
			//#endif
			
			#ifndef _ORDERED_TEST_MODE
	
				// Les tests pairs sont des proies, les tests impairs sont des prédateurs
				#define _ALTERNATED_TEST_MODE
			#endif
		#endif
	#endif

	#if (defined(_TEST_BEST_POPULATION_MODE) || defined(_TEST_RANDOM_POPULATION_MODE))

		// Tests bimodaux (audio + visio)
		#define _BIMODAL_TEST_MODE

		#ifndef _BIMODAL_TEST_MODE

			// Tests uniquement visuels
			#define _VISIO_TEST_MODE

			#ifndef _VISIO_TEST_MODE

				// Tests uniquement auditifs
				#define _AUDIO_TEST_MODE
			#endif
		#endif
		
	#endif

	//#define _MINI_SCREEN_MODE

	#ifdef _MINI_SCREEN_MODE
		#define X_TARGET_ANIMAL 3
		#define Y_TARGET_ANIMAL 6

		#define _SCREEN_FILENAME "miniscreen"
	#endif

	#ifndef _MINI_SCREEN_MODE

		#define _MINI_SCREEN2_MODE

		#ifdef _MINI_SCREEN2_MODE
			#define _SCREEN_FILENAME "miniscreen2"
			#define X_TARGET_ANIMAL 2
			#define Y_TARGET_ANIMAL 5

		#endif

		#define NB_MAX_PREYS 8
		#define NB_MAX_PREDATORS 2

		#define NB_MAX_SCREENS (NB_MAX_PREYS+NB_MAX_PREDATORS)
	#endif

#endif

#endif


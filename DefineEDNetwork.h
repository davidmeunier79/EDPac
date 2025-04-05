// DefineEDNetwork.h

#ifndef _DEFINE_ED_NETWORK_H
#define _DEFINE_ED_NETWORK_H

#include "Define.h"
#include "DefinePhysiology.h"
#include "DefineZoo.h"
#include "DefineMPI.h"

/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/******************************************************* Marqueurs de fonctionnement ******************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
enum projNature
{
	NO_PROJ_NATURE = -1,
	EXCIT,
	INHIB
};

enum assemblyNature
{
	NO_NATURE = -1,
	INPUT,
	OUTPUT
};

enum Colour
{
	BLANC = -1,
	GRIS,
	NOIR
};

#ifdef _TRACE_MODE

	// Marqueur de test du fonctionnement "run"
	//#define _TEST

	// Marqueur d'affichage sur la console
	//#define _CONSOLE_TRACE_MODE

	// Marqueur d'affichage de tous les potentiels de membrane et de PSPs (ofstream)
	#define _TEXT_TRACE_MODE

	#ifdef _TEXT_TRACE_MODE

		// Mode d'affichage des graphiques au format gnuplot
		#define _GNUPLOT_TRACE_MODE

		#ifndef _GNUPLOT_TRACE_MODE

			// Fichiers au format ELAN
			/*Attention, �mettre en place*/
			#define _ELAN_TRACE_MODE

		#endif

	#endif
#endif

#ifndef _BLOCKING_MODE

	// Inputs stochastiques, �ission d'autant plus fr�uente que le message �une valeur proche de 1.0
	#define _STOCHASTIC_INPUT_MODE

	#ifndef _STOCHASTIC_INPUT_MODE
		// Codage temporel "�la Thorpe"
		#define _TEMPORAL_CODING_INPUT_MODE
	#endif
#endif

#ifdef _INPUT_RATIO_TEST_MODE
	#define INPUT_RATIO_STEP 1
#endif

#ifdef _EXCIT_RATIO_TEST_MODE
	#define EXCIT_RATIO_STEP 1
#endif
				
#ifdef _INHIB_RATIO_TEST_MODE
	#define INHIB_RATIO_STEP 1
#endif

#ifdef _EXCIT_DEPRESSION_TEST_MODE
	#define EXCIT_DEPRESSION_STRENGTH_STEP 0.1
#endif

#ifdef _INHIB_DEPRESSION_TEST_MODE
	#define INHIB_DEPRESSION_STRENGTH_STEP 0.1
#endif

#ifdef _INHIB_STDP_TIME_TEST_MODE
	#define INHIB_STDP_TIME_STEP 5
#endif

#ifndef _TOPOLOGY_PROJECTION_MODE
	// Une projection correspond �une synapse entre chaque paire de neurones
	#define _ALL_TO_ALL_PROJECTION_MODE
	
	#ifndef _ALL_TO_ALL_PROJECTION_MODE
	
		// Chaque projection correspond au meme nombre de synapses
		#define _FIXED_RATIO_PROJECTION_MODE
	#endif
#endif

/******************************************************************************************************************************************/
/****************************************************************** Modes du r�eau *******************************************************/
/******************************************************************************************************************************************/

	// Parametres du r�eau de neurones
// Nombre d'assembl�s inputs (modaux)
#define NB_INPUT_ASSEMBLIES (PACMAN_NB_OUTPUTS)

// Pour TopologyDisplayer (longueur du carr�repr�ent� les assembl�s cach�s
#ifdef _LARGE_DISTRIBUTED_NETWORK_MODE

	#define SQRT_NB_ASSEMBLIES 10
#else
	#define SQRT_NB_ASSEMBLIES 5
#endif

// Nombre d'assembl�s cach�s
#define NB_ASSEMBLIES (SQRT_NB_ASSEMBLIES*SQRT_NB_ASSEMBLIES)

// Nombre d'assembl�s outputs (motrices)
#define NB_OUTPUT_ASSEMBLIES (NB_MOTOR_PATTERNS)

// Sp�ial assembl�s �olutionnistes:
#ifdef _LARGE_DISTRIBUTED_NETWORK_MODE

	#define SQRT_NB_NEURONS 5
	//#define SQRT_NB_NEURONS 7
#else
	#define SQRT_NB_NEURONS 10

#endif

// Nombre de neurones par assembl�s
#define NB_NEURONS_EACH_ASSEMBLY (SQRT_NB_NEURONS*SQRT_NB_NEURONS)

// Pour le TopologyDisplayer
#define NB_VISIO_NEURONS (VISIO_BUFFER_SIZE*NB_VISIO_INPUTS)

// Pour le TopologyDisplayer
#define NB_AUDIO_NEURONS (AUDIO_BUFFER_SIZE*NB_AUDIO_INPUTS)

#ifdef _CONDITIONNING_MODE

	#define NB_CONDITIONNING_NEURONS (CONDITIONNING_BUFFER_SIZE*NB_CONDITIONNING_INPUTS)
#endif

// Pour le TopologyDisplayer
#define NB_OUTPUTS_NEURONS (MOTOR_PATTERN_BUFFER_SIZE*NB_MOTOR_PATTERNS)

// Pour le TopologyDisplayer
#define NB_HIDDEN_NEURONS (NB_NEURONS_EACH_ASSEMBLY*NB_ASSEMBLIES)

#ifndef _OLD_CONFIG_MODE

	// Prise en compte de la distance topologique entre groupes pour le calcul de delai
	#define _TOPOLOGICAL_DELAY_MODE
	
	#ifdef _TOPOLOGICAL_DELAY_MODE
		#define DELAY_STEP 5
		
		#define MAX_DELAY (1.414*SQRT_NB_ASSEMBLIES)
	#endif
#endif
/******************************************************* Marqueurs de l'event manager *****************************************************/

#ifdef _TOPOLOGICAL_DELAY_MODE
	#define EVENT_MANAGER_SIZE (DELAY_STEP*MAX_DELAY+DELAY+INHIBITORY_DELAY)
	//#define EVENT_MANAGER_SIZE (DELAY_STEP*sqrt(2*NB_ASSEMBLIES))
#else
	#define EVENT_MANAGER_SIZE (DELAY+1)
#endif

#define PSP_EVENT_PACKAGE_SIZE 10000

/******************************************************* Marqueurs de calcul *****************************************************/

// Calcul de la d�roissance de la membrane avec une exponentielle discr�is�
// Si non d�ini, d�roissance lin�ire
//#define _DISCRETE_EXP_MODE

#ifdef _DISCRETE_EXP_MODE
	// Nombre de pas de discretisation de l'exponentielle
	#define NB_DISCRETE_EXP_STEPS 100

#endif

#endif

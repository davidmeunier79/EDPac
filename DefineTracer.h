// DefineTracer.h

#ifndef _DEFINE_TRACER_H
#define _DEFINE_TRACER_H

#include "Define.h"
#include "DefineStater.h"

/****************************************************************************************************************************************/
/****************************************************** Parametres des traces ***********************************************************/
/****************************************************************************************************************************************/
#ifdef _TRACE_MODE

	// Suivi des traces
	//#define _TRACE_TEST

	#ifdef _RUN_MODE

		// Suivi du fitness des chromosomes de la population
		#define _POPULATION_TRACE_MODE
	#endif

	#ifdef _TEST_BEST_POPULATION_MODE

		#ifndef _MULTI_TEST_MODE
			// Suivi des paramètres du réseau (tres lent...)
			//#define _NETWORK_TRACE_MODE
		#endif
		
	#endif
#endif

#ifdef _POPULATION_TRACE_MODE

	// Fichier de trace de tous les chromosomes
	#define FITNESS_FILENAME "Fitness"

	#ifdef _SINGLE_INDIVIDUAL_MODE

		#define _INDIVIDUAL_TRACE_MODE

		#ifdef _INDIVIDUAL_TRACE_MODE

			// Suivi du niveau de vie des pacmans
			#define LIFE_LEVEL_FILENAME "LifeLevel"

			// Suivi des positions des pacmans
			#define POSITION_FILENAME "Position"

		#endif
	#endif
#endif


/******************************************************* Marqueurs de suivi d'éxecution ***************************************************/

// Specification du format de sauvegarde des fichiers trace
#ifdef _NETWORK_TRACE_MODE

	// Affiche les valeurs de tous les objets dans les fichiers trace
	/* A tester.. */
	#define _GLOBAL_TRACE_MODE

	#ifndef _GLOBAL_TRACE_MODE

		// Suit une assemblée précise

		/* Attention, tres long... */
		//#define _SINGLE_ASSEMBLY_TRACE_MODE

		#ifdef _SINGLE_ASSEMBLY_TRACE_MODE

			// Le suivi des stats cible la meme assemblée par défaut
			#ifndef _SINGLE_ASSEMBLY_STAT_MODE

				// Index de l'assemblée précise
				#define SINGLE_ASSEMBLY_INDEX 1
			#endif
		#else

			// Affiche un unique neurone dans les fichiers trace
			//#define _SINGLE_NEURON_TRACE_MODE

			#ifdef _SINGLE_NEURON_TRACE_MODE

				// Index du neurone trace
				#define SINGLE_NEURON_INDEX 120
				//#define SINGLE_NEURON_INDEX 750
			#else
				// Affiche une unique synapse dans les fichiers trace
				#define _SINGLE_SYNAPSE_TRACE_MODE

				#ifdef _SINGLE_SYNAPSE_TRACE_MODE
					// Index de la synapse tracee
					// Inhib
					//#define SINGLE_SYNAPSE_INDEX 235300
					
					//#define SINGLE_SYNAPSE_INDEX 1571800
					//#define SINGLE_SYNAPSE_INDEX 142800
					//#define SINGLE_SYNAPSE_INDEX 1875
					//#define SINGLE_SYNAPSE_INDEX 865495
					
					// Excit
					#define SINGLE_SYNAPSE_INDEX 339345
					//#define SINGLE_SYNAPSE_INDEX 1840850
					//#define SINGLE_SYNAPSE_INDEX 1723050
					//#define SINGLE_SYNAPSE_INDEX 1242795
					
					
					//#define SINGLE_SYNAPSE_INDEX 245463
					//#define SINGLE_SYNAPSE_INDEX 540075
					//#define SINGLE_SYNAPSE_INDEX 723300
					//#define SINGLE_SYNAPSE_INDEX 1954078
					 
					//#define SINGLE_SYNAPSE_INDEX 100000
					//#define SINGLE_SYNAPSE_INDEX 250000
					//#define SINGLE_SYNAPSE_INDEX 500000
					//#define SINGLE_SYNAPSE_INDEX 750000
					//#define SINGLE_SYNAPSE_INDEX 1000000
					//#define SINGLE_SYNAPSE_INDEX 1500000
				#endif

			#endif
		#endif

	#endif


	// Affiche le potentiel de membrane et le seuil dans des fichiers locaux aux neurones
	#define _NEURON_TRACE_MODE

	#ifdef _NEURON_TRACE_MODE

		// Affichage des potentiels de membrane
		#define _MEMBRANE_POTENTIAL_TRACE_MODE

		#ifdef _MEMBRANE_POTENTIAL_TRACE_MODE

			// Fichier de stockage des potentiels de membrane
			#define MEMBRANE_POTENTIAL_FILENAME "MembranePotential"
		#endif

		#ifdef _SINGLE_NEURON_TRACE_MODE

			// Affichage des seuils
			#define _THRESHOLD_TRACE_MODE
		#else
			#ifdef _SINGLE_SYNAPSE_TRACE_MODE

				// Affichage des seuils
				#define _THRESHOLD_TRACE_MODE

			#endif
		#endif

		#ifdef _THRESHOLD_TRACE_MODE

			// Fichiers de stockage des seuils
			#define THRESHOLD_FILENAME "Threshold"
		#endif

		#ifdef _GRAPH_MODE

			// Nom du gnuplot pour le tracage des graphs des neurones
			#define NEURON_FILENAME "NeuronFiles"
		#endif
	#endif

	// Affiche les paramètres des synapses
	// (poids de chaque synapse, poids moyen d'entrée de chaque neurone, délai d'entrée moyen...)
	#ifndef _SINGLE_ASSEMBLY_TRACE_MODE
		#ifdef _ONLINE_LEARNING_MODE
			#define _SYNAPSE_TRACE_MODE
		#endif
	#endif

	#ifdef _SYNAPSE_TRACE_MODE

		// Sauvegarde les poids de toutes les synapses à chaque mise à jour
		// Defini seulement si apprentissage on-line
		//#ifdef _ONLINE_LEARNING_MODE
			#define _WEIGHT_TRACE_MODE
		//#endif

		#ifdef _WEIGHT_TRACE_MODE

			// Nom du fichier trace
			#define WEIGHT_FILENAME "SynapticWeights"
		#endif

	#endif
#endif


#endif

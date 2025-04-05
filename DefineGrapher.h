// DefineGrapher.h

#ifndef _DEFINE_GRAPHER_H
#define _DEFINE_GRAPHER_H

#include "Define.h"
#include "DefineTracer.h"

/****************************************************************************************************************************************/
/****************************************************** Parametres des graphes **********************************************************/
/****************************************************************************************************************************************/

// Graph de la population
#ifdef _GRAPH_MODE

	// Suivi du fitness et des valeurs du zoo
	#define _POPULATION_GRAPH_MODE

	#ifdef _NETWORK_TRACE_MODE
		// Graphs réalisés à partir des traces
		#define _NETWORK_GRAPH_MODE
	#endif
#endif


/******************************************************* Marqueurs des graphiques du zoo *********************************************************/

#ifdef _POPULATION_GRAPH_MODE

	#define FITNESS_GRAPH_NAME "ZooFitness"

	#ifdef _INDIVIDUAL_TRACE_MODE

		#define _INDIVIDUAL_GRAPH_MODE

		#ifdef _INDIVIDUAL_GRAPH_MODE

			#define INDIVIDUAL_GRAPH_NAME "IndividualTraces"
		#endif
	#endif

	#ifdef _TEST_MODE
		#define BEHAVIOUR_FILENAME "BehaviourTraces"
	#endif
#endif
/******************************************************* Marqueurs des graphiques du réseau *********************************************************/

#ifdef _NETWORK_GRAPH_MODE

	#ifdef _GNUPLOT_TRACE_MODE

		// Lie les points obtenus par des lignes
		#define _GNUPLOT_DOTS_GRAPH_MODE

		#ifndef _GNUPLOT_DOTS_GRAPH_MODE

			// Affiche seulement les points
			#define _GNUPLOT_POINTS_GRAPH_MODE
		#endif

	#endif

		// Echelle de précision de l'affichage des graphs (niveau réseau, assemblée, neurone ou synapse)

	#ifdef _SINGLE_ASSEMBLY_TRACE_MODE

		// Affichage au niveau de l'assemblée
		#define _ASSEMBLY_GRAPH_MODE

		// Affichage au niveau du neurone
		#define _NEURON_GRAPH_MODE

		// Affichage au niveau de la synapse
		//#define _SYNAPSE_GRAPH_MODE
	#endif
	
	#ifdef _SINGLE_NEURON_TRACE_MODE

		// Affichage au niveau du neurone
		#define _NEURON_GRAPH_MODE

		// Affichage au niveau de la synapse
		#define _SYNAPSE_GRAPH_MODE
	#endif
	
	#ifdef _SINGLE_SYNAPSE_TRACE_MODE

		// Affichage au niveau du neurone
		#define _NEURON_GRAPH_MODE

		// Affichage au niveau de la synapse
		#define _SYNAPSE_GRAPH_MODE
	#endif

	#ifdef _GLOBAL_TRACE_MODE

		// Affiche la somme des impacts dans un meme fichier
		#define _LFP_GRAPH_MODE

		#ifdef _LFP_GRAPH_MODE

			// Largeur du bin pour sommer les temps d'emission
			#define BIN_LENGTH (1)
		#endif

	#endif

#endif

// Caractéristique de chaque fichier

// Affiche tous les graphiques dans un meme fichier
#define _MULTIPLOT_GRAPH_MODE

#ifndef _MULTIPLOT_GRAPH_MODE

	// Affiche tous les graphiques dans un fichier différent
	#define _SINGLE_PLOT_GRAPH_MODE
#endif

#endif


// DefineStater.h

#ifndef _DEFINE_STATER_H
#define _DEFINE_STATER_H

#include "Define.h"

/****************************************************************************************************************************************/
/****************************************************** Parametres des stats ************************************************************/
/****************************************************************************************************************************************/

#ifdef _STAT_MODE

	#ifdef _RUN_MODE
		//#ifdef _TEST_MODE
		//Suivi des stats d'apprentissage des populations
		#define _POPULATION_STAT_MODE
		//#endif
				
		#ifdef _POPULATION_STAT_MODE
		
			// Fitness moyen d'une g��ation pour chaque g��ation
			#define MEAN_FITNESS_FILENAME "MeanFitness"
		
			// Meilleur individu d'une g��ation pour chaque g��ation
			#define BEST_FITNESS_FILENAME "BestFitness"
		
		#endif

	#else
		#if (defined(_TEST_BEST_POPULATION_MODE) || defined(_TEST_RANDOM_POPULATION_MODE))

			// Suivi de l'activit�par assembl�
			//#define _ASSEMBLY_STAT_MODE

			#ifndef _PARAMETRIC_TEST_MODE
			
				// Les assembl�es sont tri�es en fonction de leur activit�			
				#define _SORT_ASSEMBLY_STAT_MODE
			#endif

			#ifdef _PHASE_TEST_MODE

				// Fait les stats sur les transitions
				// (d�ut de phase) plutot que sur les phases completes
				//#define _TRANSITION_STAT_MODE

				#ifdef _TRANSITION_STAT_MODE
					#define TRANSITION_TIME_STEP 10
				#endif

			#endif
											
			#ifdef _ASSEMBLY_STAT_MODE
			
				// Suivi de l'activit�global
				#define _GLOBAL_STAT_MODE
				
				#ifdef _GLOBAL_STAT_MODE
			
					// Plot des graphiques en 2D et 3D
					//#define _PHASE_STAT_MODE
					
					// Suivi des stats sur les synapses
					//#define _GLOBAL_SYNAPSE_STAT_MODE
					
					// Pas de stats avec les assemblees liees aux inputs
					//#define _NO_LINK_INPUT_STAT_MODE
			
					#ifdef _NO_LINK_INPUT_STAT_MODE
			
						// Pas de stats avec les assemblees liees par des projections excitatrices aux inputs
						//#define _NO_EXCIT_LINK_INPUT_STAT_MODE
					#else
						// Stats sur les assemblees liees aux inputs.
						// Si non d�ini, les assemblees liees aux inputs sont ajout�s aux stats globales
						//#define _LINK_INPUT_STAT_MODE
			
						#ifdef _LINK_INPUT_STAT_MODE
			
							// Suivi des liens excitateurs en entr� seulement. Les liens inhibiteurs se sont pas pris en compte
							//#define _EXCIT_LINK_INPUT_STAT_MODE
			
							#ifndef _EXCIT_LINK_INPUT_STAT_MODE
			
			
								// Suivi des liens inhibiteurs en entr� seulement. Les liens excitateurs se sont pas pris en compte
								//#define _INHIB_LINK_INPUT_STAT_MODE
							#endif
			
						#endif
					#endif
			
					// Pas de stats avec les assemblees auto-connectees
					//#define _NO_SELF_EXCIT_STAT_MODE
			
				#else
			
					// Suivi de toutes les assembl�s
					#define _ALL_ASSEMBLY_STAT_MODE
			
					#ifndef _ALL_ASSEMBLY_STAT_MODE
			
						// Ne suit qu'une seule assembl�
						/* Attention, a remettre en place pour les splikes... */
						#define _SINGLE_ASSEMBLY_STAT_MODE
			
						#ifdef _SINGLE_ASSEMBLY_STAT_MODE
			
							// Index de l'assembl� suivie
							#define SINGLE_ASSEMBLY_INDEX 4
							//#define SINGLE_ASSEMBLY_INDEX 30
						#endif
					#endif
					
					// On suit les activit� au niveau post synaptiques
					// Si non d�ini, LFPPotential (potentiel de membrane)
					// et ThresholdLFPPotential (diff�ence potentiel de membrane au seuil)
					//#define _PSP_LFP_STAT_MODE
			
				#endif
			
				// Param�res des diagrammes temps-fr�uence
			
				// Si d�ini, applique un filtre passe-bas au diagramme de high temps-frequence
				#define _LOW_PASS_STAT_MODE
			
				// Nombre de bins de fr�uence pour le high time-frequency
				#define NB_HIGH_FREQUENCY_BINS 20
				//#define NB_HIGH_FREQUENCY_BINS 10
			
				// Plage de frequences couverte par un bin pour le high time-frequency
				//#define HIGH_FREQUENCY_BIN_LENGTH 10
				//#define HIGH_FREQUENCY_BIN_LENGTH 5
				#define HIGH_FREQUENCY_BIN_LENGTH 5
			
				// Nombre de bins de 5Hz pour le temps-frequence
				#define NB_FREQUENCY_BINS 20
				//#define NB_FREQUENCY_BINS 50
				//#define NB_FREQUENCY_BINS 25
				//#define NB_FREQUENCY_BINS 100
				//#define NB_FREQUENCY_BINS 200
			
			
			#endif
					
			// Pas de temps pour une seconde (serait mieux dans DefineEDNetwork, mais n'est utilis�que dans NeuronStater pour le moment)
			#define ONE_SECOND 1000
			
			// Stockage des spikes du r�eau (NeuronStater)
			#define _SPIKE_TRACE_MODE
			
			#ifdef _SPIKE_TRACE_MODE
			
				// Nom du fichier de stockage des ��ements PSPs
				#define SPIKE_FILENAME "Spike_Trace"
			#endif

		#endif

	#endif

	// Suivi des stats sur les projections
	// A modifier pour clusters dynamiques
	#ifdef _TOPOLOGY_PROJECTION_MODE

		// Suivi des stats au niveau des propriétés "graph"
		#define _NETWORK_STAT_MODE
		
	#endif

	#ifdef _NETWORK_STAT_MODE
		
		// Recherche des clusters
		#define _CLUSTER_STAT_MODE

		#ifdef _CLUSTER_STAT_MODE

			// Sauvegarde des projections (a finir...)
			#define _SAVE_ORDERED_PROJECTIONS_MODE
			
			#ifndef _SAVE_ORDERED_PROJECTIONS_MODE
			
				// Charge des projections (a finir...)
				#define _LOAD_ORDERED_PROJECTIONS_MODE
			#endif
			
			// Les clusters sont li�
			// et ne represente que des composantes fortement connexes (LinkedCluster)
			// Sinon, clusters non dirig�
			#define _LINKED_CLUSTER_STAT_MODE

			#ifdef _LINKED_CLUSTER_STAT_MODE

				// Application des chemins au niveau des clusters
				#define _CLUSTER_CENTRALITY_STAT_MODE
			#endif

			// Stats sur les clusters obtenus pour le r�eau complet
			#define _NETWORK_CLUSTER_STAT_MODE

			#ifdef _NETWORK_CLUSTER_STAT_MODE

				// Garde la configuration des clusters ayant la plus forte modularite
				#define _OPTIMAL_CLUSTERS_STAT_MODE
				
				#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
				
					// Trace dans une matrice les clusters optimaux
					#define _MATRIX_CLUSTERS_STAT_MODE
				#endif
				
			#endif

			//#define _3D_ONGOING_STAT_MODE
			
			#ifdef _3D_ONGOING_STAT_MODE
				// Les probas ongoing sont cumulaees
				//#define _ONGOING_CUMUL_STAT_MODE
			#endif
				
			// Liens entre inputs/outputs et clusters
			#define _INPUT_OUTPUT_CLUSTER_STAT_MODE
				
		#else			
			// Sauve la matrice de connectivite
			#define _TOPOLOGY_STAT_MODE
			
			#ifdef _TOPOLOGY_STAT_MODE
				// Suivi des projections inhib et excit (attention,0 peut etre inhib+excit)
				// Sinon, compte seulement les projections quelles que soit leur nature
				//#define _INHIB_EXCIT_TOPOLOGY_STAT_MODE
			#endif
			
			// Affiche les noeud qui sont directement li�s aux inputs
			#define _LINK_TO_INPUT_STAT_MODE
			
			#ifdef _LINK_TO_INPUT_STAT_MODE
			
				#define _EXCIT_LINK_TO_INPUT_STAT_MODE
			#endif
			
			// Affiche les noeud qui sont directement li�s aux outputs
			#define _LINK_TO_OUTPUT_STAT_MODE
			
			#ifdef _LINK_TO_OUTPUT_STAT_MODE
			
				#define _EXCIT_LINK_TO_OUTPUT_STAT_MODE
			#endif
			
		#endif
				
		// Calcul de centralit�des noeuds du r�eau
		#define _CENTRALITY_STAT_MODE

		#ifdef _CENTRALITY_STAT_MODE

			//Calcul de centralit�des liens du r�eau
			#define _EDGE_BETWEENNESS_STAT_MODE

			#ifdef _EDGE_BETWEENNESS_STAT_MODE

				#ifdef _CLUSTER_STAT_MODE
					// Suppression des liens dans l'ordre de edge-betweenness decroissante pour la construction de clusters
					// Methode de Girvan et Newman, PNAS, 2002
					#define _GN_CLUSTER_STAT_MODE
				#endif
			#endif

			#ifdef _CLUSTER_STAT_MODE
				#ifndef _GN_CLUSTER_STAT_MODE

					// Methode de Fortunato,Physical Rewiew E, 2004
					// Si non d�ini, random clusters
					#define _EFFICIENCY_CLUSTER_STAT_MODE
				#endif
			#endif
		#endif
		
		// Suivi des parametres longueur de chemin minimale et coefficient de clusterisation
		#define _SMALL_WORLD_STAT_MODE

		// Suivi des param�res de boucles
		#define _LOOP_STAT_MODE

		// Suivi des motifs
		#define _MOTIF_STAT_MODE

		#ifdef _MOTIF_STAT_MODE

			// Chaque motif (avec plus de 2 liens) est compte plus d'une fois
			// Si non d�ini, chaque n'est compte qu'une fois (sauf le motif 7, 3 fois)
			#define _REDONDANT_MOTIF_STAT_MODE

			#ifdef _CLUSTER_STAT_MODE

				// Suivi des motifs internes
				#define _INTERNAL_MOTIF_STAT_MODE
			#endif
		#endif

		// Suivi des chemins entre les inputs et les outputs
		#define _INPUT_OUTPUT_LENGTH_STAT_MODE
		
		// Repartition des assembl�s en fonction du degre in/out
		#define _DEGREE_STAT_MODE

		// Recherche composante fortement connexe
		#define _GSCC_STAT_MODE

		#ifdef _GSCC_STAT_MODE
			#ifndef _CLUSTER_STAT_MODE
				#define _INPUT_OUTPUT_GSCC_STAT_MODE
			#endif
		#endif
		
		// Stat des projections
		#ifndef _CLUSTER_STAT_MODE
			#define _PROJECTION_STAT_MODE
		#endif
		
		// Suivi des ditributions exponentielles
		//#define _XLOG_STAT_MODE
		//#define _YLOG_STAT_MODE

		// Suivi des distributions en loi de puissance
		//#define _LOG_LOG_STAT_MODE

		#if (!(defined(_TEST_BEST_POPULATION_MODE) || defined(_TEST_RANDOM_POPULATION_MODE)))
			// Diagramme en 3D
			#define _3D_STAT_MODE
		#endif

		// Proba cumul� pour les LogDistribution
		//#define _CUMUL_PROBA_STAT_MODE
		
		#ifndef _CUMUL_PROBA_STAT_MODE
		
			// Proba pour les LogDistribution
			// Si non d�inie, accumulation simple
			//#define _PROBA_STAT_MODE
			
		#endif
		
	#endif
	
	#if (!(defined (_SINGLE_INDIVIDUAL_MODE)))
	
		// Graph avec ecart-type
		#define _ERROR_BARS_STAT_MODE
		
		// Trace des valeurs sans accumulation
		#define _ANOVA_STAT_MODE
		
	#endif
#endif

#endif


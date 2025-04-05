// DefineGA.h

#ifndef _DEFINE_GA_H
#define _DEFINE_GA_H

#include "Define.h"
#include "DefineZoo.h"
#include "DefineEDNetwork.h"

	/* Mode de fonctionnement de l'algorithme g��ique */

	// Affichage �ran

// Affichage max: �n'utiliser qu'en cas de bug extreme (si execution sans aucun affichage)
//#define _GA_TEST

	// Encodage

// Codage par projections
#define _PROJECTION_ENCODING_MODE

#ifdef _PROJECTION_ENCODING_MODE

	// Codage par projections localis�s
	//#define _LOCAL_PROJECTION_ENCODING_MODE

	#ifndef _LOCAL_PROJECTION_ENCODING_MODE

		// Codage par projections distribu�s
		#define _DISTRIBUTED_PROJECTION_ENCODING_MODE

		#ifdef _DISTRIBUTED_PROJECTION_ENCODING_MODE

			// Nombre d'assembl�s pouvant etre pris comme preAssembly
			#define NB_PRE_ASSEMBLIES (NB_ASSEMBLIES+NB_INPUT_ASSEMBLIES)

			// Taux de projection maximum encode
			#define MAX_PROJECTION_CODE 1
			//#define MAX_PROJECTION_CODE 16
			//#define MAX_PROJECTION_CODE 8
			//#define MAX_PROJECTION_CODE 4
			//#define MAX_PROJECTION_CODE 2

			// Nombre d'assembl�s pouvant etre pris comme postAssembly
			#define NB_POST_ASSEMBLIES (NB_ASSEMBLIES+NB_OUTPUT_ASSEMBLIES)
		#endif
	#endif
	
	// Les projections peuvent etre nulles (code 2)
	// Non d�ini pour l'instant dans le cas _SELF_INHIBITION_MODE 
	//#define _VOID_PROJECTION_ENCODING_MODE

	// Construction des assembl�s de neurones de mani�e incr�entale
	// Non d�ini dans le cas _TOPOLOGY_PROJECTION_MODE
	//#define _INCREMENTAL_TOPOLOGY_MODE
	
	#ifdef _INCREMENTAL_TOPOLOGY_MODE
	
		//#define NB_PROJECTIONS_EACH_ASSEMBLY 5
		//#define NB_PROJECTIONS_EACH_ASSEMBLY 4
		#define NB_PROJECTIONS_EACH_ASSEMBLY 3
		//#define NB_PROJECTIONS_EACH_ASSEMBLY 2
		//#define NB_PROJECTIONS_EACH_ASSEMBLY 1
	#endif
#endif

// Nombre de genes de chaque chromosome
/*
#ifndef _PROJECTION_ENCODING_MODE
	#define NB_GENES_EACH_CHROMOSOME 24
#endif
*/
#ifdef _PROJECTION_ENCODING_MODE

	// Nombre de projections par chromosomes
	#ifdef _LARGE_DISTRIBUTED_NETWORK_MODE
		#ifdef _SELF_INHIBITION_MODE
			#define NB_PROJECTIONS_EACH_CHROMOSOME (2*(NB_POST_ASSEMBLIES))
		#else
			#ifdef _INCREMENTAL_TOPOLOGY_MODE
				#define NB_PROJECTIONS_EACH_CHROMOSOME (NB_PROJECTIONS_EACH_ASSEMBLY*NB_ASSEMBLIES)
			#else
				
				#ifdef _OLD_CONFIG_MODE
					// Special older graphs
					#define NB_PROJECTIONS_EACH_CHROMOSOME 1440
				#else
					//#define NB_PROJECTIONS_EACH_CHROMOSOME (NB_PRE_ASSEMBLIES+NB_POST_ASSEMBLIES)
					//#define NB_PROJECTIONS_EACH_CHROMOSOME (2*(NB_PRE_ASSEMBLIES+NB_POST_ASSEMBLIES))
					//#define NB_PROJECTIONS_EACH_CHROMOSOME (3*(NB_PRE_ASSEMBLIES+NB_POST_ASSEMBLIES))
					#define NB_PROJECTIONS_EACH_CHROMOSOME (4*(NB_PRE_ASSEMBLIES+NB_POST_ASSEMBLIES))
					//#define NB_PROJECTIONS_EACH_CHROMOSOME (5*(NB_PRE_ASSEMBLIES+NB_POST_ASSEMBLIES))
				
				#endif
			#endif
		#endif
	#else
		#define NB_PROJECTIONS_EACH_CHROMOSOME ((NB_PRE_ASSEMBLIES+NB_POST_ASSEMBLIES)*3)
		//#define NB_PROJECTIONS_EACH_CHROMOSOME (90*2)
	#endif

	// Nombre de genes par projection
	#define NB_GENES_EACH_PROJECTION 3

	// Nombre de genes par chromosome (taille du chromosome)
	#define NB_GENES_EACH_CHROMOSOME (NB_PROJECTIONS_EACH_CHROMOSOME*NB_GENES_EACH_PROJECTION)

#endif

	// S�ection

// Mode de selection par tournoi
#define _TOURNAMENT_SELECTION_MODE

#ifdef _TOURNAMENT_SELECTION_MODE

	// Selection par environnement isol�(niche)
	//#define _ISOLATED_SELECTION_MODE

	#ifdef _ISOLATED_SELECTION_MODE

		// Nombre d'individus dans chaque niche
		#define NB_INDIVIDUS_EACH_ISOLATED_ENVT 5

		// Nombre de niches
		#define NB_ISOLATED_ENVT 3

		// Nombre d'individus de la population
		#define NB_INDIVIDUS (NB_INDIVIDUS_EACH_ISOLATED_ENVT*NB_ISOLATED_ENVT)


		// Nombre d'individus impliqu�dans un tournoi
		#define NB_TOURNAMENT_OPPONENTS (NB_INDIVIDUS_EACH_ISOLATED_ENVT/2)
	#else

		// Nombre d'individus de la population
		#ifdef _TEST_CONFIG_MODE
			#define NB_INDIVIDUS 4
		#else
			#define NB_INDIVIDUS 100
		#endif
		
		// Nombre d'individus impliqu� dans un tournoi
		
		#ifdef _TEST_CONFIG_MODE
			#define NB_TOURNAMENT_OPPONENTS (NB_INDIVIDUS/2)
		#else
			#define NB_TOURNAMENT_OPPONENTS (NB_INDIVIDUS/10)
		#endif

	#endif

	#define _ELITIST_SELECTION_MODE

	#ifdef _ELITIST_SELECTION_MODE
		// Nombre des meilleurs chromosomes conserv� intacts d'une g��ation sur l'autre
		// Attention, doit etre largement inf�ieur �NB_INDIVIDUS
		#ifdef _TEST_CONFIG_MODE
			#define NB_ELITIST_INDIVIDUS (NB_INDIVIDUS/4)
		#else
			#define NB_ELITIST_INDIVIDUS (NB_INDIVIDUS/10)
		#endif
		
	#endif

#endif
#ifndef _TOURNAMENT_SELECTION_MODE

	// Mode de selection par roue de la fortune (fitness-dependant)
	/* Pas remis en place */
	//#define _ROULETTE_WHEEL_SELECTION_MODE
#endif

#define _CLUSTER_EVO_MODE

	/* Param�res li� �l'algorithme g��ique */

// Critere d'arret sur le fitness du dernier meilleur ��ent
#define FITNESS_MIN 0.00001

// Nombre de g��ations d'�olution
#ifdef _TEST_CONFIG_MODE
	#define NB_GENERATIONS 3
#else
	#ifdef _OLD_CONFIG_MODE
		
		// Special anciennes simulation
		#define NB_GENERATIONS 15
	#else
	
		#define NB_GENERATIONS 30
	#endif
	
#endif

// Probabilit�de mutation
#ifdef _TEST_CONFIG_MODE
	#define PROB_MUTATION (0.0)
#else
	#define PROB_MUTATION (1.0/NB_GENES_EACH_CHROMOSOME)
#endif
//#define PROB_MUTATION (2.0/NB_GENES_EACH_CHROMOSOME)
//#define PROB_MUTATION (0.5)

// Probabilit�de crossing-over
#ifdef _TEST_CONFIG_MODE
	#define PROB_CROSSOVER (0.0)
#else
	#define PROB_CROSSOVER (0.5/NB_GENES_EACH_CHROMOSOME)
#endif
//#define PROB_CROSSOVER (2.0/NB_GENES_EACH_CHROMOSOME)
//#define PROB_CROSSOVER (2.0/NB_GENES_EACH_CHROMOSOME)
//#define PROB_CROSSOVER (0.5)
//#define PROB_CROSSOVER (0.6)
//#define PROB_CROSSOVER (1.0)

#endif


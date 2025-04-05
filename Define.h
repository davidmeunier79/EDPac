// Define.h

#ifndef _DEFINE_H
#define _DEFINE_H

/****************************************************************************************************************************************/
/**************************************************** Parametres generaux ***************************************************************/
/****************************************************************************************************************************************/

// Mode evolutionniste
#define _EVO_PACMAN_MODE

#ifdef _EVO_PACMAN_MODE

	// Les inputs reward/punish sont accessibles
	#define _CONDITIONNING_MODE

	#ifdef _CONDITIONNING_MODE

		// Definit le contact avec une proie comme une recompense
		#define _PREY_CONTACT_REWARDS_PACMAN_MODE

		// Definit le contact (proximite avec un predateur comme envoyant un signal de punition pour le pacman)
		#define _PREDATOR_CONTACT_PUNISHES_PACMAN_MODE

	#endif

		// Independant des deux suivants, impliquant la lecture de la derniere populationt, et des graphs

	// Ne charge que la derniere population, et effectue des graphs
	// Si non defini, pas de graphs du reseau
	#define _TEST_BEST_POPULATION_MODE

	//#ifndef _TEST_BEST_POPULATION_MODE
		// Ne charge que la premiere population
		//(initialise aleatoirement si pas de chromosomes0.txt), et effectue des graphs
		#define _TEST_RANDOM_POPULATION_MODE
	//#endif

	// Suivi d'un individu de chaque population seulement
	//#define _SINGLE_INDIVIDUAL_MODE

	#ifdef _SINGLE_INDIVIDUAL_MODE

		// Suivi du meilleur individu de chaque population seulement
		#define _BEST_INDIVIDUAL_MODE

		#ifndef _BEST_INDIVIDUAL_MODE

			#define SINGLE_INDIVIDUAL_INDEX 6

		#endif
	#endif

	#ifndef _SINGLE_INDIVIDUAL_MODE

		// Mode intermediaire, suivi des premiers individus de chaque population
		// Si non defini, suivi de tous les individus de chaque population
		#define _FIRST_BEST_INDIVIDUALS_MODE

		#ifdef _FIRST_BEST_INDIVIDUALS_MODE

			// Nombre de premiers individus suivis
			#define NB_FIRST_BEST_INDIVIDUALS 10
			//#define NB_FIRST_BEST_INDIVIDUALS 2
		#endif
	#endif

	// La combinaison des deux marqueurs suivant permet de lancer un test, un run, puis un test post-run
	// Si aucun n'est defini, tourne a vide. Attention, temps dans  Pacman::waitSynchro()

	// Au debut et a la fin de chaque evaluation, le reseau est teste si RUN_MODE sans_TEST_BEST_POPULATION_MODE
	// Sinon, envoie des inputs correspondant aux animaux du zoo
	//#define _TEST_MODE

	// Le pacman est place dans le zoo, et est evalue	
	//#define _RUN_MODE

	#if (defined(_TEST_BEST_POPULATION_MODE) || defined(_TEST_RANDOM_POPULATION_MODE))

		#ifndef _RUN_MODE

			//#ifdef _TEST_MODE

				// Les patterns moteurs n'entrainent pas de mouvement du pacman
				#define _NO_MOVE_TEST_MODE

				#ifdef _NO_MOVE_TEST_MODE

					// Suivi de chacun des tests sur des graphs independants
					// Si non defini, l'individu est graphe d'un seul bloc
					//#define _PHASE_TEST_MODE

				#endif

				//Plusieurs animaux sont envoyes a la suite au cours d'un meme test
				#define _REPETITIVE_TEST_MODE

			//#endif

			// Definition de la repetition de chaque test
			//#define _MULTI_TEST_MODE

			#ifdef _MULTI_TEST_MODE

				// Nombre de fois ou le test est repete
				//#define NB_MULTI_TESTS 10
				//#define NB_MULTI_TESTS 3
				#define NB_MULTI_TESTS 2
				//#define NB_MULTI_TESTS 1

				// Test paramtrique sur une valeur
				//#define _PARAMETRIC_TEST_MODE

				#ifdef _PARAMETRIC_TEST_MODE

					#define _CONDITIONAL_TEST_MODE

					#ifdef _CONDITIONAL_TEST_MODE

						#define NB_PARAMETRIC_TESTS 2

						// Inhibition vs pas d'inhibition
						//#define _INHIBITION_TEST_MODE

						// inhib STDP vs pas de inhib STDP
						#define _INHIB_STDP_TEST_MODE

						// excit STDP vs pas de excit STDP
						#define _EXCIT_STDP_TEST_MODE

					#else
						//#define NB_PARAMETRIC_TESTS 30
						//#define NB_PARAMETRIC_TESTS 20
						//#define NB_PARAMETRIC_TESTS 11
						#define NB_PARAMETRIC_TESTS 10
						//#define NB_PARAMETRIC_TESTS 9
						//#define NB_PARAMETRIC_TESTS 7
						//#define NB_PARAMETRIC_TESTS 5
						//#define NB_PARAMETRIC_TESTS 3
						//#define NB_PARAMETRIC_TESTS 2

						// Test alpha synapses excitatrices
						//#define _EXCIT_ALPHA_TEST_MODE

						// Test alpha synapses inhibitrices
						//#define _INHIB_ALPHA_TEST_MODE

						// Test de la depression de la fenetre de STDP excit
						//#define _EXCIT_DEPRESSION_TEST_MODE

						// Test de la depression de la fenetre de STDP inhib
						//#define _INHIB_DEPRESSION_TEST_MODE

						// Test de la longuenr de la fenetre de potentiation
						//#define _INHIB_STDP_TIME_TEST_MODE

						// Test de la longueur des transitions
						//#define _TRANSITION_TEST_MODE

						// Test periode refractaire absolue
						//#define _ABS_REF_TEST_MODE

						// Test periode refractaire relative
						//#define _REL_REF_TEST_MODE

						// Test de la constante de fuite du potentiel de membrane
						//#define _PTI_TEST_MODE

						// Test de la valeur du seuil maximal
						//#define _THRESHOLD_MAX_TEST_MODE

						// Influence du potentiel max d'impact des PSPs sur le neurone
						#define _MAX_PSP_POTENTIAL_TEST_MODE

						// Test de l'influence des inputs sur le calcul
						//#define _INPUT_RATIO_TEST_MODE

						// Test de l'influence de la connectivite des excitations sur la calcul
						//#define _EXCIT_RATIO_TEST_MODE

						// Test de l'influence de la connectivite des inhibitions sur la calcul
						//#define _INHIB_RATIO_TEST_MODE

					#endif
				#endif
			#endif

		#else
			#ifdef _TEST_MODE
			
				// Period d'attente entre chaque test
				#define _WAITING_PERIOD_TEST_MODE
				
				// Pas de STDP pendant les tests (seulement pendant le run)
				// Special testEvo
				//#define _NO_STDP_TEST_MODE
				
			#endif
		#endif
	#else
		#ifdef _RUN_MODE
		
			// Reprise de l'evolution si probleme
			//#define _CONTINUE_EVOLUTION_MODE

			#ifdef _CONTINUE_EVOLUTION_MODE

				// Indice de la derniere population
				#define LAST_POPULATION_INDEX 14
			#endif
		#endif
	#endif

	#ifndef _RUN_MODE
		#ifndef _TEST_MODE

			// Ne construit que les assemblees et les projections (ni neurones ni synapses)
			// Attention, probleme avoid VOID testBest
			#define _TOPOLOGY_PROJECTION_MODE
		#endif
	#endif

	// Mode de simulation reduite (4 individus, 3 gen, pas d'operateurs genetiques pour RUN_MODE)
	// Si non defini, grosse simulation et pas d'affichage graphique
	// N'impacte que DefineGA.h
	//#define _TEST_CONFIG_MODE

	#ifdef _RUN_MODE

		// Prise en compte du faible run comme fitness
		//#define _LOWEST_FITNESS_MODE

		#ifndef _LOWEST_FITNESS_MODE

			// Fitness = moyenne des runs
			#define _MEAN_FITNESS_MODE

		#endif
	#endif
	
	// Special Biocyb
	//#define _OLD_CONFIG_MODE
	
	
#endif

// 100 assemblees, 25 neurones
// Si non defini, 25 assemblees, 100 neurones
#define _LARGE_DISTRIBUTED_NETWORK_MODE

// Assemblees auto-connectees en inhibition
// Si non defini, l'inhibition est codee dans le genome
// Non defini pour _TOPOLOGY_PROJECTION_MODE
//#define _SELF_INHIBITION_MODE

// Definit l'affichage graphique
#if (defined(_TEST_CONFIG_MODE) || defined(_BEST_INDIVIDUAL_MODE))
	#define _GRAPHICAL_DISPLAY_MODE
#endif

// Apprentissage en continu
#define _ONLINE_LEARNING_MODE

#ifdef _ONLINE_LEARNING_MODE

	// pas de inhib STDP
	//#define _NO_INHIB_STDP_MODE

	// pas de excit STDP
	//#define _NO_EXCIT_STDP_MODE
#endif

// Mode sans influence de l'inhibition
//#define _NO_INHIBITION_MODE
			
// Nettoie le repertoire data au debut du run
#define _CLEAR_DATA_DIRECTORY_MODE

// Indique que les inputs sont integrés a un rythme different des envois de messages
#define _BLOCKING_MODE

// Statistiques sur les parametres du reseau
#define _STAT_MODE

// Trace les parametres du reseau
#define _TRACE_MODE

#ifdef _TRACE_MODE
	// Graph les parametres du reseau (si trace)
	#define _GRAPH_MODE
#endif

// Mode de debug complet
//#define _DEBUG_TEST

#ifdef _DEBUG_TEST
	// Teste du protocole MPI (echange de message entre les processus)
	#define _MPI_TEST

	// Teste le fonctionnement du zoo
	#define _ZOO_TEST

	// Teste le fonctionnement du reseau
	#define _TEST

	// Teste le fonctionnement de l'algorithme genetique
	#define _GA_TEST

	// Teste le fonctionnement des traces
	#define _TRACE_TEST
	
	// Teste le fonctionnement des stats
	#define _TEST_STAT

#endif

#endif




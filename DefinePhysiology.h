// DefinePhysiology.h

#ifndef _DEFINE_PHYSIOLOGY
#define _DEFINE_PHYSIOLOGY

#include "Define.h"
//#include "DefineEDNetwork.h"

/******************************************************************************************************************************************/
/******************************************************* Modes des objets synapses et neurones ********************************************/
/******************************************************************************************************************************************/

	// Modes de la synapse

// Marqueurs de connexions (pas de connexion d'un neurone sur lui-m�e)
#define _NO_AUTO_CONNEXIONS_MODE

// Plusieurs synapses entre 2 neurones
//#define _MULTISYNAPSES_MODE

/******************************************************************************************************************************************/
/******************************************************************************************************************************************/
/*********************************************************** Constantes globales **********************************************************/
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/

// Tous les temps sont en secondes
// Tous les potentiels sont en millivolts

/******************************************************************************************************************************************/
/*********************************************************** Param�res des synapses ******************************************************/
/******************************************************************************************************************************************/

// Pour l'apprentissage online
#ifdef _ONLINE_LEARNING_MODE

	// Prise en compte du delai de transmission dans la fenetre
	#define _DELAYED_STDP_MODE

	// Fenetre continue (voir "Enhancement of synchrony via STDP synapses", Nowotny, 2003)
	#define _CONTINUOUS_HEBBIAN_WINDOW_MODE

	#ifndef _CONTINUOUS_HEBBIAN_WINDOW_MODE

		// Fenetre discontinue (selection des d�ais, Gerstner, 1996)
		#define _SHARP_HEBBIAN_WINDOW_MODE
	#endif

	// Regle multiplicative pour le non-depassement des bornes par le poids excit
	// Si non d�ini, regle additive (depassement tranch�)
	// Seul le mode _ALPHA_UPDATE_MODE est activ�dans ce cas (prise en compte d'une valeur alpha ou non)
	#define _EXCIT_MULTIPLICATIVE_STDP_MODE
	
	#ifdef _EXCIT_MULTIPLICATIVE_STDP_MODE
	
		// Correspond �un apprentissage type backProp, coef d'apprentissage
		#define _EXCIT_ALPHA_UPDATE_MODE
	
		#ifdef _EXCIT_ALPHA_UPDATE_MODE
	
			#ifdef _EXCIT_ALPHA_TEST_MODE
				#define EXCIT_ALPHA_STEP 0.1
			#endif
			
		#else	
			// Le poids ne peut de lui-meme depasser 0 ou 1
			// Si ni _EXCIT_AUTO_SCALING_WEIGHT_MODE, ni _EXCIT_ALPHA_UPDATE_MODE ne sont d�ini, mise �jour sans EXCIT_ALPHA
			//#define _EXCIT_AUTO_SCALING_WEIGHT_MODE
		#endif
	#else
		// Prise en compte d'un ALPHA dans la regle de modification
		// Sinon d�ini, equivalent �ALPHA vaut 1
		#define _EXCIT_ALPHA_UPDATE_MODE
	#endif

	// Regle multiplicative pour le non-depassement des bornes par le poids inhib
	// Si non d�ini, regle additive (depassement tranch�)
	// Seul le mode _ALPHA_UPDATE_MODE est activ�dans ce cas (prise en compte d'une valeur alpha ou non)
	#define _INHIB_MULTIPLICATIVE_STDP_MODE
	
	#ifdef _INHIB_MULTIPLICATIVE_STDP_MODE
	
		// Correspond �un apprentissage type backProp, coef d'apprentissage
		#define _INHIB_ALPHA_UPDATE_MODE
	
		#ifdef _INHIB_ALPHA_UPDATE_MODE
	
			#ifdef _INHIB_ALPHA_TEST_MODE
				#define INHIB_ALPHA_STEP 0.1
			#endif
			
		#else	
			// Le poids ne peut de lui-meme depasser 0 ou 1
			// Si ni _INHIB_AUTO_SCALING_WEIGHT_MODE, ni _INHIB_ALPHA_UPDATE_MODE ne sont d�ini, mise �jour sans INHIB_ALPHA
			//#define _INHIB_AUTO_SCALING_WEIGHT_MODE
		#endif
	#else
		// Prise en compte d'un ALPHA dans la regle de modification
		// Sinon d�ini, equivalent �ALPHA vaut 1
		#define _INHIB_ALPHA_UPDATE_MODE
	#endif
#endif

// Poids initial fix�#define _INITIAL_FIXED_WEIGHT_MODE

#ifndef _INITIAL_FIXED_WEIGHT_MODE

	// Poids initial al�toire
	#define _INITIAL_RANDOM_WEIGHT_MODE
#endif

// Poids inhib initial fix�#define _INITIAL_FIXED_INHIB_WEIGHT_MODE

#ifndef _INITIAL_FIXED_INHIB_WEIGHT_MODE
	// Poids inhib initial al�toire
	#define _INITIAL_RANDOM_INHIB_WEIGHT_MODE
#endif

// D�ais al�toires
#define _RANDOM_DELAY_MODE

#ifndef _RANDOM_DELAY_MODE

	// D�ais fixes
	#define _FIXED_DELAY_MODE
#endif

// D�ais inhib al�toires
#define _RANDOM_INHIB_DELAY_MODE

#ifndef _RANDOM_INHIB_DELAY_MODE

	// D�ais inhib fixes
	#define _FIXED_INHIB_DELAY_MODE
#endif
/******************************************************************************************************************************************/

	// Param�res des synapses

// Delai max
//#define DELAY 20
#define DELAY 10
//#define DELAY 1

// Delai inhibiteur max
//#define INHIBITORY_DELAY 20
#define INHIBITORY_DELAY 10
//#define INHIBITORY_DELAY 1

// Poids moyen
#define WEIGHT 0.5

/******************************************************************************************************************************************/

	// Param�res des PSP

// Potential max du PSP
#ifdef _MAX_PSP_POTENTIAL_TEST_MODE
	//#define MAX_PSP_POTENTIAL_STEP 0.0001
	//#define MAX_PSP_POTENTIAL_STEP 0.0002
	#define MAX_PSP_POTENTIAL_STEP 0.0005
#endif
	
#ifdef _PTI_TEST_MODE
	#define PSP_TEMPORAL_IMPACT_STEP 5
#endif

/******************************************************************************************************************************************/
/******************************************************* Param�res des neurones **********************************************************/
/******************************************************************************************************************************************/

	// Param�res de la membrane

// Potentiel de membrane de repos
#define RESTING_POTENTIAL 0.0000

/******************************************************************************************************************************************/

	// Param�res du seuil

// Nombre de PSPs moyens pour avoir un spike
#define NB_MEAN_PSPS_TO_SPIKE 20

// Seuil de r��ence
#define THRESHOLD_REF (0.002*WEIGHT*NB_MEAN_PSPS_TO_SPIKE)

// La veleur max de seuil THRESHOLD_MAX est ajout� au seuil courant lors d'un spike. 
// Si non, THRESHOLD_MAX definit la valeur du seuil.
#define _ADDITIVE_THRESHOLD_MODE

// Les neurones peuvent pulser plusieurs fois entre 2 inhibitions
// Marqueur utilis�seulement ici et dans SpikingNeuron
#define _BURSTY_NEURON_MODE

#ifdef _BURSTY_NEURON_MODE
	#ifdef _REL_REF_TEST_MODE
		#define RELATIVE_REFRACTORY_STEP 5
	#endif

#endif

#ifdef _ABS_REF_TEST_MODE
	#define ABSOLUT_REFRACTORY_STEP 5
	//#define ABSOLUT_REFRACTORY_STEP 1
#endif
	
#ifdef _THRESHOLD_MAX_TEST_MODE
	#define THRESHOLD_MAX_STEP (THRESHOLD_REF)
#endif

	// Impact de l'ihnibition

// Chaque PSP inhibiteur remet le potential de membrane �HYPER_POLARISATION_POTENTIAL
// Si non, d�ini, les poids inhibiteurs impactent le neurone de la meme mani�e que les excitateurs (somme du poids n�atif)

#ifdef _SELF_INHIBITION_MODE
	#define _INHIBITION_RESET_COMPUTING_MODE
#endif

//#ifdef _INHIBITION_RESET_COMPUTING_MODE
	// Limite inf�ieure du potential de membrane
	#define HYPER_POLARISATION_POTENTIAL -0.020
//#endif

/******************************************************************************************************************************************/
#endif

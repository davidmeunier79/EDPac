// DefineMPI.h

#ifndef _DEFINE_MPI_H
#define _DEFINE_MPI_H

#include "Define.h"

#include "DefineEDNetwork.h"
#include "DefineGA.h"
#include "DefineZoo.h"

/****************************************************************************************************************************************/
/********************************************************* Parametres MPI ***************************************************************/
/****************************************************************************************************************************************/

// MPI_IDs des processus
enum MPI_ID
{
	// Environnement graphiques
	GRAPHICAL_ENVIRONNEMENT_MPI_ID=0,

	// Réseau evolutif
	EVO_NETWORK_MPI_ID,

	// Module moteur
	//MOTOR_MODULE_MPI_ID
};

enum MPI_Message
{
	DEFAULT = 0,
	VOID = -1,
	BREAK = -2,
	SKIP = -3
};


// Mode d'affichage console des échanges de messages réalisés
//#define _MPI_TEST

	// Canal de transmission globale de synchronisation

// Tag par défaut (n'est jamais utilisé...)
#define DEFAULT_TAG 1000

// Canal pour envoi des chromosomes et des messages break
#define SYNCHRO_CHANNEL_TAG 100

// Module synchronisateur (envoi les messages synchro et break aux autres modules
#define ROOT_MODULE_MPI_ID 0

	// Canaux de transmission modaux

	// Communication Pacman->EDNetwork

// Modalité visuelle

// Taille d'un buffer visuel
#define VISIO_BUFFER_SIZE (VISIO_GRAPHICAL_SIZE*VISIO_GRAPHICAL_SIZE)

// Intervalle d'etiquettes des buffers visuels
/* Attention, la derniere valeur n'est pas INCLUSE */
#define FIRST_VISIO_CHANNEL_ETIQUETTE 0
#define LAST_VISIO_CHANNEL_ETIQUETTE (FIRST_VISIO_CHANNEL_ETIQUETTE+NB_VISIO_INPUTS)

// Modalité auditive

// Taille d'un buffer auditif
#define AUDIO_BUFFER_SIZE (AUDIO_GRAPHICAL_SIZE*AUDIO_GRAPHICAL_SIZE)

// Etiquette de l'unique buffer auditif
#define LEFT_AUDIO_CHANNEL_ETIQUETTE 5
#define RIGHT_AUDIO_CHANNEL_ETIQUETTE 6

// Punition
#ifdef _CONDITIONNING_MODE

	// Nombre de neurones dans l'assemblée d'entrée de punition
	#define CONDITIONNING_BUFFER_SIZE (CONDITIONNING_GRAPHICAL_SIZE*CONDITIONNING_GRAPHICAL_SIZE)

	#ifdef _PREDATOR_CONTACT_PUNISHES_PACMAN_MODE

		// Canal de transmission de la punition
		#define PUNISH_CHANNEL_ETIQUETTE 7

	#endif

	// Recompense

	#ifdef _PREY_CONTACT_REWARDS_PACMAN_MODE

		// Canal de transmission de la récompense
		#define REWARD_CHANNEL_ETIQUETTE 8

	#endif
#endif

#define CHROMO_BUFFER_SIZE (NB_PROJECTIONS_EACH_CHROMOSOME*NB_GENES_EACH_PROJECTION)

#define CHROMOSOME_CHANNEL_ETIQUETTE 9

	// Commnunication EDNetwork->Pacman

#define MOVE_BODY_ON_LEFT_CHANNEL_ETIQUETTE 0
#define MOVE_BODY_ON_RIGHT_CHANNEL_ETIQUETTE 1

#define MOVE_HEAD_ON_LEFT_CHANNEL_ETIQUETTE 2
#define MOVE_HEAD_ON_RIGHT_CHANNEL_ETIQUETTE 3

#define MOTOR_PATTERN_BUFFER_SIZE (MOTOR_GRAPHICAL_SIZE*MOTOR_GRAPHICAL_SIZE)

#endif


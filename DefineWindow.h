//DefineWindow.h

#ifndef _DEFINE_WINDOW_H
#define _DEFINE_WINDOW_H

#include "Define.h"
#include "DefineEDNetwork.h"

/****************************************************************************************************************************************/
/************************* Parametres des paramètres des representations graphiques *****************************************************/
/****************************************************************************************************************************************/

// Definit l'affichage graphique
#ifdef _GRAPHICAL_DISPLAY_MODE

	// Définit l'affichage console des paramètres du zoo
	//#define _ZOO_TEST
	
	// Marge d'affichage
	#define MARGIN 30

	// Spécial FenetreTopo, correspond à la taille de la réprésentation d'une assemblée graphique
	#define ASSEMBLY_GRAPHICAL_SIZE (SQRT_NB_NEURONS)

	#if (defined (_RUN_MODE) || defined(_TEST_MODE))
	
		// Sauve la zoo a chaque pas de temps
		//#define _SAVE_ZOO_DISPLAY_MODE
	#endif
	
	// Sauve le réseau affiché dans TopologyDisplayer a chaque pas de temps;
	//#define _SAVE_TOPOLOGY_DISPLAY_MODE
		
#endif

#endif

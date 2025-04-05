//DefineWindow.h

#ifndef _DEFINE_WINDOW_H
#define _DEFINE_WINDOW_H

#include "Define.h"
#include "DefineEDNetwork.h"

/****************************************************************************************************************************************/
/************************* Parametres des param�tres des representations graphiques *****************************************************/
/****************************************************************************************************************************************/

// Definit l'affichage graphique
#ifdef _GRAPHICAL_DISPLAY_MODE

	// D�finit l'affichage console des param�tres du zoo
	//#define _ZOO_TEST
	
	// Marge d'affichage
	#define MARGIN 30

	// Sp�cial FenetreTopo, correspond � la taille de la r�pr�sentation d'une assembl�e graphique
	#define ASSEMBLY_GRAPHICAL_SIZE (SQRT_NB_NEURONS)

	#if (defined (_RUN_MODE) || defined(_TEST_MODE))
	
		// Sauve la zoo a chaque pas de temps
		//#define _SAVE_ZOO_DISPLAY_MODE
	#endif
	
	// Sauve le r�seau affich� dans TopologyDisplayer a chaque pas de temps;
	//#define _SAVE_TOPOLOGY_DISPLAY_MODE
		
#endif

#endif

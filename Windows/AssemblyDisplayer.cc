// AssemblyDisplayer.cc

// Local Includes
#include "AssemblyDisplayer.h"

/****************************************************************************************************************************************/
/************************************************* Methodes de la classe AssemblyDisplayer **********************************************/
/****************************************************************************************************************************************/

AssemblyDisplayer::AssemblyDisplayer()
{
}

AssemblyDisplayer::~AssemblyDisplayer()
{
}

#ifdef _GRAPHICAL_DISPLAY_MODE
void AssemblyDisplayer::display(Assembly* a)
{
	//cout << "Initing assembly display" << a->getIndex() << endl;

	int posX;
	int posY;
	string couleur;

	// Assemblées inputs
	// visio
	if (NB_ASSEMBLIES <= a->getIndex() && a->getIndex() < NB_ASSEMBLIES+NB_VISIO_INPUTS)
	{
		posX=1+SQRT_NB_ASSEMBLIES;
		posY=a->getIndex()-NB_ASSEMBLIES;

		topoWindow->colorierZone(MARGIN-VISIO_GRAPHICAL_SIZE/2+posX*MARGIN,MARGIN-VISIO_GRAPHICAL_SIZE/2+posY*MARGIN,VISIO_GRAPHICAL_SIZE,VISIO_GRAPHICAL_SIZE,"noir");
	}
	// audio
	else if (NB_ASSEMBLIES+NB_VISIO_INPUTS <= a->getIndex() && a->getIndex() < NB_ASSEMBLIES+NB_VISIO_INPUTS+NB_AUDIO_INPUTS)
	{
		posX=1+SQRT_NB_ASSEMBLIES;
		posY=a->getIndex()-NB_ASSEMBLIES;

		topoWindow->colorierZone(MARGIN-AUDIO_GRAPHICAL_SIZE/2+posX*MARGIN,MARGIN-AUDIO_GRAPHICAL_SIZE/2+posY*MARGIN,AUDIO_GRAPHICAL_SIZE,AUDIO_GRAPHICAL_SIZE,"noir");
	}
	// punish/reward
	#ifdef _CONDITIONNING_MODE
	else if (NB_ASSEMBLIES+NB_VISIO_INPUTS+NB_AUDIO_INPUTS <= a->getIndex() && a->getIndex() < NB_ASSEMBLIES+NB_VISIO_INPUTS+NB_AUDIO_INPUTS+NB_CONDITIONNING_INPUTS)
	{
		posX=1+SQRT_NB_ASSEMBLIES;
		posY=a->getIndex()-NB_ASSEMBLIES;
topoWindow->colorierZone(MARGIN-CONDITIONNING_GRAPHICAL_SIZE/2+posX*MARGIN,MARGIN-CONDITIONNING_GRAPHICAL_SIZE/2+posY*MARGIN,CONDITIONNING_GRAPHICAL_SIZE,CONDITIONNING_GRAPHICAL_SIZE,"noir");
	}
	#endif

	// Assemblées cachées...
	#ifdef _SINGLE_ASSEMBLY_STAT_MODE
	else if (0 <= a->getIndex() && a->getIndex() < NB_ASSEMBLIES)
	{
		if (a->getIndex() == SINGLE_ASSEMBLY_INDEX)
		{
			posX=1+a->getIndex()%SQRT_NB_ASSEMBLIES;
			posY=a->getIndex()/SQRT_NB_ASSEMBLIES;

			topoWindow->colorierZone(MARGIN-ASSEMBLY_GRAPHICAL_SIZE/2+posX*MARGIN,MARGIN-ASSEMBLY_GRAPHICAL_SIZE/2+posY*MARGIN,ASSEMBLY_GRAPHICAL_SIZE,ASSEMBLY_GRAPHICAL_SIZE,"marron");
		}
		else if (0 <= a->getIndex() && a->getIndex() < NB_ASSEMBLIES)
		{
			posX=1+a->getIndex()%SQRT_NB_ASSEMBLIES;
			posY=a->getIndex()/SQRT_NB_ASSEMBLIES;

			topoWindow->colorierZone(MARGIN-ASSEMBLY_GRAPHICAL_SIZE/2+posX*MARGIN,MARGIN-ASSEMBLY_GRAPHICAL_SIZE/2+posY*MARGIN,ASSEMBLY_GRAPHICAL_SIZE,ASSEMBLY_GRAPHICAL_SIZE,"noir");
		}
	}
	#else
	else if (0 <= a->getIndex() && a->getIndex() < NB_ASSEMBLIES)
	{
		posX=1+a->getIndex()%SQRT_NB_ASSEMBLIES;
		posY=a->getIndex()/SQRT_NB_ASSEMBLIES;

		topoWindow->colorierZone(MARGIN-ASSEMBLY_GRAPHICAL_SIZE/2+posX*MARGIN,MARGIN-ASSEMBLY_GRAPHICAL_SIZE/2+posY*MARGIN,ASSEMBLY_GRAPHICAL_SIZE,ASSEMBLY_GRAPHICAL_SIZE,"noir");
	}
	#endif
	// Assemblées outputs
	else if (NB_ASSEMBLIES+NB_INPUT_ASSEMBLIES  <= a->getIndex() && a->getIndex() < NB_ASSEMBLIES+NB_INPUT_ASSEMBLIES+NB_OUTPUT_ASSEMBLIES)
	{
		posX=0;
		posY=a->getIndex()-NB_ASSEMBLIES-NB_INPUT_ASSEMBLIES;

		topoWindow->colorierZone(MARGIN-MOTOR_GRAPHICAL_SIZE/2+posX*MARGIN,MARGIN-MOTOR_GRAPHICAL_SIZE/2+posY*MARGIN,MOTOR_GRAPHICAL_SIZE,MOTOR_GRAPHICAL_SIZE,"noir");
	}
	else
	{
		cerr << "Warning, wrong assembly getIndex() " << a->getIndex() << endl;
		return;
	}
}
#endif





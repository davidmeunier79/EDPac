// TopologyDisplayer.cc

// Local Includes
#include "TopologyDisplayer.h"

/****************************************************************************************************************************************/
/************************************************* Methodes de la classe TopologyDisplayer **********************************************/
/****************************************************************************************************************************************/

TopologyDisplayer::TopologyDisplayer()
{
}

TopologyDisplayer::~TopologyDisplayer()
{
}

void TopologyDisplayer::flushDisplay()
{
	topoWindow->redessine();
}

void TopologyDisplayer::cleanDisplay()
{
	topoWindow->effacer();
}

#ifdef _GRAPHICAL_DISPLAY_MODE
void TopologyDisplayer::traceProjection(int preAssemblyIndex,int postAssemblyIndex, int projectionCode,const string& couleur)
{
		// Assemblée pre-synaptique

	int prePosX;
	int prePosY;

	// Assemblée inputs
	if (0<=preAssemblyIndex && preAssemblyIndex<NB_INPUT_ASSEMBLIES)
	{
		prePosX=1+SQRT_NB_ASSEMBLIES;
		prePosY=preAssemblyIndex;
	}
	// Assemblée cachées...
	else if (NB_INPUT_ASSEMBLIES<=preAssemblyIndex && preAssemblyIndex<NB_INPUT_ASSEMBLIES+NB_ASSEMBLIES)
	{
		prePosX=1+(preAssemblyIndex-NB_INPUT_ASSEMBLIES)%SQRT_NB_ASSEMBLIES;
		prePosY=(preAssemblyIndex-NB_INPUT_ASSEMBLIES)/SQRT_NB_ASSEMBLIES;
	}
	else
	{
		cerr << "Warning, wrong preAssemblyIndex: " << preAssemblyIndex << endl;
		return;
	}

		// Assemblée post-synaptique

	int postPosX;
	int postPosY;

	// Assemblée outputs
	if (0<=postAssemblyIndex && postAssemblyIndex<NB_OUTPUT_ASSEMBLIES)
	{
		postPosX=0;
		postPosY=postAssemblyIndex;
	}
	// Assemblée cachées...
	else if (NB_OUTPUT_ASSEMBLIES<=postAssemblyIndex && postAssemblyIndex<NB_OUTPUT_ASSEMBLIES+NB_ASSEMBLIES)
	{
		postPosX=1+(postAssemblyIndex-NB_OUTPUT_ASSEMBLIES)%SQRT_NB_ASSEMBLIES;
		postPosY=(postAssemblyIndex-NB_OUTPUT_ASSEMBLIES)/SQRT_NB_ASSEMBLIES;
	}
	else
	{
		cerr << "Warning, wrong postAssemblyIndex: " << postAssemblyIndex << endl;
		return;
	}

		// Couleur et épaisseur

	if (0<projectionCode && projectionCode<=2*MAX_PROJECTION_CODE)
	{
		/*
		for (int i=(int) -1*projectionCode*ASSEMBLY_GRAPHICAL_SIZE/(2*2*MAX_PROJECTION_CODE);i<=(int) projectionCode*ASSEMBLY_GRAPHICAL_SIZE/(2*2*MAX_PROJECTION_CODE);i++)
		{
			topoWindow->traceLigne(
			MARGIN+prePosX*MARGIN,
			MARGIN+prePosY*MARGIN,
			MARGIN+postPosX*MARGIN+i,
			MARGIN+postPosY*MARGIN,
			couleur);
		}
		*/
		topoWindow->traceLigne(MARGIN+prePosX*MARGIN,MARGIN+prePosY*MARGIN,MARGIN+postPosX*MARGIN,MARGIN+postPosY*MARGIN,couleur);
	}
	else
	{
		cerr << "Warning, wrong projectionCode: " << projectionCode << endl;
		return;
	}
}

void TopologyDisplayer::traceProjection(Projection* curProj)
{
	int preAssemblyIndex = -1;
	int postAssemblyIndex = -1;
	
	if (0 <= ((Assembly*) curProj->getPreNode())->getIndex() && ((Assembly*) curProj->getPreNode())->getIndex() < NB_ASSEMBLIES)
	{
		preAssemblyIndex = ((Assembly*) curProj->getPreNode())->getIndex()+NB_INPUT_ASSEMBLIES;
	}	
	else if (NB_ASSEMBLIES <= ((Assembly*) curProj->getPreNode())->getIndex() && ((Assembly*) curProj->getPreNode())->getIndex() < NB_ASSEMBLIES+NB_INPUT_ASSEMBLIES)
	{
		preAssemblyIndex = ((Assembly*) curProj->getPreNode())->getIndex()-NB_ASSEMBLIES;
	}
	else
	{
		cerr << "Warning, wrong preNodeIndex: " << ((Assembly*) curProj->getPreNode())->getIndex() << endl;
		return;
	}
	
	if (0 <= ((Assembly*) curProj->getPostNode())->getIndex() && ((Assembly*) curProj->getPostNode())->getIndex() < NB_ASSEMBLIES)
	{
		postAssemblyIndex = ((Assembly*) curProj->getPostNode())->getIndex()+NB_OUTPUT_ASSEMBLIES;
	}	
	else if ((NB_ASSEMBLIES+NB_INPUT_ASSEMBLIES) <= ((Assembly*) curProj->getPostNode())->getIndex() && ((Assembly*) curProj->getPostNode())->getIndex() < (NB_ASSEMBLIES+NB_INPUT_ASSEMBLIES+NB_OUTPUT_ASSEMBLIES))
	{
		postAssemblyIndex = ((Assembly*) curProj->getPostNode())->getIndex()-NB_ASSEMBLIES-NB_INPUT_ASSEMBLIES;
	}
	else
	{
		cerr << "Warning, wrong preNodeIndex: " << ((Assembly*) curProj->getPostNode())->getIndex() << endl;
		return;
	}
	
	if (curProj->getProjectionNature() == EXCIT)
	{
		traceProjection(preAssemblyIndex,postAssemblyIndex,1,"bleu");
	}
	else if (curProj->getProjectionNature() == INHIB)
	{
		traceProjection(preAssemblyIndex,postAssemblyIndex,1,"rouge");
	}
	else
	{
		cerr << "Warning, wrong ProjectionNature: " << curProj->getProjectionNature() << endl;
		return;
	}
	
}

void TopologyDisplayer::display(Topology* t)
{
	//cout << "Initing topology display" << endl;

	std::vector<Assembly*>::iterator it=t->assemblies.begin();
	std::vector<Assembly*>::iterator end=t->assemblies.end();

	while (it!=end)
	{
		((Assembly*) *it)->display();
		it++;
	}
}

void TopologyDisplayer::saveTopologyDisplayer(int time)
{
	ostringstream oss;
	oss << "Network" << getEvoIndex() << "_" << getTopoIndex() << "_" << time << ".xpm";

	((Fenetre*) topoWindow)->saveXpmImage(oss.str());
}
#endif






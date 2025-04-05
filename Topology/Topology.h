// Topology.h

#ifndef _TOPOLOGY_H
#define _TOPOLOGY_H

//#include <stdio.h>

// STL Includes
//#include <iostream>
//#include <fstream>
//#include <deque>
//#include <list>
#include <vector>
using namespace std;

// Local Includes
#include "../Define.h"

// special trace, évaluations multiples
#include "../DefineZoo.h"
#include "../DefineEDNetwork.h"

#include "../Objets/Object.h"

#include "../Interfaces/TopoIndexable.h"

// Pour affichage graphique de la topologie
#include "../Interfaces/Displayable.h"


#include "Assembly.h"

class Topology;
#include "../Windows/TopologyDisplayer.h"

/******************************************************************************************************************************************/
/********************************************************** Classe Topology ***************************************************************/
/******************************************************************************************************************************************/

class Topology : public Object, public Displayable, public TopoIndexable
{
protected:
	std::vector<Assembly*> assemblies;

public:

	// Construction du réseau
	Topology();

	// Destruction du réseau (fermeture des fichiers trace)
	~Topology();

	// Ajout d'une assemblée à la topologie
	void addAssembly(Assembly* _pNewAssembly);

	// methodes virtuelles, implémentées dans les sous-classes
	virtual void buildTopology();

#ifdef _GRAPHICAL_DISPLAY_MODE
	friend class TopologyDisplayer;

	void initTopologyDisplayer(TopologyDisplayer* td);
	void display();
	void freeTopologyDisplayer();
#endif	

	// Sauvegarde et affichage
	friend std::ostream& operator<<(std::ostream& f,Topology& n);
};

#endif

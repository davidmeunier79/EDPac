// Assembly.h

#ifndef _ASSEMBLY_H
#define _ASSEMBLY_H

//#include <stdio.h>

// STL Includes
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

// Local Includes
#include "../Define.h"
#include "../DefineEDNetwork.h"

#include "../Objets/IndexedObject.h"

#include "Neuron.h"

class Assembly;
#include "../Windows/AssemblyDisplayer.h"
#include "Projection.h"

/******************************************************************************************************************************************/
/*************************************************************** Classe Assembly **********************************************************/
/******************************************************************************************************************************************/

class Assembly : public Node, public Displayable
{
protected:

	// Indique si l'assemblée est d'entrée (0) ou de sortie (1)
	int assemblyNature;

	// Neurones appartenant à l'assemblée
	std::vector<Neuron*> neurons;

public:

	Assembly();	
	~Assembly();

	static int nbAssemblies;

	void addNeuron(Neuron* _pNewNeuron);

	std::vector<Neuron*>::iterator getBegin();
	std::vector<Neuron*>::iterator getEnd();

	int getNature();
	
	int getNbInternalInputLinks();
	int getNbInternalOutputLinks();
	
	Link* eraseInternalOutputLink(int linkIndex);
	void insertInternalOutputLink(Link* curLink, int linkIndex);
	
#ifdef _ALL_TO_ALL_PROJECTION_MODE
	virtual void buildTotalPostExcitProjection(Assembly* postAssembly);
	virtual void buildTotalPostInhibProjection(Assembly* postAssembly);
#endif
	
#ifdef _FIXED_RATIO_PROJECTION_MODE
	virtual void buildPostExcitProjection(Assembly* postAssembly);
	virtual void buildPostInhibProjection(Assembly* postAssembly);
#endif

#ifdef _GRAPHICAL_DISPLAY_MODE
	friend class AssemblyDisplayer;

	void initAssemblyDisplayer(AssemblyDisplayer* ad);
	void display();
	void freeAssemblyDisplayer();
#endif
	friend std::ostream& operator<<(std::ostream&, Assembly&);
};

#endif

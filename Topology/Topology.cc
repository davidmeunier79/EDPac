// Topology.cc

// Local Includes
#include "Topology.h"

/****************************************************************************************************************************************/
/****************************************************** Methodes de la classe Topology *************************************************/
/****************************************************************************************************************************************/

// Construction du réseau
Topology::Topology()
{
	initTopoIndex();
}

Topology::~Topology()
{
}

void Topology::buildTopology()
{
}

void Topology::addAssembly(Assembly* _pNewAssembly)
{
	assemblies.push_back(_pNewAssembly);
}

#ifdef _GRAPHICAL_DISPLAY_MODE
void Topology::initTopologyDisplayer(TopologyDisplayer* td)
{
	#ifdef _TEST
	cout << "Initing graphical display for Topology " << getTopoIndex() << endl;
	#endif

	std::vector<Assembly*>::iterator it=assemblies.begin();
	std::vector<Assembly*>::iterator end=assemblies.end();

	while (it!=end)
	{
	#ifdef _TEST
		cout << "Initing assembly displayer" << ((Assembly*) *it)->getIndex() << endl;
	#endif	
		((Assembly*) *it)->initAssemblyDisplayer((AssemblyDisplayer*) td);
		it++;
	}
}

void Topology::display()
{
	std::vector<Assembly*>::iterator it=assemblies.begin();
	std::vector<Assembly*>::iterator end=assemblies.end();

	while (it!=end)
	{
		((Assembly*) *it)->display();
		it++;
	}
}

void Topology::freeTopologyDisplayer()
{
	delete ((TopologyDisplayer*) displayer);

	std::vector<Assembly*>::iterator it=assemblies.begin();
	std::vector<Assembly*>::iterator end=assemblies.end();

	while (it!=end)
	{
		((Assembly*) *it)->freeAssemblyDisplayer();
		it++;
	}
}
#endif

/****************************************************************************************************************************************/
/********************************************************** Méthodes d'affichage console ************************************************/
/****************************************************************************************************************************************/

std::ostream& operator<<(std::ostream& f,Topology& n)
{
	f << "******************************** Network printing *****************************\"" << endl << endl;

	std::vector<Assembly*>::iterator it=n.assemblies.begin();
	std::vector<Assembly*>::iterator end=n.assemblies.end();

	while (it!=end)
	{
		f << (*(Assembly*)(*it)) << endl;
		it++;
	}

	return f;
}

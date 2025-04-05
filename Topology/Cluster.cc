// Cluster.cc

// Local Includes
#include "Cluster.h"

/****************************************************************************************************************************************/
/****************************************************** Methodes de la classe Cluster **************************************************/
/****************************************************************************************************************************************/

int Cluster::nbClusters=0;

Cluster::Cluster()
{
	index = nbClusters;
	nbClusters++;
}

Cluster::Cluster(Assembly* rootAssembly)
{
	index = nbClusters;
	nbClusters++;
	addAssembly(rootAssembly);

#ifdef _TEST
	cout << "Cluster: " << nbClusters << endl;
#endif
}

Cluster::Cluster(Cluster& curCluster)
{
	index = curCluster.getIndex();
	nbClusters++;

#ifdef _TEST
	cout << "~Cluster: " << nbClusters << endl;
#endif

	std::vector<Assembly*>::iterator it = curCluster.clusterAssemblies.begin();
	std::vector<Assembly*>::iterator end = curCluster.clusterAssemblies.end();

	while (it != end)
	{
		addAssembly((Assembly*) *it);
		it++;
	}
}

Cluster::~Cluster()
{
	nbClusters--;

#ifdef _TEST
	cout << "~Cluster: " << nbClusters << endl;
#endif
	eraseCluster();
}

Cluster* Cluster::clone()
{
	return new Cluster(*this);
}

void Cluster::eraseCluster()
{
	clusterAssemblies.erase(clusterAssemblies.begin(),clusterAssemblies.end());
	clusterAssemblies.clear();
}

void Cluster::addAssembly(Assembly* newAssembly)
{
	if (!isInCluster(newAssembly))
	{
		clusterAssemblies.push_back((Assembly*) newAssembly);
	}
	else
	{
		cerr << "Warning, assembly " << ((Assembly*) newAssembly)->getIndex() << " is already in cluster " << endl;
	}
}

void Cluster::addCluster(Cluster* rootCluster)
{
	std::vector<Assembly*>::iterator it = rootCluster->clusterAssemblies.begin();
	std::vector<Assembly*>::iterator end = rootCluster->clusterAssemblies.end();
	
	while (it != end)
	{
		addAssembly((Assembly*) &(*(*it)));
		it++;
	}
}

bool Cluster::isInCluster(Assembly* curAssembly)
{
	return ((bool) isInCluster((int) ((Assembly*) curAssembly)->getIndex()));
}

bool Cluster::isInCluster(int assemblyIndex)
{
	std::vector<Assembly*>::iterator it = clusterAssemblies.begin();
	std::vector<Assembly*>::iterator end = clusterAssemblies.end();

	while (it != end)
	{
		if (assemblyIndex == ((Assembly*) *it)->getIndex())
		{
#ifdef _TEST
			cout << "Detected same assembly for " << assemblyIndex << " and " << ((Assembly*) *it)->getIndex() << endl;
#endif
			return 1;
		}

		it++;
	}

	return 0;
}

bool Cluster::isInCluster(Cluster* curCluster)
{
	std::vector<Assembly*>::iterator it = curCluster->clusterAssemblies.begin();
	std::vector<Assembly*>::iterator end = curCluster->clusterAssemblies.end();
	
	while (it != end)
	{
		if (isInCluster((Assembly*) *it))
		{
			return 1;
		}
		it++;
	}
	
	return 0;
}

int Cluster::computeInputLinkFraction(Cluster* targetCluster)
{
	int nbLinks=0;
	
	std::vector<Assembly*>::iterator it = clusterAssemblies.begin();
	std::vector<Assembly*>::iterator end = clusterAssemblies.end();
	
	while (it != end)
	{
		std::vector<Assembly*>::iterator it2 = targetCluster->clusterAssemblies.begin();
		std::vector<Assembly*>::iterator end2 = targetCluster->clusterAssemblies.end();
		
		while (it2 != end2)
		{
			if (((Assembly*) *it)->isInputLinked((Assembly*) *it2))
			{
				nbLinks++;
			}
			it2++;
		}
		it++;
	}
	
	return nbLinks;
}

int Cluster::computeOutputLinkFraction(Cluster* targetCluster)
{
	int nbLinks=0;
	
	std::vector<Assembly*>::iterator it = clusterAssemblies.begin();
	std::vector<Assembly*>::iterator end = clusterAssemblies.end();
	
	while (it != end)
	{
		std::vector<Assembly*>::iterator it2 = targetCluster->clusterAssemblies.begin();
		std::vector<Assembly*>::iterator end2 = targetCluster->clusterAssemblies.end();
		
		while (it2 != end2)
		{
			if (((Assembly*) *it)->isOutputLinked((Assembly*) *it2))
			{
				nbLinks++;
			}
			it2++;
		}
		it++;
	}
	
	return nbLinks;
}

int Cluster::getClusterSize()
{
	return clusterAssemblies.size();
}

bool Cluster::isSameCluster(Cluster* targetCluster)
{
	std::vector<Assembly*>::iterator it = clusterAssemblies.begin();
	std::vector<Assembly*>::iterator end = clusterAssemblies.end();

	while (it != end)
	{
		bool isInBothCluster = 0;
		
		std::vector<Assembly*>::iterator it2 = targetCluster->clusterAssemblies.begin();
		std::vector<Assembly*>::iterator end2 = targetCluster->clusterAssemblies.end();

		while (it2 != end2)
		{
			if (((IndexedObject*) *it)->isSameIndex((IndexedObject*) *it2))
			{
				isInBothCluster = 1;
			}

			it2++;
		}
		
		if (!isInBothCluster)
		{
			return 0;
		}
		it++;
	}
	return 1;
}

Cluster* Cluster::intersectCluster(Cluster* targetCluster)
{
	Cluster* intersectedCluster = new Cluster();
	
	std::vector<Assembly*>::iterator it = clusterAssemblies.begin();
	std::vector<Assembly*>::iterator end = clusterAssemblies.end();
	
	while (it != end)
	{
		std::vector<Assembly*>::iterator it2 = targetCluster->clusterAssemblies.begin();
		std::vector<Assembly*>::iterator end2 = targetCluster->clusterAssemblies.end();
		
		while (it2 != end2)
		{
			if (((IndexedObject*) *it) == ((IndexedObject*) *it2))
			{
				intersectedCluster->addAssembly((Assembly*) *it);
			}
			it2++;
		}
		it++;
	}
	return intersectedCluster;
	
}

Cluster* Cluster::unionCluster(Cluster* targetCluster)
{
	Cluster* unionCluster = new Cluster();
	
	unionCluster->addCluster((Cluster*) this);
	
	std::vector<Assembly*>::iterator it = targetCluster->clusterAssemblies.begin();
	std::vector<Assembly*>::iterator end = targetCluster->clusterAssemblies.end();
		
	while (it != end)
	{
		bool isDifferent = 1;
		
		std::vector<Assembly*>::iterator it2 = clusterAssemblies.begin();
		std::vector<Assembly*>::iterator end2 = clusterAssemblies.end();
	
		while (it2 != end2)
		{
			if (((IndexedObject*) *it) == ((IndexedObject*) *it2))
			{
				isDifferent = 0;
			}
			it2++;
		}
		
		if (isDifferent)
		{
			unionCluster->addAssembly((Assembly*) *it);
		}
		it++;
	}
	
	return unionCluster;
}
	
/****************************************************************************************************************************************/
/****************************************************** Methodes d'affichage console ****************************************************/
/****************************************************************************************************************************************/

std::ostream& operator<<(std::ostream& f, Cluster& c)
{
	cout << "Cluster " << c.index << endl;
	
	std::vector<Assembly*>::iterator it = c.clusterAssemblies.begin();
	std::vector<Assembly*>::iterator end = c.clusterAssemblies.end();
	
	while (it != end)
	{
		f << "Assembly: " << ((Assembly&) (*(*it))).getIndex() << " ";
		it++;
	}
	
	return f;
}

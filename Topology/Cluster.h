// Cluster.h

#ifndef _CLUSTER_H
#define _CLUSTER_H

//#include <stdio.h>

// STL Includes
#include <iostream>
#include <list>
#include <vector>
#include <iterator>
using namespace std;

// Local Includes
#include "../Define.h"
#include "../DefineEDNetwork.h"

#include "../DirectedGraph/Node.h"

#include "Assembly.h"

class Cluster;
#include "../Staters/ClusterStater.h"

/******************************************************************************************************************************************/
/*************************************************************** Classe Cluster  **********************************************************/
/******************************************************************************************************************************************/

class Cluster: public Node
{
protected:
	
	friend class ClusterStater;
	friend class NetworkStater;
	
	// Stockage des liens qui partent de l'assemblée
	std::vector<Assembly*> clusterAssemblies;
	
	static int nbClusters;
public:
	
	Cluster();
	Cluster(Assembly* rootAssembly);
	
	Cluster(Cluster& curCluster);
	
	virtual ~Cluster();
	virtual Cluster* clone();
	
	void eraseCluster();
		
	void addAssembly(Assembly* newAssembly);
	void addCluster(Cluster* newCluster);
	
	bool isInCluster(Assembly* curAssembly);
	bool isInCluster(int assemblyIndex);

	bool isInCluster(Cluster* curAssembly);
	
	int computeInputLinkFraction(Cluster* targetCluster);
	int computeOutputLinkFraction(Cluster* targetCluster);
	
	int getClusterSize();
	
	Cluster* intersectCluster(Cluster* targetCluster);
	Cluster* unionCluster(Cluster* targetCluster);
	
	bool isSameCluster(Cluster* targetCluster);
		
	friend std::ostream& operator<<(std::ostream&, Cluster&);
};

#endif

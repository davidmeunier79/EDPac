// LinkedCluster.h

#ifndef _LINKED_CLUSTER_H
#define _LINKED_CLUSTER_H

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

#include "Cluster.h"

class LinkedCluster;
#include "ClusterLink.h"

#include "../Staters/LinkedClusterStater.h"

/******************************************************************************************************************************************/
/*********************************************************** Classe LinkedCluster  ********************************************************/
/******************************************************************************************************************************************/

class LinkedCluster : public Cluster
{
protected:
	
	friend class LinkedClusterStater;
	
public:
	
	LinkedCluster();
	LinkedCluster(Assembly* rootAssembly);
	LinkedCluster(LinkedCluster& curLinkedCluster);

	virtual ~LinkedCluster();
	virtual LinkedCluster* clone();

	void addLinkedCluster(LinkedCluster* linkClust);
	int checkIntegrity();
	
	void eraseInputCluster(LinkedCluster* inputCluster);
	void eraseOutputCluster(LinkedCluster* outputCluster) ;

	friend std::ostream& operator<<(std::ostream&, LinkedCluster&);
};

#endif

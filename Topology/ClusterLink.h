// ClusterLink.h

#ifndef _CLUSTER_LINK_H
#define _CLUSTER_LINK_H

//#include <stdio.h>

// STL Includes
#include <iostream>
#include <iterator>
using namespace std;

// Local Includes
#include "../Define.h"
#include "../DefineEDNetwork.h"

#include "../DirectedGraph/Link.h"

class ClusterLink;
#include "LinkedCluster.h"

/******************************************************************************************************************************************/
/*********************************************************** Classe ClusterLink  ********************************************************/
/******************************************************************************************************************************************/

class ClusterLink : public Link
{
	static int nbClusterLinks;
public:
	
	ClusterLink();
	ClusterLink(LinkedCluster* newPreClusterLink, LinkedCluster* newPostClusterLink);
	ClusterLink(ClusterLink& curClusterLink);
	
	virtual ~ClusterLink();
	virtual ClusterLink* clone();
	
	friend std::ostream& operator<<(std::ostream&, ClusterLink&);
};

#endif

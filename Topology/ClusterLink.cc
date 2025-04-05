// LinkedCluster.cc

// Local Includes
#include "LinkedCluster.h"

/****************************************************************************************************************************************/
/****************************************************** Methodes de la classe LinkedCluster **************************************************/
/****************************************************************************************************************************************/

int ClusterLink::nbClusterLinks = 0;

ClusterLink::ClusterLink()
{
	index = nbClusterLinks;
	nbClusterLinks++;
}

ClusterLink::ClusterLink(LinkedCluster* newPreLinkedCluster, LinkedCluster* newPostLinkedCluster):Link(newPreLinkedCluster, newPostLinkedCluster)
{
	index = nbClusterLinks;
	nbClusterLinks++;
}

ClusterLink::ClusterLink(ClusterLink& curClusterLink):Link((Link&) curClusterLink)
{
	//index = curClusterLink.index;
	index = nbClusterLinks;
	nbClusterLinks++;
#ifdef _TEST
	cout << "After ClusterLink, " << nbClusterLinks << endl;
#endif
}

ClusterLink::~ClusterLink()
{
	nbClusterLinks--;
#ifdef _TEST
	cout << "After ~ClusterLink, " << nbClusterLinks << endl;
#endif
}

ClusterLink* ClusterLink::clone()
{
	return new ClusterLink(*this);
}

/****************************************************************************************************************************************/
/****************************************************** Methodes d'affichage console ****************************************************/
/****************************************************************************************************************************************/

std::ostream& operator<<(std::ostream& f, ClusterLink& cl)
{
	f << (Link&) cl;	
	return f;
}

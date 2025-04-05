// LinkedCluster.cc

// Local Includes
#include "LinkedCluster.h"

/****************************************************************************************************************************************/
/****************************************************** Methodes de la classe LinkedCluster **************************************************/
/****************************************************************************************************************************************/

LinkedCluster::LinkedCluster()
{
}

LinkedCluster::LinkedCluster(Assembly* rootAssembly):Cluster(rootAssembly)
{
}

LinkedCluster::LinkedCluster(LinkedCluster& curLinkedCluster):Cluster((Cluster&) curLinkedCluster)
{
}

LinkedCluster::~LinkedCluster()
{
}

LinkedCluster* LinkedCluster::clone()
{
	return new LinkedCluster(*this);
}

void LinkedCluster::addLinkedCluster(LinkedCluster* linkClust)
{
	
	// Input Clusters
	std::vector<Link*>::iterator itIn = linkClust->inputLinks.begin();
	std::vector<Link*>::iterator endIn = linkClust->inputLinks.end();
	
	while (itIn != endIn)
	{
		if (!isInCluster((Cluster*) ((LinkedCluster*) ((Node*) ((ClusterLink*) *itIn)->getPreNode()))))
		{
			updateInputLink((ClusterLink*) *itIn);
		}
#ifdef _TEST
		else
		{
			cout << "Cluster " << ((LinkedCluster*) (Node*) ((ClusterLink*) *itIn)->getPreNode())->getIndex() << " is already in cluster " << index << endl;
		}
#endif
		itIn++;
	}

	// Output Clusters
	std::vector<Link*>::iterator itOut = linkClust->outputLinks.begin();
	std::vector<Link*>::iterator endOut = linkClust->outputLinks.end();
	
	while (itOut != endOut)
	{
		if (!isInCluster((Cluster*) ((LinkedCluster*) ((Node*) ((ClusterLink*) *itOut)->getPostNode()))))
		{
			updateOutputLink((ClusterLink*) *itOut);
		}
#ifdef _TEST
		else
		{
			cerr << "Cluster " << ((LinkedCluster*) (Node*) ((ClusterLink*) *itOut)->getPostNode())->getIndex() << " is already in cluster " << index << endl;
		}
#endif
		itOut++;
	}
	
	if (isInputLinked(linkClust))
	{
		eraseInputCluster(linkClust);
	}

	if (isOutputLinked(linkClust))
	{
		eraseOutputCluster(linkClust);
	}
}

int LinkedCluster::checkIntegrity()
{
	std::vector<Link*>::iterator itIn = inputLinks.begin();
	std::vector<Link*>::iterator endIn = inputLinks.end();
	
	while (itIn != endIn)
	{
		std::vector<Link*>::iterator itOut = outputLinks.begin();
		std::vector<Link*>::iterator endOut = outputLinks.end();
		
		while (itOut != endOut)
		{
#ifdef _TEST
			cout << "In: " << (ClusterLink&) *(*itIn) << " Out: " << (ClusterLink&) *(*itOut) << endl;
#endif			
			if (((Node*) ((Link*) *itIn)->getPreNode())->isSameIndex((Node*) ((Link*) *itOut)->getPostNode()))
			{
				int sameIndex = ((Node*) ((Link*) *itIn)->getPreNode())->getIndex();
#ifdef _TEST				
				cout << "*********** Detected " << sameIndex << " as input and output node of LinkedCluster" << index << " *************" << endl;
#endif				
				eraseInputCluster((LinkedCluster*) ((Link*) *itIn)->getPreNode());
				eraseOutputCluster((LinkedCluster*) ((Link*) *itOut)->getPostNode());
				
				return sameIndex;
				
			}
			itOut++;
		}
		itIn++;
	}
	return -1;
}

void LinkedCluster::eraseInputCluster(LinkedCluster* inputCluster)
{
	std::vector<Link*>::iterator itIn = inputLinks.begin();
	std::vector<Link*>::iterator endIn = inputLinks.end();
	
	while (itIn != endIn)
	{
		if (((LinkedCluster*) (Node*) ((ClusterLink*) *itIn)->getPreNode())->isInCluster((LinkedCluster*) inputCluster))
		{
#ifdef _TEST	
			cerr << "*** Removing input cluster link " << (ClusterLink&) *(*itIn);
			cerr << " between " << inputCluster->getIndex() << " and " << index << endl;
#endif
			inputLinks.erase(itIn);
			return;
		}
		itIn++;
	}
	
	cerr << "*** Warning, unable to find cluster " << ((LinkedCluster*) inputCluster)->getIndex();
	cerr << " in inputLinks of cluster " << index << ": ";
	
	std::vector<Link*>::iterator itIn2 = inputLinks.begin();
	std::vector<Link*>::iterator endIn2 = inputLinks.end();
	
	while (itIn2 != endIn2)
	{
		cerr << ((LinkedCluster*) ((ClusterLink*) *itIn2)->getPreNode())->getIndex() << " ";
		itIn2++;
	}
	
	cerr << endl;
}

void LinkedCluster::eraseOutputCluster(LinkedCluster* outputCluster)
{
	std::vector<Link*>::iterator itOut = outputLinks.begin();
	std::vector<Link*>::iterator endOut = outputLinks.end();
	
	while (itOut != endOut)
	{
		if (((LinkedCluster*) (Node*) ((ClusterLink*) *itOut)->getPostNode())->isInCluster((LinkedCluster*) outputCluster))
		{
#ifdef _TEST	
			cerr << "*** Removing output cluster link " << (ClusterLink&) *(*itOut);
			cerr << " between " << index << " and " << outputCluster->getIndex() << endl;
#endif
			outputLinks.erase(itOut);
			return;
		}
		itOut++;
	}
	
	cerr << "*** Warning, unable to find cluster " << ((LinkedCluster*) outputCluster)->getIndex();
	cerr << " in outputLinks of cluster " << index << ": ";
	
	std::vector<Link*>::iterator itOut2 = outputLinks.begin();
	std::vector<Link*>::iterator endOut2 = outputLinks.end();
	
	while (itOut2 != endOut2)
	{
		cerr << ((LinkedCluster*) (Node*) ((ClusterLink*) *itOut2)->getPostNode())->getIndex() << " ";
		itOut2++;
	}
	
	cerr << endl;
}

/****************************************************************************************************************************************/
/****************************************************** Methodes d'affichage console ****************************************************/
/****************************************************************************************************************************************/

std::ostream& operator<<(std::ostream& f, LinkedCluster& lc)
{
	
	f << "Linked Cluster: " << lc.getIndex() << " : ";
	
	f << (Cluster&) lc << endl;
	f << (Node&) lc << endl;
	
	return f;
}

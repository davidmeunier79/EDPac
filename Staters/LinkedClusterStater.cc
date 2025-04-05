// LinkedClusterStater.cc

// Local Includes
#include "LinkedClusterStater.h"

/****************************************************************************************************************************************/
/********************************************* Methodes de la classe LinkedClusterStater ************************************************/
/****************************************************************************************************************************************/

LinkedClusterStater::LinkedClusterStater()
{
#ifdef _NETWORK_STAT_MODE
	openTracer();
	
	#ifdef _CENTRALITY_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
			#ifdef _LINKED_CLUSTER_STAT_MODE
	inDC = new Accumulater();
	inGIN = new Accumulater();
	inGOUT = new Accumulater();
	inGSCC = new Accumulater();
			#endif
		#endif
	#endif
	
	#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	linkedClusterBetweenness = new Accumulater();
	//linkedClusterBetweennessDistribution = new LogDistribution(-1,4,5);
	linkedClusterBetweennessDistribution = new LogDistribution(0,4,5);

	linkedClusterCentralBetweenness = new Accumulater();
	//linkedClusterCentralBetweennessDistribution = new LogDistribution(-8,0,5);
	linkedClusterCentralBetweennessDistribution = new LogDistribution(-4,0,5);


	linkedClusterGlobalEfficiency = new Accumulater();
	//linkedClusterGlobalEfficiencyDistribution = new LogDistribution(-8,0,5);
	linkedClusterGlobalEfficiencyDistribution = new LogDistribution(-2,0,5);

	linkedClusterLocalEfficiency = new Accumulater();
	//linkedClusterLocalEfficiencyDistribution = new LogDistribution(-8,0,5);
	linkedClusterLocalEfficiencyDistribution = new LogDistribution(-2,0,5);

		#ifdef _EDGE_BETWEENNESS_STAT_MODE
	//linkedClusterEdgeBetweennessDistribution = new LogDistribution(-1,4,5);
	linkedClusterEdgeBetweennessDistribution = new LogDistribution(0,4,5);
		#endif
	#endif
#endif
}

LinkedClusterStater::LinkedClusterStater(IndexedObject* io) : ClusterStater(io)
{
#ifdef _NETWORK_STAT_MODE
	openTracer();
	
	#ifdef _CENTRALITY_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
			#ifdef _LINKED_CLUSTER_STAT_MODE
	inDC = new Accumulater();
	inGIN = new Accumulater();
	inGOUT = new Accumulater();
	inGSCC = new Accumulater();
			#endif
		#endif
	#endif
	
	#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	linkedClusterBetweenness = new Accumulater();
	//linkedClusterBetweennessDistribution = new LogDistribution(-1,4,5);
	linkedClusterBetweennessDistribution = new LogDistribution(0,4,5);

	linkedClusterCentralBetweenness = new Accumulater();
	//linkedClusterCentralBetweennessDistribution = new LogDistribution(-8,0,5);
	linkedClusterCentralBetweennessDistribution = new LogDistribution(-4,0,5);


	linkedClusterGlobalEfficiency = new Accumulater();
	//linkedClusterGlobalEfficiencyDistribution = new LogDistribution(-8,0,5);
	linkedClusterGlobalEfficiencyDistribution = new LogDistribution(-2,0,5);

	linkedClusterLocalEfficiency = new Accumulater();
	//linkedClusterLocalEfficiencyDistribution = new LogDistribution(-8,0,5);
	linkedClusterLocalEfficiencyDistribution = new LogDistribution(-2,0,5);

		#ifdef _EDGE_BETWEENNESS_STAT_MODE
	//linkedClusterEdgeBetweennessDistribution = new LogDistribution(-1,4,5);
	linkedClusterEdgeBetweennessDistribution = new LogDistribution(0,4,5);
		#endif
	#endif
#endif

}

LinkedClusterStater::~LinkedClusterStater()
{
#ifdef _NETWORK_STAT_MODE
	cerr << "In ~LinkedClusterStater" << endl;

	closeTracer();

	openGrapher();
	graph();
	runGrapher();
	closeGrapher();
	
	#ifdef _CLUSTER_CENTRALITY_STAT_MODE
		#ifdef _EDGE_BETWEENNESS_STAT_MODE
	delete(linkedClusterEdgeBetweennessDistribution);
		#endif
		
	delete(linkedClusterBetweenness);
	delete(linkedClusterBetweennessDistribution);
	
	delete(linkedClusterCentralBetweenness);
	delete(linkedClusterCentralBetweennessDistribution);
	
	delete(linkedClusterGlobalEfficiency);
	delete(linkedClusterGlobalEfficiencyDistribution);
	
	delete(linkedClusterLocalEfficiency);
	delete(linkedClusterLocalEfficiencyDistribution);
	#endif
	
	#ifdef _CENTRALITY_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
			#ifdef _LINKED_CLUSTER_STAT_MODE
	delete(inDC);
	delete(inGIN);
	delete(inGOUT);
	delete(inGSCC);
			#endif
		#endif
	#endif
#endif
}

void LinkedClusterStater::openTracer()
{
#ifdef _NETWORK_STAT_MODE
	
#endif
}

void LinkedClusterStater::closeTracer()
{
#ifdef _NETWORK_STAT_MODE
	
#endif
}

void LinkedClusterStater::openGrapher()
{
#ifdef _NETWORK_STAT_MODE

#endif
}

void LinkedClusterStater::runGrapher()
{
#ifdef _NETWORK_STAT_MODE
	
#endif
}

void LinkedClusterStater::closeGrapher()
{
#ifdef _NETWORK_STAT_MODE
	
#endif
}

/****************************************************************************************************************************************/
/******************************************************* Compteurs **************************************************************/
/****************************************************************************************************************************************/

void LinkedClusterStater::initCounters()
{	
#ifdef _NETWORK_STAT_MODE
	#ifdef _CENTRALITY_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
			#ifdef _LINKED_CLUSTER_STAT_MODE
	inDC->initAccu();
	inGIN->initAccu();
	inGOUT->initAccu();
	inGSCC->initAccu();
			#endif
		#endif
	#endif
	
	#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	if (linkedClusterBetweenness)
	{
		linkedClusterBetweenness->initAccu();
	}

	if (linkedClusterBetweennessDistribution)
	{
		linkedClusterBetweennessDistribution->initDistribution();
	}

	if (linkedClusterCentralBetweenness)
	{
		linkedClusterCentralBetweenness->initAccu();
	}
	
	if (linkedClusterCentralBetweennessDistribution)
	{
		linkedClusterCentralBetweennessDistribution->initDistribution();
	}

	if (linkedClusterGlobalEfficiency)
	{
		linkedClusterGlobalEfficiency->initAccu();
	}
	
	if (linkedClusterGlobalEfficiencyDistribution)
	{
		linkedClusterGlobalEfficiencyDistribution->initDistribution();
	}

	if (linkedClusterLocalEfficiency)
	{
		linkedClusterLocalEfficiency->initAccu();
	}

	if (linkedClusterLocalEfficiencyDistribution)
	{
		linkedClusterLocalEfficiencyDistribution->initDistribution();
	}

		#ifdef _EDGE_BETWEENNESS_STAT_MODE
	if (linkedClusterEdgeBetweennessDistribution)
	{
		linkedClusterEdgeBetweennessDistribution->initDistribution();
		
	}

	linkedClusterMaxEdgeBetweenness = 0.0;
		#endif	
	#endif
#endif
}

void LinkedClusterStater::flushCounters()
{
#ifdef _NETWORK_STAT_MODE
	
#endif
}

/****************************************************************************************************************************************/
/******************************************************* Methodes de stats **************************************************************/
/****************************************************************************************************************************************/

#ifdef _NETWORK_STAT_MODE
	#ifdef _CENTRALITY_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
void LinkedClusterStater::stat(LinkedCluster* curCluster)
{
			#ifdef _LINKED_CLUSTER_STAT_MODE

	statClusterSize((Cluster*) curCluster);
	computeEfficiency((Cluster*) curCluster);
	
	if (((LinkedCluster*) curCluster)->getNbInputLinks() == 0 && ((LinkedCluster*) curCluster)->getNbOutputLinks() == 0)
	{
		inDC->accumulate(curCluster->getClusterSize());
	}
	else if (((LinkedCluster*) curCluster)->getNbInputLinks() == 0)
	{
		inGIN->accumulate(curCluster->getClusterSize());
	}
	else if (((LinkedCluster*) curCluster)->getNbOutputLinks() == 0)
	{
		inGOUT->accumulate(curCluster->getClusterSize());
	}
	else
	{
		inGSCC->accumulate(curCluster->getClusterSize());
	}
			#endif
}
		#endif
	#endif
	
	#ifdef _CLUSTER_CENTRALITY_STAT_MODE
void LinkedClusterStater::computeLinkedClusterEfficiency()
{
	for (int i=0;i< NB_ASSEMBLIES;i++)
	{
		if (0.0 <= nodeGlobalEfficiency[i])
		{
			linkedClusterGlobalEfficiency->accumulate(nodeGlobalEfficiency[i]);
			((LogDistribution*) linkedClusterGlobalEfficiencyDistribution)->count((double) nodeGlobalEfficiency[i]);
		}
	}

	for (int i=0;i< NB_ASSEMBLIES;i++)
	{
		if (0.0 <= nodeLocalEfficiency[i])
		{
			linkedClusterLocalEfficiency->accumulate(nodeLocalEfficiency[i]);
			((LogDistribution*) linkedClusterLocalEfficiencyDistribution)->count((double) nodeLocalEfficiency[i]);
		}
	}
}

void LinkedClusterStater::computeLinkedClusterBetweenness()
{
	for (int i=0;i<NB_ASSEMBLIES;i++)
	{
		if (0.0 <= nodeBetweenness[i].getAccu())
		{
			linkedClusterBetweenness->accumulate(nodeBetweenness[i].getAccu());
			((LogDistribution*) linkedClusterBetweennessDistribution)->count((double) nodeBetweenness[i].getAccu());
		}
		else
		{
			cerr << "Warning, nodeBetweenness is negative " << endl;
		}
	}
}

void LinkedClusterStater::computeLinkedClusterCentralBetweenness()
{
	// Plus haute nodeBetweenness
	double highestBetwenness = 0.0;

	int nbClusters=0;
	
	for (int i=0;i<NB_ASSEMBLIES;i++)
	{
		if (nodeBetweenness[i].getCounter() != 0)
		{
			if (highestBetwenness <= nodeBetweenness[i].getAccu())
			{
				highestBetwenness = nodeBetweenness[i].getAccu();
			}
			
			nbClusters++;
		}
	}

	if (2 < nbClusters)
	{
		for (int i=0;i<NB_ASSEMBLIES;i++)
		{
			if (nodeBetweenness[i].getCounter() != 0)
			{
				double curCentralBetweenness = (((double) fabs((double) (highestBetwenness - nodeBetweenness[i].getAccu()))*(nbClusters+2))/((double) ((nbClusters-2)*(nbClusters+1)*nbClusters*(nbClusters-1))));
				
				linkedClusterCentralBetweenness->accumulate((double) curCentralBetweenness);
				
				((LogDistribution*) linkedClusterCentralBetweennessDistribution)->count((double) curCentralBetweenness);
			}
		}
	}
	else
	{
		linkedClusterCentralBetweenness->accumulate(0.0);
	}
	
}

void LinkedClusterStater::computeLinkedClusterShortPaths()
{
	linkedClusterShortPathLengthDistribution = shortPathLengthDistribution;
}

		#ifdef _EDGE_BETWEENNESS_STAT_MODE
void LinkedClusterStater::computeLinkedClusterEdgeBetweennessDistribution()
{
	for (int i=0;i<NB_ASSEMBLIES;i++)
	{
		for (int j=0;j<NB_ASSEMBLIES;j++)
		{
			if (LoopStater::edgeBetweenness[i][j].getCounter() != 0)
			{
			#ifdef _TEST_STAT
				cout << "in LCS edgeBetweenness[" << i << "][" << j << "]: " << LoopStater::edgeBetweenness[i][j].getAccu() << endl;
			#endif	
				((LogDistribution*) linkedClusterEdgeBetweennessDistribution)->count((double) LoopStater::edgeBetweenness[i][j].getAccu());
			}
		}
	}
}

void LinkedClusterStater::computeLinkedClusterMaxEdgeBetweenness()
{
	for (int i=0;i<NB_ASSEMBLIES;i++)
	{
		for (int j=0;j<NB_ASSEMBLIES;j++)
		{
			if (LoopStater::edgeBetweenness[i][j].getCounter() != 0)
			{
			#ifdef _TEST_STAT
				cout << "in LCS edgeBetweenness[" << i << "][" << j << "]: " << LoopStater::edgeBetweenness[i][j].getAccu() << endl;
			#endif	
				if (linkedClusterMaxEdgeBetweenness  < LoopStater::edgeBetweenness[i][j].getAccu())
				{
					linkedClusterMaxEdgeBetweenness = LoopStater::edgeBetweenness[i][j].getAccu();
				}
			}
		}
	}
			#ifdef _TEST_STAT
	cout << "linkedClusterMaxEdgeBetweenness = " << linkedClusterMaxEdgeBetweenness << endl;
			#endif
}

double LinkedClusterStater::getLinkedClusterMaxEdgeBetweenness()
{
	return linkedClusterMaxEdgeBetweenness;
}
		#endif
	#endif
#endif

/****************************************************************************************************************************************/
/****************************************************** Methodes de traces **************************************************************/
/****************************************************************************************************************************************/

void LinkedClusterStater::trace()
{
}

void LinkedClusterStater::graph()
{
}

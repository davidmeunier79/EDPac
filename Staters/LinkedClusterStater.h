// LinkedClusterStater.h

#ifndef _LINKED_CLUSTER_STATER_H
#define _LINKED_CLUSTER_STATER_H

// STL Includes
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Local Includes
#include "../Define.h"
#include "../DefineGA.h"
#include "../DefineZoo.h"
#include "../DefineEDNetwork.h"

#include "../DefineStater.h"
#include "../DefineTracer.h"
#include "../DefineGrapher.h"

#include "../Handlers/Counter.h"
#include "../Handlers/Accumulater.h"

#include "ClusterStater.h"

class LinkedClusterStater;
#include "../Topology/LinkedCluster.h"

/******************************************************************************************************************************************/
/************************************************* Classe LinkedClusterStater *************************************************************/
/******************************************************************************************************************************************/

class LinkedClusterStater : public ClusterStater
{
	
protected:

#ifdef _NETWORK_STAT_MODE
	
	#ifdef _CENTRALITY_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
			#ifdef _LINKED_CLUSTER_STAT_MODE
	Accumulater* inDC;
	Accumulater* inGIN;
	Accumulater* inGOUT;
	Accumulater* inGSCC;
			#endif
		#endif
	#endif
	
	#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	
	// Calcul d'intermediarité
	Accumulater* linkedClusterBetweenness;
	LogDistribution* linkedClusterBetweennessDistribution;
	
	// Calcul de centralité
	Accumulater* linkedClusterCentralBetweenness;
	LogDistribution* linkedClusterCentralBetweennessDistribution;
	
	// Efficacité
	Accumulater* linkedClusterLocalEfficiency;
	LogDistribution* linkedClusterLocalEfficiencyDistribution;
	
	Accumulater* linkedClusterGlobalEfficiency;
	LogDistribution* linkedClusterGlobalEfficiencyDistribution;
	
	Distribution* linkedClusterShortPathLengthDistribution;
	
		#ifdef _EDGE_BETWEENNESS_STAT_MODE
	LogDistribution* linkedClusterEdgeBetweennessDistribution;	
	double linkedClusterMaxEdgeBetweenness;
		#endif
	#endif
#endif
	
	void openGrapher();
	void closeGrapher();
	void runGrapher();

	void openTracer();
	void closeTracer();

public:
	LinkedClusterStater();
	LinkedClusterStater(IndexedObject* io);

	virtual ~LinkedClusterStater();
	
#ifdef _NETWORK_STAT_MODE

	#ifdef _CENTRALITY_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
	void stat(LinkedCluster* curCluster);
	
			#ifdef _LINKED_CLUSTER_STAT_MODE
	void initClusterComponentCounters();
			#endif
		#endif
	#endif
	
	#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	void computeLinkedClusterEfficiency();
	void computeLinkedClusterBetweenness();
	void computeLinkedClusterCentralBetweenness();
	
	void computeLinkedClusterShortPaths();
	
		#ifdef _EDGE_BETWEENNESS_STAT_MODE
	void computeLinkedClusterEdgeBetweennessDistribution();
				
	void computeLinkedClusterMaxEdgeBetweenness();

	double getLinkedClusterMaxEdgeBetweenness();
	int getPreLinkedClusterMaxEdgeBetweenness();
	int getPostLinkedClusterMaxEdgeBetweenness();
	
		#endif
	#endif
	
#endif
	void initCounters();
	void flushCounters();
	
	void trace();
	void graph();
};

#endif

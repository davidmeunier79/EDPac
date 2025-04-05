// ClusterStater.h

#ifndef _CLUSTER_STATER_H
#define _CLUSTER_STATER_H

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

#include "AssemblyStater.h"

class ClusterStater;
#include "../Topology/Cluster.h"

/******************************************************************************************************************************************/
/****************************************************** Classe ClusterStater *************************************************************/
/******************************************************************************************************************************************/

class ClusterStater : public AssemblyStater
{
protected:

	
#ifdef _NETWORK_STAT_MODE

	#ifdef _CENTRALITY_STAT_MODE	
		#ifdef _EDGE_BETWEENNESS_STAT_MODE
			#ifdef _CLUSTER_STAT_MODE
	int nbClusters;

	Distribution* clusterSizeDistribution;
	int maxClusterSize;

	double clusterEfficiencyRepartition[NB_ASSEMBLIES];
	
	LogDistribution* clusterEfficiencyDistribution;
	Accumulater* clusterEfficiency;

	LogDistribution* clusterRealEfficiencyDistribution;
	Accumulater* clusterRealEfficiency;

	double clusterModularity;

			#endif
			
		#endif
	#endif

	#ifdef _SMALL_WORLD_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
	Accumulater* clusterInternalDensity;
	Accumulater* realClusterInternalDensity;
		#endif
	#endif
	
	#ifdef _MOTIF_STAT_MODE
		#ifdef _INTERNAL_MOTIF_STAT_MODE
	Counter* internalBinodeMotifs;
	Distribution* internalTrinodeMotifsDistribution;
		#endif
	#endif
	
	#ifdef _INPUT_OUTPUT_CLUSTER_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
	Distribution* inputClusterSizeDistribution;
	Distribution* outputClusterSizeDistribution;
	
	double inputClusterFractionRepartition[NB_INPUT_ASSEMBLIES];
	double outputClusterFractionRepartition[NB_OUTPUT_ASSEMBLIES];
	
	int nbLinkedProjections;
		#endif
	#endif
#endif
	void openGrapher();
	void closeGrapher();
	void runGrapher();

	void openTracer();
	void closeTracer();

public:
	ClusterStater();
	ClusterStater(IndexedObject* io);

	virtual ~ClusterStater();
	
#ifdef _NETWORK_STAT_MODE
	#ifdef _CENTRALITY_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
	void computeEfficiency(Cluster* curCluster);
	void computeClusterEfficiency();

	void statClusterSize(Cluster* curCluster);
	
	void initClusterModularity();
	void addClusterModularity(double curModularity);
	double getClusterModularity();
		#endif
	#endif

	// Loops
	#ifdef _LOOP_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
	void statInternalLoops(Cluster* curCluster);
	void statDepthFirstPostProjections(Assembly* curAssembly,Cluster* curCluster);
		#endif
	#endif
	
	// Clustering Coeff
	#ifdef _SMALL_WORLD_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
	void initClusterInternalDensityCounters();
	void statClusterInternalDensity(Cluster* curCluster);
		#endif
	#endif
	
	#ifdef _MOTIF_STAT_MODE
		#ifdef _INTERNAL_MOTIF_STAT_MODE
	void initInternalMotifsCounters();
	void statInternalMotifs(Cluster* curCluster);
		#endif
	#endif
	
	#ifdef _INPUT_OUTPUT_CLUSTER_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
	void initInputOutputCounters();
	void initNbProjections();
	
	void statInputClusters(Assembly* curInputAssembly,Cluster* curCluster);
	void statNbInputProjections(int inputAssemblyIndex, int degree);
	
	void statOutputClusters(Assembly* curOutputAssembly,Cluster* curCluster);
	void statNbOutputProjections(int outputAssemblyIndex, int degree);
		#endif
	#endif

#endif
	void initCounters();
	void flushCounters();
	
	void trace();
	void graph();
};

#endif

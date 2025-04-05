// EDNetwork.h

#ifndef _EDNETWORK_H
#define _EDNETWORK_H

//#include <stdio.h>

// STL Includes
//#include <iostream>
//#include <queue>
//#include <deque>
//#include <vector>
//#include <fstream>
using namespace std;

// Local Includes

#include "../Define.h"
#include "../DefineZoo.h"

#include "../DefineEDNetwork.h"
#include "../DefineGA.h"
#include "../DefineMPI.h"

#include "../DefineStater.h"
#include "../DefineTracer.h"
#include "../DefineGrapher.h"

#include "../DefineWindow.h"

#include "../Interfaces/Tracable.h"
#include "../Interfaces/Graphable.h"
#include "../Interfaces/Statable.h"

#include "../Files/IOFile.h"

#include "../MathTools/NeuronMathTools.h"

#include "../MPI/InputAssembly.h"
#include "../MPI/OutputAssembly.h"

#include "../MPI/SynchroModule.h"

#include "../Topology/Topology.h"
#include "../Topology/Cluster.h"
#include "../Topology/ClusterLink.h"
#include "../Topology/LinkedCluster.h"

#include "EDAssembly.h"

class EDNetwork;
#include "../Tracers/NetworkTracer.h"
#include "../Graphers/NetworkGrapher.h"
#include "../Staters/NetworkStater.h"
#include "../Staters/InputStater.h"
#include "../Staters/ActivityStater.h"

/******************************************************************************************************************************************/
/******************************************************** Classe EDNetwork ****************************************************************/
/******************************************************************************************************************************************/

class EDNetwork : public Topology, public SynchroModule, public Tracable, public Graphable, public Statable
{
#ifdef _CLUSTER_STAT_MODE

	std::vector<Projection*> tabOrderedProjections;

	#if (defined(_SAVE_ORDERED_PROJECTIONS_MODE) || defined(_LOAD_ORDERED_PROJECTIONS_MODE))
	IOFile* tabOrderedProjectionsFile;
	#endif
	
	#ifdef _LINKED_CLUSTER_STAT_MODE
	
	// Conservation de tous les liens entre clusters, pour destruction
	std::vector<ClusterLink*> tabClusterLinks;
	
	// Table des clusters
	std::vector<LinkedCluster*> tabClusters;

	// Necessaire pour conserver tous les clusters initiaux
	std::vector<LinkedCluster*> tabInitialClusters;

		#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
	std::vector<LinkedCluster*> tabOptimalClusters;
		#endif
	#else
	std::vector<Cluster*> tabClusters;

	// Necessaire pour conserver tous les clusters initiaux
	std::vector<Cluster*> tabInitialClusters;

		#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
	std::vector<Cluster*> tabOptimalClusters;
		#endif
	#endif

	int nbInternalProjections;

#endif	
protected:

	int timeRef;

	// Intégration des inputs dans le réseau
	void integrateInputs(int time);

	// Intégration des outputs du réseau dans le message
	void integrateOutputs(int time);

	// Construction des assemblées
	void initAssemblies();

	void addNewAssembly();
	
	// Destruction des assemblees internes
	void deleteAssemblies();
	
#ifdef _TOPOLOGY_PROJECTION_MODE
	// Contruction des projections
	void buildProjections();
	
	
	#ifdef _INCREMENTAL_TOPOLOGY_MODE
	void buildIncrementalProjections();
	void buildIncrementalPostProjection(double relativePreAssemblyIndex, int projectionCode, double relativePostAssemblyIndex);
	#endif
	
	void buildPostProjection(int preAssemblyIndex,int postAssemblyIndex, int projectionCode);
	// Destruction des projections
	void destroyProjections();
#else

	// Construction des liens synaptiques
	void buildTopology();
	
	#ifdef _INCREMENTAL_TOPOLOGY_MODE
	void buildCompleteIncrementalPostProjection(double relativePreAssemblyIndex, int projectionCode, double relativePostAssemblyIndex);
	#endif
	
	void buildCompletePostProjection(int preAssemblyIndex,int projectionCode, int postAssemblyIndex);
		
	#ifdef _SELF_INHIBITION_MODE
	void buildCompleteSelfInhibitions();
	#endif
	// Destruction des liens synaptiques
	void destroyTopology();
#endif

	void initSynchroBuffer();

	// Reception des inputs
	void receiveInputs();

	// Envoi des outputs
	void sendOutputs();
	
	// Si pas d'evenement	
	void receiveVoidInputs();
	
#ifdef _LINK_INPUT_STAT_MODE
	NeuronStater* inputLinkStater;
#endif

public:

#ifdef _TRANSITION_STAT_MODE
	static int TRANSITION_TIME_LENGTH;
#endif

	// Construction + ouverture des fichiers traces
	EDNetwork();
	EDNetwork(int newNbInputBuffers, int newNbOutputBuffers);

	// Destruction du réseau + fermeture des fichiers trace et/ou graph
	~EDNetwork();

	void initInputBuffers();
	void initOutputBuffers();

#ifdef _GRAPHICAL_DISPLAY_MODE
	void display();
#endif

#ifdef _NETWORK_STAT_MODE
	friend class NetworkStater;
	void statNetwork();
	
	
	#ifdef _TOPOLOGY_STAT_MODE
	void statTopology();
	#endif
	
	#ifdef _LINK_TO_INPUT_STAT_MODE
	void statInputConnectivity();
	#endif
	
	#ifdef _LINK_TO_OUTPUT_STAT_MODE
	void statOutputConnectivity();
	#endif
	
	#ifdef _CENTRALITY_STAT_MODE
	void statAssemblyPaths();
	#endif
	
	#ifdef _LOOP_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
	void statInternalClusterLoops();
		#endif
	void statLoops();
	#endif
	
	#ifdef _SMALL_WORLD_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
	void statClusterInternalDensity();
		#endif
	void statClusteringCoeff();
	#endif

	#ifdef _MOTIF_STAT_MODE
	void statMotifs();
	
		#ifdef _INTERNAL_MOTIF_STAT_MODE
	void statInternalMotifs();	
		#endif
	#endif

	#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE
	// Liens input-outputs
	void statInputOutputLinks();
	#endif

	#ifdef _DEGREE_STAT_MODE
	void statDegree();
	#endif

	#ifdef _GSCC_STAT_MODE
	void statAssemblySCC();
		
		#ifdef _INPUT_OUTPUT_GSCC_STAT_MODE
	void statInputOutputSCC();
		#endif
	#endif
	
	#ifdef _PROJECTION_STAT_MODE
	void statProjections();
	#endif
	
	#ifdef _CLUSTER_STAT_MODE
		
	void buildClusters();
				
	void removeLinks();
			
		#ifdef _SAVE_ORDERED_PROJECTIONS_MODE
	void saveTabOrderedProjections();
		#else
			#ifdef _LOAD_ORDERED_PROJECTIONS_MODE
	void loadTabOrderedProjections();
			#endif
		#endif
		
	// Suppression d'une projection
	bool removeProjection(int preAssemblyIndex, int postAssemblyIndex);
	
		#ifdef _GN_CLUSTER_STAT_MODE
	bool removeAssemblyMaxBetweenness();
		#else
			#ifdef _EFFICIENCY_CLUSTER_STAT_MODE
	bool removeMaxEfficiencyLink();
	double computeIntermediateEfficiency();
			#else
	bool removeRandomLink();
			#endif
		#endif
		
	void initTabOrderedProjections();
	
	void initTabClusters();

	void updateClusters(Projection* curProjection);

	void statClusterEfficiency();
	
	void freeTabClusters();

		#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
	void freeTabOptimalClusters();

	void cloneTabClusters();

	void computeTabOptimalClusters();
	
			#ifdef _LINKED_CLUSTER_STAT_MODE
	// Rajout de tous les liens entre les clusters
	void cloneTabClusterLinks();
			#endif
		#endif

		#ifdef _CLUSTER_CENTRALITY_STAT_MODE
			#ifdef _CENTRALITY_STAT_MODE
	void statLinkedClusterPath();
			#endif	
				
			#ifdef _SMALL_WORLD_STAT_MODE
	void statLinkedClusterClusteringCoeffs();
			#endif
				
			#ifdef _DEGREE_STAT_MODE
	void statLinkedClusterDegree();
			#endif
				
			#ifdef _MOTIF_STAT_MODE
	void statLinkedClusterMotifs();
			#endif
			
		#endif
	#endif
#endif

#ifdef _ASSEMBLY_STAT_MODE
	void traceNetworkFiles();
	void traceVoidFiles();
	
	
	#ifdef _PSP_LFP_STAT_MODE
	void initPSPotential();
	#endif
#endif

	void initNetworkFiles();
	void endNetworkFiles();

#ifdef _GRAPH_MODE
	friend class NetworkGrapher;

	void initNetworkGrapher();
	void freeNetworkGrapher();
#endif

#ifdef _NETWORK_TRACE_MODE
	friend class NetworkTracer;

	void initNetworkTracer();
	void freeNetworkTracer();
#endif

	void runSimulation();
	void runOneStep();
};

#endif

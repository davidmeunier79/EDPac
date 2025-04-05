// LoopStater.h

#ifndef _LOOP_STATER_H
#define _LOOP_STATER_H

// STL Includes
#include <iostream>
#include <string>
#include <iterator>
#include <fstream>
#include <deque>
using namespace std;

// Local Includes
#include "../Define.h"
#include "../DefineEDNetwork.h"

#include "../DefineStater.h"

#include "../Handlers/Stater.h"
#include "../Handlers/Tracer.h"
#include "../Handlers/Grapher.h"

#include "../Handlers/Counter.h"
#include "../Handlers/Accumulater.h"
#include "../Handlers/Distribution.h"
#include "../Handlers/LogDistribution.h"
#include "../Handlers/MeanDistribution.h"

#include "../DirectedGraph/Node.h"
#include "../DirectedGraph/Link.h"

/******************************************************************************************************************************************/
/****************************************************** Classe LoopStater *************************************************************/
/******************************************************************************************************************************************/

class LoopStater : public Stater
{
	virtual void openTracer();
	virtual void closeTracer();

	virtual void openGrapher();
	virtual void runGrapher();
	virtual void closeGrapher();
/*
	vector<int> tabIndex;
*/
protected:

	
#ifdef _NETWORK_STAT_MODE

	#ifdef _CENTRALITY_STAT_MODE
	
			// Variables globales du réseau
		
		// Calcul d'intermediarite
			
	// Correspond à Cb dans (Brandes,2001)
	Accumulater nodeBetweenness[NB_ASSEMBLIES];
	
		// Calcul d'efficacité du réseau

	// Stockage de l'efficaté entre 2 noeuds du réseau
	//double efficiency[NB_ASSEMBLIES][NB_ASSEMBLIES];
	double efficiency[NB_ASSEMBLIES][NB_ASSEMBLIES];
	
	// Efficacité global de chaque noeud
	//double nodeGlobalEfficiency[NB_ASSEMBLIES];
	double nodeGlobalEfficiency[NB_ASSEMBLIES];
	
	// Efficacité local de chaque noeud
	//double nodeLocalEfficiency[NB_ASSEMBLIES];
	double nodeLocalEfficiency[NB_ASSEMBLIES];
	
	// Repartition des shortPath
	//Counter shortPathRepartition[NB_ASSEMBLIES];
	//Counter noShortPathRepartition[NB_ASSEMBLIES];
	Counter shortPathRepartition[NB_ASSEMBLIES];
	Counter noShortPathRepartition[NB_ASSEMBLIES];
	
	Distribution* shortPathLengthDistribution;
	
		#ifdef _EDGE_BETWEENNESS_STAT_MODE
	// Valeur d'intermediarité pour chaque lien du réseau
	//Accumulater edgeBetweenness[NB_ASSEMBLIES][NB_ASSEMBLIES];
	Accumulater edgeBetweenness[NB_ASSEMBLIES][NB_ASSEMBLIES];	
		#endif
		
			// Variables liés au parcours à partir d'un noeud donné
		
	// Correspond a sigma dans (Brandes,2001)
	//int nbShortPaths[NB_ASSEMBLIES];
	int nbShortPaths[NB_ASSEMBLIES];
	
	// Correspond à d dans (Brandes,2001)
	//int shortPathLengths[NB_ASSEMBLIES];
	int shortPathLengths[NB_ASSEMBLIES];
	
	// Correspond à S dans (Brandes,2001)
	vector<Node*> tabShortPaths;
	
	// Correspond à P[w] dans (Brandes,2001)
	// Premier indice:  predecesseur v
	// Deuxieme indice: voisin w
	//bool directPredecessors[NB_ASSEMBLIES][NB_ASSEMBLIES];
	bool directPredecessors[NB_ASSEMBLIES][NB_ASSEMBLIES];
	
	// Correspond à delta dans (Brandes,2001)
	Accumulater pairCorrelations[NB_ASSEMBLIES];
			
		#ifdef _EDGE_BETWEENNESS_STAT_MODE
	//double edgeWeights[NB_ASSEMBLIES][NB_ASSEMBLIES];
	double edgeWeights[NB_ASSEMBLIES][NB_ASSEMBLIES];
		#endif
	#endif

	#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE
	Distribution* reachedByInputDistribution;
	Distribution* reachedByOutputDistribution;

	int pathToInput[NB_ASSEMBLIES];
	int pathToOutput[NB_ASSEMBLIES];

	Distribution* pathToInputDistribution;
	Distribution* pathToOutputDistribution;
	
	Distribution* inputOutputPathLengthDistribution;
	#endif

	#ifdef _SMALL_WORLD_STAT_MODE
	MeanDistribution* clusteringCoeffDegreeDistribution;
	LogDistribution* clusteringCoeffDistribution;
	
	double clusteringCoeffRepartition[NB_ASSEMBLIES];

	Accumulater* networkClusteringCoeff;

	#endif

	#ifdef _MOTIF_STAT_MODE
	Counter* binodeMotifs;
	Distribution* trinodeMotifsDistribution;
	#endif

	#ifdef _DEGREE_STAT_MODE
	Distribution* degreeDistribution;
	Distribution* preDegreeDistribution;
	Distribution* postDegreeDistribution;
	
	MeanDistribution* nearestNeighboursDegreeDistribution;
	
		#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE
	Distribution* inputNodeDegreeDistribution;
	Distribution* outputNodeDegreeDistribution;
	
	MeanDistribution* inputNodeNearestNeighboursDegreeDistribution;
	MeanDistribution* outputNodeNearestNeighboursDegreeDistribution;
		#endif
	#endif
	
	#ifdef _LOOP_STAT_MODE
	Counter nbLoopsRepartition[NB_ASSEMBLIES];
	Distribution* loopSizeDistribution;
	LogDistribution* nbLoopsDistribution;
	
	MeanDistribution* nbLoopsDegreeDistribution;
	
	int nbLoops;
	#endif
	
	#ifdef _GSCC_STAT_MODE
	// Indique les parents des vertex: 
	// 1ere coordonnees: le vertex
	// 2eme coordonnees: les suivants
	bool edgeVisited[NB_ASSEMBLIES][NB_ASSEMBLIES];

	vector<Node*> holdStack;

	int low[NB_ASSEMBLIES];

	int dfnum;

	vector<Node*> tabGSCCNodes;
	vector<int> nbStrongComponents;

	
	// Indique le parent de chaque vertex:
	int parents[NB_ASSEMBLIES];
	#endif
#endif

	// Correspond à Q dans (Brandes,2001)
	deque<Node*> tabNodes;
	int marked[NB_ASSEMBLIES];

public:

	LoopStater();
	LoopStater(IndexedObject* io);

	virtual ~LoopStater();

	void initCounters();

	void initTabNodes();
	void addNode(Node* newNode);
	
	Node* getLastNode();
	void deleteLastNode();
	
	Node* getFirstNode();
	void deleteFirstNode();
	
	std::vector<Node*> scanLoopCluster(Node* fromNode, Node* toNode);
	
#ifdef _NETWORK_STAT_MODE
	#ifdef _CENTRALITY_STAT_MODE
	void initPathCounters();
	void initBetweennessCounters();
	
		#ifdef _EDGE_BETWEENNESS_STAT_MODE
	void initBetweenness();
		#endif
	void initBreadthFirstPostLinks(Node* curNode);
	
	void statBreadthFirstPostLinks(Node* postNode);
	void computeBetweenness(Node* postNode);

	void initEfficiencyCounters();
	void computeEfficiency(Node* postNode);
	#endif

	#ifdef _SMALL_WORLD_STAT_MODE
	void initClusteringCoeffCounters();
	void statSmallWorld(Node* postNode);
	void computeNetworkClusteringCoeff();
	#endif

	#ifdef _MOTIF_STAT_MODE
	void initMotifsCounters();
	void statMotifs(Node* postNode);
	#endif

	#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE
	void initInputPathCounters();

	void statBreadthFirstInputNode(Node* inputNode);
	void statBreadthFirstOutputNode(Node* outputNode);
	void statReachedInputAssemblies(Node* inputNode);
	void statReachedOutputAssemblies(Node* outputNode);
	#endif

	#ifdef _DEGREE_STAT_MODE
	void initDegreeCounters();
	void statDegreeDistribution(Node* postNode);
	
		#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE
	void statInputNodeDegree(Node* inputNode);
	void statOutputNodeDegree(Node* outputNode);
		#endif
	#endif
	
	#ifdef _LOOP_STAT_MODE
	void initLoopCounters();
	void statDepthFirstPostLinks(Node* postNode);
	void statLoop(Node* postNode);
	void computeNbLoops();
	void computeNbLoopsDegree(Node* postNode);
	#endif
	
	#ifdef _GSCC_STAT_MODE
	void initGSCC();
	bool isInGSCC(Node* postNode);
	void initDFS(Node* rootNode);
	void statGSCC(Node* postNode);
	#endif
#endif
	
	void trace();
	void graph();
	
};

#endif

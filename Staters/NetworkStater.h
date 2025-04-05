// NetworkStater.h

#ifndef _NETWORK_STATER_H
#define _NETWORK_STATER_H

class NetworkStater;
#include "../EDNetwork/EDNetwork.h"

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

#include "../Handlers/Stater.h"

#include "../Handlers/Counter.h"
#include "../Handlers/Accumulater.h"
#include "../Files/AccuDataFile.h"

#include "../Handlers/MeanDistribution.h"
#include "../Handlers/MeanLogDistribution.h"

#include "../Handlers/OngoingDistribution.h"
#include "../Handlers/OngoingMeanDistribution.h"
#include "../Handlers/OngoingCumulatedDistribution.h"

#include "../Handlers/OngoingMeanLogDistribution.h"

#include "../Files/DistributionDataFile.h"
#include "../Files/OngoingDistributionDataFile.h"

#include "../Files/OngoingDistributionGnuplotFile.h"

#include "AssemblyStater.h"
#include "InputAssemblyStater.h"
#include "OutputAssemblyStater.h"

#include "LinkedClusterStater.h"

class NetworkStater;
#include "../EDNetwork/EDNetwork.h"

/******************************************************************************************************************************************/
/****************************************************** Classe NetworkStater *************************************************************/
/******************************************************************************************************************************************/

#ifdef _CLUSTER_STAT_MODE
	#ifdef _LINKED_CLUSTER_STAT_MODE
class NetworkStater : public LinkedClusterStater
	#else
class NetworkStater : public ClusterStater
	#endif
#else
class NetworkStater : public AssemblyStater
#endif
{
#ifdef _NETWORK_STAT_MODE

	#ifdef _TOPOLOGY_STAT_MODE
	DataFile* topologyMatrixFile;
	int** connectivityMatrix;
	#endif
	
	#ifdef _LINK_TO_INPUT_STAT_MODE
	DataFile* linkToInputFile;
	int* linkToInputVector;
	#endif
	
	#ifdef _LINK_TO_OUTPUT_STAT_MODE
	DataFile* linkToOutputFile;
	int* linkToOutputVector;
	#endif
	
	#ifdef _MATRIX_CLUSTERS_STAT_MODE
	DataFile* clusterMatrixFile;
	int** clusterMatrix;
	#endif
	
	#ifdef _CENTRALITY_STAT_MODE

		#ifdef _CLUSTER_STAT_MODE

	
		// Pour les assemblées
	// Calcul de centralité
			#ifdef _3D_ONGOING_STAT_MODE
	OngoingMeanLogDistribution* ongoingAssemblyCentralBetweennessDistribution;
	OngoingDistributionDataFile* ongoingAssemblyCentralBetweennessDistributionFile;
			#endif
	Accumulater ongoingAssemblyCentralBetweenness[NB_PROJECTIONS_EACH_CHROMOSOME];
	AccuDataFile* ongoingAssemblyCentralBetweennessFile;

	// Centralite de noeuds
			#ifdef _3D_ONGOING_STAT_MODE
	OngoingMeanLogDistribution* ongoingAssemblyBetweennessDistribution;
	OngoingDistributionDataFile* ongoingAssemblyBetweennessDistributionFile;
			#endif
			
	Accumulater ongoingAssemblyBetweenness[NB_PROJECTIONS_EACH_CHROMOSOME];
	AccuDataFile* ongoingAssemblyBetweennessFile;
	
			
			#ifdef _EDGE_BETWEENNESS_STAT_MODE
	// Intermediarite de liens
	Accumulater ongoingAssemblyMaxEdgeBetweenness[NB_PROJECTIONS_EACH_CHROMOSOME];
	AccuDataFile* ongoingAssemblyMaxEdgeBetweennessFile;
	
				#ifdef _3D_ONGOING_STAT_MODE
	OngoingMeanLogDistribution* ongoingAssemblyEdgeBetweennessDistribution;
	OngoingDistributionDataFile* ongoingAssemblyEdgeBetweennessDistributionFile;
				#endif
			#endif
			
	// Efficacité du réseau au fur et à mesure de la suppression
			#ifdef _3D_ONGOING_STAT_MODE
	OngoingMeanLogDistribution* ongoingAssemblyGlobalEfficiencyDistribution;
	OngoingDistributionDataFile* ongoingAssemblyGlobalEfficiencyDistributionFile;
			#endif
				
	Accumulater ongoingAssemblyGlobalEfficiency[NB_PROJECTIONS_EACH_CHROMOSOME];
	AccuDataFile* ongoingAssemblyGlobalEfficiencyFile;
	
			#ifdef _3D_ONGOING_STAT_MODE
	OngoingMeanLogDistribution* ongoingAssemblyLocalEfficiencyDistribution;
	OngoingDistributionDataFile* ongoingAssemblyLocalEfficiencyDistributionFile;
			#endif
				
	Accumulater ongoingAssemblyLocalEfficiency[NB_PROJECTIONS_EACH_CHROMOSOME];
	AccuDataFile* ongoingAssemblyLocalEfficiencyFile;
	
	// ShortPath
			#ifdef _3D_ONGOING_STAT_MODE
	OngoingMeanDistribution* ongoingAssemblyShortPathLengthDistribution;
	OngoingDistributionDataFile* ongoingAssemblyShortPathLengthDistributionFile;
			#endif
				
			// Pour les clusters
	// Modularité
	double ongoingClusterModularity[NB_PROJECTIONS_EACH_CHROMOSOME];
	DataFile* ongoingClusterModularityFile;
	
	// Repartition de l'efficacité des clusters
			#ifdef _3D_ONGOING_STAT_MODE
	OngoingMeanLogDistribution* ongoingClusterEfficiencyDistribution;
	OngoingDistributionDataFile* ongoingClusterEfficiencyDistributionFile;
			#endif
				
	Accumulater ongoingClusterEfficiency[NB_PROJECTIONS_EACH_CHROMOSOME];
	AccuDataFile* ongoingClusterEfficiencyFile;

			#ifdef _3D_ONGOING_STAT_MODE
	OngoingMeanLogDistribution* ongoingClusterRealEfficiencyDistribution;
	OngoingDistributionDataFile* ongoingClusterRealEfficiencyDistributionFile;
			#endif
				
	Accumulater ongoingClusterRealEfficiency[NB_PROJECTIONS_EACH_CHROMOSOME];
	AccuDataFile* ongoingClusterRealEfficiencyFile;

	// Nombre de clusters
	Accumulater ongoingNbClusters[NB_PROJECTIONS_EACH_CHROMOSOME];
	AccuDataFile* ongoingNbClustersFile;

	// Taille du cluster max
	Accumulater ongoingMaxClusterSizes[NB_PROJECTIONS_EACH_CHROMOSOME];
	AccuDataFile* ongoingMaxClusterSizesFile;

	// Repartition de la taille des clusters au cours du processus de clusterisation
			#ifdef _3D_ONGOING_STAT_MODE
	OngoingMeanDistribution* ongoingClusterSizeDistribution;
	OngoingDistributionDataFile* ongoingClusterSizeDistributionFile;
			#endif
				
			#ifdef _LINKED_CLUSTER_STAT_MODE
	// Repartition des clusters dans les composants
	Accumulater ongoingInDC[NB_PROJECTIONS_EACH_CHROMOSOME];
	AccuDataFile* ongoingInDCFile;

	Accumulater ongoingInGOUT[NB_PROJECTIONS_EACH_CHROMOSOME];
	AccuDataFile* ongoingInGOUTFile;

	Accumulater ongoingInGIN[NB_PROJECTIONS_EACH_CHROMOSOME];
	AccuDataFile* ongoingInGINFile;

	Accumulater ongoingInGSCC[NB_PROJECTIONS_EACH_CHROMOSOME];
	AccuDataFile* ongoingInGSCCFile;
	
				#ifdef _CLUSTER_CENTRALITY_STAT_MODE
		// Pour les linkedClusters
	// Calcul de centralité
					#ifdef _3D_ONGOING_STAT_MODE
	OngoingMeanLogDistribution* ongoingLinkedClusterCentralBetweennessDistribution;
	OngoingDistributionDataFile* ongoingLinkedClusterCentralBetweennessDistributionFile;
					#endif
					
	Accumulater ongoingLinkedClusterCentralBetweenness[NB_PROJECTIONS_EACH_CHROMOSOME];
	AccuDataFile* ongoingLinkedClusterCentralBetweennessFile;

	// Centralite de noeuds
					#ifdef _3D_ONGOING_STAT_MODE
	OngoingMeanLogDistribution* ongoingLinkedClusterBetweennessDistribution;
	OngoingDistributionDataFile* ongoingLinkedClusterBetweennessDistributionFile;
					#endif
					
	Accumulater ongoingLinkedClusterBetweenness[NB_PROJECTIONS_EACH_CHROMOSOME];
	AccuDataFile* ongoingLinkedClusterBetweennessFile;
	
					#ifdef _EDGE_BETWEENNESS_STAT_MODE
	// Intermediarite de liens
	Accumulater ongoingLinkedClusterMaxEdgeBetweenness[NB_PROJECTIONS_EACH_CHROMOSOME];
	AccuDataFile* ongoingLinkedClusterMaxEdgeBetweennessFile;
	
						#ifdef _3D_ONGOING_STAT_MODE
	OngoingMeanLogDistribution* ongoingLinkedClusterEdgeBetweennessDistribution;
	OngoingDistributionDataFile* ongoingLinkedClusterEdgeBetweennessDistributionFile;
						#endif
					#endif
					
	// Efficacité du réseau au fur et à mesure de la suppression
					#ifdef _3D_ONGOING_STAT_MODE
	OngoingMeanLogDistribution* ongoingLinkedClusterGlobalEfficiencyDistribution;
	OngoingDistributionDataFile* ongoingLinkedClusterGlobalEfficiencyDistributionFile;
					#endif
					
	Accumulater ongoingLinkedClusterGlobalEfficiency[NB_PROJECTIONS_EACH_CHROMOSOME];
	AccuDataFile* ongoingLinkedClusterGlobalEfficiencyFile;
	
					#ifdef _3D_ONGOING_STAT_MODE
	OngoingMeanLogDistribution* ongoingLinkedClusterLocalEfficiencyDistribution;
	OngoingDistributionDataFile* ongoingLinkedClusterLocalEfficiencyDistributionFile;
					#endif
					
	Accumulater ongoingLinkedClusterLocalEfficiency[NB_PROJECTIONS_EACH_CHROMOSOME];
	AccuDataFile* ongoingLinkedClusterLocalEfficiencyFile;
	
	// ShortPath
					#ifdef _3D_ONGOING_STAT_MODE
	OngoingMeanDistribution* ongoingLinkedClusterShortPathLengthDistribution;
	OngoingDistributionDataFile* ongoingLinkedClusterShortPathLengthDistributionFile;
					#endif
				#endif
			#endif
	
			#ifdef _NETWORK_CLUSTER_STAT_MODE
				#ifdef _LINKED_CLUSTER_STAT_MODE
	// Repartition des clusters dans les composants pour le réseau à la fin du processus de clusterisation
	Accumulater* networkInDC;
	Accumulater* networkInGOUT;
	Accumulater* networkInGIN;
	Accumulater* networkInGSCC;
	AccuDataFile* networkComponentRepartitionFile;
				#endif

	// Repartition de la taille des clusters pour le réseau à la fin du processus de clusterisation
	MeanDistribution* networkClusterSizeDistribution;
	DistributionDataFile* networkClusterSizeDistributionFile;

	// Repartition de l'efficacité des clusters pour le réseau à la fin du processus de clusterisation
	Accumulater* networkClusterEfficiency;
	AccuDataFile* networkClusterEfficiencyFile;
	
	MeanLogDistribution* networkClusterEfficiencyDistribution;
	DistributionDataFile* networkClusterEfficiencyDistributionFile;
	
	Accumulater* networkClusterRealEfficiency;
	AccuDataFile* networkClusterRealEfficiencyFile;

	MeanLogDistribution* networkClusterRealEfficiencyDistribution;
	DistributionDataFile* networkClusterRealEfficiencyDistributionFile;
	
				#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
	// Nombre de suppression de liens pour atteindre le réseau optimal
	int curMaxModularityProjectionIndex;

	Accumulater* maxModularityProjectionIndex;
	AccuDataFile* maxModularityProjectionIndexFile;

	// Modularité maximale
	double curMaxModularity;

	Accumulater* maxModularity;
	AccuDataFile* maxModularityFile;
					#ifdef _LINKED_CLUSTER_STAT_MODE
	// Repartition des clusters dans les composants pour le réseau optimal
	Accumulater* maxModularityInDC;
	Accumulater* maxModularityInGOUT;
	Accumulater* maxModularityInGIN;
	Accumulater* maxModularityInGSCC;
	AccuDataFile* maxModularityComponentRepartitionFile;
					#endif

	// Repartition de la taille des clusters pour le réseau optimal
	MeanDistribution* maxModularityClusterSizeDistribution;
	DistributionDataFile* maxModularityClusterSizeDistributionFile;

	// Repartition de l'efficacité des clusters pour le réseau optimal
	Accumulater* maxModularityClusterEfficiency;
	AccuDataFile* maxModularityClusterEfficiencyFile;
	
	MeanLogDistribution* maxModularityClusterEfficiencyDistribution;
	DistributionDataFile* maxModularityClusterEfficiencyDistributionFile;
	
	Accumulater* maxModularityClusterRealEfficiency;
	AccuDataFile* maxModularityClusterRealEfficiencyFile;
	
	MeanLogDistribution* maxModularityClusterRealEfficiencyDistribution;
	DistributionDataFile* maxModularityClusterRealEfficiencyDistributionFile;
	
				#endif
			#endif
			
		#else
		
	// Calcul d'intermediarité pour les assemblées
	Accumulater meanAssemblyBetweennessRepartition[NB_ASSEMBLIES];
			
	AccuDataFile* meanAssemblyBetweennessRepartitionFile;

	Accumulater* meanAssemblyBetweenness;
	AccuDataFile* meanAssemblyBetweennessFile;
	
	MeanLogDistribution* meanAssemblyBetweennessDistribution;
	DistributionDataFile* meanAssemblyBetweennessDistributionFile;

	// Calcul de centralité
	Accumulater meanAssemblyCentralBetweennessRepartition[NB_ASSEMBLIES];
	
	AccuDataFile* meanAssemblyCentralBetweennessRepartitionFile;

	Accumulater* meanAssemblyCentralBetweenness;
	AccuDataFile* meanAssemblyCentralBetweennessFile;

	MeanLogDistribution* meanAssemblyCentralBetweennessDistribution;
	DistributionDataFile* meanAssemblyCentralBetweennessDistributionFile;
			
			#ifdef _EDGE_BETWEENNESS_STAT_MODE

	// Calcul d'intermediarité pour les liens
	Accumulater meanEdgeBetweennessRepartition[NB_ASSEMBLIES][NB_ASSEMBLIES];
				
	DistributionDataFile* meanEdgeBetweennessRepartitionFile;

	MeanLogDistribution* meanEdgeBetweennessDistribution;
	DistributionDataFile* meanEdgeBetweennessDistributionFile;
	
			#endif
	
	// Repartition des short paths
	Accumulater meanAssemblyShortPathRepartition[NB_ASSEMBLIES];
	AccuDataFile* meanAssemblyShortPathRepartitionFile;

	Accumulater meanAssemblyNoShortPathRepartition[NB_ASSEMBLIES];
	AccuDataFile* meanAssemblyNoShortPathRepartitionFile;

	// Distribution des short paths
	MeanDistribution* meanAssemblyNbShortPathDistribution;
	DistributionDataFile* meanAssemblyNbShortPathDistributionFile;

	// Calcul d'efficacite pour les assemblées
	Accumulater meanAssemblyGlobalEfficiencyRepartition[NB_ASSEMBLIES];
	AccuDataFile* meanAssemblyGlobalEfficiencyRepartitionFile;

	Accumulater meanAssemblyLocalEfficiencyRepartition[NB_ASSEMBLIES];
	AccuDataFile* meanAssemblyLocalEfficiencyRepartitionFile;

	MeanLogDistribution* meanAssemblyGlobalEfficiencyDistribution;
	DistributionDataFile* meanAssemblyGlobalEfficiencyDistributionFile;
	
	MeanLogDistribution* meanAssemblyLocalEfficiencyDistribution;
	DistributionDataFile* meanAssemblyLocalEfficiencyDistributionFile;
	
	Accumulater* meanAssemblyGlobalEfficiency;
	AccuDataFile* meanAssemblyGlobalEfficiencyFile;

	Accumulater* meanAssemblyLocalEfficiency;
	AccuDataFile* meanAssemblyLocalEfficiencyFile;
	
		#endif
	#endif

	// Loops
	#ifdef _LOOP_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
		// Assembly
	// Distribution
			#ifdef _3D_ONGOING_STAT_MODE
	OngoingMeanLogDistribution* ongoingAssemblyNbLoopsDistribution;
	OngoingDistributionDataFile* ongoingAssemblyNbLoopsDistributionFile;
			#endif
			
	Accumulater ongoingAssemblyNbLoops[NB_PROJECTIONS_EACH_CHROMOSOME];
	AccuDataFile* ongoingAssemblyNbLoopsFile;
		
	// Degree
			#ifdef _3D_ONGOING_STAT_MODE
	OngoingCumulatedDistribution* ongoingAssemblyNbLoopsDegreeDistribution;
	OngoingDistributionDataFile* ongoingAssemblyNbLoopsDegreeDistributionFile;

	// Taille des boucles
	OngoingMeanDistribution* ongoingAssemblyLoopSizeDistribution;
	OngoingDistributionDataFile* ongoingAssemblyLoopSizeDistributionFile;
	
		// Cluster
	OngoingMeanDistribution* ongoingClusterLoopSizeDistribution;
	OngoingDistributionDataFile* ongoingClusterLoopSizeDistributionFile;
			#endif
			
	Accumulater ongoingClusterNbLoops[NB_PROJECTIONS_EACH_CHROMOSOME];
	AccuDataFile* ongoingClusterNbLoopsFile;

			#ifdef _NETWORK_CLUSTER_STAT_MODE
	/*
	// Degree
	CumulatedDistribution* networkClusterNbLoopsDegreeDistribution;
	DistributionDataFile* networkClusterNbLoopsDegreeDistributionFile;
	*/
	// LoopSize
	MeanDistribution* networkClusterLoopSizeDistribution;
	DistributionDataFile* networkClusterLoopSizeDistributionFile;

				#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
	MeanDistribution* maxModularityClusterLoopSizeDistribution;
	DistributionDataFile* maxModularityClusterLoopSizeDistributionFile;
				#endif
				
			#endif
		#else
	// LoopSize
	MeanDistribution*  meanAssemblyLoopSizeDistribution;
	DistributionDataFile* meanAssemblyLoopSizeDistributionFile;
	
	// Nb Loops
	Accumulater meanAssemblyNbLoopsRepartition[NB_ASSEMBLIES];
	AccuDataFile* meanAssemblyNbLoopsRepartitionFile;
	
	MeanLogDistribution* meanAssemblyNbLoopsDistribution;
	DistributionDataFile* meanAssemblyNbLoopsDistributionFile;
	
	// Degree
	CumulatedDistribution* meanAssemblyNbLoopsDegreeDistribution;
	DistributionDataFile* meanAssemblyNbLoopsDegreeDistributionFile;

		#endif
	#endif
	
	// Small World
	#ifdef _SMALL_WORLD_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE

		// Assembly
	// Distribution
			#ifdef _3D_ONGOING_STAT_MODE
	OngoingMeanLogDistribution* ongoingAssemblyClusteringCoeffDistribution;
	OngoingDistributionDataFile* ongoingAssemblyClusteringCoeffDistributionFile;
	
	// Degree
	OngoingCumulatedDistribution* ongoingAssemblyClusteringCoeffDegreeDistribution;
	OngoingDistributionDataFile* ongoingAssemblyClusteringCoeffDegreeDistributionFile;
			#endif
			
		// Cluster
	// Distribution
	Accumulater ongoingClusterInternalDensity[NB_PROJECTIONS_EACH_CHROMOSOME];
	AccuDataFile* ongoingClusterInternalDensityFile;

	// Degree
	Accumulater ongoingRealClusterInternalDensity[NB_PROJECTIONS_EACH_CHROMOSOME];
	AccuDataFile* ongoingRealClusterInternalDensityFile;
	
			#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	// Distribution
				#ifdef _3D_ONGOING_STAT_MODE
	OngoingMeanLogDistribution* ongoingLinkedClusterClusteringCoeffDistribution;
	OngoingDistributionDataFile* ongoingLinkedClusterClusteringCoeffDistributionFile;
	
	// Degree
	OngoingCumulatedDistribution* ongoingLinkedClusterClusteringCoeffDegreeDistribution;
	OngoingDistributionDataFile* ongoingLinkedClusterClusteringCoeffDegreeDistributionFile;
				#endif
			#endif
			
			#ifdef _NETWORK_CLUSTER_STAT_MODE
	Accumulater* networkClusterInternalDensity;
	AccuDataFile* networkClusterInternalDensityFile;
	
	Accumulater* networkRealClusterInternalDensity;
	AccuDataFile* networkRealClusterInternalDensityFile;
				
				#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	// Distribution
	MeanLogDistribution* networkLinkedClusterClusteringCoeffDistribution;
	DistributionDataFile* networkLinkedClusterClusteringCoeffDistributionFile;
	
	// Degree
	CumulatedDistribution* networkLinkedClusterClusteringCoeffDegreeDistribution;
	DistributionDataFile* networkLinkedClusterClusteringCoeffDegreeDistributionFile;
				#endif
				
				#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
	Accumulater* maxModularityClusterInternalDensity;
	AccuDataFile* maxModularityClusterInternalDensityFile;
	
	Accumulater* maxModularityRealClusterInternalDensity;
	AccuDataFile* maxModularityRealClusterInternalDensityFile;	
	
					#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	// Distribution
	MeanLogDistribution* maxModularityLinkedClusterClusteringCoeffDistribution;
	DistributionDataFile* maxModularityLinkedClusterClusteringCoeffDistributionFile;
	
	// Degree
	CumulatedDistribution* maxModularityLinkedClusterClusteringCoeffDegreeDistribution;
	DistributionDataFile* maxModularityLinkedClusterClusteringCoeffDegreeDistributionFile;
					#endif		
				#endif
			#endif
		#else
	// Distribution
	MeanLogDistribution* meanClusteringCoeffDistribution;
	DistributionDataFile* meanClusteringCoeffDistributionFile;

	// Degree
	CumulatedDistribution* meanClusteringCoeffDegreeDistribution;
	DistributionDataFile* meanClusteringCoeffDegreeDistributionFile;
	
	// Repartition
	Accumulater meanClusteringCoeffRepartition[NB_ASSEMBLIES];
	AccuDataFile* meanClusteringCoeffRepartitionFile;

	// Network
	Accumulater* meanClusteringCoeff;
	AccuDataFile* meanClusteringCoeffFile;
		#endif
	#endif

	#ifdef _MOTIF_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
			
			#ifdef _3D_ONGOING_STAT_MODE
	Accumulater ongoingAssemblyBinodeMotifs[NB_PROJECTIONS_EACH_CHROMOSOME];
	AccuDataFile* ongoingAssemblyBinodeMotifsFile;
			
	OngoingMeanDistribution* ongoingAssemblyTrinodeMotifsDistribution;
	OngoingDistributionDataFile* ongoingAssemblyTrinodeMotifsDistributionFile;
			#endif
			
			#ifdef _CLUSTER_CENTRALITY_STAT_MODE
				#ifdef _3D_ONGOING_STAT_MODE
	OngoingMeanDistribution* ongoingLinkedClusterTrinodeMotifsDistribution;
	OngoingDistributionDataFile* ongoingLinkedClusterTrinodeMotifsDistributionFile;
				#endif
			#endif
			
			#ifdef _INTERNAL_MOTIF_STAT_MODE
				
				#ifdef _3D_ONGOING_STAT_MODE
	Accumulater ongoingClusterInternalBinodeMotifs[NB_PROJECTIONS_EACH_CHROMOSOME];
	AccuDataFile* ongoingClusterInternalBinodeMotifsFile;
	
	OngoingMeanDistribution* ongoingClusterInternalTrinodeMotifsDistribution;
	OngoingDistributionDataFile* ongoingClusterInternalTrinodeMotifsDistributionFile;
				#endif
				
				#ifdef _NETWORK_CLUSTER_STAT_MODE
	Accumulater* networkClusterInternalBinodeMotifs;
	AccuDataFile* networkClusterInternalBinodeMotifsFile;

	MeanDistribution* networkClusterInternalTrinodeMotifsDistribution;
	DistributionDataFile* networkClusterInternalTrinodeMotifsDistributionFile;
					
					#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	MeanDistribution* networkLinkedClusterTrinodeMotifsDistribution;
	DistributionDataFile* networkLinkedClusterTrinodeMotifsDistributionFile;
					#endif
			
					#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
	Accumulater* maxModularityClusterInternalBinodeMotifs;
	AccuDataFile* maxModularityClusterInternalBinodeMotifsFile;
	
	MeanDistribution* maxModularityClusterInternalTrinodeMotifsDistribution;
	DistributionDataFile* maxModularityClusterInternalTrinodeMotifsDistributionFile;
	
						#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	
	MeanDistribution* maxModularityLinkedClusterTrinodeMotifsDistribution;
	DistributionDataFile* maxModularityLinkedClusterTrinodeMotifsDistributionFile;
						#endif
					#endif
				#endif
			#endif
		#else
	Accumulater* meanBinodeMotifs;
	AccuDataFile* meanBinodeMotifsFile;

	MeanDistribution* meanTrinodeMotifsDistribution;
	DistributionDataFile* meanTrinodeMotifsDistributionFile;
		#endif
	#endif
	
	#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE
		
		#ifdef _CLUSTER_STAT_MODE
			
			#ifdef _3D_ONGOING_STAT_MODE
	OngoingMeanDistribution* ongoingAssemblyReachedByInputDistribution;
	OngoingDistributionDataFile* ongoingAssemblyReachedByInputDistributionFile;
	
	OngoingMeanDistribution* ongoingAssemblyReachedByOutputDistribution;
	OngoingDistributionDataFile* ongoingAssemblyReachedByOutputDistributionFile;
	
	OngoingMeanDistribution* ongoingAssemblyInputOutputPathLengthDistribution;
	OngoingDistributionDataFile* ongoingAssemblyInputOutputPathLengthDistributionFile;

	OngoingMeanDistribution* ongoingAssemblyPathToInputDistribution;
	OngoingDistributionDataFile* ongoingAssemblyPathToInputDistributionFile;
	
	OngoingMeanDistribution* ongoingAssemblyPathToOutputDistribution;
	OngoingDistributionDataFile* ongoingAssemblyPathToOutputDistributionFile;
			#endif
		#else
	MeanDistribution* meanReachedByInputDistribution;
	DistributionDataFile* meanReachedByInputDistributionFile;

	MeanDistribution* meanReachedByOutputDistribution;
	DistributionDataFile* meanReachedByOutputDistributionFile;

	MeanDistribution* meanPathToInputDistribution;
	DistributionDataFile* meanPathToInputDistributionFile;

	MeanDistribution* meanPathToOutputDistribution;
	DistributionDataFile* meanPathToOutputDistributionFile;
	
	MeanDistribution* meanInputOutputPathLengthDistribution;
	DistributionDataFile* meanInputOutputPathLengthDistributionFile;
		#endif
	#endif

	
	// Nb total de degres
	#ifdef _DEGREE_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
	// Degree
			
			#ifdef _3D_ONGOING_STAT_MODE
	OngoingMeanDistribution* ongoingAssemblyDegreeDistribution;
	OngoingDistributionDataFile* ongoingAssemblyDegreeDistributionFile;

	OngoingMeanDistribution* ongoingAssemblyPreDegreeDistribution;
	OngoingDistributionDataFile* ongoingAssemblyPreDegreeDistributionFile;

	OngoingMeanDistribution* ongoingAssemblyPostDegreeDistribution;
	OngoingDistributionDataFile* ongoingAssemblyPostDegreeDistributionFile;

	// Voisins
	OngoingCumulatedDistribution* ongoingAssemblyNearestNeighboursDegreeDistribution;
	OngoingDistributionDataFile* ongoingAssemblyNearestNeighboursDegreeDistributionFile;
			#endif
			
			#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE	
	// Input-Output
				
			#ifdef _3D_ONGOING_STAT_MODE
	OngoingMeanDistribution* ongoingInputAssemblyDegreeDistribution;
	OngoingDistributionDataFile* ongoingInputAssemblyDegreeDistributionFile;
	
	OngoingMeanDistribution* ongoingOutputAssemblyDegreeDistribution;
	OngoingDistributionDataFile* ongoingOutputAssemblyDegreeDistributionFile;
	
	OngoingCumulatedDistribution* ongoingInputAssemblyNearestNeighboursDegreeDistribution;
	OngoingDistributionDataFile* ongoingInputAssemblyNearestNeighboursDegreeDistributionFile;
	
	OngoingCumulatedDistribution* ongoingOutputAssemblyNearestNeighboursDegreeDistribution;
	OngoingDistributionDataFile* ongoingOutputAssemblyNearestNeighboursDegreeDistributionFile;
				#endif
			#endif
			
			#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	// Degree
				#ifdef _3D_ONGOING_STAT_MODE
	OngoingMeanDistribution* ongoingLinkedClusterDegreeDistribution;
	OngoingDistributionDataFile* ongoingLinkedClusterDegreeDistributionFile;
	
	OngoingMeanDistribution* ongoingLinkedClusterPreDegreeDistribution;
	OngoingDistributionDataFile* ongoingLinkedClusterPreDegreeDistributionFile;
	
	OngoingMeanDistribution* ongoingLinkedClusterPostDegreeDistribution;
	OngoingDistributionDataFile* ongoingLinkedClusterPostDegreeDistributionFile;

	// Voisins
	OngoingCumulatedDistribution* ongoingLinkedClusterNearestNeighboursDegreeDistribution;
	OngoingDistributionDataFile* ongoingLinkedClusterNearestNeighboursDegreeDistributionFile;
				#endif
				
				#ifdef _NETWORK_CLUSTER_STAT_MODE
	// Degree
	MeanDistribution* networkLinkedClusterDegreeDistribution;
	DistributionDataFile* networkLinkedClusterDegreeDistributionFile;
	
	MeanDistribution* networkLinkedClusterPreDegreeDistribution;
	DistributionDataFile* networkLinkedClusterPreDegreeDistributionFile;
	
	MeanDistribution* networkLinkedClusterPostDegreeDistribution;
	DistributionDataFile* networkLinkedClusterPostDegreeDistributionFile;

	// Voisins
	CumulatedDistribution* networkLinkedClusterNearestNeighboursDegreeDistribution;
	DistributionDataFile* networkLinkedClusterNearestNeighboursDegreeDistributionFile;
					
					#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
	// Degree
	MeanDistribution* maxModularityLinkedClusterDegreeDistribution;
	DistributionDataFile* maxModularityLinkedClusterDegreeDistributionFile;
	
	MeanDistribution* maxModularityLinkedClusterPreDegreeDistribution;
	DistributionDataFile* maxModularityLinkedClusterPreDegreeDistributionFile;
	
	MeanDistribution* maxModularityLinkedClusterPostDegreeDistribution;
	DistributionDataFile* maxModularityLinkedClusterPostDegreeDistributionFile;

	// Voisins
	CumulatedDistribution* maxModularityLinkedClusterNearestNeighboursDegreeDistribution;
	DistributionDataFile* maxModularityLinkedClusterNearestNeighboursDegreeDistributionFile;
					#endif
				#endif
			#endif
		#else
	// Degree
	MeanDistribution* meanDegreeDistribution;
	DistributionDataFile* meanDegreeDistributionFile;

	MeanDistribution* meanPreDegreeDistribution;
	DistributionDataFile* meanPreDegreeDistributionFile;
	
	MeanDistribution* meanPostDegreeDistribution;
	DistributionDataFile* meanPostDegreeDistributionFile;

	// Voisins
	CumulatedDistribution* meanNearestNeighboursDegreeDistribution;
	DistributionDataFile* meanNearestNeighboursDegreeDistributionFile;

			#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE
	// Input-Output
	MeanDistribution* meanInputAssemblyDegreeDistribution;
	DistributionDataFile* meanInputAssemblyDegreeDistributionFile;
	
	MeanDistribution* meanOutputAssemblyDegreeDistribution;
	DistributionDataFile* meanOutputAssemblyDegreeDistributionFile;
	
	CumulatedDistribution* meanInputAssemblyNearestNeighboursDegreeDistribution;
	DistributionDataFile* meanInputAssemblyNearestNeighboursDegreeDistributionFile;
	
	CumulatedDistribution* meanOutputAssemblyNearestNeighboursDegreeDistribution;
	DistributionDataFile* meanOutputAssemblyNearestNeighboursDegreeDistributionFile;
			#endif
		#endif
	#endif

	#ifdef _GSCC_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
	// Composante fortement connexe
	Accumulater ongoingNbGSCCNodes[NB_PROJECTIONS_EACH_CHROMOSOME];
	AccuDataFile* ongoingNbGSCCNodesFile;

			#ifdef _3D_ONGOING_STAT_MODE
	OngoingMeanDistribution* ongoingSCComponentSizeDistribution;
	OngoingDistributionDataFile* ongoingSCComponentSizeDistributionFile;
			#endif
			
	// Composante géante
	Accumulater ongoingMaxSCComponentSize[NB_PROJECTIONS_EACH_CHROMOSOME];
	AccuDataFile* ongoingMaxSCComponentSizeFile;

			#ifdef _3D_ONGOING_STAT_MODE
	OngoingDistribution* ongoingMaxSCComponentSizeDistribution;
	OngoingDistributionDataFile* ongoingMaxSCComponentSizeDistributionFile;
			#endif
			
	// Calcul diametre
	/*
	MeanDistribution* meanAssemblyDiameterSizeDistribution;
	DistributionDataFile* meanAssemblyDiameterSizeDistributionFile;
	*/
		#else
	Accumulater* meanNbGSCCNodes;
	AccuDataFile* meanNbGSCCNodesFile;

	MeanDistribution* meanSCComponentSizeDistribution;
	DistributionDataFile* meanSCComponentSizeDistributionFile;

	Accumulater* meanMaxSCComponentSize;
	AccuDataFile* meanMaxSCComponentSizeFile;

	Distribution* meanMaxSCComponentSizeDistribution;
	DistributionDataFile* meanMaxSCComponentSizeDistributionFile;
	
			#ifdef _INPUT_OUTPUT_GSCC_STAT_MODE	
	MeanDistribution* meanInputSCComponentSizeDistribution;
	DistributionDataFile* meanInputSCComponentSizeDistributionFile;

	MeanDistribution* meanOutputSCComponentSizeDistribution;
	DistributionDataFile* meanOutputSCComponentSizeDistributionFile;
	
	Accumulater meanInputSCCFractionRepartition[NB_INPUT_ASSEMBLIES];
	AccuDataFile* meanInputSCCFractionRepartitionFile;
	
	Accumulater meanOutputSCCFractionRepartition[NB_OUTPUT_ASSEMBLIES];
	AccuDataFile* meanOutputSCCFractionRepartitionFile;
			#endif
		#endif
	#endif

	#ifdef _PROJECTION_STAT_MODE
	Accumulater* meanProjections;
	
	AccuDataFile* meanProjectionsFile;

	// Excit/Inhib
	Accumulater* meanExcitProjections;
	Accumulater* meanInhibProjections;

	AccuDataFile* meanExcitProjectionsFile;
	AccuDataFile* meanInhibProjectionsFile;

	// Input
	Accumulater* meanExcitInputProjections;
	Accumulater* meanInhibInputProjections;

	AccuDataFile* meanExcitInputProjectionsFile;
	AccuDataFile* meanInhibInputProjectionsFile;

	// Output
	Accumulater* meanExcitOutputProjections;
	Accumulater* meanInhibOutputProjections;

	AccuDataFile* meanExcitOutputProjectionsFile;
	AccuDataFile* meanInhibOutputProjectionsFile;

	// Self
	Accumulater* meanExcitSelfProjections;
	Accumulater* meanInhibSelfProjections;

	AccuDataFile* meanExcitSelfProjectionsFile;
	AccuDataFile* meanInhibSelfProjectionsFile;
	#endif
	
	#ifdef _INPUT_OUTPUT_CLUSTER_STAT_MODE
//		#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
	MeanDistribution* maxModularityInputClusterSizeDistribution;
	DistributionDataFile* maxModularityInputClusterSizeDistributionFile;

	MeanDistribution* maxModularityOutputClusterSizeDistribution;
	DistributionDataFile* maxModularityOutputClusterSizeDistributionFile;
	
	Accumulater maxModularityInputClusterFractionRepartition[NB_INPUT_ASSEMBLIES];
	AccuDataFile* maxModularityInputClusterFractionRepartitionFile;
	
	Accumulater maxModularityOutputClusterFractionRepartition[NB_OUTPUT_ASSEMBLIES];
	AccuDataFile* maxModularityOutputClusterFractionRepartitionFile;
//		#endif
	#endif
	
	// Graphs
	OngoingDistributionGnuplotFile* meanGnuplotProjectionsFile;

#endif
	void openGrapher();
	void closeGrapher();
	void runGrapher();

	void openTracer();
	void closeTracer();

public:

	NetworkStater();
	virtual ~NetworkStater();

	void flushAccumulaters();
	void initAccumulaters();

#ifdef _NETWORK_STAT_MODE

	#ifdef _TOPOLOGY_STAT_MODE
	void initConnectivityMatrix();
	void statConnectivity(EDAssembly* curAssembly);
	#endif
	
	#ifdef _LINK_TO_INPUT_STAT_MODE
	void initLinkToInputVector();
	void statInputConnectivity(EDAssembly* curAssembly);
	#endif
	
	#ifdef _LINK_TO_OUTPUT_STAT_MODE
	void initLinkToOutputVector();
	void statOutputConnectivity(EDAssembly* curAssembly);
	#endif
	
	#ifdef _CENTRALITY_STAT_MODE

		#ifdef _CLUSTER_STAT_MODE
			#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
	void initCurMaxModularity();
			#endif
	void computeModularity(EDNetwork* curEDNetwork);

	void statClusters(int projectionIndex);

	void statAssemblyBetweenness(int projectionIndex);
	
			
			#ifdef _EDGE_BETWEENNESS_STAT_MODE
	void statAssemblyEdgeBetweenness(int projectionIndex);
			#endif
			
	void statAssemblyEfficiency(int projectionIndex);
	void statAssemblyShortPathLength(int projectionIndex);

			#ifdef _NETWORK_CLUSTER_STAT_MODE

				#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
	bool checkOptimalClusters(int projectionIndex);
	void statOptimalClusters();
					
					#ifdef _MATRIX_CLUSTERS_STAT_MODE
	void initClusterMatrix();
	void printClusterMatrix();				
	void statMatrixClusters(Cluster* curCluster);
					#endif
				#endif

	void statNetworkClusters();
			#endif
			
			#ifdef _LOOP_STAT_MODE
	void statAssemblyLoops(int projectionIndex);
			#endif
			
			#ifdef _SMALL_WORLD_STAT_MODE
	void statAssemblyClusteringCoeff(int projectionIndex);
			#endif
			
			#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE
	void statAssemblyInputOutputLinks(int projectionIndex);
			#endif
			
			#ifdef _MOTIF_STAT_MODE
	void statAssemblyMotifs(int projectionIndex);
			#endif
			
			#ifdef _DEGREE_STAT_MODE
	void statAssemblyDegree(int projectionIndex);
			#endif
			
			#ifdef _GSCC_STAT_MODE
	void statAssemblyGSCC(int projectionIndex);
			#endif
		#endif
	#endif

	void stat();
	void trace();
	void graph();

#endif
};

#endif

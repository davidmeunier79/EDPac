// NetworkStater.cc

// Local Includes
#include "NetworkStater.h"

/****************************************************************************************************************************************/
/*************************************************** Methodes de la classe NetworkStater ************************************************/
/****************************************************************************************************************************************/

NetworkStater::NetworkStater()
{
#ifdef _NETWORK_STAT_MODE
	
	#ifdef _TOPOLOGY_STAT_MODE
	cerr << "Initing topologyMatrixFile" << endl;
	
	topologyMatrixFile = new DataFile();
	
	cerr << "Initing Connectivity Matrix" << endl;
	
	connectivityMatrix = new int* [NB_ASSEMBLIES];
	
	for (int i=0;i<NB_ASSEMBLIES;i++)
	{
		connectivityMatrix[i] = new int[NB_ASSEMBLIES];
	}
	
	#endif
	
	#ifdef _LINK_TO_INPUT_STAT_MODE
	cerr << "Initing linkToInputFile" << endl;
	
	linkToInputFile = new DataFile();
	
	cerr << "Initing linkToInput Vector" << endl;
	
	linkToInputVector = new int[NB_ASSEMBLIES];
	
	#endif
		
	#ifdef _LINK_TO_OUTPUT_STAT_MODE
	cerr << "Initing linkToOutputFile" << endl;
	
	linkToOutputFile = new DataFile();
	
	cerr << "Initing linkToInput Vector" << endl;
	
	linkToOutputVector = new int[NB_ASSEMBLIES];
	
	#endif
	
	#ifdef _MATRIX_CLUSTERS_STAT_MODE
	cerr << "Initing clusterMatrixFile" << endl;
	
	clusterMatrixFile = new DataFile();
	
	cerr << "Initing cluster Matrix" << endl;
	
	clusterMatrix = new int* [NB_ASSEMBLIES];
	
	for (int i=0;i<NB_ASSEMBLIES;i++)
	{
		clusterMatrix[i] = new int[NB_ASSEMBLIES];
	}
	#endif
	
	#ifdef _CENTRALITY_STAT_MODE

		#ifdef _CLUSTER_STAT_MODE
		
		// Assemblees

	// Calcul de centralité
			#ifdef _3D_ONGOING_STAT_MODE
	ongoingAssemblyCentralBetweennessDistribution = new OngoingMeanLogDistribution(NB_PROJECTIONS_EACH_CHROMOSOME,-4,0,5);
	ongoingAssemblyCentralBetweennessDistributionFile = new OngoingDistributionDataFile();
			#endif
			
	ongoingAssemblyCentralBetweennessFile = new AccuDataFile();

	// Centralite de noeuds
			#ifdef _3D_ONGOING_STAT_MODE
	ongoingAssemblyBetweennessDistribution = new OngoingMeanLogDistribution(NB_PROJECTIONS_EACH_CHROMOSOME,0,4,5);
	ongoingAssemblyBetweennessDistributionFile = new OngoingDistributionDataFile();
			#endif
			
	ongoingAssemblyBetweennessFile = new AccuDataFile();
	
			#ifdef _EDGE_BETWEENNESS_STAT_MODE

	// Distribution intermédiarite de liens
	ongoingAssemblyMaxEdgeBetweennessFile = new AccuDataFile();

				#ifdef _3D_ONGOING_STAT_MODE
	ongoingAssemblyEdgeBetweennessDistribution = new OngoingMeanLogDistribution(NB_PROJECTIONS_EACH_CHROMOSOME,0,4,5);
	ongoingAssemblyEdgeBetweennessDistributionFile = new OngoingDistributionDataFile();
				#endif
			#endif
		
	// Efficacité du réseau au fur et à mesure de la suppression
			#ifdef _3D_ONGOING_STAT_MODE
	ongoingAssemblyGlobalEfficiencyDistribution = new OngoingMeanLogDistribution(NB_PROJECTIONS_EACH_CHROMOSOME,-2,0,5);
	ongoingAssemblyGlobalEfficiencyDistributionFile = new OngoingDistributionDataFile();
			#endif
			
	ongoingAssemblyGlobalEfficiencyFile = new AccuDataFile();
	
			#ifdef _3D_ONGOING_STAT_MODE
	ongoingAssemblyLocalEfficiencyDistribution = new OngoingMeanLogDistribution(NB_PROJECTIONS_EACH_CHROMOSOME,-2,0,5);
	ongoingAssemblyLocalEfficiencyDistributionFile = new OngoingDistributionDataFile();
			#endif
			
	ongoingAssemblyLocalEfficiencyFile = new AccuDataFile();
	
	// ShortPath
			#ifdef _3D_ONGOING_STAT_MODE
	ongoingAssemblyShortPathLengthDistribution = new OngoingMeanDistribution(NB_PROJECTIONS_EACH_CHROMOSOME,30);
	ongoingAssemblyShortPathLengthDistributionFile = new OngoingDistributionDataFile();
			#endif
			
		// Clusters
	// Nombre de clusters
	ongoingNbClustersFile = new AccuDataFile();

	// Taille du cluster max
	ongoingMaxClusterSizesFile = new AccuDataFile();
	
	// Distribution de la taille des clusters au cours du processus de clusterisation
			#ifdef _3D_ONGOING_STAT_MODE
	ongoingClusterSizeDistribution = new OngoingMeanDistribution(NB_PROJECTIONS_EACH_CHROMOSOME,NB_ASSEMBLIES+NB_INPUT_ASSEMBLIES+NB_OUTPUT_ASSEMBLIES);
	ongoingClusterSizeDistributionFile = new OngoingDistributionDataFile();
			#endif
			
	ongoingClusterModularityFile = new DataFile();
	
	// Distribution de l'efficacité des clusters
			#ifdef _3D_ONGOING_STAT_MODE
	ongoingClusterEfficiencyDistribution = new OngoingMeanLogDistribution(NB_PROJECTIONS_EACH_CHROMOSOME,-2,0,5);
	ongoingClusterEfficiencyDistributionFile = new OngoingDistributionDataFile();
			#endif
			
	ongoingClusterEfficiencyFile = new AccuDataFile();
	
			#ifdef _3D_ONGOING_STAT_MODE
	ongoingClusterRealEfficiencyDistribution = new OngoingMeanLogDistribution(NB_PROJECTIONS_EACH_CHROMOSOME,-2,0,5);
	ongoingClusterRealEfficiencyDistributionFile = new OngoingDistributionDataFile();
			#endif
			
	ongoingClusterRealEfficiencyFile = new AccuDataFile();
	
	
			#ifdef _LINKED_CLUSTER_STAT_MODE
	// Distribution des clusters dans les composants
	ongoingInDCFile = new AccuDataFile();
	ongoingInGOUTFile = new AccuDataFile();
	ongoingInGINFile = new AccuDataFile();
	ongoingInGSCCFile = new AccuDataFile();
				
				#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	// Calcul de centralité
					#ifdef _3D_ONGOING_STAT_MODE
	ongoingLinkedClusterBetweennessDistribution = new OngoingMeanLogDistribution(NB_PROJECTIONS_EACH_CHROMOSOME,0,4,5);
	ongoingLinkedClusterBetweennessDistributionFile = new OngoingDistributionDataFile();
					#endif
					
	ongoingLinkedClusterBetweennessFile = new AccuDataFile();

					#ifdef _3D_ONGOING_STAT_MODE
	ongoingLinkedClusterCentralBetweennessDistribution = new OngoingMeanLogDistribution(NB_PROJECTIONS_EACH_CHROMOSOME,-4,0,5);
	ongoingLinkedClusterCentralBetweennessDistributionFile = new OngoingDistributionDataFile();
					#endif
					
	ongoingLinkedClusterCentralBetweennessFile = new AccuDataFile();
					
					#ifdef _EDGE_BETWEENNESS_STAT_MODE

	// Distribution intermédiarite de liens
	ongoingLinkedClusterMaxEdgeBetweennessFile = new AccuDataFile();

						#ifdef _3D_ONGOING_STAT_MODE
	ongoingLinkedClusterEdgeBetweennessDistribution = new OngoingMeanLogDistribution(NB_PROJECTIONS_EACH_CHROMOSOME,0,4,5);
	ongoingLinkedClusterEdgeBetweennessDistributionFile = new OngoingDistributionDataFile();
						#endif
					#endif
					
	// Efficacité du réseau au fur et à mesure de la suppression
					#ifdef _3D_ONGOING_STAT_MODE
	ongoingLinkedClusterGlobalEfficiencyDistribution = new OngoingMeanLogDistribution(NB_PROJECTIONS_EACH_CHROMOSOME,-2,0,5);
	ongoingLinkedClusterGlobalEfficiencyDistributionFile = new OngoingDistributionDataFile();
					#endif
					
	ongoingLinkedClusterGlobalEfficiencyFile = new AccuDataFile();

					#ifdef _3D_ONGOING_STAT_MODE
	ongoingLinkedClusterLocalEfficiencyDistribution = new OngoingMeanLogDistribution(NB_PROJECTIONS_EACH_CHROMOSOME,-2,0,5);
	ongoingLinkedClusterLocalEfficiencyDistributionFile = new OngoingDistributionDataFile();
					#endif
					
	ongoingLinkedClusterLocalEfficiencyFile = new AccuDataFile();
	
	// ShortPath
					#ifdef _3D_ONGOING_STAT_MODE
	ongoingLinkedClusterShortPathLengthDistribution = new OngoingMeanDistribution(NB_PROJECTIONS_EACH_CHROMOSOME,30);
	ongoingLinkedClusterShortPathLengthDistributionFile = new OngoingDistributionDataFile();
					#endif
				#endif
			#endif

			#ifdef _NETWORK_CLUSTER_STAT_MODE
				#ifdef _LINKED_CLUSTER_STAT_MODE
	// Repartition des clusters dans les composants pour le réseau à la fin du processus de clusterisation
	networkInDC = new Accumulater();
	networkInGOUT = new Accumulater();
	networkInGIN = new Accumulater();
	networkInGSCC = new Accumulater();
	networkComponentRepartitionFile = new AccuDataFile();
				#endif

	// Distribution de la taille des clusters pour le réseau à la fin du processus de clusterisation
	networkClusterSizeDistribution = new MeanDistribution(NB_ASSEMBLIES+NB_INPUT_ASSEMBLIES+NB_OUTPUT_ASSEMBLIES);
	networkClusterSizeDistributionFile = new DistributionDataFile();
				
	// Repartition de l'efficacité des clusters pour le réseau à la fin du processus de clusterisation
	networkClusterEfficiency = new Accumulater();
	networkClusterEfficiencyFile = new AccuDataFile();

	networkClusterEfficiencyDistribution = new MeanLogDistribution(-2,0,5);
	networkClusterEfficiencyDistributionFile = new DistributionDataFile();
				
	networkClusterRealEfficiency= new Accumulater();
	networkClusterRealEfficiencyFile = new AccuDataFile();

	networkClusterRealEfficiencyDistribution = new MeanLogDistribution(-2,0,5);
	networkClusterRealEfficiencyDistributionFile = new DistributionDataFile();
				
				#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
	// Nombre de suppression de liens pour atteindre le réseau optimal
	maxModularityProjectionIndex = new Accumulater();
	maxModularityProjectionIndexFile = new AccuDataFile();

	// Modularité maximale
	maxModularity = new Accumulater();
	maxModularityFile = new AccuDataFile();
					#ifdef _LINKED_CLUSTER_STAT_MODE
	// Repartition des clusters dans les composants pour le réseau optimal
	maxModularityInDC = new Accumulater();
	maxModularityInGOUT = new Accumulater();
	maxModularityInGIN = new Accumulater();
	maxModularityInGSCC = new Accumulater();
	maxModularityComponentRepartitionFile = new AccuDataFile();
					#endif

	// Distribution de la taille des clusters pour le réseau optimal
	maxModularityClusterSizeDistribution = new MeanDistribution(NB_ASSEMBLIES+NB_INPUT_ASSEMBLIES+NB_OUTPUT_ASSEMBLIES);
	maxModularityClusterSizeDistributionFile = new DistributionDataFile();
	
	// Distribution de l'efficacité des clusters pour le réseau optimal
	maxModularityClusterEfficiency = new Accumulater();
	maxModularityClusterEfficiencyFile = new AccuDataFile();

	maxModularityClusterEfficiencyDistribution = new MeanLogDistribution(-2,0,5);
	maxModularityClusterEfficiencyDistributionFile = new DistributionDataFile();
	
	maxModularityClusterRealEfficiency = new Accumulater();
	maxModularityClusterRealEfficiencyFile = new AccuDataFile();
	
	maxModularityClusterRealEfficiencyDistribution = new MeanLogDistribution(-2,0,5);
	maxModularityClusterRealEfficiencyDistributionFile = new DistributionDataFile();
	
				#endif
			#endif
		#else
	
	// Calcul d'intermediarité
	meanAssemblyBetweennessRepartitionFile = new AccuDataFile();

	meanAssemblyBetweenness = new Accumulater();
	meanAssemblyBetweennessFile = new AccuDataFile();

	meanAssemblyBetweennessDistribution = new MeanLogDistribution(0,4,5);
	meanAssemblyBetweennessDistributionFile = new DistributionDataFile();

	// Calcul de centralité
	meanAssemblyCentralBetweennessRepartitionFile = new AccuDataFile();
	
	meanAssemblyCentralBetweenness = new Accumulater();
	meanAssemblyCentralBetweennessFile = new AccuDataFile();

	meanAssemblyCentralBetweennessDistribution = new MeanLogDistribution(-4,0,5);
	meanAssemblyCentralBetweennessDistributionFile = new DistributionDataFile();
	
			#ifdef _EDGE_BETWEENNESS_STAT_MODE

	// Calcul d'intermediarité pour les liens
	meanEdgeBetweennessRepartitionFile = new DistributionDataFile();

	//meanEdgeBetweennessDistribution = new MeanLogDistribution(-1,4,5);
	meanEdgeBetweennessDistribution = new MeanLogDistribution(0,4,5);
	meanEdgeBetweennessDistributionFile = new DistributionDataFile();
	
			#endif
			
	// Repartition des short paths
	meanAssemblyShortPathRepartitionFile = new AccuDataFile();
	meanAssemblyNoShortPathRepartitionFile = new AccuDataFile();

	meanAssemblyNbShortPathDistribution = new MeanDistribution(NB_ASSEMBLIES+NB_INPUT_ASSEMBLIES+NB_OUTPUT_ASSEMBLIES);
	meanAssemblyNbShortPathDistributionFile = new DistributionDataFile();

	// Calcul d'efficacite
	meanAssemblyLocalEfficiencyRepartitionFile = new AccuDataFile();
	meanAssemblyGlobalEfficiencyRepartitionFile = new AccuDataFile();

	meanAssemblyGlobalEfficiencyDistribution = new MeanLogDistribution(-2,0,5);
	meanAssemblyGlobalEfficiencyDistributionFile = new DistributionDataFile();
	
	meanAssemblyLocalEfficiencyDistribution = new MeanLogDistribution(-2,0,5);
	meanAssemblyLocalEfficiencyDistributionFile = new DistributionDataFile();
	
	meanAssemblyGlobalEfficiency = new Accumulater();
	meanAssemblyGlobalEfficiencyFile = new AccuDataFile();

	meanAssemblyLocalEfficiency = new Accumulater();
	meanAssemblyLocalEfficiencyFile = new AccuDataFile();
		#endif
	#endif

	// Loop
	#ifdef _LOOP_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
		// Assembly
	// NbLoops
			#ifdef _3D_ONGOING_STAT_MODE
	ongoingAssemblyNbLoopsDistribution = new OngoingMeanLogDistribution(NB_PROJECTIONS_EACH_CHROMOSOME,0,4,10);
	ongoingAssemblyNbLoopsDistributionFile = new OngoingDistributionDataFile();
			#endif
			
	ongoingAssemblyNbLoopsFile = new AccuDataFile();

	// Degree
			#ifdef _3D_ONGOING_STAT_MODE
	ongoingAssemblyNbLoopsDegreeDistribution = new OngoingCumulatedDistribution(NB_PROJECTIONS_EACH_CHROMOSOME,NB_ASSEMBLIES);
	ongoingAssemblyNbLoopsDegreeDistributionFile = new OngoingDistributionDataFile();
			
	// LoopSize
	ongoingAssemblyLoopSizeDistribution = new OngoingMeanDistribution(NB_PROJECTIONS_EACH_CHROMOSOME,NB_ASSEMBLIES);
	ongoingAssemblyLoopSizeDistributionFile = new OngoingDistributionDataFile();
			
		// Cluster
	ongoingClusterLoopSizeDistribution = new OngoingMeanDistribution(NB_PROJECTIONS_EACH_CHROMOSOME,NB_ASSEMBLIES);
	ongoingClusterLoopSizeDistributionFile = new OngoingDistributionDataFile();
			#endif
			
	ongoingClusterNbLoopsFile = new AccuDataFile();

			#ifdef _NETWORK_CLUSTER_STAT_MODE
	/*
	// Degree
	networkClusterNbLoopsDegreeDistribution = new CumulatedDistribution(NB_PROJECTIONS_EACH_CHROMOSOME,NB_ASSEMBLIES);
	networkClusterNbLoopsDegreeDistributionFile = new DistributionDataFile();
	*/
	// Taille des boucles
	networkClusterLoopSizeDistribution = new MeanDistribution(NB_ASSEMBLIES);
	networkClusterLoopSizeDistributionFile = new DistributionDataFile();

				#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
	maxModularityClusterLoopSizeDistribution = new MeanDistribution(NB_ASSEMBLIES);
	maxModularityClusterLoopSizeDistributionFile = new DistributionDataFile();
				#endif
				
			#endif

		#else
	meanAssemblyLoopSizeDistribution = new MeanDistribution(NB_ASSEMBLIES);
	meanAssemblyLoopSizeDistributionFile = new DistributionDataFile();
	
	// Nb Loops
	meanAssemblyNbLoopsRepartitionFile = new AccuDataFile();

	meanAssemblyNbLoopsDistribution = new MeanLogDistribution(0,4,10);
	meanAssemblyNbLoopsDistributionFile = new DistributionDataFile();
	
	// Degree
	meanAssemblyNbLoopsDegreeDistribution = new CumulatedDistribution(NB_ASSEMBLIES);
	meanAssemblyNbLoopsDegreeDistributionFile = new DistributionDataFile();

		#endif
	#endif
	
	// Small World
	#ifdef _SMALL_WORLD_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
	// Degree
			#ifdef _3D_ONGOING_STAT_MODE
	ongoingAssemblyClusteringCoeffDegreeDistribution = new OngoingCumulatedDistribution(NB_PROJECTIONS_EACH_CHROMOSOME,NB_ASSEMBLIES);
	ongoingAssemblyClusteringCoeffDegreeDistributionFile = new OngoingDistributionDataFile();
	
	ongoingAssemblyClusteringCoeffDistribution = new OngoingMeanLogDistribution(NB_PROJECTIONS_EACH_CHROMOSOME,-2,0,10);
	ongoingAssemblyClusteringCoeffDistributionFile = new OngoingDistributionDataFile();
			#endif
			
	// Cluster
	ongoingClusterInternalDensityFile = new AccuDataFile();
	ongoingRealClusterInternalDensityFile = new AccuDataFile();
	
			#ifdef _CLUSTER_CENTRALITY_STAT_MODE
				#ifdef _3D_ONGOING_STAT_MODE
	ongoingLinkedClusterClusteringCoeffDegreeDistribution = new OngoingCumulatedDistribution(NB_PROJECTIONS_EACH_CHROMOSOME,NB_ASSEMBLIES);
	ongoingLinkedClusterClusteringCoeffDegreeDistributionFile = new OngoingDistributionDataFile();
	
	ongoingLinkedClusterClusteringCoeffDistribution = new OngoingMeanLogDistribution(NB_PROJECTIONS_EACH_CHROMOSOME,-2,0,10);
	ongoingLinkedClusterClusteringCoeffDistributionFile = new OngoingDistributionDataFile();
				#endif
			#endif
			
			#ifdef _NETWORK_CLUSTER_STAT_MODE
	networkClusterInternalDensity = new Accumulater();
	networkClusterInternalDensityFile = new AccuDataFile();

	networkRealClusterInternalDensity = new Accumulater();
	networkRealClusterInternalDensityFile = new AccuDataFile();
	
				#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	networkLinkedClusterClusteringCoeffDegreeDistribution = new CumulatedDistribution(NB_ASSEMBLIES);
	networkLinkedClusterClusteringCoeffDegreeDistributionFile = new DistributionDataFile();
	
	networkLinkedClusterClusteringCoeffDistribution = new MeanLogDistribution(-2,0,10);
	networkLinkedClusterClusteringCoeffDistributionFile = new DistributionDataFile();
				#endif
				
				#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
	maxModularityClusterInternalDensity = new Accumulater();
	maxModularityClusterInternalDensityFile = new AccuDataFile();

	maxModularityRealClusterInternalDensity = new Accumulater();
	maxModularityRealClusterInternalDensityFile = new AccuDataFile();	
					
					#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	maxModularityLinkedClusterClusteringCoeffDegreeDistribution = new CumulatedDistribution(NB_ASSEMBLIES);
	maxModularityLinkedClusterClusteringCoeffDegreeDistributionFile = new DistributionDataFile();
	
	maxModularityLinkedClusterClusteringCoeffDistribution = new MeanLogDistribution(-2,0,10);
	maxModularityLinkedClusterClusteringCoeffDistributionFile = new DistributionDataFile();
					#endif
				#endif
			#endif
		#else
	// Distribution
	meanClusteringCoeffDistribution = new MeanLogDistribution(-2,0,10);
	meanClusteringCoeffDistributionFile = new DistributionDataFile();
	
	// Degree
	meanClusteringCoeffDegreeDistribution = new CumulatedDistribution(NB_ASSEMBLIES);
	meanClusteringCoeffDegreeDistributionFile = new DistributionDataFile();
	
	// Repartition
	meanClusteringCoeffRepartitionFile = new AccuDataFile();
	
	meanClusteringCoeff = new Accumulater();
	meanClusteringCoeffFile = new AccuDataFile();
	
		#endif
	#endif

	#ifdef _MOTIF_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
			#ifdef _3D_ONGOING_STAT_MODE
	ongoingAssemblyBinodeMotifsFile = new AccuDataFile();
	
	ongoingAssemblyTrinodeMotifsDistribution = new OngoingMeanDistribution(NB_PROJECTIONS_EACH_CHROMOSOME,14);
	ongoingAssemblyTrinodeMotifsDistributionFile = new OngoingDistributionDataFile();
			#endif
			
			#ifdef _CLUSTER_CENTRALITY_STAT_MODE
				#ifdef _3D_ONGOING_STAT_MODE
	ongoingLinkedClusterTrinodeMotifsDistribution = new OngoingMeanDistribution(NB_PROJECTIONS_EACH_CHROMOSOME,14);
	ongoingLinkedClusterTrinodeMotifsDistributionFile = new OngoingDistributionDataFile();
				#endif
			#endif
			
			#ifdef _INTERNAL_MOTIF_STAT_MODE
				#ifdef _3D_ONGOING_STAT_MODE
	ongoingClusterInternalBinodeMotifsFile = new AccuDataFile();
	
	ongoingClusterInternalTrinodeMotifsDistribution = new OngoingMeanDistribution(NB_PROJECTIONS_EACH_CHROMOSOME,14);
	ongoingClusterInternalTrinodeMotifsDistributionFile = new OngoingDistributionDataFile();
				#endif
				
				#ifdef _NETWORK_CLUSTER_STAT_MODE
	networkClusterInternalBinodeMotifs = new Accumulater();
	networkClusterInternalBinodeMotifsFile = new AccuDataFile();
	
	networkClusterInternalTrinodeMotifsDistribution = new MeanDistribution(14);
	networkClusterInternalTrinodeMotifsDistributionFile = new DistributionDataFile();
					
					#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	networkLinkedClusterTrinodeMotifsDistribution = new MeanDistribution(14);
	networkLinkedClusterTrinodeMotifsDistributionFile = new DistributionDataFile();
					#endif
					
					#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
	maxModularityClusterInternalBinodeMotifs = new Accumulater();
	maxModularityClusterInternalBinodeMotifsFile = new AccuDataFile();
	
	maxModularityClusterInternalTrinodeMotifsDistribution = new MeanDistribution(14);
	maxModularityClusterInternalTrinodeMotifsDistributionFile = new DistributionDataFile();
						
						#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	maxModularityLinkedClusterTrinodeMotifsDistribution = new MeanDistribution(14);
	maxModularityLinkedClusterTrinodeMotifsDistributionFile = new DistributionDataFile();
						#endif
					#endif
				#endif
			#endif
		#else
	meanBinodeMotifs = new Accumulater();
	meanBinodeMotifsFile = new AccuDataFile();

	meanTrinodeMotifsDistribution = new MeanDistribution(14);
	meanTrinodeMotifsDistributionFile = new DistributionDataFile();
		#endif
	#endif
	
	#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
			#ifdef _3D_ONGOING_STAT_MODE
	ongoingAssemblyReachedByInputDistribution = new OngoingMeanDistribution(NB_PROJECTIONS_EACH_CHROMOSOME,NB_INPUT_ASSEMBLIES);
	ongoingAssemblyReachedByInputDistributionFile = new OngoingDistributionDataFile();
	
	ongoingAssemblyReachedByOutputDistribution = new OngoingMeanDistribution(NB_PROJECTIONS_EACH_CHROMOSOME,NB_OUTPUT_ASSEMBLIES);
	ongoingAssemblyReachedByOutputDistributionFile = new OngoingDistributionDataFile();
	
	ongoingAssemblyInputOutputPathLengthDistribution = new OngoingMeanDistribution(NB_PROJECTIONS_EACH_CHROMOSOME,NB_ASSEMBLIES);
	ongoingAssemblyInputOutputPathLengthDistributionFile = new OngoingDistributionDataFile();
	
	ongoingAssemblyPathToInputDistribution = new OngoingMeanDistribution(NB_PROJECTIONS_EACH_CHROMOSOME,NB_ASSEMBLIES);
	ongoingAssemblyPathToInputDistributionFile = new OngoingDistributionDataFile();
	
	ongoingAssemblyPathToOutputDistribution = new OngoingMeanDistribution(NB_PROJECTIONS_EACH_CHROMOSOME,NB_ASSEMBLIES);
	ongoingAssemblyPathToOutputDistributionFile = new OngoingDistributionDataFile();
			#endif
		#else
		
	meanReachedByInputDistribution = new MeanDistribution(NB_INPUT_ASSEMBLIES);
	meanReachedByInputDistributionFile = new DistributionDataFile();
	
	meanReachedByOutputDistribution = new MeanDistribution(NB_OUTPUT_ASSEMBLIES);
	meanReachedByOutputDistributionFile = new DistributionDataFile();

	meanPathToInputDistribution = new MeanDistribution(NB_ASSEMBLIES);
	meanPathToInputDistributionFile = new DistributionDataFile();

	meanPathToOutputDistribution = new MeanDistribution(NB_ASSEMBLIES);
	meanPathToOutputDistributionFile = new DistributionDataFile();
	
	meanInputOutputPathLengthDistribution = new MeanDistribution(NB_ASSEMBLIES);
	meanInputOutputPathLengthDistributionFile = new DistributionDataFile();
		#endif
	#endif
	
	#ifdef _DEGREE_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
			#ifdef _3D_ONGOING_STAT_MODE
	ongoingAssemblyDegreeDistribution = new OngoingMeanDistribution(NB_PROJECTIONS_EACH_CHROMOSOME,NB_ASSEMBLIES);
	ongoingAssemblyDegreeDistributionFile = new OngoingDistributionDataFile();
	
	ongoingAssemblyPreDegreeDistribution = new OngoingMeanDistribution(NB_PROJECTIONS_EACH_CHROMOSOME,NB_ASSEMBLIES);
	ongoingAssemblyPreDegreeDistributionFile = new OngoingDistributionDataFile();
	
	ongoingAssemblyPostDegreeDistribution = new OngoingMeanDistribution(NB_PROJECTIONS_EACH_CHROMOSOME,NB_ASSEMBLIES);
	ongoingAssemblyPostDegreeDistributionFile = new OngoingDistributionDataFile();
	
	// Voisins
	ongoingAssemblyNearestNeighboursDegreeDistribution = new OngoingCumulatedDistribution(NB_PROJECTIONS_EACH_CHROMOSOME,NB_ASSEMBLIES);
	ongoingAssemblyNearestNeighboursDegreeDistributionFile = new OngoingDistributionDataFile();
			#endif
	
			#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE
	// In/Out
				#ifdef _3D_ONGOING_STAT_MODE
	ongoingInputAssemblyDegreeDistribution = new OngoingMeanDistribution(NB_PROJECTIONS_EACH_CHROMOSOME,NB_INPUT_ASSEMBLIES);
	ongoingInputAssemblyDegreeDistributionFile = new OngoingDistributionDataFile();
	
	ongoingOutputAssemblyDegreeDistribution = new OngoingMeanDistribution(NB_PROJECTIONS_EACH_CHROMOSOME,NB_OUTPUT_ASSEMBLIES);
	ongoingOutputAssemblyDegreeDistributionFile = new OngoingDistributionDataFile();
	
	// Voisins
	ongoingInputAssemblyNearestNeighboursDegreeDistribution = new OngoingCumulatedDistribution(NB_PROJECTIONS_EACH_CHROMOSOME,NB_INPUT_ASSEMBLIES);
	ongoingInputAssemblyNearestNeighboursDegreeDistributionFile = new OngoingDistributionDataFile();

	ongoingOutputAssemblyNearestNeighboursDegreeDistribution = new OngoingCumulatedDistribution(NB_PROJECTIONS_EACH_CHROMOSOME,NB_OUTPUT_ASSEMBLIES);
	ongoingOutputAssemblyNearestNeighboursDegreeDistributionFile = new OngoingDistributionDataFile();
				#endif
			#endif
		
			#ifdef _CLUSTER_CENTRALITY_STAT_MODE
				#ifdef _3D_ONGOING_STAT_MODE
	ongoingLinkedClusterDegreeDistribution = new OngoingMeanDistribution(NB_PROJECTIONS_EACH_CHROMOSOME,NB_ASSEMBLIES);
	ongoingLinkedClusterDegreeDistributionFile = new OngoingDistributionDataFile();
	
	ongoingLinkedClusterPreDegreeDistribution = new OngoingMeanDistribution(NB_PROJECTIONS_EACH_CHROMOSOME,NB_ASSEMBLIES);
	ongoingLinkedClusterPreDegreeDistributionFile = new OngoingDistributionDataFile();
	
	ongoingLinkedClusterPostDegreeDistribution = new OngoingMeanDistribution(NB_PROJECTIONS_EACH_CHROMOSOME,NB_ASSEMBLIES);
	ongoingLinkedClusterPostDegreeDistributionFile = new OngoingDistributionDataFile();
	
	// Voisins
	ongoingLinkedClusterNearestNeighboursDegreeDistribution = new OngoingCumulatedDistribution(NB_PROJECTIONS_EACH_CHROMOSOME,NB_ASSEMBLIES);
	ongoingLinkedClusterNearestNeighboursDegreeDistributionFile = new OngoingDistributionDataFile();
				#endif
				
				#ifdef _NETWORK_CLUSTER_STAT_MODE
	networkLinkedClusterDegreeDistribution = new MeanDistribution(NB_ASSEMBLIES);
	networkLinkedClusterDegreeDistributionFile = new DistributionDataFile();
	
	networkLinkedClusterPreDegreeDistribution = new MeanDistribution(NB_ASSEMBLIES);
	networkLinkedClusterPreDegreeDistributionFile = new DistributionDataFile();
	
	networkLinkedClusterPostDegreeDistribution = new MeanDistribution(NB_ASSEMBLIES);
	networkLinkedClusterPostDegreeDistributionFile = new DistributionDataFile();
	
	networkLinkedClusterNearestNeighboursDegreeDistribution = new CumulatedDistribution(NB_ASSEMBLIES);
	networkLinkedClusterNearestNeighboursDegreeDistributionFile = new DistributionDataFile();
					
					#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
	maxModularityLinkedClusterDegreeDistribution = new MeanDistribution(NB_ASSEMBLIES);
	maxModularityLinkedClusterDegreeDistributionFile = new DistributionDataFile();
	
	maxModularityLinkedClusterPreDegreeDistribution = new MeanDistribution(NB_ASSEMBLIES);
	maxModularityLinkedClusterPreDegreeDistributionFile = new DistributionDataFile();
	
	maxModularityLinkedClusterPostDegreeDistribution = new MeanDistribution(NB_ASSEMBLIES);
	maxModularityLinkedClusterPostDegreeDistributionFile = new DistributionDataFile();
	
	maxModularityLinkedClusterNearestNeighboursDegreeDistribution = new CumulatedDistribution(NB_ASSEMBLIES);
	maxModularityLinkedClusterNearestNeighboursDegreeDistributionFile = new DistributionDataFile();
	
					#endif
				#endif
			#endif
		#else
	meanDegreeDistribution = new MeanDistribution(NB_ASSEMBLIES);
	meanDegreeDistributionFile = new DistributionDataFile();
	
	meanPreDegreeDistribution = new MeanDistribution(NB_ASSEMBLIES);
	meanPreDegreeDistributionFile = new DistributionDataFile();
	
	meanPostDegreeDistribution = new MeanDistribution(NB_ASSEMBLIES);
	meanPostDegreeDistributionFile = new DistributionDataFile();

	meanNearestNeighboursDegreeDistribution = new CumulatedDistribution(NB_ASSEMBLIES);
	meanNearestNeighboursDegreeDistributionFile = new DistributionDataFile();
	
	// In/Out
	
			#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE
	meanInputAssemblyDegreeDistribution = new MeanDistribution(NB_INPUT_ASSEMBLIES);
	meanInputAssemblyDegreeDistributionFile = new DistributionDataFile();
	
	meanOutputAssemblyDegreeDistribution = new MeanDistribution(NB_OUTPUT_ASSEMBLIES);
	meanOutputAssemblyDegreeDistributionFile = new DistributionDataFile();

	meanInputAssemblyNearestNeighboursDegreeDistribution = new CumulatedDistribution(NB_INPUT_ASSEMBLIES);
	meanInputAssemblyNearestNeighboursDegreeDistributionFile = new DistributionDataFile();
	
	meanOutputAssemblyNearestNeighboursDegreeDistribution = new CumulatedDistribution(NB_OUTPUT_ASSEMBLIES);
	meanOutputAssemblyNearestNeighboursDegreeDistributionFile = new DistributionDataFile();
			#endif
		#endif
	#endif

	#ifdef _GSCC_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
	ongoingNbGSCCNodesFile = new AccuDataFile();
			#ifdef _3D_ONGOING_STAT_MODE
	ongoingSCComponentSizeDistribution = new OngoingMeanDistribution(NB_PROJECTIONS_EACH_CHROMOSOME,NB_ASSEMBLIES);
	ongoingSCComponentSizeDistributionFile = new OngoingDistributionDataFile();
			#endif
			
	ongoingMaxSCComponentSizeFile = new AccuDataFile();
			
			#ifdef _3D_ONGOING_STAT_MODE
	ongoingMaxSCComponentSizeDistribution = new OngoingDistribution(NB_PROJECTIONS_EACH_CHROMOSOME,NB_ASSEMBLIES);
	ongoingMaxSCComponentSizeDistributionFile = new OngoingDistributionDataFile();
			#endif
	/*
	meanAssemblyDiameterSizeDistribution = new MeanDistribution(NB_ASSEMBLIES);
	meanAssemblyDiameterSizeDistributionFile = new DistributionDataFile();
	*/
		#else
	meanNbGSCCNodes = new Accumulater();
	meanNbGSCCNodesFile = new AccuDataFile();

	meanSCComponentSizeDistribution = new MeanDistribution(NB_ASSEMBLIES);
	meanSCComponentSizeDistributionFile = new DistributionDataFile();

	meanMaxSCComponentSize = new Accumulater();
	meanMaxSCComponentSizeFile = new AccuDataFile();


	meanMaxSCComponentSizeDistribution = new Distribution(NB_ASSEMBLIES);
	meanMaxSCComponentSizeDistributionFile = new DistributionDataFile();
	
	
			#ifdef _INPUT_OUTPUT_GSCC_STAT_MODE		
	meanInputSCComponentSizeDistribution = new MeanDistribution(NB_ASSEMBLIES);
	meanInputSCComponentSizeDistributionFile = new DistributionDataFile();

	meanOutputSCComponentSizeDistribution = new MeanDistribution(NB_ASSEMBLIES);
	meanOutputSCComponentSizeDistributionFile = new DistributionDataFile();
	
	meanInputSCCFractionRepartitionFile = new AccuDataFile();
	meanOutputSCCFractionRepartitionFile = new AccuDataFile();

			#endif
		#endif
	#endif

	#ifdef _PROJECTION_STAT_MODE
	meanProjections = new Accumulater();

	meanProjectionsFile = new AccuDataFile();
	
	// Excit/Inhib
	meanExcitProjections = new Accumulater();
	meanInhibProjections = new Accumulater();

	meanExcitProjectionsFile = new AccuDataFile();
	meanInhibProjectionsFile = new AccuDataFile();

	// Input
	meanExcitInputProjections = new Accumulater();
	meanInhibInputProjections = new Accumulater();

	meanExcitInputProjectionsFile = new AccuDataFile();
	meanInhibInputProjectionsFile = new AccuDataFile();

	// Output
	meanExcitOutputProjections = new Accumulater();
	meanInhibOutputProjections = new Accumulater();

	meanExcitOutputProjectionsFile = new AccuDataFile();
	meanInhibOutputProjectionsFile = new AccuDataFile();

	// Self
	meanExcitSelfProjections = new Accumulater();
	meanInhibSelfProjections = new Accumulater();

	meanExcitSelfProjectionsFile = new AccuDataFile();
	meanInhibSelfProjectionsFile = new AccuDataFile();
	#endif
	
	
	#ifdef _INPUT_OUTPUT_CLUSTER_STAT_MODE		
	maxModularityInputClusterSizeDistribution = new MeanDistribution(NB_ASSEMBLIES);
	maxModularityInputClusterSizeDistributionFile = new DistributionDataFile();

	maxModularityOutputClusterSizeDistribution = new MeanDistribution(NB_ASSEMBLIES);
	maxModularityOutputClusterSizeDistributionFile = new DistributionDataFile();
	
	maxModularityInputClusterFractionRepartitionFile = new AccuDataFile();
	maxModularityOutputClusterFractionRepartitionFile = new AccuDataFile();

	#endif
	
	// Graphs
	meanGnuplotProjectionsFile = new OngoingDistributionGnuplotFile();

	openTracer();
#endif

}

NetworkStater::~NetworkStater()
{
#ifdef _NETWORK_STAT_MODE

	//#ifdef _TEST_STAT
	cerr << "In ~NetworkStater" << endl;
	//#endif

	closeTracer();

	#ifdef _TEST_STAT
	cerr << "After closeTracer" << endl;
	#endif

	openGrapher();

	#ifdef _TEST_STAT
	cerr << "After openGrapher" << endl;
	#endif

	graph();

	#ifdef _TEST_STAT
	cerr << "After graph" << endl;
	#endif

	runGrapher();

	#ifdef _TEST_STAT
	cerr << "After runGrapher" << endl;
	#endif

	closeGrapher();

	#ifdef _TEST_STAT
	cerr << "After closeGrapher" << endl;
	#endif
	
	#ifdef _TOPOLOGY_STAT_MODE
	delete(topologyMatrixFile);
	
	for (int i=0;i<NB_ASSEMBLIES;i++)
	{
		delete((int*) connectivityMatrix[i]);
	}
	
	delete((int**) connectivityMatrix);
	#endif
	
	#ifdef _LINK_TO_INPUT_STAT_MODE
	delete(linkToInputFile);
	delete((int*) linkToInputVector);
	#endif
	
	#ifdef _LINK_TO_OUTPUT_STAT_MODE
	delete(linkToOutputFile);
	delete((int*) linkToOutputVector);
	#endif
	
	#ifdef _MATRIX_CLUSTERS_STAT_MODE
	delete(clusterMatrixFile);
	
	for (int i=0;i<NB_ASSEMBLIES;i++)
	{
		delete((int*) clusterMatrix[i]);
	}
	
	delete((int**) clusterMatrix);
	
	#endif
	
	#ifdef _CENTRALITY_STAT_MODE

		#ifdef _CLUSTER_STAT_MODE
		// Assemblees
	// Calcul de centralité
			#ifdef _3D_ONGOING_STAT_MODE
	delete(ongoingAssemblyCentralBetweennessDistribution);
	delete(ongoingAssemblyCentralBetweennessDistributionFile);
			#endif
			
	delete(ongoingAssemblyCentralBetweennessFile);
	
	// Centralite de noeud
			#ifdef _3D_ONGOING_STAT_MODE
	delete(ongoingAssemblyBetweennessDistribution);
	delete(ongoingAssemblyBetweennessDistributionFile);
			#endif
			
	delete(ongoingAssemblyBetweennessFile);
	
	
			#ifdef _EDGE_BETWEENNESS_STAT_MODE
	
				#ifdef _TEST_STAT
	cerr << "Before close _EDGE_BETWEENNESS_STAT_MODE" << endl;
				#endif
	
	// Intermediarite de liens
				#ifdef _3D_ONGOING_STAT_MODE
	delete(ongoingAssemblyEdgeBetweennessDistribution);
	delete(ongoingAssemblyEdgeBetweennessDistributionFile);
				#endif
				
	delete(ongoingAssemblyMaxEdgeBetweennessFile);
	
	#ifdef _TEST_STAT
	cerr << "After close _EDGE_BETWEENNESS_STAT_MODE" << endl;
	#endif
			#endif
		
	// Efficacite
			#ifdef _3D_ONGOING_STAT_MODE
	delete(ongoingAssemblyGlobalEfficiencyDistribution);
	delete(ongoingAssemblyGlobalEfficiencyDistributionFile);
			#endif
				
	delete(ongoingAssemblyGlobalEfficiencyFile);
	
			#ifdef _3D_ONGOING_STAT_MODE
	delete(ongoingAssemblyLocalEfficiencyDistribution);
	delete(ongoingAssemblyLocalEfficiencyDistributionFile);
			#endif
				
	delete(ongoingAssemblyLocalEfficiencyFile);
	
	// ShortPath
			#ifdef _3D_ONGOING_STAT_MODE
	delete(ongoingAssemblyShortPathLengthDistribution);
	delete(ongoingAssemblyShortPathLengthDistributionFile);
			#endif
				
		// Clusters
	// Modularite
	delete(ongoingClusterModularityFile);
	// Nombre de clusters
	delete(ongoingNbClustersFile);
	delete(ongoingMaxClusterSizesFile);

	// Taille des clusters
			#ifdef _3D_ONGOING_STAT_MODE
	delete(ongoingClusterSizeDistribution);
	delete(ongoingClusterSizeDistributionFile);
			#endif
			
	// Efficacite des clusters
			#ifdef _3D_ONGOING_STAT_MODE
	delete(ongoingClusterEfficiencyDistribution);
	delete(ongoingClusterEfficiencyDistributionFile);
			#endif
			
	delete(ongoingClusterEfficiencyFile);
			
			#ifdef _3D_ONGOING_STAT_MODE
	delete(ongoingClusterRealEfficiencyDistribution);
	delete(ongoingClusterRealEfficiencyDistributionFile);
			#endif
			
	delete(ongoingClusterRealEfficiencyFile);
	
			#ifdef _LINKED_CLUSTER_STAT_MODE
	delete(ongoingInDCFile);
	delete(ongoingInGOUTFile);
	delete(ongoingInGINFile);
	delete(ongoingInGSCCFile);
	
				#ifdef _CLUSTER_CENTRALITY_STAT_MODE
					
					#ifdef _EDGE_BETWEENNESS_STAT_MODE
	
	delete(ongoingLinkedClusterMaxEdgeBetweennessFile);

						#ifdef _3D_ONGOING_STAT_MODE
	delete(ongoingLinkedClusterEdgeBetweennessDistribution);
	delete(ongoingLinkedClusterEdgeBetweennessDistributionFile);
						#endif
					#endif
	
	// Calcul de centralité
					#ifdef _3D_ONGOING_STAT_MODE
	delete(ongoingLinkedClusterCentralBetweennessDistribution);
	delete(ongoingLinkedClusterCentralBetweennessDistributionFile);
					#endif
					
	delete(ongoingLinkedClusterCentralBetweennessFile);
	
					#ifdef _3D_ONGOING_STAT_MODE
	delete(ongoingLinkedClusterBetweennessDistribution);
	delete(ongoingLinkedClusterBetweennessDistributionFile);
					#endif
					
	delete(ongoingLinkedClusterBetweennessFile);
		
	// Efficacite
					#ifdef _3D_ONGOING_STAT_MODE
	delete(ongoingLinkedClusterGlobalEfficiencyDistribution);
	delete(ongoingLinkedClusterGlobalEfficiencyDistributionFile);
					#endif
					
	delete(ongoingLinkedClusterGlobalEfficiencyFile);
	
					#ifdef _3D_ONGOING_STAT_MODE
	delete(ongoingLinkedClusterLocalEfficiencyDistribution);
	delete(ongoingLinkedClusterLocalEfficiencyDistributionFile);
					#endif
					
	delete(ongoingLinkedClusterLocalEfficiencyFile);
	
	// ShortPath
					#ifdef _3D_ONGOING_STAT_MODE
	delete(ongoingLinkedClusterShortPathLengthDistribution);
	delete(ongoingLinkedClusterShortPathLengthDistributionFile);
					#endif
				#endif
			#endif
				
			#ifdef _NETWORK_CLUSTER_STAT_MODE
				#ifdef _LINKED_CLUSTER_STAT_MODE
	// Repartition des clusters dans les composants pour le réseau à la fin du processus de clusterisation
	delete(networkInDC);
	delete(networkInGOUT);
	delete(networkInGIN);
	delete(networkInGSCC);
	delete(networkComponentRepartitionFile);
				#endif
				
	// Repartition de la taille des clusters pour le réseau à la fin du processus de clusterisation
	delete(networkClusterSizeDistributionFile);
	delete(networkClusterSizeDistribution);
	
	// Repartition de l'efficacité des clusters pour le réseau à la fin du processus de clusterisation
	delete(networkClusterEfficiency);
	delete(networkClusterEfficiencyFile);
	
	delete(networkClusterEfficiencyDistribution);
	delete(networkClusterEfficiencyDistributionFile);

	delete(networkClusterRealEfficiency);
	delete(networkClusterRealEfficiencyFile);

	delete(networkClusterRealEfficiencyDistribution);
	delete(networkClusterRealEfficiencyDistributionFile);

				#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
	// Nombre de suppression de liens pour atteindre le réseau optimal
	delete(maxModularityProjectionIndex);
	delete(maxModularityProjectionIndexFile);

	// Modularité maximale
	delete(maxModularity);
	delete(maxModularityFile);

					#ifdef _LINKED_CLUSTER_STAT_MODE
	// Repartition des clusters dans les composants pour le réseau optimal
	delete(maxModularityInDC);
	delete(maxModularityInGOUT);
	delete(maxModularityInGIN);
	delete(maxModularityInGSCC);
	delete(maxModularityComponentRepartitionFile);
					#endif
						
	// Repartition de la taille des clusters pour le réseau optimal
	delete(maxModularityClusterSizeDistributionFile);
	delete(maxModularityClusterSizeDistribution);

	// Repartition de l'efficacité des clusters pour le réseau optimal
	delete(maxModularityClusterEfficiency);
	delete(maxModularityClusterEfficiencyFile);

	delete(maxModularityClusterEfficiencyDistribution);
	delete(maxModularityClusterEfficiencyDistributionFile);

	delete(maxModularityClusterRealEfficiency);
	delete(maxModularityClusterRealEfficiencyFile);
	
	delete(maxModularityClusterRealEfficiencyDistribution);
	delete(maxModularityClusterRealEfficiencyDistributionFile);

				#endif
			#endif
	
			#ifdef _TEST_STAT
	cerr << "After close _CENTRALITY_STAT_MODE" << endl;
			#endif
		#else


	// Calcul d'intermediarité
	delete(meanAssemblyBetweennessRepartitionFile);

	delete(meanAssemblyBetweenness);
	delete(meanAssemblyBetweennessFile);
			
	delete(meanAssemblyCentralBetweennessDistribution);
	delete(meanAssemblyCentralBetweennessDistributionFile);

	// Calcul de centralité
	delete(meanAssemblyCentralBetweennessRepartitionFile);
	
	delete(meanAssemblyCentralBetweenness);
	delete(meanAssemblyCentralBetweennessFile);

			#ifdef _EDGE_BETWEENNESS_STAT_MODE
	
	// Calcul d'intermediarité pour les liens
	delete(meanEdgeBetweennessRepartitionFile);

	delete(meanEdgeBetweennessDistributionFile);
	delete(meanEdgeBetweennessDistribution);
			#endif
			
	// Centralite de noeud
	delete(meanAssemblyBetweennessDistribution);
	delete(meanAssemblyBetweennessDistributionFile);

	// Repartition des short paths
	delete(meanAssemblyShortPathRepartitionFile);
	delete(meanAssemblyNoShortPathRepartitionFile);

	delete(meanAssemblyNbShortPathDistribution);
	delete(meanAssemblyNbShortPathDistributionFile);
	
	// Calcul d'efficacite
	delete(meanAssemblyLocalEfficiencyRepartitionFile);
	delete(meanAssemblyGlobalEfficiencyRepartitionFile);

	delete(meanAssemblyGlobalEfficiencyDistribution);
	delete(meanAssemblyGlobalEfficiencyDistributionFile);

	delete(meanAssemblyLocalEfficiencyDistribution);
	delete(meanAssemblyLocalEfficiencyDistributionFile);

	delete(meanAssemblyGlobalEfficiency);
	delete(meanAssemblyGlobalEfficiencyFile);

	delete(meanAssemblyLocalEfficiency);
	delete(meanAssemblyLocalEfficiencyFile);
		#endif
	#endif

	// Loop
	#ifdef _LOOP_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
		// Assembly
	// Nb Loops
			#ifdef _3D_ONGOING_STAT_MODE
	delete(ongoingAssemblyNbLoopsDistribution);
	delete(ongoingAssemblyNbLoopsDistributionFile);
			#endif
			
	delete(ongoingAssemblyNbLoopsFile);
	
	// Degree
			#ifdef _3D_ONGOING_STAT_MODE
	delete(ongoingAssemblyNbLoopsDegreeDistribution);
	delete(ongoingAssemblyNbLoopsDegreeDistributionFile);
			#endif
	// Loop size
			#ifdef _3D_ONGOING_STAT_MODE
	delete(ongoingAssemblyLoopSizeDistribution);
	delete(ongoingAssemblyLoopSizeDistributionFile);
			#endif
			
		// Cluster
			#ifdef _3D_ONGOING_STAT_MODE
	delete(ongoingClusterLoopSizeDistribution);
	delete(ongoingClusterLoopSizeDistributionFile);
			#endif
			
	delete(ongoingClusterNbLoopsFile);
	
			#ifdef _NETWORK_CLUSTER_STAT_MODE
			
	delete(networkClusterLoopSizeDistribution);
	delete(networkClusterLoopSizeDistributionFile);
	
				#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
	delete(maxModularityClusterLoopSizeDistribution);
	delete(maxModularityClusterLoopSizeDistributionFile);
				#endif
				
			#endif
		#else
	delete(meanAssemblyLoopSizeDistribution);
	delete(meanAssemblyLoopSizeDistributionFile);
	
	// Nb Loops
	delete(meanAssemblyNbLoopsRepartitionFile);
	
	delete(meanAssemblyNbLoopsDistribution);
	delete(meanAssemblyNbLoopsDistributionFile);
	
	// Degree
	delete(meanAssemblyNbLoopsDegreeDistribution);
	delete(meanAssemblyNbLoopsDegreeDistributionFile);

		#endif
	#endif
	
	#ifdef _TEST_STAT
	cerr << "After close _LOOP_STAT_MODE" << endl;
	#endif
	
	// Small World
	#ifdef _SMALL_WORLD_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
	// Degree
			#ifdef _3D_ONGOING_STAT_MODE
	delete(ongoingAssemblyClusteringCoeffDegreeDistribution);
	delete(ongoingAssemblyClusteringCoeffDegreeDistributionFile);

	delete(ongoingAssemblyClusteringCoeffDistribution);
	delete(ongoingAssemblyClusteringCoeffDistributionFile);
			#endif
	// Cluster
	delete(ongoingClusterInternalDensityFile);
	delete(ongoingRealClusterInternalDensityFile);
	
			#ifdef _CLUSTER_CENTRALITY_STAT_MODE
				#ifdef _3D_ONGOING_STAT_MODE
	delete(ongoingLinkedClusterClusteringCoeffDegreeDistribution);
	delete(ongoingLinkedClusterClusteringCoeffDegreeDistributionFile);

	delete(ongoingLinkedClusterClusteringCoeffDistribution);
	delete(ongoingLinkedClusterClusteringCoeffDistributionFile);
				#endif
			#endif
			
			#ifdef _NETWORK_CLUSTER_STAT_MODE
	delete(networkClusterInternalDensity);
	delete(networkClusterInternalDensityFile);
	
	delete(networkRealClusterInternalDensity);
	delete(networkRealClusterInternalDensityFile);
	
				#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	delete(networkLinkedClusterClusteringCoeffDegreeDistribution);
	delete(networkLinkedClusterClusteringCoeffDegreeDistributionFile);

	delete(networkLinkedClusterClusteringCoeffDistribution);
	delete(networkLinkedClusterClusteringCoeffDistributionFile);

				#endif
				
				#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
	delete(maxModularityClusterInternalDensity);
	delete(maxModularityClusterInternalDensityFile);
	
	delete(maxModularityRealClusterInternalDensity);
	delete(maxModularityRealClusterInternalDensityFile);
	
					#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	delete(maxModularityLinkedClusterClusteringCoeffDegreeDistribution);
	delete(maxModularityLinkedClusterClusteringCoeffDegreeDistributionFile);

	delete(maxModularityLinkedClusterClusteringCoeffDistribution);
	delete(maxModularityLinkedClusterClusteringCoeffDistributionFile);
					#endif
				#endif
			#endif
		#else
	// Distribution
	delete(meanClusteringCoeffDistribution);
	delete(meanClusteringCoeffDistributionFile);
	
	// Degree
	delete(meanClusteringCoeffDegreeDistribution);
	delete(meanClusteringCoeffDegreeDistributionFile);

	// Repartition
	delete(meanClusteringCoeffRepartitionFile);
	

	delete(meanClusteringCoeffFile);
	
	delete(meanClusteringCoeff);
		#endif
	#endif

	#ifdef _TEST_STAT
	cerr << "After close _SMALL_WORLD_STAT_MODE" << endl;
	#endif
	

	#ifdef _MOTIF_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
			#ifdef _3D_ONGOING_STAT_MODE
	delete(ongoingAssemblyBinodeMotifsFile);
	
	delete(ongoingAssemblyTrinodeMotifsDistribution);
	delete(ongoingAssemblyTrinodeMotifsDistributionFile);
			#endif
			
			#ifdef _CLUSTER_CENTRALITY_STAT_MODE
				#ifdef _3D_ONGOING_STAT_MODE
	delete(ongoingLinkedClusterTrinodeMotifsDistribution);
	delete(ongoingLinkedClusterTrinodeMotifsDistributionFile);
				#endif
			#endif
			
			#ifdef _INTERNAL_MOTIF_STAT_MODE
				#ifdef _3D_ONGOING_STAT_MODE
	delete(ongoingClusterInternalBinodeMotifsFile);
	
	delete(ongoingClusterInternalTrinodeMotifsDistribution);
	delete(ongoingClusterInternalTrinodeMotifsDistributionFile);
				#endif
				
				#ifdef _NETWORK_CLUSTER_STAT_MODE
	delete(networkClusterInternalBinodeMotifs);
	delete(networkClusterInternalBinodeMotifsFile);
	
	delete(networkClusterInternalTrinodeMotifsDistribution);
	delete(networkClusterInternalTrinodeMotifsDistributionFile);
	
					#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	delete(networkLinkedClusterTrinodeMotifsDistribution);
	delete(networkLinkedClusterTrinodeMotifsDistributionFile);
	
					#endif
					
					#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
	delete(maxModularityClusterInternalBinodeMotifs);
	delete(maxModularityClusterInternalBinodeMotifsFile);
	
	delete(maxModularityClusterInternalTrinodeMotifsDistribution);
	delete(maxModularityClusterInternalTrinodeMotifsDistributionFile);
						
						#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	delete(maxModularityLinkedClusterTrinodeMotifsDistribution);
	delete(maxModularityLinkedClusterTrinodeMotifsDistributionFile);
	
						#endif
					#endif
				#endif
			#endif
		#else
	delete(meanBinodeMotifs);
	delete(meanBinodeMotifsFile);

	delete(meanTrinodeMotifsDistribution);
	delete(meanTrinodeMotifsDistributionFile);
		#endif
	#endif
	
	#ifdef _TEST_STAT
	cerr << "After close _MOTIF_STAT_MODE" << endl;
	#endif
	
	#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
			#ifdef _3D_ONGOING_STAT_MODE
	delete(ongoingAssemblyReachedByInputDistribution);
	delete(ongoingAssemblyReachedByInputDistributionFile);
	
	delete(ongoingAssemblyReachedByOutputDistribution);
	delete(ongoingAssemblyReachedByOutputDistributionFile);
	
	delete(ongoingAssemblyInputOutputPathLengthDistribution);
	delete(ongoingAssemblyInputOutputPathLengthDistributionFile);
	
	delete(ongoingAssemblyPathToInputDistribution);
	delete(ongoingAssemblyPathToInputDistributionFile);
	
	delete(ongoingAssemblyPathToOutputDistribution);
	delete(ongoingAssemblyPathToOutputDistributionFile);
			#endif
		#else
	
	delete(meanReachedByInputDistribution);
	delete(meanReachedByInputDistributionFile);
	
	delete(meanReachedByOutputDistribution);
	delete(meanReachedByOutputDistributionFile);

	delete(meanPathToInputDistribution);
	delete(meanPathToInputDistributionFile);

	delete(meanPathToOutputDistribution);
	delete(meanPathToOutputDistributionFile);
	
	delete(meanInputOutputPathLengthDistribution);
	delete(meanInputOutputPathLengthDistributionFile);
		#endif
	#endif
	
	#ifdef _TEST_STAT
	cerr << "After close _INPUT_OUTPUT_LENGTH_STAT_MODE" << endl;
	#endif
	
	#ifdef _DEGREE_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
	// Degree
			#ifdef _3D_ONGOING_STAT_MODE
	delete(ongoingAssemblyDegreeDistribution);
	delete(ongoingAssemblyDegreeDistributionFile);
	
	delete(ongoingAssemblyPreDegreeDistribution);
	delete(ongoingAssemblyPreDegreeDistributionFile);
	
	delete(ongoingAssemblyPostDegreeDistribution);
	delete(ongoingAssemblyPostDegreeDistributionFile);
	
	// Voisins
	delete(ongoingAssemblyNearestNeighboursDegreeDistribution);
	delete(ongoingAssemblyNearestNeighboursDegreeDistributionFile);
			#endif
	// In/Out
	
			#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE
				#ifdef _3D_ONGOING_STAT_MODE
	delete(ongoingInputAssemblyDegreeDistribution);
	delete(ongoingInputAssemblyDegreeDistributionFile);
	
	delete(ongoingOutputAssemblyDegreeDistribution);
	delete(ongoingOutputAssemblyDegreeDistributionFile);
	
	// Voisins
	delete(ongoingInputAssemblyNearestNeighboursDegreeDistribution);
	delete(ongoingInputAssemblyNearestNeighboursDegreeDistributionFile);
	
	delete(ongoingOutputAssemblyNearestNeighboursDegreeDistribution);
	delete(ongoingOutputAssemblyNearestNeighboursDegreeDistributionFile);
				#endif
			#endif
			
			#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	// Degree
				#ifdef _3D_ONGOING_STAT_MODE
	delete(ongoingLinkedClusterDegreeDistribution);
	delete(ongoingLinkedClusterDegreeDistributionFile);
	
	delete(ongoingLinkedClusterPreDegreeDistribution);
	delete(ongoingLinkedClusterPreDegreeDistributionFile);
	
	delete(ongoingLinkedClusterPostDegreeDistribution);
	delete(ongoingLinkedClusterPostDegreeDistributionFile);
	
	// Voisins
	delete(ongoingLinkedClusterNearestNeighboursDegreeDistribution);
	delete(ongoingLinkedClusterNearestNeighboursDegreeDistributionFile);
				#endif
				
				#ifdef _NETWORK_CLUSTER_STAT_MODE
	// Degree
	delete(networkLinkedClusterDegreeDistribution);
	delete(networkLinkedClusterDegreeDistributionFile);
	
	delete(networkLinkedClusterPreDegreeDistribution);
	delete(networkLinkedClusterPreDegreeDistributionFile);
	
	delete(networkLinkedClusterPostDegreeDistribution);
	delete(networkLinkedClusterPostDegreeDistributionFile);
	
	// Voisins
	delete(networkLinkedClusterNearestNeighboursDegreeDistribution);
	delete(networkLinkedClusterNearestNeighboursDegreeDistributionFile);
					
					#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
	// Degree
	delete(maxModularityLinkedClusterDegreeDistribution);
	delete(maxModularityLinkedClusterDegreeDistributionFile);
	
	delete(maxModularityLinkedClusterPreDegreeDistribution);
	delete(maxModularityLinkedClusterPreDegreeDistributionFile);
	
	delete(maxModularityLinkedClusterPostDegreeDistribution);
	delete(maxModularityLinkedClusterPostDegreeDistributionFile);
	
	// Voisins
	delete(maxModularityLinkedClusterNearestNeighboursDegreeDistribution);
	delete(maxModularityLinkedClusterNearestNeighboursDegreeDistributionFile);
									
					#endif
				#endif
			#endif
			
		#else
	// Degree
	delete(meanDegreeDistribution);
	delete(meanDegreeDistributionFile);
	
	delete(meanPreDegreeDistribution);
	delete(meanPreDegreeDistributionFile);
	
	delete(meanPostDegreeDistribution);
	delete(meanPostDegreeDistributionFile);
	
			#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE
	//Voisins
	delete(meanNearestNeighboursDegreeDistribution);
	delete(meanNearestNeighboursDegreeDistributionFile);
		
	delete(meanInputAssemblyDegreeDistribution);
	delete(meanInputAssemblyDegreeDistributionFile);
	
	delete(meanOutputAssemblyDegreeDistribution);
	delete(meanOutputAssemblyDegreeDistributionFile);

	delete(meanInputAssemblyNearestNeighboursDegreeDistribution);
	delete(meanInputAssemblyNearestNeighboursDegreeDistributionFile);
	
	delete(meanOutputAssemblyNearestNeighboursDegreeDistribution);
	delete(meanOutputAssemblyNearestNeighboursDegreeDistributionFile);
			#endif
		#endif
	#endif

	#ifdef _TEST_STAT
	cerr << "After close _DEGREE_STAT_MODE" << endl;
	#endif
	
	#ifdef _GSCC_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
	delete(ongoingNbGSCCNodesFile);
			#ifdef _3D_ONGOING_STAT_MODE
	delete(ongoingSCComponentSizeDistribution);
	delete(ongoingSCComponentSizeDistributionFile);
			#endif
	delete(ongoingMaxSCComponentSizeFile);
	
			#ifdef _3D_ONGOING_STAT_MODE
	delete(ongoingMaxSCComponentSizeDistribution);
	delete(ongoingMaxSCComponentSizeDistributionFile);
			#endif
	/*
	delete(meanAssemblyDiameterSizeDistribution);
	delete(meanAssemblyDiameterSizeDistributionFile);
	*/
		#else
	delete(meanNbGSCCNodes);
	delete(meanNbGSCCNodesFile);

	delete(meanMaxSCComponentSize);
	delete(meanMaxSCComponentSizeFile);

	delete(meanMaxSCComponentSizeDistribution);
	delete(meanMaxSCComponentSizeDistributionFile);
	
			#ifdef _INPUT_OUTPUT_GSCC_STAT_MODE		
	
	delete(meanInputSCComponentSizeDistribution);
	delete(meanInputSCComponentSizeDistributionFile);


	delete(meanOutputSCComponentSizeDistribution);
	delete(meanOutputSCComponentSizeDistributionFile);

	delete(meanInputSCCFractionRepartitionFile);

	delete(meanOutputSCCFractionRepartitionFile);

			#endif
		#endif
	#endif

	#ifdef _TEST_STAT
	cerr << "After close _GSCC_STAT_MODE" << endl;
	#endif
	
	#ifdef _PROJECTION_STAT_MODE
	delete(meanProjections);

	delete(meanProjectionsFile);
	
	// Excit/Inhib
	delete(meanExcitProjections);
	delete(meanInhibProjections);

	delete(meanExcitProjectionsFile);
	delete(meanInhibProjectionsFile);

	// Input
	delete(meanExcitInputProjections);
	delete(meanInhibInputProjections);

	delete(meanExcitInputProjectionsFile);
	delete(meanInhibInputProjectionsFile);

	// Output
	delete(meanExcitOutputProjections);
	delete(meanInhibOutputProjections);

	delete(meanExcitOutputProjectionsFile);
	delete(meanInhibOutputProjectionsFile);

	// Self
	delete(meanExcitSelfProjections);
	delete(meanInhibSelfProjections);

	delete(meanExcitSelfProjectionsFile);
	delete(meanInhibSelfProjectionsFile);

	#endif
	
	#ifdef _TEST_STAT
	cerr << "After close _PROJECTION_STAT_MODE" << endl;
	#endif
	
	#ifdef _INPUT_OUTPUT_CLUSTER_STAT_MODE		
	delete(maxModularityInputClusterSizeDistribution);
	delete(maxModularityInputClusterSizeDistributionFile);
	
	delete(maxModularityOutputClusterSizeDistribution);
	delete(maxModularityOutputClusterSizeDistributionFile);
	
	delete(maxModularityInputClusterFractionRepartitionFile);
	delete(maxModularityOutputClusterFractionRepartitionFile);
	
	#endif
	
	// Graphs
	delete(meanGnuplotProjectionsFile);

	//#ifdef _TEST_STAT
	cerr << "End of ~NetworkStater" << endl;
	//#endif
#endif
}

void NetworkStater::openTracer()
{	
#ifdef _NETWORK_STAT_MODE
	
	#ifdef _TOPOLOGY_STAT_MODE
	if (topologyMatrixFile)
	{
		cerr << "Opening Topology Matrix data file" << endl;
		#ifdef _INHIB_EXCIT_TOPOLOGY_STAT_MODE
		topologyMatrixFile->openDataFile("InhibExcitProjectionsTopologyMatrix");
		#else
		topologyMatrixFile->openDataFile("NbProjectionsTopologyMatrix");
		#endif
	}
	#endif
	
	#ifdef _LINK_TO_INPUT_STAT_MODE
	if (linkToInputFile)
	{
		cerr << "Opening link To Input File" << endl;
		#ifdef _EXCIT_LINK_TO_INPUT_STAT_MODE
		linkToInputFile->openDataFile("ExcitLinkToInputVector");
		#else
		linkToInputFile->openDataFile("LinkToInputVector");
		#endif
	}
	
	#endif
	
	#ifdef _LINK_TO_OUTPUT_STAT_MODE
	if (linkToOutputFile)
	{
		cerr << "Opening link To Output File" << endl;
		#ifdef _EXCIT_LINK_TO_OUTPUT_STAT_MODE
		linkToOutputFile->openDataFile("ExcitLinkToOutputVector");
		#else
		linkToOutputFile->openDataFile("LinkToOutputVector");
		#endif
	}
	
	#endif
	
	#ifdef _MATRIX_CLUSTERS_STAT_MODE
	if (clusterMatrixFile)
	{
		cerr << "Opening Clusters Matrix data file" << endl;
		clusterMatrixFile->openDataFile("ClusterMatrix");
	}
	#endif
	
	#ifdef _CENTRALITY_STAT_MODE

		#ifdef _CLUSTER_STAT_MODE
		// Assemblees
	// Calcul de centralité
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingAssemblyCentralBetweennessDistributionFile)
	{
		ongoingAssemblyCentralBetweennessDistributionFile->openOngoingDistributionDataFile("AssemblyCentralBetweenness");
	}
			#endif
			
	if (ongoingAssemblyCentralBetweennessFile)
	{
		ongoingAssemblyCentralBetweennessFile->openDataFile("Indexed_Sorted_OngoingAssemblyCentralBetweennessStat");
	}

	// Centralite de noeuds
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingAssemblyBetweennessDistributionFile)
	{
		ongoingAssemblyBetweennessDistributionFile->openOngoingDistributionDataFile("AssemblyBetweenness");
	}
			#endif
			
	if (ongoingAssemblyBetweennessFile)
	{
		ongoingAssemblyBetweennessFile->openDataFile("Indexed_Sorted_OngoingAssemblyBetweennessStat");
	}

		#ifdef _EDGE_BETWEENNESS_STAT_MODE

	// EdgeBetweenness
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingAssemblyEdgeBetweennessDistributionFile)
	{
		ongoingAssemblyEdgeBetweennessDistributionFile->openOngoingDistributionDataFile("AssemblyEdgeBetweenness");
	}
			#endif
			
	if (ongoingAssemblyMaxEdgeBetweennessFile)
	{
		ongoingAssemblyMaxEdgeBetweennessFile->openDataFile("Indexed_Sorted_OngoingAssemblyMaxEdgeBetweennessStat");
	}
		#endif
		
	// Efficacité du réseau au fur et à mesure de la suppression
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingAssemblyGlobalEfficiencyDistributionFile)
	{
		ongoingAssemblyGlobalEfficiencyDistributionFile->openOngoingDistributionDataFile("AssemblyGlobalEfficiency");
	}
			#endif
			
	if (ongoingAssemblyGlobalEfficiencyFile)
	{
		ongoingAssemblyGlobalEfficiencyFile->openDataFile("Indexed_Sorted_OngoingAssemblyGlobalEfficiencyStat");
	}

			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingAssemblyLocalEfficiencyDistributionFile)
	{
		ongoingAssemblyLocalEfficiencyDistributionFile->openOngoingDistributionDataFile("AssemblyLocalEfficiency");
	}
			#endif
			
	if (ongoingAssemblyLocalEfficiencyFile)
	{
		ongoingAssemblyLocalEfficiencyFile->openDataFile("Indexed_Sorted_OngoingAssemblyLocalEfficiencyStat");
	}

	// ShortPath
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingAssemblyShortPathLengthDistributionFile)
	{
		ongoingAssemblyShortPathLengthDistributionFile->openOngoingDistributionDataFile("AssemblyShortPathLength");
	}
			#endif
			
		// Clusters
	if (ongoingClusterModularityFile)
	{
		ongoingClusterModularityFile->openDataFile("Indexed_Sorted_OngoingClusterModularityStat");
	}

	if (ongoingNbClustersFile)
	{
		ongoingNbClustersFile->openDataFile("Indexed_Sorted_OngoingNbClustersStat");
	}

	if (ongoingMaxClusterSizesFile)
	{
		ongoingMaxClusterSizesFile->openDataFile("Indexed_Sorted_OngoingMaxClusterSizesStat");
	}
	
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingClusterSizeDistributionFile)
	{
		ongoingClusterSizeDistributionFile->openOngoingDistributionDataFile("ClusterSize");
	}
			#endif
			
	// Repartition de l'efficacité des clusters
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingClusterEfficiencyDistributionFile)
	{
		ongoingClusterEfficiencyDistributionFile->openOngoingDistributionDataFile("ClusterEfficiency");
	}
			#endif
			
	if (ongoingClusterEfficiencyFile)
	{
		ongoingClusterEfficiencyFile->openDataFile("Indexed_Sorted_OngoingClusterEfficiencyStat");
	}

			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingClusterRealEfficiencyDistributionFile)
	{
		ongoingClusterRealEfficiencyDistributionFile->openOngoingDistributionDataFile("ClusterRealEfficiency");
	}
			#endif
			
	if (ongoingClusterRealEfficiencyFile)
	{
		ongoingClusterRealEfficiencyFile->openDataFile("Indexed_Sorted_OngoingClusterRealEfficiencyStat");
	}


			#ifdef _LINKED_CLUSTER_STAT_MODE
	// Repartition des clusters dans les composants
	if (ongoingInDCFile)
	{
		ongoingInDCFile->openDataFile("Indexed_Sorted_OngoingInDCStat");
	}

	if (ongoingInGOUTFile)
	{
		ongoingInGOUTFile->openDataFile("Indexed_Sorted_OngoingInGOUTStat");
	}

	if (ongoingInGINFile)
	{
		ongoingInGINFile->openDataFile("Indexed_Sorted_OngoingInGINStat");
	}

	if (ongoingInGSCCFile)
	{
		ongoingInGSCCFile->openDataFile("Indexed_Sorted_OngoingInGSCCStat");
	}
	
				#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	// Efficacité du réseau au fur et à mesure de la suppression
					#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingLinkedClusterGlobalEfficiencyDistributionFile)
	{
		ongoingLinkedClusterGlobalEfficiencyDistributionFile->openOngoingDistributionDataFile("LinkedClusterGlobalEfficiency");
	}
					#endif
					
	if (ongoingLinkedClusterGlobalEfficiencyFile)
	{
		ongoingLinkedClusterGlobalEfficiencyFile->openDataFile("Indexed_Sorted_OngoingLinkedClusterGlobalEfficiencyStat");
	}

					#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingLinkedClusterLocalEfficiencyDistributionFile)
	{
		ongoingLinkedClusterLocalEfficiencyDistributionFile->openOngoingDistributionDataFile("LinkedClusterLocalEfficiency");
	}
					#endif
					
	if (ongoingLinkedClusterLocalEfficiencyFile)
	{
		ongoingLinkedClusterLocalEfficiencyFile->openDataFile("Indexed_Sorted_OngoingLinkedClusterLocalEfficiencyStat");
	}

					
					#ifdef _EDGE_BETWEENNESS_STAT_MODE

	// Intermediarite de liens
						#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingLinkedClusterEdgeBetweennessDistributionFile)
	{
		ongoingLinkedClusterEdgeBetweennessDistributionFile->openOngoingDistributionDataFile("LinkedClusterEdgeBetweenness");
	}	
						#endif

	if (ongoingLinkedClusterMaxEdgeBetweennessFile)
	{
		ongoingLinkedClusterMaxEdgeBetweennessFile->openDataFile("Indexed_Sorted_OngoingLinkedClusterMaxEdgeBetweennessStat");
	}
					#endif
					
	// Calcul de centralité
					#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingLinkedClusterBetweennessDistributionFile)
	{
		ongoingLinkedClusterBetweennessDistributionFile->openOngoingDistributionDataFile("LinkedClusterBetweenness");
	}
					#endif

	if (ongoingLinkedClusterBetweennessFile)
	{
		ongoingLinkedClusterBetweennessFile->openDataFile("Indexed_Sorted_OngoingLinkedClusterBetweennessStat");
	}

					#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingLinkedClusterCentralBetweennessDistributionFile)
	{
		ongoingLinkedClusterCentralBetweennessDistributionFile->openOngoingDistributionDataFile("LinkedClusterCentralBetweenness");
	}
					#endif
					
	if (ongoingLinkedClusterCentralBetweennessFile)
	{
		ongoingLinkedClusterCentralBetweennessFile->openDataFile("Indexed_Sorted_OngoingLinkedClusterCentralBetweennessStat");
	}

	// ShortPath
					#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingLinkedClusterShortPathLengthDistributionFile)
	{
		ongoingLinkedClusterShortPathLengthDistributionFile->openOngoingDistributionDataFile("LinkedClusterShortPathLength");
	}
					#endif
				#endif
			#endif

			#ifdef _NETWORK_CLUSTER_STAT_MODE
				#ifdef _LINKED_CLUSTER_STAT_MODE
	if (networkComponentRepartitionFile)
	{
		networkComponentRepartitionFile->openDataFile("Indexed_Sorted_NetworkComponentRepartitionStat");
	}
				#endif

	if (networkClusterSizeDistributionFile)
	{
		networkClusterSizeDistributionFile->openDistributionDataFile("NetworkClusterSize");
	}
	
	// Efficacite des clusters
	if (networkClusterEfficiencyFile)
	{
		networkClusterEfficiencyFile->openAccuDataFile("NetworkClusterEfficiency");
	}

	if (networkClusterEfficiencyDistributionFile)
	{
		networkClusterEfficiencyDistributionFile->openDistributionDataFile("NetworkClusterEfficiency");
	}
	
	if (networkClusterRealEfficiencyFile)
	{
		networkClusterRealEfficiencyFile->openAccuDataFile("NetworkClusterRealEfficiency");
	}
	
	if (networkClusterRealEfficiencyDistributionFile)
	{
		networkClusterRealEfficiencyDistributionFile->openDistributionDataFile("NetworkClusterRealEfficiency");
	}
	
				#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
	// Nombre de suppression de liens pour atteindre le réseau optimal
	if (maxModularityProjectionIndexFile)
	{
		maxModularityProjectionIndexFile->openAccuDataFile("MaxModularityProjectionIndex");
	}

	// Modularité maximale
	if (maxModularityFile)
	{
		maxModularityFile->openAccuDataFile("MaxModularity");
	}

					#ifdef _LINKED_CLUSTER_STAT_MODE
	// Repartition des clusters dans les composants pour le réseau optimal
	if (maxModularityComponentRepartitionFile)
	{
		maxModularityComponentRepartitionFile->openDataFile("Indexed_Sorted_MaxModularityComponentRepartitionStat");
	}
					#endif
					
	// Repartition de la taille des clusters pour le réseau optimal
	if (maxModularityClusterSizeDistributionFile)
	{
		maxModularityClusterSizeDistributionFile->openDistributionDataFile("MaxModularityClusterSize");
	}

	// Repartition de l'efficacité des clusters pour le réseau optimal
	if (maxModularityClusterEfficiencyFile)
	{
		maxModularityClusterEfficiencyFile->openAccuDataFile("MaxModularityClusterEfficiency");
	}

	if (maxModularityClusterEfficiencyDistributionFile)
	{
		maxModularityClusterEfficiencyDistributionFile->openDistributionDataFile("MaxModularityClusterEfficiency");
	}

	if (maxModularityClusterRealEfficiencyFile)
	{
		maxModularityClusterRealEfficiencyFile->openAccuDataFile("MaxModularityClusterRealEfficiency");
	}
	
	if (maxModularityClusterRealEfficiencyDistributionFile)
	{
		maxModularityClusterRealEfficiencyDistributionFile->openDistributionDataFile("MaxModularityClusterRealEfficiency");
	}
				#endif
			#endif

		#else

	// Calcul d'intermediarité
	if (meanAssemblyBetweennessRepartitionFile)
	{
		meanAssemblyBetweennessRepartitionFile->openDataFile("Indexed_Sorted_MeanAssemblyBetweennessRepartitionStat");
	}

	if (meanAssemblyBetweennessFile)
	{
		meanAssemblyBetweennessFile->openAccuDataFile("MeanAssemblyBetweenness");
	}

	if (meanAssemblyBetweennessDistributionFile)
	{
		meanAssemblyBetweennessDistributionFile->openDistributionDataFile("MeanAssemblyBetweenness");
	}

	// Calcul de centralité
	if (meanAssemblyCentralBetweennessRepartitionFile)
	{
		meanAssemblyCentralBetweennessRepartitionFile->openDataFile("Indexed_Sorted_MeanAssemblyCentralBetweennessRepartitionStat");
	}
	
	if (meanAssemblyCentralBetweennessFile)
	{
		meanAssemblyCentralBetweennessFile->openAccuDataFile("MeanAssemblyCentralBetweenness");
	}
	
	if (meanAssemblyCentralBetweennessDistributionFile)
	{
		meanAssemblyCentralBetweennessDistributionFile->openDistributionDataFile("MeanAssemblyCentralBetweenness");
	}
			
			#ifdef _EDGE_BETWEENNESS_STAT_MODE

	// Calcul d'intermediarité pour les liens
	if (meanEdgeBetweennessRepartitionFile)
	{
		meanEdgeBetweennessRepartitionFile->openRepartitionDataFile("MeanEdgeBetweenness");
	}

	if (meanEdgeBetweennessDistributionFile)
	{
		meanEdgeBetweennessDistributionFile->openDistributionDataFile("MeanEdgeBetweenness");
	}
			#endif
			
	// Repartition des short paths
	if (meanAssemblyShortPathRepartitionFile)
	{
		meanAssemblyShortPathRepartitionFile->openDataFile("Indexed_Sorted_MeanAssemblyShortPathRepartitionStat");
	}

	if (meanAssemblyNoShortPathRepartitionFile)
	{
		meanAssemblyNoShortPathRepartitionFile->openDataFile("Indexed_Sorted_MeanAssemblyNoShortPathRepartitionStat");
	}
	
	if (meanAssemblyNbShortPathDistributionFile)
	{
		meanAssemblyNbShortPathDistributionFile->openDataFile("Indexed_Sorted_MeanAssemblyNbShortPathDistributionStat");
	}
	
	// Calcul d'efficacite
	if (meanAssemblyGlobalEfficiencyRepartitionFile)
	{
		meanAssemblyGlobalEfficiencyRepartitionFile->openDataFile("Indexed_Sorted_MeanAssemblyGlobalEfficiencyRepartitionStat");
	}

	if (meanAssemblyLocalEfficiencyRepartitionFile)
	{
		meanAssemblyLocalEfficiencyRepartitionFile->openDataFile("Indexed_Sorted_MeanAssemblyLocalEfficiencyRepartitionStat");
	}
	
	if (meanAssemblyGlobalEfficiencyDistributionFile)
	{
		meanAssemblyGlobalEfficiencyDistributionFile->openDistributionDataFile("MeanAssemblyGlobalEfficiency");
	}

	if (meanAssemblyLocalEfficiencyDistributionFile)
	{
		meanAssemblyLocalEfficiencyDistributionFile->openDistributionDataFile("MeanAssemblyLocalEfficiency");
	}

	if (meanAssemblyGlobalEfficiencyFile)
	{
		meanAssemblyGlobalEfficiencyFile->openAccuDataFile("MeanAssemblyGlobalEfficiency");
	}

	if (meanAssemblyLocalEfficiencyFile)
	{
		meanAssemblyLocalEfficiencyFile->openAccuDataFile("MeanAssemblyLocalEfficiency");
	}
		#endif
	#endif

	// Loop
	#ifdef _LOOP_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
		// Assembly
	// NbLoops
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingAssemblyNbLoopsDistributionFile)
	{
		ongoingAssemblyNbLoopsDistributionFile->openOngoingDistributionDataFile("AssemblyNbLoops");
	}
			#endif
			
	if (ongoingAssemblyNbLoopsFile)
	{
		ongoingAssemblyNbLoopsFile->openDataFile("Indexed_Sorted_OngoingAssemblyNbLoopsStat");
	}
	
			#ifdef _3D_ONGOING_STAT_MODE
	// Degree
	if (ongoingAssemblyNbLoopsDegreeDistributionFile)
	{
		ongoingAssemblyNbLoopsDegreeDistributionFile->openOngoingDistributionDataFile("AssemblyNbLoopsDegree");
	}
	// LoopSize
	if (ongoingAssemblyLoopSizeDistributionFile)
	{
		ongoingAssemblyLoopSizeDistributionFile->openOngoingDistributionDataFile("AssemblyLoopSize");
	}
			#endif
	


		// Cluster
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingClusterLoopSizeDistributionFile)
	{
		ongoingClusterLoopSizeDistributionFile->openOngoingDistributionDataFile("ClusterLoopSize");
	}
			#endif
			
	if (ongoingClusterNbLoopsFile)
	{
		ongoingClusterNbLoopsFile->openDataFile("Indexed_Sorted_OngoingClusterNbLoopsStat");
	}

			#ifdef _NETWORK_CLUSTER_STAT_MODE
			
	if (networkClusterLoopSizeDistributionFile)
	{
		networkClusterLoopSizeDistributionFile->openDataFile("Indexed_Sorted_NetworkClusterLoopSizeDistributionStat");
	}

				#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
				
	if (maxModularityClusterLoopSizeDistributionFile)
	{
		maxModularityClusterLoopSizeDistributionFile->openDataFile("Indexed_Sorted_MaxModularityClusterLoopSizeDistributionStat");
	}
				#endif
				
			#endif
		#else
	if (meanAssemblyLoopSizeDistributionFile)
	{
		meanAssemblyLoopSizeDistributionFile->openDistributionDataFile("MeanAssemblyLoopSize");
	}
	
	// Nb Loops
	if (meanAssemblyNbLoopsRepartitionFile)
	{
		meanAssemblyNbLoopsRepartitionFile->openDataFile("Indexed_Sorted_MeanAssemblyNbLoopsRepartitionStat");
	}
	
	if (meanAssemblyNbLoopsDistributionFile)
	{
		meanAssemblyNbLoopsDistributionFile->openDistributionDataFile("MeanAssemblyNbLoops");
	}
	
	// Degree
	if (meanAssemblyNbLoopsDegreeDistributionFile)
	{
		meanAssemblyNbLoopsDegreeDistributionFile->openDistributionDataFile("MeanAssemblyNbLoopsDegree");
	}
		#endif
	#endif
	
	// Small World
	#ifdef _SMALL_WORLD_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
	// Degree
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingAssemblyClusteringCoeffDegreeDistributionFile)
	{
		ongoingAssemblyClusteringCoeffDegreeDistributionFile->openOngoingDistributionDataFile("AssemblyClusteringCoeffDegree");
	}
	
	if (ongoingAssemblyClusteringCoeffDistributionFile)
	{
		ongoingAssemblyClusteringCoeffDistributionFile->openOngoingDistributionDataFile("AssemblyClusteringCoeff");
	}
			#endif
			
	// Cluster
	if (ongoingClusterInternalDensityFile)
	{
		ongoingClusterInternalDensityFile->openDataFile("Indexed_Sorted_OngoingClusterInternalDensityStat");
	}

	if (ongoingRealClusterInternalDensityFile)
	{
		ongoingRealClusterInternalDensityFile->openDataFile("Indexed_Sorted_OngoingRealClusterInternalDensityStat");
	}
	
			#ifdef _CLUSTER_CENTRALITY_STAT_MODE
				#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingLinkedClusterClusteringCoeffDegreeDistributionFile)
	{
		ongoingLinkedClusterClusteringCoeffDegreeDistributionFile->openOngoingDistributionDataFile("LinkedClusterClusteringCoeffDegree");
	}
	
	if (ongoingLinkedClusterClusteringCoeffDistributionFile)
	{
		ongoingLinkedClusterClusteringCoeffDistributionFile->openOngoingDistributionDataFile("LinkedClusterClusteringCoeff");
	}
				#endif
			#endif
			
			#ifdef _NETWORK_CLUSTER_STAT_MODE
	if (networkClusterInternalDensityFile)
	{
		networkClusterInternalDensityFile->openAccuDataFile("NetworkClusterInternalDensity");
	}
	
	if (networkRealClusterInternalDensityFile)
	{
		networkRealClusterInternalDensityFile->openAccuDataFile("NetworkRealClusterInternalDensity");
	}
				#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	if (networkLinkedClusterClusteringCoeffDegreeDistributionFile)
	{
		networkLinkedClusterClusteringCoeffDegreeDistributionFile->openDistributionDataFile("NetworkLinkedClusterClusteringCoeffDegree");
	}
	
	if (networkLinkedClusterClusteringCoeffDistributionFile)
	{
		networkLinkedClusterClusteringCoeffDistributionFile->openDistributionDataFile("NetworkLinkedClusterClusteringCoeff");
	}
				#endif
				
				#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
	if (maxModularityClusterInternalDensityFile)
	{
		maxModularityClusterInternalDensityFile->openAccuDataFile("MaxModularityClusterInternalDensity");
	}
	
	if (maxModularityRealClusterInternalDensityFile)
	{
		maxModularityRealClusterInternalDensityFile->openAccuDataFile("MaxModularityRealClusterInternalDensity");
	}
	
					#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	if (maxModularityLinkedClusterClusteringCoeffDegreeDistributionFile)
	{
		maxModularityLinkedClusterClusteringCoeffDegreeDistributionFile->openDistributionDataFile("MaxModularityLinkedClusterClusteringCoeffDegree");
	}
	
	if (maxModularityLinkedClusterClusteringCoeffDistributionFile)
	{
		maxModularityLinkedClusterClusteringCoeffDistributionFile->openDistributionDataFile("MaxModularityLinkedClusterClusteringCoeff");
	}
					#endif
				#endif
			#endif

		#else
	
	// Distribution
	if (meanClusteringCoeffDistributionFile)
	{
		meanClusteringCoeffDistributionFile->openDistributionDataFile("MeanClusteringCoeff");
	}
	
	// Degree
	if (meanClusteringCoeffDegreeDistributionFile)
	{
		meanClusteringCoeffDegreeDistributionFile->openDistributionDataFile("MeanClusteringCoeffDegree");
	}
	
	// Repartition
	if (meanClusteringCoeffRepartitionFile)
	{
		meanClusteringCoeffRepartitionFile->openDataFile("Indexed_Sorted_MeanClusteringCoeffRepartitionStat");
	}
	
	// Network
	if (meanClusteringCoeffFile)
	{
		meanClusteringCoeffFile->openAccuDataFile("MeanClusteringCoeff");
	}
	
		#endif
	#endif

	#ifdef _MOTIF_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingAssemblyBinodeMotifsFile)
	{
		ongoingAssemblyBinodeMotifsFile->openDataFile("Indexed_Sorted_OngoingAssemblyBinodeMotifsStat");
	}
	
	if (ongoingAssemblyTrinodeMotifsDistributionFile)
	{
		ongoingAssemblyTrinodeMotifsDistributionFile->openOngoingDistributionDataFile("AssemblyTrinodeMotifs");
	}
			#endif
			
			#ifdef _CLUSTER_CENTRALITY_STAT_MODE
				#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingLinkedClusterTrinodeMotifsDistributionFile)
	{
		ongoingLinkedClusterTrinodeMotifsDistributionFile->openOngoingDistributionDataFile("LinkedClusterTrinodeMotifs");
	}
				#endif
				
			#endif
			#ifdef _INTERNAL_MOTIF_STAT_MODE
				#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingClusterInternalBinodeMotifsFile)
	{
		ongoingClusterInternalBinodeMotifsFile->openDataFile("Indexed_Sorted_OngoingClusterInternalBinodeMotifsStat");
	}
	
	if (ongoingClusterInternalTrinodeMotifsDistributionFile)
	{
		ongoingClusterInternalTrinodeMotifsDistributionFile->openOngoingDistributionDataFile("ClusterInternalTrinodeMotifs");
	}
				#endif
				
				#ifdef _NETWORK_CLUSTER_STAT_MODE
	if (networkClusterInternalBinodeMotifsFile)
	{
		networkClusterInternalBinodeMotifsFile->openDataFile("NetworkClusterInternalBinodeMotifsStat");
	}
	
	if (networkClusterInternalTrinodeMotifsDistributionFile)
	{
		networkClusterInternalTrinodeMotifsDistributionFile->openDataFile("Indexed_Sorted_NetworkClusterInternalTrinodeMotifsDistributionStat");
	}
					#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	if (networkLinkedClusterTrinodeMotifsDistributionFile)
	{
		networkLinkedClusterTrinodeMotifsDistributionFile->openDataFile("Indexed_Sorted_NetworkLinkedClusterTrinodeMotifsDistributionStat");
	}				
					#endif
					
					#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
	if (maxModularityClusterInternalBinodeMotifsFile)
	{
		maxModularityClusterInternalBinodeMotifsFile->openDataFile("MaxModularityClusterInternalBinodeMotifsStat");
	}
	
	if (maxModularityClusterInternalTrinodeMotifsDistributionFile)
	{
		maxModularityClusterInternalTrinodeMotifsDistributionFile->openDataFile("Indexed_Sorted_MaxModularityClusterInternalTrinodeMotifsDistributionStat");
	}
						#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	if (maxModularityLinkedClusterTrinodeMotifsDistributionFile)
	{
		maxModularityLinkedClusterTrinodeMotifsDistributionFile->openDataFile("Indexed_Sorted_MaxModularityLinkedClusterTrinodeMotifsDistributionStat");
	}
						#endif
					#endif
				#endif
			#endif
		#else
	if (meanBinodeMotifsFile)
	{
		meanBinodeMotifsFile->openDataFile("MeanBinodeMotifsStat");
	}

	if (meanTrinodeMotifsDistributionFile)
	{
		meanTrinodeMotifsDistributionFile->openDataFile("Indexed_Sorted_MeanTrinodeMotifsDistributionStat");
	}
		#endif
	#endif
	
	#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingAssemblyReachedByInputDistributionFile)
	{
		ongoingAssemblyReachedByInputDistributionFile->openOngoingDistributionDataFile("AssemblyReachedByInput");
	}
	
	if (ongoingAssemblyReachedByOutputDistributionFile)
	{
		ongoingAssemblyReachedByOutputDistributionFile->openOngoingDistributionDataFile("AssemblyReachedByOutput");
	}
		
	if (ongoingAssemblyInputOutputPathLengthDistributionFile)
	{
		ongoingAssemblyInputOutputPathLengthDistributionFile->openOngoingDistributionDataFile("AssemblyInputOutputPathLength");
	}
	
	if (ongoingAssemblyPathToInputDistributionFile)
	{
		ongoingAssemblyPathToInputDistributionFile->openOngoingDistributionDataFile("AssemblyPathToInput");
	}
	
	if (ongoingAssemblyPathToOutputDistributionFile)
	{
		ongoingAssemblyPathToOutputDistributionFile->openOngoingDistributionDataFile("AssemblyPathToOutput");
	}
			#endif
		#else
	if (meanReachedByInputDistributionFile)
	{
		meanReachedByInputDistributionFile->openDistributionDataFile("MeanReachedByInput");
	}

	if (meanReachedByOutputDistributionFile)
	{
		meanReachedByOutputDistributionFile->openDistributionDataFile("MeanReachedByOutput");
	}

	if (meanPathToInputDistributionFile)
	{
		meanPathToInputDistributionFile->openDistributionDataFile("MeanPathToInput");
	}

	if (meanPathToOutputDistributionFile)
	{
		meanPathToOutputDistributionFile->openDistributionDataFile("MeanPathToOutput");
	}
	
	if (meanInputOutputPathLengthDistributionFile)
	{
		meanInputOutputPathLengthDistributionFile->openDistributionDataFile("MeanInputOutputPathLength");
	}
		#endif
	#endif
	
	#ifdef _DEGREE_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
	// Degree
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingAssemblyDegreeDistributionFile)
	{
		ongoingAssemblyDegreeDistributionFile->openOngoingDistributionDataFile("AssemblyDegree");
	}
	
	if (ongoingAssemblyPreDegreeDistributionFile)
	{
		ongoingAssemblyPreDegreeDistributionFile->openOngoingDistributionDataFile("AssemblyPreDegree");
	}
	
	if (ongoingAssemblyPostDegreeDistributionFile)
	{
		ongoingAssemblyPostDegreeDistributionFile->openOngoingDistributionDataFile("AssemblyPostDegree");
	}

	// Voisins
	if (ongoingAssemblyNearestNeighboursDegreeDistributionFile)
	{
		ongoingAssemblyNearestNeighboursDegreeDistributionFile->openOngoingDistributionDataFile("AssemblyNearestNeighboursDegree");
	}
			#endif
			
			#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE
	// In/Out
				#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingInputAssemblyDegreeDistributionFile)
	{
		ongoingInputAssemblyDegreeDistributionFile->openOngoingDistributionDataFile("InputAssemblyDegree");
	}
	
	if (ongoingOutputAssemblyDegreeDistributionFile)
	{
		ongoingOutputAssemblyDegreeDistributionFile->openOngoingDistributionDataFile("OutputAssemblyDegree");
	}
	
	// Voisins
	if (ongoingInputAssemblyNearestNeighboursDegreeDistributionFile)
	{
		ongoingInputAssemblyNearestNeighboursDegreeDistributionFile->openOngoingDistributionDataFile("InputAssemblyNearestNeighboursDegree");
	}
	
	if (ongoingOutputAssemblyNearestNeighboursDegreeDistributionFile)
	{
		ongoingOutputAssemblyNearestNeighboursDegreeDistributionFile->openOngoingDistributionDataFile("OutputAssemblyNearestNeighboursDegree");
	}
				#endif
			#endif
	
			#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	// Degree
				#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingLinkedClusterDegreeDistributionFile)
	{
		ongoingLinkedClusterDegreeDistributionFile->openOngoingDistributionDataFile("LinkedClusterDegree");
	}
	
	if (ongoingLinkedClusterPreDegreeDistributionFile)
	{
		ongoingLinkedClusterPreDegreeDistributionFile->openOngoingDistributionDataFile("LinkedClusterPreDegree");
	}
	
	if (ongoingLinkedClusterPostDegreeDistributionFile)
	{
		ongoingLinkedClusterPostDegreeDistributionFile->openOngoingDistributionDataFile("LinkedClusterPostDegree");
	}

	// Voisins
	if (ongoingLinkedClusterNearestNeighboursDegreeDistributionFile)
	{
		ongoingLinkedClusterNearestNeighboursDegreeDistributionFile->openOngoingDistributionDataFile("LinkedClusterNearestNeighboursDegree");
	}
				#endif
				
				#ifdef _NETWORK_CLUSTER_STAT_MODE
	// Degree
	if (networkLinkedClusterDegreeDistributionFile)
	{
		networkLinkedClusterDegreeDistributionFile->openDistributionDataFile("NetworkLinkedClusterDegree");
	}
	
	if (networkLinkedClusterPreDegreeDistributionFile)
	{
		networkLinkedClusterPreDegreeDistributionFile->openDistributionDataFile("NetworkLinkedClusterPreDegree");
	}
	
	if (networkLinkedClusterPostDegreeDistributionFile)
	{
		networkLinkedClusterPostDegreeDistributionFile->openDistributionDataFile("NetworkLinkedClusterPostDegree");
	}

	// Voisins
	if (networkLinkedClusterNearestNeighboursDegreeDistributionFile)
	{
		networkLinkedClusterNearestNeighboursDegreeDistributionFile->openDistributionDataFile("NetworkLinkedClusterNearestNeighboursDegree");
	}
					#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
	// Degree
	if (maxModularityLinkedClusterDegreeDistributionFile)
	{
		maxModularityLinkedClusterDegreeDistributionFile->openDistributionDataFile("MaxModularityLinkedClusterDegree");
	}
	
	if (maxModularityLinkedClusterPreDegreeDistributionFile)
	{
		maxModularityLinkedClusterPreDegreeDistributionFile->openDistributionDataFile("MaxModularityLinkedClusterPreDegree");
	}
	
	if (maxModularityLinkedClusterPostDegreeDistributionFile)
	{
		maxModularityLinkedClusterPostDegreeDistributionFile->openDistributionDataFile("MaxModularityLinkedClusterPostDegree");
	}

	// Voisins
	if (maxModularityLinkedClusterNearestNeighboursDegreeDistributionFile)
	{
		maxModularityLinkedClusterNearestNeighboursDegreeDistributionFile->openDistributionDataFile("MaxModularityLinkedClusterNearestNeighboursDegree");
	}
						
					#endif
				#endif
			#endif
			
		#else
	if (meanDegreeDistributionFile)
	{
		meanDegreeDistributionFile->openDistributionDataFile("MeanDegree");
	}
	
	if (meanPreDegreeDistributionFile)
	{
		meanPreDegreeDistributionFile->openDistributionDataFile("MeanPreDegree");
	}
	
	if (meanPostDegreeDistributionFile)
	{
		meanPostDegreeDistributionFile->openDistributionDataFile("MeanPostDegree");
	}

	if (meanNearestNeighboursDegreeDistributionFile)
	{
		meanNearestNeighboursDegreeDistributionFile->openDistributionDataFile("MeanNearestNeighboursDegree");
	}
	
			#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE
	// In/Out
	if (meanInputAssemblyDegreeDistributionFile)
	{
		meanInputAssemblyDegreeDistributionFile->openDistributionDataFile("MeanInputAssemblyDegree");
	}
	
	if (meanOutputAssemblyDegreeDistributionFile)
	{
		meanOutputAssemblyDegreeDistributionFile->openDistributionDataFile("MeanOutputAssemblyDegree");
	}
	
	if (meanInputAssemblyNearestNeighboursDegreeDistributionFile)
	{
		meanInputAssemblyNearestNeighboursDegreeDistributionFile->openDistributionDataFile("MeanInputAssemblyNearestNeighboursDegree");
	}
	
	if (meanOutputAssemblyNearestNeighboursDegreeDistributionFile)
	{
		meanOutputAssemblyNearestNeighboursDegreeDistributionFile->openDistributionDataFile("MeanOutputAssemblyNearestNeighboursDegree");
	}
			#endif
		#endif
	#endif

	#ifdef _GSCC_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
	if (ongoingNbGSCCNodesFile)
	{
		ongoingNbGSCCNodesFile->openDataFile("Indexed_Sorted_OngoingNbGSCCNodesStat");
	}
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingSCComponentSizeDistributionFile)
	{
		ongoingSCComponentSizeDistributionFile->openOngoingDistributionDataFile("SCComponentSize");
	}
			#endif
			
	if (ongoingMaxSCComponentSizeFile)
	{
		ongoingMaxSCComponentSizeFile->openDataFile("Indexed_Sorted_OngoingMaxSCComponentSizeStat");
	}
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingMaxSCComponentSizeDistributionFile)
	{
		ongoingMaxSCComponentSizeDistributionFile->openOngoingDistributionDataFile("MaxSCComponentSize");
	}
			#endif
	/*
	if (meanAssemblyDiameterSizeDistributionFile)
	{
		meanAssemblyDiameterSizeDistributionFile->openDistributionDataFile("MeanAssemblyDiameterSize");
	}
	*/
		#else
	if (meanNbGSCCNodesFile)
	{
		meanNbGSCCNodesFile->openAccuDataFile("MeanNbGSCCNodes");
	}

	if (meanSCComponentSizeDistributionFile)
	{
		meanSCComponentSizeDistributionFile->openDistributionDataFile("MeanSCComponentSize");
	}

	if (meanMaxSCComponentSizeFile)
	{
		meanMaxSCComponentSizeFile->openAccuDataFile("MeanMaxSCComponentSize");
	}

	if (meanMaxSCComponentSizeDistributionFile)
	{
		meanMaxSCComponentSizeDistributionFile->openDistributionDataFile("MeanMaxSCComponentSize");
	}
			
			#ifdef _INPUT_OUTPUT_GSCC_STAT_MODE		
	
	if (meanInputSCComponentSizeDistributionFile)
	{
		meanInputSCComponentSizeDistributionFile->openDistributionDataFile("MeanInputSCComponentSize");
	}
	
	
	if (meanOutputSCComponentSizeDistributionFile)
	{
		meanOutputSCComponentSizeDistributionFile->openDistributionDataFile("MeanOutputSCComponentSize");
	}


	if (meanInputSCCFractionRepartitionFile)
	{
		meanInputSCCFractionRepartitionFile->openDataFile("Indexed_Sorted_MeanInputSCCFractionRepartitionStat");
	}

	if (meanOutputSCCFractionRepartitionFile)
	{
		meanOutputSCCFractionRepartitionFile->openDataFile("Indexed_Sorted_MeanOutputSCCFractionRepartitionStat");
	}
			#endif
		#endif
	#endif
	
	#ifdef _PROJECTION_STAT_MODE
	
	if (meanProjectionsFile)
	{
		meanProjectionsFile->openAccuDataFile("MeanProjections");
	}

	if (meanExcitProjectionsFile)
	{
		meanExcitProjectionsFile->openAccuDataFile("MeanExcitProjections");
	}

	if (meanInhibProjectionsFile)
	{
		meanInhibProjectionsFile->openAccuDataFile("MeanInhibProjections");
	}

	if (meanExcitInputProjectionsFile)
	{
		meanExcitInputProjectionsFile->openAccuDataFile("MeanExcitInputProjections");
	}

	if (meanInhibInputProjectionsFile)
	{
		meanInhibInputProjectionsFile->openAccuDataFile("MeanInhibInputProjections");
	}

	if (meanExcitOutputProjectionsFile)
	{
		meanExcitOutputProjectionsFile->openAccuDataFile("MeanExcitOutputProjections");
	}

	if (meanInhibOutputProjectionsFile)
	{
		meanInhibOutputProjectionsFile->openAccuDataFile("MeanInhibOutputProjections");
	}

	if (meanExcitSelfProjectionsFile)
	{
		meanExcitSelfProjectionsFile->openAccuDataFile("MeanExcitSelfProjections");
	}

	if (meanInhibSelfProjectionsFile)
	{
		meanInhibSelfProjectionsFile->openAccuDataFile("MeanInhibSelfProjections");
	}
	#endif
	
	
	#ifdef _INPUT_OUTPUT_CLUSTER_STAT_MODE		
	
	if (maxModularityInputClusterSizeDistributionFile)
	{
		maxModularityInputClusterSizeDistributionFile->openDistributionDataFile("MaxModularityInputClusterSize");
	}
	
	if (maxModularityOutputClusterSizeDistributionFile)
	{
		maxModularityOutputClusterSizeDistributionFile->openDistributionDataFile("MaxModularityOutputClusterSize");
	}

	if (maxModularityInputClusterFractionRepartitionFile)
	{
		maxModularityInputClusterFractionRepartitionFile->openDataFile("Indexed_Sorted_MaxModularityInputClusterFractionRepartitionStat");
	}

	if (maxModularityOutputClusterFractionRepartitionFile)
	{
		maxModularityOutputClusterFractionRepartitionFile->openDataFile("Indexed_Sorted_MaxModularityOutputClusterFractionRepartitionStat");
	}
	#endif
#endif
}

void NetworkStater::closeTracer()
{	
#ifdef _NETWORK_STAT_MODE
	
	#ifdef _TOPOLOGY_STAT_MODE
	if (topologyMatrixFile->isOpen())
	{
		topologyMatrixFile->closeFile();
	}
	#endif
	
	#ifdef _LINK_TO_INPUT_STAT_MODE
	if (linkToInputFile->isOpen())
	{
		linkToInputFile->closeFile();
	}
	#endif
	
	#ifdef _LINK_TO_OUTPUT_STAT_MODE
	if (linkToOutputFile->isOpen())
	{
		linkToOutputFile->closeFile();
	}
	#endif
	
	#ifdef _MATRIX_CLUSTERS_STAT_MODE
	if (clusterMatrixFile->isOpen())
	{
		clusterMatrixFile->closeFile();
	}
	#endif
	
	#ifdef _CENTRALITY_STAT_MODE

		#ifdef _CLUSTER_STAT_MODE
		// Assemblees
	// Calcul de centralité
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingAssemblyCentralBetweennessDistributionFile->isOpen())
	{
		ongoingAssemblyCentralBetweennessDistributionFile->closeOngoingDistributionDataFile();
	}
			#endif
			
	if (ongoingAssemblyCentralBetweennessFile->isOpen())
	{
		ongoingAssemblyCentralBetweennessFile->closeFile();
	}

	// Centralite de noeuds
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingAssemblyBetweennessDistributionFile->isOpen())
	{
		ongoingAssemblyBetweennessDistributionFile->closeOngoingDistributionDataFile();
	}
			#endif
			
	if (ongoingAssemblyBetweennessFile->isOpen())
	{
		ongoingAssemblyBetweennessFile->closeFile();
	}

	// Efficacité du réseau au fur et à mesure de la suppression
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingAssemblyGlobalEfficiencyDistributionFile->isOpen())
	{
		ongoingAssemblyGlobalEfficiencyDistributionFile->closeOngoingDistributionDataFile();
	}
			#endif
			
	if (ongoingAssemblyGlobalEfficiencyFile->isOpen())
	{
		ongoingAssemblyGlobalEfficiencyFile->closeFile();
	}

			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingAssemblyLocalEfficiencyDistributionFile->isOpen())
	{
		ongoingAssemblyLocalEfficiencyDistributionFile->closeOngoingDistributionDataFile();
	}
			#endif
			
	if (ongoingAssemblyLocalEfficiencyFile->isOpen())
	{
		ongoingAssemblyLocalEfficiencyFile->closeFile();
	}
			
			#ifdef _EDGE_BETWEENNESS_STAT_MODE
	// Intermediarité de liens
				#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingAssemblyEdgeBetweennessDistributionFile->isOpen())
	{
		ongoingAssemblyEdgeBetweennessDistributionFile->closeOngoingDistributionDataFile();
	}
				#endif
				
	if (ongoingAssemblyMaxEdgeBetweennessFile->isOpen())
	{
		ongoingAssemblyMaxEdgeBetweennessFile->closeFile();
	}
			#endif
			
	// ShortPath
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingAssemblyShortPathLengthDistributionFile->isOpen())
	{
		ongoingAssemblyShortPathLengthDistributionFile->closeFile();
	}
			#endif
			
		// Clusters
	if (ongoingClusterModularityFile->isOpen())
	{
		ongoingClusterModularityFile->closeFile();
	}

	// Nombre de clusters
	if (ongoingNbClustersFile->isOpen())
	{
		ongoingNbClustersFile->closeFile();
	}

	if (ongoingMaxClusterSizesFile->isOpen())
	{
		ongoingMaxClusterSizesFile->closeFile();
	}
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingClusterSizeDistributionFile->isOpen())
	{
		ongoingClusterSizeDistributionFile->closeOngoingDistributionDataFile();
	}
			
	// Repartition de l'efficacité des clusters
	if (ongoingClusterEfficiencyDistributionFile->isOpen())
	{
		ongoingClusterEfficiencyDistributionFile->closeOngoingDistributionDataFile();
	}
			#endif
			
	if (ongoingClusterEfficiencyFile->isOpen())
	{
		ongoingClusterEfficiencyFile->closeFile();
	}

			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingClusterRealEfficiencyDistributionFile->isOpen())
	{
		ongoingClusterRealEfficiencyDistributionFile->closeOngoingDistributionDataFile();
	}
			#endif
			
	if (ongoingClusterRealEfficiencyFile->isOpen())
	{
		ongoingClusterRealEfficiencyFile->closeFile();
	}

			#ifdef _LINKED_CLUSTER_STAT_MODE
	if (ongoingInDCFile->isOpen())
	{
		ongoingInDCFile->closeFile();
	}

	if (ongoingInGOUTFile->isOpen())
	{
		ongoingInGOUTFile->closeFile();
	}

	if (ongoingInGINFile->isOpen())
	{
		ongoingInGINFile->closeFile();
	}

	if (ongoingInGSCCFile->isOpen())
	{
		ongoingInGSCCFile->closeFile();
	}
	
				#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	// Efficacite
					#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingLinkedClusterGlobalEfficiencyDistributionFile->isOpen())
	{
		ongoingLinkedClusterGlobalEfficiencyDistributionFile->closeOngoingDistributionDataFile();
	}
					#endif
					
	if (ongoingLinkedClusterGlobalEfficiencyFile->isOpen())
	{
		ongoingLinkedClusterGlobalEfficiencyFile->closeFile();
	}

					#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingLinkedClusterLocalEfficiencyDistributionFile->isOpen())
	{
		ongoingLinkedClusterLocalEfficiencyDistributionFile->closeOngoingDistributionDataFile();
	}
					#endif

	if (ongoingLinkedClusterLocalEfficiencyFile->isOpen())
	{
		ongoingLinkedClusterLocalEfficiencyFile->closeFile();
	}

					
					#ifdef _EDGE_BETWEENNESS_STAT_MODE
	// Intermediarite de liens
						#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingLinkedClusterEdgeBetweennessDistributionFile->isOpen())
	{
		ongoingLinkedClusterEdgeBetweennessDistributionFile->closeOngoingDistributionDataFile();
	}
						#endif
						
	if (ongoingLinkedClusterMaxEdgeBetweennessFile->isOpen())
	{
		ongoingLinkedClusterMaxEdgeBetweennessFile->closeFile();
	}
					#endif
					
	// Calcul de centralité
					#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingLinkedClusterCentralBetweennessDistributionFile->isOpen())
	{
		ongoingLinkedClusterCentralBetweennessDistributionFile->closeOngoingDistributionDataFile();
	}
					#endif
					
	if (ongoingLinkedClusterCentralBetweennessFile->isOpen())
	{
		ongoingLinkedClusterCentralBetweennessFile->closeFile();
	}

	// Centralite de noeuds
					#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingLinkedClusterBetweennessDistributionFile->isOpen())
	{
		ongoingLinkedClusterBetweennessDistributionFile->closeOngoingDistributionDataFile();
	}
					#endif
					
	if (ongoingLinkedClusterBetweennessFile->isOpen())
	{
		ongoingLinkedClusterBetweennessFile->closeFile();
	}

	// ShortPath
					#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingLinkedClusterShortPathLengthDistributionFile->isOpen())
	{
		ongoingLinkedClusterShortPathLengthDistributionFile->closeOngoingDistributionDataFile();
	}	
					#endif
				#endif
			#endif

			#ifdef _NETWORK_CLUSTER_STAT_MODE
				#ifdef _LINKED_CLUSTER_STAT_MODE
	if (networkComponentRepartitionFile->isOpen())
	{
		networkComponentRepartitionFile->closeFile();
	}
				#endif

	if (networkClusterSizeDistributionFile->isOpen())
	{
		networkClusterSizeDistributionFile->closeFile();
	}

	// Efficacite
	if (networkClusterEfficiencyDistributionFile->isOpen())
	{
		networkClusterEfficiencyDistributionFile->closeFile();
	}

	if (networkClusterEfficiencyFile->isOpen())
	{
		networkClusterEfficiencyFile->closeAccuDataFile();
	}
	
	if (networkClusterRealEfficiencyDistributionFile->isOpen())
	{
		networkClusterRealEfficiencyDistributionFile->closeFile();
	}
	if (networkClusterRealEfficiencyFile->isOpen())
	{
		networkClusterRealEfficiencyFile->closeAccuDataFile();
	}
				#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
	// Nombre de suppression de liens pour atteindre le réseau optimal
	if (maxModularityProjectionIndexFile->isOpen())
	{
		maxModularityProjectionIndexFile->closeAccuDataFile();
	}

	// Modularité maximale
	if (maxModularityFile->isOpen())
	{
		maxModularityFile->closeAccuDataFile();
	}
					#ifdef _LINKED_CLUSTER_STAT_MODE
	// Repartition des clusters dans les composants pour le réseau optimal
	if (maxModularityComponentRepartitionFile->isOpen())
	{
		maxModularityComponentRepartitionFile->closeFile();
	}
					#endif

	// Repartition de la taille des clusters pour le réseau optimal
	if (maxModularityClusterSizeDistributionFile->isOpen())
	{
		maxModularityClusterSizeDistributionFile->closeFile();
	}

	// Repartition de l'efficacité des clusters pour le réseau optimal
	if (maxModularityClusterEfficiencyDistributionFile->isOpen())
	{
		maxModularityClusterEfficiencyDistributionFile->closeFile();
	}

	if (maxModularityClusterEfficiencyFile->isOpen())
	{
		maxModularityClusterEfficiencyFile->closeAccuDataFile();
	}
	
	if (maxModularityClusterRealEfficiencyDistributionFile->isOpen())
	{
		maxModularityClusterRealEfficiencyDistributionFile->closeFile();
	}
	if (maxModularityClusterRealEfficiencyFile->isOpen())
	{
		maxModularityClusterRealEfficiencyFile->closeAccuDataFile();
	}
				#endif
			#endif
		#else

	// Calcul d'intermediarité
	if (meanAssemblyBetweennessRepartitionFile->isOpen())
	{
		meanAssemblyBetweennessRepartitionFile->closeFile();
	}

	if (meanAssemblyBetweennessFile->isOpen())
	{
		meanAssemblyBetweennessFile->closeAccuDataFile();
	}

	if (meanAssemblyBetweennessDistributionFile->isOpen())
	{
		meanAssemblyBetweennessDistributionFile->closeFile();
	}

	// Calcul de centralité
	if (meanAssemblyCentralBetweennessRepartitionFile->isOpen())
	{
		meanAssemblyCentralBetweennessRepartitionFile->closeFile();
	}

	if (meanAssemblyCentralBetweennessFile->isOpen())
	{
		meanAssemblyCentralBetweennessFile->closeAccuDataFile();
	}

	if (meanAssemblyCentralBetweennessDistributionFile->isOpen())
	{
		meanAssemblyCentralBetweennessDistributionFile->closeFile();
	}
			
			#ifdef _EDGE_BETWEENNESS_STAT_MODE
	// Calcul d'intermediarité pour les liens
	if (meanEdgeBetweennessRepartitionFile->isOpen())
	{
		meanEdgeBetweennessRepartitionFile->closeFile();
	}

	if (meanEdgeBetweennessDistributionFile->isOpen())
	{
		meanEdgeBetweennessDistributionFile->closeFile();
	}
			#endif
			
	// Repartition des short paths
	if (meanAssemblyShortPathRepartitionFile->isOpen())
	{
		meanAssemblyShortPathRepartitionFile->closeFile();
	}

	if (meanAssemblyNoShortPathRepartitionFile->isOpen())
	{
		meanAssemblyNoShortPathRepartitionFile->closeFile();
	}
	
	if (meanAssemblyNbShortPathDistributionFile->isOpen())
	{
		meanAssemblyNbShortPathDistributionFile->closeFile();
	}

	// Calcul d'efficacite
	if (meanAssemblyLocalEfficiencyRepartitionFile->isOpen())
	{
		meanAssemblyLocalEfficiencyRepartitionFile->closeFile();
	}

	if (meanAssemblyGlobalEfficiencyRepartitionFile->isOpen())
	{
		meanAssemblyGlobalEfficiencyRepartitionFile->closeFile();
	}

	if (meanAssemblyLocalEfficiencyDistributionFile->isOpen())
	{
		meanAssemblyLocalEfficiencyDistributionFile->closeFile();
	}

	if (meanAssemblyGlobalEfficiencyDistributionFile->isOpen())
	{
		meanAssemblyGlobalEfficiencyDistributionFile->closeFile();
	}

	if (meanAssemblyGlobalEfficiencyFile->isOpen())
	{
		meanAssemblyGlobalEfficiencyFile->closeAccuDataFile();
	}

	if (meanAssemblyLocalEfficiencyFile->isOpen())
	{
		meanAssemblyLocalEfficiencyFile->closeAccuDataFile();
	}
		#endif
	#endif

	// Loops
	#ifdef _LOOP_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
		// Assembly
	// NbLoops
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingAssemblyNbLoopsDistributionFile->isOpen())
	{
		ongoingAssemblyNbLoopsDistributionFile->closeOngoingDistributionDataFile();
	}
			#endif
			
	if (ongoingAssemblyNbLoopsFile->isOpen())
	{
		ongoingAssemblyNbLoopsFile->closeFile();
	}
	
	// Degree
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingAssemblyNbLoopsDegreeDistributionFile->isOpen())
	{
		ongoingAssemblyNbLoopsDegreeDistributionFile->closeOngoingDistributionDataFile();
	}
	
	// Loop Size
	if (ongoingAssemblyLoopSizeDistributionFile->isOpen())
	{
		ongoingAssemblyLoopSizeDistributionFile->closeOngoingDistributionDataFile();
	}
			#endif
	
		// Cluster
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingClusterLoopSizeDistributionFile->isOpen())
	{
		ongoingClusterLoopSizeDistributionFile->closeOngoingDistributionDataFile();
	}
			#endif
			
	if (ongoingClusterNbLoopsFile->isOpen())
	{
		ongoingClusterNbLoopsFile->closeFile();
	}
			#ifdef _NETWORK_CLUSTER_STAT_MODE
	if (networkClusterLoopSizeDistributionFile->isOpen())
	{
		networkClusterLoopSizeDistributionFile->closeFile();
	}

				#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
				
	if (maxModularityClusterLoopSizeDistributionFile->isOpen())
	{
		maxModularityClusterLoopSizeDistributionFile->closeFile();
	}
				#endif
				
			#endif
		#else
	// Loop size
	if (meanAssemblyLoopSizeDistributionFile->isOpen())
	{
		meanAssemblyLoopSizeDistributionFile->closeFile();
	}

	// Nb Loops
	if (meanAssemblyNbLoopsRepartitionFile->isOpen())
	{
		meanAssemblyNbLoopsRepartitionFile->closeFile();
	}
	
	if (meanAssemblyNbLoopsDistributionFile->isOpen())
	{
		meanAssemblyNbLoopsDistributionFile->closeFile();
	}

	// Degree
	if (meanAssemblyNbLoopsDegreeDistributionFile->isOpen())
	{
		meanAssemblyNbLoopsDegreeDistributionFile->closeFile();
	}
		#endif
	#endif
	
	#ifdef _SMALL_WORLD_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
	// Degree
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingAssemblyClusteringCoeffDegreeDistributionFile->isOpen())
	{
		ongoingAssemblyClusteringCoeffDegreeDistributionFile->closeOngoingDistributionDataFile();
	}
	
	if (ongoingAssemblyClusteringCoeffDistributionFile->isOpen())
	{
		ongoingAssemblyClusteringCoeffDistributionFile->closeOngoingDistributionDataFile();
	}
			#endif
	// Cluster
	if (ongoingClusterInternalDensityFile->isOpen())
	{
		ongoingClusterInternalDensityFile->closeFile();
	}
	if (ongoingRealClusterInternalDensityFile->isOpen())
	{
		ongoingRealClusterInternalDensityFile->closeFile();
	}
	
			#ifdef _CLUSTER_CENTRALITY_STAT_MODE
				#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingLinkedClusterClusteringCoeffDegreeDistributionFile->isOpen())
	{
		ongoingLinkedClusterClusteringCoeffDegreeDistributionFile->closeOngoingDistributionDataFile();
	}
	
	if (ongoingLinkedClusterClusteringCoeffDistributionFile->isOpen())
	{
		ongoingLinkedClusterClusteringCoeffDistributionFile->closeOngoingDistributionDataFile();
	}
				#endif
			#endif
	
			#ifdef _NETWORK_CLUSTER_STAT_MODE
	if (networkClusterInternalDensityFile->isOpen())
	{
		networkClusterInternalDensityFile->closeAccuDataFile();
	}
	
	if (networkRealClusterInternalDensityFile->isOpen())
	{
		networkRealClusterInternalDensityFile->closeAccuDataFile();
	}
				#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	if (networkLinkedClusterClusteringCoeffDegreeDistributionFile->isOpen())
	{
		networkLinkedClusterClusteringCoeffDegreeDistributionFile->closeFile();
	}
	
	if (networkLinkedClusterClusteringCoeffDistributionFile->isOpen())
	{
		networkLinkedClusterClusteringCoeffDistributionFile->closeFile();
	}
				#endif
				
				#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
	if (maxModularityClusterInternalDensityFile->isOpen())
	{
		maxModularityClusterInternalDensityFile->closeAccuDataFile();
	}
	
	if (maxModularityRealClusterInternalDensityFile->isOpen())
	{
		maxModularityRealClusterInternalDensityFile->closeAccuDataFile();
	}
	
					#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	if (maxModularityLinkedClusterClusteringCoeffDegreeDistributionFile->isOpen())
	{
		maxModularityLinkedClusterClusteringCoeffDegreeDistributionFile->closeFile();
	}
	
	if (maxModularityLinkedClusterClusteringCoeffDistributionFile->isOpen())
	{
		maxModularityLinkedClusterClusteringCoeffDistributionFile->closeFile();
	}
					#endif
				#endif
			#endif

		#else
	// Distribution
	if (meanClusteringCoeffDistributionFile->isOpen())
	{
		meanClusteringCoeffDistributionFile->closeFile();
	}
	
	// Degree
	if (meanClusteringCoeffDegreeDistributionFile->isOpen())
	{
		meanClusteringCoeffDegreeDistributionFile->closeFile();
	}
	
	// Repartition
	if (meanClusteringCoeffRepartitionFile->isOpen())
	{
		meanClusteringCoeffRepartitionFile->closeFile();
	}
	
	// Network
	if (meanClusteringCoeffFile->isOpen())
	{
		meanClusteringCoeffFile->closeAccuDataFile();
	}
		#endif
	#endif

	#ifdef _MOTIF_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingAssemblyBinodeMotifsFile->isOpen())
	{
		ongoingAssemblyBinodeMotifsFile->closeFile();
	}
	
	if (ongoingAssemblyTrinodeMotifsDistributionFile->isOpen())
	{
		ongoingAssemblyTrinodeMotifsDistributionFile->closeOngoingDistributionDataFile();
	}
			#endif
			
			#ifdef _CLUSTER_CENTRALITY_STAT_MODE
				#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingLinkedClusterTrinodeMotifsDistributionFile->isOpen())
	{
		ongoingLinkedClusterTrinodeMotifsDistributionFile->closeOngoingDistributionDataFile();
	}
				#endif
			#endif
			
			#ifdef _INTERNAL_MOTIF_STAT_MODE
				#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingClusterInternalBinodeMotifsFile->isOpen())
	{
		ongoingClusterInternalBinodeMotifsFile->closeFile();
	}
	
	if (ongoingClusterInternalTrinodeMotifsDistributionFile->isOpen())
	{
		ongoingClusterInternalTrinodeMotifsDistributionFile->closeOngoingDistributionDataFile();
	}
				#endif
				
				#ifdef _NETWORK_CLUSTER_STAT_MODE
	if (networkClusterInternalBinodeMotifsFile->isOpen())
	{
		networkClusterInternalBinodeMotifsFile->closeFile();
	}
	
	if (networkClusterInternalTrinodeMotifsDistributionFile->isOpen())
	{
		networkClusterInternalTrinodeMotifsDistributionFile->closeFile();
	}
					#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	if (networkLinkedClusterTrinodeMotifsDistributionFile->isOpen())
	{
		networkLinkedClusterTrinodeMotifsDistributionFile->closeFile();
	}				
					#endif
	
					#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
	if (maxModularityClusterInternalBinodeMotifsFile->isOpen())
	{
		maxModularityClusterInternalBinodeMotifsFile->closeFile();
	}
	
	if (maxModularityClusterInternalTrinodeMotifsDistributionFile->isOpen())
	{
		maxModularityClusterInternalTrinodeMotifsDistributionFile->closeFile();
	}
						#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	if (maxModularityLinkedClusterTrinodeMotifsDistributionFile->isOpen())
	{
		maxModularityLinkedClusterTrinodeMotifsDistributionFile->closeFile();
	}
						#endif
					#endif
				#endif
			#endif
		#else
	if (meanBinodeMotifsFile->isOpen())
	{
		meanBinodeMotifsFile->closeFile();
	}

	if (meanTrinodeMotifsDistributionFile->isOpen())
	{
		meanTrinodeMotifsDistributionFile->closeFile();
	}
		#endif
	#endif
	
	#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingAssemblyReachedByInputDistributionFile->isOpen())
	{
		ongoingAssemblyReachedByInputDistributionFile->closeOngoingDistributionDataFile();
	}
	
	if (ongoingAssemblyReachedByOutputDistributionFile->isOpen())
	{
		ongoingAssemblyReachedByOutputDistributionFile->closeOngoingDistributionDataFile();
	}
		
	if (ongoingAssemblyInputOutputPathLengthDistributionFile->isOpen())
	{
		ongoingAssemblyInputOutputPathLengthDistributionFile->closeOngoingDistributionDataFile();
	}
	
	if (ongoingAssemblyPathToInputDistributionFile->isOpen())
	{
		ongoingAssemblyPathToInputDistributionFile->closeOngoingDistributionDataFile();
	}
	
	if (ongoingAssemblyPathToOutputDistributionFile->isOpen())
	{
		ongoingAssemblyPathToOutputDistributionFile->closeOngoingDistributionDataFile();
	}
			#endif
		#else
	if (meanReachedByInputDistributionFile->isOpen())
	{
		meanReachedByInputDistributionFile->closeFile();
	}

	if (meanReachedByOutputDistributionFile->isOpen())
	{
		meanReachedByOutputDistributionFile->closeFile();
	}

	if (meanPathToInputDistributionFile->isOpen())
	{
		meanPathToInputDistributionFile->closeFile();
	}

	if (meanPathToOutputDistributionFile->isOpen())
	{
		meanPathToOutputDistributionFile->closeFile();
	}
	
	if (meanInputOutputPathLengthDistributionFile->isOpen())
	{
		meanInputOutputPathLengthDistributionFile->closeFile();
	}
		#endif
	#endif
	
	#ifdef _DEGREE_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingAssemblyDegreeDistributionFile->isOpen())
	{
		ongoingAssemblyDegreeDistributionFile->closeOngoingDistributionDataFile();
	}
	
	if (ongoingAssemblyPreDegreeDistributionFile->isOpen())
	{
		ongoingAssemblyPreDegreeDistributionFile->closeOngoingDistributionDataFile();
	}
	
	if (ongoingAssemblyPostDegreeDistributionFile->isOpen())
	{
		ongoingAssemblyPostDegreeDistributionFile->closeOngoingDistributionDataFile();
	}
	
	// Voisins
	if (ongoingAssemblyNearestNeighboursDegreeDistributionFile->isOpen())
	{
		ongoingAssemblyNearestNeighboursDegreeDistributionFile->closeOngoingDistributionDataFile();
	}
			#endif
			
			#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE
	// In/Out
				#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingInputAssemblyDegreeDistributionFile->isOpen())
	{
		ongoingInputAssemblyDegreeDistributionFile->closeOngoingDistributionDataFile();
	}
	
	if (ongoingOutputAssemblyDegreeDistributionFile->isOpen())
	{
		ongoingOutputAssemblyDegreeDistributionFile->closeOngoingDistributionDataFile();
	}
	
	// Voisins
	if (ongoingInputAssemblyNearestNeighboursDegreeDistributionFile->isOpen())
	{
		ongoingInputAssemblyNearestNeighboursDegreeDistributionFile->closeOngoingDistributionDataFile();
	}
	
	if (ongoingOutputAssemblyNearestNeighboursDegreeDistributionFile->isOpen())
	{
		ongoingOutputAssemblyNearestNeighboursDegreeDistributionFile->closeOngoingDistributionDataFile();
	}
				#endif
			#endif
			
			#ifdef _CLUSTER_CENTRALITY_STAT_MODE
				#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingLinkedClusterDegreeDistributionFile->isOpen())
	{
		ongoingLinkedClusterDegreeDistributionFile->closeFile();
	}
	
	if (ongoingLinkedClusterPreDegreeDistributionFile->isOpen())
	{
		ongoingLinkedClusterPreDegreeDistributionFile->closeFile();
	}
	
	if (ongoingLinkedClusterPostDegreeDistributionFile->isOpen())
	{
		ongoingLinkedClusterPostDegreeDistributionFile->closeFile();
	}

	// Voisins
	if (ongoingLinkedClusterNearestNeighboursDegreeDistributionFile->isOpen())
	{
		ongoingLinkedClusterNearestNeighboursDegreeDistributionFile->closeFile();
	}
				#endif
				
				#ifdef _NETWORK_CLUSTER_STAT_MODE
	if (networkLinkedClusterDegreeDistributionFile->isOpen())
	{
		networkLinkedClusterDegreeDistributionFile->closeFile();
	}
	
	if (networkLinkedClusterPreDegreeDistributionFile->isOpen())
	{
		networkLinkedClusterPreDegreeDistributionFile->closeFile();
	}
	
	if (networkLinkedClusterPostDegreeDistributionFile->isOpen())
	{
		networkLinkedClusterPostDegreeDistributionFile->closeFile();
	}

	// Voisins
	if (networkLinkedClusterNearestNeighboursDegreeDistributionFile->isOpen())
	{
		networkLinkedClusterNearestNeighboursDegreeDistributionFile->closeFile();
	}
					#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
	if (maxModularityLinkedClusterDegreeDistributionFile->isOpen())
	{
		maxModularityLinkedClusterDegreeDistributionFile->closeFile();
	}
	
	if (maxModularityLinkedClusterPreDegreeDistributionFile->isOpen())
	{
		maxModularityLinkedClusterPreDegreeDistributionFile->closeFile();
	}
	
	if (maxModularityLinkedClusterPostDegreeDistributionFile->isOpen())
	{
		maxModularityLinkedClusterPostDegreeDistributionFile->closeFile();
	}

	// Voisins
	if (maxModularityLinkedClusterNearestNeighboursDegreeDistributionFile->isOpen())
	{
		maxModularityLinkedClusterNearestNeighboursDegreeDistributionFile->closeFile();
	}
					#endif
				#endif
			#endif
			
		#else
	// Degree
	if (meanDegreeDistributionFile->isOpen())
	{
		meanDegreeDistributionFile->closeFile();
	}

	if (meanPreDegreeDistributionFile->isOpen())
	{
		meanPreDegreeDistributionFile->closeFile();
	}
	
	if (meanPostDegreeDistributionFile->isOpen())
	{
		meanPostDegreeDistributionFile->closeFile();
	}
	
	// Voisins
	if (meanNearestNeighboursDegreeDistributionFile->isOpen())
	{
		meanNearestNeighboursDegreeDistributionFile->closeFile();
	}
	
	// In/Out

			#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE
	if (meanInputAssemblyDegreeDistributionFile->isOpen())
	{
		meanInputAssemblyDegreeDistributionFile->closeFile();
	}

	if (meanOutputAssemblyDegreeDistributionFile->isOpen())
	{
		meanOutputAssemblyDegreeDistributionFile->closeFile();
	}

	if (meanInputAssemblyNearestNeighboursDegreeDistributionFile->isOpen())
	{
		meanInputAssemblyNearestNeighboursDegreeDistributionFile->closeFile();
	}

	if (meanOutputAssemblyNearestNeighboursDegreeDistributionFile->isOpen())
	{
		meanOutputAssemblyNearestNeighboursDegreeDistributionFile->closeFile();
	}
			#endif
		#endif
	#endif

	#ifdef _GSCC_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
	if (ongoingNbGSCCNodesFile->isOpen())
	{
		ongoingNbGSCCNodesFile->closeFile();
	}
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingSCComponentSizeDistributionFile->isOpen())
	{
		ongoingSCComponentSizeDistributionFile->closeOngoingDistributionDataFile();
	}
			#endif
			
	if (ongoingMaxSCComponentSizeFile->isOpen())
	{
		ongoingMaxSCComponentSizeFile->closeFile();
	}
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingMaxSCComponentSizeDistributionFile->isOpen())
	{
		ongoingMaxSCComponentSizeDistributionFile->closeOngoingDistributionDataFile();
	}
			#endif
	/*
	if (meanAssemblyDiameterSizeDistributionFile->isOpen())
	{
		meanAssemblyDiameterSizeDistributionFile->closeFile();
	}
	*/
		#else
	if (meanNbGSCCNodesFile->isOpen())
	{
		meanNbGSCCNodesFile->closeAccuDataFile();
	}

	if (meanSCComponentSizeDistributionFile->isOpen())
	{
		meanSCComponentSizeDistributionFile->closeFile();
	}

	if (meanMaxSCComponentSizeFile->isOpen())
	{
		meanMaxSCComponentSizeFile->closeAccuDataFile();
	}

	if (meanMaxSCComponentSizeDistributionFile->isOpen())
	{
		meanMaxSCComponentSizeDistributionFile->closeFile();
	}
			
			#ifdef _INPUT_OUTPUT_GSCC_STAT_MODE	
	if (meanInputSCComponentSizeDistributionFile->isOpen())
	{
		meanInputSCComponentSizeDistributionFile->closeFile();
	}

	if (meanOutputSCComponentSizeDistributionFile->isOpen())
	{
		meanOutputSCComponentSizeDistributionFile->closeFile();
	}
	
	
	if (meanOutputSCCFractionRepartitionFile->isOpen())
	{
		meanOutputSCCFractionRepartitionFile->closeFile();
	}

	
	if (meanInputSCCFractionRepartitionFile->isOpen())
	{
		meanInputSCCFractionRepartitionFile->closeFile();
	}

			#endif
		#endif
	#endif
	
	#ifdef _PROJECTION_STAT_MODE
	if (meanProjectionsFile->isOpen())
	{
		meanProjectionsFile->closeAccuDataFile();
	}
	
	if (meanExcitProjectionsFile->isOpen())
	{
		meanExcitProjectionsFile->closeAccuDataFile();
	}

	if (meanInhibProjectionsFile->isOpen())
	{
		meanInhibProjectionsFile->closeAccuDataFile();
	}

	if (meanExcitInputProjectionsFile->isOpen())
	{
		meanExcitInputProjectionsFile->closeAccuDataFile();
	}

	if (meanInhibInputProjectionsFile->isOpen())
	{
		meanInhibInputProjectionsFile->closeAccuDataFile();
	}

	if (meanExcitOutputProjectionsFile->isOpen())
	{
		meanExcitOutputProjectionsFile->closeAccuDataFile();
	}

	if (meanInhibOutputProjectionsFile->isOpen())
	{
		meanInhibOutputProjectionsFile->closeAccuDataFile();
	}

	if (meanExcitSelfProjectionsFile->isOpen())
	{
		meanExcitSelfProjectionsFile->closeAccuDataFile();
	}

	if (meanInhibSelfProjectionsFile->isOpen())
	{
		meanInhibSelfProjectionsFile->closeAccuDataFile();
	}

	#endif
	
	#ifdef _INPUT_OUTPUT_CLUSTER_STAT_MODE		
	if (maxModularityInputClusterSizeDistributionFile->isOpen())
	{
		maxModularityInputClusterSizeDistributionFile->closeFile();
	}
	
	if (maxModularityOutputClusterSizeDistributionFile->isOpen())
	{
		maxModularityOutputClusterSizeDistributionFile->closeFile();
	}


	if (maxModularityInputClusterFractionRepartitionFile->isOpen())
	{
		maxModularityInputClusterFractionRepartitionFile->closeFile();
	}

	if (maxModularityOutputClusterFractionRepartitionFile->isOpen())
	{
		maxModularityOutputClusterFractionRepartitionFile->closeFile();
	}
	#endif
#endif
}

void NetworkStater::openGrapher()
{
#ifdef _NETWORK_STAT_MODE
	if (meanGnuplotProjectionsFile)
	{
		meanGnuplotProjectionsFile->openGnuplotFile("MeanProjectionsStat");
	}
	else
	{
		cerr << "Warning, meanGnuplotProjectionsFile is not inited" << endl;
	}
#endif
}

void NetworkStater::runGrapher()
{
#ifdef _NETWORK_STAT_MODE
	if (meanGnuplotProjectionsFile)
	{
		meanGnuplotProjectionsFile->systemFile();
	}
	else
	{
		cerr << "Warning, meanGnuplotProjectionsFile is not inited" << endl;
	}
#endif
}

void NetworkStater::closeGrapher()
{
#ifdef _NETWORK_STAT_MODE
	if (meanGnuplotProjectionsFile->isOpen())
	{
		meanGnuplotProjectionsFile->closeFile();
	}
	else
	{
		cerr << "Warning, meanGnuplotProjectionsFile is not open" << endl;
	}
#endif
}

/****************************************************************************************************************************************/
/******************************************************* Accumulateurs **************************************************************/
/****************************************************************************************************************************************/

void NetworkStater::initAccumulaters()
{
#ifdef _NETWORK_STAT_MODE
	
	#ifdef _TEST_STAT
	cerr << "NetworkStater::initAccumulaters" << endl;
	#endif
	
	#ifdef _CENTRALITY_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
		// Assemblees
	
	// Calcul de centralité	
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingAssemblyCentralBetweennessDistribution)
	{
		((OngoingMeanLogDistribution*) ongoingAssemblyCentralBetweennessDistribution)->initOngoingMeanDistribution();
	}
	else
	{
		cerr << "Warning, ongoingAssemblyCentralBetweennessDistribution should be inited" << endl;
	}
			#endif
			
	if (ongoingAssemblyCentralBetweenness)
	{
		for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
		{
			ongoingAssemblyCentralBetweenness[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, ongoingAssemblyCentralBetweenness should be inited" << endl;
	}
	
	// Centralite de noeuds
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingAssemblyBetweennessDistribution)
	{
		((OngoingMeanLogDistribution*) ongoingAssemblyBetweennessDistribution)->initOngoingMeanDistribution();
	}
	else
	{
		cerr << "Warning, ongoingAssemblyBetweennessDistribution should be inited" << endl;
	}
			#endif
			
	if (ongoingAssemblyBetweenness)
	{
		for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
		{
			ongoingAssemblyBetweenness[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, ongoingAssemblyBetweenness should be inited" << endl;
	}
	
			
			#ifdef _EDGE_BETWEENNESS_STAT_MODE
				#ifdef _3D_ONGOING_STAT_MODE
	// Intermediarite de liens
	if (ongoingAssemblyEdgeBetweennessDistribution)
	{
		((OngoingMeanLogDistribution*) ongoingAssemblyEdgeBetweennessDistribution)->initOngoingMeanDistribution();
	}
	else
	{
		cerr << "Warning, ongoingAssemblyEdgeBetweennessDistribution should be inited" << endl;
	}
				#endif
				
	if (ongoingAssemblyMaxEdgeBetweenness)
	{
		for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
		{
			ongoingAssemblyMaxEdgeBetweenness[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, ongoingAssemblyMaxEdgeBetweenness should be inited" << endl;
	}
			#endif
			
	// Efficacité du réseau au fur et à mesure de la suppression
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingAssemblyGlobalEfficiencyDistribution)
	{
		((OngoingMeanLogDistribution*) ongoingAssemblyGlobalEfficiencyDistribution)->initOngoingMeanDistribution();
	}
	else
	{
		cerr << "Warning, ongoingAssemblyGlobalEfficiencyDistribution should be inited" << endl;
	}
			#endif
			
	if (ongoingAssemblyGlobalEfficiency)
	{
		for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
		{
			ongoingAssemblyGlobalEfficiency[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, ongoingAssemblyGlobalEfficiency should be inited" << endl;
	}

			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingAssemblyLocalEfficiencyDistribution)
	{
		((OngoingMeanLogDistribution*) ongoingAssemblyLocalEfficiencyDistribution)->initOngoingMeanDistribution();
	}
	else
	{
		cerr << "Warning, ongoingAssemblyLocalEfficiencyDistribution should be inited" << endl;
	}
			#endif
			
	if (ongoingAssemblyLocalEfficiency)
	{
		for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
		{
			ongoingAssemblyLocalEfficiency[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, ongoingAssemblyLocalEfficiency should be inited" << endl;
	}

	// ShortPath
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingAssemblyShortPathLengthDistribution)
	{
		((OngoingMeanDistribution*) ongoingAssemblyShortPathLengthDistribution)->initOngoingMeanDistribution();
	}
	else
	{
		cerr << "Warning, ongoingAssemblyShortPathLengthDistribution should be inited" << endl;
	}
			#endif
			
		// Clusters
	if (ongoingClusterModularity)
	{
		for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
		{
			ongoingClusterModularity[i] = 0.0;
		}
	}
	else
	{
		cerr << "Warning, ongoingClusterModularity should be inited" << endl;
	}
	
	// Nombre de clusters
	if (ongoingNbClusters)
	{
		for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
		{
			ongoingNbClusters[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, ongoingNbClusters should be inited" << endl;
	}
	
	if (ongoingMaxClusterSizes)
	{
		for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
		{
			ongoingMaxClusterSizes[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, ongoingMaxClusterSizes should be inited" << endl;
	}
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingClusterSizeDistribution)
	{
		((OngoingMeanDistribution*) ongoingClusterSizeDistribution)->initOngoingMeanDistribution();
	}
	else
	{
		cerr << "Warning, ongoingClusterSizeDistribution should be inited" << endl;
	}
	

	// Repartition de l'efficacité des clusters
	if (ongoingClusterEfficiencyDistribution)
	{
		((OngoingMeanLogDistribution*) ongoingClusterEfficiencyDistribution)->initOngoingMeanDistribution();
	}
	else
	{
		cerr << "Warning, ongoingClusterEfficiencyDistribution should be inited" << endl;
	}
			#endif
			
	if (ongoingClusterEfficiency)
	{
		for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
		{
			ongoingClusterEfficiency[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, ongoingClusterEfficiency should be inited" << endl;
	}
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingClusterRealEfficiencyDistribution)
	{
		((OngoingMeanLogDistribution*) ongoingClusterRealEfficiencyDistribution)->initOngoingMeanDistribution();
	}
	else
	{
		cerr << "Warning, ongoingClusterRealEfficiencyDistribution should be inited" << endl;
	}
			#endif
			
	if (ongoingClusterRealEfficiency)
	{
		for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
		{
			ongoingClusterRealEfficiency[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, ongoingClusterRealEfficiency should be inited" << endl;
	}


			#ifdef _LINKED_CLUSTER_STAT_MODE
	if (ongoingInDC)
	{
		for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
		{
			ongoingInDC[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, ongoingInDC should be inited" << endl;
	}
	
	if (ongoingInGOUT)
	{
		for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
		{
			ongoingInGOUT[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, ongoingInGOUT should be inited" << endl;
	}
	
	if (ongoingInGIN)
	{
		for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
		{
			ongoingInGIN[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, ongoingInGIN should be inited" << endl;
	}
	
	if (ongoingInGSCC)
	{
		for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
		{
			ongoingInGSCC[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, ongoingInGSCC should be inited" << endl;
	}
				#ifdef _CLUSTER_CENTRALITY_STAT_MODE	
					#ifdef _EDGE_BETWEENNESS_STAT_MODE

	// Intermedirite de liens
	if (ongoingLinkedClusterMaxEdgeBetweenness)
	{
		for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
		{
			ongoingLinkedClusterMaxEdgeBetweenness[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, ongoingLinkedClusterMaxEdgeBetweenness should be inited" << endl;
	}
						#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingLinkedClusterEdgeBetweennessDistribution)
	{
		((OngoingMeanLogDistribution*) ongoingLinkedClusterEdgeBetweennessDistribution)->initOngoingMeanDistribution();
	}
	else
	{
		cerr << "Warning, ongoingLinkedClusterEdgeBetweennessDistribution should be inited" << endl;
	}
						#endif
					#endif
					
	// Calcul de centralité
					#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingLinkedClusterBetweennessDistribution)
	{
		((OngoingMeanLogDistribution*) ongoingLinkedClusterBetweennessDistribution)->initOngoingMeanDistribution();
	}
	else
	{
		cerr << "Warning, ongoingLinkedClusterBetweennessDistribution should be inited" << endl;
	}
					#endif
					
	if (ongoingLinkedClusterBetweenness)
	{
		for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
		{
			ongoingLinkedClusterBetweenness[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, ongoingLinkedClusterBetweenness should be inited" << endl;
	}
					#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingLinkedClusterCentralBetweennessDistribution)
	{
		((OngoingMeanLogDistribution*) ongoingLinkedClusterCentralBetweennessDistribution)->initOngoingMeanDistribution();
	}
	else
	{
		cerr << "Warning, ongoingLinkedClusterCentralBetweennessDistribution should be inited" << endl;
	}
					#endif
					
	if (ongoingLinkedClusterCentralBetweenness)
	{
		for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
		{
			ongoingLinkedClusterCentralBetweenness[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, ongoingLinkedClusterCentralBetweenness should be inited" << endl;
	}
					#ifdef _3D_ONGOING_STAT_MODE
	// Efficacité du réseau au fur et à mesure de la suppression
	if (ongoingLinkedClusterGlobalEfficiencyDistribution)
	{
		((OngoingMeanLogDistribution*) ongoingLinkedClusterGlobalEfficiencyDistribution)->initOngoingMeanDistribution();
	}
	else
	{
		cerr << "Warning, ongoingLinkedClusterGlobalEfficiencyDistribution should be inited" << endl;
	}
					#endif
					
	if (ongoingLinkedClusterGlobalEfficiency)
	{
		for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
		{
			ongoingLinkedClusterGlobalEfficiency[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, ongoingLinkedClusterGlobalEfficiency should be inited" << endl;
	}
	
					#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingLinkedClusterLocalEfficiencyDistribution)
	{
		((OngoingMeanLogDistribution*) ongoingLinkedClusterLocalEfficiencyDistribution)->initOngoingMeanDistribution();
	}
	else
	{
		cerr << "Warning, ongoingLinkedClusterLocalEfficiencyDistribution should be inited" << endl;
	}
					#endif
					
	if (ongoingLinkedClusterLocalEfficiency)
	{
		for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
		{
			ongoingLinkedClusterLocalEfficiency[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, ongoingLinkedClusterLocalEfficiency should be inited" << endl;
	}

	// ShortPath
					#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingLinkedClusterShortPathLengthDistribution)
	{
		((OngoingMeanDistribution*) ongoingLinkedClusterShortPathLengthDistribution)->initOngoingMeanDistribution();
	}
	else
	{
		cerr << "Warning, ongoingLinkedClusterShortPathLengthDistribution should be inited" << endl;
	}
					#endif
				#endif
			#endif

			#ifdef _NETWORK_CLUSTER_STAT_MODE

				#ifdef _LINKED_CLUSTER_STAT_MODE
	// Repartition des clusters dans les composants pour le réseau à la fin du processus de clusterisation
	if (networkInDC)
	{
		networkInDC->initAccu();
	}

	if (networkInGOUT)
	{
		networkInGOUT->initAccu();
	}

	if (networkInGIN)
	{
		networkInGIN->initAccu();
	}

	if (networkInGSCC)
	{
		networkInGSCC->initAccu();
	}
				#endif

	if (networkClusterSizeDistribution)
	{
		networkClusterSizeDistribution->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, networkClusterSizeDistribution should be inited" << endl;
	}
	
	// Repartition de l'efficacité des clusters pour le réseau à la fin du processus de clusterisation
	if (networkClusterEfficiency)
	{
		networkClusterEfficiency->initAccu();
	}

	if (networkClusterEfficiencyDistribution)
	{
		((MeanLogDistribution*) networkClusterEfficiencyDistribution)->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, networkClusterEfficiencyDistribution should be inited" << endl;
	}
	
	if (networkClusterRealEfficiency)
	{
		networkClusterRealEfficiency->initAccu();
	}

	if (networkClusterRealEfficiencyDistribution)
	{
		((MeanLogDistribution*) networkClusterRealEfficiencyDistribution)->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, networkClusterRealEfficiencyDistribution should be inited" << endl;
	}
	
				#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
	// Nombre de suppression de liens pour atteindre le réseau optimal
	if (maxModularityProjectionIndex)
	{
		maxModularityProjectionIndex->initAccu();
	}

	// Modularité maximale
	if (maxModularity)
	{
		maxModularity->initAccu();
	}
					#ifdef _LINKED_CLUSTER_STAT_MODE
	// Repartition des clusters dans les composants pour le réseau optimal
	if (maxModularityInDC)
	{
		maxModularityInDC->initAccu();
	}

	if (maxModularityInGOUT)
	{
		maxModularityInGOUT->initAccu();
	} 

	if (maxModularityInGIN)
	{
		maxModularityInGIN->initAccu();
	}

	if (maxModularityInGSCC)
	{
		maxModularityInGSCC->initAccu();
	}
					#endif

	// Repartition de la taille des clusters pour le réseau optimal
	if (maxModularityClusterSizeDistribution)
	{
		maxModularityClusterSizeDistribution->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, maxModularityClusterSizeDistribution should be inited" << endl;
	}

	// Repartition de l'efficacité des clusters pour le réseau optimal
	if (maxModularityClusterEfficiency)
	{
		maxModularityClusterEfficiency->initAccu();
	}

	if (maxModularityClusterEfficiencyDistribution)
	{
		((MeanLogDistribution*) maxModularityClusterEfficiencyDistribution)->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, maxModularityClusterEfficiencyDistribution should be inited" << endl;
	}
	
	if (maxModularityClusterRealEfficiency)
	{
		maxModularityClusterRealEfficiency->initAccu();
	}

	if (maxModularityClusterRealEfficiencyDistribution)
	{
		((MeanLogDistribution*) maxModularityClusterRealEfficiencyDistribution)->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, maxModularityClusterRealEfficiencyDistribution should be inited" << endl;
	}
				#endif
			#endif
			
		#else
	// Calcul d'intermediarité
	if (meanAssemblyBetweennessRepartition)
	{
			
		for (int i=0;i<NB_ASSEMBLIES;i++)
		{
			meanAssemblyBetweennessRepartition[i].initAccu();
		}
		
		
	}
	else
	{
		cerr << "Warning, meanAssemblyBetweennessRepartition should be inited" << endl;
	}

	if (meanAssemblyBetweenness)
	{
		meanAssemblyBetweenness->initAccu();
	}
	else
	{
	
		cerr << "Warning, meanAssemblyBetweenness should be inited" << endl;
	}
	
	if (meanAssemblyBetweennessDistribution)
	{
		((MeanLogDistribution*) meanAssemblyBetweennessDistribution)->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, meanAssemblyBetweennessDistribution should be inited" << endl;
	}
	
	// Calcul de centralité
	if (meanAssemblyCentralBetweennessRepartition)
	{
		for (int i=0;i<NB_ASSEMBLIES;i++)
		{
			meanAssemblyCentralBetweennessRepartition[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, meanAssemblyBetweennessRepartition should be inited" << endl;
	}

	if (meanAssemblyCentralBetweenness)
	{
		meanAssemblyCentralBetweenness->initAccu();
	}
	else
	{
	
		cerr << "Warning, meanAssemblyCentralBetweenness should be inited" << endl;
	}
	
	if (meanAssemblyCentralBetweennessDistribution)
	{
		((MeanLogDistribution*) meanAssemblyCentralBetweennessDistribution)->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, meanAssemblyCentralBetweennessDistribution should be inited" << endl;
	}
			#ifdef _EDGE_BETWEENNESS_STAT_MODE
	// Calcul d'intermediarité pour les liens
	if (meanEdgeBetweennessRepartition)
	{
		for (int i=0;i<NB_ASSEMBLIES;i++)
		{
			for (int j=0;j<NB_ASSEMBLIES;j++)
			{
				meanEdgeBetweennessRepartition[i][j].initAccu();
			}
		}
		
	}
	else
	{
		cerr << "Warning, meanEdgeBetweennessRepartition should be inited" << endl;
	}

	if (meanEdgeBetweennessDistribution)
	{
		((MeanDistribution*) meanEdgeBetweennessDistribution)->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, meanEdgeBetweennessDistribution should be inited" << endl;
	}


			#endif
			
	// Repartition des short paths
	if (meanAssemblyShortPathRepartition)
	{
		for (int i=0;i<NB_ASSEMBLIES;i++)
		{
			meanAssemblyShortPathRepartition[i].initAccu();
		}
		
	}
	else
	{
		cerr << "Warning, meanAssemblyShortPathRepartition should be inited" << endl;
	}

	if (meanAssemblyNoShortPathRepartition)
	{
		for (int i=0;i<NB_ASSEMBLIES;i++)
		{
			meanAssemblyNoShortPathRepartition[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, meanAssemblyNoShortPathRepartition should be inited" << endl;
	}

	if (meanAssemblyNbShortPathDistribution)
	{
		meanAssemblyNbShortPathDistribution->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, meanAssemblyNbShortPathDistribution should be inited" << endl;
	}


	// Calcul d'efficacite
	if (meanAssemblyGlobalEfficiencyRepartition)
	{
		for (int i=0;i<NB_ASSEMBLIES;i++)
		{
			meanAssemblyGlobalEfficiencyRepartition[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, meanAssemblyGlobalEfficiencyRepartition should be inited" << endl;
	}

	if (meanAssemblyLocalEfficiencyRepartition)
	{
		for (int i=0;i<NB_ASSEMBLIES;i++)
		{
			meanAssemblyLocalEfficiencyRepartition[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, meanAssemblyLocalEfficiencyRepartition should be inited" << endl;
	}

	if (meanAssemblyGlobalEfficiencyDistribution)
	{
		((MeanLogDistribution*) meanAssemblyGlobalEfficiencyDistribution)->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, meanAssemblyGlobalEfficiencyDistribution should be inited" << endl;
	}
	
	if (meanAssemblyLocalEfficiencyDistribution)
	{
		((MeanLogDistribution*) meanAssemblyLocalEfficiencyDistribution)->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, meanAssemblyLocalEfficiencyDistribution should be inited" << endl;
	}
	
	if (meanAssemblyGlobalEfficiency)
	{
		meanAssemblyGlobalEfficiency->initAccu();
	}
	else
	{
		cerr << "Warning, meanAssemblyGlobalEfficiency should be inited" << endl;
	}

	if (meanAssemblyLocalEfficiency)
	{
		meanAssemblyLocalEfficiency->initAccu();
	}
	else
	{
		cerr << "Warning, meanAssemblyLocalEfficiency should be inited" << endl;
	}

		#endif
	#endif

	// Loop
	#ifdef _LOOP_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
		// Assembly
	// NbLoops
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingAssemblyNbLoopsDistribution)
	{
		((OngoingMeanLogDistribution*) ongoingAssemblyNbLoopsDistribution)->initOngoingMeanDistribution();
	}
	else
	{
		cerr << "Warning, ongoingAssemblyNbLoopsDistribution should be inited" << endl;
	}
			#endif
	
	if (ongoingAssemblyNbLoops)
	{
		for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
		{
			ongoingAssemblyNbLoops[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, ongoingAssemblyNbLoopsRepartition should be inited" << endl;
	}
	
	// Degree
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingAssemblyNbLoopsDegreeDistribution)
	{
		((OngoingCumulatedDistribution*) ongoingAssemblyNbLoopsDegreeDistribution)->initOngoingCumulatedDistribution();
	}
	else
	{
		cerr << "Warning, ongoingAssemblyNbLoopsDegreeDistribution should be inited" << endl;
	}
	
	// LoopSize	
	if (ongoingAssemblyLoopSizeDistribution)
	{
		((OngoingMeanDistribution*) ongoingAssemblyLoopSizeDistribution)->initOngoingMeanDistribution();
	}
	else
	{
		cerr << "Warning, ongoingAssemblyLoopSizeDistribution should be inited" << endl;
	}
			#endif
			
		// Cluster
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingClusterLoopSizeDistribution)
	{
		((OngoingMeanLogDistribution*) ongoingClusterLoopSizeDistribution)->initOngoingMeanDistribution();
	}
	else
	{
		cerr << "Warning, ongoingClusterLoopSizeDistribution should be inited" << endl;
	}
			#endif
			
	if (ongoingClusterNbLoops)
	{
		for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
		{
			ongoingClusterNbLoops[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, ongoingClusterNbLoopsRepartition should be inited" << endl;
	}
	
		#ifdef _NETWORK_CLUSTER_STAT_MODE
		
	if (networkClusterLoopSizeDistribution)
	{
		networkClusterLoopSizeDistribution->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, networkClusterLoopSizeDistribution should be inited" << endl;
	}		
				#ifdef _OPTIMAL_CLUSTERS_STAT_MODE	
	if (maxModularityClusterLoopSizeDistribution)
	{
		maxModularityClusterLoopSizeDistribution->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, maxModularityClusterLoopSizeDistribution should be inited" << endl;
	}
				#endif
			#endif
		#else
		
	if (meanAssemblyLoopSizeDistribution)
	{
		meanAssemblyLoopSizeDistribution->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, meanAssemblyLoopSizeDistribution should be inited" << endl;
	}
	
	// Nb Loops
	if (meanAssemblyNbLoopsRepartition)
	{
		for (int i=0;i<NB_ASSEMBLIES;i++)
		{
			meanAssemblyNbLoopsRepartition[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, meanAssemblyNbLoopsRepartition should be inited" << endl;
	}
	
	if (meanAssemblyNbLoopsDistribution)
	{
		meanAssemblyNbLoopsDistribution->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, meanAssemblyNbLoopsDistribution should be inited" << endl;
	}
	
	// Degree
	if (meanAssemblyNbLoopsDegreeDistribution)
	{
		((CumulatedDistribution*) meanAssemblyNbLoopsDegreeDistribution)->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, meanAssemblyNbLoopsDegreeDistribution should be inited" << endl;
	}
	
		#endif
	#endif
	
	// Small World
	#ifdef _SMALL_WORLD_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE

	// Degree
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingAssemblyClusteringCoeffDegreeDistribution)
	{
		((OngoingCumulatedDistribution*) ongoingAssemblyClusteringCoeffDegreeDistribution)->initOngoingCumulatedDistribution();
	}
	else
	{
		cerr << "Warning, ongoingAssemblyClusteringCoeffDegreeDistribution should be inited" << endl;
	}
	
	if (ongoingAssemblyClusteringCoeffDistribution)
	{
		((OngoingMeanLogDistribution*) ongoingAssemblyClusteringCoeffDistribution)->initOngoingMeanDistribution();
	}
	else
	{
		cerr << "Warning, ongoingAssemblyClusteringCoeffDistribution should be inited" << endl;
	}
			#endif
			
	// Cluster
	if (ongoingClusterInternalDensity)
	{
		for (int i=0; i < NB_PROJECTIONS_EACH_CHROMOSOME;i++)
		{
			ongoingClusterInternalDensity[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, ongoingClusterInternalDensity should be inited" << endl;
	}

	if (ongoingRealClusterInternalDensity)
	{
		for (int i=0; i < NB_PROJECTIONS_EACH_CHROMOSOME;i++)
		{
			ongoingRealClusterInternalDensity[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, ongoingRealClusterInternalDensity should be inited" << endl;
	}
			#ifdef _CLUSTER_CENTRALITY_STAT_MODE
				#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingLinkedClusterClusteringCoeffDegreeDistribution)
	{
		((OngoingCumulatedDistribution*) ongoingLinkedClusterClusteringCoeffDegreeDistribution)->initOngoingCumulatedDistribution();
	}
	else
	{
		cerr << "Warning, ongoingLinkedClusterClusteringCoeffDegreeDistribution should be inited" << endl;
	}
	
	if (ongoingLinkedClusterClusteringCoeffDistribution)
	{
		ongoingLinkedClusterClusteringCoeffDistribution->initOngoingMeanDistribution();
	}
	else
	{
		cerr << "Warning, ongoingLinkedClusterClusteringCoeffDistribution should be inited" << endl;
	}	
				#endif
			#endif
			
			#ifdef _NETWORK_CLUSTER_STAT_MODE
	if (networkClusterInternalDensity)
	{
		networkClusterInternalDensity->initAccu();
	}
	else
	{
		cerr << "Warning, networkClusterInternalDensity should be inited" << endl;
	}
	
	if (networkRealClusterInternalDensity)
	{
		networkRealClusterInternalDensity->initAccu();
	}
	else
	{
		cerr << "Warning, networkRealClusterInternalDensity should be inited" << endl;
	}
				#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	
	if (networkLinkedClusterClusteringCoeffDistribution)
	{
		networkLinkedClusterClusteringCoeffDistribution->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, networkLinkedClusterClusteringCoeffDistribution should be inited" << endl;
	}
	
	if (networkLinkedClusterClusteringCoeffDegreeDistribution)
	{
		((CumulatedDistribution*) networkLinkedClusterClusteringCoeffDegreeDistribution)->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, networkLinkedClusterClusteringCoeffDegreeDistribution should be inited" << endl;
	}
				#endif
				
				#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
	if (maxModularityClusterInternalDensity)
	{
		maxModularityClusterInternalDensity->initAccu();
	}
	else
	{
		cerr << "Warning, maxModularityClusterInternalDensity should be inited" << endl;
	}
	
	if (maxModularityRealClusterInternalDensity)
	{
		maxModularityRealClusterInternalDensity->initAccu();
	}
	else
	{
		cerr << "Warning, maxModularityRealClusterInternalDensity should be inited" << endl;
	}
					#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	
	if (maxModularityLinkedClusterClusteringCoeffDistribution)
	{
		maxModularityLinkedClusterClusteringCoeffDistribution->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, maxModularityLinkedClusterClusteringCoeffDistribution should be inited" << endl;
	}
	
	if (maxModularityLinkedClusterClusteringCoeffDegreeDistribution)
	{
		((CumulatedDistribution*) maxModularityLinkedClusterClusteringCoeffDegreeDistribution)->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, maxModularityLinkedClusterClusteringCoeffDegreeDistribution should be inited" << endl;
	}
					#endif
				#endif
			#endif
		#else
	// Distribution
	if (meanClusteringCoeffDistribution)
	{
		meanClusteringCoeffDistribution->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, meanClusteringCoeffDistribution should be inited" << endl;
	}
	
	// Degree
	if (meanClusteringCoeffDegreeDistribution)
	{
		((CumulatedDistribution*) meanClusteringCoeffDegreeDistribution)->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, meanClusteringCoeffDegreeDistribution should be inited" << endl;
	}
	
	// Repartition
	if (meanClusteringCoeffRepartition)
	{
		for (int i=0; i < NB_ASSEMBLIES;i++)
		{	
			meanClusteringCoeffRepartition[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, meanClusteringCoeffRepartition should be inited" << endl;
	}
	
	// Network
	if (meanClusteringCoeff)
	{
		meanClusteringCoeff->initAccu();
	}
	else
	{
		cerr << "Warning, meanClusteringCoeff should be inited" << endl;
	}
		#endif
	#endif
	#ifdef _MOTIF_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingAssemblyBinodeMotifs)
	{
		for (int i=0; i < NB_PROJECTIONS_EACH_CHROMOSOME;i++)
		{
			ongoingAssemblyBinodeMotifs[i].initAccu();
		}		
	}
	else
	{
		cerr << "Warning, ongoingAssemblyBinodeMotifs should be inited" << endl;
	}
	
	
	if (ongoingAssemblyTrinodeMotifsDistribution)
	{
		((OngoingMeanDistribution*) ongoingAssemblyTrinodeMotifsDistribution)->initOngoingMeanDistribution();
	}
	else
	{
		cerr << "Warning, ongoingAssemblyTrinodeMotifsDistribution should be inited" << endl;
	}
			#endif
			
			#ifdef _CLUSTER_CENTRALITY_STAT_MODE
				#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingLinkedClusterTrinodeMotifsDistribution)
	{
		((OngoingMeanDistribution*) ongoingLinkedClusterTrinodeMotifsDistribution)->initOngoingMeanDistribution();
	}
	else
	{
		cerr << "Warning, ongoingLinkedClusterTrinodeMotifsDistribution should be inited" << endl;
	}
				#endif
			#endif
			
			#ifdef _INTERNAL_MOTIF_STAT_MODE
				#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingClusterInternalBinodeMotifs)
	{
		for (int i=0; i < NB_PROJECTIONS_EACH_CHROMOSOME;i++)
		{
			ongoingClusterInternalBinodeMotifs[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, ongoingClusterInternalBinodeMotifs should be inited" << endl;
	}
	
	if (ongoingClusterInternalTrinodeMotifsDistribution)
	{
		((OngoingMeanDistribution*) ongoingClusterInternalTrinodeMotifsDistribution)->initOngoingMeanDistribution();
	}
	else
	{
		cerr << "Warning, ongoingClusterInternalTrinodeMotifsDistribution should be inited" << endl;
	}
				#endif
				
				#ifdef _NETWORK_CLUSTER_STAT_MODE
	if (networkClusterInternalBinodeMotifs)
	{
		networkClusterInternalBinodeMotifs->initAccu();		
	}
	else
	{
		cerr << "Warning, networkClusterInternalBinodeMotifs should be inited" << endl;
	}
	
	if (networkClusterInternalTrinodeMotifsDistribution)
	{
		networkClusterInternalTrinodeMotifsDistribution->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, networkClusterInternalTrinodeMotifsDistribution should be inited" << endl;
	}
	
	
					#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	
	if (networkLinkedClusterTrinodeMotifsDistribution)
	{
		networkLinkedClusterTrinodeMotifsDistribution->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, networkLinkedClusterTrinodeMotifsDistribution should be inited" << endl;
	}			
					#endif
	
					#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
	if (maxModularityClusterInternalBinodeMotifs)
	{
		maxModularityClusterInternalBinodeMotifs->initAccu();		
	}
	else
	{
		cerr << "Warning, maxModularityClusterInternalBinodeMotifs should be inited" << endl;
	}
	
	if (maxModularityClusterInternalTrinodeMotifsDistribution)
	{
		maxModularityClusterInternalTrinodeMotifsDistribution->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, maxModularityClusterInternalTrinodeMotifsDistribution should be inited" << endl;
	}
						#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	if (maxModularityLinkedClusterTrinodeMotifsDistribution)
	{
		maxModularityLinkedClusterTrinodeMotifsDistribution->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, maxModularityLinkedClusterTrinodeMotifsDistribution should be inited" << endl;
	}			
						#endif
					#endif
				#endif
			#endif
		#else
	if (meanBinodeMotifs)
	{
		meanBinodeMotifs->initAccu();
	}
	else
	{
		cerr << "Warning, meanBinodeMotifs should be inited" << endl;
	}
	
	if (meanTrinodeMotifsDistribution)
	{
		meanTrinodeMotifsDistribution->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, meanTrinodeMotifsDistribution should be inited" << endl;
	}
		#endif
	#endif
	
	#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingAssemblyReachedByInputDistribution)
	{
		((OngoingMeanDistribution*) ongoingAssemblyReachedByInputDistribution)->initOngoingMeanDistribution();
	}
	else
	{
		cerr << "Warning, ongoingAssemblyReachedByInputDistribution should be inited" << endl;
	}
	
	if (ongoingAssemblyReachedByOutputDistribution)
	{
		((OngoingMeanDistribution*) ongoingAssemblyReachedByOutputDistribution)->initOngoingMeanDistribution();
	}
	else
	{
		cerr << "Warning, ongoingAssemblyReachedByOutputDistribution should be inited" << endl;
	}
	
	if (ongoingAssemblyInputOutputPathLengthDistribution)
	{
		((OngoingMeanDistribution*) ongoingAssemblyInputOutputPathLengthDistribution)->initOngoingMeanDistribution();
	}
	else
	{
		cerr << "Warning, ongoingAssemblyInputOutputPathLengthDistribution should be inited" << endl;
	}
	
	if (ongoingAssemblyPathToInputDistribution)
	{
		((OngoingMeanDistribution*) ongoingAssemblyPathToInputDistribution)->initOngoingMeanDistribution();
	}
	else
	{
		cerr << "Warning, ongoingAssemblyPathToInputDistribution should be inited" << endl;
	}
	
	if (ongoingAssemblyPathToOutputDistribution)
	{
		((OngoingMeanDistribution*) ongoingAssemblyPathToOutputDistribution)->initOngoingMeanDistribution();
	}
	else
	{
		cerr << "Warning, ongoingAssemblyPathToOutputDistribution should be inited" << endl;
	}
			#endif
		#else
	if (meanReachedByInputDistribution)
	{
		meanReachedByInputDistribution->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, meanReachedByInputDistribution should be inited" << endl;
	}

	if (meanReachedByOutputDistribution)
	{
		meanReachedByOutputDistribution->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, meanReachedByOutputDistribution should be inited" << endl;
	}
	
	if (meanPathToInputDistribution)
	{
		meanPathToInputDistribution->initMeanDistribution();
	}

	if (meanPathToOutputDistribution)
	{
		meanPathToOutputDistribution->initMeanDistribution();
	}
		#endif
	#endif
	
	#ifdef _DEGREE_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingAssemblyDegreeDistribution)
	{
		((OngoingMeanDistribution*) ongoingAssemblyDegreeDistribution)->initOngoingMeanDistribution();
	}
	else
	{
		cerr << "Warning, ongoingAssemblyDegreeDistribution should be inited" << endl;
	}
	
	if (ongoingAssemblyPreDegreeDistribution)
	{
		((OngoingMeanDistribution*) ongoingAssemblyPreDegreeDistribution)->initOngoingMeanDistribution();
	}
	else
	{
		cerr << "Warning, ongoingAssemblyPreDegreeDistribution should be inited" << endl;
	}
	
	if (ongoingAssemblyPostDegreeDistribution)
	{
		((OngoingMeanDistribution*) ongoingAssemblyPostDegreeDistribution)->initOngoingMeanDistribution();
	}
	else
	{
		cerr << "Warning, ongoingAssemblyPostDegreeDistribution should be inited" << endl;
	}
	
	// Voisins
	if (ongoingAssemblyNearestNeighboursDegreeDistribution)
	{
		((OngoingCumulatedDistribution*) ongoingAssemblyNearestNeighboursDegreeDistribution)->initOngoingCumulatedDistribution();
	}
	else
	{
		cerr << "Warning, ongoingAssemblyNearestNeighboursDegreeDistribution should be inited" << endl;
	}
			#endif
			
			#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE
	// In/Out
				#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingInputAssemblyDegreeDistribution)
	{
		((OngoingMeanDistribution*) ongoingInputAssemblyDegreeDistribution)->initOngoingMeanDistribution();
	}
	else
	{
		cerr << "Warning, ongoingInputAssemblyDegreeDistribution should be inited" << endl;
	}
	
	if (ongoingOutputAssemblyDegreeDistribution)
	{
		((OngoingMeanDistribution*) ongoingOutputAssemblyDegreeDistribution)->initOngoingMeanDistribution();
	}
	else
	{
		cerr << "Warning, ongoingOutputAssemblyDegreeDistribution should be inited" << endl;
	}
	
	// Voisins
	if (ongoingInputAssemblyNearestNeighboursDegreeDistribution)
	{
		((OngoingCumulatedDistribution*) ongoingInputAssemblyNearestNeighboursDegreeDistribution)->initOngoingCumulatedDistribution();
	}
	else
	{
		cerr << "Warning, ongoingInputAssemblyNearestNeighboursDegreeDistribution should be inited" << endl;
	}
	
	if (ongoingOutputAssemblyNearestNeighboursDegreeDistribution)
	{
		((OngoingCumulatedDistribution*) ongoingOutputAssemblyNearestNeighboursDegreeDistribution)->initOngoingCumulatedDistribution();
	}
	else
	{
		cerr << "Warning, ongoingOutputAssemblyNearestNeighboursDegreeDistribution should be inited" << endl;
	}
				#endif
			#endif

			#ifdef _CLUSTER_CENTRALITY_STAT_MODE
				#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingLinkedClusterDegreeDistribution)
	{
		((OngoingMeanDistribution*) ongoingLinkedClusterDegreeDistribution)->initOngoingMeanDistribution();
	}
	else
	{
		cerr << "Warning, ongoingLinkedClusterDegreeDistribution should be inited" << endl;
	}
	
	if (ongoingLinkedClusterPreDegreeDistribution)
	{
		((OngoingMeanDistribution*) ongoingLinkedClusterPreDegreeDistribution)->initOngoingMeanDistribution();
	}
	else
	{
		cerr << "Warning, ongoingLinkedClusterPreDegreeDistribution should be inited" << endl;
	}
	
	if (ongoingLinkedClusterPostDegreeDistribution)
	{
		((OngoingMeanDistribution*) ongoingLinkedClusterPostDegreeDistribution)->initOngoingMeanDistribution();
	}
	else
	{
		cerr << "Warning, ongoingLinkedClusterPostDegreeDistribution should be inited" << endl;
	}
	
	// Voisins
	if (ongoingLinkedClusterNearestNeighboursDegreeDistribution)
	{
		((OngoingCumulatedDistribution*) ongoingLinkedClusterNearestNeighboursDegreeDistribution)->initOngoingCumulatedDistribution();
	}
	else
	{
		cerr << "Warning, ongoingLinkedClusterNearestNeighboursDegreeDistribution should be inited" << endl;
	}
				#endif
				
				#ifdef _NETWORK_CLUSTER_STAT_MODE
	if (networkLinkedClusterDegreeDistribution)
	{
		((MeanDistribution*) networkLinkedClusterDegreeDistribution)->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, networkLinkedClusterDegreeDistribution should be inited" << endl;
	}
	
	if (networkLinkedClusterPreDegreeDistribution)
	{
		((MeanDistribution*) networkLinkedClusterPreDegreeDistribution)->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, networkLinkedClusterPreDegreeDistribution should be inited" << endl;
	}
	
	if (networkLinkedClusterPostDegreeDistribution)
	{
		((MeanDistribution*) networkLinkedClusterPostDegreeDistribution)->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, networkLinkedClusterPostDegreeDistribution should be inited" << endl;
	}
	
	// Voisins
	if (networkLinkedClusterNearestNeighboursDegreeDistribution)
	{
		((CumulatedDistribution*) networkLinkedClusterNearestNeighboursDegreeDistribution)->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, networkLinkedClusterNearestNeighboursDegreeDistribution should be inited" << endl;
	}
					#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
	if (maxModularityLinkedClusterDegreeDistribution)
	{
		((MeanDistribution*) maxModularityLinkedClusterDegreeDistribution)->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, maxModularityLinkedClusterDegreeDistribution should be inited" << endl;
	}
	
	if (maxModularityLinkedClusterPreDegreeDistribution)
	{
		((MeanDistribution*) maxModularityLinkedClusterPreDegreeDistribution)->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, maxModularityLinkedClusterPreDegreeDistribution should be inited" << endl;
	}
	
	if (maxModularityLinkedClusterPostDegreeDistribution)
	{
		((MeanDistribution*) maxModularityLinkedClusterPostDegreeDistribution)->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, maxModularityLinkedClusterPostDegreeDistribution should be inited" << endl;
	}
	
	// Voisins
	if (maxModularityLinkedClusterNearestNeighboursDegreeDistribution)
	{
		((CumulatedDistribution*) maxModularityLinkedClusterNearestNeighboursDegreeDistribution)->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, maxModularityLinkedClusterNearestNeighboursDegreeDistribution should be inited" << endl;
	}
					#endif
				#endif
			#endif
			
		#else
	if (meanDegreeDistribution)
	{
		meanDegreeDistribution->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, meanNearestNeighboursDegreeDistribution should be inited" << endl;
	}
	
	if (meanPreDegreeDistribution)
	{
		meanPreDegreeDistribution->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, meanPreDegreeDistribution should be inited" << endl;
	}
	
	if (meanPostDegreeDistribution)
	{
		meanPostDegreeDistribution->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, meanPostDegreeDistribution should be inited" << endl;
	}
	
	
	if (meanNearestNeighboursDegreeDistribution)
	{
		meanNearestNeighboursDegreeDistribution->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, meanNearestNeighboursDegreeDistribution should be inited" << endl;
	}
	
	// In/Out
	
			#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE
	if (meanInputAssemblyDegreeDistribution)
	{
		meanInputAssemblyDegreeDistribution->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, meanInputAssemblyDegreeDistribution should be inited" << endl;
	}
	
	if (meanOutputAssemblyDegreeDistribution)
	{
		meanOutputAssemblyDegreeDistribution->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, meanOutputAssemblyDegreeDistribution should be inited" << endl;
	}
	
	if (meanInputAssemblyNearestNeighboursDegreeDistribution)
	{
		meanInputAssemblyNearestNeighboursDegreeDistribution->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, meanInputAssemblyNearestNeighbourDegreeDistribution should be inited" << endl;
	}
	
	if (meanOutputAssemblyNearestNeighboursDegreeDistribution)
	{
		meanOutputAssemblyNearestNeighboursDegreeDistribution->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, meanOutputAssemblyNearestNeighbourDegreeDistribution should be inited" << endl;
	}
			#endif
		#endif
	#endif

	#ifdef _GSCC_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
	if (ongoingNbGSCCNodes)
	{
		for (int i=0; i < NB_PROJECTIONS_EACH_CHROMOSOME;i++)
		{
			ongoingNbGSCCNodes[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, ongoingNbGSCCNodes should be inited" << endl;
	}

			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingSCComponentSizeDistribution)
	{
		((OngoingMeanDistribution*) ongoingSCComponentSizeDistribution)->initOngoingMeanDistribution();
	}
	else
	{
		cerr << "Warning, ongoingSCComponentSizeDistribution should be inited" << endl;
	}
			#endif
			
	if (ongoingMaxSCComponentSize)
	{
		for (int i=0; i < NB_PROJECTIONS_EACH_CHROMOSOME;i++)
		{
			ongoingMaxSCComponentSize[i].initAccu();
		}
	}
	else
	{
		cerr << "Warning, ongoingMaxSCComponentSize should be inited" << endl;
	}

			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingMaxSCComponentSizeDistribution)
	{
		((OngoingDistribution*) ongoingSCComponentSizeDistribution)->initOngoingDistribution();
	}
	else
	{
		cerr << "Warning, ongoingMaxSCComponentSizeDistribution should be inited" << endl;
	}
			#endif
	/*
	if (meanAssemblyDiameterSizeDistribution)
	{
		((MeanDistribution*) meanAssemblyDiameterSizeDistribution)->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, meanAssemblyDiameterSizeDistribution should be inited" << endl;
	}
	*/
		#else
	if (meanNbGSCCNodes)
	{
		meanNbGSCCNodes->initAccu();
	}
			
	if (meanSCComponentSizeDistribution)
	{
		meanSCComponentSizeDistribution->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, meanSCComponentSizeDistribution should be inited" << endl;
	}

	if (meanMaxSCComponentSize)
	{
		meanMaxSCComponentSize->initAccu();
	}

	if (meanMaxSCComponentSizeDistribution)
	{
		meanMaxSCComponentSizeDistribution->initDistribution();
	}
	else
	{
		cerr << "Warning, meanMaxSCComponentSizeDistribution should be inited" << endl;
	}
			
			#ifdef _INPUT_OUTPUT_GSCC_STAT_MODE	
	
	if (meanInputSCComponentSizeDistribution)
	{
		meanInputSCComponentSizeDistribution->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, meanInputSCComponentSizeDistribution should be inited" << endl;
	}
	
	
	if (meanOutputSCComponentSizeDistribution)
	{
		meanOutputSCComponentSizeDistribution->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, meanSCComponentSizeDistribution should be inited" << endl;
	}
	
	if (meanInputSCCFractionRepartition)
	{
		for (int i=0;i<NB_INPUT_ASSEMBLIES;i++)
		{
			meanInputSCCFractionRepartition[i].initAccu();
		}		
	}
	else
	{
		cerr << "Warning, meanInputSCCFractionRepartition should be inited" << endl;
	}

	if (meanOutputSCCFractionRepartition)
	{
		for (int i=0;i<NB_OUTPUT_ASSEMBLIES;i++)
		{
			meanOutputSCCFractionRepartition[i].initAccu();
		}		
		
		
	}
	else
	{
		cerr << "Warning, meanOutputSCCFractionRepartition should be inited" << endl;
	}

			#endif
		#endif
	#endif
	
	#ifdef _PROJECTION_STAT_MODE
	if (meanProjections)
	{
		meanProjections->initAccu();
	}
	else
	{
		cerr << "Warning, meanProjections should be inited" << endl;
	}
	
	// Excit/Inhib
	if (meanExcitProjections)
	{
		meanExcitProjections->initAccu();
	}
	else
	{
		cerr << "Warning, meanExcitProjections should be inited" << endl;
	}

	if (meanInhibProjections)
	{
		meanInhibProjections->initAccu();
	}
	else
	{
		cerr << "Warning, meanInhibProjections should be inited" << endl;
	}

	// Input
	if (meanExcitInputProjections)
	{
		meanExcitInputProjections->initAccu();
	}
	else
	{
		cerr << "Warning, meanExcitInputProjections should be inited" << endl;
	}

	if (meanInhibInputProjections)
	{
		meanInhibInputProjections->initAccu();
	}
	else
	{
		cerr << "Warning, meanInhibInputProjections should be inited" << endl;
	}

	// Output
	if (meanExcitOutputProjections)
	{
		meanExcitOutputProjections->initAccu();
	}
	else
	{
		cerr << "Warning, meanExcitOutputProjections should be inited" << endl;
	}

	if (meanInhibOutputProjections)
	{
		meanInhibOutputProjections->initAccu();
	}
	else
	{
		cerr << "Warning, meanInhibOutputProjections should be inited" << endl;
	}

	// Self
	if (meanExcitSelfProjections)
	{
		meanExcitSelfProjections->initAccu();
	}
	else
	{
		cerr << "Warning, meanExcitSelfProjections should be inited" << endl;
	}

	if (meanInhibSelfProjections)
	{
		meanInhibSelfProjections->initAccu();
	}
	else
	{
		cerr << "Warning, meanInhibSelfProjections should be inited" << endl;
	}
	#endif

	#ifdef _INPUT_OUTPUT_CLUSTER_STAT_MODE

	if (maxModularityInputClusterSizeDistribution)
	{
		maxModularityInputClusterSizeDistribution->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, maxModularityInputClusterSizeDistribution should be inited" << endl;
	}
	
	if (maxModularityOutputClusterSizeDistribution)
	{
		maxModularityOutputClusterSizeDistribution->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, maxModularityClusterSizeDistribution should be inited" << endl;
	}
	
	if (maxModularityInputClusterFractionRepartition)
	{
		for (int i=0;i<NB_INPUT_ASSEMBLIES;i++)
		{
			maxModularityInputClusterFractionRepartition[i].initAccu();
		}		
	}
	else
	{
		cerr << "Warning, maxModularityInputClusterFractionRepartition should be inited" << endl;
	}

	if (maxModularityOutputClusterFractionRepartition)
	{
		for (int i=0;i<NB_OUTPUT_ASSEMBLIES;i++)
		{
			maxModularityOutputClusterFractionRepartition[i].initAccu();
		}		
		
		
	}
	else
	{
		cerr << "Warning, maxModularityOutputClusterFractionRepartition should be inited" << endl;
	}

	#endif
	
	#ifdef _TEST_STAT
	cerr << "After NetworkStater::initAccumulaters" << endl;
	#endif

#endif

}

void NetworkStater::flushAccumulaters()
{
#ifdef _NETWORK_STAT_MODE
#endif
}

/****************************************************************************************************************************************/
/******************************************************* Methodes de stats **************************************************************/
/****************************************************************************************************************************************/

#ifdef _NETWORK_STAT_MODE

	
	#ifdef _TOPOLOGY_STAT_MODE
void NetworkStater::initConnectivityMatrix()
{
	cerr << "Initing connectivity matrix" << endl;
	
	for (int i = 0;i < NB_ASSEMBLIES;i++)
	{
		for (int j=0;j < NB_ASSEMBLIES;j++)
		{
			connectivityMatrix[i][j] = 0;
			
			//cerr  << "connectivityMatrix[" << i << "][" << j << "]" << connectivityMatrix[i][j] << endl;
		}
	}
}

void NetworkStater::statConnectivity(EDAssembly* curAssembly)
{
	int curAssemblyIndex = ((EDAssembly*) curAssembly)->getIndex();
	
	std::vector<Link*>::iterator it = ((EDAssembly*) curAssembly)->outputLinks.begin();
	std::vector<Link*>::iterator end = ((EDAssembly*) curAssembly)->outputLinks.end();

	while (it!=end)
	{
		int postAssemblyIndex = ((Node*) ((Projection*) ((Link*) *it))->getPostNode())->getIndex();
		
		if (curAssemblyIndex < NB_ASSEMBLIES && postAssemblyIndex < NB_ASSEMBLIES)
		{
		#ifdef _INHIB_EXCIT_TOPOLOGY_STAT_MODE
			if (((Projection*) ((Link*) *it))->getProjectionNature() == INHIB)
			{
				connectivityMatrix[curAssemblyIndex][postAssemblyIndex]--;
				
				//cerr  << "connectivityMatrix[" << curAssemblyIndex << "][" << postAssemblyIndex << "]" << connectivityMatrix[curAssemblyIndex][postAssemblyIndex] << endl;
			}
			else if (((Projection*) ((Link*) *it))->getProjectionNature() == EXCIT)
			{
				connectivityMatrix[curAssemblyIndex][postAssemblyIndex]++;
			
				//cerr  << "connectivityMatrix[" << curAssemblyIndex << "][" << postAssemblyIndex << "]" << connectivityMatrix[curAssemblyIndex][postAssemblyIndex] << endl;
			}
		#else
			connectivityMatrix[curAssemblyIndex][postAssemblyIndex]++;
		#endif
		}
		
			it++;
	}
}
	#endif
	
	#ifdef _LINK_TO_INPUT_STAT_MODE
void NetworkStater::initLinkToInputVector()
{
		#ifdef _TEST_STAT
	cout << "Initing link to input vector matrix" << endl;
		#endif
		
	for (int i = 0;i < NB_ASSEMBLIES;i++)
	{
		linkToInputVector[i] = 0;
		
		#ifdef _TEST_STAT	
		cout << "linkToInputVector[" << i << "]" << linkToInputVector[i] << endl;
		#endif
		
	}
}

void NetworkStater::statInputConnectivity(EDAssembly* curAssembly)
{
	if (curAssembly->getNature() == INPUT)
	{
		std::vector<Link*>::iterator it = ((EDAssembly*) curAssembly)->outputLinks.begin();
		std::vector<Link*>::iterator end = ((EDAssembly*) curAssembly)->outputLinks.end();
	
		while (it!=end)
		{
			int postAssemblyIndex = ((Node*) ((Projection*) ((Link*) *it))->getPostNode())->getIndex();
			
			if (postAssemblyIndex < NB_ASSEMBLIES)
			{
		#ifdef _EXCIT_LINK_TO_INPUT_STAT_MODE
				if (((Projection*) ((Link*) *it))->getProjectionNature() == EXCIT)
				{
					linkToInputVector[postAssemblyIndex]++;
				}
		#else
				linkToInputVector[postAssemblyIndex]++;
		#endif	
		
		#ifdef _TEST_STAT
				cout  << "linkToInputVector[" << postAssemblyIndex << "]" << linkToInputVector[postAssemblyIndex] << endl;
		#endif
			}
			
			it++;
		}
	}
	else
	{
		cerr << "Warning, wrong assembly nature for " << curAssembly->getIndex() << ", should be INPUT" << endl;
	}
}
	#endif
	#ifdef _LINK_TO_OUTPUT_STAT_MODE
void NetworkStater::initLinkToOutputVector()
{
		#ifdef _TEST_STAT
	cerr << "Initing link to input vector matrix" << endl;
		#endif
		
	for (int i = 0;i < NB_ASSEMBLIES;i++)
	{
		linkToOutputVector[i] = 0;
		#ifdef _TEST_STAT	
		cout  << "linkToOutputVector[" << i << "]" << linkToOutputVector[i] << endl;
		#endif
	}
}

void NetworkStater::statOutputConnectivity(EDAssembly* curAssembly)
{
	if (curAssembly->getNature() == OUTPUT)
	{
		std::vector<Link*>::iterator it = ((EDAssembly*) curAssembly)->inputLinks.begin();
		std::vector<Link*>::iterator end = ((EDAssembly*) curAssembly)->inputLinks.end();
	
		while (it!=end)
		{
			int postAssemblyIndex = ((Node*) ((Projection*) ((Link*) *it))->getPreNode())->getIndex();
			
			if (postAssemblyIndex < NB_ASSEMBLIES)
			{
		#ifdef _EXCIT_LINK_TO_OUTPUT_STAT_MODE
				if (((Projection*) ((Link*) *it))->getProjectionNature() == EXCIT)
				{
					linkToOutputVector[postAssemblyIndex]++;
				}
		#else
				linkToOutputVector[postAssemblyIndex]++;
		#endif	
		
		#ifdef _TEST_STAT
				cout << "linkToOutputVector[" << postAssemblyIndex << "]" << linkToOutputVector[postAssemblyIndex] << endl;
		#endif
			}
			
			it++;
		}
	}
	else
	{
		cerr << "Warning, wrong assembly nature for " << curAssembly->getIndex() << ", should be OUTPUT" << endl;
	}
}
	#endif
	
	#ifdef _CENTRALITY_STAT_MODE

		#ifdef _CLUSTER_STAT_MODE
			#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
void NetworkStater::initCurMaxModularity()
{
	curMaxModularity = -1.0;
}
			#endif
void NetworkStater::computeModularity(EDNetwork* curNetwork)
{
	initClusterModularity();

		#ifdef _LINKED_CLUSTER_STAT_MODE
	
	// Calcul de Modularité
	std::vector<LinkedCluster*>::iterator it=curNetwork->tabClusters.begin();
	std::vector<LinkedCluster*>::iterator end=curNetwork->tabClusters.end();

	while (it!=end)
	{
			
		double averageInputLinkFraction=0.0;
		double averageOutputLinkFraction=0.0;

		double internalInputLinkFraction=0.0;
		double internalOutputLinkFraction=0.0;

		std::vector<LinkedCluster*>::iterator it2=curNetwork->tabClusters.begin();
		std::vector<LinkedCluster*>::iterator end2=curNetwork->tabClusters.end();

		while (it2!=end2)
		{
			if (((LinkedCluster*) *it)->isSameIndex((LinkedCluster*) *it2))
			{
				internalInputLinkFraction = ((double) ((Cluster*) *it)->computeInputLinkFraction(((Cluster*) *it2)))/((double) curNetwork->nbInternalProjections);
				internalOutputLinkFraction = ((double) ((Cluster*) *it)->computeOutputLinkFraction(((Cluster*) *it2)))/((double) curNetwork->nbInternalProjections);

				averageInputLinkFraction += internalInputLinkFraction;
				averageOutputLinkFraction += internalOutputLinkFraction;

				if (internalInputLinkFraction != internalOutputLinkFraction)
				{
					cerr << "Warning, internalInputLinkFraction and internalOutputLinkFraction should be equal";
					cerr << internalInputLinkFraction << " != " << internalOutputLinkFraction << endl;
				}
			}
			else
			{
				averageInputLinkFraction += ((double) ((Cluster*) *it)->computeInputLinkFraction(((Cluster*) *it2)))/((double) curNetwork->nbInternalProjections);
				averageOutputLinkFraction += ((double) ((Cluster*) *it)->computeOutputLinkFraction(((Cluster*) *it2)))/((double) curNetwork->nbInternalProjections);
			}

				#ifdef _TEST
			cout << "averageInputLinkFraction: " << averageInputLinkFraction << ", averageOutputLinkFraction: " << averageOutputLinkFraction << endl;
				#endif

			it2++;
		}

		double modularity = ((double) internalInputLinkFraction+internalOutputLinkFraction)/2.0 - (double) averageInputLinkFraction*averageOutputLinkFraction;

				#ifdef _TEST
		cout << "Modularity: " << modularity << endl;
				#endif
		
		addClusterModularity(modularity);
		it++;
	}		
		#else
	
	std::vector<Cluster*>::iterator it=curNetwork->tabClusters.begin();
	std::vector<Cluster*>::iterator end=curNetwork->tabClusters.end();

	while (it!=end)
	{
		double averageInputLinkFraction=0.0;
		double averageOutputLinkFraction=0.0;
			
		double internalInputLinkFraction=0.0;
		double internalOutputLinkFraction=0.0;
		
		std::vector<Cluster*>::iterator it2=curNetwork->tabClusters.begin();
		std::vector<Cluster*>::iterator end2=curNetwork->tabClusters.end();
	
		while (it2!=end2)
		{
			//if (((Cluster*) *it)->getIndex() == ((Cluster*) *it2)->getIndex())
			if (((Cluster*) *it)->isSameIndex((Cluster*) *it2))
			//if (((Cluster*) *it) == ((Cluster*) *it2))
			{
				internalInputLinkFraction = ((double) ((Cluster*) *it)->computeInputLinkFraction(((Cluster*) *it2)))/((double) curNetwork->nbInternalProjections);
				internalOutputLinkFraction = ((double) ((Cluster*) *it)->computeOutputLinkFraction(((Cluster*) *it2)))/((double) curNetwork->nbInternalProjections);
				
				averageInputLinkFraction += internalInputLinkFraction;
				averageOutputLinkFraction += internalOutputLinkFraction;
				
				if (internalInputLinkFraction != internalOutputLinkFraction)
				{
					cerr << "Warning, internalInputLinkFraction and internalOutputLinkFraction should be equal";
					cerr << internalInputLinkFraction << " != " << internalOutputLinkFraction << endl;
				}
			}
			else
			{
				averageInputLinkFraction += ((double) ((Cluster*) *it)->computeInputLinkFraction(((Cluster*) *it2)))/((double) curNetwork->nbInternalProjections);
				averageOutputLinkFraction += ((double) ((Cluster*) *it)->computeOutputLinkFraction(((Cluster*) *it2)))/((double) curNetwork->nbInternalProjections);
			}
			
			it2++;
		}
		
		double modularity = ((double) internalInputLinkFraction+internalOutputLinkFraction)/2.0 - (double) averageInputLinkFraction*averageOutputLinkFraction;

			
			#ifdef _TEST
		cout << "Modularity: " << modularity << endl;
			#endif
		
		addClusterModularity(modularity);
			
		it++;
	}
		#endif
	
		//#ifdef _TEST
	cout << "Cluster Modularity = " << clusterModularity << ", nb clusters " << curNetwork->tabClusters.size() << endl;
		//#endif

}

void NetworkStater::statClusters(int projectionIndex)
{			
			#ifdef _TEST_STAT
	cout << "stat Cluster : Projection index = " << projectionIndex << endl;
			#endif
			
	if (0 <= projectionIndex && projectionIndex<NB_PROJECTIONS_EACH_CHROMOSOME)
	{
			#ifdef _3D_ONGOING_STAT_MODE
				#ifdef _CUMUL_PROBA_STAT_MODE
		ongoingClusterEfficiencyDistribution->ongoingAccumulateCumulProba(projectionIndex,(LogDistribution*) clusterEfficiencyDistribution);
				#else
					#ifdef _PROBA_STAT_MODE
		ongoingClusterEfficiencyDistribution->ongoingAccumulateProba(projectionIndex,(LogDistribution*) clusterEfficiencyDistribution);	
					#else
		ongoingClusterEfficiencyDistribution->ongoingAccumulate(projectionIndex,(LogDistribution*) clusterEfficiencyDistribution);	
					#endif		
				#endif
			#endif
			
		ongoingClusterEfficiency[projectionIndex].accumulate((double) clusterEfficiency->getMean());
		//ongoingClusterEfficiency[projectionIndex].accumulate((double) clusterEfficiency->getAccu());
			
			#ifdef _3D_ONGOING_STAT_MODE
				#ifdef _CUMUL_PROBA_STAT_MODE
		ongoingClusterRealEfficiencyDistribution->ongoingAccumulateCumulProba(projectionIndex,(LogDistribution*) clusterRealEfficiencyDistribution);
				#else
					#ifdef _PROBA_STAT_MODE
		ongoingClusterRealEfficiencyDistribution->ongoingAccumulateProba(projectionIndex,(LogDistribution*) clusterRealEfficiencyDistribution);	
					#else
		ongoingClusterRealEfficiencyDistribution->ongoingAccumulate(projectionIndex,(LogDistribution*) clusterRealEfficiencyDistribution);	
					#endif			
				#endif
			#endif
			
		ongoingClusterRealEfficiency[projectionIndex].accumulate((double) clusterRealEfficiency->getMean());
		//ongoingClusterRealEfficiency[projectionIndex].accumulate((double) clusterRealEfficiency->getAccu());
		
			#ifdef _LINKED_CLUSTER_STAT_MODE
		ongoingInDC[projectionIndex].accumulate((double) inDC->getAccu());
		ongoingInGOUT[projectionIndex].accumulate((double) inGOUT->getAccu());
		ongoingInGIN[projectionIndex].accumulate((double) inGIN->getAccu());
		ongoingInGSCC[projectionIndex].accumulate((double) inGSCC->getAccu());
				
				#ifdef _CLUSTER_CENTRALITY_STAT_MODE
					#ifdef _3D_ONGOING_STAT_MODE
						#ifdef _CUMUL_PROBA_STAT_MODE
		ongoingLinkedClusterCentralBetweennessDistribution->ongoingAccumulateCumulProba(projectionIndex,(LogDistribution*) linkedClusterCentralBetweennessDistribution);
						#else
							#ifdef _PROBA_STAT_MODE
		ongoingLinkedClusterCentralBetweennessDistribution->ongoingAccumulateProba(projectionIndex,(LogDistribution*) linkedClusterCentralBetweennessDistribution);		
							#else
		ongoingLinkedClusterCentralBetweennessDistribution->ongoingAccumulate(projectionIndex,(LogDistribution*) linkedClusterCentralBetweennessDistribution);		
							#endif				
						#endif
					#endif
					
		ongoingLinkedClusterCentralBetweenness[projectionIndex].accumulate((double) linkedClusterCentralBetweenness->getAccu());
		
					#ifdef _3D_ONGOING_STAT_MODE
						#ifdef _CUMUL_PROBA_STAT_MODE
		ongoingLinkedClusterBetweennessDistribution->ongoingAccumulateCumulProba(projectionIndex,(LogDistribution*) linkedClusterBetweennessDistribution);
						#else
							#ifdef _PROBA_STAT_MODE
		ongoingLinkedClusterBetweennessDistribution->ongoingAccumulateProba(projectionIndex,(LogDistribution*) linkedClusterBetweennessDistribution);		
							#else
		ongoingLinkedClusterBetweennessDistribution->ongoingAccumulate(projectionIndex,(LogDistribution*) linkedClusterBetweennessDistribution);	
							#endif
						#endif
					#endif
					
		ongoingLinkedClusterBetweenness[projectionIndex].accumulate((double) linkedClusterBetweenness->getMean());
		
					#ifdef _EDGE_BETWEENNESS_STAT_MODE

		// Intermediarite de liens
		ongoingLinkedClusterMaxEdgeBetweenness[projectionIndex].accumulate((double) linkedClusterMaxEdgeBetweenness);	
		
						#ifdef _3D_ONGOING_STAT_MODE
							#ifdef _CUMUL_PROBA_STAT_MODE
		ongoingLinkedClusterEdgeBetweennessDistribution->ongoingAccumulateCumulProba(projectionIndex,(LogDistribution*) linkedClusterEdgeBetweennessDistribution);
							#else
								#ifdef _PROBA_STAT_MODE
		ongoingLinkedClusterEdgeBetweennessDistribution->ongoingAccumulateProba(projectionIndex,(LogDistribution*) linkedClusterEdgeBetweennessDistribution);		
								#else
		ongoingLinkedClusterEdgeBetweennessDistribution->ongoingAccumulate(projectionIndex,(LogDistribution*) linkedClusterEdgeBetweennessDistribution);		
								#endif		
							#endif
						#endif
					#endif
					
		// Efficacite
					#ifdef _3D_ONGOING_STAT_MODE
						#ifdef _CUMUL_PROBA_STAT_MODE
		ongoingLinkedClusterGlobalEfficiencyDistribution->ongoingAccumulateCumulProba(projectionIndex,(LogDistribution*) linkedClusterGlobalEfficiencyDistribution);
						#else
							#ifdef _PROBA_STAT_MODE
		ongoingLinkedClusterGlobalEfficiencyDistribution->ongoingAccumulateProba(projectionIndex,(LogDistribution*) linkedClusterGlobalEfficiencyDistribution);		
							#else
		ongoingLinkedClusterGlobalEfficiencyDistribution->ongoingAccumulate(projectionIndex,(LogDistribution*) linkedClusterGlobalEfficiencyDistribution);		
							#endif				
						#endif
					#endif
					
		ongoingLinkedClusterGlobalEfficiency[projectionIndex].accumulate((double) linkedClusterGlobalEfficiency->getMean());
		
					#ifdef _3D_ONGOING_STAT_MODE
						#ifdef _CUMUL_PROBA_STAT_MODE
		ongoingLinkedClusterLocalEfficiencyDistribution->ongoingAccumulateCumulProba(projectionIndex,(LogDistribution*) linkedClusterLocalEfficiencyDistribution);
						#else
							#ifdef _PROBA_STAT_MODE
		ongoingLinkedClusterLocalEfficiencyDistribution->ongoingAccumulateProba(projectionIndex,(LogDistribution*) linkedClusterLocalEfficiencyDistribution);	
							#else
		ongoingLinkedClusterLocalEfficiencyDistribution->ongoingAccumulate(projectionIndex,(LogDistribution*) linkedClusterLocalEfficiencyDistribution);		
							#endif				
						#endif
					#endif
					
		ongoingLinkedClusterLocalEfficiency[projectionIndex].accumulate((double) linkedClusterLocalEfficiency->getMean());
		
		//Short path		
					#ifdef _3D_ONGOING_STAT_MODE
		ongoingLinkedClusterShortPathLengthDistribution->ongoingAccumulate(projectionIndex,(Distribution*) linkedClusterShortPathLengthDistribution);
					#endif
				#endif
			#endif

		ongoingClusterModularity[projectionIndex]+=((double) clusterModularity);

		ongoingNbClusters[projectionIndex].accumulate((double) nbClusters);
		ongoingMaxClusterSizes[projectionIndex].accumulate((double) maxClusterSize);
		
			#ifdef _3D_ONGOING_STAT_MODE
		ongoingClusterSizeDistribution->ongoingAccumulate(projectionIndex,(Distribution*) clusterSizeDistribution);
			#endif

			#ifdef _LOOP_STAT_MODE
				#ifdef _3D_ONGOING_STAT_MODE
		ongoingClusterLoopSizeDistribution->ongoingAccumulate(projectionIndex,(Distribution*) loopSizeDistribution);
				#endif
				
		ongoingClusterNbLoops[projectionIndex].accumulate((double) nbLoops);
			#endif

			#ifdef _SMALL_WORLD_STAT_MODE
		ongoingClusterInternalDensity[projectionIndex].accumulate((double) clusterInternalDensity->getMean());
		ongoingRealClusterInternalDensity[projectionIndex].accumulate((double) realClusterInternalDensity->getMean());
				
				#ifdef _CLUSTER_CENTRALITY_STAT_MODE
					#ifdef _3D_ONGOING_STAT_MODE
						#ifdef _CUMUL_PROBA_STAT_MODE
		ongoingLinkedClusterClusteringCoeffDistribution->ongoingAccumulateCumulProba(projectionIndex,(LogDistribution*) clusteringCoeffDistribution);
						#else
							#ifdef _PROBA_STAT_MODE
		ongoingLinkedClusterClusteringCoeffDistribution->ongoingAccumulateProba(projectionIndex,(LogDistribution*) clusteringCoeffDistribution);
							#else
		ongoingLinkedClusterClusteringCoeffDistribution->ongoingAccumulate(projectionIndex,(LogDistribution*) clusteringCoeffDistribution);		
							#endif	
						#endif
		ongoingLinkedClusterClusteringCoeffDegreeDistribution->ongoingCumulate(projectionIndex,(MeanDistribution*) clusteringCoeffDegreeDistribution);
					#endif
				#endif
			#endif
			
			
			#ifdef _MOTIF_STAT_MODE
				#ifdef _CLUSTER_CENTRALITY_STAT_MODE
					#ifdef _3D_ONGOING_STAT_MODE
		ongoingLinkedClusterTrinodeMotifsDistribution->ongoingAccumulate(projectionIndex,(Distribution*) trinodeMotifsDistribution);
					#endif
				#endif
				
				#ifdef _INTERNAL_MOTIF_STAT_MODE
					
					#ifdef _3D_ONGOING_STAT_MODE
		ongoingClusterInternalBinodeMotifs[projectionIndex].accumulate(((double) ((Counter*) internalBinodeMotifs)->getCounter())/2.0);
		ongoingClusterInternalTrinodeMotifsDistribution->ongoingAccumulate(projectionIndex,(Distribution*) internalTrinodeMotifsDistribution);
					#endif
				#endif
			#endif

			#ifdef _DEGREE_STAT_MODE
				#ifdef _CLUSTER_CENTRALITY_STAT_MODE
					
					#ifdef _3D_ONGOING_STAT_MODE
		ongoingLinkedClusterDegreeDistribution->ongoingAccumulate(projectionIndex,(Distribution*) degreeDistribution);
		ongoingLinkedClusterPreDegreeDistribution->ongoingAccumulate(projectionIndex,(Distribution*) preDegreeDistribution);
		ongoingLinkedClusterPostDegreeDistribution->ongoingAccumulate(projectionIndex,(Distribution*) postDegreeDistribution);
		
		ongoingLinkedClusterNearestNeighboursDegreeDistribution->ongoingCumulate(projectionIndex,(MeanDistribution*) nearestNeighboursDegreeDistribution);
					#endif
				#endif
			#endif
	}
}

void NetworkStater::statAssemblyBetweenness(int projectionIndex)
{
			#ifdef _TEST_STAT
	cout << "stat AssemblyBetweenness : Projection index = " << projectionIndex << endl;
			#endif
			
	if (0 <= projectionIndex && projectionIndex<NB_PROJECTIONS_EACH_CHROMOSOME)
	{
			
			#ifdef _3D_ONGOING_STAT_MODE
				#ifdef _CUMUL_PROBA_STAT_MODE
		ongoingAssemblyCentralBetweennessDistribution->ongoingAccumulateCumulProba(projectionIndex,(LogDistribution*) assemblyCentralBetweennessDistribution);
				#else
					#ifdef _PROBA_STAT_MODE
		ongoingAssemblyCentralBetweennessDistribution->ongoingAccumulateProba(projectionIndex,(LogDistribution*) assemblyCentralBetweennessDistribution);
					#else
		ongoingAssemblyCentralBetweennessDistribution->ongoingAccumulate(projectionIndex,(LogDistribution*) assemblyCentralBetweennessDistribution);	
					#endif
				#endif
			#endif
		ongoingAssemblyCentralBetweenness[projectionIndex].accumulate((double) assemblyCentralBetweenness->getMean());

			
			#ifdef _3D_ONGOING_STAT_MODE
				#ifdef _CUMUL_PROBA_STAT_MODE
		ongoingAssemblyBetweennessDistribution->ongoingAccumulateCumulProba(projectionIndex,(LogDistribution*) assemblyBetweennessDistribution);
				#else
					#ifdef _PROBA_STAT_MODE
		ongoingAssemblyBetweennessDistribution->ongoingAccumulateProba(projectionIndex,(LogDistribution*) assemblyBetweennessDistribution);
					#else
		ongoingAssemblyBetweennessDistribution->ongoingAccumulate(projectionIndex,(LogDistribution*) assemblyBetweennessDistribution);		
					#endif
				#endif
			#endif
			
		ongoingAssemblyBetweenness[projectionIndex].accumulate((double) assemblyBetweenness->getMean());
	}
}

			#ifdef _EDGE_BETWEENNESS_STAT_MODE
void NetworkStater::statAssemblyEdgeBetweenness(int projectionIndex)
{	
	if (0 <= projectionIndex && projectionIndex<NB_PROJECTIONS_EACH_CHROMOSOME)
	{
				
				#ifdef _3D_ONGOING_STAT_MODE
					#ifdef _CUMUL_PROBA_STAT_MODE
		ongoingAssemblyEdgeBetweennessDistribution->ongoingAccumulateCumulProba(projectionIndex,(LogDistribution*) assemblyEdgeBetweennessDistribution);
					#else
						#ifdef _PROBA_STAT_MODE
		ongoingAssemblyEdgeBetweennessDistribution->ongoingAccumulateProba(projectionIndex,(LogDistribution*) assemblyEdgeBetweennessDistribution);
						#else
		ongoingAssemblyEdgeBetweennessDistribution->ongoingAccumulate(projectionIndex,(LogDistribution*) assemblyEdgeBetweennessDistribution);	
						#endif			
					#endif
				#endif
				
		ongoingAssemblyMaxEdgeBetweenness[projectionIndex].accumulate((double) assemblyMaxEdgeBetweenness);
	}
}
			#endif

void NetworkStater::statAssemblyEfficiency(int projectionIndex)
{
	if (0 <= projectionIndex && projectionIndex<NB_PROJECTIONS_EACH_CHROMOSOME)
	{
			
			#ifdef _3D_ONGOING_STAT_MODE
				#ifdef _CUMUL_PROBA_STAT_MODE
		ongoingAssemblyGlobalEfficiencyDistribution->ongoingAccumulateCumulProba(projectionIndex,(LogDistribution*) assemblyGlobalEfficiencyDistribution);
				#else
					#ifdef _PROBA_STAT_MODE
		ongoingAssemblyGlobalEfficiencyDistribution->ongoingAccumulateProba(projectionIndex,(LogDistribution*) assemblyGlobalEfficiencyDistribution);	
					#else
		ongoingAssemblyGlobalEfficiencyDistribution->ongoingAccumulate(projectionIndex,(LogDistribution*) assemblyGlobalEfficiencyDistribution);		
					#endif		
				#endif
			#endif
			
		ongoingAssemblyGlobalEfficiency[projectionIndex].accumulate((double) assemblyGlobalEfficiency->getMean());
	}

	if (0 <= projectionIndex && projectionIndex<NB_PROJECTIONS_EACH_CHROMOSOME)
	{
			
			#ifdef _3D_ONGOING_STAT_MODE
				#ifdef _CUMUL_PROBA_STAT_MODE
		ongoingAssemblyLocalEfficiencyDistribution->ongoingAccumulateCumulProba(projectionIndex,(LogDistribution*) assemblyLocalEfficiencyDistribution);
				#else
					#ifdef _PROBA_STAT_MODE
		ongoingAssemblyLocalEfficiencyDistribution->ongoingAccumulateProba(projectionIndex,(LogDistribution*) assemblyLocalEfficiencyDistribution);	
					#else
		ongoingAssemblyLocalEfficiencyDistribution->ongoingAccumulateProba(projectionIndex,(LogDistribution*) assemblyLocalEfficiencyDistribution);		
					#endif			
				#endif
			#endif
		ongoingAssemblyLocalEfficiency[projectionIndex].accumulate((double) assemblyLocalEfficiency->getMean());
	}
}

void NetworkStater::statAssemblyShortPathLength(int projectionIndex)
{
	if (0 <= projectionIndex && projectionIndex<NB_PROJECTIONS_EACH_CHROMOSOME)
	{
			#ifdef _3D_ONGOING_STAT_MODE
					ongoingAssemblyShortPathLengthDistribution->ongoingAccumulate(projectionIndex,(Distribution*) assemblyShortPathLengthDistribution);
			#endif
	}
}
			#ifdef _NETWORK_CLUSTER_STAT_MODE
				#ifdef _OPTIMAL_CLUSTERS_STAT_MODE

bool NetworkStater::checkOptimalClusters(int projectionIndex)
{
	if (curMaxModularity < clusterModularity)
	{
		cout << "Stating optimal cluster with modularity " << clusterModularity << endl;
		
		curMaxModularity = clusterModularity;
		curMaxModularityProjectionIndex = projectionIndex;
		
		return 1;
	}
	else
	{
		return 0;
	}
}	
	
void NetworkStater::statOptimalClusters()
{
	if (maxModularityProjectionIndex)
	{
		maxModularityProjectionIndex->accumulate(curMaxModularityProjectionIndex);
	}

					#ifdef _ANOVA_STAT_MODE
	if (maxModularityProjectionIndexFile)
	{
		maxModularityProjectionIndexFile->addValueData(getEvoIndex(),getTopoIndex(),curMaxModularityProjectionIndex);
	}
					#endif
				
	if (maxModularity)
	{
		maxModularity->accumulate(curMaxModularity);
	}
					#ifdef _ANOVA_STAT_MODE
	if (maxModularityFile)
	{
		maxModularityFile->addValueData(getEvoIndex(),getTopoIndex(),curMaxModularity);
	}
					#endif
					
					#ifdef _LINKED_CLUSTER_STAT_MODE
	// Repartition des clusters dans les composants pour le réseau optimal
	if (maxModularityInDC)
	{
		maxModularityInDC->accumulate((double) inDC->getAccu());
	}

	if (maxModularityInGOUT)
	{
		maxModularityInGOUT->accumulate((double) inGOUT->getAccu());
	}

	if (maxModularityInGIN)
	{
		maxModularityInGIN->accumulate((double) inGIN->getAccu());
	}

	if (maxModularityInGSCC)
	{
		maxModularityInGSCC->accumulate((double) inGSCC->getAccu());
	}

					#endif

	// Repartition de la taille des clusters pour le réseau optimal
	if (maxModularityClusterSizeDistribution)
	{
		maxModularityClusterSizeDistribution->accumulate((Distribution*) clusterSizeDistribution);
	}
	else
	{
		cerr << "Warning, maxModularityClusterSizeDistribution should be inited" << endl;
	}
	
	// Repartition de l'efficacité des clusters pour le réseau optimal
		
	if (maxModularityClusterEfficiency)
	{
		maxModularityClusterEfficiency->accumulate((double) clusterEfficiency->getMean());
		//maxModularityClusterEfficiency->accumulate((double) clusterEfficiency->getAccu());
	}
	
					#ifdef _ANOVA_STAT_MODE
	if (maxModularityClusterEfficiencyFile)
	{
		maxModularityClusterEfficiencyFile->addValueData(getEvoIndex(),getTopoIndex(),clusterEfficiency->getMean());
	}
					#endif
				
	if (maxModularityClusterEfficiencyDistribution)
	{
					#ifdef _CUMUL_PROBA_STAT_MODE
		maxModularityClusterEfficiencyDistribution->accumulateCumulProba((LogDistribution*) clusterEfficiencyDistribution);
					#else
						#ifdef _PROBA_STAT_MODE
		maxModularityClusterEfficiencyDistribution->accumulateProba((LogDistribution*) clusterEfficiencyDistribution);
						#else
		maxModularityClusterEfficiencyDistribution->accumulate((LogDistribution*) clusterEfficiencyDistribution);	
						#endif				
					#endif
	}
	
	if (maxModularityClusterRealEfficiency)
	{
		maxModularityClusterRealEfficiency->accumulate((double) clusterRealEfficiency->getMean());
		//maxModularityClusterRealEfficiency->accumulate((double) clusterRealEfficiency->getAccu());
	}				
		
					#ifdef _ANOVA_STAT_MODE
	if (maxModularityClusterRealEfficiencyFile)
	{
		maxModularityClusterRealEfficiencyFile->addValueData(getEvoIndex(),getTopoIndex(),clusterRealEfficiency->getMean());
	}
					#endif
				
	if (maxModularityClusterRealEfficiencyDistribution)
	{
					#ifdef _CUMUL_PROBA_STAT_MODE
		maxModularityClusterRealEfficiencyDistribution->accumulateCumulProba((LogDistribution*) clusterRealEfficiencyDistribution);
					#else
						#ifdef _PROBA_STAT_MODE
		maxModularityClusterRealEfficiencyDistribution->accumulateProba((LogDistribution*) clusterRealEfficiencyDistribution);
						#else
		maxModularityClusterRealEfficiencyDistribution->accumulate((LogDistribution*) clusterRealEfficiencyDistribution);	
						#endif				
					#endif
	}
					
					#ifdef _LOOP_STAT_MODE
	if (maxModularityClusterLoopSizeDistribution)
	{
		maxModularityClusterLoopSizeDistribution->accumulate((Distribution*) loopSizeDistribution);
	}
	else
	{
		cerr << "Warning, maxModularityClusterLoopSizeDistribution should be inited" << endl;
	}		
				
					#endif
					
					#ifdef _SMALL_WORLD_STAT_MODE
	if (maxModularityClusterInternalDensity)
	{
		maxModularityClusterInternalDensity->accumulate((double) clusterInternalDensity->getMean());
	}
	
						#ifdef _ANOVA_STAT_MODE
	if (maxModularityClusterInternalDensityFile)
	{
		maxModularityClusterInternalDensityFile->addValueData(getEvoIndex(),getTopoIndex(),clusterInternalDensity->getMean());
	}
						#endif
						
	if (maxModularityRealClusterInternalDensity)
	{
		maxModularityRealClusterInternalDensity->accumulate((double) realClusterInternalDensity->getMean());
	}
						#ifdef _ANOVA_STAT_MODE
	if (maxModularityRealClusterInternalDensityFile)
	{
		maxModularityRealClusterInternalDensityFile->addValueData(getEvoIndex(),getTopoIndex(),realClusterInternalDensity->getMean());
	}
						#endif
					
						#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	if (maxModularityLinkedClusterClusteringCoeffDistribution)
	{
							#ifdef _CUMUL_PROBA_STAT_MODE
		maxModularityLinkedClusterClusteringCoeffDistribution->accumulateCumulProba((LogDistribution*) clusteringCoeffDistribution);
							#else
								#ifdef _PROBA_STAT_MODE
		maxModularityLinkedClusterClusteringCoeffDistribution->accumulateProba((LogDistribution*) clusteringCoeffDistribution);
								#else
		maxModularityLinkedClusterClusteringCoeffDistribution->accumulate((LogDistribution*) clusteringCoeffDistribution);	
								#endif	
							#endif
	}
	
	if (maxModularityLinkedClusterClusteringCoeffDegreeDistribution)
	{
		((CumulatedDistribution*) maxModularityLinkedClusterClusteringCoeffDegreeDistribution)->cumulate((MeanDistribution*) clusteringCoeffDegreeDistribution);
	}
						#endif
					#endif
				
					#ifdef _INTERNAL_MOTIF_STAT_MODE
	if (maxModularityClusterInternalBinodeMotifs)
	{
		maxModularityClusterInternalBinodeMotifs->accumulate(((double) internalBinodeMotifs->getCounter())/2.0);
	}
	
	if (maxModularityClusterInternalTrinodeMotifsDistribution)
	{
		maxModularityClusterInternalTrinodeMotifsDistribution->accumulate((Distribution*) internalTrinodeMotifsDistribution);
	}
	
						#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	if (maxModularityLinkedClusterTrinodeMotifsDistribution)
	{
		maxModularityLinkedClusterTrinodeMotifsDistribution->accumulate((Distribution*) trinodeMotifsDistribution);
	}
						#endif
					#endif
				
					#ifdef _DEGREE_STAT_MODE
						#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	if (maxModularityLinkedClusterDegreeDistribution)
	{
		maxModularityLinkedClusterDegreeDistribution->accumulate((Distribution*) degreeDistribution);
	}
	
	if (maxModularityLinkedClusterPreDegreeDistribution)
	{
		maxModularityLinkedClusterPreDegreeDistribution->accumulate((Distribution*) preDegreeDistribution);
	}
	
	if (maxModularityLinkedClusterPostDegreeDistribution)
	{
		maxModularityLinkedClusterPostDegreeDistribution->accumulate((Distribution*) postDegreeDistribution);
	}
		
	if (maxModularityLinkedClusterNearestNeighboursDegreeDistribution)
	{
		maxModularityLinkedClusterNearestNeighboursDegreeDistribution->cumulate((MeanDistribution*) nearestNeighboursDegreeDistribution);
	}
						#endif
					#endif
					
					
					#ifdef _INPUT_OUTPUT_CLUSTER_STAT_MODE	
	
	if (maxModularityInputClusterSizeDistribution)
	{
		maxModularityInputClusterSizeDistribution->accumulate((Distribution*) inputClusterSizeDistribution);
	}

	if (maxModularityOutputClusterSizeDistribution)
	{
		maxModularityOutputClusterSizeDistribution->accumulate((Distribution*) outputClusterSizeDistribution);
	}

	if (maxModularityInputClusterFractionRepartition)
	{
		for (int i=0;i<NB_INPUT_ASSEMBLIES;i++)
		{
			if (0.0 <= (double) inputClusterFractionRepartition[i])
			{
				maxModularityInputClusterFractionRepartition[i].accumulate((double) inputClusterFractionRepartition[i]);
			}
			else
			{
				maxModularityInputClusterFractionRepartition[i].accumulate(0.0);
			}
		}
		
	}
	
	if (maxModularityOutputClusterFractionRepartition)
	{
		for (int i=0;i<NB_OUTPUT_ASSEMBLIES;i++)
		{
			if (0.0 <= (double) outputClusterFractionRepartition[i])
			{
				maxModularityOutputClusterFractionRepartition[i].accumulate((double) outputClusterFractionRepartition[i]);
			}
			else
			{
				maxModularityOutputClusterFractionRepartition[i].accumulate(0.0);
			}
		}
		
	}
					#endif
}
					#ifdef _MATRIX_CLUSTERS_STAT_MODE
void NetworkStater::initClusterMatrix()
{
	for (int i = 0;i < NB_ASSEMBLIES; i++)
	{
		for (int j = 0;j < NB_ASSEMBLIES; j++)
		{
			clusterMatrix[i][j] = 0;
		}
	}
}

void NetworkStater::printClusterMatrix()
{
	for (int i = 0;i < NB_ASSEMBLIES; i++)
	{
		ostringstream oss;
		for (int j = 0;j < NB_ASSEMBLIES; j++)
		{
			oss << clusterMatrix[i][j] << " ";
		}
		
		clusterMatrixFile->addStringLine(oss.str());
	}
	
	clusterMatrixFile->addDataSeparator();
}
			
void NetworkStater::statMatrixClusters(Cluster* curCluster)
{
	std::vector<Assembly*>::iterator itAss = ((Cluster*) curCluster)->clusterAssemblies.begin();
	std::vector<Assembly*>::iterator endAss = ((Cluster*) curCluster)->clusterAssemblies.end();
	
	while (itAss != endAss)
	{
		std::vector<Assembly*>::iterator itAss2 = ((Cluster*) curCluster)->clusterAssemblies.begin();
		std::vector<Assembly*>::iterator endAss2 = ((Cluster*) curCluster)->clusterAssemblies.end();
		
		while (itAss2 != endAss2)
		{
			clusterMatrix[((Assembly*) *itAss)->getIndex()][((Assembly*) *itAss2)->getIndex()] = 1;
			
			itAss2++;
		}
		itAss++;
	}
}
					#endif
				#endif

void NetworkStater::statNetworkClusters()
{
				#ifdef _LINKED_CLUSTER_STAT_MODE
	// Repartition des clusters dans les composants pour le réseau à la fin du processus de clusterisation
	if (networkInDC)
	{
		networkInDC->accumulate((double) inDC->getAccu());
	}

	if (networkInGOUT)
	{
		networkInGOUT->accumulate((double) inGOUT->getAccu());
	}

	if (networkInGIN)
	{
		networkInGIN->accumulate((double) inGIN->getAccu());
	}

	if (networkInGSCC)
	{
		networkInGSCC->accumulate((double) inGSCC->getAccu());
	}

				#endif
			
	// Repartition de l'efficacité des clusters pour le réseau final
	if (networkClusterEfficiency)
	{
		networkClusterEfficiency->accumulate((double) clusterEfficiency->getMean());
		//networkClusterEfficiency->accumulate((double) clusterEfficiency->getAccu());
	}
				#ifdef _ANOVA_STAT_MODE
	if (networkClusterEfficiencyFile)
	{
		networkClusterEfficiencyFile->addValueData(getEvoIndex(),getTopoIndex(),clusterEfficiency->getMean());
	}
				#endif
			
	if (networkClusterEfficiencyDistribution)
	{
				#ifdef _CUMUL_PROBA_STAT_MODE
		networkClusterEfficiencyDistribution->accumulateCumulProba((LogDistribution*) clusterEfficiencyDistribution);
				#else
					#ifdef _PROBA_STAT_MODE
		networkClusterEfficiencyDistribution->accumulateProba((LogDistribution*) clusterEfficiencyDistribution);
					#else
		networkClusterEfficiencyDistribution->accumulate((LogDistribution*) clusterEfficiencyDistribution);
					#endif				
				#endif
	}
	
	if (networkClusterRealEfficiency)
	{
		networkClusterRealEfficiency->accumulate((double) clusterRealEfficiency->getMean());
		//networkClusterRealEfficiency->accumulate((double) clusterRealEfficiency->getAccu());
	}				

				#ifdef _ANOVA_STAT_MODE
	if (networkClusterRealEfficiencyFile)
	{
		networkClusterRealEfficiencyFile->addValueData(getEvoIndex(),getTopoIndex(),clusterRealEfficiency->getMean());
	}
				#endif
			
	if (networkClusterRealEfficiencyDistribution)
	{
				#ifdef _CUMUL_PROBA_STAT_MODE
		networkClusterRealEfficiencyDistribution->accumulateCumulProba((LogDistribution*) clusterRealEfficiencyDistribution);
				#else
					#ifdef _PROBA_STAT_MODE
		networkClusterRealEfficiencyDistribution->accumulateProba((LogDistribution*) clusterRealEfficiencyDistribution);	
					#else
		networkClusterRealEfficiencyDistribution->accumulate((LogDistribution*) clusterRealEfficiencyDistribution);	
					#endif			
				#endif
	}

	// Taille des clusters
	if (networkClusterSizeDistribution)
	{
		networkClusterSizeDistribution->accumulate((Distribution*) clusterSizeDistribution);
	}

		
				#ifdef _LOOP_STAT_MODE
	if (networkClusterLoopSizeDistribution)
	{
		networkClusterLoopSizeDistribution->accumulate((Distribution*) loopSizeDistribution);
	}
	else
	{
		cerr << "Warning, networkClusterLoopSizeDistribution should be inited" << endl;
	}		
				#endif
				
				#ifdef _SMALL_WORLD_STAT_MODE
	if (networkClusterInternalDensity)
	{
		networkClusterInternalDensity->accumulate((double) clusterInternalDensity->getMean());
	}
	
					#ifdef _ANOVA_STAT_MODE
	if (networkClusterInternalDensityFile)
	{
		networkClusterInternalDensityFile->addValueData(getEvoIndex(),getTopoIndex(),clusterInternalDensity->getMean());
	}
					#endif
					
	if (networkRealClusterInternalDensity)
	{
		networkRealClusterInternalDensity->accumulate((double) realClusterInternalDensity->getMean());
	}
					#ifdef _ANOVA_STAT_MODE
	if (networkRealClusterInternalDensityFile)
	{
		networkRealClusterInternalDensityFile->addValueData(getEvoIndex(),getTopoIndex(),realClusterInternalDensity->getMean());
	}
					#endif
	
					#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	if (networkLinkedClusterClusteringCoeffDistribution)
	{
						#ifdef _CUMUL_PROBA_STAT_MODE
		networkLinkedClusterClusteringCoeffDistribution->accumulateCumulProba((LogDistribution*) clusteringCoeffDistribution);
						#else
							#ifdef _PROBA_STAT_MODE
		networkLinkedClusterClusteringCoeffDistribution->accumulateProba((LogDistribution*) clusteringCoeffDistribution);	
							#else
		networkLinkedClusterClusteringCoeffDistribution->accumulate((LogDistribution*) clusteringCoeffDistribution);	
							#endif	
						#endif
	}
	
	if (networkLinkedClusterClusteringCoeffDegreeDistribution)
	{
		((CumulatedDistribution*) networkLinkedClusterClusteringCoeffDegreeDistribution)->cumulate((MeanDistribution*) clusteringCoeffDegreeDistribution);
	}
					#endif
				#endif
				
				#ifdef _INTERNAL_MOTIF_STAT_MODE
	if (networkClusterInternalBinodeMotifs)
	{
		networkClusterInternalBinodeMotifs->accumulate(((double) internalBinodeMotifs->getCounter())/2.0);
	}
	
	if (networkClusterInternalTrinodeMotifsDistribution)
	{
		networkClusterInternalTrinodeMotifsDistribution->accumulate((Distribution*) internalTrinodeMotifsDistribution);
	}
	
					#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	if (networkLinkedClusterTrinodeMotifsDistribution)
	{
		networkLinkedClusterTrinodeMotifsDistribution->accumulate((Distribution*) trinodeMotifsDistribution);
	}
					#endif
				#endif
				
				#ifdef _DEGREE_STAT_MODE
					#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	if (networkLinkedClusterDegreeDistribution)
	{
		networkLinkedClusterDegreeDistribution->accumulate((Distribution*) degreeDistribution);
	}
	
	if (networkLinkedClusterPreDegreeDistribution)
	{
		networkLinkedClusterPreDegreeDistribution->accumulate((Distribution*) preDegreeDistribution);
	}
	
	if (networkLinkedClusterPostDegreeDistribution)
	{
		networkLinkedClusterPostDegreeDistribution->accumulate((Distribution*) postDegreeDistribution);
	}
		
	if (networkLinkedClusterNearestNeighboursDegreeDistribution)
	{
		networkLinkedClusterNearestNeighboursDegreeDistribution->cumulate((MeanDistribution*) nearestNeighboursDegreeDistribution);
	}
					#endif
				#endif
}
			#endif
			
			#ifdef _LOOP_STAT_MODE
void NetworkStater::statAssemblyLoops(int projectionIndex)
{				
	if (0 <= projectionIndex && projectionIndex<NB_PROJECTIONS_EACH_CHROMOSOME)
	{
				
				#ifdef _3D_ONGOING_STAT_MODE
					#ifdef _CUMUL_PROBA_STAT_MODE
		ongoingAssemblyNbLoopsDistribution->ongoingAccumulateCumulProba(projectionIndex,(LogDistribution*) nbLoopsDistribution);
					#else
						#ifdef _PROBA_STAT_MODE
		ongoingAssemblyNbLoopsDistribution->ongoingAccumulateProba(projectionIndex,(LogDistribution*) nbLoopsDistribution);	
						#else
		ongoingAssemblyNbLoopsDistribution->ongoingAccumulate(projectionIndex,(LogDistribution*) nbLoopsDistribution);
						#endif	
					#endif
		ongoingAssemblyNbLoopsDegreeDistribution->ongoingCumulate(projectionIndex,(MeanDistribution*) nbLoopsDegreeDistribution);
		ongoingAssemblyLoopSizeDistribution->ongoingAccumulate(projectionIndex,(Distribution*) loopSizeDistribution);
				#endif
				
		ongoingAssemblyNbLoops[projectionIndex].accumulate((double) nbLoops);
	}
}
			#endif
			
			#ifdef _SMALL_WORLD_STAT_MODE
void NetworkStater::statAssemblyClusteringCoeff(int projectionIndex)
{
	if (0 <= projectionIndex && projectionIndex<NB_PROJECTIONS_EACH_CHROMOSOME)
	{
				
				#ifdef _3D_ONGOING_STAT_MODE
					#ifdef _CUMUL_PROBA_STAT_MODE
		ongoingAssemblyClusteringCoeffDistribution->ongoingAccumulateCumulProba(projectionIndex,(LogDistribution*) clusteringCoeffDistribution);
					#else
						#ifdef _PROBA_STAT_MODE
		ongoingAssemblyClusteringCoeffDistribution->ongoingAccumulateProba(projectionIndex,(LogDistribution*) clusteringCoeffDistribution);	
						#else
		ongoingAssemblyClusteringCoeffDistribution->ongoingAccumulate(projectionIndex,(LogDistribution*) clusteringCoeffDistribution);
						#endif	
					#endif
		ongoingAssemblyClusteringCoeffDegreeDistribution->ongoingCumulate(projectionIndex,(MeanDistribution*) clusteringCoeffDegreeDistribution);
				#endif
	}	
}
			#endif
			
			#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE
void NetworkStater::statAssemblyInputOutputLinks(int projectionIndex)
{
	if (0 <= projectionIndex && projectionIndex<NB_PROJECTIONS_EACH_CHROMOSOME)
	{
				
				#ifdef _3D_ONGOING_STAT_MODE
		ongoingAssemblyReachedByInputDistribution->ongoingAccumulate(projectionIndex,(Distribution*) reachedByInputDistribution);	
		ongoingAssemblyReachedByOutputDistribution->ongoingAccumulate(projectionIndex,(Distribution*) reachedByOutputDistribution);	
		
		ongoingAssemblyInputOutputPathLengthDistribution->ongoingAccumulate(projectionIndex,(Distribution*) inputOutputPathLengthDistribution);	
		ongoingAssemblyPathToInputDistribution->ongoingAccumulate(projectionIndex,(Distribution*) pathToInputDistribution);	
		ongoingAssemblyPathToOutputDistribution->ongoingAccumulate(projectionIndex,(Distribution*) pathToOutputDistribution);	
				#endif
	}
}
			#endif
			
			#ifdef _MOTIF_STAT_MODE
void NetworkStater::statAssemblyMotifs(int projectionIndex)
{
	if (0 <= projectionIndex && projectionIndex<NB_PROJECTIONS_EACH_CHROMOSOME)
	{
				
				#ifdef _3D_ONGOING_STAT_MODE
		ongoingAssemblyBinodeMotifs[projectionIndex].accumulate(((double) ((Counter*) binodeMotifs)->getCounter())/((double) 2.0));
		ongoingAssemblyTrinodeMotifsDistribution->ongoingAccumulate(projectionIndex,(Distribution*) trinodeMotifsDistribution);
				#endif
	}
}
			#endif
			
			#ifdef _DEGREE_STAT_MODE
void NetworkStater::statAssemblyDegree(int projectionIndex)
{
	if (0 <= projectionIndex && projectionIndex<NB_PROJECTIONS_EACH_CHROMOSOME)
	{
				
				#ifdef _3D_ONGOING_STAT_MODE
		ongoingAssemblyDegreeDistribution->ongoingAccumulate(projectionIndex,(Distribution*) degreeDistribution);
		ongoingAssemblyPreDegreeDistribution->ongoingAccumulate(projectionIndex,(Distribution*) preDegreeDistribution);
		ongoingAssemblyPostDegreeDistribution->ongoingAccumulate(projectionIndex,(Distribution*) postDegreeDistribution);
		
		ongoingAssemblyNearestNeighboursDegreeDistribution->ongoingCumulate(projectionIndex,(MeanDistribution*) nearestNeighboursDegreeDistribution);
				#endif
				
				#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE
		// In/Out
					
					#ifdef _3D_ONGOING_STAT_MODE
		ongoingInputAssemblyDegreeDistribution->ongoingAccumulate(projectionIndex,(Distribution*) inputNodeDegreeDistribution);
		ongoingOutputAssemblyDegreeDistribution->ongoingAccumulate(projectionIndex,(Distribution*) outputNodeDegreeDistribution);
		
		ongoingInputAssemblyNearestNeighboursDegreeDistribution->ongoingCumulate(projectionIndex,(MeanDistribution*) inputNodeNearestNeighboursDegreeDistribution);
		ongoingOutputAssemblyNearestNeighboursDegreeDistribution->ongoingCumulate(projectionIndex,(MeanDistribution*) outputNodeNearestNeighboursDegreeDistribution);
					#endif
				#endif
	}	
}
			#endif
			
			#ifdef _GSCC_STAT_MODE
void NetworkStater::statAssemblyGSCC(int projectionIndex)
{
	if (0 <= projectionIndex && projectionIndex<NB_PROJECTIONS_EACH_CHROMOSOME)
	{
		ongoingNbGSCCNodes[projectionIndex].accumulate((double) tabGSCCNodes.size());
			
				#ifdef _3D_ONGOING_STAT_MODE
		ongoingSCComponentSizeDistribution->ongoingAccumulate(projectionIndex, (Distribution*) SCComponentSizeDistribution);
				#endif
				
		ongoingMaxSCComponentSize[projectionIndex].accumulate((double) maxSCComponentSize);
				
				#ifdef _3D_ONGOING_STAT_MODE
		ongoingMaxSCComponentSizeDistribution->ongoingCount(projectionIndex,(int) maxSCComponentSize);
				#endif
	}
}
			#endif
		#endif
	#endif
	
void NetworkStater::stat()
{
	#ifdef _TOPOLOGY_STAT_MODE
	for (int i = 0;i < NB_ASSEMBLIES;i++)
	{
		ostringstream oss;
		for (int j=0;j < NB_ASSEMBLIES;j++)
		{
			oss << connectivityMatrix[i][j] << " ";
			
			//cerr  << "connectivityMatrix[" << i << "][" << j << "]" << connectivityMatrix[i][j] << endl;
		}
		
		topologyMatrixFile->addStringLine(oss.str());
		
	}
	
	topologyMatrixFile->addDataSeparator();
	
	#endif
	
	#ifdef _LINK_TO_INPUT_STAT_MODE
	for (int i = 0;i < NB_ASSEMBLIES;i++)
	{
		linkToInputFile->addDotData(i,linkToInputVector[i]);
	}
	
	linkToInputFile->addDataSeparator();
	#endif
	
	#ifdef _LINK_TO_OUTPUT_STAT_MODE
	for (int i = 0;i < NB_ASSEMBLIES;i++)
	{
		linkToOutputFile->addDotData(i,linkToOutputVector[i]);
	}
	
	linkToOutputFile->addDataSeparator();
	#endif
	
	#ifdef _CENTRALITY_STAT_MODE

		#ifndef _CLUSTER_STAT_MODE
			
	//cerr << "In stat cetrality" << endl;
	// Calcul d'intermediarité
	if (meanAssemblyBetweennessRepartition)
	{
		for (int i=0;i<NB_ASSEMBLIES;i++)
		{
			if (0.0 <= (double) assemblyBetweennessRepartition[i])
			{
				meanAssemblyBetweennessRepartition[i].accumulate((double) assemblyBetweennessRepartition[i]);
			}
			else
			{
				meanAssemblyBetweennessRepartition[i].accumulate(0.0);
			}
		}
		
	}

	if (meanAssemblyBetweenness)
	{
		meanAssemblyBetweenness->accumulate(assemblyBetweenness->getMean());
	}

	if (meanAssemblyBetweennessDistribution)
	{
			#ifdef _CUMUL_PROBA_STAT_MODE
		meanAssemblyBetweennessDistribution->accumulateCumulProba((LogDistribution*) assemblyBetweennessDistribution);
			#else
				#ifdef _PROBA_STAT_MODE
		meanAssemblyBetweennessDistribution->accumulateProba((LogDistribution*) assemblyBetweennessDistribution);
				#else
		meanAssemblyBetweennessDistribution->accumulate((LogDistribution*) assemblyBetweennessDistribution);
				#endif	
			#endif
	}
	
	// Centralite
	if (meanAssemblyCentralBetweennessRepartition)
	{
		for (int i=0;i<NB_ASSEMBLIES;i++)
		{
			if (0.0 <= (double) assemblyCentralBetweennessRepartition[i])
			{
				meanAssemblyCentralBetweennessRepartition[i].accumulate((double) assemblyCentralBetweennessRepartition[i]);
			}
			else
			{
				meanAssemblyCentralBetweennessRepartition[i].accumulate(0.0);
			}
		}
	}

	if (meanAssemblyCentralBetweenness)
	{
		meanAssemblyCentralBetweenness->accumulate(assemblyCentralBetweenness->getMean());
	}

			#ifdef _ANOVA_STAT_MODE
	if (meanAssemblyCentralBetweennessFile)
	{
		meanAssemblyCentralBetweennessFile->addValueData(getEvoIndex(),getTopoIndex(),assemblyCentralBetweenness->getMean());
	}

	if (meanAssemblyBetweennessFile)
	{
		meanAssemblyBetweennessFile->addValueData(getEvoIndex(),getTopoIndex(),assemblyBetweenness->getMean());
	}
			#endif
			
	if (meanAssemblyCentralBetweennessDistribution)
	{
			#ifdef _CUMUL_PROBA_STAT_MODE
		meanAssemblyCentralBetweennessDistribution->accumulateCumulProba((LogDistribution*) assemblyCentralBetweennessDistribution);
			#else
				#ifdef _PROBA_STAT_MODE
		meanAssemblyCentralBetweennessDistribution->accumulateProba((LogDistribution*) assemblyCentralBetweennessDistribution);
				#else
		meanAssemblyCentralBetweennessDistribution->accumulate((LogDistribution*) assemblyCentralBetweennessDistribution);
				#endif	
			#endif
	}
	
			#ifdef _EDGE_BETWEENNESS_STAT_MODE
				
	//cerr << "In stat edge bet" << endl;
	// Calcul d'intermediarité pour les liens
	if (meanEdgeBetweennessDistribution)
	{
				#ifdef _CUMUL_PROBA_STAT_MODE
		meanEdgeBetweennessDistribution->accumulateCumulProba((LogDistribution*) assemblyEdgeBetweennessDistribution);
				#else
					#ifdef _PROBA_STAT_MODE
		meanEdgeBetweennessDistribution->accumulateProba((LogDistribution*) assemblyEdgeBetweennessDistribution);
					#else
		meanEdgeBetweennessDistribution->accumulate((LogDistribution*) assemblyEdgeBetweennessDistribution);
					#endif	
				#endif
	}

	if (meanEdgeBetweennessRepartition)
	{
		for (int i=0;i<NB_ASSEMBLIES;i++)
		{
			for (int j=0;j<NB_ASSEMBLIES;j++)
			{
				meanEdgeBetweennessRepartition[i][j].accumulate((double) edgeBetweenness[i][j].getMean());
			}
		}
		
	}
	
	//cerr << "After stat edge bet" << endl;
			#endif
			
	// ShortPath
	if (meanAssemblyShortPathRepartition)
	{
		for (int i=0;i<NB_ASSEMBLIES;i++)
		{
			meanAssemblyShortPathRepartition[i].accumulate(((double) assemblyShortPathRepartition[i])/((double) NB_ASSEMBLIES));
		}	
	}

	if (meanAssemblyNoShortPathRepartition)
	{
		for (int i=0;i<NB_ASSEMBLIES;i++)
		{
			meanAssemblyNoShortPathRepartition[i].accumulate(((double) assemblyNoShortPathRepartition[i])/((double) NB_ASSEMBLIES));
		}
		
	}

	if (meanAssemblyNbShortPathDistribution)
	{
		meanAssemblyNbShortPathDistribution->accumulate(assemblyNbShortPathDistribution);
	}
	
	// Calcul d'efficacite
	if (meanAssemblyLocalEfficiencyRepartition)
	{
		for (int i=0;i<NB_ASSEMBLIES;i++)
		{
			if (0.0 <= assemblyLocalEfficiencyRepartition[i])
			{
				meanAssemblyLocalEfficiencyRepartition[i].accumulate((double) assemblyLocalEfficiencyRepartition[i]);
			}
		}
	}

	if (meanAssemblyGlobalEfficiencyRepartition)
	{
		for (int i=0;i<NB_ASSEMBLIES;i++)
		{
			if (0.0 <= assemblyGlobalEfficiencyRepartition[i])
			{
				meanAssemblyGlobalEfficiencyRepartition[i].accumulate((double) assemblyGlobalEfficiencyRepartition[i]);
			}
		}
	}

	if (meanAssemblyGlobalEfficiencyDistribution)
	{
			#ifdef _CUMUL_PROBA_STAT_MODE
		meanAssemblyGlobalEfficiencyDistribution->accumulateCumulProba((LogDistribution*) assemblyGlobalEfficiencyDistribution);
			#else
				#ifdef _PROBA_STAT_MODE
		meanAssemblyGlobalEfficiencyDistribution->accumulateProba((LogDistribution*) assemblyGlobalEfficiencyDistribution);	
				#else
		meanAssemblyGlobalEfficiencyDistribution->accumulate((LogDistribution*) assemblyGlobalEfficiencyDistribution);	
				#endif			
			#endif
	}	
	
	if (meanAssemblyLocalEfficiencyDistribution)
	{
			#ifdef _CUMUL_PROBA_STAT_MODE
		meanAssemblyLocalEfficiencyDistribution->accumulateCumulProba((LogDistribution*) assemblyLocalEfficiencyDistribution);
			#else
				#ifdef _PROBA_STAT_MODE
		meanAssemblyLocalEfficiencyDistribution->accumulateProba((LogDistribution*) assemblyLocalEfficiencyDistribution);	
				#else
		meanAssemblyLocalEfficiencyDistribution->accumulate((LogDistribution*) assemblyLocalEfficiencyDistribution);	
				#endif			
			#endif
	}
	
	if (meanAssemblyGlobalEfficiency)
	{
		meanAssemblyGlobalEfficiency->accumulate(assemblyGlobalEfficiency->getMean());
	}

	if (meanAssemblyLocalEfficiency)
	{
		meanAssemblyLocalEfficiency->accumulate(assemblyLocalEfficiency->getMean());
	}
	
			#ifdef _ANOVA_STAT_MODE
	if (meanAssemblyGlobalEfficiencyFile)
	{
		meanAssemblyGlobalEfficiencyFile->addValueData(getEvoIndex(),getTopoIndex(),assemblyGlobalEfficiency->getMean());
	}

	if (meanAssemblyLocalEfficiencyFile)
	{
		meanAssemblyLocalEfficiencyFile->addValueData(getEvoIndex(),getTopoIndex(),assemblyLocalEfficiency->getMean());
	}
			#endif

	//cerr << "After stat cetrality" << endl;
	
		#endif
	#endif

	// Loops
	#ifdef _LOOP_STAT_MODE
		#ifndef _CLUSTER_STAT_MODE
			
	//cerr << "In stat Loop" << endl;
	if (meanAssemblyLoopSizeDistribution)
	{
		meanAssemblyLoopSizeDistribution->accumulate((Distribution*) loopSizeDistribution);

	}

	if (meanAssemblyNbLoopsRepartition)
	{
		for (int i=0;i<NB_ASSEMBLIES;i++)
		{
			meanAssemblyNbLoopsRepartition[i].accumulate(((double) nbLoopsRepartition[i].getCounter()));
		}
	}
	
	if (meanAssemblyNbLoopsDistribution)
	{
			#ifdef _CUMUL_PROBA_STAT_MODE
		meanAssemblyNbLoopsDistribution->accumulateCumulProba((LogDistribution*) nbLoopsDistribution);
			#else
				#ifdef _PROBA_STAT_MODE
		meanAssemblyNbLoopsDistribution->accumulateProba((LogDistribution*) nbLoopsDistribution);	
				#else
		meanAssemblyNbLoopsDistribution->accumulate((LogDistribution*) nbLoopsDistribution);
				#endif	
			#endif
		
	}
	
	if (meanAssemblyNbLoopsDegreeDistribution)
	{
		meanAssemblyNbLoopsDegreeDistribution->cumulate((MeanDistribution*) nbLoopsDegreeDistribution);
	}
		
	//cerr << "After stat Loop" << endl;
		#endif
	#endif
	
	// Small World
	#ifdef _SMALL_WORLD_STAT_MODE
		#ifndef _CLUSTER_STAT_MODE
			
	//cerr << "In stat Small World" << endl;
	// Distribution
	if (meanClusteringCoeffDistribution)
	{
			#ifdef _CUMUL_PROBA_STAT_MODE
		meanClusteringCoeffDistribution->accumulateCumulProba((LogDistribution*) clusteringCoeffDistribution);
			#else
				#ifdef _PROBA_STAT_MODE
		meanClusteringCoeffDistribution->accumulateProba((LogDistribution*) clusteringCoeffDistribution);	
				#else
		meanClusteringCoeffDistribution->accumulate((LogDistribution*) clusteringCoeffDistribution);
				#endif	
			#endif
	}
	
	// Degree
	if (meanClusteringCoeffDegreeDistribution)
	{
		((CumulatedDistribution*) meanClusteringCoeffDegreeDistribution)->cumulate((MeanDistribution*) clusteringCoeffDegreeDistribution);
	}
	
	// Repartition
	if (meanClusteringCoeffRepartition)
	{
		for (int i=0;i<NB_ASSEMBLIES;i++)
		{
			meanClusteringCoeffRepartition[i].accumulate((double) clusteringCoeffRepartition[i]);
		}
	}
	
	// Network
	if (meanClusteringCoeff)
	{
		meanClusteringCoeff->accumulate(networkClusteringCoeff->getMean());
	}
	
			#ifdef _ANOVA_STAT_MODE
	if (meanClusteringCoeffFile)
	{
		meanClusteringCoeffFile->addValueData(getEvoIndex(),getTopoIndex(),networkClusteringCoeff->getMean());
	}
			#endif
	
	//cerr << "After stat Small World" << endl;
		#endif
	#endif

	#ifdef _MOTIF_STAT_MODE
		#ifndef _CLUSTER_STAT_MODE
			
	if (meanBinodeMotifs)
	{
		meanBinodeMotifs->accumulate(((double) binodeMotifs->getCounter())/2.0);
	}

	if (meanTrinodeMotifsDistribution)
	{
		meanTrinodeMotifsDistribution->accumulateProba((Distribution*) trinodeMotifsDistribution);
	}
			
		#endif
	#endif
	
	#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE
		#ifndef _CLUSTER_STAT_MODE
	if (meanReachedByInputDistribution)
	{
		meanReachedByInputDistribution->accumulate((Distribution*) reachedByInputDistribution);
	}

	if (meanReachedByOutputDistribution)
	{
		meanReachedByOutputDistribution->accumulate((Distribution*) reachedByOutputDistribution);
	}

	if (meanPathToInputDistribution)
	{
		meanPathToInputDistribution->accumulate((Distribution*) pathToInputDistribution);
	}

	if (meanPathToOutputDistribution)
	{
		meanPathToOutputDistribution->accumulate((Distribution*) pathToOutputDistribution);
	}

	if (meanInputOutputPathLengthDistribution)
	{
		meanInputOutputPathLengthDistribution->accumulate((Distribution*) pathToOutputDistribution);
	}
		#endif
	#endif
	
	#ifdef _DEGREE_STAT_MODE
		#ifndef _CLUSTER_STAT_MODE
			
	//cerr << "In stat Degree" << endl;
	if (meanDegreeDistribution)
	{
		meanDegreeDistribution->accumulate((Distribution*) degreeDistribution);
	}
	
	if (meanPreDegreeDistribution)
	{
		meanPreDegreeDistribution->accumulate((Distribution*) preDegreeDistribution);
	}
	
	if (meanPostDegreeDistribution)
	{
		meanPostDegreeDistribution->accumulate((Distribution*) postDegreeDistribution);
	}
	
	if (meanNearestNeighboursDegreeDistribution)
	{
		meanNearestNeighboursDegreeDistribution->cumulate((MeanDistribution*) nearestNeighboursDegreeDistribution);
	}

			#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE
	if (meanInputAssemblyDegreeDistribution)
	{
		meanInputAssemblyDegreeDistribution->accumulate((Distribution*) inputNodeDegreeDistribution);
	}
	
	if (meanOutputAssemblyDegreeDistribution)
	{
		meanOutputAssemblyDegreeDistribution->accumulate((Distribution*) outputNodeDegreeDistribution);
	}
	
	if (meanInputAssemblyNearestNeighboursDegreeDistribution)
	{
		meanInputAssemblyNearestNeighboursDegreeDistribution->cumulate((MeanDistribution*) inputNodeNearestNeighboursDegreeDistribution);
	}
	
	if (meanOutputAssemblyNearestNeighboursDegreeDistribution)
	{
		meanOutputAssemblyNearestNeighboursDegreeDistribution->cumulate((MeanDistribution*) outputNodeNearestNeighboursDegreeDistribution);
	}
			#endif
			
			#ifdef _TEST_STAT
	cout << "After stat Degree" << endl;
			#endif
		#endif
	#endif

	#ifdef _GSCC_STAT_MODE
		#ifndef _CLUSTER_STAT_MODE
	//cerr << "In stat GSCC" << endl;
	if (meanNbGSCCNodes)
	{
		meanNbGSCCNodes->accumulate((double) tabGSCCNodes.size());
	}

	if (meanSCComponentSizeDistribution)
	{
		meanSCComponentSizeDistribution->accumulate((Distribution*) SCComponentSizeDistribution);
	}

	if (meanMaxSCComponentSize)
	{
		meanMaxSCComponentSize->accumulate((double) maxSCComponentSize);
	}

	if (meanMaxSCComponentSizeDistribution)
	{
		meanMaxSCComponentSizeDistribution->count((int) maxSCComponentSize);
	}
	
			
			#ifdef _INPUT_OUTPUT_GSCC_STAT_MODE	
	
	if (meanInputSCComponentSizeDistribution)
	{
		meanInputSCComponentSizeDistribution->accumulate((Distribution*) inputSCComponentSizeDistribution);
	}


	if (meanOutputSCComponentSizeDistribution)
	{
		meanOutputSCComponentSizeDistribution->accumulate((Distribution*) outputSCComponentSizeDistribution);
	}

	if (meanInputSCCFractionRepartition)
	{
		for (int i=0;i<NB_INPUT_ASSEMBLIES;i++)
		{
			if (0.0 <= (double) inputSCCFractionRepartition[i])
			{
				meanInputSCCFractionRepartition[i].accumulate((double) inputSCCFractionRepartition[i]);
			}
			else
			{
				meanInputSCCFractionRepartition[i].accumulate(0.0);
			}
		}
		
	}
	
	if (meanOutputSCCFractionRepartition)
	{
		for (int i=0;i<NB_OUTPUT_ASSEMBLIES;i++)
		{
			if (0.0 <= (double) outputSCCFractionRepartition[i])
			{
				meanOutputSCCFractionRepartition[i].accumulate((double) outputSCCFractionRepartition[i]);
			}
			else
			{
				meanOutputSCCFractionRepartition[i].accumulate(0.0);
			}
		}
		
	}
			#endif
			
			#ifdef _ANOVA_STAT_MODE
	if (meanNbGSCCNodesFile->isOpen())
	{
		meanNbGSCCNodesFile->addValueData(getEvoIndex(),getTopoIndex(),(double) tabGSCCNodes.size());
	}

	if (meanMaxSCComponentSizeFile->isOpen())
	{
		meanMaxSCComponentSizeFile->addValueData(getEvoIndex(),getTopoIndex(),(double) maxSCComponentSize);
	}
			#endif
	//cerr << "After stat GSCC" << endl;
		#endif
	#endif
	
	#ifdef _PROJECTION_STAT_MODE
	if (meanProjections)
	{
		meanProjections->accumulate(countProjections->getCounter());
	}

		
	// Excit/Inhib
	if (meanExcitProjections)
	{
		meanExcitProjections->accumulate(countExcitProjections->getCounter());
	}

	if (meanInhibProjections)
	{
		meanInhibProjections->accumulate(countInhibProjections->getCounter());
	}

	// Input
	if (meanExcitInputProjections)
	{
		meanExcitInputProjections->accumulate(countExcitInputProjections->getCounter());
	}
	if (meanInhibInputProjections)
	{
		meanInhibInputProjections->accumulate(countInhibInputProjections->getCounter());
	}

	// Output
	if (meanExcitOutputProjections)
	{
		meanExcitOutputProjections->accumulate(countExcitOutputProjections->getCounter());
	}

	if (meanInhibOutputProjections)
	{
		meanInhibOutputProjections->accumulate(countInhibOutputProjections->getCounter());
	}

	// Self
	if (meanExcitSelfProjections)
	{
		meanExcitSelfProjections->accumulate(countExcitSelfProjections->getCounter());
	}

	if (meanInhibSelfProjections)
	{
		meanInhibSelfProjections->accumulate(countInhibSelfProjections->getCounter());
	}
	
		#ifdef _ANOVA_STAT_MODE
	if (meanProjectionsFile->isOpen())
	{
		meanProjectionsFile->addValueData(getEvoIndex(),getTopoIndex(),countProjections->getCounter());
	}

		
	// Excit/Inhib
	if (meanExcitProjectionsFile->isOpen())
	{
		meanExcitProjectionsFile->addValueData(getEvoIndex(),getTopoIndex(),countExcitProjections->getCounter());
	}

	if (meanInhibProjectionsFile->isOpen())
	{
		meanInhibProjectionsFile->addValueData(getEvoIndex(),getTopoIndex(),countInhibProjections->getCounter());
	}

	// Input
	if (meanExcitInputProjectionsFile->isOpen())
	{
		meanExcitInputProjectionsFile->addValueData(getEvoIndex(),getTopoIndex(),countExcitInputProjections->getCounter());
	}
	if (meanInhibInputProjectionsFile->isOpen())
	{
		meanInhibInputProjectionsFile->addValueData(getEvoIndex(),getTopoIndex(),countInhibInputProjections->getCounter());
	}

	// Output
	if (meanExcitOutputProjectionsFile->isOpen())
	{
		meanExcitOutputProjectionsFile->addValueData(getEvoIndex(),getTopoIndex(),countExcitOutputProjections->getCounter());
	}

	if (meanInhibOutputProjectionsFile->isOpen())
	{
		meanInhibOutputProjectionsFile->addValueData(getEvoIndex(),getTopoIndex(),countInhibOutputProjections->getCounter());
	}

	// Self
	if (meanExcitSelfProjectionsFile->isOpen())
	{
		meanExcitSelfProjectionsFile->addValueData(getEvoIndex(),getTopoIndex(),countExcitSelfProjections->getCounter());
	}

	if (meanInhibSelfProjectionsFile->isOpen())
	{
		meanInhibSelfProjectionsFile->addValueData(getEvoIndex(),getTopoIndex(),countInhibSelfProjections->getCounter());
	}
	
		#endif
	#endif
}

void NetworkStater::trace()
{
	#ifdef _TEST_STAT
	cerr << "*** NetworkStater *** beginning trace" << endl;
	#endif
	
	#ifdef _CENTRALITY_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
		// Assemblees
	// Calcul de centralité
			
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingAssemblyCentralBetweennessDistributionFile->isOpen())
	{
		if (ongoingAssemblyCentralBetweennessDistribution)
		{
			ongoingAssemblyCentralBetweennessDistributionFile->addOngoingMeanLogDistribution(getEvoIndex(), ongoingAssemblyCentralBetweennessDistribution);
		}
		else
		{
			cerr << "Warning, ongoingAssemblyCentralBetweennessDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, ongoingAssemblyLoopSizeDistributionFile should be inited" << endl;
	}
			#endif
			
	if (ongoingAssemblyCentralBetweennessFile->isOpen())
	{
		if (ongoingAssemblyCentralBetweenness)
		{
			for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
			{
				ongoingAssemblyCentralBetweennessFile->addIndexedAccuLineData(getEvoIndex(),i,ongoingAssemblyCentralBetweenness[i]);
			}

			ongoingAssemblyCentralBetweennessFile->addDataSeparator();
		}
		else
		{
			cerr << "Warning, ongoingAssemblyCentralBetweenness should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, ongoingAssemblyCentralBetweennessFile should be inited" << endl;
	}

	// Centralite de noeuds
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingAssemblyBetweennessDistributionFile->isOpen())
	{
		if (ongoingAssemblyBetweennessDistribution)
		{
			ongoingAssemblyBetweennessDistributionFile->addOngoingMeanLogDistribution(getEvoIndex(),ongoingAssemblyBetweennessDistribution);
		}
		else
		{
			cerr << "Warning, ongoingAssemblyBetweennessDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, ongoingAssemblyLoopSizeDistributionFile should be inited" << endl;
	}
			#endif
	
	if (ongoingAssemblyBetweennessFile->isOpen())
	{
		if (ongoingAssemblyBetweenness)
		{
			for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
			{
				ongoingAssemblyBetweennessFile->addIndexedAccuLineData(getEvoIndex(),i,ongoingAssemblyBetweenness[i]);
			}

			ongoingAssemblyBetweennessFile->addDataSeparator();
		}
		else
		{
			cerr << "Warning, ongoingAssemblyBetweenness should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, ongoingAssemblyBetweennessFile should be inited" << endl;
	}

		
			#ifdef _EDGE_BETWEENNESS_STAT_MODE

	// Intermediarite de liens
	if (ongoingAssemblyMaxEdgeBetweennessFile->isOpen())
	{
		if (ongoingAssemblyMaxEdgeBetweenness)
		{
			for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
			{
				ongoingAssemblyMaxEdgeBetweennessFile->addIndexedAccuLineData(getEvoIndex(),i,ongoingAssemblyMaxEdgeBetweenness[i]);
			}

			ongoingAssemblyMaxEdgeBetweennessFile->addDataSeparator();
		}
		else
		{
			cerr << "Warning, ongoingAssemblyMaxEdgeBetweenness should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, ongoingAssemblyMaxEdgeBetweennessFile should be inited" << endl;
	}
				#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingAssemblyEdgeBetweennessDistributionFile->isOpen())
	{
		if (ongoingAssemblyEdgeBetweennessDistribution)
		{
	ongoingAssemblyEdgeBetweennessDistributionFile->addOngoingMeanLogDistribution(getEvoIndex(),ongoingAssemblyEdgeBetweennessDistribution);
		}
		else
		{
			cerr << "Warning, ongoingAssemblyEdgeBetweennessDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, ongoingAssemblyLoopSizeDistributionFile should be inited" << endl;
	}
				#endif
			#endif
	
	#ifdef _TEST_STAT
	cerr << "*** NetworkStater *** beginning assembly betweeness trace" << endl;
	#endif
			
	// Efficacité du réseau au fur et à mesure de la suppression
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingAssemblyGlobalEfficiencyDistributionFile->isOpen())
	{
		if (ongoingAssemblyGlobalEfficiencyDistribution)
		{
	ongoingAssemblyGlobalEfficiencyDistributionFile->addOngoingMeanLogDistribution(getEvoIndex(),ongoingAssemblyGlobalEfficiencyDistribution);
		}
		else
		{
			cerr << "Warning, ongoingAssemblyGlobalEfficiencyDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, ongoingAssemblyLoopSizeDistributionFile should be inited" << endl;
	}
			#endif
			
	if (ongoingAssemblyGlobalEfficiencyFile->isOpen())
	{
		if (ongoingAssemblyGlobalEfficiency)
		{
			for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
			{
				ongoingAssemblyGlobalEfficiencyFile->addIndexedAccuLineData(getEvoIndex(),i,ongoingAssemblyGlobalEfficiency[i]);
			}

			ongoingAssemblyGlobalEfficiencyFile->addDataSeparator();
		}
		else
		{
			cerr << "Warning, ongoingAssemblyGlobalEfficiency should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, ongoingAssemblyGlobalEfficiencyFile should be inited" << endl;
	}
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingAssemblyLocalEfficiencyDistributionFile->isOpen())
	{
		if (ongoingAssemblyLocalEfficiencyDistribution)
		{
			ongoingAssemblyLocalEfficiencyDistributionFile->addOngoingMeanLogDistribution(getEvoIndex(),ongoingAssemblyLocalEfficiencyDistribution);
		}
		else
		{
			cerr << "Warning, ongoingAssemblyLocalEfficiencyDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, ongoingAssemblyLoopSizeDistributionFile should be inited" << endl;
	}
			#endif
			
	if (ongoingAssemblyLocalEfficiencyFile->isOpen())
	{
		if (ongoingAssemblyLocalEfficiency)
		{
			for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
			{
				ongoingAssemblyLocalEfficiencyFile->addIndexedAccuLineData(getEvoIndex(),i,ongoingAssemblyLocalEfficiency[i]);
			}

			ongoingAssemblyLocalEfficiencyFile->addDataSeparator();
		}
		else
		{
			cerr << "Warning, ongoingAssemblyLocalEfficiency should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, ongoingAssemblyLocalEfficiencyFile should be inited" << endl;
	}

	// ShortPath
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingAssemblyShortPathLengthDistributionFile->isOpen())
	{
		if (ongoingAssemblyShortPathLengthDistribution)
		{
		ongoingAssemblyShortPathLengthDistributionFile->addOngoingMeanDistribution(getEvoIndex(),ongoingAssemblyShortPathLengthDistribution);
		}
		else
		{
			cerr << "Warning, ongoingAssemblyShortPathLengthDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, ongoingAssemblyLoopSizeDistributionFile should be inited" << endl;
	}
			#endif
			
	#ifdef _TEST_STAT
	cerr << "*** NetworkStater *** after trace assembly efficiency" << endl;
	#endif
	
		// Clusters
	// Modularite
	if (ongoingClusterModularityFile->isOpen())
	{
		if (ongoingClusterModularity)
		{
			for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
			{
			#ifdef _SINGLE_INDIVIDUAL_MODE
				ongoingClusterModularityFile->addIndexedLineData(getEvoIndex(),i, ongoingClusterModularity[i]);
			#else
				#ifdef _FIRST_BEST_INDIVIDUALS_MODE
				ongoingClusterModularityFile->addIndexedLineData(getEvoIndex(),i, ongoingClusterModularity[i]/((double) NB_FIRST_BEST_INDIVIDUALS));	
				#else
				ongoingClusterModularityFile->addIndexedLineData(getEvoIndex(),i, ongoingClusterModularity[i]/((double) NB_INDIVIDUS));
				#endif
			#endif
			}

			ongoingClusterModularityFile->addDataSeparator();
		}
		else
		{
			cerr << "Warning, ongoingClusterModularity should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, ongoingClusterModularityFile should be inited" << endl;
	}
	
	// Nombre de clusters
	if (ongoingNbClustersFile->isOpen())
	{
		if (ongoingNbClusters)
		{
			for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
			{
				//cout << i << " " << meanLoopSizes[i].getMean() << endl;
				ongoingNbClustersFile->addIndexedAccuLineData(getEvoIndex(),i,ongoingNbClusters[i]);
			}

			ongoingNbClustersFile->addDataSeparator();
		}
		else
		{
			cerr << "Warning, ongoingNbClusters should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, ongoingNbClustersFile should be inited" << endl;
	}
	
	
	if (ongoingMaxClusterSizesFile->isOpen())
	{
		if (ongoingMaxClusterSizes)
		{
			for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
			{
				//cout << i << " " << meanLoopSizes[i].getMean() << endl;
				ongoingMaxClusterSizesFile->addIndexedAccuLineData(getEvoIndex(),i,ongoingMaxClusterSizes[i]);
			}

			ongoingMaxClusterSizesFile->addDataSeparator();
		}
		else
		{
			cerr << "Warning, ongoingMaxClusterSizes should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, ongoingMaxClusterSizesFile should be inited" << endl;
	}

			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingClusterSizeDistributionFile->isOpen())
	{
		if (ongoingClusterSizeDistribution)
		{
			ongoingClusterSizeDistributionFile->addOngoingMeanDistribution(getEvoIndex(),ongoingClusterSizeDistribution);
		}
		else
		{
			cerr << "Warning, ongoingClusterSizeDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, ongoingClusterLoopSizeDistributionFile should be inited" << endl;
	}
			#endif
			
	#ifdef _TEST_STAT
	cerr << "*** NetworkStater *** after trace cluster size" << endl;
	#endif
	
	// Repartition de l'efficacité des clusters
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingClusterEfficiencyDistributionFile->isOpen())
	{
		if (ongoingClusterEfficiencyDistribution)
		{
			ongoingClusterEfficiencyDistributionFile->addOngoingMeanLogDistribution(getEvoIndex(),ongoingClusterEfficiencyDistribution);
		}
		else
		{
			cerr << "Warning, ongoingClusterEfficiencyDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, ongoingClusterLoopSizeDistributionFile should be inited" << endl;
	}
			#endif
			
	if (ongoingClusterEfficiencyFile->isOpen())
	{
		if (ongoingClusterEfficiency)
		{
			for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
			{
				ongoingClusterEfficiencyFile->addIndexedAccuLineData(getEvoIndex(),i,ongoingClusterEfficiency[i]);
			}

			ongoingClusterEfficiencyFile->addDataSeparator();
		}
		else
		{
			cerr << "Warning, ongoingClusterEfficiency should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, ongoingClusterEfficiencyFile should be inited" << endl;
	}

			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingClusterRealEfficiencyDistributionFile->isOpen())
	{
		if (ongoingClusterRealEfficiencyDistribution)
		{
	ongoingClusterRealEfficiencyDistributionFile->addOngoingMeanLogDistribution(getEvoIndex(),ongoingClusterRealEfficiencyDistribution);
		}
		else
		{
			cerr << "Warning, ongoingClusterRealEfficiencyDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, ongoingClusterLoopSizeDistributionFile should be inited" << endl;
	}
			#endif
			
	if (ongoingClusterRealEfficiencyFile->isOpen())
	{
		if (ongoingClusterRealEfficiency)
		{
			for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
			{
				ongoingClusterRealEfficiencyFile->addIndexedAccuLineData(getEvoIndex(),i,ongoingClusterRealEfficiency[i]);
			}

			ongoingClusterRealEfficiencyFile->addDataSeparator();
		}
		else
		{
			cerr << "Warning, ongoingClusterRealEfficiency should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, ongoingClusterRealEfficiencyFile should be inited" << endl;
	}
	
	#ifdef _TEST_STAT
	cerr << "*** NetworkStater *** after trace cluster efficiency" << endl;
	#endif
	
			#ifdef _LINKED_CLUSTER_STAT_MODE
	// Repartition des composants
	if (ongoingInDCFile->isOpen())
	{
		if (ongoingInDC)
		{
			for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
			{
				ongoingInDCFile->addIndexedAccuLineData(getEvoIndex(),i,ongoingInDC[i]);
			}

			ongoingInDCFile->addDataSeparator();
		}
		else
		{
			cerr << "Warning, ongoingInDC should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, ongoingInDCFile should be inited" << endl;
	}

	if (ongoingInGOUTFile->isOpen())
	{
		if (ongoingInGOUT)
		{
			for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
			{
				ongoingInGOUTFile->addIndexedAccuLineData(getEvoIndex(),i,ongoingInGOUT[i]);
			}

			ongoingInGOUTFile->addDataSeparator();
		}
		else
		{
			cerr << "Warning, ongoingInGOUT should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, ongoingInGOUTFile should be inited" << endl;
	}

	if (ongoingInGINFile->isOpen())
	{
		if (ongoingInGIN)
		{
			for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
			{
				ongoingInGINFile->addIndexedAccuLineData(getEvoIndex(),i,ongoingInGIN[i]);
			}

			ongoingInGINFile->addDataSeparator();
		}
		else
		{
			cerr << "Warning, ongoingInGIN should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, ongoingInGINFile should be inited" << endl;
	}

	if (ongoingInGSCCFile->isOpen())
	{
		if (ongoingInGSCC)
		{
			for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
			{
				ongoingInGSCCFile->addIndexedAccuLineData(getEvoIndex(),i,ongoingInGSCC[i]);
			}

			ongoingInGSCCFile->addDataSeparator();
		}
		else
		{
			cerr << "Warning, ongoingInGSCC should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, ongoingInGSCCFile should be inited" << endl;
	}
				#ifdef _CLUSTER_CENTRALITY_STAT_MODE
					
					#ifdef _EDGE_BETWEENNESS_STAT_MODE

	// Intermediarite de liens
	if (ongoingLinkedClusterMaxEdgeBetweennessFile->isOpen())
	{
		if (ongoingLinkedClusterMaxEdgeBetweenness)
		{
			for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
			{
				ongoingLinkedClusterMaxEdgeBetweennessFile->addIndexedAccuLineData(getEvoIndex(),i,ongoingLinkedClusterMaxEdgeBetweenness[i]);
			}

			ongoingLinkedClusterMaxEdgeBetweennessFile->addDataSeparator();
		}
		else
		{
			cerr << "Warning, ongoingLinkedClusterMaxEdgeBetweenness should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, ongoingLinkedClusterMaxEdgeBetweennessFile should be inited" << endl;
	}
						#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingLinkedClusterEdgeBetweennessDistributionFile->isOpen())
	{
		if (ongoingLinkedClusterEdgeBetweennessDistribution)
		{
ongoingLinkedClusterEdgeBetweennessDistributionFile->addOngoingMeanLogDistribution(getEvoIndex(),ongoingLinkedClusterEdgeBetweennessDistribution);
		}
		else
		{
			cerr << "Warning, ongoingLinkedClusterEdgeBetweennessDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, ongoingLinkedClusterLoopSizeDistributionFile should be inited" << endl;
	}
						#endif
					#endif
	// Calcul de centralité
					#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingLinkedClusterBetweennessDistributionFile->isOpen())
	{
		if (ongoingLinkedClusterBetweennessDistribution)
		{
	ongoingLinkedClusterBetweennessDistributionFile->addOngoingMeanLogDistribution(getEvoIndex(),ongoingLinkedClusterBetweennessDistribution);
		}
		else
		{
			cerr << "Warning, ongoingLinkedClusterBetweennessDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, ongoingLinkedClusterLoopSizeDistributionFile should be inited" << endl;
	}
					#endif
					
	if (ongoingLinkedClusterBetweennessFile->isOpen())
	{
		if (ongoingLinkedClusterBetweenness)
		{
			for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
			{
				ongoingLinkedClusterBetweennessFile->addIndexedAccuLineData(getEvoIndex(),i,ongoingLinkedClusterBetweenness[i]);
			}

			ongoingLinkedClusterBetweennessFile->addDataSeparator();
		}
		else
		{
			cerr << "Warning, ongoingLinkedClusterBetweenness should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, ongoingLinkedClusterBetweennessFile should be inited" << endl;
	}

					#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingLinkedClusterCentralBetweennessDistributionFile->isOpen())
	{
		if (ongoingLinkedClusterCentralBetweennessDistribution)
		{			ongoingLinkedClusterCentralBetweennessDistributionFile->addOngoingMeanLogDistribution(getEvoIndex(),ongoingLinkedClusterCentralBetweennessDistribution);
		}
		else
		{
			cerr << "Warning, ongoingLinkedClusterCentralBetweennessDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, ongoingLinkedClusterLoopSizeDistributionFile should be inited" << endl;
	}
					#endif
					
	if (ongoingLinkedClusterCentralBetweennessFile->isOpen())
	{
		if (ongoingLinkedClusterCentralBetweenness)
		{
			for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
			{
				ongoingLinkedClusterCentralBetweennessFile->addIndexedAccuLineData(getEvoIndex(),i,ongoingLinkedClusterCentralBetweenness[i]);
			}

			ongoingLinkedClusterCentralBetweennessFile->addDataSeparator();
		}
		else
		{
			cerr << "Warning, ongoingLinkedClusterCentralBetweenness should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, ongoingLinkedClusterCentralBetweennessFile should be inited" << endl;
	}

	#ifdef _TEST_STAT
	cerr << "*** NetworkStater *** after trace linked cluster betweeneness" << endl;
	#endif
	
	// Efficacité du réseau au fur et à mesure de la suppression
					#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingLinkedClusterGlobalEfficiencyDistributionFile->isOpen())
	{
		if (ongoingLinkedClusterGlobalEfficiencyDistribution)
		{
ongoingLinkedClusterGlobalEfficiencyDistributionFile->addOngoingMeanLogDistribution(getEvoIndex(),ongoingLinkedClusterGlobalEfficiencyDistribution);
		}
		else
		{
			cerr << "Warning, ongoingLinkedClusterGlobalEfficiencyDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, ongoingLinkedClusterLoopSizeDistributionFile should be inited" << endl;
	}
					#endif
					
	if (ongoingLinkedClusterGlobalEfficiencyFile->isOpen())
	{
		if (ongoingLinkedClusterGlobalEfficiency)
		{
			for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
			{
				ongoingLinkedClusterGlobalEfficiencyFile->addIndexedAccuLineData(getEvoIndex(),i,ongoingLinkedClusterGlobalEfficiency[i]);
			}

			ongoingLinkedClusterGlobalEfficiencyFile->addDataSeparator();
		}
		else
		{
			cerr << "Warning, ongoingLinkedClusterGlobalEfficiency should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, ongoingLinkedClusterGlobalEfficiencyFile should be inited" << endl;
	}

					#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingLinkedClusterLocalEfficiencyDistributionFile->isOpen())
	{
		if (ongoingLinkedClusterLocalEfficiencyDistribution)
		{
ongoingLinkedClusterLocalEfficiencyDistributionFile->addOngoingMeanLogDistribution(getEvoIndex(),ongoingLinkedClusterLocalEfficiencyDistribution);
		}
		else
		{
			cerr << "Warning, ongoingLinkedClusterLocalEfficiencyDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, ongoingLinkedClusterLoopSizeDistributionFile should be inited" << endl;
	}
					#endif
					
	if (ongoingLinkedClusterLocalEfficiencyFile->isOpen())
	{
		if (ongoingLinkedClusterLocalEfficiency)
		{
			for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
			{
			ongoingLinkedClusterLocalEfficiencyFile->addIndexedAccuLineData(getEvoIndex(),i,ongoingLinkedClusterLocalEfficiency[i]);
			}

			ongoingLinkedClusterLocalEfficiencyFile->addDataSeparator();
		}
		else
		{
			cerr << "Warning, ongoingLinkedClusterLocalEfficiency should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, ongoingLinkedClusterLocalEfficiencyFile should be inited" << endl;
	}

	// ShortPath
					#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingLinkedClusterShortPathLengthDistributionFile->isOpen())
	{
		if (ongoingLinkedClusterShortPathLengthDistribution)
		{
ongoingLinkedClusterShortPathLengthDistributionFile->addOngoingMeanDistribution(getEvoIndex(),ongoingLinkedClusterShortPathLengthDistribution);
		}
		else
		{
			cerr << "Warning, ongoingLinkedClusterShortPathLengthDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, ongoingLinkedClusterLoopSizeDistributionFile should be inited" << endl;
	}
					#endif
				#endif
			#endif

	#ifdef _TEST_STAT
	cerr << "*** NetworkStater *** after trace linked cluster efficiency" << endl;
	#endif
	
			#ifdef _NETWORK_CLUSTER_STAT_MODE
				#ifdef _LINKED_CLUSTER_STAT_MODE
	// Repartition des clusters dans les composants pour le réseau à la fin du processus de clusterisation
	if (networkComponentRepartitionFile->isOpen())
	{
		if (networkInDC)
		{
			networkComponentRepartitionFile->addIndexedAccuLineData(getEvoIndex(),0,*networkInDC);
		}

		if (networkInGOUT)
		{
			networkComponentRepartitionFile->addIndexedAccuLineData(getEvoIndex(),1,*networkInGOUT);
		}

		if (networkInGIN)
		{
			networkComponentRepartitionFile->addIndexedAccuLineData(getEvoIndex(),2,*networkInGIN);
		}

		if (networkInGSCC)
		{
			networkComponentRepartitionFile->addIndexedAccuLineData(getEvoIndex(),3,*networkInGSCC);
		}

		networkComponentRepartitionFile->addDataSeparator();
	}
				#endif

	
	#ifdef _TEST_STAT
	cerr << "*** NetworkStater *** after trace network component" << endl;
	#endif
	
	// Repartition de la taille des clusters pour le réseau à la fin du processus de clusterisation
	if (networkClusterSizeDistributionFile->isOpen())
	{
		if (networkClusterSizeDistribution)
		{
			networkClusterSizeDistributionFile->addIndexedMeanDistribution(getEvoIndex(),networkClusterSizeDistribution);
		}
		else
		{
			cerr << "Warning, networkClusterSizeDistribution should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, networkClusterSizeDistributionFile should be inited" << endl;
	}

	
	#ifdef _TEST_STAT
	cerr << "*** NetworkStater *** after trace network cluster size" << endl;
	#endif
	
		// Repartition de l'efficacité des clusters pour le réseau à la fin du processus de clusterisation
	if (networkClusterEfficiencyFile->isOpen())
	{
		if (networkClusterEfficiency)
		{
			networkClusterEfficiencyFile->addAccuLineData(getEvoIndex(),*networkClusterEfficiency);
		}
	}
	
	if (networkClusterEfficiencyDistributionFile->isOpen())
	{
		if (networkClusterEfficiencyDistribution)
		{
			networkClusterEfficiencyDistributionFile->addIndexedMeanLogDistribution(getEvoIndex(),networkClusterEfficiencyDistribution);
		}
		else
		{
			cerr << "Warning, networkClusterEfficiencyDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, networkClusterEfficiencyDistributionFile should be inited" << endl;
	}

	if (networkClusterRealEfficiencyFile->isOpen())
	{
		if (networkClusterRealEfficiency)
		{
			networkClusterRealEfficiencyFile->addAccuLineData(getEvoIndex(),*networkClusterRealEfficiency);
		}
	}
	
	if (networkClusterRealEfficiencyDistributionFile->isOpen())
	{
		if (networkClusterRealEfficiencyDistribution)
		{
			networkClusterRealEfficiencyDistributionFile->addIndexedMeanLogDistribution(getEvoIndex(),networkClusterRealEfficiencyDistribution);
		}
		else
		{
			cerr << "Warning, networkClusterRealEfficiencyDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, networkClusterRealEfficiencyDistributionFile should be inited" << endl;
	}

	#ifdef _TEST_STAT
	cerr << "*** NetworkStater *** after trace network efficiency" << endl;
	#endif
				#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
	// Nombre de suppression de liens pour atteindre le réseau optimal
	if (maxModularityProjectionIndexFile->isOpen())
	{
		if (maxModularityProjectionIndexFile)
		{
			maxModularityProjectionIndexFile->addAccuLineData(getEvoIndex(),*maxModularityProjectionIndex);
		}
	}


	// Modularité maximale
	if (maxModularityFile->isOpen())
	{
		if (maxModularityFile)
		{
			maxModularityFile->addAccuLineData(getEvoIndex(),*maxModularity);
		}
	}
					#ifdef _LINKED_CLUSTER_STAT_MODE
	// Repartition des clusters dans les composants pour le réseau optimal
	if (maxModularityComponentRepartitionFile->isOpen())
	{
		if (maxModularityInDC)
		{
			maxModularityComponentRepartitionFile->addIndexedAccuLineData(getEvoIndex(),0,*maxModularityInDC);
		}

		if (maxModularityInGOUT)
		{
			maxModularityComponentRepartitionFile->addIndexedAccuLineData(getEvoIndex(),1,*maxModularityInGOUT);
		}

		if (maxModularityInGIN)
		{
			maxModularityComponentRepartitionFile->addIndexedAccuLineData(getEvoIndex(),2,*maxModularityInGIN);
		}

		if (maxModularityInGSCC)
		{
			maxModularityComponentRepartitionFile->addIndexedAccuLineData(getEvoIndex(),3,*maxModularityInGSCC);
		}

		maxModularityComponentRepartitionFile->addDataSeparator();
	}
					#endif

	// Repartition de la taille des clusters pour le réseau optimal
	if (maxModularityClusterSizeDistributionFile->isOpen())
	{
		if (maxModularityClusterSizeDistribution)
		{
			maxModularityClusterSizeDistributionFile->addIndexedMeanDistribution(getEvoIndex(),maxModularityClusterSizeDistribution);
		}
		else
		{
			cerr << "Warning, maxModularityClusterSizeDistribution should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, maxModularityClusterSizeDistributionFile should be inited" << endl;
	}

	// Repartition de l'efficacité des clusters pour le réseau optimal
	if (maxModularityClusterEfficiencyFile->isOpen())
	{
		if (maxModularityClusterEfficiency)
		{
			maxModularityClusterEfficiencyFile->addAccuLineData(getEvoIndex(),*maxModularityClusterEfficiency);
		}
	}
	
	if (maxModularityClusterEfficiencyDistributionFile->isOpen())
	{
		if (maxModularityClusterEfficiencyDistribution)
		{
			maxModularityClusterEfficiencyDistributionFile->addIndexedMeanLogDistribution(getEvoIndex(),maxModularityClusterEfficiencyDistribution);
		}
		else
		{
			cerr << "Warning, maxModularityClusterEfficiencyDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, maxModularityClusterLoopSizeDistributionFile should be inited" << endl;
	}

	if (maxModularityClusterRealEfficiencyFile->isOpen())
	{
		if (maxModularityClusterRealEfficiency)
		{
			maxModularityClusterRealEfficiencyFile->addAccuLineData(getEvoIndex(),*maxModularityClusterRealEfficiency);
		}
	}
	
	if (maxModularityClusterRealEfficiencyDistributionFile->isOpen())
	{
		if (maxModularityClusterRealEfficiencyDistribution)
		{
			maxModularityClusterRealEfficiencyDistributionFile->addIndexedMeanLogDistribution(getEvoIndex(),maxModularityClusterRealEfficiencyDistribution);
		}
		else
		{
			cerr << "Warning, maxModularityClusterRealEfficiencyDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, maxModularityClusterRealEfficiencyFile should be inited" << endl;
	}
				#endif
			#endif
	
	#ifdef _TEST_STAT
	cerr << "*** NetworkStater *** after trace max modularity" << endl;
	#endif
	
		#else

	// Calcul d'intermediarité
	if (meanAssemblyBetweennessRepartitionFile->isOpen())
	{
		if (meanAssemblyBetweennessRepartition)
		{
			for (int i=0;i<NB_ASSEMBLIES;i++)
			{
				meanAssemblyBetweennessRepartitionFile->addIndexedAccuLineData(getEvoIndex(),i,meanAssemblyBetweennessRepartition[i]);
			}

			meanAssemblyBetweennessRepartitionFile->addDataSeparator();
		}
		else
		{
			cerr << "Warning, meanAssemblyBetweennessRepartition should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, meanAssemblyBetweennessRepartitionFile should be inited" << endl;
	}

	if (meanAssemblyBetweennessFile->isOpen())
	{
		meanAssemblyBetweennessFile->addAccuLineData(getEvoIndex(),*meanAssemblyBetweenness);
	}


	if (meanAssemblyBetweennessDistributionFile->isOpen())
	{
		if (meanAssemblyBetweennessDistribution)
		{
			meanAssemblyBetweennessDistributionFile->addIndexedMeanLogDistribution(getEvoIndex(),meanAssemblyBetweennessDistribution);
		}
		else
		{
			cerr << "Warning, meanAssemblyBetweennessDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, meanAssemblyLoopSizeDistributionFile should be inited" << endl;
	}

	// Centralite
	if (meanAssemblyCentralBetweennessRepartitionFile->isOpen())
	{
		if (meanAssemblyCentralBetweennessRepartition)
		{
			for (int i=0;i<NB_ASSEMBLIES;i++)
			{
				meanAssemblyCentralBetweennessRepartitionFile->addIndexedAccuLineData(getEvoIndex(),i,meanAssemblyCentralBetweennessRepartition[i]);
			}

			meanAssemblyCentralBetweennessRepartitionFile->addDataSeparator();
		}
		else
		{
			cerr << "Warning, meanAssemblyCentralBetweennessRepartition should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, meanAssemblyCentralBetweennessRepartitionFile should be inited" << endl;
	}

	if (meanAssemblyCentralBetweennessFile->isOpen())
	{
		meanAssemblyCentralBetweennessFile->addAccuLineData(getEvoIndex(),*meanAssemblyCentralBetweenness);
	}

	
	if (meanAssemblyCentralBetweennessDistributionFile->isOpen())
	{
		if (meanAssemblyCentralBetweennessDistribution)
		{
			meanAssemblyCentralBetweennessDistributionFile->addIndexedMeanLogDistribution(getEvoIndex(),meanAssemblyCentralBetweennessDistribution);
		}
		else
		{
			cerr << "Warning, meanAssemblyCentralBetweennessDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, meanAssemblyLoopSizeDistributionFile should be inited" << endl;
	}
			#ifdef _EDGE_BETWEENNESS_STAT_MODE
	// Calcul d'intermediarité pour les liens
	if (meanEdgeBetweennessRepartitionFile->isOpen())
	{
		if (meanEdgeBetweennessRepartition)
		{
			for (int i=0;i<NB_ASSEMBLIES;i++)
			{
				for (int j=0;j<NB_ASSEMBLIES;j++)
				{
					meanEdgeBetweennessRepartitionFile->addIndexedAccuLineData(i,j,(Accumulater&) meanEdgeBetweennessRepartition[i][j]);
				}
			}
				
			meanEdgeBetweennessRepartitionFile->addDataSeparator();
		}
		else
		{
			cerr << "Warning, meanEdgeBetweennessRepartition should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, meanEdgeBetweennessRepartitionFile should be inited" << endl;
	}

	if (meanEdgeBetweennessDistributionFile->isOpen())
	{
		if (meanEdgeBetweennessDistribution)
		{
			meanEdgeBetweennessDistributionFile->addIndexedMeanLogDistribution(getEvoIndex(),meanEdgeBetweennessDistribution);
		}
		else
		{
			cerr << "Warning, meanEdgeBetweennessDistribution should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, meanEdgeBetweennessDistributionFile should be inited" << endl;
	}

			#endif
			
	// ShortPath
	if (meanAssemblyShortPathRepartitionFile->isOpen())
	{
		if (meanAssemblyShortPathRepartition)
		{
			for (int i=0;i<NB_ASSEMBLIES;i++)
			{
				meanAssemblyShortPathRepartitionFile->addIndexedAccuLineData(getEvoIndex(),i,meanAssemblyShortPathRepartition[i]);
			}
		
			meanAssemblyShortPathRepartitionFile->addDataSeparator();
		}
		else
		{
			cerr << "Warning, meanAssemblyShortPathRepartition should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, meanAssemblyShortPathRepartitionFile should be inited" << endl;
	}

	if (meanAssemblyNoShortPathRepartitionFile->isOpen())
	{
		if (meanAssemblyNoShortPathRepartition)
		{
			for (int i=0;i<NB_ASSEMBLIES;i++)
			{
				meanAssemblyNoShortPathRepartitionFile->addIndexedAccuLineData(getEvoIndex(),i,meanAssemblyNoShortPathRepartition[i]);
			}
		
			meanAssemblyNoShortPathRepartitionFile->addDataSeparator();
		}
		else
		{
			cerr << "Warning, meanAssemblyNoShortPathRepartition should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, meanAssemblyNoShortPathRepartitionFile should be inited" << endl;
	}

	if (meanAssemblyNbShortPathDistributionFile->isOpen())
	{
		if (meanAssemblyNbShortPathDistribution)
		{
			meanAssemblyNbShortPathDistributionFile->addIndexedMeanDistribution(getEvoIndex(),meanAssemblyNbShortPathDistribution);
		}
		else
		{
			cerr << "Warning, meanAssemblyNbShortPathDistribution should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, meanAssemblyNbShortPathDistributionFile should be inited" << endl;
	}
	
	// Efficacite
	if (meanAssemblyGlobalEfficiencyRepartitionFile->isOpen())
	{
		if (meanAssemblyGlobalEfficiencyRepartition)
		{
			for (int i=0;i<NB_ASSEMBLIES;i++)
			{
				meanAssemblyGlobalEfficiencyRepartitionFile->addIndexedAccuLineData(getEvoIndex(),i,meanAssemblyGlobalEfficiencyRepartition[i]);
			}

			meanAssemblyGlobalEfficiencyRepartitionFile->addDataSeparator();
		}
		else
		{
			cerr << "Warning, meanAssemblyGlobalEfficiencyRepartition should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, meanAssemblyGlobalEfficiencyRepartitionFile should be inited" << endl;
	}

	if (meanAssemblyLocalEfficiencyRepartitionFile->isOpen())
	{
		if (meanAssemblyLocalEfficiencyRepartition)
		{
			for (int i=0;i<NB_ASSEMBLIES;i++)
			{
				meanAssemblyLocalEfficiencyRepartitionFile->addIndexedAccuLineData(getEvoIndex(),i,meanAssemblyLocalEfficiencyRepartition[i]);
			}

			meanAssemblyLocalEfficiencyRepartitionFile->addDataSeparator();
		}
		else
		{
			cerr << "Warning, meanAssemblyLocalEfficiencyRepartition should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, meanAssemblyLocalEfficiencyRepartitionFile should be inited" << endl;
	}

	if (meanAssemblyGlobalEfficiencyDistributionFile->isOpen())
	{
		if (meanAssemblyGlobalEfficiencyDistribution)
		{
			meanAssemblyGlobalEfficiencyDistributionFile->addIndexedMeanLogDistribution(getEvoIndex(),meanAssemblyGlobalEfficiencyDistribution);
		}
		else
		{
			cerr << "Warning, meanAssemblyGlobalEfficiencyDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, meanAssemblyLoopSizeDistributionFile should be inited" << endl;
	}

	if (meanAssemblyLocalEfficiencyDistributionFile->isOpen())
	{
		if (meanAssemblyLocalEfficiencyDistribution)
		{
			meanAssemblyLocalEfficiencyDistributionFile->addIndexedMeanLogDistribution(getEvoIndex(),meanAssemblyLocalEfficiencyDistribution);
		}
		else
		{
			cerr << "Warning, meanAssemblyLocalEfficiencyDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, meanAssemblyLoopSizeDistributionFile should be inited" << endl;
	}

	if (meanAssemblyGlobalEfficiencyFile->isOpen())
	{
		meanAssemblyGlobalEfficiencyFile->addAccuLineData(getEvoIndex(),*meanAssemblyGlobalEfficiency);
	}

	if (meanAssemblyLocalEfficiencyFile->isOpen())
	{
		meanAssemblyLocalEfficiencyFile->addAccuLineData(getEvoIndex(),*meanAssemblyLocalEfficiency);
	}
		#endif
	#endif

	cerr << "trace loop" << endl;
		
	// Loops
	#ifdef _LOOP_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
		// Assembly
	// NbLoops
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingAssemblyNbLoopsDistributionFile->isOpen())
	{
		if (ongoingAssemblyNbLoopsDistribution)
		{
			ongoingAssemblyNbLoopsDistributionFile->addOngoingMeanLogDistribution(getEvoIndex(),ongoingAssemblyNbLoopsDistribution);
		}
		else
		{
			cerr << "Warning, ongoingAssemblyNbLoopsDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, ongoingAssemblyLoopSizeDistributionFile should be inited" << endl;
	}
			#endif
		
	if (ongoingAssemblyNbLoopsFile->isOpen())
	{
		if (ongoingAssemblyNbLoops)
		{
			for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
			{
				ongoingAssemblyNbLoopsFile->addIndexedAccuLineData(getEvoIndex(),i,ongoingAssemblyNbLoops[i]);
			}

			ongoingAssemblyNbLoopsFile->addDataSeparator();
		}
		else
		{
			cerr << "Warning, ongoingAssemblyNbLoops should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, ongoingAssemblyNbLoops should be inited" << endl;
	}

	// Degree
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingAssemblyNbLoopsDegreeDistributionFile->isOpen())
	{
		if (ongoingAssemblyNbLoopsDegreeDistribution)
		{
			ongoingAssemblyNbLoopsDegreeDistributionFile->addOngoingMeanDistribution(getEvoIndex(),ongoingAssemblyNbLoopsDegreeDistribution);
		}
		else
		{
			cerr << "Warning, ongoingAssemblyNbLoopsDegreeDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, ongoingAssemblyLoopSizeDistributionFile should be inited" << endl;
	}
	
	// LoopSize
	if (ongoingAssemblyLoopSizeDistributionFile->isOpen())
	{
		if (ongoingAssemblyLoopSizeDistribution)
		{
			ongoingAssemblyLoopSizeDistributionFile->addOngoingMeanDistribution(getEvoIndex(),ongoingAssemblyLoopSizeDistribution);
		}
		else
		{
			cerr << "Warning, ongoingAssemblyLoopSizeDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, ongoingAssemblyLoopSizeDistributionFile should be inited" << endl;
	}
			#endif
			
		// Cluster
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingClusterLoopSizeDistributionFile->isOpen())
	{
		if (ongoingClusterLoopSizeDistribution)
		{
			ongoingClusterLoopSizeDistributionFile->addOngoingMeanDistribution(getEvoIndex(),ongoingClusterLoopSizeDistribution);
		}
		else
		{
			cerr << "Warning, ongoingClusterLoopSizeDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, ongoingClusterLoopSizeDistributionFile should be inited" << endl;
	}
			#endif
			
	if (ongoingClusterNbLoopsFile->isOpen())
	{
		if (ongoingClusterNbLoops)
		{
			for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
			{
				ongoingClusterNbLoopsFile->addIndexedAccuLineData(getEvoIndex(),i,ongoingClusterNbLoops[i]);
			}

			ongoingClusterNbLoopsFile->addDataSeparator();
		}
		else
		{
			cerr << "Warning, ongoingClusterNbLoops should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, ongoingClusterNbLoops should be inited" << endl;
	}
			#ifdef _NETWORK_CLUSTER_STAT_MODE
	if (networkClusterLoopSizeDistributionFile->isOpen())
	{
		if (networkClusterLoopSizeDistribution)
		{
			((DistributionDataFile*) networkClusterLoopSizeDistributionFile)->addIndexedMeanDistribution(getEvoIndex(),networkClusterLoopSizeDistribution);
		}
		else
		{
			cerr << "Warning, networkClusterLoopSizeDistribution should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, networkClusterLoopSizeDistributionFile should be inited" << endl;
	}

				#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
	if (maxModularityClusterLoopSizeDistributionFile->isOpen())
	{
		if (maxModularityClusterLoopSizeDistribution)
		{
			((DistributionDataFile*) maxModularityClusterLoopSizeDistributionFile)->addIndexedMeanDistribution(getEvoIndex(),maxModularityClusterLoopSizeDistribution);
		}
		else
		{
			cerr << "Warning, maxModularityClusterLoopSizeDistribution should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, maxModularityClusterLoopSizeDistributionFile should be inited" << endl;
	}
				#endif
				
			#endif
		#else
	if (meanAssemblyLoopSizeDistributionFile->isOpen())
	{
		if (meanAssemblyLoopSizeDistribution)
		{
			((DistributionDataFile*) meanAssemblyLoopSizeDistributionFile)->addIndexedMeanDistribution(getEvoIndex(),meanAssemblyLoopSizeDistribution);
		}
		else
		{
			cerr << "Warning, meanAssemblyLoopSizeDistribution should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, meanAssemblyLoopSizeDistributionFile should be inited" << endl;
	}

	// Nb Loops
	if (meanAssemblyNbLoopsRepartitionFile->isOpen())
	{
		if (meanAssemblyNbLoopsRepartition)
		{
			for (int i=0;i<NB_ASSEMBLIES;i++)
			{
				//cout << i << " " << meanNbLoops[i].getMean() << endl;
				meanAssemblyNbLoopsRepartitionFile->addIndexedAccuLineData(getEvoIndex(),i,meanAssemblyNbLoopsRepartition[i]);
			}

			meanAssemblyNbLoopsRepartitionFile->addDataSeparator();
		}
		else
		{
			cerr << "Warning, meanAssemblyNbLoopsRepartition should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, meanAssemblyNbLoopsRepartitionFile should be inited" << endl;
	}
	
	if (meanAssemblyNbLoopsDistributionFile->isOpen())
	{
		if (meanAssemblyNbLoopsDistribution)
		{
			((DistributionDataFile*) meanAssemblyNbLoopsDistributionFile)->addIndexedMeanLogDistribution(getEvoIndex(),meanAssemblyNbLoopsDistribution);
		}
		else
		{
			cerr << "Warning, meanAssemblyNbLoopsDistribution should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, meanAssemblyNbLoopsDistributionFile should be inited" << endl;
	}
	
	// Degree
	if (meanAssemblyNbLoopsDegreeDistributionFile->isOpen())
	{
		if (meanAssemblyNbLoopsDegreeDistribution)
		{
			meanAssemblyNbLoopsDegreeDistributionFile->addIndexedMeanDistribution(getEvoIndex(),meanAssemblyNbLoopsDegreeDistribution);
		}
		else
		{
			cerr << "Warning, meanAssemblyNbLoopsDegreeDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, meanAssemblyLoopSizeDistributionFile should be inited" << endl;
	}
		#endif
	#endif
	
	cerr << "trace small world" << endl;
	
	#ifdef _SMALL_WORLD_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
			#ifdef _3D_ONGOING_STAT_MODE
	// Degree
	if (ongoingAssemblyClusteringCoeffDegreeDistributionFile->isOpen())
	{
		if (ongoingAssemblyClusteringCoeffDegreeDistribution)
		{
			ongoingAssemblyClusteringCoeffDegreeDistributionFile->addOngoingMeanDistribution(getEvoIndex(),ongoingAssemblyClusteringCoeffDegreeDistribution);
		}
		else
		{
			cerr << "Warning, ongoingAssemblyClusteringCoeffDegreeDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, ongoingAssemblyClusteringCoeffLoopSizeDistributionFile should be inited" << endl;
	}
	
	if (ongoingAssemblyClusteringCoeffDistributionFile->isOpen())
	{
		if (ongoingAssemblyClusteringCoeffDistribution)
		{
			ongoingAssemblyClusteringCoeffDistributionFile->addOngoingMeanLogDistribution(getEvoIndex(),ongoingAssemblyClusteringCoeffDistribution);
		}
		else
		{
			cerr << "Warning, ongoingAssemblyClusteringCoeffDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, ongoingAssemblyClusteringCoeffLoopSizeDistributionFile should be inited" << endl;
	}
			#endif
			
	// Cluster
	if (ongoingClusterInternalDensityFile->isOpen())
	{
		if (ongoingClusterInternalDensity)
		{
			for (int i=0; i < NB_PROJECTIONS_EACH_CHROMOSOME; i++)
			{
				ongoingClusterInternalDensityFile->addIndexedAccuLineData(getEvoIndex(),i,ongoingClusterInternalDensity[i]);
			}

			ongoingClusterInternalDensityFile->addDataSeparator();
		}
	}

	if (ongoingRealClusterInternalDensityFile->isOpen())
	{
		if (ongoingRealClusterInternalDensity)
		{
			for (int i=0; i < NB_PROJECTIONS_EACH_CHROMOSOME; i++)
			{
				ongoingRealClusterInternalDensityFile->addIndexedAccuLineData(getEvoIndex(),i,ongoingRealClusterInternalDensity[i]);
			}

			ongoingRealClusterInternalDensityFile->addDataSeparator();
		}
	}
	
			#ifdef _CLUSTER_CENTRALITY_STAT_MODE
				#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingLinkedClusterClusteringCoeffDegreeDistributionFile->isOpen())
	{
		if (ongoingLinkedClusterClusteringCoeffDegreeDistribution)
		{
			ongoingLinkedClusterClusteringCoeffDegreeDistributionFile->addOngoingMeanDistribution(getEvoIndex(),ongoingLinkedClusterClusteringCoeffDegreeDistribution);
		}
		else
		{
			cerr << "Warning, ongoingLinkedClusterClusteringCoeffDegreeDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, ongoingLinkedClusterClusteringCoeffLoopSizeDistributionFile should be inited" << endl;
	}
	
	if (ongoingLinkedClusterClusteringCoeffDistributionFile->isOpen())
	{
		if (ongoingLinkedClusterClusteringCoeffDistribution)
		{
			ongoingLinkedClusterClusteringCoeffDistributionFile->addOngoingMeanLogDistribution(getEvoIndex(),ongoingLinkedClusterClusteringCoeffDistribution);
		}
		else
		{
			cerr << "Warning, ongoingLinkedClusterClusteringCoeffDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, ongoingLinkedClusterClusteringCoeffLoopSizeDistributionFile should be inited" << endl;
	}
				#endif
			#endif
			
			#ifdef _NETWORK_CLUSTER_STAT_MODE
	if (networkClusterInternalDensityFile->isOpen())
	{
		networkClusterInternalDensityFile->addAccuLineData(getEvoIndex(),*networkClusterInternalDensity);
	}
	
	if (networkRealClusterInternalDensityFile->isOpen())
	{
		networkRealClusterInternalDensityFile->addAccuLineData(getEvoIndex(),*networkRealClusterInternalDensity);
	}
				#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	if (networkLinkedClusterClusteringCoeffDegreeDistributionFile->isOpen())
	{
		if (networkLinkedClusterClusteringCoeffDegreeDistribution)
		{
			networkLinkedClusterClusteringCoeffDegreeDistributionFile->addIndexedMeanDistribution(getEvoIndex(),networkLinkedClusterClusteringCoeffDegreeDistribution);
		}
		else
		{
			cerr << "Warning, networkLinkedClusterClusteringCoeffDegreeDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, networkLinkedClusterClusteringCoeffLoopSizeDistributionFile should be inited" << endl;
	}
	
	if (networkLinkedClusterClusteringCoeffDistributionFile->isOpen())
	{
		if (networkLinkedClusterClusteringCoeffDistribution)
		{
			networkLinkedClusterClusteringCoeffDistributionFile->addIndexedMeanLogDistribution(getEvoIndex(),networkLinkedClusterClusteringCoeffDistribution);
		}
		else
		{
			cerr << "Warning, networkLinkedClusterClusteringCoeffDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, networkLinkedClusterClusteringCoeffLoopSizeDistributionFile should be inited" << endl;
	}
				#endif
				
				#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
	if (maxModularityClusterInternalDensityFile->isOpen())
	{
		maxModularityClusterInternalDensityFile->addAccuLineData(getEvoIndex(),*maxModularityClusterInternalDensity);
	}
	
	if (maxModularityRealClusterInternalDensityFile->isOpen())
	{
		maxModularityRealClusterInternalDensityFile->addAccuLineData(getEvoIndex(),*maxModularityRealClusterInternalDensity);
	}	
					#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	if (maxModularityLinkedClusterClusteringCoeffDegreeDistributionFile->isOpen())
	{
		if (maxModularityLinkedClusterClusteringCoeffDegreeDistribution)
		{
			maxModularityLinkedClusterClusteringCoeffDegreeDistributionFile->addIndexedMeanDistribution(getEvoIndex(),maxModularityLinkedClusterClusteringCoeffDegreeDistribution);
		}
		else
		{
			cerr << "Warning, maxModularityLinkedClusterClusteringCoeffDegreeDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, maxModularityLinkedClusterClusteringCoeffLoopSizeDistributionFile should be inited" << endl;
	}
	
	if (maxModularityLinkedClusterClusteringCoeffDistributionFile->isOpen())
	{
		if (maxModularityLinkedClusterClusteringCoeffDistribution)
		{
			maxModularityLinkedClusterClusteringCoeffDistributionFile->addIndexedMeanLogDistribution(getEvoIndex(),maxModularityLinkedClusterClusteringCoeffDistribution);
		}
		else
		{
			cerr << "Warning, maxModularityLinkedClusterClusteringCoeffDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, maxModularityLinkedClusterClusteringCoeffLoopSizeDistributionFile should be inited" << endl;
	}
					#endif
				#endif
			#endif
		#else
	// Distribution
	if (meanClusteringCoeffDistributionFile->isOpen())
	{
		if (meanClusteringCoeffDistribution)
		{
			meanClusteringCoeffDistributionFile->addIndexedMeanLogDistribution(getEvoIndex(),meanClusteringCoeffDistribution);
		}
		else
		{
			cerr << "Warning, meanClusteringCoeffDistributionFile should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, meanClusteringCoeffDistributionFile should be inited" << endl;
	}
	
	// Degree
	if (meanClusteringCoeffDegreeDistributionFile->isOpen())
	{
		if (meanClusteringCoeffDegreeDistribution)
		{
			meanClusteringCoeffDegreeDistributionFile->addIndexedMeanDistribution(getEvoIndex(),meanClusteringCoeffDegreeDistribution);
		}
		else
		{
			cerr << "Warning, meanClusteringCoeffDegreeDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, meanClusteringCoeffLoopSizeDistributionFile should be inited" << endl;
	}
	
	// Repartition
	if (meanClusteringCoeffRepartitionFile->isOpen())
	{
		if (meanClusteringCoeffRepartition)
		{
			for (int i=0; i < NB_ASSEMBLIES; i++)
			{
				meanClusteringCoeffRepartitionFile->addIndexedAccuLineData(getEvoIndex(),i,meanClusteringCoeffRepartition[i]);
			}
			
			meanClusteringCoeffRepartitionFile->addDataSeparator();
		}
	}
	
	// Network
	if (meanClusteringCoeffFile->isOpen())
	{
		meanClusteringCoeffFile->addAccuLineData(getEvoIndex(),*meanClusteringCoeff);
	}
	
		#endif
	#endif

	#ifdef _MOTIF_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingAssemblyBinodeMotifsFile->isOpen())
	{
		for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
		{
			ongoingAssemblyBinodeMotifsFile->addIndexedAccuLineData(getEvoIndex(),i,ongoingAssemblyBinodeMotifs[i]);
		}
		ongoingAssemblyBinodeMotifsFile->addDataSeparator();
	}
	else
	{
		cerr << "Warning, ongoingAssemblyBinodeMotifsFile should be inited" << endl;
	}
	
	if (ongoingAssemblyTrinodeMotifsDistributionFile->isOpen())
	{
		if (ongoingAssemblyTrinodeMotifsDistribution)
		{
			ongoingAssemblyTrinodeMotifsDistributionFile->addOngoingMeanDistribution(getEvoIndex(), ongoingAssemblyTrinodeMotifsDistribution);
		}
		else
		{
			cerr << "Warning, ongoingAssemblyTrinodeMotifsDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, ongoingAssemblyLoopSizeDistributionFile should be inited" << endl;
	}
			#endif
			
			#ifdef _CLUSTER_CENTRALITY_STAT_MODE
				#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingLinkedClusterTrinodeMotifsDistributionFile->isOpen())
	{
		if (ongoingLinkedClusterTrinodeMotifsDistribution)
		{
			ongoingLinkedClusterTrinodeMotifsDistributionFile->addOngoingMeanDistribution(getEvoIndex(), ongoingLinkedClusterTrinodeMotifsDistribution);
		}
		else
		{
			cerr << "Warning, ongoingLinkedClusterTrinodeMotifsDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, ongoingLinkedClusterLoopSizeDistributionFile should be inited" << endl;
	}
				#endif
			#endif
			
			#ifdef _INTERNAL_MOTIF_STAT_MODE
				#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingClusterInternalBinodeMotifsFile->isOpen())
	{
		for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
		{
			ongoingClusterInternalBinodeMotifsFile->addIndexedAccuLineData(getEvoIndex(),i,ongoingClusterInternalBinodeMotifs[i]);
		}
		ongoingClusterInternalBinodeMotifsFile->addDataSeparator();
	}
	else
	{
		cerr << "Warning, ongoingClusterInternalBinodeMotifsFile should be inited" << endl;
	}
	
	if (ongoingClusterInternalTrinodeMotifsDistributionFile->isOpen())
	{
		if (ongoingClusterInternalTrinodeMotifsDistribution)
		{
			ongoingClusterInternalTrinodeMotifsDistributionFile->addOngoingMeanDistribution(getEvoIndex(), ongoingClusterInternalTrinodeMotifsDistribution);
		}
		else
		{
			cerr << "Warning, ongoingClusterInternalTrinodeMotifsDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, ongoingClusterInternalLoopSizeDistributionFile should be inited" << endl;
	}
				#endif
				
				#ifdef _NETWORK_CLUSTER_STAT_MODE
	if (networkClusterInternalBinodeMotifsFile->isOpen())
	{
		if (networkClusterInternalBinodeMotifs)
		{
			networkClusterInternalBinodeMotifsFile->addAccuLineData(getEvoIndex(),*networkClusterInternalBinodeMotifs);
		}
		else
		{
			cerr << "Warning, networkClusterInternalBinodeMotifs should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, networkClusterInternalBinodeMotifsFile should be inited" << endl;
	}
	
	if (networkClusterInternalTrinodeMotifsDistributionFile->isOpen())
	{
		if (networkClusterInternalTrinodeMotifsDistribution)
		{
			((DistributionDataFile*) networkClusterInternalTrinodeMotifsDistributionFile)->addIndexedMeanDistribution(getEvoIndex(),networkClusterInternalTrinodeMotifsDistribution);
		}
		else
		{
			cerr << "Warning, networkClusterInternalTrinodeMotifsDistribution should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, networkClusterInternalTrinodeMotifsDistributionFile should be inited" << endl;
	}
					#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	if (networkLinkedClusterTrinodeMotifsDistributionFile->isOpen())
	{
		if (networkLinkedClusterTrinodeMotifsDistribution)
		{
			((DistributionDataFile*) networkLinkedClusterTrinodeMotifsDistributionFile)->addIndexedMeanDistribution(getEvoIndex(),networkLinkedClusterTrinodeMotifsDistribution);
		}
		else
		{
			cerr << "Warning, networkLinkedClusterTrinodeMotifsDistribution should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, networkLinkedClusterTrinodeMotifsDistributionFile should be inited" << endl;
	}
					#endif
					
					#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
	if (maxModularityClusterInternalBinodeMotifsFile->isOpen())
	{
		if (maxModularityClusterInternalBinodeMotifs)
		{
			maxModularityClusterInternalBinodeMotifsFile->addAccuLineData(getEvoIndex(),*maxModularityClusterInternalBinodeMotifs);
		}
		else
		{
			cerr << "Warning, maxModularityClusterInternalBinodeMotifs should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, maxModularityClusterInternalBinodeMotifsFile should be inited" << endl;
	}
	
	if (maxModularityClusterInternalTrinodeMotifsDistributionFile->isOpen())
	{
		if (maxModularityClusterInternalTrinodeMotifsDistribution)
		{
			((DistributionDataFile*) maxModularityClusterInternalTrinodeMotifsDistributionFile)->addIndexedMeanDistribution(getEvoIndex(),maxModularityClusterInternalTrinodeMotifsDistribution);
		}
		else
		{
			cerr << "Warning, maxModularityClusterInternalTrinodeMotifsDistribution should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, maxModularityClusterInternalTrinodeMotifsDistributionFile should be inited" << endl;
	}
						#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	if (maxModularityLinkedClusterTrinodeMotifsDistributionFile->isOpen())
	{
		if (maxModularityLinkedClusterTrinodeMotifsDistribution)
		{
			((DistributionDataFile*) maxModularityLinkedClusterTrinodeMotifsDistributionFile)->addIndexedMeanDistribution(getEvoIndex(),maxModularityLinkedClusterTrinodeMotifsDistribution);
		}
		else
		{
			cerr << "Warning, maxModularityLinkedClusterTrinodeMotifsDistribution should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, maxModularityLinkedClusterTrinodeMotifsDistributionFile should be inited" << endl;
	}
						#endif
					#endif
				#endif
			#endif
		#else
	if (meanBinodeMotifsFile->isOpen())
	{
		meanBinodeMotifsFile->addAccuLineData(getEvoIndex(),*meanBinodeMotifs);
	}

	if (meanTrinodeMotifsDistributionFile->isOpen())
	{
		if (meanTrinodeMotifsDistribution)
		{
			meanTrinodeMotifsDistributionFile->addIndexedMeanDistribution(getEvoIndex(),(MeanDistribution*) meanTrinodeMotifsDistribution);
		}
	}
		#endif
	#endif
	
	#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingAssemblyReachedByInputDistributionFile->isOpen())
	{
		if (ongoingAssemblyReachedByInputDistribution)
		{
			ongoingAssemblyReachedByInputDistributionFile->addOngoingMeanDistribution(getEvoIndex(), ongoingAssemblyReachedByInputDistribution);
		}
		else
		{
			cerr << "Warning, ongoingAssemblyReachedByInputDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, ongoingAssemblyLoopSizeDistributionFile should be inited" << endl;
	}
	
	if (ongoingAssemblyReachedByOutputDistributionFile->isOpen())
	{
		if (ongoingAssemblyReachedByOutputDistribution)
		{
			ongoingAssemblyReachedByOutputDistributionFile->addOngoingMeanDistribution(getEvoIndex(), ongoingAssemblyReachedByOutputDistribution);
		}
		else
		{
			cerr << "Warning, ongoingAssemblyReachedByOutputDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, ongoingAssemblyLoopSizeDistributionFile should be inited" << endl;
	}
	
	if (ongoingAssemblyInputOutputPathLengthDistributionFile->isOpen())
	{
		if (ongoingAssemblyInputOutputPathLengthDistribution)
		{
			ongoingAssemblyInputOutputPathLengthDistributionFile->addOngoingMeanDistribution(getEvoIndex(), ongoingAssemblyInputOutputPathLengthDistribution);
		}
		else
		{
			cerr << "Warning, ongoingAssemblyInputOutputPathLengthDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, ongoingAssemblyLoopSizeDistributionFile should be inited" << endl;
	}
	
	if (ongoingAssemblyPathToInputDistributionFile->isOpen())
	{
		if (ongoingAssemblyPathToInputDistribution)
		{
			ongoingAssemblyPathToInputDistributionFile->addOngoingMeanDistribution(getEvoIndex(), ongoingAssemblyPathToInputDistribution);
		}
		else
		{
			cerr << "Warning, ongoingAssemblyPathToInputDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, ongoingAssemblyLoopSizeDistributionFile should be inited" << endl;
	}
	
	if (ongoingAssemblyPathToOutputDistributionFile->isOpen())
	{
		if (ongoingAssemblyPathToOutputDistribution)
		{
			ongoingAssemblyPathToOutputDistributionFile->addOngoingMeanDistribution(getEvoIndex(), ongoingAssemblyPathToOutputDistribution);
		}
		else
		{
			cerr << "Warning, ongoingAssemblyPathToOutputDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, ongoingAssemblyLoopSizeDistributionFile should be inited" << endl;
	}
			#endif
		#else
	if (meanReachedByInputDistributionFile->isOpen())
	{
		if (meanReachedByInputDistribution)
		{
			meanReachedByInputDistributionFile->addIndexedMeanDistribution(getEvoIndex(),meanReachedByInputDistribution);
		}
		else
		{
			cerr << "Warning, meanReachedByInput should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, meanReachedByInputFile should be inited" << endl;
	}

	if (meanReachedByOutputDistributionFile->isOpen())
	{
		if (meanReachedByOutputDistribution)
		{
			meanReachedByOutputDistributionFile->addIndexedMeanDistribution(getEvoIndex(),meanReachedByOutputDistribution);
		}
		else
		{
			cerr << "Warning, meanReachedByOutput should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, meanReachedByOutputFile should be inited" << endl;
	}

	if (meanPathToInputDistributionFile->isOpen())
	{
		if (meanPathToInputDistribution)
		{
			meanPathToInputDistributionFile->addIndexedMeanDistribution(getEvoIndex(),meanPathToInputDistribution);
		}
		else
		{
			cerr << "Warning, meanPathToInputDistribution should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, meanPathToInputDistributionFile should be inited" << endl;
	}

	if (meanPathToOutputDistributionFile->isOpen())
	{
		if (meanPathToOutputDistribution)
		{
			meanPathToOutputDistributionFile->addIndexedMeanDistribution(getEvoIndex(),meanPathToOutputDistribution);
		}
		else
		{
			cerr << "Warning, meanPathToOutputDistribution should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, meanPathToOutputDistributionFile should be inited" << endl;
	}
	
	if (meanInputOutputPathLengthDistributionFile->isOpen())
	{
		if (meanInputOutputPathLengthDistribution)
		{
			meanInputOutputPathLengthDistributionFile->addIndexedMeanDistribution(getEvoIndex(),meanInputOutputPathLengthDistribution);
		}
		else
		{
			cerr << "Warning, meanInputOutputPathLengthDistribution should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, meanInputOutputPathLengthDistributionFile should be inited" << endl;
	}
		#endif
	#endif

	#ifdef _DEGREE_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingAssemblyDegreeDistributionFile->isOpen())
	{
		if (ongoingAssemblyDegreeDistribution)
		{
			ongoingAssemblyDegreeDistributionFile->addOngoingMeanDistribution(getEvoIndex(),ongoingAssemblyDegreeDistribution);
		}
		else
		{
			cerr << "Warning, ongoingAssemblyDegreeDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, ongoingAssemblyLoopSizeDistributionFile should be inited" << endl;
	}
	
	if (ongoingAssemblyPreDegreeDistributionFile->isOpen())
	{
		if (ongoingAssemblyPreDegreeDistribution)
		{
			ongoingAssemblyPreDegreeDistributionFile->addOngoingMeanDistribution(getEvoIndex(),ongoingAssemblyPreDegreeDistribution);
		}
		else
		{
			cerr << "Warning, ongoingAssemblyPreDegreeDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, ongoingAssemblyLoopSizeDistributionFile should be inited" << endl;
	}
	
	if (ongoingAssemblyPostDegreeDistributionFile->isOpen())
	{
		if (ongoingAssemblyPostDegreeDistribution)
		{
			ongoingAssemblyPostDegreeDistributionFile->addOngoingMeanDistribution(getEvoIndex(),ongoingAssemblyPostDegreeDistribution);
		}
		else
		{
			cerr << "Warning, ongoingAssemblyPostDegreeDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, ongoingAssemblyLoopSizeDistributionFile should be inited" << endl;
	}

	// Voisins
	if (ongoingAssemblyNearestNeighboursDegreeDistributionFile->isOpen())
	{
		if (ongoingAssemblyNearestNeighboursDegreeDistribution)
		{
			ongoingAssemblyNearestNeighboursDegreeDistributionFile->addOngoingMeanDistribution(getEvoIndex(),ongoingAssemblyNearestNeighboursDegreeDistribution);
		}
		else
		{
			cerr << "Warning, ongoingAssemblyNearestNeighboursDegreeDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, ongoingAssemblyNearestNeighboursLoopSizeDistributionFile should be inited" << endl;
	}
			#endif
			
			#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE
				#ifdef _3D_ONGOING_STAT_MODE
	// In/Out
	if (ongoingInputAssemblyDegreeDistributionFile->isOpen())
	{
		if (ongoingInputAssemblyDegreeDistribution)
		{
			ongoingInputAssemblyDegreeDistributionFile->addOngoingMeanDistribution(getEvoIndex(),ongoingInputAssemblyDegreeDistribution);
		}
		else
		{
			cerr << "Warning, ongoingInputAssemblyDegreeDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, ongoingInputAssemblyLoopSizeDistributionFile should be inited" << endl;
	}
	
	if (ongoingOutputAssemblyDegreeDistributionFile->isOpen())
	{
		if (ongoingOutputAssemblyDegreeDistribution)
		{
			ongoingOutputAssemblyDegreeDistributionFile->addOngoingMeanDistribution(getEvoIndex(),ongoingOutputAssemblyDegreeDistribution);
		}
		else
		{
			cerr << "Warning, ongoingOutputAssemblyDegreeDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, ongoingOutputAssemblyLoopSizeDistributionFile should be inited" << endl;
	}
	
	// Voisins
	if (ongoingInputAssemblyNearestNeighboursDegreeDistributionFile->isOpen())
	{
		if (ongoingInputAssemblyNearestNeighboursDegreeDistribution)
		{
			ongoingInputAssemblyNearestNeighboursDegreeDistributionFile->addOngoingMeanDistribution(getEvoIndex(),ongoingInputAssemblyNearestNeighboursDegreeDistribution);
		}
		else
		{
			cerr << "Warning, ongoingInputAssemblyNearestNeighboursDegreeDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, ongoingInputAssemblyNearestNeighboursLoopSizeDistributionFile should be inited" << endl;
	}
	
	if (ongoingOutputAssemblyNearestNeighboursDegreeDistributionFile->isOpen())
	{
		if (ongoingOutputAssemblyNearestNeighboursDegreeDistribution)
		{
			ongoingOutputAssemblyNearestNeighboursDegreeDistributionFile->addOngoingMeanDistribution(getEvoIndex(),ongoingOutputAssemblyNearestNeighboursDegreeDistribution);
		}
		else
		{
			cerr << "Warning, ongoingOutputAssemblyNearestNeighboursDegreeDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, ongoingOutputAssemblyNearestNeighboursLoopSizeDistributionFile should be inited" << endl;
	}
				#endif
			#endif
			
			#ifdef _CLUSTER_CENTRALITY_STAT_MODE
				#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingLinkedClusterDegreeDistributionFile->isOpen())
	{
		if (ongoingLinkedClusterDegreeDistribution)
		{
			ongoingLinkedClusterDegreeDistributionFile->addOngoingMeanDistribution(getEvoIndex(),ongoingLinkedClusterDegreeDistribution);
		}
		else
		{
			cerr << "Warning, ongoingLinkedClusterDegreeDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, ongoingLinkedClusterLoopSizeDistributionFile should be inited" << endl;
	}
	
	if (ongoingLinkedClusterPreDegreeDistributionFile->isOpen())
	{
		if (ongoingLinkedClusterPreDegreeDistribution)
		{
			ongoingLinkedClusterPreDegreeDistributionFile->addOngoingMeanDistribution(getEvoIndex(),ongoingLinkedClusterPreDegreeDistribution);
		}
		else
		{
			cerr << "Warning, ongoingLinkedClusterPreDegreeDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, ongoingLinkedClusterLoopSizeDistributionFile should be inited" << endl;
	}
	
	if (ongoingLinkedClusterPostDegreeDistributionFile->isOpen())
	{
		if (ongoingLinkedClusterPostDegreeDistribution)
		{
			ongoingLinkedClusterPostDegreeDistributionFile->addOngoingMeanDistribution(getEvoIndex(),ongoingLinkedClusterPostDegreeDistribution);
		}
		else
		{
			cerr << "Warning, ongoingLinkedClusterPostDegreeDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, ongoingLinkedClusterLoopSizeDistributionFile should be inited" << endl;
	}

	// Voisins
	if (ongoingLinkedClusterNearestNeighboursDegreeDistributionFile->isOpen())
	{
		if (ongoingLinkedClusterNearestNeighboursDegreeDistribution)
		{
			ongoingLinkedClusterNearestNeighboursDegreeDistributionFile->addOngoingMeanDistribution(getEvoIndex(),ongoingLinkedClusterNearestNeighboursDegreeDistribution);
		}
		else
		{
			cerr << "Warning, ongoingLinkedClusterNearestNeighboursDegreeDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, ongoingLinkedClusterNearestNeighboursLoopSizeDistributionFile should be inited" << endl;
	}
				#endif
				
				#ifdef _NETWORK_CLUSTER_STAT_MODE
	if (networkLinkedClusterDegreeDistributionFile->isOpen())
	{
		if (networkLinkedClusterDegreeDistribution)
		{
			networkLinkedClusterDegreeDistributionFile->addIndexedMeanDistribution(getEvoIndex(),networkLinkedClusterDegreeDistribution);
		}
		else
		{
			cerr << "Warning, networkLinkedClusterDegreeDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, networkLinkedClusterLoopSizeDistributionFile should be inited" << endl;
	}
	
	if (networkLinkedClusterPreDegreeDistributionFile->isOpen())
	{
		if (networkLinkedClusterPreDegreeDistribution)
		{
			networkLinkedClusterPreDegreeDistributionFile->addIndexedMeanDistribution(getEvoIndex(),networkLinkedClusterPreDegreeDistribution);
		}
		else
		{
			cerr << "Warning, networkLinkedClusterPreDegreeDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, networkLinkedClusterLoopSizeDistributionFile should be inited" << endl;
	}
	
	if (networkLinkedClusterPostDegreeDistributionFile->isOpen())
	{
		if (networkLinkedClusterPostDegreeDistribution)
		{
			networkLinkedClusterPostDegreeDistributionFile->addIndexedMeanDistribution(getEvoIndex(),networkLinkedClusterPostDegreeDistribution);
		}
		else
		{
			cerr << "Warning, networkLinkedClusterPostDegreeDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, networkLinkedClusterLoopSizeDistributionFile should be inited" << endl;
	}

	// Voisins
	if (networkLinkedClusterNearestNeighboursDegreeDistributionFile->isOpen())
	{
		if (networkLinkedClusterNearestNeighboursDegreeDistribution)
		{
			networkLinkedClusterNearestNeighboursDegreeDistributionFile->addIndexedMeanDistribution(getEvoIndex(),networkLinkedClusterNearestNeighboursDegreeDistribution);
		}
		else
		{
			cerr << "Warning, networkLinkedClusterNearestNeighboursDegreeDistribution should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, networkLinkedClusterNearestNeighboursDegreeDistributionFile should be inited" << endl;
	}
					#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
	if (maxModularityLinkedClusterDegreeDistributionFile->isOpen())
	{
		if (maxModularityLinkedClusterDegreeDistribution)
		{
			maxModularityLinkedClusterDegreeDistributionFile->addIndexedMeanDistribution(getEvoIndex(),maxModularityLinkedClusterDegreeDistribution);
		}
		else
		{
			cerr << "Warning, maxModularityLinkedClusterDegreeDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, maxModularityLinkedClusterLoopSizeDistributionFile should be inited" << endl;
	}
	
	if (maxModularityLinkedClusterPreDegreeDistributionFile->isOpen())
	{
		if (maxModularityLinkedClusterPreDegreeDistribution)
		{
			maxModularityLinkedClusterPreDegreeDistributionFile->addIndexedMeanDistribution(getEvoIndex(),maxModularityLinkedClusterPreDegreeDistribution);
		}
		else
		{
			cerr << "Warning, maxModularityLinkedClusterPreDegreeDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, maxModularityLinkedClusterLoopSizeDistributionFile should be inited" << endl;
	}
	
	if (maxModularityLinkedClusterPostDegreeDistributionFile->isOpen())
	{
		if (maxModularityLinkedClusterPostDegreeDistribution)
		{
			maxModularityLinkedClusterPostDegreeDistributionFile->addIndexedMeanDistribution(getEvoIndex(),maxModularityLinkedClusterPostDegreeDistribution);
		}
		else
		{
			cerr << "Warning, maxModularityLinkedClusterPostDegreeDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, maxModularityLinkedClusterLoopSizeDistributionFile should be inited" << endl;
	}

	// Voisins
	if (maxModularityLinkedClusterNearestNeighboursDegreeDistributionFile->isOpen())
	{
		if (maxModularityLinkedClusterNearestNeighboursDegreeDistribution)
		{
			maxModularityLinkedClusterNearestNeighboursDegreeDistributionFile->addIndexedMeanDistribution(getEvoIndex(),maxModularityLinkedClusterNearestNeighboursDegreeDistribution);
		}
		else
		{
			cerr << "Warning, maxModularityLinkedClusterNearestNeighboursDegreeDistribution should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, maxModularityLinkedClusterNearestNeighboursDegreeDistributionFile should be inited" << endl;
	}				
					#endif
				#endif
			#endif
			
		#else
	if (meanDegreeDistributionFile->isOpen())
	{
		if (meanDegreeDistribution)
		{
			meanDegreeDistributionFile->addIndexedMeanDistribution(getEvoIndex(),(MeanDistribution*) meanDegreeDistribution);
		}
		else
		{
			cerr << "Warning, meanDegreeDistribution should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, meanDegreeDistributionFile should be inited" << endl;
	}

	if (meanPreDegreeDistributionFile->isOpen())
	{
		if (meanPreDegreeDistribution)
		{
			meanPreDegreeDistributionFile->addIndexedMeanDistribution(getEvoIndex(),(MeanDistribution*) meanPreDegreeDistribution);
		}
		else
		{
			cerr << "Warning, meanPreDegreeDistribution should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, meanPreDegreeDistributionFile should be inited" << endl;
	}

	if (meanPostDegreeDistributionFile->isOpen())
	{
		if (meanPostDegreeDistribution)
		{
			meanPostDegreeDistributionFile->addIndexedMeanDistribution(getEvoIndex(),(MeanDistribution*) meanPostDegreeDistribution);
		}
		else
		{
			cerr << "Warning, meanPostDegreeDistribution should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, meanPostDegreeDistributionFile should be inited" << endl;
	}
	
	if (meanNearestNeighboursDegreeDistributionFile->isOpen())
	{
		if (meanNearestNeighboursDegreeDistribution)
		{
			meanNearestNeighboursDegreeDistributionFile->addIndexedMeanDistribution(getEvoIndex(),(MeanDistribution*) meanNearestNeighboursDegreeDistribution);
		}
		else
		{
			cerr << "Warning, meanNearestNeighboursDegreeDistribution should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, meanNearestNeighboursDegreeDistributionFile should be inited" << endl;
	}
	
			#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE
	if (meanInputAssemblyDegreeDistributionFile->isOpen())
	{
		if (meanInputAssemblyDegreeDistribution)
		{
			meanInputAssemblyDegreeDistributionFile->addIndexedMeanDistribution(getEvoIndex(),(MeanDistribution*) meanInputAssemblyDegreeDistribution);
		}
		else
		{
			cerr << "Warning, meanInputAssemblyDegreeDistribution should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, meanInputAssemblyDegreeDistributionFile should be inited" << endl;
	}
	
	if (meanOutputAssemblyDegreeDistributionFile->isOpen())
	{
		if (meanOutputAssemblyDegreeDistribution)
		{
			meanOutputAssemblyDegreeDistributionFile->addIndexedMeanDistribution(getEvoIndex(),(MeanDistribution*) meanOutputAssemblyDegreeDistribution);
		}
		else
		{
			cerr << "Warning, meanOutputAssemblyDegreeDistribution should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, meanOutputAssemblyDegreeDistributionFile should be inited" << endl;
	}
	
	if (meanInputAssemblyNearestNeighboursDegreeDistributionFile->isOpen())
	{
		if (meanInputAssemblyNearestNeighboursDegreeDistribution)
		{
			meanInputAssemblyNearestNeighboursDegreeDistributionFile->addIndexedMeanDistribution(getEvoIndex(),(MeanDistribution*) meanInputAssemblyNearestNeighboursDegreeDistribution);
		}
		else
		{
			cerr << "Warning, meanInputAssemblyNearestNeighbourDegreeDistribution should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, meanInputAssemblyNearestNeighbourDegreeDistributionFile should be inited" << endl;
	}
	
	if (meanOutputAssemblyNearestNeighboursDegreeDistributionFile->isOpen())
	{
		if (meanOutputAssemblyNearestNeighboursDegreeDistribution)
		{
			meanOutputAssemblyNearestNeighboursDegreeDistributionFile->addIndexedMeanDistribution(getEvoIndex(),(MeanDistribution*) meanOutputAssemblyNearestNeighboursDegreeDistribution);
		}
		else
		{
			cerr << "Warning, meanOutputAssemblyNearestNeighbourDegreeDistribution should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, meanOutputAssemblyNearestNeighbourDegreeDistributionFile should be inited" << endl;
	}
			#endif
		#endif
	#endif

	#ifdef _GSCC_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
	if (ongoingNbGSCCNodesFile->isOpen())
	{
		for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
		{
			ongoingNbGSCCNodesFile->addIndexedAccuLineData(getEvoIndex(),i,ongoingNbGSCCNodes[i]);
		}
		ongoingNbGSCCNodesFile->addDataSeparator();
	}
	else
	{
		cerr << "Warning, ongoingNbGSCCNodesFile should be inited" << endl;
	}
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingSCComponentSizeDistributionFile->isOpen())
	{
		if (ongoingSCComponentSizeDistribution)
		{
			ongoingSCComponentSizeDistributionFile->addOngoingMeanDistribution(getEvoIndex(),ongoingSCComponentSizeDistribution);
		}
		else
		{
			cerr << "Warning, ongoingSCComponentSizeDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, ongoingSCComponentSizeDistributionFile should be inited" << endl;
	}
			#endif
			
	if (ongoingMaxSCComponentSizeFile->isOpen())
	{
		for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
		{
			ongoingMaxSCComponentSizeFile->addIndexedAccuLineData(getEvoIndex(),i,ongoingMaxSCComponentSize[i]);
		}
		ongoingMaxSCComponentSizeFile->addDataSeparator();
	}
	else
	{
		cerr << "Warning, ongoingMaxSCComponentSizeFile should be inited" << endl;
	}
	
			#ifdef _3D_ONGOING_STAT_MODE
	if (ongoingMaxSCComponentSizeDistributionFile->isOpen())
	{
		if (ongoingMaxSCComponentSizeDistribution)
		{
			ongoingMaxSCComponentSizeDistributionFile->addOngoingDistribution(getEvoIndex(),ongoingMaxSCComponentSizeDistribution);
		}
		else
		{
			cerr << "Warning, ongoingMaxSCComponentSizeDistribution should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, ongoingMaxSCComponentSizeDistributionFile should be inited" << endl;
	}
			#endif
	/*
	if (meanAssemblyDiameterSizeDistributionFile->isOpen())
	{
		if (meanAssemblyDiameterSizeDistribution)
		{
			((DistributionDataFile*) meanAssemblyDiameterSizeDistributionFile)->addIndexedMeanDistribution(getEvoIndex(),meanAssemblyDiameterSizeDistribution);
		}
		else
		{
			cerr << "Warning, meanAssemblyDiameterSizeDistribution should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, meanAssemblyDiameterSizeDistributionFile should be inited" << endl;
	}
	*/
		#else
	if (meanNbGSCCNodesFile->isOpen())
	{
		meanNbGSCCNodesFile->addAccuLineData(getEvoIndex(),*meanNbGSCCNodes);
	}

	if (meanSCComponentSizeDistributionFile->isOpen())
	{
		if (meanSCComponentSizeDistribution)
		{
			meanSCComponentSizeDistributionFile->addIndexedMeanDistribution(getEvoIndex(),(MeanDistribution*) meanSCComponentSizeDistribution);
		}
		else
		{
			cerr << "Warning, meanSCComponentSizeDistributionFile should be inited" << endl;
		}
	}

	if (meanMaxSCComponentSizeFile->isOpen())
	{
		meanMaxSCComponentSizeFile->addAccuLineData(getEvoIndex(),*meanMaxSCComponentSize);
	}

	if (meanMaxSCComponentSizeDistributionFile->isOpen())
	{
		if (meanMaxSCComponentSizeDistribution)
		{
			meanMaxSCComponentSizeDistributionFile->addIndexedDistribution(getEvoIndex(),(Distribution*) meanMaxSCComponentSizeDistribution);
		}
		else
		{
			cerr << "Warning, meanMaxSCComponentSizeDistributionFile should be inited" << endl;
		}
	}
			#ifdef _INPUT_OUTPUT_GSCC_STAT_MODE	
	if (meanInputSCComponentSizeDistributionFile->isOpen())
	{
		if (meanInputSCComponentSizeDistribution)
		{
			meanInputSCComponentSizeDistributionFile->addIndexedMeanDistribution(getEvoIndex(),(MeanDistribution*) meanInputSCComponentSizeDistribution);
		}
		else
		{
			cerr << "Warning, meanInputSCComponentSizeDistributionFile should be inited" << endl;
		}
	}
	
	
	if (meanOutputSCComponentSizeDistributionFile->isOpen())
	{
		if (meanOutputSCComponentSizeDistribution)
		{
			meanOutputSCComponentSizeDistributionFile->addIndexedMeanDistribution(getEvoIndex(),(MeanDistribution*) meanOutputSCComponentSizeDistribution);
		}
		else
		{
			cerr << "Warning, meanOutputSCComponentSizeDistributionFile should be inited" << endl;
		}
	}
	
	if (meanInputSCCFractionRepartitionFile->isOpen())
	{
		if (meanInputSCCFractionRepartition)
		{
			for (int i=0;i<NB_INPUT_ASSEMBLIES;i++)
			{
				meanInputSCCFractionRepartitionFile->addIndexedAccuLineData(getEvoIndex(),i,meanInputSCCFractionRepartition[i]);
			}
			
			meanInputSCCFractionRepartitionFile->addDataSeparator();
		}
		else
		{
			cerr << "Warning, meanInputSCCFractionRepartition should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, meanInputSCCFractionRepartitionFile should be inited" << endl;
	}

	if (meanOutputSCCFractionRepartitionFile->isOpen())
	{
		if (meanOutputSCCFractionRepartition)
		{
			for (int i=0;i<NB_OUTPUT_ASSEMBLIES;i++)
			{
				meanOutputSCCFractionRepartitionFile->addIndexedAccuLineData(getEvoIndex(),i,meanOutputSCCFractionRepartition[i]);
			}
			
			meanOutputSCCFractionRepartitionFile->addDataSeparator();
		}
		else
		{
			cerr << "Warning, meanOutputSCCFractionRepartition should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, meanOutputSCCFractionRepartitionFile should be inited" << endl;
	}

			#endif
		#endif
	#endif

	#ifdef _PROJECTION_STAT_MODE
	if(meanProjectionsFile->isOpen())
	{
		if (meanProjections)
		{
			meanProjectionsFile->addAccuLineData(getEvoIndex(),*meanProjections);
		}
		else
		{
			cerr << "Warning, meanProjections should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, meanProjectionsFile should be inited" << endl;
	}

	// Excit/Inhib
	if(meanExcitProjectionsFile->isOpen())
	{
		if (meanExcitProjections)
		{
			meanExcitProjectionsFile->addAccuLineData(getEvoIndex(),*meanExcitProjections);
		}
		else
		{
			cerr << "Warning, meanExcitProjections should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, meanExcitProjectionsFile should be inited" << endl;
	}

	if(meanInhibProjectionsFile->isOpen())
	{
		if (meanInhibProjections)
		{
			meanInhibProjectionsFile->addAccuLineData(getEvoIndex(),*meanInhibProjections);

		}
		else
		{
			cerr << "Warning, meanInhibProjectionsFile should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, meanInhibProjectionsFile should be inited" << endl;
	}

	// Input
	if(meanExcitInputProjectionsFile->isOpen())
	{
		if (meanExcitInputProjections)
		{
			meanExcitInputProjectionsFile->addAccuLineData(getEvoIndex(),*meanExcitInputProjections);
		}
		else
		{
			cerr << "Warning, meanExcitInputProjections should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, meanExcitInputProjectionsFile should be inited" << endl;
	}

	if(meanInhibInputProjectionsFile->isOpen())
	{
		if (meanInhibInputProjections)
		{
			meanInhibInputProjectionsFile->addAccuLineData(getEvoIndex(),*meanInhibInputProjections);
		}
		else
		{
			cerr << "Warning, meanInhibInputProjections should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, meanInhibInputProjectionsFile should be inited" << endl;
	}

	// Output
	if(meanExcitOutputProjectionsFile->isOpen())
	{
		if (meanExcitOutputProjections)
		{
			meanExcitOutputProjectionsFile->addAccuLineData(getEvoIndex(),*meanExcitOutputProjections);
		}
		else
		{
			cerr << "Warning, meanExcitOutputProjections should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, meanExcitOutputProjectionsFile should be inited" << endl;
	}

	if(meanInhibOutputProjectionsFile->isOpen())
	{
		if (meanInhibOutputProjections)
		{
			meanInhibOutputProjectionsFile->addAccuLineData(getEvoIndex(),*meanInhibOutputProjections);
		}
		else
		{
			cerr << "Warning, meanInhibOutputProjections should be inited" << endl;
		}

	}
	else
	{
		cerr << "Warning, meanInhibOutputProjectionsFile should be inited" << endl;
	}

	// Self
	if(meanExcitSelfProjectionsFile->isOpen())
	{
		if (meanExcitSelfProjections)
		{
			meanExcitSelfProjectionsFile->addAccuLineData(getEvoIndex(),*meanExcitSelfProjections);

		}
		else
		{
			cerr << "Warning, meanExcitSelfProjections should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, meanExcitSelfProjectionsFile should be inited" << endl;
	}

	if(meanInhibSelfProjectionsFile->isOpen())
	{
		if (meanInhibSelfProjections)
		{
			meanInhibSelfProjectionsFile->addAccuLineData(getEvoIndex(),*meanInhibSelfProjections);

		}
		else
		{
			cerr << "Warning, meanInhibSelfProjections should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, meanInhibSelfProjectionsFile should be inited" << endl;
	}
	#endif
	
	
	#ifdef _INPUT_OUTPUT_CLUSTER_STAT_MODE	
	
	if (maxModularityInputClusterSizeDistributionFile->isOpen())
	{
		if (maxModularityInputClusterSizeDistribution)
		{
			maxModularityInputClusterSizeDistributionFile->addIndexedMeanDistribution(getEvoIndex(),(MeanDistribution*) maxModularityInputClusterSizeDistribution);
		}
		else
		{
			cerr << "Warning, maxModularityInputClusterSizeDistributionFile should be inited" << endl;
		}
	}
	
	if (maxModularityOutputClusterSizeDistributionFile->isOpen())
	{
		if (maxModularityOutputClusterSizeDistribution)
		{
			maxModularityOutputClusterSizeDistributionFile->addIndexedMeanDistribution(getEvoIndex(),(MeanDistribution*) maxModularityOutputClusterSizeDistribution);
		}
		else
		{
			cerr << "Warning, maxModularityOutputClusterSizeDistributionFile should be inited" << endl;
		}
	}
	
	if (maxModularityInputClusterFractionRepartitionFile->isOpen())
	{
		if (maxModularityInputClusterFractionRepartition)
		{
			for (int i=0;i<NB_INPUT_ASSEMBLIES;i++)
			{
				maxModularityInputClusterFractionRepartitionFile->addIndexedAccuLineData(getEvoIndex(),i,maxModularityInputClusterFractionRepartition[i]);
			}
			
			maxModularityInputClusterFractionRepartitionFile->addDataSeparator();
		}
		else
		{
			cerr << "Warning, maxModularityInputClusterFractionRepartition should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, maxModularityInputClusterFractionRepartitionFile should be inited" << endl;
	}

	if (maxModularityOutputClusterFractionRepartitionFile->isOpen())
	{
		if (maxModularityOutputClusterFractionRepartition)
		{
			for (int i=0;i<NB_OUTPUT_ASSEMBLIES;i++)
			{
				maxModularityOutputClusterFractionRepartitionFile->addIndexedAccuLineData(getEvoIndex(),i,maxModularityOutputClusterFractionRepartition[i]);
			}
			
			maxModularityOutputClusterFractionRepartitionFile->addDataSeparator();
		}
		else
		{
			cerr << "Warning, maxModularityOutputClusterFractionRepartition should be inited" << endl;
		}
	}
	else
	{
		cerr << "Warning, maxModularityOutputClusterFractionRepartitionFile should be inited" << endl;
	}

	#endif
			
	#ifdef _TEST_STAT
	flushCounters();
	#endif
}

void NetworkStater::graph()
{
	ostringstream oss;

	#ifdef _CENTRALITY_STAT_MODE

		#ifdef _CLUSTER_STAT_MODE
		// Assemblees			
		
			#ifndef _LOAD_ORDERED_PROJECTIONS_MODE	
	// Calcul de centralite
				#ifdef _3D_ONGOING_STAT_MODE
	meanGnuplotProjectionsFile->plotOngoingMeanLogDistribution("AssemblyCentralBetweenness",getEvoIndex());
				#endif
				
	meanGnuplotProjectionsFile->plotOngoingAccumulater("AssemblyCentralBetweenness");

	// Centralite de noeuds
				#ifdef _3D_ONGOING_STAT_MODE
	meanGnuplotProjectionsFile->plotOngoingMeanLogDistribution("AssemblyBetweenness",getEvoIndex());
				#endif
				
	meanGnuplotProjectionsFile->plotOngoingAccumulater("AssemblyBetweenness");

			
				#ifdef _EDGE_BETWEENNESS_STAT_MODE

	// Intermediarite de liens
	meanGnuplotProjectionsFile->plotOngoingAccumulater("AssemblyMaxEdgeBetweenness");
					#ifdef _3D_ONGOING_STAT_MODE
	meanGnuplotProjectionsFile->plotOngoingMeanLogDistribution("AssemblyEdgeBetweenness",getEvoIndex());
					#endif
				#endif
			
	// Efficacite
	meanGnuplotProjectionsFile->plotOngoingAccumulater("AssemblyGlobalEfficiency");
				
				#ifdef _3D_ONGOING_STAT_MODE
	meanGnuplotProjectionsFile->plotOngoingMeanLogDistribution("AssemblyGlobalEfficiency",getEvoIndex());
				#endif
				
	meanGnuplotProjectionsFile->plotOngoingAccumulater("AssemblyLocalEfficiency");
				
				#ifdef _3D_ONGOING_STAT_MODE
	meanGnuplotProjectionsFile->plotOngoingMeanLogDistribution("AssemblyLocalEfficiency",getEvoIndex());
				#endif
	// ShortPath
				#ifdef _3D_ONGOING_STAT_MODE
	meanGnuplotProjectionsFile->plotOngoingDistribution("AssemblyShortPathLength",getEvoIndex());
				#endif
			#endif
			
		// Clusters
	meanGnuplotProjectionsFile->plotOngoingValue("ClusterModularity");
	meanGnuplotProjectionsFile->plotOngoingAccumulater("NbClusters");
	meanGnuplotProjectionsFile->plotOngoingAccumulater("MaxClusterSizes");

			#ifdef _3D_ONGOING_STAT_MODE
	meanGnuplotProjectionsFile->plotOngoingDistribution("ClusterSize",getEvoIndex());
			#endif

	// Efficacite
	meanGnuplotProjectionsFile->plotOngoingAccumulater("ClusterEfficiency");
			#ifdef _3D_ONGOING_STAT_MODE
	meanGnuplotProjectionsFile->plotOngoingMeanLogDistribution("ClusterEfficiency",getEvoIndex());
			#endif
			
	meanGnuplotProjectionsFile->plotOngoingAccumulater("ClusterRealEfficiency");
			#ifdef _3D_ONGOING_STAT_MODE
	meanGnuplotProjectionsFile->plotOngoingMeanLogDistribution("ClusterRealEfficiency",getEvoIndex());
			#endif
				
			#ifdef _LINKED_CLUSTER_STAT_MODE
	// Repartition des composants
	meanGnuplotProjectionsFile->plotOngoingAccumulater("InDC");
	meanGnuplotProjectionsFile->plotOngoingAccumulater("InGOUT");
	meanGnuplotProjectionsFile->plotOngoingAccumulater("InGIN");
	meanGnuplotProjectionsFile->plotOngoingAccumulater("InGSCC");

				#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	// Calcul de centralite
					#ifdef _3D_ONGOING_STAT_MODE
	meanGnuplotProjectionsFile->plotOngoingMeanLogDistribution("LinkedClusterCentralBetweenness",getEvoIndex());
					#endif
	meanGnuplotProjectionsFile->plotOngoingAccumulater("LinkedClusterCentralBetweenness");

	// Centralite de noeuds
					#ifdef _3D_ONGOING_STAT_MODE
	meanGnuplotProjectionsFile->plotOngoingMeanLogDistribution("LinkedClusterBetweenness",getEvoIndex());
					#endif
	meanGnuplotProjectionsFile->plotOngoingAccumulater("LinkedClusterBetweenness");

					
					#ifdef _EDGE_BETWEENNESS_STAT_MODE

	// Intermediarite de liens
						#ifdef _3D_ONGOING_STAT_MODE
	meanGnuplotProjectionsFile->plotOngoingMeanLogDistribution("LinkedClusterEdgeBetweenness",getEvoIndex());
						#endif
	meanGnuplotProjectionsFile->plotOngoingAccumulater("LinkedClusterMaxEdgeBetweenness");
					#endif
	// Efficacite
					#ifdef _3D_ONGOING_STAT_MODE
	meanGnuplotProjectionsFile->plotOngoingMeanLogDistribution("LinkedClusterLocalEfficiency",getEvoIndex());
					#endif
	meanGnuplotProjectionsFile->plotOngoingAccumulater("LinkedClusterLocalEfficiency");

					#ifdef _3D_ONGOING_STAT_MODE
	meanGnuplotProjectionsFile->plotOngoingMeanLogDistribution("LinkedClusterGlobalEfficiency",getEvoIndex());	
					#endif
	meanGnuplotProjectionsFile->plotOngoingAccumulater("LinkedClusterGlobalEfficiency");

	// ShortPath
					#ifdef _3D_ONGOING_STAT_MODE
	meanGnuplotProjectionsFile->plotOngoingDistribution("LinkedClusterShortPathLength",getEvoIndex());
					#endif

				#endif
			#endif

			#ifdef _NETWORK_CLUSTER_STAT_MODE
				#ifdef _LINKED_CLUSTER_STAT_MODE
	meanGnuplotProjectionsFile->plotRepartition("NetworkComponent");
				#endif

	meanGnuplotProjectionsFile->plotMeanDistribution("NetworkClusterSize");

	// Efficacite
	meanGnuplotProjectionsFile->plotMean("NetworkClusterEfficiency");
	meanGnuplotProjectionsFile->plotLogDistribution("NetworkClusterEfficiency");

	meanGnuplotProjectionsFile->plotMean("NetworkClusterRealEfficiency");
	meanGnuplotProjectionsFile->plotLogDistribution("NetworkClusterRealEfficiency");


				#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
	// Nombre de suppression de liens pour atteindre le réseau optimal
	meanGnuplotProjectionsFile->plotMean("MaxModularityProjectionIndex");

	// Modularité maximale
	meanGnuplotProjectionsFile->plotMean("MaxModularity");

					#ifdef _LINKED_CLUSTER_STAT_MODE
	// Repartition des clusters dans les composants pour le réseau optimal
	meanGnuplotProjectionsFile->plotRepartition("MaxModularityComponent");
					#endif

	// Repartition de la taille des clusters pour le réseau optimal
	meanGnuplotProjectionsFile->plotMeanDistribution("MaxModularityClusterSize");

	// Repartition de l'efficacité des clusters pour le réseau optimal
	meanGnuplotProjectionsFile->plotMean("MaxModularityClusterEfficiency");
	meanGnuplotProjectionsFile->plotLogDistribution("MaxModularityClusterEfficiency");

	meanGnuplotProjectionsFile->plotMean("MaxModularityClusterRealEfficiency");
	meanGnuplotProjectionsFile->plotLogDistribution("MaxModularityClusterRealEfficiency");
				#endif
			#endif
		#else

	// Calcul d'intermediarité
	meanGnuplotProjectionsFile->plotRepartition("MeanAssemblyBetweenness");
	meanGnuplotProjectionsFile->plotMean("MeanAssemblyBetweenness");

	meanGnuplotProjectionsFile->plotLogDistribution("MeanAssemblyBetweenness");
	
	// Calcul de centralité
	meanGnuplotProjectionsFile->plotRepartition("MeanAssemblyCentralBetweenness");
	meanGnuplotProjectionsFile->plotMean("MeanAssemblyCentralBetweenness");
	
	meanGnuplotProjectionsFile->plotLogDistribution("MeanAssemblyCentralBetweenness");

			#ifdef _EDGE_BETWEENNESS_STAT_MODE

	// Calcul d'intermediarité pour les liens
	for (int i=0;i<getEvoIndex()+1;i++)
	{
		ostringstream oss;
		oss << i;
		meanGnuplotProjectionsFile->setOutput("3DMeanEdgeBetweennessRepartition"+oss.str());
		meanGnuplotProjectionsFile->setTitle("3DMeanEdgeBetweennessRepartition"+oss.str());
		meanGnuplotProjectionsFile->plot3DSingleSurface("MeanEdgeBetweennessRepartitionStat",i);
	}
	
	meanGnuplotProjectionsFile->plotLogDistribution("MeanEdgeBetweenness");
	
			#endif
			
	// Repartition des short paths
	meanGnuplotProjectionsFile->plotRepartition("MeanAssemblyShortPath");
	meanGnuplotProjectionsFile->plotRepartition("MeanAssemblyNoShortPath");

	meanGnuplotProjectionsFile->plotMeanDistribution("MeanAssemblyNbShortPath");

	// Calcul d'efficacite
	meanGnuplotProjectionsFile->plotRepartition("MeanAssemblyGlobalEfficiency");
	meanGnuplotProjectionsFile->plotRepartition("MeanAssemblyLocalEfficiency");
	
	meanGnuplotProjectionsFile->plotLogDistribution("MeanAssemblyGlobalEfficiency");
	meanGnuplotProjectionsFile->plotLogDistribution("MeanAssemblyLocalEfficiency");

	meanGnuplotProjectionsFile->plotMean("MeanAssemblyGlobalEfficiency");
	meanGnuplotProjectionsFile->plotMean("MeanAssemblyLocalEfficiency");
		#endif
	#endif

	//Loops
	#ifdef _LOOP_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
		// Assembly
			#ifndef _LOAD_ORDERED_PROJECTIONS_MODE
	// Nb Loops
				#ifdef _3D_ONGOING_STAT_MODE
	meanGnuplotProjectionsFile->plotOngoingMeanLogDistribution("AssemblyNbLoops",getEvoIndex());
				#endif
	meanGnuplotProjectionsFile->plotOngoingAccumulater("AssemblyNbLoops");

	// Degree
				#ifdef _3D_ONGOING_STAT_MODE
	meanGnuplotProjectionsFile->plotOngoingDistribution("AssemblyNbLoopsDegree",getEvoIndex());
	
	// LoopSize
	meanGnuplotProjectionsFile->plotOngoingDistribution("AssemblyLoopSize",getEvoIndex());
				#endif
			#endif
			
		// Cluster
			#ifdef _3D_ONGOING_STAT_MODE
	meanGnuplotProjectionsFile->plotOngoingDistribution("ClusterLoopSize",getEvoIndex());
			#endif
	meanGnuplotProjectionsFile->plotOngoingAccumulater("ClusterNbLoops");

			#ifdef _NETWORK_CLUSTER_STAT_MODE
	meanGnuplotProjectionsFile->plotMeanDistribution("NetworkClusterLoopSize");

				#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
	meanGnuplotProjectionsFile->plotMeanDistribution("MaxModularityClusterLoopSize");
				#endif
				
			#endif
		#else
	meanGnuplotProjectionsFile->plotMeanDistribution("MeanAssemblyLoopSize");

	// Nb Loops
	meanGnuplotProjectionsFile->plotRepartition("MeanAssemblyNbLoops");
	meanGnuplotProjectionsFile->plotLogDistribution("MeanAssemblyNbLoops");
	
	// Degree
	meanGnuplotProjectionsFile->plotMeanDistribution("MeanAssemblyNbLoopsDegree");
	

		#endif
	#endif

	// Small World
	#ifdef _SMALL_WORLD_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
			#ifndef _LOAD_ORDERED_PROJECTIONS_MODE
	// Degree
				#ifdef _3D_ONGOING_STAT_MODE
	meanGnuplotProjectionsFile->plotOngoingDistribution("AssemblyClusteringCoeffDegree",getEvoIndex());
	meanGnuplotProjectionsFile->plotOngoingMeanLogDistribution("AssemblyClusteringCoeff",getEvoIndex());
				#endif
			#endif
			
	// Cluster
	meanGnuplotProjectionsFile->plotOngoingAccumulater("ClusterInternalDensity");
	meanGnuplotProjectionsFile->plotOngoingAccumulater("RealClusterInternalDensity");

			#ifdef _CLUSTER_CENTRALITY_STAT_MODE
				#ifdef _3D_ONGOING_STAT_MODE
	meanGnuplotProjectionsFile->plotOngoingDistribution("LinkedClusterClusteringCoeffDegree",getEvoIndex());
	meanGnuplotProjectionsFile->plotOngoingMeanLogDistribution("LinkedClusterClusteringCoeff",getEvoIndex());
				#endif
			#endif
			
		 	#ifdef _NETWORK_CLUSTER_STAT_MODE
	meanGnuplotProjectionsFile->plotMean("NetworkClusterInternalDensity");
	meanGnuplotProjectionsFile->plotMean("NetworkRealClusterInternalDensity");
	
				#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	meanGnuplotProjectionsFile->plotMeanDistribution("NetworkLinkedClusterClusteringCoeffDegree");
	meanGnuplotProjectionsFile->plotLogDistribution("NetworkLinkedClusterClusteringCoeff");
				#endif
				
				#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
	meanGnuplotProjectionsFile->plotMean("MaxModularityClusterInternalDensity");
	meanGnuplotProjectionsFile->plotMean("MaxModularityRealClusterInternalDensity");
	
					#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	meanGnuplotProjectionsFile->plotMeanDistribution("MaxModularityLinkedClusterClusteringCoeffDegree");
	meanGnuplotProjectionsFile->plotLogDistribution("MaxModularityLinkedClusterClusteringCoeff");
					#endif
				#endif
			#endif
		#else
	// Distribution
	meanGnuplotProjectionsFile->plotLogDistribution("MeanClusteringCoeff");
	
	// Degree
	meanGnuplotProjectionsFile->plotMeanDistribution("MeanClusteringCoeffDegree");
			
	// Repartition
	meanGnuplotProjectionsFile->plotRepartition("MeanClusteringCoeff");
	
	// Network
	meanGnuplotProjectionsFile->plotMean("MeanClusteringCoeff");
		#endif
	#endif

	#ifdef _MOTIF_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
			#ifndef _LOAD_ORDERED_PROJECTIONS_MODE
				#ifdef _3D_ONGOING_STAT_MODE
	meanGnuplotProjectionsFile->plotOngoingAccumulater("AssemblyBinodeMotifs");
	meanGnuplotProjectionsFile->plotOngoingDistribution("AssemblyTrinodeMotifs",getEvoIndex());
				#endif
			#endif
			
			#ifdef _CLUSTER_CENTRALITY_STAT_MODE
				#ifdef _3D_ONGOING_STAT_MODE
	meanGnuplotProjectionsFile->plotOngoingDistribution("LinkedClusterTrinodeMotifs",getEvoIndex());
				#endif
			#endif
			
			#ifdef _INTERNAL_MOTIF_STAT_MODE
				#ifdef _3D_ONGOING_STAT_MODE
	meanGnuplotProjectionsFile->plotOngoingAccumulater("ClusterInternalBinodeMotifs");
	meanGnuplotProjectionsFile->plotOngoingDistribution("ClusterInternalTrinodeMotifs",getEvoIndex());
				#endif
				
				#ifdef _NETWORK_CLUSTER_STAT_MODE
				
	meanGnuplotProjectionsFile->plotMean("NetworkClusterInternalBinodeMotifs");
	meanGnuplotProjectionsFile->plotDistribution("NetworkClusterInternalTrinodeMotifs");
	
					#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	meanGnuplotProjectionsFile->plotDistribution("NetworkLinkedClusterTrinodeMotifs");
					#endif
					
					#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
	meanGnuplotProjectionsFile->plotMean("MaxModularityClusterInternalBinodeMotifs");
	meanGnuplotProjectionsFile->plotDistribution("MaxModularityClusterInternalTrinodeMotifs");
	
						#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	meanGnuplotProjectionsFile->plotDistribution("MaxModularityLinkedClusterTrinodeMotifs");
						#endif
					#endif
				#endif
			#endif
		#else
	meanGnuplotProjectionsFile->plotMean("MeanBinodeMotifs");
	meanGnuplotProjectionsFile->plotDistribution("MeanTrinodeMotifs");
		#endif
	#endif
	
	#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
		
			#ifndef _LOAD_ORDERED_PROJECTIONS_MODE
				#ifdef _3D_ONGOING_STAT_MODE
	meanGnuplotProjectionsFile->plotOngoingDistribution("AssemblyReachedByInput",getEvoIndex());
	meanGnuplotProjectionsFile->plotOngoingDistribution("AssemblyReachedByOutput",getEvoIndex());
	
	meanGnuplotProjectionsFile->plotOngoingDistribution("AssemblyInputOutputPathLength",getEvoIndex());
	meanGnuplotProjectionsFile->plotOngoingDistribution("AssemblyPathToInput",getEvoIndex());
	meanGnuplotProjectionsFile->plotOngoingDistribution("AssemblyPathToOutput",getEvoIndex());
				#endif
			#endif
		#else
	meanGnuplotProjectionsFile->plotDistribution("MeanReachedByInput");
	meanGnuplotProjectionsFile->plotDistribution("MeanReachedByOutput");
	
	meanGnuplotProjectionsFile->plotMeanDistribution("MeanPathToInput");
	meanGnuplotProjectionsFile->plotMeanDistribution("MeanPathToInput");
	meanGnuplotProjectionsFile->plotMeanDistribution("MeanInputOutputPathLength");
		#endif
	#endif
	

	#ifdef _DEGREE_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
			#ifndef _LOAD_ORDERED_PROJECTIONS_MODE
	// Degree
				#ifdef _3D_ONGOING_STAT_MODE
	meanGnuplotProjectionsFile->plotOngoingDistribution("AssemblyDegree",getEvoIndex());
	meanGnuplotProjectionsFile->plotOngoingDistribution("AssemblyPreDegree",getEvoIndex());
	meanGnuplotProjectionsFile->plotOngoingDistribution("AssemblyPostDegree",getEvoIndex());
	
	// Voisins
	meanGnuplotProjectionsFile->plotOngoingDistribution("AssemblyNearestNeighboursDegree",getEvoIndex());
				#endif
				
				#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE
	// In/Out
					#ifdef _3D_ONGOING_STAT_MODE
	meanGnuplotProjectionsFile->plotOngoingDistribution("InputAssemblyDegree",getEvoIndex());
	meanGnuplotProjectionsFile->plotOngoingDistribution("OutputAssemblyDegree",getEvoIndex());
	
	// Voisins
	meanGnuplotProjectionsFile->plotOngoingDistribution("InputAssemblyNearestNeighboursDegree",getEvoIndex());
	meanGnuplotProjectionsFile->plotOngoingDistribution("OutputAssemblyNearestNeighboursDegree",getEvoIndex());
					#endif
				#endif
			#endif
			
			#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	// Degree
				#ifdef _3D_ONGOING_STAT_MODE
	meanGnuplotProjectionsFile->plotOngoingDistribution("LinkedClusterDegree",getEvoIndex());
	meanGnuplotProjectionsFile->plotOngoingDistribution("LinkedClusterPreDegree",getEvoIndex());
	meanGnuplotProjectionsFile->plotOngoingDistribution("LinkedClusterPostDegree",getEvoIndex());
	
	// Voisins
	meanGnuplotProjectionsFile->plotOngoingDistribution("LinkedClusterNearestNeighboursDegree",getEvoIndex());
				#endif
				
				#ifdef _NETWORK_CLUSTER_STAT_MODE
	// Degree
	meanGnuplotProjectionsFile->plotMeanDistribution("NetworkLinkedClusterDegree");
	meanGnuplotProjectionsFile->plotMeanDistribution("NetworkLinkedClusterPreDegree");
	meanGnuplotProjectionsFile->plotMeanDistribution("NetworkLinkedClusterPostDegree");
	
	// Voisins
	meanGnuplotProjectionsFile->plotMeanDistribution("NetworkLinkedClusterNearestNeighboursDegree");
	
					#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
	// Degree
	meanGnuplotProjectionsFile->plotMeanDistribution("MaxModularityLinkedClusterDegree");
	meanGnuplotProjectionsFile->plotMeanDistribution("MaxModularityLinkedClusterPreDegree");
	meanGnuplotProjectionsFile->plotMeanDistribution("MaxModularityLinkedClusterPostDegree");
	
	// Voisins
	meanGnuplotProjectionsFile->plotMeanDistribution("MaxModularityLinkedClusterNearestNeighboursDegree");
					#endif
				#endif
			#endif
		#else
	//Degree	
	meanGnuplotProjectionsFile->plotMeanDistribution("MeanDegree");
	meanGnuplotProjectionsFile->plotMeanDistribution("MeanPreDegree");
	meanGnuplotProjectionsFile->plotMeanDistribution("MeanPostDegree");
			
	// Voisins
	meanGnuplotProjectionsFile->plotMeanDistribution("MeanNearestNeighboursDegree");
			#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE
	// In/Out
	meanGnuplotProjectionsFile->plotDistribution("MeanInputAssemblyDegree");
	meanGnuplotProjectionsFile->plotDistribution("MeanOutputAssemblyDegree");
		
	// Voisins
	meanGnuplotProjectionsFile->plotDistribution("MeanInputAssemblyNearestNeighboursDegree");
	meanGnuplotProjectionsFile->plotDistribution("MeanOutputAssemblyNearestNeighboursDegree");
			#endif
		#endif
	#endif

	#ifdef _GSCC_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
			#ifndef _LOAD_ORDERED_PROJECTIONS_MODE
	meanGnuplotProjectionsFile->plotOngoingAccumulater("NbGSCCNodes");
				#ifdef _3D_ONGOING_STAT_MODE
	meanGnuplotProjectionsFile->plotOngoingDistribution("SCComponentSize",getEvoIndex());
				#endif
				
	meanGnuplotProjectionsFile->plotOngoingAccumulater("MaxSCComponentSize");
				#ifdef _3D_ONGOING_STAT_MODE
	meanGnuplotProjectionsFile->plotOngoingDistribution("MaxSCComponentSize",getEvoIndex());
				#endif
			#endif
			
	//meanGnuplotProjectionsFile->plotMeanDistribution("MeanAssemblyDiameterSize");

		#else

	meanGnuplotProjectionsFile->plotMean("MeanNbGSCCNodes");
	meanGnuplotProjectionsFile->plotMeanDistribution("MeanSCComponentSize");

	meanGnuplotProjectionsFile->plotMean("MeanMaxSCComponentSize");
	meanGnuplotProjectionsFile->plotMeanDistribution("MeanMaxSCComponentSize");
	
			#ifdef _INPUT_OUTPUT_GSCC_STAT_MODE	
	meanGnuplotProjectionsFile->plotMeanDistribution("MeanInputSCComponentSize");
	meanGnuplotProjectionsFile->plotMeanDistribution("MeanOutputSCComponentSize");
	
	meanGnuplotProjectionsFile->plotRepartition("MeanInputSCCFraction");
	meanGnuplotProjectionsFile->plotRepartition("MeanOutputSCCFraction");
			#endif
		#endif
	#endif
	
	#ifdef _PROJECTION_STAT_MODE
	meanGnuplotProjectionsFile->plotMean("MeanProjections");
	
	// Excit/Inhib
	meanGnuplotProjectionsFile->plotMean("MeanExcitProjections");
	meanGnuplotProjectionsFile->plotMean("MeanInhibProjections");
	
	// Input
	meanGnuplotProjectionsFile->plotMean("MeanExcitInputProjections");
	meanGnuplotProjectionsFile->plotMean("MeanInhibInputProjections");
	
	// Output
	meanGnuplotProjectionsFile->plotMean("MeanExcitOutputProjections");
	meanGnuplotProjectionsFile->plotMean("MeanInhibOutputProjections");
	
	// Self
	meanGnuplotProjectionsFile->plotMean("MeanExcitSelfProjections");
	meanGnuplotProjectionsFile->plotMean("MeanInhibSelfProjections");
	#endif
	
	#ifdef _INPUT_OUTPUT_CLUSTER_STAT_MODE	
	meanGnuplotProjectionsFile->plotMeanDistribution("MaxModularityInputClusterSize");
	meanGnuplotProjectionsFile->plotMeanDistribution("MaxModularityOutputClusterSize");
	
	meanGnuplotProjectionsFile->plotRepartition("MaxModularityInputClusterFraction");
	meanGnuplotProjectionsFile->plotRepartition("MaxModularityOutputClusterFraction");
	#endif

}
#endif

// ClusterStater.cc

// Local Includes
#include "ClusterStater.h"

/****************************************************************************************************************************************/
/************************************************* Methodes de la classe ClusterStater ************************************************/
/****************************************************************************************************************************************/

ClusterStater::ClusterStater()
{
#ifdef _NETWORK_STAT_MODE
	#ifdef _CENTRALITY_STAT_MODE	
		#ifdef _EDGE_BETWEENNESS_STAT_MODE
			#ifdef _CLUSTER_STAT_MODE

	clusterEfficiency = new Accumulater();
	//clusterEfficiencyDistribution = new LogDistribution(-8,0,5);
	clusterEfficiencyDistribution = new LogDistribution(-2,0,5);

	clusterRealEfficiency = new Accumulater();
	//clusterLocalEfficiencyDistribution = new LogDistribution(-8,0,5);
	clusterRealEfficiencyDistribution = new LogDistribution(-2,0,5);

	clusterSizeDistribution = new Distribution(NB_ASSEMBLIES+NB_INPUT_ASSEMBLIES+NB_OUTPUT_ASSEMBLIES);
			#endif
			
		#endif
	#endif
	
	#ifdef _SMALL_WORLD_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
	clusterInternalDensity = new Accumulater();
	realClusterInternalDensity = new Accumulater();
		#endif
	#endif
	
	#ifdef _MOTIF_STAT_MODE
		#ifdef _INTERNAL_MOTIF_STAT_MODE
	internalBinodeMotifs = new Counter();
	internalTrinodeMotifsDistribution = new Distribution(14);
		#endif
	#endif
	
	#ifdef _INPUT_OUTPUT_CLUSTER_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
	inputClusterSizeDistribution = new Distribution(NB_ASSEMBLIES);
	outputClusterSizeDistribution = new Distribution(NB_ASSEMBLIES);	
		#endif
	#endif
#endif
}

ClusterStater::ClusterStater(IndexedObject* io) : AssemblyStater(io)
{
#ifdef _NETWORK_STAT_MODE
	#ifdef _CENTRALITY_STAT_MODE	
		#ifdef _EDGE_BETWEENNESS_STAT_MODE
			#ifdef _CLUSTER_STAT_MODE

	clusterEfficiency = new Accumulater();
	//clusterEfficiencyDistribution = new LogDistribution(-8,0,5);
	clusterEfficiencyDistribution = new LogDistribution(-2,0,5);
	
	clusterRealEfficiency = new Accumulater();
	//clusterLocalEfficiencyDistribution = new LogDistribution(-8,0,5);
	clusterRealEfficiencyDistribution = new LogDistribution(-2,0,5);
	
	clusterSizeDistribution = new Distribution(NB_ASSEMBLIES+NB_INPUT_ASSEMBLIES+NB_OUTPUT_ASSEMBLIES);
			#endif
			
		#endif
	#endif
	
	#ifdef _SMALL_WORLD_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
	clusterInternalDensity = new Accumulater();
	realClusterInternalDensity = new Accumulater();
		#endif
	#endif
	
	#ifdef _MOTIF_STAT_MODE
		#ifdef _INTERNAL_MOTIF_STAT_MODE
	internalBinodeMotifs = new Counter();
	internalTrinodeMotifsDistribution = new Distribution(14);
		#endif
	#endif
	
	#ifdef _INPUT_OUTPUT_CLUSTER_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
	inputClusterSizeDistribution = new Distribution(NB_ASSEMBLIES);
	outputClusterSizeDistribution = new Distribution(NB_ASSEMBLIES);	
		#endif
	#endif
	
	openTracer();
#endif
}

ClusterStater::~ClusterStater()
{
#ifdef _NETWORK_STAT_MODE

	cerr << "In ~ClusterStater" << endl;
	
	#ifdef _CENTRALITY_STAT_MODE
		#ifdef _EDGE_BETWEENNESS_STAT_MODE
			#ifdef _CLUSTER_STAT_MODE
	delete(clusterEfficiency);
	delete(clusterEfficiencyDistribution);
	
	delete(clusterRealEfficiency);
	delete(clusterRealEfficiencyDistribution);
	
	delete(clusterSizeDistribution);
			#endif

		#endif
	#endif

	#ifdef _SMALL_WORLD_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
	delete(clusterInternalDensity);
	delete(realClusterInternalDensity);
		#endif
	#endif

	#ifdef _MOTIF_STAT_MODE
		#ifdef _INTERNAL_MOTIF_STAT_MODE
	delete(internalBinodeMotifs);
	delete(internalTrinodeMotifsDistribution);
		#endif
	#endif
	
	#ifdef _INPUT_OUTPUT_CLUSTER_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
	delete(inputClusterSizeDistribution);
	delete(outputClusterSizeDistribution);
		#endif
	#endif
	closeTracer();

	openGrapher();
	graph();
	runGrapher();
	closeGrapher();
	
	
	cerr << "End of ~ClusterStater" << endl;
	
#endif
}

void ClusterStater::openTracer()
{
#ifdef _NETWORK_STAT_MODE
	
#endif
}

void ClusterStater::closeTracer()
{
#ifdef _NETWORK_STAT_MODE
	
#endif
}

void ClusterStater::openGrapher()
{
#ifdef _NETWORK_STAT_MODE

#endif
}

void ClusterStater::runGrapher()
{
#ifdef _NETWORK_STAT_MODE
	
#endif
}

void ClusterStater::closeGrapher()
{
#ifdef _NETWORK_STAT_MODE
	
#endif
}

/****************************************************************************************************************************************/
/******************************************************* Compteurs **************************************************************/
/****************************************************************************************************************************************/

void ClusterStater::initCounters()
{	
#ifdef _NETWORK_STAT_MODE
	#ifdef _CENTRALITY_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
	
	nbClusters=0;
	maxClusterSize=0;
	
	if (clusterSizeDistribution)
	{
		clusterSizeDistribution->initDistribution();
	}
	
	if (clusterEfficiency)
	{
		clusterEfficiency->initAccu();
	}
	
	if (clusterEfficiencyDistribution)
	{
		clusterEfficiencyDistribution->initDistribution();
	}
	
	if (clusterRealEfficiency)
	{
		clusterRealEfficiency->initAccu();
	}
	
	if (clusterRealEfficiencyDistribution)
	{
		clusterRealEfficiencyDistribution->initDistribution();
	}
	
	for (int i=0;i<NB_ASSEMBLIES;i++)
	{
		clusterEfficiencyRepartition[i] = - 1.0;
	}
	
	
		#endif
	#endif
#endif
}

void ClusterStater::flushCounters()
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

void ClusterStater::statClusterSize(Cluster* curCluster)
{
	int clusterSize = curCluster->getClusterSize();
	
	((Distribution*) clusterSizeDistribution)->count((int) clusterSize);
	
	if (maxClusterSize < clusterSize)
	{
		maxClusterSize = clusterSize;
	}

	nbClusters++;
}

void ClusterStater::computeEfficiency(Cluster* curCluster)
{
	std::vector<Assembly*>::iterator it = curCluster->clusterAssemblies.begin();
	std::vector<Assembly*>::iterator end = curCluster->clusterAssemblies.end();

	while( it != end)
	{
		
		if (((Assembly*) *it)->getIndex() < NB_ASSEMBLIES)
		{

			if (1 < curCluster->getClusterSize())
			{
				// Efficacité du noeud
				Accumulater* curClusterEfficiency = new Accumulater();
	
				for (int i=0;i<NB_ASSEMBLIES;i++)
				{
					if  (0.0 <= assemblyEfficiency[((Assembly*) *it)->getIndex()][i])
					{
						if (((Cluster*) curCluster)->isInCluster(i))
						{
							if (i != ((Assembly*) *it)->getIndex())
							{
								curClusterEfficiency->accumulate(assemblyEfficiency[((Assembly*) *it)->getIndex()][i]);
							}
						}
					}
				}
	
				
				clusterEfficiencyRepartition[((Assembly*) *it)->getIndex()] = curClusterEfficiency->getMean();
				
				delete(curClusterEfficiency);
			}
			else
			{
				clusterEfficiencyRepartition[((Assembly*) *it)->getIndex()] = -1.0;
			}
		}
		
		it++;
	}
}

void ClusterStater::computeClusterEfficiency()
{
	
	for (int i=0;i< NB_ASSEMBLIES;i++)
	{
		if (0.0 <= clusterEfficiencyRepartition[i])
		{
			clusterEfficiency->accumulate(clusterEfficiencyRepartition[i]);
			((LogDistribution*) clusterEfficiencyDistribution)->count((double) clusterEfficiencyRepartition[i]);
			
			clusterRealEfficiency->accumulate(clusterEfficiencyRepartition[i]);
			((LogDistribution*) clusterRealEfficiencyDistribution)->count((double) clusterEfficiencyRepartition[i]);
		}
		else
		{
			clusterRealEfficiency->accumulate(0.0);
			((LogDistribution*) clusterRealEfficiencyDistribution)->count(0.0);
		}
	}
}

void ClusterStater::initClusterModularity()
{
	clusterModularity = 0.0;
}

void ClusterStater::addClusterModularity(double curModularity)
{
	clusterModularity += curModularity;
}

double ClusterStater::getClusterModularity()
{
	return clusterModularity;
}
		#endif
	#endif

	#ifdef _LOOP_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
/*
void ClusterStater::initLoopCounters()
{
	nbLoopsCluster->initAccu();
	//meanClusterLoopSize = 0.0;
}
*/
void ClusterStater::statInternalLoops(Cluster* curCluster)
{
	std::vector<Assembly*>::iterator it = curCluster->clusterAssemblies.begin();
	std::vector<Assembly*>::iterator end = curCluster->clusterAssemblies.end();

	while (it != end)
	{
		//LoopStater::initTabNodes();
		initTabNodes();
		statDepthFirstPostProjections((Assembly*) *it,(Cluster*) curCluster);
		it++;
	}
}

void ClusterStater::statDepthFirstPostProjections(Assembly* postAssembly, Cluster* curCluster)
{
	if (((EDAssembly*) postAssembly)->getIndex() < NB_ASSEMBLIES)
	{
		if (marked[((EDAssembly*) postAssembly)->getIndex()] == BLANC)
		{
			addNode((Node*) postAssembly);

			std::vector<Link*>::iterator it = ((EDAssembly*) postAssembly)->getFirstOutputLink();
			std::vector<Link*>::iterator end = ((EDAssembly*) postAssembly)->getLastOutputLink();

			while (it!=end)
			{
				if (((Cluster*) curCluster)->isInCluster((Assembly*) postAssembly))
				{
					statDepthFirstPostProjections((Assembly*) ((Projection*) *it)->getPostNode(),(Cluster*) curCluster);
				}
				it++;
			}

			deleteLastNode();
		}
		else if (marked[((EDAssembly*) postAssembly)->getIndex()] == GRIS)
		{
			statLoop(postAssembly);
		}
	}
	/*
	else
	{
		cerr << "Assembly " << postAssembly->getIndex() << " is not an internal assembly" << endl;
	}
	*/
}
		#endif
	#endif

	#ifdef _SMALL_WORLD_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
void ClusterStater::initClusterInternalDensityCounters()
{
	clusterInternalDensity->initAccu();
	realClusterInternalDensity->initAccu();
}

void ClusterStater::statClusterInternalDensity(Cluster* curCluster)
{
	std::vector<Assembly*>::iterator it = curCluster->clusterAssemblies.begin();
	std::vector<Assembly*>::iterator end = curCluster->clusterAssemblies.end();

	int clusterSize = curCluster->clusterAssemblies.size();

	int nbInternalLinks = 0;

	while( it != end)
	{
		std::vector<Assembly*>::iterator it2 = curCluster->clusterAssemblies.begin();
		std::vector<Assembly*>::iterator end2 = curCluster->clusterAssemblies.end();

		while( it2 != end2)
		{
			if (!((Assembly*) *it)->isSameIndex(((Assembly*) *it2)))
			{
				if (((Assembly*) *it)->isOutputLinked(((Assembly*) *it2)))
				{
					nbInternalLinks++;
				}
			}
			it2++;
		}
		it++;
	}

	if (1 < clusterSize)
	{
		clusterInternalDensity->accumulate(((double) nbInternalLinks)/((double) clusterSize*(clusterSize-1)));
	}
	else
	{
		clusterInternalDensity->accumulate(0.0);
	}

	if (1 < clusterSize)
	{
		realClusterInternalDensity->accumulate(((double) nbInternalLinks)/((double) clusterSize*(clusterSize-1)));
	}
}
		#endif
	#endif
	
	#ifdef _MOTIF_STAT_MODE
		#ifdef _INTERNAL_MOTIF_STAT_MODE
void ClusterStater::initInternalMotifsCounters()
{
	if (internalBinodeMotifs)
	{
		internalBinodeMotifs->initCounter();
	}

	if (internalTrinodeMotifsDistribution)
	{
		internalTrinodeMotifsDistribution->initDistribution();
	}
}

void ClusterStater::statInternalMotifs(Cluster* curCluster)
{
			#ifdef _REDONDANT_MOTIF_STAT_MODE
	vector<Assembly*>::iterator itAss = curCluster->clusterAssemblies.begin();
	vector<Assembly*>::iterator endAss = curCluster->clusterAssemblies.end();
	
	while (itAss != endAss)
	{
		// 2 motifs
		std::vector<Link*>::iterator itPostBi = ((Node*) *itAss)->getFirstOutputLink();
		std::vector<Link*>::iterator endPostBi = ((Node*) *itAss)->getLastOutputLink();
	
		while (itPostBi != endPostBi)
		{
				
			Node* postNode = (Node*) ((Link*) *itPostBi)->getPostNode();
			
				#ifdef _TEST_STAT
			cerr << "Binode Motifs for assembly " << ((Node*) *itAss)->getIndex();
			cerr << " and post assembly " << ((Node*) postNode)->getIndex() << endl;
				#endif
			
			if (!((Node*) postNode)->isSameIndex((Node*) *itAss))
			{
				if (((Cluster*) curCluster)->isInCluster((Assembly*) postNode))
				{	
				#ifdef _TEST_STAT
					cerr << "Binode: In cluster " << endl;
				#endif
				
					if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
					{
				#ifdef _TEST_STAT
						cerr << "Binode: count internal motif " << endl;
				#endif
						
						internalBinodeMotifs->count();
					}
				}
			}	
			itPostBi++;
		}
		
				#ifdef _TEST_STAT
		cerr << "Trinode Motifs for assembly " << ((Node*) *itAss)->getIndex() << endl;
				#endif
		
		// Trois motifs
		// Index basé sur (Sporns et Kotter,2004)
		std::vector<Link*>::iterator itPostTri = ((Node*) *itAss)->getFirstOutputLink();
		std::vector<Link*>::iterator endPostTri = ((Node*) *itAss)->getLastOutputLink();
	
		while (itPostTri != endPostTri)
		{
			Node* postNode = ((Link*) *itPostTri)->getPostNode();
			
				#ifdef _TEST_STAT
			cerr << "Trinode Motifs for assembly " << ((Node*) *itAss)->getIndex();
			cerr << " and post assembly " << ((Node*) postNode)->getIndex() << endl;
				#endif
		
				#ifdef _TEST_STAT
			cerr << "Motifs with outputLinks of postNode" << endl;
				#endif
				
			if (!((Node*) postNode)->isSameIndex((Node*) *itAss))
			{
				if (((Cluster*) curCluster)->isInCluster((Assembly*) postNode))
				{
					
				#ifdef _TEST_STAT
					cerr << "Trinode: in cluster" << endl;
				#endif
					
					// A partir de l'assemblée post
					std::vector<Link*>::iterator itPre = ((Node*) postNode)->getFirstInputLink();
					std::vector<Link*>::iterator endPre = ((Node*) postNode)->getLastInputLink();
			
					while (itPre != endPre)
					{
						Node* preToPostNode = (Node*) ((Link*) *itPre)->getPreNode();
						
						if (!((Node*) preToPostNode)->isSameIndex((Node*) postNode))
						{
							if (((Cluster*) curCluster)->isInCluster((Assembly*) preToPostNode))
							{
				#ifdef _TEST_STAT
								cerr << "Trinode Motifs for assembly " << ((Node*) *itAss)->getIndex();
								cerr << ", post assembly " << ((Node*) postNode)->getIndex();
								cerr << " and pre-to-post assembly " << ((Node*) preToPostNode)->getIndex() << endl;
				#endif
								if (!((Node*) preToPostNode)->isSameIndex((Node*) *itAss))
								{
									// Convergence
									// 2 liens
									internalTrinodeMotifsDistribution->count((int) 1);
					
									if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
									{
										// Bidir/Convergence 4a
										// 3 liens
										internalTrinodeMotifsDistribution->count((int) 4);
					
										if (((Node*) postNode)->isOutputLinked((Node*) preToPostNode))
										{
											// Bidir+Bidir 9a
											// 4 liens
											internalTrinodeMotifsDistribution->count((int) 9);
											
											if (((Node*) *itAss)->isOutputLinked((Node*) preToPostNode))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) preToPostNode)->isOutputLinked((Node*) *itAss))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
											
											if (((Node*) preToPostNode)->isOutputLinked((Node*) *itAss))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) *itAss)->isOutputLinked((Node*) preToPostNode))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
										}
					
										if (((Node*) *itAss)->isOutputLinked((Node*) preToPostNode))
										{
											// Bidir+Bidir 10a
											// 4 liens
											internalTrinodeMotifsDistribution->count((int) 10);
											
											if (((Node*) postNode)->isOutputLinked((Node*) preToPostNode))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) preToPostNode)->isOutputLinked((Node*) *itAss))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
											
											if (((Node*) preToPostNode)->isOutputLinked((Node*) *itAss))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode)->isOutputLinked((Node*) preToPostNode))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
										}
					
										if (((Node*) preToPostNode)->isOutputLinked((Node*) *itAss))
										{
											// Bidir+Div 8a
											// 4 liens
											internalTrinodeMotifsDistribution->count((int) 8);
											
											if (((Node*) postNode)->isOutputLinked((Node*) preToPostNode))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) *itAss)->isOutputLinked((Node*) preToPostNode))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
											
											if (((Node*) *itAss)->isOutputLinked((Node*) preToPostNode))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode)->isOutputLinked((Node*) preToPostNode))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
										}
									}
					
									if (((Node*) postNode)->isOutputLinked((Node*) preToPostNode))
									{
										// Bidir/Convergence 4c
										// 3 liens
										internalTrinodeMotifsDistribution->count((int) 4);
					
										if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
										{
											// Bidir+Bidir 9a
											// 4 liens
											internalTrinodeMotifsDistribution->count((int) 9);
											
											if (((Node*) preToPostNode)->isOutputLinked((Node*) *itAss))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) *itAss)->isOutputLinked((Node*) preToPostNode))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
											
											if (((Node*) *itAss)->isOutputLinked((Node*) preToPostNode))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) preToPostNode)->isOutputLinked((Node*) *itAss))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
										}
					
										if (((Node*) preToPostNode)->isOutputLinked((Node*) *itAss))
										{
											// Bidir+Cont 10d
											// 4 liens
											internalTrinodeMotifsDistribution->count((int) 10);
											
											if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) *itAss)->isOutputLinked((Node*) preToPostNode))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
											
											if (((Node*) *itAss)->isOutputLinked((Node*) preToPostNode))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
										}
					
										if (((Node*) *itAss)->isOutputLinked((Node*) preToPostNode))
										{
											// Bidir+Div 8b
											// 4 liens
											internalTrinodeMotifsDistribution->count((int) 8);
											
											if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) preToPostNode)->isOutputLinked((Node*) *itAss))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
											
											if (((Node*) preToPostNode)->isOutputLinked((Node*) *itAss))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
										}
									}
					
									if (((Node*) *itAss)->isOutputLinked((Node*) preToPostNode))
									{
										// Feedforward Loop (Cut/ByPass) 5b
										// 3 liens
										internalTrinodeMotifsDistribution->count((int) 5);
					
										if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
										{
											// Bidir+Cont 10a
											// 4 liens
											internalTrinodeMotifsDistribution->count((int) 10);
											
											if (((Node*) postNode)->isOutputLinked((Node*) preToPostNode))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) preToPostNode)->isOutputLinked((Node*) *itAss))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
											
											if (((Node*) preToPostNode)->isOutputLinked((Node*) *itAss))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode)->isOutputLinked((Node*) preToPostNode))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
										}
					
										if (((Node*) postNode)->isOutputLinked((Node*) preToPostNode))
										{
											// Bidir+Div 8b
											// 4 liens
											internalTrinodeMotifsDistribution->count((int) 8);
											
											if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) preToPostNode)->isOutputLinked((Node*) *itAss))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
											
											if (((Node*) preToPostNode)->isOutputLinked((Node*) *itAss))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
										}
					
										if (((Node*) preToPostNode)->isOutputLinked((Node*) *itAss))
										{
											// Bidir+Conv 11a
											// 4 liens
											internalTrinodeMotifsDistribution->count((int) 11);
											
											if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode)->isOutputLinked((Node*) preToPostNode))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
											
											if (((Node*) postNode)->isOutputLinked((Node*) preToPostNode))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
										}
									}
					
									if (((Node*) preToPostNode)->isOutputLinked((Node*) *itAss))
									{
										// Feedforward Loop (Cut/ByPass) 5a
										// 3 liens
										internalTrinodeMotifsDistribution->count((int) 5);
					
										if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
										{
											// Bidir+Div 8a
											// 4 liens
											internalTrinodeMotifsDistribution->count((int) 8);
											
											if (((Node*) *itAss)->isOutputLinked((Node*) preToPostNode))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode)->isOutputLinked((Node*) preToPostNode))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
											
											if (((Node*) postNode)->isOutputLinked((Node*) preToPostNode))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) *itAss)->isOutputLinked((Node*) preToPostNode) )
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
										}
					
										if (((Node*) postNode)->isOutputLinked((Node*) preToPostNode))
										{
											// Bidir+Cont 10d
											// 4 liens
											internalTrinodeMotifsDistribution->count((int) 10);
											
											if (((Node*) *itAss)->isOutputLinked((Node*) preToPostNode))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
											
											if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) *itAss)->isOutputLinked((Node*) preToPostNode) )
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
										}
					
										if (((Node*) *itAss)->isOutputLinked((Node*) preToPostNode))
										{
											// Bidir+Conv 11a
											// 4 liens
											internalTrinodeMotifsDistribution->count((int) 11);
											
											if (((Node*) postNode)->isOutputLinked((Node*) preToPostNode))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
											
											if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode)->isOutputLinked((Node*) preToPostNode))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
										}
									}
								}
								else
								{
				#ifdef _TEST_STAT
									cerr << "preToPost and cur have same index" << endl;
				#endif
								}
							}
						}
						itPre++;
					}
					
				#ifdef _TEST_STAT
					cerr << "Motifs with inputLinks of *itAss";
					cerr << " (*itAss has " << ((Node*) *itAss)->getNbInputLinks() << ")" << endl;
				#endif
					
					// A partir de l'assemblée courante
					std::vector<Link*>::iterator itPre2 = ((Node*) *itAss)->getFirstInputLink();
					std::vector<Link*>::iterator endPre2 = ((Node*) *itAss)->getLastInputLink();
			
					while (itPre2 != endPre2)
					{
						Node* preNode = (Node*) ((Link*) *itPre2)->getPreNode();
						
						if (!((Node*) preNode)->isSameIndex((Node*) *itAss))
						{
							if (((Cluster*) curCluster)->isInCluster((Assembly*) preNode))
							{
				#ifdef _TEST_STAT
								cerr << "Trinode Motifs for assembly " << ((Node*) *itAss)->getIndex();
								cerr << ", post assembly " << ((Node*) postNode)->getIndex();
								cerr << " and pre assembly " << ((Node*) preNode)->getIndex() << endl;
				#endif
								if (!((Node*) preNode)->isSameIndex((Node*) postNode))
								{
									// Continued 2a
									// 2 liens
									internalTrinodeMotifsDistribution->count((int) 2);
					
									if (((Node*) postNode)->isOutputLinked((Node*) preNode))
									{
										// Loop 7
										// 3 liens
										internalTrinodeMotifsDistribution->count((int) 7);
					
										if (((Node*) preNode)->isOutputLinked((Node*) postNode))
										{
											// Bidir+Cont 10d
											// 4 liens
											internalTrinodeMotifsDistribution->count((int) 10);
											
											if (((Node*) *itAss)->isOutputLinked((Node*) preNode))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
											
											if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) *itAss)->isOutputLinked((Node*) preNode))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
										}
					
										if (((Node*) *itAss)->isOutputLinked((Node*) preNode))
										{
											// Bidir+Cont 10c
											// 4 liens
											internalTrinodeMotifsDistribution->count((int) 10);
											
											if (((Node*) preNode)->isOutputLinked((Node*) postNode))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
											
											if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) preNode)->isOutputLinked((Node*) postNode))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
										}
					
										if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
										{
											// Bidir+Cont 10b
											// 4 liens
											internalTrinodeMotifsDistribution->count((int) 10);
											
											if (((Node*) preNode)->isOutputLinked((Node*) postNode))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) *itAss)->isOutputLinked((Node*) preNode))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
											
											if (((Node*) *itAss)->isOutputLinked((Node*) preNode))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) preNode)->isOutputLinked((Node*) postNode))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
										}
									}
					
									if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
									{
										// Bidir/Conv 4b
										// 3 liens
										internalTrinodeMotifsDistribution->count((int) 4);
					
										if (((Node*) *itAss)->isOutputLinked((Node*) preNode))
										{
											// Bidir+Bidir 9b
											// 4 liens
											internalTrinodeMotifsDistribution->count((int) 9);
											
											if (((Node*) preNode)->isOutputLinked((Node*) postNode))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode)->isOutputLinked((Node*) preNode))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
											
											if (((Node*) postNode)->isOutputLinked((Node*) preNode))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) preNode)->isOutputLinked((Node*) postNode))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
										}
					
										if (((Node*) preNode)->isOutputLinked((Node*) postNode))
										{
											// Bidir+Div 8a
											// 4 liens
											internalTrinodeMotifsDistribution->count((int) 8);
											
											if (((Node*) *itAss)->isOutputLinked((Node*) preNode))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode)->isOutputLinked((Node*) preNode))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
											
											if (((Node*) postNode)->isOutputLinked((Node*) preNode))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) *itAss)->isOutputLinked((Node*) preNode))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
										}
					
										if (((Node*) postNode)->isOutputLinked((Node*) preNode))
										{
											// Bidir+Cont 10b
											// 4 liens
											internalTrinodeMotifsDistribution->count((int) 10);
											
											if (((Node*) *itAss)->isOutputLinked((Node*) preNode))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) preNode)->isOutputLinked((Node*) postNode))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
											
											if (((Node*) preNode)->isOutputLinked((Node*) postNode))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) *itAss)->isOutputLinked((Node*) preNode))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
										}
									}
					
									if (((Node*) preNode)->isOutputLinked((Node*) postNode))
									{
										// Feedforward Loop (Cut/ByPass) 5a
										// 3 liens
										internalTrinodeMotifsDistribution->count((int) 5);
					
										if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
										{
											// Bidir+Div 8a
											// 4 liens
											internalTrinodeMotifsDistribution->count((int) 8);
											
											if (((Node*) *itAss)->isOutputLinked((Node*) preNode))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode)->isOutputLinked((Node*) preNode))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
											
											if (((Node*) postNode)->isOutputLinked((Node*) preNode))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) *itAss)->isOutputLinked((Node*) preNode))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
										}
					
										if (((Node*) postNode)->isOutputLinked((Node*) preNode))
										{
											// Bidir+Cont 10d
											// 4 liens
											internalTrinodeMotifsDistribution->count((int) 10);
											
											if (((Node*) *itAss)->isOutputLinked((Node*) preNode))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
											
											if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) *itAss)->isOutputLinked((Node*) preNode))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
										}
					
										if (((Node*) *itAss)->isOutputLinked((Node*) preNode))
										{
											// Bidir+Conv 11a
											// 4 liens
											internalTrinodeMotifsDistribution->count((int) 11);
											
											if (((Node*) postNode)->isOutputLinked((Node*) preNode))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
											
											if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode)->isOutputLinked((Node*) preNode))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
										}
									}
					
									if (((Node*) *itAss)->isOutputLinked((Node*) preNode))
									{
										// Bidir/Div 6b
										// 3 liens
										internalTrinodeMotifsDistribution->count((int) 6);
					
										if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
										{
											// Bidir+Bidir 9b
											// 4 liens
											internalTrinodeMotifsDistribution->count((int) 9);
											
											if (((Node*) postNode)->isOutputLinked((Node*) preNode))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) preNode)->isOutputLinked((Node*) postNode))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
											
											if (((Node*) preNode)->isOutputLinked((Node*) postNode))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode)->isOutputLinked((Node*) preNode))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
										}
					
										if (((Node*) postNode)->isOutputLinked((Node*) preNode))
										{
											// Bidir+Cont 10c
											// 4 liens
											internalTrinodeMotifsDistribution->count((int) 10);
											
											if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) preNode)->isOutputLinked((Node*) postNode))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
											
											if (((Node*) preNode)->isOutputLinked((Node*) postNode))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
										}
					
										if (((Node*) preNode)->isOutputLinked((Node*) postNode))
										{
											// Bidir+Conv 11a
											// 4 liens
											internalTrinodeMotifsDistribution->count((int) 11);
											
											if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode)->isOutputLinked((Node*) preNode))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
											
											if (((Node*) postNode)->isOutputLinked((Node*) preNode))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
										}
					
									}
								}
							}
						}
						itPre2++;
					}
				#ifdef _TEST_STAT
					cerr << "Motifs with outputLinks of *itAss" << endl;
				#endif
					
					std::vector<Link*>::iterator itPost2 = ((Node*) *itAss)->getFirstOutputLink();
					std::vector<Link*>::iterator endPost2 = ((Node*) *itAss)->getLastOutputLink();
			
					while (itPost2 != endPost2)
					{
						Node* postNode2 = (Node*) ((Link*) *itPost2)->getPostNode();
						
						if (!((Node*) postNode2)->isSameIndex((Node*) *itAss))
						{
							if (((Cluster*) curCluster)->isInCluster((Assembly*) postNode2))
							{
				#ifdef _TEST_STAT
								cerr << "Trinode Motifs for assembly " << ((Node*) *itAss)->getIndex();
								cerr << ", post assembly " << ((Node*) postNode)->getIndex();
								cerr << " and post assembly2 " << ((Node*) postNode2)->getIndex() << endl;
				#endif
								if (!((Node*) postNode2)->isSameIndex((Node*) postNode))
								{
									// Divergence
									// 2 liens
									internalTrinodeMotifsDistribution->count((int) 3);
					
									if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
									{
										// Bidir/Div 6c
										// 3 liens
										internalTrinodeMotifsDistribution->count((int) 6);
					
										if (((Node*) postNode)->isOutputLinked((Node*) postNode2))
										{
											// Bidir+Conv 11b
											// 4 liens
											internalTrinodeMotifsDistribution->count((int) 11);
											
											if (((Node*) postNode2)->isOutputLinked((Node*) postNode))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode2)->isOutputLinked((Node*) *itAss))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
											
											if (((Node*) postNode2)->isOutputLinked((Node*) *itAss))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode2)->isOutputLinked((Node*) postNode))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
										}
					
										if (((Node*) postNode2)->isOutputLinked((Node*) postNode))
										{
											// Bidir+Cont 10a
											// 4 liens
											internalTrinodeMotifsDistribution->count((int) 10);
											
											if (((Node*) postNode)->isOutputLinked((Node*) postNode2))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode2)->isOutputLinked((Node*) *itAss))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
											
											if (((Node*) postNode2)->isOutputLinked((Node*) *itAss))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode)->isOutputLinked((Node*) postNode2))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
										}
					
										if (((Node*) postNode2)->isOutputLinked((Node*) *itAss))
										{
											// Bidir+Bidir 9b
											// 4 liens
											internalTrinodeMotifsDistribution->count((int) 9);
												
											if (((Node*) postNode)->isOutputLinked((Node*) postNode2))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode2)->isOutputLinked((Node*) postNode))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
											
											if (((Node*) postNode2)->isOutputLinked((Node*) postNode))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode)->isOutputLinked((Node*) postNode2))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
										}
									}
					
									if (((Node*) postNode2)->isOutputLinked((Node*) *itAss))
									{
										// Bidir/Div 6b
										// 3 liens
										internalTrinodeMotifsDistribution->count((int) 6);
					
										if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
										{
											// Bidir+Bidir 9b
											// 4 liens
											internalTrinodeMotifsDistribution->count((int) 9);
												
											if (((Node*) postNode)->isOutputLinked((Node*) postNode2))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode2)->isOutputLinked((Node*) postNode))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
											
											if (((Node*) postNode2)->isOutputLinked((Node*) postNode))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode)->isOutputLinked((Node*) postNode2))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
										}
					
										if (((Node*) postNode)->isOutputLinked((Node*) postNode2))
										{
											// Bidir+Cont 10c
											// 4 liens
											internalTrinodeMotifsDistribution->count((int) 10);
												
											if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode2)->isOutputLinked((Node*) postNode))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
											
											if (((Node*) postNode2)->isOutputLinked((Node*) postNode))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
										}
					
										if (((Node*) postNode2)->isOutputLinked((Node*) postNode))
										{
											// Bidir+Conv 11a
											// 4 liens
											internalTrinodeMotifsDistribution->count((int) 11);
												
											if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode)->isOutputLinked((Node*) postNode2))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
											
											if (((Node*) postNode)->isOutputLinked((Node*) postNode2))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
										}
									}
					
									if (((Node*) postNode)->isOutputLinked((Node*) postNode2))
									{
										// Feedforward Loop (Cut/ByPass) 5c
										// 3 liens
										internalTrinodeMotifsDistribution->count((int) 5);
					
										if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
										{
											// Bidir+Conv 11b
											// 4 liens
											internalTrinodeMotifsDistribution->count((int) 11);
												
											if (((Node*) postNode2)->isOutputLinked((Node*) *itAss))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode2)->isOutputLinked((Node*) postNode))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
											
											if (((Node*) postNode2)->isOutputLinked((Node*) postNode))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode2)->isOutputLinked((Node*) *itAss))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
										}
					
										if (((Node*) postNode2)->isOutputLinked((Node*) postNode))
										{
											// Bidir+Div 8b
											//4 liens
											internalTrinodeMotifsDistribution->count((int) 8);
											
											if (((Node*) postNode2)->isOutputLinked((Node*) *itAss))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
											
											if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode2)->isOutputLinked((Node*) *itAss))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
										}
					
										if (((Node*) postNode2)->isOutputLinked((Node*) *itAss))
										{
											// Bidir+Cont 10c
											// 4 liens
											internalTrinodeMotifsDistribution->count((int) 10);
											
											if (((Node*) postNode2)->isOutputLinked((Node*) postNode))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
											
											if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode2)->isOutputLinked((Node*) postNode))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
										}
									}
					
									if (((Node*) postNode2)->isOutputLinked((Node*) postNode))
									{
										// Feedforward Loop (Cut/ByPass) 5b
										// 3 liens
										internalTrinodeMotifsDistribution->count((int) 5);
					
										if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
										{
											// Bidir+Cont 10a
											// 4 liens
											internalTrinodeMotifsDistribution->count((int) 10);
											
											if (((Node*) postNode2)->isOutputLinked((Node*) *itAss))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode)->isOutputLinked((Node*) postNode2))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
											
											if (((Node*) postNode)->isOutputLinked((Node*) postNode2))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode2)->isOutputLinked((Node*) *itAss))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
										}
					
										if (((Node*) postNode)->isOutputLinked((Node*) postNode2))
										{
											// Bidir+Div 8b
											// 4 liens
											internalTrinodeMotifsDistribution->count((int) 8);
											
											if (((Node*) postNode2)->isOutputLinked((Node*) *itAss))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
											
											if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode2)->isOutputLinked((Node*) *itAss))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
										}
					
										if (((Node*) postNode2)->isOutputLinked((Node*) *itAss))
										{
											// Bidir+Conv 11a
											// 4 liens
											internalTrinodeMotifsDistribution->count((int) 11);
											
											if (((Node*) postNode)->isOutputLinked((Node*) postNode2))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
											
											if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
											{
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
												
												if (((Node*) postNode)->isOutputLinked((Node*) postNode2))
												{
													// Bidir+Bidir+Bidir 13
													// 5 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
										}
									}
								}
							}
						}
						itPost2++;
					}
				}
			}
			itPostTri++;
		}
		itAss++;
	}
}
			#else

	vector<Assembly*>::iterator itAss = curCluster->clusterAssemblies.begin();
	vector<Assembly*>::iterator endAss = curCluster->clusterAssemblies.end();
	
	while (itAss != endAss)
	{
		// 2 motifs
		std::vector<Link*>::iterator itPostBi = ((Node*) *itAss)->getFirstOutputLink();
		std::vector<Link*>::iterator endPostBi = ((Node*) *itAss)->getLastOutputLink();
	
		while (itPostBi != endPostBi)
		{
				
			Node* postNode = (Node*) ((Link*) *itPostBi)->getPostNode();
			
			#ifdef _TEST_STAT
			cerr << "Binode Motifs for assembly " << ((Node*) *itAss)->getIndex();
			cerr << " and post assembly " << ((Node*) postNode)->getIndex() << endl;
			#endif
			
			if (!((Node*) postNode)->isSameIndex((Node*) *itAss))
			{
				if (((Cluster*) curCluster)->isInCluster((Assembly*) postNode))
				{	
			#ifdef _TEST_STAT
					cerr << "Binode: In cluster " << endl;
			#endif
				
					if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
					{
			#ifdef _TEST_STAT
						cerr << "Binode: count internal motif " << endl;
			#endif
						
						internalBinodeMotifs->count();
					}
				}
			}	
			itPostBi++;
		}
	
		// Trois motifs
		// Index basé sur (Sporns et Kotter,2004)
		std::vector<Link*>::iterator itPostTri = ((Node*) *itAss)->getFirstOutputLink();
		std::vector<Link*>::iterator endPostTri = ((Node*) *itAss)->getLastOutputLink();
	
		while (itPostTri != endPostTri)
		{
			Node* postNode = ((Link*) *itPostTri)->getPostNode();
		
			if (!((Node*) postNode)->isSameIndex((Node*) *itAss))
			{
				if (((Cluster*) curCluster)->isInCluster((Assembly*) postNode))
				{
			#ifdef _TEST_STAT
					cout << "Trinode Motifs for assembly " << ((Node*) *itAss)->getIndex();
					cout << " and post assembly " << ((Node*) postNode)->getIndex() << endl;
			#endif
			
			#ifdef _TEST_STAT
					cout << "Motifs with outputLinks of postNode" << endl;
			#endif
			
					// A partir de l'assemblée post
					std::vector<Link*>::iterator itPre = ((Node*) postNode)->getFirstInputLink();
					std::vector<Link*>::iterator endPre = ((Node*) postNode)->getLastInputLink();
			
					while (itPre != endPre)
					{
						Node* preToPostNode = (Node*) ((Link*) *itPre)->getPreNode();
						
						if (!((Node*) postNode)->isSameIndex((Node*) preToPostNode))
						{
							if (((Cluster*) curCluster)->isInCluster((Assembly*) preToPostNode))
							{
			#ifdef _TEST_STAT
								cout << "Trinode Motifs for assembly " << ((Node*) *itAss)->getIndex();
								cout << ", post assembly " << ((Node*) postNode)->getIndex();
								cout << " and pre-to-post assembly " << ((Node*) preToPostNode)->getIndex() << endl;
			#endif
								if (!((Node*) preToPostNode)->isSameIndex((Node*) *itAss))
								{
			#ifdef _TEST_STAT
									cout << "ClusterStater: Trinode 1" << endl;
			#endif		
									// Convergence
									// 2 liens
									internalTrinodeMotifsDistribution->count((int) 1);
					
									if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
									{
			#ifdef _TEST_STAT
										cout << "ClusterStater: Trinode 4" << endl;
			#endif		
										// Bidir/Convergence 4a
										// 3 liens
										internalTrinodeMotifsDistribution->count((int) 4);
					
										if (((Node*) postNode)->isOutputLinked((Node*) preToPostNode))
										{
			#ifdef _TEST_STAT
											cout << "ClusterStater: Trinode 9" << endl;
			#endif		
											// Bidir+Bidir 9a
											// 4 liens
											internalTrinodeMotifsDistribution->count((int) 9);
										}
					
										if (((Node*) *itAss)->isOutputLinked((Node*) preToPostNode))
										{
			#ifdef _TEST_STAT
											cout << "ClusterStater: Trinode 10" << endl;
			#endif		
											// Bidir+Bidir 10a
											// 4 liens
											internalTrinodeMotifsDistribution->count((int) 10);
										}
					
										if (((Node*) preToPostNode)->isOutputLinked((Node*) *itAss))
										{
			#ifdef _TEST_STAT
											cout << "ClusterStater: Trinode 8" << endl;
			#endif		
											// Bidir+Div 8a
											// 4 liens
											internalTrinodeMotifsDistribution->count((int) 8);
										}
									}
					
									if (((Node*) *itAss)->isOutputLinked((Node*) preToPostNode))
									{
			#ifdef _TEST_STAT
										cout << "ClusterStater: Trinode 5" << endl;
			#endif		
										// Feedforward Loop (Cut/ByPass) 5b
										// 3 liens
										internalTrinodeMotifsDistribution->count((int) 5);
					
										if (((Node*) preToPostNode)->isOutputLinked((Node*) *itAss))
										{
			#ifdef _TEST_STAT
											cout << "ClusterStater: Trinode 11" << endl;
			#endif		
											// Bidir+Conv 11a
											// 4 liens
											internalTrinodeMotifsDistribution->count((int) 11);
					
											if (((Node*) postNode)->isOutputLinked((Node*) *itAss))
											{
			#ifdef _TEST_STAT
												cout << "ClusterStater: Trinode 12" << endl;
			#endif		
												// Bidir+Bidir+link 12
												// 5 liens
												internalTrinodeMotifsDistribution->count((int) 12);
					
												if (((Node*) postNode)->isOutputLinked((Node*) preToPostNode))
												{
			#ifdef _TEST_STAT
													cout << "ClusterStater: Trinode 13" << endl;
			#endif		
													// Full 13
													// 6 liens
													internalTrinodeMotifsDistribution->count((int) 13);
												}
											}
										}
									}
								}
								else
								{
			#ifdef _TEST_STAT
									cout << "preToPost and cur have same index" << endl;
			#endif
								}
							}
						}
						itPre++;
					}
			#ifdef _TEST_STAT
					cout << "Motifs with inputLinks of *itAss";
					cout << " (*itAss has " << ((Node*) *itAss)->getNbInputLinks() << ")" << endl;
			#endif
			
					// A partir de l'assemblée courante
					std::vector<Link*>::iterator itPre2 = ((Node*) *itAss)->getFirstInputLink();
					std::vector<Link*>::iterator endPre2 = ((Node*) *itAss)->getLastInputLink();
			
					while (itPre2 != endPre2)
					{
						Node* preNode = (Node*) ((Link*) *itPre2)->getPreNode();
						
						if (!((Node*) preNode)->isSameIndex((Node*) *itAss))
						{
							if (((Cluster*) curCluster)->isInCluster((Assembly*) preNode))
							{
			#ifdef _TEST_STAT
								cout << "Trinode Motifs for assembly " << ((Node*) *itAss)->getIndex();
								cout << ", post assembly " << ((Node*) postNode)->getIndex();
								cout << " and pre assembly " << ((Node*) preNode)->getIndex() << endl;
			#endif
								if (!((Node*) preNode)->isSameIndex((Node*) postNode))
								{
			#ifdef _TEST_STAT
									cout << "ClusterStater: Trinode 2" << endl;
			#endif		
									// Continued 2a
									// 2 liens
									internalTrinodeMotifsDistribution->count((int) 2);
					
									if (((Node*) postNode)->isOutputLinked((Node*) preNode))
									{
			#ifdef _TEST_STAT
										cout << "ClusterStater: Trinode 7" << endl;
			#endif	
										// Loop 7
										// 3 liens
										internalTrinodeMotifsDistribution->count((int) 7);
									}
					
									if (((Node*) *itAss)->isOutputLinked((Node*) preNode))
									{
			#ifdef _TEST_STAT
										cout << "ClusterStater: Trinode 6" << endl;
			#endif
										// Bidir/Div 6b
										// 3 liens
										internalTrinodeMotifsDistribution->count((int) 6);
									}
								}
							}
						}
			
						itPre2++;
					}
			#ifdef _TEST_STAT
					cout << "Motifs with outputLinks of *itAss" << endl;
			#endif
			
					std::vector<Link*>::iterator itPost2 = ((Node*) *itAss)->getFirstOutputLink();
					std::vector<Link*>::iterator endPost2 = ((Node*) *itAss)->getLastOutputLink();
			
					while (itPost2 != endPost2)
					{
						Node* postNode2 = (Node*) ((Link*) *itPost2)->getPostNode();
						
						if (!((Node*) postNode2)->isSameIndex((Node*) *itAss))
						{
							if (((Cluster*) curCluster)->isInCluster((Assembly*) postNode2))
							{
			#ifdef _TEST_STAT
								cout << "Trinode Motifs for assembly " << ((Node*) *itAss)->getIndex();
								cout << ", post assembly " << ((Node*) postNode)->getIndex();
								cout << " and post assembly2 " << ((Node*) postNode2)->getIndex() << endl;
			#endif
								if (!((Node*) postNode2)->isSameIndex((Node*) postNode))
								{
			#ifdef _TEST_STAT
									cout << "ClusterStater: Trinode 3" << endl;
			#endif
									// Divergence
									// 2 liens
									internalTrinodeMotifsDistribution->count((int) 3);
								}
							}
						}
						itPost2++;
					}
				}
			}
			itPostTri++;
		}
		itAss++;
	}
			#endif
		#endif
	#endif
#endif

	#ifdef _INPUT_OUTPUT_CLUSTER_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
void ClusterStater::initInputOutputCounters()
{
	if (inputClusterSizeDistribution)
	{
		inputClusterSizeDistribution->initDistribution();
	}
	
	if (outputClusterSizeDistribution)
	{
		outputClusterSizeDistribution->initDistribution();
	}
}

void ClusterStater::initNbProjections()
{
	nbLinkedProjections = 0;
}

void ClusterStater::statInputClusters(Assembly* curInputAssembly,Cluster* curCluster)
{
	std::vector<Link*>::iterator it = ((EDAssembly*) curInputAssembly)->getFirstOutputLink();
	std::vector<Link*>::iterator end = ((EDAssembly*) curInputAssembly)->getLastOutputLink();

	while (it!=end)
	{
		Node* postAssembly = ((Link*) *it)->getPostNode();
		
		if (((Cluster*) curCluster)->isInCluster((Assembly*) postAssembly) && (1 < curCluster->getClusterSize()))
		{
			inputClusterSizeDistribution->count((int) curCluster->getClusterSize());
			nbLinkedProjections++;
		}
		it++;
	}

}

void ClusterStater::statNbInputProjections(int inputAssemblyIndex, int degree)
{
	if (0 <= inputAssemblyIndex && inputAssemblyIndex < NB_INPUT_ASSEMBLIES)
	{
		if (degree != 0)
		{
			inputClusterFractionRepartition[inputAssemblyIndex] = ((double) nbLinkedProjections)/((double) degree);
		}
		else if (degree == 0)
		{
			inputClusterFractionRepartition[inputAssemblyIndex] = 0;
		}
		else
		{
			cerr << "Warning, degree cannot be null and not nbLinkedProjections" << endl;
		}
	}
}

void ClusterStater::statOutputClusters(Assembly* curOutputAssembly,Cluster* curCluster)
{
	std::vector<Link*>::iterator it = ((EDAssembly*) curOutputAssembly)->getFirstInputLink();
	std::vector<Link*>::iterator end = ((EDAssembly*) curOutputAssembly)->getLastInputLink();

	while (it!=end)
	{
		Node* preAssembly = ((Link*) *it)->getPreNode();
		
		if (((Cluster*) curCluster)->isInCluster((Assembly*) preAssembly) && (1 < curCluster->getClusterSize()))
		{
			outputClusterSizeDistribution->count((int) curCluster->getClusterSize());
			nbLinkedProjections++;
		}
		it++;
	}

}

void ClusterStater::statNbOutputProjections(int outputAssemblyIndex, int degree)
{
	if (0 <= outputAssemblyIndex && outputAssemblyIndex < NB_OUTPUT_ASSEMBLIES)
	{
		if (degree != 0)
		{
			outputClusterFractionRepartition[outputAssemblyIndex] = ((double) nbLinkedProjections)/((double) degree);
		}
		else if (degree == 0)
		{
			outputClusterFractionRepartition[outputAssemblyIndex] = 0;
		}
		else
		{
			cerr << "Warning, degree cannot be null and not nbLinkedProjections" << endl;
		}
	}
}
		#endif
	#endif
/****************************************************************************************************************************************/
/****************************************************** Methodes de traces **************************************************************/
/****************************************************************************************************************************************/

void ClusterStater::trace()
{
}

void ClusterStater::graph()
{
}

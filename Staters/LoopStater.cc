// LoopStater.cc

// Local Includes
#include "LoopStater.h"

/****************************************************************************************************************************************/
/************************************************* Methodes de la classe LoopStater ************************************************/
/****************************************************************************************************************************************/

LoopStater::LoopStater()
{
#ifdef _NETWORK_STAT_MODE

	#ifdef _CENTRALITY_STAT_MODE
	shortPathLengthDistribution = new Distribution(30);
	#endif
	
	#ifdef _SMALL_WORLD_STAT_MODE
	clusteringCoeffDegreeDistribution = new MeanDistribution(NB_ASSEMBLIES);
	clusteringCoeffDistribution = new LogDistribution(-2,0,10);
	
	networkClusteringCoeff = new Accumulater();
	#endif

	#ifdef _DEGREE_STAT_MODE
	degreeDistribution = new Distribution(NB_ASSEMBLIES);
	preDegreeDistribution = new Distribution(NB_ASSEMBLIES);
	postDegreeDistribution = new Distribution(NB_ASSEMBLIES);
	
	nearestNeighboursDegreeDistribution = new MeanDistribution(NB_ASSEMBLIES);
	
		#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE
	inputNodeDegreeDistribution = new Distribution(NB_INPUT_ASSEMBLIES);
	outputNodeDegreeDistribution = new Distribution(NB_OUTPUT_ASSEMBLIES);
	
	inputNodeNearestNeighboursDegreeDistribution = new MeanDistribution(NB_INPUT_ASSEMBLIES);
	outputNodeNearestNeighboursDegreeDistribution = new MeanDistribution(NB_OUTPUT_ASSEMBLIES);
		#endif
	#endif
	
	#ifdef _MOTIF_STAT_MODE
	binodeMotifs = new Counter();
	trinodeMotifsDistribution = new Distribution(14);
	#endif

	#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE
	reachedByInputDistribution = new Distribution(NB_INPUT_ASSEMBLIES);
	reachedByOutputDistribution = new Distribution(NB_OUTPUT_ASSEMBLIES);
	
	inputOutputPathLengthDistribution = new Distribution(NB_ASSEMBLIES);
	pathToInputDistribution = new Distribution(NB_ASSEMBLIES);
	pathToOutputDistribution = new Distribution(NB_ASSEMBLIES);
	#endif

	#ifdef _LOOP_STAT_MODE
	loopSizeDistribution = new Distribution(NB_ASSEMBLIES);
	nbLoopsDistribution = new LogDistribution(0,4,10);
	nbLoopsDegreeDistribution  = new MeanDistribution(NB_ASSEMBLIES);
	#endif
#endif
}

LoopStater::LoopStater(IndexedObject* io): Stater(io)
{
#ifdef _NETWORK_STAT_MODE
	
	#ifdef _CENTRALITY_STAT_MODE
	shortPathLengthDistribution = new Distribution(NB_ASSEMBLIES);
	#endif
	
	#ifdef _SMALL_WORLD_STAT_MODE
	clusteringCoeffDegreeDistribution = new MeanDistribution(NB_ASSEMBLIES);
	
	networkClusteringCoeff = new Accumulater();
	#endif

	#ifdef _DEGREE_STAT_MODE
	degreeDistribution = new Distribution(NB_ASSEMBLIES);
	preDegreeDistribution = new Distribution(NB_ASSEMBLIES);
	postDegreeDistribution = new Distribution(NB_ASSEMBLIES);
	
	nearestNeighboursDegreeDistribution = new MeanDistribution(NB_ASSEMBLIES);
	
		#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE
	inputNodeDegreeDistribution = new Distribution(NB_INPUT_ASSEMBLIES);
	outputNodeDegreeDistribution = new Distribution(NB_OUTPUT_ASSEMBLIES);
	
	inputNodeNearestNeighboursDegreeDistribution = new MeanDistribution(NB_INPUT_ASSEMBLIES);
	outputNodeNearestNeighboursDegreeDistribution = new MeanDistribution(NB_OUTPUT_ASSEMBLIES);
		#endif
	#endif
	
	#ifdef _MOTIF_STAT_MODE
	binodeMotifs = new Counter();
	trinodeMotifsDistribution = new Distribution(14);
	#endif

	#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE
	reachedByInputDistribution = new Distribution(NB_INPUT_ASSEMBLIES);
	reachedByOutputDistribution = new Distribution(NB_OUTPUT_ASSEMBLIES);
	
	inputOutputPathLengthDistribution = new Distribution(NB_ASSEMBLIES);
	pathToInputDistribution = new Distribution(NB_ASSEMBLIES);
	pathToOutputDistribution = new Distribution(NB_ASSEMBLIES);
	#endif
	
	#ifdef _LOOP_STAT_MODE
	loopSizeDistribution = new Distribution(NB_ASSEMBLIES);
	nbLoopsDistribution = new LogDistribution(0,3,10);
	
	nbLoopsDegreeDistribution  = new MeanDistribution(NB_ASSEMBLIES);
	#endif
#endif
}

LoopStater::~LoopStater()
{
#ifdef _NETWORK_STAT_MODE
	
	cerr << "In ~LoopStater" << endl;
	#ifdef _CENTRALITY_STAT_MODE
	delete(shortPathLengthDistribution);
	#endif
	
	#ifdef _SMALL_WORLD_STAT_MODE
	delete(clusteringCoeffDegreeDistribution);
	
	delete(networkClusteringCoeff);
	#endif

	#ifdef _DEGREE_STAT_MODE
	delete(degreeDistribution);
	delete(preDegreeDistribution);
	delete(postDegreeDistribution);
	
	// Voisins
	delete(nearestNeighboursDegreeDistribution);
	
		#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE
	delete(inputNodeDegreeDistribution);
	delete(outputNodeDegreeDistribution);
	
	delete(inputNodeNearestNeighboursDegreeDistribution);
	delete(outputNodeNearestNeighboursDegreeDistribution);
		#endif
	#endif
	
	#ifdef _MOTIF_STAT_MODE
	delete(binodeMotifs);
	delete(trinodeMotifsDistribution);
	#endif

	#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE
	delete(pathToInputDistribution);
	delete(pathToOutputDistribution);
	#endif

	#ifdef _LOOP_STAT_MODE
	delete(loopSizeDistribution);
	delete(nbLoopsDistribution);
	
	delete(nbLoopsDegreeDistribution);
	#endif
	
	cerr << "After ~LoopStater" << endl;
#endif
}

void LoopStater::openGrapher()
{
	cout << "Warning, accessing openGrapher virtual method" << endl;
}

void LoopStater::runGrapher()
{
	cout << "Warning, accessing runGrapher virtual method" << endl;
}

void LoopStater::closeGrapher()
{
	cout << "Warning, accessing closeGrapher virtual method" << endl;
}

void LoopStater::openTracer()
{
	cout << "Warning, accessing openTracer virtual method" << endl;
}

void LoopStater::closeTracer()
{
	cout << "Warning, accessing closeTracer virtual method" << endl;
}

void LoopStater::initCounters()
{
}

void LoopStater::initTabNodes()
{
	for (int i=0;i<(NB_ASSEMBLIES);i++)
	{
		marked[i]= BLANC;
	}
	
	// Initialisation de Q
	tabNodes.erase(tabNodes.begin(),tabNodes.end());
	tabNodes.clear();
	
	//tabNodes = deque<Node*>();
}

void LoopStater::addNode(Node* newNode)
{
	if (((Node*) newNode)->getIndex() < (NB_ASSEMBLIES))
	{
		if (marked[((Node*) newNode)->getIndex()] == BLANC)
		{
			tabNodes.push_back((Node*) newNode);
			marked[((Node*) newNode)->getIndex()] = GRIS;
#ifdef _TEST_STAT			
			cout << "Adding " << newNode->getIndex() << " in tab assemblies (size: " << tabNodes.size() << ")" << endl;
#endif			
		}
	}
//#ifdef _TEST_STAT
	else
	{
		cout << "Node " << newNode->getIndex() << " is not an assembly" << endl;
	}
//#endif
}

Node* LoopStater::getFirstNode()
{
	Node* firstNode = tabNodes.front();
	marked[((Node*) firstNode)->getIndex()] = NOIR;
	return firstNode;
}
	
void LoopStater::deleteFirstNode()
{
	Node* firstNode = tabNodes.front();
	marked[((Node*) firstNode)->getIndex()] = NOIR;
	tabNodes.pop_front();
}

Node* LoopStater::getLastNode()
{
	Node* lastNode = tabNodes.back();
	marked[((Node*) lastNode)->getIndex()] = NOIR;
	return lastNode;
}
	
void LoopStater::deleteLastNode()
{
	Node* lastNode = tabNodes.back();
	marked[((Node*) lastNode)->getIndex()] = NOIR;
#ifdef _TEST_STAT
	cout << "Deleting node " << ((Node*) lastNode)->getIndex() << endl;
#endif
	tabNodes.pop_back();
}

std::vector<Node*> LoopStater::scanLoopCluster(Node* fromNode,Node* toNode)
{
#ifdef _TEST	
	cerr << "Entering scan loop with " << (Node&) *fromNode;
	//cerr << "Entering scan loop with node" << ((Node*) fromNode)->getIndex() << endl;
#endif

	std::vector<Node*> loopClusters;
	
	if (fromNode->getIndex() < (NB_ASSEMBLIES))
	{
		if (marked[((Node*) fromNode)->getIndex()] == BLANC)
		{		
			marked[((Node*) fromNode)->getIndex()] = GRIS;
#ifdef _TEST
			cerr << "For " << (Node&) *fromNode << endl;
#endif		
			
			std::vector<Link*>::iterator itOut = ((Node*) fromNode)->outputLinks.begin();
			std::vector<Link*>::iterator endOut = ((Node*) fromNode)->outputLinks.end();
				
			while (itOut != endOut)
			{
				if (((Node*) ((Link*) *itOut)->getPostNode())->isSameIndex((Node*) toNode))
				{	
#ifdef _TEST
					cerr << "*************** Detected cluster " << ((Node*) toNode)->getIndex(); 				
					cerr << " as output cluster of " << ((Node*) fromNode)->getIndex() << endl;
#endif
#ifdef _TEST
					cerr << (Node&) *toNode << endl;
#endif 
#ifdef _TEST
					cerr << (Node&) *fromNode << endl;
#endif
					std::vector<Node*>::iterator itLoop = loopClusters.begin();
					std::vector<Node*>::iterator endLoop = loopClusters.end();

					if (find(itLoop,endLoop,(Node*) *(&fromNode)) == endLoop)
					{
						loopClusters.push_back(((Node*) *(&fromNode)));
					}
#ifdef _TEST
					else
					{
						cerr << "Node " << fromNode->getIndex() << " is already in loopClusters" << endl;
					}
#endif
				}
				else
				{
					std::vector<Node*> outputLoopClusters = scanLoopCluster((Node*) ((Link*) *itOut)->getPostNode(),(Node*) toNode);
	
					if (outputLoopClusters.size() != 0)
					{
#ifdef _TEST
						cout << (Node&) *fromNode << endl;
#endif
	
						std::vector<Node*>::iterator itOutLoop = outputLoopClusters.begin();
						std::vector<Node*>::iterator endOutLoop = outputLoopClusters.end();
	
						while (itOutLoop != endOutLoop)
						{
							loopClusters.push_back((Node*) *(&*itOutLoop));
							itOutLoop++;
						}
	
						outputLoopClusters.erase(outputLoopClusters.begin(),outputLoopClusters.end());
						outputLoopClusters.clear();
						
						std::vector<Node*>::iterator itLoop = loopClusters.begin();
						std::vector<Node*>::iterator endLoop = loopClusters.end();
		
						if (find(itLoop,endLoop,(Node*) *(&fromNode)) == endLoop)
						{
							loopClusters.push_back(((Node*) *(&fromNode)));
						}
#ifdef _TEST
						else
						{
							cerr << "Node " << fromNode->getIndex() << " is already in loopClusters" << endl;
						}
#endif
					}
				}
#ifdef _TEST			
				cerr << "Loop cluster size = " << loopClusters.size() << endl;
#endif			
				itOut++;
			}
			
			marked[((Node*) fromNode)->getIndex()] = NOIR;
		}
#ifdef _TEST
		else
		{
			cerr << "Node " << fromNode->getIndex() << " already visited" << endl;
		}
#endif
	}
	else
	{
		cerr << "Node " << fromNode->getIndex() << " is not an internal node" << endl;
	}
	
	return loopClusters;
}

#ifdef _NETWORK_STAT_MODE
	
	#ifdef _CENTRALITY_STAT_MODE
void LoopStater::initPathCounters()
{
	if (shortPathLengthDistribution)
	{
		((Distribution*) shortPathLengthDistribution)->initDistribution();
	}
	
	for (int i=0;i<(NB_ASSEMBLIES);i++)
	{
		nodeGlobalEfficiency[i] = -1.0;
	}

	for (int i=0;i<(NB_ASSEMBLIES);i++)
	{
		nodeLocalEfficiency[i] = -1.0;
	}

	for (int i=0;i<(NB_ASSEMBLIES);i++)
	{
		for (int j=0;j<(NB_ASSEMBLIES);j++)
		{
			efficiency[i][j] = -1.0;
		}
	}

	if (shortPathRepartition)
	{
		for (int i=0;i<(NB_ASSEMBLIES);i++)
		{
			shortPathRepartition[i].initCounter();
		}
	}

	if (noShortPathRepartition)
	{
		for (int i=0;i<(NB_ASSEMBLIES);i++)
		{
			noShortPathRepartition[i].initCounter();
		}
	}
}
void LoopStater::initBetweennessCounters()
{
	if (nodeBetweenness)
	{
		for (int i=0;i<(NB_ASSEMBLIES);i++)
		{
			nodeBetweenness[i].initAccu();
		}
	}
	
		#ifdef _EDGE_BETWEENNESS_STAT_MODE
	for (int i=0;i<(NB_ASSEMBLIES);i++)
	{
		for (int j=0;j<(NB_ASSEMBLIES);j++)
		{
			edgeBetweenness[i][j].initAccu();
		}
	}
		#endif
}
		#ifdef _EDGE_BETWEENNESS_STAT_MODE
void LoopStater::initBetweenness()
{
	for (int i=0;i<(NB_ASSEMBLIES);i++)
	{
		for (int j=0;j<(NB_ASSEMBLIES);j++)
		{
			edgeWeights[i][j]= -1.0;
		}
	}
}
		#endif
void LoopStater::initBreadthFirstPostLinks(Node* curNode)
{
		#ifdef _TEST_STAT
	cerr << "initBreadthFirstPostLinks " << ((Node*) curNode)->getIndex() << endl;
		#endif
		
	initTabNodes();
	
		#ifdef _TEST_STAT
	cerr << "in initBreadthFirstPostLinks " << (int) (tabNodes.size()) << " for " << ((Node*) curNode)->getIndex() << endl;
		#endif
		
	// Index de l'assemblée initiale
	int curNodeIndex = ((Node*) curNode)->getIndex();

	// Initialisation de S
	tabShortPaths.erase(tabShortPaths.begin(),tabShortPaths.end());

	// Initialisation de P[w]
	for (int i=0;i<(NB_ASSEMBLIES);i++)
	{
		for (int j=0;j<(NB_ASSEMBLIES);j++)
		{
			directPredecessors[i][j]= 0;
		}
	}
	// Initialisation de sigma
	for (int i=0;i<(NB_ASSEMBLIES);i++)
	{
		nbShortPaths[i]= 0;
	}

	nbShortPaths[curNodeIndex]=1;
	
	// Initialisation de d
	for (int i=0;i<(NB_ASSEMBLIES);i++)
	{
		shortPathLengths[i]= -1;
	}
	
	shortPathLengths[curNodeIndex]=0;

	addNode((Node*) curNode);
	
		#ifdef _TEST_STAT
	cerr << "Top node index" << ((Node*) tabNodes.front())->getIndex() << endl;
		#endif	
}

void LoopStater::statBreadthFirstPostLinks(Node* postNode)
{
	//initBreadthFirstPostLinks((Node*) postNode);
	
		#ifdef _TEST_STAT
	cerr << "in statBreadthFirstPostLinks " << (int) tabNodes.size() << " for " << ((Node*) postNode)->getIndex() << endl;
		#endif
		#ifdef _TEST_STAT
	cerr << "after initBreadthFirstPostLinks " << postNode->getIndex() << endl;
		#endif
		
	while (tabNodes.size() != 0)
	{
		#ifdef _TEST_STAT
		cerr << tabNodes.size() << " elements in tabNodes" << endl;
		#endif
		
		Node* curNode = getFirstNode();

		int curNodeIndex = ((Node*) curNode)->getIndex();

		#ifdef _TEST_STAT
		cerr << "Expanding node " << curNodeIndex << endl;
		#endif
		
		tabShortPaths.push_back(curNode);

		std::vector<Link*>::iterator it = ((Node*) curNode)->outputLinks.begin();
		std::vector<Link*>::iterator end = ((Node*) curNode)->outputLinks.end();

		while (it!=end)
		{
			int neighbourIndex = ((Node*) ((Link*) *it)->getPostNode())->getIndex();

			if (neighbourIndex < (NB_ASSEMBLIES))
			{
				if (shortPathLengths[neighbourIndex] < 0)
				{
					if (shortPathLengths[curNodeIndex] != -1)
					{
						addNode((Node*) ((Link*) *it)->getPostNode());
						shortPathLengths[neighbourIndex] = shortPathLengths[curNodeIndex] + 1;
					}
					else
					{
						cerr << "Warning, shortPathLengths[" << curNodeIndex << "] is undefined" << endl;
					}
				}

				if (shortPathLengths[neighbourIndex] == shortPathLengths[curNodeIndex] + 1)
				{
					nbShortPaths[neighbourIndex] += nbShortPaths[curNodeIndex];

					// curNode est un predecesseur de neighbour
					directPredecessors[curNodeIndex][neighbourIndex] = 1;
				}
			}
			else
			{
		#ifdef _TEST_STAT
				cerr << "Warning, neighbourIndex is not an assembly: " << neighbourIndex << endl;
		#endif
			}
			it++;
		}
		#ifdef _TEST_STAT
		cout << tabNodes.size() << " elements in tabNodes" << endl;
		#endif
		
		deleteFirstNode();
	}
		#ifdef _TEST_STAT
	cerr << "Out of tabNodes " << postNode->getIndex() << endl;
		#endif
	
	for (int i=0;i<(NB_ASSEMBLIES);i++)
	{
		if (i != postNode->getIndex())
		{
			if (shortPathLengths[i] != -1)
			{
				if (shortPathLengths[i] != 0)
				{
					//cout << i << " " << (double) 1.0/((double) shortPathLengths[i]) << endl;
					efficiency[postNode->getIndex()][i] = (double) 1.0/((double) shortPathLengths[i]) ;
					shortPathRepartition[postNode->getIndex()].count();
					
					((Distribution*) shortPathLengthDistribution)->count((int) shortPathLengths[i]);
				}
				else 
				{
					cerr << "shortPathLengths[" << i << "] = 0" << endl; 
				}
			}
			else
			{
				noShortPathRepartition[postNode->getIndex()].count();
				efficiency[postNode->getIndex()][i] = 0.0;
			}
		}
	}		
}

void LoopStater::computeBetweenness(Node* postNode)
{
	// Initialisation de delta
	for (int i=0;i<(NB_ASSEMBLIES);i++)
	{
		pairCorrelations[i].initAccu();
	}

	while (tabShortPaths.size() != 0)
	{
		Node* curNode = tabShortPaths.back();

		for (int i=0;i<(NB_ASSEMBLIES);i++)
		{
			// i est un predecesseur de curNode
			if (directPredecessors[i][curNode->getIndex()] == 1)
			{
				if (nbShortPaths[curNode->getIndex()] != 0)
				{
					pairCorrelations[i].accumulate(((double) nbShortPaths[i])/((double) nbShortPaths[curNode->getIndex()])*(1.0+ (double) pairCorrelations[curNode->getIndex()].getAccu()));

					if (curNode != postNode)
					{
						//nodeBetweenness[curNode->getIndex()].accumulate((double) pairCorrelations[i].getAccu()/((double) NB_ASSEMBLIES*(NB_ASSEMBLIES-1)));
						nodeBetweenness[curNode->getIndex()].accumulate((double) pairCorrelations[i].getAccu());
					}

					#ifdef _EDGE_BETWEENNESS_STAT_MODE
					// Calcul de la somme des poids des liens en amont de curNode
					Accumulater* edgeBelowWeights = new Accumulater();
					//double edgeBelowWeights = 0.0;

					std::vector<Link*>::iterator it = ((Node*) curNode)->outputLinks.begin();
					std::vector<Link*>::iterator end = ((Node*) curNode)->outputLinks.end();

					while (it!=end)
					{
						Node* beforeNode = ((Link*) *it)->getPostNode();
						//Node* beforeNode = ((Link*) *it)->getPreNode();
						if (0.0 <= edgeWeights[curNode->getIndex()][beforeNode->getIndex()])
						{
							edgeBelowWeights->accumulate((double) edgeWeights[curNode->getIndex()][beforeNode->getIndex()]);
						}
						else
						{
							edgeBelowWeights->accumulate(0.0);
						}
						it++;
					}

					edgeWeights[i][curNode->getIndex()] = ((double) nbShortPaths[i])/((double) nbShortPaths[curNode->getIndex()])*(1.0 + edgeBelowWeights->getAccu());
					
					delete(edgeBelowWeights);
					#endif
				}
				else
				{
					cerr << "Warning, nbShortPaths[" << curNode->getIndex() << "] is uninstantcited" << endl;
				}
			}
		}
			
		tabShortPaths.pop_back();
	}
	
		#ifdef _EDGE_BETWEENNESS_STAT_MODE
	for (int i=0;i<(NB_ASSEMBLIES);i++)
	{
		for (int j=0;j<(NB_ASSEMBLIES);j++)
		{
			if (0.0 <= edgeWeights[i][j])
			{
				//cout << "edgeWeights[" << i << "][" << j << "]: " << edgeWeights[i][j] << endl;
				edgeBetweenness[i][j].accumulate((double) edgeWeights[i][j]);
				//cout << "edgeBetweenness[" << i << "][" << j << "]: " << edgeBetweenness[i][j].getAccu() << endl;
			}
		}
	}
		#endif
		
		#ifdef _TEST_STAT
	cerr << "after computeBetwenness " << postNode->getIndex() << endl;
		#endif
}
		
void LoopStater::computeEfficiency(Node* postNode)
{
	//if (postNode->getIndex() < (NB_ASSEMBLIES))
	if (postNode->getIndex() < (NB_ASSEMBLIES))
	{
		// Efficacité global du noeud
		Accumulater* curGlobalEfficiency = new Accumulater();
		
		for (int i=0;i<(NB_ASSEMBLIES);i++)
		{
			if (i != postNode->getIndex() && 0.0 <= efficiency[postNode->getIndex()][i])
			{
				//curGlobalEfficiency->accumulate(efficiency[postNode->getIndex()][i]/((double) (NB_ASSEMBLIES-1)));
				curGlobalEfficiency->accumulate(efficiency[postNode->getIndex()][i]);
			}
		}

		if (curGlobalEfficiency->getCounter() != 0)
		{
			nodeGlobalEfficiency[postNode->getIndex()] = curGlobalEfficiency->getMean();
		}
		else
		{
			nodeGlobalEfficiency[postNode->getIndex()] = 0.0;
		}
		
		delete(curGlobalEfficiency);
		
		// Efficacité local du noeud
		Accumulater* curLocalEfficiency = new Accumulater();
		
		int nbPostNeighbours = ((Node*) postNode)->outputLinks.size();
		
		std::vector<Link*>::iterator it = ((Node*) postNode)->outputLinks.begin();
		std::vector<Link*>::iterator end = ((Node*) postNode)->outputLinks.end();
	
		while (it != end)
		{
			int firstNeighbourIndex = ((Node*) ((Link*) *it)->getPostNode())->getIndex();
			
			if (firstNeighbourIndex < (NB_ASSEMBLIES))
			{
				std::vector<Link*>::iterator it2 = ((Node*) postNode)->outputLinks.begin();
				std::vector<Link*>::iterator end2 = ((Node*) postNode)->outputLinks.end();
		
				while (it2 != end2)
				{
					int secondNeighbourIndex = ((Node*) ((Link*) *it2)->getPostNode())->getIndex();
					
					if (secondNeighbourIndex < NB_ASSEMBLIES)
					{
						if (firstNeighbourIndex != secondNeighbourIndex && 0.0 <= efficiency[firstNeighbourIndex][secondNeighbourIndex])
						{
							//curLocalEfficiency->accumulate(efficiency[firstNeighbourIndex][secondNeighbourIndex]/((double) nbPostNeighbours*(nbPostNeighbours-1)));
							curLocalEfficiency->accumulate(efficiency[firstNeighbourIndex][secondNeighbourIndex]);
						}
					}	
					else
					{
					
		#ifdef _TEST_STAT
						cerr << "Warning, second assembly index " << secondNeighbourIndex << "=>" << NB_ASSEMBLIES << endl;
		#endif
					}
					it2++;
				}
			}
			else
			{
		#ifdef _TEST_STAT
				cerr << "Warning, first assembly index " << firstNeighbourIndex << "=>" << (NB_ASSEMBLIES) << endl;
		#endif
			}
			it++;
		}
		
		if (curLocalEfficiency->getCounter() != 0)
		{
			nodeLocalEfficiency[postNode->getIndex()] = curLocalEfficiency->getMean();
		}
		else
		{
			nodeLocalEfficiency[postNode->getIndex()] = 0.0;
		}		
		delete(curLocalEfficiency);
	}
	else
	{
		cerr << "Warning, assembly index " << postNode->getIndex() << "=>" << NB_ASSEMBLIES << endl;
	}
}
	#endif

	#ifdef _SMALL_WORLD_STAT_MODE
void LoopStater::initClusteringCoeffCounters()
{
	if (clusteringCoeffDegreeDistribution)
	{
		clusteringCoeffDegreeDistribution->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, clusteringCoeffDegreeDistribution should be inited" << endl;
	}
	
	if (clusteringCoeffDistribution)
	{
		clusteringCoeffDistribution->initDistribution();
	}
	
	// Repartition
	if (clusteringCoeffRepartition)
	{
		for (int i=0;i<NB_ASSEMBLIES;i++)
		{
			clusteringCoeffRepartition[i] = 0.0;
		}
	}
	else
	{
		cerr << "Warning, clusteringCoeffRepartition should be inited" << endl;
	}
	
	// Network
	if (networkClusteringCoeff)
	{
		networkClusteringCoeff->initAccu();
	}
}

void LoopStater::statSmallWorld(Node* postNode)
{
	int curDegree = ((Node*) postNode)->getNbLinks();

	if (1< curDegree && curDegree < NB_ASSEMBLIES)
	{

		Counter* nbNeighboursLinks = new Counter();

		// Pre
		int curPreDegree = ((Node*) postNode)->getNbInputLinks();

		if (1< curPreDegree && curPreDegree < NB_ASSEMBLIES)
		{
			std::vector<Link*>::iterator itPre = ((Node*) postNode)->inputLinks.begin();
			std::vector<Link*>::iterator endPre = ((Node*) postNode)->inputLinks.end();

			while (itPre != endPre)
			{
				Node* curPreNode = ((Link*) *itPre)->getPreNode();
				
				std::vector<Link*>::iterator itPre2 = ((Node*) postNode)->inputLinks.begin();
				std::vector<Link*>::iterator endPre2 = ((Node*) postNode)->inputLinks.end();
			
				while (itPre2 != endPre2)
				{
					Node* curPreNode2 = ((Link*) *itPre2)->getPreNode();
					
					if (curPreNode != curPreNode2)
					{
						if (curPreNode->isInputLinked(curPreNode2) || curPreNode2->isInputLinked(curPreNode))
						{
							nbNeighboursLinks->count();
						}
					}
					itPre2++;
				}
				
				std::vector<Link*>::iterator itPost = ((Node*) postNode)->outputLinks.begin();
				std::vector<Link*>::iterator endPost = ((Node*) postNode)->outputLinks.end();
			
				while (itPost != endPost)
				{
					Node* curPostNode = ((Link*) *itPost)->getPreNode();
					
					if (curPreNode != curPostNode)
					{
						if (curPreNode->isInputLinked(curPostNode) || curPostNode->isInputLinked(curPreNode))
						{
							nbNeighboursLinks->count();
						}
					}
					itPost++;
				}
				
				itPre++;
			}
		}

		clusteringCoeffRepartition[((Node*) postNode)->getIndex()] = ((double) nbNeighboursLinks->getCounter())/((double) curDegree*(curDegree-1));

		clusteringCoeffDegreeDistribution->accumulate(curDegree,(double) clusteringCoeffRepartition[((Node*) postNode)->getIndex()]);

		((LogDistribution*) clusteringCoeffDistribution)->count((double) clusteringCoeffRepartition[((Node*) postNode)->getIndex()]);
		
 		delete(nbNeighboursLinks);
	}
	
}

void LoopStater::computeNetworkClusteringCoeff()
{
	Accumulater* curCluster = new Accumulater();

	for (int i=0;i < NB_ASSEMBLIES;i++)
	{
		curCluster->accumulate(clusteringCoeffRepartition[i]);
	}

	networkClusteringCoeff->accumulate(curCluster->getMean());

	delete(curCluster);
}
	#endif

	#ifdef _MOTIF_STAT_MODE
void LoopStater::initMotifsCounters()
{
	if (binodeMotifs)
	{
		binodeMotifs->initCounter();
	}

	if (trinodeMotifsDistribution)
	{
		((Distribution*) trinodeMotifsDistribution)->initDistribution();
	}
}

void LoopStater::statMotifs(Node* curNode)
{
	#ifdef _REDONDANT_MOTIF_STAT_MODE
	// 2 motifs
	std::vector<Link*>::iterator itPostBi = ((Node*) curNode)->outputLinks.begin();
	std::vector<Link*>::iterator endPostBi = ((Node*) curNode)->outputLinks.end();

	while (itPostBi != endPostBi)
	{
		Node* postNode = (Node*) ((Link*) *itPostBi)->getPostNode();

		if (!((Node*) postNode)->isSameIndex((Node*) curNode))
		{
			if (((Node*) postNode)->isOutputLinked((Node*) curNode))
			{
				binodeMotifs->count();
			}
		}
		itPostBi++;
	}

	// Trois motifs
	// Index basé sur (Sporns et Kotter,2004)
	std::vector<Link*>::iterator itPostTri = ((Node*) curNode)->outputLinks.begin();
	std::vector<Link*>::iterator endPostTri = ((Node*) curNode)->outputLinks.end();

	while (itPostTri != endPostTri)
	{
		Node* postNode = ((Link*) *itPostTri)->getPostNode();
		
		if (!postNode->isSameIndex(curNode))
		{
			#ifdef _TEST_STAT
			cerr << "Trinode Motifs for assembly " << ((Node*) curNode)->getIndex();
			cerr << " and post assembly " << ((Node*) postNode)->getIndex() << endl;
			#endif
	
			#ifdef _TEST_STAT
			cerr << "Motifs with outputLinks of postNode" << endl;
			#endif
			
			// A partir de l'assemblée post
			std::vector<Link*>::iterator itPre = ((Node*) postNode)->inputLinks.begin();
			std::vector<Link*>::iterator endPre = ((Node*) postNode)->inputLinks.end();
	
			while (itPre != endPre)
			{
				Node* preToPostNode = (Node*) ((Link*) *itPre)->getPreNode();
			#ifdef _TEST_STAT
				cerr << "Trinode Motifs for assembly " << ((Node*) curNode)->getIndex();
				cerr << ", post assembly " << ((Node*) postNode)->getIndex();
				cerr << " and pre-to-post assembly " << ((Node*) preToPostNode)->getIndex() << endl;
			#endif
				if (!preToPostNode->isSameIndex(curNode))
				{
			#ifdef _TEST_STAT
					cerr << "Trinode 1" << endl;
			#endif
					// Convergence
					// 2 liens
					trinodeMotifsDistribution->count((int) 1);
	
					if (postNode->isOutputLinked(curNode))
					{
			#ifdef _TEST_STAT
						cerr << "Trinode 4" << endl;
			#endif
						// Bidir/Convergence 4a
						// 3 liens
						trinodeMotifsDistribution->count((int) 4);
	
						if (postNode->isOutputLinked(preToPostNode))
						{
							// Bidir+Bidir 9a
							// 4 liens
							trinodeMotifsDistribution->count((int) 9);
							
							if (curNode->isOutputLinked(preToPostNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (preToPostNode->isOutputLinked(curNode))
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
							
							if (preToPostNode->isOutputLinked(curNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (curNode->isOutputLinked(preToPostNode))
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
						}
	
						if (curNode->isOutputLinked(preToPostNode))
						{
							// Bidir+Bidir 10a
							// 4 liens
							trinodeMotifsDistribution->count((int) 10);
							
							if (postNode->isOutputLinked(preToPostNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (preToPostNode->isOutputLinked(curNode))
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
							
							if (preToPostNode->isOutputLinked(curNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (postNode->isOutputLinked(preToPostNode))
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
						}
	
						if (preToPostNode->isOutputLinked(curNode))
						{
							// Bidir+Div 8a
							// 4 liens
							trinodeMotifsDistribution->count((int) 8);
							
							if (postNode->isOutputLinked(preToPostNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (curNode->isOutputLinked(preToPostNode))
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
							
							if (curNode->isOutputLinked(preToPostNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (postNode->isOutputLinked(preToPostNode))
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
						}
					}
	
					if (postNode->isOutputLinked(preToPostNode))
					{
			#ifdef _TEST_STAT
						cerr << "Trinode 4" << endl;
			#endif
						// Bidir/Convergence 4c
						// 3 liens
						trinodeMotifsDistribution->count((int) 4);
	
						if (postNode->isOutputLinked(curNode))
						{
							// Bidir+Bidir 9a
							// 4 liens
							trinodeMotifsDistribution->count((int) 9);
							
							if (preToPostNode->isOutputLinked(curNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (curNode->isOutputLinked(preToPostNode))
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
							
							if (curNode->isOutputLinked(preToPostNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (preToPostNode->isOutputLinked(curNode))
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
						}
	
						if (preToPostNode->isOutputLinked(curNode))
						{
							// Bidir+Cont 10d
							// 4 liens
							trinodeMotifsDistribution->count((int) 10);
							
							if (postNode->isOutputLinked(curNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (curNode->isOutputLinked(preToPostNode))
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
							
							if (curNode->isOutputLinked(preToPostNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (postNode->isOutputLinked(curNode))
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
						}
	
						if (curNode->isOutputLinked(preToPostNode))
						{
							// Bidir+Div 8b
							// 4 liens
							trinodeMotifsDistribution->count((int) 8);
							
							if (postNode->isOutputLinked(curNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (preToPostNode->isOutputLinked(curNode))
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
							
							if (preToPostNode->isOutputLinked(curNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (postNode->isOutputLinked(curNode))
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
						}
					}
	
					if (curNode->isOutputLinked(preToPostNode))
					{
			#ifdef _TEST_STAT
						cerr << "Trinode 5" << endl;
			#endif
						// Feedforward Loop (Cut/ByPass) 5b
						// 3 liens
						trinodeMotifsDistribution->count((int) 5);
	
						if (postNode->isOutputLinked(curNode))
						{
							// Bidir+Cont 10a
							// 4 liens
							trinodeMotifsDistribution->count((int) 10);
							
							if (postNode->isOutputLinked(preToPostNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (preToPostNode->isOutputLinked(curNode))
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
							
							if (preToPostNode->isOutputLinked(curNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (postNode->isOutputLinked(preToPostNode))
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
						}
	
						if (postNode->isOutputLinked(preToPostNode))
						{
							// Bidir+Div 8b
							// 4 liens
							trinodeMotifsDistribution->count((int) 8);
							
							if (postNode->isOutputLinked(curNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (preToPostNode->isOutputLinked(curNode))
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
							
							if (preToPostNode->isOutputLinked(curNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (postNode->isOutputLinked(curNode))
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
						}
	
						if (preToPostNode->isOutputLinked(curNode))
						{
							// Bidir+Conv 11a
							// 4 liens
							trinodeMotifsDistribution->count((int) 11);
							
							if (postNode->isOutputLinked(curNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (postNode->isOutputLinked(preToPostNode))
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
							
							if (postNode->isOutputLinked(preToPostNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (postNode->isOutputLinked(curNode))
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
						}
					}
	
					if (preToPostNode->isOutputLinked(curNode))
					{
			#ifdef _TEST_STAT
						cerr << "Trinode 5" << endl;
			#endif
						// Feedforward Loop (Cut/ByPass) 5a
						// 3 liens
						trinodeMotifsDistribution->count((int) 5);
	
						if (postNode->isOutputLinked(curNode))
						{
							// Bidir+Div 8a
							// 4 liens
							trinodeMotifsDistribution->count((int) 8);
							
							if (curNode->isOutputLinked(preToPostNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (postNode->isOutputLinked(preToPostNode))
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
							
							if (postNode->isOutputLinked(preToPostNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (curNode->isOutputLinked(preToPostNode) )
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
						}
	
						if (postNode->isOutputLinked(preToPostNode))
						{
							// Bidir+Cont 10d
							// 4 liens
							trinodeMotifsDistribution->count((int) 10);
							
							if (curNode->isOutputLinked(preToPostNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (postNode->isOutputLinked(curNode))
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
							
							if (postNode->isOutputLinked(curNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (curNode->isOutputLinked(preToPostNode) )
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
						}
	
						if (curNode->isOutputLinked(preToPostNode))
						{
							// Bidir+Conv 11a
							// 4 liens
							trinodeMotifsDistribution->count((int) 11);
							
							if (postNode->isOutputLinked(preToPostNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (postNode->isOutputLinked(curNode))
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
							
							if (postNode->isOutputLinked(curNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (postNode->isOutputLinked(preToPostNode))
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
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
				itPre++;
			}
			#ifdef _TEST_STAT
			cerr << "Motifs with inputLinks of curNode";
			cerr << " (curNode has " << ((Node*) curNode)->getNbInputLinks() << ")" << endl;
			#endif
			// A partir de l'assemblée courante
			std::vector<Link*>::iterator itPre2 = ((Node*) curNode)->inputLinks.begin();
			std::vector<Link*>::iterator endPre2 = ((Node*) curNode)->inputLinks.end();
	
			while (itPre2 != endPre2)
			{
				Node* preNode = (Node*) ((Link*) *itPre2)->getPreNode();
			#ifdef _TEST_STAT
				cerr << "Trinode Motifs for assembly " << ((Node*) curNode)->getIndex();
				cerr << ", post assembly " << ((Node*) postNode)->getIndex();
				cerr << " and pre assembly " << ((Node*) preNode)->getIndex() << endl;
			#endif
				if (!preNode->isSameIndex(postNode))
				{
			#ifdef _TEST_STAT
					cerr << "Trinode 2" << endl;
			#endif
					// Continued 2a
					// 2 liens
					trinodeMotifsDistribution->count((int) 2);
	
					if (postNode->isOutputLinked(preNode))
					{
						// Loop 7
						// 3 liens
						trinodeMotifsDistribution->count((int) 7);
	
						if (preNode->isOutputLinked(postNode))
						{
							// Bidir+Cont 10d
							// 4 liens
							trinodeMotifsDistribution->count((int) 10);
							
							if (curNode->isOutputLinked(preNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (postNode->isOutputLinked(curNode))
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
							
							if (postNode->isOutputLinked(curNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (curNode->isOutputLinked(preNode))
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
						}
	
						if (curNode->isOutputLinked(preNode))
						{
							// Bidir+Cont 10c
							// 4 liens
							trinodeMotifsDistribution->count((int) 10);
							
							if (preNode->isOutputLinked(postNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (postNode->isOutputLinked(curNode))
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
							
							if (postNode->isOutputLinked(curNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (preNode->isOutputLinked(postNode))
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
						}
	
						if (postNode->isOutputLinked(curNode))
						{
							// Bidir+Cont 10b
							// 4 liens
							trinodeMotifsDistribution->count((int) 10);
							
							if (preNode->isOutputLinked(postNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
				
								trinodeMotifsDistribution->count((int) 12);
								
								if (curNode->isOutputLinked(preNode))
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
							
							if (curNode->isOutputLinked(preNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (preNode->isOutputLinked(postNode))
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
						}
					}
	
					if (postNode->isOutputLinked(curNode))
					{
						// Bidir/Conv 4b
						// 3 liens
						trinodeMotifsDistribution->count((int) 4);
	
						if (curNode->isOutputLinked(preNode))
						{
							// Bidir+Bidir 9b
							// 4 liens
							trinodeMotifsDistribution->count((int) 9);
							
							if (preNode->isOutputLinked(postNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (postNode->isOutputLinked(preNode))
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
							
							if (postNode->isOutputLinked(preNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (preNode->isOutputLinked(postNode))
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
						}
	
						if (preNode->isOutputLinked(postNode))
						{
							// Bidir+Div 8a
							// 4 liens
							trinodeMotifsDistribution->count((int) 8);
							
							if (curNode->isOutputLinked(preNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (postNode->isOutputLinked(preNode))
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
							
							if (postNode->isOutputLinked(preNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (curNode->isOutputLinked(preNode))
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
						}
	
						if (postNode->isOutputLinked(preNode))
						{
							// Bidir+Cont 10b
							// 4 liens
							trinodeMotifsDistribution->count((int) 10);
							
							if (curNode->isOutputLinked(preNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (preNode->isOutputLinked(postNode))
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
							
							if (preNode->isOutputLinked(postNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (curNode->isOutputLinked(preNode))
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
						}
					}
	
					if (preNode->isOutputLinked(postNode))
					{
						// Feedforward Loop (Cut/ByPass) 5a
						// 3 liens
						trinodeMotifsDistribution->count((int) 5);
	
						if (postNode->isOutputLinked(curNode))
						{
							// Bidir+Div 8a
							// 4 liens
							trinodeMotifsDistribution->count((int) 8);
							
							if (curNode->isOutputLinked(preNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (postNode->isOutputLinked(preNode))
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
							
							if (postNode->isOutputLinked(preNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (curNode->isOutputLinked(preNode))
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
						}
	
						if (postNode->isOutputLinked(preNode))
						{
							// Bidir+Cont 10d
							// 4 liens
							trinodeMotifsDistribution->count((int) 10);
							
							if (curNode->isOutputLinked(preNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (postNode->isOutputLinked(curNode))
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
							
							if (postNode->isOutputLinked(curNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (curNode->isOutputLinked(preNode))
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
						}
	
						if (curNode->isOutputLinked(preNode))
						{
							// Bidir+Conv 11a
							// 4 liens
							trinodeMotifsDistribution->count((int) 11);
							
							if (postNode->isOutputLinked(preNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (postNode->isOutputLinked(curNode))
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
							
							if (postNode->isOutputLinked(curNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (postNode->isOutputLinked(preNode))
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
						}
					}
	
					if (curNode->isOutputLinked(preNode))
					{
						// Bidir/Div 6b
						// 3 liens
						trinodeMotifsDistribution->count((int) 6);
	
						if (postNode->isOutputLinked(curNode))
						{
							// Bidir+Bidir 9b
							// 4 liens
							trinodeMotifsDistribution->count((int) 9);
							
							if (postNode->isOutputLinked(preNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (preNode->isOutputLinked(postNode))
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
							
							if (preNode->isOutputLinked(postNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (postNode->isOutputLinked(preNode))
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
						}
	
						if (postNode->isOutputLinked(preNode))
						{
							// Bidir+Cont 10c
							// 4 liens
							trinodeMotifsDistribution->count((int) 10);
							
							if (postNode->isOutputLinked(curNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (preNode->isOutputLinked(postNode))
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
							
							if (preNode->isOutputLinked(postNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (postNode->isOutputLinked(curNode))
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
						}
	
						if (preNode->isOutputLinked(postNode))
						{
							// Bidir+Conv 11a
							// 4 liens
							trinodeMotifsDistribution->count((int) 11);
							
							if (postNode->isOutputLinked(curNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (postNode->isOutputLinked(preNode))
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
							
							if (postNode->isOutputLinked(preNode))
							{
								// Bidir+Bidir+link 12
								// 5 liens
								trinodeMotifsDistribution->count((int) 12);
								
								if (postNode->isOutputLinked(curNode))
								{
									// Bidir+Bidir+Bidir 13
									// 5 liens
									trinodeMotifsDistribution->count((int) 13);
								}
							}
						}
	
					}
				}
	
	
				itPre2++;
			}
			#ifdef _TEST_STAT
			cerr << "Motifs with outputLinks of curNode" << endl;
			#endif
			std::vector<Link*>::iterator itPost2 = ((Node*) curNode)->outputLinks.begin();
			std::vector<Link*>::iterator endPost2 = ((Node*) curNode)->outputLinks.end();
	
			while (itPost2 != endPost2)
			{
				Node* postNode2 = (Node*) ((Link*) *itPost2)->getPostNode();
				
				if (!postNode2->isSameIndex(curNode))
				{
				#ifdef _TEST_STAT
					cerr << "Trinode Motifs for assembly " << ((Node*) curNode)->getIndex();
					cerr << ", post assembly " << ((Node*) postNode)->getIndex();
					cerr << " and post assembly2 " << ((Node*) postNode2)->getIndex() << endl;
				#endif
					if (!postNode2->isSameIndex(postNode))
					{
						// Divergence
						// 2 liens
						trinodeMotifsDistribution->count((int) 3);
		
						if (postNode->isOutputLinked(curNode))
						{
							// Bidir/Div 6c
							// 3 liens
							trinodeMotifsDistribution->count((int) 6);
		
							if (postNode->isOutputLinked(postNode2))
							{
								// Bidir+Conv 11b
								// 4 liens
								trinodeMotifsDistribution->count((int) 11);
								
								if (postNode2->isOutputLinked(postNode))
								{
									// Bidir+Bidir+link 12
									// 5 liens
									trinodeMotifsDistribution->count((int) 12);
									
									if (postNode2->isOutputLinked(curNode))
									{
										// Bidir+Bidir+Bidir 13
										// 5 liens
										trinodeMotifsDistribution->count((int) 13);
									}
								}
								
								if (postNode2->isOutputLinked(curNode))
								{
									// Bidir+Bidir+link 12
									// 5 liens
									trinodeMotifsDistribution->count((int) 12);
									
									if (postNode2->isOutputLinked(postNode))
									{
										// Bidir+Bidir+Bidir 13
										// 5 liens
										trinodeMotifsDistribution->count((int) 13);
									}
								}
							}
		
							if (postNode2->isOutputLinked(postNode))
							{
								// Bidir+Cont 10a
								// 4 liens
								trinodeMotifsDistribution->count((int) 10);
								
								if (postNode->isOutputLinked(postNode2))
								{
									// Bidir+Bidir+link 12
									// 5 liens
									trinodeMotifsDistribution->count((int) 12);
									
									if (postNode2->isOutputLinked(curNode))
									{
										// Bidir+Bidir+Bidir 13
										// 5 liens
										trinodeMotifsDistribution->count((int) 13);
									}
								}
								
								if (postNode2->isOutputLinked(curNode))
								{
									// Bidir+Bidir+link 12
									// 5 liens
									trinodeMotifsDistribution->count((int) 12);
									
									if (postNode->isOutputLinked(postNode2))
									{
										// Bidir+Bidir+Bidir 13
										// 5 liens
										trinodeMotifsDistribution->count((int) 13);
									}
								}
							}
		
							if (postNode2->isOutputLinked(curNode))
							{
								// Bidir+Bidir 9b
								// 4 liens
								trinodeMotifsDistribution->count((int) 9);
									
								if (postNode->isOutputLinked(postNode2))
								{
									// Bidir+Bidir+link 12
									// 5 liens
									trinodeMotifsDistribution->count((int) 12);
									
									if (postNode2->isOutputLinked(postNode))
									{
										// Bidir+Bidir+Bidir 13
										// 5 liens
										trinodeMotifsDistribution->count((int) 13);
									}
								}
								
								if (postNode2->isOutputLinked(postNode))
								{
									// Bidir+Bidir+link 12
									// 5 liens
									trinodeMotifsDistribution->count((int) 12);
									
									if (postNode->isOutputLinked(postNode2))
									{
										// Bidir+Bidir+Bidir 13
										// 5 liens
										trinodeMotifsDistribution->count((int) 13);
									}
								}
							}
						}
		
						if (postNode2->isOutputLinked(curNode))
						{
							// Bidir/Div 6b
							// 3 liens
							trinodeMotifsDistribution->count((int) 6);
		
							if (postNode->isOutputLinked(curNode))
							{
								// Bidir+Bidir 9b
								// 4 liens
								trinodeMotifsDistribution->count((int) 9);
									
								if (postNode->isOutputLinked(postNode2))
								{
									// Bidir+Bidir+link 12
									// 5 liens
									trinodeMotifsDistribution->count((int) 12);
									
									if (postNode2->isOutputLinked(postNode))
									{
										// Bidir+Bidir+Bidir 13
										// 5 liens
										trinodeMotifsDistribution->count((int) 13);
									}
								}
								
								if (postNode2->isOutputLinked(postNode))
								{
									// Bidir+Bidir+link 12
									// 5 liens
									trinodeMotifsDistribution->count((int) 12);
									
									if (postNode->isOutputLinked(postNode2))
									{
										// Bidir+Bidir+Bidir 13
										// 5 liens
										trinodeMotifsDistribution->count((int) 13);
									}
								}
							}
		
							if (postNode->isOutputLinked(postNode2))
							{
								// Bidir+Cont 10c
								// 4 liens
								trinodeMotifsDistribution->count((int) 10);
									
								if (postNode->isOutputLinked(curNode))
								{
									// Bidir+Bidir+link 12
									// 5 liens
									trinodeMotifsDistribution->count((int) 12);
									
									if (postNode2->isOutputLinked(postNode))
									{
										// Bidir+Bidir+Bidir 13
										// 5 liens
										trinodeMotifsDistribution->count((int) 13);
									}
								}
								
								if (postNode2->isOutputLinked(postNode))
								{
									// Bidir+Bidir+link 12
									// 5 liens
									trinodeMotifsDistribution->count((int) 12);
									
									if (postNode->isOutputLinked(curNode))
									{
										// Bidir+Bidir+Bidir 13
										// 5 liens
										trinodeMotifsDistribution->count((int) 13);
									}
								}
							}
		
							if (postNode2->isOutputLinked(postNode))
							{
								// Bidir+Conv 11a
								// 4 liens
								trinodeMotifsDistribution->count((int) 11);
									
								if (postNode->isOutputLinked(curNode))
								{
									// Bidir+Bidir+link 12
									// 5 liens
									trinodeMotifsDistribution->count((int) 12);
									
									if (postNode->isOutputLinked(postNode2))
									{
										// Bidir+Bidir+Bidir 13
										// 5 liens
										trinodeMotifsDistribution->count((int) 13);
									}
								}
								
								if (postNode->isOutputLinked(postNode2))
								{
									// Bidir+Bidir+link 12
									// 5 liens
									trinodeMotifsDistribution->count((int) 12);
									
									if (postNode->isOutputLinked(curNode))
									{
										// Bidir+Bidir+Bidir 13
										// 5 liens
										trinodeMotifsDistribution->count((int) 13);
									}
								}
							}
						}
		
						if (postNode->isOutputLinked(postNode2))
						{
							// Feedforward Loop (Cut/ByPass) 5c
							// 3 liens
							trinodeMotifsDistribution->count((int) 5);
		
							if (postNode->isOutputLinked(curNode))
							{
								// Bidir+Conv 11b
								// 4 liens
								trinodeMotifsDistribution->count((int) 11);
									
								if (postNode2->isOutputLinked(curNode))
								{
									// Bidir+Bidir+link 12
									// 5 liens
									trinodeMotifsDistribution->count((int) 12);
									
									if (postNode2->isOutputLinked(postNode))
									{
										// Bidir+Bidir+Bidir 13
										// 5 liens
										trinodeMotifsDistribution->count((int) 13);
									}
								}
								
								if (postNode2->isOutputLinked(postNode))
								{
									// Bidir+Bidir+link 12
									// 5 liens
									trinodeMotifsDistribution->count((int) 12);
									
									if (postNode2->isOutputLinked(curNode))
									{
										// Bidir+Bidir+Bidir 13
										// 5 liens
										trinodeMotifsDistribution->count((int) 13);
									}
								}
							}
		
							if (postNode2->isOutputLinked(postNode))
							{
								// Bidir+Div 8b
								//4 liens
								trinodeMotifsDistribution->count((int) 8);
								
								if (postNode2->isOutputLinked(curNode))
								{
									// Bidir+Bidir+link 12
									// 5 liens
									trinodeMotifsDistribution->count((int) 12);
									
									if (postNode->isOutputLinked(curNode))
									{
										// Bidir+Bidir+Bidir 13
										// 5 liens
										trinodeMotifsDistribution->count((int) 13);
									}
								}
								
								if (postNode->isOutputLinked(curNode))
								{
									// Bidir+Bidir+link 12
									// 5 liens
									trinodeMotifsDistribution->count((int) 12);
									
									if (postNode2->isOutputLinked(curNode))
									{
										// Bidir+Bidir+Bidir 13
										// 5 liens
										trinodeMotifsDistribution->count((int) 13);
									}
								}
							}
		
							if (postNode2->isOutputLinked(curNode))
							{
								// Bidir+Cont 10c
								// 4 liens
								trinodeMotifsDistribution->count((int) 10);
								
								if (postNode2->isOutputLinked(postNode))
								{
									// Bidir+Bidir+link 12
									// 5 liens
									trinodeMotifsDistribution->count((int) 12);
									
									if (postNode->isOutputLinked(curNode))
									{
										// Bidir+Bidir+Bidir 13
										// 5 liens
										trinodeMotifsDistribution->count((int) 13);
									}
								}
								
								if (postNode->isOutputLinked(curNode))
								{
									// Bidir+Bidir+link 12
									// 5 liens
									trinodeMotifsDistribution->count((int) 12);
									
									if (postNode2->isOutputLinked(postNode))
									{
										// Bidir+Bidir+Bidir 13
										// 5 liens
										trinodeMotifsDistribution->count((int) 13);
									}
								}
							}
						}
		
						if (postNode2->isOutputLinked(postNode))
						{
							// Feedforward Loop (Cut/ByPass) 5b
							// 3 liens
							trinodeMotifsDistribution->count((int) 5);
		
							if (postNode->isOutputLinked(curNode))
							{
								// Bidir+Cont 10a
								// 4 liens
								trinodeMotifsDistribution->count((int) 10);
								
								if (postNode2->isOutputLinked(curNode))
								{
									// Bidir+Bidir+link 12
									// 5 liens
									trinodeMotifsDistribution->count((int) 12);
									
									if (postNode->isOutputLinked(postNode2))
									{
										// Bidir+Bidir+Bidir 13
										// 5 liens
										trinodeMotifsDistribution->count((int) 13);
									}
								}
								
								if (postNode->isOutputLinked(postNode2))
								{
									// Bidir+Bidir+link 12
									// 5 liens
									trinodeMotifsDistribution->count((int) 12);
									
									if (postNode2->isOutputLinked(curNode))
									{
										// Bidir+Bidir+Bidir 13
										// 5 liens
										trinodeMotifsDistribution->count((int) 13);
									}
								}
							}
		
							if (postNode->isOutputLinked(postNode2))
							{
								// Bidir+Div 8b
								// 4 liens
								trinodeMotifsDistribution->count((int) 8);
								
								if (postNode2->isOutputLinked(curNode))
								{
									// Bidir+Bidir+link 12
									// 5 liens
									trinodeMotifsDistribution->count((int) 12);
									
									if (postNode->isOutputLinked(curNode))
									{
										// Bidir+Bidir+Bidir 13
										// 5 liens
										trinodeMotifsDistribution->count((int) 13);
									}
								}
								
								if (postNode->isOutputLinked(curNode))
								{
									// Bidir+Bidir+link 12
									// 5 liens
									trinodeMotifsDistribution->count((int) 12);
									
									if (postNode2->isOutputLinked(curNode))
									{
										// Bidir+Bidir+Bidir 13
										// 5 liens
										trinodeMotifsDistribution->count((int) 13);
									}
								}
							}
		
							if (postNode2->isOutputLinked(curNode))
							{
								// Bidir+Conv 11a
								// 4 liens
								trinodeMotifsDistribution->count((int) 11);
								
								if (postNode->isOutputLinked(postNode2))
								{
									// Bidir+Bidir+link 12
									// 5 liens
									trinodeMotifsDistribution->count((int) 12);
									
									if (postNode->isOutputLinked(curNode))
									{
										// Bidir+Bidir+Bidir 13
										// 5 liens
										trinodeMotifsDistribution->count((int) 13);
									}
								}
								
								if (postNode->isOutputLinked(curNode))
								{
									// Bidir+Bidir+link 12
									// 5 liens
									trinodeMotifsDistribution->count((int) 12);
									
									if (postNode->isOutputLinked(postNode2))
									{
										// Bidir+Bidir+Bidir 13
										// 5 liens
										trinodeMotifsDistribution->count((int) 13);
									}
								}
							}
						}
					}
				}
				itPost2++;
			}
		}

		itPostTri++;
	}
		#else
	// 2 motifs
	std::vector<Link*>::iterator itPostBi = ((Node*) curNode)->outputLinks.begin();
	std::vector<Link*>::iterator endPostBi = ((Node*) curNode)->outputLinks.end();

	while (itPostBi != endPostBi)
	{
		Node* postNode = (Node*) ((Link*) *itPostBi)->getPostNode();

		if (!((Node*) postNode)->isSameIndex((Node*) curNode))
		{
			if (((Node*) postNode)->isOutputLinked((Node*) curNode))
			{
				binodeMotifs->count();
			}
		}
		itPostBi++;
	}

	// Trois motifs
	// Index basé sur (Sporns et Kotter,2004)
	std::vector<Link*>::iterator itPostTri = ((Node*) curNode)->outputLinks.begin();
	std::vector<Link*>::iterator endPostTri = ((Node*) curNode)->outputLinks.end();

	while (itPostTri != endPostTri)
	{
		Node* postNode = ((Link*) *itPostTri)->getPostNode();

		if (!((Node*) postNode)->isSameIndex((Node*) curNode))
		{
			#ifdef _TEST_STAT
			cout << "Trinode Motifs for assembly " << ((Node*) curNode)->getIndex();
			cout << " and post assembly " << ((Node*) postNode)->getIndex() << endl;
			#endif
	
			#ifdef _TEST_STAT
			cout << "Motifs with outputLinks of postNode" << endl;
			#endif

			// A partir de l'assemblée post
			std::vector<Link*>::iterator itPre = ((Node*) postNode)->inputLinks.begin();
			std::vector<Link*>::iterator endPre = ((Node*) postNode)->inputLinks.end();
	
			while (itPre != endPre)
			{
				Node* preToPostNode = (Node*) ((Link*) *itPre)->getPreNode();
				
				if (!((Node*) preToPostNode)->isSameIndex(postNode))
				{
			#ifdef _TEST_STAT
					cout << "Trinode Motifs for assembly " << ((Node*) curNode)->getIndex();
					cout << ", post assembly " << ((Node*) postNode)->getIndex();
					cout << " and pre-to-post assembly " << ((Node*) preToPostNode)->getIndex() << endl;
			#endif
					if (!((Node*) preToPostNode)->isSameIndex((Node*) curNode))
					{
			#ifdef _TEST_STAT
						cout << "LoopStater: Trinode 1" << endl;
			#endif
						// Convergence
						// 2 liens
						trinodeMotifsDistribution->count((int) 1);
		
						if (((Node*) postNode)->isOutputLinked((Node*) curNode))
						{
		
							cout << "LoopStater: Trinode 4";
							cout << " (" << ((Node*) curNode)->getIndex();
							cout << " " << ((Node*) postNode)->getIndex();
							cout << " " << ((Node*) preToPostNode)->getIndex() << endl;
		
							// Bidir/Convergence 4a
							// 3 liens
							trinodeMotifsDistribution->count((int) 4);
		
							if (((Node*) postNode)->isOutputLinked(((Node*) preToPostNode)))
							{
								cout << "LoopStater: Trinode 9";
								cout << " (" << ((Node*) curNode)->getIndex();
								cout << " " << ((Node*) postNode)->getIndex();
								cout << " " << ((Node*) preToPostNode)->getIndex() << endl;
								// Bidir+Bidir 9a
								// 4 liens
								trinodeMotifsDistribution->count((int) 9);
							}
		
							if (((Node*) curNode)->isOutputLinked(((Node*) preToPostNode)))
							{
								cout << "LoopStater: Trinode 10";
								cout << " (" << ((Node*) curNode)->getIndex();
								cout << " " << ((Node*) postNode)->getIndex();
								cout << " " << ((Node*) preToPostNode)->getIndex() << endl;
								// Bidir+Bidir 10a
								// 4 liens
								trinodeMotifsDistribution->count((int) 10);
							}
		
							if (((Node*) preToPostNode)->isOutputLinked((Node*) curNode))
							{
								cout << "LoopStater: Trinode 8";
								cout << " (" << ((Node*) curNode)->getIndex();
								cout << " " << ((Node*) postNode)->getIndex();
								cout << " " << ((Node*) preToPostNode)->getIndex() << endl;
		
								// Bidir+Div 8a
								// 4 liens
								trinodeMotifsDistribution->count((int) 8);
							}
						}
		
						if (((Node*) curNode)->isOutputLinked(((Node*) preToPostNode)))
						{
				#ifdef _TEST_STAT
							cout << "LoopStater: Trinode 5" << endl;
				#endif
							// Feedforward Loop (Cut/ByPass) 5b
							// 3 liens
							trinodeMotifsDistribution->count((int) 5);
		
							if (((Node*) preToPostNode)->isOutputLinked(((Node*) curNode)))
							{
								cout << "LoopStater: Trinode 11";
								cout << " (" << ((Node*) curNode)->getIndex();
								cout << " " << ((Node*) postNode)->getIndex();
								cout << " " << ((Node*) preToPostNode)->getIndex() << endl;
								// Bidir+Conv 11a
								// 4 liens
								trinodeMotifsDistribution->count((int) 11);
		
								if (((Node*) postNode)->isOutputLinked(((Node*) curNode)))
								{
									cout << "LoopStater: Trinode 12";
									cout << " (" << ((Node*) curNode)->getIndex();
									cout << " " << ((Node*) postNode)->getIndex();
									cout << " " << ((Node*) preToPostNode)->getIndex() << endl;
									// Bidir+Bidir+link 12
									// 5 liens
									trinodeMotifsDistribution->count((int) 12);
		
									if (((Node*) postNode)->isOutputLinked(((Node*) preToPostNode)))
									{
										cout << "LoopStater: Trinode 13" << endl;
										cout << " (" << ((Node*) curNode)->getIndex();
										cout << " " << ((Node*) postNode)->getIndex();
										cout << " " << ((Node*) preToPostNode)->getIndex() << endl;
										// Full 13
										// 6 liens
										trinodeMotifsDistribution->count((int) 13);
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
				itPre++;
			}
			#ifdef _TEST_STAT
			cout << "Motifs with inputLinks of curNode";
			cout << " (curNode has " << ((Node*) curNode)->getNbInputLinks() << ")" << endl;
			#endif
	
			// A partir de l'assemblée courante
			std::vector<Link*>::iterator itPre2 = ((Node*) curNode)->inputLinks.begin();
			std::vector<Link*>::iterator endPre2 = ((Node*) curNode)->inputLinks.end();
	
			while (itPre2 != endPre2)
			{
				Node* preNode = (Node*) ((Link*) *itPre2)->getPreNode();
				
				if (!((Node*) preNode)->isSameIndex((Node*) curNode))
				{
			#ifdef _TEST_STAT
					cout << "Trinode Motifs for assembly " << ((Node*) curNode)->getIndex();
					cout << ", post assembly " << ((Node*) postNode)->getIndex();
					cout << " and pre assembly " << ((Node*) preNode)->getIndex() << endl;
			#endif
					if (!((Node*) preNode)->isSameIndex((Node*) postNode))
					{
			#ifdef _TEST_STAT
						cout << "LoopStater: Trinode 2" << endl;
			#endif
						// Continued 2a
						// 2 liens
						trinodeMotifsDistribution->count((int) 2);
		
						if (((Node*) postNode)->isOutputLinked(((Node*) preNode)))
						{
							cout << "LoopStater: Trinode 7";
							cout << "(" << ((Node*) curNode)->getIndex();
							cout << " " << ((Node*) postNode)->getIndex();
							cout << " " << ((Node*) preNode)->getIndex() << endl;
		
							// Loop 7
							// 3 liens
							trinodeMotifsDistribution->count((int) 7);
						}
		
						if (((Node*) curNode)->isOutputLinked(((Node*) preNode)))
						{
							cout << "LoopStater: Trinode 6";
							cout << "(" << ((Node*) curNode)->getIndex();
							cout << " " << ((Node*) postNode)->getIndex();
							cout << " " << ((Node*) preNode)->getIndex() << endl;
							// Bidir/Div 6b
							// 3 liens
							trinodeMotifsDistribution->count((int) 6);
						}
					}
				}
	
				itPre2++;
			}
			#ifdef _TEST_STAT
			cout << "Motifs with outputLinks of curNode" << endl;
			#endif

			std::vector<Link*>::iterator itPost2 = ((Node*) curNode)->outputLinks.begin();
			std::vector<Link*>::iterator endPost2 = ((Node*) curNode)->outputLinks.end();

			while (itPost2 != endPost2)
			{
				Node* postNode2 = (Node*) ((Link*) *itPost2)->getPostNode();
				
				if (!((Node*) postNode2)->isSameIndex(curNode))
				{
			#ifdef _TEST_STAT
					cout << "Trinode Motifs for assembly " << ((Node*) curNode)->getIndex();
					cout << ", post assembly " << ((Node*) postNode)->getIndex();
					cout << " and post assembly2 " << ((Node*) postNode2)->getIndex() << endl;
			#endif
					if (!((Node*) postNode2)->isSameIndex(postNode))
					{
			#ifdef _TEST_STAT
						cout << "LoopStater: Trinode 3" << endl;
			#endif
						// Divergence
						// 2 liens
						trinodeMotifsDistribution->count((int) 3);
					}
				}
				itPost2++;
			}
		}

		itPostTri++;
	}
		#endif
}
	#endif

	#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE
void LoopStater::initInputPathCounters()
{
	if (reachedByInputDistribution)
	{
		reachedByInputDistribution->initDistribution();
	}

	if (reachedByInputDistribution)
	{
		reachedByOutputDistribution->initDistribution();
	}

	
	if (pathToInputDistribution)
	{
		pathToInputDistribution->initDistribution();
	}
	
	if (pathToOutputDistribution)
	{
		pathToOutputDistribution->initDistribution();
	}
	
	if (inputOutputPathLengthDistribution)
	{
		inputOutputPathLengthDistribution->initDistribution();
	}
}

void LoopStater::statBreadthFirstInputNode(Node* inputNode)
{
	initTabNodes();

	for (int i=0;i<NB_ASSEMBLIES;i++)
	{
		pathToInput[i]= -1;
	}

	std::vector<Link*>::iterator it = ((Node*) inputNode)->outputLinks.begin();
	std::vector<Link*>::iterator end = ((Node*) inputNode)->outputLinks.end();

	while (it!=end)
	{
		int neighbourIndex = ((Node*) ((Link*) *it)->getPostNode())->getIndex();

		if (neighbourIndex < NB_ASSEMBLIES)
		{
			pathToInput[neighbourIndex] = 1;
			addNode((Node*) ((Link*) *it)->getPostNode());
		}
		else if (NB_ASSEMBLIES + NB_INPUT_ASSEMBLIES <= neighbourIndex && neighbourIndex < NB_ASSEMBLIES + NB_INPUT_ASSEMBLIES + NB_OUTPUT_ASSEMBLIES)
		{
		#ifdef _TEST_STAT
			cout << "NeighbourIndex is a direct output assembly: " << neighbourIndex << endl;
		#endif
			((Distribution*) inputOutputPathLengthDistribution)->count((int) 0);
		}
		else
		{
			cerr << "Warning, neighbourIndex is not an adapted post assembly: " << neighbourIndex << endl;
		}
		it++;
	}

	while (tabNodes.size() != 0)
	{
		Node* curNode = getFirstNode();

		int curNodeIndex = curNode->getIndex();

		std::vector<Link*>::iterator it = ((Node*) curNode)->outputLinks.begin();
		std::vector<Link*>::iterator end = ((Node*) curNode)->outputLinks.end();

		while (it!=end)
		{
			int neighbourIndex = ((Node*) ((Link*) *it)->getPostNode())->getIndex();

			if (neighbourIndex < NB_ASSEMBLIES)
			{
				if (pathToInput[neighbourIndex ] < 0)
				{
					if (pathToInput[curNodeIndex] != -1)
					{
						pathToInput[neighbourIndex] = pathToInput[curNodeIndex]+1;
						addNode((Node*) ((Link*) *it)->getPostNode());
					}
					else
					{
						cerr << "Warning, pathToInput[" << curNodeIndex<< "] is undefined" << endl;
					}
				}
			}
			else if (NB_ASSEMBLIES + NB_INPUT_ASSEMBLIES <= neighbourIndex && neighbourIndex < NB_ASSEMBLIES + NB_INPUT_ASSEMBLIES + NB_OUTPUT_ASSEMBLIES)
			{
		#ifdef _TEST_STAT	
				cout << "NeighbourIndex is an output assembly: " << neighbourIndex << endl;
		#endif
				((Distribution*) inputOutputPathLengthDistribution)->count((int) pathToInput[curNodeIndex]+1);
			}
			else
			{
				cerr << "Warning, neighbourIndex is not an adapted post assembly: " << neighbourIndex << endl;
			}
			
			it++;
		}
		#ifdef _TEST_STAT
		cout << tabNodes.size() << " elements in tabNodes" << endl;
		#endif
		deleteFirstNode();
	}

	statReachedInputAssemblies((Node*) inputNode);
}

void LoopStater::statBreadthFirstOutputNode(Node* outputNode)
{
	initTabNodes();

	for (int i=0;i<NB_ASSEMBLIES;i++)
	{
		pathToOutput[i]= -1;
	}

	std::vector<Link*>::iterator it = ((Node*) outputNode)->inputLinks.begin();
	std::vector<Link*>::iterator end = ((Node*) outputNode)->inputLinks.end();

	while (it!=end)
	{
		int neighbourIndex = ((Node*) ((Link*) *it)->getPreNode())->getIndex();

		if (neighbourIndex < NB_ASSEMBLIES)
		{
			pathToOutput[neighbourIndex]= 1;
			addNode((Node*) ((Link*) *it)->getPreNode());
		}
		it++;
	}

	while (tabNodes.size() != 0)
	{
		Node* curNode = getFirstNode();

		int curNodeIndex = curNode->getIndex();

		std::vector<Link*>::iterator it = ((Node*) curNode)->inputLinks.begin();
		std::vector<Link*>::iterator end = ((Node*) curNode)->inputLinks.end();

		while (it!=end)
		{
			int neighbourIndex = ((Node*) ((Link*) *it)->getPreNode())->getIndex();

			if (neighbourIndex < NB_ASSEMBLIES)
			{
				if (pathToOutput[neighbourIndex ] < 0)
				{
					if (pathToOutput[curNodeIndex] != -1)
					{
						pathToOutput[neighbourIndex] = pathToOutput[curNodeIndex]+1;
						addNode((Node*) ((Link*) *it)->getPreNode());
					}
					else
					{
						cerr << "Warning, pathToOutput[" << curNodeIndex<< "] is undefined" << endl;
					}
				}
			}
		#ifdef _TEST_STAT
			else
			{
				cerr << "Warning, neighbourIndex is a post assembly: " << neighbourIndex << endl;
			}
		#endif
			it++;
		}
		#ifdef _TEST_STAT
		cout << tabNodes.size() << " elements in tabNodes" << endl;
		#endif
		deleteFirstNode();
	}

	statReachedOutputAssemblies((Node*) outputNode);
}

void LoopStater::statReachedInputAssemblies(Node* inputNode)
{
	int inputIndex = inputNode->getIndex() - NB_ASSEMBLIES;

	if (0 <= inputIndex && inputIndex < NB_INPUT_ASSEMBLIES)
	{
		for (int i=0;i<NB_ASSEMBLIES;i++)
		{
			if (marked[i] == NOIR)
			{
				reachedByInputDistribution->count(inputIndex);
				pathToInputDistribution->count(pathToInput[i]);
			}
			else if (marked[i] == GRIS)
			{
				cerr << "Warning, marked[" << i << "] is GRIS" << endl;
			}
		}
	}
	else
	{
		cerr << "Warning, assembly " << inputNode->getIndex() << " is not an input assembly " << endl;
	}
}


void LoopStater::statReachedOutputAssemblies(Node* outputNode)
{
	int outputIndex = outputNode->getIndex() - NB_ASSEMBLIES - NB_INPUT_ASSEMBLIES;

	if (0 <= outputIndex && outputIndex < NB_OUTPUT_ASSEMBLIES)
	{
		for (int i=0;i<NB_ASSEMBLIES;i++)
		{
			if (marked[i] == NOIR)
			{
				reachedByOutputDistribution->count(outputIndex);
				pathToOutputDistribution->count(pathToOutput[i]);
			}
			else if (marked[i] == GRIS)
			{
				cerr << "Warning, marked[" << i << "] is GRIS" << endl;
			}
		}
	}
	else
	{
		cerr << "Warning, assembly " << outputNode->getIndex() << " is not an output assembly " << endl;
	}
}
	#endif

	#ifdef _DEGREE_STAT_MODE
void LoopStater::initDegreeCounters()
{
		#ifdef _TEST_STAT
	cout << "Initing degree counters" << endl;
		#endif
		
	if (degreeDistribution)
	{
		degreeDistribution->initDistribution();
	}
	else
	{
		cerr << "Warning, degreeDistribution should be inited" << endl;
	}
	
	if (preDegreeDistribution)
	{
		preDegreeDistribution->initDistribution();
	}
	else
	{
		cerr << "Warning, preDegreeDistribution should be inited" << endl;
	}
	
	if (postDegreeDistribution)
	{
		postDegreeDistribution->initDistribution();
	}
	else
	{
		cerr << "Warning, postDegreeDistribution should be inited" << endl;
	}
	
	
	if (nearestNeighboursDegreeDistribution)
	{
		nearestNeighboursDegreeDistribution->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, nearestNeighboursDegreeDistribution should be inited" << endl;
	}
	
		#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE
	if (inputNodeDegreeDistribution)
	{
		inputNodeDegreeDistribution->initDistribution();
	}
	else
	{
		cerr << "Warning, inputNodeDegreeDistribution should be inited" << endl;
	}
	
	if (outputNodeDegreeDistribution)
	{
		outputNodeDegreeDistribution->initDistribution();
	}
	else
	{
		cerr << "Warning, outputNodeDegreeDistribution should be inited" << endl;
	}
	
	if (inputNodeNearestNeighboursDegreeDistribution)
	{
		inputNodeNearestNeighboursDegreeDistribution->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, inputNodeNearestNeighboursDegreeDistribution should be inited" << endl;
	}
	
	if (outputNodeNearestNeighboursDegreeDistribution)
	{
		outputNodeNearestNeighboursDegreeDistribution->initMeanDistribution();
	}
	else
	{
		cerr << "Warning, outputNodeNearestNeighboursDegreeDistribution should be inited" << endl;
	}
		#endif
}

void LoopStater::statDegreeDistribution(Node* postNode)
{
	int curDegree = ((Node*) postNode)->getNbLinks();
	
		#ifdef _TEST_STAT
	cout << "stat degree distribution for node " << postNode->getIndex() << " with  degree: " << curDegree << endl;
		#endif
		
	if (curDegree < NB_ASSEMBLIES)
	{
		degreeDistribution->count(curDegree);
		
		Accumulater* meanDegree = new Accumulater();

		int curPreDegree = ((Node*) postNode)->getNbInputLinks();
		
		if (curPreDegree < NB_ASSEMBLIES)
		{
			preDegreeDistribution->count(curPreDegree);
			
			std::vector<Link*>::iterator it = ((Node*) postNode)->inputLinks.begin();
			std::vector<Link*>::iterator end = ((Node*) postNode)->inputLinks.end();

			Accumulater* meanPreDegree = new Accumulater();

			while (it != end)
			{
				Node* curPreNode = ((Link*) *it)->getPreNode();

				meanPreDegree->accumulate((double) curPreNode->getNbInputLinks());
				meanDegree->accumulate((double) curPreNode->getNbLinks());
				it++;
			}

			delete(meanPreDegree);
		}
		
		int curPostDegree = ((Node*) postNode)->getNbOutputLinks();
		
		if (curPostDegree < NB_ASSEMBLIES)
		{
			postDegreeDistribution->count(curPostDegree);
			
			Accumulater* meanPostDegree = new Accumulater();

			std::vector<Link*>::iterator it2 = ((Node*) postNode)->outputLinks.begin();
			std::vector<Link*>::iterator end2 = ((Node*) postNode)->outputLinks.end();
		
			while (it2 != end2)
			{
				Node* curPostNode = ((Link*) *it2)->getPostNode();

				meanPostDegree->accumulate((double) curPostNode->getNbOutputLinks());
				meanDegree->accumulate((double) curPostNode->getNbLinks());

				it2++;
			}

			delete(meanPostDegree);
		}

		nearestNeighboursDegreeDistribution->accumulate((int) curDegree,(double) meanDegree->getMean());
		
		delete(meanDegree);
	}
}
		#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE
void LoopStater::statInputNodeDegree(Node* inputNode)
{
	int inputIndex = inputNode->getIndex() - NB_ASSEMBLIES;
	
	if (0 <= inputIndex && inputIndex < NB_INPUT_ASSEMBLIES)
	{
		inputNodeDegreeDistribution->count((int) inputIndex,(int) ((Node*) inputNode)->getNbOutputLinks());
		
		std::vector<Link*>::iterator it = ((Node*) inputNode)->outputLinks.begin();
		std::vector<Link*>::iterator end = ((Node*) inputNode)->outputLinks.end();
		
		while (it != end)
		{
			inputNodeNearestNeighboursDegreeDistribution->accumulate((int) inputIndex,(double) ((Node*) ((Link*) *it)->getPostNode())->getNbLinks());
			it++;
		}
	}
	else
	{
		cerr << "Warning, assembly " << inputNode->getIndex() << " is not an input assembly " << endl;
	}
}

void LoopStater::statOutputNodeDegree(Node* outputNode)
{
	int outputIndex = outputNode->getIndex() - NB_ASSEMBLIES - NB_INPUT_ASSEMBLIES;

	if (0 <= outputIndex && outputIndex < NB_OUTPUT_ASSEMBLIES)
	{
		outputNodeDegreeDistribution->count((int) outputIndex,(int) ((Node*) outputNode)->getNbInputLinks());
				
		std::vector<Link*>::iterator it = ((Node*) outputNode)->inputLinks.begin();
		std::vector<Link*>::iterator end = ((Node*) outputNode)->inputLinks.end();
		
		while (it != end)
		{
			outputNodeNearestNeighboursDegreeDistribution->accumulate((int) outputIndex,(double) ((Node*) ((Link*) *it)->getPreNode())->getNbLinks());
			it++;
		}
	}
	else
	{
		cerr << "Warning, assembly " << outputNode->getIndex() << " is not an output assembly " << endl;
	}	
}
		#endif
	#endif

	#ifdef _LOOP_STAT_MODE
void LoopStater::initLoopCounters()
{
	if (nbLoopsRepartition)
	{
		for (int i=0;i<NB_ASSEMBLIES;i++)
		{
			nbLoopsRepartition[i].initCounter();
		}
	}

	if (loopSizeDistribution)
	{
		((Distribution*) loopSizeDistribution)->initDistribution();
	}
	
	if (nbLoopsDistribution)
	{
		((LogDistribution*) nbLoopsDistribution)->initDistribution();
	}
	
	if (nbLoopsDegreeDistribution)
	{
		((MeanDistribution*) nbLoopsDegreeDistribution)->initMeanDistribution();
	}
	
	nbLoops = 0;
}

void LoopStater::statDepthFirstPostLinks(Node* postNode)
{
	if (((Node*) postNode)->getIndex() < NB_ASSEMBLIES)
	{
		if (marked[((Node*) postNode)->getIndex()] == BLANC)
		{
			addNode(postNode);

			std::vector<Link*>::iterator it = ((Node*) postNode)->outputLinks.begin();
			std::vector<Link*>::iterator end = ((Node*) postNode)->outputLinks.end();

			while (it!=end)
			{
				statDepthFirstPostLinks((Node*) ((Link*) *it)->getPostNode());
				it++;
			}

			deleteLastNode();
		}
		else if (marked[((Node*) postNode)->getIndex()] == GRIS)
		{
			statLoop(postNode);
		}
	}
		#ifdef _TEST_STAT
	else
	{
		cout << "Node " << postNode->getIndex() << " is not an internal node" << endl;
	}
		#endif
}

void LoopStater::statLoop(Node* postNode)
{

		#ifdef _TEST_STAT
	cout << "index " << postNode->getIndex() << " already visited";
	cout << "(size: " << tabNodes.size() << ")" << endl;
		#endif

	deque<Node*>::reverse_iterator it = tabNodes.rbegin();
	deque<Node*>::reverse_iterator end = tabNodes.rend();
	
	int count = 0;

	
	while(it != end)
	{
		if (((Node*) *it)->getIndex() < NB_ASSEMBLIES)
		{
		#ifdef _TEST_STAT
			cout << "Stating nb loops for " << ((Node*) *it)->getIndex() << endl;
		#endif
			nbLoopsRepartition[((Node*) *it)->getIndex()].count();
		}
		else
		{
			cout << "Node " << ((Node*) *it)->getIndex() << " is not a correct node" << endl;
		}
	
		#ifdef _TEST_STAT
		cout << "Scanning tab nodes for " << ((Node*) *it)->getIndex() << endl;
		#endif
		
		if (((Node*) *it)->getIndex() == ((Node*) postNode)->getIndex())
		{
		#ifdef _TEST_STAT
			cout << "Stating loop size " << count << endl;
		#endif
			((Distribution*) loopSizeDistribution)->count((int) count);

			return;
		}
		count++;
		it++;
	}

	cout << "Warning, unable to find node " <<  ((Node*) postNode)->getIndex() << " in tabNodes" << endl;
}

void LoopStater::computeNbLoops()
{
	for (int i=0;i<NB_ASSEMBLIES;i++)
	{
		nbLoops += nbLoopsRepartition[i].getCounter();
		((LogDistribution*) nbLoopsDistribution)->count((double) nbLoopsRepartition[i].getCounter());
	}
}

void LoopStater::computeNbLoopsDegree(Node* postNode)
{
	if (0 <= ((Node*) postNode)->getIndex() && ((Node*) postNode)->getIndex() < NB_ASSEMBLIES)
	{
		((MeanDistribution*) nbLoopsDegreeDistribution)->accumulate(((Node*) postNode)->getNbLinks(),(double) nbLoopsRepartition[((Node*) postNode)->getIndex()].getCounter());
	}
	else
	{
		cerr << "Warning, node " << ((Node*) postNode)->getIndex() << " has a wrong node index" << endl; 
	}
}
	#endif
	
	#ifdef _GSCC_STAT_MODE
void LoopStater::initGSCC()
{
	tabGSCCNodes.erase(tabGSCCNodes.begin(),tabGSCCNodes.end());
	tabGSCCNodes.clear();

	nbStrongComponents.erase(nbStrongComponents.begin(),nbStrongComponents.end());
	nbStrongComponents.clear();
}

bool LoopStater::isInGSCC(Node* postNode)
{
	std::vector<Node*>::iterator it = tabGSCCNodes.begin();
	std::vector<Node*>::iterator end = tabGSCCNodes.end();

	if (find(it,end,(Node*) postNode) == end)
	{
		// Le noeud n'est pas present
		return 0;
	}
	else
	{
		// Le noeud est deja present
		return 1;
	}
}

void LoopStater::initDFS(Node* postNode)
{
	for (int i=0;i<(NB_ASSEMBLIES);i++)
	{
		for (int j=0;j<(NB_ASSEMBLIES);j++)
		{
			edgeVisited[i][j] = false;
		}
	}

	for (int i=0;i<(NB_ASSEMBLIES);i++)
	{
		parents[i] = -1;
	}

	for (int i=0;i<(NB_ASSEMBLIES);i++)
	{
		low[i] = -1;
	}

	holdStack.erase(holdStack.begin(),holdStack.end());
	holdStack.clear();

	dfnum = 0;

	initTabNodes();

}
void LoopStater::statGSCC(Node* postNode)
{
	int postNodeIndex = postNode->getIndex();

	if (postNodeIndex < (NB_ASSEMBLIES))
	{
		if (!isInGSCC(postNode))
		{
			tabNodes.push_back((Node*) postNode);

			#ifdef _TEST_STAT
			cerr << tabNodes.size() << " elements in tabNodes, " << tabGSCCNodes.size() << " in tabGSCCNodes " << endl;
			#endif

			#ifdef _TEST_STAT
			cerr << "Expanding node " << postNodeIndex << endl;
			#endif

			int nbRealOutputLinks = 0;

			std::vector<Link*>::iterator it = ((Node*) postNode)->outputLinks.begin();
			std::vector<Link*>::iterator end = ((Node*) postNode)->outputLinks.end();

			while (it!=end)
			{
				int neighbourIndex = ((Node*) ((Link*) *it)->getPostNode())->getIndex();

				if (neighbourIndex != postNodeIndex)
				{
					if (edgeVisited[postNodeIndex][neighbourIndex] == false)
					{
						edgeVisited[postNodeIndex][neighbourIndex] = true;

						Node* neighbourNode = (Node*) ((Link*) *it)->getPostNode();

						if (neighbourIndex < (NB_ASSEMBLIES))
						{
							if (marked[neighbourIndex] == BLANC)
							{
								marked[neighbourIndex] = dfnum;
								low[neighbourIndex] = dfnum;
								dfnum++;

								if (parents[neighbourIndex] == -1)
								{
									parents[neighbourIndex] = postNodeIndex;
								}
								else
								{
									cerr << "Warning, parent of " << neighbourIndex;
									cerr << " already inited with " << parents[neighbourIndex] << endl;
								}

								statGSCC((Node*) neighbourNode);
							}
							else if (!isInGSCC(neighbourNode))
							{
								if (marked[neighbourIndex] < low[postNodeIndex])
								{
									low[postNodeIndex] = marked[neighbourIndex];
								}
							}
						}
						else
						{
			#ifdef _TEST_STAT
							cerr << "Warning, neighbourIndex is not an assembly: " << neighbourIndex << endl;
			#endif
						}
					}

					nbRealOutputLinks++;
				}


				it++;
			}

			if (low[postNodeIndex] == marked[postNodeIndex] && marked[postNodeIndex] != -1)
			{
				if (0 < nbRealOutputLinks)
				{
			#ifdef _TEST_STAT
					cout << "Adding node " << postNodeIndex << " in GSCC: ";
					cout << low[postNodeIndex] << " " << marked[postNodeIndex] << endl;

					cout << "Nb nodes in holdStack: " << holdStack.size() << endl;
			#endif
					int nbNodesInComp = 0;

					tabGSCCNodes.push_back((Node*) postNode);

					nbNodesInComp++;
					
					while (holdStack.size() != 0)
					{
						Node* lastNode = holdStack.back();

						int lastNodeIndex = lastNode->getIndex();

						if (lastNodeIndex < (NB_ASSEMBLIES))
						{
							if (marked[postNodeIndex] <= low[lastNodeIndex] )
							{
			#ifdef _TEST_STAT
								cout << "Adding node " << lastNodeIndex << " in GSCC: holdstack" << endl;

			#endif
								tabGSCCNodes.push_back((Node*) lastNode);
			#ifdef _TEST_STAT
								cout << "Nb nodes in GSCC: " << tabGSCCNodes.size() << endl;
			#endif
								nbNodesInComp++;

								holdStack.pop_back();
							}
							else
							{
			#ifdef _TEST_STAT
								cout << "Adding component of size " << nbNodesInComp;
								cout << " to nbStrongComponents" << endl;
			#endif
								nbStrongComponents.push_back((int) nbNodesInComp);
			#ifdef _TEST_STAT
								cout << "Breaking holdStack with " << holdStack.size() << " elements" << endl;
			#endif
								break;
							}
						}
						else
						{
							cerr << "Warning, lastNodeIndex is not an assembly: " << lastNodeIndex << endl;
						}
					}

			#ifdef _TEST_STAT
					cout << "Adding component of size " << nbNodesInComp << " to nbStrongComponents" << endl;
			#endif
					nbStrongComponents.push_back((int) nbNodesInComp);
				}
			#ifdef _TEST_STAT
				else
				{
					cerr << "Warning, node " << postNodeIndex << " has no real output, cannot be strongly connected" << endl;
				}
			#endif
			}
			else
			{
				holdStack.push_back((Node*) postNode);

				if (parents[postNodeIndex] != -1)
				{
					if (parents[postNodeIndex] < (NB_ASSEMBLIES))
					{
						if (low[postNodeIndex] < low[parents[postNodeIndex]])
						{
							low[parents[postNodeIndex]] = low[postNodeIndex];
						}
					}
					else
					{
						cerr << "Warning, parentNodeIndex is not an assembly: " << parents[postNodeIndex] << endl;
					}
				}
			#ifdef _TEST_STAT
				else
				{
					cout << "Node " << postNodeIndex << " is the root" << endl;
				}
			#endif
			}

		#ifdef _TEST_STAT
			cerr << tabNodes.size() << " elements in tabNodes" << endl;
		#endif

			tabNodes.pop_back();
		}
		#ifdef _TEST_STAT
		else
		{
			cerr << "Node " << postNodeIndex << " is already in GSCC" << endl;
		}
		#endif
	}
	else
	{
		cerr << "Warning, postNodeIndex is not an assembly: " << postNodeIndex << endl;
	}
}
	#endif
#endif

void LoopStater::graph()
{
}

void LoopStater::trace()
{
}

// AssemblyStater.cc

// Local Includes
#include "AssemblyStater.h"

/****************************************************************************************************************************************/
/************************************************* Methodes de la classe AssemblyStater ************************************************/
/****************************************************************************************************************************************/

AssemblyStater::AssemblyStater()
{
#ifdef _NETWORK_STAT_MODE
	#ifdef _CENTRALITY_STAT_MODE

	assemblyBetweenness = new Accumulater();
	//assemblyBetweennessDistribution = new LogDistribution(-1,4,5);
	assemblyBetweennessDistribution = new LogDistribution(0,4,5);

	assemblyCentralBetweenness = new Accumulater();
	//assemblyCentralBetweennessDistribution = new LogDistribution(-8,0,5);
	assemblyCentralBetweennessDistribution = new LogDistribution(-4,0,5);

	assemblyGlobalEfficiency = new Accumulater();
	//assemblyGlobalEfficiencyDistribution = new LogDistribution(-8,0,5);
	assemblyGlobalEfficiencyDistribution = new LogDistribution(-2,0,5);

	assemblyLocalEfficiency = new Accumulater();
	//assemblyLocalEfficiencyDistribution = new LogDistribution(-8,0,5);
	assemblyLocalEfficiencyDistribution = new LogDistribution(-2,0,5);

	assemblyNbShortPathDistribution = new Distribution(NB_ASSEMBLIES+NB_INPUT_ASSEMBLIES+NB_OUTPUT_ASSEMBLIES);
	
		#ifdef _EDGE_BETWEENNESS_STAT_MODE
	//assemblyEdgeBetweennessDistribution = new LogDistribution(-1,4,5);
	assemblyEdgeBetweennessDistribution = new LogDistribution(0,4,5);
		#endif
	#endif

	#ifdef _GSCC_STAT_MODE
	SCComponentSizeDistribution = new Distribution(NB_ASSEMBLIES);
		
		#ifdef _INPUT_OUTPUT_GSCC_STAT_MODE
	inputSCComponentSizeDistribution = new Distribution(NB_ASSEMBLIES);
	outputSCComponentSizeDistribution = new Distribution(NB_ASSEMBLIES);	
		#endif
	//assemblyDiameterSizeDistribution = new MeanDistribution(NB_ASSEMBLIES);
	#endif
	
	#ifdef _PROJECTION_STAT_MODE
	
	countProjections = new Counter();
	
	// Excit/inhib
	countExcitProjections = new Counter();
	countInhibProjections = new Counter();

	// Input
	countExcitInputProjections = new Counter();
	countInhibInputProjections = new Counter();

	// Output
	countExcitOutputProjections = new Counter();
	countInhibOutputProjections = new Counter();

	// Self
	countExcitSelfProjections = new Counter();
	countInhibSelfProjections = new Counter();
	#endif

#endif
}

AssemblyStater::AssemblyStater(IndexedObject* io) : LoopStater(io)
{
#ifdef _NETWORK_STAT_MODE
	#ifdef _CENTRALITY_STAT_MODE
	assemblyBetweenness = new Accumulater();
	//assemblyBetweennessDistribution = new LogDistribution(-1,4,5);
	assemblyBetweennessDistribution = new LogDistribution(0,4,5);
	
	assemblyCentralBetweenness = new Accumulater();
	//assemblyCentralBetweennessDistribution = new LogDistribution(-8,0,5);
	assemblyCentralBetweennessDistribution = new LogDistribution(-4,0,5);
	
	assemblyGlobalEfficiency = new Accumulater();
	//assemblyGlobalEfficiencyDistribution = new LogDistribution(-8,0,5);
	assemblyGlobalEfficiencyDistribution = new LogDistribution(-2,0,5);
	
	assemblyLocalEfficiency = new Accumulater();
	//assemblyLocalEfficiencyDistribution = new LogDistribution(-8,0,5);
	assemblyLocalEfficiencyDistribution = new LogDistribution(-2,0,5);
	
	assemblyNbShortPathDistribution = new Distribution(NB_ASSEMBLIES+NB_INPUT_ASSEMBLIES+NB_OUTPUT_ASSEMBLIES);
	
		#ifdef _EDGE_BETWEENNESS_STAT_MODE
	//assemblyEdgeBetweennessDistribution = new LogDistribution(-1,4,5);
	assemblyEdgeBetweennessDistribution = new LogDistribution(0,4,5);
		#endif
	#endif

	#ifdef _GSCC_STAT_MODE
	SCComponentSizeDistribution = new Distribution(NB_ASSEMBLIES);
	
		#ifdef _INPUT_OUTPUT_GSCC_STAT_MODE
	inputSCComponentSizeDistribution = new Distribution(NB_ASSEMBLIES);
	outputSCComponentSizeDistribution = new Distribution(NB_ASSEMBLIES);	
		#endif
	//assemblyDiameterSizeDistribution = new MeanDistribution(NB_ASSEMBLIES);
	#endif
	
	#ifdef _PROJECTION_STAT_MODE
	countProjections = new Counter();
	
	// Excit/inhib
	countExcitProjections = new Counter();
	countInhibProjections = new Counter();

	// Input
	countExcitInputProjections = new Counter();
	countInhibInputProjections = new Counter();

	// Output
	countExcitOutputProjections = new Counter();
	countInhibOutputProjections = new Counter();

	// Self
	countExcitSelfProjections = new Counter();
	countInhibSelfProjections = new Counter();
	#endif

#endif
}

AssemblyStater::~AssemblyStater()
{
#ifdef _NETWORK_STAT_MODE
	
	cerr << "in ~AssemblyStater" << endl;
	
	#ifdef _CENTRALITY_STAT_MODE
		#ifdef _EDGE_BETWEENNESS_STAT_MODE
	delete(assemblyEdgeBetweennessDistribution);
		#endif
		 
	delete(assemblyNbShortPathDistribution);
	
	delete(assemblyBetweenness);
	delete(assemblyBetweennessDistribution);
	
	delete(assemblyCentralBetweenness);
	delete(assemblyCentralBetweennessDistribution);
	
	delete(assemblyGlobalEfficiency);
	delete(assemblyGlobalEfficiencyDistribution);
	
	delete(assemblyLocalEfficiency);
	delete(assemblyLocalEfficiencyDistribution);
	#endif

	#ifdef _GSCC_STAT_MODE
	delete(SCComponentSizeDistribution);
	
		#ifdef _INPUT_OUTPUT_GSCC_STAT_MODE
	delete(inputSCComponentSizeDistribution);
	delete(outputSCComponentSizeDistribution);
		#endif
	//delete(assemblyDiameterSizeDistribution);
	#endif
	
	#ifdef _PROJECTION_STAT_MODE
	delete(countProjections);
	
	// Excit/inhib
	delete(countExcitProjections);
	delete(countInhibProjections);

	// Input
	delete(countExcitInputProjections);
	delete(countInhibInputProjections);

	// Output
	delete(countExcitOutputProjections);
	delete(countInhibOutputProjections);

	// Self
	delete(countExcitSelfProjections);
	delete(countInhibSelfProjections);
	#endif
	

#endif

}

void AssemblyStater::openTracer()
{
}

void AssemblyStater::closeTracer()
{
}

void AssemblyStater::openGrapher()
{
}

void AssemblyStater::runGrapher()
{
}

void AssemblyStater::closeGrapher()
{
}

/****************************************************************************************************************************************/
/******************************************************* Compteurs **************************************************************/
/****************************************************************************************************************************************/

void AssemblyStater::initCounters()
{
#ifdef _NETWORK_STAT_MODE
	#ifdef _CENTRALITY_STAT_MODE
	
	if (assemblyBetweenness)
	{
		assemblyBetweenness->initAccu();
	}
	
	if (assemblyBetweennessDistribution)
	{
		assemblyBetweennessDistribution->initDistribution();
	}

	
	
	if (assemblyCentralBetweenness)
	{
		assemblyCentralBetweenness->initAccu();
	}
	
	if (assemblyCentralBetweennessDistribution)
	{
		assemblyCentralBetweennessDistribution->initDistribution();
	}

	
	if (assemblyGlobalEfficiencyDistribution)
	{
		assemblyGlobalEfficiencyDistribution->initDistribution();
	}
	
	if (assemblyGlobalEfficiency)
	{
		assemblyGlobalEfficiency->initAccu();
	}
	
	if (assemblyLocalEfficiencyDistribution)
	{
		assemblyLocalEfficiencyDistribution->initDistribution();
	}
	
	if (assemblyLocalEfficiency)
	{
		assemblyLocalEfficiency->initAccu();
	}
	
	for (int i=0;i<NB_ASSEMBLIES;i++)
	{
		assemblyBetweennessRepartition[i] = -1.0;
	}
	
	
	for (int i=0;i<NB_ASSEMBLIES;i++)
	{
		assemblyCentralBetweennessRepartition[i] = -1.0;
	}
	
	for (int i=0;i<NB_ASSEMBLIES;i++)
	{
		assemblyGlobalEfficiencyRepartition[i] = -1.0;
	}
	
	for (int i=0;i<NB_ASSEMBLIES;i++)
	{
		assemblyLocalEfficiencyRepartition[i] = -1.0;
	}
	
	for (int i=0;i< NB_ASSEMBLIES;i++)
	{
		for (int j=0;j< NB_ASSEMBLIES;j++)
		{
			assemblyEfficiency[i][j] = -1.0;	
		}
	}
	
	for (int i=0;i<NB_ASSEMBLIES;i++)
	{
		assemblyShortPathRepartition[i] = -1;
	}

	for (int i=0;i<NB_ASSEMBLIES;i++)
	{
		assemblyNoShortPathRepartition[i] = -1;
	}
	
	
	if (assemblyNbShortPathDistribution)
	{
		assemblyNbShortPathDistribution->initDistribution();
	}
	
		#ifdef _EDGE_BETWEENNESS_STAT_MODE
	if (assemblyEdgeBetweennessDistribution)
	{
		assemblyEdgeBetweennessDistribution->initDistribution();
		
	}

	assemblyMaxEdgeBetweenness = 0.0;
	
			#ifdef _CLUSTER_STAT_MODE

	preAssemblyMaxEdgeBetweenness = -1;
	postAssemblyMaxEdgeBetweenness = -1;
			#endif
		#endif	
	#endif
#endif
}

void AssemblyStater::flushCounters()
{
}

#ifdef _NETWORK_STAT_MODE
	#ifdef _CENTRALITY_STAT_MODE
void AssemblyStater::computeAssemblyEfficiency()
{
	
	for (int i=0;i< NB_ASSEMBLIES;i++)
	{
		for (int j=0;j< NB_ASSEMBLIES;j++)
		{
			if (0.0 <= efficiency[i][j])
			{
				assemblyEfficiency[i][j] = efficiency[i][j];
			}	
		}
	}
	
	for (int i=0;i< NB_ASSEMBLIES;i++)
	{
		if (0.0 <= nodeGlobalEfficiency[i])
		{
			assemblyGlobalEfficiency->accumulate(nodeGlobalEfficiency[i]);
			assemblyGlobalEfficiencyRepartition[i] = nodeGlobalEfficiency[i];
			((LogDistribution*) assemblyGlobalEfficiencyDistribution)->count((double) nodeGlobalEfficiency[i]);
		}
	}
	
	for (int i=0;i< NB_ASSEMBLIES;i++)
	{
		if (0.0 <= nodeLocalEfficiency[i])
		{
			assemblyLocalEfficiency->accumulate(nodeLocalEfficiency[i]);
			assemblyLocalEfficiencyRepartition[i] = nodeLocalEfficiency[i];
			((LogDistribution*) assemblyLocalEfficiencyDistribution)->count((double) nodeLocalEfficiency[i]);
		}
	}
}

void AssemblyStater::computeAssemblyBetweenness()
{
	for (int i=0;i<NB_ASSEMBLIES;i++)
	{
		if (0.0 <= nodeBetweenness[i].getAccu())
		{
			assemblyBetweennessRepartition[i] = nodeBetweenness[i].getAccu();
			
			((LogDistribution*) assemblyBetweennessDistribution)->count((double) nodeBetweenness[i].getAccu());
			assemblyBetweenness->accumulate(nodeBetweenness[i].getAccu());
		}
		else
		{
			cerr << "Warning, nodeBetweenness is negative " << endl;
		}
	}
}

void AssemblyStater::computeAssemblyCentralBetweenness()
{
	// Plus haute nodeBetweenness
	double highestBetwenness = 0.0;

	for (int i=0;i<NB_ASSEMBLIES;i++)
	{
		if (nodeBetweenness[i].getCounter() != 0)
		{
			if (highestBetwenness <= nodeBetweenness[i].getAccu())
			{
				highestBetwenness = nodeBetweenness[i].getAccu();
			}
		}
	}

	for (int i=0;i<NB_ASSEMBLIES;i++)
	{
		if (nodeBetweenness[i].getCounter() != 0)
		{
			double curCentralBetweenness = (((double) fabs(((double) (highestBetwenness - nodeBetweenness[i].getAccu()))*(NB_ASSEMBLIES+2)))/((double) ((NB_ASSEMBLIES-2)*(NB_ASSEMBLIES+1)*(NB_ASSEMBLIES-1))));
			
			assemblyCentralBetweenness->accumulate(curCentralBetweenness);
			
			((LogDistribution*) assemblyCentralBetweennessDistribution)->count((double) curCentralBetweenness);
			
			assemblyCentralBetweennessRepartition[i] = curCentralBetweenness;
		}
	}
}

void AssemblyStater::computeAssemblyShortPaths()
{
	for (int i=0;i<NB_ASSEMBLIES;i++)
	{
		assemblyShortPathRepartition[i] = shortPathRepartition[i].getCounter();
		assemblyNoShortPathRepartition[i] = noShortPathRepartition[i].getCounter();
		
		assemblyNbShortPathDistribution->count((int) shortPathRepartition[i].getCounter());
	}
	
	if (shortPathLengthDistribution)
	{
		assemblyShortPathLengthDistribution = shortPathLengthDistribution;
	}
	else
	{
		cerr << "Warning, shortPathLengthDistribution should be inited" << endl;
	}
}		
		#ifdef _EDGE_BETWEENNESS_STAT_MODE
void AssemblyStater::computeAssemblyEdgeBetweennessDistribution()
{
	for (int i=0;i<NB_ASSEMBLIES;i++)
	{
		for (int j=0;j<NB_ASSEMBLIES;j++)
		{
			if (edgeBetweenness[i][j].getCounter() != 0)
			{
				((LogDistribution*) assemblyEdgeBetweennessDistribution)->count((double) edgeBetweenness[i][j].getAccu());
			}
		}
	}	
}

void AssemblyStater::computeAssemblyMaxEdgeBetweenness()
{
	for (int i=0;i<NB_ASSEMBLIES;i++)
	{
		for (int j=0;j<NB_ASSEMBLIES;j++)
		{
			if (edgeBetweenness[i][j].getCounter() != 0)
			{
				if (assemblyMaxEdgeBetweenness  < edgeBetweenness[i][j].getAccu())
				{
					assemblyMaxEdgeBetweenness = edgeBetweenness[i][j].getAccu();
					preAssemblyMaxEdgeBetweenness = i;
					postAssemblyMaxEdgeBetweenness = j;
				}
			}
		}
	}			
			#ifdef _GN_CLUSTER_STAT_MODE
	cout << "assemblyMaxEdgeBetweenness = " << assemblyMaxEdgeBetweenness << "(" << preAssemblyMaxEdgeBetweenness << ";" << postAssemblyMaxEdgeBetweenness << ")" << endl;
			#endif
}
		
			#ifdef _GN_CLUSTER_STAT_MODE
double AssemblyStater::getAssemblyMaxEdgeBetweenness()
{
	return assemblyMaxEdgeBetweenness;
}

int AssemblyStater::getPreAssemblyMaxEdgeBetweenness()
{
	return preAssemblyMaxEdgeBetweenness;
}

int AssemblyStater::getPostAssemblyMaxEdgeBetweenness()
{
	return postAssemblyMaxEdgeBetweenness;
}
			#endif
		#endif
		#ifdef _CLUSTER_STAT_MODE
			#ifdef _EFFICIENCY_CLUSTER_STAT_MODE
double AssemblyStater::getAssemblyGlobalEfficiency()
{
	return assemblyGlobalEfficiency->getMean();
}
			#endif
		#endif
	#endif

	#ifdef _GSCC_STAT_MODE
void AssemblyStater::initSCComponents()
{
	if (SCComponentSizeDistribution)
	{
		SCComponentSizeDistribution->initDistribution();
	}
	
	maxSCComponentSize = 0;
}

void AssemblyStater::computeSCComponents()
{
	vector<int>::iterator it = nbStrongComponents.begin();
	vector<int>::iterator end = nbStrongComponents.end();

	int firstTabGSCCNodeIndex=0;
	
	while (it != end)
	{
		if (maxSCComponentSize < (int) *it)
		{
			maxSCComponentSize = (int) *it;
		}

		SCComponentSizeDistribution->count((int) *it);
		
		firstTabGSCCNodeIndex+=(int) *it;
		
		it++;
	}
}
	
		#ifdef _INPUT_OUTPUT_GSCC_STAT_MODE
void AssemblyStater::initInputOutputSCCCounters()
{
	if (inputSCComponentSizeDistribution)
	{
		inputSCComponentSizeDistribution->initDistribution();
	}
	
	if (outputSCComponentSizeDistribution)
	{
		outputSCComponentSizeDistribution->initDistribution();
	}
	
	
	for (int i=0;i<NB_INPUT_ASSEMBLIES;i++)
	{
		inputSCCFractionRepartition[i] = 0.0;
	}
	
	for (int i=0;i<NB_OUTPUT_ASSEMBLIES;i++)
	{
		outputSCCFractionRepartition[i] = 0.0;
	}
}

void AssemblyStater::statInputSCC(EDAssembly* inputAssembly)
{
	if (inputAssembly->getNature() == INPUT)
	{
		int inputAssemblyIndex = inputAssembly->getIndex() - NB_ASSEMBLIES;
		
		int nbInputProjections = 0;
		int nbInputProjectionsLinkedToSCC = 0;
		
		std::vector<Link*>::iterator it = ((EDAssembly*) inputAssembly)->outputLinks.begin();
		std::vector<Link*>::iterator end = ((EDAssembly*) inputAssembly)->outputLinks.end();

		while (it!=end)
		{
			Node* postAssembly = ((Projection*) *it)->getPostNode();
			
			int tabGSCCIndex = 0;
			
			std::vector<Node*>::iterator itNode = tabGSCCNodes.begin();
			std::vector<Node*>::iterator endNode = tabGSCCNodes.end();

			while (itNode != endNode)
			{
				if (((Node*) postAssembly)->isSameIndex((Node*) *itNode))
				{
			#ifdef _TEST_STAT
					cout << "Found node linked to input in GSCC" << endl;
			#endif
					break;
				}
				itNode++;
				tabGSCCIndex++;
			}
			
			int curIndex = 0;
			
			std::vector<int>::iterator itSize = nbStrongComponents.begin();
			std::vector<int>::iterator endSize = nbStrongComponents.end();
			
			while (itSize != endSize)
			{
				if (curIndex < tabGSCCIndex && tabGSCCIndex < curIndex + *itSize)
				{	
			#ifdef _TEST_STAT
					cout << "Corresponding size = " << *itSize << endl;
			#endif	
					inputSCComponentSizeDistribution->count(*itSize);
					nbInputProjectionsLinkedToSCC++;
									
					break;
				}
				
				itSize++;
				
			}
			it++;
					
			nbInputProjections++;
		}
		
		if (nbInputProjections != 0)
		{
			inputSCCFractionRepartition[inputAssemblyIndex] = ((double) nbInputProjectionsLinkedToSCC)/((double) nbInputProjections);
		}
			
			#ifdef _TEST_STAT
		cout << "Fraction of projection linked to SCC for input assembly "<< inputAssemblyIndex << " = " << inputSCCFractionRepartition[inputAssemblyIndex] << endl;
			#endif	
	}
	else
	{
		cerr << "Warning, EDAssembly should be an input" << endl;
	}
}

void AssemblyStater::statOutputSCC(EDAssembly* outputAssembly)
{
	if (outputAssembly->getNature() == OUTPUT)
	{
		int outputAssemblyIndex = outputAssembly->getIndex() - NB_ASSEMBLIES - NB_INPUT_ASSEMBLIES;
		
		int nbOutputProjections = 0;
		int nbOutputProjectionsLinkedToSCC = 0;
		
		std::vector<Link*>::iterator it = ((EDAssembly*) outputAssembly)->inputLinks.begin();
		std::vector<Link*>::iterator end = ((EDAssembly*) outputAssembly)->inputLinks.end();

		while (it!=end)
		{
			Node* preAssembly = ((Projection*) *it)->getPreNode();
			
			int tabGSCCIndex = 0;
			
			std::vector<Node*>::iterator itNode = tabGSCCNodes.begin();
			std::vector<Node*>::iterator endNode = tabGSCCNodes.end();

			while (itNode != endNode)
			{
				if (((Node*) preAssembly)->isSameIndex((Node*) *itNode))
				{
			#ifdef _TEST_STAT
					cout << "Found node linked to output in GSCC" << endl;
			#endif
					break;
				}
				itNode++;
				tabGSCCIndex++;
			}
			
			int curIndex = 0;
			
			std::vector<int>::iterator itSize = nbStrongComponents.begin();
			std::vector<int>::iterator endSize = nbStrongComponents.end();
			
			while (itSize != endSize)
			{
				if (curIndex < tabGSCCIndex && tabGSCCIndex < curIndex + *itSize)
				{	
			#ifdef _TEST_STAT
					cout << "Corresponding size = " << *itSize << endl;
			#endif	
					outputSCComponentSizeDistribution->count(*itSize);
					nbOutputProjectionsLinkedToSCC++;
									
					break;
				}
				
				itSize++;
				
			}
			it++;
					
			nbOutputProjections++;
		}
		
		if (nbOutputProjections != 0)
		{
			outputSCCFractionRepartition[outputAssemblyIndex] = ((double) nbOutputProjectionsLinkedToSCC)/((double) nbOutputProjections);
		}
			
			#ifdef _TEST_STAT
		cout << "Fraction of projection linked to SCC for output assembly "<< outputAssemblyIndex << " = " << outputSCCFractionRepartition[outputAssemblyIndex] << endl;
			#endif	
	}
	else
	{
		cerr << "Warning, EDAssembly should be an output" << endl;
	}
}

		#endif
	#endif
	
// Stats Projections
	#ifdef _PROJECTION_STAT_MODE
void AssemblyStater::initProjectionCounters()
{
	if (countProjections)
	{
		countProjections->initCounter();
	}
	else
	{
		cerr << "Warning, countProjections should be inited" << endl;
	}


	// Excit/Inhib
	if (countExcitProjections)
	{
		countExcitProjections->initCounter();
	}
	else
	{
		cerr << "Warning, countExcitProjections should be inited" << endl;
	}

	if (countInhibProjections)
	{
		countInhibProjections->initCounter();
	}
	else
	{
		cerr << "Warning, countInhibProjections should be inited" << endl;
	}

	// Input
	if (countExcitInputProjections)
	{
		countExcitInputProjections->initCounter();
	}
	else
	{
		cerr << "Warning, countExcitInputProjections should be inited" << endl;
	}

	if (countInhibInputProjections)
	{
		countInhibInputProjections->initCounter();
	}
	else
	{
		cerr << "Warning, countInhibInputProjections should be inited" << endl;
	}

	// Output
	if (countExcitOutputProjections)
	{
		countExcitOutputProjections->initCounter();
	}
	else
	{
		cerr << "Warning, countExcitOutputProjections should be inited" << endl;
	}

	if (countInhibOutputProjections)
	{
		countInhibOutputProjections->initCounter();
	}
	else
	{
		cerr << "Warning, countInhibOutputProjections should be inited" << endl;
	}

	// Self
	if (countExcitSelfProjections)
	{
		countExcitSelfProjections->initCounter();
	}
	else
	{
		cerr << "Warning, countExcitSelfProjections should be inited" << endl;
	}

	if (countInhibSelfProjections)
	{
		countInhibSelfProjections->initCounter();
	}
	else
	{
		cerr << "Warning, countInhibSelfProjections should be inited" << endl;
	}
}

void AssemblyStater::statPostProjection(Projection* curProjection)
{
	Node* preAssembly = curProjection->getPreNode();
	Node* postAssembly = curProjection->getPostNode();
	
	int curProjectionNature = curProjection->getProjectionNature();
		
	countProjections->count();
	
	if (curProjectionNature == EXCIT)
	{
		// Projection excitatrice
		countExcitProjections->count();
		
		if (preAssembly->getIndex() == postAssembly->getIndex())
		{
			countExcitSelfProjections->count();
		}
		else if (((Assembly*) preAssembly)->getNature() == INPUT)
		{
			countExcitInputProjections->count();
		}
		else if (((Assembly*) postAssembly)->getNature() == OUTPUT)
		{
			countExcitOutputProjections->count();
		}		
	}
	else if (curProjectionNature == INHIB)
	{
		// Projection inhibitrice
		countInhibProjections->count();
		
		if (preAssembly->getIndex() == postAssembly->getIndex())
		{
			countInhibSelfProjections->count();
		}
		else if (((Assembly*) preAssembly)->getNature() == INPUT)
		{
			countInhibInputProjections->count();
		}
		else if (((Assembly*) postAssembly)->getNature() == OUTPUT)
		{
			countInhibOutputProjections->count();
		}	
	}
}

void AssemblyStater::statPostProjections(EDAssembly* postAssembly)
{
	if (((EDAssembly*) postAssembly)->outputLinks.size()!=0)
	{
		std::vector<Link*>::iterator it = ((EDAssembly*) postAssembly)->outputLinks.begin();
		std::vector<Link*>::iterator end = ((EDAssembly*) postAssembly)->outputLinks.end();

		while (it!=end)
		{
		
			statPostProjection(((Projection*) *it));
			it++;
		}
	}
		#ifdef _TEST_STAT
	else
	{
		cout << "PostProjections is empty for assembly" << postAssembly->getIndex() << endl;
	}
		#endif
}
	#endif

#endif

void AssemblyStater::graph()
{
}

void AssemblyStater::trace()
{
}

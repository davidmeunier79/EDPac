// EDNetwork.cc

// Local Includes
#include "EDNetwork.h"

/****************************************************************************************************************************************/
/****************************************************** Methodes de la classe EDNetwork *************************************************/
/****************************************************************************************************************************************/

#ifdef _TRANSITION_STAT_MODE
int EDNetwork::TRANSITION_TIME_LENGTH=10;
#endif

EDNetwork::EDNetwork()
{
	initRandom();

#ifdef _DISCRETE_EXP_MODE
	cout << "*** EDNetwork *** initing discreteExp" << endl;
	initDiscreteExp();
#endif

#ifdef _LINK_INPUT_STAT_MODE
	inputLinkStater=0;
	
	#ifdef _STAT_TEST
	cerr << "Input link stater " << inputLinkStater<< endl;
	#endif
#endif

}

EDNetwork::EDNetwork(int newNbInputBuffers, int newNbOutputBuffers): SynchroModule(newNbInputBuffers,newNbOutputBuffers)
{
	initSynchroBuffer();

	initRandom();

#ifdef _DISCRETE_EXP_MODE
	cout << "*** EDNetwork *** initing discreteExp" << endl;
	initDiscreteExp();
#endif

	
	cout << "Initing graphical display for EDNetwork " << getTopoIndex() << endl;
	displayer= new TopologyDisplayer();

#ifndef _INCREMENTAL_TOPOLOGY_MODE
	#ifdef _TEST
	cout << "*** EDNetwork *** building hidden assemblies" << endl;
	#endif
	initAssemblies();
	
	#ifdef _GRAPHICAL_DISPLAY_MODE
	
			#ifdef _SAVE_TOPOLOGY_DISPLAY_MODE
	system("rm Network*.xpm");	
	system("rm Network*.jpeg");
	
	system("rm Network*.sh");
	system("rm Network*.par_mpg");
			#endif
			
	initTopologyDisplayer((TopologyDisplayer*) displayer);
	#endif
#endif

	initInputBuffers();
	initOutputBuffers();
	

	#ifdef _SAVE_ORDERED_PROJECTIONS_MODE
	
	system("rm OrderedProjections.txt");
	
	tabOrderedProjectionsFile = new IOFile();
	
	tabOrderedProjectionsFile->openOutputFile("OrderedProjections");
	
	if (tabOrderedProjectionsFile->isOpen())
	{
		cout << "*** EDNetwork *** tabOrderedProjectionsFile is open" << endl;
	}
	else
	{
		cerr << "Warning, *** EDNetwork *** tabOrderedProjectionsFile is not open" << endl;
	}
	#else
	
		#ifdef _LOAD_ORDERED_PROJECTIONS_MODE
	tabOrderedProjectionsFile = new IOFile();
	
	tabOrderedProjectionsFile->openInputFile("OrderedProjections");
	
	if (tabOrderedProjectionsFile->isOpen())
	{
		cout << "*** EDNetwork *** tabOrderedProjectionsFile is open" << endl;
	}
	else
	{
		cerr << "Warning, *** EDNetwork *** tabOrderedProjectionsFile is not open" << endl;
	}
		#endif

	#endif
	
	#ifdef _GRAPHICAL_DISPLAY_MODE
	// Réinitialise les synpases des assemblèes d'entrees
	for (int i=0;i<nbInputBuffers;i++)
	{
		(((Assembly*) (EDAssembly*) ((InputAssembly*) inputBuffers[i])))->initAssemblyDisplayer((AssemblyDisplayer*) displayer);
	}

	// Réinitialise les synpases des assemblèes d'entrees
	for (int i=0;i<nbOutputBuffers;i++)
	{
		(((Assembly*) (EDAssembly*) ((OutputAssembly*) outputBuffers[i])))->initAssemblyDisplayer((AssemblyDisplayer*) displayer);
	}
	#endif

	//#ifdef _TEST
	cout << "Initing TimeRef = 0" << endl;
	//#endif
	timeRef=0;

#ifdef _LINK_INPUT_STAT_MODE
	inputLinkStater=0;
	
	#ifdef _STAT_TEST
	cerr << "Input link stater " << inputLinkStater<< endl;
	#endif
#endif
}

void EDNetwork::initInputBuffers()
{
	// Inputs visuels
	for (int i=FIRST_VISIO_CHANNEL_ETIQUETTE; i<LAST_VISIO_CHANNEL_ETIQUETTE;i++)
	{
		inputBuffers[i]=new InputAssembly(VISIO_BUFFER_SIZE,i,GRAPHICAL_ENVIRONNEMENT_MPI_ID);
	}

	// Inputs auditifs
	inputBuffers[LEFT_AUDIO_CHANNEL_ETIQUETTE]=new InputAssembly(AUDIO_BUFFER_SIZE,LEFT_AUDIO_CHANNEL_ETIQUETTE,GRAPHICAL_ENVIRONNEMENT_MPI_ID);
	inputBuffers[RIGHT_AUDIO_CHANNEL_ETIQUETTE]=new InputAssembly(AUDIO_BUFFER_SIZE,RIGHT_AUDIO_CHANNEL_ETIQUETTE,GRAPHICAL_ENVIRONNEMENT_MPI_ID);

#ifdef _PREDATOR_CONTACT_PUNISHES_PACMAN_MODE
	inputBuffers[PUNISH_CHANNEL_ETIQUETTE]=new InputAssembly(CONDITIONNING_BUFFER_SIZE,PUNISH_CHANNEL_ETIQUETTE,GRAPHICAL_ENVIRONNEMENT_MPI_ID);
#endif

#ifdef _PREY_CONTACT_REWARDS_PACMAN_MODE
	inputBuffers[REWARD_CHANNEL_ETIQUETTE]=new InputAssembly(CONDITIONNING_BUFFER_SIZE,REWARD_CHANNEL_ETIQUETTE,GRAPHICAL_ENVIRONNEMENT_MPI_ID);
#endif
}

void EDNetwork::initOutputBuffers()
{
	outputBuffers[0]=new OutputAssembly(MOTOR_PATTERN_BUFFER_SIZE,MOVE_BODY_ON_LEFT_CHANNEL_ETIQUETTE,GRAPHICAL_ENVIRONNEMENT_MPI_ID);
	outputBuffers[1]=new OutputAssembly(MOTOR_PATTERN_BUFFER_SIZE,MOVE_BODY_ON_RIGHT_CHANNEL_ETIQUETTE,GRAPHICAL_ENVIRONNEMENT_MPI_ID);
	outputBuffers[2]=new OutputAssembly(MOTOR_PATTERN_BUFFER_SIZE,MOVE_HEAD_ON_LEFT_CHANNEL_ETIQUETTE,GRAPHICAL_ENVIRONNEMENT_MPI_ID);
	outputBuffers[3]=new OutputAssembly(MOTOR_PATTERN_BUFFER_SIZE,MOVE_HEAD_ON_RIGHT_CHANNEL_ETIQUETTE,GRAPHICAL_ENVIRONNEMENT_MPI_ID);
}

EDNetwork::~EDNetwork()
{
#ifdef _TEST
	cout << "~EDNetwork" << endl;
#endif

#ifdef _GRAPHICAL_DISPLAY_MODE
	cout << "Freeing graphical display for EvoNetwork " << getTopoIndex() << endl;
	delete((TopologyDisplayer*) displayer);
#endif

	deleteAssemblies();

	for (int i=0;i<nbInputBuffers;i++)
	{
#ifdef _TEST
		cout << "Destroying projections of input assembly " << ((EDAssembly*) inputBuffers[i])->getIndex() << endl;
#endif
		delete((InputAssembly*) inputBuffers[i]);
	}

	for (int i=0;i<nbOutputBuffers;i++)
	{
#ifdef _TEST
		cout << "Destroying projections of output assembly " << ((EDAssembly*) outputBuffers[i])->getIndex() << endl;
#endif
		delete(((OutputAssembly*) outputBuffers[i]));
	}
	
#ifdef _SAVE_ORDERED_PROJECTIONS_MODE
	if (tabOrderedProjectionsFile->isOpen())
	{
		tabOrderedProjectionsFile->closeFile();
	}
	
	delete(tabOrderedProjectionsFile);
#else
	#ifdef _LOAD_ORDERED_PROJECTIONS_MODE
	if (tabOrderedProjectionsFile->isOpen())
	{
		tabOrderedProjectionsFile->closeFile();
	}
	
	delete(tabOrderedProjectionsFile);
	#endif
#endif
}

void EDNetwork::initAssemblies()
{
	int compt=0;
	while (compt<NB_ASSEMBLIES)
	{
		addNewAssembly();
		compt++;
	}
}

void EDNetwork::addNewAssembly()
{
	EDAssembly* newAssembly= new EDAssembly(NB_NEURONS_EACH_ASSEMBLY);
	addAssembly(newAssembly);
}

void EDNetwork::deleteAssemblies()
{
	std::vector<Assembly*>::iterator it=assemblies.begin();
	std::vector<Assembly*>::iterator end=assemblies.end();

	while (it!=end)
	{
#ifdef _TEST
		cout << "Destroying assembly " << ((EDAssembly*) *it)->getIndex() << endl;
#endif
		delete((EDAssembly*) *it);
		it++;
	}
	
	assemblies.erase(assemblies.begin(),assemblies.end());
}

#ifdef _TOPOLOGY_PROJECTION_MODE
void EDNetwork::buildProjections()
{
	if (synchroBuffer->getSize()==NB_GENES_EACH_CHROMOSOME)
	{

		int comptProjections=0;
	
		while (comptProjections<NB_PROJECTIONS_EACH_CHROMOSOME)
		{

	#if (NB_GENES_EACH_PROJECTION==3)
		#ifdef _INCREMENTAL_TOPOLOGY_MODE
			
			#ifdef _GA_TEST
			cout << "***(" << comptProjections << "/" << NB_PROJECTIONS_EACH_CHROMOSOME << ") ";
			cout << "Projection :(" << ((double) (*synchroBuffer)[comptProjections*NB_GENES_EACH_PROJECTION])/((double) NB_PRE_ASSEMBLIES);
			cout << "," << (int) (*synchroBuffer)[comptProjections*NB_GENES_EACH_PROJECTION+1];
			cout << "," << ((double) (*synchroBuffer)[comptProjections*NB_GENES_EACH_PROJECTION+2])/((double) NB_POST_ASSEMBLIES) << ")" << endl;
			#endif
			
			if (comptProjections % NB_PROJECTIONS_EACH_ASSEMBLY == 0)
			{
				addNewAssembly();
			}
			
			buildIncrementalPostProjection
			(
			((double) (*synchroBuffer)[comptProjections*NB_GENES_EACH_PROJECTION])/((double) NB_PRE_ASSEMBLIES),
			(int) (*synchroBuffer)[comptProjections*NB_GENES_EACH_PROJECTION+1],
			((double) (*synchroBuffer)[comptProjections*NB_GENES_EACH_PROJECTION+2])/((double) NB_POST_ASSEMBLIES)
			);
		#else
			#ifdef _GA_TEST
			cout << "***(" << comptProjections << "/" << NB_PROJECTIONS_EACH_CHROMOSOME << ") ";
			cout << "Projection :(" << (int) (*synchroBuffer)[comptProjections*NB_GENES_EACH_PROJECTION];
			cout << "," << (int) (*synchroBuffer)[comptProjections*NB_GENES_EACH_PROJECTION+1];
			cout << "," << (int) (*synchroBuffer)[comptProjections*NB_GENES_EACH_PROJECTION+2] << ")" << endl;
			#endif
			
			buildPostProjection
			(
			(int) (*synchroBuffer)[comptProjections*NB_GENES_EACH_PROJECTION],
			(int) (*synchroBuffer)[comptProjections*NB_GENES_EACH_PROJECTION+1],
			(int) (*synchroBuffer)[comptProjections*NB_GENES_EACH_PROJECTION+2]
			);
		#endif
	#else
			cerr << "Warning, NB_GENES_EACH_PROJECTION should be 3" << endl;
	#endif

	#ifdef _GRAPHICAL_DISPLAY_MODE
			((TopologyDisplayer*) displayer)->flushDisplay();
	#endif
			comptProjections++;
		}
	//#ifdef GA_TEST
		cout << "Nb Projections: " << comptProjections << endl;
	//#endif
	}
	else
	{
		cerr << "Incompatible size of chromoBuffer: " << synchroBuffer->getSize() << endl;
		return;
	}

}

	#ifdef _INCREMENTAL_TOPOLOGY_MODE
void EDNetwork::buildIncrementalProjections()
{
	if (synchroBuffer->getSize()==NB_GENES_EACH_CHROMOSOME)
	{
		EDAssembly::nbEDAssemblies = 0;
		
		int comptProjections=0;
	
		while (comptProjections<NB_PROJECTIONS_EACH_CHROMOSOME)
		{

		#if (NB_GENES_EACH_PROJECTION==3)
			
			#ifdef _GA_TEST
			cout << "***(" << comptProjections << "/" << NB_PROJECTIONS_EACH_CHROMOSOME << ") ";
			cout << "Projection :(" << ((double) (*synchroBuffer)[comptProjections*NB_GENES_EACH_PROJECTION])/((double) NB_PRE_ASSEMBLIES);
			cout << "," << (int) (*synchroBuffer)[comptProjections*NB_GENES_EACH_PROJECTION+1];
			cout << "," << ((double) (*synchroBuffer)[comptProjections*NB_GENES_EACH_PROJECTION+2])/((double) NB_POST_ASSEMBLIES) << ")" << endl;
			#endif
			
			if (comptProjections % NB_PROJECTIONS_EACH_ASSEMBLY == 0)
			{
				EDAssembly::nbEDAssemblies++;
			}
			
			buildIncrementalPostProjection
			(
			((double) (*synchroBuffer)[comptProjections*NB_GENES_EACH_PROJECTION])/((double) NB_PRE_ASSEMBLIES),
			(int) (*synchroBuffer)[comptProjections*NB_GENES_EACH_PROJECTION+1],
			((double) (*synchroBuffer)[comptProjections*NB_GENES_EACH_PROJECTION+2])/((double) NB_POST_ASSEMBLIES)
			);
		#else
			cerr << "Warning, NB_GENES_EACH_PROJECTION should be 3" << endl;
		#endif

		#ifdef _GRAPHICAL_DISPLAY_MODE
			((TopologyDisplayer*) displayer)->flushDisplay();
		#endif
			comptProjections++;
		}
		//#ifdef GA_TEST
		cout << "Nb Projections: " << comptProjections << endl;
		//#endif
	}
	else
	{
		cerr << "Incompatible size of chromoBuffer: " << synchroBuffer->getSize() << endl;
		return;
	}	
}
	
void EDNetwork::buildIncrementalPostProjection(double relativePreAssemblyIndex, int projectionCode, double relativePostAssemblyIndex)
{
	int preAssemblyIndex = (int) ((int) NB_INPUT_ASSEMBLIES+EDAssembly::nbEDAssemblies)*relativePreAssemblyIndex;
	int postAssemblyIndex = (int) ((int) NB_OUTPUT_ASSEMBLIES+EDAssembly::nbEDAssemblies)*relativePostAssemblyIndex;
	
	buildPostProjection(preAssemblyIndex,projectionCode,postAssemblyIndex);
}
	#endif
	
void EDNetwork::buildPostProjection(int preAssemblyIndex, int projectionCode, int postAssemblyIndex)
{
	EDAssembly* preAssembly;
	EDAssembly* postAssembly;
	double projectionRatio;

	// Assemblée pré
	if (0<=preAssemblyIndex && preAssemblyIndex<nbInputBuffers)
	{
	#ifdef _GA_TEST
		cout << "preAssembly is an input assembly (index: 0<" << preAssemblyIndex << "<" << nbInputBuffers << ")" << endl;
	#endif
		preAssembly=(EDAssembly*)((InputAssembly*) inputBuffers[preAssemblyIndex]);
	#ifdef _GRAPHICAL_DISPLAY_MODE
		((AssemblyDisplayer*) displayer)->display(preAssembly);
	#endif
	}
	else if (nbInputBuffers<=preAssemblyIndex && preAssemblyIndex<nbInputBuffers+assemblies.size())
	{
	#ifdef _GA_TEST
		cout << "preAssembly is an hidden assembly (index: 0<" << preAssemblyIndex-nbInputBuffers << "<" << assemblies.size() << ")" << endl;
	#endif
		preAssembly=(EDAssembly*) assemblies[preAssemblyIndex-nbInputBuffers];
	#ifdef _GRAPHICAL_DISPLAY_MODE
		((AssemblyDisplayer*) displayer)->display(preAssembly);
	#endif
	}
	else
	{
	#ifdef _GA_TEST
		cerr << "Warning, incompatible index for pre assembly: " << preAssemblyIndex << endl;
	#endif
		return;
	}

	// Assemblée post
	if (0<=postAssemblyIndex && postAssemblyIndex<nbOutputBuffers)
	{
	#ifdef _GA_TEST
		cout << "postAssembly is an output assembly (index: 0<" << postAssemblyIndex << "<" << nbOutputBuffers << ")" << endl;
	#endif
		postAssembly=(EDAssembly*)((OutputAssembly*) outputBuffers[postAssemblyIndex]);
	#ifdef _GRAPHICAL_DISPLAY_MODE
		((AssemblyDisplayer*) displayer)->display(postAssembly);
	#endif
	}
	else if (nbOutputBuffers<=postAssemblyIndex && postAssemblyIndex<nbOutputBuffers+assemblies.size())
	{
	#ifdef _GA_TEST
		cout << "postAssembly is an hidden assembly (index: 0<" << postAssemblyIndex-nbOutputBuffers << "<" << assemblies.size() << ")" << endl;
	#endif
		postAssembly=(EDAssembly*) assemblies[postAssemblyIndex-nbOutputBuffers];

	#ifdef _GRAPHICAL_DISPLAY_MODE
		((AssemblyDisplayer*) displayer)->display(postAssembly);
	#endif
	}
	else
	{
		cerr << "Warning, incompatible index for post assembly: " << postAssemblyIndex << endl;
		return;
	}
	
	if (0<=projectionCode && projectionCode<2*MAX_PROJECTION_CODE)
	{
		if (0<=projectionCode && projectionCode<MAX_PROJECTION_CODE)
		{
			// Construction de la projection
			preAssembly->buildPostExcitProjection(postAssembly);
			

			// Affichage de la projection
		#ifdef _GRAPHICAL_DISPLAY_MODE
			((TopologyDisplayer*) displayer)->traceProjection(preAssemblyIndex,postAssemblyIndex,1,"bleu");
		#endif

		#ifdef _GA_TEST
			cout << "projectionRatio: " << 1.0 << endl;
		#endif
		}
		else if (MAX_PROJECTION_CODE<=projectionCode && projectionCode<2*MAX_PROJECTION_CODE)
		{

			// Construction de la projection
			preAssembly->buildPostInhibProjection(postAssembly);
			

			// Affichage de la projection
		#ifdef _GRAPHICAL_DISPLAY_MODE
			//((TopologyDisplayer*) displayer)->traceProjection(preAssemblyIndex,postAssemblyIndex,1,"jaune");
			((TopologyDisplayer*) displayer)->traceProjection(preAssemblyIndex,postAssemblyIndex,1,"rouge");
		#endif

		#ifdef _GA_TEST
			cout << "projectionRatio: " << 1.0 << endl;
		#endif
		}
	}
	#ifdef _VOID_PROJECTION_ENCODING_MODE
	else if (projectionCode<3*MAX_PROJECTION_CODE)
	{
		#ifdef _GA_TEST
		cout << "Projection is void" << endl;
		#endif
	}
	else
	{
		cerr << "Warning, projection code " << projectionCode << " has uncompatible value with " << 3*MAX_PROJECTION_CODE << endl;
		return;
	}
	#else
	else
	{
		cerr << "Warning, projection code " << projectionCode << " has uncompatible value with " << 2*MAX_PROJECTION_CODE << endl;
		return;
	}
	#endif
}	

// Destruction des projections
void EDNetwork::destroyProjections()
{
	std::vector<Assembly*>::iterator it=assemblies.begin();
	std::vector<Assembly*>::iterator end=assemblies.end();
	
	#ifdef _TEST
	cout << "*** EDNetwork *** destroying assemblies (" << assemblies.size() << " neurons)" << endl;
	#endif
	
	while (it!=end)
	{
	#ifdef _TEST
		cerr << "Destroying projections of assembly " << ((EDAssembly*) *it)->getIndex() << endl;
	#endif
		((EDAssembly*) *it)->destroyLinks();

		it++;
	}
	#ifdef _TEST
	cout << "*** EDNetwork *** destroying input assemblies (" << nbInputBuffers << " neurons)" << endl;
	#endif
	for (int i=0;i<nbInputBuffers;i++)
	{
	#ifdef _TEST
		cout << "Destroying projections of input assembly " << ((EDAssembly*)  inputBuffers[i])->getIndex();
	#endif
		((EDAssembly*) ((InputAssembly*) inputBuffers[i]))->destroyLinks();
	}
	#ifdef _TEST
	cout << "*** EDNetwork *** destroying output assemblies (" << nbOutputBuffers << " neurons)" << endl;
	#endif
	for (int i=0;i<nbOutputBuffers;i++)
	{
	#ifdef _TEST
		cout << "Destroying projections of output assembly " << ((EDAssembly*) outputBuffers[i])->getIndex();
	#endif
		((EDAssembly*) ((OutputAssembly*) outputBuffers[i]))->destroyLinks();
	}
}
#else
void EDNetwork::buildTopology()
{
	EDSynapse::nbSynapses=0;

	if (synchroBuffer->getSize()==NB_GENES_EACH_CHROMOSOME)
	{
		int comptProjections=0;
	
		while (comptProjections<NB_PROJECTIONS_EACH_CHROMOSOME)
		{
	
	#if (NB_GENES_EACH_PROJECTION==3)
		#ifdef _INCREMENTAL_TOPOLOGY_MODE
			
			#ifdef _GA_TEST
			cout << "***(" << comptProjections << "/" << NB_PROJECTIONS_EACH_CHROMOSOME << ") ";
			cout << "Projection :(" << ((double) (*synchroBuffer)[comptProjections*NB_GENES_EACH_PROJECTION])/((double) NB_PRE_ASSEMBLIES);
			cout << "," << (int) (*synchroBuffer)[comptProjections*NB_GENES_EACH_PROJECTION+1];
			cout << "," << ((double) (*synchroBuffer)[comptProjections*NB_GENES_EACH_PROJECTION+2])/((double) NB_POST_ASSEMBLIES) << ")" << endl;
			#endif
			
			if (comptProjections % NB_PROJECTIONS_EACH_ASSEMBLY == 0)
			{
				addNewAssembly();
			}
			
			buildCompleteIncrementalPostProjection
			(
			((double) (*synchroBuffer)[comptProjections*NB_GENES_EACH_PROJECTION])/((double) NB_PRE_ASSEMBLIES),
			(int) (*synchroBuffer)[comptProjections*NB_GENES_EACH_PROJECTION+1],
			((double) (*synchroBuffer)[comptProjections*NB_GENES_EACH_PROJECTION+2])/((double) NB_POST_ASSEMBLIES)
			);
		#else
			#ifdef _GA_TEST
			cout << "***(" << comptProjections << "/" << NB_PROJECTIONS_EACH_CHROMOSOME << ") ";
			cout << "Projection :(" << (int) (*synchroBuffer)[comptProjections*NB_GENES_EACH_PROJECTION];
			cout << "," << (int) (*synchroBuffer)[comptProjections*NB_GENES_EACH_PROJECTION+1];
			cout << "," << (int) (*synchroBuffer)[comptProjections*NB_GENES_EACH_PROJECTION+2] << ")" << endl;
			#endif
			
			buildCompletePostProjection
			(
			(int) (*synchroBuffer)[comptProjections*NB_GENES_EACH_PROJECTION],
			(int) (*synchroBuffer)[comptProjections*NB_GENES_EACH_PROJECTION+1],
			(int) (*synchroBuffer)[comptProjections*NB_GENES_EACH_PROJECTION+2]
			);
		#endif

	#else
			cerr << "Warning, NB_GENES_EACH_PROJECTION should be 3" << endl;
	#endif

	#ifdef _GRAPHICAL_DISPLAY_MODE
			((TopologyDisplayer*) displayer)->flushDisplay();
	#endif
			comptProjections++;
		}
	}
	else
	{
		cerr << "Incompatible size of chromoBuffer: " << synchroBuffer->getSize() << endl;
		return;
	}

	#ifdef _SELF_INHIBITION_MODE
	buildSelfInhibitions();
	#endif

//#ifdef _GA_TEST
	cout << "Nb synapses build: " << Synapse::nbSynapses << endl;
	cout << "Nb neurons : " << Neuron::nbNeurons << endl;
//#endif
}

	#ifdef _INCREMENTAL_TOPOLOGY_MODE
void EDNetwork::buildCompleteIncrementalPostProjection(double relativePreAssemblyIndex, int projectionCode, double relativePostAssemblyIndex)
{
	int preAssemblyIndex = (int) ((int) NB_INPUT_ASSEMBLIES+EDAssembly::nbEDAssemblies)*relativePreAssemblyIndex;
	int postAssemblyIndex = (int) ((int) NB_OUTPUT_ASSEMBLIES+EDAssembly::nbEDAssemblies)*relativePostAssemblyIndex;
	
	buildCompletePostProjection(preAssemblyIndex,projectionCode,postAssemblyIndex);
}
	#endif
	
void EDNetwork::buildCompletePostProjection(int preAssemblyIndex, int projectionCode, int postAssemblyIndex)
{
	EDAssembly* preAssembly;
	EDAssembly* postAssembly;
	double projectionRatio;

	// Assemblée pré
	if (0<=preAssemblyIndex && preAssemblyIndex<nbInputBuffers)
	{
	#ifdef _GA_TEST
		cout << "preAssembly is an input assembly (index: 0<" << preAssemblyIndex << "<" << nbInputBuffers << ")" << endl;
	#endif
		preAssembly=(EDAssembly*)((InputAssembly*) inputBuffers[preAssemblyIndex]);
	#ifdef _GRAPHICAL_DISPLAY_MODE
		((AssemblyDisplayer*) displayer)->display(preAssembly);
	#endif
	}
	else if (nbInputBuffers<=preAssemblyIndex && preAssemblyIndex<nbInputBuffers+assemblies.size())
	{
	#ifdef _GA_TEST
		cout << "preAssembly is an hidden assembly (index: 0<" << preAssemblyIndex-nbInputBuffers << "<" << assemblies.size() << ")" << endl;
	#endif
		preAssembly=(EDAssembly*) assemblies[preAssemblyIndex-nbInputBuffers];
	#ifdef _GRAPHICAL_DISPLAY_MODE
		((AssemblyDisplayer*) displayer)->display(preAssembly);
	#endif
	}
	else
	{
		cerr << "Warning, incompatible index for pre assembly: " << preAssemblyIndex << endl;
		return;
	}

	// Assemblée post
	if (0<=postAssemblyIndex && postAssemblyIndex<nbOutputBuffers)
	{
	#ifdef _GA_TEST
		cout << "postAssembly is an output assembly (index: 0<" << postAssemblyIndex << "<" << nbOutputBuffers << ")" << endl;
	#endif
		postAssembly=(EDAssembly*)((OutputAssembly*) outputBuffers[postAssemblyIndex]);
	#ifdef _GRAPHICAL_DISPLAY_MODE
		((AssemblyDisplayer*) displayer)->display(postAssembly);
	#endif
	}
	else if (nbOutputBuffers<=postAssemblyIndex && postAssemblyIndex<nbOutputBuffers+assemblies.size())
	{
	#ifdef _GA_TEST
		cout << "postAssembly is an hidden assembly (index: 0<" << postAssemblyIndex-nbOutputBuffers << "<" << assemblies.size() << ")" << endl;
	#endif
		postAssembly=(EDAssembly*) assemblies[postAssemblyIndex-nbOutputBuffers];

	#ifdef _GRAPHICAL_DISPLAY_MODE
		((AssemblyDisplayer*) displayer)->display(postAssembly);
	#endif
	}
	else
	{
		cerr << "Warning, incompatible index for post assembly: " << postAssemblyIndex << endl;
		return;
	}
	
	#ifdef _SELF_INHIBITION_MODE
	if (0<=projectionCode && projectionCode<MAX_PROJECTION_CODE)
	{
		for (int i=0;i<projectionCode+1;i++)
		{
			// Construction de la projection
			preAssembly->buildTotalPostExcitProjection(postAssembly);
		}

		// Affichage de la projection
		#ifdef _GRAPHICAL_DISPLAY_MODE
		((AssemblyDisplayer*) displayer)->traceProjection(preAssemblyIndex,postAssemblyIndex,1,"bleu");
		#endif

		#ifdef _GA_TEST
		cout << "projectionRatio: " << ((double) projectionCode+1)/MAX_PROJECTION_CODE << endl;
		#endif
	}
	else
	{
		cerr << "Warning, projection code " << projectionCode << " has uncompatible value" << endl;
		return;
	}

	#else
	if (0<=projectionCode && projectionCode<2*MAX_PROJECTION_CODE)
	{
		if (0<=projectionCode && projectionCode<MAX_PROJECTION_CODE)
		{
			// Construction de la projection
		#ifdef _ALL_TO_ALL_PROJECTION_MODE
			preAssembly->buildTotalPostExcitProjection(postAssembly);
		#endif
		#ifdef _FIXED_RATIO_PROJECTION_MODE
			preAssembly->buildFixedPostExcitProjection(postAssembly);
		#endif
			

			// Affichage de la projection
		#ifdef _GRAPHICAL_DISPLAY_MODE
			((TopologyDisplayer*) displayer)->traceProjection(preAssemblyIndex,postAssemblyIndex,1,"bleu");
		#endif

		#ifdef _GA_TEST
			cout << "projectionRatio: " << 1.0 << endl;
		#endif
		}
		else if (MAX_PROJECTION_CODE<=projectionCode && projectionCode<2*MAX_PROJECTION_CODE)
		{

			// Construction de la projection
		#ifdef _ALL_TO_ALL_PROJECTION_MODE
			preAssembly->buildTotalPostInhibProjection(postAssembly);
		#endif
		#ifdef _FIXED_RATIO_PROJECTION_MODE
			preAssembly->buildFixedPostInhibProjection(postAssembly);
		#endif
			

			// Affichage de la projection
		#ifdef _GRAPHICAL_DISPLAY_MODE
			//((TopologyDisplayer*) displayer)->traceProjection(preAssemblyIndex,postAssemblyIndex,1,"jaune");
			((TopologyDisplayer*) displayer)->traceProjection(preAssemblyIndex,postAssemblyIndex,1,"rouge");
		#endif

		#ifdef _GA_TEST
			cout << "projectionRatio: " << 1.0 << endl;
		#endif
		}
	}
		#ifdef _VOID_PROJECTION_ENCODING_MODE
	else if (projectionCode<3*MAX_PROJECTION_CODE)
	{
			#ifdef _GA_TEST
		cout << "Projection is void" << endl;
			#endif
	}
	else
	{
		cerr << "Warning, projection code " << projectionCode << " has uncompatible value with " << 3*MAX_PROJECTION_CODE << endl;
		return;
	}
		#else
	else
	{
		cerr << "Warning, projection code " << projectionCode << " has uncompatible value with " << 2*MAX_PROJECTION_CODE << endl;
		return;
	}
		#endif
	#endif
}
	
	#ifdef _SELF_INHIBITION_MODE
void EDNetwork::buildCompleteSelfInhibitions()
{
	std::vector<Assembly*>::iterator it=assemblies.begin();
	std::vector<Assembly*>::iterator end=assemblies.end();

	while (it!=end)
	{
		((EDAssembly*) *it)->buildSelfInhibition();
		it++;
	}
}
	#endif
	
void EDNetwork::destroyTopology()
{
	std::vector<Assembly*>::iterator it=assemblies.begin();
	std::vector<Assembly*>::iterator end=assemblies.end();
	#ifdef _TEST
	cout << "*** EDNetwork *** destroying assemblies (" << assemblies.size() << " neurons)" << endl;
	#endif
	while (it!=end)
	{
	#ifdef _TEST
		cerr << "Destroying projections of assembly " << ((EDAssembly*) *it)->getIndex() << endl;
	#endif
		((EDAssembly*) *it)->destroyProjections();

		it++;
	}
	
	#ifdef _TEST
	cout << "*** EDNetwork *** destroying input assemblies (" << nbInputBuffers << " neurons)" << endl;
	#endif
	
	for (int i=0;i<nbInputBuffers;i++)
	{
	#ifdef _TEST
		cout << "Destroying projections of input assembly " << ((EDAssembly*)  inputBuffers[i])->getIndex();
	#endif
		((EDAssembly*) ((InputAssembly*) inputBuffers[i]))->destroyProjections();
	}
	
	#ifdef _TEST
	cout << "*** EDNetwork *** destroying output assemblies (" << nbOutputBuffers << " neurons)" << endl;
	#endif
	
	for (int i=0;i<nbOutputBuffers;i++)
	{
	#ifdef _TEST
		cout << "Destroying projections of output assembly " << ((EDAssembly*) outputBuffers[i])->getIndex();
	#endif
		((EDAssembly*) ((OutputAssembly*) outputBuffers[i]))->destroyProjections();
	}
	
	#ifdef _TEST
	cout << "Nb synapses after destroyTopology: " << Synapse::nbSynapses << endl;
	#endif
}
#endif

void EDNetwork::initSynchroBuffer()
{
	cout << "*** EDNetwork *** Initing synchroBuffer " << endl;
	synchroBuffer = new InputBuffer(CHROMO_BUFFER_SIZE,SYNCHRO_CHANNEL_TAG,ROOT_MODULE_MPI_ID);
}

void EDNetwork::receiveInputs()
{
#ifdef _MPI_TEST
	cout << "*** EDNetwork *** entering integrateOnlineInputs" << endl;
#endif

	for (int i=0;i<nbInputBuffers;i++)
	{
		if (inputBuffers[i]->getFlag())
		{
			if (!inputBuffers[i]->getActive())
			{
#ifdef _MPI_TEST
				cout << "Testing if new input as arrived" << endl;
#endif
				// On teste si un nouvel input peut etre recu
				inputBuffers[i]->receiveInput();
			}
		}
	}
}

#ifdef _BLOCKING_MODE
void EDNetwork::integrateInputs(int time)
{
	#ifdef _MPI_TEST
	cout << "*** EDNetwork *** entering integrateOnlineInputs" << endl;
	#endif

	for (int i=0;i<nbInputBuffers;i++)
	{
		if (inputBuffers[i]->getFlag())
		{
			if (inputBuffers[i]->getActive())
			{
	#ifdef _MPI_TEST
			cout << "*** EDNetwork *** Integrating message in input assembly " << i << " at time " << time << endl;
	#endif
				((InputAssembly*) inputBuffers[i])->integrateInput(time,timeRef);
			}
		}
	}
}

void EDNetwork::integrateOutputs(int time)
{
	for (int i=0;i<nbOutputBuffers;i++)
	{
		if (outputBuffers[i]->getFlag())
		{
			if (!outputBuffers[i]->getActive())
			{
#ifdef _MPI_TEST
				cout << "*** EDNetwork *** reiniting message from output assembly " << i << " at time " << time << endl;
#endif
				((OutputAssembly*) outputBuffers[i])->initOutputIntegration();
			}
			else
			{
#ifdef _MPI_TEST
				cout << "*** EDNetwork *** integrating message from output assembly " << i << " at time " << time << endl;
#endif
				((OutputAssembly*) outputBuffers[i])->integrateOutput(time);
			}
		}
	}
}
#endif

#ifndef _BLOCKING_MODE
void EDNetwork::integrateInputs(int time)
{
	#ifdef _MPI_TEST
	cout << "*** EDNetwork *** entering integrateOnlineInputs" << endl;
	#endif

	for (int i=0;i<nbInputBuffers;i++)
	{
		if (inputBuffers[i]->getFlag())
		{
			if (inputBuffers[i]->getActive())
			{
	#ifdef _MPI_TEST
			cout << "*** EDNetwork *** Integrating message in input assembly " << i << " at time " << time << endl;
	#endif
				((InputAssembly*) inputBuffers[i])->integrateInput(time,timeRef);
			}
		}
	}
}
//#endif

void EDNetwork::integrateOutputs(int time)
{
	for (int i=0;i<nbOutputBuffers;i++)
	{
		if (outputBuffers[i]->getFlag())
		{
			if (!outputBuffers[i]->getActive())
			{
	#ifdef _MPI_TEST
				cout << "*** EDNetwork *** integrating message from output assembly " << i << " at time " << time << endl;
	#endif
				((OutputAssembly*) outputBuffers[i])->integrateOutput(time);
			}
		}
	}
}
#endif

void EDNetwork::sendOutputs()
{
#ifdef _MPI_TEST
	cout << "*** EDNetwork *** sending some outputs" << endl;
#endif

	for (int i=0;i<nbOutputBuffers;i++)
	{
		if (outputBuffers[i]->getFlag())
		{
#ifdef _MPI_TEST
			cout << "*** EDNetwork *** Sending message from output assembly " << i << " "  << endl;
#endif	
			((OutputAssembly*) outputBuffers[i])->sendOutput();
		}
	}
}

void EDNetwork::receiveVoidInputs()
{
	#ifdef _MPI_TEST
	cout << "*** EDNetwork *** entering integrateOnlineInputs" << endl;
	#endif

	for (int i=0;i<nbInputBuffers;i++)
	{
		if (inputBuffers[i]->getFlag())
		{
			if (!inputBuffers[i]->getActive())
			{
				inputBuffers[i]->receiveInput();
				inputBuffers[i]->freeActive();
			}
		}
	}
}

void EDNetwork::initNetworkFiles()
{
#ifdef _NETWORK_TRACE_MODE
	#ifdef _TRACE_TEST
	cerr << "New network Traces" << endl;
	#endif
	//tracer = new NetworkTracer();
	initNetworkTracer();

	//((NeuronTracer*) tracer)->openTracer();
	//((SynapseTracer*) tracer)->openTracer();


#endif


#ifdef _ASSEMBLY_STAT_MODE
	#ifdef _STAT_TEST
	cerr << "Initing network Stats" << endl;
	#endif

	#ifdef _GLOBAL_STAT_MODE
		#ifdef _MULTI_TEST_MODE
		
	std::vector<Assembly*>::iterator it=assemblies.begin();
	std::vector<Assembly*>::iterator end=assemblies.end();

	while (it!=end)
	{
			#ifdef _STAT_TEST
		cout << "Initing assembly " << ((Assembly*) *it)->getIndex() << " Stats" << endl;
			#endif

		((EDAssembly*) *it)->initAssemblyFiles((NeuronStater*) stater);
		it++;
	}	
		#else
			#ifndef _PHASE_TEST_MODE
				#ifdef _LINK_INPUT_STAT_MODE
	cerr << "Initing Input Stats" << endl;
	inputLinkStater = new NeuronStater();
	
				#else
	cerr << "Initing Neuron Stats" << endl;
	stater = new NeuronStater();
	
	std::vector<Assembly*>::iterator it=assemblies.begin();
	std::vector<Assembly*>::iterator end=assemblies.end();

	while (it!=end)
	{
		#ifdef _STAT_TEST
		cout << "Initing assembly " << ((Assembly*) *it)->getIndex() << " Stats" << endl;
		#endif

		((EDAssembly*) *it)->initAssemblyFiles((NeuronStater*) stater);
		it++;
	}				
				#endif
			#endif	
		#endif
	#else
	std::vector<Assembly*>::iterator it=assemblies.begin();
	std::vector<Assembly*>::iterator end=assemblies.end();

	while (it!=end)
	{
		#ifdef _STAT_TEST
		cout << "Initing assembly " << ((Assembly*) *it)->getIndex() << " Stats" << endl;
		#endif
		((EDAssembly*) *it)->initAssemblyFiles();
		it++;
	}
	#endif
	
	#ifdef _NO_LINK_INPUT_STAT_MODE
	for (int i=0;i<nbInputBuffers;i++)
	{
		if (i == TEST_VISIO_INPUT_ASSEMBLY || i ==LEFT_AUDIO_CHANNEL_ETIQUETTE || i ==RIGHT_AUDIO_CHANNEL_ETIQUETTE)
		{
		//#ifdef _STAT_TEST
			cerr << "Freeing input assembly " << i << " Stats" << endl;
		//#endif

			((InputAssembly*) ((InputBuffer*) inputBuffers[i]))->freeAssemblyFiles();
		}
	}
	#endif
	
	#ifdef _LINK_INPUT_STAT_MODE
	//#ifdef _STAT_TEST
	cerr << "Initing input link stater " << endl;
	//#endif

	for (int i=0;i<nbInputBuffers;i++)
	{
		if (i == TEST_VISIO_INPUT_ASSEMBLY || i ==LEFT_AUDIO_CHANNEL_ETIQUETTE || i ==RIGHT_AUDIO_CHANNEL_ETIQUETTE)
		{
		//#ifdef _STAT_TEST
			cerr << "Initing link input assembly " << i << " Stats" << endl;
		//#endif
			//((EDAssembly*) *it)->initAssemblyFiles((NeuronStater*) stater);
			((InputAssembly*) ((InputBuffer*) inputBuffers[i]))->freeAssemblyFiles((NeuronStater*) inputLinkStater);
		}
	}
	#endif
	
	#ifdef _RUN_MODE
	for (int i=0;i<nbInputBuffers;i++)
	{
		//#ifdef _STAT_TEST
		cerr << "Initing output assembly " << ((OutputAssembly*) ((OutputBuffer*) outputBuffers[i]))->getIndex() << " Stats" << endl;
		//#endif
	
		((InputAssembly*) ((InputBuffer*) inputBuffers[i]))->initAssemblyFiles();

	}
	for (int i=0;i<nbOutputBuffers;i++)
	{
		//#ifdef _STAT_TEST
		cerr << "Initing output assembly " << ((OutputAssembly*) ((OutputBuffer*) outputBuffers[i]))->getIndex() << " Stats" << endl;
		//#endif

		((OutputAssembly*) ((OutputBuffer*) outputBuffers[i]))->initAssemblyFiles();
		it++;
	}
	#endif
	//#endif
#endif
}

void EDNetwork::endNetworkFiles()
{
#ifdef _ASSEMBLY_STAT_MODE
	#ifdef _STAT_TEST
	cout << "Ending network Stats" << endl;
	#endif

	std::vector<Assembly*>::iterator it=assemblies.begin();
	std::vector<Assembly*>::iterator end=assemblies.end();

	while (it!=end)
	{

		#ifdef _STAT_TEST
		cout << "Ending assembly " << ((Assembly*) *it)->getIndex() << " Stats" << endl;
		#endif

		((EDAssembly*) *it)->endAssemblyFiles();
		it++;
	}

	#ifdef _RUN_MODE
	for (int i=0;i<nbOutputBuffers;i++)
	{
		//#ifdef _STAT_TEST
		cerr << "Ending output assembly " << ((OutputAssembly*) ((OutputBuffer*) outputBuffers[i]))->getIndex() << " Stats" << endl;
		//#endif

		((OutputAssembly*) ((OutputBuffer*) outputBuffers[i]))->endAssemblyFiles();
		it++;
	}

	for (int i=0;i<nbInputBuffers;i++)
	{
		//#ifdef _STAT_TEST
		cerr << "Ending input assembly " << ((InputAssembly*) ((InputBuffer*) inputBuffers[i]))->getIndex() << " Stats" << endl;
		//#endif

		((InputAssembly*) ((InputBuffer*) inputBuffers[i]))->endAssemblyFiles();
		it++;
	}
	#endif

	#ifdef _GLOBAL_STAT_MODE
		#ifndef _MULTI_TEST_MODE
			#ifndef _PHASE_TEST_MODE
				#ifdef _LINK_INPUT_STAT_MODE
	cerr << "Stating Input Stats" << endl;
	delete((NeuronStater*) inputLinkStater);
	inputLinkStater = 0;	
				#else
	cerr << "Freeing Neuron Stats" << endl;
	delete((NeuronStater*) stater);
	stater = 0;			
				#endif
			#endif
		#else
	((ActivityStater*) stater)->stat();
			
			#ifdef _LINK_INPUT_STAT_MODE
	cerr << "Stating Input Stats" << endl;
	((InputStater*) inputLinkStater)->stat();
			#endif

		#endif
	#endif
#endif

#ifdef _NETWORK_TRACE_MODE
	#ifdef _TRACE_TEST
	cerr << "Ending network Traces" << endl;
	#endif

	freeNetworkTracer();
#endif
#ifdef _NETWORK_GRAPH_MODE
	//#ifdef _TRACE_TEST
	cout << "Opening Graphers" << endl;
	//#endif

	initNetworkGrapher();
	((NetworkGrapher*) grapher)->graph(this);
	freeNetworkGrapher();
#endif
}

#ifdef _ASSEMBLY_STAT_MODE
void EDNetwork::traceNetworkFiles()
{
		#ifdef _TEST_STAT
	cout << "Tracing network files" << endl;
		#endif

		#ifdef _GLOBAL_STAT_MODE
			#ifdef _LINK_INPUT_STAT_MODE
				#ifdef _STAT_TEST
	cout << "Tracing input link stater " << inputLinkStater<< endl;
				#endif
	
	if (inputLinkStater)
	{
		((NeuronStater*) inputLinkStater)->trace(EDSynapse::theEventManager.getTime());
	}
			#else
	if (stater)
	{
			//#ifndef _MULTI_TEST_MODE
			//	#ifndef _PHASE_TEST_MODE
		((NeuronStater*) stater)->trace(EDSynapse::theEventManager.getTime());
			//	#endif
			//#endif
	}
			
			#endif
		#else
	std::vector<Assembly*>::iterator it=assemblies.begin();
	std::vector<Assembly*>::iterator end=assemblies.end();

	while (it!=end)
	{
		((EDAssembly*) *it)->traceAssemblyFiles(EDSynapse::theEventManager.getTime());
		it++;
	}
		#endif
}

void EDNetwork::traceVoidFiles()
{
	#ifdef _LINK_INPUT_STAT_MODE		
	if (inputLinkStater)
	{
		((NeuronStater*) inputLinkStater)->traceVoid();
	}
	#else
	if (stater)
	{
		((NeuronStater*) stater)->traceVoid();
	}
	
	#endif
}

	#ifdef _PSP_LFP_STAT_MODE
void EDNetwork::initPSPotential()
{
	std::vector<Assembly*>::iterator it=assemblies.begin();
	std::vector<Assembly*>::iterator end=assemblies.end();

	while (it!=end)
	{
		((EDAssembly*) *it)->initPSPotential();
		it++;
	}
}
	#endif
#endif

#ifdef _NETWORK_STAT_MODE
void EDNetwork::statNetwork()
{
	#ifdef _CLUSTER_STAT_MODE
		
		#ifdef _SAVE_ORDERED_PROJECTIONS_MODE
		
		removeLinks();
		
		saveTabOrderedProjections();
				
		#else
		
			#ifdef _LOAD_ORDERED_PROJECTIONS_MODE
			loadTabOrderedProjections();
			#else	
			removeLinks();	
			#endif	
		#endif
			
		// Reconstruction de réseau
		destroyProjections();
		
			#ifdef _INCREMENTAL_TOPOLOGY_MODE
		buildIncrementalProjections();
			#else	
		buildProjections();
			#endif	
			
		buildClusters();
		
			
	#else
	
		#ifdef _TOPOLOGY_STAT_MODE
	statTopology();
		#endif
		
		#ifdef _LINK_TO_INPUT_STAT_MODE
	statInputConnectivity();
		#endif
		
		#ifdef _LINK_TO_OUTPUT_STAT_MODE
	statOutputConnectivity();
		#endif
		
		#ifdef _CENTRALITY_STAT_MODE
			#ifdef _TEST
	cerr << "statAssemblyPaths" << endl;
			#endif
	statAssemblyPaths();
	
			#ifdef _EDGE_BETWEENNESS_STAT_MODE
				#ifdef _TEST
	cerr << "computeAssemblyEdgeBetweennessDistribution" << endl;
				#endif
	((AssemblyStater*) stater)->computeAssemblyEdgeBetweennessDistribution();
			#endif

		#endif

		#ifdef _MOTIF_STAT_MODE
			#ifdef _TEST
	cerr << "statMotifs" << endl;
			#endif
	statMotifs();
		#endif

		#ifdef _SMALL_WORLD_STAT_MODE
			#ifdef _TEST
	cerr << "statClusteringCoeff" << endl;
			#endif
	statClusteringCoeff();
		#endif

		#ifdef _DEGREE_STAT_MODE
			#ifdef _TEST
	cerr << "statDegree" << endl;
			#endif
	statDegree();
		#endif

		#ifdef _LOOP_STAT_MODE
			#ifdef _TEST
	cerr << "statLoops" << endl;
			#endif
	statLoops();
		#endif

		#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE
			#ifdef _TEST
	cerr << "statInputOutputLinks" << endl;
			#endif
			
	// Liens input-outputs
	statInputOutputLinks();
		#endif

		
		#ifdef _GSCC_STAT_MODE
			#ifdef _TEST
	cerr << "statAssemblySCC" << endl;
			#endif
	statAssemblySCC();
	
			#ifdef _INPUT_OUTPUT_GSCC_STAT_MODE
	statInputOutputSCC();
			#endif
		#endif
		
		#ifdef _PROJECTION_STAT_MODE
			#ifdef _TEST
	cerr << "statProjections" << endl;
			#endif
	statProjections();
		#endif
	#endif
}


	#ifdef _TOPOLOGY_STAT_MODE
void EDNetwork::statTopology()
{
	((NetworkStater*) stater)->initConnectivityMatrix();
	
	std::vector<Assembly*>::iterator it=assemblies.begin();
	std::vector<Assembly*>::iterator end=assemblies.end();

	while (it!=end)
	{
		((NetworkStater*) stater)->statConnectivity((EDAssembly*) *it);
		it++;
	}
		
}
	#endif
	
	#ifdef _LINK_TO_INPUT_STAT_MODE
void EDNetwork::statInputConnectivity()
{
	((NetworkStater*) stater)->initLinkToInputVector();
	
	for (int i=0;i<nbInputBuffers;i++)
	{
		((NetworkStater*) stater)->statInputConnectivity((EDAssembly*) ((InputAssembly*) inputBuffers[i]));
	}
}
	#endif
	
	#ifdef _LINK_TO_OUTPUT_STAT_MODE
void EDNetwork::statOutputConnectivity()
{
	((NetworkStater*) stater)->initLinkToOutputVector();
	
	for (int i=0;i<nbOutputBuffers;i++)
	{
		((NetworkStater*) stater)->statOutputConnectivity((EDAssembly*) ((OutputAssembly*) outputBuffers[i]));
	}
}
	#endif
	
	#ifdef _SMALL_WORLD_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
void EDNetwork::statClusterInternalDensity()
{
			#ifdef _LINKED_CLUSTER_STAT_MODE
	((ClusterStater*) stater)->initClusterInternalDensityCounters();

	std::vector<LinkedCluster*>::iterator it=tabClusters.begin();
	std::vector<LinkedCluster*>::iterator end=tabClusters.end();

	while (it!=end)
	{
		((ClusterStater*) stater)->statClusterInternalDensity((Cluster*) *it);
		it++;
	}
			#else
	((ClusterStater*) stater)->initClusterInternalDensityCounters();

	std::vector<Cluster*>::iterator it=tabClusters.begin();
	std::vector<Cluster*>::iterator end=tabClusters.end();

	while (it!=end)
	{
		((ClusterStater*) stater)->statClusterInternalDensity((Cluster*) *it);
		it++;
	}
			#endif
}
		#endif
		
void EDNetwork::statClusteringCoeff()
{
	((LoopStater*) stater)->initClusteringCoeffCounters();

	std::vector<Assembly*>::iterator it=assemblies.begin();
	std::vector<Assembly*>::iterator end=assemblies.end();

	while (it!=end)
	{
		((LoopStater*) stater)->statSmallWorld((Assembly*) *it);
		it++;
	}

	((LoopStater*) stater)->computeNetworkClusteringCoeff();
}
	#endif

	#ifdef _LOOP_STAT_MODE
		#ifdef _CLUSTER_STAT_MODE
void EDNetwork::statInternalClusterLoops()
{
	//((ClusterStater*) stater)->initLoopCounters();
	((LoopStater*) stater)->initLoopCounters();

			#ifdef _LINKED_CLUSTER_STAT_MODE
	std::vector<LinkedCluster*>::iterator it=tabClusters.begin();
	std::vector<LinkedCluster*>::iterator end=tabClusters.end();

	while (it!=end)
	{
				#ifdef _TEST
		cout << "stat Internal Loops Linked Cluster  = " << ((LinkedCluster*) *it)->getIndex() << endl;
				#endif
		((ClusterStater*) stater)->statInternalLoops((Cluster*) *it);
			
		it++;
	}
	
			#else
	std::vector<Cluster*>::iterator it=tabClusters.begin();
	std::vector<Cluster*>::iterator end=tabClusters.end();

	while (it!=end)
	{
				#ifdef _TEST
		cout << "stat Internal Loops Linked Cluster  = " << ((Cluster*) *it)->getIndex() << endl;
				#endif
		((ClusterStater*) stater)->statInternalLoops((Cluster*) *it);
		
		it++;
	}
			#endif
	
	((LoopStater*) stater)->computeNbLoops();
}
		#endif
		
void EDNetwork::statLoops()
{		
	((LoopStater*) stater)->initLoopCounters();
	
	std::vector<Assembly*>::iterator it=assemblies.begin();
	std::vector<Assembly*>::iterator end=assemblies.end();

	while (it!=end)
	{
		((LoopStater*) stater)->initTabNodes();

		#ifdef _TEST_STAT
		cout << "Computing loop stat for assembly " << ((Assembly*) *it)->getIndex() << endl;
		#endif

		((LoopStater*) stater)->statDepthFirstPostLinks((Node*) *it);
		it++;
	}
	
	((LoopStater*) stater)->computeNbLoops();
	
	std::vector<Assembly*>::iterator it2=assemblies.begin();
	std::vector<Assembly*>::iterator end2=assemblies.end();

	while (it2!=end2)
	{
		((LoopStater*) stater)->initTabNodes();

		#ifdef _TEST_STAT
		cout << "Computing loop stat for assembly " << ((Assembly*) *it2)->getIndex() << endl;
		#endif

		((LoopStater*) stater)->computeNbLoopsDegree((Node*) *it2);
		it2++;
	}
}
	#endif

	#ifdef _MOTIF_STAT_MODE
void EDNetwork::statMotifs()
{
	((LoopStater*) stater)->initMotifsCounters();

	std::vector<Assembly*>::iterator it=assemblies.begin();
	std::vector<Assembly*>::iterator end=assemblies.end();

	while (it!=end)
	{
		#ifdef _TEST_STAT
		cerr << "Stating motifs of assembly " << ((Assembly*) *it)->getIndex() << endl;
		#endif
		((LoopStater*) stater)->statMotifs((Assembly*) *it);
		it++;
	}
}
		#ifdef _INTERNAL_MOTIF_STAT_MODE
void EDNetwork::statInternalMotifs()
{
	((ClusterStater*) stater)->initInternalMotifsCounters();
	
			#ifdef _LINKED_CLUSTER_STAT_MODE
	std::vector<LinkedCluster*>::iterator it=tabClusters.begin();
	std::vector<LinkedCluster*>::iterator end=tabClusters.end();

	while (it!=end)
	{
				#ifdef _TEST_STAT
		cerr << "Stating motifs of cluster " << ((LinkedCluster*) *it)->getIndex() << endl;
				#endif
		((ClusterStater*) stater)->statInternalMotifs((LinkedCluster*) *it);
		it++;
	}
			#else
	std::vector<Cluster*>::iterator it=tabClusters.begin();
	std::vector<Cluster*>::iterator end=tabClusters.end();

	while (it!=end)
	{
		((ClusterStater*) stater)->statInternalMotifs((Cluster*) *it);
		it++;
	}
			#endif
}
		#endif
	#endif

	#ifdef _CENTRALITY_STAT_MODE
void EDNetwork::statAssemblyPaths()
{

	#ifdef _TEST_STAT
	cerr << "in statAssemblyPaths "  << endl;
	#endif
	((LoopStater*) stater)->initPathCounters();

	((LoopStater*) stater)->initBetweennessCounters();
	
	#ifdef _TEST_STAT
	cerr << "after LoopStater::initPathCounters "  << endl;
	#endif
	
	std::vector<Assembly*>::iterator it=assemblies.begin();
	std::vector<Assembly*>::iterator end=assemblies.end();

	while (it!=end)
	{
		#ifdef _TEST_STAT
		cerr << "Computing breadth first search for assembly " << ((Assembly*) *it)->getIndex() << endl;
		#endif

		#ifdef _EDGE_BETWEENNESS_STAT_MODE
		((LoopStater*) stater)->initBetweenness();
		#endif
		
		((LoopStater*) stater)->initBreadthFirstPostLinks((Assembly*) *it);
		((LoopStater*) stater)->statBreadthFirstPostLinks((Assembly*) *it);
		
		((LoopStater*) stater)->computeBetweenness((Assembly*) *it);
		it++;
	}
	
	((AssemblyStater*) stater)->initCounters();
	
	((AssemblyStater*) stater)->computeAssemblyBetweenness();
	((AssemblyStater*) stater)->computeAssemblyCentralBetweenness();
	((AssemblyStater*) stater)->computeAssemblyShortPaths();
	
		#ifdef _TEST_STAT
	cout << "Computing assembly efficiency " << endl;
		#endif
		
	std::vector<Assembly*>::iterator it2=assemblies.begin();
	std::vector<Assembly*>::iterator end2=assemblies.end();

	while (it2!=end2)
	{
		#ifdef _TEST_STAT
		cout << "Computing efficiency for assembly " << ((Assembly*) *it2)->getIndex() << endl;
		#endif

		((LoopStater*) stater)->computeEfficiency((Assembly*) *it2);
		it2++;
	}
	
	((AssemblyStater*) stater)->computeAssemblyEfficiency();
	
		#ifdef _TEST_STAT
	cerr << "After computing assembly efficiency " << endl;
		#endif
}
	#endif

	#ifdef _DEGREE_STAT_MODE
void EDNetwork::statDegree()
{
	((LoopStater*) stater)->initDegreeCounters();

	std::vector<Assembly*>::iterator it=assemblies.begin();
	std::vector<Assembly*>::iterator end=assemblies.end();

	while (it!=end)
	{
		((LoopStater*) stater)->statDegreeDistribution((EDAssembly*) *it);
		it++;
	}

		#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE
	for (int i=0;i<nbInputBuffers;i++)
	{
		((LoopStater*) stater)->statInputNodeDegree(((InputAssembly*) ((InputBuffer*) inputBuffers[i])));
	}

	for (int i=0;i<nbOutputBuffers;i++)
	{
		((LoopStater*) stater)->statOutputNodeDegree(((OutputAssembly*) ((OutputBuffer*) outputBuffers[i])));
	}
		#endif
}
	#endif

	#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE
// Liens input-outputs
void EDNetwork::statInputOutputLinks()
{
	((LoopStater*) stater)->initInputPathCounters();

	for (int i=0;i<nbInputBuffers;i++)
	{
		((LoopStater*) stater)->statBreadthFirstInputNode((((EDAssembly*) ((InputAssembly*) ((InputBuffer*) inputBuffers[i])))));
	}

	for (int i=0;i<nbOutputBuffers;i++)
	{
		((LoopStater*) stater)->statBreadthFirstOutputNode((((EDAssembly*) ((OutputAssembly*) ((OutputBuffer*) outputBuffers[i])))));
	}
}
	#endif

	#ifdef _GSCC_STAT_MODE
void EDNetwork::statAssemblySCC()
{
	((LoopStater*) stater)->initGSCC();

	((AssemblyStater*) stater)->initSCComponents();

	std::vector<Assembly*>::iterator it=assemblies.begin();
	std::vector<Assembly*>::iterator end=assemblies.end();

	while (it!=end)
	{
		#ifdef _TEST_STAT
		cerr << "***** Computing GSCC for assembly " << ((Assembly*) *it)->getIndex() << " *****" << endl;
		#endif

		((LoopStater*) stater)->initDFS((Assembly*) *it);
		((LoopStater*) stater)->statGSCC((Assembly*) *it);
		it++;
	}

	((AssemblyStater*) stater)->computeSCComponents();
}

	
		#ifdef _INPUT_OUTPUT_GSCC_STAT_MODE
void EDNetwork::statInputOutputSCC()
{
	((AssemblyStater*) stater)->initInputOutputSCCCounters();

	for (int i=0;i<nbInputBuffers;i++)
	{
		((AssemblyStater*) stater)->statInputSCC((((EDAssembly*) ((InputAssembly*) ((InputBuffer*) inputBuffers[i])))));
	}

	for (int i=0;i<nbOutputBuffers;i++)
	{
		((AssemblyStater*) stater)->statOutputSCC((((EDAssembly*) ((OutputAssembly*) ((OutputBuffer*) outputBuffers[i])))));
	}
}
		#endif
	#endif
	
	#ifdef _PROJECTION_STAT_MODE
void EDNetwork::statProjections()
{	
	((AssemblyStater*) stater)->initProjectionCounters();

	std::vector<Assembly*>::iterator it=assemblies.begin();
	std::vector<Assembly*>::iterator end=assemblies.end();

	while (it!=end)
	{
		#ifdef _TEST_STAT
		cerr << "***** Computing Post projections for assembly " << ((Assembly*) *it)->getIndex() << " *****" << endl;
		#endif

		((AssemblyStater*) stater)->statPostProjections((EDAssembly*) *it);
		it++;
	}
	
	for (int i=0;i<nbInputBuffers;i++)
	{
		#ifdef _TEST_STAT
		cerr << "***** Computing Post projections for input assembly " << ((InputAssembly*) ((InputBuffer*) inputBuffers[i]))->getIndex() << " *****" << endl;
		#endif
		((AssemblyStater*) stater)->statPostProjections(((EDAssembly*) ((InputAssembly*) ((InputBuffer*) inputBuffers[i]))));
	}
}
	#endif
	
	#ifdef _CLUSTER_STAT_MODE
	
void EDNetwork::removeLinks()
{
	cerr << "Initing stat Projections" << endl;
	initTabOrderedProjections();
	
	while (tabOrderedProjections.size() < NB_PROJECTIONS_EACH_CHROMOSOME)
	{
		#ifdef _TEST_STAT
		cerr << "tabOrderedProjections: ";
		cerr << tabOrderedProjections.size() << endl;
		#endif
		
		statAssemblyPaths();
		
		#ifdef _TEST_STAT
		cerr << "statAssemblyPaths: " << endl;
		#endif
		
		((NetworkStater*) stater)->statAssemblyEfficiency(tabOrderedProjections.size());
		
		#ifdef _TEST_STAT
		cerr << "statAssemblyEfficiency " << endl;
		#endif
		
		((NetworkStater*) stater)->statAssemblyBetweenness(tabOrderedProjections.size());

		#ifdef _TEST_STAT
		cerr << "statAssemblyBetweenness " << endl;
		#endif
		
		#ifdef _MOTIF_STAT_MODE
			#ifdef _TEST
		cout << "stat Assembly Motifs" << endl;
			#endif
		statMotifs();
		
		((NetworkStater*) stater)->statAssemblyMotifs(tabOrderedProjections.size());
		#endif
		
		#ifdef _INPUT_OUTPUT_LENGTH_STAT_MODE
			#ifdef _TEST
		cout << "stat InputOutputLinks" << endl;
			#endif
		statInputOutputLinks();
		
		((NetworkStater*) stater)->statAssemblyInputOutputLinks(tabOrderedProjections.size());
		#endif
		
		#ifdef _LOOP_STAT_MODE
			#ifdef _TEST
		cout << "stat Assembly Loop" << endl;
			#endif
		statLoops();
		
		((NetworkStater*) stater)->statAssemblyLoops(tabOrderedProjections.size());
		#endif
		
		#ifdef _SMALL_WORLD_STAT_MODE
			#ifdef _TEST
		cout << "statClusteringCoeff" << endl;
			#endif
		statClusteringCoeff();
		
		((NetworkStater*) stater)->statAssemblyClusteringCoeff(tabOrderedProjections.size());
		
		#endif
		
		#ifdef _DEGREE_STAT_MODE
			#ifdef _TEST
		cout << "statDegree" << endl;
			#endif
		statDegree();

		((NetworkStater*) stater)->statAssemblyDegree(tabOrderedProjections.size());
		#endif

		#ifdef _GSCC_STAT_MODE
			#ifdef _TEST
		cout << "statAssemblySCC" << endl;
			#endif
		statAssemblySCC();

		((NetworkStater*) stater)->statAssemblyGSCC(tabOrderedProjections.size());

		#endif

		#ifdef _EDGE_BETWEENNESS_STAT_MODE
		((AssemblyStater*) stater)->computeAssemblyMaxEdgeBetweenness();

			#ifdef _TEST_STAT
		cerr << "computeAssemblyMaxEdgeBetweenness " << endl;
			#endif

		((AssemblyStater*) stater)->computeAssemblyEdgeBetweennessDistribution();

			#ifdef _TEST_STAT
		cerr << "computeAssemblyEdgeBetweennessDistribution " << endl;
			#endif
		
		((NetworkStater*) stater)->statAssemblyEdgeBetweenness(tabOrderedProjections.size());

			#ifdef _TEST_STAT
		cerr << "statAssemblyEdgeBetweenness " << endl;
			#endif
		
		((NetworkStater*) stater)->statAssemblyShortPathLength(tabOrderedProjections.size());
		
		#endif
		
		#ifdef _GN_CLUSTER_STAT_MODE
		if (removeAssemblyMaxBetweenness())
		{
			#ifdef _TEST_STAT
			cerr << "removed linked " << tabOrderedProjections.size() << endl;
			#endif
		}
		else
		{
			break;
		}
		#else
			#ifdef _EFFICIENCY_CLUSTER_STAT_MODE
		if (removeMaxEfficiencyLink())
		{
			#ifdef _TEST_STAT
			cerr << "removed linked " << tabOrderedProjections.size() << endl;
			#endif
		}
		else
		{
			break;
		}
			#else
		if (removeRandomLink())
		{
			#ifdef _TEST_STAT
			cerr << "removed linked " << tabOrderedProjections.size() << endl;
			#endif
		}
		else
		{
			break;
		}
			#endif
		#endif
	}
	
	cout << "Breaking with nb ordered projections = " << tabOrderedProjections.size() << endl;
}

void EDNetwork::buildClusters()
{		
		#ifdef _TEST_STAT
	int count=0;
	
	std::vector<Projection*>::iterator it = tabOrderedProjections.begin();
	std::vector<Projection*>::iterator end = tabOrderedProjections.end();
	
	while (it != end)
	{
		cout << count << " " << (Projection&) *(*it);
		count++;
		it++;
	}
		#endif
	
		#ifdef _GRAPHICAL_DISPLAY_MODE
	((TopologyDisplayer*) displayer)->cleanDisplay();
		#endif
		
	initTabClusters();
	
	cout << "Initing cluster determination " << endl;
	
	nbInternalProjections = tabOrderedProjections.size();
	
	statAssemblyPaths();
				
		#ifdef _TEST
	cerr << "After last statAssemblyPaths" << endl;
		#endif
		
		#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
	((NetworkStater*) stater)->initCurMaxModularity();
		#endif
		
	while (0 < tabOrderedProjections.size())
	{
		#ifdef _TEST
		cout << "tabOrderedProjections: " << tabOrderedProjections.size() << endl;
		#endif
		Projection* curProjection = tabOrderedProjections.back();
			
		#ifdef _GRAPHICAL_DISPLAY_MODE
		((TopologyDisplayer*) displayer)->traceProjection((Projection*) curProjection);
		display();
		((TopologyDisplayer*) displayer)->flushDisplay();
		#endif

		#ifdef _TEST
		cout << "statClusters" << endl;
		#endif
		updateClusters(curProjection);
		
		statClusterEfficiency();
		
		#ifdef _CLUSTER_CENTRALITY_STAT_MODE
		
			#ifdef _CENTRALITY_STAT_MODE
		statLinkedClusterPath();
			#endif		
				
			#ifdef _SMALL_WORLD_STAT_MODE
		statLinkedClusterClusteringCoeffs();
			#endif
			
			#ifdef _DEGREE_STAT_MODE
		statLinkedClusterDegree();
			#endif
				
			#ifdef _MOTIF_STAT_MODE
				#ifdef _TEST
		cout << "stat LinkedCluster Motifs" << endl;
				#endif
		statLinkedClusterMotifs();
			#endif
		#endif
			
		#ifdef _INTERNAL_MOTIF_STAT_MODE
			#ifdef _TEST
		cout << "stat Internal Motifs" << endl;
			#endif
		statInternalMotifs();	
		#endif
		
		#ifdef _LOOP_STAT_MODE
			#ifdef _TEST
		cout << "statInternalClusterLoops" << endl;
			#endif
		statInternalClusterLoops();
		#endif
	
		#ifdef _SMALL_WORLD_STAT_MODE
			#ifdef _TEST
		cout << "statClusterInternalDensity" << endl;
			#endif
		statClusterInternalDensity();
		#endif
		
		#ifdef _TEST
		cout << "statCluster at " << tabOrderedProjections.size() << endl;
		#endif
		
		((NetworkStater*) stater)->computeModularity((EDNetwork*) this);
		
		#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
		if (((NetworkStater*) stater)->checkOptimalClusters(tabOrderedProjections.size()-1))
		{
			cloneTabClusters();
		}
		#endif
			
		((NetworkStater*) stater)->statClusters(tabOrderedProjections.size()-1);

		#ifdef _TEST
		cerr << "tabClusters: " << tabClusters.size() << endl;
		#endif

		delete(curProjection);
		
		tabOrderedProjections.pop_back();
	}
	
	cout << "tabOrderedProjections size " << tabOrderedProjections.size() << endl;
	
		#ifdef _NETWORK_CLUSTER_STAT_MODE
			#ifdef _TEST
	cerr << "statNetworkClusters" << endl;
			#endif

	((NetworkStater*) stater)->statNetworkClusters();
		#endif

		#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
	computeTabOptimalClusters();
	
	((NetworkStater*) stater)->statOptimalClusters();
			
			#ifdef _MATRIX_CLUSTERS_STAT_MODE
	((NetworkStater*) stater)->initClusterMatrix();
	
				#ifdef _LINKED_CLUSTER_STAT_MODE
	std::vector<LinkedCluster*>::iterator it = tabOptimalClusters.begin();
	std::vector<LinkedCluster*>::iterator end = tabOptimalClusters.end();
	
	while (it != end)
	{
		((NetworkStater*) stater)->statMatrixClusters((Cluster*) *it);
		it++;
	}
				#else
	std::vector<Cluster*>::iterator it = tabOptimalClusters.begin();
	std::vector<Cluster*>::iterator end = tabOptimalClusters.end();
	
	while (it != end)
	{
		((NetworkStater*) stater)->statMatrixClusters((Cluster*) *it);
		it++;
	}
				#endif
	
	((NetworkStater*) stater)->printClusterMatrix();
	
			#endif
		#endif

		#ifdef _TEST
	cerr << "freeing tabClusters" << endl;
		#endif
	freeTabClusters();	
}	

		#ifdef _SAVE_ORDERED_PROJECTIONS_MODE
void EDNetwork::saveTabOrderedProjections()
{
	if (tabOrderedProjectionsFile->isOpen())
	{
		
		cout << "tabOrderedProjectionsFile is open" << endl;
		ostringstream oss2;
		
		std::vector<Projection*>::iterator it = tabOrderedProjections.begin();
		std::vector<Projection*>::iterator end = tabOrderedProjections.end();
		
		int count =0;
		
		while (it != end)
		{
		
			if (count !=0)
			{
				oss2 << " ";
			}
		
			oss2 << (Projection&) *(*it);
			
			//oss2 << (Projection&) *(*it) << " ";
			it++;
			count++;
		}	
		
		oss2 << endl;
		
		cout << "*** EDNetwork *** saving tabOrderedProjections" << endl;
		
		tabOrderedProjectionsFile->add((ostringstream*) &oss2);
	}
	else
	{
		cerr << "Warning, tabOrderedProjectionsFile is not open" << endl;
		return;
	}
}
		#else	
			#ifdef _LOAD_ORDERED_PROJECTIONS_MODE
void EDNetwork::loadTabOrderedProjections()
{
	if (tabOrderedProjectionsFile->isOpen())
	{
		istream& is((istream&) tabOrderedProjectionsFile->getFile());
		
		cerr << "before tabPos" << endl;
		
		int projNature,preIndex,postIndex;
		
		while (is >> projNature >> preIndex >> postIndex)
		{
			if (is.peek() != '\n')
			{
				cout << projNature << " " << preIndex << " " << postIndex << " ";
				
				if (preIndex < NB_ASSEMBLIES && postIndex < NB_ASSEMBLIES)
				{
					if (removeProjection(preIndex,postIndex))
					{
						cout << "removeProjections(" << preIndex << "," << postIndex << ")" << endl;
						
					}
					else
					{
						cerr << "Warning, unable to remove projection(" << preIndex << "," << postIndex << ")" << endl;
						break;
					}
				}
				else
				{
					cout << "projection is input or output (" << preIndex << "," << postIndex << ")" << endl;
				}
			}
			else
			{
				cout << "End of line" << endl;
				break;
			}
		}
		
		cout << "Out of while" << endl;
		
		return;
		
	}
	else
	{
		cerr << "Warning, tabOrderedProjectionsFile is not open" << endl;
		return;
	}

}
			#endif
		
		#endif
		
bool EDNetwork::removeProjection(int preAssemblyIndex, int postAssemblyIndex)
{	
	EDAssembly* preAssembly;
	EDAssembly* postAssembly;
	
		#ifdef _TEST_STAT
	cout << "Deleting projection " << preAssemblyIndex << " -> " << postAssemblyIndex  << endl;
		#endif
	
	if (0 <= preAssemblyIndex && preAssemblyIndex < NB_ASSEMBLIES)
	{
		preAssembly = (EDAssembly*) ((Assembly*) assemblies[preAssemblyIndex]);
	}
	else
	{
		cerr << "Warning, wrong pre assembly index " <<  preAssemblyIndex << endl;
		return 0;
	}
	
	if (0 <= postAssemblyIndex && postAssemblyIndex < NB_ASSEMBLIES)
	{
		postAssembly = (EDAssembly*) ((Assembly*) assemblies[postAssemblyIndex]);
	}
	else
	{
		cerr << "Warning, wrong post assembly index " <<  postAssemblyIndex << endl;
		return 0;
	}
	
	Link* deletedProjection = (Link*) ((EDAssembly*) preAssembly)->eraseOutputLink((EDAssembly*) postAssembly);
					
	if (deletedProjection != 0)
	{
		//delete(deletedProjection);
		tabOrderedProjections.push_back((Projection*) deletedProjection);
		return 1;
	}
	else
	{
		return 0;
	}
}

		#ifdef _GN_CLUSTER_STAT_MODE
bool EDNetwork::removeAssemblyMaxBetweenness()
{
	if (0.0 < ((AssemblyStater*) stater)->getAssemblyMaxEdgeBetweenness())
	{
		if (removeProjection(((AssemblyStater*) stater)->getPreAssemblyMaxEdgeBetweenness(),((AssemblyStater*) stater)->getPostAssemblyMaxEdgeBetweenness()))
		{
			return 1;
		}
		else
		{
			cerr << "Warning, unable to delete projection " << ((AssemblyStater*) stater)->getPreAssemblyMaxEdgeBetweenness() << " -> " << ((AssemblyStater*) stater)->getPostAssemblyMaxEdgeBetweenness() << endl;
		}
	}
	else
	{
		return 0;
	}
}

		#else
			#ifdef _EFFICIENCY_CLUSTER_STAT_MODE
bool EDNetwork::removeMaxEfficiencyLink()
{	
	double realGlobalEfficiency = ((AssemblyStater*) stater)->getAssemblyGlobalEfficiency();
	
				
			#ifdef _TEST
	cout << "removeMaxEfficiencyLink " << tabOrderedProjections.size() << ", efficency " << realGlobalEfficiency << endl;
			#endif
	// 
	double bestGlobalEfficiency = -1.0;
		
	Link* bestDeletedProjection =0;
	
				
				
	std::vector<Assembly*>::iterator it=assemblies.begin();
	std::vector<Assembly*>::iterator end=assemblies.end();

	while (it!=end)
	{
					#ifdef _TEST
		cout << "For assembly " << ((Assembly*) *it)->getIndex() << " with " << ((Assembly*) *it)->getNbOutputLinks() << " output links" << endl;
					#endif
		
		for (int i=0;i < ((EDAssembly*) *it)->getNbInternalOutputLinks(); i++)
		{
					#ifdef _TEST
			cout << "Before remove, Assembly " << ((EDAssembly*) *it)->getIndex() << " has " << ((EDAssembly*) *it)->getNbInternalOutputLinks() << " links" << endl;
			cout << (Node&) *(*it);
					#endif
			
			// Suppression du liens
			Link* deletedProjection = (Link*) ((EDAssembly*) *it)->eraseInternalOutputLink(i);
			
			
					#ifdef _TEST
			cout << "Deleted projection: " << (Projection&) *deletedProjection << endl;
					#endif
			
					#ifdef _TEST
			cout << "After remove, Assembly " << ((EDAssembly*) *it)->getIndex() << " has " << ((EDAssembly*) *it)->getNbOutputLinks() << " links" << endl;
			cout << (Node&) *(*it);
					#endif
			
			if (deletedProjection != 0)
			{
				// Pour savoir si on a déja ajouté un lien
				// Efficacite intermédiare courante
				double newIntermediateGlobalEfficiency = computeIntermediateEfficiency();
			
					#ifdef _TEST		
				cout << "newIntermediateGlobalEfficiency: " << newIntermediateGlobalEfficiency << endl;
					#endif
				
				if (bestGlobalEfficiency < 0.0)
				{
					
					#ifdef _TEST
					cout << "first: " << newIntermediateGlobalEfficiency << endl;
					#endif
					
					// Cas où l'on a pas encore ajoute de liens
					bestDeletedProjection = (Link*) deletedProjection;
						
					// Efficacite intermediaire plus faible que la global
					//tabOrderedProjections.push_back((Projection*) bestDeletedProjection);
					
					#ifdef _TEST		
					cout << "After clone, tabOrderedProjections size " << tabOrderedProjections.size() << endl;
					#endif			
					bestGlobalEfficiency = newIntermediateGlobalEfficiency;
				}
				else
				{
					// Une projection a deja ete rajouté
					if (newIntermediateGlobalEfficiency < bestGlobalEfficiency)
					{
						// La projection courante est plus influente que celle déja stocké
						bestDeletedProjection = (Link*) deletedProjection;
					
						// Efficacite intermediaire plus faible que la global
						bestGlobalEfficiency = newIntermediateGlobalEfficiency;
							
					#ifdef _TEST
						cout << "Lowest GlobalEfficiency: " << bestGlobalEfficiency << endl;				
						cout << "Best projection: " << (Projection&) *deletedProjection << endl;
					#endif
					}
				}
			}
			else
			{
				cerr << "Warning, unable to delete " << i << "th projection of assembly " << ((Assembly*) *it)->getIndex() << endl;
				return 0;
			}
			
			// Ajout du lien supprimé;
			((EDAssembly*) *it)->insertInternalOutputLink((Link*) deletedProjection,i);
			
			Node* postNode = ((Link*) deletedProjection)->getPostNode();
			
			((Node*) postNode)->addInputLink((Link*) deletedProjection);
			
					#ifdef _TEST	
			double afterGlobalEfficiency = computeIntermediateEfficiency();
			cout << "After add (" << realGlobalEfficiency << "), afterGlobalEfficiency: " << afterGlobalEfficiency << endl;
			cout << "After add, Assembly " << ((EDAssembly*) *it)->getIndex() << " has " << ((EDAssembly*) *it)->getNbOutputLinks() << " links" << endl;
			cout << (Node&) *(*it);
					#endif
		}				

		it++;
	}
				
	// Suppression de la meilleure projection
	if (bestDeletedProjection != 0)
	{
		if (bestGlobalEfficiency != -1.0)
		{
			
			int bestProjectionPreAssembly =  ((Node*) ((Link*) bestDeletedProjection)->getPreNode())->getIndex();
			int bestProjectionPostAssembly =  ((Node*) ((Link*) bestDeletedProjection)->getPostNode())->getIndex();
			
			cout << "For " << tabOrderedProjections.size() << " " << realGlobalEfficiency << ", best projection: " << bestGlobalEfficiency << endl;
			
			if (removeProjection(bestProjectionPreAssembly, bestProjectionPostAssembly))
			{
				return 1;
			}
			else
			{
				cerr << "Warning, unable to delete projection " << bestProjectionPreAssembly << " -> " << bestProjectionPostAssembly << endl;
				return 0;
			}
		}
		else
		{
			cout << "no modif efficiency" << endl;
			return 0;
		}
	}
	else
	{
		cout << "no more internal projections" << endl;
		return 0;
	}	
}

double EDNetwork::computeIntermediateEfficiency()
{
	((LoopStater*) stater)->initPathCounters();
	
	std::vector<Assembly*>::iterator it=assemblies.begin();
	std::vector<Assembly*>::iterator end=assemblies.end();

	while (it!=end)
	{
		#ifdef _TEST_STAT
		cerr << "Computing breadth first search for assembly " << ((Assembly*) *it)->getIndex() << endl;
		#endif
		((LoopStater*) stater)->initBreadthFirstPostLinks((Assembly*) *it);
		((LoopStater*) stater)->statBreadthFirstPostLinks((Assembly*) *it);
		it++;
	}
	
	((AssemblyStater*) stater)->initCounters();
	
		#ifdef _TEST_STAT
	cout << "Computing assembly efficiency " << endl;
		#endif
		
	std::vector<Assembly*>::iterator it2=assemblies.begin();
	std::vector<Assembly*>::iterator end2=assemblies.end();

	while (it2!=end2)
	{
		#ifdef _TEST_STAT
		cout << "Computing efficiency for assembly " << ((Assembly*) *it2)->getIndex() << endl;
		#endif

		((LoopStater*) stater)->computeEfficiency((Assembly*) *it2);
		it2++;
	}
	
	((AssemblyStater*) stater)->computeAssemblyEfficiency();
	
	double intermediateEfficiency = ((AssemblyStater*) stater)->getAssemblyGlobalEfficiency();
	
	return intermediateEfficiency;
}
			#else
bool EDNetwork::removeRandomLink()
{
					//#ifdef _TEST
	cout << "Removing random link " << tabOrderedProjections.size() << endl;
					//#endif
	
	bool hasOutputProjections[NB_ASSEMBLIES];
	bool hasInputProjections[NB_ASSEMBLIES];
	
	for (int i=0; i< NB_ASSEMBLIES;i++)
	{
		hasOutputProjections[i] = 1;
		hasInputProjections[i] = 1;
	}
	
	for (;;)
	{
		// Recherche d'un projection non detruite
		int preProjectionIndex = randomInt(NB_ASSEMBLIES);
		int postProjectionIndex = randomInt(NB_ASSEMBLIES);
		
		if (hasOutputProjections[preProjectionIndex] != 0 && hasInputProjections[postProjectionIndex] != 0)
		{
			if (((Assembly*) assemblies[preProjectionIndex])->getNbInternalOutputLinks() == 0)
			{
				hasOutputProjections[preProjectionIndex] = 0;
			}
			
			if (((Assembly*) assemblies[postProjectionIndex])->getNbInternalInputLinks() == 0)
			{
				hasInputProjections[postProjectionIndex] = 0;
			}
			
			if ((hasOutputProjections[preProjectionIndex] != 0) && (hasInputProjections[postProjectionIndex]!=0))
			{	
				if (removeProjection(preProjectionIndex,postProjectionIndex))
				{
					return 1;
				}
			}
		} 
		
		// Verication si liens encore presents
		
		int nbAssembliesWithInputs = 0;
		int nbAssembliesWithOutputs = 0;
		
		
		for (int i=0; i< NB_ASSEMBLIES;i++)
		{
			if (hasInputProjections[i] == 1)
			{
				nbAssembliesWithInputs++;
			}
			
			if (hasOutputProjections[i] == 1)
			{
				nbAssembliesWithOutputs++;
			}
		}
		
		if (nbAssembliesWithInputs == 0 || nbAssembliesWithOutputs == 0)
		{
			cout << "no more internal projections" << endl;
								
			return 0;
		}
		else
		{
					#ifdef _TEST_STAT
			cout << "nbAssembliesWithInputs: " << nbAssembliesWithOutputs << ", nbAssembliesWithOutputs: " << nbAssembliesWithOutputs << endl;
					#endif
		}
	}
}			
			#endif
		#endif

void EDNetwork::initTabOrderedProjections()
{
	if (tabOrderedProjections.size() != 0)
	{
		tabOrderedProjections.erase(tabOrderedProjections.begin(),tabOrderedProjections.end());
	}
}

void EDNetwork::initTabClusters()
{
		#ifdef _LINKED_CLUSTER_STAT_MODE

	std::vector<Assembly*>::iterator it=assemblies.begin();
	std::vector<Assembly*>::iterator end=assemblies.end();

	while (it!=end)
	{
		LinkedCluster* newCluster = new LinkedCluster((Assembly*) *it);
		tabInitialClusters.push_back(newCluster);
		it++;
	}

	tabClusters = tabInitialClusters;

			#ifdef _TEST
	std::vector<LinkedCluster*>::iterator itClust=tabClusters.begin();
	std::vector<LinkedCluster*>::iterator endClust=tabClusters.end();

	while (itClust!=endClust)
	{
		cout << ((LinkedCluster&) (*(*itClust)));
		itClust++;
	}
			#endif
		#else

	std::vector<Assembly*>::iterator it=assemblies.begin();
	std::vector<Assembly*>::iterator end=assemblies.end();

	while (it!=end)
	{
		Cluster* newCluster = new Cluster((Assembly*) *it);
		tabInitialClusters.push_back(newCluster);
		it++;
	}
	
	tabClusters = tabInitialClusters;
	
			#ifdef _TEST
	std::vector<Cluster*>::iterator itClust=tabClusters.begin();
	std::vector<Cluster*>::iterator endClust=tabClusters.end();

	while (itClust!=endClust)
	{
		cout << ((Cluster&) (*(*itClust)));
		itClust++;
	}
			#endif
		#endif
}

void EDNetwork::updateClusters(Projection* curProjection)
{
		#ifdef _TEST
	cout << "********************************** " << (Projection&) *curProjection;
		#endif

		#ifdef _LINKED_CLUSTER_STAT_MODE

	bool preClust=0;
	bool postClust=0;

	std::vector<LinkedCluster*>::iterator preClustIt;
	std::vector<LinkedCluster*>::iterator postClustIt;
	
	std::vector<LinkedCluster*>::iterator it=tabClusters.begin();
	std::vector<LinkedCluster*>::iterator end=tabClusters.end();

	while (it!=end)
	{	
		if (((Cluster*) *it)->isInCluster((Assembly*) curProjection->getPreNode()))
		{
			#ifdef _TEST
			cout << "Pre : Assembly " << ((Assembly*) curProjection->getPreAssembly())->getIndex() << ", In cluster " << (LinkedCluster&) *(*it) << endl;
			#endif
			preClustIt = it;
			preClust = 1;
		}
		
		if (((Cluster*) *it)->isInCluster((Assembly*) curProjection->getPostNode()))
		{
			#ifdef _TEST
			cout << "Post: Assembly " << ((Assembly*) curProjection->getPostAssembly())->getIndex() << ", In cluster " << (LinkedCluster&) *(*it) << endl;
			#endif
			postClustIt = it;
			postClust = 1;
		}
		it++;
	}

	if (preClust && postClust)
	{
		if (!((Cluster*) *preClustIt)->isSameCluster((Cluster*) *postClustIt))
		{
			#ifdef _TEST
			cerr << "********************************Scanning cluster loop" << " from " << ((LinkedCluster*) *postClustIt)->getIndex();
			cerr << " to " << ((LinkedCluster*) *preClustIt)->getIndex() << endl;
			#endif
			
			((LoopStater*) stater)->initTabNodes();
			std::vector<Node*> loopClusters = ((LoopStater*) stater)->scanLoopCluster((LinkedCluster*) *postClustIt,(LinkedCluster*) *preClustIt);
			
			#ifdef _TEST
			cerr << "After scan cluster loop" << endl;
			#endif
			
			if (loopClusters.size() != 0)
			{
			#ifdef _TEST
				cerr << "Detected cluster loop of size " << loopClusters.size();
				cerr << " from " << ((LinkedCluster*) *postClustIt)->getIndex();
				cerr << " to " << ((LinkedCluster*) *preClustIt)->getIndex() << endl;
			#endif			

				// Concatenation des clusters
				std::vector<Node*>::iterator it2 = loopClusters.begin();
				std::vector<Node*>::iterator end2 = loopClusters.end();

				while (it2 != end2)
				{
			#ifdef _TEST
					cout << (LinkedCluster&) *(*it2);
			#endif
					std::vector<LinkedCluster*>::iterator itClust=tabClusters.begin();
					std::vector<LinkedCluster*>::iterator endClust=tabClusters.end();

					while (itClust != endClust)
					{
						if (((LinkedCluster*) *itClust)->isSameCluster((LinkedCluster*) *it2))
						{
			#ifdef _TEST
							cout << (LinkedCluster&) *(*itClust);
							
							cout << "Adding cluster " << ((Cluster*) *itClust)->getIndex() << " to " << ((Cluster*) *preClustIt)->getIndex() << endl;
			#endif
							((LinkedCluster*) *preClustIt)->addCluster((Cluster*) *itClust);

						}

						itClust++;
					}
    					it2++;
				}

			#ifdef _TEST
				cout << "After add : " << endl;
				cout << (LinkedCluster&) *(*preClustIt) << endl;
			#endif
				
				// Ajout des liens
				std::vector<Node*>::iterator it3 = loopClusters.begin();
				std::vector<Node*>::iterator end3 = loopClusters.end();

				while (it3 != end3)
				{
			#ifdef _TEST
					cout << (LinkedCluster&) *(*it3);
			#endif
					std::vector<LinkedCluster*>::iterator itClust=tabClusters.begin();
					std::vector<LinkedCluster*>::iterator endClust=tabClusters.end();

					while (itClust != endClust)
					{
						if (((LinkedCluster*) *itClust)->isSameCluster((LinkedCluster*) *it3))
						{
			#ifdef _TEST	
							cout << "Adding cluster " << ((LinkedCluster*) *itClust)->getIndex() << " to " << ((LinkedCluster*) *preClustIt)->getIndex() << endl;
			#endif
			#ifdef _TEST
							cout << (LinkedCluster&) *(*itClust);
			#endif			
							((LinkedCluster*) *preClustIt)->addLinkedCluster((LinkedCluster*) *itClust);

						}

						itClust++;
					}
    					it3++;
				}
			#ifdef _TEST
				cout << "After add Links: " << endl;
				cout << (LinkedCluster&) *(*preClustIt) << endl;
			#endif
				int removedIndex = 0;
				
				while (removedIndex != -1)
				{
			#ifdef _TEST
					cout << "Before remove index: ";
					cout << (LinkedCluster&) *(*preClustIt) << endl;
			#endif
					removedIndex = ((LinkedCluster*) *preClustIt)->checkIntegrity();
			#ifdef _TEST		
					cout << "removedIndex = " << removedIndex << endl;
			#endif		
					if (removedIndex == -1)
					{
						break;
					}

					std::vector<LinkedCluster*>::iterator itClust=tabClusters.begin();
					std::vector<LinkedCluster*>::iterator endClust=tabClusters.end();

					while (itClust != endClust)
					{
						if (((LinkedCluster*) *itClust)->sameIndex(removedIndex))
						{
			#ifdef _TEST	
							cout << "Adding cluster " << ((LinkedCluster*) *itClust)->getIndex() << " to " << ((LinkedCluster*) *preClustIt)->getIndex() << endl;
			#endif
							((LinkedCluster*) *preClustIt)->addCluster((Cluster*) *itClust);
							((LinkedCluster*) *preClustIt)->addLinkedCluster((LinkedCluster*) *itClust);
			#ifdef _TEST
							cout << "Erasing cluster " << ((LinkedCluster*) *itClust)->getIndex() << endl;
			#endif
							loopClusters.push_back((LinkedCluster*) *itClust);
							
							break;
						}

						itClust++;
					}
					
			#ifdef _TEST
					cout << "After remove index" << endl;
					cout << (LinkedCluster&) *(*preClustIt) << endl;
			#endif				
				}
				std::vector<Node*>::iterator it4 = loopClusters.begin();
				std::vector<Node*>::iterator end4 = loopClusters.end();

				while (it4 != end4)
				{
    					std::vector<LinkedCluster*>::iterator itClust=tabClusters.begin();
					std::vector<LinkedCluster*>::iterator endClust=tabClusters.end();

					while (itClust != endClust)
					{
						if (((LinkedCluster*) *itClust)->isSameCluster((LinkedCluster*) *it4))
						{
			#ifdef _TEST
							cout << "Erasing cluster " << ((LinkedCluster*) *itClust)->getIndex() << endl;
			#endif

							tabClusters.erase(itClust);
						}

						itClust++;
					}

					it4++;
				}		
			}
			else if (!(((LinkedCluster*) *preClustIt)->isOutputLinked((LinkedCluster*) *postClustIt) || ((LinkedCluster*) *postClustIt)->isInputLinked((LinkedCluster*) *preClustIt)))
			{
			
			#ifdef _TEST
				cout << "***************** Linking cluster " << ((LinkedCluster*) *preClustIt)->getIndex();
				cout << " to cluster " << ((LinkedCluster*) *postClustIt)->getIndex() << endl;
			#endif
			
			#ifdef _TEST
				cout << "Pre Clust: " << (LinkedCluster&) *(*preClustIt) << endl;
				cout << "Post Clust: " << (LinkedCluster&) *(*postClustIt) << endl;
			#endif

				ClusterLink* newClusterLink = new ClusterLink(*preClustIt,*postClustIt);
				tabClusterLinks.push_back(newClusterLink);
			#ifdef _TEST
				cout << (ClusterLink&) *newClusterLink << endl;
			#endif	
				((LinkedCluster*) *preClustIt)->addOutputLink(newClusterLink);
				((LinkedCluster*) *postClustIt)->addInputLink(newClusterLink);

			#ifdef _TEST
				cout << "Pre Clust: " << (LinkedCluster&) *(*preClustIt) << endl;;
				cout << "Post Clust: " << (LinkedCluster&) *(*postClustIt) << endl;;
			#endif
			}
			else
			{
				cout << "A link exist from " << ((LinkedCluster*) *preClustIt)->getIndex() << " to ";
				cout << ((LinkedCluster*) *postClustIt)->getIndex() << "(" << ((LinkedCluster*) *preClustIt)->isOutputLinked((LinkedCluster*) *postClustIt) << " ";
				cout << ((LinkedCluster*) *postClustIt)->isInputLinked((LinkedCluster*) *preClustIt) << ")" << endl;
				
			}

			loopClusters.erase(loopClusters.begin(),loopClusters.end());	
			loopClusters.clear();	
			
		}
		else
		{
			#ifdef _TEST
			cout << "No modification for clusters" << endl;
			#endif
		}
	}
	else
	{
		if (!preClust)
		{
			cerr << "Warning, unable to find pre assembly " << ((Assembly*) curProjection->getPreNode())->getIndex() << endl; 
		}
		
		if (!postClust)
		{
			cerr << "Warning, unable to find post assembly " << ((Assembly*) curProjection->getPostNode())->getIndex() << endl; 
		}

		std::vector<LinkedCluster*>::iterator itClust=tabClusters.begin();
		std::vector<LinkedCluster*>::iterator endClust=tabClusters.end();

		while (itClust!=endClust)
		{
			cerr << ((LinkedCluster&) (*(*itClust))) << endl;
			itClust++;
		}
	}

			#ifdef _TEST
	std::vector<LinkedCluster*>::iterator itClust=tabClusters.begin();
	std::vector<LinkedCluster*>::iterator endClust=tabClusters.end();

	while (itClust!=endClust)
	{
		cerr << ((LinkedCluster&) (*(*itClust))) << endl;
		itClust++;
	}
			#endif
		
		#else
	bool preClust=0;
	bool postClust=0;
	
	std::vector<Cluster*>::iterator preClustIt;
	std::vector<Cluster*>::iterator postClustIt;
	
	std::vector<Cluster*>::iterator it=tabClusters.begin();
	std::vector<Cluster*>::iterator end=tabClusters.end();

	int maxClusterSize =0;
	int nbClusters = tabClusters.size();

	while (it!=end)
	{
		if (maxClusterSize < ((Cluster*) *it)->getClusterSize())
		{
			maxClusterSize = ((Cluster*) *it)->getClusterSize();
		}
		
		if (((Cluster*) *it)->isInCluster((Assembly*) ((Link*) curProjection)->getPreNode()))
		{
			preClustIt = it;
			preClust = 1;
		}
		
		if (((Cluster*) *it)->isInCluster((Assembly*) ((Link*) curProjection)->getPostNode()))
		{
			postClustIt = it;
			postClust = 1;
		}
		it++;
	}

	if (preClust && postClust)
	{
		if (((Cluster*) *preClustIt) != ((Cluster*) *postClustIt))
		{
			((Cluster*) *preClustIt)->addCluster((Cluster*) *postClustIt);
			tabClusters.erase(postClustIt);
		}
		else
		{
			#ifdef _TEST
			cout << "No modification for clusters" << endl; 
			#endif
		}
	}
	else
	{
		if (!preClust)
		{
			cerr << "Warning, unable to find pre assembly " << ((Assembly*) ((Link*) curProjection)->getPreNode())->getIndex() << endl; 
		}
		
		if (!postClust)
		{
			cerr << "Warning, unable to find post assembly " << ((Assembly*) ((Link*) curProjection)->getPostNode())->getIndex() << endl; 
		}
		//	#ifdef _TEST
		std::vector<Cluster*>::iterator itClust=tabClusters.begin();
		std::vector<Cluster*>::iterator endClust=tabClusters.end();

		while (itClust!=endClust)
		{
			cout << ((Cluster&) (*(*itClust)));
			itClust++;
		}
		//	#endif
	}
		#endif

	
}

void EDNetwork::statClusterEfficiency()
{
		#ifdef _LINKED_CLUSTER_STAT_MODE
	((ClusterStater*) stater)->initCounters();
	((LinkedClusterStater*) stater)->initCounters();
	
	// Calcul d'efficacité intra-cluster
	std::vector<LinkedCluster*>::iterator it3=tabClusters.begin();
	std::vector<LinkedCluster*>::iterator end3=tabClusters.end();

	while (it3!=end3)
	{
			#ifdef _TEST
		cout << "Linked Cluster  = " << ((LinkedCluster*) *it3)->getIndex() << endl;
			#endif
		((LinkedClusterStater*) stater)->stat((LinkedCluster*) *it3);
		it3++;
	}
	
	((ClusterStater*) stater)->computeClusterEfficiency();		
		#else
	
	((ClusterStater*) stater)->initCounters();

	// Calcul d'efficacité
	std::vector<Cluster*>::iterator it2=tabClusters.begin();
	std::vector<Cluster*>::iterator end2=tabClusters.end();

	while (it2!=end2)
	{
		((ClusterStater*) stater)->statClusterSize((Cluster*) *it2);
		((ClusterStater*) stater)->computeEfficiency((Cluster*) *it2);
		it2++;
	}
	
	((ClusterStater*) stater)->computeClusterEfficiency();
	
		#endif
}

void EDNetwork::freeTabClusters()
{
		#ifdef _LINKED_CLUSTER_STAT_MODE
			#ifdef _TEST
	std::vector<LinkedCluster*>::iterator itClust=tabClusters.begin();
	std::vector<LinkedCluster*>::iterator endClust=tabClusters.end();

	while (itClust!=endClust)
	{
		cout << ((LinkedCluster&) (*(*itClust)));
		itClust++;
	}
			#endif

	std::vector<ClusterLink*>::iterator itClustLink=tabClusterLinks.begin();
	std::vector<ClusterLink*>::iterator endClustLink=tabClusterLinks.end();

	while (itClustLink!=endClustLink)
	{
		delete((ClusterLink*) *itClustLink);
		itClustLink++;
	}

	tabClusterLinks.erase(tabClusterLinks.begin(),tabClusterLinks.end());
	tabClusterLinks.clear();

	tabClusters.erase(tabClusters.begin(),tabClusters.end());
	tabClusters.clear();

	std::vector<LinkedCluster*>::iterator it=tabInitialClusters.begin();
	std::vector<LinkedCluster*>::iterator end=tabInitialClusters.end();

	while (it!=end)
	{

		delete((LinkedCluster*) *it);
		it++;
	}

	tabInitialClusters.erase(tabInitialClusters.begin(),tabInitialClusters.end());
	tabInitialClusters.clear();
		#else
			#ifdef _TEST
	std::vector<Cluster*>::iterator itClust=tabClusters.begin();
	std::vector<Cluster*>::iterator endClust=tabClusters.end();

	while (itClust!=endClust)
	{
		cout << ((Cluster&) (*(*itClust)));
		itClust++;
	}
			#endif
	tabClusters.erase(tabClusters.begin(),tabClusters.end());
	tabClusters.clear();

	std::vector<Cluster*>::iterator it=tabInitialClusters.begin();
	std::vector<Cluster*>::iterator end=tabInitialClusters.end();

	while (it!=end)
	{

		delete((Cluster*) *it);
		it++;
	}

	tabInitialClusters.erase(tabInitialClusters.begin(),tabInitialClusters.end());
	tabInitialClusters.clear();
		#endif

		#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
	freeTabOptimalClusters();
		#endif
}
		#ifdef _OPTIMAL_CLUSTERS_STAT_MODE
void EDNetwork::freeTabOptimalClusters()
{
			#ifdef _LINKED_CLUSTER_STAT_MODE
	std::vector<LinkedCluster*>::iterator it=tabOptimalClusters.begin();
	std::vector<LinkedCluster*>::iterator end=tabOptimalClusters.end();

	while (it!=end)
	{
		((LinkedCluster*) *it)->destroyLinks();

		delete((LinkedCluster*) *it);
		it++;
	}
			#else
	std::vector<Cluster*>::iterator it=tabOptimalClusters.begin();
	std::vector<Cluster*>::iterator end=tabOptimalClusters.end();

	while (it!=end)
	{
		delete((Cluster*) *it);
		it++;
	}
			#endif

	tabOptimalClusters.erase(tabOptimalClusters.begin(),tabOptimalClusters.end());
	tabOptimalClusters.clear();
}

void EDNetwork::cloneTabClusters()
{
	if (tabOptimalClusters.size() != 0)
	{
		freeTabOptimalClusters();
	}
			#ifdef _LINKED_CLUSTER_STAT_MODE
	std::vector<LinkedCluster*>::iterator itClust=tabClusters.begin();
	std::vector<LinkedCluster*>::iterator endClust=tabClusters.end();

	while (itClust!=endClust)
	{
		LinkedCluster* newCluster = ((LinkedCluster*) *itClust)->clone();
		tabOptimalClusters.push_back((LinkedCluster*) newCluster);
		itClust++;
	}

	cloneTabClusterLinks();

			#else
	std::vector<Cluster*>::iterator itClust=tabClusters.begin();
	std::vector<Cluster*>::iterator endClust=tabClusters.end();

	while (itClust!=endClust)
	{
		Cluster* newCluster = ((Cluster*) *itClust)->clone();
		tabOptimalClusters.push_back((Cluster*) newCluster);
		itClust++;
	}
			#endif
}

void EDNetwork::computeTabOptimalClusters()
{
			#ifdef _CENTRALITY_STAT_MODE
	
				#ifdef _LINKED_CLUSTER_STAT_MODE
	((ClusterStater*) stater)->initCounters();
	((LinkedClusterStater*) stater)->initCounters();
	
	
	// Calcul d'efficacité intra-cluster
	std::vector<LinkedCluster*>::iterator it=tabOptimalClusters.begin();
	std::vector<LinkedCluster*>::iterator end=tabOptimalClusters.end();

	while (it!=end)
	{
					#ifdef _TEST
		cout << "Linked Cluster  = " << ((LinkedCluster*) *it)->getIndex() << endl;
					#endif
		((LinkedClusterStater*) stater)->stat((LinkedCluster*) *it);
		it++;
	}
		
	((ClusterStater*) stater)->computeClusterEfficiency();	
				#else

	((ClusterStater*) stater)->initCounters();
	// Calcul d'efficacité
	std::vector<Cluster*>::iterator it=tabOptimalClusters.begin();
	std::vector<Cluster*>::iterator end=tabOptimalClusters.end();

	while (it!=end)
	{
		((ClusterStater*) stater)->statClusterSize((Cluster*) *it);
		((ClusterStater*) stater)->computeEfficiency((Cluster*) *it);
		it++;
	}
	
	((ClusterStater*) stater)->computeClusterEfficiency();	
				#endif

			#endif
			
			#ifdef _LOOP_STAT_MODE
	((LoopStater*) stater)->initLoopCounters();

				#ifdef _LINKED_CLUSTER_STAT_MODE
	std::vector<LinkedCluster*>::iterator it4=tabOptimalClusters.begin();
	std::vector<LinkedCluster*>::iterator end4=tabOptimalClusters.end();

	while (it4!=end4)
	{
					#ifdef _TEST
		cout << "stat Internal Loops Linked Cluster  = " << ((LinkedCluster*) *it4)->getIndex() << end2l;
					#endif
		((ClusterStater*) stater)->statInternalLoops((Cluster*) *it4);
		it4++;
	}
	
				#else
	std::vector<Cluster*>::iterator it4=tabOptimalClusters.begin();
	std::vector<Cluster*>::iterator end4=tabOptimalClusters.end();

	while (it4!=end4)
	{
					
					#ifdef _TEST
		cout << "stat Internal Loops Linked Cluster  = " << ((Cluster*) *it4)->getIndex() << end2l;
					#endif
		((ClusterStater*) stater)->statInternalLoops((Cluster*) *it4);
					
		it4++;
	}
				#endif
	
	((LoopStater*) stater)->computeNbLoops();
			#endif
			
			#ifdef _SMALL_WORLD_STAT_MODE
				#ifdef _LINKED_CLUSTER_STAT_MODE
	((ClusterStater*) stater)->initClusterInternalDensityCounters();

	std::vector<LinkedCluster*>::iterator it5=tabOptimalClusters.begin();
	std::vector<LinkedCluster*>::iterator end5=tabOptimalClusters.end();

	while (it5!=end5)
	{
		((ClusterStater*) stater)->statClusterInternalDensity((Cluster*) *it5);
		it5++;
	}
					
					#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	((LoopStater*) stater)->initClusteringCoeffCounters();

	std::vector<LinkedCluster*>::iterator it6=tabOptimalClusters.begin();
	std::vector<LinkedCluster*>::iterator end6=tabOptimalClusters.end();

	while (it6!=end6)
	{
		
		if (((LinkedCluster*) *it6)->getIndex() < NB_ASSEMBLIES)
		{
					#ifdef _TEST
			cout << "Stating LinkedCluster " << ((LinkedCluster*) *it6)->getIndex()  << " ClusteringCoeffs " << endl;
					#endif
			
			((LoopStater*) stater)->statSmallWorld((LinkedCluster*) *it6);
		}
		it6++;
	}
					#endif
				#else
	((ClusterStater*) stater)->initClusterInternalDensityCounters();

	std::vector<Cluster*>::iterator it5=tabOptimalClusters.begin();
	std::vector<Cluster*>::iterator end5=tabOptimalClusters.end();

	while (it5!=end5)
	{
		((ClusterStater*) stater)->statClusterInternalDensity((Cluster*) *it5);
		it5++;
	}
				#endif
			#endif
			
			#ifdef _INTERNAL_MOTIF_STAT_MODE
			
	((ClusterStater*) stater)->initInternalMotifsCounters();
	
				#ifdef _LINKED_CLUSTER_STAT_MODE
	std::vector<LinkedCluster*>::iterator it7=tabOptimalClusters.begin();
	std::vector<LinkedCluster*>::iterator end7=tabOptimalClusters.end();

	while (it7!=end7)
	{
					#ifdef _TEST_STAT
		cerr << "Stating motifs of cluster " << ((LinkedCluster*) *it7)->getIndex() << endl;
					#endif
		((ClusterStater*) stater)->statInternalMotifs((LinkedCluster*) *it7);
		it7++;
	}
	
					#ifdef _MOTIF_STAT_MODE
	((LoopStater*) stater)->initMotifsCounters();

	std::vector<LinkedCluster*>::iterator it8=tabOptimalClusters.begin();
	std::vector<LinkedCluster*>::iterator end8=tabOptimalClusters.end();

	while (it8!=end8)
	{
						#ifdef _TEST_STAT
		cerr << "Stating motifs of linked cluster " << ((LinkedCluster*) *it8)->getIndex() << endl;
						#endif
					
		((LoopStater*) stater)->statMotifs((LinkedCluster*) *it8);
		it8++;
	}
					#endif
				#else
	std::vector<Cluster*>::iterator it7=tabOptimalClusters.begin();
	std::vector<Cluster*>::iterator end7=tabOptimalClusters.end();

	while (it7!=end7)
	{
		((ClusterStater*) stater)->statInternalMotifs((Cluster*) *it7);
		it7++;
	}
				#endif
			#endif
			
			#ifdef _DEGREE_STAT_MODE
				#ifdef _CLUSTER_CENTRALITY_STAT_MODE
	((LoopStater*) stater)->initDegreeCounters();

	std::vector<LinkedCluster*>::iterator it9=tabOptimalClusters.begin();
	std::vector<LinkedCluster*>::iterator end9=tabOptimalClusters.end();

	while (it9!=end9)
	{
					#ifdef _TEST
		cout << "Stating Degree Distribution for linked cluster " << ((LinkedCluster*) *it9)->getIndex()  << " degree " << ((LinkedCluster*) *it9)->getNbLinks() << endl;
					#endif
		((LoopStater*) stater)->statDegreeDistribution((LinkedCluster*) *it9);
		it9++;
	}
				#endif
			#endif	
			
			#ifdef _INPUT_OUTPUT_CLUSTER_STAT_MODE
	((ClusterStater*) stater)->initInputOutputCounters();

	for (int i = 0; i < NB_INPUT_ASSEMBLIES;i++)
	{
			
		((ClusterStater*) stater)->initNbProjections();
			
				#ifdef _LINKED_CLUSTER_STAT_MODE
		std::vector<LinkedCluster*>::iterator it9=tabOptimalClusters.begin();
		std::vector<LinkedCluster*>::iterator end9=tabOptimalClusters.end();
	
		while (it9!=end9)
		{
			
						#ifdef _TEST
			cout << "Stating Input Cluster Distribution for linked cluster " << ((LinkedCluster*) *it9)->getIndex()  << " for input assembly " << ((InputAssembly*) inputBuffers[i])->getIndex() << endl;
						#endif
			((ClusterStater*) stater)->statInputClusters(((Assembly*) ((InputAssembly*) inputBuffers[i])), (LinkedCluster*) *it9);
	
			it9++;
		}
				#else
		std::vector<Cluster*>::iterator it9=tabOptimalClusters.begin();
		std::vector<Cluster*>::iterator end9=tabOptimalClusters.end();
	
		while (it9!=end9)
		{
			
						#ifdef _TEST
			cout << "Stating Input Cluster Distribution for linked cluster " << ((Cluster*) *it9)->getIndex()  << " for input assembly " << ((InputAssembly*) inputBuffers[i])->getIndex() << endl;
						#endif
			((ClusterStater*) stater)->statInputClusters(((Assembly*) ((InputAssembly*) inputBuffers[i])), (Cluster*) *it9);
	
			it9++;
		}
				#endif
		((ClusterStater*) stater)->statNbInputProjections(i,((InputAssembly*) inputBuffers[i])->getNbOutputLinks());
	}
	
	for (int i = 0; i < NB_OUTPUT_ASSEMBLIES;i++)
	{
			
		((ClusterStater*) stater)->initNbProjections();
				#ifdef _LINKED_CLUSTER_STAT_MODE
		std::vector<LinkedCluster*>::iterator it9=tabOptimalClusters.begin();
		std::vector<LinkedCluster*>::iterator end9=tabOptimalClusters.end();
	
		while (it9!=end9)
		{
			
						#ifdef _TEST
			cout << "Stating Output Cluster Distribution for linked cluster " << ((LinkedCluster*) *it9)->getIndex()  << " for input assembly " << ((OutputAssembly*) outputBuffers[i])->getIndex() << endl;
						#endif
			((ClusterStater*) stater)->statOutputClusters(((Assembly*) ((OutputAssembly*) outputBuffers[i])), (LinkedCluster*) *it9);
	
			it9++;
		}
		
				#else
		std::vector<Cluster*>::iterator it9=tabOptimalClusters.begin();
		std::vector<Cluster*>::iterator end9=tabOptimalClusters.end();
	
		while (it9!=end9)
		{
			
						#ifdef _TEST
			cout << "Stating Output Cluster Distribution for linked cluster " << ((Cluster*) *it9)->getIndex()  << " for input assembly " << ((OutputAssembly*) outputBuffers[i])->getIndex() << endl;
						#endif
			((ClusterStater*) stater)->statOutputClusters(((Assembly*) ((OutputAssembly*) outputBuffers[i])), (Cluster*) *it9);
	
			it9++;
		}
				
				#endif
		((ClusterStater*) stater)->statNbOutputProjections(i,((OutputAssembly*) outputBuffers[i])->getNbInputLinks());
	}
			#endif
}

			#ifdef _LINKED_CLUSTER_STAT_MODE
void EDNetwork::cloneTabClusterLinks()
{
	// Parcours de tous les liens exitants pour l'instant
	std::vector<ClusterLink*>::iterator itClustLink=tabClusterLinks.begin();
	std::vector<ClusterLink*>::iterator endClustLink=tabClusterLinks.end();

	while (itClustLink!=endClustLink)
	{
		int preClusterIndex = ((Node*) ((Link*) *itClustLink)->getPreNode())->getIndex();
		int postClusterIndex = ((Node*) ((Link*) *itClustLink)->getPostNode())->getIndex();

		// Creation des liens pour tabOptimalClusters
		std::vector<LinkedCluster*>::iterator itClust=tabOptimalClusters.begin();
		std::vector<LinkedCluster*>::iterator endClust=tabOptimalClusters.end();

		while (itClust!=endClust)
		{
			if (((LinkedCluster*) *itClust)->sameIndex(preClusterIndex))
			{
				std::vector<LinkedCluster*>::iterator itClust2=tabOptimalClusters.begin();
				std::vector<LinkedCluster*>::iterator endClust2=tabOptimalClusters.end();

				while (itClust2!=endClust2)
				{
					if (((LinkedCluster*) *itClust2)->sameIndex(postClusterIndex))
					{
						ClusterLink* newClusterLink = new ClusterLink((LinkedCluster*) *itClust,(LinkedCluster*) *itClust2);
						((LinkedCluster*) *itClust)->addOutputLink(newClusterLink);
						((LinkedCluster*) *itClust2)->addInputLink(newClusterLink);

						//tabClusterLinks.push_back(newClusterLink);

					}
					itClust2++;
				}
			}
			itClust++;
		}


		itClustLink++;
	}


}
			#endif
		#endif

		#ifdef _CLUSTER_CENTRALITY_STAT_MODE
			#ifdef _CENTRALITY_STAT_MODE
void EDNetwork::statLinkedClusterPath()
{
	// Parcours du graph
	((LoopStater*) stater)->initPathCounters();	
	((LoopStater*) stater)->initBetweennessCounters();		
				#ifdef _TEST
	cerr << "Stat BreadthFirst PostLinks " << endl;
				#endif
			
	std::vector<LinkedCluster*>::iterator it4=tabClusters.begin();
	std::vector<LinkedCluster*>::iterator end4=tabClusters.end();

	while (it4!=end4)
	{
				#ifdef _EDGE_BETWEENNESS_STAT_MODE
		((LoopStater*) stater)->initBetweenness();
				#endif
		
		((LoopStater*) stater)->initBreadthFirstPostLinks((LinkedCluster*) *it4);
		((LoopStater*) stater)->statBreadthFirstPostLinks((LinkedCluster*) *it4);
		((LinkedClusterStater*) stater)->computeLinkedClusterEdgeBetweennessDistribution();
	
		((LoopStater*) stater)->computeBetweenness((LinkedCluster*) *it4);
		
		it4++;
	}
				#ifdef _TEST
	cerr << "After stat BreadthFirst PostLinks " << endl;
				#endif
		
	((LinkedClusterStater*) stater)->computeLinkedClusterMaxEdgeBetweenness();
	//((LinkedClusterStater*) stater)->computeLinkedClusterEdgeBetweennessDistribution();
		
	((LinkedClusterStater*) stater)->computeLinkedClusterBetweenness();
	((LinkedClusterStater*) stater)->computeLinkedClusterCentralBetweenness();
	
	((LinkedClusterStater*) stater)->computeLinkedClusterShortPaths();
	
	// Calcul d'efficacité entre les clusters	
				#ifdef _TEST
	cerr << "Compute LinkedCluster Efficiency " << endl;
				#endif
			
	std::vector<LinkedCluster*>::iterator it5=tabClusters.begin();
	std::vector<LinkedCluster*>::iterator end5=tabClusters.end();

	while (it5!=end5)
	{
		((LoopStater*) stater)->computeEfficiency((LinkedCluster*) *it5);
		it5++;
	}			
	
	((LinkedClusterStater*) stater)->computeLinkedClusterEfficiency();
			
				#ifdef _TEST
	cerr << "After compute LinkedCluster Efficiency " << endl;
				#endif
}
			#endif				
			
			#ifdef _SMALL_WORLD_STAT_MODE
void EDNetwork::statLinkedClusterClusteringCoeffs()
{
	((LoopStater*) stater)->initClusteringCoeffCounters();

	std::vector<LinkedCluster*>::iterator it=tabClusters.begin();
	std::vector<LinkedCluster*>::iterator end=tabClusters.end();

	while (it!=end)
	{
		
		if (((LinkedCluster*) *it)->getIndex() < NB_ASSEMBLIES)
		{
				#ifdef _TEST
			cout << "Stating LinkedCluster " << ((LinkedCluster*) *it)->getIndex()  << " ClusteringCoeffs " << endl;
				#endif
			
			((LoopStater*) stater)->statSmallWorld((LinkedCluster*) *it);
		}
		it++;
	}
}
			#endif
			
			#ifdef _DEGREE_STAT_MODE
void EDNetwork::statLinkedClusterDegree()
{
	((LoopStater*) stater)->initDegreeCounters();

	std::vector<LinkedCluster*>::iterator it7=tabClusters.begin();
	std::vector<LinkedCluster*>::iterator end7=tabClusters.end();

	while (it7!=end7)
	{
				#ifdef _TEST
		cout << "Stating Degree Distribution for linked cluster " << ((LinkedCluster*) *it7)->getIndex()  << " degree " << ((LinkedCluster*) *it7)->getNbLinks() << endl;
				#endif
		((LoopStater*) stater)->statDegreeDistribution((LinkedCluster*) *it7);
		it7++;
	}
}
			#endif
				
			#ifdef _MOTIF_STAT_MODE
void EDNetwork::statLinkedClusterMotifs()
{
	((LoopStater*) stater)->initMotifsCounters();

	std::vector<LinkedCluster*>::iterator it8=tabClusters.begin();
	std::vector<LinkedCluster*>::iterator end8=tabClusters.end();

	while (it8!=end8)
	{
				#ifdef _TEST_STAT
		cerr << "Stating motifs of linked cluster " << ((LinkedCluster*) *it8)->getIndex() << endl;
				#endif
					
		((LoopStater*) stater)->statMotifs((LinkedCluster*) *it8);
		it8++;
	}
}
			#endif
		#endif
			
	#endif
#endif

#ifdef _NETWORK_GRAPH_MODE
void EDNetwork::initNetworkGrapher()
{
	//grapher= new NetworkGrapher();

	std::vector<Assembly*>::iterator it= assemblies.begin();
	std::vector<Assembly*>::iterator end= assemblies.end();

	while(it!=end)
	{
		((EDAssembly*) *it)->initAssemblyGrapher();
		//((EDAssembly*) *it)->initAssemblyGrapher((AssemblyGrapher*) grapher);
		it++;
	}
}

void EDNetwork::freeNetworkGrapher()
{
	std::vector<Assembly*>::iterator it= assemblies.begin();
	std::vector<Assembly*>::iterator end= assemblies.end();

	while(it!=end)
	{
		((EDAssembly*) *it)->freeAssemblyGrapher();
		it++;
	}
}
#endif

#ifdef _NETWORK_TRACE_MODE
void EDNetwork::initNetworkTracer()
{
	#ifdef _GLOBAL_TRACE_MODE
	tracer= new NetworkTracer();

	std::vector<Assembly*>::iterator it=assemblies.begin();
	std::vector<Assembly*>::iterator end=assemblies.end();

	while (it!=end)
	{
		//((EDAssembly*) *it)->initAssemblyTracer();
		((EDAssembly*) *it)->initAssemblyTracer((AssemblyTracer*) tracer);
		it++;
	}

	for (int i=0;i<nbOutputBuffers;i++)
	{
		#ifdef _TEST
		cout << "Initing output assembly tracer" << endl;
		#endif
		((EDAssembly*) ((OutputAssembly*) outputBuffers[i]))->initAssemblyTracer((AssemblyTracer*) tracer);
	}

	#else
	std::vector<Assembly*>::iterator it=assemblies.begin();
	std::vector<Assembly*>::iterator end=assemblies.end();

	while (it!=end)
	{
		((EDAssembly*) *it)->initAssemblyTracer();
		it++;
	}

	for (int i=0;i<nbInputBuffers;i++)
	{
	#ifdef _TEST
		cout << "Initing input assembly tracer" << endl;
	#endif
		((EDAssembly*) ((InputAssembly*) inputBuffers[i]))->initAssemblyTracer();
	}

	for (int i=0;i<nbOutputBuffers;i++)
	{
		#ifdef _TEST
		cout << "Initing output assembly tracer" << endl;
		#endif
		((EDAssembly*) ((OutputAssembly*) outputBuffers[i]))->initAssemblyTracer();
	}
	#endif
}

void EDNetwork::freeNetworkTracer()
{
	std::vector<Assembly*>::iterator it=assemblies.begin();
	std::vector<Assembly*>::iterator end=assemblies.end();

	while (it!=end)
	{
		((EDAssembly*) *it)->freeAssemblyTracer();
		it++;
	}
/*
	for (int i=0;i<a->nbInputBuffers;i++)
	{
	#ifdef _TEST
		cout << "Initing input assembly tracer" << endl;
	#endif
		initTracer(((EDAssembly*) ((InputAssembly*) a->inputBuffers[i]));
	}
*/

	for (int i=0;i<nbOutputBuffers;i++)
	{
	#ifdef _TEST
		cout << "Initing output assembly tracer" << endl;
	#endif
		((EDAssembly*) ((OutputAssembly*) outputBuffers[i]))->freeAssemblyTracer();
		//((AssemblyTracer*) n->tracer)->freeAssemblyTracer();
	}

	#ifdef _GLOBAL_TRACE_MODE
	delete((NetworkTracer*) tracer);
	#endif
}
#endif

#ifdef _BLOCKING_MODE
void EDNetwork::runOneStep()
{
	if (!EDSynapse::theEventManager.getEmpty())
	{
		receiveInputs();
	
		int time = EDSynapse::theEventManager.getTime();
	
		timeRef += INTER_WAVE_PERIOD;
	
		#ifdef _TEST
		cout << "Entering one step loop, time = " << time << ", timeRef = " << timeRef << endl;
		#endif
	
		while (time<=timeRef)
		{
	
		#ifdef _GRAPHICAL_DISPLAY_MODE
			#ifdef _TEST
			cerr << "*** EDNetwork *** display " << endl;
			#endif
			display();
		#endif
	
		#ifdef _TEST
			cerr << "*** EDNetwork *** time " << time << " time ref " << timeRef << endl;
		#endif
	
		#ifdef _PSP_LFP_STAT_MODE
			initPSPotential();
		#endif
		
			integrateInputs(time);
			integrateOutputs(time);
	
	
		#ifdef _TEST
			cerr << "*** EDNetwork *** time before eventManager " << time << endl;
		#endif
			time=EDSynapse::theEventManager.runOneStep();
	
		#ifdef _TEST
			cerr << "*** EDNetwork *** time after eventManager " << time << endl;
		#endif
		
		#ifdef _ASSEMBLY_STAT_MODE
			if (EDSynapse::theEventManager.getEmpty())
			{
				cerr << "Network Stats are void" << endl;
				traceVoidFiles();
			}
			else
			{
				traceNetworkFiles();
			}
		#endif
		
		#ifdef _GRAPHICAL_DISPLAY_MODE
			#ifdef _TEST
			cerr << "*** EDNetwork *** flushDisplay " << endl;
			#endif
			((TopologyDisplayer*) displayer)->flushDisplay();
			
			#ifdef _SAVE_TOPOLOGY_DISPLAY_MODE
			((TopologyDisplayer*) displayer)->saveTopologyDisplayer(time);
			#endif
		#endif
		}
		
		//sleep(1000);
		
		sendOutputs();
	}
	else
	{
		//#ifdef _TEST
		cout << "*** EDNetwork *** is void, no inputs are injected " << endl;
		//#endif
		receiveVoidInputs();
	}
}
#endif

#ifndef _BLOCKING_MODE
void EDNetwork::runOneStep()
{
	#ifdef _GRAPHICAL_DISPLAY_MODE
	display();
	#endif
	
	int time=EDSynapse::theEventManager.runOneStep();

	if (timeRef<time)
	{
		timeRef += INTER_WAVE_PERIOD;
	}
 	
	receiveInputs();
	
	integrateInputs(time);
	
	#ifdef _TEST
	cout << "*** EDNetwork *** time " << time << endl;
	#endif
	integrateOutputs(time);

	#ifdef _ASSEMBLY_STAT_MODE
	traceNetworkFiles();
	#endif
	
	sendOutputs();
	
	#ifdef _GRAPHICAL_DISPLAY_MODE
	((TopologyDisplayer*) displayer)->flushDisplay();
	#endif
}
#endif

#ifdef _GRAPHICAL_DISPLAY_MODE
void EDNetwork::display()
{
	std::vector<Assembly*>::iterator it=assemblies.begin();
	std::vector<Assembly*>::iterator end=assemblies.end();

	while (it!=end)
	{
		((AssemblyDisplayer*) displayer)->display((Assembly*) *it);
		it++;
	}
	
	for (int i=0;i<nbInputBuffers;i++)
	{
		((AssemblyDisplayer*) displayer)->display((Assembly*) ((InputAssembly*) inputBuffers[i]));
	}

	for (int i=0;i<nbOutputBuffers;i++)
	{
		((AssemblyDisplayer*) displayer)->display((Assembly*) ((OutputAssembly*) outputBuffers[i]));
	}
}
#endif




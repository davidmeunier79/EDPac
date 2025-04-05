// EvoNetwork.cc

// Local Includes
#include "EvoNetwork.h"

/****************************************************************************************************************************************/
/*************************************************** Methodes de la classe EvoNetwork ***************************************************/
/****************************************************************************************************************************************/

EvoNetwork::EvoNetwork(): EDNetwork(NB_INPUT_ASSEMBLIES,NB_OUTPUT_ASSEMBLIES)
{
	initEvoIndex();
	initTopoIndex();

#ifdef _PARAMETRIC_TEST_MODE
	paramIndex=0;
#endif
}

EvoNetwork::~EvoNetwork()
{
}

void EvoNetwork::statEvo()
{
#ifdef _NETWORK_STAT_MODE
	initEvoNetworkFiles();
#endif

	while (!synchroBuffer->isActive())
	{
#ifdef _MPI_TEST
		cout << "*** EvoNetwork *** Probing receive request for synchroBuffer..." << endl;
#endif
	}

#ifdef _MPI_TEST
	cout << "*** EvoNetwork *** Launching receive request for synchroBuffer..." << endl;
#endif
	synchroBuffer->receive();

#ifdef _MPI_TEST
	cout << "*** EvoNetwork *** waiting for synchroBuffer..." << endl;
#endif
	synchroBuffer->wait();

	while(!testBreak())
	{
#ifdef _MPI_TEST
		cout << "*** Synchro Module " << MPI_GLOBALS.getMyId() << " *** synchronizing with COMM_WORLD root module " << endl;
#endif
		MPI_GLOBALS.synchronize();

		while (!isReady());
		{
#ifdef _MPI_TEST
			cout << "*** EvoNetwork *** in testActive loop" << endl;
#endif
		}
	}

#ifdef _NETWORK_STAT_MODE
	cout << "*** EvoNetwork *** endEvoNetworkFiles" << endl;
	endEvoNetworkFiles();
#endif

	cout << "*** Synchro Module " << MPI_GLOBALS.getMyId() << " *** after break synchronizing with COMM_WORLD root module " << endl;
	MPI_GLOBALS.synchronize();

	cout << "*** Synchro Module " << MPI_GLOBALS.getMyId() << " *** after break synchronizing with COMM_WORLD root module " << endl;
	MPI_GLOBALS.synchronize();
}

void EvoNetwork::integrateSynchro()
{
#ifdef _TOPOLOGY_PROJECTION_MODE
	if (Projection::nbProjections)
#else
	if (EDSynapse::nbSynapses)
#endif
	{
#ifdef _TEST
		cout << "*** EvoNetwork *** destroying topology with " << EDSynapse::nbSynapses << " synapses" << endl;
#endif

#ifdef _TOPOLOGY_PROJECTION_MODE
		destroyProjections();
#else
		destroyTopology();
		
	#ifdef _TEST
		cout << "*** EvoNetwork *** reseting theEventManager" << endl;
	#endif
		EDSynapse::theEventManager.reset();

		timeRef=0;
#endif
	
#ifdef _INCREMENTAL_TOPOLOGY_MODE
		//#ifdef _TEST
		cout << "*** EvoNetwork *** destroying internal assemblies" << endl;
		//#endif
		deleteAssemblies();
#endif
	
#ifdef _GRAPHICAL_DISPLAY_MODE
		((TopologyDisplayer*) displayer)->cleanDisplay();
#endif


#ifdef _NETWORK_STAT_MODE
		if (stater)
		{
			((AssemblyStater*) stater)->initCounters();
			//((LoopStater*) stater)->initCounters();
		}
#endif

#ifndef _PARAMETRIC_TEST_MODE
		incrementTopoIndex();
#endif

#ifdef _SINGLE_INDIVIDUAL_MODE
		if (getTopoIndex()==1)
		{
	#ifdef _GA_TEST
			cout << "Switching generation after " << getTopoIndex() << " individuals " << endl;
	#endif

	#ifdef _NETWORK_STAT_MODE
			if (stater)
			{
		#ifdef _TEST
				cout << "Trace NetworkStater" << getTopoIndex() << " individuals " << endl;
		#endif
				((NetworkStater*) stater)->trace();
		#ifdef _TEST
				cout << "initAccumulaters NetworkStater" << getTopoIndex() << " individuals " << endl;
		#endif
				((NetworkStater*) stater)->initAccumulaters();
			}
	#endif
			incrementEvoIndex();

	#ifndef _PARAMETRIC_TEST_MODE
			initTopoIndex();
	#endif
		}
#else
	#ifdef _FIRST_BEST_INDIVIDUALS_MODE
		if (getTopoIndex()==NB_FIRST_BEST_INDIVIDUALS)
		{
		#ifdef _GA_TEST
			cout << "Switching generation after " << getTopoIndex() << " individuals " << endl;
		#endif

		#ifdef _NETWORK_STAT_MODE
			if (stater)
			{
			#ifdef _TEST
				cout << "Trace NetworkStater" << getTopoIndex() << " individuals " << endl;
			#endif
				((NetworkStater*) stater)->trace();
			#ifdef _TEST
				cout << "initAccumulaters NetworkStater" << getTopoIndex() << " individuals " << endl;
			#endif
				((NetworkStater*) stater)->initAccumulaters();
			}
		#endif
			incrementEvoIndex();

		#ifndef _PARAMETRIC_TEST_MODE
			initTopoIndex();
		#endif
		}
	#else
		if (getTopoIndex()==NB_INDIVIDUS)
		{
		#ifdef _GA_TEST
			cout << "Switching generation after " << getTopoIndex() << " individuals " << endl;
		#endif

		#ifdef _NETWORK_STAT_MODE
			if (stater)
			{
			#ifdef _TEST
				cout << "Trace NetworkStater" << getTopoIndex() << " individuals " << endl;
			#endif
				((NetworkStater*) stater)->trace();
			#ifdef _TEST
				cout << "initAccumulaters NetworkStater" << getTopoIndex() << " individuals " << endl;
			#endif
				((NetworkStater*) stater)->initAccumulaters();
			}
		#endif
			incrementEvoIndex();

		#ifndef _PARAMETRIC_TEST_MODE
			initTopoIndex();
		#endif
		}
	#endif
#endif
		cout << "*** EvoNetwork *** Index Topology: " << getTopoIndex() << ", index generation: " << getEvoIndex() << endl;
	}
	
#ifdef _TOPOLOGY_PROJECTION_MODE
	if (!Projection::nbProjections)
#else
	if (!EDSynapse::nbSynapses)
#endif
	{

#ifdef _TEST
		cout << "*** EvoNetwork *** building topology" << endl;
#endif

#ifdef _TOPOLOGY_PROJECTION_MODE
		buildProjections();
#else
		buildTopology();
#endif
		

#ifdef _INCREMENTAL_TOPOLOGY_MODE
	#ifdef _GRAPHICAL_DISPLAY_MODE
		initTopologyDisplayer((TopologyDisplayer*) displayer);
	#endif
#endif
	
#ifdef _NETWORK_STAT_MODE
		if (stater)
		{
	#ifdef _TEST
			cerr << "*** EvoNetwork *** stating network" << endl;
	#endif
			statNetwork();
	#ifdef _TEST
			cout << "*** EvoNetwork *** stating topology stats" << endl;
	#endif
			((NetworkStater*) stater)->stat();

		}
#endif

#ifdef _GRAPHICAL_DISPLAY_MODE
	#ifdef _TEST
		cout << "*** EvoNetwork *** flushing display" << endl;
	#endif
		((TopologyDisplayer*) displayer)->flushDisplay();

	#ifdef _TEST
		cout << "*** EvoNetwork *** after flushing display" << endl;
	#endif
#endif

#ifndef _PARAMETRIC_TEST_MODE
		initEvalIndex();
#endif
	}
	else
	{
		cerr << "Warning, topology is not properly destroyed, unable to build" << endl;
	}
}

void EvoNetwork::integrateVoidSynchro()
{
	if(EDSynapse::nbSynapses)
	{
#ifdef _GRAPHICAL_DISPLAY_MODE
		((TopologyDisplayer*) displayer)->flushDisplay();
#endif
	}
	else
	{
		cerr << "Warning, impossible to re-init topology, topology not build" << endl;
	}
}

void EvoNetwork::integrateSkipSynchro()
{
	if(EDSynapse::nbSynapses)
	{
		cout << "*** EvoNetwork *** reiniting topology" << endl;
		reInitTopology();

//#ifdef _GA_TEST
		cout << "*** EvoNetwork *** reseting theEventManager" << endl;
//#endif
		EDSynapse::theEventManager.reset();

		timeRef=0;
		
#ifndef _PARAMETRIC_TEST_MODE
		incrementEvalIndex();
		cout << "Eval index: " << getEvalIndex() << endl;
#endif

#ifdef _GRAPHICAL_DISPLAY_MODE
		((TopologyDisplayer*) displayer)->flushDisplay();
#endif
	}
	else
	{
		cerr << "Warning, impossible to re-init topology, topology not build" << endl;
	}


}

#ifdef _RUN_MODE
void EvoNetwork::run()
{
	#ifdef _NETWORK_STAT_MODE
	initEvoNetworkFiles();
	#endif

	while (!synchroBuffer->isActive())
	{
	#ifdef _MPI_TEST
		cout << "*** EvoNetwork *** Probing receive request for synchroBuffer..." << endl;
	#endif
	}

	#ifdef _MPI_TEST
	cout << "*** EvoNetwork *** Launching receive request for synchroBuffer..." << endl;
	#endif
	synchroBuffer->receive();

	#ifdef _MPI_TEST
	cout << "*** EvoNetwork *** waiting for synchroBuffer..." << endl;
	#endif
	synchroBuffer->wait();

	while(!testBreak())
	{

	//#ifdef _MPI_TEST
		cout << "*** EvoNetwork *** initing MPI module" << endl;
	//#endif
		initMPIModule();

		integrateBirthFlash();

		if (!testBreak())
		{
			runNetwork();
		}
	//#ifdef _MPI_TEST
		cout << "*** EvoNetwork *** freeing MPI module" << endl;
	//#endif
		freeMPIModule();
	}

#ifdef _NETWORK_STAT_MODE
	endEvoNetworkFiles();
#endif

	//cout << "*** Synchro Module " << MPI_GLOBALS.getMyId() << " *** after break synchronizing with COMM_WORLD root module " << endl;
	//MPI_GLOBALS.synchronize();
}

void EvoNetwork::runNetwork()
{
	cout << "*** EvoNetwork *** opening network test files" << endl;
	initNetworkFiles();

//#ifdef _MPI_TEST
	cout << "*** EvoNetwork *** entering main loop for individual " << getTopoIndex() << ", eval " << getEvalIndex() << " " << endl;
//#endif
	while(!testSynchro())
	{
#ifdef _MPI_TEST
		cout << "*** EvoNetwork *** run one step " << endl;
#endif
		runOneStep();
	}

//#ifdef _MPI_TEST
	cout << "*** EvoNetwork *** out of main loop" << endl;
//#endif
//#ifdef _MPI_TEST
	cout << "*** EvoNetwork *** end network files" << endl;
//#endif
	endNetworkFiles();
}
#endif

void EvoNetwork::integrateBirthFlash()
{
	
	initEvalIndex();
/*
	cout << "*** EvoNetwork *** opening network test files" << endl;
	initNetworkFiles();
*/

#ifdef _MPI_TEST
	cout << "*** EvoNetwork *** entering birth flash loop for individual " << getTopoIndex() << ", eval " << getEvalIndex() << " " << endl;
#endif
	while(!testSynchro())
	{
#ifdef _MPI_TEST
		cout << "*** EvoNetwork *** integrateBirthFlash " << endl;
#endif
		runOneStep();
	}

//#ifdef _MPI_TEST
	cout << "*** EvoNetwork *** out of birth flash loop" << endl;
//#endif

/*
	cout << "*** EvoNetwork *** end network files" << endl;
	endNetworkFiles();
*/
}

#ifdef _NETWORK_STAT_MODE
void EvoNetwork::initEvoNetworkFiles()
{
	stater = new NetworkStater();
	cout << "************************* Initing NetworkStater" << endl;
	/*
	#ifdef _ASSEMBLY_STAT_MODE
	tester = new ActivityTester();
	#else
	
	stater = new NetworkStater();
	cout << "************************* Initing NetworkStater" << endl;
	#endif
	*/
}

void EvoNetwork::endEvoNetworkFiles()
{
	if (stater)
	{
		cout << "Trace NetworkStater " << getTopoIndex() << " individuals " << endl;
		((NetworkStater*) stater)->trace();
	}

	delete((NetworkStater*) stater);
	
	/*
	#ifdef _ASSEMBLY_STAT_MODE
	delete((ActivityTester*) tester);
	#else
	
	if (stater)
	{
		cout << "Trace NetworkStater " << getTopoIndex() << " individuals " << endl;
		((NetworkStater*) stater)->trace();
	}

	delete((NetworkStater*) stater);
	
	#endif
	*/
}
#endif

#ifdef _TEST_MODE
void EvoNetwork::testNetwork()
{

#ifdef _TRANSITION_STAT_MODE
	
//#ifdef _MPI_TEST
	cout << "*** EvoNetwork *** entering test loop " << getTestIndex() << " (Eval: " << getEvalIndex() << " - transition)"<< " for individual " << getTopoIndex() << " " << endl;
//#endif

	#ifdef _GLOBAL_STAT_MODE
		#ifndef _MULTI_TEST_MODE
			#ifdef _PHASE_TEST_MODE
	stater = new ActivityStater();
				
				#ifdef _LINK_INPUT_STAT_MODE
	inputLinkStater = new InputStater();
				#endif
			#endif
		#endif
	#endif
	
	//#ifdef _TRACE_MODE
	cout << "*** EvoNetwork *** opening network test "<< getTestIndex() << " files" << endl;
	initNetworkFiles();
	//#endif

	while(!testSynchro())
	{
		runOneStep();
	}

	//#ifdef _TRACE_MODE
	cout << "*** EvoNetwork *** end network files for test " << getTestIndex() << endl;
	endNetworkFiles();
	
	#ifdef _GLOBAL_STAT_MODE
		#ifdef _MULTI_TEST_MODE
			#ifdef _PARAMETRIC_TEST_MODE
	if (stater)
	{
		((ActivityTester*) stater)->stat(paramIndex);
	}
				#ifdef _LINK_INPUT_STAT_MODE
	if (inputLinkStater)
	{
		((InputTester*) inputLinkStater)->stat(paramIndex);
	}
				#endif
			#else
				#ifdef _PHASE_TEST_MODE
	if (stater)
	{
		((ActivityTester*) stater)->stat();
	}
					#ifdef _LINK_INPUT_STAT_MODE
	if (inputLinkStater)
	{
		((InputTester*) inputLinkStater)->stat();
	}
					#endif
				#else
	if (stater)
	{
		((ActivityStater*) stater)->trace();
	}
					#ifdef _LINK_INPUT_STAT_MODE
	if (inputLinkStater)
	{
		((InputStater*) inputLinkStater)->stat();
	}
					#endif
				#endif
			#endif
		#else
			#ifdef _PHASE_TEST_MODE
	if (stater)
	{
		((ActivityStater*) stater)->trace();
	}

	delete((ActivityStater*) stater);
	
				#ifdef _LINK_INPUT_STAT_MODE
	if (inputLinkStater)
	{
		((InputStater*) inputLinkStater)->stat();
	}
	
	delete((InputStater*) stater);
				#endif
			#endif
		#endif
	#endif
	
	incrementEvalIndex();
	
	if (testBreak())
	{
		return;
	}
#endif

//#ifdef _MPI_TEST
	cout << "*** EvoNetwork *** entering test loop " << getTestIndex() << " (Eval: " << getEvalIndex() << ")"<< " for individual " << getTopoIndex() << " " << endl;
//#endif

#ifdef _GLOBAL_STAT_MODE
	#ifndef _MULTI_TEST_MODE
		#ifdef _PHASE_TEST_MODE
	stater = new ActivityStater();
				
			#ifdef _LINK_INPUT_STAT_MODE
	inputLinkStater = new InputStater();
			#endif
		#endif
	#endif
#endif

	//#ifdef _TRACE_MODE
	cout << "*** EvoNetwork *** opening network test "<< getTestIndex() << " files" << endl;
	initNetworkFiles();
	//#endif

	while(!testSynchro())
	{
		runOneStep();
	}

	//#ifdef _TRACE_MODE
	cout << "*** EvoNetwork *** end network files for test " << getTestIndex() << endl;
	endNetworkFiles();
	//#endif
	
#ifdef _GLOBAL_STAT_MODE
	#ifdef _MULTI_TEST_MODE
		#ifdef _PARAMETRIC_TEST_MODE
		if (stater)
		{
			((ActivityTester*) stater)->stat(paramIndex);
		}
			#ifdef _LINK_INPUT_STAT_MODE
		if (inputLinkStater)
		{
			((InputTester*) inputLinkStater)->stat(paramIndex);
		}
			#endif
		#else
			#ifdef _PHASE_TEST_MODE
		if (stater)
		{
			((ActivityTester*) stater)->stat();
		}
				#ifdef _LINK_INPUT_STAT_MODE
		if (inputLinkStater)
		{
			((InputTester*) inputLinkStater)->stat();
		}
				#endif
			#else
		if (stater)
		{
			((ActivityStater*) stater)->trace();
		}
				#ifdef _LINK_INPUT_STAT_MODE
		if (inputLinkStater)
		{
			((InputStater*) inputLinkStater)->stat();
		}
				#endif
			#endif
		#endif
	#else
		#ifdef _PHASE_TEST_MODE
		if (stater)
		{
			((ActivityStater*) stater)->stat();
		}
	
		delete((ActivityStater*) stater);
		
			#ifdef _LINK_INPUT_STAT_MODE
		if (inputLinkStater)
		{
			((InputStater*) inputLinkStater)->stat();
		}
		
		delete((InputStater*) stater);
			#endif
		#endif
	#endif
#endif
	
//#ifdef _MPI_TEST
	cout << "*** EvoNetwork *** out of test loop" << endl;
//#endif
	incrementEvalIndex();
}

void EvoNetwork::test()
{
	#ifdef _NETWORK_STAT_MODE
	initEvoNetworkFiles();
	#endif

	while (!synchroBuffer->isActive())
	{
	#ifdef _MPI_TEST
		cout << "*** EvoNetwork *** Probing receive request for synchroBuffer..." << endl;
	#endif
	}

	#ifdef _MPI_TEST
	cout << "*** EvoNetwork *** Launching receive request for synchroBuffer..." << endl;
	#endif
	synchroBuffer->receive();

	#ifdef _MPI_TEST
	cout << "*** EvoNetwork *** waiting for synchroBuffer..." << endl;
	#endif
	synchroBuffer->wait();

	while(!testBreak())
	{
		initEvalIndex();

	//#ifdef _MPI_TEST
		cout << "*** EvoNetwork *** initing MPI module" << endl;
	//#endif
		initMPIModule();

	//#ifdef _MPI_TEST
		cout << "*** EvoNetwork *** integrating birth flash" << endl;
	//#endif

		integrateBirthFlash();

		#ifdef _RUN_MODE
			#ifdef _TEST_MODE


		cout << "*** EvoNetwork *** in first test Phase " << endl;

				#ifdef _NO_STDP_TEST_MODE
		SynapseMathTools::INHIB_ALPHA = 0.0;
		cout << "INHIB_ALPHA: " << SynapseMathTools::INHIB_ALPHA << endl;

		SynapseMathTools::EXCIT_ALPHA = 0.0;
		cout << "EXCIT_ALPHA: " << SynapseMathTools::EXCIT_ALPHA << endl;
				#endif

				#ifdef _PHASE_TEST_MODE
		initTestIndex();

		while (getTestIndex()<NB_TESTED_ANIMALS && testSynchro())
		{
			if (!testBreak())
			{
				runNetwork();
			}
			else
			{
				break;
			}

			incrementTestIndex();
		}

		incrementEvalIndex();
				#else
		if (!testBreak())
		{
			runNetwork();

			incrementEvalIndex();
		}


				#endif

		cout << "*** EvoNetwork *** out of first test Phase " << endl;

			#endif


		cout << "*** EvoNetwork *** in run Phase " << endl;

			#ifdef _NO_STDP_TEST_MODE
		SynapseMathTools::INHIB_ALPHA = 0.1;
		cout << "INHIB_ALPHA: " << SynapseMathTools::INHIB_ALPHA << endl;

		SynapseMathTools::EXCIT_ALPHA = 0.5;
		cout << "EXCIT_ALPHA: " << SynapseMathTools::EXCIT_ALPHA << endl;
			#endif

		if (!testBreak())
		{
			runNetwork();
			incrementEvalIndex();
		}


		cout << "*** EvoNetwork *** out of run Phase " << endl;

			#ifdef _TEST_MODE


		cout << "*** EvoNetwork *** in second test Phase " << endl;


				#ifdef _NO_STDP_TEST_MODE
		SynapseMathTools::INHIB_ALPHA = 0.0;
		cout << "INHIB_ALPHA: " << SynapseMathTools::INHIB_ALPHA << endl;

		SynapseMathTools::EXCIT_ALPHA = 0.0;
		cout << "EXCIT_ALPHA: " << SynapseMathTools::EXCIT_ALPHA << endl;
				#endif

				#ifdef _PHASE_TEST_MODE				
		initTestIndex();

		while (getTestIndex()<NB_TESTED_ANIMALS )
		{
			if (!testBreak())
			{
				runNetwork();
			}
			else
			{
				break;
			}

			incrementTestIndex();
		}

		incrementEvalIndex();

		if (!testBreak())
		{
			initTestIndex();
			runNetwork();
		}
				#else
		if (!testBreak())
		{
			initTestIndex();
			runNetwork();

			incrementEvalIndex();
		}


		cout << "*** EvoNetwork *** out of second test Phase " << endl;

				#endif
			#endif
		#else

			#ifdef _TEST_MODE
				#ifdef _PHASE_TEST_MODE
		initTestIndex();

		while (getTestIndex()<NB_TESTED_ANIMALS )
		{
			if (!testBreak())
			{
				testNetwork();
			}
			else
			{
				break;
			}

			incrementTestIndex();
		}

		incrementEvalIndex();
				#else

		if (!testBreak())
		{
			initTestIndex();
			testNetwork();

			incrementEvalIndex();
		}
				#endif
			#else

			#endif
		#endif
	//#ifdef _MPI_TEST
		cout << "*** EvoNetwork *** freeing MPI module" << endl;
	//#endif
		freeMPIModule();

	}
	#ifdef _NETWORK_STAT_MODE
	endEvoNetworkFiles();
	#endif
	
	cout << "*** Synchro Module " << MPI_GLOBALS.getMyId() << " *** after break synchronizing with COMM_WORLD root module " << endl;
	MPI_GLOBALS.synchronize();

	cout << "*** Synchro Module " << MPI_GLOBALS.getMyId() << " *** after break synchronizing with COMM_WORLD root module " << endl;
	MPI_GLOBALS.synchronize();
}
#endif

//#ifdef _TEST_BEST_POPULATION_MODE
void EvoNetwork::testBest()
{
	#ifdef _NETWORK_STAT_MODE
	initEvoNetworkFiles();
	#endif

	#ifdef _GLOBAL_STAT_MODE
		#ifdef _MULTI_TEST_MODE
			#ifdef _PARAMETRIC_TEST_MODE
		stater = new ActivityTester();
				
				#ifdef _LINK_INPUT_STAT_MODE
		inputLinkStater = new InputTester();
				#endif
			#else
				#ifdef _PHASE_TEST_MODE
		stater = new ActivityTester();
		
					#ifdef _LINK_INPUT_STAT_MODE
		inputLinkStater = new InputTester();
					#endif
				#else
		stater = new ActivityStater();
		
					#ifdef _LINK_INPUT_STAT_MODE
		inputLinkStater = new InputStater();
					#endif
				#endif
			#endif
		#else
			#ifdef _PHASE_TEST_MODE
		stater = new ActivityStater();
		
				#ifdef _LINK_INPUT_STAT_MODE
		inputLinkStater = new InputStater();
				#endif
			#endif
		#endif
	#endif
	
	while (!synchroBuffer->isActive())
	{
	#ifdef _MPI_TEST
		cout << "*** EvoNetwork *** Probing receive request for synchroBuffer..." << endl;
	#endif
	}

	#ifdef _MPI_TEST
	cout << "*** EvoNetwork *** Launching receive request for synchroBuffer..." << endl;
	#endif
	synchroBuffer->receive();

	#ifdef _MPI_TEST
	cout << "*** EvoNetwork *** waiting for synchroBuffer..." << endl;
	#endif
	synchroBuffer->wait();

	//if(!testBreak())
	while(!testBreak())
	{
	//#ifdef _MPI_TEST
		cout << "*** EvoNetwork *** initing MPI module" << endl;
	//#endif
		initMPIModule();

		#ifdef _PARAMETRIC_TEST_MODE
		while (paramIndex<NB_PARAMETRIC_TESTS)
		{
			#ifdef _CONDITIONAL_TEST_MODE
			if (paramIndex == NB_PARAMETRIC_TESTS -1)
			{	
				#ifdef _INHIBITION_TEST_MODE
				SynapseMathTools::INHIB_WEIGHT = 0;
				SynapseMathTools::INHIB_ALPHA = 0;
				cout << "INHIB_WEIGHT: " << SynapseMathTools::INHIB_WEIGHT << endl;
				cout << "INHIB_ALPHA: " << SynapseMathTools::INHIB_ALPHA << endl;	
				#endif
				
				#ifdef _INHIB_STDP_TEST_MODE
				SynapseMathTools::INHIB_ALPHA = 0;
				cout << "INHIB_ALPHA: " << SynapseMathTools::INHIB_ALPHA << endl;
				#endif

				#ifdef _EXCIT_STDP_TEST_MODE
				SynapseMathTools::EXCIT_ALPHA = 0;
				cout << "EXCIT_ALPHA: " << SynapseMathTools::EXCIT_ALPHA << endl;
				#endif
			}
			#else
				#ifdef _EXCIT_ALPHA_TEST_MODE
			SynapseMathTools::EXCIT_ALPHA = EXCIT_ALPHA_STEP * paramIndex;
			cout << "EXCIT_ALPHA: " << SynapseMathTools::EXCIT_ALPHA << endl;
				#endif
				
				#ifdef _INHIB_ALPHA_TEST_MODE
			SynapseMathTools::INHIB_ALPHA = INHIB_ALPHA_STEP*paramIndex;
			cout << "INHIB_ALPHA: " << SynapseMathTools::INHIB_ALPHA << endl;
				#endif
			
				#ifdef _INHIB_DEPRESSION_TEST_MODE
			SynapseMathTools::INHIB_DEPRESSION_STRENGTH = INHIB_DEPRESSION_STRENGTH_STEP*paramIndex;
			cout << "INHIB_DEPRESSION_STRENGTH: " << SynapseMathTools::INHIB_DEPRESSION_STRENGTH << endl;
				#endif
				
				#ifdef _INHIB_STDP_TIME_TEST_MODE
			SynapseMathTools::INHIB_STDP_TIME_LENGTH = INHIB_STDP_TIME_STEP*paramIndex;
			cout << "INHIB_STDP_TIME_LENGTH: " << SynapseMathTools::INHIB_STDP_TIME_LENGTH << endl;
				#endif
				
				#ifdef _EXCIT_DEPRESSION_TEST_MODE
			SynapseMathTools::EXCIT_DEPRESSION_STRENGTH = EXCIT_DEPRESSION_STRENGTH_STEP*paramIndex;
			cout << "EXCIT_DEPRESSION_STRENGTH: " << SynapseMathTools::EXCIT_DEPRESSION_STRENGTH << endl;
				#endif
				
				#ifdef _REL_REF_TEST_MODE
			NeuronMathTools::RELATIVE_REFRACTORY_PERIOD = RELATIVE_REFRACTORY_STEP*paramIndex;
			cout << "RELATIVE_REFRACTORY_PERIOD: " << NeuronMathTools::RELATIVE_REFRACTORY_PERIOD << endl;
				#endif
			
				#ifdef _ABS_REF_TEST_MODE
			NeuronMathTools::ABSOLUT_REFRACTORY_PERIOD = ABSOLUT_REFRACTORY_STEP*paramIndex;
			cout << "ABSOLUT_REFRACTORY_PERIOD: " << NeuronMathTools::ABSOLUT_REFRACTORY_PERIOD << endl;
				#endif
			
				#ifdef _PTI_TEST_MODE
			NeuronMathTools::PSP_TEMPORAL_IMPACT = PSP_TEMPORAL_IMPACT_STEP*paramIndex;
			cout << "PSP_TEMPORAL_IMPACT: " << NeuronMathTools::PSP_TEMPORAL_IMPACT << endl;
				#endif
				
				#ifdef _THRESHOLD_MAX_TEST_MODE
			NeuronMathTools::THRESHOLD_MAX = THRESHOLD_MAX_STEP*(paramIndex+1);
			cout << "THRESHOLD_MAX: " << NeuronMathTools::THRESHOLD_MAX << endl;
				#endif
				
				#ifdef _MAX_PSP_POTENTIAL_TEST_MODE
			NeuronMathTools::MAX_PSP_POTENTIAL = MAX_PSP_POTENTIAL_STEP*(paramIndex+1);
			cout << "MAX_PSP_POTENTIAL: " << NeuronMathTools::MAX_PSP_POTENTIAL << endl;
				#endif
				
				#ifdef _TRANSITION_TEST_MODE
			EDNetwork::TRANSITION_TIME_LENGTH = TRANSITION_TIME_STEP*(paramIndex+1);
			//EDNetwork::TRANSITION_TIME_LENGTH = TRANSITION_TIME_STEP*paramIndex;
			cout << "TRANSITION_TIME_LENGTH: " << EDNetwork::TRANSITION_TIME_LENGTH << endl;	
				#endif
				
			#endif
			
			testBestIndividual();
			paramIndex++;
			
			#ifndef _CONDITIONAL_TEST_MODE
				#ifdef _INPUT_RATIO_TEST_MODE
			InputAssembly::INPUT_RATIO = INPUT_RATIO_STEP*paramIndex+1;
			cout << "INPUT_RATIO: " << InputAssembly::INPUT_RATIO << endl;
				#endif
				
				#ifdef _EXCIT_RATIO_TEST_MODE
			EDAssembly::EXCIT_RATIO = EXCIT_RATIO_STEP*paramIndex+1;
			cout << "EXCIT_RATIO: " << EDAssembly::EXCIT_RATIO << endl;
				#endif
			
				#ifdef _INHIB_RATIO_TEST_MODE
			EDAssembly::INHIB_RATIO = INHIB_RATIO_STEP*paramIndex+1;
			cout << "INHIB_RATIO: " << EDAssembly::INHIB_RATIO << endl;
				#endif
			#endif
			
			
		}
		#else
		testBestIndividual();
		#endif
		
	//#ifdef _MPI_TEST
		cout << "*** EvoNetwork *** freeing MPI module" << endl;
	//#endif
		freeMPIModule();

	}
	
	#ifdef _GLOBAL_STAT_MODE
		#ifdef _MULTI_TEST_MODE
			#ifdef _PARAMETRIC_TEST_MODE
		((ActivityTester*) stater)->trace();
		delete((ActivityTester*) stater);
		
				#ifdef _LINK_INPUT_STAT_MODE
		((InputTester*) inputLinkStater)->trace();
		delete((InputTester*) inputLinkStater);
		inputLinkStater=0;
		cerr << "After Freeing Input Activity Stats" << endl;
				#endif
			#else
				#ifdef _PHASE_TEST_MODE
		((ActivityTester*) stater)->trace();
		delete((ActivityTester*) stater);
		
					#ifdef _LINK_INPUT_STAT_MODE
		((InputTester*) inputLinkStater)->trace();
		delete((InputTester*) inputLinkStater);
		inputLinkStater=0;
		cerr << "After Freeing Input Activity Stats" << endl;
					#endif
				#else
		((ActivityStater*) stater)->trace();
		delete((ActivityStater*) stater);
					
					#ifdef _LINK_INPUT_STAT_MODE
		((InputStater*) inputLinkStater)->trace();
		delete((InputStater*) inputLinkStater);
		inputLinkStater=0;
		cerr << "After Freeing Input Activity Stats" << endl;
					#endif
				#endif
			#endif
		#else
			#ifdef _PHASE_TEST_MODE
		((ActivityStater*) stater)->stat();
		delete((ActivityStater*) stater);
		
				#ifdef _LINK_INPUT_STAT_MODE
		((InputStater*) inputLinkStater)->stat();
		delete((InputStater*) inputLinkStater);
		inputLinkStater=0;
		cerr << "After Freeing Input Activity Stats" << endl;
				#endif
			#endif
		#endif
	#endif
	
	#ifdef _NETWORK_STAT_MODE
	endEvoNetworkFiles();
	#endif
	
	cout << "*** Synchro Module " << MPI_GLOBALS.getMyId() << " *** after break synchronizing with COMM_WORLD root module " << endl;
	MPI_GLOBALS.synchronize();
	
	cout << "*** Synchro Module " << MPI_GLOBALS.getMyId() << " *** after break synchronizing with COMM_WORLD root module " << endl;
	MPI_GLOBALS.synchronize();
}

void EvoNetwork::testBestIndividual()
{	
	//initEvalIndex();

	//integrateBirthFlash();

	#ifdef _RUN_MODE

	//#ifdef _MPI_TEST
	cout << "*** EvoNetwork *** integrating birth flash" << endl;
	//#endif

	integrateBirthFlash();

	if (!testBreak())
	{
		initTestIndex();
		runNetwork();
		incrementEvalIndex();
	}
	#else
		#ifdef _TEST_MODE
	
			#ifdef _MULTI_TEST_MODE
	initTestIndex();
	
	//while (getTestIndex()<NB_MULTI_TESTS+1 & testSynchro())
	while (getTestIndex()<NB_MULTI_TESTS+1)
	{
				#ifdef _PARAMETRIC_TEST_MODE
		if (paramIndex==0 && getTestIndex()==0)
		{
			testSynchro();
			integrateBirthFlash();
		}
		else
		{
			if (!testBreak())
			{
				testSynchro();
				integrateBirthFlash();
			}
			else
			{
				break;
			}
		}
				#else
		if (getTestIndex()==0)
		{
			testSynchro();
			integrateBirthFlash();
		}
		else
		{
			if (!testBreak())
			{
				testSynchro();
				integrateBirthFlash();
			}
			else
			{
				break;
			}
		}
				#endif
				
				#ifdef _PHASE_TEST_MODE
		
		if (!testBreak())
		{
			testNetwork();

			//incrementEvalIndex();
		}
		else
		{
			break;
		}
		
					#ifdef _TRANSITION_STAT_MODE
		while (getEvalIndex()<2*(2*NB_TESTED_ANIMALS+1))
		{
			//testSynchro();
			
			if (!testBreak())
			{
				testNetwork();
			}
			else
			{
				break;
			}

			//incrementEvalIndex();

			if (!testBreak())
			{
				testNetwork();
			}
			else
			{
				break;
			}

			//incrementEvalIndex();
		}
					#else
		while (getEvalIndex()<2*NB_TESTED_ANIMALS+1)
		{
			//testSynchro();
			
			if (!testBreak())
			{
				testNetwork();
			}
			else
			{
				break;
			}

			//incrementEvalIndex();

			if (!testBreak())
			{
				testNetwork();
			}
			else
			{
				break;
			}

			//incrementEvalIndex();
		}
					#endif
		if (!testBreak())
		{
			testNetwork();

		}
		else
		{
			break;
		}
	
		//incrementEvalIndex();
					
				#else
				
		if (!testBreak())
		{
			testNetwork();
		}
		else
		{
			break;
		}
		
				#endif			
		incrementTestIndex();
	}
			
			#else
		
	//initEvalIndex();
				#ifdef _PHASE_TEST_MODE
	testSynchro();
	
	//#ifdef _MPI_TEST
	cout << "*** EvoNetwork *** integrating birth flash" << endl;
	//#endif

	integrateBirthFlash();
	//stater = new ActivityStater();
	
	if (!testBreak())
	{
		testNetwork();

		//incrementEvalIndex();
	}
					#ifdef _TRANSITION_STAT_MODE
	while (getEvalIndex()< 2*(2*NB_TESTED_ANIMALS+1))
	{
		if (!testBreak())
		{
			testNetwork();
		}
		else
		{
			break;
		}

		//incrementEvalIndex();

		if (!testBreak())
		{
			testNetwork();
		}
		else
		{
			break;
		}

		//incrementEvalIndex();
	}
					#else
	while (getEvalIndex()< 2*NB_TESTED_ANIMALS+1)
	{
		if (!testBreak())
		{
			testNetwork();
		}
		else
		{
			break;
		}

		//incrementEvalIndex();

		if (!testBreak())
		{
			testNetwork();
		}
		else
		{
			break;
		}

		//incrementEvalIndex();
	}
					#endif
	
	if (!testBreak())
	{
		testNetwork();
	}
	
	//incrementEvalIndex();

	//delete((ActivityStater*) stater);
	
				#else
	integrateBirthFlash();
	
	if (!testBreak())
	{
		testNetwork();
	}
				#endif
				
			#endif
		#else
	
			#ifdef _MULTI_TEST_MODE
	initTestIndex();
		
	while (getTestIndex()<NB_MULTI_TESTS+1)
	{
		//testSynchro();
				#ifdef _PARAMETRIC_TEST_MODE
		if (paramIndex==0 && getTestIndex()==0)
		{
			cout << "In initialise birth flash" << endl;
			
			cout << "Network testing synchro" << endl;
			testSynchro();
			integrateBirthFlash();
		}
		else
		{
			cout << "In second order birth flash" << endl;
			
			cout << "Network testing synchro" << endl;
			
			if (!testBreak())
			{
				testSynchro();
				integrateBirthFlash();
			}
			else
			{
				break;
			}
		}
				#else
		if (getTestIndex()==0)
		{
			
			testSynchro();
			integrateBirthFlash();
		}
		else
		{
			if (!testBreak())
			{
				testSynchro();
				integrateBirthFlash();
			}
			else
			{
				break;
			}
		}		
				#endif
				
		if (!testBreak())
		{
			initNetworkFiles();
			integrateBirthFlash();
			endNetworkFiles();

				#ifdef _PARAMETRIC_TEST_MODE
			if (stater)
			{
				((ActivityTester*) stater)->stat(paramIndex);
			}
			
					#ifdef _LINK_INPUT_STAT_MODE
			if (inputLinkStater)
			{
				((InputTester*) inputLinkStater)->stat(paramIndex);
			}
					#endif
				/*
				#else
			if (stater)
			{
				//((ActivityTester*) stater)->stat();
				((ActivityStater*) stater)->stat();
			}
			*/
				#endif
		}
		else
		{
			cout << "Out of multi test loop" << endl;
			break;
		}
		
		incrementTestIndex();
	}
/*
	cout << "Graphing mean data files" << endl;
	meanDataFiles();
*/
			#else
	testSynchro();
	//#ifdef _MPI_TEST
	cout << "*** EvoNetwork *** integrating birth flash" << endl;
	//#endif

	integrateBirthFlash();
	
	if (!testBreak())
	{
		initNetworkFiles();
		integrateBirthFlash();
		endNetworkFiles();
	}
			#endif
	
		#endif
	#endif
}

	#ifdef _MULTI_TEST_MODE
void EvoNetwork::meanDataFiles()
{
	stater = new ActivityStater();
	delete ((ActivityStater*) stater);
	
}
	#endif
//#endif
/*
void EvoNetwork::initNetworkStater()
{
	stater=(NetworkStater*) NetworkStater::initNetworkStater();

	NetworkStater::openTracer();
}

void EvoNetwork::endNetworkStater()
{

	NetworkStater::closeTracer();

	NetworkStater::openGrapher();

	((NetworkStater*) stater)->graph();

	NetworkStater::runGrapher();
	NetworkStater::closeGrapher();
}
*/
void EvoNetwork::reInitTopology()
{
	// Réinitialise les synpases des assemblèes d'entrees
	for (int i=0;i<nbInputBuffers;i++)
	{
		((EDAssembly*) ((InputAssembly*) inputBuffers[i]))->reInitAssembly();
	}

	// Réinitialise les synpases des assemblèes d'entrees
	for (int i=0;i<NB_ASSEMBLIES;i++)
	{
		((EDAssembly*) assemblies[i])->reInitAssembly();
	}

	// Réinitialise les synpases des assemblèes d'entrees
	for (int i=0;i<nbOutputBuffers;i++)
	{
		((EDAssembly*) ((OutputAssembly*) outputBuffers[i]))->reInitAssembly();
	}
}

void EvoNetwork::reInitEDNetwork()
{
	// Réinitialise les synpases des assemblèes d'entrees
	for (int i=0;i<nbInputBuffers;i++)
	{
		((EDAssembly*) ((InputAssembly*) inputBuffers[i]))->reInitEDAssembly();
	}

	// Réinitialise les synpases des assemblèes d'entrees
	for (int i=0;i<NB_ASSEMBLIES;i++)
	{
		((EDAssembly*) assemblies[i])->reInitEDAssembly();
	}

	// Réinitialise les synpases des assemblèes d'entrees
	for (int i=0;i<nbOutputBuffers;i++)
	{
		((EDAssembly*) ((OutputAssembly*) outputBuffers[i]))->reInitEDAssembly();
	}
}

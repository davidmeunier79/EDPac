// NetworkGrapher.cc

// Local Includes
#include "NetworkGrapher.h"

/****************************************************************************************************************************************/
/**************************************************** Methodes de la classe NetworkGrapher *****************************************************/
/****************************************************************************************************************************************/

NetworkGrapher::NetworkGrapher()
{
}

NetworkGrapher::~NetworkGrapher()
{
}


/****************************************************************************************************************************************/
/******************************************************* Methodes statiques *************************************************************/
/****************************************************************************************************************************************/

#ifdef _NETWORK_GRAPH_MODE

/****************************************************************************************************************************************/
/******************************************************* Methodes de graphiques *********************************************************/
/****************************************************************************************************************************************/

void NetworkGrapher::graph(EDNetwork* t)
{
	//openGrapher();
	#ifdef _SYNAPSE_TRACE_MODE
		//#ifdef _TRACE_TEST
	cout << "Graphing EDNetwork SynapseFiles" << endl;
		//#endif
	graphSynapseFiles(t);
	#endif

	#ifdef _NEURON_TRACE_MODE
		//#ifdef _TRACE_TEST
	cout << "Graphing EDNetwork NeuronFiles" << endl;
		//#endif
	graphNeuronFiles(t);
	#endif

	std::vector<Assembly*>::iterator it=t->assemblies.begin();
	std::vector<Assembly*>::iterator end=t->assemblies.end();

	while (it!=end)
	{
	#ifdef _SINGLE_ASSEMBLY_GRAPH_MODE
		if (((Assembly*) *it)->getIndex()==SINGLE_ASSEMBLY_INDEX)
		{
			((AssemblyGrapher*) t->grapher)->graph((EDAssembly*) *it);
		}
	#else
		((AssemblyGrapher*) t->grapher)->graph((EDAssembly*) *it);
	#endif
		it++;
	}

	//runGrapher();
	//closeGrapher();
}

	#ifdef _SYNAPSE_TRACE_MODE
void NetworkGrapher::graphSynapseFiles(EDNetwork* t)
{
}
	#endif

	#ifdef _NEURON_TRACE_MODE
void NetworkGrapher::graphNeuronFiles(EDNetwork* t)
{
}
	#endif
#endif

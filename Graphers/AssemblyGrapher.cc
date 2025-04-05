// AssemblyGrapher.cc

// Local Includes
#include "AssemblyGrapher.h"

/****************************************************************************************************************************************/
/************************************************* Methodes de la classe AssemblyGrapher ************************************************/
/****************************************************************************************************************************************/

//AssemblyGrapher* AssemblyGrapher::theAssemblyGrapher=0;

AssemblyGrapher::AssemblyGrapher()
{
}

AssemblyGrapher::~AssemblyGrapher()
{
}

/****************************************************************************************************************************************/
/******************************************************* Methodes de graphiques *********************************************************/
/****************************************************************************************************************************************/

#ifdef _NETWORK_GRAPH_MODE
/****************************************************************************************************************************************/
/******************************************************* Methodes de graphiques *********************************************************/
/****************************************************************************************************************************************/
void AssemblyGrapher::graph(EDAssembly* a)
{
	#ifdef _ASSEMBLY_GRAPH_MODE
		#ifdef _TRACE_TEST
	cout << "Graphing assembly " << a->index << endl;
		#endif

		#ifdef _SYNAPSE_TRACE_MODE
			#ifdef _TRACE_TEST
		cout << "Graphing Assembly SynapseFiles" << endl;
			#endif
		graphSynapseFiles(a);
		#endif

		#ifdef _NEURON_TRACE_MODE
			#ifdef _TRACE_TEST
		cout << "Graphing Assembly NeuronFiles" << endl;
			#endif
		graphNeuronFiles(a);
		#endif

	#endif

	#ifdef _NEURON_GRAPH_MODE
	std::vector<Neuron*>::iterator it=a->neurons.begin();
	std::vector<Neuron*>::iterator end=a->neurons.end();

	while (it!=end)
	{
		#ifdef _SINGLE_NEURON_TRACE_MODE
		if (((EDNeuron*) *it)->getIndex()==SINGLE_NEURON_INDEX)
		{
			((EDNeuron*) *it)->graph();
		}
		#else
		//cout << "Graphing Neuron " << ((EDNeuron*) *it)->getIndex() << endl;
		((EDNeuron*) *it)->graph();
		#endif
		it++;
	}
	#endif
}
#endif

#ifdef _ASSEMBLY_GRAPH_MODE
	#ifdef _SYNAPSE_TRACE_MODE
void AssemblyGrapher::graphSynapseFiles(EDAssembly* a)
{

}
	#endif

	#ifdef _NEURON_TRACE_MODE
void AssemblyGrapher::graphNeuronFiles(EDAssembly* a)
{
		#ifdef _MEMBRANE_POTENTIAL_TRACE_MODE

			#ifdef _SINGLE_ASSEMBLY_TRACE_MODE
	if (a->index == SINGLE_ASSEMBLY_INDEX)
	{
		if (neuronGnuplotFile->isOpen())
		{
				#ifdef _MULTIPLOT_GRAPH_MODE
			ostringstream oss;
			oss << MEMBRANE_POTENTIAL_FILENAME ;
			oss << "_Assembly" << a->index;
			oss << "_Generation" << getEvoIndex();
			oss << "_Pacman" << getTopoIndex();
			oss << "_Run" << getEvalIndex();
			oss << "_Test" << getTestIndex();

					//#ifdef _TRACE_TEST
			cout << "Neuron grapher adding neuron plot for assembly" << a->index << endl;
					//#endif
			neuronGnuplotFile->setTitle(MEMBRANE_POTENTIAL_FILENAME);
			neuronGnuplotFile->setOutput(oss.str());
					//#ifndef _THRESHOLD_TRACE_MODE
			neuronGnuplotFile->plotIndexedLines(MEMBRANE_POTENTIAL_FILENAME,0,a->neurons.size());
					/*#endif
					#ifdef _THRESHOLD_TRACE_MODE
		neuronGnuplotFile->plotFirstLine(MEMBRANE_POTENTIAL_FILENAME);
		neuronGnuplotFile->plotSecondLine(THRESHOLD_FILENAME);
					#endif*/
				#else
					#ifdef _SINGLE_PLOT_GRAPH_MODE
			for (int i=0;i<a->neurons.size();i++)
			{

				ostringstream oss;
				oss << MEMBRANE_POTENTIAL_FILENAME ;
				oss << "_Generation" << getEvoIndex();
				oss << "_Pacman" << getTopoIndex();
				oss << "_Run" << getEvalIndex();
				oss << "_Test" << getTestIndex();
				oss << "_Assembly" << a->index;
				oss << "_Neuron" << i;

					//#ifdef _TRACE_TEST
				cout << "Neuron grapher adding neuron plot for assembly" << a->index;
				cout << " for neuron " << i << endl;
					//#endif
				neuronGnuplotFile->setTitle(MEMBRANE_POTENTIAL_FILENAME);
				neuronGnuplotFile->setOutput(oss.str());
						#ifndef _THRESHOLD_TRACE_MODE
				neuronGnuplotFile->plotIndexedLine(MEMBRANE_POTENTIAL_FILENAME,i);
						#endif
						#ifdef _THRESHOLD_TRACE_MODE
				neuronGnuplotFile->plotFirstIndexedLine(MEMBRANE_POTENTIAL_FILENAME,i);
				neuronGnuplotFile->plotSecondIndexedLine(THRESHOLD_FILENAME,i);
						#endif

			}
					#endif
				#endif
		}
		else
		{
			cerr << "Warning, neuronGnuplotFile should be inited" << endl;
		}
	}
			#endif
		#endif
}
	#endif
#endif

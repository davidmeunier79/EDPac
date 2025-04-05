// NeuronGrapher.cc

// Local Includes
#include "NeuronGrapher.h"

/****************************************************************************************************************************************/
/**************************************************** Methodes de la classe NeuronGrapher *****************************************************/
/****************************************************************************************************************************************/

NeuronGrapher::NeuronGrapher()
{
}

NeuronGrapher::NeuronGrapher(IndexedObject* io): SynapseGrapher(io)
{
}

NeuronGrapher::~NeuronGrapher()
{
	cout << "~NeuronGrapher" << endl;
}

/****************************************************************************************************************************************/
/******************************************************* Methodes statiques *************************************************************/
/****************************************************************************************************************************************/
#ifdef _NETWORK_GRAPH_MODE
void NeuronGrapher::graph(EDNeuron* n)
{
	#ifdef _NEURON_GRAPH_MODE

		//#ifdef _TRACE_TEST
	cout << "Graphing neuron " << n->index << endl;
		//#endif

		#ifdef _SYNAPSE_TRACE_MODE
			//#ifdef _TRACE_TEST
	cout << "Graphing Neuron SynapseFiles" << endl;
			//#endif
	graphSynapseFiles(n);
		#endif

		#ifdef _NEURON_TRACE_MODE
			//#ifdef _TRACE_TEST
	cout << "Graphing Neuron NeuronFiles" << endl;
			//#endif
	graphNeuronFiles(n);
		#endif
	#endif
/*
	#ifdef _SYNAPSE_GRAPH_MODE
	std::vector<Link*>::iterator itOut=n->outputLinks.begin();
	std::vector<Link*>::iterator endOut=n->outputLinks.end();

	while (itOut!=endOut)
	{
	#ifdef _SINGLE_SYNAPSE_TRACE_MODE
		if (((EDSynapse*) *itOut)->getIndex()==SINGLE_SYNAPSE_INDEX)
		{
			((EDSynapse*) *itOut)->graph();
		}
	#else
		//((EDSynapse*) *itOut)->graph();
		if (n->grapher)
		{
			((SynapseGrapher*) n->grapher)->graph((DynamicSynapse*) *itOut);
		}
	#endif
		itOut++;
	}
	#endif
*/
}
#endif

#ifdef _NEURON_GRAPH_MODE
	#ifdef _SYNAPSE_TRACE_MODE
void NeuronGrapher::graphSynapseFiles(EDNeuron* n)
{
	std::vector<Link*>::iterator itIn=n->inputLinks.begin();
	std::vector<Link*>::iterator endIn=n->inputLinks.end();

	std::vector<Link*>::iterator itOut=n->outputLinks.begin();
	std::vector<Link*>::iterator endOut=n->outputLinks.end();

		#ifdef _WEIGHT_TRACE_MODE

	if (n->inputLinks.size())
	{
		stringstream oss;
		oss << WEIGHT_FILENAME << n->index;
		oss << (Handler*) this;

			#ifdef _SINGLE_NEURON_TRACE_MODE
		if (n->index==SINGLE_NEURON_INDEX)
		{
		
			int firstInIndex=0;
			int lastInIndex=n->inputLinks.size()-1;

			if (synapseGnuplotFile->isOpen())
			{
				synapseGnuplotFile->setTitle("Input_"+oss.str());
				synapseGnuplotFile->setOutput("Input_"+oss.str());
				synapseGnuplotFile->plotIndexedLines(oss.str(),firstInIndex,lastInIndex);
			}
			else
			{
				cerr << "Warning, synapseGnuplotFile should be inited" << endl;
			}
			
			int firstInIndex=0;
			int lastInIndex=n->inputLinks.size()-1;

			if (synapseGnuplotFile->isOpen())
			{
				synapseGnuplotFile->setTitle("Input_"+oss.str());
				synapseGnuplotFile->setOutput("Input_"+oss.str());
				synapseGnuplotFile->plotIndexedLines(oss.str(),firstInIndex,lastInIndex);
			}
			else
			{
				cerr << "Warning, synapseGnuplotFile should be inited" << endl;
			}
		}
			#else
				#ifdef _SINGLE_SYNAPSE_TRACE_MODE
		int firstInIndex=0;
		int lastInIndex=n->inputLinks.size()-1;

		if (synapseGnuplotFile->isOpen())
		{
			synapseGnuplotFile->setTitle("Input_"+oss.str());
			synapseGnuplotFile->setOutput("Input_"+oss.str());
			synapseGnuplotFile->plotIndexedLines(oss.str(),firstInIndex,lastInIndex);
		}
		else
		{
			cerr << "Warning, synapseGnuplotFile should be inited" << endl;
		}		
				#else			
					#ifdef _GLOBAL_TRACE_MODE
		int firstInIndex=((Synapse*)*itIn)->getSynapseIndex();
		int lastInIndex=((Synapse*)*itIn)->getSynapseIndex()+n->inputLinks.size()-1;

		if (synapseGnuplotFile->isOpen())
		{
			synapseGnuplotFile->setTitle("Input_"+oss.str());
			synapseGnuplotFile->setOutput("Input_"+oss.str());
			synapseGnuplotFile->plotIndexedLines(oss.str(),firstInIndex,lastInIndex);
		}
		else
		{
			cerr << "Warning, synapseGnuplotFile should be inited" << endl;
		}
					#endif
				#endif	
			#endif
	}
	else
	{
		cout << "Neuron " << n->index << " has no input synapses" << endl;
	}

	if (n->outputLinks.size())
	{
		stringstream oss;
		oss << WEIGHT_FILENAME << n->index;
		oss << (Handler*) this;

			#ifdef _SINGLE_NEURON_TRACE_MODE
		if (n->index==SINGLE_NEURON_INDEX)
		{

			int firstOutIndex=n->inputLinks.size();
			int lastOutIndex=n->inputLinks.size()+n->outputLinks.size()-1;

			if (synapseGnuplotFile->isOpen())
			{
				synapseGnuplotFile->setTitle("Output"+oss.str());
				synapseGnuplotFile->setOutput("Output"+oss.str());
				synapseGnuplotFile->plotIndexedLines(oss.str(),firstOutIndex,lastOutIndex);
			}
			else
			{
				cerr << "Warning, synapseGnuplotFile should be inited" << endl;
			}
		}
			#else
				#ifdef _SINGLE_SYNAPSE_TRACE_MODE
		int firstOutIndex=n->inputLinks.size();
		int lastOutIndex=n->inputLinks.size()+n->outputLinks.size()-1;

		if (synapseGnuplotFile->isOpen())
		{
			synapseGnuplotFile->setTitle("Output"+oss.str());
			synapseGnuplotFile->setOutput("Output"+oss.str());
			synapseGnuplotFile->plotIndexedLines(oss.str(),firstOutIndex,lastOutIndex);
		}
		else
		{
			cerr << "Warning, synapseGnuplotFile should be inited" << endl;
		}
				#else
					#ifdef _GLOBAL_TRACE_MODE
		int firstOutIndex=((Synapse*)*itOut)->getIndex();
		int lastOutIndex=((Synapse*)*itOut)->getIndex()+n->outputLinks.size()-1;

		if (synapseGnuplotFile->isOpen())
		{
			synapseGnuplotFile->setTitle("Output"+oss.str());
			synapseGnuplotFile->setOutput("Output"+oss.str());
			synapseGnuplotFile->plotIndexedLines(oss.str(),firstOutIndex,lastOutIndex);
		}
		else
		{
			cerr << "Warning, synapseGnuplotFile should be inited" << endl;
		}
					#endif
				#endif
				
			
			#endif
	}
	else
	{
		cout << "Neuron " << n->index << " has no output synapses" << endl;
	}
	
	// Attention, tous (input et output) dans la meme couleur
// 	if (synapseGnuplotFile->isOpen())
// 	{
// 		
// 		stringstream oss;
// 		oss << WEIGHT_FILENAME << n->index;
// 		oss << (Handler*) this;
// 
// 		synapseGnuplotFile->setTitle(oss.str());
// 		synapseGnuplotFile->setOutput(oss.str());
// 		synapseGnuplotFile->plotIndexedLines(oss.str());
// 	}
// 	else
// 	{
// 		cerr << "Warning, synapseGnuplotFile should be inited" << endl;
// 	}
		#endif
}
	#endif

	#ifdef _NEURON_TRACE_MODE
void NeuronGrapher::graphNeuronFiles(EDNeuron* n)
{

		#ifdef _MEMBRANE_POTENTIAL_TRACE_MODE
	ostringstream oss;
	oss << MEMBRANE_POTENTIAL_FILENAME << (string) n->getStringIndex() << (Handler*) this;

			#ifdef _SINGLE_NEURON_TRACE_MODE
	if(n->index==SINGLE_NEURON_INDEX)
	{
				#ifdef _TRACE_TEST
		cout << "Neuron grapher adding neuron plot " << n->index << endl;
				#endif

		if (neuronGnuplotFile->isOpen())
		{
			neuronGnuplotFile->setTitle(MEMBRANE_POTENTIAL_FILENAME);
			neuronGnuplotFile->setOutput(oss.str());

				#ifdef _THRESHOLD_TRACE_MODE
			neuronGnuplotFile->plotFirstSingleIndexedLine(oss.str());

			ostringstream oss2;
			oss2 << THRESHOLD_FILENAME << (string) n->getStringIndex() << (Handler*) this;

			neuronGnuplotFile->plotLastSingleIndexedLine(oss2.str());
				#else
			neuronGnuplotFile->plotSingleIndexedLine(oss.str());
				#endif
		}
		else
		{
			cerr << "Warning, neuronGnuplotFile should be inited" << endl;
		}

	}
			#else
				#ifdef _SINGLE_SYNAPSE_TRACE_MODE
					//#ifdef _TRACE_TEST
		cout << "Neuron grapher adding neuron plot " << n->index << endl;
					//#endif

		if (neuronGnuplotFile->isOpen())
		{
			neuronGnuplotFile->setTitle(MEMBRANE_POTENTIAL_FILENAME);
			neuronGnuplotFile->setOutput(oss.str());

					#ifdef _THRESHOLD_TRACE_MODE
			neuronGnuplotFile->plotFirstSingleIndexedLine(oss.str());

			ostringstream oss2;
			oss2 << THRESHOLD_FILENAME << (string) n->getStringIndex() << (Handler*) this;

			neuronGnuplotFile->plotLastSingleIndexedLine(oss2.str());
					#else
			neuronGnuplotFile->plotSingleIndexedLine(oss.str());
					#endif
		}
		else
		{
			cerr << "Warning, neuronGnuplotFile should be inited" << endl;
		}			
				#endif
				/*
				#ifdef _GLOBAL_TRACE_MODE
	if (neuronGnuplotFile->isOpen())
	{
					//#ifdef _TRACE_TEST
		cout << "Neuron grapher adding neuron plot " << n->index << endl;
					//#endif

		neuronGnuplotFile->setTitle(MEMBRANE_POTENTIAL_FILENAME);
		neuronGnuplotFile->setOutput(oss.str());

					#ifndef _THRESHOLD_TRACE_MODE
		neuronGnuplotFile->plotIndexedLine(MEMBRANE_POTENTIAL_FILENAME,n->index);
					#endif
					#ifdef _THRESHOLD_TRACE_MODE
		neuronGnuplotFile->plotFirstLine(MEMBRANE_POTENTIAL_FILENAME);
		neuronGnuplotFile->plotSecondLine(THRESHOLD_FILENAME);
					#endif
	}
	else
	{
		cerr << "Warning, neuronGnuplotFile should be inited" << endl;
	}
				#endif
				*/
			#endif
		#endif
}
	#endif
#endif

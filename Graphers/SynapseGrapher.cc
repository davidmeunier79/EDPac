 // SynapseGrapher.cc

// Local Includes
#include "SynapseGrapher.h"

/****************************************************************************************************************************************/
/********************************************** Methodes de la classe SynapseGrapher ****************************************************/
/****************************************************************************************************************************************/

//GnuplotFile* SynapseGrapher::synapseGnuplotFile=0;
//GnuplotFile* SynapseGrapher::neuronGnuplotFile=0;

SynapseGrapher::SynapseGrapher()
{
#ifdef _SYNAPSE_TRACE_MODE
	synapseGnuplotFile = new GnuplotFile();
#endif

#ifdef _NEURON_TRACE_MODE
	neuronGnuplotFile = new GnuplotFile();
#endif

	openGrapher();
}

SynapseGrapher::SynapseGrapher(IndexedObject* io): Grapher(io)
{
	
#ifdef _SYNAPSE_TRACE_MODE
	synapseGnuplotFile = new GnuplotFile();
#endif

#ifdef _NEURON_TRACE_MODE
	neuronGnuplotFile = new GnuplotFile();
#endif

	openGrapher();
}

SynapseGrapher::~SynapseGrapher()
{
	closeGrapher();
	runGrapher();

#ifdef _SYNAPSE_TRACE_MODE
	delete(synapseGnuplotFile);
#endif

#ifdef _NEURON_TRACE_MODE
	delete(neuronGnuplotFile);
#endif

	cout << "~SynapseGrapher" << endl;
}

void SynapseGrapher::openGrapher()
{
#ifdef _SYNAPSE_TRACE_MODE
	if (synapseGnuplotFile)
	{
	//#ifdef _TRACE_TEST
		cout << "Opening Synapse_Synapse File" << endl;
	//#endif
		ostringstream oss;
		oss << "Synapse_Synapse" << (string) getStringIndex() << (Handler*) this;
		synapseGnuplotFile->openGnuplotFile(oss.str());
	}
	else
	{
		cerr << "Warning, synapseGnuplotFile should be inited" << endl;
	}
#endif
#ifdef _NEURON_TRACE_MODE
	if (neuronGnuplotFile)
	{
	//#ifdef _TRACE_TEST
		cout << "Opening Neuron_Synapse File" << endl;
	//#endif
		ostringstream oss;
		oss << "Neuron_Synapse" << (string) getStringIndex() << (Handler*) this;
		neuronGnuplotFile->openGnuplotFile(oss.str());
	}
	else
	{
		cerr << "Warning, synapseGnuplotFile should be inited" << endl;
	}
#endif
}

void SynapseGrapher::runGrapher()
{
#ifdef _SYNAPSE_TRACE_MODE
	if (synapseGnuplotFile)
	{
		synapseGnuplotFile->systemFile();
	}
	else
	{
		cerr << "Warning, synapseGnuplotFile should be inited" << endl;
	}
#endif
#ifdef _NEURON_TRACE_MODE
	if (neuronGnuplotFile)
	{
		neuronGnuplotFile->systemFile();
	}
	else
	{
		cerr << "Warning, neuronGnuplotFile should be inited" << endl;
	}
#endif
}

void SynapseGrapher::closeGrapher()
{
#ifdef _SYNAPSE_TRACE_MODE
	if (synapseGnuplotFile->isOpen())
	{
		synapseGnuplotFile->closeFile();
	}
	else
	{
		cerr << "Warning, synapseGnuplotFile should be open" << endl;
	}
#endif
#ifdef _NEURON_TRACE_MODE
	if (neuronGnuplotFile->isOpen())
	{
		neuronGnuplotFile->closeFile();
	}
	else
	{
		cerr << "Warning, synapseGnuplotFile should be open" << endl;
	}
#endif
}

/****************************************************************************************************************************************/
/******************************************************* Methodes statiques *************************************************************/
/****************************************************************************************************************************************/

#ifdef _SYNAPSE_GRAPH_MODE
/****************************************************************************************************************************************/
/******************************************************* Methodes de graphiques *********************************************************/
/****************************************************************************************************************************************/
void SynapseGrapher::graph(EDSynapse* s)
{

		#ifdef _TRACE_TEST
	cout << "Graphing synapse " << s->getIndex() << endl;
		#endif

		#ifdef _SYNAPSE_TRACE_MODE
			//#ifdef _TRACE_TEST
	cout << "Graphing Synapse SynapseFiles" << endl;
			//#endif
	graphSynapseFiles(s);
		#endif

		#ifdef _NEURON_TRACE_MODE
			//#ifdef _TRACE_TEST
	cout << "Graphing Synapse NeuronFiles" << endl;
			//#endif
	graphNeuronFiles(s);
		#endif
}
#endif

	#ifdef _SYNAPSE_TRACE_MODE
void SynapseGrapher::graphSynapseFiles(EDSynapse* s)
{
		#ifdef _WEIGHT_TRACE_MODE
	ostringstream oss;
	oss << WEIGHT_FILENAME << (string) s->getStringIndex() << (Handler*) this;

			#ifdef _SINGLE_SYNAPSE_TRACE_MODE
	if (s->index==SINGLE_SYNAPSE_INDEX)
	{
		if (synapseGnuplotFile->isOpen())
		{
			cout << "Graphing synapse " << s->index << endl;

			synapseGnuplotFile->setTitle(WEIGHT_FILENAME);
			synapseGnuplotFile->setOutput(oss.str());
			synapseGnuplotFile->plotSingleIndexedLine(oss.str());
		}
		else
		{
			cerr << "Warning, synapseGnuplotFile should be inited" << endl;
		}
	}
			#else
				#ifdef _GLOBAL_TRACE_MODE
	if (synapseGnuplotFile->isOpen())
	{
		synapseGnuplotFile->setOutput(oss.str());
		synapseGnuplotFile->plotIndexedLine(oss.str(),s->getIndex());
	}
	else
	{
		cerr << "Warning, synapseGnuplotFile should be inited" << endl;
	}
				#endif
			#endif
		#endif
}
	#endif

	#ifdef _NEURON_TRACE_MODE
void SynapseGrapher::graphNeuronFiles(EDSynapse* s)
{
		#ifdef _MEMBRANE_POTENTIAL_TRACE_MODE
/*			#ifdef _SINGLE_SYNAPSE_TRACE_MODE
	ostringstream oss;
	oss << "PrePost" << MEMBRANE_POTENTIAL_FILENAME;
	oss << "_Synapse" << s->index;
	oss << "_Generation" << getEvoIndex();
	oss << "_Pacman" << getTopoIndex();
	oss << "_Run" << getEvalIndex();
	oss << "_Test" << getTestIndex();

	if(neuronGnuplotFile->isOpen())
	{
		neuronGnuplotFile->setTitle("PrePost Spike Trace");
		neuronGnuplotFile->setOutput(oss.str());
		neuronGnuplotFile->plotFirstSingleIndexedLine(MEMBRANE_POTENTIAL_FILENAME+ (string) ((Neuron*) s->_pPreNeuron)->getStringIndex()+oss.str());
		neuronGnuplotFile->plotSecondSingleIndexedLine(MEMBRANE_POTENTIAL_FILENAME+ (string) ((Neuron*) s->_pPostNeuron)->getStringIndex()+oss.str());
		#ifdef _THRESHOLD_TRACE_MODE
		neuronGnuplotFile->plotSecondSingleIndexedLine(THRESHOLD_FILENAME+ (string) ((Neuron*) s->_pPreNeuron)->getStringIndex());
		neuronGnuplotFile->plotSecondSingleIndexedLine(THRESHOLD_FILENAME+ (string) ((Neuron*) s->_pPostNeuron)->getStringIndex());
		#endif
		neuronGnuplotFile->plotLastSingleIndexedLine(WEIGHT_FILENAME+(string) ((EDSynapse*) s)->getStringIndex());
	}
	else
	{
		cerr << "Warning, neuronGnuplotFile should be inited" << endl;
	}
			#else
				#ifdef _GLOBAL_TRACE_MODE
				#endif
			#endif
*/		#endif
}
	#endif

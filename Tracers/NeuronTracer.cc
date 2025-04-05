// NeuronTracer.cc

// Local Includes
#include "NeuronTracer.h"

/****************************************************************************************************************************************/
/************************************************** Methodes de la classe NeuronTracer **************************************************/
/****************************************************************************************************************************************/
NeuronTracer::NeuronTracer()
{
#ifdef _TEST
	cout << "NeuronTracer" << endl;
#endif

#ifdef _MEMBRANE_POTENTIAL_TRACE_MODE
	membraneFile = new DataFile();
#endif

#ifdef _THRESHOLD_TRACE_MODE
	thresholdFile = new DataFile();
#endif
	openTracer();
}

NeuronTracer::NeuronTracer(IndexedObject* io): SynapseTracer(io)
{
#ifdef _TEST
	cout << "NeuronTracer" << endl;
#endif

#ifdef _MEMBRANE_POTENTIAL_TRACE_MODE
	membraneFile = new DataFile();
#endif

#ifdef _THRESHOLD_TRACE_MODE
	thresholdFile = new DataFile();
#endif
	openTracer();
}

NeuronTracer::~NeuronTracer()
{
	cout << "~NeuronTracer" << endl;

	runTracer();
	closeTracer();

#ifdef _MEMBRANE_POTENTIAL_TRACE_MODE
	delete(membraneFile);
#endif

#ifdef _THRESHOLD_TRACE_MODE
	delete(thresholdFile);
#endif

}


/****************************************************************************************************************************************/
/************************************************** Methodes statiques ******************************************************************/
/****************************************************************************************************************************************/

void NeuronTracer::openTracer()
{
#ifdef _MEMBRANE_POTENTIAL_TRACE_MODE
	if (membraneFile)
	{
		ostringstream oss;
		oss << MEMBRANE_POTENTIAL_FILENAME << (string) getStringIndex() << (Handler*) this;
		membraneFile->openDataFile(oss.str());
	}
	else
	{
		cerr << "Warning, membraneFile should be inited" << endl;
	}
#endif
#ifdef _THRESHOLD_TRACE_MODE
 	if (thresholdFile)
	{
		ostringstream oss2;
		oss2 << THRESHOLD_FILENAME << (string) getStringIndex() << (Handler*) this;
		thresholdFile->openDataFile(oss2.str());
	}
	else
	{
		cerr << "Warning, thresholdFile should be inited" << endl;
	}
#endif
}

void NeuronTracer::closeTracer()
{
#ifdef _MEMBRANE_POTENTIAL_TRACE_MODE
	if (membraneFile->isOpen())
	{
		membraneFile->closeFile();
	}
	else
	{
		cerr << "Warning, membraneFile should be open" << endl;
	}
#endif
#ifdef _THRESHOLD_TRACE_MODE
	if (thresholdFile->isOpen())
	{
		thresholdFile->closeFile();
	}
	else
	{
		cerr << "Warning, thresholdFile should be open" << endl;
	}
#endif
}

void NeuronTracer::runTracer()
{
#ifdef _MEMBRANE_POTENTIAL_TRACE_MODE
	if (membraneFile->isOpen())
	{
		membraneFile->formatFile();
	}
	else
	{
		cerr << "Warning, membraneFile should be open" << endl;
	}
#endif

#ifdef _THRESHOLD_TRACE_MODE
	if (thresholdFile->isOpen())
	{
		thresholdFile->formatFile();
	}
	else
	{
		cerr << "Warning, thresholdFile should be open" << endl;
	}
#endif

}

/****************************************************************************************************************************************/
/************************************************** Methodes de traces ******************************************************************/
/****************************************************************************************************************************************/
/****************************************************************************************************************************************/
/************************************************** Methodes statiques ******************************************************************/
/****************************************************************************************************************************************/
#ifdef _NEURON_TRACE_MODE
void NeuronTracer::tracePSPImpact(EDNeuron* n)
{
	#ifdef _MEMBRANE_POTENTIAL_TRACE_MODE
	if (membraneFile->isOpen())
	{
		membraneFile->addIndexedLineData(n->index,n->lastTimeOfPSPImpact,n->membranePotential);
	}
	else
	{
		cerr << "Warning, membraneFile should be open" << endl;
	}
	#endif
	#ifdef _THRESHOLD_TRACE_MODE
	if (thresholdFile->isOpen())
	{
		thresholdFile->addIndexedLineData(n->index,n->lastTimeOfPSPImpact,n->thresholdPotential);
	}
	else
	{
		cerr << "Warning, thresholdFile should be open" << endl;
	}
	#endif
}

void NeuronTracer::traceSpikeEmission(EDNeuron* n)
{
	#ifdef _MEMBRANE_POTENTIAL_TRACE_MODE
	if (membraneFile->isOpen())
	{
		membraneFile->addIndexedLineData(n->index,n->lastTimeOfFiring,n->membranePotential);
	}
	else
	{
		cerr << "Warning, membraneFile should be open" << endl;
	}
	#endif
	#ifdef _THRESHOLD_TRACE_MODE
	if (thresholdFile->isOpen())
	{
		thresholdFile->addIndexedLineData(n->index,n->lastTimeOfFiring,n->thresholdPotential);
	}
	else
	{
		cerr << "Warning, thresholdFile should be open" << endl;
	}
	#endif
}
#endif

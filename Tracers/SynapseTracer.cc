// SynapseTracer.cc

// Local Includes
#include "SynapseTracer.h"

/****************************************************************************************************************************************/
/************************************************* Methodes de la classe SynapseTracer **************************************************/
/****************************************************************************************************************************************/
//SynapseTracer* SynapseTracer::theSynapseTracer=0;

SynapseTracer::SynapseTracer()
{
#ifdef _TEST
	cout << "SynapseTracer" << endl;
#endif

#ifdef _WEIGHT_TRACE_MODE
	weightFile = new DataFile();
#endif
	openTracer();
}

SynapseTracer::SynapseTracer(IndexedObject* io): Tracer(io)
{
#ifdef _TEST
	cout << "SynapseTracer" << endl;
#endif

#ifdef _WEIGHT_TRACE_MODE
	weightFile = new DataFile();
#endif
	openTracer();
}

SynapseTracer::~SynapseTracer()
{
	cout << "~SynapseTracer" << endl;

	runTracer();
	closeTracer();

#ifdef _WEIGHT_TRACE_MODE
	delete(weightFile);
#endif
}

void SynapseTracer::openTracer()
{
#ifdef _WEIGHT_TRACE_MODE
	if (weightFile)
	{
		ostringstream oss;
		oss << WEIGHT_FILENAME << (string) getStringIndex() << (Handler*) this;
		weightFile->openDataFile(oss.str());
	}
	else
	{
		cerr << "Warning, weightFile should be inited" << endl;
	}
#endif
}

void SynapseTracer::closeTracer()
{
#ifdef _WEIGHT_TRACE_MODE
	if (weightFile->isOpen())
	{
		weightFile->closeFile();
	}
	else
	{
		cerr << "Warning, weightFile should be open" << endl;
	}
#endif
}

void SynapseTracer::runTracer()
{
#ifdef _WEIGHT_TRACE_MODE
	if (weightFile->isOpen())
	{
		weightFile->formatFile();
	}
	else
	{
		cerr << "Warning, weightFile should be open" << endl;
	}
#endif
}

/****************************************************************************************************************************************/
/************************************************** Methodes statiques ******************************************************************/
/****************************************************************************************************************************************/
#ifdef _SYNAPSE_TRACE_MODE

/****************************************************************************************************************************************/
/************************************************** Methodes de traces ******************************************************************/
/****************************************************************************************************************************************/

void SynapseTracer::tracePreWeight(EDSynapse* s)
{
	#ifdef _WEIGHT_TRACE_MODE
	if (weightFile->isOpen())
	{
		weightFile->addIndexedLineData(s->index,s->lastTimeOfPreSpike,s->weight);
	}
	else
	{
		cerr << "Warning, weightFile should be open" << endl;
	}
	#endif
}

void SynapseTracer::tracePostWeight(EDSynapse* s)
{
	#ifdef _WEIGHT_TRACE_MODE
	if (weightFile->isOpen())
	{
		weightFile->addIndexedLineData(s->index+EDSynapse::nbSynapses,s->lastTimeOfPostSpike,s->weight);
	}
	else
	{
		cerr << "Warning, weightFile should be open" << endl;
	}
	#endif
}
#endif

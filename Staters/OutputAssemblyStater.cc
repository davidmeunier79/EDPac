// OutputAssemblyStater.cc

// Local Includes
#include "OutputAssemblyStater.h"

/****************************************************************************************************************************************/
/************************************************* Methodes de la classe OutputAssemblyStater ************************************************/
/****************************************************************************************************************************************/

OutputAssemblyStater::OutputAssemblyStater()
{
	outputSpikeFile = new DataFile();
	neuronOutputGnuplotFile = new GnuplotFile();

	openStater();
}

OutputAssemblyStater::OutputAssemblyStater(IndexedObject* io): Stater(io)
{
	outputSpikeFile = new DataFile();
	neuronOutputGnuplotFile = new GnuplotFile();

	openStater();
}

OutputAssemblyStater::~OutputAssemblyStater()
{
	closeStater();
	
	delete(outputSpikeFile);
	delete(neuronOutputGnuplotFile);
}

void OutputAssemblyStater::openTracer()
{
	if (outputSpikeFile)
	{
		outputSpikeFile->openDataFile("OutputSpikes"+(string) getStringIndex());
	}
	else
	{
		cerr << "Warning, outputSpikeFile is not inited" << endl;
	}
}

void OutputAssemblyStater::closeTracer()
{
	if (outputSpikeFile->isOpen())
	{
		outputSpikeFile->closeFile();
	}
	else
	{
		cerr << "Warning, outputSpikeFile is not open" << endl;
	}
}

void OutputAssemblyStater::openGrapher()
{
	if (neuronOutputGnuplotFile)
	{
		neuronOutputGnuplotFile->openGnuplotFile("OutputAssemblyStat");
	}
	else
	{
		cerr << "Warning, neuronOutputGnuplotFile is not inited" << endl;
	}
}

void OutputAssemblyStater::runGrapher()
{
	if (neuronOutputGnuplotFile)
	{
		neuronOutputGnuplotFile->systemFile();
	}
	else
	{
		cerr << "Warning, neuronOutputGnuplotFile is not inited" << endl;
	}
}

void OutputAssemblyStater::closeGrapher()
{
	if (neuronOutputGnuplotFile->isOpen())
	{
		neuronOutputGnuplotFile->closeFile();
	}
	else
	{
		cerr << "Warning, neuronOutputGnuplotFile is not open" << endl;
	}
}

/****************************************************************************************************************************************/
/******************************************************* Methodes de stats **************************************************************/
/****************************************************************************************************************************************/
#ifdef _ASSEMBLY_STAT_MODE
void OutputAssemblyStater::traceSpikeEmission(int neuronIndex, int timeOfFiring)
{
	if (outputSpikeFile->isOpen())
	{
		outputSpikeFile->addDotData(neuronIndex, timeOfFiring);
	}
}

void OutputAssemblyStater::graph()
{
#ifdef _TEST_STAT
	cout << "*** OutputAssemblyStater *** Graphing Neuron stats for topo " << getTopoIndex() << endl;
#endif
	ostringstream oss;
	oss << "_Generation" << getEvoIndex();
	oss << "_Pacman" << getTopoIndex();
	oss << "_Run" << getEvalIndex();
	oss << "_Test" << getTestIndex();
	oss << "_OutputAssembly" << (string) getStringIndex();

	// Digramme global de spikes
	neuronOutputGnuplotFile->setOutput("OutputSpikes"+oss.str());
	neuronOutputGnuplotFile->setTitle("OutputSpikes"+(string) getStringIndex());
	neuronOutputGnuplotFile->plotDots("OutputSpikes"+(string) getStringIndex());
}
#endif

// InputAssemblyStater.cc

// Local Includes
#include "InputAssemblyStater.h"

/****************************************************************************************************************************************/
/************************************************* Methodes de la classe InputAssemblyStater ************************************************/
/****************************************************************************************************************************************/

InputAssemblyStater::InputAssemblyStater()
{
	inputSpikeFile = new DataFile();
	neuronInputGnuplotFile = new GnuplotFile();

	openStater();
}

InputAssemblyStater::InputAssemblyStater(IndexedObject* io): Stater(io)
{
	inputSpikeFile = new DataFile();
	neuronInputGnuplotFile = new GnuplotFile();

	openStater();
}


InputAssemblyStater::~InputAssemblyStater()
{
	closeStater();

	delete(inputSpikeFile);
	delete(neuronInputGnuplotFile);
}

void InputAssemblyStater::openTracer()
{
	if (inputSpikeFile)
	{
		inputSpikeFile->openDataFile("InputSpikes"+(string) getStringIndex());
	}
	else
	{
		cerr << "Warning, inputSpikeFile is not inited" << endl;
	}
}

void InputAssemblyStater::closeTracer()
{
	if (inputSpikeFile->isOpen())
	{
		inputSpikeFile->closeFile();
	}
	else
	{
		cerr << "Warning, inputSpikeFile is not open" << endl;
	}
}

void InputAssemblyStater::openGrapher()
{
	if (neuronInputGnuplotFile)
	{
		neuronInputGnuplotFile->openGnuplotFile("InputAssemblyStat"+(string) getStringIndex());
	}
	else
	{
		cerr << "Warning, neuronInputGnuplotFile is not inited" << endl;
	}
}

void InputAssemblyStater::runGrapher()
{
	if (neuronInputGnuplotFile)
	{
		neuronInputGnuplotFile->systemFile();
	}
	else
	{
		cerr << "Warning, neuronInputGnuplotFile is not open" << endl;
	}
}

void InputAssemblyStater::closeGrapher()
{
	if (neuronInputGnuplotFile->isOpen())
	{
		neuronInputGnuplotFile->closeFile();
	}
	else
	{
		cerr << "Warning, neuronInputGnuplotFile is not open" << endl;
	}
}

/****************************************************************************************************************************************/
/******************************************************* Methodes de stats **************************************************************/
/****************************************************************************************************************************************/

#ifdef _ASSEMBLY_STAT_MODE
void InputAssemblyStater::traceSpikeEmission(int neuronIndex, int timeOfFiring)
{
	if (inputSpikeFile->isOpen())
	{
		inputSpikeFile->addDotData(neuronIndex, timeOfFiring);
	}
	else
	{
		cerr << "Warning, inputSpikeFile is not open" << endl;
	}
}

void InputAssemblyStater::graph()
{
	#ifdef _TEST_STAT
	cout << "*** InputAssemblyStater *** Graphing Neuron stats for topo " << getTopoIndex() << endl;
	#endif
	
	ostringstream oss;
	oss << "_Generation" << getEvoIndex();
	oss << "_Pacman" << getTopoIndex();
	oss << "_Run" << getEvalIndex();
	oss << "_Test" << getTestIndex();
	oss << "_InputAssembly" << (string) getStringIndex();

	// Digramme global de spikes
	neuronInputGnuplotFile->setOutput("InputSpikes"+oss.str());
	neuronInputGnuplotFile->setTitle("InputSpikes"+(string) getStringIndex());
	neuronInputGnuplotFile->plotDots("InputSpikes"+(string) getStringIndex());
}
#endif

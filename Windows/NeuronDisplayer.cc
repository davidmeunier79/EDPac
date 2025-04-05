// NeuronDisplayer.cc

// Local Includes
#include "NeuronDisplayer.h"

/****************************************************************************************************************************************/
/************************************************* Methodes de la classe NeuronDisplayer **********************************************/
/****************************************************************************************************************************************/

NeuronDisplayer::NeuronDisplayer()
{
#ifdef _GRAPHICAL_DISPLAY_MODE
	topoWindow = new Fenetre();

	topoWindow->setTitre("Network Topology");
	topoWindow->setPosition(0,400);
	
	//topoWindow->setDimensions((2+SQRT_NB_ASSEMBLIES)*MARGIN+VISIO_GRAPHICAL_SIZE+(SQRT_NB_ASSEMBLIES+1)*ASSEMBLY_GRAPHICAL_SIZE,(2+NB_INPUT_ASSEMBLIES-1)*MARGIN+NB_INPUT_ASSEMBLIES*VISIO_GRAPHICAL_SIZE);
	
	#ifdef _CONDITIONNING_MODE
	if (((2+SQRT_NB_ASSEMBLIES-1)*MARGIN+VISIO_GRAPHICAL_SIZE+(SQRT_NB_ASSEMBLIES+1)*ASSEMBLY_GRAPHICAL_SIZE < 480) && ((2+NB_INPUT_ASSEMBLIES-1)*MARGIN+NB_VISIO_INPUTS*VISIO_GRAPHICAL_SIZE+AUDIO_GRAPHICAL_SIZE*NB_AUDIO_INPUTS+NB_CONDITIONNING_INPUTS*CONDITIONNING_GRAPHICAL_SIZE < 480))
	{
		topoWindow->setDimensions(480,480);
	}
	else
	{
		cerr << "Warning, unable to open topoWindow with size > 480" << endl;
	}
	//topoWindow->setDimensions((2+SQRT_NB_ASSEMBLIES)*MARGIN+VISIO_GRAPHICAL_SIZE+(SQRT_NB_ASSEMBLIES+1)*ASSEMBLY_GRAPHICAL_SIZE,
	//(2+NB_INPUT_ASSEMBLIES)*MARGIN+NB_VISIO_INPUTS*VISIO_GRAPHICAL_SIZE+AUDIO_GRAPHICAL_SIZE*NB_AUDIO_INPUTS+NB_CONDITIONNING_INPUTS*CONDITIONNING_GRAPHICAL_SIZE);
	#else
	
	if (((2+SQRT_NB_ASSEMBLIES)*MARGIN+VISIO_GRAPHICAL_SIZE+(SQRT_NB_ASSEMBLIES+1)*ASSEMBLY_GRAPHICAL_SIZE < 480) && ((2+NB_INPUT_ASSEMBLIES-1)*MARGIN+NB_VISIO_INPUTS*VISIO_GRAPHICAL_SIZE+AUDIO_GRAPHICAL_SIZE*NB_AUDIO_INPUTS) < 480)
	{
		topoWindow->setDimensions(480,480);
	}
	else
	{
		cerr << "Warning, unable to open topoWindow with size > 480" << endl;
	}
	//topoWindow->setDimensions((2+SQRT_NB_ASSEMBLIES)*MARGIN+VISIO_GRAPHICAL_SIZE+(SQRT_NB_ASSEMBLIES+1)*ASSEMBLY_GRAPHICAL_SIZE,
	//(2+NB_INPUT_ASSEMBLIES)*MARGIN+NB_VISIO_INPUTS*VISIO_GRAPHICAL_SIZE+AUDIO_GRAPHICAL_SIZE*NB_AUDIO_INPUTS);
	#endif
#endif
}

NeuronDisplayer::~NeuronDisplayer()
{
#ifdef _GRAPHICAL_DISPLAY_MODE
	delete(topoWindow);
#endif
}

#ifdef _GRAPHICAL_DISPLAY_MODE
void NeuronDisplayer::display(Neuron* n)
{
	int posNeuX;
	int posNeuY;

	int posAssX;
	int posAssY;

	//cout << "In display for neuron index " << n->getIndex() << " ";

	// Neurone caché
	if (0<= n->getIndex() && n->getIndex() < NB_HIDDEN_NEURONS)
	{
		//cout << "Hidden neuron index" << endl;

		int assemblyIndex = n->getIndex()/(ASSEMBLY_GRAPHICAL_SIZE*ASSEMBLY_GRAPHICAL_SIZE);
		int relativeIndex = n->getIndex()%(ASSEMBLY_GRAPHICAL_SIZE*ASSEMBLY_GRAPHICAL_SIZE);

		posAssX = 1+assemblyIndex%SQRT_NB_ASSEMBLIES;
		posAssY = assemblyIndex/SQRT_NB_ASSEMBLIES;

		posNeuX = relativeIndex/ASSEMBLY_GRAPHICAL_SIZE;
		posNeuY = relativeIndex%ASSEMBLY_GRAPHICAL_SIZE;

		topoWindow->colorierZone(MARGIN-ASSEMBLY_GRAPHICAL_SIZE/2+posAssX*MARGIN+posNeuX,MARGIN-ASSEMBLY_GRAPHICAL_SIZE/2+posAssY*MARGIN+posNeuY,1,1,"jaune");

	}
	// Neurone input visuel
	else if (NB_HIDDEN_NEURONS <= n->getIndex() && n->getIndex() <NB_HIDDEN_NEURONS+NB_VISIO_NEURONS)
	{
		//cout << "Visual neuron index" << endl;

		int assemblyIndex = (n->getIndex()-NB_HIDDEN_NEURONS)/(VISIO_GRAPHICAL_SIZE*VISIO_GRAPHICAL_SIZE);
		int relativeIndex = (n->getIndex()-NB_HIDDEN_NEURONS)%(VISIO_GRAPHICAL_SIZE*VISIO_GRAPHICAL_SIZE);

		posAssX=1+SQRT_NB_ASSEMBLIES;
		posAssY=assemblyIndex;

		posNeuX = relativeIndex/VISIO_GRAPHICAL_SIZE;
		posNeuY = relativeIndex%VISIO_GRAPHICAL_SIZE;

		topoWindow->colorierZone(MARGIN-VISIO_GRAPHICAL_SIZE/2+posAssX*MARGIN+posNeuX,MARGIN-VISIO_GRAPHICAL_SIZE/2+posAssY*MARGIN+posNeuY,1,1,"jaune");
	}
	// Neurone input auditif
	else if (NB_HIDDEN_NEURONS+NB_VISIO_NEURONS <= n->getIndex() && n->getIndex() <NB_HIDDEN_NEURONS+NB_VISIO_NEURONS+NB_AUDIO_NEURONS)
	{
		//cout << "Audio neuron index" << endl;

		int assemblyIndex = (n->getIndex()-NB_HIDDEN_NEURONS-NB_VISIO_NEURONS)/(AUDIO_GRAPHICAL_SIZE*AUDIO_GRAPHICAL_SIZE);
		int relativeIndex = (n->getIndex()-NB_HIDDEN_NEURONS-NB_VISIO_NEURONS)%(AUDIO_GRAPHICAL_SIZE*AUDIO_GRAPHICAL_SIZE);

		posAssX=1+SQRT_NB_ASSEMBLIES;
		posAssY=NB_VISIO_INPUTS+assemblyIndex;

		posNeuX = relativeIndex/AUDIO_GRAPHICAL_SIZE;
		posNeuY = relativeIndex%AUDIO_GRAPHICAL_SIZE;

		topoWindow->colorierZone(MARGIN-AUDIO_GRAPHICAL_SIZE/2+posAssX*MARGIN+posNeuX,MARGIN-AUDIO_GRAPHICAL_SIZE/2+posAssY*MARGIN+posNeuY,1,1,"jaune");
	}
	// Neurone input de conditionnement
	else if (NB_HIDDEN_NEURONS+NB_VISIO_NEURONS+NB_AUDIO_NEURONS <= n->getIndex() && n->getIndex() <NB_HIDDEN_NEURONS+NB_VISIO_NEURONS+NB_AUDIO_NEURONS+NB_CONDITIONNING_NEURONS)
	{
		//cout << "Audio neuron index" << endl;

		int assemblyIndex = (n->getIndex()-NB_HIDDEN_NEURONS-NB_VISIO_NEURONS-NB_AUDIO_NEURONS)/(CONDITIONNING_GRAPHICAL_SIZE*CONDITIONNING_GRAPHICAL_SIZE);
		int relativeIndex = (n->getIndex()-NB_HIDDEN_NEURONS-NB_VISIO_NEURONS-NB_AUDIO_NEURONS)%(CONDITIONNING_GRAPHICAL_SIZE*CONDITIONNING_GRAPHICAL_SIZE);

		posAssX=1+SQRT_NB_ASSEMBLIES;
		posAssY=NB_VISIO_INPUTS+NB_AUDIO_INPUTS+assemblyIndex;

		posNeuX = relativeIndex/CONDITIONNING_GRAPHICAL_SIZE;
		posNeuY = relativeIndex%CONDITIONNING_GRAPHICAL_SIZE;

		topoWindow->colorierZone(MARGIN-CONDITIONNING_GRAPHICAL_SIZE/2+posAssX*MARGIN+posNeuX,MARGIN-CONDITIONNING_GRAPHICAL_SIZE/2+posAssY*MARGIN+posNeuY,1,1,"jaune");
	}
	// Neurone output
	else if(NB_HIDDEN_NEURONS+NB_VISIO_NEURONS+NB_AUDIO_NEURONS+NB_CONDITIONNING_NEURONS <= n->getIndex() && n->getIndex() < NB_HIDDEN_NEURONS+NB_VISIO_NEURONS+NB_AUDIO_NEURONS+NB_CONDITIONNING_NEURONS+NB_OUTPUTS_NEURONS)
	{
		//cout << "Motor neuron index" << endl;

		int assemblyIndex = (n->getIndex()-NB_HIDDEN_NEURONS-NB_VISIO_NEURONS-NB_AUDIO_NEURONS-NB_CONDITIONNING_NEURONS)/(MOTOR_GRAPHICAL_SIZE*MOTOR_GRAPHICAL_SIZE);
		int relativeIndex = (n->getIndex()-NB_HIDDEN_NEURONS-NB_VISIO_NEURONS-NB_AUDIO_NEURONS-NB_CONDITIONNING_NEURONS)%(MOTOR_GRAPHICAL_SIZE*MOTOR_GRAPHICAL_SIZE);

		posAssX=0;
		posAssY=assemblyIndex;

		posNeuX = relativeIndex/MOTOR_GRAPHICAL_SIZE;
		posNeuY = relativeIndex%MOTOR_GRAPHICAL_SIZE;

		topoWindow->colorierZone(MARGIN-MOTOR_GRAPHICAL_SIZE/2+posAssX*MARGIN+posNeuX,MARGIN-MOTOR_GRAPHICAL_SIZE/2+posAssY*MARGIN+posNeuY,1,1,"jaune");
	}
	else
	{
		cerr << "Warning, wrong neuron getIndex() " << n->getIndex() << ", should be < " << NB_HIDDEN_NEURONS+NB_VISIO_NEURONS+NB_AUDIO_NEURONS+NB_OUTPUTS_NEURONS+NB_CONDITIONNING_NEURONS << endl;
		return;
	}
}
#endif

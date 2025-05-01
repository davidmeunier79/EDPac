// MPIModule.cc

// Local Includes
#include "MPIModule.h"

/****************************************************************************************************************************************/
/***************************************************** Methodes de la classe MPIModule **************************************************/
/****************************************************************************************************************************************/

MPIModule::MPIModule()
{
    nbInputBuffers = 0;
    nbOutputBuffers = 0;

    inputBuffers = nullptr;
    outputBuffers = nullptr;
}

MPIModule::MPIModule(MPIModule& MPIm)
{
    nbInputBuffers = MPIm.nbInputBuffers;
    nbOutputBuffers = MPIm.nbOutputBuffers;

    inputBuffers = new InputBuffer*[nbInputBuffers];
    outputBuffers = new OutputBuffer*[nbOutputBuffers];
}

MPIModule::MPIModule(int newNbInputBuffers, int newNbOutputBuffers)
{
    nbInputBuffers = newNbInputBuffers;
    nbOutputBuffers = newNbOutputBuffers;

    inputBuffers = new InputBuffer*[nbInputBuffers];
    outputBuffers = new OutputBuffer*[nbOutputBuffers];
}

MPIModule::~MPIModule()
{
    delete[] inputBuffers;
    delete[] outputBuffers;
}

void MPIModule::initModule()
{
    for (int i = 0; i < nbInputBuffers; i++)
    {
        inputBuffers[i]->initReceiveInput();
    }

    for (int i = 0; i < nbOutputBuffers; i++)
    {
        outputBuffers[i]->initSendOutput();
    }
}

void MPIModule::freeModule()
{
    for (int i = 0; i < nbInputBuffers; i++)
    {
        inputBuffers[i]->freeRequest();
    }

    for (int i = 0; i < nbOutputBuffers; i++)
    {
        outputBuffers[i]->freeRequest();
    }
}

// Reception des inputs
bool MPIModule::testAnyInputs()
{
    bool any = false; // Placeholder logic
    return any;
}

void MPIModule::testAllInputs()
{
    for (int i = 0; i < nbInputBuffers; i++)
    {
        if (inputBuffers[i]->getFlag())
        {
            inputBuffers[i]->receiveInput();
        }
    }
}

// Envoi des outputs
void MPIModule::testAllOutputs()
{
    for (int i = 0; i < nbOutputBuffers; i++)
    {
        if (outputBuffers[i]->testActiveRequete())
        {
            outputBuffers[i]->setFlag(1);
        }
    }
}

bool MPIModule::isReady()
{
    return true; // Placeholder logic
}

void MPIModule::initInputBuffers()
{
    // Placeholder logic
}

void MPIModule::initOutputBuffers()
{
    // Placeholder logic
}

void MPIModule::receiveInputs()
{
    // Placeholder logic
}

void MPIModule::sendOutputs()
{
    // Placeholder logic
}

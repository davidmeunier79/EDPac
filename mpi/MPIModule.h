// MPIModule.h

#ifndef _MPI_MODULE_H
#define _MPI_MODULE_H

// Local Includes
#include "../Define.h"
#include "InputBuffer.h"
#include "OutputBuffer.h"

/******************************************************************************************************************************************/
/***************************************************** Classe MPIModule *****************************************************************/
/******************************************************************************************************************************************/

class MPIModule
{
protected:
    // Nombre de buffers dans le module
    int nbInputBuffers;
    int nbOutputBuffers;

    // Buffers du module
    InputBuffer** inputBuffers;
    OutputBuffer** outputBuffers;

public:
    MPIModule();
    MPIModule(MPIModule& MPIm);
    MPIModule(int newNbInputBuffers, int newNbOutputBuffers);

    ~MPIModule();

    void initModule();
    void freeModule();

    // Reception des inputs
    bool testAnyInputs();
    int testSomeInputs(int* recus);
    int waitSomeInputs(int* recus);
    bool waitAllInputs();

    // Envoi des outputs
    void testAllOutputs();
    void testAllInputs();

    int testSomeOutputs(int* sended);
    int waitSomeOutputs(int* sended);
    bool waitAllOutputs();

    // Utilisation d'active
    virtual bool isReady();

    // Initilisation des buffers
    virtual void initInputBuffers();
    virtual void initOutputBuffers();

    // Envoi et reception
    virtual void receiveInputs();
    virtual void sendOutputs();
};

#endif

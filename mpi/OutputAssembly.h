// OutputAssembly.h

#ifndef _OUTPUT_ASSEMBLY_H
#define _OUTPUT_ASSEMBLY_H

//#include <stdio.h>

// Local Includes
#include "../Define.h"
#include "../DefineMPI.h"
#include "../DefineEDNetwork.h"

#include "../DefineStater.h"

#include "../MPI/OutputBuffer.h"

#include "../EDNetwork/EDAssembly.h"

#include "../Interfaces/Statable.h"

class OutputAssembly;
#include "../Staters/OutputAssemblyStater.h"

/******************************************************************************************************************************************/
/***************************************************** Classe OutputAssembly *****************************************************************/
/******************************************************************************************************************************************/

class OutputAssembly : public EDAssembly, public OutputBuffer
{
public:
	
	static int nbOutputAssemblies;
	
	OutputAssembly();
	~OutputAssembly();

	OutputAssembly(int nbNeurons, int etiquette, int newTargetMPIId);

	virtual void initNeuronIndexs();

	
#ifdef _BLOCKING_MODE
	// Initialise le message de sortie 
	void initOutputIntegration();
	// Integration des outputs dans le réseau
	void integrateOutput(int time);
#endif


#ifndef _BLOCKING_MODE
	// Integration des outputs dans le réseau
	void integrateOutput(int time);
#endif

	virtual void initAssemblyFiles();
	virtual void endAssemblyFiles();

#ifdef _ASSEMBLY_STAT_MODE
	virtual void traceAssemblyFiles(int time);
	friend class OutputAssemblyStater;
#endif
	
};

#endif

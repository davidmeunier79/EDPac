// InputAssembly.h

#ifndef _INPUT_ASSEMBLY_H
#define _INPUT_ASSEMBLY_H

//#include <stdio.h>

// Local Includes
#include "../MPI/InputBuffer.h"

#include "../Define.h"
#include "../DefineMPI.h"
#include "../DefineEDNetwork.h"
#include "../DefinePhysiology.h"
#include "../DefineZoo.h"

#include "../DefineStater.h"

#include "../EDNetwork/EDAssembly.h"
//#include "../Interfaces/Statable.h"

class InputAssembly;
#include "../Staters/InputAssemblyStater.h"

/******************************************************************************************************************************************/
/*************************************************** Classe InputAssembly *****************************************************************/
/******************************************************************************************************************************************/

class InputAssembly : public EDAssembly, public InputBuffer
{

public:
	static int INPUT_RATIO;
	
	static int nbInputAssemblies;
	
	InputAssembly();
	InputAssembly(int newNbNeurons, int newTag, int newSourceMPIId);
	
	~InputAssembly();
	
	virtual void initNeuronIndexs();
	
	// Integration des inputs dans le réseau
	void integrateInput(int time,int timeRef);


	virtual void initAssemblyFiles();
	virtual void endAssemblyFiles();

#ifdef _ALL_TO_ALL_PROJECTION_MODE
	virtual void buildTotalPostExcitProjection(Assembly* postAssembly);
	virtual void buildTotalPostInhibProjection(Assembly* postAssembly);
#endif
	
#ifdef _FIXED_RATIO_PROJECTION_MODE
	virtual void buildPostExcitProjection(Assembly* postAssembly);
	virtual void buildPostInhibProjection(Assembly* postAssembly);
#endif

#ifdef _ASSEMBLY_STAT_MODE
	virtual void traceAssemblyFiles(int time);
	friend class InputAssemblyStater;
	
	#ifdef _NO_LINK_INPUT_STAT_MODE
	void freeAssemblyFiles();
	#endif
	
	#ifdef _LINK_INPUT_STAT_MODE
	void freeAssemblyFiles(NeuronStater* ns);
	#endif
#endif
};

#endif

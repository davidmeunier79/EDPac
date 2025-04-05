// EDAssembly.h

#ifndef _ED_Assembly_H
#define _ED_Assembly_H

//#include <stdio.h>
#include <vector>
using namespace std;

// Local Includes
#include "../Define.h"
#include "../DefineZoo.h"
#include "../DefinePhysiology.h"

#include "../DefineEDNetwork.h"

#include "../DefineStater.h"
#include "../DefineTracer.h"
#include "../DefineGrapher.h"

#include "../Interfaces/Tracable.h"
#include "../Interfaces/Graphable.h"
#include "../Interfaces/Statable.h"

#include "../MathTools/RandomMathTools.h"

#include "../Topology/Assembly.h"

#include "EDNeuron.h"
#include "EDExcitProjection.h"
#include "EDInhibProjection.h"

class EDAssembly;
#include "../Graphers/AssemblyGrapher.h"
#include "../Tracers/AssemblyTracer.h"
#include "../Staters/AssemblyStater.h"

/******************************************************************************************************************************************/
/******************************************************** Classe EDAssembly ***************************************************************/
/******************************************************************************************************************************************/

class EDAssembly : public Assembly, public Tracable, public Statable, public Graphable
{
	friend class TopologyDisplayer;
	friend class NetworkStater;

public:
	#ifdef _INHIB_RATIO_TEST_MODE
	static double INHIB_RATIO;
	#endif
	#ifdef _EXCIT_RATIO_TEST_MODE
	static double EXCIT_RATIO;
	#endif
	
	static int nbEDAssemblies;
	
	EDAssembly();
	EDAssembly(int nbNeurons);
	EDAssembly(int nbNeurons, int newAssemblyNature);

	~EDAssembly();

	void initAssembly(int nbNeurons);
	virtual void initNeuronIndexs();
	
	void reInitAssembly();
	void reInitEDAssembly();
	
	int getNbExcitPreProjections();
	int getNbInhibPreProjections();
	
	EDAssembly& operator=(const EDAssembly&);

#ifndef _TOPOLOGY_PROJECTION_MODE
	
	void buildSelfInhibition();
	
	#ifdef _ALL_TO_ALL_PROJECTION_MODE
	virtual void buildTotalPostExcitProjection(Assembly* postAssembly);
	virtual void buildTotalPostInhibProjection(Assembly* postAssembly);
	#endif
	
	#ifdef _FIXED_RATIO_PROJECTION_MODE
	virtual void buildFixedPostExcitProjection(Assembly* postAssembly);
	virtual void buildFixedPostInhibProjection(Assembly* postAssembly);
	#endif
	
	void destroyProjections();
#endif	

	void buildPostExcitProjection(Assembly* postAssembly);
	void buildPostInhibProjection(Assembly* postAssembly);
	
	friend std::ostream& operator<<(std::ostream&, EDAssembly&);

	friend class AssemblyStater;
	
#ifdef _ASSEMBLY_STAT_MODE
	virtual void traceAssemblyFiles(int time);

	#ifdef _GLOBAL_STAT_MODE
	virtual void initAssemblyFiles(NeuronStater* as);
	#else
	virtual void initAssemblyFiles();
	#endif

	#ifdef _PSP_LFP_STAT_MODE
	void initPSPotential();
	#endif
	
	virtual void endAssemblyFiles();

#endif
/*
#ifdef _NETWORK_STAT_MODE
	#ifdef _SMALL_WORLD_STAT_MODE
	void initNeighbours(AssemblyStater* as);
	#endif
#endif
*/	
#ifdef _NETWORK_GRAPH_MODE
	friend class AssemblyGrapher;

//	#ifdef _SINGLE_ASSEMBLY_GRAPH_MODE
	void initAssemblyGrapher(AssemblyGrapher* at);
//	#else

	void initAssemblyGrapher();
	//#endif
	void freeAssemblyGrapher();
#endif

#ifdef _NETWORK_TRACE_MODE
	friend class AssemblyTracer;

	//#ifdef _SINGLE_ASSEMBLY_TRACE_MODE
	void initAssemblyTracer();
	//#else
	void initAssemblyTracer(AssemblyTracer* at);
	//#endif

	void freeAssemblyTracer();
#endif
};

#endif

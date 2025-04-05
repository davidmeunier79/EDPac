// AssemblyStater.h

#ifndef _ASSEMBLY_STATER_H
#define _ASSEMBLY_STATER_H

// STL Includes

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Local Includes
#include "../Define.h"
#include "../DefineGA.h"
#include "../DefineZoo.h"
#include "../DefineEDNetwork.h"

#include "../DefineStater.h"
#include "../DefineTracer.h"
#include "../DefineGrapher.h"

#include "../Handlers/Counter.h"
#include "../Handlers/Accumulater.h"

#include "../Handlers/Distribution.h"
#include "../Handlers/LogDistribution.h"

#include "LoopStater.h"

class AssemblyStater;
#include "../EDNetwork/EDAssembly.h"

/******************************************************************************************************************************************/
/****************************************************** Classe AssemblyStater *************************************************************/
/******************************************************************************************************************************************/

class AssemblyStater : public LoopStater
{
protected:

	friend class EDAssembly;

	void openGrapher();
	void closeGrapher();
	void runGrapher();

	void openTracer();
	void closeTracer();
	
#ifdef _NETWORK_STAT_MODE
	#ifdef _CENTRALITY_STAT_MODE
	
	// Calcul d'intermediarité
	Accumulater* assemblyBetweenness;
	LogDistribution* assemblyBetweennessDistribution;
	
	double assemblyBetweennessRepartition[NB_ASSEMBLIES];
	
	// Calcul de centralité
	Accumulater* assemblyCentralBetweenness;
	LogDistribution* assemblyCentralBetweennessDistribution;
	
	double assemblyCentralBetweennessRepartition[NB_ASSEMBLIES];
	
	// Efficacité
	double assemblyEfficiency[NB_ASSEMBLIES][NB_ASSEMBLIES];
	
	Accumulater* assemblyLocalEfficiency;
	Distribution* assemblyLocalEfficiencyDistribution;
	
	Accumulater* assemblyGlobalEfficiency;
	Distribution* assemblyGlobalEfficiencyDistribution;
	
	// Efficacité global de chaque assemblee
	double assemblyGlobalEfficiencyRepartition[NB_ASSEMBLIES];
		
	// Efficacité local de chaque assemblee
	double assemblyLocalEfficiencyRepartition[NB_ASSEMBLIES];
	
	// ShortPath
	int assemblyShortPathRepartition[NB_ASSEMBLIES];
	int assemblyNoShortPathRepartition[NB_ASSEMBLIES];
	
	Distribution* assemblyShortPathLengthDistribution;
	Distribution* assemblyNbShortPathDistribution;
	
		#ifdef _EDGE_BETWEENNESS_STAT_MODE
	LogDistribution* assemblyEdgeBetweennessDistribution;
	double assemblyMaxEdgeBetweenness;
		
	int preAssemblyMaxEdgeBetweenness;
	int postAssemblyMaxEdgeBetweenness;			
		#endif
	#endif

	#ifdef _GSCC_STAT_MODE
	Distribution* SCComponentSizeDistribution;
	int maxSCComponentSize;
	
		#ifdef _INPUT_OUTPUT_GSCC_STAT_MODE
	Distribution* inputSCComponentSizeDistribution;
	Distribution* outputSCComponentSizeDistribution;
	
	double inputSCCFractionRepartition[NB_INPUT_ASSEMBLIES];
	double outputSCCFractionRepartition[NB_OUTPUT_ASSEMBLIES];
	
		#endif
	//MeanDistribution* assemblyDiameterSizeDistribution;
	#endif
	
	
	#ifdef _PROJECTION_STAT_MODE
	Counter* countProjections;
	
	Counter* countExcitProjections;
	Counter* countInhibProjections;

	// Self
	Counter* countExcitSelfProjections;
	Counter* countInhibSelfProjections;
	
	// Input
	Counter* countExcitInputProjections;
	Counter* countInhibInputProjections;

	// Output
	Counter* countExcitOutputProjections;
	Counter* countInhibOutputProjections;

	#endif
#endif

public:
	AssemblyStater();
	AssemblyStater(IndexedObject* io);

	virtual ~AssemblyStater();
	
	void flushCounters();
	void initCounters();
	
#ifdef _NETWORK_STAT_MODE
	#ifdef _CENTRALITY_STAT_MODE
	void computeAssemblyEfficiency();
	void computeAssemblyBetweenness();
	void computeAssemblyCentralBetweenness();
	
	void computeAssemblyShortPaths();
	
		#ifdef _EDGE_BETWEENNESS_STAT_MODE
	void computeAssemblyEdgeBetweennessDistribution();
	void computeAssemblyMaxEdgeBetweenness();

			#ifdef _GN_CLUSTER_STAT_MODE	
	double getAssemblyMaxEdgeBetweenness();
	int getPreAssemblyMaxEdgeBetweenness();
	int getPostAssemblyMaxEdgeBetweenness();
			#endif
		#endif
		
		#ifdef _CLUSTER_STAT_MODE
			#ifdef _EFFICIENCY_CLUSTER_STAT_MODE
	double getAssemblyGlobalEfficiency();
			#endif
		#endif
	#endif

	#ifdef _GSCC_STAT_MODE
	void initSCComponents();
	void computeSCComponents();
		
		#ifdef _INPUT_OUTPUT_GSCC_STAT_MODE
	void initInputOutputSCCCounters();
	
	void statInputSCC(EDAssembly* inputAssembly);
	void statOutputSCC(EDAssembly* outputAssembly);
		#endif
	#endif
	
	#ifdef _PROJECTION_STAT_MODE
	void initProjectionCounters();
	
	void statPostProjections(EDAssembly* postAssembly);
	void statPostProjection(Projection* curProjection); 
	#endif

#endif
	void graph();
	void trace();
};

#endif

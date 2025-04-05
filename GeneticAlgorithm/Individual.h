// Individual.h

#ifndef _INDIVIDUAL_H
#define _INDIVIDUAL_H

// C Includes
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

// Local Includes
#include "../Define.h"
#include "../DefineGA.h"
#include "../DefineZoo.h"

#include "../DefineTracer.h"
#include "../DefineGrapher.h"
//#include "../DefineStater.h"

#include "../Interfaces/Graphable.h"
#include "../Interfaces/Tracable.h"

#include "../Interfaces/EvalIndexable.h"

#include "../Handlers/Accumulater.h"

#include "Chromosome.h"

class Individual;
#include "../Graphers/IndividualGrapher.h"
#include "../Tracers/IndividualTracer.h"

/******************************************************************************************************************************************/
/****************************************************** Classe Individual *****************************************************************/
/******************************************************************************************************************************************/

class Individual : public Chromosome, public Tracable, public Graphable, public EvalIndexable
{
protected:

	
	int nbSteps;
	void initNbSteps();

#ifdef _RUN_MODE
	Accumulater* evalFitness;

	int nbMvtsTous;
	int nbMvtAvants;
	int nbPacgums;
	int nbPreys;

	int lifeLevel;
#endif

#ifdef _TEST_MODE
	Counter* countGoodBehaviour;
	Counter* countBadBehaviour;

#endif
public:

	// Constructeur / destructeur
	Individual();
	Individual(Individual&);
	virtual ~Individual();

#ifdef _TEST_MODE
	void statGoodBehaviour();
	void statBadBehaviour();

	void initIndividualScore();

	int getIndividualScore();
	int getGoodBehaviour();
	int getBadBehaviour();
#endif

#ifdef _RUN_MODE
	// Accesseurs du fitness
	void initEvalFitness();
	virtual void setEvalFitness();

	virtual void setFitness();
	double getFitness();

	int getNbSteps();
	int getNbMvtsTous();
	int getNbMvtAvants();
	int getNbPacgums();
	int getNbPreys();
	
	void initIndividualFiles();
	void endIndividualFiles();

#endif

	virtual void getPosition(int& posX,int& posY);

	// Operateur de clonage pure virtuel
	virtual Chromosome* clone();

#ifdef _INDIVIDUAL_TRACE_MODE
	friend class IndividualTracer;
#endif
#ifdef _INDIVIDUAL_GRAPH_MODE
	friend class IndividualGrapher;
#endif
};

#endif

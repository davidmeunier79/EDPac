// Chromsome.h

#ifndef _CHROMOSOME_H
#define _CHROMOSOME_H

// C Includes
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

// Local Includes
#include "../Define.h"
#include "../DefineGA.h"

#include "../Objets/Object.h"
#include "../Handlers/Accumulater.h"

#include "../Interfaces/EvoIndexable.h"
#include "../Interfaces/TopoIndexable.h"
#include "../Interfaces/Savable.h"

#include "Gene.h"

/******************************************************************************************************************************************/
/****************************************************** Classe Chromosome *****************************************************************/
/******************************************************************************************************************************************/

class Chromosome : public Object, public Savable, public EvoIndexable, public TopoIndexable
{
	void deleteTabGenes();

protected:

	vector<Gene*> tabGenes;

	Accumulater* fitness;

public:

	static int nbChromosomes;

	// Constructeur / destructeur
	Chromosome();
	Chromosome(Chromosome&);

	virtual ~Chromosome();

	// Operateur de clonage pure virtuel
	virtual Chromosome* clone()=0;
	
   	Chromosome& operator=(const Chromosome &);
	bool operator==(Chromosome &chr);
	
	// Accesseurs des genes
	int operator[](int i);
	vector<Gene*>::iterator returnGeneIt(int position);

	// Initialisation des genes
	void initChromosome();
#ifdef _CLUSTER_EVO_MODE
	void reInitChromosome();
#endif
	
	void initFitness();
	virtual double getFitness();

		// Méthodes de reproduction
	// Mutation
	void muteGene(int i);

	// Crossing-over
	vector<Gene*> copyGenes(vector<Gene*>::iterator firstGeneIt);
	void replaceGenes(vector<Gene*>::iterator firstGeneIt ,vector<Gene*> newGenes);

	// Méthodes amies (affichage + comparaison)
	friend ostream& operator<<(ostream& o, Chromosome* c);
	friend istream& operator>>(istream& i, Chromosome* c);

	//spécial Population::sortPopulation
	friend class CompareChromos;
};

class CompareChromos
{
public:
	//bool operator()(Chromosome& chr1, Chromosome& chr2);
	//bool operator()(const Chromosome* &, const Chromosome* &);
	bool operator()(Chromosome* , Chromosome*);
};

#endif

// Population.h
// d�crit le comportment d'ensemble des chromosomes, rassembl�s en une population

#ifndef _POPULATION_H
#define _POPULATION_H

// C Includes
//#include <stdio.h>
//#include <stdlib.h>
//#include <memory.h>
//#include <math.h>

// C++ include
#include <iostream>

/* Sp�cial somme fitness, pas tres propre, � modifier */
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

// Local Includes
#include "../Define.h"
#include "../DefineGA.h"

#include "../MathTools/RandomMathTools.h"

#include "../Objets/IndexedObject.h"

#include "../Interfaces/EvoIndexable.h"
#include "../Interfaces/TopoIndexable.h"

#include "Gene.h"
#include "Chromosome.h"

/******************************************************************************************/
/********************************** Classe Population *************************************/
/******************************************************************************************/

class Population : public EvoIndexable, public TopoIndexable
{

	void deleteTabChromosomes();

protected:
	vector<Chromosome*> tabChromosomes;
	
	void initTabChromosomes();
/*
	double meanFitness;
	double bestFitness;
*/
	ofstream sumFitness;
public:
	// Gestion m�moire
	Population();
	~Population();

	Population& operator=(const Population &pop);
	//void initPopulation();
	//void reInitPopulation();

	// M�thodes d'affichage fichier et console
	void openSumFitness();
	void closeSumFitness();

//	void print();
//	void printChromosomes();

	// Normoalisation du fitness
	//void normalisePopulation();

	// Tri de la population par fitness d�croissant
	void sortPopulation();

	// M�thodes de modification de la population
	virtual void evaluatePopulation();
	
#ifdef _CLUSTER_EVO_MODE
	virtual void clusterizeChromos();
#endif	

	void selectPopulation();
	void varyPopulation();

	vector<Chromosome*>::iterator returnChromoIt(int position);

//#ifdef _TRACE_MODE

	// Operateurs g�n�tiques
	void mutation(vector<Chromosome*>::iterator chromoIt, int j);
	void crossOver(vector<Chromosome*>::iterator chromoIt, int j);

	// Affichage
	
	friend ostream& operator<<(ostream& o,Population* pop);
	//friend istream& operator>>(istream& o,Population* pop);
};

#endif


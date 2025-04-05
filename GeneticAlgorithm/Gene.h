// Gene.h
// Définition des composants de base de l'algorithme génétique

#ifndef _GENE_H
#define _GENE_H

// C Includes
#include <iostream>
using namespace std;

// Local Includes
#include "../Define.h"
#include "../DefineGA.h"

#include "../Objets/IndexedObject.h"

#include "../MathTools/RandomMathTools.h"

/******************************************************************************************/
/************************************* Classe Gene ****************************************/
/******************************************************************************************/

class Gene: public IndexedObject
{
	static int nbGenes;

	int valueAllele;
	int valueMax;

public:

	Gene();
	Gene(int newValueMax);
	Gene(const Gene& g);
	//Gene(Gene* g);

	~Gene();

	Gene* clone();

	Gene& operator=(const Gene&);
	bool operator==(const Gene& g);
	bool operator!=(const Gene& g);
	// Valeur de l'allele
	int getValueAllele();

	// Modification aléatoire
	void initGene(int newValueMax);
	void mute();

	// Affichage console
	friend std::ostream& operator<<(std::ostream&, Gene*);
	friend std::istream& operator>>(std::istream&, Gene*);
};

#endif



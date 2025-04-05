// RandomMathTools.cc

// Local Includes
#include "RandomMathTools.h"

/****************************************************************************************************************************************/
/******************************************************* Génération de nombres aléatoires ***********************************************/
/****************************************************************************************************************************************/

// Initialisation du génrateur de nombre aléatoire
void initRandom()
{
	srandom(time(NULL));
	
	// Modif pour tirer la meme graine
	//srand(1234);
}

// Retourne une valeur aléatoire entre 0.0 et 1.0
double randomProb()
{

	int randomInt=random();
	double randomDouble=(double) randomInt/RAND_MAX;
	return randomDouble;
}

double randomUniform()
{
	RNG x;
	return x.uniform();
}

// Retourne soit la valeur +1.0, soit -1.0
double randomSign()
{
	int randomInt=random();
	double randomDouble=(double) randomInt/RAND_MAX;

	if (0.0<=randomDouble && randomDouble<0.5)
	{
		return 1.0;
	}
	else if (0.5<=randomDouble && randomDouble<1.0)
	{
		return -1.0;
	}
}

// Retourne soit 0.0, soit 1.0
double randomBool()
{
	int randomInt=random();
	double randomDouble=(double) randomInt/RAND_MAX;

	if (0.0<=randomDouble && randomDouble<0.5)
	{
		return 1.0;
	}
	else if (0.5<=randomDouble && randomDouble<1.0)
	{
		return 0.0;
	}
}

// Retourne un entier entre 0 et randMax-1
int randomInt(int randMax)
{
	double randomInt=(int) random();
	return static_cast<int>(randMax*(((double) randomInt)/RAND_MAX));
}

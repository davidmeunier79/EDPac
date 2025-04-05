// Accumulater.h

#ifndef _ACCUMULATER_H
#define _ACCUMULATER_H

#include <math.h>

// STL Includes
//#include <string>
//#include <fstream>
#include <iostream>
using namespace std;

// Local Includes
#include "../Objets/Object.h"
#include "Counter.h"


/******************************************************************************************************************************************/
/******************************************************* Classe Accumulater *************************************************************/
/******************************************************************************************************************************************/

class Accumulater: public Counter
{
	double best;
	double lowest;
	
	double accu;
	double accuSquare;
public:
	Accumulater();
	virtual ~Accumulater();

	void accumulate(double value);
	
	double getAccu();
	double getBest();
	double getLowest();
	
	void initAccu();
	
	double getMean();
	double getLogMean();
	
	double getMeanSquare();
	
	double getStd();
	
	double getStdMin();	
	double getStdMax();
	
	friend ostream& operator<<(ostream& o, Accumulater* co);
	friend istream& operator>>(istream& i, Accumulater* co);
};

#endif

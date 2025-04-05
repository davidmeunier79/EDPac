// Distribution.h

#ifndef _DISTRIBUTION_H
#define _DISTRIBUTION_H

// STL Includes
//#include <string>
//#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

// Local Includes
#include "Counter.h"

/******************************************************************************************************************************************/
/******************************************************* Classe Distribution *************************************************************/
/******************************************************************************************************************************************/

class Distribution : public Counter
{
protected:
	vector<Counter*> tabCounters;
	
public:
	
	friend class DistributionDataFile;
	
	Distribution();
	Distribution(int nbCounters);
	
	virtual ~Distribution();

	void initDistribution();
	
	void count(int index);
	void count(int index, int value);
	
	void countDistrib(Distribution* curDistrib);
	
	int getCount(int index);
	int getCumulCount(int index);

	int getMaxIndex();
	double getMeanIndex();
	
	double getProba(int index);
	double getCumulProba(int index);
	
	int getNbCounters();
	
	friend ostream& operator<<(ostream& o, Distribution* co);
};

#endif

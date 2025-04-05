// DistributionDataFile.h

#ifndef _DISTRIBUTION_DATA_FILE_H
#define _DISTRIBUTION_DATA_FILE_H

// Local Includes
#include "../Define.h"

#include "AccuDataFile.h"

#include "../Handlers/MeanDistribution.h"
#include "../Handlers/MeanLogDistribution.h"

// STL Includes
#include <sstream>
#include <string>
#include <fstream>
using namespace std;

/******************************************************************************************************************************************/
/**************************************************** Classe DistributionDataFile *********************************************************/
/******************************************************************************************************************************************/

class DistributionDataFile: public AccuDataFile
{
public:

	DistributionDataFile();
	virtual ~DistributionDataFile();
	
	void openRepartitionDataFile(string fileName);
	void openDistributionDataFile(string fileName);

	// Distribution
	void addDistribution(int index, Distribution* curLogDistrib);
	void addIndexedDistribution(int index, Distribution* curLogDistrib);

	void addCumulatedDistribution(int index, Distribution* curLogDistrib);
	void addCumulatedIndexedDistribution(int index, Distribution* curLogDistrib);

	// LogDistribution
	void addLogDistribution(int index, LogDistribution* curLogDistrib);
	void addIndexedLogDistribution(int index, LogDistribution* curLogDistrib);

	void addCumulatedLogDistribution(int index, LogDistribution* curLogDistrib);
	void addCumulatedIndexedLogDistribution(int index, LogDistribution* curLogDistrib);

	// MeanDistribution
	void addMeanDistribution(int index, MeanDistribution* curDistrib);
	void addIndexedMeanDistribution(int index, MeanDistribution* curDistrib);

	// MeanLogDistribution
	void addMeanLogDistribution(int index, MeanLogDistribution* curLogDistrib);
	void addIndexedMeanLogDistribution(int index, MeanLogDistribution* curLogDistrib);
	
	//void addIndexedOngoingMaxValue(int index, OngoingMeanLogDistribution* ongoingDistrib);
};

#endif


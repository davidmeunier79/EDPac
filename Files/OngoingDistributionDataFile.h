// OngoingDistributionDataFile.h

#ifndef _ONGOING_DISTRIBUTION_DATA_FILE_H
#define _ONGOING_DISTRIBUTION_DATA_FILE_H

// Local Includes
#include "../Define.h"
#include "../DefineStater.h"

#include "DataFile.h"
#include "AccuDataFile.h"
#include "DistributionDataFile.h"

#include "../Handlers/OngoingDistribution.h"
#include "../Handlers/OngoingMeanDistribution.h"
#include "../Handlers/OngoingMeanLogDistribution.h"

// STL Includes
#include <sstream>
#include <string>
#include <fstream>
using namespace std;

/******************************************************************************************************************************************/
/************************************************ Classe OngoingDistributionDataFile ******************************************************/
/******************************************************************************************************************************************/

class OngoingDistributionDataFile: public DistributionDataFile
{
	DistributionDataFile* cumulatedDistributionDataFile;
/*
	AccuDataFile* meanDataFile;
	DataFile* maxDataFile;
*/
public:

	OngoingDistributionDataFile();
	virtual ~OngoingDistributionDataFile();

	void openOngoingDistributionDataFile(string fileName);
	void closeOngoingDistributionDataFile();

	void addOngoingDistribution(int index, OngoingDistribution* curDistrib);
	void addOngoingMeanDistribution(int index, OngoingMeanDistribution* curDistrib);
	void addOngoingMeanLogDistribution(int index, OngoingMeanLogDistribution* curLogDistrib);

};

#endif


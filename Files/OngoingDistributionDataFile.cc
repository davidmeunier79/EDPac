// OngoingDistributionDataFile.cc

// Local Includes
#include "OngoingDistributionDataFile.h"

/****************************************************************************************************************************************/
/********************************************** Methodes de la classe OngoingDistributionDataFile ***************************************/
/****************************************************************************************************************************************/

OngoingDistributionDataFile::OngoingDistributionDataFile()
{
	
	#ifdef _ONGOING_CUMUL_STAT_MODE
	cumulatedDistributionDataFile = new DistributionDataFile();
	#endif
}

OngoingDistributionDataFile::~OngoingDistributionDataFile()
{
	
	#ifdef _ONGOING_CUMUL_STAT_MODE
	delete(cumulatedDistributionDataFile);
	#endif
}

void OngoingDistributionDataFile::openOngoingDistributionDataFile(string fileName)
{
	
	#ifdef _ONGOING_CUMUL_STAT_MODE
	cumulatedDistributionDataFile->openDistributionDataFile("OngoingCumulated"+fileName);
	#endif
	
	openDistributionDataFile("Ongoing"+fileName);
}

void OngoingDistributionDataFile::closeOngoingDistributionDataFile()
{
	
	#ifdef _ONGOING_CUMUL_STAT_MODE
	cumulatedDistributionDataFile->closeFile();
	#endif
	
	closeFile();
}

void OngoingDistributionDataFile::addOngoingDistribution(int index, OngoingDistribution* curDistrib)
{
	vector<Distribution*>::iterator it = ((OngoingDistribution*) curDistrib)->tabDistributions.begin();
	vector<Distribution*>::iterator end = ((OngoingDistribution*) curDistrib)->tabDistributions.end();

	int count = 0;

	while (it != end)
	{
		addDistribution(count,(Distribution*) *it);
		count++;
		it++;
	}

	addDataSeparator();
	
	#ifdef _ONGOING_CUMUL_STAT_MODE
	cumulatedDistributionDataFile->addIndexedMeanDistribution(index, (MeanDistribution*) curDistrib->getCumulatedDistribution());
	#endif
}

void OngoingDistributionDataFile::addOngoingMeanDistribution(int index, OngoingMeanDistribution* curDistrib)
{
	vector<Distribution*>::iterator it = ((OngoingDistribution*) curDistrib)->tabDistributions.begin();
	vector<Distribution*>::iterator end = ((OngoingDistribution*) curDistrib)->tabDistributions.end();

	int count = 0;

	while (it != end)
	{
		addMeanDistribution(count,(MeanDistribution*) *it);
		count++;
		it++;
	}

	addDataSeparator();

	#ifdef _ONGOING_CUMUL_STAT_MODE
	cumulatedDistributionDataFile->addIndexedMeanDistribution(index, (MeanDistribution*) curDistrib->getCumulatedDistribution());
	#endif
	
}

void OngoingDistributionDataFile::addOngoingMeanLogDistribution(int index, OngoingMeanLogDistribution* curDistrib)
{
	vector<Distribution*>::iterator it = ((OngoingDistribution*) curDistrib)->tabDistributions.begin();
	vector<Distribution*>::iterator end = ((OngoingDistribution*) curDistrib)->tabDistributions.end();
	
	int count = 0;
	
	while (it != end)
	{
		addMeanLogDistribution(count,(MeanLogDistribution*) *it);
		count++;
		it++;
	}

	addDataSeparator();

	
	#ifdef _ONGOING_CUMUL_STAT_MODE
	cumulatedDistributionDataFile->addIndexedMeanLogDistribution(index, (MeanLogDistribution*) curDistrib->getCumulatedDistribution());
	#endif
}


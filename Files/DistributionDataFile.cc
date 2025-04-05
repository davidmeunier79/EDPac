// DistributionDataFile.cc

// Local Includes
#include "DistributionDataFile.h"

/****************************************************************************************************************************************/
/*************************************************** Methodes de la classe DistributionDataFile *****************************************/
/****************************************************************************************************************************************/

DistributionDataFile::DistributionDataFile()
{
}

DistributionDataFile::~DistributionDataFile()
{
}

void DistributionDataFile::openDistributionDataFile(string fileName)
{
	openDataFile("Indexed_Sorted_"+fileName+"DistributionStat");
}

void DistributionDataFile::openRepartitionDataFile(string fileName)
{
	openDataFile("Indexed_Sorted_"+fileName+"RepartitionStat");
}

void DistributionDataFile::addDistribution(int index, Distribution* curDistrib)
{
	vector<Counter*>::iterator it = curDistrib->tabCounters.begin();
	vector<Counter*>::iterator end = curDistrib->tabCounters.end();

	int count=0;

	while (it != end)
	{
		//addIndexedLineData(index,count,((Distribution*) curDistrib)->getProba(count));
		addIndexedLineData(index,count,((Counter*) *it)->getCounter());
		count++;
		it++;
	}
}

void DistributionDataFile::addIndexedDistribution(int index, Distribution* curDistrib)
{
	addDistribution(index, (Distribution*) curDistrib);
	
	addDataSeparator();
}


void DistributionDataFile::addCumulatedDistribution(int index, Distribution* curDistrib)
{
	vector<Counter*>::iterator it = curDistrib->tabCounters.begin();
	vector<Counter*>::iterator end = curDistrib->tabCounters.end();
		
	int count=0;
	
	while (it != end)
	{
		//addIndexedLineData(index,count,((Distribution*) curDistrib)->getCumulProba(count));
		addIndexedLineData(index,count,((Distribution*) curDistrib)->getCumulCount(count));
		count++;
		it++;
	}
}

void DistributionDataFile::addCumulatedIndexedDistribution(int index, Distribution* curDistrib)
{
	addCumulatedDistribution(index, (Distribution*) curDistrib);
	
	addDataSeparator();
}

void DistributionDataFile::addLogDistribution(int index, LogDistribution* curLogDistrib)
{
	vector<Counter*>::iterator it = curLogDistrib->tabCounters.begin();
	vector<Counter*>::iterator end = curLogDistrib->tabCounters.end();
		
	int count=0;
	
	while (it != end)
	{
		addIndexedLineData(index,(double) ((LogDistribution*) curLogDistrib)->getLogIndex(count),((LogDistribution*) curLogDistrib)->getLogProbaValue(count));
		count++;
		it++;
	}
}

void DistributionDataFile::addIndexedLogDistribution(int index, LogDistribution* curLogDistrib)
{
	addLogDistribution(index, (LogDistribution*) curLogDistrib);
	
	addDataSeparator();
}

void DistributionDataFile::addCumulatedLogDistribution(int index,  LogDistribution* curLogDistrib)
{
	vector<Counter*>::iterator it = curLogDistrib->tabCounters.begin();
	vector<Counter*>::iterator end = curLogDistrib->tabCounters.end();
		
	int count=0;
	
	while (it != end)
	{
		addIndexedLineData(index,(double) ((LogDistribution*) curLogDistrib)->getLogIndex(count),((LogDistribution*) curLogDistrib)->getLogCumulProbaValue(count));
		count++;
		it++;
	}
}

void DistributionDataFile::addCumulatedIndexedLogDistribution(int index,  LogDistribution* curLogDistrib)
{
	addCumulatedLogDistribution(index, (LogDistribution*) curLogDistrib);
	
	addDataSeparator();
}

void DistributionDataFile::addMeanDistribution(int index,  MeanDistribution* curDistrib)
{
	vector<Counter*>::iterator it = ((Distribution*) curDistrib)->tabCounters.begin();
	vector<Counter*>::iterator end = ((Distribution*) curDistrib)->tabCounters.end();

	int count=0;

	while (it != end)
	{
		//addIndexedLineData(index,count,((Accumulater*) *it)->getMean());
		addIndexedAccuLineData(index,count,*((Accumulater*) *it));
		count++;
		it++;
	}
}

void DistributionDataFile::addIndexedMeanDistribution(int index,  MeanDistribution* curDistrib)
{
	addMeanDistribution(index, (MeanDistribution*) curDistrib);
	
	addDataSeparator();
}

void DistributionDataFile::addMeanLogDistribution(int index,  MeanLogDistribution* curLogDistrib)
{
	vector<Counter*>::iterator it = ((Distribution*) curLogDistrib)->tabCounters.begin();
	vector<Counter*>::iterator end = ((Distribution*) curLogDistrib)->tabCounters.end();
		
	int count=0;
	
	while (it != end)
	{
		addIndexedLineData(index,(double) ((LogDistribution*) curLogDistrib)->getLogIndex(count),((Accumulater*) *it)->getLogMean());
		count++;
		it++;
	}
}

void DistributionDataFile::addIndexedMeanLogDistribution(int index,  MeanLogDistribution* curLogDistrib)
{
	addMeanLogDistribution(index, (MeanLogDistribution*) curLogDistrib);
	
	addDataSeparator();
}



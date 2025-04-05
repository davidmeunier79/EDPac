// AccuDataFile.cc

// Local Includes
#include "AccuDataFile.h"

/****************************************************************************************************************************************/
/******************************************************** Methodes de la classe AccuDataFile ************************************************/
/****************************************************************************************************************************************/

AccuDataFile::AccuDataFile()
{
#ifdef _ANOVA_STAT_MODE
	dataValueFile = new DataFile();
#endif
}

AccuDataFile::AccuDataFile(std::string dataFileName)
{
	openDataFile(dataFileName);
}


AccuDataFile::~AccuDataFile()
{
#ifdef _ANOVA_STAT_MODE	
	if (dataValueFile)
	{
		delete(dataValueFile);
	}
#endif
}

void AccuDataFile::openAccuDataFile(string fileName)
{
	openDataFile(fileName+"Stat");
	
#ifdef _ANOVA_STAT_MODE
	if (dataValueFile)
	{
		dataValueFile->openDataFile(fileName);
	}
#endif
}

void AccuDataFile::closeAccuDataFile()
{
	closeFile();
	
#ifdef _ANOVA_STAT_MODE
	if (dataValueFile->isOpen())
	{
		dataValueFile->closeFile();
	}
#endif
}

#ifdef _ANOVA_STAT_MODE
void AccuDataFile::addValueData(int index, int time, double value)
{
	if (dataValueFile->isOpen())
	{
		dataValueFile->addIndexedLineData((int) index, (int) time, (double) value);
	}
}

void AccuDataFile::addValueDataSeparator()
{
	if (dataValueFile->isOpen())
	{
		dataValueFile->addDataSeparator();
	}
}
#endif

void AccuDataFile::addIndexedAccuLineData(int index, int time, Accumulater& accu)
{
	file << index << " " << time << " " << accu.getMean() << " " << accu.getStdMin() << " " << accu.getStdMax() << " " << endl;

#ifdef _ANOVA_STAT_MODE
	addValueDataSeparator();
#endif
}

void AccuDataFile::addIndexedAccuLineData(int index, double valueTime, Accumulater& accu)
{
	file << index << " " << valueTime << " " << accu.getMean() << " " << accu.getStdMin() << " " << accu.getStdMax() << " " << endl;

#ifdef _ANOVA_STAT_MODE
	addValueDataSeparator();
#endif
}

void AccuDataFile::addAccuLineData(int time, Accumulater& accu)
{
	file << time << " " << accu.getMean() << " " << accu.getStdMin() << " " << accu.getStdMax() << " " << endl;
	
#ifdef _ANOVA_STAT_MODE
	addValueDataSeparator();
#endif
}


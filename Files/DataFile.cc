// DataFile.cc

// Local Includes
#include "DataFile.h"

string indexNeuronsAWKCommand="awk \'BEGIN{tmp=0} {if(tmp==$1) printf (\"%d %f %f %s\\n\",$1,$2,$3,$4); else printf (\"\\n\\n%d %f %f %s\\n\",$1,$2,$3,$4); tmp=$1}\'";

string indexIndexedValuesAWKCommand="awk \'BEGIN{tmp=0;count=0} {if(tmp==$1) {printf (\"%d %f %f\\n\",$1,count,$3);count++;} else {count=0;printf (\"\\n\\n%d %f %f\\n\",$1,count,$3); tmp=$1;count++;}}\'";

string indexValuesAWKCommand="awk \'BEGIN{tmp=0;count=0} {printf (\"%d %f\\n\",count,$2);count++;}\'";

string LFPAWKCommand="'BEGIN{tmpBin=0.0;potential=0.0;} {if (tmpBin<=$2 && $2 <= tmpBin+BIN_LENGTH) {potential+=1.0;} else {printf (\"%lf %lf\\n\",tmpBin,potential); potential=0.0; tmpBin=tmpBin+BIN_LENGTH;}}'";
/*
string LFPAssemblyAWKCommand="'BEGIN {tmpBin=0.0;potential=0.0;} {if (tmpBin<=$2 && $2 <= tmpBin+BIN_LENGTH && firstIndex<=$1 && $1<lastIndex) {potential+=1.0;} else {printf (\"%lf %lf\\n\",tmpBin,potential); potential=0.0; tmpBin=tmpBin+BIN_LENGTH;}}'";
*/
string phase3DAWKCommand="\'BEGIN{tmp1=-1.0;tmp2=-1.0;} {curVal=$2;if(tmp1!=-1.0 && tmp2!=-1.0){printf(\"%lf %lf %lf\\n\",curVal,tmp1,tmp2);}; tmp2=tmp1; tmp1=curVal;}\'";

string phase2DAWKCommand="\'BEGIN{tmp1=-1.0;} {curVal=$2;if(tmp1!=-1.0){printf(\"%lf %lf\\n\",curVal,tmp1);}; tmp1=curVal;}\'";

//#ifdef _TRAIN_GRAPH_MODE
string trainAWKCommand="'{printf (\"%d %f %f %s\\n\",$1,$2,($1*POTENTIAL_INTERVAL)+$3,$4)}'";
//#endif

/****************************************************************************************************************************************/
/******************************************************** Methodes de la classe DataFile ************************************************/
/****************************************************************************************************************************************/

DataFile::DataFile()
{
}

DataFile::DataFile(std::string dataFileName)
{
	openDataFile(dataFileName);
}


DataFile::~DataFile()
{
}

void DataFile::openDataFile(string newFileName)
{
	fileName=newFileName + ".dat";
	openOFile();
}

void DataFile::openIndexDataFile(int index)
{
	ostringstream oss;
	oss << index;
	string indexFileName = fileName + oss.str()+ ".dat";
	openOFile(indexFileName);
}
void DataFile::phase3DFile()
{
	ostringstream phaseFilename;
	phaseFilename << "Phase_3D_" << fileName << endl;

	ostringstream phaseCommand;
	phaseCommand << "awk " << phase3DAWKCommand << " " << fileName << ">" << phaseFilename.str() << endl;

	system(((string)phaseCommand.str()).c_str());
}

void DataFile::phase2DFile()
{
	ostringstream phaseFilename;
	phaseFilename << "Phase_2D_" << fileName << endl;

	ostringstream phaseCommand;
	phaseCommand << "awk " << phase2DAWKCommand << " " << fileName << ">" << phaseFilename.str() << endl;

	system(((string)phaseCommand.str()).c_str());
}

void DataFile::sortFile()
{
	ostringstream sortedFileName;
	sortedFileName << "Sorted_" << fileName;

	ostringstream sortCommand;
	sortCommand << "sort -g -s " << fileName << " > " << sortedFileName.str() << endl;
	//sortCommand << "sort -s " << fileName << " > " << sortedFileName.str() << endl;

	// Remplacement du nom
	fileName=sortedFileName.str();

	system(((string)sortCommand.str()).c_str());
}

void DataFile::sortIndexedValuesFile()
{
	ostringstream sortedFileName;
	sortedFileName << "Sorted3_" << fileName;

	ostringstream sortCommand;
	//sortCommand << "sort -n -s -nbk3 " << fileName << " > " << sortedFileName.str() << endl;
	//sortCommand << "sort -s -k 3n " << fileName << " > " << sortedFileName.str() << endl;
	//sortCommand << "sort -k 3n " << fileName << " > " << sortedFileName.str() << endl;
	//sortCommand << "sort -s -k 3 " << fileName << " > " << sortedFileName.str() << endl;
	sortCommand << "sort -s -k 3n " << fileName << " > " << sortedFileName.str() << endl;

	// Remplacement du nom
	fileName=sortedFileName.str();

	system(((string)sortCommand.str()).c_str());
}

void DataFile::sortValuesFile()
{
	ostringstream sortedFileName;
	sortedFileName << "Sorted2_" << fileName;

	ostringstream sortCommand;
	//sortCommand << "sort -n -s -nbk3 " << fileName << " > " << sortedFileName.str() << endl;
	//sortCommand << "sort -s -k 3n " << fileName << " > " << sortedFileName.str() << endl;
	//sortCommand << "sort -k 3n " << fileName << " > " << sortedFileName.str() << endl;
	//sortCommand << "sort -s -k 3 " << fileName << " > " << sortedFileName.str() << endl;
	sortCommand << "sort -s -k 2n " << fileName << " > " << sortedFileName.str() << endl;

	// Remplacement du nom
	fileName=sortedFileName.str();

	system(((string)sortCommand.str()).c_str());
}

void DataFile::indexFile()
{
	ostringstream indexedFileName;
	indexedFileName << "Indexed_" << fileName;

	ostringstream indexCommand;
	indexCommand << indexNeuronsAWKCommand << " " << fileName << " > " << indexedFileName.str();

	// Remeplacement du nom
	fileName=indexedFileName.str();
	system(((string)indexCommand.str()).c_str());
}

void DataFile::indexValuesFile()
{
	ostringstream indexedFileName;
	indexedFileName << "Indexed_" << fileName;

	ostringstream indexCommand;
	indexCommand << indexValuesAWKCommand << " " << fileName << " > " << indexedFileName.str();

	// Remeplacement du nom
	fileName=indexedFileName.str();
	system(((string)indexCommand.str()).c_str());
}

void DataFile::indexIndexedValuesFile()
{
	ostringstream indexedFileName;
	indexedFileName << "Indexed_" << fileName;

	ostringstream indexCommand;
	indexCommand << indexIndexedValuesAWKCommand << " " << fileName << " > " << indexedFileName.str();

	// Remeplacement du nom
	fileName=indexedFileName.str();
	system(((string)indexCommand.str()).c_str());
}

void DataFile::formatFile()
{
	sortFile();
	indexFile();
}

void DataFile::formatValuesFile()
{
	sortValuesFile();
	indexValuesFile();
}

void DataFile::formatIndexedValuesFile()
{
	sortIndexedValuesFile();
	sortFile();
	indexIndexedValuesFile();
}

void DataFile::addIndexedLineData(int index, int time, double value)
{
	file << index << " " << time << " " << value << endl;
}

void DataFile::addIndexedLineData(int index, double valueTime, double value)
{
	file << index << " " << valueTime << " " << value << endl;
}

void DataFile::addDotData(int index, int time)
{
	file << index << " " << time << " " << endl;
}

void DataFile::addLineData(int time, double value)
{
	file << time << " " << value << " " << endl;
}

void DataFile::addStringLine(string data)
{
	file << data << endl;
}

void DataFile::addDataSeparator()
{
	file << endl << endl;
}

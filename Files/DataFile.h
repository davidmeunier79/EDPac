// DataFile.h

#ifndef _DATA_FILE_H
#define _DATA_FILE_H

// Local Includes
#include "../Objets/FileObject.h"

// STL Includes
#include <sstream>
#include <string>
#include <fstream>
using namespace std;

/******************************************************************************************************************************************/
/********************************************************** Classe DataFile ***************************************************************/
/******************************************************************************************************************************************/

class DataFile: public FileObject
{
	void sortFile();
	void sortValuesFile();
	void sortIndexedValuesFile();
	
	void indexFile();
	void indexValuesFile();
	void indexIndexedValuesFile();
	
public:

	DataFile();
	DataFile(std::string fileName);

	virtual ~DataFile();

	void openDataFile(string fileName);
	
	void openIndexDataFile(int index);
	
	void addIndexedLineData(int index, int time, double value);
	void addIndexedLineData(int index, double valueTime, double value);
	
	void addLineData(int time, double value);
	void addDotData(int index, int time);
	
	void addStringLine(string data);

	void addDataSeparator();

	void formatFile();
	void formatValuesFile();
	void formatIndexedValuesFile();
	
	void meanFile();

	void phase3DFile();
	void phase2DFile();
};

#endif


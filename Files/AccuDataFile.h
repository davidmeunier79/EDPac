// AccuDataFile.h

#ifndef _ACCU_DATA_FILE_H
#define _ACCU_DATA_FILE_H

// Local Includes
#include "../Define.h"
#include "../DefineStater.h"

#include "../Files/DataFile.h"
#include "../Handlers/Accumulater.h"

// STL Includes
#include <sstream>
#include <string>
#include <fstream>
using namespace std;

/******************************************************************************************************************************************/
/******************************************************* Classe AccuDataFile ***************************************************************/
/******************************************************************************************************************************************/

class AccuDataFile: public DataFile
{

#ifdef _ANOVA_STAT_MODE
	DataFile* dataValueFile;
#endif

public:

#ifdef _ANOVA_STAT_MODE
	void addValueData(int index, int time, double value);
	void addValueDataSeparator();
#endif

	AccuDataFile();
	AccuDataFile(std::string fileName);

	virtual ~AccuDataFile();

	void openAccuDataFile(string fileName);

	void closeAccuDataFile();
	
	void addIndexedAccuLineData(int index, int time, Accumulater& accu);
	void addIndexedAccuLineData(int index, double valueTime, Accumulater& accu);
	
	void addAccuLineData(int time, Accumulater& accu);
};

#endif


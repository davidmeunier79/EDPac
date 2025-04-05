// DistributionGnuplotFile.h

#ifndef _DISTRIBUTION_GNUPLOT_FILE_H
#define _DISTRIBUTION_GNUPLOT_FILE_H

// Local Includes
#include "../Define.h"
#include "../DefineStater.h"

#include "GnuplotFile.h"

// STL Includes
#include <string>
#include <sstream>

#include <fstream>
using namespace std;

/******************************************************************************************************************************************/
/******************************************************** Classe DistributionGnuplotFile **************************************************/
/******************************************************************************************************************************************/

class DistributionGnuplotFile : public GnuplotFile
{
	
#ifdef _LOG_LOG_STAT_MODE
	void plotLogLogDistribution(string fileName);
#endif

#ifdef _XLOG_STAT_MODE
	void plotXLogDistribution(string fileName);
#endif

#ifdef _YLOG_STAT_MODE
	void plotYLogDistribution(string fileName);
#endif
public:
	DistributionGnuplotFile();
	~DistributionGnuplotFile();

	void plotMeanDistribution(string fileName);
	
	void plotDistribution(string fileName);

	void plotLogDistribution(string fileName);
	
	void plotMean(string fileName);
	void plotMean(string fileName,int maxIndex);
	
	void plotMean(string name, string fileName,string FileName2, int maxIndex);
	
	void plotRepartition(string fileName);
};

#endif

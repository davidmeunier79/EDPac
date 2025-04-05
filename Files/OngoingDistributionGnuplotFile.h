// OngoingDistributionGnuplotFile.h

#ifndef _ONGOING_DISTRIBUTION_GNUPLOT_FILE_H
#define _ONGOING_DISTRIBUTION_GNUPLOT_FILE_H

// Local Includes
#include "../Define.h"
#include "../DefineStater.h"

#include "DistributionGnuplotFile.h"

// STL Includes
#include <string>
#include <sstream>

#include <fstream>
using namespace std;

/******************************************************************************************************************************************/
/************************************************* Classe OngoingDistributionGnuplotFile **************************************************/
/******************************************************************************************************************************************/

class OngoingDistributionGnuplotFile : public DistributionGnuplotFile
{
public:
	OngoingDistributionGnuplotFile();
	~OngoingDistributionGnuplotFile();

	void plotOngoingDistribution(string fileName,int index);
	
	void plotOngoingMeanLogDistribution(string fileName,int index);


	void plotOngoingAccumulater(string fileName);
	void plotOngoingValue(string fileName);
};

#endif

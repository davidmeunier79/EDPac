// OngoingDistributionGnuplotFile.cc

// Local Includes
#include "OngoingDistributionGnuplotFile.h"

/****************************************************************************************************************************************/
/*********************************** Methodes de la classe OngoingDistributionGnuplotFile ***********************************************/
/****************************************************************************************************************************************/

OngoingDistributionGnuplotFile::OngoingDistributionGnuplotFile()
{
}

OngoingDistributionGnuplotFile::~OngoingDistributionGnuplotFile()
{
}

void OngoingDistributionGnuplotFile::plotOngoingDistribution(string fileName, int index)
{
	ostringstream oss;
	oss << "Ongoing" << fileName << "Distribution";

	for (int i=0;i<index+1;i++)
	{
		ostringstream oss2;
		oss2 << i;
		setOutput("3D"+oss.str()+oss2.str());
		setTitle("3D"+oss.str()+oss2.str());
		plot3DSingleSurface(oss.str()+"Stat",i);
	}

	
	#ifdef _ONGOING_CUMUL_STAT_MODE
	ostringstream ossCumul;
	ossCumul << "OngoingCumulated" << fileName;

	plotMeanDistribution(ossCumul.str());
	#endif
}

void OngoingDistributionGnuplotFile::plotOngoingMeanLogDistribution(string fileName, int index)
{
	ostringstream oss;
	oss << "Ongoing" << fileName << "Distribution";

	for (int i=0;i<index+1;i++)
	{
		ostringstream oss2;
		oss2 << i;
		setOutput("3D"+oss.str()+oss2.str());
		setTitle("3D"+oss.str()+oss2.str());
		plot3DSingleSurface(oss.str()+"Stat",i);
	}

	
	#ifdef _ONGOING_CUMUL_STAT_MODE
	ostringstream ossCumul;
	ossCumul << "OngoingCumulated" << fileName;

	plotLogDistribution(ossCumul.str());
	#endif
}

void OngoingDistributionGnuplotFile::plotOngoingAccumulater(string fileName)
{
	ostringstream oss;
	oss << "Ongoing" << fileName;

#ifdef _3D_STAT_MODE
	setOutput("3D"+oss.str());
	setTitle("3D"+oss.str());
	plot3DIndexedLines(oss.str()+"Stat");
#else
	setOutput(oss.str());
	setTitle(oss.str());

	#ifdef _ERROR_BARS_STAT_MODE
	plotFirstIndexedErrorBarsLine(oss.str()+"Stat",0);
	plotSecondIndexedErrorBarsLine(oss.str()+"Stat",1);
	#else
	plotFirstIndexedLine(oss.str()+"Stat",0);
	plotSecondIndexedLine(oss.str()+"Stat",1);
	#endif
#endif
}

void OngoingDistributionGnuplotFile::plotOngoingValue(string fileName)
{
	ostringstream oss;
	oss << "Ongoing" << fileName;

#ifdef _3D_STAT_MODE
	setOutput("3D"+oss.str());
	setTitle("3D"+oss.str());
	plot3DIndexedLines(oss.str()+"Stat");
#else
	setOutput(oss.str());
	setTitle(oss.str());

	plotFirstIndexedLine(oss.str()+"Stat",0);
	plotSecondIndexedLine(oss.str()+"Stat",1);
#endif
}



// DistributionGnuplotFile.cc

// Local Includes
#include "DistributionGnuplotFile.h"

/****************************************************************************************************************************************/
/****************************************** Methodes de la classe DistributionGnuplotFile ***********************************************/
/****************************************************************************************************************************************/

DistributionGnuplotFile::DistributionGnuplotFile()
{
}

DistributionGnuplotFile::~DistributionGnuplotFile()
{
}

void DistributionGnuplotFile::plotMeanDistribution(string fileName)
{
	plotDistribution(fileName);
	
#ifdef _LOG_LOG_STAT_MODE
	plotLogLogDistribution(fileName);
#endif

#ifdef _XLOG_STAT_MODE
	plotXLogDistribution(fileName);
#endif

#ifdef _YLOG_STAT_MODE
	plotYLogDistribution(fileName);
#endif
}

void DistributionGnuplotFile::plotDistribution(string fileName)
{
	ostringstream oss;
	oss << fileName << "Distribution";
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

void DistributionGnuplotFile::plotLogDistribution(string fileName)
{
	ostringstream oss;
	oss << fileName << "Distribution";
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

#ifdef _LOG_LOG_STAT_MODE
void DistributionGnuplotFile::plotLogLogDistribution(string fileName)
{
	ostringstream oss;
	oss << fileName << "Distribution";
	#ifdef _3D_STAT_MODE
	setOutput("3D"+oss.str());
	setTitle("3D"+oss.str());
	plot3DIndexedLines(oss.str()+"Stat");
	#else
	setOutput(oss.str()+"LogLog");
	setTitle(oss.str()+"LogLog");

	setLogLog();
		#ifdef _ERROR_BARS_STAT_MODE
	plotFirstIndexedErrorBarsLine(oss.str()+"Stat",0);
	plotSecondIndexedErrorBarsLine(oss.str()+"Stat",1);
		#else
	plotFirstIndexedLine(oss.str()+"Stat",0);
	plotSecondIndexedLine(oss.str()+"Stat",1);
		#endif

	setNoLogLog();
	#endif
}
#endif

#ifdef _XLOG_STAT_MODE
void DistributionGnuplotFile::plotXLogDistribution(string fileName)
{
	ostringstream oss;
	oss << fileName << "Distribution";

	#ifdef _3D_STAT_MODE
	setOutput("3D"+oss.str());
	setTitle("3D"+oss.str());
	plot3DIndexedLines(oss.str()+"Stat");
	#else
	setOutput(oss.str()+"XLog");
	setTitle(oss.str()+"XLog");

	setXLog();
		#ifdef _ERROR_BARS_STAT_MODE
	plotFirstIndexedErrorBarsLine(oss.str()+"Stat",0);
	plotSecondIndexedErrorBarsLine(oss.str()+"Stat",1);
		#else
	plotFirstIndexedLine(oss.str()+"Stat",0);
	plotSecondIndexedLine(oss.str()+"Stat",1);
		#endif

	setNoXLog();
	#endif
}
#endif

#ifdef _YLOG_STAT_MODE
void DistributionGnuplotFile::plotYLogDistribution(string fileName)
{
	ostringstream oss;
	oss << fileName << "Distribution";

	#ifdef _3D_STAT_MODE
	setOutput("3D"+oss.str());
	setTitle("3D"+oss.str());
	plot3DIndexedLines(oss.str()+"Stat");
	#else
	setOutput(oss.str()+"YLog");
	setTitle(oss.str()+"YLog");

	setYLog();
		#ifdef _ERROR_BARS_STAT_MODE
	plotFirstIndexedErrorBarsLine(oss.str()+"Stat",0);
	plotSecondIndexedErrorBarsLine(oss.str()+"Stat",1);
		#else
	plotFirstIndexedLine(oss.str()+"Stat",0);
	plotSecondIndexedLine(oss.str()+"Stat",1);
	#endif

	setNoYLog();
	#endif
}
#endif

void DistributionGnuplotFile::plotMean(string fileName)
{
	setOutput(fileName);
	setTitle(fileName);

#ifdef _ERROR_BARS_STAT_MODE
	setXRange(-1,2);
	plotErrorBarsLine(fileName+"Stat");
	setNoXRange();
#else
	plotLine(fileName+"Stat");
#endif
}

void DistributionGnuplotFile::plotMean(string fileName, int maxIndex)
{
	setOutput(fileName);
	setTitle(fileName);

#ifdef _ERROR_BARS_STAT_MODE
	setXRange(-1,maxIndex+1);
	plotErrorBarsLine(fileName+"Stat");
	setNoXRange();
#else
	plotLine(fileName+"Stat");
#endif
}

void DistributionGnuplotFile::plotMean(string name, string fileName,string fileName2, int maxIndex)
{
	setOutput(name);
	setTitle(name);

#ifdef _ERROR_BARS_STAT_MODE
	setXRange(-1,maxIndex+1);
	plotFirstErrorBarsLine(fileName+"Stat");
	plotSecondErrorBarsLine(fileName2+"Stat");
	setNoXRange();
#else
	plotLine(fileName+"Stat");
#endif
}

void DistributionGnuplotFile::plotRepartition(string fileName)
{
	ostringstream oss;
	oss << fileName << "Repartition";

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

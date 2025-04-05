// GnuplotFile.h

#ifndef _GNUPLOT_FILE_H
#define _GNUPLOT_FILE_H

// Local Includes
#include "../Objets/FileObject.h"

// STL Includes
#include <string>
#include <sstream>

#include <fstream>
using namespace std;

/******************************************************************************************************************************************/
/******************************************************* Classe GnuplotFile ***************************************************************/
/******************************************************************************************************************************************/

class GnuplotFile : public FileObject
{
public:
	GnuplotFile();
	~GnuplotFile();

	void openGnuplotFile(string fileName);

	void plotLine(string dataFileName);
	void plotErrorBarsLine(string dataFileName);
	
	void plotFirstErrorBarsLine(string dataFileName);
	void plotSecondErrorBarsLine(string dataFileName);
	
	void plotLines(string dataFileName, int firstIndex, int lastIndex);

	void plotFirstSingleLine(string dataFileName);
	void plotSecondSingleLine(string dataFileName);

	void plotIndexedLine(string dataFileName, int index);

	void plotFirstIndexedLine(string dataFileName, int index);
	void plotSecondIndexedLine(string dataFileName, int index);
	
	void plotFirstIndexedErrorBarsLine(string dataFileName, int index);
	void plotSecondIndexedErrorBarsLine(string dataFileName, int index);
/*
	void plotLogLogFirstIndexedLine(string dataFileName, int index);
	void plotLogLogSecondIndexedLine(string dataFileName, int index);
*/	
	void plotIndexedLines(string dataFileName);
	void plotIndexedLines(string dataFileName, int firstIndex, int lastIndex);
	void plotTitleIndexedLines(string dataFileName, int firstIndex, int lastIndex);
	void plotTitleEveryIndexedLines(string dataFileName, int firstIndex, int everyIndex, int nbSteps);
	
	void plotSorted2Line(string dataFileName);
	void plotTitleSorted3IndexedLines(string dataFileName, int firstIndex, int lastIndex);

	void plotSingleIndexedLine(string dataFileName);

	void plotFirstSingleIndexedLine(string dataFileName);
	void plotSecondSingleIndexedLine(string dataFileName);
	void plotLastSingleIndexedLine(string dataFileName);
	
	void plot3DIndexedLines(string dataFileName);
	void plot3DSingleIndexedLine(string dataFileName,int singleIndex);
	void plot3DSingleSurface(string dataFileName,int singleIndex);
	
	void plot3DIndexedLines(string dataFileName, int firstIndex, int lastIndex);
	void plot3DSingleIndexedLines(string dataFileName, int firstIndex, int lastIndex);

	void plot3DLine(string dataFileName);
	
	void plotIndexedPoints(string dataFileName, int firstIndex, int lastIndex);
	void plotPoints(string dataFileName);

	void plotIndexedDots(string dataFileName, int firstIndex, int lastIndex);
	void plotDots(string dataFileName);

	void setTitle(string title);
	void setOutput(string output);
	
	void setXRange(int xMin, int xMax);
	void setNoXRange();

	void setLogLog();
	void setNoLogLog();

	void setXLog();
	void setNoXLog();

	void setYLog();
	void setNoYLog();

	void systemFile();
};

#endif

// GnuplotFile.cc

// Local Includes
#include "GnuplotFile.h"

/****************************************************************************************************************************************/
/****************************************************** Methodes de la classe GnuplotFile ***********************************************/
/****************************************************************************************************************************************/

GnuplotFile::GnuplotFile()
{
}

GnuplotFile::~GnuplotFile()
{
}

void GnuplotFile::openGnuplotFile(string newFileName)
{
	fileName = newFileName + ".gnu";
	openOFile();

	file << "set terminal postscript eps noenhanced color solid defaultplex \"Times-Roman\" 18" << endl;
	file << "set size 1.5,1.5" << endl;
	file << "set lmargin 8" << endl;
	file << "set bmargin 3" << endl;
	file << "set rmargin 2" << endl;
	file << "set tmargin 1" << endl << endl;
}

void GnuplotFile::systemFile()
{
	ostringstream gnuplotCommand;
	gnuplotCommand << "gnuplot " << fileName << endl;
	system(((string)gnuplotCommand.str()).c_str());
}

void GnuplotFile::plotLine(string dataFileName)
{
	file << "plot \'" << dataFileName << ".dat' using 1:2 notitle with lines" << endl << endl;
}

void GnuplotFile::plotErrorBarsLine(string dataFileName)
{
	file << "plot \'" << dataFileName << ".dat' using 1:2:3:4 with yerrorbars";
	file << ", \t\'" << dataFileName << ".dat' using 1:2 title \"" << dataFileName << "\"  with lines" << endl << endl;
}

void GnuplotFile::plotFirstErrorBarsLine(string dataFileName)
{
	//file << "set xrange [*:*]" << endl;
	file << "plot \'" << dataFileName << ".dat' using 1:2:3:4 notitle with yerrorbars";
	file << ", \t\'" << dataFileName << ".dat' using 1:2 title \"" << dataFileName << "\" with lines";
}

void GnuplotFile::plotSecondErrorBarsLine(string dataFileName)
{
	file << ", \t\'" << dataFileName << ".dat' using 1:2:3:4 notitle with yerrorbars";
	file << ", \t\'" << dataFileName << ".dat' using 1:2 title \"" << dataFileName << "\" with lines" << endl << endl;
}

void GnuplotFile::plotLines(string dataFileName, int firstIndex, int lastIndex)
{
	if (firstIndex<lastIndex)
	{
		for (int i=firstIndex; i<lastIndex; i++)
		{
			if (i==firstIndex)
			{
				file << "plot ";
			}
			else
			{
				file << "\t";
			}

			file << "\'" << dataFileName << i << ".dat' using 1:2 notitle with lines";

			if (i==lastIndex-1)
			{
				file << endl << endl;
			}
			else
			{
				file << ", \\" << endl;
			}
		}
	}
	else
	{
		cerr << "Warning, wrong index order: " << firstIndex << " < " << lastIndex << endl;
	}
}

void GnuplotFile::plotFirstSingleLine(string dataFileName)
{
	file << "plot \'" << dataFileName << ".dat' using 1:2 title \"" << dataFileName << "\"  with lines" ;
}

void GnuplotFile::plotSecondSingleLine(string dataFileName)
{
	file << ", \t\'" << dataFileName << ".dat' using 1:2 title \"" << dataFileName << "\" with lines" << endl << endl;
}

// Graphs avec index
void GnuplotFile::plotIndexedLine(string dataFileName, int index)
{
	file << "plot \'Indexed_Sorted_" << dataFileName << ".dat' index " << index << " using 2:3 notitle with lines" << endl << endl;
}

void GnuplotFile::plotFirstIndexedLine(string dataFileName, int index)
{
	//file << "set xrange [*:*]" << endl;
	file << "plot \'Indexed_Sorted_" << dataFileName << ".dat' index " << index << " using 2:3 title \"" << dataFileName << "\" with lines" ;
}

void GnuplotFile::plotSecondIndexedLine(string dataFileName, int index)
{
	file << ", \t\'Indexed_Sorted_" << dataFileName << ".dat' index " << index << " using 2:3 title \"" << dataFileName << "\" with lines" << endl << endl;
}

void GnuplotFile::plotFirstIndexedErrorBarsLine(string dataFileName, int index)
{
	//file << "set xrange [*:*]" << endl;
	file << "plot \'Indexed_Sorted_" << dataFileName << ".dat' index " << index << " using 2:3 title \"" << dataFileName << "\" with lines" ;
	file << ", \t \'Indexed_Sorted_" << dataFileName << ".dat' index " << index << " using 2:3:4:5 notitle with yerrorbars";
}

void GnuplotFile::plotSecondIndexedErrorBarsLine(string dataFileName, int index)
{
	file << ", \t\'Indexed_Sorted_" << dataFileName << ".dat' index " << index << " using 2:3 title \"" << dataFileName << "\" with lines";
	file << ", \t\'Indexed_Sorted_" << dataFileName << ".dat' index " << index << " using 2:3:4:5 notitle with yerrorbars" << endl << endl;
}

// Graphs seuls
void GnuplotFile::plotSingleIndexedLine(string dataFileName)
{
	file << "plot \'" << dataFileName << ".dat' using 2:3 notitle with lines" << endl << endl;
}

void GnuplotFile::plotFirstSingleIndexedLine(string dataFileName)
{
	file << "plot \'" << dataFileName << ".dat' using 2:3 title \"" << dataFileName << "\" with lines" ;
}

void GnuplotFile::plotSecondSingleIndexedLine(string dataFileName)
{
	file << ", \t\'" << dataFileName << ".dat' using 2:3 title \"" << dataFileName << "\" with lines";
}

void GnuplotFile::plotLastSingleIndexedLine(string dataFileName)
{
	file << ", \t\'" << dataFileName << ".dat' using 2:3 title \"" << dataFileName << "\" with lines" << endl << endl;
}

void GnuplotFile::plotTitleIndexedLines(string dataFileName, int firstIndex, int lastIndex)
{
	if (firstIndex<lastIndex)
	{
		for (int i=firstIndex; i<lastIndex; i++)
		{
			if (i==firstIndex)
			{
				file << "plot ";
			}
			else
			{
				file << "\t";
			}

			file << "\'Indexed_Sorted_" << dataFileName << ".dat' index " << i << " using 2:3 title\'" << dataFileName << i << "\' with lines";

			if (i==lastIndex-1)
			{
				file << endl << endl;
			}
			else
			{
				file << ", \\" << endl;
			}
		}
	}
	else
	{
		cerr << "Warning, wrong index order: " << firstIndex << " < " << lastIndex << endl;
	}
}

void GnuplotFile::plotTitleEveryIndexedLines(string dataFileName, int firstIndex, int everyIndex, int nbSteps)
{
	for (int i=0; i<nbSteps; i++)
	{
		if (i==0)
		{
			file << "plot ";
		}
		else
		{
			file << "\t";
		}

		file << "\'Indexed_Sorted_" << dataFileName << ".dat' index " << firstIndex+i*everyIndex << " using 2:3 title\'" << dataFileName << i << "\' with lines";

		if (i==nbSteps-1)
		{
			file << endl << endl;
		}
		else
		{
			file << ", \\" << endl;
		}
	}
}


void GnuplotFile::plotSorted2Line(string dataFileName)
{
	file << "plot \'Indexed_Sorted2_" << dataFileName << ".dat' using 1:2 notitle with lines" << endl << endl;
}

void GnuplotFile::plotTitleSorted3IndexedLines(string dataFileName, int firstIndex, int lastIndex)
{
	if (firstIndex<lastIndex)
	{
		for (int i=firstIndex; i<lastIndex; i++)
		{
			if (i==firstIndex)
			{
				file << "plot ";
			}
			else
			{
				file << "\t";
			}

			file << "\'Indexed_Sorted_Sorted3_Indexed_Sorted_" << dataFileName << ".dat' index " << i << " using 2:3 title\'" << dataFileName << i << "\' with lines";

			if (i==lastIndex-1)
			{
				file << endl << endl;
			}
			else
			{
				file << ", \\" << endl;
			}
		}
	}
	else
	{
		cerr << "Warning, wrong index order: " << firstIndex << " < " << lastIndex << endl;
	}
}

void GnuplotFile::plotIndexedLines(string dataFileName)
{
	file << "plot \'Indexed_Sorted_" << dataFileName << ".dat' using 2:3 notitle with lines" << endl;
}

void GnuplotFile::plotIndexedLines(string dataFileName, int firstIndex, int lastIndex)
{
	if (firstIndex<lastIndex)
	{
		for (int i=firstIndex; i<lastIndex; i++)
		{
			if (i==firstIndex)
			{
				file << "plot ";
			}
			else
			{
				file << "\t";
			}

			file << "\'Indexed_Sorted_" << dataFileName << ".dat' index " << i << " using 2:3 notitle with lines";

			if (i==lastIndex-1)
			{
				file << endl << endl;
			}
			else
			{
				file << ", \\" << endl;
			}
		}
	}
	else
	{
		cerr << "Warning, wrong index order: " << firstIndex << " < " << lastIndex << endl;
	}
}

void GnuplotFile::plot3DIndexedLines(string dataFileName)
{
	//file << "set xrange[*:*]" << endl;
	file << "set dgrid3d 20,20,10" << endl;
	file << "set ticslevel 0" << endl;
	file << "set view 60,315,1,1" << endl;
	file << "set isosample 100" << endl;
	file << "splot \'Indexed_Sorted_" << dataFileName << ".dat' using 2:1:3 notitle with lines" << endl << endl;
}

void GnuplotFile::plot3DSingleIndexedLine(string dataFileName,int singleIndex)
{
	//file << "set xrange[*:*]" << endl;
	file << "set dgrid3d 20,20,10" << endl;
	file << "set ticslevel 0" << endl;
	file << "set view 45,135,1,1" << endl;
	file << "splot \'Indexed_Sorted_" << dataFileName << ".dat' index " << singleIndex << " using 2:1:3 notitle with lines" << endl << endl;
}

void GnuplotFile::plot3DSingleSurface(string dataFileName,int singleIndex)
{
	//file << "set xrange[*:*]" << endl;
	file << "set dgrid3d 30,30,100" << endl;
	//file << "set surface" << endl;
	//file << "set contour both" << endl;
	//file << "set cntrparam bspline" << endl;
	file << "set hidden3d" << endl;
	file << "set ticslevel 0" << endl;
	file << "set view 45,135,1,1" << endl;
	file << "splot \'Indexed_Sorted_" << dataFileName << ".dat' index " << singleIndex << " using 2:1:3 notitle with lines" << endl << endl;
}

void GnuplotFile::plot3DIndexedLines(string dataFileName, int firstIndex, int lastIndex)
{
	file << "set dgrid3d 10,10,10" << endl;
	file << "set ticslevel 0" << endl;
	//file << "set view 60,330,1,1" << endl;
	file << "set view 60,315,1,1" << endl;

	if (firstIndex<lastIndex)
	{
		for (int i=firstIndex; i<lastIndex; i++)
		{
			if (i==firstIndex)
			{
				file << "splot ";
			}
			else
			{
				file << "\t";
			}

			file << "\'Indexed_Sorted_" << dataFileName << ".dat' index " << i << " using 2:1:3 notitle with lines";

			if (i==lastIndex-1)
			{
				file << endl << endl;
			}
			else
			{
				file << ", \\" << endl;
			}
		}
	}
	else
	{
		cerr << "Warning, wrong index order: " << firstIndex << " < " << lastIndex << endl;
	}
}

void GnuplotFile::plot3DSingleIndexedLines(string dataFileName, int firstIndex, int lastIndex)
{
	file << "set dgrid3d 10,10,10" << endl;
	file << "set ticslevel 0" << endl;
	//file << "set view 60,330,1,1" << endl;
	file << "set view 60,315,1,1" << endl;

	if (firstIndex<lastIndex)
	{
		for (int i=firstIndex; i<=lastIndex; i++)
		{
			ostringstream oss;
			oss << "3D_" << dataFileName << i;

			setOutput(oss.str());
			setTitle(oss.str());

			file << "splot \'Indexed_Sorted_" << dataFileName << ".dat' index " << i << " using 2:1:3 notitle with lines" << endl << endl;
		}
	}
	else
	{
		cerr << "Warning, wrong index order: " << firstIndex << " < " << lastIndex << endl;
	}
}

void GnuplotFile::plot3DLine(string dataFileName)
{
	file << "set ticslevel 0" << endl;
	//file << "set view 60,330,1,1" << endl;
	file << "set view 60,315,1,1" << endl;
	file << "splot \'" << dataFileName << ".dat' using 1:2:3 notitle with lines" << endl << endl;
}

void GnuplotFile::plotIndexedDots(string dataFileName, int firstIndex, int lastIndex)
{
	if (firstIndex<lastIndex)
	{
		for (int i=firstIndex; i<lastIndex; i++)
		{
			if (i==firstIndex)
			{
				file << "plot ";
			}
			else
			{
				file << "\t";
			}

			file << "\'Indexed_Sorted_" << dataFileName << ".dat' index " << i << " using 2:1 notitle with dots";

			if (i==lastIndex-1)
			{
				file << endl << endl;
			}
			else
			{
				file << ", \\" << endl;
			}
		}
	}
	else
	{
		cerr << "Warning, wrong index order: " << firstIndex << " < " << lastIndex << endl;
	}
}

void GnuplotFile::plotDots(string dataFileName)
{
	file << "plot \'" << dataFileName << ".dat' using 2:1 notitle with dots" << endl << endl;
}

void GnuplotFile::plotIndexedPoints(string dataFileName, int firstIndex, int lastIndex)
{
	if (firstIndex<lastIndex)
	{
		for (int i=firstIndex; i<lastIndex; i++)
		{
			if (i==firstIndex)
			{
				file << "plot ";
			}
			else
			{
				file << "\t";
			}

			file << "\'Indexed_Sorted_" << dataFileName << ".dat' index " << i << " using 2:1 notitle with points";

			if (i==lastIndex-1)
			{
				file << endl << endl;
			}
			else
			{
				file << ", \\" << endl;
			}
		}
	}
	else
	{
		cerr << "Warning, wrong index order: " << firstIndex << " < " << lastIndex << endl;
	}
}

void GnuplotFile::plotPoints(string dataFileName)
{
	file << "plot \'" << dataFileName << ".dat' using 2:1 notitle with points" << endl << endl;
}


void GnuplotFile::setTitle(string title)
{
	file << "set title \"" << title << "\"" << endl;
}

void GnuplotFile::setOutput(string output)
{
	file << "set output \"" << output << ".eps\"" << endl;
}

void GnuplotFile::setXRange(int xMin, int xMax)
{
	file << "set xrange [" << xMin << ":" << xMax << "]" << endl;
}

void GnuplotFile::setNoXRange()
{
	file << "set xrange [*:*]" << endl << endl;
}

void GnuplotFile::setLogLog()
{
	file << "set logscale x" << endl;
	file << "set logscale y" << endl;
}

void GnuplotFile::setXLog()
{
	file << "set logscale x" << endl;
}

void GnuplotFile::setYLog()
{
	file << "set logscale y" << endl;
}

void GnuplotFile::setNoLogLog()
{
	file << "set nologscale x" << endl;
	file << "set nologscale y" << endl << endl;
}

void GnuplotFile::setNoXLog()
{
	file << "set nologscale x" << endl;
}

void GnuplotFile::setNoYLog()
{
	file << "set nologscale y" << endl;
}

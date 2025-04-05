// IOFile.cc

// Local Includes
#include "IOFile.h"

/****************************************************************************************************************************************/
/******************************************************** Methodes de la classe IOFile ************************************************/
/****************************************************************************************************************************************/

IOFile::IOFile()
{
}

IOFile::~IOFile()
{
}

void IOFile::openInputFile(string newFileName)
{
	fileName=newFileName + ".txt";
	
	cout << "Opening Input " << fileName << endl;
	
	openIFile();
}

void IOFile::openOutputFile(string newFileName)
{
	fileName=newFileName + ".txt";
	
	cout << "Opening Output " << fileName << endl;
	openOFile();
}

void IOFile::add(ostringstream* ostr)
{
	file << ostr->str();
}


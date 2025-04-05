// IOFile.h

#ifndef _IO_FILE_H
#define _IO_FILE_H

// Local Includes
#include "../Objets/FileObject.h"

// STL Includes
#include <sstream>
#include <string>
#include <fstream>
using namespace std;

/******************************************************************************************************************************************/
/********************************************************** Classe IOFile ***************************************************************/
/******************************************************************************************************************************************/

class IOFile: public FileObject
{
public:

	IOFile();
	~IOFile();

	void openInputFile(string fileName);
	void openOutputFile(string fileName);
	
	
	void add(ostringstream* str);
	//void add(ostringstream& str);
};

#endif


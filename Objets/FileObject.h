// FileObject.h

#ifndef _FILE_OBJECT_H
#define _FILE_OBJECT_H

// C includes
// Pour chdir
#include <unistd.h>
// Pour mkdir
#include <sys/stat.h>

// STL Includes
#include <string>
#include <fstream>
using namespace std;

// Local Includes
#include "Object.h"

/******************************************************************************************************************************************/
/********************************************************* Classe FileObject **************************************************************/
/******************************************************************************************************************************************/

class FileObject: public Object
{
protected:
	fstream file;
	string fileName;

public:
	FileObject();
	virtual ~FileObject();

	// Ouverture/fermeture
	void openIFile();
	void openIFile(string newFileName);
	
	void openOFile();
	void openOFile(string newFileName);
	
	void closeFile();
	
	bool isOpen();

	// Methode get/set
	void setFileName(string string);
	
	string getFileName();
	fstream& getFile();
	
	// Respectivement entrée et entrée+nettoyage du répertoire /data
	static void initDataFiles();
	static void deleteDataFiles();
};

#endif

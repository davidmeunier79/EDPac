// FileObject.cc

// Local Includes
#include "FileObject.h"

/****************************************************************************************************************************************/
/******************************************************** Methodes de la classe FileObject **********************************************/
/****************************************************************************************************************************************/


FileObject::FileObject()
{
	fileName="";
}

FileObject::~FileObject()
{
	closeFile();
}

void FileObject::setFileName(string newFileName)
{
	fileName = newFileName;
}

string FileObject::getFileName()
{
	return fileName;
}

fstream& FileObject::getFile()
{
	return file;
}
// Création ou utilisation du fichier "data"
void FileObject::deleteDataFiles()
{
	if (chdir("data/")==0)
	{
		cout << "In directory /data" << endl;

		system("rm *.eps");
		system("rm *.sta");

		system("rm *.dat");
		system("rm *.gnu");
	}
	else
	{
		cerr << "error entering directory" << endl;
		return;
	}
}
void FileObject::initDataFiles()
{
	if (chdir("data/")==0)
	{
		cout << "In directory /data" << endl;
	}
	else
	{
		cerr << "Error entering directory" << endl;
		return;
	}
}

void FileObject::openOFile()
{
	file.open(fileName.c_str(),ios::out);
}

void FileObject::openOFile(string newFileName)
{
	file.open(newFileName.c_str(),ios::out);
}

void FileObject::openIFile()
{
	file.open(fileName.c_str(),ifstream::in);
}
void FileObject::openIFile(string newFileName)
{
	file.open(newFileName.c_str(),ifstream::in);
}

bool FileObject::isOpen()
{
	return file.is_open();
}

void FileObject::closeFile()
{
	if (file.is_open())
	{
		file.close();
	}
}

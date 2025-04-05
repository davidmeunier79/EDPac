// IndexedObject.cc

// Local Includes
#include "IndexedObject.h"

/****************************************************************************************************************************************/
/******************************************************* Methodes de la classe IndexedObject ********************************************/
/****************************************************************************************************************************************/

IndexedObject::IndexedObject()
{
	index=-1;
}

IndexedObject::~IndexedObject()
{
}

void IndexedObject::setIndex(int newIndex)
{
	index = newIndex;
}

void IndexedObject::incrementIndex()
{
	index++;
}

int IndexedObject::getIndex()
{
	return index;
}

string IndexedObject::getStringIndex()
{
	std::ostringstream oss;
	oss << index;
	return oss.str();
}

bool IndexedObject::sameIndex(int targetIndex)
{
	return (index==targetIndex);
}

bool IndexedObject::isSameIndex(IndexedObject* io)
{
	return sameIndex(io->getIndex());
}

bool IndexedObject::operator==(IndexedObject* io)
{
	return sameIndex(io->getIndex());
}

bool IndexedObject::operator!=(IndexedObject* io)
{
	return !sameIndex(io->getIndex());
}


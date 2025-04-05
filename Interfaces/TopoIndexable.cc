// TopoIndexable.cc

// Local Includes
#include "TopoIndexable.h"

/****************************************************************************************************************************************/
/*********************************************** Methodes de la classe TopoIndexable ****************************************************/
/****************************************************************************************************************************************/

int TopoIndexable::topoIndex=0;

TopoIndexable::TopoIndexable()
{
}

TopoIndexable::~TopoIndexable()
{
}

void TopoIndexable::incrementTopoIndex()
{
	topoIndex++;
}

void TopoIndexable::initTopoIndex()
{
	topoIndex=0;
}

void TopoIndexable::setTopoIndex(int newTopoIndex)
{
	topoIndex= newTopoIndex;
}

int TopoIndexable::getTopoIndex()
{
	return topoIndex;
}

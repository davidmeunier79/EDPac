// EvalIndexableObject.cc

// Local Includes
#include "EvalIndexable.h"

/****************************************************************************************************************************************/
/*********************************************** Methodes de la classe EvalIndexableObject ************************************************/
/****************************************************************************************************************************************/

int EvalIndexable::evalIndex=0;

EvalIndexable::EvalIndexable()
{
}

EvalIndexable::~EvalIndexable()
{
}

void EvalIndexable::incrementEvalIndex()
{
	evalIndex++;
}

void EvalIndexable::initEvalIndex()
{
	evalIndex=0;
}

int EvalIndexable::getEvalIndex()
{
	return evalIndex;
}

// EvalIndexable.h

#ifndef _EVAL_INDEXABLE_H
#define _EVAL_INDEXABLE_H

// STL Includes
#include <iostream>
using namespace std;

/******************************************************************************************************************************************/
/********************************************************** Classe EvalIndexable **********************************************************/
/******************************************************************************************************************************************/

class EvalIndexable
{
	static int evalIndex;
public:

	EvalIndexable();
	~EvalIndexable();

	static void incrementEvalIndex();
	static void initEvalIndex();

	static int getEvalIndex();
};

#endif

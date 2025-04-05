// TopoIndexable.h

#ifndef _TOPO_INDEXABLE_H
#define _TOPO_INDEXABLE_H

// STL Includes
#include <iostream>
using namespace std;

/******************************************************************************************************************************************/
/********************************************************** Classe EvalIndexable **********************************************************/
/******************************************************************************************************************************************/

class TopoIndexable
{
	static int topoIndex;
public:

	TopoIndexable();
	~TopoIndexable();

	void incrementTopoIndex();

	static void initTopoIndex();
	static void setTopoIndex(int newTopoIndex);

	static int getTopoIndex();
};

#endif

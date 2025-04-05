// CircledList.h

#ifndef _CIRCLED_LIST_H
#define _CIRCLED_LIST_H

#include "PreConstructedList.h"

class CircledList : public PreConstructedList
{
  
public:
	CircledList();
  	CircledList(int nbElement);
	virtual ~CircledList();

	//methode fonctionnelles
	void add(Object* newObject);
	void modifyPEnd(LinkedObject* newLinkedObject);
	Object* getIthObjectAfter_pCur(int nbGap);
};

#endif

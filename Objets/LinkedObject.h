// LinkedObject.h

#ifndef _LINKED_OBJECT_H
#define _LINKED_OBJECT_H

// STL Includes
#include <iostream>

// Local Includes
#include "Object.h"

/******************************************************************************************************************************************/
/******************************************************* Classe LinkedObject **************************************************************/
/******************************************************************************************************************************************/

class LinkedObject
{
private :
	Object* _pObject;
	LinkedObject* _pNext;

public:
	
	LinkedObject();
	LinkedObject(Object* pObject);
	LinkedObject(Object* pObject, LinkedObject* pNextLinkedObject);
	virtual ~LinkedObject();
	
	//Accesseurs
	Object* get_pObject();
	void set_pObject(Object* pObject);
	
	LinkedObject* get_pNext();
	void set_pNext(LinkedObject* pNext);
};

#endif

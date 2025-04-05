/***************************************************************************
                          list.h  -  description
                             -------------------
    begin                : lun mar 29 2004
    copyright            : (C) 2004 by
    email                :
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef LIST_H
#define LIST_H


/**
  *@author
  */


#include "../Objets/LinkedObject.h"
#include "../Objets/Object.h"


class List : public Object {

protected :

  LinkedObject* _pBegin;  
  LinkedObject* _pEnd;

protected :  
  void modifyPEnd(LinkedObject* newLinkedObject);
  
public:
	List();
  
	virtual ~List();

//Accesseurs

  LinkedObject* get_pBegin();  
  LinkedObject* get_pEnd();  

//Methodes fonctionnelles
  void add(Object* newObject);
  void change(LinkedObject* pLinkedObject, Object* pNewObjec);  
  bool isEmpty();
  Object* getIthObject(int idObject);
  LinkedObject* getIthLinkedObject(int idObject);
};

#endif

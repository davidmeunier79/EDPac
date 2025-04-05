// PreConstructedList.h

#ifndef PRECONSTRUCTEDLIST_H
#define PRECONSTRUCTEDLIST_H

#include "List.h"

class PreConstructedList : public List {

protected :
  LinkedObject* _pCur;
  
public: 
	PreConstructedList();
  PreConstructedList(int nbElement);
  
	virtual ~PreConstructedList();

//Accesseurs
  LinkedObject* get_pCur();

//Methodes fonctionnelles
  void set_pCur(LinkedObject* pNewPCur);
  virtual void addChange(Object* pNewObject);
  Object* getNextObject();
};

#endif

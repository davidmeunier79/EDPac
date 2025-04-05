// PreConstructedList.cc

#include "PreConstructedList.h"

PreConstructedList::PreConstructedList(){
}
PreConstructedList::~PreConstructedList(){
}

PreConstructedList::PreConstructedList(int nbElement) {
  _pBegin = 0;
  _pCur = 0;
  _pEnd = 0;

  for (int i=0; i<nbElement; i++) {
    add(0);
  }
}

LinkedObject* PreConstructedList::get_pCur() {
  return _pCur;
}

void PreConstructedList::set_pCur(LinkedObject* pNewPCur) {
  _pCur = pNewPCur;
}

void PreConstructedList::addChange(Object* pNewObject) {
  if (_pCur == 0) {
    _pCur = _pBegin;
  }
  else {
    if (_pCur == _pEnd) {
      add(pNewObject);
    }
    _pCur = _pCur->get_pNext();
  }
  _pCur->set_pObject( pNewObject );
}

Object* PreConstructedList::getNextObject() {

  if (_pCur == 0) {
    _pCur = _pBegin;
  }
  
  Object* returnObject = (&(*_pCur->get_pObject()));    
  _pCur = _pCur->get_pNext();

  return returnObject;
}


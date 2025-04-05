// List.cc

#include "List.h"

List::List(){
  _pBegin = 0;
  _pEnd = 0;
}

List::~List(){
  delete _pBegin;
  _pBegin = 0;
}

void List::modifyPEnd(LinkedObject* newLinkedObject) {
  if (_pBegin !=0) {
    _pEnd->set_pNext(newLinkedObject);
  }
  else {
    _pBegin = newLinkedObject;
  }
  _pEnd = newLinkedObject;
}

void List::add(Object* newObject) {
  LinkedObject* newLinkedObject = new LinkedObject(newObject);
  modifyPEnd(newLinkedObject);
}

void List::change(LinkedObject* pLinkedObject, Object* pNewObjec) {
  pLinkedObject->set_pObject(pNewObjec);
}


bool List::isEmpty() {
  if (_pBegin == 0) {
    return true;
  }
  return false;
}

LinkedObject* List::get_pBegin() {
  return _pBegin;
}

LinkedObject* List::get_pEnd() {
  return _pEnd;
}

Object* List::getIthObject(int idObject) {
  return getIthLinkedObject(idObject)->get_pObject();
}

LinkedObject* List::getIthLinkedObject(int idObject) {
  LinkedObject* pCurObject = _pBegin;
  for (int i=0; i<idObject; i++) {
    pCurObject = pCurObject->get_pNext();
  }
  return pCurObject;
}


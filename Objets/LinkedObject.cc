// LinkedObject.cc

#include "LinkedObject.h"

LinkedObject::LinkedObject(){
  _pObject = 0;
  _pNext = 0;
}

LinkedObject::LinkedObject(Object* pObject) {
  _pObject = pObject;
}

LinkedObject::LinkedObject(Object* pObject, LinkedObject* pNextLinkedObject) {
  _pObject = pObject;
  _pNext = pNextLinkedObject;
}

LinkedObject::~LinkedObject(){
/*  delete _pObject;
  _pObject = 0;
  delete _pNext;
  _pNext = 0;*/
}

Object* LinkedObject::get_pObject() {
  return _pObject;
}

void LinkedObject::set_pObject(Object* pObject) {
  _pObject = (&(*pObject));
}

LinkedObject* LinkedObject::get_pNext() {
  return _pNext;
}

void LinkedObject::set_pNext(LinkedObject* pNext){
  _pNext = (&(*pNext));
}


// CircledList.cc

#include "CircledList.h"

CircledList::CircledList(){
}

CircledList::CircledList(int nbElement) : PreConstructedList(nbElement) {
}

CircledList::~CircledList(){
  _pEnd->set_pNext(0);
}

void CircledList::add(Object* newObject) {
  LinkedObject* newLinkedObject = new LinkedObject(newObject);
  modifyPEnd(newLinkedObject);
}

void CircledList::modifyPEnd(LinkedObject* newLinkedObject) {
  if (_pBegin !=0) {
    _pEnd->set_pNext(newLinkedObject);    
  }
  else {
    _pBegin = newLinkedObject;   
  }
  _pEnd = newLinkedObject;    
  _pEnd->set_pNext(_pBegin); 
}

Object* CircledList::getIthObjectAfter_pCur(int nbGap) {

  if (_pBegin != 0) {
    if (_pCur == 0) {
      _pCur = _pBegin;
    }
  }
  
  LinkedObject* pTmpLinkedObject = _pCur;
  for (int i=0; i<nbGap; i++) {     
    pTmpLinkedObject = pTmpLinkedObject->get_pNext();    
  }
  
  return pTmpLinkedObject->get_pObject();

}

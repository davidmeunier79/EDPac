// PspEventPackage.cc

#include "PspEventPackage.h"

PSPEventPackage::PSPEventPackage() {  
  _iTime = -1;
}

PSPEventPackage::PSPEventPackage(int nbElement) : PreConstructedList(nbElement) {
  _iTime = -1;
}

PSPEventPackage::~PSPEventPackage(){
}

int PSPEventPackage::get_iTime() {
  return _iTime;
}

void PSPEventPackage::set_iTime(int time) {
  _iTime = time;
}

void PSPEventPackage::addSynapseActivation(int time, Synapse* pSynapse) {
  if (_iTime == -1) {
    _iTime = time;   
  }
  else if (_iTime != time) {
    cout << "ERROR !!!!! : La liste de package d'evenements n'est pas assez grosse : Temps du package : "<< _iTime << " Temps de l'evenement : "<< time << endl;
  }
  addChange(pSynapse);
}

void PSPEventPackage::reset()
{
	_iTime=-1;
	_pCur=0;
}

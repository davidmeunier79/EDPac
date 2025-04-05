// PspEventPackage.h

#ifndef _PSP_EVENT_PACKAGE_H
#define _PSP_EVENT_PACKAGE_H

#include "PreConstructedList.h"

#include "../Topology/Synapse.h"

class PSPEventPackage : public PreConstructedList
{
private :
	int _iTime;

public: 
	PSPEventPackage();
  	PSPEventPackage(int nbElement);
  
	virtual ~PSPEventPackage();

	//Accesseurs
	int get_iTime();
	void set_iTime(int time);

	//Methodes fonctionnelles
	void addSynapseActivation(int time, Synapse* pSynapse);
	void reset();
};

#endif

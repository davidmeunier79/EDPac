// EventManager.cc

// Local Includes
#include "EventManager.h"

/****************************************************************************************************************************************/
/****************************************** Méthodes de la classe EventManager **********************************************************/
/****************************************************************************************************************************************/

EventManager::EventManager(int nbElement) 
{
	empty=0;
	_iCurTime = 0;
	for (int i=0; i<nbElement; i++)
	{
		add(new PSPEventPackage(PSP_EVENT_PACKAGE_SIZE));
	}
	_pCur = _pBegin;
}

EventManager::~EventManager() 
{
}

void EventManager::reset()
{
	 empty=0;
	_iCurTime = 0;

	_pCur = _pBegin;
	while (_pCur!=_pEnd)
	{
		PSPEventPackage* curPSPEventPackage=(PSPEventPackage*) _pCur->get_pObject();
		curPSPEventPackage->reset();
		_pCur = _pCur->get_pNext();
	}

	// Reinitialisation du dernier élément
	PSPEventPackage* curPSPEventPackage=(PSPEventPackage*) _pEnd->get_pObject();
	curPSPEventPackage->reset();
}


bool EventManager::getEmpty()
{
	return empty;
}
		
int EventManager::runOneStep()
{
	PSPEventPackage* pCurEventPackage = ((PSPEventPackage*) _pCur->get_pObject());

#ifdef _TEST
	cerr << "Temps d'activation des evenement dans le package courant = " << pCurEventPackage->get_iTime() << endl;
	cerr << "Temps courant dans l'event manager = " << _iCurTime << endl;
#endif

	treatValideEvents(pCurEventPackage);

#ifdef _TEST
	cerr << "After treatValidEvents " << _iCurTime << endl;
#endif	
	_pCur = _pCur->get_pNext();

	return _iCurTime;
}
	
int EventManager::getTime()
{
	return _iCurTime;
}


void EventManager::addNewEvent(int timeOfImpact,EDSynapse* pTargetSynapse) 
{
	int differenceOfTime = timeOfImpact - _iCurTime;
	PSPEventPackage* pspEventPackage = ((PSPEventPackage*) getIthObjectAfter_pCur(differenceOfTime));
	pspEventPackage->addSynapseActivation(timeOfImpact, (Synapse*) pTargetSynapse);
}

void EventManager::treatValideEvents(PSPEventPackage* pPSPEventPackage) 
{
	#ifdef _TEST
	cerr << "Begin treatValideEvents" << endl;
	#endif
		
	LinkedObject* pCurLinkedObject = pPSPEventPackage->get_pBegin();
	
	#ifdef _TEST
	cerr << "After read LinkedObject" << endl;
	#endif
		
	if (pPSPEventPackage->get_iTime() != -1)
	{
		int compt=0;
			
		#ifdef _TEST
		cerr << "In pPSPEventPackage" << endl;
		#endif
		
		while (pCurLinkedObject != pPSPEventPackage->get_pCur()->get_pNext())
		{
			#ifdef _TEST
			cerr << "In pPSPEventPackage " << compt << endl;
			#endif
			
			Synapse* curTopoSynapse = (Synapse*)((Object*) pCurLinkedObject->get_pObject());
			
			#ifdef _TEST
			cerr << (Synapse&) *curTopoSynapse << endl;
			#endif
			
			curTopoSynapse->computePSPEmission(_iCurTime);
			pCurLinkedObject = pCurLinkedObject->get_pNext();
			
			compt++;
		}
		#ifdef _TEST
		cerr << "Nb events in current pPSPEventPackage " << compt << endl;
		#endif
		
		if (compt == 0)
		{
			cerr << "No event treated at time " << _iCurTime << endl;
		}
		
		pPSPEventPackage->set_iTime(-1);
		pPSPEventPackage->set_pCur(0);
	}
	else
	{
		cerr << "No event in package at time " << _iCurTime << endl;
		//if (_iCurTime > EVENT_MANAGER_SIZE+20)
		if (_iCurTime > 20)
		{
			empty=1;
		}
	}
	
	_iCurTime++;
}

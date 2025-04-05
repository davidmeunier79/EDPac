// EventManager.h

#ifndef _EVENT_MANAGER_H
#define _EVENT_MANAGER_H

// STL Includes
#include <queue>
#include <vector>
using namespace std;

// Local Includes
#include "../Define.h"
#include "../DefineEDNetwork.h"

#include "CircledList.h"
#include "PspEventPackage.h"

class EventManager;
#include "../EDNetwork/EDSynapse.h"

/******************************************************************************************************************************************/
/************************************************** Classe EventManager *******************************************************************/
/******************************************************************************************************************************************/

class EventManager : public CircledList
{
 	friend class EDSynapse;
	
private :
	int _iCurTime;
	bool empty;

protected:
	void addNewEvent(int timeOfImpact,EDSynapse* pTargetSynapse);

public:
	EventManager(int nbElement);
	virtual ~EventManager();

	void reset();
	int runOneStep();
	int getTime();

	void treatValideEvents(PSPEventPackage* pPSPEventPackage);
	
	bool getEmpty();

};

#endif

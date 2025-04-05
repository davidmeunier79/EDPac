// Node.h

#ifndef _NODE_H
#define _NODE_H

// STL Includes
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

// Local Includes
#include "../Objets/IndexedObject.h"

class Node;
#include "Link.h"


/******************************************************************************************************************************************/
/************************************************************ Classe Node ***************************************************************/
/******************************************************************************************************************************************/

class Node : public IndexedObject
{
protected:

	std::vector<Link*> inputLinks;
	std::vector<Link*> outputLinks;

	friend class LoopStater;
public:

	Node();
	virtual ~Node();

	int getNbLinks();
	void destroyLinks();
	void updateLinks();
	
	// Input
	int getNbInputLinks();
	void addInputLink(Link* newInputLink);
	void updateInputLink(Link* newInputLink);
		
	vector<Link*>::iterator getFirstInputLink();
	vector<Link*>::iterator getLastInputLink();
	
	bool isInputLinked(Node* preNode);
	//bool removeInputLink(Node* preNode);
	bool eraseInputLink(Node* preNode);
	
	// Output
	int getNbOutputLinks();
	void addOutputLink(Link* newOutputLink);
	void updateOutputLink(Link* newOutputLink);
	
	vector<Link*>::iterator getFirstOutputLink();
	vector<Link*>::iterator getLastOutputLink();
	
	bool isOutputLinked(Node* postNode);
	//Link* removeOutputLink(Node* postNode);
	Link* eraseOutputLink(Node* postNode);
	
	// Special suppression/insertion
	Link* eraseOutputLink(int linkIndex);
	void insertOutputLink(Link* curLink, int linkIndex);
	
	friend std::ostream& operator<<(std::ostream&, Node&);
};

#endif

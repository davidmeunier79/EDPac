// Link.h

#ifndef _LINK_H
#define _LINK_H

//#include <stdio.h>

// STL Includes
#include <iostream>
//#include <fstream>

// Local Includes
#include "../Objets/IndexedObject.h"

class Link;
#include "Node.h"

using namespace std;

/******************************************************************************************************************************************/
/*********************************************************** Classe Synapse ***************************************************************/
/******************************************************************************************************************************************/

class Link : public IndexedObject
{
protected:

	Node* preNode;
	Node* postNode;

public:
	Link();
	Link(Node* newPreNeuron, Node* newPostNeuron);
	Link(Link& curLink);
	
	virtual ~Link();
	virtual Link* clone();

	bool replacePostNode(Node* oldPostNode,Node* newPostNode);
	bool replacePreNode(Node* oldPreNode,Node* newPreNode);
	
	// Methodes get
	Node* getPreNode();
	Node* getPostNode();

	void setPostNode(Node* newPostNode);
	void setPreNode(Node* newPreNode);
	
	friend std::ostream& operator<<(std::ostream&, Link&);

};

#endif

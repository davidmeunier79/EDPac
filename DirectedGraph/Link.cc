// Link.cc

// Local Includes
#include "Link.h"

/****************************************************************************************************************************************/
/***************************************************** Methodes de la classe Link ****************************************************/
/****************************************************************************************************************************************/

Link::Link()
{
	preNode=0;
	postNode=0;
}

Link::Link(Node* newPreNode, Node* newPostNode)
{
	preNode=newPreNode;
	postNode=newPostNode;
}

Link::Link(Link& curLink)
{
	index = curLink.index;
	
	preNode=curLink.preNode;
	postNode=curLink.postNode;
}

Link::~Link()
{
	preNode=0;
	postNode=0;
}

Link* Link::clone()
{
	return new Link(*this);
}

bool Link::replacePreNode(Node* oldPreNode,Node* newPreNode)
{
	if (preNode->isSameIndex(oldPreNode))
	{
		preNode = newPreNode;
		return 1;
	}
	return 0;
}

bool Link::replacePostNode(Node* oldPostNode,Node* newPostNode)
{
	if (postNode->isSameIndex(oldPostNode))
	{
		postNode = newPostNode;
		return 1;
	}
	return 0;
}

Node* Link::getPreNode()
{
	return preNode;
}

Node* Link::getPostNode()
{
	return postNode;
}

void Link::setPreNode(Node* newPreNode)
{
	preNode = newPreNode;
}

void Link::setPostNode(Node* newPostNode)
{
	postNode = newPostNode;
}

/****************************************************************************************************************************************/
/******************************************************* Methodes d'affichage ***********************************************************/
/****************************************************************************************************************************************/

std::ostream& operator<<(std::ostream& f, Link& s)
{
	//f << "Link n° : " << s.index << " ";
	
	if (s.preNode && s.postNode)
	{
		//f << "PreNode : " << s.preNode->getIndex() << "  ";
		f << s.preNode->getIndex() << " " << s.postNode->getIndex();
	}
	else
	{
		cerr << "Warning, preNode or postNode undefined";
	}
	
	return f;
}


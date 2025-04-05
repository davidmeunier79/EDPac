// Node.cc

// Local Includes
#include "Node.h"

/****************************************************************************************************************************************/
/***************************************************** Methodes de la classe Node *****************************************************/
/****************************************************************************************************************************************/

Node::Node()
{
}

Node::~Node()
{
	inputLinks.erase(inputLinks.begin(),inputLinks.end());
	outputLinks.erase(outputLinks.begin(),outputLinks.end());
}

int Node::getNbLinks()
{
	return (inputLinks.size()+outputLinks.size());
}

void Node::destroyLinks()
{
	// Destruction des pointeurs sur projections d'entrée
	/*
	std::vector<Link*>::iterator itInput=inputLinks.begin();
	std::vector<Link*>::iterator endInput=inputLinks.end();

	inputLinks.erase(itInput,endInput);
	*/
	
	inputLinks.erase(inputLinks.begin(),inputLinks.end());
	
	// Destruction + desallocation des pointeurs sur projections de sortie
	std::vector<Link*>::iterator itOutput=outputLinks.begin();
	std::vector<Link*>::iterator endOutput=outputLinks.end();

	while (itOutput!=endOutput)
	{
		delete(*itOutput);
		itOutput++;
	}

	//outputLinks.erase(itOutput,endOutput);
	outputLinks.erase(outputLinks.begin(),outputLinks.end());
	
	//inputLinks=std::vector<Link*>();
	//outputLinks=std::vector<Link*>();
}

void Node::updateLinks()
{
	std::vector<Link*>::iterator itInput=inputLinks.begin();
	std::vector<Link*>::iterator endInput=inputLinks.end();
	
	while (itInput != endInput)
	{
		updateInputLink(*itInput);
		itInput++;
	}
	
	std::vector<Link*>::iterator itOutput=outputLinks.begin();
	std::vector<Link*>::iterator endOutput=outputLinks.end();
	
	while (itOutput != endOutput)
	{
		updateOutputLink(*itOutput);
		itOutput++;
	}
}

// Input Links
int Node::getNbInputLinks()
{
	return ((int) inputLinks.size());
}

void Node::addInputLink(Link* newInputLink)
{
	inputLinks.push_back(newInputLink);
}

void Node::updateInputLink(Link* newInputLink)
{
	if (!isInputLinked((Node*) ((Link*) newInputLink)->getPreNode()))
	{
		if (isSameIndex((Node*) newInputLink->getPostNode()))
		{
			addInputLink(newInputLink);
		}
		else
		{
			newInputLink->setPostNode((Node*) this);
			addInputLink(newInputLink);
		}
	}
}

std::vector<Link*>::iterator Node::getFirstInputLink()
{
	return inputLinks.begin();
}

std::vector<Link*>::iterator Node::getLastInputLink()
{
	return inputLinks.end();
}

bool Node::isInputLinked(Node* preNode)
{
	std::vector<Link*>::iterator itInput=inputLinks.begin();
	std::vector<Link*>::iterator endInput=inputLinks.end();
	
	while (itInput != endInput)
	{
		if (((Node*) ((Link*) *itInput)->getPreNode())->isSameIndex((Node*) preNode))
		{
			return 1;
		}
		itInput++;
	}
	
	return 0;
}

bool Node::eraseInputLink(Node* preNode)
{
	std::vector<Link*>::iterator itInput=inputLinks.begin();
	std::vector<Link*>::iterator endInput=inputLinks.end();

	while (itInput != endInput)
	{
		if ((Node*) ((Link*) *itInput)->getPreNode()->isSameIndex(preNode))
		{			
			inputLinks.erase(itInput);
			return 1;
		}
		itInput++;
	}
	
	cerr << "Warning, unable to find input link with preNode " << ((Node*) preNode)->getIndex() << " in " << (Node&) *this;
	
	return 0;
}

// Output Links
int Node::getNbOutputLinks()
{
	return ((int) outputLinks.size());
}

void Node::addOutputLink(Link* newOutputLink)
{
	outputLinks.push_back(newOutputLink);
}

void Node::updateOutputLink(Link* newOutputLink)
{
	if (!isOutputLinked((Node*) ((Link*) newOutputLink)->getPostNode()))
	{
		if (isSameIndex((Node*) newOutputLink->getPreNode()))
		{
			addOutputLink(newOutputLink);
		}
		else
		{
			newOutputLink->setPreNode((Node*) this);
			addOutputLink(newOutputLink);
		}
	}
}

std::vector<Link*>::iterator Node::getFirstOutputLink()
{
	return outputLinks.begin();
}

std::vector<Link*>::iterator Node::getLastOutputLink()
{
	return outputLinks.end();
}

bool Node::isOutputLinked(Node* postNode)
{
	std::vector<Link*>::iterator itOutput=outputLinks.begin();
	std::vector<Link*>::iterator endOutput=outputLinks.end();

	while (itOutput != endOutput)
	{
		if (((Node*) ((Link*) *itOutput)->getPostNode())->isSameIndex((Node*) postNode))
		{
			return 1;
		}
		itOutput++;
	}

	return 0;
}

Link* Node::eraseOutputLink(Node* postNode)
//Link* Node::removeOutputLink(Node* postNode)
{
	std::vector<Link*>::iterator itOutput=outputLinks.begin();
	std::vector<Link*>::iterator endOutput=outputLinks.end();

	while (itOutput != endOutput)
	{
		if ((Node*) ((Link*) *itOutput)->getPostNode()->isSameIndex(postNode))
		{
			if (postNode->eraseInputLink(this) != 0)
			{
				Link* newProj = (Link*) *itOutput;

				outputLinks.erase(itOutput);
				
				return newProj;
			}
		}
		itOutput++;
	}
	
	return 0;
}

Link* Node::eraseOutputLink(int linkIndex)
{
	if (linkIndex < outputLinks.size())
	{
		Node* postNode = ((Link*) outputLinks[linkIndex])->getPostNode();
		
		if (postNode->eraseInputLink(this) != 0)
		{
			Link* newProj = (Link*) outputLinks[linkIndex];

			int countNbOutputLinks = 0;
				
			std::vector<Link*>::iterator itOutput=outputLinks.begin();
			std::vector<Link*>::iterator endOutput=outputLinks.end();

			while (itOutput != endOutput)
			{
				if (linkIndex == countNbOutputLinks)
				{
					outputLinks.erase(itOutput);
					return newProj;
				}
				countNbOutputLinks++;
				itOutput++;
			}
			
			return 0;
		}
		else
		{
			cerr << "Warning, wrong node index " << postNode->getIndex() <<  endl;
			return 0;
		}
	}
	else
	{
		cerr << "Warning, wrong link index " << linkIndex << " > " << outputLinks.size() << endl;
		return 0;
	}
}

void Node::insertOutputLink(Link* curLink, int linkIndex)
{
	if (0 <= linkIndex && linkIndex < outputLinks.size())
	{
		int countNbOutputLinks = 0;
			
		std::vector<Link*>::iterator itOutput=outputLinks.begin();
		std::vector<Link*>::iterator endOutput=outputLinks.end();
	
		while (itOutput != endOutput)
		{
			if (linkIndex == countNbOutputLinks)
			{
				if (sameIndex(((Node*) ((Link*) curLink)->getPreNode())->getIndex()))
				{
					outputLinks.insert(itOutput,(Link*) curLink);
				}
				else
				{
					cerr << "Warning, wrong link pre node index " << ((Node*) ((Link*) curLink)->getPreNode())->getIndex() << endl;
				}
				return;
			}
			countNbOutputLinks++;
			itOutput++;
		}
	}
	else if (linkIndex == outputLinks.size())
	{
		outputLinks.push_back((Link*) curLink);
	}
	else
	{
		cerr << "Warning, wrong link index " << linkIndex << " > " << outputLinks.size() << endl;
	}
}
/****************************************************************************************************************************************/
/******************************************************* Methodes d'affichage ***********************************************************/
/****************************************************************************************************************************************/

std::ostream& operator<<(std::ostream& f, Node& n)
{
	f << "Node : " << n.index << endl;
	
	std::vector<Link*>::iterator itIn=n.inputLinks.begin();
	std::vector<Link*>::iterator endIn=n.inputLinks.end();

	while(itIn!=endIn)
	{
		f << "input : " << (Link&) (*(*itIn)) << endl;
		itIn++;

	}

	std::vector<Link*>::iterator itOut=n.outputLinks.begin();
	std::vector<Link*>::iterator endOut=n.outputLinks.end();

	while(itOut!=endOut)
	{
		f << "output : " << (Link&) (*(*itOut)) << endl;
		itOut++;

	}

	return f;
}


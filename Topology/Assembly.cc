// Assembly.cc

// Local Includes
#include "Assembly.h"

/****************************************************************************************************************************************/
/****************************************************** Methodes de la classe Assembly **************************************************/
/****************************************************************************************************************************************/

int Assembly::nbAssemblies=0;

Assembly::Assembly()
{
	assemblyNature=-1;

	//index=nbAssemblies;
	nbAssemblies++;

#ifdef _TEST
	cout << "assemblyIndex " << index << endl;;
#endif
#ifdef _TEST
	cout << "AssemblyGrapher: " << evoGrapher << endl;
#endif
}

Assembly::~Assembly()
{
	nbAssemblies--;
}

void Assembly::addNeuron(Neuron* _pNewNeuron)
{
	neurons.push_back(&(*_pNewNeuron));
}

std::vector<Neuron*>::iterator Assembly::getBegin()
{
	return neurons.begin();
}

std::vector<Neuron*>::iterator Assembly::getEnd()
{
	return neurons.end();
}

int Assembly::getNature()
{
	return assemblyNature;
}

int Assembly::getNbInternalInputLinks()
{
	int nbInternalInputLinks = 0;
	
	std::vector<Link*>::iterator itInput=inputLinks.begin();
	std::vector<Link*>::iterator endInput=inputLinks.end();
	
	while (itInput != endInput)
	{
		if (((Node*) ((Link*) *itInput)->getPreNode())->getIndex() < NB_ASSEMBLIES)
		{
			nbInternalInputLinks++;
		}
		itInput++;
	}
	
	return nbInternalInputLinks;
}

int Assembly::getNbInternalOutputLinks()
{
	int nbInternalOutputLinks = 0;
	
	std::vector<Link*>::iterator itOutput=outputLinks.begin();
	std::vector<Link*>::iterator endOutput=outputLinks.end();

	while (itOutput != endOutput)
	{
		if (((Node*) ((Link*) *itOutput)->getPostNode())->getIndex() < NB_ASSEMBLIES)
		{
			nbInternalOutputLinks++;
		}
		itOutput++;
	}

	return nbInternalOutputLinks;
}

Link* Assembly::eraseInternalOutputLink(int linkIndex)
{
	if (0 <= linkIndex && linkIndex < getNbInternalOutputLinks())
	{
		int countNbInternalOutputLinks = 0;
			
		std::vector<Link*>::iterator itOutput=outputLinks.begin();
		std::vector<Link*>::iterator endOutput=outputLinks.end();

		while (itOutput != endOutput)
		{
			if (((Node*) ((Link*) *itOutput)->getPostNode())->getIndex() < NB_ASSEMBLIES)
			{
				if (linkIndex == countNbInternalOutputLinks)
				{
					Node* postNode = ((Link*) *itOutput)->getPostNode();
	
					if (postNode->eraseInputLink(this) != 0)
					{
						Link* newProj = (Link*) *itOutput;

						outputLinks.erase(itOutput);
					
						return newProj;
					}
					else
					{
						cerr << "Warning, wrong node index " << postNode->getIndex() <<  endl;
						return 0;
					}
				}
				countNbInternalOutputLinks++;
			}
			
			itOutput++;
		}
		
		
		cerr << "Warning, unable to find " << linkIndex <<  endl;
		return 0;
		
	}
	else
	{
		cerr << "Warning, wrong link index " << linkIndex << " > " << getNbInternalOutputLinks() << endl;
		return 0;
	}
}

void Assembly::insertInternalOutputLink(Link* curLink, int linkIndex)
{
	if (0 <= linkIndex && linkIndex < getNbInternalOutputLinks())
	{
		int countNbInternalOutputLinks = 0;
			
		std::vector<Link*>::iterator itOutput=outputLinks.begin();
		std::vector<Link*>::iterator endOutput=outputLinks.end();
	
		while (itOutput != endOutput)
		{
			if (((Node*) ((Link*) *itOutput)->getPostNode())->getIndex() < NB_ASSEMBLIES)
			{
				if (linkIndex == countNbInternalOutputLinks)
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
				countNbInternalOutputLinks++;
			}
			itOutput++;
		}
	}
	else if (linkIndex == getNbInternalOutputLinks())
	{
		outputLinks.push_back((Link*) curLink);
	}
	else
	{
		cerr << "Warning, wrong link index " << linkIndex << " > " << getNbInternalOutputLinks() << endl;
	}
}

#ifdef _ALL_TO_ALL_PROJECTION_MODE
void Assembly::buildTotalPostExcitProjection(Assembly* postAssembly)
{
	cerr << "Warning, accessing Assembly::buildTotalPostExcitProjection virtual method" << endl;
}

void Assembly::buildTotalPostInhibProjection(Assembly* postAssembly)
{
	cerr << "Warning, accessing Assembly::buildTotalPostInhibProjection virtual method" << endl;
}
#endif

#ifdef _FIXED_RATIO_PROJECTION_MODE
void Assembly::buildPostExcitProjection(Assembly* postAssembly)
{
	cerr << "Warning, accessing Assembly::buildPostExcitProjection virtual method" << endl;
}

void Assembly::buildPostInhibProjection(Assembly* postAssembly)
{
	cerr << "Warning, accessing Assembly::buildPostInhibProjection virtual method" << endl;
}
#endif

#ifdef _GRAPHICAL_DISPLAY_MODE
void Assembly::initAssemblyDisplayer(AssemblyDisplayer* ad)
{
	displayer = (AssemblyDisplayer*) ad;

	std::vector<Neuron*>::iterator it = neurons.begin();
	std::vector<Neuron*>::iterator end = neurons.end();

	while (it != end)
	{
		//cout << "Initing neuron displayer " << ((Neuron*) *it)->getIndex() << endl;

		((Neuron*) *it)->initNeuronDisplayer((NeuronDisplayer*) displayer);
		it++;
	}
}
void Assembly::display()
{
	if (displayer)
	{
		((AssemblyDisplayer*) displayer)->display((Assembly*) this);
	}
	else
	{
		cerr << "Warning, displayer should be inited" << endl;
	}
}

void Assembly::freeAssemblyDisplayer()
{
	displayer = 0;

	std::vector<Neuron*>::iterator it = neurons.begin();
	std::vector<Neuron*>::iterator end = neurons.end();

	while (it != end)
	{
		((Neuron*) *it)->freeNeuronDisplayer();
		it++;
	}
}
#endif
/****************************************************************************************************************************************/
/****************************************************** Methodes d'affichage console ****************************************************/
/****************************************************************************************************************************************/

std::ostream& operator<<(std::ostream& f, Assembly& a)
{
	f <<  "Assembly" << a.index;

	f << "Nature: " << a.assemblyNature << endl;

	std::vector<Neuron*>::iterator it = a.neurons.begin();
	std::vector<Neuron*>::iterator end = a.neurons.end();

	while (it != end)
	{
		f << ((Neuron&) (*(*it)))<< endl;
		it++;
	}

	return f;
}

// Chromosome.cc

#include "Chromosome.h"

/****************************************************************************************************************************************/
/*************************************************** Methodes de la classe EvoNetwork ***************************************************/
/****************************************************************************************************************************************/

//int Chromosome::nbChromosomes=0;

// Construit un chromosome vide, avec un tableau de genes vides et un fitness à -1
Chromosome::Chromosome()
{
	tabGenes=vector<Gene*>();

	//incrementTopoIndex();

	initFitness();
}

Chromosome::Chromosome(Chromosome& chr)
{
	tabGenes=vector<Gene*>();

	vector<Gene*>::iterator itChr = chr.tabGenes.begin();
	vector<Gene*>::iterator endChr = chr.tabGenes.end();

	while (itChr!=endChr)
	{
		Gene* newG = (Gene*) ((Gene*) *itChr)->clone();
		tabGenes.push_back(newG);
		itChr++;
	}

	//incrementTopoIndex();

	initFitness();
}

void Chromosome::deleteTabGenes()
{
	vector<Gene*>::iterator it = tabGenes.begin();
	vector<Gene*>::iterator end = tabGenes.end();

	while(it!=end)
	{
		delete(*it);
		it++;
	}

	tabGenes.erase(tabGenes.begin(),tabGenes.end());
}

// Construit un chromosome vide, avec un tableau de genes vides et un fitness à -1
Chromosome::~Chromosome()
{
#ifdef _GA_TEST
	cout << "~Chromosome " << getTopoIndex() << endl;
#endif
	if (tabGenes.size())
	{
		deleteTabGenes();
	}

	delete(fitness);
}

// Surcharge de l'opérateur = pour 2 chromosomes
Chromosome &Chromosome::operator=(const Chromosome &chr)
{
	if (this==&chr)
	{
		return *this;
	}

	if (tabGenes.size())
	{
		deleteTabGenes();
	}

	tabGenes=vector<Gene*>(chr.tabGenes.begin(),chr.tabGenes.end());

	return *this;
}

bool Chromosome::operator==(Chromosome &chr)
{
	cout << "Accessing Chromosome operator== " << getTopoIndex() << endl;
	
	vector<Gene*>::iterator it = tabGenes.begin();
	vector<Gene*>::iterator end = tabGenes.end();

	int countIt = 0;
	
	while (it!=end)
	{
		int countNewIt = 0;
		
		vector<Gene*>::iterator newIt = chr.tabGenes.begin();
		vector<Gene*>::iterator newEnd = chr.tabGenes.end();
	
		while (newIt!=newEnd)
		{
			if (countIt == countNewIt)
			{
				if ((Gene&) *(*it) != (Gene&) *(*newIt))
				{
					return 0;
				}
			}
			
			countNewIt++;
			newIt++;
		}
		
		countIt++;
		it++;
		
	}
	return 1;
}

int Chromosome::operator[](int i)
{
	int valueGene=tabGenes[i]->getValueAllele();
	return valueGene;
}

void Chromosome::initChromosome()
{
	/*
	#ifndef _PROJECTION_ENCODING_MODE
	for (int i=0;i<NB_GENES_EACH_CHROMOSOME;i++)
	{
		tabGenes[i].initGene(NB_MAX_GENES);
	}
	#endif
	*/
	#ifdef _PROJECTION_ENCODING_MODE
	for (int i=0;i<NB_PROJECTIONS_EACH_CHROMOSOME;i++)
	{
		#if (NB_GENES_EACH_PROJECTION==3)
		Gene* newGene1 = new Gene(NB_PRE_ASSEMBLIES);
		newGene1->mute();
		tabGenes.push_back(newGene1);

			#ifdef _SELF_INHIBITION_MODE
		Gene* newGene2 = new Gene(MAX_PROJECTION_CODE);
			#else
				#ifdef _VOID_PROJECTION_ENCODING_MODE
		Gene* newGene2 = new Gene(3*MAX_PROJECTION_CODE);
				#else
		Gene* newGene2 = new Gene(2*MAX_PROJECTION_CODE);
				#endif
			#endif
			
		newGene2->mute();
		tabGenes.push_back(newGene2);

		Gene* newGene3 = new Gene(NB_POST_ASSEMBLIES);
		newGene3->mute();
		tabGenes.push_back(newGene3);
		#else
		cerr << "Warning, NB_GENES_EACH_PROJECTION should be 3" << endl;
		#endif
	}
	#endif
}

#ifdef _CLUSTER_EVO_MODE
void Chromosome::reInitChromosome()
{
	
//#ifdef _GA_TEST
	cout << "reInitChromosome " << getTopoIndex() << endl;
//#endif
	if (tabGenes.size())
	{
		deleteTabGenes();
	}

	delete(fitness);
	
	initChromosome();
	initFitness();
}
#endif
void Chromosome::initFitness()
{
	fitness = new Accumulater();
}

double Chromosome::getFitness()
{
	cerr << "Warning, accessing Chromosome::getFitness virtual method" << endl;
}

/******************************************************************************************/
/*                              Methodes de reproduction                                  */
/******************************************************************************************/

// Copie la séquence de genes du chromosome (à partir de i+1)
vector<Gene*> Chromosome::copyGenes(vector<Gene*>::iterator firstGeneIt)
{
#ifdef _GA_TEST
	cout << "In copy genes (chromosome " << getTopoIndex() << ")" << endl;
#endif
	vector<Gene*> tempChromo=vector<Gene*>(firstGeneIt,tabGenes.end());

	return tempChromo;
}

// Remplace la séquence de genes du chromosome(à partir de i+1) par
// les nouveaux genes
void Chromosome::replaceGenes(vector<Gene*>::iterator firstGeneIt,vector<Gene*> newGenes)
{
#ifdef _GA_TEST
	cout << "In replace genes (chromosome " << getTopoIndex() << ")" << endl;
#endif
	tabGenes.erase(firstGeneIt,tabGenes.end());

	vector<Gene*>::iterator newIt = newGenes.begin();
	vector<Gene*>::iterator newEnd = newGenes.end();

	while (newIt!=newEnd)
	{
		Gene* newG = (Gene*) ((Gene*) *newIt)->clone();
		tabGenes.insert(firstGeneIt, newG);
		firstGeneIt=tabGenes.end();
		newIt++;
	}
}

void Chromosome::muteGene(int indexToMute)
{
	tabGenes[indexToMute]->mute();
}

vector<Gene*>::iterator Chromosome::returnGeneIt(int position)
{
	if (position<tabGenes.size())
	{
		vector<Gene*>::iterator it = tabGenes.begin();
		vector<Gene*>::iterator end = tabGenes.end();

		int compt=0;

		while (it!=end)
		{
			if (compt==position)
			{
				return it;
			}

			it++;
			compt++;
		}
	}
	else
	{
		cerr << "Warning, position " << position << " => " << tabGenes.size() << endl;
	}
}

bool CompareChromos::operator()(Chromosome* chromo1, Chromosome* chromo2)
{
	return (chromo1->getFitness()>chromo2->getFitness());
}

/******************************************************************************************/
/*                             Methode d'affichage console                                */
/******************************************************************************************/

ostream& operator<<(ostream& o, Chromosome* c)
{
	//o << c->getTopoIndex() << " " << c->getFitness() << " ";

	copy(c->tabGenes.begin(),c->tabGenes.end(),ostream_iterator<Gene*>(o," "));

	//c->incrementTopoIndex();

	return o;
}

istream& operator>>(istream& i, Chromosome* c)
{
	cout << "Accessing Chromosome >>" << endl;
/*
	int readIndex;
	if (i >> readIndex)
	{
		if (readIndex == c->getTopoIndex())
		{
			cout << "Individual index = " << c->getTopoIndex() << endl;
		}
		else
		{
			cerr << "Warning, read index " << readIndex << " != index " << c->getTopoIndex() << endl;
			
			i.ignore(std::numeric_limits<std::streamsize>::max() ,'\n');
			return i;
		}
	}
	else
	{
		cerr << "Warning, false initialisation of index " << c->getTopoIndex() << " (" << readIndex << ")" << endl;

		i.ignore(std::numeric_limits<std::streamsize>::max() ,'\n');
		return i;
	}
	if (i >> c->fitness)
	{
		cout << "Individual fitness = " << c->fitness << endl;
		//i.ignore(std::numeric_limits<std::streamsize>::max() ,' ');
	}
	else
	{
		cerr << "Warning, false initialisation of fitness " << c->fitness << endl;
		i.ignore(std::numeric_limits<std::streamsize>::max() ,'\n');
		
		return i;
	}
*/
	Gene* g;

	//cout << "peek: " << i.peek() << endl;
/*
	int valueAllele;
	int valueMax;
	
	if (i >> valueAllele)
	{
		cout << "valueAllele " << valueAllele << endl;
	}
	
	if (i >> valueMax)
	{
		cout << "valueMax " << valueMax << endl;
	}
	
	return i;
*/
	while (i >> (g = new Gene()))
	{
		c->tabGenes.push_back(g);

		if (i.peek() == '\n')
		{	
			cout << "Detected end of chromosome" << endl;
			break;
		}

	}
	

	i.ignore(std::numeric_limits<std::streamsize>::max() ,'\n');

	return i;
	
}


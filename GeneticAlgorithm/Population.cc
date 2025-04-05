// Population.cpp

#include "Population.h"

/******************************************************************************************/
/******************************************************************************************/
/*                         Méthodes de gestion de la classe Population                    */
/******************************************************************************************/
/******************************************************************************************/

/******************************************************************************************/
/*                        Constructeur de la classe Population                            */
/******************************************************************************************/

Population::Population()
{	
	initEvoIndex();
	//index=0;
}

// Initialise la population en accord avec le tableau de fonctions tabFonctionVis
/*
void Population::initPopulation()
{
	int comptChromo = 0;

	while (comptChromo<NB_INDIVIDUS)
	{
		Chromosome* chr = new Chromosome();
		chr->initChromosome();
		tabChromosomes.push_back(chr);

		comptChromo++;
	}
}
*/

void Population::initTabChromosomes()
{
	if (tabChromosomes.size())
	{
		cout << "Freeing population with " << tabChromosomes.size() << " chromsomes (nbChromosomes = " << getTopoIndex() << ")" << endl;
		
		deleteTabChromosomes();
		
	}
	else 
	{
		cout << "Tab chromosomes already freed; " << endl;
	}
	
	tabChromosomes = vector<Chromosome*>();	
}

void Population::deleteTabChromosomes()
{
	// Remplace la population courante par la nouvelle population.
	vector<Chromosome*>::iterator it = tabChromosomes.begin();
	vector<Chromosome*>::iterator end = tabChromosomes.end();

	while (it!=end)
	{
		delete((Chromosome*) *it);
		it++;
	}

	tabChromosomes.erase(tabChromosomes.begin(),tabChromosomes.end());

	initTopoIndex();
}
/*
void Population::reInitPopulation()
{
	vector<Chromosome*>::iterator it = tabChromosomes.begin();
	vector<Chromosome*>::iterator end = tabChromosomes.end();

	while (it!=end)
	{
		((Chromosome*) *it)->initFitness();
		it++;
	}
}
*/

/******************************************************************************************/
/*                       Gestion mémoire : destructeur et copie                           */
/******************************************************************************************/

Population::~Population()
{
	deleteTabChromosomes();
}

// Surcharge de l'opérateur = pour 2 populations

Population& Population::operator=(const Population& pop)
{
	if (tabChromosomes.size())
	{
		deleteTabChromosomes();
	}

	tabChromosomes=vector<Chromosome*>(pop.tabChromosomes.begin(),pop.tabChromosomes.end());

	return *this;
}

/******************************************************************************************/
/******************************************************************************************/
/*                         Methode d'affichage console et fichier                         */
/******************************************************************************************/
/******************************************************************************************/

void Population::openSumFitness()
{
	sumFitness.open("sumFitness.sta",ios::app);
}

void Population::closeSumFitness()
{
	sumFitness.close();
}

void Population::sortPopulation()
{
	sort(tabChromosomes.begin(),tabChromosomes.end(),CompareChromos());
}
/******************************************************************************************/
/******************************************************************************************/
/*                    Methodes de modification de la population                           */
/******************************************************************************************/
/******************************************************************************************/

// Méthode d'attibution du fitness des individus de la population
void Population::evaluatePopulation()
{
	cerr << "Warning, accessing virtual method" << endl;
}

void Population::clusterizeChromos()
{
	cerr << "Warning, accessing virtual method" << endl;
}

void Population::selectPopulation()
{
	// Procédure de selection, tant que la nouvelle population n'est pas remplit
	vector<Chromosome*> newTabChromosomes= vector<Chromosome*>();

	// On réinitialise les indexs des futurs chromosomes à 0
	initTopoIndex();

#ifdef _TOURNAMENT_SELECTION_MODE

	cout << "*** Population *** Entering tournament selection mode" << endl;

	#ifdef _ELITIST_SELECTION_MODE

	// On recopie les chromosomes élitistes dans la nouvelle population
	for (int k=0;k<NB_ELITIST_INDIVIDUS;k++)
	{
		#ifdef _GA_TEST
		cout << k << " is elitist " << endl;
		#endif
		sumFitness << k << " is elitist " << endl;
		newTabChromosomes.push_back((Chromosome*) (((Chromosome*) tabChromosomes[k])->clone()));
/*
		cout << "New chromosome:" << endl;
		cout << newTabChromosomes[k];
*/
	}

	// On choisit les autres individus à selectionner
	for (int k=NB_ELITIST_INDIVIDUS;k<NB_INDIVIDUS;k++)
	{
		int selectedChromosomeIndex=-1;
		double bestIndividualFitness=-1.0;

		sumFitness << "( ";
		
		for (int l=0;l<NB_TOURNAMENT_OPPONENTS;l++)
		{
			int newIndividualIndex=randomInt(NB_INDIVIDUS);
			
			sumFitness << newIndividualIndex << " - " << tabChromosomes[newIndividualIndex]->getFitness() << " ";
			
		#ifdef _GA_TEST
			cout << k << " " << l << "Testing individual " << newIndividualIndex;
			cout << " with fitness " << tabChromosomes[newIndividualIndex]->getFitness();
		#endif
			if (bestIndividualFitness<tabChromosomes[newIndividualIndex]->getFitness())
			{
				bestIndividualFitness=tabChromosomes[newIndividualIndex]->getFitness();
				selectedChromosomeIndex=newIndividualIndex;
			}
		}
		
		sumFitness << " ) ";

		if (selectedChromosomeIndex!=-1)
		{
		#ifdef _GA_TEST
			cout << k << " Selected Individual " << selectedChromosomeIndex << " with fitness " << bestIndividualFitness << endl;
		#endif
			sumFitness << k << " Selected Individual " << selectedChromosomeIndex << " with fitness " << bestIndividualFitness << endl;
		}
		else
		{
			selectedChromosomeIndex=randomInt(NB_INDIVIDUS);
			cerr << k << " Warning, selected random Individual " << selectedChromosomeIndex << " with fitness " << bestIndividualFitness << endl;
		}
		newTabChromosomes.push_back((Chromosome*) tabChromosomes[selectedChromosomeIndex]->clone());
/*
		cout << "New chromosome: ";
		cout << newTabChromosomes[k] << endl;
*/
	}
	#endif

	/*
	#ifdef _ISOLATED_SELECTION_MODE
	for (int k=0;k<NB_ISOLATED_ENVT;k++)
	{
		for (int m=0;m<NB_INDIVIDUS_EACH_ISOLATED_ENVT;m++)
		{
			int selectedChromosomeIndex=-1;
			double bestIndividualFitness=0.0;

			for (int l=0;l<NB_TOURNAMENT_OPPONENTS;l++)
			{
				int newIndividualIndex=randomInt(NB_INDIVIDUS_EACH_ISOLATED_ENVT);
				if (bestIndividualFitness<tabChromosomes[k*NB_INDIVIDUS_EACH_ISOLATED_ENVT+newIndividualIndex].fitness)
				{
					bestIndividualFitness=tabChromosomes[k*NB_INDIVIDUS_EACH_ISOLATED_ENVT+newIndividualIndex].fitness;
					selectedChromosomeIndex=newIndividualIndex;
				}
			}

			if (selectedChromosomeIndex!=-1)
			{
		#ifdef _TEST_TRACE_MODE
				printf("Selected Individual %d with fitness %lf\n",selectedChromosomeIndex,bestIndividualFitness);
		#endif
			}
			else
			{
				selectedChromosomeIndex=randomInt(NB_INDIVIDUS_EACH_ISOLATED_ENVT);
		#ifdef _TEST_TRACE_MODE
				printf("Selected Individual %d with fitness %lf\n",selectedChromosomeIndex,bestIndividualFitness);
		#endif
			}

			newPopulation.tabChromosomes[k*NB_INDIVIDUS_EACH_ISOLATED_ENVT+m]=tabChromosomes[k*NB_INDIVIDUS_EACH_ISOLATED_ENVT+selectedChromosomeIndex];
		}
	}
	#endif
	*/
#endif
	deleteTabChromosomes();

	tabChromosomes=newTabChromosomes;

#ifdef _GA_TEST
	cout << "Apres selection" << endl;
	printChromosomes();
#endif
}

void Population::varyPopulation()
{
#ifndef _ELITIST_SELECTION_MODE
	vector<Chromosome*>::iterator itChr = tabChromosomes.begin();

	initTopoIndex();
#endif
#ifdef _ELITIST_SELECTION_MODE
	vector<Chromosome*>::iterator itChr = returnChromoIt(NB_ELITIST_INDIVIDUS);
	setTopoIndex(NB_ELITIST_INDIVIDUS);
#endif
	vector<Chromosome*>::iterator endChr = tabChromosomes.end();

	while (itChr!=endChr)
	{
		int comptGene=0;

		while (comptGene<NB_GENES_EACH_CHROMOSOME)
		{
			mutation(itChr,comptGene);
			crossOver(itChr,comptGene);
			comptGene++;
		}
		itChr++;

		incrementTopoIndex();

		if (NB_INDIVIDUS < getTopoIndex())
		{
			cerr << "Breaking, topo index " << getTopoIndex() << " higher than " << NB_INDIVIDUS << endl;
			break;
		}
	}
}

vector<Chromosome*>::iterator Population::returnChromoIt(int position)
{
	vector<Chromosome*>::iterator it = tabChromosomes.begin();
	vector<Chromosome*>::iterator end = tabChromosomes.end();

	if (0<=position && position<tabChromosomes.size())
	{
		int compt=0;

		while (it!=end)
		{
			if (compt==position)
			{
				return it;
			}
			compt++;
			it++;
		}
	}
	else
	{
		cerr << "Warning, position " << position << " out of tabChromosomes (size = " << tabChromosomes.size() << ")" << endl;
		return end;
	}

}

void Population::mutation(vector<Chromosome*>::iterator chromoIt,int comptGene)
{
	double random=randomProb();

	if (random<PROB_MUTATION)
	{
		((Chromosome*) *chromoIt)->muteGene(comptGene);

#ifdef _GA_TEST
		cout << "Mutation au chromosome " << ((Chromosome*) *chromoIt)->getTopoIndex() << ",gene " << comptGene << " (random= " << random << ")" << endl;
#endif
		sumFitness << "Mutation au chromosome " << ((Chromosome*) *chromoIt)->getTopoIndex() << ",gene " << comptGene << " (random= " << random << ")" << endl;

	 }
}

void Population::crossOver(vector<Chromosome*>::iterator chromoIt,int comptGene)
{
	double random=randomProb();

	if (random<PROB_CROSSOVER)
	{
		if (chromoIt!=tabChromosomes.end())
		{
			vector<Gene*>::iterator crossIt = ((Chromosome*) *chromoIt)->returnGeneIt(comptGene);

			vector<Chromosome*>::iterator nextChromoIt = chromoIt;
			nextChromoIt++;

			if (nextChromoIt!=tabChromosomes.end())
			{
			}
			else
			{
#ifdef _ELITIST_SELECTION_MODE
				nextChromoIt = returnChromoIt(NB_ELITIST_INDIVIDUS);
	#ifdef _GA_TEST
				cout << "Making cross over between first and last non-elitist chromosomes" << endl;
	#endif
#endif
#ifndef _ELITIST_SELECTION_MODE
				nextChromoIt = tabChromosomes.begin();
	#ifdef _GA_TEST
				cout << "Making cross over between first and last chromosomes" << endl;
	#endif
#endif
			}

			vector<Gene*>::iterator nextCrossIt = ((Chromosome*) *nextChromoIt)->returnGeneIt(comptGene);

			vector<Gene*> tmpGenes=((Chromosome*) *chromoIt)->copyGenes(crossIt);
			vector<Gene*> tmpGenes2=((Chromosome*) *nextChromoIt)->copyGenes(nextCrossIt);

			((Chromosome*) *chromoIt)->replaceGenes(crossIt,tmpGenes2);
			((Chromosome*) *nextChromoIt)->replaceGenes(nextCrossIt,tmpGenes);
		}
		else
		{
			cerr << "Warning, wrong chromoIt" << endl;
		}
#ifdef _GA_TEST
		cout << "Point de cross-over au chromosome " << ((Chromosome*) *chromoIt)->getTopoIndex() << ",gene " << comptGene << " (random= " << random << ")" << endl;
#endif
		sumFitness << "Point de cross-over au chromosome " << ((Chromosome*) *chromoIt)->getTopoIndex() << ",gene " << comptGene << " (random= " << random << ")" << endl;
	}
}


ostream& operator<<(ostream& o, Population* pop)
{
	copy(pop->tabChromosomes.begin(),pop->tabChromosomes.end(),ostream_iterator<Chromosome*>(o,"\n"));
	
	return o;
}
/*
istream& operator>>(istream& i, Population* pop)
{
	Chromosome* c = new Chromosome();

	while (i >> c)
	{
		pop->tabChromosomes.push_back(c);
		
		if (i.eof())
		{
			cerr << "End of file detected" << endl;
			break;
		}

		c = new Chromosome();
	}
	
	delete(c);
	
	return i;
}
*/

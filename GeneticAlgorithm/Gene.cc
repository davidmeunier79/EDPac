// Gene.cc

#include "Gene.h"

/******************************************************************************************/
/******************************************************************************************/
/*                            Méthodes de gestion de la classe Gene                     */
/******************************************************************************************/
/******************************************************************************************/

/******************************************************************************************/
/*                          Constructeur de la classe Gene                                */
/******************************************************************************************/

int Gene::nbGenes=0;

Gene::Gene()
{
	valueAllele=-1;
	valueMax=-1;
}

Gene::Gene(const Gene& g)
{
	valueAllele=g.valueAllele;
	valueMax=g.valueMax;

	index=nbGenes;
	nbGenes++;
}

Gene::Gene(int newValueMax)
{
	valueAllele=-1;
	valueMax=newValueMax;

	index=nbGenes;
	nbGenes++;

}

Gene* Gene::clone()
{
	//cout << "Accessing Gene clone" << endl;
	return new Gene(*this);
}

Gene& Gene::operator=(const Gene& g)
{
	cout << "Accessing Gene operator=" << endl;

	if(&g==this)
	{
		return *this;
	}

	valueAllele=g.valueAllele;
	valueMax=g.valueMax;

	return *this;
}


bool Gene::operator==(const Gene& g)
{
#ifdef _GA_TEST
	cout << "Accessing Gene operator== " << index << endl;
#endif
	if(valueAllele == g.valueAllele && valueMax == g.valueMax)
	{
		return 1;
	}
	return 0;
}

bool Gene::operator!=(const Gene& g)
{
#ifdef _GA_TEST
	cout << "Accessing Gene operator!= " << index << endl;
#endif	
	if(valueAllele != g.valueAllele || valueMax != g.valueMax)
	{
		return 1;
	}
	return 0;
}

void Gene::initGene(int newValueMax)
{
	valueMax=newValueMax;
}

int Gene::getValueAllele()
{
	return valueAllele;
}

Gene::~Gene()
{
#ifdef _GA_TEST
	cout << "~Gene " << index << endl;
#endif
}

/******************************************************************************************/
/*                          Définit la mutation sur un gene                               */
/******************************************************************************************/
			
void Gene::mute()
{
	valueAllele=randomInt(valueMax);
}

/******************************************************************************************/
/*                            Méthode d'affichage console                                */
/******************************************************************************************/

std::ostream& operator<<(std::ostream& o, Gene* g)
{
	o << g->valueAllele << " " << g->valueMax;
	return o;
}

std::istream& operator>>(std::istream& i, Gene* g)
{
#ifdef _GA_TEST
	cout << "Accessing Gene >>" << endl;
#endif
	int readValue=0;
	int readValueMax=0;
	
	if (i >> readValue >> readValueMax)
	{
		 g->valueAllele = readValue;
		 g->valueMax = readValueMax;
#ifdef _GA_TEST
		cout << "Value allele = " << g->valueAllele << endl;
		cout << "Value max = " << g->valueMax << endl;
#endif
	}
	else
	{
		cerr << "Warning, false value for value allele " << readValue << endl;
		cerr << "Warning, false value for value max " << readValueMax << endl;
	}
	
	i.ignore(std::numeric_limits<std::streamsize>::max() ,' ');

	return i;

}




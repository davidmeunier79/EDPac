// ObjetSensitif.cc

#include "ObjetSensitif.h"

/*********************************************************************************************/
/*                                                                                           */
/*                      Definitions des methodes de ObjetSensitif                            */
/*                                                                                           */
/*********************************************************************************************/

ObjetSensitif::ObjetSensitif()
{}

ObjetSensitif::ObjetSensitif(int taille2)
{
  for(int i=0;i<taille2;i++)
  {
    push_back(1.0);
  }
}
ObjetSensitif::ObjetSensitif(const vector<double> & aCopier) : vector<double>(aCopier)
{}

ObjetSensitif::ObjetSensitif(double *representant2,int taille2)
{
  setRepresentant(representant2,taille2);
}

ObjetSensitif::ObjetSensitif(const double *representant2,int taille2)
{
  setRepresentant(representant2,taille2);
}

ObjetSensitif & ObjetSensitif::operator=(const ObjetSensitif & aCopier)
{
  if(this==&aCopier)
    return *this;

  clear();
  reserve(aCopier.getTaille());
  for(int i=0;i<aCopier.getTaille();i++)
    push_back(aCopier[i]);
  return *this;
}

int ObjetSensitif::getTaille() const
{
  return size();
}

void ObjetSensitif::setRepresentant(const double * representant2,int taille2)
{
  clear();
  reserve(taille2);
  for(int i=0;i<taille2;i++)
    push_back(representant2[i]);
}

void ObjetSensitif::setRepresentant(double * representant2,int taille2)
{
  clear();
  reserve(taille2);
  for(int i=0;i<taille2;i++)
    push_back(representant2[i]);
}

void ObjetSensitif::setRepresentant(const vector<double> & representant2)
{
  clear();
  reserve(representant2.size());
  for(int i=0;i<representant2.size();i++)
    push_back(representant2[i]);
}

void ObjetSensitif::init(string nomFichier)
{
  int taille;

  // creation de l'image
  ifstream f;
  f.open(nomFichier.data(),ifstream::in);
  if(!f)
    {
      cerr<<"fichier image non trouve : "<<nomFichier<<endl;
      return;
    }
  f.ignore(100,':');
  f>>taille;
  double * tab = new double [taille];
  for(int i=0;i<taille;i++)
    {
      f>>tab[i];
    }
  setRepresentant(tab,taille);
  delete [] tab;
}

void ObjetSensitif::sauver(string nomFichier) const
{
  ofstream f;
  f.open(nomFichier.data(),ofstream::out | ofstream::trunc);
  if(!f)
    {
      cerr<<"fichier image non trouve : "<<nomFichier<<endl;
      return;
    }
  f<<"taille : "<<getTaille()<<'\n';
  for(int i=0;i<getTaille();i++)
    {
      f<<(*this)[i]<<' ';
    }
  f.close();
}

// on ne peu pas brouiller un objet sans savoir ce que c'est !
void ObjetSensitif::brouiller(float distance)
{
  vector<double>::iterator it=(*this).begin();
  vector<double>::iterator end=(*this).end();
  
  while (it!=end)
  {
  	*it = ((double) *it)*(randomProb());
  	it++;
  }
  
}

ObjetSensitif * ObjetSensitif::clone() const
{
  return new ObjetSensitif(*this);
}


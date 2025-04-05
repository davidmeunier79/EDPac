// Menagerie.cc

#include "Menagerie.h"

/*********************************************************************************************/
/*                                                                                           */
/*                        Definitions des methodes de Menagerie                              */
/*                                                                                           */
/*********************************************************************************************/

Menagerie::Menagerie()
{
  init("./menagerie");
}

Menagerie::Menagerie(string nomDossier)
{
  init(nomDossier);
}

void Menagerie::init(string nomDossier)
{
  int categ,gentil,taille;
  string nomFR,nomUK;

  ifstream f;
  f.open((nomDossier+"/menagerie.txt").data(),ifstream::in);
  if(!f)
    {
      cerr<< "fichier de menagerie non trouve : " << "./menagerie/menagerie.txt"<<endl;
      return;
    }

  f.ignore(100,':');
  f>>taille;
  f.ignore(100,':');
  f>>nbrePac;

  listeAnimaux.reserve(taille);
  for(int i=0;i<taille;i++)
    {
      f>>nomUK;
      f>>nomFR;
      f>>categ;
      f>>gentil;
      listeAnimaux.push_back(new Animal (nomFR,nomUK,categ,static_cast<Personnalite>(gentil)));
    }
  f.close();
}

int Menagerie::getTaille() const
{
  return listeAnimaux.size();
}

int Menagerie::getNbrePac() const
{
  return listeAnimaux.size();
}

const Animal & Menagerie::operator[](int indice) const
{
  if(indice>=0)
    return *listeAnimaux[indice];
  else
    return *listeAnimaux[listeAnimaux.size()-nbrePac-1-indice];
}

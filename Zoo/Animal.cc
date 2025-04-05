// Animal.cc

#include "Animal.h"

/*********************************************************************************************/
/*                                                                                           */
/*                         Definitions des methodes de Animal                                */
/*                                                                                           */
/*********************************************************************************************/

Animal::Animal(string nomFR2,string nomUK2,Categorie categorie2,Personnalite gentil2)
  : nomFR(nomFR2),nomUK(nomUK2),categorie(categorie2), image(0), son(0), gentil(gentil2)
{
  image = new Image("./menagerie/"+nomFR+"/"+nomFR+".img");
  son = new Son("./menagerie/"+nomFR+"/"+nomFR+".son");
}

Animal::Animal(const Animal & aCopier)
  : nomFR(aCopier.nomFR),nomUK(aCopier.nomUK),categorie(aCopier.categorie),image(0),son(0),gentil(aCopier.gentil)
{
  if(aCopier.image)
    image = new Image (*aCopier.image);
  if(aCopier.son)
    son = new Son (*aCopier.son);
}

Animal::~Animal()
{
  if(image)
    delete image;
  if(son)
    delete son;
}

string Animal::getNomFR() const
{
  return nomFR;
}

string Animal::getNomUK() const
{
  return nomUK;
}

Categorie Animal::getCategorie() const
{
  return categorie;
}

Personnalite Animal::getPersonnalite() const
{
  return gentil;
}

const ObjetSensitif * Animal::getModalite(int numModalite) const
{
  switch(numModalite)
    {
    case 0 :
      return image;
    case 1 :
      return son;
    }
}

Animal * Animal::clone() const
{
  return new Animal(*this);
}

// Animal.h

#ifndef _ANIMAL_H
#define _ANIMAL_H

//#include <list>
using namespace std;

// Local Includes
#include "../Define.h"
#include "../DefineZoo.h"

#include "ObjetSensitif.h"

#include "Son.h"
#include "Image.h"

// un Animal apartient a une categorie et est represente par un ObjetSensitif dans chaque modalite
class Animal
{
 private:
  string nomFR,nomUK;
  Personnalite gentil;
  Categorie categorie;
  Image * image;
  Son * son;
 public:
  // constructeurs destructeur et opérateurs courant.
  Animal(string nomFR2,string nomUK2,Categorie categ,Personnalite gentil2);
  Animal(const Animal & aCopier);
  virtual ~Animal();
  virtual Animal * clone() const;
  // acces aux donnees
  string getNomFR() const;
  string getNomUK() const;
  Categorie getCategorie() const;
  Personnalite getPersonnalite() const;
  // getModalite permet de numeroter les modalites
  const ObjetSensitif * getModalite(int numModalite) const;
};

#endif

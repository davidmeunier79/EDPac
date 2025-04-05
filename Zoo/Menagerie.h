// Menageerie.h

#ifndef _MENAGERIE_H
#define _MENAGERIE_H

#include <string>
#include <vector>
using namespace std;

// Local Includes
#include "Animal.h"

// une menagerie est un ensemble d'animaux
class Menagerie
{
 private:
  vector<Animal *> listeAnimaux;
  int nbrePac;
 public:
  // constructeurs
  Menagerie();
  Menagerie(string nomDossier);
  // pour initialiser la menagerie
  void init(string nomDossier);
  // acceseur en lecture uniquement
  int getTaille() const;
  int getNbrePac() const;
  const Animal  & operator[](int indice) const; 
};

#endif

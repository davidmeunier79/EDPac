// Image.h

#ifndef _IMAGE_H
#define _IMAGE_H

//#include <cstdlib>
#include <string>
//#include <iostream>
//#include <fstream>
//#include <vector>

// Local Includes
#include "ObjetSensitif.h"

using namespace std;

class Image : public ObjetSensitif
{
private :
  int hauteur,largeur;
public :
  Image();
  Image(int taille);
  Image(string nomFichier);
  Image(ObjetSensitif base,int hauteur,int largeur);
  void init(string nomFichier);
  void sauve(string nomFichier) const;
  int getHauteur() const;
  int getLargeur() const;
  double getValeur(int x,int y) const;
  virtual void brouiller(float distance);
  virtual Image * clone() const;
};

#endif



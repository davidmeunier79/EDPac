// ObjetSensitif.h

#ifndef _OBJET_SENSITIF_H
#define _OBJET_SENSITIF_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Local Includes
#include "../MathTools/RandomMathTools.h"

/*********************************************************************************************/
/*                                                                                           */
/*                     Définition des objets generaux du programme                           */
/*                                                                                           */
/*********************************************************************************************/

// un ObjetSensitif represente par exemple une image ou un son
// c'est ce q'il y a de plus general
// les autres objets doivent heriter de lui
class ObjetSensitif : public vector<double>
{
public :
   // constructeurs et destructeur
  ObjetSensitif();
  ObjetSensitif(int taille2);
  ObjetSensitif(const vector<double> &);
  ObjetSensitif(const double * representant2,int taille2);
  ObjetSensitif(double * representant2,int taille2);
  // operateur =
  ObjetSensitif & operator=(const ObjetSensitif & aCopier);
  // acces aux données
  int getTaille() const;
  void setRepresentant(const vector<double> &);
  void setRepresentant(const double * representant2,int taille2);
  void setRepresentant(double * representant2,int taille2);
  void init(string nomFichier);
  void sauver(string nomFichier) const;
  // brouillage de l'objet
  virtual void brouiller(float distance);
  // la fonction clone renvoie un duplicata de this aloue dynamiquement
  virtual ObjetSensitif * clone() const;
};

// la categorie est representee par un entier car c'etait le cas dans le prgm original
// possibilite de changer (pour un string par exemple)
typedef int Categorie;

#endif

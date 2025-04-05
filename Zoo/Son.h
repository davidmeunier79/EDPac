// Son.h

#ifndef _SON_H
#define _SON_H

#include <string>
using namespace std;

// Local Includes
#include "ObjetSensitif.h"

using namespace std;

class Son : public ObjetSensitif
{
public :
  Son();
  Son(int taille);
  Son(string nomFichier); 
  virtual void brouiller(float distance);
  virtual Son * clone() const;
};

#endif

// Palette.h

#ifndef _PALETTE_H
#define _PALETTE_H

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/keysym.h>
#include "cursor"
#include "cmask"

//#include <iostream>
#include <string>
#include <map>
//#include <cstdio>
using namespace std;

// Local Includes
class Palette;
#include "EnvGraph.h"

// Variables globales servant à paramètrer le pacman

#define EVENTMASK (ExposureMask | KeyPressMask | ButtonPressMask) // evenements geres par les fenetres

// la palette  est cree par l'environement graphique
// elle contient les coucleurs rangees par leur nom
class Palette : public map<string,XColor>
{
  friend class EnvGraph;
private :
  Colormap cmap;  // Palette des couleurs utilisées au sens de X-Window
  Palette(Display * display);
  ~Palette();
public :
  bool existe(const string & couleur);
  void ajouteCouleur(const string & couleur,int R,int V,int B);
  void retireCouleur(const string & couleur);
};

#endif

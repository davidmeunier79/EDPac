// EnvGraph.h

#ifndef _ENV_GRAPH_H
#define _ENV_GRAPH_H

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/keysym.h>
//#include "cursor"
//#include "cmask"

#include <iostream>
//#include <string>
//#include <map>
//#include <cstdio>
//using namespace std;

// Local Includes
#include "Palette.h"

// l'environnement graphique represente la fenetre mere
// on ne dessinera rien a l'interieur sauf dans des fenetres
// on suppose ici qu'il n'y a qu'un ecran (donc c'est un singleton) donc une palette

#define ENVGRAPH (EnvGraph::getInstance())
#define PALETTE  (EnvGraph::getInstance().getPalette())
#define DISPLAY  (EnvGraph::getInstance().getDisplay())

class EnvGraph
{
private :
  Display * display;           // canal d'affichage
  Palette * palette;           // couleurs  utilisees dans l'application
  static EnvGraph * instance;  // unique instance du singleton
  // consrtucteur et destructeur
  EnvGraph();
  ~EnvGraph();
public:
  static EnvGraph & getInstance();
  // acces aux attributs
  Palette & getPalette();
  Display * getDisplay();
};

#endif

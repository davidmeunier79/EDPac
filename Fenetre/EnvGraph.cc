// EnvGraph.cc

#include "EnvGraph.h"

/*************************************************************************************************
 *                                                                                               *
 *                                      Classe EnvGraph                                          *
 *                                                                                               *
 *************************************************************************************************/

EnvGraph * EnvGraph::instance=0;

EnvGraph::EnvGraph()
{
  if((display=XOpenDisplay(NULL)) == NULL )
    {
      cerr<<"Le canal d'affichage n'a pas pu être initialisé !"<<endl;
      return;
    }
  palette = new Palette(display);
}

EnvGraph::~EnvGraph()
{
  delete palette;
  XCloseDisplay( display );
}

EnvGraph & EnvGraph::getInstance()
{
  if(!instance)
    instance = new EnvGraph;
  return *instance;
}

Palette & EnvGraph::getPalette()
{
  return *palette;
}

Display * EnvGraph::getDisplay()
{
  return display;
}

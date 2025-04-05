// ImagePixmap.h

#ifndef _IMAGE_PIXMAP_H
#define _IMAGE_PIXMAP_H

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/keysym.h>
//#include "cursor"
//#include "cmask"

//#include <iostream>
//#include <string>
//#include <map>
//#include <cstdio>

// Local Includes
#include "Fenetre.h"

using namespace std;

// pour stocker les images
// dans l'absolu seule la classe fenetre en a besoin
// j'ai tout de meme mis les constructeurs/destructeur en public pour plus de souplesse
class ImagePixmap
{
friend class Fenetre;
private :
  Pixmap image;
  unsigned int largeur,hauteur,x_hot,y_hot;
public :
  ImagePixmap();
  ImagePixmap(Pixmap image2,unsigned int largeur2,unsigned int hauteur2,int x_hot2,int y_hot2);
  ~ImagePixmap();
};

#endif

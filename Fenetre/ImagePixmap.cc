// ImagePixmap.cc

#include "ImagePixmap.h"

/*************************************************************************************************
 *                                                                                               *
 *                                     Classe Image                                              *
 *                                                                                               *
 *************************************************************************************************/

ImagePixmap::ImagePixmap()
{}

ImagePixmap::ImagePixmap(Pixmap image2,unsigned int largeur2,unsigned int hauteur2,int x_hot2,int y_hot2)
  : image(image2),hauteur(hauteur2),largeur(largeur2),x_hot(x_hot2),y_hot(y_hot2)
{}

ImagePixmap::~ImagePixmap()
{
  XFreePixmap(DISPLAY, image);
}

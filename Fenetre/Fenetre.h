// Fenetre.h

#ifndef _FENETRE_H
#define _FENETRE_H

#include <X11/Xlib.h>
#include <X11/xpm.h>

#include <X11/Xutil.h>
#include <X11/keysym.h>
//#include "cursor"
//#include "cmask"

// NEW
#define _POSIX_C_SOURCE 200809L

#include <iostream>
#include <string>
#include <map>
// sprinf (NEW)
#include <cstdio>

using namespace std;

// Local Includes
#include "EnvGraph.h"
class ImagePixmap;
#include "ImagePixmap.h"

// classe permettant la création et la gestion d'une fenêtre sous X
class Fenetre
{
private :
  // attributs pour la Xlib
  Window winX;                 // la fenêtre au sens du systeme X-Window
  string titre,iconeTitre;     // ce qui apparaitra dans la barre de la fenetre
  Pixmap buffer;               // buffer contenant le fenetre entiere
  GC contextGraph;             // context graphique pour l'affichage
  Cursor curseur;              // curseur dans la fenetre
  // methode privee pour ne pas trop se repeter
  void init(const Window & mere,const string & titre2,const string & iconeTitre2);
  // methodes associees aux evenements (et methodes par defaut)
  void (*expose)();
  void (*buttonPress)(int,int);
  map<KeySym,void (*)()> reflexes;
  // ensemble d'images directement affichables
  map<string,ImagePixmap*> images;

public :
  // constructeur et destructeur
  Fenetre();
  Fenetre(const string & titre2,const string & iconeTitre2="");
  Fenetre(Fenetre * mere);
  Fenetre(Fenetre * mere,const string & titre2,const string & iconeTitre2);
  ~Fenetre();
  // methodes d'acces aux differents attributs
  string getTitre(void);
  void setTitre(const string & titre2);
  string getIconeTitre(void);
  void setIconeTitre(const string & iconTitre2);
  void getPosition(int &x, int &y);
  void setPosition(int x, int y);
  void getDimensions(int &l, int &h);
  void setDimensions(int l, int h);
  void setExpose(void (*expose2)());
  void setButtonPress(void (*buttonPress2)(int,int));
  void setKeyPress(string key,void (*keyPress2)());
  string getEvenements();


  // methodes de gestion des images
  void initImage(const string & etiquette,const string & fichier,const string &couleur);
  void initImage(const string & fichier,const string &couleur);
  void placeImage(const string & etiquette, int x, int y);
  void saveXpmImage(string fileName);

  // methodes de dessin et d'affichage dans la fenetre
  void affiche(void);
  void redessine(void);
  void afficheTexte(const string & txt, int x, int y,const string & couleur="noir");
  void traceLigne(int x1,int y1,int x2,int y2,const string & couleur="noir");
  void colorierZone(int x,int y,unsigned int l,unsigned int h,const string & couleur="noir");


  void effacer(void);
  void ferme(void);
};

#endif



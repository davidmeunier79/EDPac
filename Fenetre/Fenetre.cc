// Fenetre.cc

#include "Fenetre.h"

/*************************************************************************************************
 *                                                                                               *
 *                                    Classe Fenetre                                             *
 *                                                                                               *
 *************************************************************************************************/

Fenetre::Fenetre()
{
  init(DefaultRootWindow(DISPLAY),"","");
}

Fenetre::Fenetre(const string & titre2,const string & iconeTitre2)
{
  init(DefaultRootWindow(DISPLAY),titre2,iconeTitre2);
}

Fenetre::Fenetre(Fenetre *  mere)
{
  init(mere->winX,"","");
}

Fenetre::Fenetre(Fenetre *  mere,const string & titre2,const string & iconeTitre2)
{
  init(mere->winX,titre2,iconeTitre2);
}

Fenetre::~Fenetre()
{
  // destruction des images
  map<string,ImagePixmap*>::iterator iter;
  for(iter=images.begin();iter!=images.end();iter++)
    delete (*iter).second;

  // destruction des attributs
  XDestroyWindow(DISPLAY,winX);
  XFreeGC(DISPLAY,contextGraph);
  XFreeCursor(DISPLAY,curseur);
}

void Fenetre::init(const Window & mere,const string & titre2,const string & iconeTitre2)
{
  titre=titre2;
  iconeTitre=iconeTitre2;

  // creation de la fenetre
  winX = XCreateSimpleWindow(DISPLAY, mere, 0, 0, 300, 300, 1, PALETTE["noir"].pixel, PALETTE["blanc"].pixel);
  XSetStandardProperties(DISPLAY, winX, titre.data(), iconeTitre.data(), None, 0, 0, 0 );
  XSelectInput(DISPLAY, winX, EVENTMASK);

  // affichage de la fenetre
  XMapWindow(DISPLAY, winX );
  XFlush(DISPLAY);
  buffer = XCreatePixmap(DISPLAY, winX, 300, 300, DefaultDepth(DISPLAY,DefaultScreen(DISPLAY)));

  // creation du curseur
  Pixmap curs_bmap,cmask_bmap;
  curs_bmap = XCreateBitmapFromData(DISPLAY, winX, cursor_bits, cursor_width, cursor_height);
  cmask_bmap = XCreateBitmapFromData(DISPLAY, winX, cmask_bits,cmask_width, cmask_height);
  curseur = XCreatePixmapCursor(DISPLAY, curs_bmap, cmask_bmap,&PALETTE["jaune"], &PALETTE["marron"], cursor_x_hot, cursor_y_hot );
  XDefineCursor(DISPLAY, winX, curseur );

  // creation du contexte graphique
  XGCValues tmp;
  contextGraph=XCreateGC(DISPLAY,winX,0,&tmp);
  Font chFont = XLoadFont(DISPLAY, "9x15" ) ;
  XSetFont(DISPLAY, contextGraph, chFont);
  XSetForeground(DISPLAY,contextGraph,PALETTE["blanc"].pixel);
  XSetBackground(DISPLAY,contextGraph,PALETTE["blanc"].pixel);
 
  // actions si evenements
  expose=0;
  buttonPress=0;
}

void Fenetre::getPosition(int &x, int &y)
{
  XWindowAttributes attributs;
  XGetWindowAttributes(DISPLAY, winX, &attributs);

  x = attributs.x;
  y = attributs.y;
}

void Fenetre::setPosition(int x, int y)
{
  unsigned int maskAttributs;
  XWindowChanges newAttributs;

  maskAttributs = CWX | CWY;
  newAttributs.x = x;
  newAttributs.y = y;
  
  XConfigureWindow(DISPLAY, winX, maskAttributs, & newAttributs);
  //XFlush(DISPLAY);
}

void Fenetre::getDimensions(int &l, int &h)
{
  XWindowAttributes attributs;
  XGetWindowAttributes(DISPLAY, winX, &attributs);

  l = attributs.width;
  h = attributs.height;
}

void Fenetre::setDimensions(int l, int h)
{
  unsigned int maskAttributs;
  XWindowChanges newAttributs;
  
  maskAttributs = CWWidth | CWHeight;
  newAttributs.width = l;
  newAttributs.height = h;

  XConfigureWindow(DISPLAY, winX, maskAttributs, & newAttributs);
  //XFlush(DISPLAY);
  XFreePixmap(DISPLAY,buffer);
  buffer = XCreatePixmap( DISPLAY, winX, l, h, DefaultDepth(DISPLAY,DefaultScreen(DISPLAY)));
  XFillRectangle(DISPLAY,buffer,contextGraph,0,0,l,h);
  XCopyArea(DISPLAY, winX, buffer, contextGraph, 0, 0, l, h, 0, 0);  
}

string Fenetre::getTitre(void)
{
  return titre;
}

void Fenetre::setTitre(const string & titre2)
{
  titre=titre2;
  XSetStandardProperties(DISPLAY, winX, titre.data(), iconeTitre.data(), None, 0, 0, 0 );  
}

string Fenetre::getIconeTitre(void)
{
  return iconeTitre;
}

void Fenetre::setIconeTitre(const string & iconeTitre2)
{
  iconeTitre=iconeTitre2;
  XSetStandardProperties(DISPLAY, winX, titre.data(), iconeTitre.data(), None, 0, 0, 0 );
}

void Fenetre::setExpose(void (*expose2)())
{
  expose=expose2;
}

void Fenetre::setButtonPress(void (*buttonPress2)(int,int))
{
  buttonPress=buttonPress2;
}

void Fenetre::setKeyPress(string key,void (*keyPress2)())
{
  KeySym touche=XStringToKeysym(key.data());
  reflexes[touche]=keyPress2;
}

// cette fonction applique les evenements de la pile concernant la fenetre
// chaque evenement n'est traité qu'une fois, les aures occurences sont ignorées
string Fenetre::getEvenements()
{
  string retour="";
  XEvent event;
  // pour indiquer si on a déja traité un de ces evenements
  bool apparait=false,button=false,key=false;

  while(XCheckWindowEvent(DISPLAY, winX, EVENTMASK, & event))
    {
      switch(event.type)
	{
	case ButtonPress :
	  // si l'evenement est deja survenu, on l'ignore
	  if(button)
	    break;
	  // sinon on le traite
	  button=true;
	  char tmp[100];
	  sprintf(tmp,"ButtonPress at x=%i and y=%i",event.xbutton.x,event.xbutton.y);
	  if(retour=="")
	    retour=tmp;
	  else
	    retour+=tmp;
	  if(buttonPress)
	    buttonPress(event.xbutton.x,event.xbutton.y);
	  break;
	case KeyPress :
	  if(key)
	    break;
	  key=true;
	  if(retour=="")
	    retour="KeyPress";
	  else
	    retour+="et KeyPress";
	  KeySym touche;
	  XLookupString(&(event.xkey), 0, 0, &touche, 0);
	  // printf("%s\n", XKeysymToString(touche)); // mettre cette ligne pour afficher les noms des touches utilisees
	  if(reflexes.find(touche)!=reflexes.end() && reflexes[touche]!=NULL)
	    reflexes[touche]();
	  break;
	case Expose :
	  if(apparait)
	    break;
	  apparait=true;
	  if(retour=="")
	    retour="Expose";
	  else
	    retour+="et Expose";
	  redessine();
	  if(expose)
	    expose();
	  break;
	}
    }
   
  return retour;
}


void Fenetre::initImage(const string & fichier,const string &couleur)
{
  initImage(fichier,fichier,couleur);
}

void Fenetre::initImage(const string &etiquette,const string &fichier,const string &couleur)
{
  int c;
  unsigned int largeur, hauteur;
  int x_hot, y_hot;
  Pixmap image;
  char pixmapData[1000];
  FILE * f;

  f = fopen(fichier.data(),"r");
  if( f == NULL )
    {
      cerr << "le fichier '" << fichier <<  "' n'a pas pu être ouvert" << endl;
      cerr << "Le pixmap correspondant ne sera pas cree" << endl;
      return;
    }

  while(fgetc(f)!=' ');
  while(fgetc(f)!=' ');
  fscanf(f, "%i\n", &largeur);
  while(fgetc(f)!=' ');
  while(fgetc(f)!=' ');
  fscanf(f, "%i\n", &hauteur);
  if(fgetc(f)=='#')
    {
      while(fgetc(f)!=' ');
      while(fgetc(f)!=' ');
      fscanf(f, "%i\n", &x_hot);
      while(fgetc(f)!=' ');
      while(fgetc(f)!=' ');
      fscanf(f, "%i\n", &y_hot);
    }
  else
    x_hot=y_hot=-1;

  while(fgetc(f)!='{');
  int k=0;
  do
    {
      int nbrHexa;
      if((c=fgetc(f))!='\n')
	ungetc(c,f);
      fscanf (f, "%X", &nbrHexa);
      pixmapData[k++] = (char)nbrHexa;
    }
  while(fgetc(f)==',');
  fclose(f);

  Pixmap aSauver;
  aSauver=XCreatePixmapFromBitmapData (DISPLAY, winX,(char*)pixmapData,largeur,hauteur,
				       PALETTE[couleur].pixel, PALETTE["blanc"].pixel,
				       DefaultDepth(DISPLAY,DefaultScreen(DISPLAY)));

  images[etiquette]=new ImagePixmap(aSauver,largeur,hauteur,x_hot,y_hot);
}

void Fenetre::placeImage(const string & etiquette, int x, int y)
{
  ImagePixmap *aPlacer=images[etiquette];

  XSetForeground(DISPLAY,contextGraph,PALETTE["blanc"].pixel);
  XCopyArea(DISPLAY,aPlacer->image,buffer,contextGraph,0,0,aPlacer->largeur,aPlacer->hauteur,x,y);
  XCopyArea(DISPLAY,aPlacer->image,winX,contextGraph,0,0,aPlacer->largeur,aPlacer->hauteur,x,y);
}

void Fenetre::saveXpmImage(string filename)
{
	XpmAttributes* newXPMA =0;
	
	char* c_fileName = strdup (filename.c_str());

	switch (XpmWriteFileFromPixmap(DISPLAY,c_fileName,buffer,0,newXPMA))
	{
		case XpmOpenFailed:
		cerr << "Warning, unable to save bitmap file " << filename << " , XpmOpenFailed" << endl; 
		break;
		case XpmNoMemory:
		cerr << "Warning, unable to save bitmap file " << filename << " , XpmNoMemory" << endl;
		break;
		case XpmSuccess:
		break;
		default:
		break;
	}
	
	delete(c_fileName);
}

void Fenetre::affiche(void)
{
  XMapWindow(DISPLAY, winX);
}

void Fenetre::redessine(void)
{
  int l,h;
  getDimensions(l,h);
  XCopyArea(DISPLAY, buffer, winX, contextGraph, 0, 0, l, h, 0, 0 );
  XFlush(DISPLAY);
}

void Fenetre::afficheTexte(const string & txt, int x, int y, const string & col)
{
  XSetForeground(DISPLAY,contextGraph,PALETTE[col].pixel);
  XDrawString (DISPLAY, buffer, contextGraph, x, y, txt.data(), txt.size());
}

void Fenetre::traceLigne(int x1, int y1, int x2, int y2, const string & col)
{
  XSetForeground(DISPLAY,contextGraph,PALETTE[col].pixel);
  XDrawLine(DISPLAY, buffer, contextGraph, x1, y1, x2, y2);
}

void Fenetre::colorierZone(int x, int y, unsigned int l, unsigned int h,const string & col)
{
  XSetForeground(DISPLAY,contextGraph,PALETTE[col].pixel);
  XFillRectangle(DISPLAY,buffer,contextGraph,x,y,l,h);
}

void Fenetre::effacer(void)
{
  int l,h;
  getDimensions(l,h);
  XClearWindow(DISPLAY,winX);
  XSetForeground(DISPLAY,contextGraph,PALETTE["blanc"].pixel);
  XFillRectangle(DISPLAY,buffer,contextGraph,0,0,l,h);
}

void Fenetre::ferme(void)
{
  XUnmapWindow(DISPLAY, winX);
}


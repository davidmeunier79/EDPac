// Palette.cc

#include "Palette.h"

/*************************************************************************************************
 *                                                                                               *
 *                                       Classe Palette                                          *
 *                                                                                               *
 *************************************************************************************************/

// lors de la creation on fabrique les couleurs les plus communes
// possibilite d'en ajouter/retirer ensuite
Palette::Palette(Display * display)
  : cmap(DefaultColormap(display,DefaultScreen(display)))
{
  XColor exacte,approche;
  
  XAllocNamedColor(display,cmap,"yellow",&exacte,&approche);
  (*this)["yellow"]=approche;
  (*this)["jaune"]=approche;

  XAllocNamedColor(display,cmap,"blue",&exacte,&approche);
  (*this)["blue"]=approche;
  (*this)["bleu"]=approche;

  XAllocNamedColor(display,cmap,"red",&exacte,&approche);
  (*this)["red"]=approche;
  (*this)["rouge"]=approche;

  XAllocNamedColor(display,cmap,"green",&exacte,&approche);
  (*this)["green"]=approche;
  (*this)["vert"]=approche;

  XAllocNamedColor(display,cmap,"cyan",&exacte,&approche);
  (*this)["cyan"]=approche;

  XAllocNamedColor(display,cmap,"magenta",&exacte,&approche);
  (*this)["magenta"]=approche;

  XAllocNamedColor(display,cmap,"coral",&exacte,&approche);
  (*this)["coral"]=approche;
  (*this)["orange"]=approche;

  XAllocNamedColor(display,cmap,"pink",&exacte,&approche);
  (*this)["pink"]=approche;
  (*this)["rose"]=approche;

  XAllocNamedColor(display,cmap,"brown",&exacte,&approche);
  (*this)["brown"]=approche;
  (*this)["marron"]=approche;

  XAllocNamedColor(display,cmap,"violet",&exacte,&approche);
  (*this)["violet"]=approche;

  XAllocNamedColor(display,cmap,"greenyellow",&exacte,&approche);
  (*this)["greenyellow"]=approche;
  (*this)["vertjaune"]=approche;

  XAllocNamedColor(display,cmap,"gray",&exacte,&approche);
  (*this)["gray"]=approche;
  (*this)["gris"]=approche;

  XAllocNamedColor(display,cmap,"black",&exacte,&approche);
  (*this)["black"]=approche;
  (*this)["noir"]=approche;

  XAllocNamedColor(display,cmap,"white",&exacte,&approche);
  (*this)["white"]=approche;
  (*this)["blanc"]=approche;
}

Palette::~Palette()
{}

bool Palette::existe(const string & couleur) 
{
  return (find(couleur) != end());
}

void Palette::ajouteCouleur(const string & couleur,int R,int V,int B)
{
  if(existe(couleur))
    {
      cerr<<"couleur "+couleur+" deja existante. Ajout non fait.\n"
	  << "il faut d'abord supprimer l'ancienne couleur"<<endl;
      return;
    }

  XColor newCouleur;
  newCouleur.red=R;
  newCouleur.green=V;
  newCouleur.blue=B;
  XAllocColor(DISPLAY,cmap,&newCouleur);
  (*this)[couleur]=newCouleur;
}

void Palette::retireCouleur(const string & couleur)
{
  if(!existe(couleur))
    {
      cout<<"couleur "+couleur+" deja inexistante. Retrait non fait.\n";
      return;
    }
  else
    erase(couleur);
}

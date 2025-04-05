// Image.cc

#include "Image.h"

/*********************************************************************************************/
/*                                                                                           */
/*                          Definitions des methodes de Image                                */
/*                                                                                           */
/*********************************************************************************************/

Image::Image() : ObjetSensitif()
{
  hauteur=1;
  largeur=getTaille();
}

Image::Image(int taille) : ObjetSensitif(taille)
{
}

Image::Image(string nomFichier) : ObjetSensitif()
{
  init(nomFichier);
}

Image::Image(ObjetSensitif base,int hauteur2,int largeur2) : ObjetSensitif(base)
{
  if(getTaille()!=hauteur*largeur)
    {
      cerr<<"taille de l'image incompatible avec le vecteur"<<endl;
      hauteur=1;
      largeur=getTaille();
      return;
    }
  hauteur=hauteur2;
  largeur=largeur2;
}

void Image::init(string nomFichier)
{
  char tmp;
  double * tab;

  // creation de l'image
  ifstream f;
  f.open(nomFichier.data(),ifstream::in);
  if(!f)
    {
      cerr<<"fichier image non trouve : "<<nomFichier<<endl;
      return;
    }
  f.ignore(100,':');
  f>>hauteur;
  f.ignore(100,':');
  f>>largeur;
  tab = new double [hauteur*largeur];
  for(int i=0;i<hauteur;i++)
    {
      f.ignore(100,'"');
      for(int j=0;j<largeur;j++)
	{
	  f>>tmp;
	  //tab[i*largeur+j] = (tmp=='#') ? 1 : 0;
	  tab[i*largeur+j] = (tmp=='#') ? 0 : 1;
	}
      f.ignore(100,'"');
    }
  setRepresentant(tab,hauteur*largeur);
  delete [] tab;
}

void Image::sauve(string nomFichier) const
{
  ofstream f;
  f.open(nomFichier.data(),ofstream::out | ofstream::trunc);
  if(!f)
    {
      cerr<<"fichier image non trouve : "<<nomFichier<<endl;
      return;
    }
  f<<"hauteur : "<<hauteur<<'\n';
  f<<"largeur : "<<largeur<<'\n';
  for(int i=0;i<hauteur;i++)
    {
      f<<'"';
      for(int j=0;j<largeur;j++)
	{
	  if((*this)[i*hauteur+j]==1)
	    f<<'#';
	  else
	    f<<'.';
	}
      f<<'"'<<','<<'\n';
    }
  f.close();
}

void Image::brouiller(float distance)
{
  const int bruitVisio=20;

  //srand(time(NULL));
  if(distance<1)
    distance=1;
  int taux = static_cast<int>(bruitVisio*(distance-1));
  for(int i = 0; i < taux; i++)
    {
      int x = rand()%hauteur;
      int y = rand()%largeur;
      (*this)[y+largeur*x] = !(*this)[y+largeur*x];
    }
}

int Image::getHauteur() const
{
  return hauteur;
}

int Image::getLargeur() const
{
  return largeur;
}

double Image::getValeur(int x,int y) const
{
  return (*this)[x+y*largeur];
}

Image* Image::clone() const
{
  return new Image(*this);
}

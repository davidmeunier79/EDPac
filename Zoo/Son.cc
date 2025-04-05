// Son.cc

#include "Son.h"

/*********************************************************************************************/
/*                                                                                           */
/*                           Definitions des methodes de Son                                 */
/*                                                                                           */
/*********************************************************************************************/

Son::Son() : ObjetSensitif()
{}

Son::Son(int taille) : ObjetSensitif(taille)
{
}

Son::Son(string nomFichier) : ObjetSensitif()
{
  ifstream f;
  double min,max;
  int taille2;
  double * tab;

  f.open(nomFichier.data(),ifstream::in);
  if(!f)
    {
      cerr<<"fichier son non trouve : "<<nomFichier<<endl;
      return;
    }
  f.ignore(100,':');
  f>>taille2;
  tab = new double [taille2];
  for(int i=0;i<taille2;i++)
    f>>tab[i];
  min=max=tab[0];
  for(int i=1;i<taille2;i++)
    {
      min=tab[i]<min ? tab[i] : min;
      max=tab[i]>max ? tab[i] : max;
    }
  for(int i=0;i<taille2;i++)
    tab[i]=(tab[i]-min)/(max-min); 
  setRepresentant(tab,taille2);
  delete [] tab;
}

void Son::brouiller(float distance)
{
  const double bruitAudio=0.07;
  static int tmp = 0;

  srand(time(NULL));
  if(distance<1)
    distance=1;
  double taux = bruitAudio*(distance-1);
  for (int i = 0; i < getTaille(); i++)
    {
      double nbralea = static_cast<double>(rand()%10000)/10000;
      double point = (*this)[i] + taux*(nbralea-0.5);
      if( point < 0 )
	point = 0;
      if( point > 1 )
	point = 1;
      (*this)[i]=point;
    }
}

Son * Son::clone() const
{
  return new Son(*this);
}



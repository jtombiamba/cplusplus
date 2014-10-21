#include "Voiture.h"

using namespace std;

Voiture::Voiture():Vehicule(), m_nbPortes(5)
{

}


Voiture::Voiture(int prix):Vehicule(prix),m_nbPortes(5)
{

}



Voiture::Voiture(int prix, int nbPortes):Vehicule(prix),m_nbPortes(nbPortes)
{

}


void Voiture::affiche() const
{

  cout << endl << "Cette voiture coute " << m_prix << endl << "\tElle a " << m_nbPortes << "portes \n" << endl;

}


int Voiture::nb_Roues()
{

  return 4;
}


Voiture::~Voiture()
{

}

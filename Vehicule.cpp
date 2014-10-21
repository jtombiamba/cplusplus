#include "Vehicule.h"

using namespace std;

Vehicule::Vehicule():m_prix(1000)
{

}


Vehicule::Vehicule(int prix):m_prix(prix)
{

}


void Vehicule::affiche() const
{
  cout << "Ceci est un vehicule qui coute " << m_prix << endl;

}

//void Vehicule::presente(Vehicule const& vic) const
//{
//  vic.affiche();
//}


Vehicule::~Vehicule()
{

}

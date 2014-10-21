#include "Moto.h"

using namespace std;



Moto::Moto():Vehicule(),m_vitesse(45)
{

}


Moto::Moto(int prix):Vehicule(prix), m_vitesse(45)
{


}


Moto::Moto(int prix, int vitesse):Vehicule(prix), m_vitesse(vitesse)
{


}



int Moto::nb_Roues()
{
  return 2;
}

void Moto::affiche() const
{
  cout << endl << "Ce véhicule est une Moto qui coute " << m_prix << endl << "\tIl va a " << m_vitesse << " KM/H\n" << endl;

}

Moto::~Moto()
{

}

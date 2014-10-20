#include "Sorcier.h"

using namespace std;

//Lors de l'initialisation des constructeurs de classes filles, on appelle d'abord via la liste d'initialisation
//les classes dont elles tiennent leurs heritages
Sorcier::Sorcier(): Personnage()
{

}

int Sorcier::lancerSortilege()
{

}

//MASQUAGE DE FONCTIONS: fait de nommer de manière identique une fonction de la classe mère dans la classe fille
//Dans ce cas, c'est la fonction qui a été développé dans la classe fille qui sera visible lors de l'appel de celle-ci et non celle de la classe mere

void Sorcier::afficher(ostream& flux) const
{
  flux << "Je suis Un grand Sorcier" << endl;
  //Ici on peut faire du démasquage, en rajoutant la classe qui portait cette méthode auparavant(ici Personnage) 
  Personnage::afficher(flux);
}

Sorcier::~Sorcier()
{

}

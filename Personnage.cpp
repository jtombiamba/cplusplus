//#include <iostream>
//#include <string>
#include "Personnage.h"

using namespace std;

Personnage::Personnage():m_vie(100), m_mana(50), m_nomArme("Basic sword"), m_degatsArme(10)
{

}

Personnage::Personnage(int vie, int mana):m_vie(vie), m_mana(mana), m_nomArme("Basic sword"), m_degatsArme(10)
{

}

Personnage::Personnage(string nomArme, int degatsArme):m_vie(100), m_mana(50), m_nomArme(nomArme), m_degatsArme(degatsArme)
{

}

//constructeur de copie, on accede directement aux attributs de l'objet que l'on veut copier, sans erreur de private
Personnage::Personnage(Personnage const& other): m_vie(other.m_vie), m_mana(other.m_mana), m_nomArme(other.m_nomArme), m_degatsArme(other.m_degatsArme)
{

}

void Personnage::recevoirDegats(int nbDegats)
{


}

void Personnage::attaquer(Personnage &cible)
{

}

void Personnage::boirePotionDeVie(int quantitePotion)
{

}

void Personnage::changerArme(string nomNouvelleArme, int degatsNouvelleArme)
{


}

// Methode constante,ne modifie pas un attribut de la classe/objet
bool Personnage::estVivant() const
{

}

Personnage::~Personnage()
{

}

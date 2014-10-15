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

///GETTERS
int Personnage::getm_vie()
{
  return m_vie;
}

int Personnage::getm_mana()
{
  return Personnage::m_mana;
}

string Personnage::getm_nomArme()
{
  return Personnage::m_nomArme;
}

int Personnage::getm_degatsArme()
{
  return Personnage::m_degatsArme;
}

///SETTERS
void Personnage::setm_vie(int vie)
{
  Personnage::m_vie = vie;
}
void Personnage::setm_mana(int mana)
{
  Personnage::m_mana = mana;
}

void Personnage::setm_nomArme(string nomArme)
{
  Personnage::m_nomArme = nomArme;
}

void Personnage::setm_degatsArme(int degatsArme)
{
  Personnage::m_degatsArme = degatsArme;
}


//OTHER METHODS
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
  m_nomArme = nomNouvelleArme;
  m_degatsArme = degatsNouvelleArme;

}

// Methode constante,ne modifie pas un attribut de la classe/objet
bool Personnage::estVivant() const
{

}

//Methode (donc dans la classe) qui va tester l'égalitay
bool Personnage::Equals(Personnage const& second) const
{
  if((m_vie == second.m_vie) && (m_mana == second.m_mana))
    return true;
  else
    return false;
}


Personnage::~Personnage()
{

}


//Faire une surcharge d'operateurs de ce type nous permet de nous passer des getters et setters
//car elle fait juste appel à une fonction de la classe qui est dejà implémentée
bool operator==(Personnage const& first, Personnage const& second)
{
  return first.Equals(second);
}

//On declare le second en const Personnage car on ne va pas le modifier, ni faire une copie mémoire de celle-ci pour les op
Personnage& Personnage::operator+=(const Personnage& second)
{
  m_vie = m_vie + second.m_vie;
  m_mana = m_mana + second.m_mana;
  if (m_degatsArme < second.m_degatsArme)
    {
      m_degatsArme = second.m_degatsArme;
      m_nomArme = second.m_nomArme;
    } 
  return *this;


  //  Personnage superMe;
  //superMe = first.Fusion(second);
  //return superMe;
}



//SURCHARGE DE FLUX
//flux = référencement de l'objet unique cout de ostream qui a été créé lors de l'appel de <iostream> 
void Personnage::afficher(ostream &flux) const
{
  flux << "Vie         : " << m_vie << endl;
  flux << "Mana        : " << m_mana << endl;
  flux << "nom Arme    : " << m_nomArme << endl;
  flux << "Degats Arme : " << m_degatsArme << endl;
  
}

ostream& operator<<(ostream &flux, Personnage const& perso)
{
  perso.afficher(flux);
  return flux;
}

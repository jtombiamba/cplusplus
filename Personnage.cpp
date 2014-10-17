//#include <iostream>
//#include <string>
#include "Personnage.h"
#include "Arme.h"

using namespace std;

Personnage::Personnage():m_vie(100), m_mana(50), m_arme()
{

}

Personnage::Personnage(int vie, int mana):m_vie(vie), m_mana(mana), m_arme()
{

}

Personnage::Personnage(string nomArme, int degatsArme):m_vie(100), m_mana(50), m_arme(nomArme,degatsArme)
{

}

//constructeur de copie, on accede directement aux attributs de l'objet que l'on veut copier, sans erreur de private
Personnage::Personnage(Personnage const& other): m_vie(other.m_vie), m_mana(other.m_mana), m_arme(other.m_arme)
{

}

///GETTERS
int Personnage::getm_vie() const
{
  return m_vie;
}

int Personnage::getm_mana() const
{
  return Personnage::m_mana;
}

Arme Personnage::getm_arme() const
{
  return m_arme;
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


void Personnage::setm_arme(string nomArme, int degatsArme)
{
  m_arme.setm_nomArme(nomArme);
  m_arme.setm_degatsArme(degatsArme);
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

void Personnage::changerArme(string nomArme, int degatsArme)
{
  //m_nomArme = nomNouvelleArme;
  //m_degatsArme = degatsNouvelleArme;
  //setm_arme(arme.getm_nomArme(), arme.getm_degatsArme());
  m_arme.changer(nomArme, degatsArme);
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
  if (m_arme.getm_degatsArme() < second.getm_arme().getm_degatsArme())
    {
      setm_arme(second.getm_arme().getm_nomArme(),second.getm_arme().getm_degatsArme());
      //m_arme.setm_degatsArme(second.getm_arme().getm_degatsArme());
      //m_arme.setm_nomArme(second.getm_nomArme().getm_nomArme());
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
  flux << m_arme;
  //flux << "nom Arme    : " << m_nomArme << endl;
  //flux << "Degats Arme : " << m_degatsArme << endl;
  
}

ostream& operator<<(ostream &flux, Personnage const& perso)
{
  perso.afficher(flux);
  return flux;
}

#include "Arme.h"

using namespace std;

Arme::Arme():m_nomArme("Basic Sword"),m_degatsArme(50)
{

}

Arme::Arme(string nomArme, int degatsArme):m_nomArme(nomArme),m_degatsArme(degatsArme)
{

}

Arme::Arme(Arme const& other):m_nomArme(other.m_nomArme),m_degatsArme(other.m_degatsArme)
{

}

string Arme::getm_nomArme() const
{
  return m_nomArme;
}

int Arme::getm_degatsArme() const
{
  return m_degatsArme;
}

void Arme::setm_nomArme(string nomArme)
{
  m_nomArme = nomArme;
}

void Arme::setm_degatsArme(int degatsArme)
{
  m_degatsArme = degatsArme;
}

void Arme::changer(string nomArme, int degatsArme)
{
  m_nomArme = nomArme;
  m_degatsArme = degatsArme;
}

void Arme::afficher(ostream& flux) const
{
  flux << "nom Arme    : " << m_nomArme << endl;
  flux << "Degats Arme : " << m_degatsArme << endl;
}


Arme::~Arme()
{

}

ostream& operator<<(ostream& flux, Arme const& weapon)
{
  weapon.afficher(flux);
  return flux;
}

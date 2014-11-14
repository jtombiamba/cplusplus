#include "ZFraction.h"

//definition du domaine de fonctions qui sera utilisé
using namespace std;



//Constructeur par défaut, aucun argument
Fraction::Fraction():m_num(0), m_den(1)
{

}



//Premiere surcharge de constructeur
Fraction::Fraction(int entier)
{

}



Fraction::Fraction(int num, int den):m_num(num), m_den(den)
{
  if(m_den == 0){
    cout << "cannot create this fraction(zero division)" << endl;
    cout << " Zeroing the fraction"  << endl;
    m_den = 1;
    m_num = 0;
  }
}


//Constructeur de copie, other ne sera pas modifié, donc déclaré en const 
//et comme on ne veut pas une copie supplémentaire dans la pile de l'objet other, on le référence directement avec &
Fraction::Fraction(Fraction const& other):m_num(other.m_num), m_den(other.m_den)
{

}



//va modifier les attributs de sa classe donc est référencé et return le pointeur sur lui mm *this (de type Fraction)
//tandis que "this" est de type "Fraction*" qui est une adresse
Fraction& Fraction::operator+=(Fraction const& other)
{
  if(m_den == other.m_den)
    {
      m_num += other.m_den; 
    }
  else
    {
      m_num = m_den * other.m_num + other.m_den * m_num;
      m_den = m_den * other.m_den;
    }
  return *this;
}




void Fraction::afficher(ostream& flux) const
{
  flux << m_num << "/" << m_den;
}



bool Fraction::biggerOrEqual(Fraction const& other) const
{
  int a(m_num * other.m_den), b(m_den * other.m_num);
  if(a >= b) return true;
  else return false;
}



Fraction& Fraction::reduce()
{
  //partie algo d'euclide
  int a, b,r(-1);
  if(m_num <= m_den)
    {
      a = m_den;
      b = m_num;
    }
  else
    {
      a = m_num;
      b = m_den;
    }
  
  while(r!=0)
    {
      r = a%b;
      if(r == 1) break;
      a = b;
      if(r!=0) b = r;
    };
    
    //partie reduction
  if(r!=0)
    {
      m_num = m_num / r;
      m_den = m_den / r;
    }
  else
    {
      m_num = m_num / b;
      m_den = m_den / b;
    }
    return *this;
}



//surcharge de l'operateur "<<" sur une sortie ostream
//mais étant donné qu'il n'y a qu'une unique instance de ostream qui est créée à chaque lancement du programme, il est directement référencé
ostream& operator<<(ostream& flux, Fraction const& frac)
{
  frac.afficher(flux);
  return flux;
}



Fraction operator+(Fraction const& first, Fraction const& second)
{
  Fraction copie(first);
  copie+=second;
  return copie;
}

bool operator>=(Fraction const& first, Fraction const& second)
{
  return first.biggerOrEqual(second);
}

Fraction::~Fraction()
{

}

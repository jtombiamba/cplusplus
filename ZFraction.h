#ifndef DEF_ZFRACTION
#define DEF_ZFRACTION


#include <iostream>
#include <string>


class Fraction
{
  // attributs
 private:
  int m_num;
  int m_den;

  //methodes
 public:

  Fraction();
  Fraction(int entier);
  Fraction(int num, int den);
  Fraction(Fraction const& other);

  Fraction& reduce();
  Fraction& operator+=(Fraction const& other);
  void afficher(std::ostream &flux) const;
  bool biggerOrEqual(Fraction const& other) const;

  ~Fraction();

};

std::ostream& operator<<(std::ostream &flux, Fraction const& frac);


Fraction operator+(Fraction const& first, Fraction const& second);

bool operator>=(Fraction const& first, Fraction const& second);

#endif

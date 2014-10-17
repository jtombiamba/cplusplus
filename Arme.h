#ifndef DEF_ARME
#define DEF_ARME

#include <iostream>
#include <string>


class Arme
{

 private:

  std::string m_nomArme;
  int m_degatsArme;

 public:

  Arme();
  Arme(std::string nomArme, int degatsArme);
  Arme(Arme const& other);

  std::string getm_nomArme() const;
  int getm_degatsArme() const;

  void setm_nomArme(std::string nomArme);
  void setm_degatsArme(int degatsArme);

  void afficher(std::ostream &flux) const;
  void changer(std::string nomArme, int degatsArme);

  ~Arme();

};

std::ostream& operator<< (std::ostream &flux, Arme const& weapon);

#endif

#ifndef DEF_VEHICULE
#define DEF_VEHICULE

#include <iostream>
#include <string>

class Vehicule 
{
 protected:
  int m_prix;

 public:
  Vehicule();
  Vehicule(int prix); // les constructeurs ne peuvent pas etre virtuelles
  virtual int nb_Roues() = 0; // méthode virtuelle pure ==> classe abstraite ==> aucune instanciation possible
  virtual void affiche() const; //methode virtuelle
  //virtual void presente(Vehicule const& vic) const;
  virtual ~Vehicule(); //le destructeur peut etre virtuel car ...

};



#endif

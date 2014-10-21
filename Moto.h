#ifndef  DEF_MOTO
#define DEF_MOTO

#include <iostream>
#include <string>
#include "Vehicule.h"


class Moto: public Vehicule
{
 private:
  int m_vitesse;

 public:
  Moto();
  Moto(int prix);
  Moto(int prix, int m_vitesse);

  virtual int nb_Roues();
  virtual void affiche() const;

  virtual ~Moto();


};

#endif

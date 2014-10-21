#ifndef DEF_VOITURE
#define DEF_VOITURE

#include <iostream>
#include <string>
#include "Vehicule.h"


class Voiture : public Vehicule
{
 private:
  int m_nbPortes;

 public:
  Voiture();
  Voiture(int nbPortes);
  Voiture(int prix, int nbPortes);
  virtual int nb_Roues();
  virtual void affiche() const;
  //virtual void presente()
  virtual ~Voiture();
};

#endif

#ifndef DEF_SORCIER
#define DEF_SORCIER

#include <iostream>
#include <string>
#include "Personnage.h"

class Sorcier : public Personnage
{

 public:
  Sorcier();
  int lancerSortilege();
  virtual void afficher(std::ostream& flux) const;
  ~Sorcier();
};

#endif

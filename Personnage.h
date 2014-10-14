#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <iostream>
#include <string>

  // CLASS
  class Personnage
  {

    //Attributs
  private: 
    int m_vie;
    int m_mana;
    std::string m_nomArme;
    int m_degatsArme;

    //Methodes
  public:
    Personnage();
    Personnage(std::string nomArme, int degatsArme); //surcharge 1
    Personnage(int vie, int mana); //surchage 2

    Personnage(Personnage const& other); // constructeur de copie surchargé

    void recevoirDegats(int nbDegats);

    void attaquer(Personnage &cible);

    void boirePotionDeVie(int quantitePotion);
    
    void changerArme(std::string nomNouvelleArme, int degatsNouvelleArme)
      ;
    bool estVivant() const;  //methode constante

    ~Personnage();

  };


#endif

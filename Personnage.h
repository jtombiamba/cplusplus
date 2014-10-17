#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <iostream>
#include <string>
#include "Arme.h"

  // CLASS
  class Personnage
  {

    //Attributs
  private: 
    int m_vie;
    int m_mana;
    Arme m_arme;

    //Methodes
  public:
    Personnage();
    Personnage(std::string nomArme, int degatsArme); //surcharge 1
    Personnage(int vie, int mana); //surchage 2

    Personnage(Personnage const& other); // constructeur de copie surchargé

    //getters et setters
    int getm_vie() const;
    int getm_mana() const;
    Arme getm_arme() const;

    void setm_vie(int vie);
    void setm_mana(int mana);
    void setm_arme(std::string nomArme, int degatsArme);

    void recevoirDegats(int nbDegats);

    void attaquer(Personnage& cible);

    void boirePotionDeVie(int quantitePotion);
    
    void changerArme(std::string nomArme, int degatsArme);   
    
    //void changerArme(std::string nomNouvelleArme, int degatsNouvelleArme);

    void afficher(std::ostream& flux) const;

    // Cette surcharge d'operateur "+=" est déclarée dans la classe puisqu'elle va modifier les attributs de
    //l'objet qui l'utilise, donc par encapsulation, elle est insérée dans la classe
    Personnage& operator+=(Personnage const& second);

    bool Equals(Personnage const& second) const;

    bool estVivant() const;  //methode constante

    ~Personnage();

  };

// surcharge de l'operateur "==" relative à la classe Personnage, utilisation de référence constante pour éviter les copies
bool operator==(Personnage const& first, Personnage const& second);

std::ostream& operator<< (std::ostream& flux, Personnage const& perso);

#endif

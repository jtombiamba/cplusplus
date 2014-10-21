#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <iostream>
#include <string>
#include "Arme.h"

  // CLASS
  class Personnage
  {

    //Attributs
    // private: // droit d'accès interessant mais trop restrictif
  protected: // droit d'accès permettant aux futurs  classes filles de pouvoir accéder à ces attributs facilement 
    int m_vie;
    int m_mana;
    Arme *m_arme;

    //Methodes
  public:
    Personnage();
    Personnage(std::string nomArme, int degatsArme); //surcharge 1
    Personnage(int vie, int mana); //surchage 2

    Personnage(Personnage const& other); // constructeur de copie surchargé

    //Si le constructeur de copie est redéfini et qu'il y a des attributs en pointeur
    //il est impératif de surcharger l'operateur "=" pour s'eviter les problèmes de pointage


    //getters et setters
    int getm_vie() const;
    int getm_mana() const;
    Arme* getm_arme() const;

    void setm_vie(int vie);
    void setm_mana(int mana);
    void setm_arme(std::string nomArme, int degatsArme);

    void recevoirDegats(int nbDegats);

    void attaquer(Personnage& cible);

    void boirePotionDeVie(int quantitePotion);
    
    void changerArme(std::string nomArme, int degatsArme);   
    
    //void changerArme(std::string nomNouvelleArme, int degatsNouvelleArme);

    virtual void afficher(std::ostream& flux) const;

    // Cette surcharge d'operateur "+=" est déclarée dans la classe puisqu'elle va modifier les attributs de
    //l'objet qui l'utilise, donc par encapsulation, elle est insérée dans la classe
    Personnage& operator+=(Personnage const& second);

    //Cette surcharge d'operateur "=" est déclarée dans la classe puisqu'elle aussi va modifier les attributs et va permettre
    //de ne pas faire de confusion avec le constructeur de copie
    Personnage& operator=(Personnage const& other);

    bool Equals(Personnage const& second) const;

    bool estVivant() const;  //methode constante

    ~Personnage();

  };

// surcharge de l'operateur "==" relative à la classe Personnage, utilisation de référence constante pour éviter les copies
bool operator==(Personnage const& first, Personnage const& second);

std::ostream& operator<< (std::ostream& flux, Personnage const& perso);

#endif

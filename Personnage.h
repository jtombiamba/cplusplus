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

    //getters et setters
    int getm_vie();
    int getm_mana();
    std::string getm_nomArme();
    int getm_degatsArme();

    void setm_vie(int vie);
    void setm_mana(int mana);
    void setm_nomArme(std::string nomArme);
    void setm_degatsArme(int degatsArme);

    void recevoirDegats(int nbDegats);

    void attaquer(Personnage &cible);

    void boirePotionDeVie(int quantitePotion);
    
    void changerArme(std::string nomNouvelleArme, int degatsNouvelleArme);

    void afficher(std::ostream &flux) const;

    // Cette surcharge d'operateur "+=" est déclarée dans la classe puisqu'elle va modifier les attributs de
    //l'objet qui l'utilise, donc par encapsulation, elle est insérée dans la classe
    Personnage& operator+=(Personnage const& second);

    bool Equals(Personnage const& second) const;

    bool estVivant() const;  //methode constante

    ~Personnage();

  };

// surcharge de l'operateur "==" relative à la classe Personnage, utilisation de référence constante pour éviter les copies
bool operator==(Personnage const& first, Personnage const& second);

std::ostream& operator<< (std::ostream &flux, Personnage const& perso);

#endif

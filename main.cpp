#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>
#include "template.h"



using namespace std; //spécifier le lot dans lequel on travaille (si deux fct identiques dans iostream et string, permet de faire un choix)



//un passage de param par valeur effectue une copie de la valeur du param dans une autre case memoire 
//pas fameux pour les perfs

//doxygen documentation creation for further use
/**
 * \brief (describes the utility of the function) 
 * \param a (name of the parameter and eventually its utility)
 * \return (describes the return value of the function)
 */

int ajouteDeuxVal(int a){
  a+=2;  
  return a;
}



//un passage de param par référence modifie profondément la valeur de la variable (param) passé à l'appel
// eviter une recopie mémoire(un passage par valeur fait une simple copie mem)
void echange(int& a, int& b){
  int temporaire(a);  
  a = b;  
  b= temporaire;
}


//******************************MAIN*****************************//

int main(){

  //simple variables
  int age(23);
  int const family(5);
  double const carre(25);
  bool adulte(true);


  int& newAge(age); // referencement de variable, very useful(premier truc) = ré-étiquettage d'une zone mémoire 


  string texte_a_lire(" et je fais du sport");  //peut etre considéré comme un tableau aussi 
  string name("No name??");

  // CLASS
  class Personnage
  {

    //Attributs
  private: 
    int m_vie;
    int m_mana;
    string n_nomArme;
    int m_degatsArme;

    //Methodes
  public:
    void recevoirDegats(int nbDegats)
    {

    }

    void attaquer(Personnage &cible)
    {

    }

    void boirePotionDeVie(int quantitePotion)
    {

    }

    void changerArme(string nomNouvelleArme, int degatsNouvelleArme)
    {

    }

    bool estVivant()
    {

    }

  };



  cout << "///////////////////////////////////////////////////////////////////////////" << endl;  
  cout << "Hello World!" << endl << "j'ai "<< age << " ans !!" << texte_a_lire << endl;
  cout << "nouvel age (via reference) " << newAge << endl;
  cout << "et vous quel est votre age? " << endl;
  cin  >> newAge;
  cin.ignore(); // A mettre absolument à chaque fois qu'on mélange les chevrons et les getline(sinon getline récupere n'importe koi) 



  cout << "Et quel est votre nom? " << endl;
  getline(cin, name);

  cout << "Bonjour " << name << endl;
  cout << "Bravo, votre age est de " << newAge << " ans" << endl;
  cout << "///////////////////////////////////////////////////////////////////////////\n" << endl;
  cout <<  "La racine carre de " << carre <<  " est " << sqrt(carre) << endl;
  cout << "age au fait vaut maintenant " << age <<  endl; 




 cout << "///////////////////////////////////////////////////////////////////////////\n" << endl;


  if(newAge >= 21){
    adulte = true;
  }
  else{
    adulte = false;
  }

  if(adulte){
    cout << "Attention à la loi, vous êtes adulte " << name << " !" << endl;
  }
  else{
    cout << "Pas de taule pour vous, " << name << " , mais ne faites pas trop de bêtises !!" << endl;
  }



 cout << "///////////////////////////////////////////////////////////////////////////\n" << endl;


  //début de différence C/C++ tableau de taille variable (vector)
  vector<int> VariableArray(family, 0); // déclaration et initialisation à 0
  vector<int> noElement; //déclaration sans élément à la base

  //à ce niveau, on rajoute à la fin du tableau une case initialisée
  VariableArray.push_back(5);

  //on peut aussi supprimer la derniere case
  VariableArray.pop_back();

  //cela implique de savoir comment retrouver la taille de ce vector
  cout << "VariableArray a une taille de " << VariableArray.size() << " éléments" << endl << " noElement lui en a " << noElement.size() << " élément(s)" << endl;


  //Un tableau dynamique multi-dimensionnel
  vector<vector<int> > multiArray;


  //on ajoute au tableau des lignes -- Remarque les lignes peuvent avoir des tailles differentes 
  multiArray.push_back(vector<int>(5));
  multiArray.push_back(vector<int>(10));


  //on peut aussi à une certaine ligne rajouter des éléments
  multiArray[0].push_back(15);
  multiArray[1].pop_back();

  cout << "Le 6 eme élément de la premiere ligne est " << multiArray[0][5] << endl;
  cout << "La 2 eme ligne comporte " << multiArray[1].size() << " Elements " << endl;


 cout << "///////////////////////////////////////////////////////////////////////////\n" << endl;



  //STRING AS AN ARRAY
  cout << "Le texte à lire comporte " << texte_a_lire.size() << " caractères!" << endl;
  texte_a_lire += " les weekends";
  cout << "Résultat : " << texte_a_lire << endl;


  cout << "///////////////////////////////////////////////////////////////////////////\n" << endl;



  //FILE STREAMING
  ofstream myStream("toto.txt"); //for output myStream.seekp pour se positionner et myStream.tellp pour donner sa position
  ifstream yourStream("tata.txt"); //for input



  cout << "///////////////////////////////////////////////////////////////////////////\n" << endl;



  //POINTER
  int *ptr(0); //Useful IMPORTANT: toujours déclarer les pointeurs en initialisant leur valeurs à 0
  ptr = new int;

  vector<int> * arrayptr(0);//Useful IMPORTANT: toujours déclarer les pointeurs en initialisant leur valeurs à 0
  arrayptr = new vector<int>;

  ptr = &age;

  cout << "Address: "  << ptr << " Value: " << *ptr << endl; //déréférencement du pointeur dans *ptr
  


  cout << "///////////////////////////////////////////////////////////////////////////\n" << endl;


  //CALLING OUTSIDE FUNCTIONS FROM OTHER FILES
  fstringer("Generation pourrie");


  cout << "\n///////////////////////////////////////////////////////////////////////////\n" << endl;


  //OBJECT ORIENTED PROGRAMMING
  Personnage David, Goliath;

  Goliath.attaquer(David);
  David.boirePotionDeVie(20);
  Goliath.attaquer(David);
  David.attaquer(Goliath);

  Goliath.changerArme("Double couteau de la mort qui tue", 50);
  Goliath.attaquer(David);

  cout << "\n///////////////////////////////////////////////////////////////////////////\n" << endl;


  return 0;

}

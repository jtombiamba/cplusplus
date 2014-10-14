#include "template.h"
//#include <iostream>

using namespace std;

//passage par reference constante
//eviter la copie de l'argument et éviter la modification par la fonction (??????)
void fstringer(string const& texte){
  cout << "D'ici je peux voir le texte: \"" << texte << "\" et m'en amuser" << endl;
}

//autre passage de parametre en reference, ceci dit, ici, on n'aura pas la possibilité de modifier le tableau
void function_with_constant_array(vector<int> const& bigArray){

}

//dans ce cas, on pourra modifier le tableau 

void func_with_array(vector<int>& Array){

}

//il est tout aussi possible de faire une fonction renvoyant un tableau, mais ceci implique une copie de tableau, qui peut être couteuse en rendement si le tableau devient super grand, donc vaut mieux le passer en parametre par référence

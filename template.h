#ifndef TEMPLATE_H_INCLUDED
#define TEMPLATE_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>

//déconseillé de mettre les using namespace dans les .h
 
void fstringer(std::string const& texte);

void function_with_constant_array(std::vector<int> const& bigArray);

void func_with_array(std::vector<int>& Array);

#endif //TEMPLATE_H_INCLUDED

// main.cpp

#include "alice.h"
#include "bob.h"

#include <iostream>
// std est un espace de noms ! Voici ce que cela donne sans
// la ligne habituelle :

int main()
{
    float pi = 3.1415;
    std::cout << pi << std::endl;
    std::cout << Alice::pi << std::endl;
    std::cout << Bob::pi << std::endl;

    return 0;
}
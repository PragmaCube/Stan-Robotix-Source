#include <iostream>
#include <cmath>

#include "constants.h"

int main()
{
    std::cout << pi::pi << std::endl;
    std::cout << "La racine carrée de 2 vaut environ : " << std::sqrt(2.0);
    std::cout << Allo::pi;
    std::cout << "La valeur de pi est " << Constants::pi;

    return 0;
}

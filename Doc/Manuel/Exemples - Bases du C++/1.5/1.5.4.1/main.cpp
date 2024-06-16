// main.cpp

#include "rectangle.h"

#include <iostream>
using namespace std;

int main()
{
    Rectangle rect;
    rect.setLargeur(3.1);
    rect.setHauteur(4.5);

    cout << "L'aire du rectangle est : " << rect.getLargeur() * rect.getHauteur();
    
    return 0;
}
// main.cpp

#include "rectangle.h"

#include <iostream>
using namespace std;

int main()
{
    Rectangle* rect = new Rectangle(3, 4);
    // Ici on appelle carrément le constructeur pour qu'il retourne
    // un objet de type Rectangle avec les informations spécifiées
    
    cout << "Aire du rectangle : " << rect->getLargeur() * rect->getHauteur();

    return 0;
}
#include <iostream>
using namespace std;

// On cherche à   calculer et afficher l'aire d'un triangle
int main()
{
    float base, hauteur;

    cout << "Donner la base et la hauteur du triangle : \n";
    cin >> base >> hauteur; // Il faut permettre à l'utilisateur de rentrer les valeurs
    
    cout << "L'aire du triangle est : ";
    cout << base * hauteur / 2; // Chercher au besoin la formule sur Internet

    return 0;
}
#include <iostream>
using namespace std;

// On cherche à calculer et afficher le périmètre d'un cercle
int main()
{
    const float pi = 3.14;
    float rayon;    // Il faut déclarer la variable rayon

    cout << "Donner le rayon du cercle : \n";
    cin >> rayon;
    
    cout << "Le périmètre du cercle est " << 2 * pi * rayon  << ".";

    return 0;
}
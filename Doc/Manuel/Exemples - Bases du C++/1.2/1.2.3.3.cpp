#include <iostream>
using namespace std;

int main()
{
    float nombre;
    
    cout << "Veuillez rentrer un nombre : ";
    cin >> nombre;

    float resultat = nombre;
    int compteur = 0;

    while (resultat > -1000 && resultat < 1000)
    {
        if (compteur == 100)
        {
            break;
        }

        cout << resultat << endl;
        
        resultat *= nombre;

        compteur++;
    }
    
    return 0;
}
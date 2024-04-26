#include <iostream>
using namespace std;

int main()
{
    int resultat;
    
    cout << "Veuillez entrer le résultat du lancer : ";
    cin >> resultat;

    if (resultat == 1)
    {
        cout << "Vous avez fait 1 !";
    }

    else if (resultat == 2)
    {
        cout << "Vous avez fait 2 !";
    }

    else if (resultat == 3)
    {
        cout << "Vous avez fait 3 !";
    }

    else if (resultat == 4)
    {
        cout << "Vous avez fait 4 !";
    }

    else if (resultat == 5)
    {
        cout << "Vous avez fait 5 !";
    }

    else if (resultat == 6)
    {
        cout << "Vous avez fait 6 !";
    }

    else
    {
        cout << "Votre dé est étonnant !";
    }

    return 0;
}
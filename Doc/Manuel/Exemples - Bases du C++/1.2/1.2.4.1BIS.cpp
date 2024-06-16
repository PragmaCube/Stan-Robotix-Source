#include <iostream>
using namespace std;

int main()
{
    int resultat;
    
    cout << "Veuillez rentrer le résultat du lancer : ";
    cin >> resultat;

    switch(resultat)
    {
        case 1:
            cout << "Vous avez fait 1 !";
            break;

        case 2:
            cout << "Vous avez fait 2 !";
            break;

        case 3:
            cout << "Vous avez fait 3 !";
            break;

        case 4:
            cout << "Vous avez fait 4 !";
            break;

        case 5:
            cout << "Vous avez fait 5 !";
            break;

        case 6:
            cout << "Vous avez fait 6 !";
            break;

        default:
            cout << "Votre dé est étonnant !";
    }

    return 0;
}
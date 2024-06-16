#include <iostream>
using namespace std;

int main()
{
    int nombre;

    while (true)
    {
        cout << "Veuillez entrer un nombre :\n>>> ";
        cin >> nombre;

        nombre %= 10;

        switch (nombre)
        {
        case 0:
            cout << "Vous avez rentré le chiffre zéro !";
            break;

        case 1:
            cout << "Vous avez rentré le chiffre un !";
            break;
        
        case 2:
            cout << "Vous avez rentré le chiffre deux !";
            break;

        case 3:
            cout << "Vous avez rentré le chiffre trois !";
            break;

        case 4:
            cout << "Vous avez rentré le chiffre quatre !";
            break;

        case 5:
            cout << "Vous avez rentré le chiffre cinq !";
            break;

        case 6:
            cout << "Vous avez rentré le chiffre six !";
            break;

        case 7:
            cout << "Vous avez rentré le chiffre sept !";
            break;

        case 8:
            cout << "Vous avez rentré le chiffre huit !";
            break;

        case 9:
            cout << "Vous avez rentré le chiffre neuf !";
            break;
        
        default:
            break;
        }

        cout << endl;
    }

    return 0;
}
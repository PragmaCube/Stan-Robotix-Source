#include <iostream>
using namespace std;

int main()
{
    int nombre = 0;

    while (nombre <= 0 || nombre > 100)
    {
        cout << "Veuillez donnner un nombre entre 1 et 100\n >>> ";
        cin >> nombre;
    }

    int essai = 50;
    int delta = 25;
    int tentatives = 0;

    while (essai != nombre)
    {
        if (essai > nombre)
        {
            essai -= delta;
        }

        else if (essai < nombre)
        {
            essai += delta;
        }

        delta /= 2;

        if (delta < 1)
        {
            delta = 1;
        }
        
        tentatives++;

        cout << "Tentative #" << tentatives << " : " << essai << endl;
    }

    cout << "Le nombre trouvé en " << tentatives << "tentatives est : " << essai ;
    
    return 0;
}
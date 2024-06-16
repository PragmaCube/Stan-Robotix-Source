#include <iostream>
using namespace std;

int plusPetitMultiple(int nombre)
{
    if (nombre < 17)
    {
        return 17;
    }

    nombre++;

    while (nombre % 17 != 0 || nombre == 17)
    {
        nombre++;
    }

    return nombre;
}

int main()
{
    int entree = 0;
    
    cout << "Veuillez rentrer un nombre :\n>>> ";
    cin >> entree;
    cout << plusPetitMultiple(entree);

    return 0;
}
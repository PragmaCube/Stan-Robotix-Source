#include <iostream>
using namespace std;

int main()
{
    float nombre;
    
    cout << "Veuillez donner un nombre : ";
    cin >> nombre;

    if (nombre < 2)
    {
        cout << "Le double de " << nombre << " est " << 2 * nombre;
    }

    else if (nombre < 8 && nombre * nombre > 12)
    {
        cout << "Le triple de " << nombre << " est " << 3 * nombre;
    }

    else if (nombre * nombre * nombre <= 2685.619)
    {
        cout << "Le carré de " << nombre << " est " << nombre * nombre;
    }

    else
    {
        cout << "Le cube de " << nombre << " est " << nombre * nombre * nombre;
    }
    
    return 0;
}
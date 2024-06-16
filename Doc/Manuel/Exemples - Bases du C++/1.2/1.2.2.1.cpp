#include <iostream>
using namespace std;

int main()
{
    int nombre;
    
    cout << "Veuillez donner un nombre : ";
    cin >> nombre;

    if (nombre % 2 == 0)
    {
        cout << nombre << " est un nombre pair.";
    }

    else
    {
        cout << nombre << " est un nombre impair.";
    }
    
    return 0;
}
#include <iostream>
using namespace std;

// On cherche à déterminer si le nombre est premier 
// (divisible seulement par lui-même et 1)
int main()
{
    int nombre;
    bool premier = true;

    cin >> nombre;

    for (...)
    {
        if (nombre % i == 0)
        {
            premier = false;
            ...
        }
    }

    if (...)
    {
        cout << "Le nombre est premier";
    }

    ...
    {
        cout << "Le nombre n'est pas premier";
    }
    
    return 0;
}
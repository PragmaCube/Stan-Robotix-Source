#include <iostream>
using namespace std;

int main()
{
    int valeurs[4] = {-71, 42, -13, 56};

    for (int i = 0; i < sizeof(valeurs) / sizeof(int); i++)
    {
        cout << valeurs[i] << endl;
    }

    return 0;
}
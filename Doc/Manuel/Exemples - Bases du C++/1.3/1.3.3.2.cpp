#include <iostream>
using namespace std;

int main()
{
    int valeurs[4] = {-71, 42, -13, 56};
    int* element = valeurs;

    for (int i = 0; i < sizeof(valeurs) / sizeof(int); i++)
    {
        cout << *element << endl;
        element++;
    }

    return 0;
}
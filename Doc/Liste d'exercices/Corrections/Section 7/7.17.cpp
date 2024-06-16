#include <iostream>
using namespace std;

int main()
{
    int hauteur;

    cout << "Hauteur de la tour :\n >>> ";
    cin >> hauteur;

    cout << endl << endl;

    for (int i = 0; i < hauteur; i++)
    {
        for (int j = 0; j < hauteur - i - 1; j++)
        {
            cout << " ";
        }

        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "*";
        }

        cout << endl;
    }

    cout << endl << endl;

    return 0;
}
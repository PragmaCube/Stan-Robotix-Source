#include <iostream>
using namespace std;

enum Type
{
    Ligne,
    Colonne
};

void permuter(int tableau[3][3], Type type, int position, int decalage)
{
    int temp;
    int bonDecalage = 0;

    switch (decalage % 3)
    {
    case 1:
        bonDecalage = 2;
        break;

    case 2:
        bonDecalage = 1;
        break;

    default:
        break;
    }

    switch(type)
    {
    case Ligne:
        temp = tableau[position][0];

        tableau[position][0] = tableau[position][bonDecalage];
        tableau[position][bonDecalage] = tableau[position][(2 * bonDecalage) % 3];
        tableau[position][(2 * bonDecalage) % 3] = temp;

        break;

    case Colonne:
        temp = tableau[0][position];

        tableau[0][position] = tableau[bonDecalage][position];
        tableau[bonDecalage][position] = tableau[(2 * bonDecalage) % 3][position];
        tableau[(2 * bonDecalage) % 3][position] = temp;
        break;

    default:
        break;
    }
}

int main()
{
    int tableau[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    for (int i = 0; i < 3; i++)
    {
        cout << "|";

        for (int j = 0; j < 3; j++)
        {
            cout << tableau[i][j] << "|";
        }

        cout << endl;
    }

    permuter(tableau, Type::Ligne, 0, 0);

    cout << "\n\n";

    for (int i = 0; i < 3; i++)
    {
        cout << "|";

        for (int j = 0; j < 3; j++)
        {
            cout << tableau[i][j] << "|";
        }

        cout << endl;
    }
    
    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    int tableau[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int temp;

    int compteur = 1;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            temp = tableau[j];

            tableau[j] = tableau[i];
            tableau[i] = temp;

            cout << "Permutation #" << compteur << " :\n";

            for (int k = 0; k < 10; k++)
            {
                cout << "|" << tableau[k];
            }

            cout << "|\n\n";

            temp = tableau[i];

            tableau[i] = tableau[j];
            tableau[j] = temp;

            compteur++;
        }
    }

    return 0;
}
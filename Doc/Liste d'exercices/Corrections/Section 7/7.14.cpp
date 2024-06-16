#include <iostream>
using namespace std;

bool premier(int nombre)
{
    for (int i = 2; i < nombre; i++)
    {
        if (nombre % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int facteursPremiers[4];
    int position = 0;
    int testFacteur = 2;

    while (position < 4)
    {
        if (6622 % testFacteur == 0 && premier(testFacteur))
        {
            facteursPremiers[position] = testFacteur;
            position++;
        }

        testFacteur++;
    }

    for (int i = 0; i < 4; i++)
    {
        cout << "Facteur " << i << " : " << facteursPremiers[i] << endl;
    }

    return 0;
}
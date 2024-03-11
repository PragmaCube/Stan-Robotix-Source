#include <iostream>
using namespace std;

int main()
{
    int i = 1;
    int compteur = 1;

    while (compteur <= 100)
    {
        if (i % 2 == 1)
        {
            cout << i << endl;
            compteur++;
        }

        i++;
    }
    
    return 0;
}
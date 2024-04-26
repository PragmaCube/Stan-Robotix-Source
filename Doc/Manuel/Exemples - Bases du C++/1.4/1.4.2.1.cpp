#include <iostream>
using namespace std;

double logTaylor(double x, int iterations = 5)
{
    if (x >= 1 || x <= -1)
    {
        return 0;
    }

    double resultat = 0;

    double xi = x;
    x *= x;
    double x2 = x;

    for (int i = 2; i <= iterations; i += 2)
    {
        resultat -= x / i;
        x *= x2;
    }
    
    x = xi;

    for (int i = 1; i <= iterations; i += 2)
    {
        resultat += x / i;
        x *= x2;
    }

    return resultat;
}

int main()
{
    cout << "Ordre 5 : " << logTaylor(0.1) << endl << "Ordre 10 : " << logTaylor(0.1, 10);

    return 0;
}
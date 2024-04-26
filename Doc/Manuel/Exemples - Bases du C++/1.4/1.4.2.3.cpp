#include <iostream>
using namespace std;

void logTaylor(double& x, int iterations = 5)
{
    if (x >= 1 || x <= -1)
    {
        x = 0;
    }

    else
    {
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
    
        x = resultat;
    }
}

int main()
{
    double x = 0.1;

    cout << "Ordre 5 :";
    logTaylor(x);
    cout << x;

    return 0;
}
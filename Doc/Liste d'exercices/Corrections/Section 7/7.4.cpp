#include <iostream>
using namespace std;

float f(float x)
{
    return x * x - 2;
}

float dichotomie(int n)
{
    float a = 0;
    float b = 2;

    for (int i = 0; i < n; i++)
    {
        if( f(a) * f(b) < 0)
        {
            b = (a + b) / 2;
        }

        else
        {
            a = (a + b) / 2;
        }
    }

    return (a + b) / 2;
}

int main()
{
    cout << "Dichotomie avec 100 itérations : " << dichotomie(100);

    return 0;
}
#include <iostream>
using namespace std;

float polynome(float& x)
{
    x *= x;

    return 3 * x * x * (x - 8) + x + 1;
}

int main()
{
    float x = 3.2;

    cout << "x initial :" << x << endl;
    cout << "P(x)     = " << polynome(x) << endl;
    cout << "x final   :" << x;

    return 0;
}
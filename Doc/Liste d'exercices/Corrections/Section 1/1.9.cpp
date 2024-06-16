#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float a, b, c;

    cout << "Quels sont les nombres ?\n >>> ";
    cin >> a >> b >> c;
    cout << "La puissance 0.5-ième de l'expression compliquée est " << pow((a + b + c) * (a + c) * (a + b) * (b + c) / 2, 0.5);

    return 0;
}
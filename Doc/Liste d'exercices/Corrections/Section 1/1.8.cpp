#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float a, b, c;

    cout << "Quels sont les nombres ?\n >>> ";
    cin >> a >> b >> c;
    cout << "La racine carrée de l'expression compliquée est " << sqrt((a + b + c) * (a + c) * (a + b) * (b + c) / 2);

    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    float a, b, c;

    cout << "Quels sont les nombres ?\n >>> ";
    cin >> a >> b >> c;
    cout << "L'expression compliquée est " << (a + b + c) * (a + c) * (a + b) * (b + c) / 2;

    return 0;
}
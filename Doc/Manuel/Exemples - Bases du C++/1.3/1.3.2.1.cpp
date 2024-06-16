#include <iostream>
using namespace std;

int main()
{
    int a = 2;
    int* b = new int;

    *b = 2 * a - 3;

    cout << "Valeur de a : " << a << endl;
    cout << "Adresse de a : " << &a << endl;
    cout << "Valeur de b : " << *b << endl;
    cout << "Adresse de b : " << b;

    return 0;
}
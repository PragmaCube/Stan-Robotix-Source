#include <iostream>
using namespace std;

// Programme qui calcule les images de la
// fonction 4x^3 - 3,5/x + 1
int main()
{
    float nombre;

    cout << "Veuillez rentrer un nombre (x) :" << endl;
    cin >> nombre;

    cout << "4 * x * x - 3.5 / x + 1 = " << 4 * nombre * nombre * nombre - 3.5 / nombre + float(1);

    return 0;
}
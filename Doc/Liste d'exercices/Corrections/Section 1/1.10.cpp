#include <iostream>
using namespace std;

int main()
{
    int bit1, bit2, bit3, bit4;

    cout << "Quels sont les bits ?\n >>> ";
    cin >> bit1 >> bit2 >> bit3 >> bit4;
    cout << "En décodant le groupe de 4 bits, on obtient la valeur " << 8 * bit1 + 4 * bit2 + 2 * bit3 + 1 * bit4;

    return 0;
}
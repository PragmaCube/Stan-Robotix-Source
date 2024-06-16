#include <iostream>
using namespace std;

int main()
{
    float rayon;
    const float pi = 3.1415;

    cout << "Quel est le rayon ?\n >>> ";
    cin >> rayon;
    cout << "L'aire du cercle est " << rayon * rayon * pi;

    return 0;
}
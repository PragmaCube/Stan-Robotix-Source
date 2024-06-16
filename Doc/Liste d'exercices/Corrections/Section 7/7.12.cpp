#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string nombre;

    cout << "Veuillez rentrer un nombre :\n>>> ";
    cin >> nombre;

    cout << "La moitié du nombre est : " << atof(nombre.c_str()) / 2;
    
    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    float nombre = 3.14;
    float* ptrNombre = &nombre;
    *ptrNombre = 3.1415;

    cout << nombre;
    
    return 0;
}
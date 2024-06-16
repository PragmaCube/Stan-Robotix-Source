#include <iostream>
using namespace std;

float conversion(float valeur, bool mile)
{
    if (mile)
    {
        return valeur * 1.609;
    }

    return valeur * 0.621;
}

int main()
{
    float x;
    bool mode;

    cin >> x >> mode;

    cout << "La conversion vaut : " << conversion(x, mode); 

    return 0;
}
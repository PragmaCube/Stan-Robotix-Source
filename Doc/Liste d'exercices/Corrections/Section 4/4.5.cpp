#include <iostream>
using namespace std;

float esperance(float g, float p)
{
    return 5 * 0.3 + g * p;
}

int main()
{
    cout << esperance(-4, 0.5);
    
    return 0;
}
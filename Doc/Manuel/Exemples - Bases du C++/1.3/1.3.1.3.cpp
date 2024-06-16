#include <iostream>
using namespace std;

int main()
{
    float nombres[4] = {0.31, 8.12, -38.1, 642.02};

    for (int i = 0; i < sizeof(nombres) / sizeof(float); i++)
    {
        nombres[i] = nombres[i] * nombres[i];
    }

    cout << (nombres[0] + nombres[int(sizeof(nombres) / sizeof(float)) - 1]  ) / 2;
    
    return 0;
}
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    float heures[16] = {25, 11, 6, 10, 0, 5, 4, 6, 4, 4, 4, 4, 6, 6, 4, 0};

    sort(heures, heures + sizeof(heures) / sizeof(float));

    float total = 0;

    for (int i = 0; i < 16; i++)
    {
        total += heures[i];
    }

    cout << "minimum, moyenne, médiane, maximum : " << heures[0] << ", " << total / float(16) << ", " << (heures[7] + heures[8] / 2) << ", " << heures[15];

    return 0;
}
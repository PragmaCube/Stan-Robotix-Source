#include <iostream>
using namespace std;

#include "sonic.h"

int main()
{
    Sonic sonic;

    cout << "Sonic a parcouru " << sonic.distanceParcourue(7200) << " mètres en 2h";

    return 0;
}
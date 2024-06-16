#include <iostream>
#include <cmath>
using namespace std;

double piParPolygone(int nbrCotes)
{
    const double piApprox = 3.14159;

    return nbrCotes * 0.5 *  sqrt( (cos(2 * piApprox / nbrCotes) - 1) * (cos(2 * piApprox / nbrCotes) - 1) + sin(2 * piApprox / nbrCotes) * sin(2 * piApprox / nbrCotes));
}

int main()
{
    cout << "Approximation de pi : " << piParPolygone(10);

    return 0;
}
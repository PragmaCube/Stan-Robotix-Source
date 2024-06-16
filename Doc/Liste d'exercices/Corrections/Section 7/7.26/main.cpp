#include <iostream>
#include <cmath>
using namespace std;

#include "complexe.h"

int main()
{
    NombreComplexe z;
    NombreComplexe w;

    z.setPartieReelle(0.5);
    z.setPartieImaginaire(sqrt(3) / 2);

    cout << "(" << z.getPartieRelle() << " + " << z.getPartieImaginaire() << "i)^2 = " << multiplicationComplexe(z, z).getPartieRelle() << " + " << multiplicationComplexe(z, z).getPartieImaginaire() << "i" << endl;

    z.setPartieReelle(1);
    z.setPartieImaginaire(1);

    w.setPartieReelle(1);
    w.setPartieImaginaire(- 1);

    cout << "(" << z.getPartieRelle() << " + " << z.getPartieImaginaire() << "i) / " << "(" << w.getPartieRelle() << " + " << w.getPartieImaginaire() << "i)" <<  " = " << divisionComplexe(z, w).getPartieRelle() << " + " << divisionComplexe(z, w).getPartieImaginaire() << "i" << endl;

    return 0;
}
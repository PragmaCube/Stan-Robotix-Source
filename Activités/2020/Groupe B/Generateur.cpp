#include "Generateur.h"
#include <iostream>

int Generateur::getNb() {
    for (int i = 0; i <= 3; i++) {
        return mNb[i];
    }
}

int Generateur::getRandom() {

    for (int b = 0; b <= 3; b++) {

        srand(time(NULL));


        mNb[b] = valeur;
        random.erase(random[rd]);
        rd = rand() % random.size();
        valeur = random[rd] - '0';
        for (int a = 0; a <= 3; a++) {

            mNbd[a] = mNb[b] + '0';
        }

    }

}




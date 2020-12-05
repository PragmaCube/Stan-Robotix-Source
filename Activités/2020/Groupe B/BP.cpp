
#include "BP.h"
#include "Generateur.cpp"



int BP::getBP()
{
    return mBP;
}

int BP::setBP(int iBP)
{
    mBP = iBP;
}

int BP::setBienPlace(std::string iGuess, std::string iTry)
{
    for (int i = 0; i <= 3; i++) {
        for (int j = 0; j <= 3; j++) {
            if (iGuess[i] == iTry[j]) {
                mBP = mBP + 1;
            }
        }
    }
}




#include "algorithme.h"
#include <string>
#include <time.h>

int algorithme::GoodPlace(std::string iTry, std::string iGuess)
{
    int wBP = 0;
    for (int a = 0; a <= 3; a++)
    {
        if (iTry[a] == iGuess[a])
        {
            wBP = wBP + 1;
        }
    }
    return wBP;
}

int algorithme::WrongPlace(std::string iTry, std::string iGuess)
{
    int wWrongPlace = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int i2 = 0; i2 < 4; i2++)
        {
            if (iTry[i2] == iGuess[i])
            {
                if (i != i2)
                {
                    wWrongPlace = wWrongPlace + 1;
                }
            }
        }
    }
    return wWrongPlace;
}

std::string algorithme::generateur()
{
    std::string wCheck = "0123456789";
    std::string wSecret;

    srand(time(NULL));

    while (wSecret.length() != 4)
    {
        int wpos = rand() % 10;
        if (wCheck[wpos] != ' ')
        {
            wCheck[wpos] = ' ';
            char wInsertion[] = "0";
            wInsertion[0] = wInsertion[0] + wpos;
            wSecret.append(wInsertion);
        }
    }
    return wSecret;
}



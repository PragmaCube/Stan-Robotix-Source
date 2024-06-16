#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string message, cle;

    cout << "Message a chiffrer (en minuscules) : \n>>> ";
    getline(cin, message);
    cout << "Cle de chiffrement :\n>>> ";
    getline(cin, cle);

    vector<int> positionsCle;
    vector<int> positionsMessage;

    int nbrEspace = 0;

    for (int i = 0; i < cle.length(); i++)
    {
        for (int j = 0; j < alphabet.length(); j++)
        {
            if (cle[i] == alphabet[j])
            {
                positionsCle.push_back(j);
                break;
            }
        }
    }

    for (int i = 0; i < message.length(); i++)
    {
        for (int j = 0; j < alphabet.length(); j++)
        {
            if (message[i] == alphabet[j])
            {
                positionsMessage.push_back(j);
                break;
            }
        }

        if (message[i] == ' ')
        {
            positionsMessage.push_back(-1);
        }
    }

    for (int i = 0; i < message.length(); i++)
    {
        if (positionsMessage[i] != -1)
        {
            message[i] = alphabet[(positionsMessage[i] + positionsCle[(i - nbrEspace) % cle.length()]) % 26];
        }

        else
        {
            nbrEspace++;
        }
    }

    cout << "Message chiffre : \n >>> " << message; 

    return 0;
}
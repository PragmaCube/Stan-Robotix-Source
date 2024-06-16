#include <iostream>
#include <cstring>
#include <vector>
#include <random>
using namespace std;

int main()
{
   vector<string> noms = {"Alice", "Alban", "André", "Ines", "Kaloyan", "Majeed", "Max", "Maxence", "Maxime", "Mohammad", "Nina", "Raphaël", "Stéphanie", "Victor", "Zachary"};
    vector<string> equipes = {"S&D", "Construction", "Programmation", "Construction", "Marketing", "S&D", "S&D", "Construction", "S&D", "S&D", "Construction", "Programmation", "S&D", "Construction", "Construction"};

    random_device systeme{};
    mt19937 generateur{systeme()};
    uniform_int_distribution<int> distribution{0, noms.size() - 1};

    float precision = 0;
    int position = 0, bonnesReponses = 0, reponses = 0;
    string reponse;

    while (precision < 0.7 || reponses < 12)
    {
        position = distribution(generateur);

        cout << "Question #" << reponses + 1 << " :\nQuelle est (fut) la sous-équipe de " << noms.at(position) << " ?\n>>> ";
        cin >> reponse;

        if (reponse == equipes.at(position))
        {
            cout << "Bonne réponse !\n";

            bonnesReponses++;
        }

        else
        {
            cout << "Mauvaise réponse !\n";
        }

        reponses++;

        precision = (float)bonnesReponses / (float)reponses;

        cout << "Précision : " << precision << endl;
    }

    return 0;
}
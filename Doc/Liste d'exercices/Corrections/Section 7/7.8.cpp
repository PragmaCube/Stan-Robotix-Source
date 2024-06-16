#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
    vector<string> equipe;
    string personnage;

    vector<string> mainDPS = {"Alhaitham", "Ayaka", "Ayato", "Cyno", "Diluc", "Eula", "Ganyu", "Hu Tao", "Itto", "Kaveh", "Keqing", "Klee", "Lyney", "Ningguang", "Noelle",  "Nomade", "Raiden", "Razor", "Tartaglia", "Yanfei", "Yoimiya", "Xiao", "Xinyan"};
    vector<string> subDPS = {"Albedo", "Aloy", "Amber", "Beidou", "Fischl", "Heizou", "Kaeya", "Tighnari", "Venti", "Xiangling", "Xingqiu", "Yae Miko", "Yelan"};
    vector<string> support = {"Baizhu", "Barbara", "Bennett", "Candace", "Chongyun", "Collei", "Dehya", "Diona", "Dori", "Faruzan", "Gorou", "Jean", "Kazuha", "Kirara", "Kokomi", "Layla", "Lisa", "Lynette", "Mika", "Mona", "Nahida", "Nilou", "Qiqi", "Rosaria", "Sara", "Sayu", "Shenhe", "Shinobu", "Sucrose", "Thoma", "Yao Yao", "Yun Jin", "Zhongli"};

    for (int i = 0; i < 4; i++)
    {
        cout << "Veuillez donner le nom du personnage #" << i + 1 << " :\n>>> ";
        cin >> personnage;

        equipe.push_back(personnage);
    }

    int nombreMainDPS = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < mainDPS.size(); j++)
        {
            if (equipe.at(i) == mainDPS.at(j))
            {
                nombreMainDPS++;

                cout << equipe.at(i) << " est un main DPS.\n";
            }
        }

        for (int j = 0; j < subDPS.size(); j++)
        {
            if (equipe.at(i) == subDPS.at(j))
            {
                cout << equipe.at(i) << " est un sub DPS.\n";
            }
        }

        for (int j = 0; j < support.size(); j++)
        {
            if (equipe.at(i) == support.at(j))
            {
                cout << equipe.at(i) << " est un support.\n";
            }
        }
    }

    switch (nombreMainDPS)
    {
    case 0:
        cout << "Je parie que tu as une team Nilou-bloom.";
        break;

    case 1:
        cout << "Une team classique.";
        break;

    case 2:
        cout << "Une team intéressante.";
        break;

    case 3:
        cout << "Tu joues avec le feu.";
        break;

    case 4:
        cout << "Comment tu fais pour 36* les abyss ?";
        break;
    
    default:
        break;
    }
    
    return 0;
}
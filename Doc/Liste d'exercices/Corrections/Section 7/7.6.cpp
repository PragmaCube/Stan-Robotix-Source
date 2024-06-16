#include <iostream>
#include <random>
using namespace std;

int main()
{
    int essai = 0;

    random_device systeme{};
    mt19937 generateur{systeme()};
    uniform_int_distribution<int> distribution{1, 100};

    int nombre = distribution(generateur);
    int tentatives = 0;

    while (nombre != essai)
    {
        cout << "Veuillez donnner un nombre entre 1 et 100\n >>> ";
        cin >> essai;

        if (nombre > essai)
        {
            cout << "C'est plus !\n";
        }

        else if (nombre < essai)
        {
            cout << "C'est moins !\n";
        }

        tentatives++;
    }

    cout << "Bravo ! Vous avez trouvé le nombre en " << tentatives << " tentatives !";
    
    return 0;
}
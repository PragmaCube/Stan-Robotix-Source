#include <iostream>
#include "algorithme.h"

int main()
{
    algorithme wObjet;
    std::string wTry;
	std::string wFind = wObjet.generateur();
	std::cout << "On va jouer a un petit jeu, du nom de mastermind. Tu auras le droit de faire autant de tentatives que tu le voudras. C est un code de 4 chiffres differents.";

	int wBPlace = 0, wnbTry = 1;

	while (wBPlace != 4)
	{
		std::cout << "\n\nTentative n " << wnbTry << std::endl;
		std::cin >> wTry;

		wnbTry++;
		wBPlace = wObjet.GoodPlace(wTry, wFind);

		if (wBPlace != 4)
		{
            std::cout << "\nBon(s) et bien(s) place(s): " << wBPlace << "\nBon(s) mais mal place(s): " << wObjet.WrongPlace(wTry, wFind);
		}
		else
		{
			std::cout << "\nBravo! Tu as trouve le code code qui etait bien " << wFind << ".\nTu as trouve en " << wnbTry;
			break;

		}
	}

}

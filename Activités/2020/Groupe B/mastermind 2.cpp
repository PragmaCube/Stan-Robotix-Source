#include <iostream>
#include <string>
#include "BMP.h"
#include "BP.h"
#include "Generateur.h"

int main() {


	const int kInfini = 0;
	int ntentative = 1;
	std::string Tentative;

	std::cout << "On va jouer a un petit jeu, master mind.\nTu vas devoir deviner mon nombre.\nTu auras le droit d utiliser autant de tentatives que tu le voudras.\nA chaque fois, je te donnerai quelques indices.\n" << std::endl;


	BMP WsetTableuD(Generateur WgetNb);
	BP WsetGuess(Generateur WgetNb);

	while (kInfini < 1)
	{
		std::cout << "Tentative n°" << ntentative << " :\n" << std::endl;
		std::cin >> Tentative;
		BMP WsetNombreT(std::string Tentative);
		BMP Wset(std::string Tentative);

		if (BP WgetmBP() != 4)
		{
			std::cout << "Bien place(s): " << BP WgetmBP() << "\nBon(s) mais mal place(s): " << BMP WgetBMP() << std::endl;
		}
		else
		{
			break;

		}

		std::cout << "Bravo! tu as trouve au bout de " << ntentative << " tentatives. La solution etait bien" << wGenerateur.getmBP << std::endl;
	}

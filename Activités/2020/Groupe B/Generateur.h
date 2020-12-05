#pragma once
#include <iostream>
#include <random>
#include <string>

class Generateur {
	std::string mNbd; // nombre a deviner

	std::string random = "0123456789";
	int mNb[4];

	int rd = rand() % random.size();  // choisi la position ( dans la string) du chiffre aleatoire

	int valeur = random[rd] - '0';  // coverti la valeur de la string, de char a int

public:

	int getNb();

	int getRandom();  // methode qui attribue un chiffre aleatoire a chaque case du tableau et defini le nombre aleatoire FINAL



};


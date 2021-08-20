#pragma once

#include "PacmanMonster.h"

/*

Personnalit� :
	� plus de 8 cases de Pacman : suit le joueur par derri�re
	� moins de 8 cases de Pacman : tourne en rond

	Pour l'instant : al�atoire
*/

class Clyde :
	public PacmanMonster
{
	bool mKeepWay = true;
public:
	Clyde();

	char randomMove();

	// Pour voir si Clyde va garder son mouvement ou non
	void randomKeepWay();

	// G�re si un mur le cnotraint � changer de direction / si son "IA" (al�atoire)
	// lui dit de changer de direction et si ce changement est possible
	void updateMovement();
	void move();

	void initializeBitmap(HDC ihdc);
};
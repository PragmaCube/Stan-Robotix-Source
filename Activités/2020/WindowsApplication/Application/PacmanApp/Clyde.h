#pragma once

#include "PacmanMonster.h"

/*

Personnalité : aléatoire mais peut garder son mouvement sur 5 blocs

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

	// Gère si un mur le cnotraint à changer de direction / si son "IA" (aléatoire)
	// lui dit de changer de direction et si ce changement est possible
	void updateMovement();
	void move();
	void reset();

	void initializeBitmap(HDC ihdc);
};
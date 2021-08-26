#pragma once

#include "PacmanMonster.h"

/*

Personnalit� : essaie de passer devant le joueur (la 4e case devant la direction du joueur est sa cible)

*/

class Pinky :
	public PacmanMonster
{
	bool mInBox = true;

	char mExitPath[17] = { 'r', 'u', 'u', 'u', 'r', 'u', 'u', 'r', 'r', 'r', 'u', 'u', 'u', 'r', 'r', 'r' };

	int mExitPos = 0;

	bool mKeepWay = true;

public:
	Pinky();

	void move();

	char randomMove();

	// Pour voir si Clyde va garder son mouvement ou non
	void randomKeepWay();

	// G�re si un mur le cnotraint � changer de direction / si son "IA" (al�atoire)
	// lui dit de changer de direction et si ce changement est possible
	void updateMovement();
	void path();

	void reset();

	void exSwitch();

	void initializeBitmap(HDC ihdc);
};
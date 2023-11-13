#pragma once

#include "PacmanMonster.h"

/*

Personnalité :
	À plus de 8 cases de Pacman : suit le joueur par derrière
	À moins de 8 cases de Pacman : tourne en rond

	Pour l'instant : aléatoire
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

	void initializeBitmap(HDC ihdc);
};
#pragma once

#include "PacmanMonster.h"

/*

Personnalité : on double le vecteur Blinky-Cible et on obtient la cible d'Inky

*/

class Inky :
	public PacmanMonster
{
	bool mInBox = true;

	char mExitPath[16] = { 'u', 'u', 'u', 'l', 'u', 'u', 'l', 'l', 'l', 'u', 'u', 'u', 'l', 'l', 'l' };

	char mLoopPath[140] = { 'l', 'l', 'l', 'l', 'l', 'u', 'u', 'u', 'u', 'r', 'r', 'r', 'r', 'r', 'd',
		'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd',
		'd', 'd', 'd', 'd', 'l', 'l', 'l', 'l', 'l', 'd', 'd', 'd', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r',
		'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'u', 'u', 'u',
		'l', 'l', 'u', 'u', 'u', 'r', 'r', 'u', 'u', 'u', 'l', 'l', 'l', 'l', 'l', 'u', 'u', 'u', 'u', 'u',
		'u', 'u', 'u', 'u', 'u', 'u', 'u', 'u', 'u', 'u', 'u', 'u', 'u', 'u', 'u', 'r', 'r', 'r', 'r', 'r',
		'd', 'd', 'd', 'd', 'l', 'l', 'l', 'l', 'l', 'l', 'l', 'l', 'l', 'l', 'l', 'l', 'l', 'l', 'l', 'l',
		'l', 'l', 'l', 'l' };

	int mExitPos = 0, mLoopPos = 0;
public:
	Inky();

	void path();
	void move();
	void reset();

	void initializeBitmap(HDC ihdc);
};
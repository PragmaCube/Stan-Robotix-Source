#pragma once
#include <Windows.h>

class PacmanPlayer
{
public:

	PacmanPlayer();

	void initialise(RECT iWindowRect);

	void movePacmanUp();
	void movePacmanDown();
	void movePacmanRight();
	void movePacmanLeft();

	void paint(HDC ihdc);


private:
	double kSpeed = 5;
	double mCoorX, mCoorY;
	int mCoorYMax, mCoorYMin, mCoorXMax, mCoorXMin; // coordonnées des extrémités du plateau de jeu
	HBRUSH mBrush;
	const int mRadius = 20; // rayon du cercle (pour l'instant, cercle = pacman)
	bool mIsInit;

};


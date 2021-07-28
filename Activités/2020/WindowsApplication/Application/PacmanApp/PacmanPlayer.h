#pragma once
#include <Windows.h>
#include "PacmanGameBoard.h"

class PacmanPlayer
{
public:

	PacmanPlayer();

	void initialise(RECT iWindowRect);

	void initializeGameEngine(PacmanGameEngine* iPacmanGameEngine);

	void movePacmanUp();
	void movePacmanDown();
	void movePacmanRight();
	void movePacmanLeft();

	char getWay();

	void move(char way);

	int getX();
	int getY();

	void paint(HDC ihdc);



private:
	double kSpeed = 5;
	double mCoorX, mCoorY;
	int mCoorYMax, mCoorYMin, mCoorXMax, mCoorXMin; // coordonnées des extrémités du plateau de jeu
	HBRUSH mBrush;
	const int mRadius = 20; // rayon du cercle (pour l'instant, cercle = pacman)
	bool mIsInit;
	int mCoorBlocX, mCoorBlocY;
	char mDir = 'l';

	const double mNbRows = 28.0;
	const double mNbColumns = 31.0;

	double wSideX, wSideY;


	PacmanGameBoard mGameBoard;
	PacmanGameEngine* mPacmanGameEngine;
};
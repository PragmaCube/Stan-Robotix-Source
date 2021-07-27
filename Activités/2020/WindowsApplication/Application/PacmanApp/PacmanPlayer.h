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

	int getX();
	int getY();

	void paint(HDC ihdc);

	void setBoard(PacmanGameBoard* iGameBoard);


private:
	double kSpeed = 5;
	double mCoorX, mCoorY;
	int mCoorYMax, mCoorYMin, mCoorXMax, mCoorXMin; // coordonnées des extrémités du plateau de jeu
	HBRUSH mBrush;
	const int mRadius = 20; // rayon du cercle (pour l'instant, cercle = pacman)
	bool mIsInit;

	PacmanGameBoard* mGameBoard;

	PacmanGameEngine* mPacmanGameEngine;
};
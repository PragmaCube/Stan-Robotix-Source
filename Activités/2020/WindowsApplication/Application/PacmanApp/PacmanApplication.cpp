#include "PacmanApplication.h"

#include <string>

PacmanApplication::PacmanApplication()
{

}

void PacmanApplication::paint(HDC ihdc, RECT& iPaintArea)
{
	std::wstring wTitle = L"Application de Pacman";

	::DrawText(
		ihdc,
		wTitle.c_str(),
		wTitle.length(),
		&iPaintArea,
		DT_CENTER | DT_TOP);

	Pacman.initialise(iPaintArea); // initialiser les valeurs de certaines constantes
	Pacman.paint(ihdc);
}

void PacmanApplication::onChar(char iChar, short iDetail)
{
	switch (iChar)
	{
	case 'a':
	case 'A':
		mNextDir = 'l';
		break;
	case 'w':
	case 'W':
		mNextDir = 'u';
		break;
	case 'd':
	case 'D':
		mNextDir = 'r';
		break;
	case 's':
	case 'S':
		mNextDir = 'd';
		break;
	}
}

void PacmanApplication::onKeyDown(char iChar, short iDetail)
{

}

void PacmanApplication::onMouseMove(int iPosX, int iPosY)
{

}

void PacmanApplication::onMouseLeftDoubleClick(int iPosX, int iPosY)
{

}

void PacmanApplication::onMouseLeftClick(int iPosX, int iPosY)
{

}

void PacmanApplication::onMouseRightClick(int iPosX, int iPosY)
{

}

void PacmanApplication::onTimer()
{
	if (mNextDir == 'l')
	{
		Pacman.movePacmanLeft();
	}
	else if (mNextDir == 'u')
	{
		Pacman.movePacmanUp();
	}
	else if (mNextDir == 'r')
	{
		Pacman.movePacmanRight();
	}
	else if (mNextDir == 'd')
	{
		Pacman.movePacmanDown();
	}

	IApplication::onTimer(); // Pour redessiner l'ecran
}

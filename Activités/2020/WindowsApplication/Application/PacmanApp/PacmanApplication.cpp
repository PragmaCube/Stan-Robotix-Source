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

	Pacman.initialise(iPaintArea);
	Pacman.paint(ihdc);

	if (prochaineDir == 'l') 
	{
		Pacman.movePacmanLeft();
	}
	else if (prochaineDir == 'u')
	{
		Pacman.movePacmanUp();
	}
	else if (prochaineDir == 'r')
	{
		Pacman.movePacmanRight();
	}
	else if (prochaineDir == 'd')
	{
		Pacman.movePacmanDown();
	}
}

void PacmanApplication::onChar(char iChar, short iDetail)
{
	switch (iChar)
	{
	case 'a':
	case 'A':
		prochaineDir = 'l';
		break;
	case 'w':
	case 'W':
		prochaineDir = 'u';
		break;
	case 'd':
	case 'D':
		prochaineDir = 'r';
		break;
	case 's':
	case 'S':
		prochaineDir = 'd';
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

	IApplication::onTimer(); // Pour redessiner l'ecran
}

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
	mMazeFloor.paint(ihdc, iPaintArea);
}

void PacmanApplication::onChar(char iChar, short iDetail)
{

}

void PacmanApplication::onKeyDown(char iChar, short iDetail)
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

#include "SnakeApplication.h"

#include <string>

SnakeApplication::SnakeApplication()
{

}

void SnakeApplication::paint(HDC ihdc, RECT& iPaintArea)
{
	std::wstring wTitle = L"Application de Snake";

	::DrawText(
		ihdc,
		wTitle.c_str(),
		wTitle.length(),
		&iPaintArea,
		DT_CENTER | DT_TOP);
}

void SnakeApplication::onChar(char iChar, short iDetail)
{

}

void SnakeApplication::onKeyDown(char iChar, short iDetail)
{

}

void SnakeApplication::onMouseLeftDoubleClick(int iPosX, int iPosY)
{

}

void SnakeApplication::onMouseLeftClick(int iPosX, int iPosY)
{

}

void SnakeApplication::onMouseRightClick(int iPosX, int iPosY)
{

}

void SnakeApplication::onTimer()
{

	IApplication::onTimer(); // Pour redessiner l'ecran
}

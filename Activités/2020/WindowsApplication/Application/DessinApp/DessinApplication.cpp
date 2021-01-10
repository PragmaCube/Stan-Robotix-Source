#include "DessinApplication.h"

#include <string>

DessinApplication::DessinApplication()
{

}

void DessinApplication::paint(HDC ihdc, RECT& iPaintArea)
{
	std::wstring wTitle = L"Application de dessin";

	::DrawText(
		ihdc,
		wTitle.c_str(),
		wTitle.length(),
		&iPaintArea,
		DT_CENTER | DT_TOP);
}

void DessinApplication::onChar(char iChar, short iDetail)
{

}

void DessinApplication::onKeyDown(char iChar, short iDetail)
{

}

void DessinApplication::onMouseLeftDoubleClick(int iPosX, int iPosY)
{

}

void DessinApplication::onMouseLeftClick(int iPosX, int iPosY)
{

}

void DessinApplication::onMouseRightClick(int iPosX, int iPosY)
{

}

void DessinApplication::onTimer()
{

	IApplication::onTimer();
}

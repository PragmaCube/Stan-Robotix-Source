#include "PingPongApplication.h"

#include <string>

PingPongApplication::PingPongApplication()
{
	int wRed = (1 & 0x1) ? 255 : 0; // Le premier bit détermine si la composante rouge.
	int wGreen = (1 & 0x2) ? 255 : 0; // Le deuxieme bit détermine si la composante verte.
	int wBlue = (1 & 0x4) ? 255 : 0; // Le troisieme bit détermine si la composante bleue.
	mBall.setColor(RGB(wRed, wGreen, wBlue));
}

void PingPongApplication::paint(HDC ihdc, RECT& iPaintArea)
{
	std::wstring wTitle = L"Application de Pong";

	::DrawText(
		ihdc,
		wTitle.c_str(),
		wTitle.length(),
		&iPaintArea,
		DT_CENTER | DT_TOP);
	mBall.updateDrawingArea(iPaintArea);
	mBall.paint(ihdc);
	mBall.applyTime();
	mLeftPad.setAsLeft(ihdc, iPaintArea);
	mLeftPad.paint(ihdc, iPaintArea);
	mRightPad.setAsRight(ihdc, iPaintArea);
	mRightPad.paint(ihdc, iPaintArea);
}



void PingPongApplication::onChar(char iChar, short iDetail)
{

}



void PingPongApplication::onKeyDown(char iChar, short iDetail)
{

}

void PingPongApplication::onMouseLeftDoubleClick(int iPosX, int iPosY)
{

}

void PingPongApplication::onMouseLeftClick(int iPosX, int iPosY)
{

}

void PingPongApplication::onMouseRightClick(int iPosX, int iPosY)
{

}

void PingPongApplication::onTimer()
{

	IApplication::onTimer(); // Pour redessiner l'ecran
}

#include "PingPongApplication.h"

#include <string>

PingPongApplication::PingPongApplication() :
	mLeftPad(PingPongPad::eLeftPadId), 
	mRightPad(PingPongPad::eRightPadId)
{
	mCollisionEngine.setBall(&mBall);
	mCollisionEngine.setLeftPad(&mLeftPad);
	mCollisionEngine.setRightPad(&mRightPad);

	mLeftPad.setBall(&mBall);
	mRightPad.setBall(&mBall);
}

void PingPongApplication::paint(HDC ihdc, RECT& iPaintArea)
{
	std::wstring wTitle = L"Application de Pingpong";

	::DrawText(
		ihdc,
		wTitle.c_str(),
		wTitle.length(),
		&iPaintArea,
		DT_CENTER | DT_TOP);

	mBall.updateDrawingArea(iPaintArea);
	mBall.paint(ihdc);
	mBall.applyTime();
	mRightPad.UpdatePosition();
	mLeftPad.paint(ihdc, iPaintArea);
	mRightPad.paint(ihdc, iPaintArea);
	mCollisionEngine.rebound();
	mCollisionEngine.updateDrawingArea(iPaintArea);
}

void PingPongApplication::onChar(char iChar, short iDetail)
{
	if (iChar == 'q')
	{
		mLeftPad.moovePadUp();
	}
	else if (iChar == 'a')
	{
		mLeftPad.moovePadDown();
	}
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

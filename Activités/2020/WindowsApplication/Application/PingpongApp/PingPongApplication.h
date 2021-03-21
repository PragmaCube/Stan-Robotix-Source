#pragma once
#include "../../Framework/IApplication.h"
#include "PingPongBall.h"
#include "PingPongPad.h"
#include "CollisionEngine.h"

class PingPongApplication : public IApplication
{
public:
	PingPongApplication();

protected:
	void paint(HDC ihdc, RECT& iPaintArea);

	void onChar(char iChar, short iDetail);
	void onKeyDown(char iChar, short iDetail);

	void onMouseLeftDoubleClick(int iPosX, int iPosY);
	void onMouseLeftClick(int iPosX, int iPosY);
	void onMouseRightClick(int iPosX, int iPosY);

	void onTimer();

private:
	PingPongBall mBall;

	PingPongPad mLeftPad;
	PingPongPad mRightPad;
    CollisionEngine mCollisionEngine;
};


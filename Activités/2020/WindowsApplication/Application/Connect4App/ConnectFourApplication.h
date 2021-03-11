#pragma once
#include "../../Framework/IApplication.h"
#include "BoardGame.h"
#include "Token.h"


class ConnectFourApplication :
    public IApplication
{

public:
	ConnectFourApplication();

private:

protected:
	void paint(HDC ihdc, RECT& iPaintArea);

	void onChar(char iChar, short iDetail);
	void onKeyDown(char iChar, short iDetail);

	void onMouseLeftDoubleClick(int iPosX, int iPosY);
	void onMouseLeftClick(int iPosX, int iPosY);
	void onMouseRightClick(int iPosX, int iPosY);

	void onTimer();


	BoardGame mBoardGame;
};


#pragma once
#include "../../Framework/IApplication.h"
#include "BoutteDeSerpent.h"
#include "pom.h"
#include "LeuhCollisioneur.h"

class SnakeApplication :
    public IApplication
{
public:
	SnakeApplication();
	 int ProchaineDir;

protected:
	void paint(HDC ihdc, RECT& iPaintArea);

	void onChar(char iChar, short iDetail);
	void onKeyDown(char iChar, short iDetail);
	void onMouseLeftDoubleClick(int iPosX, int iPosY);
	void onMouseLeftClick(int iPosX, int iPosY);
	void onMouseRightClick(int iPosX, int iPosY);
	

private:
	BoutteDeSerpent mRond;
	pom mPomme;
	LeuhCollisionneur CollisionEngine;

	void onMouseMove(int iPosX, int iPosY);

	void onTimer();
};


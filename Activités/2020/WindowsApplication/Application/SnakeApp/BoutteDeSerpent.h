#pragma once
#include <Windows.h>

class BoutteDeSerpent{
	public:
		BoutteDeSerpent();

		void updateDrawingArea(RECT iWindowRect);
		void paint(HDC ihdc);
		
	private:
		int NombreDeBalles;
		bool mIsInit = false;
		int mCoorY;
		int mCoorX;
		double mSpeedX = 20, mSpeedY = 20;
		int mRadius = 20;
		HBRUSH mBrush;
		enum ProchaineDirection { haut, bas, gauche, droite };
};

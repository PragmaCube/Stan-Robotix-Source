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
		int mRadius = 20;
		HBRUSH mBrush;
		enum ProchaineDirection { haut, bas, gauche, droite };
};

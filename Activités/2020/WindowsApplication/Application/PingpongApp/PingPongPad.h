#pragma once
#include <Windows.h>

	class PingPongPad
	{
	public:
		PingPongPad();

		void setAsLeft(HDC ihdc, RECT& iPaintArea);
		void setAsRight(HDC ihdc, RECT& iPaintArea);

		void moovePad(char iChar);


		void paint(HDC ihdc, RECT& iPaintArea);


	private:

		const double mWidth = 20;
		const double mHeight =	100;
		int mCoorY, mCoorX, mSpeed;
		char iChar1, iChar2;

		bool mIsInit;


		RECT mDrawingArea;

		COLORREF mColor;
		HBRUSH mBrush;
	};




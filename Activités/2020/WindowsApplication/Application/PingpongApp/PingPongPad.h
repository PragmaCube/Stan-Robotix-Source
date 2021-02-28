#pragma once
#include <Windows.h>

#include "PingPongBall.h"

	class PingPongPad
	{
	public:
	    enum { eRightPadId, eLeftPadId };
	
		PingPongPad(int iId);

		int getY();
		
		void setBall(PingPongBall* iball);

		void moovePad(char iChar);

		void paint(HDC ihdc, RECT& iPaintArea);


	private:
		PingPongBall* mBallPtr;

		const double mWidth = 20;
		const double mHeight =	100;
		int mCoorY, mCoorX, mSpeed;
		char iChar1, iChar2; // Antoine mauvaise convention. Suffixe doit etre m pas i
		                     // Que signifie iChar1 ? Pourquoi ne pas donner les noms mKeyUp et mKeyDown

		bool mIsInit;

		HBRUSH mBrush;
	};




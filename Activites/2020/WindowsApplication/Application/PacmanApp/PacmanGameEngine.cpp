#include "PacmanGameEngine.h"

void PacmanGameEngine::setPacmanPos(int iX, int iY)
{
	mPacmanPos.x = iX;
	mPacmanPos.y = iY;
}

POINT& PacmanGameEngine::getPacmanPos()
{
	return mPacmanPos;
}

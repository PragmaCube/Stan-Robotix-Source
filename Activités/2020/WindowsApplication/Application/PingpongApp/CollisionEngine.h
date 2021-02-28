#pragma 
#include "Ball.h"
#include "Pad.h"

class CollisionEngine
{
public:
	CollisionEngine();

	void execute();

	void setBall(Ball* iball);
	void setLeftPad(Pad* iPad);
	void setRightPad(Pad* iPad);

private:
	Ball* mBallPtr;
	Pad* mLeftPadPtr;
	Pad* mRightPadPtr;
};


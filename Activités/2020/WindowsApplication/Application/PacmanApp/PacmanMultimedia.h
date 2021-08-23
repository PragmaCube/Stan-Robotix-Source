#include <windows.h>

#pragma once

class PacmanMultimedia
{
private:
	static PacmanMultimedia mPacmanMultimedia;

public: 
	PacmanMultimedia() { }

	static PacmanMultimedia & getInstance()
	{
    	return mPacmanMultimedia;
	}

	bool playResource(LPCWSTR ipWavName);
};


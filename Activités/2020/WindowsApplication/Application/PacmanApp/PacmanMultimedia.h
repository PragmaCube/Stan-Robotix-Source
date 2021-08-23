#include <windows.h>
#include <map>
#include <string>
#pragma once

class PacmanMultimedia
{
private:
	static PacmanMultimedia mPacmanMultimedia;

	std::map<std::wstring, LPVOID> mWavDatabase;

public: 
	PacmanMultimedia() { }

	static PacmanMultimedia & getInstance()
	{
    	return mPacmanMultimedia;
	}

	bool playResource(LPCWSTR ipWavName);
};


#include "PacmanMultimedia.h"

extern HINSTANCE hInst;                                // instance actuelle;
PacmanMultimedia PacmanMultimedia::mPacmanMultimedia;

bool PacmanMultimedia::playResource(LPCWSTR ipWavName)
{
    std::wstring wWavToPlay(ipWavName);
    LPVOID wWavResource = nullptr;

    if (mWavDatabase.find(wWavToPlay) == mWavDatabase.end())
    {
        // Find the WAVE resource. 
        const HRSRC wResInfoHnd = FindResource(hInst, ipWavName, L"WAVE");
        if (wResInfoHnd == NULL)
        {
            return false;
        }

        // Load the WAVE resource. 
        HGLOBAL wResHnd = LoadResource(hInst, wResInfoHnd);
        if (wResHnd == NULL)
        {
            return false;
        }

        // Lock the WAVE resource and play it. 
        wWavResource = LockResource(wResHnd);

        mWavDatabase.insert(std::pair<std::wstring, LPVOID>(wWavToPlay, wWavResource));
    }
    else
    {
        wWavResource = mWavDatabase.at(wWavToPlay);
    }
    
    if (wWavResource != NULL) 
    {
      sndPlaySound((LPCWSTR) wWavResource,
                    SND_MEMORY | SND_ASYNC | SND_NODEFAULT);
    }

    return true;
}

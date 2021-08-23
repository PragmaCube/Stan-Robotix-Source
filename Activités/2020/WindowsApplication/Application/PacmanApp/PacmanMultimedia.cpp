#include "PacmanMultimedia.h"

extern HINSTANCE hInst;                                // instance actuelle;
PacmanMultimedia PacmanMultimedia::mPacmanMultimedia;

bool PacmanMultimedia::playResource(LPCWSTR ipWavName)
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
    LPVOID wWavResource = LockResource(wResHnd);
    if (wWavResource != NULL) 
    {
      sndPlaySound((LPCWSTR) wWavResource,
                    SND_MEMORY | SND_ASYNC | SND_NODEFAULT);
    }

    return true;
}

#include "LED.h"

LED::LED()
{
    m_led.SetLength(kLength);
    m_led.SetData(m_ledBuffer);
    m_led.Start();
}

void LED::setMode(Mode iMode){
    switch (iMode)
    {
        case immobile:
            isImmobile = true; 
            isMoving = false;
            isGiving = false;
            isTaking = false;
            for (int i = 0; i < kLength; i++)
            {
                m_ledBuffer[i].SetRGB(0, 0, 0);
            }
            break;
        case moving:
        // Ces lignes permettent sont pour le moment seulement des lignes de test. Elles servent a faire en sorte que les led continuent de s'animer
        // meme lorsque le bouton correspondant n'est pas presse. Lorsque les vraies commandes seront configurees, le joystick sera toujours presse lorsque le robot bougera
        // et donc ces lignes de code seront inutiles.
            isImmobile = false; 
            isMoving = true;
            isGiving = false;
            isTaking = false;

            m_ledBuffer[firstPixelHue].SetRGB(0, 0, 0);
            firstPixelHue += 1;
            firstPixelHue %= 40;
            m_ledBuffer[firstPixelHue].SetRGB(255, 0, 0);
            break;
        case giving:
            isImmobile = false; 
            isMoving = false;
            isGiving = true;
            isTaking = false;

            firstPixelHue += 1;
            firstPixelHue %= 3;
            for (int i = 0; i < kLength; i += 3)
            {
                m_ledBuffer[(firstPixelHue + i) % kLength].SetRGB(255, 0, 0);
                m_ledBuffer[(firstPixelHue + 1 + i) % kLength].SetRGB(0, 255, 0);
                m_ledBuffer[(firstPixelHue + 2 + i) % kLength].SetRGB(0, 0, 255);
            }
            break;
        case taking:
            isImmobile = false; 
            isMoving = false;
            isGiving = false;
            isTaking = true;
            for (int i = 0; i < kLength; i++)
            {
                m_ledBuffer[i].SetRGB(255, 50, 0);
            }
            break;
    };
    m_led.SetData(m_ledBuffer);
}
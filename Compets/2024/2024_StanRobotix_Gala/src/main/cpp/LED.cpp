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
            for (int i = 0; i < kLength; i++)
            {
                m_ledBuffer[i].SetRGB(0, 255, 0);
            }
            break;
        case taking:
            for (int i = 0; i < kLength; i++)
            {
                m_ledBuffer[i].SetRGB(0, 0, 255);
            }
            break;
    };
    m_led.SetData(m_ledBuffer);
}
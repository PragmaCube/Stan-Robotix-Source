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
            break;
        case moving:
            for (int i = 0; i < kLength; i++)
            {
                m_ledBuffer[i].SetHSV(0, 100, 100);
            }
            break;
        case giving:
            for (int i = 0; i < kLength; i++)
            {
                m_ledBuffer[i].SetHSV(120, 100, 100);
            }
            break;
        case taking:
            for (int i = 0; i < kLength; i++)
            {
                m_ledBuffer[i].SetHSV(240, 100, 100);
            }
            break;
    };
    m_led.SetData(m_ledBuffer);
}
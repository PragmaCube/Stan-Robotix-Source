/*#include "LED.h"

LED::LED()
{
    m_led.SetLength(kLength);
    m_led.Start();
    m_RainbowLEDPattern = new frc::LEDPattern{frc::LEDPattern::Rainbow(255, 128)};
    m_RedBlueGradiant.emplace_back(getGradiant(frc::Color("ff0000"), frc::Color("000000"), 9));
    m_RedBlueGradiant.emplace_back(getGradiant(frc::Color("0000ff"), frc::Color("000000"), 9));
    m_RedBlueLEDPattern = new frc::LEDPattern{frc::LEDPattern::Gradient(frc::LEDPattern::kContinuous, m_RedBlueGradiant)};
    m_RainbowLEDPattern->ScrollAtAbsoluteSpeed(0.5_mps, LEDsConstants::kLedSpacing);
    m_RedBlueLEDPattern->ScrollAtAbsoluteSpeed(0.5_mps, LEDsConstants::kLedSpacing);
}

std::vector<frc::Color> getGradiant(frc::Color iStartingColor, frc::Color iEndingColor, int iVectorSize)
{
    int startingR = iStartingColor.red;
    int startingG = iStartingColor.green;
    int startingB = iStartingColor.blue;
    int endingR = iEndingColor.red;
    int endingG = iEndingColor.green;
    int endingB = iEndingColor.blue;
    std::vector<frc::Color> gradiant;
    for (int i = 0; i <= iVectorSize; i++)
    {
        gradiant.emplace_back(frc::Color(startingR - (startingR - endingR) / iVectorSize * i,
                                         startingG - (startingG - endingG) / iVectorSize * i,
                                         startingB - (startingB - endingB) / iVectorSize * i));
    }
    return gradiant;
}

void LED::setMode(Mode iMode){
    switch (iMode)
    {
        case immobile:
            isImmobile = true; 
            isMoving = false;
            isWaving = false;
            isTalking = false;
            m_RainbowLEDPattern->ApplyTo(m_ledBuffer);
            m_led.SetData(m_ledBuffer);
            break;
        case moving:
        // Ces lignes permettent sont pour le moment seulement des lignes de test. Elles servent a faire en sorte que les led continuent de s'animer
        // meme lorsque le bouton correspondant n'est pas presse. Lorsque les vraies commandes seront configurees, le joystick sera toujours presse lorsque le robot bougera
        // et donc ces lignes de code seront inutiles.
            isImmobile = false; 
            isMoving = true;
            isWaving = false;
            isTalking = false;
            m_RedBlueLEDPattern->ApplyTo(m_ledBuffer);
            m_led.SetData(m_ledBuffer);
            break;
        case waving:
            isImmobile = false; 
            isMoving = false;
            isWaving = true;
            isTalking = false;

            firstPixelHue += 1;
            firstPixelHue %= 3;
            for (int i = 0; i < kLength; i += 3)
            {
                m_ledBuffer[(firstPixelHue + i) % kLength].SetRGB(255, 0, 0);
                m_ledBuffer[(firstPixelHue + 1 + i) % kLength].SetRGB(0, 255, 0);
                m_ledBuffer[(firstPixelHue + 2 + i) % kLength].SetRGB(0, 0, 255);
            }
            break;
        case talking:
            isImmobile = false; 
            isMoving = false;
            isWaving = false;
            isTalking = true;
            for (int i = 0; i < kLength; i++)
            {
                m_ledBuffer[i].SetRGB(255, 50, 0);
            }
            break;
    };
    m_led.SetData(m_ledBuffer);
}*/
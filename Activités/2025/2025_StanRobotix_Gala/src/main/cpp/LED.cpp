#include "LED.h"

LED::LED()
{
    m_led.SetLength(LEDsConstants::kLength);
    m_led.Start();
    
    m_RedBlueGradiant = new std::vector<frc::Color>{};
    addGradiant(frc::Color("#ff0000"), frc::Color("#000000"), 9, m_RedBlueGradiant);
    addGradiant(frc::Color("#0000ff"), frc::Color("#000000"), 9, m_RedBlueGradiant);
    m_RedBlueLEDPattern = new frc::LEDPattern{frc::LEDPattern::Gradient(frc::LEDPattern::kContinuous, *m_RedBlueGradiant)};

    m_RedBlueLEDPattern->ScrollAtAbsoluteSpeed(0.5_mps, LEDsConstants::kLedSpacing);
}

void LED::addGradiant(frc::Color iStartingColor, frc::Color iEndingColor, int iVectorSize, std::vector<frc::Color> * iModifiedVector)
{
    int startingR = iStartingColor.red;
    int startingG = iStartingColor.green;
    int startingB = iStartingColor.blue;
    int endingR = iEndingColor.red;
    int endingG = iEndingColor.green;
    int endingB = iEndingColor.blue;
    for (int i = 0; i <= iVectorSize; i++)
    {
        iModifiedVector->emplace_back(frc::Color(startingR - (startingR - endingR) / iVectorSize * i,
                                                 startingG - (startingG - endingG) / iVectorSize * i,
                                                 startingB - (startingB - endingB) / iVectorSize * i));
    }
}

void LED::setMouthLEDs(int iMouthSize)
{
    for (int i = -iMouthSize; i <= iMouthSize; i++)
    {
        m_ledBuffer[LEDsConstants::kMouthCenter - i].SetRGB(255, 255, 255);
    }
}

void LED::pulseLEDs(frc::Color iPulseColor)
{
    std::vector<frc::Color> * m_PulseGradiant = new std::vector<frc::Color>{};
    addGradiant(frc::Color("#000000"), iPulseColor, 9, m_PulseGradiant);
    addGradiant(iPulseColor, frc::Color("#000000"), 9, m_PulseGradiant);
    frc::LEDPattern * m_PulseLEDPattern = new frc::LEDPattern{frc::LEDPattern::Gradient(frc::LEDPattern::kDiscontinuous, *m_PulseGradiant)};

    m_PulseLEDPattern->ScrollAtAbsoluteSpeed(0.5_mps, LEDsConstants::kLedSpacing);
    m_PulseLEDPattern->ApplyTo(m_ledBuffer);
}

void LED::setWhite()
{
    frc::LEDPattern white = frc::LEDPattern::Solid(frc::Color::kWhite);
    white.ApplyTo(m_ledBuffer);
    m_led.SetData(m_ledBuffer);
}

void LED::setMode(Mode iMode){
    switch (iMode)
    {
        case immobile:
            isImmobile = true; 
            isMoving = false;
            isWaving = false;
            isTalking = false;
            pulseLEDs(frc::Color("#FFA500"));
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

            break;
        case waving:
            isImmobile = false; 
            isMoving = false;
            isWaving = true;
            isTalking = false;
            for (int i = 0; i < LEDsConstants::kLength; i++)
            {
                m_ledBuffer[i].SetRGB(255, 255, 255);
            }
            break;
        case talking:
            isImmobile = false; 
            isMoving = false;
            isWaving = false;
            isTalking = true;
            srand(int(frc::Timer::GetFPGATimestamp() * 50));
            if (m_MouthSize >= rand() % LEDsConstants::kMaxMouthSize)
            {
                m_MouthSizeIncreasing = false;
            }
            else{
                m_MouthSizeIncreasing = true;
            }
            if (m_MouthSizeIncreasing)
            {
                m_MouthSize++;
            }
            else
            {
                m_MouthSize--;
            }
            setMouthLEDs(m_MouthSize);
            break;
        case test:
            isImmobile = false; 
            isMoving = false;
            isWaving = false;
            isTalking = false;
            setWhite();
    };
    m_led.SetData(m_ledBuffer);
}
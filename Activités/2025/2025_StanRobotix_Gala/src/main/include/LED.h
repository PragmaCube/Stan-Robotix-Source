#pragma once
#include <iostream>
#include <array>
#include <frc/AddressableLED.h>
#include <frc/LEDPattern.h>
#include <chrono>
#include <frc/Timer.h>

#include "Constants.h"

class LED {
 public:
    enum Mode
    {
        immobile,
        moving,
        waving,
        talking,
        test
    };

    LED();

    void addGradiant(frc::Color iStartingColor, frc::Color iEndingColor, int iVectorSize, std::vector<frc::Color> * iModifiedVector);

    void setMouthLEDs(int iMouthSize);

    void pulseLEDs(frc::Color iPulseColor);

    void setWhite();
    
    void setMode(Mode iMode);

    bool isImmobile = false;
    bool isMoving = false;
    bool isWaving = false;
    bool isTalking = false;

 private:
    // PWM port 9
    // Must be a PWM header, not MXP or DIO
    frc::AddressableLED m_led{LEDsConstants::kLEDPort};  // Ce code est un code test, le port sur lequel se trouvera les LED est encore à changer.
    frc::LEDPattern * m_RedBlueLEDPattern;
    std::vector<frc::Color> * m_RedBlueGradiant;
    std::array<frc::AddressableLED::LEDData, LEDsConstants::kLength> m_ledBuffer;  // Reuse the buffer
    // Store what the last hue of the first pixel is
    int firstPixelHue = 0;
    int m_MouthSize = 0;
    bool m_MouthSizeIncreasing = true;
};
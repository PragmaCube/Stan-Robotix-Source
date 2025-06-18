#pragma once
/*#include <iostream>
#include <array>
#include <frc/AddressableLED.h>
#include <frc/LEDPattern.h>
#include <chrono>

#include "Constants.h"

class LED {
 public:
    enum Mode
    {
        immobile,
        moving,
        waving,
        talking
    };

    LED();

    std::vector<frc::Color> getGradiant(frc::Color iStartingColor, frc::Color iEndingColor, int iVectorSize);
    
    void setMode(Mode iMode);

    bool isImmobile = false;
    bool isMoving = false;
    bool isWaving = false;
    bool isTalking = false;

 private:
    static constexpr int kLength = 40;

    // PWM port 9
    // Must be a PWM header, not MXP or DIO
    frc::AddressableLED m_led{9};  // Ce code est un code test, le port sur lequel se trouvera les LED est encore à changer.
    frc::LEDPattern * m_RainbowLEDPattern;
    frc::LEDPattern * m_RedBlueLEDPattern;
    std::vector<frc::Color> m_RedBlueGradiant;
    std::array<frc::AddressableLED::LEDData, kLength> m_ledBuffer;  // Reuse the buffer
    // Store what the last hue of the first pixel is
    int firstPixelHue = 0;
};*/
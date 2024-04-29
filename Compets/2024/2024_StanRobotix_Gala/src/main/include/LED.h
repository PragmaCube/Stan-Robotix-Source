#pragma once
#include <iostream>
#include <array>
#include <frc/AddressableLED.h>

class LED {
 public:
    enum Mode
    {
        immobile,
        moving,
        giving,
        taking
    };

    LED();
    
    void setMode(Mode iMode);

 private:
    static constexpr int kLength = 40;

    // PWM port 9
    // Must be a PWM header, not MXP or DIO
    frc::AddressableLED m_led{9};  // Ce code est un code test, le port sur lequel se trouvera les LED est encore à changer.
    std::array<frc::AddressableLED::LEDData, kLength> m_ledBuffer;  // Reuse the buffer
    // Store what the last hue of the first pixel is
    int firstPixelHue = 0;
};
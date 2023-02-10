/*
Dans ce programme, la pin utilisée pour controller la bande de Led est la pin 6
 */
int counter;
int longueur_bande = 5;
#define PIN 6
#define PIXELNB 60
#include <Adafruit_NeoPixel.h>
// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_RGB + NEO_KHZ800);
void setup() {

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
 }
void loop () {
  for(counter = 0; counter < (PIXELNB) ; counter++)
 {
    strip.setPixelColor(counter,   0, 255, 0  );
    strip.setPixelColor(counter-longueur_bande, 0, 0,   255);
    strip.setPixelColor(counter+(61-longueur_bande),0, 255, 0  );
    strip.setPixelColor(counter+(60-longueur_bande),0, 0,   255);
    strip.show(); //commence a mettre les pixels en rouge un a un<
    delay(50);
 }
}
 /*
Arduino:1.8.6 (Windows 10), Carte : "Arduino Yún"

C:\Program Files (x86)\Arduino\arduino-builder -dump-prefs -logger=machine -hardware C:\Program Files (x86)\Arduino\hardware -hardware C:\Users\jc012369\AppData\Local\Arduino15\packages -tools C:\Program Files (x86)\Arduino\tools-builder -tools C:\Program Files (x86)\Arduino\hardware\tools\avr -tools C:\Users\jc012369\AppData\Local\Arduino15\packages -built-in-libraries C:\Program Files (x86)\Arduino\libraries -libraries \\me50f003.edu.stanislas.montreal\datas_etudiants\jc012369\Documents\Arduino\libraries -fqbn=arduino:avr:yun -vid-pid=0X2341_0X8041 -ide-version=10806 -build-path C:\Users\jc012369\AppData\Local\Temp\arduino_build_982862 -warnings=none -build-cache C:\Users\jc012369\AppData\Local\Temp\arduino_cache_760315 -prefs=build.warn_data_percentage=75 -prefs=runtime.tools.avr-gcc.path=C:\Users\jc012369\AppData\Local\Arduino15\packages\arduino\tools\avr-gcc\5.4.0-atmel3.6.1-arduino2 -prefs=runtime.tools.avrdude.path=C:\Users\jc012369\AppData\Local\Arduino15\packages\arduino\tools\avrdude\6.3.0-arduino14 -prefs=runtime.tools.arduinoOTA.path=C:\Users\jc012369\AppData\Local\Arduino15\packages\arduino\tools\arduinoOTA\1.2.1 -verbose \\me50f003.edu.stanislas.montreal\datas_etudiants\JC012369\Desktop\code_led\code_led.ino
C:\Program Files (x86)\Arduino\arduino-builder -compile -logger=machine -hardware C:\Program Files (x86)\Arduino\hardware -hardware C:\Users\jc012369\AppData\Local\Arduino15\packages -tools C:\Program Files (x86)\Arduino\tools-builder -tools C:\Program Files (x86)\Arduino\hardware\tools\avr -tools C:\Users\jc012369\AppData\Local\Arduino15\packages -built-in-libraries C:\Program Files (x86)\Arduino\libraries -libraries \\me50f003.edu.stanislas.montreal\datas_etudiants\jc012369\Documents\Arduino\libraries -fqbn=arduino:avr:yun -vid-pid=0X2341_0X8041 -ide-version=10806 -build-path C:\Users\jc012369\AppData\Local\Temp\arduino_build_982862 -warnings=none -build-cache C:\Users\jc012369\AppData\Local\Temp\arduino_cache_760315 -prefs=build.warn_data_percentage=75 -prefs=runtime.tools.avr-gcc.path=C:\Users\jc012369\AppData\Local\Arduino15\packages\arduino\tools\avr-gcc\5.4.0-atmel3.6.1-arduino2 -prefs=runtime.tools.avrdude.path=C:\Users\jc012369\AppData\Local\Arduino15\packages\arduino\tools\avrdude\6.3.0-arduino14 -prefs=runtime.tools.arduinoOTA.path=C:\Users\jc012369\AppData\Local\Arduino15\packages\arduino\tools\arduinoOTA\1.2.1 -verbose \\me50f003.edu.stanislas.montreal\datas_etudiants\JC012369\Desktop\code_led\code_led.ino
Using board 'yun' from platform in folder: C:\Users\jc012369\AppData\Local\Arduino15\packages\arduino\hardware\avr\1.6.23
Using core 'arduino' from platform in folder: C:\Users\jc012369\AppData\Local\Arduino15\packages\arduino\hardware\avr\1.6.23
Detecting libraries used...
"C:\\Users\\jc012369\\AppData\\Local\\Arduino15\\packages\\arduino\\tools\\avr-gcc\\5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -flto -w -x c++ -E -CC -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10806 -DARDUINO_AVR_YUN -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8041 "-DUSB_MANUFACTURER=\"Unknown\"" "-DUSB_PRODUCT=\"Arduino Yun\"" "-IC:\\Users\\jc012369\\AppData\\Local\\Arduino15\\packages\\arduino\\hardware\\avr\\1.6.23\\cores\\arduino" "-IC:\\Users\\jc012369\\AppData\\Local\\Arduino15\\packages\\arduino\\hardware\\avr\\1.6.23\\variants\\yun" "C:\\Users\\jc012369\\AppData\\Local\\Temp\\arduino_build_982862\\sketch\\code_led.ino.cpp" -o nul
"C:\\Users\\jc012369\\AppData\\Local\\Arduino15\\packages\\arduino\\tools\\avr-gcc\\5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -flto -w -x c++ -E -CC -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10806 -DARDUINO_AVR_YUN -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8041 "-DUSB_MANUFACTURER=\"Unknown\"" "-DUSB_PRODUCT=\"Arduino Yun\"" "-IC:\\Users\\jc012369\\AppData\\Local\\Arduino15\\packages\\arduino\\hardware\\avr\\1.6.23\\cores\\arduino" "-IC:\\Users\\jc012369\\AppData\\Local\\Arduino15\\packages\\arduino\\hardware\\avr\\1.6.23\\variants\\yun" "-I\\\\me50f003.edu.stanislas.montreal\\datas_etudiants\\jc012369\\Documents\\Arduino\\libraries\\Adafruit_NeoPixel" "C:\\Users\\jc012369\\AppData\\Local\\Temp\\arduino_build_982862\\sketch\\code_led.ino.cpp" -o nul
"C:\\Users\\jc012369\\AppData\\Local\\Arduino15\\packages\\arduino\\tools\\avr-gcc\\5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -flto -w -x c++ -E -CC -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10806 -DARDUINO_AVR_YUN -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8041 "-DUSB_MANUFACTURER=\"Unknown\"" "-DUSB_PRODUCT=\"Arduino Yun\"" "-IC:\\Users\\jc012369\\AppData\\Local\\Arduino15\\packages\\arduino\\hardware\\avr\\1.6.23\\cores\\arduino" "-IC:\\Users\\jc012369\\AppData\\Local\\Arduino15\\packages\\arduino\\hardware\\avr\\1.6.23\\variants\\yun" "-I\\\\me50f003.edu.stanislas.montreal\\datas_etudiants\\jc012369\\Documents\\Arduino\\libraries\\Adafruit_NeoPixel" "\\\\me50f003.edu.stanislas.montreal\\datas_etudiants\\jc012369\\Documents\\Arduino\\libraries\\Adafruit_NeoPixel\\Adafruit_NeoPixel.cpp" -o nul
"C:\\Users\\jc012369\\AppData\\Local\\Arduino15\\packages\\arduino\\tools\\avr-gcc\\5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -flto -w -x c++ -E -CC -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10806 -DARDUINO_AVR_YUN -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8041 "-DUSB_MANUFACTURER=\"Unknown\"" "-DUSB_PRODUCT=\"Arduino Yun\"" "-IC:\\Users\\jc012369\\AppData\\Local\\Arduino15\\packages\\arduino\\hardware\\avr\\1.6.23\\cores\\arduino" "-IC:\\Users\\jc012369\\AppData\\Local\\Arduino15\\packages\\arduino\\hardware\\avr\\1.6.23\\variants\\yun" "-I\\\\me50f003.edu.stanislas.montreal\\datas_etudiants\\jc012369\\Documents\\Arduino\\libraries\\Adafruit_NeoPixel" "\\\\me50f003.edu.stanislas.montreal\\datas_etudiants\\jc012369\\Documents\\Arduino\\libraries\\Adafruit_NeoPixel\\esp8266.c" -o nul
Generating function prototypes...
"C:\\Users\\jc012369\\AppData\\Local\\Arduino15\\packages\\arduino\\tools\\avr-gcc\\5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -flto -w -x c++ -E -CC -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10806 -DARDUINO_AVR_YUN -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8041 "-DUSB_MANUFACTURER=\"Unknown\"" "-DUSB_PRODUCT=\"Arduino Yun\"" "-IC:\\Users\\jc012369\\AppData\\Local\\Arduino15\\packages\\arduino\\hardware\\avr\\1.6.23\\cores\\arduino" "-IC:\\Users\\jc012369\\AppData\\Local\\Arduino15\\packages\\arduino\\hardware\\avr\\1.6.23\\variants\\yun" "-I\\\\me50f003.edu.stanislas.montreal\\datas_etudiants\\jc012369\\Documents\\Arduino\\libraries\\Adafruit_NeoPixel" "C:\\Users\\jc012369\\AppData\\Local\\Temp\\arduino_build_982862\\sketch\\code_led.ino.cpp" -o "C:\\Users\\jc012369\\AppData\\Local\\Temp\\arduino_build_982862\\preproc\\ctags_target_for_gcc_minus_e.cpp"
"C:\\Program Files (x86)\\Arduino\\tools-builder\\ctags\\5.8-arduino11/ctags" -u --language-force=c++ -f - --c++-kinds=svpf --fields=KSTtzns --line-directives "C:\\Users\\jc012369\\AppData\\Local\\Temp\\arduino_build_982862\\preproc\\ctags_target_for_gcc_minus_e.cpp"
Compilation du croquis...
"C:\\Users\\jc012369\\AppData\\Local\\Arduino15\\packages\\arduino\\tools\\avr-gcc\\5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10806 -DARDUINO_AVR_YUN -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8041 "-DUSB_MANUFACTURER=\"Unknown\"" "-DUSB_PRODUCT=\"Arduino Yun\"" "-IC:\\Users\\jc012369\\AppData\\Local\\Arduino15\\packages\\arduino\\hardware\\avr\\1.6.23\\cores\\arduino" "-IC:\\Users\\jc012369\\AppData\\Local\\Arduino15\\packages\\arduino\\hardware\\avr\\1.6.23\\variants\\yun" "-I\\\\me50f003.edu.stanislas.montreal\\datas_etudiants\\jc012369\\Documents\\Arduino\\libraries\\Adafruit_NeoPixel" "C:\\Users\\jc012369\\AppData\\Local\\Temp\\arduino_build_982862\\sketch\\code_led.ino.cpp" -o "C:\\Users\\jc012369\\AppData\\Local\\Temp\\arduino_build_982862\\sketch\\code_led.ino.cpp.o"
In file included from \\me50f003.edu.stanislas.montreal\datas_etudiants\JC012369\Desktop\code_led\code_led.ino:8:0:

\\me50f003.edu.stanislas.montreal\datas_etudiants\jc012369\Documents\Arduino\libraries\Adafruit_NeoPixel/Adafruit_NeoPixel.h:111:1: error: expected initializer before 'typedef'

 typedef uint16_t neoPixelType;

 ^

\\me50f003.edu.stanislas.montreal\datas_etudiants\jc012369\Documents\Arduino\libraries\Adafruit_NeoPixel/Adafruit_NeoPixel.h:121:46: error: 'neoPixelType' has not been declared

   Adafruit_NeoPixel(uint16_t n, uint8_t p=6, neoPixelType t=NEO_GRB + NEO_KHZ800);

                                              ^

\\me50f003.edu.stanislas.montreal\datas_etudiants\jc012369\Documents\Arduino\libraries\Adafruit_NeoPixel/Adafruit_NeoPixel.h:136:16: error: 'neoPixelType' has not been declared

     updateType(neoPixelType t);

                ^

Utilisation de la bibliothèque Adafruit_NeoPixel version 1.1.7 dans le dossier: \\me50f003.edu.stanislas.montreal\datas_etudiants\jc012369\Documents\Arduino\libraries\Adafruit_NeoPixel 
exit status 1
Erreur de compilation pour la carte Arduino Yún
*/

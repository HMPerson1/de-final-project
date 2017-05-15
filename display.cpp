#include <stdint.h>

#include <Adafruit_GFX.h>
#include <Fonts/FreeSerifBold9pt7b.h>

#include "display.h"

namespace toasting::display {

  static constexpr uint8_t kPinTftCs = 10;
  static constexpr uint8_t kPinTftDc = 9;

  DisplayClass::DisplayClass()
    : Adafruit_ILI9341{kPinTftCs, kPinTftDc}
  {
    setFont(&FreeSerifBold9pt7b);
  }

  void DisplayClass::writeRGBBitmap(
      uint16_t x, uint16_t y, uint16_t *pcolors,
      uint16_t w, uint16_t h)
  {
    setAddrWindow(x,y,w,h);
    writePixels(pcolors, w*h);
  }

  void setup() {
    Display.begin();
    Display.setRotation(3);
    Display.fillScreen(0x0000);
  }

  DisplayClass Display;

}

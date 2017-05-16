#include <avr/pgmspace.h>
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

  void DisplayClass::writeRGBBitmap(uint16_t x, uint16_t y, uint16_t *pcolors,
                                    uint16_t w, uint16_t h)
  {
    setAddrWindow(x,y,w,h);
    writePixels(pcolors, w*h);
  }

  void DisplayClass::drawText(const char* text, int16_t x, int16_t y, uint16_t w, uint16_t h,
                              Alignment hAlign, Alignment vAlign, uint16_t textColor)
  {
    // compute
    // no need to cache really because rendering takes orders of magnitude more time
    int16_t tx,ty;
    uint16_t tw,th;
    getTextBounds(const_cast<char*>(text), 0, 0, &tx, &ty, &tw, &th);
    // *** ASSUMING NO NEWLINES ***
    // the y-advance is a better measurement of "height" for alignment
    // purposes, whereas the actual height of the text can vary
    // depending on if there's any characters like 'p', 't', 'f', etc.
    th = 14;
    tx = x - tx;
    switch (hAlign) {
    case Alignment::kStart:                         break;
    case Alignment::kMid:    tx += (w/2) - (tw/2);  break;
    case Alignment::kEnd:    tx += w - tw;          break;
    }
    ty = y - ty;
    switch (vAlign) {
    case Alignment::kStart:                         break;
    case Alignment::kMid:    ty += (h/2) - (th/2);  break;
    case Alignment::kEnd:    ty += h - th;          break;
    }
    // render
    setTextColor(textColor);
    setCursor(tx, ty);
    print(text);

    // startWrite();
    // writeFastVLine(tx,y,ty-th-y,0xF800);
    // writeFastVLine(tx,ty-th,th,0xFFFF);
    // writeFastVLine(tx,ty,y+h-ty,0xF800);
    // endWrite();
  }

  void DisplayClass::print_2digit(uint16_t n)
  {
    if (n < 10) {
      print(0u);
    }
    print(n);
  }

  void setup()
  {
    Display.begin();
    Display.setRotation(3);
    Display.fillScreen(0x0000);
  }

  DisplayClass Display;

}

#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdint.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

namespace toasting::display {

  enum class Alignment {
    kStart,
    kMid,
    kEnd,
  };

  class DisplayClass : public Adafruit_ILI9341 {
  public:
    DisplayClass();
    void writeRGBBitmap(uint16_t x, uint16_t y, uint16_t* pcolors, uint16_t w, uint16_t h);
    void drawText(const char* text, int16_t x, int16_t y, uint16_t w, uint16_t h,
                  Alignment hAlign, Alignment vAlign, uint16_t textColor);
    void print_2digit(uint16_t);
  };

  void setup();

  extern DisplayClass Display;

}

#endif /* DISPLAY_H */

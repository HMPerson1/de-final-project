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
  struct TextLabel {
    int16_t x,y;
    uint16_t w,h;
    const char* text;
    Alignment hAlign,vAlign;
    uint16_t textColor,bkgdColor;

    void render(Adafruit_GFX& gfx) const {
      // compute
      // no need to cache really because rendering takes orders of magnitude more time
      int16_t tx,ty;
      uint16_t tw,th;
      gfx.getTextBounds(const_cast<char*>(text), 0, 0, &tx, &ty, &tw, &th);
      tx = -tx;
      switch (hAlign) {
      case Alignment::kStart:  tx += x;                   break;
      case Alignment::kMid:    tx += x + (w/2) - (tw/2);  break;
      case Alignment::kEnd:    tx += x + w - tw;          break;
      }
      ty = -ty;
      switch (vAlign) {
      case Alignment::kStart:  ty += y;                   break;
      case Alignment::kMid:    ty += y + (h/2) - (th/2);  break;
      case Alignment::kEnd:    ty += y + h - th;          break;
      }
      // render
      gfx.fillRect(x,y,w,h,bkgdColor);
      gfx.setTextColor(textColor);
      gfx.setCursor(tx, ty);
      gfx.print(text);
    }
  };

  class DisplayClass : public Adafruit_ILI9341 {
  public:
    DisplayClass();
    void writeRGBBitmap(uint16_t,uint16_t,uint16_t*,uint16_t,uint16_t);
  };

  void setup();

  extern DisplayClass Display;

}

#endif /* DISPLAY_H */

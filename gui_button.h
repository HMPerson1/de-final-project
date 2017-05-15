#ifndef GUI_BUTTON_H
#define GUI_BUTTON_H

#include <stdint.h>

#include "display.h"
#include "touch.h"

namespace toasting::gui {

  class Callback {
  public:
    virtual void operator()() = 0;
  };

  class GuiButton {
  protected:
    int16_t x,y;
    uint16_t w, h;
    Callback& onPress;
    bool isPressed = false;

    constexpr
    bool contains(int16_t px, int16_t py)
    { return (x <= px && px <= int16_t(x+w)) && (x <= py && py <= int16_t(y+h)); }

  public:
    constexpr
    GuiButton(int16_t x, int16_t y, uint16_t w, uint16_t h, Callback& onPress)
    : x{x}, y{y}, w{w}, h{h}, onPress(onPress)
    {}

    virtual void doRender() {
      display::Display.fillRect(x,y,w,h,0x000F);
      display::Display.drawRect(x,y,w,h,0xFFFF);
    }

    void dispatchTouch(touch::TouchEvent te) {
      // a press is when the touch starts in the button and stays in the button until
      // it ends in the button
      if (contains(te.x, te.y)) {
        switch (te.evType) {
        case touch::TEType::kDown:
          isPressed = true;
          break;
        case touch::TEType::kUp:
          if (isPressed) {
            onPress();
          }
          isPressed = false;
          break;
        case touch::TEType::kMove:
        case touch::TEType::kNone:
          break;
        }
      } else {
        isPressed = false;
      }
    }

  };

  template <typename T>
  class MemberCallback
    : public Callback
  {
  private:
    T& t;
    void (T::*f)();
  public:
    constexpr MemberCallback(T& t, void (T::*f)()) : t{t}, f{f} {}
    void operator()() override { (t.*f)(); }
  };

}

#endif /* GUI_BUTTON_H */

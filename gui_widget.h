#ifndef GUI_WIDGET_H
#define GUI_WIDGET_H

#include <stdint.h>

#include "gui_colors.h"
#include "touch.h"

namespace toasting::gui {

  using color::Color;

  class Widget {
  public:
    int16_t x,y;
    uint16_t w, h;
    Color bkgdColor;

    constexpr
    Widget(int16_t x, int16_t y, uint16_t w, uint16_t h, Color bkgdColor)
    : x{x}, y{y}, w{w}, h{h}, bkgdColor{bkgdColor}
    {}

    constexpr
    bool contains(int16_t px, int16_t py) const
    { return (x <= px && px <= int16_t(x+w)) && (y <= py && py <= int16_t(y+h)); }

    void invalidate();
    void dispatchRender();
    virtual void doRender();
    virtual void dispatchTouch(touch::Event const&) {}

  protected:
    bool needsRender = true;
  };

  class Callback {
  public:
    virtual void operator()() = 0;
  };

  class Button : public Widget {
  public:
    constexpr
    Button(int16_t x, int16_t y, uint16_t w, uint16_t h, Color bkgdColor, Callback& onPress)
    : Widget{x,y,w,h,bkgdColor}, onPress(onPress)
    {}

    void doRender() override;
    void dispatchTouch(touch::Event const&) override;

  protected:
    Callback& onPress;
    bool isPressed = false;
  };

  class TextButton : public Button {
  public:
    char const* text;
    Color textColor;

    constexpr
    TextButton(int16_t x, int16_t y, uint16_t w, uint16_t h, Color bkgdColor,
               Callback& onPress, char const* text, Color textColor)
    : Button{x,y,w,h,bkgdColor,onPress},
      text{text}, textColor{textColor}
    {}

    void doRender() override;
  };

  class TextLabel : public Widget {
  public:
    char const* text;
    Color textColor;

    constexpr
    TextLabel(int16_t x, int16_t y, uint16_t w, uint16_t h, Color bkgdColor, char const* text, Color textColor)
    : Widget{x,y,w,h,bkgdColor},
      text{text}, textColor{textColor}
    {}

    void doRender() override;
  };

  template <typename T>
  class MemberCallback : public Callback {
  public:
    constexpr MemberCallback(T& t, void (T::*f)()) : t{t}, f{f} {}
    void operator()() override { (t.*f)(); }
  private:
    T& t;
    void (T::*const f)();
  };

}

#endif /* GUI_WIDGET_H */

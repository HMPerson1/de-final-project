#ifndef GUI_SCREEN_H
#define GUI_SCREEN_H

#include <stddef.h>

#include "std_array.h"

#include "gui_button.h"
#include "touch.h"
#include "display.h"

namespace toasting::gui {

  class GuiScreen {
  public:
    virtual void dispatchTouch(touch::TouchEvent) = 0;
    virtual void doStart() = 0;
  };

  template<size_t BtnCnt>
  class AbstractGuiScreen : public GuiScreen {
  protected:
    std_array<GuiButton*, BtnCnt> buttons;

    constexpr
    AbstractGuiScreen(std_array<GuiButton*, BtnCnt> buttons)
    : buttons{buttons}
    {}

  public:
    void dispatchTouch(touch::TouchEvent te) override {
      for (auto btn : buttons) {
        btn->dispatchTouch(te);
      }
    }
    void doStart() override {
      display::Display.fillScreen(0x0000);
      for (auto btn : buttons) {
        btn->doRender();
      }
    }
  };

}

#endif /* GUI_SCREEN_H */


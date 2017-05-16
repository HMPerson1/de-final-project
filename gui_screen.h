#ifndef GUI_SCREEN_H
#define GUI_SCREEN_H

#include <stddef.h>

#include "std_array.h"

#include "gui_widget.h"
#include "touch.h"
#include "display.h"

namespace toasting::gui {

  class Screen {
  public:
    virtual void doStart() = 0;
    virtual void dispatchTouch(touch::Event const&) = 0;
    virtual void dispatchRender() = 0;
  };

  template<size_t WgtCnt>
  class AbstractScreen : public Screen {
  protected:
    std_array<Widget*, WgtCnt> const widgets;

    constexpr
    AbstractScreen(std_array<Widget*, WgtCnt> widgets)
    : widgets{widgets}
    {}

  public:
    void doStart() override
    {
      display::Display.fillScreen(0x0000);
      for (auto const& wgt : widgets) {
        wgt->invalidate();
      }
    }
    void dispatchTouch(touch::Event const& te) override
    {
      for (auto const& wgt : widgets) {
        wgt->dispatchTouch(te);
      }
    }
    void dispatchRender() override
    {
      for (auto const& wgt : widgets) {
        wgt->dispatchRender();
      }
    }
  };

}

#endif /* GUI_SCREEN_H */


#ifndef GUI_CANCEL_H
#define GUI_CANCEL_H

#include <stdint.h>

#include "touch.h"
#include "display.h"
#include "gui_button.h"
#include "gui_screen.h"

namespace toasting::gui {

  class TextButton : public GuiButton {
  protected:
    display::TextLabel textLbl;

  public:
    constexpr
    TextButton(const char* text, int16_t x, int16_t y, uint16_t w, uint16_t h, Callback& onPress)
    : GuiButton{x,y,w,h,onPress},
      textLbl{x,y,w,h,text,display::Alignment::kMid,display::Alignment::kMid,0xFFFF,0x0000}
    {}

    void doRender() override;
    const char*& text() { return textLbl.text; }
  };

  class CancelScreenClass : public AbstractGuiScreen<1> {
  private:
    static constexpr const char* cancelText = "Cancel";
    static constexpr const char* startText = "Start";
    bool started = false;
    unsigned long stopTime = 0;
    uint16_t toastingTime = 0;
    MemberCallback<CancelScreenClass> cancelCB{*this, &CancelScreenClass::onButton};
    TextButton button{startText, 80,80,60,40, cancelCB};

    void onButton();
    void stopToasting();

  public:
    void doStart() override;
    void dispatchTouch(touch::TouchEvent t) override;
    constexpr
    CancelScreenClass()
      : AbstractGuiScreen{std_array<GuiButton*, 1>{&button}}
    {}
    void setTimeLeft(uint16_t s);
  };

  extern CancelScreenClass CancelScreen;

}

#endif /* GUI_CANCEL_H */

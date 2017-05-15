#include "gui_cancel.h"

#include "gui.h"
#include "display.h"
#include "gui_main.h"

namespace toasting::gui {

  using display::Display;

  void TextButton::doRender() {
    GuiButton::doRender();
    textLbl.render(Display);
  }

  void CancelScreenClass::doStart() {
    started = false;
    button.text() = startText;
    AbstractGuiScreen<1>::doStart();
  }
  void CancelScreenClass::onButton() {
    if (started) {
      stopToasting();
    } else {
      started = true;
      button.text() = cancelText;
      button.doRender();
      stopTime = millis() + toastingTime * 1000;
    }
  }
  void CancelScreenClass::stopToasting() {
    changeScreen(MainScreen);
  }
  void CancelScreenClass::dispatchTouch(touch::TouchEvent t) {
    AbstractGuiScreen<1>::dispatchTouch(t);
    if (started) {
      unsigned long curTime = millis();
      if (curTime > stopTime) {
        stopToasting();
      } else {
        auto timeLeft = stopTime - curTime;
        Display.fillRect(150,140,40,50,0x0000);
        Display.setCursor(150, 150);
        Display.print(timeLeft/1000);
      }
    } else {
      Display.fillRect(150,140,40,50,0x0000);
      Display.setCursor(150, 150);
      Display.print(toastingTime);
    }
  }
  void CancelScreenClass::setTimeLeft(uint16_t s) {
    toastingTime = s;
  }

  CancelScreenClass CancelScreen;

}

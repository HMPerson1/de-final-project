#include "gui_main.h"

#include "toast.h"
#include "display.h"
#include "gui.h"
#include "gui_cancel.h"

namespace toasting::gui {

  using display::Display;

  void ToastButton::doRender() {
    GuiButton::doRender();
    Display.startWrite();
    Display.writeFillRect(x, y, w, 147, 0xF800);
    Display.writeFastHLine(x, y+147, w, 0xFFFF);
    Display.endWrite();
    toastText.render(Display);
  }

  void MainScreenClass::onLeftToast() {
    CancelScreen.setTimeLeft(toast::toasts[0][0].time);
    onToast();
  }
  void MainScreenClass::onRightToast() {
    CancelScreen.setTimeLeft(toast::toasts[0][1].time);
    onToast();
  }
  void MainScreenClass::onToast() {
    changeScreen(CancelScreen);
  }

  MainScreenClass MainScreen;

}

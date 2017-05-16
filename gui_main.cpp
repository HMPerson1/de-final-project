#include "gui_main.h"

#include "toast.h"
#include "display.h"
#include "gui.h"
#include "gui_toasting.h"
#include "gui_config.h"

namespace toasting::gui {

  using display::Display;
  using display::Alignment;

  void ToastButton::doRender()
  {
    Button::doRender();
    toast.render(x,y);
    Display.drawText(toast.name, x, y+152, 158, 30,
                     Alignment::kMid, Alignment::kMid, color::kWhite.color);
  }

  void MainScreenClass::onLeftToast()
  {
    ToastingScreen.toast = &toast::toasts[0][0];
    onToast();
  }

  void MainScreenClass::onRightToast()
  {
    ToastingScreen.toast = &toast::toasts[0][1];
    onToast();
  }

  void MainScreenClass::onToast()
  { changeScreen(ToastingScreen); }

  void MainScreenClass::onConfig()
  { changeScreen(ConfigScreen); }

  MainScreenClass MainScreen;

}

#include "gui.h"

#include "gui_screen.h"
#include "gui_main.h"
#include "touch.h"
#include "display.h"

namespace toasting::gui {

  static bool screenChanged = true;
  static GuiScreen* screen = &MainScreen;

  void guiTick() {
    GuiScreen& scrSave = *screen;
    if (screenChanged) {
      scrSave.doStart();
      screenChanged = false;
    }
    touch::TouchEvent te = touch::update();
    scrSave.dispatchTouch(te);
    delay(80);
  }

  void changeScreen(GuiScreen& newScreen) {
    screen = &newScreen;
    screenChanged = true;
  }

}

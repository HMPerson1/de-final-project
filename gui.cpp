#include "gui.h"

#include "gui_screen.h"
#include "gui_main.h"
#include "touch.h"
// #include "display.h"

namespace toasting::gui {

  static bool screenChanged = true;
  static Screen* screen = &MainScreen;

  // using display::Display;

  void guiTick()
  {
    Screen& srnSave = *screen;
    if (screenChanged) {
      screenChanged = false;
      srnSave.doStart();
    }
    touch::Event te = touch::update();
    srnSave.dispatchTouch(te);
    srnSave.dispatchRender();

    // if (te.evType != touch::TEType::kNone) {
    //   Display.fillRect(10,200,80,40,0x000F);
    //   Display.setCursor(10,215);
    //   Display.println(te.x);
    //   Display.print(te.y);
    // }

    delay(80);
  }
  void changeScreen(Screen& newScreen)
  {
    screen = &newScreen;
    screenChanged = true;
  }

}

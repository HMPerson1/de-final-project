#ifndef GUI_H
#define GUI_H

#include "gui_screen.h"

namespace toasting::gui {

  void guiTick();
  void changeScreen(GuiScreen& newScreen);

}

#endif /* GUI_H */

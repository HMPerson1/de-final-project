#include "gui_config.h"

#include "gui.h"
#include "gui_main.h"
#include "display.h"
#include "toast.h"

namespace toasting::gui {

  void ConfigScreenClass::doStart()
  {
    needsRenderSelection = true;
    prevSelection = -1;
    AbstractScreen<5>::doStart();
  }

  void ConfigScreenClass::dispatchRender()
  {
    AbstractScreen<5>::dispatchRender();
    if (needsRenderSelection) {
      needsRenderSelection = false;
      if (prevSelection != -1) {
        renderSelectionBox(prevSelection, color::kBlack);
      }
      renderSelectionBox(static_cast<uint8_t>(toast::curWattage), color::kGreen);
    }
  }

  void ConfigScreenClass::on0800W()
  { select(toast::ToasterWattage::k0800); }
  void ConfigScreenClass::on1100W()
  { select(toast::ToasterWattage::k1100); }
  void ConfigScreenClass::on1500W()
  { select(toast::ToasterWattage::k1500); }

  void ConfigScreenClass::select(toast::ToasterWattage w)
  {
    prevSelection = static_cast<uint8_t>(toast::curWattage);
    toast::curWattage = w;
    needsRenderSelection = true;
    toast::saveWattage();
  }

  void ConfigScreenClass::onBack()
  { changeScreen(MainScreen); }

  void ConfigScreenClass::renderSelectionBox(uint8_t which, Color color)
  {
    using display::Display;
    auto x = btnXLoc[which];
    Display.drawRect(x-1, 100-1, 60+2, 40+2, color.color);
    Display.drawRect(x-2, 100-2, 60+4, 40+4, color.color);
  }

  constexpr int16_t ConfigScreenClass::btnXLoc[];

  ConfigScreenClass ConfigScreen;

}

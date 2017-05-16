#include "toast.h"

#include <Arduino.h>
#include <EEPROM.h>

#include "display.h"
#include "gui_colors.h"

namespace toasting::toast {

  constexpr int kToasterPin = 8;
  constexpr int kEepromSaveIdx = 0;

  void setup()
  {
    pinMode(kToasterPin, OUTPUT);
    stopToaster();

    EEPROM.get(kEepromSaveIdx, curWattage);
  }

  void saveWattage()
  { EEPROM.put(kEepromSaveIdx, curWattage); }

  void startToaster()
  { digitalWrite(kToasterPin, HIGH); }
  void stopToaster()
  { digitalWrite(kToasterPin, LOW); }


  void renderBread(int16_t x,int16_t y)
  {
    using display::Display;
    using gui::color::kBrown;
    Display.fillRect(x + 10, y + 50, 127, 80, kBrown.color);
    Display.fillCircle(x +  45, y + 50, 35, kBrown.color);
    Display.fillCircle(x + 101, y + 50, 35, kBrown.color);
  }
  void renderBagel(int16_t x,int16_t y)
  {
    using display::Display;
    using gui::color::kBrown;
    using gui::color::kBlack;
    Display.fillCircle(x + 79, y + 73, 63, kBrown.color);
    Display.fillCircle(x + 79, y + 73, 30, kBlack.color);
  }

  ToasterWattage curWattage = ToasterWattage::k1100;

}

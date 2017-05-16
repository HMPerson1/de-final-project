#ifndef TOAST_H
#define TOAST_H

#include <stdint.h>

#include "std_array.h"

namespace toasting::toast {

  struct Toast {
    uint32_t time;
    const char* name;
    void (&render)(int16_t, int16_t);
  };

  void renderBread(int16_t x, int16_t y);
  void renderBagel(int16_t x, int16_t y);

  constexpr
  std_array<std_array<Toast, 2>, 1> toasts
  { Toast{90, "Bread", renderBread}, Toast{150, "Bagel", renderBagel} };

  enum class ToasterWattage : uint8_t {
    k0800 = 0,
    k1100 = 1,
    k1500 = 2,
  };

  extern ToasterWattage curWattage;

  constexpr uint32_t conversion[3] = {1400, 1200, 1000};
  constexpr uint32_t convert(ToasterWattage w)
  { return conversion[static_cast<uint8_t>(w)]; }

  void setup();
  void saveWattage();
  void startToaster();
  void stopToaster();

}

#endif /* TOAST_H */

#include "touch.h"

#include <stdint.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

#include <Arduino.h>
#include <Wire.h>
#include <FT6206.h>

namespace toasting::touch {

  static FT6206 ctp;

  static TouchEvent last{TEType::kNone,0,0};

  constexpr
  TouchEvent::TouchEvent(TouchEvent::Type t, uint8_t (&i2cdat)[4])
    : evType{t},
      x{((i2cdat[0] & 0x0F) << 8) | static_cast<uint16_t>(i2cdat[1])},
      y{((i2cdat[2] & 0x0F) << 8) | static_cast<uint16_t>(i2cdat[3])}
  {}

  void setup() {
    ctp.begin(40);
  }

  TouchEvent update() {
    TS_Data data = ctp.poll();

    if (data.touched) {
      switch (last.evType) {
      case TEType::kNone:
      case TEType::kUp:
        last = TouchEvent(TEType::kDown, data.x, data.y);
        break;
      case TEType::kDown:
      case TEType::kMove:
        last = TouchEvent(TEType::kMove, data.x, data.y);
        break;
      }
    } else {
      switch (last.evType) {
      case TEType::kNone:
      case TEType::kUp:
        last = TouchEvent(TEType::kNone, last.x, last.y);
        break;
      case TEType::kDown:
      case TEType::kMove:
        last = TouchEvent(TEType::kUp, last.x, last.y);
        break;
      }
    }

    return last;
  }

}

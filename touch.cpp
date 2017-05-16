#include "touch.h"

#include <stdint.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

#include <Arduino.h>
#include <Wire.h>
#include <FT6206.h>

namespace toasting::touch {

  static FT6206 ctp;

  static Event last{TEType::kNone,0,0};

  void setup() {
    ctp.begin(40);
  }

  Event update() {
    TS_Data data = ctp.poll();

    if (data.touched) {
      switch (last.evType) {
      case TEType::kNone:
      case TEType::kUp:
        last = Event(TEType::kDown, data.y, 240-data.x);
        break;
      case TEType::kDown:
      case TEType::kMove:
        last = Event(TEType::kMove, data.y, 240-data.x);
        break;
      }
    } else {
      switch (last.evType) {
      case TEType::kNone:
      case TEType::kUp:
        last = Event(TEType::kNone, last.x, last.y);
        break;
      case TEType::kDown:
      case TEType::kMove:
        last = Event(TEType::kUp, last.x, last.y);
        break;
      }
    }

    return last;
  }

}

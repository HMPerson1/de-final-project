#ifndef TOUCH_H
#define TOUCH_H

#include <stdint.h>

namespace toasting::touch {

  struct TouchEvent {
    enum class Type {
      kNone,
      kDown,
      kMove,
      kUp,
    };

    Type evType;
    uint16_t x, y;

    constexpr TouchEvent(Type t, uint16_t x, uint16_t y) : evType(t), x(x), y(y) {}
    constexpr TouchEvent(Type t, uint8_t (&i2cdat)[4]);
  };

  using TEType = TouchEvent::Type;

  void setup();
  TouchEvent update();

}

#endif /* TOUCH_H */

// -*- mode: c++ -*-

#include <avr/interrupt.h>
#include <avr/sleep.h>

// #include <StandardCplusplus.h>
#include "std_array.h"

#include "display.h"
#include "gui.h"
#include "touch.h"
#include "toast.h"

using namespace toasting;

void setup() {
  // Serial.begin(9600);
  toast::setup();
  touch::setup();
  display::setup();
}

// static std_array<touch::TouchEvent, 80> buf;
// static touch::TouchEvent buf[80];

void loop() {
  // for (auto& e : buf) {
  //   e = touch::waitForTouch();
  // }
  // for (auto& e : buf) {
  //   Serial.print(static_cast<byte>(e.evType));
  //   Serial.print(", ");
  //   Serial.print(e.x);
  //   Serial.print(", ");
  //   Serial.println(e.y);
  // }
  toasting::gui::guiTick();
}

#include "gui_toasting.h"

#include "gui.h"
#include "display.h"
#include "gui_main.h"
#include "toast.h"

namespace toasting::gui {

  using display::Display;

  void ToastingScreenClass::doStart()
  {
    stopToasting();
    toastLabel.text = toast->name;
    lastTimeLeft = 0;
    AbstractScreen<3>::doStart();
    toast->render(130,40);
  }
  void ToastingScreenClass::onStButton()
  {
    if (toasting) {
      stopToasting();
    } else {
      startToasting();
    }
  }
  void ToastingScreenClass::onBackButton()
  {
    stopToasting();
    changeScreen(MainScreen);
  }
  void ToastingScreenClass::startToasting()
  {
    toasting = true;
    stButton.text = "Stop";
    stButton.invalidate();
    stopTime = millis() + toast->time * toast::convert(toast::curWattage);
    toast::startToaster();
  }
  void ToastingScreenClass::stopToasting()
  {
    toast::stopToaster();
    toasting = false;
    stButton.text = "Start";
    stButton.invalidate();
  }
  void ToastingScreenClass::dispatchRender()
  {
    AbstractScreen<3>::dispatchRender();
    if (toasting) {
      unsigned long curTime = millis();
      if (curTime >= stopTime) {
        stopToasting();
      } else {
        updateTimeLeft((stopTime - curTime)/1000);
      }
    } else {
      updateTimeLeft((toast->time* toast::convert(toast::curWattage))/1000);
    }
  }
  void ToastingScreenClass::updateTimeLeft(uint16_t timeLeft)
  {
    if (timeLeft != lastTimeLeft) {
      lastTimeLeft = timeLeft;
      Display.fillRect(10,100,60,30,0x0000);
      Display.setCursor(15, 120);
      Display.print_2digit(timeLeft/60);
      Display.print(':');
      Display.print_2digit(timeLeft%60);
    }
  }

  ToastingScreenClass ToastingScreen;

}

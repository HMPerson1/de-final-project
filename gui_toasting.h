#ifndef GUI_TOASTING_H
#define GUI_TOASTING_H

#include <stdint.h>

#include "toast.h"
#include "touch.h"
#include "display.h"
#include "gui_widget.h"
#include "gui_screen.h"

namespace toasting::gui {

  class ToastingScreenClass : public AbstractScreen<3> {
  public:
    toast::Toast const* toast = &toast::toasts[0][0];

    constexpr
    ToastingScreenClass()
    : AbstractScreen{std_array<Widget*, 3>{&stButton, &backButton, &toastLabel}}
    {}

    void doStart() override;
    void dispatchRender() override;

  private:
    bool toasting = false;
    unsigned long stopTime = 0;
    uint16_t lastTimeLeft = 0;
    MemberCallback<ToastingScreenClass> stCB{*this, &ToastingScreenClass::onStButton};
    MemberCallback<ToastingScreenClass> backCB{*this, &ToastingScreenClass::onBackButton};
    TextButton stButton{10, 50, 80, 40, color::kBlue, stCB, "Start", color::kWhite};
    TextButton backButton{10, 150, 80, 40, color::kBlue, backCB, "Back", color::kWhite};
    TextLabel toastLabel{0, 10, 320, 30, color::kBlack, toast->name, color::kWhite};

    void onStButton();
    void onBackButton();
    void startToasting();
    void stopToasting();
    void updateTimeLeft(uint16_t timeLeft);
  };

  extern ToastingScreenClass ToastingScreen;

}

#endif /* GUI_TOASTING_H */

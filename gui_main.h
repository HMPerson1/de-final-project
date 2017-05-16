#ifndef GUI_MAIN_H
#define GUI_MAIN_H

#include "toast.h"
#include "display.h"
#include "gui_widget.h"
#include "gui_screen.h"

namespace toasting::gui {

  class ToastButton : public Button {
  private:
    toast::Toast const& toast;

  protected:
    void doRender() override;

  public:
    constexpr
    ToastButton(int16_t x, int16_t y, const toast::Toast& toast, Callback& onPress)
    : Button{x, y, 158, 187, color::kBlue, onPress},
      toast{toast}
    {}
  };

  class MainScreenClass : public AbstractScreen<3> {
  private:
    MemberCallback<MainScreenClass> leftCB{*this, &MainScreenClass::onLeftToast};
    MemberCallback<MainScreenClass> rightCB{*this, &MainScreenClass::onRightToast};
    MemberCallback<MainScreenClass> configCB{*this, &MainScreenClass::onConfig};
    ToastButton leftToast{0, 0, toast::toasts[0][0], leftCB};
    ToastButton rightToast{162, 0, toast::toasts[0][1], rightCB};
    TextButton configBtn{255, 195, 60, 40, color::kBlue, configCB, "Config", color::kWhite};

    void onLeftToast();
    void onRightToast();
    void onToast();
    void onConfig();

  public:
    constexpr
    MainScreenClass()
    : AbstractScreen{std_array<Widget*, 3>{&leftToast, &rightToast, &configBtn}}
    {}
  };

  extern MainScreenClass MainScreen;

}

#endif /* GUI_MAIN_H */

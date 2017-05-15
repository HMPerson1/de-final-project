#ifndef GUI_MAIN_H
#define GUI_MAIN_H

#include "toast.h"
#include "display.h"
#include "gui_button.h"
#include "gui_screen.h"

namespace toasting::gui {

  class ToastButton : public GuiButton {
  private:
    const toast::Toast& toast;
    const display::TextLabel toastText;

  protected:
    void doRender() override;

  public:
    constexpr
    ToastButton(const toast::Toast& toast, int16_t x, int16_t y, Callback& onPress)
    : GuiButton{x,y,158,187,onPress},
      toast{toast},
      toastText{x,y+147,158,30,toast.name,display::Alignment::kMid,display::Alignment::kMid,0xF800,0x0000}
    {}
  };

  class MainScreenClass : public AbstractGuiScreen<2> {
  private:
    MemberCallback<MainScreenClass> leftCB{*this, &MainScreenClass::onLeftToast};
    MemberCallback<MainScreenClass> rightCB{*this, &MainScreenClass::onRightToast};
    ToastButton leftToast{toast::toasts[0][0],0,0,leftCB};
    ToastButton rightToast{toast::toasts[0][1],162,0,rightCB};
    void onLeftToast();
    void onRightToast();
    void onToast();

  public:
    constexpr
    MainScreenClass()
      : AbstractGuiScreen{std_array<GuiButton*, 2>{&leftToast, &rightToast}}
    {}
  };

  extern MainScreenClass MainScreen;

}

#endif /* GUI_MAIN_H */

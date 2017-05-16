#ifndef GUI_CONFIG_H
#define GUI_CONFIG_H

#include "std_array.h"
#include "toast.h"
#include "gui_screen.h"

namespace toasting::gui {

  class ConfigScreenClass : public AbstractScreen<5> {
  public:
    constexpr
    ConfigScreenClass()
    : AbstractScreen{std_array<Widget*, 5>{
        &titleLabel, &b0800WBtn, &b1100WBtn, &b1500WBtn, &backBtn
      }}
    {}

    void doStart() override;
    void dispatchRender() override;

  private:
    static constexpr int16_t btnXLoc[3] = {50, 130, 210};
    int8_t prevSelection = -1;
    bool needsRenderSelection = true;
    MemberCallback<ConfigScreenClass> b0800WCB{*this, &ConfigScreenClass::on0800W};
    MemberCallback<ConfigScreenClass> b1100WCB{*this, &ConfigScreenClass::on1100W};
    MemberCallback<ConfigScreenClass> b1500WCB{*this, &ConfigScreenClass::on1500W};
    MemberCallback<ConfigScreenClass> backCB{*this, &ConfigScreenClass::onBack};
    TextButton b0800WBtn{btnXLoc[0], 100, 60, 40, color::kBlue, b0800WCB,  "800W", color::kWhite};
    TextButton b1100WBtn{btnXLoc[1], 100, 60, 40, color::kBlue, b1100WCB, "1100W", color::kWhite};
    TextButton b1500WBtn{btnXLoc[2], 100, 60, 40, color::kBlue, b1500WCB, "1500W", color::kWhite};
    TextLabel titleLabel{0, 10, 320, 30, color::kBlack, "Toaster Wattage:", color::kWhite};
    TextButton backBtn{130, 170, 60, 40, color::kBlue, backCB, "Back", color::kWhite};

    void on0800W();
    void on1100W();
    void on1500W();
    void select(toast::ToasterWattage w);
    void onBack();
    void renderSelectionBox(uint8_t which, Color color);

  };

  extern ConfigScreenClass ConfigScreen;

}

#endif /* GUI_CONFIG_H */

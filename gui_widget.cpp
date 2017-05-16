#include "gui_widget.h"

#include "display.h"

namespace toasting::gui {

  using display::Display;

  void Widget::invalidate()
  { needsRender = true; }

  void Widget::dispatchRender()
  {
    if (needsRender) {
      needsRender = false;
      doRender();
    }
  }

  void Widget::doRender()
  { Display.fillRect(x,y,w,h,bkgdColor.color); }

  void Button::doRender()
  {
    Widget::doRender();
    Display.drawRect(x,y,w,h,0xFFFF);
  }

  void Button::dispatchTouch(touch::Event const& te)
  {
    // a press is when the touch starts in the button and stays in the button until
    // it ends in the button
    if (contains(te.x, te.y)) {
      switch (te.evType) {
      case touch::TEType::kDown:
        isPressed = true;
        break;
      case touch::TEType::kUp:
        if (isPressed) {
          onPress();
        }
        isPressed = false;
        break;
      case touch::TEType::kMove:
      case touch::TEType::kNone:
        break;
      }
    } else {
      isPressed = false;
    }
  }

  void TextButton::doRender()
  {
    using display::Alignment;
    Button::doRender();
    Display.drawText(text,x,y,w,h,Alignment::kMid,Alignment::kMid,textColor.color);
  }

  void TextLabel::doRender()
  {
    using display::Alignment;
    Widget::doRender();
    Display.drawText(text,x,y,w,h,Alignment::kMid,Alignment::kMid,textColor.color);
  }

}

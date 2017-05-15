#ifndef TOAST_H
#define TOAST_H

#include <stdint.h>

#include "std_array.h"

namespace toasting::toast {

  struct Toast {
    uint16_t time;
    const char* name;
  };

  constexpr
  std_array<std_array<Toast, 2>, 1> toasts
  { Toast{20, "Bread"}, Toast{20, "Bagel"} };

}

#endif /* TOAST_H */

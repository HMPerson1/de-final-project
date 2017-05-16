;;; Directory Local Variables
;;; For more information see (info "(emacs) Directory Variables")

((c++-mode
  (flycheck-gcc-include-path "/usr/share/arduino/hardware/archlinux-arduino/avr/cores/arduino" "/usr/share/arduino/hardware/archlinux-arduino/avr/variants/standard" "/home/michael/Arduino/libraries/Adafruit_GFX_Library" "/usr/share/arduino/hardware/archlinux-arduino/avr/libraries/SPI/src" "/usr/share/arduino/hardware/archlinux-arduino/avr/libraries/EEPROM/src" "/home/michael/Arduino/libraries/Adafruit_ILI9341" "/usr/share/arduino/hardware/archlinux-arduino/avr/libraries/Wire/src" "/home/michael/Arduino/libraries/FT6206")
  (flycheck-gcc-definitions "F_CPU=16000000L" "ARDUINO=10800" "ARDUINO_AVR_UNO" "ARDUINO_ARCH_AVR")
  (flycheck-gcc-args "-Os" "-fpermissive" "-fno-exceptions" "-ffunction-sections" "-fdata-sections" "-fno-threadsafe-statics" "-flto" "-fno-devirtualize" "-fno-use-cxa-atexit" "-mmcu=atmega328p")
  (flycheck-gcc-language-standard . "gnu++11")
  (flycheck-c/c++-gcc-executable . "/usr/bin/avr-g++")))

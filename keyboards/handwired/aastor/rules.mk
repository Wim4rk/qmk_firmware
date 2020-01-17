# MCU name
MCU = atmega32u4

# Processor frequency
F_CPU = 8000000

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp
BOOTLOADER = caterina       # I'm using an Adafruit Feather 32u4 Basic Proto
                            # Maybe your hardware needs another bootloader?

CUSTOM_MATRIX = yes         # We have a custom matrix
SRC = matrix.c sx1509.c i2c_master.c     # Adding support files for that

# Build Options --- change yes to no to disable
# ###################
BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE = no        # Mouse keys(+4700)
EXTRAKEY_ENABLE = yes       # Audio control and System control(+450)
CONSOLE_ENABLE = yes        # Console for debug(+400)
COMMAND_ENABLE = no         # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = no            # USB Nkey Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
MIDI_ENABLE = no            # MIDI support (+2400 to 4200, depending on config)
UNICODE_ENABLE = no         # Unicode
AUDIO_ENABLE = no           # Audio output on port C6
FAUXCLICKY_ENABLE = no      # Use buzzer to emulate clicky switches
BLUETOOTH_ENABLE = no       # Enable Bluetooth with Adafruit EZ-Key HID
BLUETOOTH = AdafruitBLE		# Enable Bluetooth with Adafruit Bluefruit SPI friend.

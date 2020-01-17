/*
Copyright 2019 Olov Wimark

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"
// #include "i2c_master.c"
// #include "sx1509.c"

/* USB Device descriptor parameter */
#define VENDOR_ID 0xFEED
#define PRODUCT_ID 0xB170
#define DEVICE_VER 0x0001
#define MANUFACTURER    Wim4rk
#define PRODUCT         POC_Mk0
#define DESCRIPTION     Aardvark Mk0

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 15

/*COL DIRECTION*/
#define DIODE_DIRECTION COL2ROW

#define MATRIX_ROW_PINS \
    { F7, F6, F5, F4, F1 }
#define UNUSED_PINS

// We have an Adafruit BLE SPI Friend board attached
#define AdafruitBleResetPin B5
#define AdafruitBleCSPin F0
#define AdafruitBleIRQPin D7
#define AdafruitBlePowerPin C6


/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

// Always send Escape if GUI is pressed
#define GRAVE_ESC_GUI_OVERRIDE

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

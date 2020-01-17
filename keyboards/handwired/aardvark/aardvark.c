/* Copyright 2020 Olov Wimark
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "aardvark.h"

// Optional override functions below.
// You can leave any or all of these undefined.
// These are only required if you want to perform custom actions.


void matrix_init_kb(void) {
  // bool sx1509_init(void);
  // bool sx1509_make_ready(void);
  matrix_init_user();
}

void matrix_scan_kb(void) {
  // uint16_t sx1509_read(void);
  matrix_scan_user();
}

// void matrix_init_user(void) {}

void matrix_scan_user(void) {}


bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
  // put your per-action keyboard code here
  // runs for every action, just before processing by the firmware

  return process_record_user(keycode, record);
}
//
// void led_set_kb(uint8_t usb_led) {
//   // put your keyboard LED indicator (ex: Caps Lock LED) toggling code here
//
//   led_set_user(usb_led);
// }

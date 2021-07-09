#include QMK_KEYBOARD_H

#include "keymap_nordic.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
enum layer_id {
  _BASE = 0,
  _PROG,
  _SYMB,
  _FUNC,
  _MOD,
};

enum endgame_keycodes {
    BASE = SAFE_RANGE,
    PROG,
    SYMB,
    FUNC,
    MOD,
    SH_BANG
};

// #define SYM_CAP LT(_SYMB, KC_CAPS) // Layer _SYMB when held, Caps lock when tapped.
// The above down't work that well...

#define ____ KC_TRNS
#define XXXX KC_NO
#define CTL(k)  ACTION_MODS_KEY(MOD_LCTL, k)

enum combos {
    CAPS
};

const uint16_t PROGMEM caps_combo[] = {KC_RCTL, KC_RSFT, COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
    [CAPS] = COMBO(caps_combo, KC_CAPS)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT_65_iso( // Normal layout
    KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,      KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,      KC_LBRC, KC_RBRC,          KC_INS,
//    SYM_CAP,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,   KC_QUOT, KC_NUHS, KC_ENT,  KC_HOME,
    MO(_SYMB), KC_A,   KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,   KC_QUOT, KC_NUHS, KC_ENT,  KC_HOME,
    KC_LSFT,  KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,    KC_SLSH, KC_RSFT, KC_UP,   KC_END,
    KC_LCTL,  KC_LGUI, KC_LALT,                            KC_SPC,                    KC_RALT, MO(_FUNC), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
),

[_PROG] = LAYOUT_65_iso( // Shifted (and alted) num row, alphas normal.
       ____,   S(KC_1),  S(KC_2),  S(KC_3), RALT(KC_4), S(KC_5), S(KC_6),
    S(KC_7),   S(KC_8),  S(KC_9),  S(KC_0), S(KC_MINS),    ____,    ____,  ____,

    ____,  ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,       ____,
    ____,  ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
    ____,  ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
    ____,  ____, ____,                   ____,             ____, ____, ____, ____, ____, ____
),

[_SYMB] = LAYOUT_65_iso(
    KC_GRV, KC_1,     KC_2,       KC_3,       KC_4, KC_5,    KC_6, KC_7,    KC_8,       KC_9,       KC_0,    KC_MINS, KC_EQL,          ____,  ____,
    ____,   ____,     ____,       ____,       ____, ____,    ____, NO_QUES, RALT(KC_8), RALT(KC_9), NO_BSLS,    ____,   ____,                KC_PSCR,
    ____, RALT(KC_2), ____, RALT(KC_4), S(KC_MINS), ____, S(KC_6), NO_LCBR, NO_LPRN,    NO_RPRN,    NO_RCBR, KC_QUOT,   ALGR(KC_NUHS), ____, KC_PGUP,
    ____,   ____,     ____,       ____,       ____, ____,    ____, NO_DLR,  S(KC_0),    NO_LESS,    NO_GRTR, NO_SLSH,   ____,          ____, KC_PGDN,
    ____,   ____,     ____,                                  ____,                               ____,       ____,    ____,   ____,          ____,  ____
),

[_FUNC] = LAYOUT_65_iso( // Function keys, macros
    ____,    KC_F1,   KC_F2, KC_F3,  KC_F4,  KC_F5,  KC_F6, KC_F7, KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12,      ____,   KC_BRIU,
    ____,     ____,   ____,   ____,   ____,   ____,   ____,  ____,  ____,   ____,   SH_BANG,   ____,   ____,              KC_BRID,
    ____,     ____,   ____,   ____,   ____,   ____,   ____,  ____,  ____,   ____,   ____,   ____,   ____,      ____,   ____,
    ____,     ____,   ____,   BL_DEC, BL_TOGG, BL_INC, ____, ____,  ____,   ____,   ____,   ____,   ____,    KC_VOLU,  ____,
    ____,     ____,   ____,                        KC_MPLY,                 ____,   ____,   ____,   KC_MPRV,  KC_VOLD, KC_MNXT
),

[_MOD] = LAYOUT_65_iso(
    KC_ESC, BASE,    PROG,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    KC_MINS, KC_EQL,  RESET, ____,
    ____,   XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX, RALT(KC_4), RALT(8), RALT(9),  XXXX,       XXXX,    XXXX,        ____,
    ____,   XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX, S(KC_7), S(KC_8), S(KC_9), S(KC_0),  KC_QUOT,       XXXX, ____,  ____,
    ____,   XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    ____,     ____,  S(KC_7),   ____,    ____,  ____,
    ____,   ____,    ____,                               ____,                      ____,     ____,    ____,    ____,    ____,  ____
),
};

// PERSISTENT LAYERS:
void persistant_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BASE:
            if (record->event.pressed) {
                persistant_default_layer_set(1UL<<_BASE);
            }
            return false;
            break;
        case PROG:
            if (record->event.pressed) {
                persistant_default_layer_set(1UL<<_PROG);
            }
            return false;
            break;
        case SH_BANG:
            if (record->event.pressed) {
                SEND_STRING("#!/usr/bin/env python3\n#! /|/ coding> UTF/8 /|/");
            }
            break;
        case KC_ESC:
            // Detect the activation of only Left Alt
            if ((get_mods() & MOD_BIT(KC_LALT)) == MOD_BIT(KC_LALT)) {
                if (record->event.pressed) {
                    // No need to register KC_LALT because it's already active.
                    // The Alt modifier will apply on this KC_GRAVE.
                    register_code(KC_GRAVE);
                } else {
                    unregister_code(KC_GRAVE);
                }
                // Do not let QMK process the keycode further
                return false;
            }
            // Else, let QMK process the KC_ESC keycode as usual
            return true;
        }
    return true;
}


//ACTIVATE THIRD LAYER (BOTH LAYER BUTTONS ACTIVE).

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYMB, _FUNC, _MOD);
}

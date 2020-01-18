#include QMK_KEYBOARD_H

#include "aardvark.h"
#include "action_layer.h"
#include "pincontrol.h"
/*#ifdef MOUSEKEY_ENABLE
#include "mousekey.h"
#endif
*/
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
    MOD
};

#define SYM_CAP LT(_SYMB, KC_CAPS) // Layer _SYMB when held, Caps lock when tapped.

#define ____ KC_TRNS
#define XXXX KC_NO
#define CTL(k)  ACTION_MODS_KEY(MOD_LCTL, k)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT( // Normal layout
    KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,      KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,      KC_LBRC, KC_RBRC,          KC_INS,
    SYM_CAP,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,   KC_QUOT, KC_NUHS, KC_ENT,  KC_HOME,
    KC_LSFT,  KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,    KC_SLSH, KC_RSFT, KC_UP,   KC_END,
    KC_LCTL,  KC_LGUI, KC_LALT,                            KC_SPC,                    KC_RALT, MO(_FUNC), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
),

[_PROG] = LAYOUT( // Shifted (and alted) num row, alphas normal.
       ____,   S(KC_1),  S(KC_2),  S(KC_3), RALT(KC_4), S(KC_5), S(KC_6),
    S(KC_7),   S(KC_8),  S(KC_9),  S(KC_0), S(KC_MINS),    ____,    ____,  ____,

    ____,  ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,       ____,
    ____,  ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
    ____,  ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
    ____,  ____, ____,                   ____,             ____, ____, ____, ____, ____, ____
),

[_SYMB] = LAYOUT(
    KC_GRV, KC_1,     KC_2,       KC_3,       KC_4, KC_5,    KC_6,       KC_7,       KC_8,       KC_9,       KC_0, KC_MINS, KC_EQL,          ____,  ____,
    ____,   ____,     ____,       ____,       ____, ____,    ____,    NO_SLSH, RALT(KC_8), RALT(KC_9),    NO_BSLS,    ____,   ____,                KC_PSCR,
    ____, RALT(KC_2), ____, RALT(KC_4), S(KC_MINS), ____, S(KC_6),    NO_QUES,    NO_LPRN,    NO_RPRN,    NO_TILD, KC_QUOT,   ALGR(KC_NUHS), ____, KC_PGUP,
    ____,   ____,     ____,       ____,       ____, ____,    ____,     NO_DLR,    S(KC_0),    NO_LESS,    NO_PIPE, NO_SLSH,   ____,          ____, KC_PGDN,
    ____,   ____,     ____,                                  ____,                               ____,       ____,    ____,   ____,          ____,  ____
),

[_FUNC] = LAYOUT( // Function keys, macros
    ____,    KC_F1,   KC_F2, KC_F3,  KC_F4,  KC_F5,  KC_F6, KC_F7, KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12,      ____,   KC_BRIU,
    ____,     ____,   ____,   ____,   ____,   ____,   ____,  ____,  ____,   ____,   ____,   ____,   ____,              KC_BRID,
    ____,     ____,   ____,   ____,   ____,   ____,   ____,  ____,  ____,   ____,   ____,   ____,   ____,      ____,   ____,
    ____,     ____,   ____,   ____,   ____,   ____,   OUT_BT,  ____,  ____,   ____,   ____,   ____,   ____,    KC_VOLU,  ____,
    ____,     ____,   ____,                        KC_MPLY,                 ____,   ____,   ____,   KC_MPRV,  KC_VOLD, KC_MNXT
),

[_MOD] = LAYOUT(
    KC_ESC, BASE,    PROG,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    KC_MINS, KC_EQL,  RESET, ____,
    ____,   XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX, RALT(KC_4), RALT(8), RALT(9),  XXXX,       XXXX,    XXXX,        ____,
    ____,   XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX, S(KC_7), S(KC_8), S(KC_9), S(KC_0),  KC_QUOT,       XXXX, ____,  ____,
    ____,   XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    ____,     ____,  S(KC_7),   ____,    ____,  ____,
    ____,   ____,    ____,                               ____,                      ____,     ____,    ____,    ____,    ____,  ____
),
};

// void matrix_init_user(void) {
// }

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
        }
    return true;
}

//ACTIVATE THIRD LAYER (BOTH LAYER BUTTONS ACTIVE).

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYMB, _FUNC, _MOD);
}

// How about using macros to check if shift is pressed and
// then return numbers from shifted keys? Would that work when
// shift is in the keycode? Ex. S(KC_7)...

// if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {
//   return MACRODOWN(T(PGUP), END);
// } else {
//   return MACRODOWN(T(HOME), END);
// }

//MACROS:

static const macro_t mac_cut[] PROGMEM = { D(LGUI), T(X), U(LGUI), END };
static const macro_t win_cut[] PROGMEM = { D(LSFT), T(DELT), U(LSFT), END };

static const macro_t mac_copy[] PROGMEM = { D(LGUI), T(C), U(LGUI), END };
static const macro_t win_copy[] PROGMEM = { D(LCTL), T(INS), U(LCTL), END };

static const macro_t mac_paste[] PROGMEM = { D(LGUI), T(V), U(LGUI), END };
static const macro_t win_paste[] PROGMEM = { D(LSFT), T(INS), U(LSFT), END };

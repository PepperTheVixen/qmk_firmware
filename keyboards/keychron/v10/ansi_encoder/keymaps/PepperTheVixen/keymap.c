/* Copyright 2023  PepperTheVixen (https://github.com/pepperthevixen)
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

#include QMK_KEYBOARD_H

// clang-format off

enum layers{
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN,
    WIN_EXTRA
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)
#define WM_DWOR C(KC_BSPC)

enum custom_keycodes {
    // NVDA shortcuts
  NV_TIME = SAFE_RANGE,
  NV_SLEP,
  NV_STRT,
  NV_DUCK,
  NV_BATT,
  // Windows macros
  WM_SLCP
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case NV_TIME:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_INS) SS_TAP(X_F12) SS_UP(X_INS)); //tells the time in NVDA
        } else {
        }
        break;

    case NV_SLEP:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_INS) SS_LSFT("s") SS_UP(X_INS)); //toggles sleep mode for the current application in NVDA
        } else {
        }
        break;
        case NV_STRT:
        if (record->event.pressed) {
            SEND_STRING(SS_LGUI("s") SS_DELAY(100) "nvda" SS_TAP(X_ENT)); //searches for NVDA to run the app if it's not running or restart the app if it's already running
        } else {
}
        break;  

        case NV_DUCK:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_INS) SS_LSFT("d") SS_UP(X_INS)); //toggles ducking mode in NVDA
        } else {            
        }
break;
        case NV_BATT:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_INS) SS_LSFT("b") SS_UP(X_INS)); //reads battery info in NVDA if one is present
        } else {
                    }
break;

    case WM_SLCP:
        if (record->event.pressed) {
           SEND_STRING(SS_LCTL("ac")); // selects all and copies that URL so you can share the dank meme about catgirls wearing programmer socks with your friend 
        } else {
}
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_89(
        KC_MUTE,  KC_ESC,   KC_BRID,  KC_BRIU,  KC_NO,    KC_NO,    RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_DEL,             KC_PGUP,
        _______,  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGDN,
        _______,  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_HOME,
        _______,  KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_END,
        _______,  KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        _______,  KC_LCTL,  KC_LOPT,            KC_LCMD,  KC_SPC,  MO(MAC_FN),                     KC_SPC,             KC_RCMD,                      KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_ansi_89(
        RGB_TOG,  _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,   _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
        _______,  _______,            _______,  _______,  _______,  _______,   _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,            _______,  _______,  _______,                       _______,            KC_ROPT,                      _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_ansi_89(
        KC_MPLY,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,             KC_PGUP,
        A(KC_F4),  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGDN,
     KC_DEL,  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_HOME,
        WM_DWOR,  KC_INS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_END,
        WM_SLCP,  KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        NV_TIME,  KC_LCTL,  KC_LWIN,            KC_LALT,  KC_SPC,  MO(WIN_FN),                     LT(WIN_EXTRA, KC_SPC),             KC_RCTL,                      KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_ansi_89(
        RGB_TOG,  _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,   KC_VOLU,  KC_PSCR,            _______,
        NV_STRT,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  KC_NUM,  KC_PSLS,  KC_PAST,  KC_PMNS,   _______,  _______,            _______,
        _______,  RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,   _______,  KC_P7,  KC_P8,  KC_P9,  _______,  _______,   _______,  _______,            _______,
        NV_DUCK,  KC_CAPS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,   _______,  KC_P4,  KC_P5,  KC_P6,  KC_PPLS,  _______,             _______,            _______,
        NV_SLEP,  _______,            _______,  _______,  _______,  _______,   _______,  _______,  NK_TOGG,  KC_P1,  KC_P2,  KC_P3,   KC_PDOT,  _______,  KC_APP,
        NV_BATT,  _______,  _______,            _______,  _______,  _______,                       KC_P0,            KC_RALT,                       KC_HOME,  KC_H,  KC_END),

        [WIN_EXTRA] = LAYOUT_ansi_89(
        KC_MPLY,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,             KC_PGUP,
        A(KC_F4),  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGDN,
     KC_DEL,  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_HOME,     KC_UP,     KC_END,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_HOME,
        WM_SLCP,  KC_INS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_LEFT,     KC_DOWN,     KC_RGHT,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_END,
        NV_SLEP,  KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_B,     KC_N,     KC_PGUP,     KC_COMM,  KC_PGDN,   KC_SLSH,  KC_RSFT,  KC_UP,
        NV_TIME,  KC_LCTL,  KC_LWIN,            KC_LALT,  KC_SPC,  KC_APP,                     LT(WIN_EXTRA, KC_SPC),             KC_RCTL,                      KC_LEFT,  KC_DOWN,  KC_RGHT),

};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [MAC_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [MAC_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [WIN_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [WIN_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [WIN_EXTRA]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) }
};
#endif // ENCODER_MAP_ENABLE

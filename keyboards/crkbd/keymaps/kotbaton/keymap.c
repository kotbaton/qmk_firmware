/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H
#include <stdio.h>

enum custom_keycodes {
  VIM_CPY = SAFE_RANGE,
  LTX_BEGIN,
  LTX_REF,
  LTX_LABEL,
  LTX_SEC,
  NAME,
  EMAIL,
  TEL,
  QMK_KEY
};

#define HOME_A    LGUI_T(KC_A)
#define HOME_S    LALT_T(KC_S)
#define HOME_D    LCTL_T(KC_D)
#define HOME_F    LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J    RSFT_T(KC_J)
#define HOME_K    RCTL_T(KC_K)
#define HOME_L    LALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)

// Left-hand home row mode on LOWER layer
#define HL_F1 LGUI_T(KC_F1)
#define HL_F2 LALT_T(KC_F2)
#define HL_F3 LCTL_T(KC_F3)
#define HL_F4 LSFT_T(KC_F4)

// Right-hand home row mode on LOWER layer
#define HL_MINS RSFT_T(KC_MINS)
#define HL_LBRC RCTL_T(KC_LBRC)
#define HL_RBRC LALT_T(KC_RBRC)
#define HL_BSLS RGUI_T(KC_BSLS)

#define CUT_X LT(0, KC_X)
#define CPY_C LT(0, KC_C)
#define PST_V LT(0, KC_V)

#define M_HOME LT(3, KC_HOME)
#define M_END LT(3, KC_END)

#define MY_MUTE KC_KB_MUTE
#define MY_VOLU KC_KB_VOLUME_UP
#define MY_VOLD KC_KB_VOLUME_DOWN

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
LT(5, KC_TAB),    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
SFT_T(KC_ESC), HOME_A,   HOME_S,  HOME_D,  HOME_F,    KC_G,                         KC_H,  HOME_J,  HOME_K,  HOME_L, HOME_SCLN, RSFT_T(KC_QUOT),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,   CUT_X,   CPY_C,   PST_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, RCTL_T(KC_ENT),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          LM(2, MOD_LGUI),   MO(2),  KC_SPC,     KC_ENT,   MO(3), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
SFT_T(KC_ESC),   KC_A,     KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,  KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          LM(2, MOD_LGUI),   MO(2),  KC_SPC,     KC_ENT,   MO(3), KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

  [2] = LAYOUT_split_3x6_3( // LOWER
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                             KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______,  HL_F1,   HL_F2,  HL_F3,   HL_F4,   KC_F5,                          KC_EQL, HL_MINS, HL_LBRC, HL_RBRC, HL_BSLS, KC_PRINT_SCREEN,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, MY_MUTE, MY_VOLD, MY_VOLU, _______, _______,                       KC_PLUS, KC_UNDS, KC_LCBR, KC_RCBR, KC_PIPE, KC_DEL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_SPC, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3( // RAISE
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______,    NAME, LTX_SEC, _______, _______, LTX_REF,                       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_UNDS, KC_EQL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______,   EMAIL,     TEL, VIM_CPY,LTX_LABEL,LTX_BEGIN,                     KC_PGUP, KC_PGDN,  M_HOME, M_END,   KC_PIPE, KC_DEL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT,   DF(0),  DF(1),  XXXXXXX, XXXXXXX, XXXXXXX,                     RGB_SPD, RGB_SPI, RGB_SAD, RGB_SAI, XXXXXXX, QMK_KEY,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        XXXXXXX, RGB_TOG, RGB_VAD, RGB_VAI, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                       XXXXXXX, RGB_MOD, RGB_HUD, RGB_HUI, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, XXXXXXX,  KC_SPC,     KC_ENT, XXXXXXX, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 4
#define L_RAISE 8
#define L_ADJUST 16

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, 2, 3, 4);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        set_keylog(keycode, record);
    }
    switch (keycode) {
        case CUT_X:
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_X));
                return false;
            }
            return true;
        case CPY_C:
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_C));
                return false;
            }
            return true;
        case PST_V:
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_V));
                return false;
            }
            return true;

        case M_HOME:
            if (record->tap.count && record->event.pressed) {
                tap_code16(C(KC_LEFT));
            } else if (record->event.pressed) {
                tap_code16(KC_HOME);
            }
            return false;
        case M_END:
            if (record->tap.count && record->event.pressed) {
                tap_code16(C(KC_RGHT));
            } else if (record->event.pressed) {
                tap_code16(KC_END);
            }
            return false;

        case VIM_CPY:
            if (record->event.pressed) {
                SEND_STRING("\"" SS_DELAY(100) "+" SS_DELAY(100) "Y");
            }
            break;
        case LTX_BEGIN:
            if (record->event.pressed) {
                SEND_STRING("\\begin{}" SS_TAP(X_LEFT));
            }
            break;
        case LTX_REF:
            if (record->event.pressed) {
                SEND_STRING("(\\ref{})" SS_TAP(X_LEFT) SS_TAP(X_LEFT));
            }
            break;
        case LTX_SEC:
            if (record->event.pressed) {
                SEND_STRING("\\section{}" SS_TAP(X_LEFT));
            }
            break;
        case LTX_LABEL:
            if (record->event.pressed) {
                SEND_STRING("\\label{}" SS_TAP(X_LEFT));
            }
            break;

        case QMK_KEY:
            if (record->event.pressed) {
                SEND_STRING("qmk flash -kb crkbd/rev1 -km kotbaton");
            }
            break;

        case NAME:
            if (record->event.pressed) {
                SEND_STRING("Your name");
            }
            break;

        case TEL:
            if (record->event.pressed) {
                SEND_STRING("Your phone");
            }
            break;

        case EMAIL:
            if (record->event.pressed) {
                SEND_STRING("Your email");
            }
            break;
    }
    return true;
}
#endif // OLED_ENABLE

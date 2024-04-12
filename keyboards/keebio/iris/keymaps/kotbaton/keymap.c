#include QMK_KEYBOARD_H

// Layer defines
#define _QWERTY   0
#define _S_QWERTY 1
#define _LOWER    2
#define _RAISE    3
#define _ADJUST   4
#define _MEDIA    5

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  VIM_CPY,
  LTX_BEGIN,
  LTX_REF,
  LTX_LABEL,
  LTX_SEC,
};

// Left-hand home row mods
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

#define M_HOME LT(_RAISE, KC_HOME)
#define M_END LT(_RAISE, KC_END)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
  //┌──────────────┬───────┬────────┬────────┬────────┬────────┐                    ┌────────┬────────┬────────┬──────────┬───────────┬────────────────┐
     KC_GRV,        KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,      KC_0,       KC_BSPC,
  //├──────────────┼───────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼──────────┼───────────┼────────────────┤
  LT(_MEDIA, KC_TAB),KC_Q,  KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,      KC_P,       KC_BSPC,
  //├──────────────┼───────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼──────────┼───────────┼────────────────┤
     SFT_T(KC_ESC), HOME_A, HOME_S,  HOME_D,  HOME_F,  KC_G,                         KC_H,    HOME_J,  HOME_K,  HOME_L,    HOME_SCLN,  RSFT_T(KC_QUOT),
  //├──────────────┼───────┼────────┼────────┼────────┼────────┼────────┐  ┌────────┼────────┼────────┼────────┼──────────┼───────────┼────────────────┤
     KC_LCTL,       KC_Z,   CUT_X,   CPY_C,   PST_V,   KC_B,    KC_HOME,    KC_END,  KC_N,    KC_M,    KC_COMM, KC_DOT,    KC_SLSH,    RCTL_T(KC_ENT),
  //└──────────────┴───────┴────────┼────────┴───┬────┴───┬────┴───┬────┘  └───┬────┴────────┴┬───────┼────────┴┬─────────┴───────────┴────────────────┘
                                      KC_LGUI,     LOWER,   KC_SPC,              KC_ENT,        RAISE,   KC_RALT
                                 // └────────────┴────────┴────────┘           └──────────────┴───────┴─────────┘
  ),

  [_S_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  DF(_QWERTY),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
SFT_T(KC_ESC),KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_HOME,          KC_END,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI,  LOWER,   KC_SPC,                    KC_ENT,  RAISE,   KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_F11,  HL_F1,   HL_F2,   HL_F3,   HL_F4,   KC_F5,                              KC_EQL, HL_MINS, HL_LBRC, HL_RBRC, HL_BSLS, KC_PRINT_SCREEN,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,          _______, KC_PLUS, KC_UNDS, KC_LCBR, KC_RCBR, KC_PIPE, KC_DEL,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                    KC_SPC, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, LTX_SEC, _______, _______, LTX_REF,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_UNDS, KC_EQL,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, VIM_CPY,LTX_LABEL,LTX_BEGIN,_______,         _______, KC_PGUP, KC_PGDN,  M_HOME, M_END,   KC_PIPE, KC_DEL,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LALT, _______, _______,                   _______, _______, KC_LALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_BOOT, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______,DF(_QWERTY),_______,_______,_______, _______,                            _______, _______, RGB_SAD, RGB_SAI, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, DF(_S_QWERTY),                      _______, RGB_TOG, RGB_VAD, RGB_VAI, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, RGB_MOD, RGB_HUD, RGB_HUI, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_MEDIA] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______,KC_KB_MUTE,KC_KB_VOLUME_DOWN,KC_KB_VOLUME_UP,_______,_______,           _______,_______,_______,_______,KC_PRINT_SCREEN,_______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
            break;

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
    }
    return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return false;
}

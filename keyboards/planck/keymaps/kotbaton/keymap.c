/* Copyright 2015-2021 Jack Humbert
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
#include "muse.h"

enum planck_layers {
    _QWERTY,
    _S_QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _MEDIA,
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  VIM_CPY,
  LTX_BEGIN,
  LTX_REF,
  LTX_LABEL,
  LTX_SEC,
  NAME,
  EMAIL,
  QMK_KEY
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

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
[_QWERTY] = LAYOUT_planck_grid(
  LT(_MEDIA, KC_TAB),KC_Q,  KC_W,    KC_E,    KC_R,    KC_T,  KC_Y,    KC_U,    KC_I,    KC_O,      KC_P,       KC_BSPC,
     SFT_T(KC_ESC), HOME_A, HOME_S,  HOME_D,  HOME_F,  KC_G,  KC_H,    HOME_J,  HOME_K,  HOME_L,    HOME_SCLN,  RSFT_T(KC_QUOT),
     KC_LCTL,       KC_Z,   CUT_X,   CPY_C,   PST_V,   KC_B,  KC_N,    KC_M,    KC_COMM, KC_DOT,    KC_SLSH,    RCTL_T(KC_ENT),
     KC_LCTL,       KC_NO,  KC_LALT, LM(_LOWER, MOD_LGUI), LOWER,   KC_SPC, KC_SPC, RAISE,   KC_RALT, KC_LEFT,    KC_RGHT,   KC_ENT
),

[_S_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    KC_LCTL, KC_NO,   KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

[_LOWER] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_F11,  HL_F1,   HL_F2,   HL_F3,   HL_F4,   KC_F5,   KC_EQL, HL_MINS, HL_LBRC, HL_RBRC, HL_BSLS, KC_PRINT_SCREEN,
    KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_PLUS,KC_UNDS, KC_LCBR, KC_RCBR, KC_PIPE, KC_DEL,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_RAISE] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
    _______, NAME,    LTX_SEC, _______, _______, LTX_REF,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_UNDS, KC_EQL,
    _______, EMAIL,   _______, VIM_CPY,LTX_LABEL,LTX_BEGIN, KC_PGUP, KC_PGDN, M_HOME,  M_END,  KC_PIPE, KC_DEL,
    _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______
),

[_ADJUST] = LAYOUT_planck_grid(
    QK_BOOT, DF(_QWERTY), _______, MI_ON,   MI_OFF,  _______,       _______, _______, RGB_SAD, RGB_SAI, _______, QMK_KEY,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  DF(_S_QWERTY), _______, RGB_TOG, RGB_VAD, RGB_VAI, _______, _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  _______,       _______, RGB_MOD, RGB_HUD, RGB_HUI, _______, _______,
    _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______
),

[_MEDIA] = LAYOUT_planck_grid(
    _______, KC_KB_MUTE, KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP, _______, _______,       _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______
),

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
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

        case QMK_KEY:
            if (record->event.pressed) {
                SEND_STRING("qmk flash -kb planck/ez/glow -km kotbaton");
            }
            break;

        case NAME:
            if (record->event.pressed) {
                SEND_STRING("Andrii Shekhovtsov");
            }
            break;

        case EMAIL:
            if (record->event.pressed) {
                SEND_STRING("andrii-shekhovtsov@zut.edu.pl");
            }
            break;
    }
    return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}

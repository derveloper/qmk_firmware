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

enum preonic_keycodes {
    TMUXVSPLIT = SAFE_RANGE,
    TMUXHSPLIT,
    TMUXBROADCAST,
};

enum preonic_layers {
    _LAYER0,
    _LAYER1,
    _LAYER2,
    _LAYER3,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_LAYER0] = LAYOUT_preonic_grid(
        KC_ESC,         KC_1,         KC_2,         KC_3,    KC_4,             KC_5,   KC_6,   KC_7,         KC_8,         KC_9,         KC_0,            KC_BSPC,
        KC_DEL,         KC_Q,         KC_W,         KC_E,    KC_R,             KC_T,   KC_Y,   KC_U,         KC_I,         KC_O,         KC_P,            KC_DEL,
        KC_TAB,         LALT_T(KC_A), LSFT_T(KC_S), KC_D,    LT(_LAYER2,KC_F), KC_G,   KC_H,   LCTL_T(KC_J), RALT_T(KC_K), RSFT_T(KC_L), LALT_T(KC_SCLN), KC_QUOT,
        KC_LSFT,        KC_Z,         KC_X,         KC_C,    KC_V,             KC_B,   KC_N,   KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,         KC_ENT,
        LCTL_T(KC_GRV), KC_ENT,       KC_LALT,      KC_LGUI, MO(_LAYER1),      KC_SPC, KC_SPC, KC_ENT,       KC_BSPC,      MO(_LAYER3),  KC_RGUI,         MO(_LAYER1)
        ),

    [_LAYER1] = LAYOUT_preonic_grid(
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,  KC_F9, KC_F10,  KC_F11,
        KC_TRNS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_UP,   KC_7,    KC_8,   KC_9,  KC_ASTR, KC_F12
        KC_TRNS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_MINS, KC_DOWN, KC_4,    KC_5,   KC_6,  KC_PPLS, KC_RCTL,
        KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_AMPR, KC_1,    KC_2,   KC_3,  KC_BSLS, KC_RSFT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LALT, KC_DOT, KC_0,  KC_EQL,  KC_TRNS
        ),

    [_LAYER2] = LAYOUT_preonic_grid(
        KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOT,
        KC_TRNS, KC_TRNS, CAPS_WORD, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_TRNS, KC_TRNS,
        KC_LALT, KC_LCTL, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        ),

    [_LAYER3] = LAYOUT_preonic_grid(
        KC_SLEP, KC_WAKE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,       BL_TOGG, BL_STEP, BL_BRTG, KC_MUTE,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, SGUI(KC_PSCR), TMUXBROADCAST, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLU,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TMUXVSPLIT,    TMUXHSPLIT,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case TMUXVSPLIT:
          if (record->event.pressed) {
              SEND_STRING(SS_LCTL("b"));
              SEND_STRING("-");
          }
          break;
        case TMUXHSPLIT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b"));
                SEND_STRING("_");
            }
            break;
        case TMUXBROADCAST:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b"));
                SEND_STRING(SS_LSFT("e"));
            }
            break;
      }
    return true;
};

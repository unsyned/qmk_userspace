/*
Copyright 2024 aki27

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
#include "keymap_introspection.h"
#include "unsyned.h"
#include "tap_dances.h"
#include "overrides.h"
#include "combos.h"

#ifdef CHORDAL_HOLD
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
        'L', 'L', 'L', 'L', 'L',        'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L',  '*',  'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L',        'R', 'R', 'R', 'R', 'R',
                  'L', '*', '*',  '*',  '*', '*', 'R'
    );
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC] = LAYOUT(
        KC_W, KC_L, KC_Y, KC_P, KC_B, KC_Z, KC_F, KC_O, KC_U, KC_QUOT,
        LCTL_T(KC_C), LALT_T(KC_R), LGUI_T(KC_S), LSFT_T(KC_T), KC_G, MS_LEFT, KC_M, RSFT_T(KC_N), RGUI_T(KC_E), RALT_T(KC_I), RCTL_T(KC_A),
        KC_Q, TD(J_MAC_CUT), TD(V_MAC_COPY), TD(D_MAC_PASTE), KC_K, KC_X, KC_H, KC_SLSH, KC_COMM, KC_DOT,
                          SCRL_MO, KC_ENT, LT(SYM, KC_SPC),  MS_MID, LT(NAV, KC_BSPC),  TD(TD_SHIFT_CW), TT(MSE)
    ),
    [LIN] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______,
        _______, TD(J_MAC_CUT), TD(V_MAC_COPY), TD(D_MAC_PASTE), _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______, _______, _______
    ),
    [SYM] = LAYOUT(
        KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_TILDE, KC_GRV,
        LCTL_T(KC_LABK), LALT_T(KC_LBRC), LGUI_T(KC_LCBR), LSFT_T(KC_LPRN), KC_BSLS, _______, KC_PIPE, KC_RPRN, KC_RCBR, KC_RBRC, KC_RABK,
        _______, KC_COLN, KC_SCLN, _______, KC_GRV, KC_UNDS, KC_MINUS, KC_PLUS, KC_EQL, KC_QUES,
                          _______, _______, _______, _______, KC_ESC, _______, _______
    ),
    [NAV] = LAYOUT(
        KC_MINUS,    KC_7,    KC_8,    KC_9,    KC_COMM,             KC_INS,    KC_HOME,    KC_UP,    KC_END,    KC_PGUP,
        LCTL_T(KC_0),   LALT_T(KC_1),   LGUI_T(KC_2),   LSFT_T(KC_3),   LSFT(KC_SCLN),   _______,  KC_DEL,  RSFT_T(KC_LEFT),   RGUI_T(KC_DOWN),  RALT_T(KC_RIGHT), RCTL_T(KC_PGDN),
        LSFT(KC_EQL),   KC_4,   KC_5,   KC_6,   KC_DOT,           KC_LEFT, KC_VOLD, TD(PLAY_MUTE), KC_VOLU,  KC_SLSH,
                          _______, KC_TAB, KC_ENT, _______, _______, _______, _______
    ),
    [FUN] = LAYOUT(
        KC_F12, KC_F7, KC_F8, KC_F9, QK_BOOT,          QK_BOOT, PDF(MAC), PDF(LIN), ROT_R15, ROT_L15,
        KC_F11, KC_F4, KC_F5, KC_F6, _______, _______, RM_TOGG, SCRL_TO, SCRL_IN, SCRL_SW, CPI_SW,
        KC_F10, KC_F1, KC_F2, KC_F3, QK_REBOOT,          QK_REBOOT, _______, SCRL_MO, ROT_R15, ROT_L15,
                          _______, _______, _______, _______, _______,  _______, _______
    ),
    // not sure where is most comfortable to place forward/backward buttons
    [MSE] = LAYOUT(
        OS_LALT, MS_FOR, MS_MID, MS_BACK, OS_LSFT,          MS_RIGHT, MS_FOR, _______, _______, AM_TOG,
        OS_LCTL, MS_RIGHT, SCRL_MO, MS_LEFT, OS_LGUI, _______, SCRL_MO, MS_MID, _______, _______, _______,
        _______, _______, _______, _______, _______,          MS_LEFT, MS_BACK, _______, _______, _______,
                          _______, _______, _______, _______, _______, _______, _______
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC] =   { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [LIN] =   { ENCODER_CCW_CW(_______, _______) },
    [SYM] =   { ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
    [NAV] =   { ENCODER_CCW_CW(_______, _______) },
    [FUN] =   { ENCODER_CCW_CW(_______, _______) },
    [MSE] =   { ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
};
#endif


bool is_mouse_record_kb(uint16_t keycode, keyrecord_t* record) {
    switch(keycode) {
      case KC_LCTL:
        return true;
      case KC_LSFT:
        return true;
      case SCRL_MO:
        return true;
      default:
        return false;
    }
    return is_mouse_record_user(keycode, record);
}



#ifdef RGB_MATRIX_ENABLE

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    int is_layer = get_highest_layer(layer_state|default_layer_state);
    HSV hsv = {0, 255, rgblight_get_val()};
    if (is_layer == 1) {
      hsv.h = 11; //CORAL
    } else if (is_layer == 2)  {
      hsv.h = 85; //GREEN
    } else if (is_layer == 3)  {
      hsv.h = 43; //YELLOW
    } else if (is_layer == 4)  {
      hsv.h = 0; //RED
    } else if (is_layer == 5)  {
      hsv.h = 191; //PURPLE
    } else if (is_layer == 6)  {
      hsv.h = 64; //CHARTREUSE
    } else if (is_layer == 7)  {
      hsv.h = 224;
    } else {
      hsv.h = 128; //CYAN
    }
    RGB rgb = hsv_to_rgb(hsv);

    for (uint8_t i = led_min; i <= led_max; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], 0x02)) {
          rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
    }
    return false;
};

#endif


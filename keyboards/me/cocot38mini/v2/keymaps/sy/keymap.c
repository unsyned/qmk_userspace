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

#define MS_LEFT MS_BTN1
#define MS_RIGHT MS_BTN2
#define MS_MID MS_BTN3
#define MS_FOR MS_BTN4
#define MS_BACK MS_BTN5


enum {
    TD_SHIFT_CW,
    J_MAC_CUT,
    V_MAC_COPY,
    D_MAC_PASTE,
    J_LIN_CUT,
    V_LIN_COPY,
    D_LIN_PASTE,
    PLAY_MUTE
};


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


typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold)                                        \
    {                                                                               \
        .fn        = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, \
        .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}),               \
    }

void td_shift_cw_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (state->pressed) {
          register_code(KC_RSFT); // hold
        }
        else {
          set_oneshot_mods(MOD_BIT(KC_RSFT)); // tap
        }
    }
    else if (state->count == 2) {
        // TODO: see if I can get this to turn back off on reactivation
        caps_word_toggle();
    }
}

void td_shift_cw_reset(tap_dance_state_t *state, void *user_data) {
    unregister_code(KC_RSFT);
}

tap_dance_action_t tap_dance_actions[] = {
    // [TD_COPY] = ACTION_TAP_DANCE_TAP_HOLD(KC_V, LGUI(KC_C)),
    // [TD_SHIFT_CW] = ACTION_TAP_DANCE_DOUBLE(OS_RSFT, CW_TOGG),
    [TD_SHIFT_CW] = ACTION_TAP_DANCE_FN_ADVANCED(
        NULL,
        td_shift_cw_finished,
        td_shift_cw_reset
    ),
    [J_MAC_CUT] = ACTION_TAP_DANCE_TAP_HOLD(KC_J, LGUI(KC_X)),
    [V_MAC_COPY] = ACTION_TAP_DANCE_TAP_HOLD(KC_V, LGUI(KC_C)),
    [D_MAC_PASTE] = ACTION_TAP_DANCE_TAP_HOLD(KC_D, LGUI(KC_V)),

    [J_LIN_CUT] = ACTION_TAP_DANCE_TAP_HOLD(KC_J, LCTL(KC_X)),
    [V_LIN_COPY] = ACTION_TAP_DANCE_TAP_HOLD(KC_V, LCTL(KC_C)),
    [D_LIN_PASTE] = ACTION_TAP_DANCE_TAP_HOLD(KC_D, LCTL(KC_V)),
    [PLAY_MUTE] = ACTION_TAP_DANCE_TAP_HOLD(KC_MPLY, KC_MUTE),
    // [TD_CUT] = ACTION_TAP_DANCE_FN_ADVANCED(
    //         NULL,
    //         td_c_finished,
    //         td_c_reset
    //         ),
    // [TD_COPY] = ACTION_TAP_DANCE_FN_ADVANCED(
    //     NULL,
    //     td_copy_finished,
    //     td_copy_reset
    // ),
    // [TD_PASTE] = ACTION_TAP_DANCE_FN_ADVANCED(
    //     NULL,
    //     td_paste_finished,
    //     td_paste_reset
    // ),
};

const key_override_t lcomma_override = ko_make_basic(MOD_BIT(KC_LSFT), KC_COMM, KC_SCLN);
const key_override_t rcomma_override = ko_make_basic(MOD_BIT(KC_RSFT), KC_COMM, KC_SCLN);

const key_override_t ldot_override = ko_make_basic(MOD_BIT(KC_LSFT), KC_DOT, KC_COLN);
const key_override_t rdot_override = ko_make_basic(MOD_BIT(KC_RSFT), KC_DOT, KC_COLN);

const key_override_t *key_overrides[] = {
    &lcomma_override,
    &rcomma_override,
    &ldot_override,
    &rdot_override,
};

const uint16_t PROGMEM osl_fun_combo[] = {KC_L, KC_Y, KC_P, COMBO_END};
const uint16_t PROGMEM caps_combo[] = {KC_F, KC_O, KC_U, COMBO_END};

combo_t key_combos[] = {
    COMBO(osl_fun_combo, OSL(FUN)),
    COMBO(caps_combo, KC_CAPS),
};

bool is_flow_tap_key(uint16_t keycode) {
    if ((get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) {
        return false; // Disable Flow Tap on hotkeys.
    }
    switch (get_tap_keycode(keycode)) {
        // case KC_SPC:
        // case KC_BSPC:
        case KC_A ... KC_Z:
        case KC_DOT:
        case KC_COMM:
        case KC_SCLN:
        case KC_SLSH:
        case TD(J_MAC_CUT):
        case TD(V_MAC_COPY):
        case TD(D_MAC_PASTE):
        case TD(J_LIN_CUT):
        case TD(V_LIN_COPY):
        case TD(D_LIN_PASTE):
            return true;
    }
    return false;
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case TD(J_MAC_CUT):
        case TD(V_MAC_COPY):
        case TD(D_MAC_PASTE):
        case TD(J_LIN_CUT):
        case TD(V_LIN_COPY):
        case TD(D_LIN_PASTE):
        // case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

// qmk will bit mask away the shift from the mod tap on the sym layer. so we intercept the mod tap instead and send the appropriate character
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    tap_dance_action_t *action;
    tap_dance_state_t* state;

    switch (keycode) {
        case TD(J_MAC_CUT):
        case TD(V_MAC_COPY):
        case TD(D_MAC_PASTE):
        case TD(J_LIN_CUT):
        case TD(V_LIN_COPY):
        case TD(D_LIN_PASTE):
        case TD(PLAY_MUTE):
            action = tap_dance_get(QK_TAP_DANCE_GET_INDEX(keycode));
            state = tap_dance_get_state(QK_TAP_DANCE_GET_INDEX(keycode));
            if (!record->event.pressed && state != NULL && state->count && !state->finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            break;
        // symbol layer overrides
        case LCTL_T(KC_LABK):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LABK);
                return false;        // Return false to ignore further processing of key
            }
            break;
        case LALT_T(KC_LBRC):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LBRC);
                return false;        // Return false to ignore further processing of key
            }
            break;
        case LGUI_T(KC_LCBR):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LCBR);
                return false;        // Return false to ignore further processing of key
            }
            break;
        case LSFT_T(KC_LPRN):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LPRN);
                return false;        // Return false to ignore further processing of key
            }
            break;
        case RSFT_T(KC_RPRN):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_RPRN);
                return false;        // Return false to ignore further processing of key
            }
            break;
        case RGUI_T(KC_RCBR):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_RCBR);
                return false;        // Return false to ignore further processing of key
            }
            break;
        case RALT_T(KC_RBRC):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_RBRC);
                return false;        // Return false to ignore further processing of key
            }
            break;
        case RCTL_T(KC_RABK):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_RABK);
                return false;        // Return false to ignore further processing of key
            }
            break;
        // nav layer overrides
        case LCTL_T(KC_0):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_0);
                return false;        // Return false to ignore further processing of key
            }
            break;
        case LALT_T(KC_1):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_1);
                return false;        // Return false to ignore further processing of key
            }
            break;
        case LGUI_T(KC_2):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_2);
                return false;        // Return false to ignore further processing of key
            }
            break;
        case LSFT_T(KC_3):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_3);
                return false;        // Return false to ignore further processing of key
            }
            break;
        case RSFT_T(KC_LEFT):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LEFT);
                return false;        // Return false to ignore further processing of key
            }
            break;
        case RGUI_T(KC_DOWN):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_DOWN);
                return false;        // Return false to ignore further processing of key
            }
            break;
        case RALT_T(KC_RIGHT):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_RIGHT);
                return false;        // Return false to ignore further processing of key
            }
            break;
        case RCTL_T(KC_PGDN):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_PGDN);
                return false;        // Return false to ignore further processing of key
            }
            break;
    }
    return true;
}

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


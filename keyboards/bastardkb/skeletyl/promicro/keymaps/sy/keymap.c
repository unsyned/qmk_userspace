#include <stdint.h>
#include "sys/types.h"
#include QMK_KEYBOARD_H
// supposedly, this
// includes quantum.h
// includes the keyboard’s keyboard.h
// defines all LAYOUT_* macros
// defines _______, custom keycodes, features, etc.
#include "sy.h"

enum {
    TD_SHIFT_CW,
};

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_SINGLE_TAP
} td_state_t;

// global tapdance state instance
static td_state_t td_state;

// const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
//     LAYOUT_split_3x5_3(
//         'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
//         'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
//         'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
//                   '*', '*', '*',  '*', '*', '*'
//     );

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // canary
    [0] = LAYOUT_sy_3x5(___5COL_BASE_LEFT_ROW1___, ___5COL_BASE_RIGHT_ROW1___,
                            ___5COL_BASE_LEFT_ROW2___, ___5COL_BASE_RIGHT_ROW2___,
                            ___5COL_BASE_LEFT_ROW3___, ___5COL_BASE_RIGHT_ROW3___,
                            // LT(1, KC_BSPC), OS_LSFT, KC_ESC, _______, KC_ENT, LT(2, KC_SPC)
                            LT(1, KC_BSPC), TD(TD_SHIFT_CW), KC_ESC, _______, KC_ENT, LT(2, KC_SPC)
                            // KC_BSPC, MO(1), KC_ESC, KC_ENT, MO(2), KC_SPC // for if we want to separate the layer and tap again
                            ),
    // // qwerty
    // [1] = LAYOUT_split_3x5_3(KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,
    //                         LCTL_T(KC_A), LALT_T(KC_S), LGUI_T(KC_D), LSFT_T(KC_F), KC_G, KC_H, RSFT_T(KC_J), RGUI_T(KC_K), RALT_T(KC_L), RCTL_T(KC_SCLN),
    //                         KC_Z, KC_X, KC_C, KC_V, KC_B, KC_M, KC_N, KC_COMM, KC_DOT, KC_SLSH,
    //                         KC_ESC, MO(3), KC_BSPC, KC_SPC, MO(4), KC_ENT
    //                         ),
    // symbol
    [1] = LAYOUT_split_3x5_3(KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_TILDE, KC_GRV,
                            LCTL_T(KC_LABK), LALT_T(KC_LBRC), LGUI_T(KC_LCBR), LSFT_T(KC_LPRN), KC_BSLS, KC_PIPE, KC_RPRN, KC_RCBR, KC_RBRC, KC_RABK,
                            _______, KC_COLN, KC_SCLN, _______, KC_GRV, KC_UNDS, KC_MINUS, KC_PLUS, KC_EQL, KC_QUES,
                            _______, _______, _______, _______, KC_TAB, KC_ESC),
    // nav
    [2] = LAYOUT_split_3x5_3(KC_MINUS, KC_7, KC_8, KC_9, KC_COMM, KC_PGUP, KC_HOME, KC_UP, KC_END, KC_INS,
                            LCTL_T(KC_0), LALT_T(KC_1), LGUI_T(KC_2), LSFT_T(KC_3), KC_COLN, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,
                            KC_PLUS, KC_4, KC_5, KC_6, KC_DOT, KC_PSCR, CW_TOGG, KC_CAPS, KC_RSFT, OSL(3),
                            KC_ENT, KC_TAB, _______, _______, _______, _______),
    // fn
    // TODO: add toggle gaming layer and qwerty
    [3] = LAYOUT_split_3x5_3(KC_F12,KC_F7,KC_F8,KC_F9,_______,_______,_______,_______,_______,_______,
                            KC_F11,KC_F4,KC_F5,KC_F6,_______,_______,_______,_______,_______,_______,
                            KC_F10,KC_F1,KC_F2,KC_F3,_______,_______,_______,_______,_______,_______,
                            _______,_______,_______,_______,_______,_______)
};


td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }

    if (state->count == 2) return TD_DOUBLE_SINGLE_TAP;
    else return TD_UNKNOWN;
}

void td_shift_cw_finished(tap_dance_state_t *state, void *user_data) {
    // if (state->count == 1) {
    //     set_oneshot_mods(MOD_BIT(KC_LSFT));
    // } else if (state->count == 2) {
    //     // TODO: see if I can get this to turn back off on tapping 3 times
    //     caps_word_toggle();
    // }

    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            set_oneshot_mods(MOD_BIT(KC_RSFT));
            break;
        case TD_SINGLE_HOLD:
            register_mods(MOD_BIT(KC_RSFT));
            break;
        case TD_DOUBLE_SINGLE_TAP:
            caps_word_toggle();
            break;
        default:
            break;
    }
}

void td_shift_cw_reset(tap_dance_state_t *state, void *user_data) {
    // nothing to unregister
    switch (td_state) {
        // cases for SINGLE_TAP and DOUBLE_SINGLE_TAP get reset on their own
        case TD_SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_RSFT));
            break;
        default:
            break;
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_SHIFT_CW] = ACTION_TAP_DANCE_FN_ADVANCED(
        NULL,
        td_shift_cw_finished,
        td_shift_cw_reset
    ),
};


const uint16_t PROGMEM esc_combo[] = {KC_L, KC_Y, COMBO_END};
const uint16_t PROGMEM enter_combo[] = {KC_SLSH, KC_COMM, COMBO_END};

combo_t key_combos[] = {
    COMBO(esc_combo, KC_ESC),
    COMBO(enter_combo, KC_ENT),
};

const key_override_t del_override = ko_make_basic(MOD_MASK_SHIFT, LT(1, KC_BSPC), KC_DEL);
const key_override_t ltab_override = ko_make_basic(MOD_BIT(KC_LSFT), LT(2, KC_SPC), KC_TAB);
// on keyboards that have the layers combined with the space or backspace keys, must disable the override for shift tab functionality
// const key_override_t rtab_override = ko_make_basic(MOD_BIT(KC_RSFT), LT(2, KC_SPC), KC_TAB);
// const key_override_t tab_override = {.replacement      = KC_TAB,
//                                     .trigger           = KC_SPACE,
//                                     .trigger_mods      = MOD_BIT(KC_LSFT),
//                                     .suppressed_mods    = MOD_BIT(KC_LSFT),
//                                     .options           = ko_option_no_unregister_on_other_key_down,
//                                     .enabled           = NULL};

const key_override_t lcomma_override = ko_make_basic(MOD_BIT(KC_LSFT), KC_COMM, KC_SCLN);
const key_override_t rcomma_override = ko_make_basic(MOD_BIT(KC_RSFT), KC_COMM, KC_SCLN);

const key_override_t ldot_override = ko_make_basic(MOD_BIT(KC_LSFT), KC_DOT, KC_COLN);
const key_override_t rdot_override = ko_make_basic(MOD_BIT(KC_RSFT), KC_DOT, KC_COLN);

const key_override_t *key_overrides[] = {
    &del_override,
    &ltab_override,
    &lcomma_override,
    &rcomma_override,
    &ldot_override,
    &rdot_override,
};

bool is_flow_tap_key(uint16_t keycode) {
    if ((get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) {
        return false; // Disable Flow Tap on hotkeys.
    }
    switch (get_tap_keycode(keycode)) {
        // removing backspace and space as flow tap continue/enable keys because they are lt/mt keys
        // case KC_SPC:
        // case KC_BSPC:
        case KC_A ... KC_Z:
        case KC_DOT:
        case KC_COMM:
        case KC_SCLN:
        case KC_SLSH:
            return true;
    }
    return false;
}

bool caps_word_press_user(uint16_t keycode) {
    // TODO: change this so that it is in it's own function
    // that can be called by boards with a symbol layer
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        // removing minus from shifted list since we have it on its own key
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // below is to allow me to backspace when I mess up the one shot shift instead of deleting
        // for non layer tap keys, use KC_BSPC
        // case KC_BSPC:
        case LT(1, KC_BSPC):
            if (record->tap.count == 1 && record->event.pressed && get_oneshot_mods()) { // if this is > 0, it is a tap, not a hold. then, if this is a key down, not release
                // if one shot mod is active, ignore the backspace

                clear_oneshot_mods();
                tap_code(KC_BSPC);
                // NOTE: for a passthrough, uncomment the following line
                // set_oneshot_mods(MOD_BIT(KC_LSFT));

                return false;        // Return false to ignore further processing of key
            }
            break;


        // TODO: move the separate features into their own functions
        // qmk will bit mask away the shift from the mod tap on the sym layer. so we intercept the mod tap instead and send the appropriate character
        case LCTL_T(KC_LABK):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LABK);
                return false;        // Return false to ignore further processing of key
            }
            break;
        case RCTL_T(KC_RABK):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_RABK);
                return false;        // Return false to ignore further processing of key
            }
            break;
        case LALT_T(KC_LBRC):
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_LBRC);   // should fit in 8bits
                return false;        // Return false to ignore further processing of key
            }
            break;
        case RALT_T(KC_RBRC):
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_RBRC);   // should fit in 8bits
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
        case LGUI_T(KC_LCBR):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LCBR);
                return false;        // Return false to ignore further processing of key
            }
            break;
        case RGUI_T(KC_RCBR):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_RCBR);
                return false;        // Return false to ignore further processing of key
            }
            break;
    }
    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            return TAP_DANCE_TERM;
        default:
            return TAPPING_TERM;
    }
}


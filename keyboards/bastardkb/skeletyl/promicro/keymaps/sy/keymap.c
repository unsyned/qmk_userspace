#include QMK_KEYBOARD_H
// supposedly, this
// includes quantum.h
// includes the keyboard’s keyboard.h
// defines all LAYOUT_* macros
// defines _______, custom keycodes, features, etc.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // colemak
    [0] = LAYOUT_split_3x5_3(KC_J, KC_L, KC_Y, KC_P, KC_K, KC_Z, KC_F, KC_O, KC_U, KC_QUOT,
                            LCTL_T(KC_C), LALT_T(KC_R), LGUI_T(KC_S), LSFT_T(KC_T), KC_G, KC_M, RSFT_T(KC_N), RGUI_T(KC_E), RALT_T(KC_I), RCTL_T(KC_A),
                            KC_W, KC_Q, KC_V, KC_D, KC_B, KC_X, KC_H, KC_SLSH, KC_COMM, KC_DOT,
                            LT(1, KC_BSPC), KC_ESC, _______, _______, KC_ENT, LT(2, KC_SPC)
                            // KC_BSPC, MO(1), KC_ESC, KC_ENT, MO(2), KC_SPC // for if we want to separate the layer and tap again
                            ),
    // // qwerty
    // [1] = LAYOUT_split_3x5_3(KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,
    //                         LCTL_T(KC_A), LALT_T(KC_S), LGUI_T(KC_D), LSFT_T(KC_F), KC_G, KC_H, RSFT_T(KC_J), RGUI_T(KC_K), RALT_T(KC_L), RCTL_T(KC_SCLN),
    //                         KC_Z, KC_X, KC_C, KC_V, KC_B, KC_M, KC_N, KC_COMM, KC_DOT, KC_SLSH,
    //                         KC_ESC, MO(3), KC_BSPC, KC_SPC, MO(4), KC_ENT
    //                         ),
    // gaming
    // TODO: add gaming num layer
    // [2] = LAYOUT_split_3x5_3(KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
    //                         LCTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
    //                         KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_M, KC_N, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_ENT),
    //                         KC_RALT, MO(3), KC_SPC, KC_SPC, MO(4), KC_LGUI
    //                         ),
    // symbol
    [1] = LAYOUT_split_3x5_3(KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_TILDE, KC_GRV,
                            LCTL_T(KC_LABK), LALT_T(KC_LBRC), LGUI_T(KC_LCBR), LSFT_T(KC_LPRN), KC_BSLS, KC_PIPE, KC_RPRN, KC_RCBR, KC_RBRC, KC_RABK,
                            KC_BSLS, KC_TILDE, KC_GRV, KC_COLN, KC_SCLN, KC_UNDS, KC_MINUS, KC_PLUS, KC_EQL, KC_QUES,
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
    // [_GAMING] = LAYOUT_split_3x6_3(),
    // [_SYMBOL] = LAYOUT_split_3x6_3(),
    // [_NAVIGATION] = LAYOUT_split_3x6_3(),
    // [_FN] = LAYOUT_split_3x6_3()
};


const uint16_t PROGMEM esc_combo[] = {KC_J, KC_L, COMBO_END};
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
        // flow tap enabled for all alphas excepting colemak homing tn
        case KC_SPC:
        case KC_BSPC:
        case KC_A ... KC_M:
        case KC_O ... KC_S:
        case KC_U ... KC_Z:
        case KC_DOT:
        case KC_COMM:
        case KC_SCLN:
        case KC_SLSH:
            return true;
    }
    return false;
}

// qmk will bit mask away the shift from the mod tap on the sym layer. so we intercept the mod tap instead and send the appropriate character
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
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
    }
    return true;
}


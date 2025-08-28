#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // colemak
    [0] = LAYOUT(KC_J, KC_L, KC_Y, KC_P, KC_K, KC_TAB, KC_Z, KC_F, KC_O, KC_U, KC_QUOT,
                            LCTL_T(KC_C), LALT_T(KC_R), LGUI_T(KC_S), LSFT_T(KC_T), KC_G, KC_ENT, KC_M, RSFT_T(KC_N), RGUI_T(KC_E), RALT_T(KC_I), RCTL_T(KC_A),
                            KC_W, KC_Q, KC_V, KC_D, KC_B, KC_LSFT, KC_X, KC_H, KC_SLSH, KC_COMM, KC_DOT,
                            // KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F11, KC_F12
                            _______, KC_ESC, _______, KC_ESC, _______, LT(1, KC_BSPC), _______, LT(2, KC_SPC), KC_ENT, KC_ENT, _______
                            ),
    // qwerty
    // [1] = LAYOUT(KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
    //                         LCTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
    //                         KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_M, KC_N, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_ENT),
    //                         KC_RALT, MO(4), KC_SPC, KC_SPC, MO(3), KC_LGUI
    //                         ),
    // symbol
    [1] = LAYOUT(KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_TILDE, KC_GRV,
                            KC_LABK, KC_LBRC, KC_LCBR, KC_LPRN, KC_BSLS, _______, KC_PIPE, KC_RPRN, KC_RCBR, KC_RBRC, KC_RABK,
                            KC_BSLS, KC_TILDE, KC_GRV, KC_COLN, KC_SCLN, _______, KC_UNDS, KC_MINUS, KC_PLUS, KC_EQL, KC_QUES,
                            _______, _______, _______, _______, _______, _______, _______, KC_ESC, KC_TAB, _______, _______),
    // nav
    [2] = LAYOUT(KC_MINUS, KC_7, KC_8, KC_9, KC_SLSH, _______, KC_PGUP, KC_HOME, KC_UP, KC_END, KC_INS,
                            KC_MINUS, KC_4, KC_5, KC_6, KC_ASTR, _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,
                            KC_PLUS, KC_1, KC_2, KC_3, KC_TAB, _______, KC_PSCR, CW_TOGG, KC_CAPS, KC_RSFT, OSL(4),
                            _______, _______, _______, KC_0, _______, KC_ENT, _______, _______, _______,_______,_______),
    // gaming num - it functions with esdf.
    // [4] = LAYOUT(_______, KC_1, KC_2,_______, KC_3, KC_4,_______,_______,_______,_______,_______,_______,
    //                         _______, KC_6, _______, _______, _______, KC_5,_______,_______,_______,_______,_______,_______,
    //                         _______, _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    //                         _______,_______,_______,_______,_______,_______),
    // fn
    // TODO: add toggle gaming layer and qwerty
    [4] = LAYOUT(_______, KC_F12,KC_F7, KC_F8, KC_F9,_______,_______,_______,_______, _______,_______,
                            _______, KC_F11, KC_F4, KC_F5, KC_F6,_______,_______,_______,_______,_______,_______,
                            _______, KC_F10, KC_F1, KC_F2, KC_F3,_______,QK_BOOT,_______,_______,_______,_______,
                            _______,_______,_______,_______,_______,_______,_______,_______, _______, _______,_______),
    // [_GAMING] = LAYOUT_split_3x6_3(),
    // [_SYMBOL] = LAYOUT_split_3x6_3(),
    // [_NAVIGATION] = LAYOUT_split_3x6_3(),
    // [_FN] = LAYOUT_split_3x6_3()

    // blank layer
    // [] = LAYOUT_split_3x6_3(_______, _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    //                         _______, _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    //                         _______, _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    //                         _______,_______,_______,_______,_______,_______)
    //                         ),
};

// todo: when I'm not being lazy, change this to be only on fletchling layer
// const uint16_t PROGMEM esc_combo[] = {KC_L, KC_Y, COMBO_END};
const uint16_t PROGMEM enter_combo[] = {KC_SLSH, KC_COMMA, COMBO_END};

combo_t key_combos[] = {
//     COMBO(esc_combo, KC_ESC),
    COMBO(enter_combo, KC_ENT),
};

const key_override_t del_override = ko_make_basic(MOD_MASK_SHIFT, LT(1, KC_BSPC), KC_DEL);

const key_override_t ltab_override = ko_make_basic(MOD_BIT(KC_LSFT), LT(2, KC_SPC), KC_TAB);
const key_override_t rtab_override = ko_make_basic(MOD_BIT(KC_RSFT), LT(2, KC_SPC), KC_TAB);

const key_override_t lcomma_override = ko_make_basic(MOD_BIT(KC_LSFT), KC_COMM, KC_SCLN);
const key_override_t rcomma_override = ko_make_basic(MOD_BIT(KC_RSFT), KC_COMM, KC_SCLN);

const key_override_t ldot_override = ko_make_basic(MOD_BIT(KC_LSFT), KC_DOT, KC_COLN);
const key_override_t rdot_override = ko_make_basic(MOD_BIT(KC_RSFT), KC_DOT, KC_COLN);
// const key_override_t tab_override = {.replacement      = KC_TAB,
//                                     .trigger           = KC_SPACE,
//                                     .trigger_mods      = MOD_BIT(KC_LSFT),
//                                     .suppressed_mods    = MOD_BIT(KC_LSFT),
//                                     .options           = ko_option_no_unregister_on_other_key_down,
//                                     .enabled           = NULL};
const key_override_t *key_overrides[] = {
    &del_override,
    &ltab_override,
    &rtab_override,
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

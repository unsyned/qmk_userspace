#include QMK_KEYBOARD_H
#include "unsyned.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ A │ B │ C │ D │ E │ F │ G │ H │ I │ J │ K │ L │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ B │ C │ D │ E │ F │ G │ H │ I │ J │ K │ L │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ B │ C │ D │ E │ F │ G │ H │ I │ J │ K │ L │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ B │ C │ D │ E │ F │ G │ H │ I │ J │ K │ L │
     * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
     */

    [MAC] = LAYOUT(
        _______,KC_W, KC_L, KC_Y, KC_P, KC_B, KC_Z, KC_F, KC_O, KC_U, KC_QUOT,_______,
        _______,LCTL_T(KC_C), LALT_T(KC_R), LGUI_T(KC_S), LSFT_T(KC_T), KC_G, KC_M, RSFT_T(KC_N), RGUI_T(KC_E), RALT_T(KC_I), RCTL_T(KC_A),_______,
        _______,KC_Q, TD(J_MAC_CUT), TD(V_MAC_COPY), TD(D_MAC_PASTE), KC_K, KC_X, KC_H, KC_SLSH, KC_COMM, KC_DOT,_______,
                _______,_______,_______,KC_ENT, LT(SYM, KC_SPC),  LT(NAV, KC_BSPC),  TD(TD_SHIFT_CW),_______,_______,_______
    ),
    [LIN] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______,_______,
        _______,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______,
        _______,_______, TD(J_MAC_CUT), TD(V_MAC_COPY), TD(D_MAC_PASTE), _______, _______, _______, _______, _______, _______,_______,
                          _______,_______,_______,_______,_______,_______,_______,_______,_______,_______
    ),
    [SYM] = LAYOUT(
        _______,KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_TILDE, KC_GRV,_______,
        _______,LCTL_T(KC_LABK), LALT_T(KC_LBRC), LGUI_T(KC_LCBR), LSFT_T(KC_LPRN), KC_BSLS, KC_PIPE, KC_RPRN, KC_RCBR, KC_RBRC, KC_RABK,_______,
        _______,_______, KC_COLN, KC_SCLN, _______, KC_GRV, KC_UNDS, KC_MINUS, KC_PLUS, KC_EQL, KC_QUES,_______,
                          _______,_______,_______,_______,_______,KC_ESC,_______,_______,_______,_______
    ),
    [NAV] = LAYOUT(
        _______,KC_MINUS,    KC_7,    KC_8,    KC_9,    KC_COMM,             KC_INS,    KC_HOME,    KC_UP,    KC_END,    KC_PGUP,_______,
        _______,LCTL_T(KC_0),   LALT_T(KC_1),   LGUI_T(KC_2),   LSFT_T(KC_3),   LSFT(KC_SCLN),   KC_DEL,  RSFT_T(KC_LEFT),   RGUI_T(KC_DOWN),  RALT_T(KC_RIGHT), RCTL_T(KC_PGDN),_______,
        _______,LSFT(KC_EQL),   KC_4,   KC_5,   KC_6,   KC_DOT,           KC_LEFT, KC_VOLD, TD(PLAY_MUTE), KC_VOLU,  KC_SLSH,_______,
                          _______,_______,_______,KC_TAB, KC_ENT,_______,_______,_______,_______,_______
    ),
    [FUN] = LAYOUT(
        _______,KC_F12, KC_F7, KC_F8, KC_F9, QK_BOOT,          QK_BOOT, PDF(MAC), PDF(LIN), _______, _______,_______,
        _______,KC_F11, KC_F4, KC_F5, KC_F6, _______, _______, _______, _______, _______, _______,_______,
        _______,KC_F10, KC_F1, KC_F2, KC_F3, QK_REBOOT,          QK_REBOOT, _______, _______, _______, _______,_______,
                          _______,_______,_______,_______,_______,_______,_______,_______,_______,_______
    )
};

/*
 * #################### Combos ####################
 * */
// combo defs
const uint16_t PROGMEM osl_fun_combo[] = {KC_L, KC_Y, KC_P, COMBO_END};
const uint16_t PROGMEM caps_combo[] = {KC_F, KC_O, KC_U, COMBO_END};

combo_t key_combos[] = {
    COMBO(osl_fun_combo, OSL(FUN)),
    COMBO(caps_combo, KC_CAPS),
};

/*
 * #################### Tap dance defs ####################
 *
*/
void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1 && !state->interrupted
// #ifndef PERMISSIVE_HOLD
            // && !state->interrupted
// #endif
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
};


/*
 * #################### Key overrides ####################
 * */
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


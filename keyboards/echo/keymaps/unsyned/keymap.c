#include QMK_KEYBOARD_H
#include "unsyned.h"
#include "tap_dances.h"
#include "overrides.h"
#include "combos.h"

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
        KC_W, KC_L, KC_Y, KC_P, KC_B, _______, _______, KC_Z, KC_F, KC_O, KC_U, KC_QUOT,
        LCTL_T(KC_C), LALT_T(KC_R), LGUI_T(KC_S), LSFT_T(KC_T), KC_G,_______,_______, KC_M, RSFT_T(KC_N), RGUI_T(KC_E), RALT_T(KC_I), RCTL_T(KC_A),
        KC_Q, TD(J_MAC_CUT), TD(V_MAC_COPY), TD(D_MAC_PASTE), KC_K, _______,_______,KC_X, KC_H, KC_SLSH, KC_COMM, KC_DOT,
                _______,_______,_______,KC_ENT, LT(SYM, KC_SPC),  LT(NAV, KC_BSPC),  TD(TD_SHIFT_CW),_______,_______,_______
    ),
    [LIN] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______,_______,
        _______,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______,
        _______, TD(J_LIN_CUT), TD(V_LIN_COPY), TD(D_LIN_PASTE), _______,_______, _______, _______, _______, _______, _______,_______,
                          _______,_______,_______,_______,_______,_______,_______,_______,_______,_______
    ),
    [SYM] = LAYOUT(
        KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, _______,_______,KC_CIRC, KC_AMPR, KC_ASTR, KC_TILDE, KC_GRV,
        LCTL_T(KC_LABK), LALT_T(KC_LBRC), LGUI_T(KC_LCBR), LSFT_T(KC_LPRN), KC_BSLS, _______,_______,KC_PIPE, KC_RPRN, KC_RCBR, KC_RBRC, KC_RABK,
        _______, KC_COLN, KC_SCLN, _______, KC_GRV, _______,_______,KC_UNDS, KC_MINUS, KC_PLUS, KC_EQL, KC_QUES,
                          _______,_______,_______,_______,_______,KC_ESC,_______,_______,_______,_______
    ),
    [NAV] = LAYOUT(
        KC_MINUS,    KC_7,    KC_8,    KC_9,    KC_COMM, _______, _______,            KC_INS,    KC_HOME,    KC_UP,    KC_END,    KC_PGUP,
        LCTL_T(KC_0),   LALT_T(KC_1),   LGUI_T(KC_2),   LSFT_T(KC_3),   LSFT(KC_SCLN),   _______,_______,KC_DEL,  RSFT_T(KC_LEFT),   RGUI_T(KC_DOWN),  RALT_T(KC_RIGHT), RCTL_T(KC_PGDN),
        LSFT(KC_EQL),   KC_4,   KC_5,   KC_6,   KC_DOT,      _______, _______,     KC_PSCR, KC_VOLD, TD(PLAY_MUTE), KC_VOLU,  KC_SLSH,
                          _______,_______,_______,KC_TAB, KC_ENT,_______,_______,_______,_______,_______
    ),
    [FUN] = LAYOUT(
        KC_F12, KC_F7, KC_F8, KC_F9, QK_BOOT,          _______,_______,QK_BOOT, PDF(MAC), PDF(LIN), _______, _______,
        KC_F11, KC_F4, KC_F5, KC_F6, _______, _______,_______,_______, _______, _______, _______, _______,
        KC_F10, KC_F1, KC_F2, KC_F3, QK_REBOOT,          _______,_______,QK_REBOOT, _______, _______, _______, _______,
                          _______,_______,_______,_______,_______,_______,_______,_______,_______,_______
    )
};


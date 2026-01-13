#include "quantum.h"

/* layers */
enum layers {
    _BASE,
    _GAME,
    _SYM,
    _NAV,
    _FUN,
    _GNUM,
};

/** tap dance **/
enum {
    TD_SHIFT,
};

enum c_keycodes {
    CAPWD_TG,
};

/* HRM aliases */
#define HRM_C LCTL_T(KC_C)
#define HRM_R LALT_T(KC_R)
#define HRM_S LGUI_T(KC_S)
#define HRM_T LSFT_T(KC_T)
#define HRM_N RSFT_T(KC_N)
#define HRM_E RGUI_T(KC_E)
#define HRM_I RALT_T(KC_I)
#define HRM_A RCTL_T(KC_A)


// TODO: note that I can make a macro at the top of the keyboard file and condense __5COL_BASE_LEFT to something like KEYBOARD
/** keymap defs **/
/*** base layer ***/
#define ___5COL_BASE_LEFT_ROW1___   KC_J, KC_L, KC_Y, KC_P, KC_K
#define ___5COL_BASE_LEFT_ROW2___   HRM_C, HRM_R, HRM_S, HRM_T, KC_G
#define ___5COL_BASE_LEFT_ROW3___   KC_W, KC_Q, KC_V, KC_D, KC_B
// TODO: make a verion of this with layer taps separate from layers & spc/bspc
#define ___5COL_BASE_LEFT_TH___      LT(1, KC_BSPC), TD(TD_SHIFT_CW), KC_ESC

#define ___5COL_BASE_RIGHT_ROW1___  KC_Z, KC_F, KC_O, KC_U, KC_QUOT
#define ___5COL_BASE_RIGHT_ROW2___  KC_M, HRM_N, HRM_E, HRM_I, HRM_A
#define ___5COL_BASE_RIGHT_ROW3___  KC_X, KC_H, KC_SLSH, KC_COMM, KC_DOT
// TODO: make a verion of this with layer taps separate from layers & spc/bspc
#define ___5COL_BASE_RIGHT_TH___     _______, KC_ENT, LT(2, KC_SPC)

#define ___6COL_BASE_LEFT_ROW1___   KC_TAB, ___5COL_BASE_LEFT_ROW1___
#define ___6COL_BASE_LEFT_ROW2___   LCTL_T(KC_ESC), ___5COL_BASE_LEFT_ROW2___
#define ___6COL_BASE_LEFT_ROW3___   KC_LSFT, ___5COL_BASE_LEFT_ROW3___
#define ___6COL_BASE_LEFT_TH___     KC_ESC, MO(_SYM), KC_BSPC

#define ___6COL_BASE_RIGHT_ROW1___  ___5COL_BASE_RIGHT_ROW1___, KC_BSPC
#define ___6COL_BASE_RIGHT_ROW2___  ___5COL_BASE_RIGHT_ROW2___, KC_ENT
#define ___6COL_BASE_RIGHT_ROW3___  ___5COL_BASE_RIGHT_ROW3___, KC_RSFT
#define ___6COL_BASE_RIGHT_TH___    KC_SPC, MO(_NAV), KC_ENT

/*** gaming layer ***/

/*** symbol layer ***/

/*** navigation layer ***/

/*** function layer ***/

/*** gaming number layer ***/


/** layout macros **/
// NOTE: apparently required for the row/half macros to expand out to the full comma separated list
#define LAYOUT_sy_3x5(...)     LAYOUT_split_3x5_3(__VA_ARGS__)
#define LAYOUT_sy_3x6(...)     LAYOUT_split_3x5_3(__VA_ARGS__)

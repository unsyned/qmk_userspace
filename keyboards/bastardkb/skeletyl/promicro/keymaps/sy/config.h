#pragma once

// #define DYNAMIC_KEYMAP_LAYER_COUNT 5
#define COMBO_TERM 30
#define PERMISSIVE_HOLD
// #define HOLD_ON_OTHER_KEY_PRESS
// #define CHORDAL_HOLD
#define TAPPING_TERM 160
#define TAPPING_TERM_PER_KEY
#define FLOW_TAP_TERM 125
#define SPECULATIVE_HOLD
// #define ONESHOT_TAP_TOGGLE 5  /* Tapping this number of times holds the key until tapped once again. */
// #define ONESHOT_TIMEOUT 5000  /* Time (in ms) before the one shot key is released */

/* NOTE:
 * this is a rev 1 version of the board.
 * bkb did a revision and dropped support for the original
 * a few years ago. the new version uses a different pinout.
 * so the following patch is required. */
#ifdef KEYBOARD_bastardkb_skeletyl_promicro
#    undef MATRIX_COL_PINS
#    undef MATRIX_ROW_PINS
#    undef SOFT_SERIAL_PIN
#    undef WS2812_DI_PIN
#    define MATRIX_COL_PINS { E6, C6, B1, B3, B2 }
#    define MATRIX_ROW_PINS { B5, F7, F6, B6 }
#    define SOFT_SERIAL_PIN D0
#    define WS2812_DI_PIN D2
#endif

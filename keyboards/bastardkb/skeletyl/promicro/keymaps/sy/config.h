#pragma once

// #define DYNAMIC_KEYMAP_LAYER_COUNT 5
#define COMBO_TERM 30
#define PERMISSIVE_HOLD
#define TAPPING_TERM 175
#define FLOW_TAP_TERM 125

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

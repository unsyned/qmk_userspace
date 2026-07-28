#pragma once

#define MAC 0
#define LIN 1
#define SYM 2
#define NAV 3
#define FUN 4
#define MSE 5

#define COMBO_TERM 30
#define PERMISSIVE_HOLD
#define TAPPING_TERM 200
#define FLOW_TAP_TERM 125
#define SPECULATIVE_HOLD
#define QUICK_TAP_TERM 0

// trying the features in this block/paragraph out
#define CAPS_WORD_INVERT_ON_SHIFT

#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define AUTO_MOUSE_DEFAULT_LAYER MSE
#define AUTO_MOUSE_TIME 650
#define AUTO_MOUSE_DELAY 200
#define AUTO_MOUSE_DEBOUNCE 25


// index is used for cpi default
#ifdef COCOT_CPI_OPTIONS
#    undef COCOT_CPI_OPTIONS
#    define COCOT_CPI_OPTIONS { 400, 600, 800, 1200, 1400, 1600 }
#    ifndef COCOT_CPI_DEFAULT
#       define COCOT_CPI_DEFAULT 3
#    endif
#endif
#ifndef COCOT_CPI_DEFAULT
#    define COCOT_CPI_DEFAULT 3
#endif

// value is used for divisor default
#ifndef COCOT_SCROLL_DIVIDERS
#    undef COCOT_SCROLL_DIVIDERS
#    define COCOT_SCROLL_DIVIDERS { 4, 5, 6, 7, 8 }
#    ifndef COCOT_SCROLL_DIV_DEFAULT
#       define COCOT_SCROLL_DIV_DEFAULT 6
#    endif
#endif
#ifndef COCOT_SCROLL_DIV_DEFAULT
#    define COCOT_SCROLL_DIV_DEFAULT 6
#endif

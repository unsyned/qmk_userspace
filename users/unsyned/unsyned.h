#pragma once

// layers
#define MAC 0
#define LIN 1
#define SYM 2
#define NAV 3
#define FUN 4
#define MSE 5

// mouse button aliases
#define MS_LEFT MS_BTN1
#define MS_RIGHT MS_BTN2
#define MS_MID MS_BTN3
#define MS_FOR MS_BTN4
#define MS_BACK MS_BTN5

// tap dance defs
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

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold)                                        \
    {                                                                               \
        .fn        = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, \
        .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}),               \
    }

// Tap dance callback prototypes
void tap_dance_tap_hold_finished(
    tap_dance_state_t *state,
    void *user_data
);

void tap_dance_tap_hold_reset(
    tap_dance_state_t *state,
    void *user_data
);

void td_shift_cw_finished(
    tap_dance_state_t *state,
    void *user_data
);

void td_shift_cw_reset(
    tap_dance_state_t *state,
    void *user_data
);

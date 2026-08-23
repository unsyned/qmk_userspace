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

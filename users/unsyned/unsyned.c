#include QMK_KEYBOARD_H
#include "keymap_introspection.h"
#include "quantum.h"
#include "unsyned.h"

// NOTE: This is untested. attempt to merge the encoder mappings when integrating the cocot38mini
// #if defined(ENCODER_MAP_ENABLE)
// const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
//     [MAC] =   { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
//     [LIN] =   { ENCODER_CCW_CW(_______, _______) },
//     [SYM] =   { ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
//     [NAV] =   { ENCODER_CCW_CW(_______, _______) },
//     [FUN] =   { ENCODER_CCW_CW(_______, _______) },
//     [MSE] =   { ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
// };
// #endif

// void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
//     tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;
//
//     if (state->pressed) {
//         if (state->count == 1 && !state->interrupted
// // #ifndef PERMISSIVE_HOLD
//             // && !state->interrupted
// // #endif
//         ) {
//             register_code16(tap_hold->hold);
//             tap_hold->held = tap_hold->hold;
//         } else {
//             register_code16(tap_hold->tap);
//             tap_hold->held = tap_hold->tap;
//         }
//     }
// }
//
// void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
//     tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;
//
//     if (tap_hold->held) {
//         unregister_code16(tap_hold->held);
//         tap_hold->held = 0;
//     }
// }
//
// void td_shift_cw_finished(tap_dance_state_t *state, void *user_data) {
//     if (state->count == 1) {
//         if (state->pressed) {
//           register_code(KC_RSFT); // hold
/*
 * #################### Callbacks ####################
 * */

bool is_flow_tap_key(uint16_t keycode) {
    if ((get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) {
        return false; // Disable Flow Tap on hotkeys.
    }
    switch (get_tap_keycode(keycode)) {
        // case KC_SPC:
        // case KC_BSPC:
        case KC_A ... KC_Z:
        case KC_DOT:
        case KC_COMM:
        case KC_SCLN:
        case KC_SLSH:
        case TD(J_MAC_CUT):
        case TD(V_MAC_COPY):
        case TD(D_MAC_PASTE):
        case TD(J_LIN_CUT):
        case TD(V_LIN_COPY):
        case TD(D_LIN_PASTE):
            return true;
    }
    return false;
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case TD(J_MAC_CUT):
        case TD(V_MAC_COPY):
        case TD(D_MAC_PASTE):
        case TD(J_LIN_CUT):
        case TD(V_LIN_COPY):
        case TD(D_LIN_PASTE):
        // case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

// qmk will bit mask away the shift from the mod tap on the sym layer. so we intercept the mod tap instead and send the appropriate character
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    tap_dance_action_t *action;
    tap_dance_state_t* state;

    switch (keycode) {
        case TD(J_MAC_CUT):
        case TD(V_MAC_COPY):
        case TD(D_MAC_PASTE):
        case TD(J_LIN_CUT):
        case TD(V_LIN_COPY):
        case TD(D_LIN_PASTE):
        case TD(PLAY_MUTE):
            action = tap_dance_get(QK_TAP_DANCE_GET_INDEX(keycode));
            state = tap_dance_get_state(QK_TAP_DANCE_GET_INDEX(keycode));
            if (!record->event.pressed && state != NULL && state->count && !state->finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            break;
        // symbol layer overrides
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
        // nav layer overrides
        case LCTL_T(KC_0):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_0);
                return false;        // Return false to ignore further processing of key
            }
            break;
        case LALT_T(KC_1):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_1);
                return false;        // Return false to ignore further processing of key
            }
            break;
        case LGUI_T(KC_2):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_2);
                return false;        // Return false to ignore further processing of key
            }
            break;
        case LSFT_T(KC_3):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_3);
                return false;        // Return false to ignore further processing of key
            }
            break;
        case RSFT_T(KC_LEFT):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LEFT);
                return false;        // Return false to ignore further processing of key
            }
            break;
        case RGUI_T(KC_DOWN):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_DOWN);
                return false;        // Return false to ignore further processing of key
            }
            break;
        case RALT_T(KC_RIGHT):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_RIGHT);
                return false;        // Return false to ignore further processing of key
            }
            break;
        case RCTL_T(KC_PGDN):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_PGDN);
                return false;        // Return false to ignore further processing of key
            }
            break;
    }
    return true;
}


// NOTE: untested layer change code. when we get to this, change the colors.
// #ifdef RGB_MATRIX_ENABLE
//
//
// bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
//     int is_layer = get_highest_layer(layer_state|default_layer_state);
//     HSV hsv = {0, 255, rgblight_get_val()};
//     if (is_layer == 1) {
//       hsv.h = 11; //CORAL
//     } else if (is_layer == 2)  {
//       hsv.h = 85; //GREEN
//     } else if (is_layer == 3)  {
//       hsv.h = 43; //YELLOW
//     } else if (is_layer == 4)  {
//       hsv.h = 0; //RED
//     } else if (is_layer == 5)  {
//       hsv.h = 191; //PURPLE
//     } else if (is_layer == 6)  {
//       hsv.h = 64; //CHARTREUSE
//     } else if (is_layer == 7)  {
//       hsv.h = 224;
//     } else {
//       hsv.h = 128; //CYAN
//     }
//     RGB rgb = hsv_to_rgb(hsv);
//
//     for (uint8_t i = led_min; i <= led_max; i++) {
//         if (HAS_FLAGS(g_led_config.flags[i], 0x02)) {
//           rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
//         }
//     }
//     return false;
// };
//
// #endif


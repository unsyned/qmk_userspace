/*
 * #################### Combos ####################
 * */
// combo defs
const uint16_t PROGMEM osl_fun_combo[] = {
    KC_L, KC_Y, KC_P, COMBO_END
};
const uint16_t PROGMEM caps_combo[] = {
    KC_F, KC_O, KC_U, COMBO_END
};

combo_t key_combos[] = {
    COMBO(osl_fun_combo, OSL(FUN)),
    COMBO(caps_combo, KC_CAPS),
};


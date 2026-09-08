/*
 * #################### Key overrides ####################
 * */
const key_override_t lcomma_override = ko_make_basic(MOD_BIT(KC_LSFT), KC_COMM, KC_SCLN);
const key_override_t rcomma_override = ko_make_basic(MOD_BIT(KC_RSFT), KC_COMM, KC_SCLN);

const key_override_t ldot_override = ko_make_basic(MOD_BIT(KC_LSFT), KC_DOT, KC_COLN);
const key_override_t rdot_override = ko_make_basic(MOD_BIT(KC_RSFT), KC_DOT, KC_COLN);

// punctuation
const key_override_t comma_ko = ko_make_basic(MOD_BIT(KC_RSFT), KC_COMM, KC_SCLN);
const key_override_t dot_ko = ko_make_basic(MOD_BIT(KC_RSFT), KC_DOT, KC_COLN);
const key_override_t exlm_ko = ko_make_basic(MOD_MASK_SHIFT, KC_QUES, KC_EXLM);

// system
const key_override_t briu_ko = ko_make_basic(MOD_MASK_GUI, KC_VOLU, KC_BRIU);
const key_override_t brid_ko = ko_make_basic(MOD_MASK_GUI, KC_VOLD, KC_BRID);


const key_override_t *key_overrides[] = {
    &comma_ko,
    &dot_ko,
    &exlm_ko,
    &briu_ko,
    &brid_ko,
};


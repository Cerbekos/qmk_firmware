#include QMK_KEYBOARD_H
#include "keymap_japanese.h"

#define C_CAPS MT(MOD_LCTL,KC_CAPS)
#define S_SLSH MT(MOD_LSFT,KC_SLSH)
#define L3_SPC LT(3,KC_SPC)
#define G_DEL MT(MOD_LGUI,KC_DEL)
#define L1_ENT LT(1,KC_ENT)
#define L2_CAPS LT(2,KC_CAPS)
#define S_SCLN S(KC_SCLN)
//#define TD_DOT TD(TD_DOT_CLN)
//#define TD_PLUS TD(TD_PLUS_PAST)
//#define TD_PMNS TD(TD_PMNS_PSLS)
#define OLED_SW USER07


// tap dance
/*
 enum {
    TD_DOT_CLN ,
    TD_PLUS_PAST,
    TD_PMNS_PSLS
};

typedef enum {
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP
 } td_state_t;

static td_state_t td_state;

td_state_t cur_dance(qk_tap_dance_state_t *state);

void dotcln_finished(qk_tap_dance_state_t *state, void *user_data);
void dotcln_reset(qk_tap_dance_state_t *state, void *user_data);
void plsast_finished(qk_tap_dance_state_t *state, void *user_data);
void plsast_reset(qk_tap_dance_state_t *state, void *user_data);
void mnssls_finished(qk_tap_dance_state_t *state, void *user_data);
void mnssls_reset(qk_tap_dance_state_t *state, void *user_data);
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        //|--------------------------------------------------------------+-----------------------------------------------------------------------'
             KC_ESC,      KC_F1,   KC_F2,   KC_F3,   KC_F4,         KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
             KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
             C_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_MINS,  KC_ENT, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
            KC_LSFT,       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT,        S_SLSH, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
            KC_LCTL,    KC_LGUI,    KC_LALT,     L3_SPC,               L1_ENT,         KC_SCLN,  TO(1),        KC_QUOT, KC_BTN1, KC_BTN3, KC_BTN2
        //|--------------------------------------------------------------+-----------------------------------------------------------------------'
    ),
    [1] = LAYOUT(
        //|--------------------------------------------------------------+-----------------------------------------------------------------------'
            _______,   _______, _______, _______, _______,       _______,  _______, _______, _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
            _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_DEL, _______, RGB_TOG, _______,
        //|--------+--------+--------+--------+--------+--------+---------+--------+--------+--------+--------+--------+--------+--------+--------|
            KC_LBRC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_RBRC, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
            KC_LPRN,    _______, _______, _______,  S_SCLN,  KC_EQL, KC_PPLS, KC_PMNS, KC_PAST, KC_PSLS,       KC_RPRN, _______, RGB_HUI, _______,
        //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
            _______,    _______,    _______,    _______,              _______,         _______,  TO(2),        _______,RGB_RMOD, RGB_HUD, RGB_MOD
        //|--------------------------------------------------------------+-----------------------------------------------------------------------'
    ),
    [2] = LAYOUT(
        //|--------------------------------------------------------------+-----------------------------------------------------------------------'
            _______,   _______, _______, _______, _______,       _______,  _______, _______, _______, _______, _______, _______, _______, QK_BOOT,
        //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
            _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
            _______,    _______,    _______,    _______,              _______,         _______,  TO(3),        _______, _______, _______, _______
        //|--------------------------------------------------------------+-----------------------------------------------------------------------'
    ),
    [3] = LAYOUT(
        //|--------------------------------------------------------------+-----------------------------------------------------------------------'
            _______,   _______, _______, _______, _______,       _______,  _______, _______, _______, _______, _______, KC_PSCR, KC_SCRL, KC_PAUS,
        //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
            _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, _______, KC_PGUP,   KC_UP, KC_PGDN, _______, _______, _______, KC_MUTE, _______,
        //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
            KC_LALT,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_HOME, KC_LEFT, KC_DOWN,KC_RIGHT, KC_BSPC, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
            _______,    _______, _______, _______, _______, _______,  KC_END, _______, _______, _______,       _______, _______, KC_VOLU, _______,
        //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
            _______,    _______,    _______,    _______,              _______,         _______,  TO(0),        _______, KC_MPRV, KC_VOLD, KC_MNXT
        //|--------------------------------------------------------------+-----------------------------------------------------------------------'
    )
};

// RGBLayer setting
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 2, HSV_RED});
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 2, HSV_BLUE});
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 2, HSV_GREEN});
const rgblight_segment_t PROGMEM my_layerCL_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 2, HSV_YELLOW});
const rgblight_segment_t PROGMEM my_layerNL_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 2, HSV_MAGENTA});

const rgblight_segment_t * const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_layerNL_layer,
    my_layerCL_layer,
    my_layer3_layer,
    my_layer2_layer,
    my_layer1_layer
);

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
};

// LayerIndicator 
layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(4, layer_state_cmp(state, 1));
    rgblight_set_layer_state(3, layer_state_cmp(state, 2));
    rgblight_set_layer_state(2, layer_state_cmp(state, 3));

    switch(get_highest_layer(state)){
        case 1:
        case 2:
            cocot_set_scroll_mode(true);
            break;
        case 3:
            cocot_set_scroll_mode(false);
            break;
        case 4:
        default:
            cocot_set_scroll_mode(false);
            break;
      }
    
    return state;
};

// LockIndicator
bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if(res) {
        writePin(0, !led_state.num_lock);
        rgblight_set_layer_state(0, !led_state.num_lock);
        rgblight_set_layer_state(1, led_state.caps_lock);
    }
    return res;
};

// Endoder 
bool encoder_update_user(uint8_t index, bool clockwise) {
    keypos_t key;

    if (index == 0) { /* First encoder */
        if (clockwise) {
            key.row = 5;
            key.col = 3;
        } else {
            key.row = 5;
            key.col = 5;
        }
    }
    action_exec((keyevent_t){.key = key, .pressed = true, .time = (timer_read() | 1)});
    action_exec((keyevent_t){.key = key, .pressed = false, .time = (timer_read() | 1)});
    return true;
}

/*
// tap dance
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }

    if (state->count == 2) return TD_DOUBLE_TAP;
    else return TD_UNKNOWN;  
}
// DOT,COLN
void dotcln_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_UNKNOWN:
            break;
        case TD_SINGLE_TAP:
            register_code16(KC_DOT);
            break;
        case TD_SINGLE_HOLD:
            layer_on(1);
            break;
        case TD_DOUBLE_TAP:
            register_code16(KC_COLN);
    }
}
void dotcln_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
       case TD_UNKNOWN:
            break;
       case TD_SINGLE_TAP:
            unregister_code16(KC_DOT);
            break;
        case TD_SINGLE_HOLD:
            layer_off(1);
            break;
        case TD_DOUBLE_TAP:
            unregister_code16(KC_COLN);
    }
}
// PLUS,AST
void plsast_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_UNKNOWN:
            break;
        case TD_SINGLE_TAP:
            register_code16(KC_PLUS);
            break;
        case TD_SINGLE_HOLD:
            layer_on(2);
            break;
        case TD_DOUBLE_TAP:
            register_code16(KC_PAST);
    }
}
void plsast_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
       case TD_UNKNOWN:
            break;
       case TD_SINGLE_TAP:
            unregister_code16(KC_PLUS);
            break;
        case TD_SINGLE_HOLD:
            layer_off(2);
            break;
        case TD_DOUBLE_TAP:
            unregister_code16(KC_PAST);
    }
}
// MINUS,SLASH
void mnssls_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_UNKNOWN:
            break;
        case TD_SINGLE_TAP:
            register_code16(KC_PMNS);
            break;
        case TD_SINGLE_HOLD:
            layer_on(3);
            break;
        case TD_DOUBLE_TAP:
            register_code16(KC_PSLS);
    }
}
void mnssls_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
       case TD_UNKNOWN:
            break;
       case TD_SINGLE_TAP:
            unregister_code16(KC_PMNS);
            break;
        case TD_SINGLE_HOLD:
            layer_off(3);
            break;
        case TD_DOUBLE_TAP:
            unregister_code16(KC_PSLS);
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_DOT_CLN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dotcln_finished, dotcln_reset),
  [TD_PLUS_PAST] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, plsast_finished, plsast_reset),
  [TD_PMNS_PSLS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, mnssls_finished, mnssls_reset)
};
*/

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    oled_write_layer_state();
    return false;
}
#endif
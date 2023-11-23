/* Copyright 2020 noroadsleft
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "keymap_japanese.h"
#include "quantum.h"  

/* tap dance */
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Tap dance enums
enum {
    ECQ,
    CCS,
    DSSS,
};

td_state_t cur_dance(tap_dance_state_t *state);

// For the x tap dance. Put it here so it can be used in any keymap
void ECQ_finished(tap_dance_state_t *state, void *user_data);
void ECQ_reset(tap_dance_state_t *state, void *user_data);
void CCS_finished(tap_dance_state_t *state, void *user_data);
void CCS_reset(tap_dance_state_t *state, void *user_data);
void DSSS_finished(tap_dance_state_t *state, void *user_data);
void DSSS_reset(tap_dance_state_t *state, void *user_data);

/* keymap */
#define MC_TAB MT(MOD_LCTL,KC_TAB)
#define MS_Z MT(MOD_LSFT,KC_Z)
#define MC_MINS MT(MOD_LCTL,KC_MINS)
#define MS_P4 MT(MOD_LSFT,KC_P4)
#define MA_CAPS MT(MOD_LALT,KC_CAPS)

#define L1_SPC LT(1,KC_SPC)
#define L2_ENT LT(2,KC_ENT)
#define L4_SPC LT(4,KC_SPC)
#define L5_ENT LT(5,KC_ENT)
#define L7_SPC LT(7,KC_SPC)
#define L8_ENT LT(8,KC_ENT)
#define L10_SPC LT(10,KC_SPC)
#define L11_ENT LT(11,KC_ENT)
#define L12_NUM LT(12,KC_NUM)

#define S_SLSH MT(MOD_RSFT,KC_SLSH)
#define S_SCLN S(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_QUOT, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        MC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LBRC, KC_H,    KC_J,    KC_K,    KC_L,    MC_MINS, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_RBRC, KC_N,    KC_M,    TD(CCS), TD(DSSS),KC_SLSH, KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT, MA_CAPS, L1_SPC,  KC_DEL,  MO(12),  KC_BSPC, L2_ENT,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),
    [1] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, KC_PGUP, KC_UP,   KC_PGDN, KC_INT3, _______,
        _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC, _______,
        _______, _______, _______, KC_PSCR, KC_SCRL, KC_PAUS, _______, KC_END,  _______, KC_SCLN, KC_QUOT, KC_APP,  _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [2] = LAYOUT(
        _______, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), _______, S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), _______,
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______, _______, _______, _______, S_SCLN,  KC_EQL,  _______, KC_PPLS, KC_PMNS, KC_PAST, KC_PSLS, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [3] = LAYOUT(
        TD(ECQ), KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_P7,   KC_P8,   KC_P9,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    MC_MINS, MS_P4,   KC_P5,   KC_P6,   
        MS_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    TD(CCS), TD(DSSS),KC_UP,   KC_P1,   KC_P2,   KC_P3,
        KC_LCTL, KC_LGUI, MA_CAPS, L4_SPC,  KC_DEL,  KC_BSPC, L5_ENT,  L12_NUM, KC_LEFT, KC_DOWN, KC_RGHT, KC_P0,   KC_PDOT
    ),
    [4] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, KC_PGUP, KC_UP,   KC_PGDN, KC_INT3, KC_LBRC, KC_RBRC, _______,
        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC, _______, _______, _______,
        _______, _______, KC_PSCR, KC_SCRL, KC_PAUS, KC_END,  _______, KC_SCLN, KC_QUOT, S_SLSH,  _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [5] = LAYOUT(
        S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),  S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), _______, _______, _______,
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, _______, _______,
        _______, _______, _______, S_SCLN,  KC_EQL,   KC_PPLS, KC_PMNS, KC_PAST, KC_PSLS, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [6] = LAYOUT(
        TD(ECQ), KC_W,    KC_E,    KC_R,    KC_T,    KC_P7,   KC_P8,   KC_P9,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_P4,   KC_P5,   KC_P6,   KC_H,    KC_J,    KC_K,    KC_L,    MC_MINS,
        MS_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_P1,   KC_P2,   KC_P3,   KC_N,    KC_M,    TD(CCS), TD(DSSS),S_SLSH,
        KC_LCTL, KC_LGUI, MA_CAPS, L7_SPC,  KC_DEL,  KC_P0,   KC_PDOT, L12_NUM, KC_BSPC, L8_ENT,  KC_TAB,  KC_APP,  KC_RCTL
    ),
    [7] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, _______, _______, KC_PGUP, KC_UP,   KC_PGDN, KC_INT3,
        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_LBRC, _______, KC_RBRC, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC,
        _______, _______, KC_PSCR, KC_SCRL, KC_PAUS, _______, _______, _______, KC_END,  _______, KC_SCLN, KC_QUOT, KC_APP,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [8] = LAYOUT(
        S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), _______, _______, _______, S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0),
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   
        _______, _______, _______, S_SCLN,  KC_EQL,  _______, _______, _______, KC_PPLS, KC_PMNS, KC_PAST, KC_PSLS, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [9] = LAYOUT(
        KC_P7,   KC_P8,   KC_P9,   TD(ECQ), KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    
        KC_P4,   KC_P5,   KC_P6,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    MC_MINS, 
        KC_P1,   KC_P2,   KC_P3,   MS_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    TD(CCS), TD(DSSS),S_SLSH,
        KC_P0,   KC_PDOT, L12_NUM, KC_LCTL, KC_LGUI, MA_CAPS, L10_SPC, KC_DEL,  KC_BSPC, L11_ENT, KC_TAB,  KC_APP,  KC_RCTL
    ),
    [10] = LAYOUT(
        _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, KC_PGUP, KC_UP,   KC_PGDN, KC_INT3,
        _______, _______, _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC,
        _______, _______, _______, KC_LSFT, KC_F11,  KC_PSCR, KC_SCRL, KC_PAUS, KC_END,  _______, KC_SCLN, KC_QUOT, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [11] = LAYOUT(
        _______, _______, _______, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),  S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0),
        _______, _______, _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   
        _______, _______, _______, _______, _______, _______, S_SCLN,  KC_EQL,   KC_PPLS, KC_PMNS, KC_PAST, KC_PSLS, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______
    ),
    [12] = LAYOUT(
        KC_F24,  KC_F23,  KC_F22,  KC_F21,  _______, RGB_HUI, _______, RGB_HUD, _______, _______, _______, _______, QK_BOOT,
        _______, _______, _______, _______, _______, RGB_MOD, _______, RGB_RMOD,_______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, RGB_SPI, _______, RGB_SPD, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______
    )
};

// RGBLayer setting
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i < led_max; i++) {
        switch(get_highest_layer(layer_state)) {
            case 12: if (HAS_FLAGS(g_led_config.flags[i], 0x08)) rgb_matrix_set_color(i, RGB_MAGENTA); break;
            case 11: if (HAS_FLAGS(g_led_config.flags[i], 0x08)) rgb_matrix_set_color(i, RGB_GREEN); break;
            case 10: if (HAS_FLAGS(g_led_config.flags[i], 0x08)) rgb_matrix_set_color(i, RGB_BLUE); break;
            case 8: if (HAS_FLAGS(g_led_config.flags[i], 0x08)) rgb_matrix_set_color(i, RGB_GREEN); break;
            case 7: if (HAS_FLAGS(g_led_config.flags[i], 0x08)) rgb_matrix_set_color(i, RGB_BLUE); break;
            case 5: if (HAS_FLAGS(g_led_config.flags[i], 0x08)) rgb_matrix_set_color(i, RGB_GREEN); break;
            case 4: if (HAS_FLAGS(g_led_config.flags[i], 0x08)) rgb_matrix_set_color(i, RGB_BLUE); break;
            case 2: if (HAS_FLAGS(g_led_config.flags[i], 0x08)) rgb_matrix_set_color(i, RGB_GREEN); break;
            case 1: if (HAS_FLAGS(g_led_config.flags[i], 0x08)) rgb_matrix_set_color(i, RGB_BLUE); break;
            default: break;
        }
        if (host_keyboard_led_state().caps_lock) {
            if (HAS_FLAGS(g_led_config.flags[i], 0x08)) rgb_matrix_set_color(i, RGB_YELLOW);
        }
    }
    return false;
}

// TAP DANCE
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

//ECQ
static td_tap_t ECQ_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void ECQ_finished(tap_dance_state_t *state, void *user_data) {
    ECQ_tap_state.state = cur_dance(state);
    switch (ECQ_tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_Q); break;
        case TD_SINGLE_HOLD: register_code(KC_LCTL); break;
        case TD_DOUBLE_TAP: register_code(KC_ESC); break;
        case TD_DOUBLE_HOLD: caps_word_on(); break;
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_Q); register_code(KC_Q); break;
        default: break;
    }
}

void ECQ_reset(tap_dance_state_t *state, void *user_data) {
    switch (ECQ_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_Q); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LCTL); break;
        case TD_DOUBLE_TAP: unregister_code(KC_ESC); break;
        case TD_DOUBLE_HOLD: break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_Q); break;
        default: break;
    }
    ECQ_tap_state.state = TD_NONE;
}

//CCS
static td_tap_t CCS_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void CCS_finished(tap_dance_state_t *state, void *user_data) {
    CCS_tap_state.state = cur_dance(state);
    switch (CCS_tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_COMM); break;
        case TD_SINGLE_HOLD: register_code(KC_RCTL); break;
        case TD_DOUBLE_TAP: register_code(KC_SCLN); break;
        case TD_DOUBLE_HOLD: register_code(KC_SCLN); break;
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_COMM); register_code(KC_COMM); break;
        default: break;
    }
}

void CCS_reset(tap_dance_state_t *state, void *user_data) {
    switch (CCS_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_COMM); break;
        case TD_SINGLE_HOLD: unregister_code(KC_RCTL); break;
        case TD_DOUBLE_TAP: unregister_code(KC_SCLN); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_SCLN); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_COMM); break;
        default: break;
    }
    CCS_tap_state.state = TD_NONE;
}

//DSSS
static td_tap_t DSSS_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void DSSS_finished(tap_dance_state_t *state, void *user_data) {
    DSSS_tap_state.state = cur_dance(state);
    switch (DSSS_tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_DOT); break;
        case TD_SINGLE_HOLD: register_code(KC_RSFT); break;
        case TD_DOUBLE_TAP: register_code(KC_RSFT); register_code(KC_SCLN); break;
        case TD_DOUBLE_HOLD: register_code(KC_RSFT); register_code(KC_SCLN); break;
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_DOT); register_code(KC_DOT); break;
        default: break;
    }
}

void DSSS_reset(tap_dance_state_t *state, void *user_data) {
    switch (DSSS_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_DOT); break;
        case TD_SINGLE_HOLD: unregister_code(KC_RSFT); break;
        case TD_DOUBLE_TAP: unregister_code(KC_RSFT); unregister_code(KC_SCLN); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_RSFT); unregister_code(KC_SCLN); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_DOT); break;
        default: break;
    }
    DSSS_tap_state.state = TD_NONE;
}

//tap_dance_actions
tap_dance_action_t tap_dance_actions [] = {
    [ECQ] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ECQ_finished, ECQ_reset),
    [CCS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, CCS_finished, CCS_reset),
    [DSSS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, DSSS_finished, DSSS_reset)
};

// CAPS WORD
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
        case TD(CCS):
        case TD(DSSS):
        case TD(ECQ):
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

led_config_t g_led_config = { {
  // Key Matrix to LED Index
  {NO_LED,0,1,2,3,4,5,6},
  {7,NO_LED,8,9,10,11,12,13},
  {14,15,NO_LED,16,17,18,19,20},
  {21,22,23,NO_LED,24,25,26,27},
  {28,29,30,31,NO_LED,32,33,34},
  {35,36,37,38,39,NO_LED,40,41},
  {42,43,44,45,46,47,NO_LED,48},
  {49,50,51,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED}
}, {
  // LED Index to Physical Position
  { 0,0 },{ 19,0 },{ 37,0 },{ 56,0 },{ 75,0 },{ 93,0 },{ 112,0 },{ 131,0 },{ 149,0 },{ 168,0 },{ 187,0 },{ 205,0 },{ 224,0 },
  { 0,21 },{ 19,21 },{ 37,21 },{ 56,21 },{ 75,21 },{ 93,21 },{ 112,21 },{ 131,21 },{ 149,21 },{ 168,21 },{ 187,21 },{ 205,21 },{ 224,21 },
  { 0,43 },{ 19,43 },{ 37,43 },{ 56,43 },{ 75,43 },{ 93,43 },{ 112,43 },{ 131,43 },{ 149,43 },{ 168,43 },{ 187,43 },{ 205,43 },{ 224,43 },
  { 0,64 },{ 19,64 },{ 37,64 },{ 56,64 },{ 75,64 },{ 93,64 },{ 112,64 },{ 131,64 },{ 149,64 },{ 168,64 },{ 187,64 },{ 205,64 },{ 224,64 }
}, {
  // LED Index to Flag
  1,4,4,4,4,4,8,4,4,4,4,4,1,
  1,4,4,4,4,4,8,4,4,4,4,4,1,
  1,4,4,4,4,4,8,4,4,4,4,4,1,
  1,1,1,1,1,1,8,1,1,1,1,1,1
} };

// Defalut lyout change
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_F24:
      if (record->event.pressed) {
        return false;
      } else {
        rgb_matrix_mode(RGB_MATRIX_CUSTOM_myef_mod_func);
        set_single_persistent_default_layer(0);
        return false;
      }
    case KC_F23:
      if (record->event.pressed) {
        return false;
      } else {
        rgb_matrix_mode(RGB_MATRIX_CUSTOM_myef_right_numpad);
        set_single_persistent_default_layer(3);
        return false;
      }
    case KC_F22:
      if (record->event.pressed) {
        return false;
      } else {
        rgb_matrix_mode(RGB_MATRIX_CUSTOM_myef_center_numpad);
        set_single_persistent_default_layer(6);
        return false;
      }
    case KC_F21:
      if (record->event.pressed) {
        return false;
      } else {
        rgb_matrix_mode(RGB_MATRIX_CUSTOM_myef_left_numpad);
        set_single_persistent_default_layer(9);
        return false;
      }
    
    default:
      return true;
  }
};

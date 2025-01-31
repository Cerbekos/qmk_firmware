/*
Copyright 2022 Cerbekos

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "keymap_jp.h"
// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define C_TAB MT(MOD_LCTL,KC_TAB)
#define GUITAB G(KC_TAB)
#define ALTTAB A(KC_TAB)
#define S_SLSH MT(MOD_LSFT,KC_SLSH)
#define L3_SPC LT(3,KC_SPC)
#define G_DEL MT(MOD_LGUI,KC_DEL)
#define L1_ENT LT(1,KC_ENT)
#define L2_SCLN LT(2,KC_SCLN)
#define S_SCLN S(KC_SCLN)

enum layer_number {
  _QWERTY = 0,
  _FN,
  _FN2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    //|--------------------------------------------------------------+--------------------------------------------------------------------------------------------------'
         KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_UP,KC_RIGHT,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
          C_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G, KC_LEFT, KC_DOWN,    KC_H,    KC_J,    KC_K,    KC_L, KC_MINS,  KC_ENT,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,          KC_RALT,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT,  S_SLSH,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        KC_LCTL,  GUITAB, KC_LALT,  L3_SPC,  ALTTAB,   G_DEL,           KC_ENT, KC_CAPS,  L1_ENT,   TO(1), KC_APP,   TO(3),  L2_SCLN
    //|--------------------------------------------------------------+--------------------------------------------------------------------------------------------------'
  ),
  [_FN] = LAYOUT(
    //|--------------------------------------------------------------+--------------------------------------------------------------------------------------------------'
        _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, _______, _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______,  S_SCLN,  KC_DEL,           KC_EQL, KC_PMNS, KC_PAST, KC_PSLS, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        _______,   KC_F7, _______, _______,   KC_F8, _______,          KC_PPLS, _______, _______,   TO(2), _______,   TO(0), _______
    //|-------- -----------------------------------------------------+--------------------------------------------------------------------------------------------------'
  ),
  [_FN2] = LAYOUT(
    //|--------------------------------------------------------------+--------------------------------------------------------------------------------------------------'
        _______, _______, _______, _______, _______, _______, KC_WH_U, KC_WH_R, _______, _______, _______, _______, _______,   RESET,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        _______, _______, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_K, KC_WH_L, KC_WH_D, _______, _______, _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        _______, _______,RGB_M_SW,RGB_M_SN, RGB_M_X, RGB_M_G,          KC_BTN1, _______, _______, _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        _______, RGB_HUI, _______, RGB_MOD, RGB_HUD,RGB_RMOD,          KC_BTN2, KC_BTN3, RGB_TOG,   TO(3), _______,   TO(1), _______
    //|-----------------------------------------------------------------------+-----------------------------------------------------------------------------------------'
  ),
  [_FN3] = LAYOUT(
    //|--------------------------------------------------------------+--------------------------------------------------------------------------------------------------'
        _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_PGUP,  KC_END,  KC_INS, _______, _______, KC_LBRC, KC_RBRC, _______,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_HOME, KC_PGDN,  KC_DEL, _______, _______, KC_SCLN, KC_QUOT, KC_BSLS,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______,          KC_BTN1, _______, _______, _______, KC_MINS,  KC_EQL, _______,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        _______, KC_VOLU, _______, _______, KC_VOLD,   MO(2),          KC_BTN2,   MO(2), _______,   TO(0), _______,   TO(2), _______
    //|--------------------------------------------------------------+--------------------------------------------------------------------------------------------------'
  )
};
// ***LED control***//
//RGBLayer setting
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {10, 6, HSV_RED}
);

const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {10, 6, HSV_BLUE}
);

const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {10, 6, HSV_GREEN}
);

const rgblight_segment_t PROGMEM my_layerCL_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {10, 6, HSV_YELLOW}
);


const rgblight_segment_t * const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_layerCL_layer,
    my_layer3_layer,
    my_layer2_layer,
    my_layer1_layer
);

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
};

// LayerIndicator setting
layer_state_t layer_state_set_user(layer_state_t state) {
      rgblight_set_layer_state(3, layer_state_cmp(state, 1));
      rgblight_set_layer_state(2, layer_state_cmp(state, 2));
      rgblight_set_layer_state(1, layer_state_cmp(state, 3));
    return state;
};

bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if(res) {
        //writePin(D2, !led_state.num_lock);
        rgblight_set_layer_state(0, led_state.caps_lock);
    }
    return res;
};

// endoder setting
bool encoder_update_user(uint8_t index, bool clockwise) {
    keypos_t key;

    if (index == 0) { /* First encoder */
        if (clockwise) {
            key.row = 3;
            key.col = 1;
        } else {
            key.row = 3;
            key.col = 4;
        }
    } else if (index == 1) { /* Second encoder */
            if (clockwise) {
              key.row = 7;
              key.col = 3;
            } else {
              key.row = 7;
              key.col = 5;
            }
        }
    action_exec((keyevent_t){.key = key, .pressed = true, .time = (timer_read() | 1)});
    action_exec((keyevent_t){.key = key, .pressed = false, .time = (timer_read() | 1)});
    return true;
}

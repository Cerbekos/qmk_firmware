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

#define L3_SPC LT(3,KC_SPC)
#define L2_DEL LT(2,KC_DEL)
#define MS_SLSH MT(MOD_LSFT,KC_SLSH)
#define L1_ENT LT(1,KC_ENT)
#define S_SCLN S(KC_SCLN)
#define G_TAB G(KC_TAB)
#define A_TAB A(KC_TAB)
#define L1_PPLS LT(1,KC_PPLS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    //|--------------------------------------------------------------+--------------------------------------------------------------------------------------------------'
         KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,            KC_P7,   KC_P8,   KC_P9, KC_PSLS,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,     KC_MINS,                 KC_P4,   KC_P5,   KC_P6, KC_PAST,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, MS_SLSH,            KC_P1,   KC_P2,   KC_P3, KC_PMNS,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        KC_LCTL, KC_LGUI, KC_LALT,      L3_SPC,       L2_DEL,          KC_BSPC,     L1_ENT,       KC_RALT, KC_RGUI, KC_RCTL,            KC_P0, KC_PDOT, KC_PENT, L1_PPLS,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
             A_TAB,   G_TAB,                                                                  TO(1),   TO(3),                                           KC_VOLU, KC_VOLD
    //|--------------------------------------------------------------+--------------------------------------------------------------------------------------------------'
  ),
  [1] = LAYOUT(
    //|--------------------------------------------------------------+--------------------------------------------------------------------------------------------------'
        _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,            KC_F7,   KC_F8,   KC_F9, _______,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,      KC_0,                   KC_F4,   KC_F5,   KC_F6, _______,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______,  S_SCLN,  KC_EQL,          KC_PPLS, KC_PMNS, KC_PAST, KC_PSLS, _______, _______,            KC_F1,   KC_F2,   KC_F3, _______,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        _______, _______, _______,     _______,      _______,          _______,     _______,      _______, _______, _______,           KC_F10,  KC_F11,  KC_F12, _______,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
             KC_F7,   KC_F8,                                                                  TO(2),   TO(0),                                           _______, _______
    //|--------------------------------------------------------------+--------------------------------------------------------------------------------------------------'
  ),
  [2] = LAYOUT(
    //|--------------------------------------------------------------+--------------------------------------------------------------------------------------------------'
          RESET, _______, _______, _______, _______, _______,          _______, _______, _______, KC_LBRC, KC_RBRC, KC_BSLS,          _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, RGB_VAD, RGB_HUD,          _______, _______, KC_SCLN, KC_QUOT,     KC_NUHS,               _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, RGB_VAI, RGB_HUI,          _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        _______, _______, _______,     _______,      _______,          _______,     RGB_TOG,      _______, _______, _______,          _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
            RGB_MOD, RGB_RMOD,                                                                  TO(3),   TO(1),                                         _______, _______
    //|--------------------------------------------------------------+--------------------------------------------------------------------------------------------------'
  ),
  [3] = LAYOUT(
    //|--------------------------------------------------------------+--------------------------------------------------------------------------------------------------'
        _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,          _______, KC_PGUP,   KC_UP, KC_PGDN, _______, _______,          _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        KC_LALT,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,          KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT,     KC_BSPC,               _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        _______,  KC_F11,  KC_F12, _______, _______, _______,          _______,  KC_END,  KC_INS, _______, _______, _______,          _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        _______, _______, _______,     _______,      _______,          _______,     _______,      _______, _______, _______,          _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
            KC_VOLU, KC_VOLD,                                                                TO(0),   TO(2),                                            _______, _______
    //|--------------------------------------------------------------+--------------------------------------------------------------------------------------------------'
  )
};

// ***LED control***//
//RGBLayer setting
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 7, HSV_RED}
);

const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 7, HSV_BLUE}
);

const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 7, HSV_GREEN}
);

const rgblight_segment_t PROGMEM my_layerCL_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 7, HSV_YELLOW}
);

const rgblight_segment_t PROGMEM my_layerNL_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 7, HSV_MAGENTA}
);

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

// LayerIndicator setting
layer_state_t layer_state_set_user(layer_state_t state) {
      rgblight_set_layer_state(4, layer_state_cmp(state, 1));
      rgblight_set_layer_state(3, layer_state_cmp(state, 2));
      rgblight_set_layer_state(2, layer_state_cmp(state, 3));
    return state;
};

bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if(res) {
        //writePin(D2, !led_state.num_lock);
        rgblight_set_layer_state(0, !led_state.num_lock);
        rgblight_set_layer_state(1, led_state.caps_lock);
    }
    return res;
};

// endoder setting
bool encoder_update_user(uint8_t index, bool clockwise) {
    keypos_t key;

    if (index == 0) { /* First encoder */
        if (clockwise) {
            key.row = 5;
            key.col = 10;
        } else {
            key.row = 5;
            key.col = 11;
        }
    } else if (index == 1) { /* Second encoder */
            if (clockwise) {
              key.row = 6;
              key.col = 10;
            } else {
              key.row = 6;
              key.col = 11;
            }
    } else if (index == 2) { /* Third encoder */
              if (clockwise) {
                key.row = 7;
                key.col = 10;
              } else {
                key.row = 7;
                key.col = 11;
              }
          }
    action_exec((keyevent_t){.key = key, .pressed = true, .time = (timer_read() | 1)});
    action_exec((keyevent_t){.key = key, .pressed = false, .time = (timer_read() | 1)});
    return true;
}

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
#include "keymap_japanese.h"
// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define G_DEL MT(MOD_LGUI,KC_DEL)
#define C_TAB MT(MOD_LCTL,KC_TAB)
#define L2_SPC LT(2,KC_SPC)
#define L1_ENT LT(1,KC_ENT)
#define S_COLN S(KC_COLN)
#define C_Z C(KC_Z)
#define C_Y C(KC_Y)

enum layer_number {
  _QWERTY = 0,
  _FN,
  _FN2,
  _FN3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    //|--------------------------------------------------------------+-----------------------------------+--------------------------------------------------------------'
        RGB_TOG, KC_GESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_P9,   KC_P6,   KC_P3,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_EQL, KC_BSPC,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
          DF(3),   C_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_P8,   KC_P5,   KC_P2,  KC_DOT,    KC_H,    KC_J,    KC_K,    KC_L, KC_MINS,     KC_QUOT,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
                 KC_LSPO,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_P7,   KC_P4,   KC_P1,   KC_P0,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSPC,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
                 KC_LCTL,          KC_LALT,      L2_SPC,        G_DEL,          KC_BSPC, KC_NLCK,          KC_CAPS,     L1_ENT,       KC_LALT,              KC_RCTL
    //|--------------------------------------------------------------+-----------------------------------+--------------------------------------------------------------'
  ),
  [_FN] = LAYOUT(
    //|--------------------------------------------------------------+--------------------------------------------------------------------------------------------------'
        KC_VOLU, KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_BTN5, KC_WH_R, KC_MS_R,          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS, _______,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        KC_VOLD, _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_BTN4, KC_MS_U, KC_MS_D, KC_BTN2,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     _______,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
                 KC_LBRC, _______, _______, _______,  S_COLN,  KC_EQL, KC_BTN3, KC_WH_L, KC_MS_L, KC_BTN1, KC_PSLS, KC_COLN, _______, _______, _______, _______, KC_RBRC,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
                 _______,          _______,          _______, _______,          KC_WH_U, KC_WH_D,          _______, _______,           _______,               _______
    //|-----------------------------------------------------------------------+-----------------------------------------------------------------------------------------'
  ),
  [_FN2] = LAYOUT(
    //|--------------------------------------------------------------+--------------------------------------------------------------------------------------------------'
        _______, _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_LPRN, KC_RPRN, KC_PSLS,          _______, KC_PGUP,   KC_UP, KC_PGDN, _______, KC_JYEN, _______,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        _______, KC_LALT,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,     C_Y,   KC_F2, KC_PAST, KC_COMM, KC_HOME, KC_LEFT, KC_DOWN,KC_RIGHT,  KC_BSPC,     _______,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
                 _______, _______, _______, _______, _______, _______,     C_Z,  S_COLN, KC_PMNS, KC_CALC, _______,  KC_END, _______, _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
                 _______,          _______,          _______, _______,           KC_EQL, KC_PLUS,          _______, _______,          _______,               _______
    //|-------- -----------------------------------------------------+--------------------------------------------------------------------------------------------------'
  ),
  [_FN3] = LAYOUT(
    //|--------------------------------------------------------------+--------------------------------------------------------------------------------------------------'
          DF(3), _______, _______,  KC_F21,  KC_F22,  KC_F23,  KC_F24, RGB_M_P, RGB_M_B, RGB_M_R,          _______, _______, _______, _______, _______, _______, QK_BOOT,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
          DF(0), _______, _______, _______, _______, _______, RGB_VAI, RGB_M_K,RGB_M_SW,RGB_M_SN, RGB_HUD, _______, _______, _______, _______, _______,     _______,
    //|--------+--------+--------+--------+--------+-------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
                 _______, _______, _______, _______, _______,RGB_VAD, RGB_M_K, RGB_M_X, RGB_M_G, RGB_HUI,  _______, _______, _______, _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
                 _______,          _______,          _______,_______,         RGB_MOD, RGB_RMOD,           _______, RGB_TOG,          TG(3),               _______
    //|--------------------------------------------------------------+--------------------------------------------------------------------------------------------------'
  )
};

// ***LED control***//
//RGBLayer setting
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {12, 24, HSV_RED}
);

const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {12, 24, HSV_BLUE}
);

const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {12, 24, HSV_GREEN}
);

const rgblight_segment_t PROGMEM my_layerCL_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {12, 24, HSV_YELLOW}
);

const rgblight_segment_t PROGMEM my_layerNL_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {12, 24, HSV_MAGENTA}
);

const rgblight_segment_t PROGMEM my_layerBlink_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {12, 24, HSV_WHITE}
);


const rgblight_segment_t * const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_layerNL_layer,
    my_layerCL_layer,
    my_layer3_layer,
    my_layer2_layer,
    my_layer1_layer,
    my_layerBlink_layer
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

// LED setting
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // RGBLighting switching
    case KC_F24:
      if (record->event.pressed) {
        return false;
      } else {
        layer_state_set(0);
        if (rgblight_get_val() > 0) {
          // RGB OFF
          rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
          rgblight_sethsv_noeeprom(0, 0, 0);
          rgblight_blink_layer_repeat(5, 200, 2);
          return false;
        } else {
          // RGB reload from eeprom
          rgblight_reload_from_eeprom();
          rgblight_blink_layer_repeat(5, 200, 2);
          return false;
        }
      }
    default:
      return true;
    }
  };


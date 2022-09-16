/*
Copyright 2021 Cerbekos

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

#define A_TAB A(KC_TAB)
#define C_CAPS MT(MOD_LCTL,KC_CAPS)
#define L2_NLCK LT(2,KC_NLCK)
#define L1_PENT LT(1,KC_PENT)
#define L1_SPC LT(1,KC_SPC)
#define L2_ENT LT(2,KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    //|--------------------------------------------------------------+--------------------------------------------------------------------------------------------------'
        KC_GESC,  KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_P7,   KC_P8,   KC_P9,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,KC_SCLN,  KC_BSPC,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
          A_TAB,  C_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_P4,   KC_P5,   KC_P6, L2_NLCK,    KC_H,    KC_J,    KC_K,    KC_L, KC_MINS,      KC_ENT,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
                 KC_LSPO,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_P1,   KC_P2,   KC_P3, L1_PENT,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSPC,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
                 KC_LCTL,          KC_LALT,      L1_SPC,      KC_LGUI,            KC_P0,  KC_DOT,                LT(2,KC_ENT),         TT(3),              LT(2,KC_DEL)
    //|--------------------------------------------------------------+--------------------------------------------------------------------------------------------------'
  ),
  [1] = LAYOUT(
    //|--------------------------------------------------------------+--------------------------------------------------------------------------------------------------'
        _______, _______, _______,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F7,   KC_F8,   KC_F9,          _______, KC_PGUP,   KC_UP, KC_PGDN, _______, KC_QUOT,  KC_EQL,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        _______, KC_LALT,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,   KC_F4,   KC_F5,   KC_F6, KC_CAPS, KC_HOME, KC_LEFT, KC_DOWN,KC_RIGHT,  KC_BSPC,     _______,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
                 _______, _______, _______, _______, _______,  KC_DEL,   KC_F1,   KC_F2,   KC_F3, _______, _______,  KC_END, _______, _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
                 _______,          _______,          _______, _______,           KC_F10, KC_CALC,                   _______,          _______,               _______
    //|-------- -----------------------------------------------------+--------------------------------------------------------------------------------------------------'
  ),
  [2] = LAYOUT(
    //|--------------------------------------------------------------+--------------------------------------------------------------------------------------------------'
        KC_VOLU, KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,  KC_ESC,  KC_DEL, KC_BSLS,          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS, _______,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        KC_VOLD, _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_PSLS, KC_PAST, KC_PMNS, _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     _______,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
                 KC_LBRC, _______, _______, _______, _______, _______, KC_COLN,  KC_EQL, KC_PLUS, KC_BSPC, KC_PSLS, KC_COLN, _______, _______, _______, _______, KC_RBRC,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
                 _______,          _______,          _______, _______,           KC_TAB, KC_COMM,                  _______,           _______,               _______
    //|-----------------------------------------------------------------------+-----------------------------------------------------------------------------------------'
  ),
  [3] = LAYOUT(
    //|--------------------------------------------------------------+--------------------------------------------------------------------------------------------------'
          DF(3), _______, _______,  KC_F21,  KC_F22,  KC_F23,  KC_F24, RGB_M_P, RGB_M_B, RGB_M_R,          _______, _______, KC_MS_U, _______, _______, _______,   RESET,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
          DF(0), _______, _______, KC_ACL0, KC_ACL1, KC_ACL2, RGB_VAI, RGB_M_K,RGB_M_SW,RGB_M_SN, RGB_HUD, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,     _______,
    //|--------+--------+--------+--------+--------+-------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
                 _______, _______, _______, _______, _______,RGB_VAD, RGB_M_K, RGB_M_X, RGB_M_G, RGB_HUI, _______, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, KC_BTN5, _______,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
                 _______,          _______,          _______,_______,         RGB_MOD, RGB_RMOD,                   RGB_TOG,          TG(3),               _______
    //|--------------------------------------------------------------+--------------------------------------------------------------------------------------------------'
  )
};

// ***LED control***//
// Variable definition
int bl_range_mode = 0;
int ly_range_mode = 0;
int NL_range_mode = 0;
int CL_range_mode = 0;

//RGBLayer setting
//LED_No is #0-16:UG,17-29:BL
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {17, 13, HSV_RED}
  //{21, 2, HSV_RED},
  //{24, 2, HSV_RED}
  //{21, 5, HSV_RED}
);

const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {17, 13, HSV_BLUE}
  //{21, 2, HSV_BLUE},
  //{24, 2, HSV_BLUE}
  //{21, 5, HSV_BLUE}
);

const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {17, 13, HSV_GREEN}
  //{21, 2, HSV_GREEN},
  //{24, 2, HSV_GREEN}
  //{21, 5, HSV_GREEN}
);

//led indicators
const rgblight_segment_t PROGMEM my_layerNL_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {17, 13, HSV_MAGENTA}
  //{21, 2, HSV_MAGENTA},
  //{24, 2, HSV_MAGENTA}
  //{21, 5, HSV_MAGENTA}
);

const rgblight_segment_t PROGMEM my_layerCL_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {17, 13, HSV_YELLOW}
  //{21, 2, HSV_YELLOW},
  //{24, 2, HSV_YELLOW}
  //{21, 5, HSV_YELLOW}
);

const rgblight_segment_t PROGMEM my_layerOFF_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {17, 13, HSV_OFF}
  //{21, 2, HSV_OFF},
  //{24, 2, HSV_OFF}
  //{21, 5, HSV_OFF}
);

const rgblight_segment_t PROGMEM my_layerBlink_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {17, 13, HSV_WHITE}
);

const rgblight_segment_t PROGMEM my_layerNone_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {90, 1, HSV_OFF}
);

const rgblight_segment_t * const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_layerNL_layer,
    my_layerCL_layer,
    my_layer3_layer,
    my_layer2_layer,
    my_layer1_layer,
    my_layerNone_layer,
    my_layerBlink_layer,
    my_layerOFF_layer
);

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
};

// LayerIndicator setting
layer_state_t layer_state_set_user(layer_state_t state) {
    if (ly_range_mode == 0) {
      rgblight_set_layer_state(4, layer_state_cmp(state, 1));
      rgblight_set_layer_state(3, layer_state_cmp(state, 2));
      rgblight_set_layer_state(2, layer_state_cmp(state, 3));
    } else if (ly_range_mode == 1) {
      rgblight_set_layer_state(5, layer_state_cmp(state, 1));
      rgblight_set_layer_state(5, layer_state_cmp(state, 2));
      rgblight_set_layer_state(5, layer_state_cmp(state, 3));
    }
    return state;
};

// Locking keys Indicator setting
bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if(res) {
      if (NL_range_mode == 0) {
          rgblight_set_layer_state(0, !led_state.num_lock);
      } else if (NL_range_mode == 1) {
          rgblight_set_layer_state(0, led_state.num_lock);
      } else if (NL_range_mode == 2) {
          rgblight_set_layer_state(5, !led_state.num_lock);
      }

      if (CL_range_mode == 0)   {
          rgblight_set_layer_state(1, led_state.caps_lock);
      } else if (CL_range_mode == 1) {
          rgblight_set_layer_state(5, led_state.caps_lock);
      }
    }
    return res;
};

// LED setting Fanction
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Backlight range mode switching
    case KC_F24:
      if (record->event.pressed) {
        return false;
      } else {
        layer_state_set(0);
        switch (bl_range_mode) {
          case 0:
            rgblight_set_effect_range(17, 13);
            rgblight_sethsv_range(HSV_OFF, 0, 17);
            rgblight_blink_layer_repeat(6, 200, 2);
            bl_range_mode = 1;
            return false;
          case 1:
            rgblight_set_effect_range(0, 30);
            rgblight_blink_layer_repeat(6, 200, 3);
            bl_range_mode = 0;
            return false;
          default:
            return false;
        }
      }
    // LayerIndicator mode switching
    case KC_F23:
      if (record->event.pressed) {
        return false;
      } else {
        layer_state_set(0);
        switch (ly_range_mode) {
          case 0:
            ly_range_mode = 1;
            rgblight_blink_layer_repeat(6, 200, 2);
            return false;
          case 1:
            ly_range_mode = 0;
            rgblight_blink_layer_repeat(6, 200, 3);
            return false;
          default:
            return false;
        }
      }
    // num_lock indicator mode switching
    case KC_F22:
      if (record->event.pressed) {
        return false;
      } else {
        layer_state_set(0);
        switch (NL_range_mode) {
          case 0:
            NL_range_mode = 1;
            rgblight_blink_layer_repeat(6, 200, 2);
            return false;
          case 1:
            NL_range_mode = 2;
            rgblight_blink_layer_repeat(6, 200, 3);
            return false;
          case 2:
            NL_range_mode = 0;
            rgblight_blink_layer_repeat(6, 200, 4);
            return false;
          default:
            return false;
        }
      }
    // caps_lock indicator mode switching
    case KC_F21:
      if (record->event.pressed) {
        return false;
      } else {
        layer_state_set(0);
        switch (CL_range_mode) {
          case 0:
            CL_range_mode = 1;
            rgblight_blink_layer_repeat(6, 200, 2);
            return false;
          case 1:
            CL_range_mode = 0;
            rgblight_blink_layer_repeat(6, 200, 3);
            return false;
          default:
            return false;
        }
      }
    default:
      return true;
  }
};

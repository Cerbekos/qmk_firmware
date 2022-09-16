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


enum layer_number {
  _QWERTY = 0,
  _FN,
  _FN2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    //|------------------------------------'
          KC_P7,   KC_P8,   KC_P9,   
    //|--------+--------+--------+--------+|
          KC_P4,   KC_P5,   KC_P6,   TO(3),
    //|--------+--------+--------+--------+|
          KC_P1,   KC_P2,   KC_P3,   TO(1),
    //|--------+--------+--------+--------+|
                   KC_P0, KC_NLCK
    //|------------------------------------'
  ),
  [_FN] = LAYOUT(
    //|------------------------------------'
          KC_F7,   KC_F8,   KC_F9, 
    //|--------+--------+--------+--------+|
          KC_F4,   KC_F5,   KC_F6,   TO(0),
    //|--------+--------+--------+--------+|
          KC_F1,   KC_F2,   KC_F3,   TO(2),
    //|--------+--------+--------+--------+|
                  KC_F10,  KC_F11
    //|------------------------------------'
  ),
  [_FN2] = LAYOUT(
    //|------------------------------------'
        RGB_M_P, RGB_M_B, RGB_M_R, 
    //|--------+--------+--------+--------+|
        RGB_M_K,RGB_M_SW,RGB_M_SN,   TO(1),
    //|--------+--------+--------+--------+|
        RGB_M_X, RGB_M_G,RGB_M_TW,   TO(3),
    //|--------+--------+--------+--------+|
                 RGB_HUI, RGB_HUD
    //|------------------------------------'
  ),
  [_FN3] = LAYOUT(
    //|------------------------------------'
        QK_BOOT, KC_QUOT, KC_PSLS, 
    //|--------+--------+--------+--------+|
        KC_LPRN, KC_RPRN, KC_PAST,   TO(2),
    //|--------+--------+--------+--------+|
        KC_PDOT, KC_COMM, KC_PMNS,   TO(0),
    //|--------+--------+--------+--------+|
                  KC_EQL, KC_PPLS
    //|------------------------------------'
  )
};

// ***LED control***//
//RGBLayer setting
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 15, HSV_RED}
);

const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 15, HSV_BLUE}
);

const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 15, HSV_GREEN}
);

const rgblight_segment_t PROGMEM my_layerCL_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 15, HSV_YELLOW}
);

const rgblight_segment_t PROGMEM my_layerNL_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 15, HSV_MAGENTA}
);

const rgblight_segment_t PROGMEM my_layerBlink_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 15, HSV_WHITE}
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

// ***endoder control***//
// endoder setting
bool encoder_update_user(uint8_t index, bool clockwise) {
    keypos_t key;

    if (index == 0) { /* First encoder */
        if (clockwise) {
            key.row = 4;
            key.col = 0;
        } else {
            key.row = 4;
            key.col = 1;
        }
    } else if (index == 1) { /* Second encoder */
            if (clockwise) {
              key.row = 9;
              key.col = 0;
            } else {
              key.row = 9;
              key.col = 1;
            }
    } 
    action_exec((keyevent_t){.key = key, .pressed = true, .time = (timer_read() | 1)});
    action_exec((keyevent_t){.key = key, .pressed = false, .time = (timer_read() | 1)});
    return true;
}

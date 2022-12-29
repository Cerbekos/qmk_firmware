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

#define C_TAB MT(MOD_LCTL,KC_TAB)
#define S_SLSH MT(MOD_LSFT,KC_SLSH)
#define L3_SPC LT(3,KC_SPC)
#define G_DEL MT(MOD_LGUI,KC_DEL)
#define L1_ENT LT(1,KC_ENT)
#define L2_CAPS LT(2,KC_CAPS)
#define S_SCLN S(KC_SCLN)
#define TD_DOT TD(TD_DOT_CLN)
#define OLED_SW USER07

// ***tap dance***//
enum {
    TD_DOT_CLN
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_DOT_CLN]  = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_COLN)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    //|--------------------------------------------------------------+--------------------------------------------------------------------------------------------------'
         KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_UP,KC_RIGHT,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
          C_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G, KC_LEFT, KC_DOWN,    KC_H,    KC_J,    KC_K,    KC_L, KC_MINS, KC_QUOT,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,          KC_BTN1,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT,  S_SLSH,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        KC_LCTL,          KC_LALT,  L3_SPC,            G_DEL,          KC_BTN2, L2_CAPS,  L1_ENT, KC_SCLN,                     TG(2)
    //|--------------------------------------------------------------+--------------------------------------------------------------------------------------------------'
  ),
  [1] = LAYOUT(
    //|--------------------------------------------------------------+--------------------------------------------------------------------------------------------------'
        _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,   RESET,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        KC_LBRC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, _______, _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_RBRC,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        KC_LPRN, _______, _______, _______,  S_SCLN,  KC_EQL,          _______, KC_PPLS, KC_PMNS, KC_PAST, KC_PSLS, _______, KC_RPRN,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        _______,          _______, _______,          _______,          _______, _______, _______, _______,                   _______
    //|-------- -----------------------------------------------------+--------------------------------------------------------------------------------------------------'
  ),
  [2] = LAYOUT(
    //|--------------------------------------------------------------+--------------------------------------------------------------------------------------------------'
        _______, _______, KC_PSLS,   KC_P7,   KC_P8,   KC_P9, _______, _______, OLED_SW,  CPI_SW, SCRL_SW,  KC_EQL, KC_JYEN, _______,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        _______, _______, KC_PAST,   KC_P4,   KC_P5,   KC_P6, _______, _______, ROT_L15, ROT_R15, _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        _______, _______, KC_PMNS,   KC_P1,   KC_P2,   KC_P3,          _______, RGB_HUD, _______, RGB_HUI, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        _______,          KC_PPLS,   KC_P0,           TD_DOT,          _______,RGB_RMOD, RGB_TOG, RGB_MOD,                   _______
    //|-----------------------------------------------------------------------+-----------------------------------------------------------------------------------------'
  ),
  [3] = LAYOUT(
    //|--------------------------------------------------------------+--------------------------------------------------------------------------------------------------'
        _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, _______, _______, _______, KC_PGUP,   KC_UP, KC_PGDN, _______, _______,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        KC_LALT,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT,KC_BSPC, _______,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______,          _______, _______,  KC_END, _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        _______,          _______, _______,          _______,          _______, _______, _______, _______,                   _______
    //|--------------------------------------------------------------+--------------------------------------------------------------------------------------------------'
  ),
  };

// ***LED control***//
//RGBLayer setting
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 2, HSV_RED});
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 2, HSV_BLUE});
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 2, HSV_GREEN});
const rgblight_segment_t PROGMEM my_layerCL_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 2, HSV_YELLOW});


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

bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if(res) {
        //writePin(D2, !led_state.num_lock);
        rgblight_set_layer_state(0, led_state.caps_lock);
    }
    return res;
};

#ifdef OLED_ENABLE
bool CHG_OLED = false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case OLED_SW:
      if (record->event.pressed) {
        return false;
      } else {
        if (CHG_OLED) CHG_OLED = false;
        else CHG_OLED = true;
        }
    
    default:
      return true;
  }
};
bool oled_task_user(void) {
    if (CHG_OLED) oled_write_layer_state();
    else render_logo();
    return false;
}


#endif
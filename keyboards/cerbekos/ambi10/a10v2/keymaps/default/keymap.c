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

#define TD_DOT TD(TD_DOT_CLN)
#define TD_PLUS TD(TD_PLUS_PAST)
#define TD_PMNS TD(TD_PMNS_PSLS)

// ***tap dance***//
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

td_state_t cur_dance(tap_dance_state_t *state);

void dotcln_finished(tap_dance_state_t *state, void *user_data);
void dotcln_reset(tap_dance_state_t *state, void *user_data);
void plsast_finished(tap_dance_state_t *state, void *user_data);
void plsast_reset(tap_dance_state_t *state, void *user_data);
void mnssls_finished(tap_dance_state_t *state, void *user_data);
void mnssls_reset(tap_dance_state_t *state, void *user_data);
 
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KC_P7,   KC_P8,   KC_P9,
    KC_P4,   KC_P5,   KC_P6, TD_PMNS,
    KC_P1,   KC_P2,   KC_P3, TD_PLUS,
             KC_P0,   TD_DOT
  ),
  [1] = LAYOUT(
    KC_HOME, KC_UP,   KC_PGUP, 
    KC_LEFT, KC_PENT, KC_RGHT, KC_BSPC,
    KC_END,  KC_DOWN, KC_PGDN,  KC_ESC,
             KC_F10, XXXXXXX
  ),
  [2] = LAYOUT(
    KC_NUM,  _______, _______, 
    KC_TAB,  KC_CALC, _______, QK_BOOT,
    _______, KC_PENT, KC_COMM, XXXXXXX,
             _______, _______
  ),
  [3] = LAYOUT(
    _______, _______, _______, 
    _______, _______, _______, XXXXXXX,
    _______, RGB_HUI, RGB_HUD, RGB_TOG,
             RGB_MOD, RGB_RMOD                 
    )
};

//RGBLayer setting
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 15, HSV_RED});
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 15, HSV_BLUE});
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 15, HSV_GREEN});
const rgblight_segment_t PROGMEM my_layerCL_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 15, HSV_YELLOW});
const rgblight_segment_t PROGMEM my_layerNL_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 15, HSV_MAGENTA});
const rgblight_segment_t PROGMEM my_layerBlink_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 15, HSV_WHITE});

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

// ***tap dance***//
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }

    if (state->count == 2) return TD_DOUBLE_TAP;
    else return TD_UNKNOWN; 
}

// DOT,COLN
void dotcln_finished(tap_dance_state_t *state, void *user_data) {
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

void dotcln_reset(tap_dance_state_t *state, void *user_data) {
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
void plsast_finished(tap_dance_state_t *state, void *user_data) {
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

void plsast_reset(tap_dance_state_t *state, void *user_data) {
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
void mnssls_finished(tap_dance_state_t *state, void *user_data) {
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

void mnssls_reset(tap_dance_state_t *state, void *user_data) {
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

tap_dance_action_t tap_dance_actions[] = {
  [TD_DOT_CLN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dotcln_finished, dotcln_reset),
  [TD_PLUS_PAST] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, plsast_finished, plsast_reset),
  [TD_PMNS_PSLS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, mnssls_finished, mnssls_reset)
};
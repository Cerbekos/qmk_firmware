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

#define L1_ENT LT(1,KC_ENT)
#define L2_APP LT(2,KC_APP)
#define L3_SPC LT(3,KC_SPC)
#define S_SLSH MT(MOD_RSFT,KC_SLSH)

#define C_TAB MT(MOD_LCTL,KC_TAB)
#define S_SCLN S(KC_SCLN)
#define S_MINS S(KC_MINS) 
#define TD_DOT TD(TD_DOT_CLN)
#define TD_PLUS TD(TD_PLUS_PAST)
#define TD_PMNS TD(TD_PMNS_PSLS)

// ***tap dance***//
enum {
    TD_DOT_CLN,
    TD_PLUS_PAST,
    TD_PMNS_PSLS
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_DOT_CLN]  = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_COLN),
    [TD_PLUS_PAST]  = ACTION_TAP_DANCE_DOUBLE(KC_PLUS, KC_PAST),
    [TD_PMNS_PSLS]  = ACTION_TAP_DANCE_DOUBLE(KC_PMNS, KC_PSLS)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, KC_DEL,  KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
        C_TAB,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_MINS, KC_ENT,           KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   S_SLSH,  KC_P4,   KC_P5,   KC_P6,
        KC_LCTL, KC_LGUI,          KC_LALT, L3_SPC,           L1_ENT,  L2_APP,                   KC_LEFT, KC_DOWN, KC_RGHT, KC_P1,   KC_P2,   KC_P3,   L1_ENT, 
                                                    KC_CAPS,                                                                 KC_P0,            TD_DOT
    ),
    [1] = LAYOUT(
        _______, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), _______, _______, KC_CALC, _______, _______, KC_INT3,
        KC_LBRC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_RBRC,          KC_ESC,  _______, KC_BSPC, KC_RSFT,
        _______, _______, _______, _______, S_SCLN,  KC_EQL,  KC_PPLS, KC_PMNS, KC_PAST, KC_PSLS, _______, _______, _______, KC_TAB,  KC_EQL,  _______,
        _______, _______,          _______, _______,          _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
                                                    _______,                                                                 _______,          _______
    ),
    [2] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_HUI, _______, RGB_M_SW,RGB_M_K, RGB_M_TW,
        _______, _______,          _______, _______,          RGB_TOG, _______,                   RGB_MOD, RGB_HUD, RGB_RMOD,RGB_M_P, RGB_M_B, RGB_M_R, _______,
                                                     _______,                                                                _______,          _______
    ),
    [3] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, KC_PGUP, KC_UP,   KC_PGDN, KC_INT3, _______, _______, KC_CALC, _______, _______, KC_INT3,
        KC_LALT, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC, _______,          KC_ESC,  _______, KC_BSPC, KC_RSFT,
        _______, _______, _______, _______, _______, _______, _______,  KC_END, _______, KC_SCLN, KC_QUOT, KC_UP,   _______, KC_TAB,  KC_EQL,  _______,
        _______, _______,          _______, _______,          _______, _______,                   KC_HOME, KC_DOWN, KC_END,  _______, _______, _______, _______,
                                                     _______,                                                                _______,          _______
    )
};

// RGBLayer setting
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS({1, 1, HSV_RED});
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS({1, 1, HSV_BLUE});
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS({1, 1, HSV_GREEN});
const rgblight_segment_t PROGMEM my_layerCL_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_YELLOW});
const rgblight_segment_t PROGMEM my_layerNL_layer[] = RGBLIGHT_LAYER_SEGMENTS({2, 1, HSV_MAGENTA});

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
    
    return state;
};

// LockIndicator
bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if(res) {
        rgblight_set_layer_state(0, !led_state.num_lock);
        rgblight_set_layer_state(1, led_state.caps_lock);
    }
    return res;
};

// CAPS WORD Indicator
void caps_word_set_user(bool active) {
    if (active) {
        rgblight_set_layer_state(1, active);
    } else {
        rgblight_set_layer_state(1, active);
    }
}

// ENCODER
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_INT5, KC_INT4)},
    [1] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD)},
    [2] = { ENCODER_CCW_CW(RGB_HUI, RGB_HUD)},
    [3] = { ENCODER_CCW_CW(KC_VOLU,  KC_VOLD)},
};
#endif
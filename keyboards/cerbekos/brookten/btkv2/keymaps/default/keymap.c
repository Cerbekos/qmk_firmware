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
#define L2_MENU LT(2,KC_MENU)
#define L3_SPC LT(3,KC_SPC)
#define S_SLSH MT(MOD_RSFT,KC_SLSH)

#define C_CAPS MT(MOD_LCTL,KC_CAPS)
#define S_SCLN S(KC_SCLN)
#define S_MINS S(KC_MINS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, KC_DEL,  KC_NUM,  KC_PSLS, KC_PAST, KC_VOLU, KC_PMNS, KC_VOLD,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,          KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        C_CAPS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_SCLN, KC_QUOT, KC_H,    KC_J,    KC_K,    KC_L,    KC_MINS,                   KC_P4,   KC_P5,   KC_P6,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_UP,   KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  S_SLSH,                    KC_P1,   KC_P2,   KC_P3,    L1_ENT,
        KC_LCTL, KC_LGUI, KC_LALT, L3_SPC,           KC_LEFT, KC_DOWN, KC_RGHT, L1_ENT,  L2_MENU, KC_RGUI, KC_RCTL,                            KC_P0,            KC_PDOT           
    ),
    [1] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,  KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, _______, _______, _______, _______, _______, QK_BOOT, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, KC_BSPC,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,  KC_EQL,  S_SCLN,
        _______, _______, _______, _______, _______, _______, KC_PGUP, _______, _______, _______, _______, _______, _______,                   _______, _______,  S_MINS, _______,
        _______, _______, _______, _______,          KC_HOME, KC_PGDN, KC_END,  _______, _______, _______, _______,                            _______,          KC_COMM          
    ),
    [2] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______,
        _______, _______, _______, _______, _______, _______, RGB_HUI, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______,
        _______, _______, _______, _______,          RGB_MOD, RGB_HUD,RGB_RMOD, _______, _______, _______, _______,                            _______,          _______
    ),
    [3] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,  KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   KC_UP, _______, _______, _______,          _______, _______, _______, _______,
        _______, _______, _______, _______, _______,  KC_F10, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC,                   _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_PGUP, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______,
        _______, _______, _______, _______,          KC_HOME, KC_PGDN, KC_END,  _______, _______, _______, _______,                            _______,          _______
    )
};

// RGBLayer setting
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS({1, 5, HSV_RED});
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS({1, 5, HSV_BLUE});
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS({1, 5, HSV_GREEN});
const rgblight_segment_t PROGMEM my_layerCL_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_YELLOW});
const rgblight_segment_t PROGMEM my_layerNL_layer[] = RGBLIGHT_LAYER_SEGMENTS({6, 1, HSV_MAGENTA});

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
        rgblight_set_layer_state(0, led_state.num_lock);
        rgblight_set_layer_state(1, led_state.caps_lock);
    }
    return res;
};

// endoder setting
bool encoder_update_user(uint8_t index, bool clockwise) {
    keypos_t key;

    if (index == 0) { /* First encoder */
        if (clockwise) {
            key.row = 13;
            key.col = 1;
        } else {
            key.row = 13;
            key.col = 2;
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            key.row = 13;
            key.col = 1;
        } else {
            key.row = 13;
            key.col = 2;
        } 
    }
    action_exec((keyevent_t){.key = key, .pressed = true, .time = (timer_read() | 1)});
    action_exec((keyevent_t){.key = key, .pressed = false, .time = (timer_read() | 1)});
    return true;
};


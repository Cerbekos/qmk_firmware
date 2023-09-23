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
#define L2_DEL LT(2,KC_DEL)
#define L3_SPC LT(3,KC_SPC)
#define S_SLSH MT(MOD_RSFT,KC_SLSH)

#define C_TAB MT(MOD_LCTL,KC_TAB)
#define S_SCLN S(KC_SCLN)
#define S_MINS S(KC_MINS) 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        C_TAB,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_MINS, KC_BSPC,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  S_SLSH,
                 KC_LGUI, KC_LALT, L3_SPC,  L2_DEL,           L1_ENT,  KC_SCLN, KC_RO
    ),
    [1] = LAYOUT(
        _______, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), _______,
        KC_LBRC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_RBRC,
        KC_LSPO, _______, _______, _______, S_SCLN,  KC_EQL,  KC_PPLS, KC_PMNS, KC_PAST, KC_PSLS, KC_RSPC,
                 _______, _______, _______, _______,          _______, _______, _______
    ),
    [2] = LAYOUT(
        QK_BOOT, _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_JYEN, _______,
        KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, KC_SCLN, KC_QUOT, KC_NUHS,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_RO,
                 _______, _______, _______, _______,          _______, _______, _______
    ),
    [3] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_INS, KC_PGUP, KC_UP,   KC_PGDN, _______, _______,
        KC_LALT, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC, _______,
        _______, KC_F11,  KC_F12,  KC_PSCR, KC_SLCK, KC_PAUS, KC_END,  _______, _______, _______, _______,
                 _______, _______, _______, _______,          _______, _______, _______
    )
};

// RGBLayer setting
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS({1, 1, HSV_RED});
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS({1, 1, HSV_BLUE});
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS({1, 1, HSV_GREEN});
const rgblight_segment_t PROGMEM my_layerCL_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_YELLOW});
const rgblight_segment_t PROGMEM my_layerNL_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_MAGENTA});
const rgblight_segment_t PROGMEM my_layerIOFF_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_OFF});
const rgblight_segment_t PROGMEM my_layerLOFF_layer[] = RGBLIGHT_LAYER_SEGMENTS({1, 1, HSV_OFF});

const rgblight_segment_t * const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_layerNL_layer,
    my_layerCL_layer,
    my_layer3_layer,
    my_layer2_layer,
    my_layer1_layer,
    my_layerIOFF_layer,
    my_layerLOFF_layer
);

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
    rgblight_sethsv_noeeprom(0, 0, 0);
};

// LayerIndicator 
layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(6, layer_state_cmp(state, 0));
    rgblight_set_layer_state(4, layer_state_cmp(state, 1));
    rgblight_set_layer_state(3, layer_state_cmp(state, 2));
    rgblight_set_layer_state(2, layer_state_cmp(state, 3));

    return state;
};

// LockIndicator
bool led_update_user(led_t led_state) {
    //rgblight_set_layer_state(0, led_state.num_lock);
    rgblight_set_layer_state(1, led_state.caps_lock);
    return true;
};

//CAPS WORD
void caps_word_set_user(bool active) {
    if (active) {
        rgblight_sethsv_range(HSV_YELLOW, 0, 1);
    } else {
        rgblight_sethsv_range(HSV_OFF, 0, 1);
    }
}
/*
Copyright 2021 Salicylic_Acid

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
enum layer_number {
  _QWERTY = 0,
  _FN,
  _FN2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    //|--------------------------------------------------------------+--------------------------------------------------------------------------------------------------'
        KC_GESC,  KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_P7,   KC_P8,   KC_P9,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,KC_SCLN,  KC_BSPC,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
      A(KC_TAB), KC_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_P4,   KC_P5,   KC_P6, KC_COMM,    KC_H,    KC_J,    KC_K,    KC_L, KC_MINS,      KC_ENT,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
                 KC_LSPO,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_P1,   KC_P2,   KC_P3,  KC_DOT,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSPC,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
                 KC_LCTL,          KC_LALT,    LT(2,KC_SPC),  KC_LGUI,            KC_P0,LT(1,KC_SPC),             LT(1,KC_ENT),        KC_APP,              LT(2,KC_DEL)
    //|--------------------------------------------------------------+--------------------------------------------------------------------------------------------------'
  ),
  [_FN] = LAYOUT(
    //|--------------------------------------------------------------+--------------------------------------------------------------------------------------------------'
        _______, _______, _______,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F7,   KC_F8,   KC_F9,          _______, KC_PGUP,   KC_UP, KC_PGDN, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        _______, KC_LALT,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,   KC_F4,   KC_F5,   KC_F6, KC_CAPS, KC_HOME, KC_LEFT, KC_DOWN,KC_RIGHT,  KC_BSPC,     _______,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
                 _______, _______, _______, _______, _______,  KC_DEL,   KC_F1,   KC_F2,   KC_F3, KC_NLCK, _______,  KC_END, _______, _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
                 _______,          _______,          _______, _______,           KC_F10, KC_CALC,                   _______,          _______,               _______
    //|-------- -----------------------------------------------------+--------------------------------------------------------------------------------------------------'
  ),
  [_FN2] = LAYOUT(
    //|--------------------------------------------------------------+--------------------------------------------------------------------------------------------------'
        KC_VOLU, KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,  KC_TAB,  KC_ESC, KC_BSLS,          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS, _______,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        KC_VOLD, _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_PSLS, KC_PAST, KC_PMNS,  KC_DEL,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     _______,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
                 KC_LBRC, _______, _______, _______, _______, _______, KC_COLN,  KC_EQL, KC_PLUS, KC_BSPC, KC_PSLS, KC_COLN, _______, _______, _______, _______, KC_RBRC,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
                 _______,          _______,          _______, _______,          KC_PERC,  KC_ENT,                  _______,           _______,               _______
    //|-----------------------------------------------------------------------+-----------------------------------------------------------------------------------------'
  )
};

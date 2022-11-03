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
#include "keymap_japanese.h"

//tapdance
enum {
    TD_SPC_ENT
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_SPC_ENT]  = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_ENT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    //|-----------------------------------------------------------------------+--------------------------------------------'
           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,RGUI_T(KC_UP),LCTL_T(KC_RIGHT),KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
           KC_A,    KC_S,    KC_D,    KC_F,    KC_G,LALT_T(KC_LEFT), LSFT_T(KC_DOWN),LT(1,KC_ENT), KC_H, KC_J,  KC_K,  KC_L, TD(TD_SPC_ENT),
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
           KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        LT(2,KC_SPC),          KC_B,    KC_N,    KC_M, KC_COMM,RSFT_T(KC_DOT)
    //|-----------------------------------------------------------------------+--------------------------------------------'
  ),
  [1] = LAYOUT(
    //|-----------------------------------------------------------------------+--------------------------------------------'
        KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_PGUP,  KC_END,          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        KC_CAPS, _______, _______, _______, _______, KC_HOME, KC_PGDN, _______, _______, _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        C(KC_Z), C(KC_X), C(KC_C), C(KC_V),  KC_EQL,            TG(3),          RGB_TOG, RGB_MOD,RGB_RMOD, RGB_HUI, RGB_HUD
    //|-----------------------------------------------------------------------+--------------------------------------------'
  ),
  [2] = LAYOUT(
    //|-----------------------------------------------------------------------+--------------------------------------------'
        KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,  KC_ESC,  KC_DEL,          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______,  KC_TAB, KC_BSPC,   TG(3), _______, _______, KC_LBRC, KC_RBRC, KC_BSLS,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______,          _______,          _______, _______, KC_SCLN, KC_QUOT, KC_SLSH
    //|-----------------------------------------------------------------------+--------------------------------------------'
  ),
  [3] = LAYOUT(
    //|-----------------------------------------------------------------------+--------------------------------------------'
          KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_PPLS, KC_PMNS,            KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
           KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_PAST, KC_PSLS,   TG(3),    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        C(KC_Z), C(KC_X), C(KC_C), C(KC_V),  KC_EQL,            TG(3),          KC_PSLS, KC_COLN,   RESET, KC_COMM,  KC_DOT
    //|-----------------------------------------------------------------------+--------------------------------------------'
  )
};

//LED Options
//LayerIndicator
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {3, 6, HSV_RED}
);

const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {3, 6, HSV_BLUE}
);

const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {3, 6, HSV_GREEN}
);

//led indicators
const rgblight_segment_t PROGMEM my_layerCL_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {3, 6, HSV_YELLOW}
);

const rgblight_segment_t * const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
  my_layerCL_layer,
  my_layer3_layer,
  my_layer2_layer,
  my_layer1_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
};

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(3, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    rgblight_set_layer_state(1, layer_state_cmp(state, 3));
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

//combo
enum combos {
  ZX_CUT,
  ZC_COPY,
  ZV_PAST,
  CS_SAVE,
  CA_ALLS,
  CF_FIND,
  CZ_UNDO,
  WE_EXPL,
  WD_DTOP,
  WV_CLIP,
  WT_WTAB,
  AT_ATAB,
  CT_EISU
};

const uint16_t PROGMEM zx_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM zc_combo[] = {KC_Z, KC_C, COMBO_END};
const uint16_t PROGMEM zv_combo[] = {KC_Z, KC_V, COMBO_END};
const uint16_t PROGMEM cs_combo[] = {KC_C, KC_S, COMBO_END};
const uint16_t PROGMEM ca_combo[] = {KC_C, KC_A, COMBO_END};
const uint16_t PROGMEM cf_combo[] = {KC_C, KC_F, COMBO_END};
const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM wd_combo[] = {KC_W, KC_D, COMBO_END};
const uint16_t PROGMEM wv_combo[] = {KC_W, KC_V, COMBO_END};
const uint16_t PROGMEM wt_combo[] = {KC_W, KC_T, COMBO_END};
const uint16_t PROGMEM at_combo[] = {KC_A, KC_T, COMBO_END};
const uint16_t PROGMEM ct_combo[] = {KC_C, KC_T, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [ZX_CUT] = COMBO(zx_combo, C(KC_X)),
  [ZC_COPY] = COMBO(zc_combo, C(KC_C)),
  [ZV_PAST] = COMBO(zv_combo, C(KC_V)),
  [CS_SAVE] = COMBO(cs_combo, C(KC_S)),
  [CA_ALLS] = COMBO(ca_combo, C(KC_A)),
  [CF_FIND] = COMBO(cf_combo, C(KC_F)),
  [WE_EXPL] = COMBO(we_combo, G(KC_E)),
  [WD_DTOP] = COMBO(wd_combo, G(KC_D)),
  [WV_CLIP] = COMBO(wv_combo, G(KC_V)),
  [WT_WTAB] = COMBO(wt_combo, G(KC_TAB)),
  [AT_ATAB] = COMBO(at_combo, A(KC_TAB)),
  [CT_EISU] = COMBO(ct_combo, C(KC_T))
};

// combo switching
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_F19:
      if (record->event.pressed) {
        return false;
      } else {
        tap_code16(CMB_TOG);
        rgblight_blink_layer_repeat(3, 200, 2);
      }
    default:
      return true;
    }
  };


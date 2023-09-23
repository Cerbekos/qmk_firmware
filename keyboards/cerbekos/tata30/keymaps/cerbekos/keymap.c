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
#include "quantum.h"  
#include <stdio.h>

/* tap dance */
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Tap dance enums
enum {
    SpcL1Ent,
    EscCtrQ,
    ComCtrScl,
    DotSftSls,
    PL2Min,
};

td_state_t cur_dance(tap_dance_state_t *state);

// For the x tap dance. Put it here so it can be used in any keymap
void SpcL1Ent_finished(tap_dance_state_t *state, void *user_data);
void SpcL1Ent_reset(tap_dance_state_t *state, void *user_data);
void EscCtrQ_finished(tap_dance_state_t *state, void *user_data);
void EscCtrQ_reset(tap_dance_state_t *state, void *user_data);
void ComCtrScl_finished(tap_dance_state_t *state, void *user_data);
void ComCtrScl_reset(tap_dance_state_t *state, void *user_data);
void DotSftSls_finished(tap_dance_state_t *state, void *user_data);
void DotSftSls_reset(tap_dance_state_t *state, void *user_data);
void PL2Min_finished(tap_dance_state_t *state, void *user_data);
void PL2Min_reset(tap_dance_state_t *state, void *user_data);


/* keymap */
#define MS_DOT MT(MOD_RSFT,KC_DOT)
#define MS_Z MT(MOD_LSFT,KC_Z)
#define MA_X MT(MOD_LALT,KC_X)
#define MG_V MT(MOD_LGUI,KC_V)

#define MS_EQL MT(MOD_LSFT,KC_EQL)
#define MA_PPLS MT(MOD_LALT,KC_PPLS)
#define MG_PAST MT(MOD_LGUI,KC_PAST)

#define L1_SPC LT(1,KC_SPC)
#define L2_P LT(2,KC_P)
#define L3_L LT(3,KC_L)

#define S_SLSH S(KC_SLSH)
#define S_SCLN S(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        TD(EscCtrQ),KC_W, KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    TD(PL2Min),
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    L3_L, TD(SpcL1Ent),
        MS_Z,    MA_X,    KC_C,    MG_V,    KC_B,    KC_F24,  KC_N,    KC_M,    TD(ComCtrScl), TD(DotSftSls) 
    ),
    [1] = LAYOUT(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_END,  KC_PGUP, KC_UP,   KC_PGDN, _______,
        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,             KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, _______,
        MS_EQL,  MA_PPLS, KC_PMNS, MG_PAST, KC_PSLS, DT_PRNT, KC_BSPC, KC_DEL,  S(KC_TAB),  KC_TAB
    ),
    [2] = LAYOUT(
        S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),          KC_SLSH, S_SLSH,  KC_INT3, _______, _______,
        S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0),          KC_LBRC, KC_RBRC, KC_BSLS, _______, _______,
        KC_LSFT, KC_CAPS, _______, _______, _______, QK_BOOT, KC_APP,  KC_SLSH, _______, _______
    ),
    [3] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,            KC_SCLN, KC_QUOT, KC_NUHS, _______, _______,
        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,           KC_MINS, KC_TAB,  KC_ESC, _______, _______,
        KC_LSFT, KC_F11,  KC_PSCR, KC_SCRL, KC_PAUS, DT_PRNT, KC_F24,  _______, _______, _______
    )
};

// RGBLayer setting
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_RED});
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_BLUE});
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_GREEN});
const rgblight_segment_t PROGMEM my_layerCL_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_YELLOW});
const rgblight_segment_t PROGMEM my_layerNL_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_MAGENTA});
const rgblight_segment_t PROGMEM my_layerOFF_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_OFF});

const rgblight_segment_t * const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_layerNL_layer,
    my_layerCL_layer,
    my_layer3_layer,
    my_layer2_layer,
    my_layer1_layer,
    my_layerOFF_layer
);

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
    rgblight_sethsv_noeeprom(0, 0, 0);
};

// LayerIndicator 
layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(5, layer_state_cmp(state, 0));
    rgblight_set_layer_state(4, layer_state_cmp(state, 1));
    rgblight_set_layer_state(3, layer_state_cmp(state, 2));
    rgblight_set_layer_state(2, layer_state_cmp(state, 3));

    return state;
};

// LockIndicator
bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(1, led_state.caps_lock);
    return true;
};

// CAPS WORD Indicator
void caps_word_set_user(bool active) {
    if (active) {
        rgblight_sethsv_range(HSV_YELLOW, 0, 1);

    } else {
        rgblight_sethsv_range(HSV_OFF, 0, 1);
    }
}

// ENCODER
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_INT5, KC_INT4)},
    [1] = { ENCODER_CCW_CW(KC_TAB,  S(KC_TAB))},
    [2] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [3] = { ENCODER_CCW_CW(DT_UP, DT_DOWN)},
};
#endif


// TAP DANCE
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

//SpcL1Ent
static td_tap_t SpcL1Ent_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void SpcL1Ent_finished(tap_dance_state_t *state, void *user_data) {
    SpcL1Ent_tap_state.state = cur_dance(state);
    switch (SpcL1Ent_tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_SPC); break;
        case TD_SINGLE_HOLD: layer_on(1); break;
        case TD_DOUBLE_TAP: register_code(KC_ENT); break;
        case TD_DOUBLE_HOLD: register_code(KC_LSFT); break;
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_SPC); register_code(KC_SPC); break;
        default: break;
    }
}

void SpcL1Ent_reset(tap_dance_state_t *state, void *user_data) {
    switch (SpcL1Ent_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_SPC); break;
        case TD_SINGLE_HOLD: layer_off(1); break;
        case TD_DOUBLE_TAP: unregister_code(KC_ENT); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_LSFT); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_SPC); break;
        default: break;
    }
    SpcL1Ent_tap_state.state = TD_NONE;
}

//EscCtrQ
static td_tap_t EscCtrQ_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void EscCtrQ_finished(tap_dance_state_t *state, void *user_data) {
    EscCtrQ_tap_state.state = cur_dance(state);
    switch (EscCtrQ_tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_Q); break;
        case TD_SINGLE_HOLD: register_code(KC_LCTL); break;
        case TD_DOUBLE_TAP: register_code(KC_ESC); break;
        case TD_DOUBLE_HOLD: caps_word_on(); break;
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_Q); register_code(KC_Q); break;
        default: break;
    }
}

void EscCtrQ_reset(tap_dance_state_t *state, void *user_data) {
    switch (EscCtrQ_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_Q); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LCTL); break;
        case TD_DOUBLE_TAP: unregister_code(KC_ESC); break;
        case TD_DOUBLE_HOLD: break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_Q); break;
        default: break;
    }
    EscCtrQ_tap_state.state = TD_NONE;
}

//ComCtrScl
static td_tap_t ComCtrScl_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void ComCtrScl_finished(tap_dance_state_t *state, void *user_data) {
    ComCtrScl_tap_state.state = cur_dance(state);
    switch (ComCtrScl_tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_COMM); break;
        case TD_SINGLE_HOLD: register_code(KC_RCTL); break;
        case TD_DOUBLE_TAP: register_code(KC_SCLN); break;
        case TD_DOUBLE_HOLD: register_code(KC_SCLN); break;
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_COMM); register_code(KC_COMM); break;
        default: break;
    }
}

void ComCtrScl_reset(tap_dance_state_t *state, void *user_data) {
    switch (ComCtrScl_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_COMM); break;
        case TD_SINGLE_HOLD: unregister_code(KC_RCTL); break;
        case TD_DOUBLE_TAP: unregister_code(KC_SCLN); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_SCLN); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_COMM); break;
        default: break;
    }
    ComCtrScl_tap_state.state = TD_NONE;
}

//DotSftSls
static td_tap_t DotSftSls_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void DotSftSls_finished(tap_dance_state_t *state, void *user_data) {
    DotSftSls_tap_state.state = cur_dance(state);
    switch (DotSftSls_tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_DOT); break;
        case TD_SINGLE_HOLD: register_code(KC_RSFT); break;
        case TD_DOUBLE_TAP: register_code(KC_SLSH); break;
        case TD_DOUBLE_HOLD: register_code(KC_SLSH); break;
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_DOT); register_code(KC_DOT); break;
        default: break;
    }
}

void DotSftSls_reset(tap_dance_state_t *state, void *user_data) {
    switch (DotSftSls_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_DOT); break;
        case TD_SINGLE_HOLD: unregister_code(KC_RSFT); break;
        case TD_DOUBLE_TAP: unregister_code(KC_SLSH); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_SLSH); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_DOT); break;
        default: break;
    }
    DotSftSls_tap_state.state = TD_NONE;
}

//PL2Min
static td_tap_t PL2Min_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void PL2Min_finished(tap_dance_state_t *state, void *user_data) {
    PL2Min_tap_state.state = cur_dance(state);
    switch (PL2Min_tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_P); break;
        case TD_SINGLE_HOLD: layer_on(2); break;
        case TD_DOUBLE_TAP: register_code(KC_MINS); break;
        case TD_DOUBLE_HOLD: register_code(KC_MINS); break;
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_P); register_code(KC_P); break;
        default: break;
    }
}

void PL2Min_reset(tap_dance_state_t *state, void *user_data) {
    switch (PL2Min_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_P); break;
        case TD_SINGLE_HOLD: layer_off(2); break;
        case TD_DOUBLE_TAP: unregister_code(KC_MINS); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_MINS); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_P); break;
        default: break;
    }
    PL2Min_tap_state.state = TD_NONE;
}

//tap_dance_actions
tap_dance_action_t tap_dance_actions [] = {
    [SpcL1Ent] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, SpcL1Ent_finished, SpcL1Ent_reset),
    [EscCtrQ] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, EscCtrQ_finished, EscCtrQ_reset),
    [ComCtrScl] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ComCtrScl_finished, ComCtrScl_reset),
    [DotSftSls] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, DotSftSls_finished, DotSftSls_reset),
    [PL2Min] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, PL2Min_finished, PL2Min_reset)
};

/*
// Tapping Term ajustment
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD(SpcL1Ent):
            return 200;
        case TD(EscCtrQ):
            return 200;
        case TD(ComCtrScl):
            return 200;
        case TD(DotSftSls):
            return 200;
        case TD(PL2Min):
            return 200;
        default:
            return TAPPING_TERM;
    }
}
*/

// OLED
#ifdef OLED_ENABLE
oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

static const char PROGMEM tata30_logo[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xfc, 0x0e, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xfc, 0xd8, 0xe0, 0xf0, 0x70, 0x38, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xfe, 0xf0, 0xe0, 0xc0, 
    0x80, 0x00, 0x00, 0x80, 0x40, 0x29, 0x1f, 0xff, 0x1f, 0x0f, 0x08, 0x02, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x81, 0x83, 0x8f, 0x8f, 0x1f, 0x1f, 0xbf, 
    0x3f, 0x3f, 0xbf, 0xbe, 0xbe, 0xbe, 0xbe, 0x1e, 0x1c, 0x8e, 0x06, 0x02, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x1f, 0x00, 0x00, 0x18, 0xc7, 0x01, 
    0xc7, 0x98, 0x00, 0x00, 0x9f, 0x40, 0x40, 0x98, 0x0e, 0x01, 0x07, 0x1c, 0x10, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x12, 
    0x13, 0x0c, 0x00, 0x07, 0x0f, 0x10, 0x10, 0x0f, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static unsigned int type_count = 0;
void count_type(void) {
    type_count++;
}

void oled_write_type_count(void) {
    static char type_count_str[7];
    oled_write_P(PSTR("Type:"), false);
    itoa(type_count, type_count_str, 10);
    oled_write_ln(type_count_str, false);
}

bool oled_task_user(void) {

    // lender logo
    oled_set_cursor(0, 1);
    oled_write_raw_P(tata30_logo, sizeof(tata30_logo));
    
    // Host Keyboard Layer Status
    oled_set_cursor(0, 7);
    oled_write_P(PSTR("Lay:"), false);

    switch (get_highest_layer(layer_state)) {
        case 1:
            oled_write_P(PSTR("1"), false);
            break;
        case 2:
            oled_write_P(PSTR("2"), false);
            break;
        case 3:
            oled_write_P(PSTR("3"), false);
            break;
        default:
            oled_write_ln_P(PSTR("0"), false);
    }

    // Host Keyboard LED Status 
    uint8_t mod_state;
    mod_state = get_mods();
    oled_set_cursor(0, 9);
    oled_write_P((mod_state & MOD_MASK_CTRL) ? PSTR("C") : PSTR(" "), false);
    oled_write_P((mod_state & MOD_MASK_SHIFT) ? PSTR("S") : PSTR(" "), false);
    oled_write_P((mod_state & MOD_MASK_ALT) ? PSTR("A") : PSTR(" "), false);
    oled_write_P((mod_state & MOD_MASK_GUI) ? PSTR("G") : PSTR(" "), false);
    oled_write_P((is_caps_word_on()) ? PSTR("W") : PSTR(" "), false);
    
    // type counat
    oled_set_cursor(0, 11);
    oled_write_type_count();
    // tapping term
    oled_set_cursor(0, 14);
    oled_write_P(PSTR("Term:"), false);
    char buf1[6];
    snprintf(buf1, 6, "%3d", g_tapping_term); 
    oled_write(buf1, false);

    return false;
}
#endif

// Keep mod
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    if (record->event.pressed) {
        count_type();

        uint8_t mod_state;
        mod_state = get_mods();
        
        switch (keycode) {
        // capsword mode switching
        case KC_F23:
            if (mod_state & MOD_MASK_CTRL) {
                del_mods(MOD_MASK_CTRL);
            } else {
                add_mods(MOD_MASK_CTRL);
            } 
            return false;
        case KC_F22:
            if (mod_state & MOD_MASK_SHIFT) {
                del_mods(MOD_MASK_SHIFT);
            } else {
                add_mods(MOD_MASK_SHIFT);
            } 
            return false;
        default:
            return true;
        }

    } else  {
        switch (keycode) {
        // capsword mode switching
        case KC_F24:
            if (is_caps_word_on()) {
                caps_word_off();
            } else {
                caps_word_on();
            }
            return false;
        default:
            return true;
        }
        
    }
}

// CAPS WORD
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case TD(PL2Min):
        case TD(ComCtrScl):
        case TD(DotSftSls):
        case TD(SpcL1Ent):
        case TD(EscCtrQ):
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

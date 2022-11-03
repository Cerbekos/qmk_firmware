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
#pragma once

#include "quantum.h"

#define LAYOUT( \
    L00, L01, L02, L03, L04, L05,  L06, R00,  R01, R02, R03, R04, R05, R06, \
    L10, L11, L12, L13, L14, L15,  L16, R10,  R11, R12, R13, R14, R15, R16, \
    L20, L21, L22, L23, L24, L25,       R20,  R21, R22, R23, R24, R25, R26, \
    L30,      L32, L33,      L35,       R30,  R31, R32,      R34,      R36 \
  ) \
  { \
    { L00,   L01,   L02,   L03,   L04,   L05,   L06 }, \
    { L10,   L11,   L12,   L13,   L14,   L15,   L16 }, \
    { L20,   L21,   L22,   L23,   L24,   L25, KC_NO }, \
    { L30, KC_NO,   L32,   L33, KC_NO,   L35, KC_NO }, \
    { R00,   R01,   R02,   R03,   R04,   R05,   R06 }, \
    { R10,   R11,   R12,   R13,   R14,   R15,   R16 }, \
    { R20,   R21,   R22,   R23,   R24,   R25,   R26 }, \
    { R30,   R31,   R32, KC_NO,   R34, KC_NO,   R36 } \
  }

/*******************************************/
/***** Trackball_module by aki27 start *****/
/*******************************************/

typedef union {
    uint32_t raw;
    struct {
        uint8_t cpi_idx;
        uint8_t scrl_div;
        uint8_t rotation_angle;
        int8_t scrl_inv;
        bool scrl_mode;
        report_mouse_t last_mouse;
    };
} cocot_config_t;



extern cocot_config_t cocot_config;

enum cocot_keycodes {

    COCOT_SAFE_RANGE = SAFE_RANGE,
    CPI_SW,
    SCRL_SW,
    ROT_R15,
    ROT_L15,
    SCRL_MO,
    SCRL_TO,
    SCRL_IN,

};

bool cocot_get_scroll_mode(void);
void cocot_set_scroll_mode(bool mode);

void render_logo(void);
void oled_write_layer_state(void);

/*******************************************/
/***** Trackball_module by aki27 end *******/
/*******************************************/

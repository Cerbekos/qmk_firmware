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
#include "agv2s.h"

#include "quantum.h"
#include <math.h>
#include "wait.h"
#include "debug.h"
#include <stdio.h>

// OLED utility
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

void oled_write_layer_state(void) {

    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case 0:
            oled_write_P(PSTR("0\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("1\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("2\n"), false);
            break;
        case 3:
            oled_write_P(PSTR("3\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undef\n"), false);
            break;
    }

    char buf4[6];
    char buf5[6];
    snprintf(buf4,6,"%3d",rgblight_get_mode());
    snprintf(buf5,6,"%3d",rgblight_get_hue());
    oled_write_P(PSTR("RGB:"), false);
    oled_write(buf4, false);
    oled_write_P(PSTR("/HUE:"), false);
    oled_write(buf5, false);

}

static const char PROGMEM qmk_logo[] = {
    0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
    0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
    0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 
    0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00};

void render_logo(void) {
    oled_write_P(qmk_logo, false);
};
#endif
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

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x7110
#define PRODUCT_ID      0x1043
#define DEVICE_VER      0x0001
#define MANUFACTURER    Cerbekos
#define PRODUCT         Ambi_GL

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 7

// wiring of each half
#define MATRIX_ROW_PINS { D7, E6, B4, B5 }
#define MATRIX_COL_PINS { F4, F5, F6, F7, B1, B3, B2}

// DIODE_DIRECTION
//#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#undef LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#undef LOCKING_RESYNC_ENABLE

/* LAYER */
#define LAYER_STATE_8BIT

/* ws2812 RGB LED */
#define RGB_DI_PIN D3

#ifndef RGBLED_NUM
  #define RGBLED_NUM 2
  #define RGBLIGHT_LED_MAP {0,1}
#endif

/* RGB ANIMATION */
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_TWINKLE

/* RGB LIGHT SETTING */
#define RGBLIGHT_LIMIT_VAL 128
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_SLEEP
#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
#define RGBLIGHT_LAYER_BLINK

/* TAP DANCE */
//#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 200

/* POINTING_DEVICE */
#define ADNS5050_SCLK_PIN         D4
#define ADNS5050_SDIO_PIN         D2
#define ADNS5050_CS_PIN           C6

#define POINTING_DEVICE_ROTATION_180

/* OLED */
#define OLED_FONT_H "keyboards/cerbekos/ambigl/agv2t/lib/glcdfont.c"

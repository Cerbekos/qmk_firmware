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
#define PRODUCT_ID      0x1045
#define DEVICE_VER      0x0001
#define MANUFACTURER    Cerbekos
#define PRODUCT         BROOKTEN

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 12

// wiring of each half  
#define MATRIX_ROW_PINS { D1, D0, D4, C6 }
#define MATRIX_COL_PINS { F4, F5, F6, F7, B1, B3, F4, F5, F6, F7, B1, B3 }
#define UNUSED_PINS

#define DIODE_DIRECTION CUSTOM_MATRIX

// split keyboard option
#define SOFT_SERIAL_PIN D2
#define MASTER_RIGHT 

/* use sym_eager_pk */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* ws2812 RGB LED */
#define RGB_DI_PIN D3
#define RGBLED_SPLIT { 5, 2 }
#define SPLIT_LAYER_STATE_ENABLE

#ifndef RGBLED_NUM
  #define RGBLED_NUM 7
  #define RGBLIGHT_LED_MAP {0,1,2,3,4,5,6}
#endif

#define RGBLIGHT_ANIMATIONS

#ifndef IOS_DEVICE_ENABLE
  #define RGBLIGHT_LIMIT_VAL 119
  #define RGBLIGHT_VAL_STEP 17
#else
  #define RGBLIGHT_LIMIT_VAL 30
  #define RGBLIGHT_VAL_STEP 4
#endif
#define RGBLIGHT_HUE_STEP 5
#define RGBLIGHT_SAT_STEP 5

#if defined(RGBLIGHT_ENABLE) && !defined(IOS_DEVICE_ENABLE)
  #define USB_MAX_POWER_CONSUMPTION 400
#else
  #define USB_MAX_POWER_CONSUMPTION 100
#endif

#define RGBLIGHT_SLEEP
#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF


// Encoders option
#define ENCODERS_PAD_A { B5, D7 }
#define ENCODERS_PAD_B { B4, E6 }
#define ENCODERS_PAD_A_RIGHT { B4 }
#define ENCODERS_PAD_B_RIGHT { B5 }
#define ENCODER_RESOLUTION 4

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
#define PRODUCT_ID      0x1048
#define DEVICE_VER      0x0001
#define MANUFACTURER    Cerbekos
#define PRODUCT         Tenalice_ambidextrous_V3

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 8

// wiring of each half
#define MATRIX_ROW_PINS { GP28, GP29, GP6, GP7, GP0, GP3, GP4, GP2, GP1 }
#define MATRIX_COL_PINS { GP28, GP29, GP6, GP7, GP0, GP3, GP4, GP2, GP1 }

#define DIODE_DIRECTION COL2ROW

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* ws2812 RGB LED */
#define RGB_DI_PIN GP26

#ifndef RGBLED_NUM
  #define RGBLED_NUM 25
  #define RGBLIGHT_LED_MAP {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,18,19,23,22,25,24,21,20,16,17}
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
#define RGBLIGHT_LAYER_BLINK

/* RP2040 */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP27
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U
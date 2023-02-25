// Copyright 2023 cerbekos (@cerbekos)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#define MATRIX_MASKED

//#define BOOTMAGIC_LITE_ROW 0
//#define BOOTMAGIC_LITE_COLUMN 1

/* IF MASTER RIGHT */
#define MASTER_RIGHT
#define BOOTMAGIC_LITE_ROW 9
#define BOOTMAGIC_LITE_COLUMN 1
#define RGBLIGHT_LED_MAP { 6,0,1,2,3,4,5 }

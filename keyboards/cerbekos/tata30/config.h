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

#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 1

#define HAL_USE_I2C TRUE
#define I2C1_SDA_PIN GP6
#define I2C1_SCL_PIN GP7

#define TAPPING_TERM_PER_KEY

#define ENCODER_DEFAULT_POS 0x3

#define WS2812_DI_PIN GP3
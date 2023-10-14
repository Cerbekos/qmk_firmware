// Copyright 2022 cerbekos (@cerbekos)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

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

/* POINTING_DEVICE */
#define ADNS5050_SCLK_PIN         D4
#define ADNS5050_SDIO_PIN         D2
#define ADNS5050_CS_PIN           C6

#define POINTING_DEVICE_ROTATION_180

/* OLED */
#define OLED_FONT_H "keyboards/cerbekos/tellesgl/tgv1t/lib/glcdfont.c"


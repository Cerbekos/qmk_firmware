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
#pragma once

#include "quantum.h"

#define LAYOUT( \
    L00, L01, L02, L03, L04, L05, L06, L07, L08, R00,      R02, R03, R04, R05, R06, R07, R08, \
    L10, L11, L12, L13, L14, L15, L16, L17, L18, R10, R11, R12, R13, R14, R15, R16,      R18, \
         L21, L22, L23, L24, L25, L26, L27, L28, R20, R21, R22, R23, R24, R25, R26, R27, R28, \
         L31,      L33, L34,      L36,      L38, R30,      R32,           R35,           R38  \
  ) \
  { \
    { L00,   L01,   L02,   L03,   L04,   L05,   L06,   L07,   L08 }, \
    { L10,   L11,   L12,   L13,   L14,   L15,   L16,   L17,   L18 }, \
    { KC_NO, L21,   L22,   L23,   L24,   L25,   L26,   L27,   L28 }, \
    { KC_NO, L31, KC_NO,   L33,   L34, KC_NO,   L36, KC_NO,   L38 }, \
    { R00, KC_NO,   R02,   R03,   R04,   R05,   R06,   R07,   R08 }, \
    { R10,   R11,   R12,   R13,   R14,   R15,   R16, KC_NO,   R18 }, \
    { R20,   R21,   R22,   R23,   R24,   R25,   R26,   R27,   R28 }, \
    { R30, KC_NO,   R32, KC_NO, KC_NO,   R35, KC_NO, KC_NO,   R38 } \
  }

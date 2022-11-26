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
    L00, L01, L02, L03, L04, L05,      R00, R01, R02, R03, R04, R05,     T00, T01, T02, T03, \
    L10, L11, L12, L13, L14, L15,      R10, R11, R12, R13, R14, R15,     T10, T11, T12, T13, \
    L20, L21, L22, L23, L24, L25,      R20, R21, R22, R23, R24, R25,     T20, T21, T22, T23, \
    L30, L31, L32,   L33,    L35,      R30,    R31,   R33, R34, R35,     T30, T31, T32, T33, \
       E1L, E1R,                                   E2L, E2R                                 \
  ) \
  { \
    { KC_NO,   L31,   L23,   L25,   R11,   R13,   R05 }, \
    { L00,   KC_NO,   L33,   L35,   R21,   R23,   R15 }, \
    { L10,     L02, KC_NO,   R00,   R31,   R33,   R25 }, \
    { L20,     L12,   L04, KC_NO,   R02,   R04,   R35 }, \
    { L30,     L22,   L14,   R10, KC_NO,   R14,   E1L }, \
    { L01,     L32,   L24,   R20,   R12, KC_NO,   E1R }, \
    { L11,     L03,   L05,   R30,   R22,   R24,   E2L }, \
    { L21,     L13,   L15,   R01,   R03,   R34,   E2R }, \
    { KC_NO,   T01,   T02,   T03, KC_NO, KC_NO, KC_NO }, \
    { T00,   KC_NO,   T12,   T13, KC_NO, KC_NO, KC_NO }, \
    { T10,     T11, KC_NO,   T23, KC_NO, KC_NO, KC_NO }, \
    { T20,     T21,   T22, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { T30,     T31,   T32,   T33, KC_NO, KC_NO, KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO } \
  }

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
    L00, L01, L02, L03, L04, L05,      R00, R01, R02, R03, R04, R05,      T00, T01, T02, T03, \
    L10, L11, L12, L13, L14, L15,      R10, R11, R12, R13,   R14,         T10, T11, T12, T13, \
    L20, L21, L22, L23, L24, L25,      R20, R21, R22, R23, R24, R25,      T20, T21, T22, T23, \
    L30, L31, L32,   L33,    L35,      R30,    R31,   R33, R34, R35,      T30, T31, T32, T33, \
      LE14, LE15,                                  RE24, RE25,                     TE34, TE35 \
  ) \
  { \
    {   L00,   L01,   L02,   L03,   L04,   L05,   R00,   R01,   R02,   R03,   R04,   R05 }, \
    {   L10,   L11,   L12,   L13,   L14,   L15,   R10,   R11,   R12,   R13,   R14, KC_NO }, \
    {   L20,   L21,   L22,   L23,   L24,   L25,   R20,   R21,   R22,   R23,   R24,   R25 }, \
    {   L30,   L31,   L32,   L33, KC_NO,   L35,   R30,   R31, KC_NO,   R33,   R34,   R35 }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   T00,   T01,   T02,   T03, KC_NO, KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   T10,   T11,   T12,   T13,  LE14,  LE15 }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   T20,   T21,   T22,   T23,  RE24,  RE25 }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   T30,   T31,   T32,   T33,  TE34,  TE35 } \
  }

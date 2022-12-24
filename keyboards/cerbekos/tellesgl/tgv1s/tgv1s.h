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
    L00, L01, L02, L03, L04,       R60,  R61,  R62,  R63,  R64, R65,   R95, R104, R105, \
    L10, L11, L12, L13, L14, L15,  R70,  R71,  R72,  R73,  R74, R75,   L53,  L54,  L55, \
    L20, L21, L22, L23, L24, L25,  R80,  R81,  R82,  R83,  R84, R85,  R113, R114, R115, \
    L30, L31, L32, L33, L34, L35,  R90,  R91,  R92,  R93,  R94,        L50,  L51,  L52, \
    L40, L41, L42, L43,       R100,           R101, R102, R103,       R110, R111, R112  \
) \
  { \
    { L00,   L01,   L02,   L03,   L04, KC_NO }, \
    { L10,   L11,   L12,   L13,   L14,   L15 }, \
    { L20,   L21,   L22,   L23,   L24,   L25 }, \
    { L30,   L31,   L32,   L33,   L34,   L35 }, \
    { L40,   L41,   L42,   L43, KC_NO, KC_NO }, \
    { L50,   L51,   L52,   L53,   L54,   L55 }, \
    { R60,   R61,   R62,   R63,   R64,   R65 }, \
    { R70,   R71,   R72,   R73,   R74,   R75 }, \
    { R80,   R81,   R82,   R83,   R84,   R85 }, \
    { R90,   R91,   R92,   R93,   R94,   R95 }, \
    {R100,  R101,  R102,  R103,  R104,  R105 }, \
    {R110,  R111,  R112,  R113,  R114,  R115 } \
  }




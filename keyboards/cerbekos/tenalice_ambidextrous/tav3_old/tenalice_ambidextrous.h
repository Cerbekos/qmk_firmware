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
    K10, K30, K70, K21, K61, K02, K52,   K03, K43, K83,        K05, K45, K06, K36, K86, K27, K47, \
    K20, K40, K80, K31, K71, K12, K62,   K13, K53, K04, K34,   K15, K65, K16, K46, K07,      K57, \
         K50, K01, K41, K81, K32, K72,   K23, K63, K14, K54,   K25, K75, K26, K56, K17, K37, K67, \
         K60,      K51,      K42, K82,        K73, K24,        K35, K85,      K76,           K87  \
  ) \
  { \
    { K10,   KC_NO, K12,   K13,   K14,   K15,   K16,   K17,   KC_NO }, \
    { K20,   K21,   KC_NO, K23,   K24,   K25,   K26,   K27,   KC_NO }, \
    { K30,   K31,   K32,   KC_NO, K34,   K35,   K36,   K37,   KC_NO }, \
    { K40,   K41,   K42,   K43,   KC_NO, K45,   K46,   K47,   KC_NO }, \
    { K50,   K51,   K52,   K53,   K54,   KC_NO, K56,   K57,   KC_NO }, \
    { K60,   K61,   K62,   K63,   KC_NO, K65,   KC_NO, K67,   KC_NO }, \
    { K70,   K71,   K72,   K73,   KC_NO, K75,   K76,   KC_NO, KC_NO }, \
    { K80,   K81,   K82,   K83,   KC_NO, K85,   K86,   K87,   KC_NO }, \
    { KC_NO, K01,   K02,   K03,   K04,   K05,   K06,   K07,   KC_NO } \
  }

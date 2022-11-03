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
    L00, L01, L02,     \
    L10, L11, L12, L13,\
    L20, L21, L22, L23,\
         L31, L32      \
  ) \
  { \
    {   L00,   L01,   L02, KC_NO,}, \
    {   L10,   L11,   L12,   L13 }, \
    {   L20,   L21,   L22,   L23 }, \
    { KC_NO,   L31,   L32, KC_NO } \
  }

#include QMK_KEYBOARD_H

const matrix_row_t matrix_mask[MATRIX_ROWS] = {
    0b1111111111111110,
    0b1111111111111101,
    0b1111111111111011,
    0b1111111111110111,
    0b1111111111101111,
    0b1111111111011111,
    0b1111111110111111,
    0b1111111101111111,
    0b1111111011111111,
    0b1111110111111111,
    0b1111101111111111,
    0b1111011111111111,
    0b1110111111111111,
    0b1101111111111111
};
#include "gf.h"
#include <iostream>

#define Mx4 0b00010011 // m(x) = x^4 + x + 1
#define Mx8 0b100011011 // m(x) = x^8 + x^4 + x^3 + x + 1

uint8_t res_gf4[4];
uint16_t res_gf8[8];

uint8_t x_mutilply_gx_gf4(uint8_t gx) {
    if ((gx & (1 << 3)) == 0)
        return (gx << 1);

    return ((gx << 1) ^ Mx4);
}

void solve_res4(uint8_t g_x) {
    if ((g_x & 0b11110000) != 0) {
        std::cout << "So dua vao khong nam trong truong GF2^4\n";
        return;
    }

    res_gf4[0] = g_x;
    uint8_t temp = x_mutilply_gx_gf4(g_x);

    for (int i = 1; i < 4; i++) {
        res_gf4[i] = temp;
        temp = x_mutilply_gx_gf4(temp);
    }
}

uint16_t x_mutilply_gx_gf8(uint8_t gx) {
    if ((gx & (1 << 7)) == 0)
        return (gx << 1);

    return ((gx << 1) ^ Mx8);
}

void solve_res8(uint16_t g_x) {
    if ((g_x & 0b1111111100000000) != 0) {
        std::cout << "So nhap khong nam trong truong GF 2^8\n";
        return;
    }

    res_gf8[0] = g_x;
    uint8_t temp = x_mutilply_gx_gf8(g_x);

    for (int i = 1; i < 8; i++) {
        res_gf8[i] = temp;
        temp = x_mutilply_gx_gf8(temp);
    }
}
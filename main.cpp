#include <iostream>
#include <bitset>
#include "gf.h"

int main() {
    uint16_t fx = 0b00010011;
    uint16_t gx = 0b00010001;

    uint8_t ans = 0;

    solve_res8(gx);
    for(int i = 0; i < 8; i++) {
        if(fx & (1 << i)) ans ^= res_gf8[i];
    }
    std::cout << std::bitset<8>(ans) << "\n";

    return 0;
}
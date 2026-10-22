#include <iostream>
#include <cstdint>
#include <bitset>

#define Mx4 0b00010011 // m(x) = x^4 + x + 1
#define Mx8 0b100011011 // m(x) = x^8 + x^4 + x^3 + x + 1


uint8_t res[5];
uint8_t x_mutilply_gx(uint8_t gx) {
    if((gx & (1 << 3)) == 0) return (gx << 1);

    return ((gx << 1) ^ Mx4);
}
void solve_res4(uint8_t g_x) {
    res[0] = g_x;
    uint8_t temp = x_mutilply_gx(g_x);
    for(int i = 0; i < 4; i++) {
        res[i + 1] = temp;
        temp = x_mutilply_gx(temp);
    }
}

// test case do AI sinh

int main() {
    uint8_t fx = 0b1000;
    uint8_t gx = 0b1000;

    uint8_t ans = 0;
    solve_res4(gx);
    for(int i = 0; i < 4; i++) {
        if(fx & (1 << i)) ans ^= res[i];
    }
    std::cout << std::bitset<4>(ans) << "\n";


    return 0;
}
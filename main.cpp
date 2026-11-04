#include <iostream>
#include <bitset>
#include "gf.h"

int main() {
    uint16_t fx;
    uint16_t gx;
    std::cout << "Ban muon nhan trong truong nao (4 or 8) : ";
    int field;
    do {
        std::cin >> field;
        if (field != 4 && field != 8) {
            std::cout << "Chi nhan vao 4 hoac 8, hay nhap lai : ";
        }
    } while (field != 4 && field != 8);
    std::cout << "Hay nhap vao da thuc fx o dang thap phan (0-255) : ";
    do {
        std::cin >> fx;
        if (fx > 255) {
            std::cout << "Da thuc nhap vao khong nam trong GF2^8, hay nhap lai : ";
        }
    } while (fx > 255);
    std::cout << "Hay nhap vao da thuc gx o dang thap phan (0-255) : ";
    do {
        std::cin >> gx;
        if (gx > 255) {
            std::cout << "Da thuc nhap vao khong nam trong GF2^8, hay nhap lai : ";
        }
    } while (gx > 255);

    uint16_t res;
    if (field == 4) { 
        res = multiply_gf4(fx, gx);
        std::cout << "Result = " << res << '\n';
    } else {
        res = multiply_gf8(fx, gx);
        std::cout << "Result = " << res << '\n';
    }
    return 0;
}
#include <iostream>
#include "../gf.h"

int main() {
    //GF4
    uint8_t input4[] = {0x00, 0x01, 0x03, 0x08, 0x05};
    uint8_t expected4[][3] = {
        {0x00, 0x00, 0x00},
        {0x02, 0x04, 0x08},
        {0x06, 0x0C, 0x0B},
        {0x03, 0x06, 0x0C},
        {0x0A, 0x07, 0x0E}
    };

    // GF8
    uint16_t input8[] = {0x00, 0x01, 0x57, 0x80};

    uint16_t expected8[][7] = {
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
        {0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80},
        {0xAE, 0x47, 0x8E, 0x07, 0x0E, 0x1C, 0x38},
        {0x1B, 0x36, 0x6C, 0xD8, 0xAB, 0x4D, 0x9A}
    };

    int checked4 = 0;
    int checked8 = 0;

    std::cout << "======================\n";
    std::cout << "Test lookup table cua GF2^4 va GF2^8\n";
    std::cout << "======================\n";
    //GF4
    for(int i = 0; i < 5; i++) {
        solve_res4(input4[i]);
        bool temp = true;

        for(int j = 0; j < 3; j++) {
            if(res_gf4[j + 1] != expected4[i][j]) {
                temp = false;
                std::cout << "Sai tai test " << i + 1 << '\n';
                std::cout << "Mong doi = " << (int)expected4[i][j] << ", thuc te = " << (int)res_gf4[j + 1] << '\n';
            }
        }

        if(temp) checked4++;
    }

    for (int i = 0; i < 4; i++) {
        solve_res8(input8[i]);

        bool temp = true;

        for (int j = 0; j < 7; j++) {
            if (res_gf8[j + 1] != expected8[i][j]) {
                temp = false;
                std::cout << "Sai tai test " << i + 1 << '\n';
                std::cout << "Mong doi = " << (int)expected8[i][j] << ", thuc te = " << (int)res_gf8[j + 1] << '\n';
            }
        }
        if(temp) checked8++;
    }

    std::cout << "GF4 pass: " << checked4 << "/5\n";
    std::cout << "GF8 pass: " << checked8 << "/4\n";
    
    std::cout << "======================\n";
    std::cout << "Test nhan 2 so trong GF2^4 va GF2^8\n";
    std::cout << "======================\n";


    // GF(2^4)
    uint8_t input_a_gf4[] = {
        0x00, 0x01, 0x03, 0x03, 0x08,
        0x08, 0x07, 0x0A, 0x0F, 0x05
    };

    uint8_t input_b_gf4[] = {
        0x07, 0x0B, 0x02, 0x05, 0x02,
        0x08, 0x06, 0x0B, 0x0F, 0x0B
    };
    uint8_t expected_gf4[] = {
        0x00, 0x0B, 0x06, 0x0F, 0x03,
        0x0C, 0x01, 0x02, 0x0A, 0x01
    };

    int checked_mul4 = 0;
    int count4 = sizeof(input_a_gf4) / sizeof(input_a_gf4[0]);

    for(int i = 0; i < count4; i++) {
        uint8_t res = multiply_gf4(input_a_gf4[i], input_b_gf4[i]);
        if(res == expected_gf4[i]) {
            checked_mul4++;
        }  else {
            std::cout << "Sai tai test " << i + 1 << '\n';
            std::cout << "Mong doi = " << (int)expected_gf4[i] << ", thuc te = " << (int)res << '\n';
        }
    }

    std::cout << "GF4 test multiply : " << checked_mul4 << "/" << count4 << "\n";
    return 0;
}
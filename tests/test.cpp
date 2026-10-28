#include <iostream>
#include "../gf.h"

int main() {
    uint8_t input[] = {0x00, 0x01, 0x03, 0x08, 0x05};
    uint8_t expected[][3] = {
        {0x00, 0x00, 0x00},
        {0x02, 0x04, 0x08},
        {0x06, 0x0C, 0x0B},
        {0x03, 0x06, 0x0C},
        {0x0A, 0x07, 0x0E}
    };

    int checked = 0;
    for(int i = 0; i < 5; i++) {
        solve_res4(input[i]);
        bool temp = true;

        for(int j = 0; j < 3; j++) {
            if(res_gf4[j + 1] != expected[i][j]) {
                temp = false;
                std::cout << "Sai tai test " << i + 1 << '\n';
                std::cout << "Mong doi = " << (int)expected[i][j] << ", thuc te = " << (int)res_gf4[j + 1] << '\n';
            }
        }

        if(temp) checked++;
    }

    std::cout << "pass: " << checked;
    return 0;
}
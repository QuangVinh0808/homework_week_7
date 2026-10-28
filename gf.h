#include <cstdint>

extern uint8_t res_gf4[4];
extern uint16_t res_gf8[8];

uint8_t x_mutilply_gx_gf4(uint8_t gx);
void solve_res4(uint8_t g_x);

uint16_t x_mutilply_gx_gf8(uint8_t gx);
void solve_res8(uint16_t g_x);

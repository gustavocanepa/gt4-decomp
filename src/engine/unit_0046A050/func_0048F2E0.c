#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0048F2E0(u8 *p) {
    return (p[0] | (p[1] << 8) | (p[2] << 16) | (p[3] << 24)) == 0xFFF7EEC5;
}

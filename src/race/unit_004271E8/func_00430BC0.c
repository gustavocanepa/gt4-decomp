#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00430BC0(u32 *p) {
    u32 v = *p;
    u32 hi = (v >> 4) & 0xF;
    s32 lo = v & 0xF;
    if (hi == 15) return 0;
    switch (lo) {
    case 0: return 0;
    case 1: return hi < 11;
    case 2: return hi < 2;
    case 3: return hi < 2;
    }
    return 0;

}

#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00430C50(u32 *p) {
    u32 v = *p;
    s32 lo = v & 0xF;
    switch (lo) {
    case 0: return 0;
    case 1: return ((v >> 4) & 0xF) < 13;
    case 2: return (v & 0xF0) == 0;
    case 3: return (v & 0xF0) == 0;
    }
    return 0;
}

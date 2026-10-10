#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003CF780(s32 x, s32 flag) {
    if (x == 0) return -1;
    if (x < 2) return 0;
    if (flag != 0 && x < 5) return 2;
    if (x < 4) return 1;
    if (x < 6) return 3;
    return -1;
}

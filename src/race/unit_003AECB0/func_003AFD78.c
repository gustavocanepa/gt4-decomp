#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern s32 D_006184F0;
s32 func_003AFD78(s32 x, s32 w, s32 fl) {
    if ((fl & 4) && D_006184F0 != 0) {
        if (fl & 8) x += 96; else x -= 96;
    }
    switch (fl & 3) {
    case 0: return x;
    case 1: return x - w;
    case 2: default: return x - (w >> 1);
    }

}

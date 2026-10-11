#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0046BC40(s32 *p, s32 dir) {
    switch (dir) {
    case 2:
        if (p[6] != 0) return 6;
    case 6:
        if (p[1] != 0) return 1;
        break;
    }
    return -1;
}

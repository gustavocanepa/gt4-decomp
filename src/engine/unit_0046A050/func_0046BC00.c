#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0046BC00(s32 *p, s32 dir) {
    switch (dir) {
    case 1:
        if (p[6] != 0) return 6;
    case 6:
        if (p[2] != 0) return 2;
        break;
    }
    return -1;

}

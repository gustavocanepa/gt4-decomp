#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003FC598(s32 *p, s32 v) {
    s32 r = 0;
    if (p[0] == 0) return 0;
    if (p[2] != 0) {
        if (p[2] == 1) r = p[4] == v;
    }
    return r;

}

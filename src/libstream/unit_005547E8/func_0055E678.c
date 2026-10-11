#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_00873DC4[];
u16 func_0055E678(s32 arg0, s32 arg1) {
    return *(s32 *)(D_00873DC4 + (((arg0 * 0x1A) + arg1) * 2));
}

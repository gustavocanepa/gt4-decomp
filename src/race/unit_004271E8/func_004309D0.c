#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00430990(s32);                             /* extern */

void func_004309D0(s32 *arg0, s32 arg1) {
    *arg0 = (*arg0 & ~0xF) | (func_00430990(arg1) & 0xF);
}

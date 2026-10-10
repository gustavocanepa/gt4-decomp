#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003B7668(s32, s32, void *, s32);   /* extern */

void func_003B7238(s32 arg0, s32 arg1) {
    s8 sp[0x10];
    do {

    } while (func_003B7668(arg1 + 0xF4, 0x1B, sp, 1) != 0);
}

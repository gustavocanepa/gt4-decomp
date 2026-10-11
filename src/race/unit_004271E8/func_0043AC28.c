#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00329CB0(void *, s32, s32, s32); /* extern */
s32 func_004365B8(s32);                         /* extern */

void func_0043AC28(s32 arg0) {
    s8 sp[0x10];
    func_004365B8(arg0 + 0x38CB0);
    func_00329CB0(sp, (s32)"afterGameLoadHook", 0, 0);
}

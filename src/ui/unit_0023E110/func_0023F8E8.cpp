#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002C3BE0(s32, s32);                    /* extern */
s32 func_0057F238(s32, s32);                    /* extern */

extern char D_00698EF0[];
struct func_0023F8E8_arg0 {
    char pad0[0x10];
    s32 unk10;
};

void func_0023F8E8(void *arg0, s32 arg1) {
    if (func_0057F238(arg1, (s32)D_00698EF0) != 0) {
        func_002C3BE0(((struct func_0023F8E8_arg0 *)arg0)->unk10, arg1);
    }
}

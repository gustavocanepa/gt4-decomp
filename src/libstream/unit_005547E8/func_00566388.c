#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0055F4B0();                            /* extern */
s32 func_00574D78(s32);                         /* extern */
s32 func_005A48D8(void *, s32, s32);    /* extern */

extern char D_00689CA8[];
struct func_00566388_arg0 {
    s32 unk0;
    char pad4[0x30];
    s32 unk34;
    s32 unk38;
    char pad3C[0x2C];
    s32 unk68;
};

void func_00566388(void *arg0, s32 arg1) {
    func_0055F4B0();
    ((struct func_00566388_arg0 *)arg0)->unk0 = (s32)D_00689CA8;
    func_00574D78(arg0 + 4);
    ((struct func_00566388_arg0 *)arg0)->unk34 = arg1;
    ((struct func_00566388_arg0 *)arg0)->unk38 = 0;
    ((struct func_00566388_arg0 *)arg0)->unk68 = 1;
    func_005A48D8(arg0 + 0x3C, 0, 0x2C);
}

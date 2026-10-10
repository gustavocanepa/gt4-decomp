#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00574D78(void *);                      /* extern */
s32 func_005A48D8(void *, s32, s32);    /* extern */

struct func_00549798_arg0 {
    s32 unk0;
    char pad4[0x60];
    s32 unk64;
    char pad68[0x434];
    s32 unk49C;
    s32 unk4A0;
    s32 unk4A4;
};

void func_00549798(void *arg0) {
    ((struct func_00549798_arg0 *)arg0)->unk0 = 0;
    func_00574D78(arg0 + 4);
    func_00574D78(arg0 + 0x34);
    ((struct func_00549798_arg0 *)arg0)->unk64 = 0;
    ((struct func_00549798_arg0 *)arg0)->unk49C = 0;
    ((struct func_00549798_arg0 *)arg0)->unk4A0 = 0;
    ((struct func_00549798_arg0 *)arg0)->unk4A4 = 0;
    func_005A48D8(arg0 + 0x68, 0, 0x37C);
    func_005A48D8(arg0 + 0x3E4, 0, 0x5C);
    func_005A48D8(arg0 + 0x440, 0, 0x5C);
}

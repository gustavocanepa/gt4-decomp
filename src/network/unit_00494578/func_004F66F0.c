#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004F0C88();                                /* extern */
s32 func_004F0CD0(void *, s32);             /* extern */
s32 func_0052EEC8(void *);                      /* extern */
s32 func_005A48D8(void *, s32, s32);    /* extern */
s32 func_005A6AB0(void *, void *, s32);     /* extern */

struct func_004F66F0_arg0 {
    char pad0[0x5A8];
    void *unk5A8;
    char pad5AC[0x1C7C];
    s32 unk2228;
};
struct func_004F66F0_temp_s0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0xC];
    s32 unk14;
};

void func_004F66F0(void *arg0) {
    void *temp_s0;

    if (func_004F0C88() != 0) {
        func_005A48D8(((struct func_004F66F0_arg0 *)arg0)->unk5A8, 0, 0x48);
        temp_s0 = ((struct func_004F66F0_arg0 *)arg0)->unk5A8;
        func_0052EEC8(temp_s0);
        ((struct func_004F66F0_temp_s0 *)temp_s0)->unk4 = (s32) ((struct func_004F66F0_arg0 *)arg0)->unk2228;
        ((struct func_004F66F0_temp_s0 *)temp_s0)->unk14 = 7;
        func_005A6AB0(temp_s0 + 8, arg0 + 0x222C, 0xC);
        func_004F0CD0(arg0, 0x31);
    }
}

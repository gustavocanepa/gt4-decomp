#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004F0C88();                                /* extern */
s32 func_004F0CD0(void *, s32);             /* extern */
s32 func_005A48D8(void *, s32, s32);    /* extern */
s32 func_005A6AB0(void *, void *, s32);     /* extern */

struct func_004F5890_arg1 {
    char pad0[0x28];
    s32 unk28;
    s32 unk2C;
    s32 unk30;
};

struct func_004F5890_arg0 {
    char pad0[0x5A8];
    void *unk5A8;
};
struct func_004F5890_temp_s0 {
    char pad0[0x28];
    s32 unk28;
    s32 unk2C;
    s32 unk30;
};

void func_004F5890(void *arg0, struct func_004F5890_arg1 *arg1) {
    void *temp_s0;

    if (func_004F0C88() != 0) {
        func_005A48D8(((struct func_004F5890_arg0 *)arg0)->unk5A8, 0, 0x34);
        temp_s0 = ((struct func_004F5890_arg0 *)arg0)->unk5A8;
        func_005A6AB0(temp_s0 + 0x15, arg0 + 0xAF8, 0x11);
        ((struct func_004F5890_temp_s0 *)temp_s0)->unk28 = (s32) arg1->unk28;
        ((struct func_004F5890_temp_s0 *)temp_s0)->unk2C = (s32) arg1->unk2C;
        ((struct func_004F5890_temp_s0 *)temp_s0)->unk30 = (s32) arg1->unk30;
        func_004F0CD0(arg0, 0x2A);
    }
}

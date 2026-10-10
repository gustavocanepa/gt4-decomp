#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004F0C88();                                /* extern */
s32 func_004F0CD0(void *, s32);             /* extern */
s32 func_005A48D8(void *, s32, s32);    /* extern */
s32 func_005A6AB0(void *, void *, s32);     /* extern */

struct func_004F2010_arg0 {
    char pad0[0x40];
    s32 unk40;
    char pad44[0x564];
    void *unk5A8;
};
struct func_004F2010_temp_s0 {
    char pad0[0x28];
    s32 unk28;
};
struct func_004F2010_temp_s0_2 {
    char pad0[0x28];
    s32 unk28;
};

void func_004F2010(void *arg0, s32 arg1) {
    void *temp_s0;
    void *temp_s0_2;

    if (arg1 != 0) {
        if (func_004F0C88() != 0) {
            func_005A48D8(((struct func_004F2010_arg0 *)arg0)->unk5A8, 0, 0x2C);
            temp_s0 = ((struct func_004F2010_arg0 *)arg0)->unk5A8;
            func_005A6AB0(temp_s0 + 0x15, arg0 + 0xAF8, 0x11);
            ((struct func_004F2010_temp_s0 *)temp_s0)->unk28 = (s32) ((struct func_004F2010_arg0 *)arg0)->unk40;
            func_004F0CD0(arg0, 0xB);
        }
    } else if (func_004F0C88() != 0) {
        func_005A48D8(((struct func_004F2010_arg0 *)arg0)->unk5A8, 0, 0x2C);
        temp_s0_2 = ((struct func_004F2010_arg0 *)arg0)->unk5A8;
        func_005A6AB0(temp_s0_2 + 0x15, arg0 + 0xAF8, 0x11);
        ((struct func_004F2010_temp_s0_2 *)temp_s0_2)->unk28 = (s32) ((struct func_004F2010_arg0 *)arg0)->unk40;
        func_004F0CD0(arg0, 0xC);
    }
}

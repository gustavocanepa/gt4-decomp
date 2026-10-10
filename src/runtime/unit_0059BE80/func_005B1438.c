/* compiler: ee-gcc2.9-991111 */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_005B0DF0(s32, void *, s32, s32, s32, s32); /* extern */
void *func_005B12B8(s32, u32);                      /* extern */
void *func_005B12E8(s32, u32);                      /* extern */
s32 func_005B9068(s32, void *, void *);    /* extern */

void func_005B13F8();
struct func_005B1438_arg0 {
    char pad0[0x10];
    u32 unk10;
    s32 unk14;
    char pad18[0x4];
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
};
struct func_005B1438_var_v0 {
    char pad0[0x14];
    s32 unk14;
    char pad18[0x4];
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
};

void func_005B1438(struct func_005B1438_arg0 *arg0, s32 arg1) {
    u32 temp_a1;
    struct func_005B1438_var_v0 *var_v0;

    temp_a1 = arg0->unk10;
    if (temp_a1 & 4) {
        var_v0 = func_005B12E8(arg1, temp_a1 >> 0x10);
    } else {
        var_v0 = func_005B12B8(arg1, temp_a1);
    }
    {
        s32 a = arg0->unk14;
        s32 b = arg0->unk1C;
        var_v0->unk14 = a;
        var_v0->unk1C = b;
    }
    var_v0->unk20 = 0x8000000C;
    var_v0->unk24 = (s32) arg0->unk20;
    var_v0->unk28 = (s32) arg0->unk24;
    var_v0->unk2C = (s32) arg0->unk28;
    if (func_005B0DF0(0x80000008, var_v0, 0x40, arg0->unk20, arg0->unk24, arg0->unk28) == 0) {
        func_005B9068(0x800, func_005B13F8, var_v0);
    }
}

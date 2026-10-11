#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004F0C88();                                /* extern */
s32 func_004F0CD0(void *, s32);             /* extern */
s32 func_005A48D8(void *, s32, s32);    /* extern */

struct func_004F3C00_arg0 {
    char pad0[0x5A8];
    void *unk5A8;
};
struct func_004F3C00_temp_v1 {
    char pad0[0x28];
    s32 unk28;
    s32 unk2C;
};

void func_004F3C00(struct func_004F3C00_arg0 *arg0, s32 arg1) {
    struct func_004F3C00_temp_v1 *temp_v1;

    if (func_004F0C88() != 0) {
        func_005A48D8(arg0->unk5A8, 0, 0x50);
        temp_v1 = arg0->unk5A8;
        temp_v1->unk2C = arg1;
        temp_v1->unk28 = 0;
        func_004F0CD0(arg0, 0x3E);
    }
}

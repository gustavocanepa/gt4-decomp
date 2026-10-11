#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00478AF0_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0xC];
    s32 unk14;
    char pad18[0xC];
    s32 unk24;
    char pad28[0xC];
    f32 unk34;
};

void func_00478AF0(struct func_00478AF0_arg0 *arg0, s32 arg1, s32 arg2, f32 fparg0) {
    arg0->unk4 = 0;
    arg0->unk14 = 0;
    arg0->unk24 = 0;
    arg0->unk34 = (f32) (((f32) arg1 + fparg0 + 0.5f) / (f32) arg2);
}

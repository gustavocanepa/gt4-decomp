#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char D_00660CA8[];
void func_00574DA8(s32, s32);
void func_0057CA38(void *, s32);
void func_005C1628(s32);
struct func_001C5638_temp_a0 {
    char pad0[0x8];
    s32 unk8;
};

void func_001C5638(s32 arg0, s32 arg1) {
    struct func_001C5638_temp_a0 *temp_a0;
    temp_a0 = (void *)(arg0 + 0x48);
    temp_a0->unk8 = (s32)D_00660CA8;
    func_0057CA38(temp_a0, 0);
    func_00574DA8(arg0, 2);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}

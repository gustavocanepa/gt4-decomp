#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_00490700_arg0 {
    char pad0[0x54];
    f32 unk54;
    f32 unk58;
    f32 unk5C;
    f32 unk60;
};

void func_00490700(struct func_00490700_arg0 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    arg0->unk5C = (f32) (arg1 + arg3);
    arg0->unk60 = (f32) (arg2 + arg4);
    arg0->unk54 = (f32) arg1;
    arg0->unk58 = (f32) arg2;
}

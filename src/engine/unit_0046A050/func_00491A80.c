#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_00491A80_arg0 {
    char pad0[0x4];
    s32 unk4;
    u16 unk8;
    u16 unkA;
};

s32 func_00491A80(struct func_00491A80_arg0 *arg0, s32 arg1) {
    u16 temp_v1;

    temp_v1 = arg0->unk8;
    if ((arg1 >= (s32) temp_v1) && ((s32) arg0->unkA >= arg1)) {
        return arg0->unk4 + ((arg1 - temp_v1) * 0x14);
    }
    return arg0->unk4;
}

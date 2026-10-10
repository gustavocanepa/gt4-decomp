#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_00555050_arg0 {
    char pad0[0x28];
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
};

void func_00555050(struct func_00555050_arg0 *arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 *arg4, s32 *arg5, s32 *arg6) {
    *arg1 = arg0->unk28;
    *arg2 = arg0->unk30;
    *arg3 = arg0->unk2C;
    *arg4 = arg0->unk34;
    *arg5 = arg0->unk38;
    *arg6 = arg0->unk3C;
}

#include "types.h"

extern "C" void func_003B1750(char *arg0, char *arg1, char *arg2, f32 *arg3, s32 arg4, s32 arg5, s32 arg6);

extern "C" void func_003B2508(char *self, f32 f12, f32 f13, f32 f14, f32 f15,
                              f32 f16, f32 f17, f32 f18, f32 f19, f32 f20,
                              s32 arg1, s32 arg2, s32 arg3) {
    *(f32 *)(self + 0x7C4) = f12;
    *(f32 *)(self + 0x7C8) = f13;
    *(f32 *)(self + 0x7CC) = f14;
    *(f32 *)(self + 0x7D0) = f15;
    *(f32 *)(self + 0x7D4) = f16;
    *(f32 *)(self + 0x7D8) = f17;
    f32 tmp[3];
    tmp[0] = f18;
    tmp[1] = f19;
    tmp[2] = f20;
    func_003B1750(self, self + 0x7C4, self + 0x7D0, tmp, arg1, arg2, arg3);
}

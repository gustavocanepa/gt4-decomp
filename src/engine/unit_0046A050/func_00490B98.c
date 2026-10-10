#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_00490B98_arg0 {
    char pad0[0x3C];
    f32 unk3C;
    f32 unk40;
};

void func_00490B98(s32 arg0, f32 *arg1, f32 *arg2, s32 arg3) {
    func_00491418(arg0, arg3, 0, 0, 1);
    *arg1 = ((struct func_00490B98_arg0 *)arg0)->unk3C;
    *arg2 = ((struct func_00490B98_arg0 *)arg0)->unk40;
}

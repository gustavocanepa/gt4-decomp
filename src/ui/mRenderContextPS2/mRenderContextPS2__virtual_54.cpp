#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_002314E8(s32);                             /* extern */
f32 func_002317C8();                                /* extern */
s32 func_00499FB0(s32, s32, s32, s32, s32, f32); /* extern */

void mRenderContextPS2__virtual_54(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    f32 temp_f20;

    temp_f20 = func_002317C8();
    func_00499FB0(arg1, arg2, arg3, arg4, func_002314E8(arg0), temp_f20);
}

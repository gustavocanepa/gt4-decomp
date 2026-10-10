#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_003D9838(void *, s32);                 /* extern */
s32 func_003D9C20(void *, s32);             /* extern */
s32 func_00426AF8(s32);                             /* extern */

struct func_003D97A8_arg0 {
    char pad0[0x1C];
    s32 unk1C;
    s32 unk20;
};

void func_003D97A8(void *arg0, s32 arg1) {
    s32 temp_v0;

    if ((((struct func_003D97A8_arg0 *)arg0)->unk1C != 0) && (((struct func_003D97A8_arg0 *)arg0)->unk20 == 0)) {
        temp_v0 = func_00426AF8(arg1);
        if (temp_v0 & 1) {
            func_003D9C20(arg0, 1);
        }
        if (temp_v0 & 0x8000) {
            func_003D9C20(arg0, 0);
        }
        func_003D9838(arg0, arg1);
    }
}

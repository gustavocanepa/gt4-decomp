#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004D1E50();                                /* extern */
s32 func_004CFD90(void *, s32, s32, s32);       /* extern */

extern char D_004CFD90[];
struct func_004CFD08_arg0 {
    char pad0[0x120];
    s32 unk120;
};

void func_004CFD08(struct func_004CFD08_arg0 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (func_004D1E50() == 0) {
        arg0->unk120 = (s32)D_004CFD90;
        func_004CFD90(arg0, arg1, arg2, arg3);
    }
}

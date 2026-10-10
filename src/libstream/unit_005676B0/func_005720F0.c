#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00572048(s32);                         /* extern */
s32 func_005724B0(void *, s32, s32);            /* extern */

extern char D_00689D28[];
struct func_005720F0_arg0 {
    char pad0[0x7C];
    s32 unk7C;
};

void func_005720F0(void *arg0, s32 arg1, s32 arg2) {
    ((struct func_005720F0_arg0 *)arg0)->unk7C = (s32)D_00689D28;
    func_00572048(arg0 + 0x4C);
    func_005724B0(arg0, arg1, arg2);
}

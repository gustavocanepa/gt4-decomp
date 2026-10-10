#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00101D38();                            /* extern */
s32 func_001CA6C0();                            /* extern */
s32 func_001CB1E8(void *, s32);             /* extern */
s32 func_00575DA0(s32);                         /* extern */
s32 func_00577100(s32, s32, s32);       /* extern */
s32 func_005C1628(void *);                      /* extern */

struct func_001C95B0_arg0 {
    char pad0[0x64];
    s32 unk64;
    s32 unk68;
};

void func_001C95B0(void *arg0, s32 arg1) {
    func_001CA6C0();
    func_00577100(((struct func_001C95B0_arg0 *)arg0)->unk68, 0, 0);
    func_00101D38();
    func_00575DA0(((struct func_001C95B0_arg0 *)arg0)->unk64);
    func_001CB1E8(arg0 + 0x20, 2);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}

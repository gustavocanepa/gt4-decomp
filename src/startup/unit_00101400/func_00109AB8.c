#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00101078(void *, s32);             /* extern */
s32 func_002292A0(void *, s32);             /* extern */
s32 func_00574DA8(s32, s32);                /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char D_00659FB8[];
struct func_00109AB8_arg0 {
    char pad0[0x64];
    s32 unk64;
};

void func_00109AB8(void *arg0, s32 arg1) {
    ((struct func_00109AB8_arg0 *)arg0)->unk64 = (s32)D_00659FB8;
    func_00574DA8(arg0 + 0x74, 2);
    func_002292A0(arg0 + 0x6C, 2);
    func_00101078(arg0, 0);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}

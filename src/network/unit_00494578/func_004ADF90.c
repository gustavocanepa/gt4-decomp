#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00574BA0(void *, s32);             /* extern */
s32 func_00574DA8(s32, s32);                /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char D_00688E30[];
struct func_004ADF90_arg0 {
    char pad0[0x44];
    s32 unk44;
};

void func_004ADF90(void *arg0, s32 arg1) {
    ((struct func_004ADF90_arg0 *)arg0)->unk44 = (s32)D_00688E30;
    func_00574DA8(arg0 + 0x3048, 2);
    func_00574BA0(arg0, 0);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}

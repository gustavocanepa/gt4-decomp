#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004ADF90(void *, s32);             /* extern */
s32 func_00574DA8(void *, s32);             /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char D_00688FE0[];
struct func_004B02E8_arg0 {
    char pad0[0x44];
    s32 unk44;
};

void func_004B02E8(void *arg0, s32 arg1) {
    ((struct func_004B02E8_arg0 *)arg0)->unk44 = (s32)D_00688FE0;
    func_00574DA8(arg0 + 0x3260, 2);
    func_00574DA8(arg0 + 0x3230, 2);
    func_00574DA8(arg0 + 0x3200, 2);
    func_00574DA8(arg0 + 0x31D0, 2);
    func_00574DA8(arg0 + 0x31A0, 2);
    func_00574DA8(arg0 + 0x3170, 2);
    func_004ADF90(arg0, 0);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}

#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00441248(s32);                             /* extern */
s32 func_004454C0(s32);                             /* extern */
s32 func_00449E10(void *, s32);                 /* extern */

struct func_00147D08_arg0 {
    char pad0[0x14];
    s32 unk14;
};

s32 func_00147D08(void *arg0) {
    s32 temp_v0;

    temp_v0 = ((struct func_00147D08_arg0 *)arg0)->unk14;
    if (temp_v0 != 0) {
        func_00449E10(arg0 + 0x18, func_004454C0(func_00441248(temp_v0)));
    }
}

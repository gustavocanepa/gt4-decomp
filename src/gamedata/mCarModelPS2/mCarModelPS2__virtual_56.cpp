#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern "C" {
s32 func_0013BD68(s32 *, s32);              /* extern */
s32 func_00147D80(s32);                             /* extern */
s32 func_00364868(void *, s32, s32);            /* extern */
s32 func_00441248(s32);                             /* extern */

struct mCarModelPS2__virtual_56_arg0 {
    char pad0[0x870];
    s32 unk870;
};

void mCarModelPS2__virtual_56(char *arg0, s32 *arg1) {
    ((struct mCarModelPS2__virtual_56_arg0 *)arg0)->unk870 = (s32) (func_00147D80(*arg1) + 0x4A0);
    func_00364868(arg0 + 0x864, func_00441248(func_00147D80(*arg1)), ((struct mCarModelPS2__virtual_56_arg0 *)arg0)->unk870);
    func_0013BD68(arg1, 2);
}

}

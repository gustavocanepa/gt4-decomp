#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00427778(s32);                             /* extern */
s32 func_004283D0(void *, s32);                 /* extern */

struct func_00428418_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void func_00428418(struct func_00428418_arg0 *arg0) {
    func_004283D0(arg0, func_00427778(arg0->unk4));
}

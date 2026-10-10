#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_002C3BA0();                            /* extern */
s32 func_004607A0(s32);                             /* extern */

struct func_002C3B60_arg0 {
    char pad0[0x10];
    s32 unk10;
};

void func_002C3B60(struct func_002C3B60_arg0 *arg0, s32 arg1) {
    func_002C3BA0();
    arg0->unk10 = func_004607A0(arg1);
}

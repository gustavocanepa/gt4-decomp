#include "types.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void *func_00396800(s32);                           /* extern */
s32 func_003E6C20(void *, s32, s32);            /* extern */
s32 func_003E6DE8(s32, s32, s32);               /* extern */

struct func_00395498_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0xA8];
    s32 unkB0;
};

void func_00395498(struct func_00395498_arg0 *arg0, s32 arg1, s32 arg2) {
    if (arg0->unkB0 < 0) {
        func_003E6C20(func_00396800(arg0->unk4), arg1, arg2);
        return;
    }
    func_003E6DE8(M2C_FIELD(func_00396800(arg0->unk4), s32 *, 0x9C) + (arg0->unkB0 << 5), arg1, arg2);
}

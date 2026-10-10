#include "types.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void *func_00396800(s32);                           /* extern */
s32 func_003E6BF0(void *, s32);                 /* extern */
s32 func_003E6DB8(s32, s32);                    /* extern */

struct func_00395420_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0xA8];
    s32 unkB0;
};

void func_00395420(struct func_00395420_arg0 *arg0, s32 arg1) {
    if (arg0->unkB0 < 0) {
        func_003E6BF0(func_00396800(arg0->unk4), arg1);
        return;
    }
    func_003E6DB8(M2C_FIELD(func_00396800(arg0->unk4), s32 *, 0x9C) + (arg0->unkB0 << 5), arg1);
}
